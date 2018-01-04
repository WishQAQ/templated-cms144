<?php
require_once (dirname(__FILE__) . "/include/common.inc.php");
header("Content-Type: text/html; charset=utf-8");
require_once(dirname(__FILE__)."/include/wap.inc.php");
if(empty($action)) $action = 'index';
$cfg_templets_dir = $cfg_basedir.$cfg_templets_dir;
$channellist = '';
$newartlist = '';
$channellistnext = '';

//顶级导航列表
$dsql->SetQuery("Select id,typename From `#@__arctype` where reid=0 And channeltype=1 And ishidden=0 And ispart<>2 order by sortrank");
$dsql->Execute();
while($row=$dsql->GetObject())
{
	$channellist .= "<a href='wap.php?action=list&amp;id={$row->id}'>{$row->typename}</a>";
}
//当前时间
$curtime = strftime("%Y-%m-%d %H:%M",time());
$cfg_webname = ConvertStr($cfg_webname);

//主页
/*------------
function __index();
------------*/
if($action=='index')
{
	//最新文章
	$dsql->SetQuery("Select id,title,pubdate From `#@__archives` where channel=1 And arcrank = 0 order by id desc limit 0,10");
	$dsql->Execute();
	while($row=$dsql->GetObject())
	{
		$newartlist .= "<li><a href='wap.php?action=article&amp;id={$row->id}'>".cut_str(ConvertStr($row->title),14)."</a> <span>(".date("m/d",$row->pubdate).")</span></li>";
	}
	//推荐图片列表
	$dsql->SetQuery("Select id,title,litpic From `#@__archives` where channel=1 AND FIND_IN_SET('c',flag) And arcrank = 0 order by id desc limit 0,6");
	$dsql->Execute();
	while($row=$dsql->GetObject())
	{
		$newpiclist .= "<li><a href='wap.php?action=article&amp;id={$row->id}'><img src='{$row->litpic}'><span>".ConvertStr($row->title)."</span></a></li>";
	}
	//最新新闻
	$dsql->SetQuery("Select id,title,litpic,flag,description From `#@__archives` where channel=1 And arcrank = 0  order by id desc limit 0,10");
	$dsql->Execute();
	while($row=$dsql->GetObject())
	{
		$hotfoucs .= "<div class='toutiao pd10'><h2><a href='wap.php?action=article&amp;id={$row->id}'>".ConvertStr($row->title)."</a></h2><div class='cont'><a href='wap.php?action=article&amp;id={$row->id}'><img class='fl' src='{$row->litpic}'></a><p>".cut_str(ConvertStr($row->description),70)."</p></div><div class='clr'></div></div>";
	}
	//焦点列表
	$dsql->SetQuery("Select id,title,litpic,flag,description From `#@__archives` where channel=1 And arcrank = 0 AND FIND_IN_SET('h',flag) order by id desc limit 1,6");
	$dsql->Execute();
	while($row=$dsql->GetObject())
	{
		$hotlist .= "<li><a href='wap.php?action=article&amp;id={$row->id}'>".ConvertStr($row->title)."</a></li>";
	}
	//显示WML
	$varlist = "cfg_webname,channellist,cfg_cmsurl,newartlist,newpiclist,hotfoucs,hotlist,cfg_powerby";
ConvertCharset($varlist);
	include($cfg_basedir."/wap/index.php");
	$dsql->Close();
	echo $pageBody;
	exit();
}
/*------------
function __list();
------------*/
//列表
else if($action=='list')
{
	$needCode = 'utf-8';
	$id = preg_replace("[^0-9]", '', $id);
	if(empty($id)) exit('Error!');
	require_once(dirname(__FILE__)."/include/datalistcp.class.php");
	$row = $dsql->GetOne("Select typename,ishidden From `#@__arctype` where id='$id' ");
	if($row['ishidden']==1) exit();
	$typename = ConvertStr($row['typename']);
	//当前栏目下级分类
	$dsql->SetQuery("Select id,typename From `#@__arctype` where reid='$id' And channeltype=1 And ishidden=0 And ispart<>2 order by sortrank");
	$dsql->Execute();
	while($row=$dsql->GetObject())
	{
		$channellistnext .= "<a href='wap.php?action=list&amp;id={$row->id}'>".ConvertStr($row->typename)."</a> ";
	}
	$channelnav = "<div class='sublist'>子栏目：".$channellistnext."</div>";
	//栏目内容(分页输出)
	$sids = GetSonIds($id,1,true);
	$varlist = "cfg_webname,typename,channelnav,channellist,channellistnext,cfg_templeturl,cfg_powerby";
	ConvertCharset($varlist);
	$dlist = new DataListCP();
	$dlist->SetTemplet($cfg_basedir."/wap/list.php");
	$dlist->pageSize = 20;
	$dlist->SetParameter("action","list");
	$dlist->SetParameter("id",$id);
	$dlist->SetSource("Select id,title,litpic,description,pubdate,click From `#@__archives` where typeid in($sids) And arcrank=0 order by id desc");
	$dlist->Display();
	exit();
}
//文档
/*------------
function __article();
------------*/
else if($action=='article')
{
	//文档信息
	$query = "
	  Select tp.typename,tp.ishidden,arc.typeid,arc.title,arc.keywords,arc.arcrank,arc.pubdate,arc.writer,arc.click,addon.body From `#@__archives` arc 
	  left join `#@__arctype` tp on tp.id=arc.typeid
	  left join `#@__addonarticle` addon on addon.aid=arc.id
	  where arc.id='$id'
	";
	$row = $dsql->GetOne($query,MYSQL_ASSOC);
	foreach($row as $k=>$v) $$k = $v;
	unset($row);
	$pubdate = strftime("%y-%m-%d",$pubdate);
	if($arcrank!=0) exit();
	$title = ConvertStr($title);
	$body = html2wml($body);
	$tags = $keywords;
	if($ishidden==1) exit();
	//当前栏目下级分类
	$dsql->SetQuery("Select id,typename From `#@__arctype` where reid='$typeid' And channeltype=1 And ishidden=0 order by sortrank");
	$dsql->Execute();
	while($row=$dsql->GetObject()){
		$channellistnext .= "<a href='wap.php?action=list&amp;id={$row->id}'>".ConvertStr($row->typename)."</a> ";
	}
	//相关文章
    $keywords = explode(',' , $keywords);
    $keyword = '';
    $n = 1;
            foreach($keywords as $k)
            {
                if($n > 3)  break;
                 
                if(trim($k)=='') continue;
                else $k = addslashes($k);
                 
                $keyword .= ($keyword=='' ? " CONCAT(keywords,' ',title) LIKE '%$k%' " : " OR CONCAT(keywords,' ',title) LIKE '%$k%' ");
                $n++;
            }
			
	    if($keyword != '')
    {
             $query2 = "SELECT id,title FROM `#@__archives` where arcrank>-1 AND ($keyword) ORDER BY id desc limit 0,5";
    }
    else
    {
            $query2 = "SELECT id,title FROM `#@__archives` where arcrank>-1 ORDER BY id desc limit 0,5";
    }
	
	$dsql->SetQuery($query2);
	$dsql->Execute();
	while($row=$dsql->GetObject())
	{
		$likearticle .= "<li><a href='wap.php?action=article&amp;id={$row->id}'>".cut_str(ConvertStr($row->title),16)."</a></li>";
	}
	//栏目内容(分页输出)
	$varlist = "cfg_webname,title,channellist,cfg_templeturl,writer,typename,body,likearticle,cfg_powerby,tags";
ConvertCharset($varlist);
	include($cfg_basedir."/wap/article.php");
	$dsql->Close();
	echo $pageBody;
	exit();
}
//错误
/*------------
function __error();
------------*/
else
{
	ConvertCharset($varlist);
	include($cfg_basedir."/wap/error.wml");
	$dsql->Close();
	ConvertCharset($varlist);
	echo $pageBody;
	exit();
}
?>
