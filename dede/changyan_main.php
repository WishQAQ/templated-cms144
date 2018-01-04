<?php
//@session_start();
require_once(dirname(__FILE__)."/config.php");
require_once(DEDEINC."/oxwindow.class.php");

helper('changyan');

if(empty($dopost)) $dopost = '';
if(empty($action)) $action = '';

$_SESSION['changyan'] = !empty($_SESSION['changyan'])? $_SESSION['changyan'] : 0;
$_SESSION['user'] = !empty($_SESSION['user'])? $_SESSION['user'] : '';

$client_id=changyan_get_setting('appid');

if ($dopost=='blank') {
    exit;
}

if ($cfg_feedback_forbid=='N' AND !empty($client_id)) {
    $dsql->ExecuteNoneQuery("UPDATE `#@__sysconfig` SET `value`='Y' WHERE `varname`='cfg_feedback_forbid';");
    changyan_ReWriteConfig();
    ShowMsg("�Ѿ�����DedeCMSĬ�����ۣ������������ۣ�","?");
    exit();
}

//auto update
$version=changyan_get_setting('version');
if (empty($version)) $version = '0.0.1';
if (version_compare($version, CHANGYAN_VER, '<')) {
    $mysql_version = $dsql->GetVersion(TRUE);
    
    foreach ($update_sqls as $ver => $sqls) {
        if (version_compare($ver, $version,'<')) {
            continue;
        }
        foreach ($sqls as $sql) {
            $sql = preg_replace("#ENGINE=MyISAM#i", 'TYPE=MyISAM', $sql);
            $sql41tmp = 'ENGINE=MyISAM DEFAULT CHARSET='.$cfg_db_language;
            
            if($mysql_version >= 4.1)
            {
                $sql = preg_replace("#TYPE=MyISAM#i", $sql41tmp, $sql);
            }
            $dsql->ExecuteNoneQuery($sql);
        }
        changyan_set_setting('version', $ver);
        $version=changyan_get_setting('version');
    }
    $isv_app_key = changyan_get_isv_app_key();
}


if($dopost=='reg')
{
    $msg = <<<EOT
<table width="98%" border="0" cellspacing="1" cellpadding="1">
  <tbody>
    <tr>
      <td height="30" colspan="2" style="color:#999"><strong>����</strong>��һ���򵥶�ǿ�����ữ���ۼ��ۺ�ƽ̨���û�����ֱ�����Լ�����ữ�����˻��ڵ�������վ�������ۣ�����һ������ͬ�����罻���罫��վ���ݺ��Լ������۷�������ѡ����ӵ�������վ�û���Ծ�ȣ��������Ѳ������ۣ�������վʵ����ữ�����Ż�����Ч������վ��ữ������</td>
    </tr>
    <tr>
      <td height="30" colspan="2" style="color:#999"></td>
    </tr>
    <tr>
      <td width="16%" height="30">���䣺</td>
      <td width="84%" style="text-align:left;"><input name="user" type="text" id="user" size="16" style="width:200px" /></td>
    </tr>
    <tr>
      <td height="30">���룺</td>
      <td style="text-align:left;"><input name="pwd" type="password" id="pwd" size="16" style="width:200px">
        &nbsp;��������'0-9a-zA-Z.@_-!'���ڷ�Χ���ַ��� </td>
    </tr>
    <tr>
      <td height="30">ȷ�����룺</td>
      <td style="text-align:left;"><input name="repwd" type="password" id="repwd" size="16" style="width:200px">
        &nbsp;</td>
    </tr>
    <tr>
      <td width="16%" height="30">��վ���ƣ�</td>
      <td width="84%" style="text-align:left;"><input name="isv_name" type="text" id="isv_name" size="16" style="width:200px" value="{$cfg_webname}" /></td>
    </tr>
    <tr>
      <td width="16%" height="30">��վ��ַ��</td>
      <td width="84%" style="text-align:left;"><input name="url" type="text" id="url" size="16" style="width:200px" value="{$cfg_basehost}" /><span style="color:#999">���磺http://www.dedecms.com</span></td>
    </tr>
  </tbody>
</table>
EOT;

    $wintitle = 'ע�ᳩ���ʺţ�';
    $wecome_info = '<a href="?">�������۲��</a> ��ע���ʺ�';
    $win = new OxWindow();
    $win->Init('?','js/blank.js','POST');
    $win->AddHidden('dopost','doreg');
    $win->AddTitle($wintitle);
    $win->AddMsgItem($msg);
    $winform = $win->GetWindow('ok', '&nbsp;', false);
    $win->Display();

} elseif ($dopost=='doreg') {
    $user = empty($user)? '' : $user;
    $pwd = empty($pwd)? '' : $pwd;
    $repwd = empty($repwd)? '' : $repwd;
    $isv_name = empty($isv_name)? '' : $isv_name;
    $url = empty($url)? '' : $url;
    
    if(!preg_match("#^http:\/\/[A-Za-z0-9]+\.[A-Za-z0-9]+[\/=\?%\-&_~`@[\]\':+!]*([^<>\"])*$#",$url))
    {
        ShowMsg("����д��ȷ����ַ��ʽ",-1);
        exit();
    }
    
    if(empty($isv_name) OR empty($url))
    {
        ShowMsg("����Ҫ��д��ȷ��վ����Ϣ����������д",-1);
        exit();
    }
    if(empty($user) OR empty($pwd) OR empty($repwd))
    {
        ShowMsg("����Ҫ��дE-mail�����룬��������д",-1);
        exit();
    }
    if(!CheckEmail($user))
    {
        ShowMsg("����E-mail��ʽ������������д",-1);
        exit();
    }
    if($pwd != $repwd)
    {
        ShowMsg("��д�������벻ͬ���뷵���������룡",-1);
        exit();
    }
    $sign=changyan_gen_sign($user);
    $paramsArr=array(
        'client_id'=>CHANGYAN_CLIENT_ID, 
        'user'=>changyan_autoCharset($user), 
        'password'=>$pwd, 
        'isv_name'=>changyan_autoCharset($isv_name), 
        'url'=>$url, 
        'sign'=>$sign);
    $rs=changyan_http_send(CHANGYAN_API_REG,0,$paramsArr);
    $result=json_decode($rs,TRUE);
    $errorinfo['appid not exist']='client_id������';
    $errorinfo['sign error']='ǩ����֤ʧ��';
    $errorinfo['user name exist']='ע���û��Ѿ�����';
    if($result['status']==0)
    {
        // ����appid,id��Ϣ
        changyan_set_setting('user', $user);
        changyan_set_setting('appid', $result['appid']);
        changyan_set_setting('id', $result['id']);
        changyan_set_setting('isv_id', $result['isv_id']);
        ShowMsg("���Ѿ��ɹ�ע�ᣬ���ڽ��е�¼��",'?');
        exit();
    } else {
        ShowMsg("�޷�����ע�ᣬ������Ϣ��".$errorinfo[$result['msg']], -1);
        exit();
    }
} elseif ($dopost=='login') {
    $user = empty($user)? '' : $user;
    $pwd = empty($pwd)? '' : $pwd;
    $rmpwd = empty($rmpwd)? '' : $rmpwd;
    if(empty($user) OR empty($pwd))
    {
        ShowMsg("����Ҫ��дE-mail�����룬��������д",-1);
        exit();
    }
    if(!CheckEmail($user))
    {
        ShowMsg("����E-mail��ʽ������������д",-1);
        exit();
    }
    $sign=changyan_gen_sign($user);
    $paramsArr=array(
        'client_id'=>CHANGYAN_CLIENT_ID, 
        'user'=>$user, 
        'password'=>$pwd, 
        'sign'=>$sign);
    $rs=changyan_http_send(CHANGYAN_API_LOGIN,0,$paramsArr);
    $result=json_decode($rs,TRUE);
    if($result['status']==1)
    {
        ShowMsg("�޷���¼�����������ʺ���Ϣ�Ƿ���д��ȷ��",-1);
        exit();
    } elseif ($result['status']==0)
    {
        $isv_id = changyan_get_setting('isv_id');
        if(empty($isv_id))
        {
            // ��û�а�װ����ӵ�ǰվ��
            $sitename = changyan_autoCharset($cfg_webname);
            $result=changyan_addsite($user, $sitename, $cfg_basehost);
            $isv_id = $result['isv_id'];
            changyan_set_setting('appid', $result['appid']);
            changyan_set_setting('id', $result['id']);
            changyan_set_setting('isv_id', $result['isv_id']);
        }
        //if($rmpwd) changyan_set_setting('pwd', $pwd);
        $db_user = changyan_get_setting('user');
        if($db_user != $user)
        {
            changyan_set_setting('isv_app_key', '');
            $isv_app_key = changyan_get_isv_app_key();
        }
        
        changyan_set_setting('user', $user);
        $login_url=CHANGYAN_API_SETCOOKIE.'?client_id='.CHANGYAN_CLIENT_ID.'&token='.$result['token'];

        $_SESSION['changyan']=$result['token'];
        $_SESSION['user']=$user;
        
        echo <<<EOT
<iframe src="{$login_url}" scrolling="no" width="0" height="0" style="border:none"></iframe>
EOT;
        ShowMsg("�ɹ���¼���ԣ�����վ���л�����",'?dopost=changeisv&isv_id='.$isv_id);
        exit();
    } else {
        ShowMsg("�޷���¼��δ֪����",-1);
        exit();
    }
} elseif ($dopost=='changeisv') {
    $isv_id = intval($isv_id);
    $changge_isv_url = CHANGYAN_API_CHANGE_ISV.$isv_id;
    $isv_app_key = changyan_get_isv_app_key();
    echo <<<EOT
<iframe src="{$changge_isv_url}" scrolling="no" width="0" height="0" style="border:none"></iframe>
EOT;
    ShowMsg("�ɹ��л�վ�㣡",'?');
    exit();
} elseif ($dopost=='isnew') {
    $rs=changyan_http_send(CHANGYAN_API_ISNEW.'/?appId='.$client_id.'&date='.urlencode( date('Y-m-d h:i:s')));
    $result=json_decode($rs,TRUE);
    if(count($result['topics'])>0) exit('true');
    else exit('false');
} elseif ($dopost=='latests') {
    $latests = changyan_latests($client_id);
    $data = array();
    if(count($latests['comments']) > 0)
    {
        foreach($latests['comments'] as $k => $v)
        {
            $data[] = array(
                'nickname'=>$v['passport']['nickname'],
                'content'=>$v['content'],
                'topic_title'=>$v['topic_title'],
                'topic_url'=>$v['topic_url'],
            );
        }
    }
    echo json_encode($latests);
    exit;
} elseif ($dopost=='getcode') {
    if(!changyan_islogin())
    {
        ShowMsg("����δ��¼���ԣ����ȵ�¼�����ʹ�á�����",'?');
        exit();
    }
    changyan_check_islogin();
    $user=changyan_get_setting('user');
    $sign=changyan_gen_sign($user);
    $result = changyan_getcode(CHANGYAN_CLIENT_ID, $user, false, $sign);
    $code = htmlspecialchars($result['code']);
    $msg = <<<EOT
<style type='text/css'>
pre {
width:50%;
display: block;
padding: 9.5px;
margin: 0 0 10px;
font-size: 13px;
line-height: 20px;
word-break: break-all;
word-wrap: break-word;
white-space: pre;
white-space: pre-wrap;
background-color: #f5f5f5;
border: 1px solid #ccc;
border: 1px solid rgba(0,0,0,0.15);
-webkit-border-radius: 4px;
-moz-border-radius: 4px;
border-radius: 4px;
}
</style>
<p>DedeCMS��ǩ���루��������뵽ģ��ҳ���Ӧλ�ü��ɣ���</p>
<pre id="iframe" style="height:50px;">   
{dede:changyan/}     
</pre>
<p>Javascript���루��������뵽ģ��ҳ���Ӧλ�ü��ɣ���</p>
<pre id="iframe" style="height:150px;">   
{$code}         
</pre>
EOT;

    $wintitle = '�������۹���';
    $wecome_info = '<a href="?">�������۲��</a> ����ȡ����';
    $win = new OxWindow();
    $win->AddTitle($wintitle);
    $win->AddMsgItem($msg);
    $winform = $win->GetWindow('hand', '&nbsp;', false);
    $win->Display();
    
} elseif ($dopost=='addsite') {
    exit('error!');
    $sign=changyan_gen_sign($user);
    $paramsArr=array(
        'client_id'=>CHANGYAN_CLIENT_ID, 
        'user'=>$user, 
        'isv_name'=>'dedecms_com',
        'url'=>'www.dedecms.com',
        'sign'=>$sign);
    $rs=changyan_http_send(CHANGYAN_API_ADDSITE,0,$paramsArr);
} elseif ($dopost=='manage' OR $dopost=='stat' OR $dopost=='setting'
OR $dopost=="import")
{
    if(!changyan_islogin())
    {
        ShowMsg("����δ��¼���ԣ����ȵ�¼�����ʹ�á�����",'?');
        exit();
    }
    changyan_check_islogin();
    $addstyle='scrolling="no" ';
    $type='audit';
    $appid=changyan_get_setting('appid');
    if($dopost=='manage') $type='audit';
    elseif($dopost=='stat') $type='stat';
    $ptitle = '�������۹���';

    $manage_url="http://changyan.sohu.com/audit/comments/TOAUDIT/1";
    $addstr='';
    if($dopost=='setting') 
    {
        $ptitle = "��������";
        $manage_url="http://changyan.sohu.com/setting/basic";
        
    } elseif ($dopost=='stat')
    {
        $ptitle = "����ͳ��";
        $manage_url="http://changyan.sohu.com/stat-data/comment";
    } elseif ($dopost=='import')
    {
        $ptitle = "���Թ���";
        $export_str=$import_str='';
        $manage_url="?dopost=blank";
        $last_import=changyan_get_setting('last_import');
        $last_export=changyan_get_setting('last_export');
        if (empty($last_export)) {
            $export_str = '<font color="red">��δ���ݣ����鱸�ݣ�</font>';
        } else {
            $export_time = date('Y-m-d H:i:s', $last_export);
            $export_str = '<font color="#666">��󱸷����ڣ�'.$export_time.'</font>';
        }
        if (empty($last_import)) {
            $import_str = '<font color="red">��δ����DedeCMS���۵����ԣ�</font>';
        } else {
            $import_time = date('Y-m-d H:i:s', $last_import);
            $import_str = '<font color="#666">��󵼳����ڣ�'.$import_time.'</font>';
        }
        $addstr=<<<EOT
        <tr bgcolor='#FFFFFF'>
          <td colspan='2' height='30px' style='padding:20px'>
          <script type="text/javascript">
          function isgo(url,msg) {
              if(confirm(msg)) window.location.href=url;
              else return false;
          }
          </script>
          <input type="button" size="14" onclick="return isgo('?dopost=changyan_to_dedecms','�Ƿ񵼳����Ե�DedeCMS���ۣ�');" value="�������Ե�DedeCMS����"> 
           <span style="color:#999">������ģ���е����ݵ������ݵ�DedeCMS���ݿ���</span>  {$export_str}
          <br /><br />
          <input type="button" size="14" onclick="return isgo('?dopost=dedecms_to_changyan','�Ƿ���DedeCMS���۵����ԣ�');" value="����DedeCMS���۵�����">
           <span style="color:#999">��DedeCMS�������ݵ��뵽����ģ����</span> {$import_str}
          </td>
        </tr>
EOT;
    }
    $addstyle='scrolling="auto" ';
    echo <<<EOT
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset={$cfg_soft_lang}">
<title>{$ptitle}</title>
<link rel="stylesheet" type="text/css" href="css/base.css">
</head>
<body background='images/allbg.gif' leftmargin="8" topmargin='8'>
<table width="98%" border="0" align="center" cellpadding="0" cellspacing="0" bgcolor="#DFF9AA" height="100%">
  <tr>
    <td height="28" style="border:1px solid #DADADA" background='images/wbg.gif'>
    
    <div style="float:left">&nbsp;<b>��<a href="?">�������۲��</a> ��{$ptitle}</b></div>
    <div style="float:right;margin-right:20px;">���ã�{$_SESSION['user']} <a href="?dopost=logout">�˳�</a></div>
    </td>
  </tr>
  <tr>
    <td width="100%" height="100%" valign="top" bgcolor='#ffffff' style="padding-top:5px"><table width='100%'  border='0' cellpadding='3' cellspacing='1' bgcolor='#DADADA' height="100%">
        <tr bgcolor='#DADADA'>
          <td colspan='2' background='images/wbg.gif' height='26'><font color='#666600'><b>{$ptitle}</b></font></td>
        </tr>
        {$addstr}
        <tr bgcolor='#FFFFFF'>
          <td colspan='2' height='100%' style='padding:20px'><br/><iframe src="{$manage_url}" {$addstyle} width="100%" height="100%" style="border:none"></iframe></td>
        </tr>
        <tr>
          <td bgcolor='#F5F5F5'>&nbsp;</td>
        </tr>
      </table></td>
  </tr>
</table>
<p align="center"> <br>
  <br>
</p>
</body>
</html>

EOT;
} elseif ($dopost=='dedecms_to_changyan') {
    if(!changyan_islogin())
    {
        ShowMsg("����δ��¼���ԣ����ȵ�¼�����ʹ�á�����",'?');
        exit();
    }
    $isv_app_key = changyan_get_isv_app_key();
    $start = isset($start)? intval($start) : 0;
    $pagesize=1;
    $sql = "SELECT count(*) as dd FROM `#@__feedback` group by aid order by aid asc limit {$start},{$pagesize}";
    $rr = $dsql->GetOne($sql);
    if($rr['dd']==0)
    {
        changyan_set_setting('last_import', time());
        ShowMsg('ȫ��������ɣ�','javascript:;');
        exit;
    }
    $sql = "SELECT aid FROM `#@__feedback` group by aid order by aid asc limit {$start},{$pagesize}";
    $dsql->SetQuery($sql);
    $dsql->Execute('dd');
    $result=array();
    while($arr = $dsql->GetArray('dd'))
    {
        $feedArr=array();
        $arctRow = $dsql->GetOne("SELECT * FROM `#@__arctiny` WHERE id={$arr['aid']}");
        if($arctRow['channel']==0) $arctRow['channel']=1;
        $cid = $arctRow['channel'];
        $chRow = $dsql->GetOne("SELECT * FROM `#@__channeltype` WHERE id='$cid' ");
        $row=array();
        if ($chRow['issystem']!= -1) {
            $sql = "SELECT arc.*,tp.reid,tp.typedir,tp.typename,tp.isdefault,tp.defaultname,tp.namerule,tp.namerule2,tp.ispart,
            tp.moresite,tp.siteurl,tp.sitepath,ch.addtable
            FROM `#@__archives` arc
                     LEFT JOIN `#@__arctype` tp on tp.id=arc.typeid
                      LEFT JOIN `#@__channeltype` as ch on arc.channel = ch.id
                      WHERE arc.id='{$arr['aid']}' ";
            $row = $dsql->GetOne($sql);
        } else {
            if($chRow['addtable']!='')
            {
                $sql = "SELECT arc.*,tp.typedir,tp.typename,tp.isdefault,tp.defaultname,tp.namerule,tp.namerule2,tp.ispart,
            tp.moresite,tp.siteurl,tp.sitepath FROM `{$chRow['addtable']}` arc  
            LEFT JOIN `#@__arctype` tp ON arc.typeid=tp.id
                WHERE `aid` = '{$arr['aid']}'";
                $addTableRow = $dsql->GetOne($sql);
                if(is_array($addTableRow))
                {
                    $row['id']=$addTableRow['aid'];
                    $row['title']=$addTableRow['title'];
                    $row['typeid']=$addTableRow['typeid'];
                    $row['mid']=$addTableRow['mid'];
                    $row['senddate']=$addTableRow['senddate'];
                    $row['channel']=$addTableRow['channel'];
                    $row['arcrank']=$addTableRow['arcrank'];
                    $row['senddate']=$addTableRow['senddate'];
                    $row['typedir']=$addTableRow['typedir'];
                    $row['isdefault']=$addTableRow['isdefault'];
                    $row['defaultname']=$addTableRow['defaultname'];
                    $row['ispart']=$addTableRow['ispart'];
                    $row['namerule2']=$addTableRow['namerule2'];
                    $row['moresite']=$addTableRow['moresite'];
                    $row['siteurl']=$addTableRow['siteurl'];
                    $row['sitepath']=$addTableRow['sitepath'];
                }
            }
        }
        $row['filename'] = $row['arcurl'] = GetFileUrl($row['id'],$row['typeid'],$row['senddate'],$row['title'],1,
        0,$row['namerule'],$row['typedir'],0,'',$row['moresite'],$row['siteurl'],$row['sitepath']);
        $row['title']=changyan_autoCharset($row['title']);
        
        $feedArr['title']=$row['title'];
        $feedArr['url']=$cfg_basehost.$row['arcurl'];
        $feedArr['ttime']= date('Y-m-d h:m:s',  $row['senddate']);
        $feedArr['sourceid']=$arr['aid'];
        $feedArr['parentid']=0;
        $feedArr['categoryid']=$row['typeid'];
        $feedArr['ownerid']=$row['mid'];
        $feedArr['metadata']='';

        $dsql->SetQuery("SELECT feedback_id FROM `#@__plus_changyan_importids` WHERE aid={$aid}");
        $dsql->Execute('dd');
        $feedback_ids=array();
        while($farr = $dsql->GetArray('dd'))
        {
            $feedback_ids[] = $farr['feedback_id'];
        }
        
        $squery="SELECT * FROM `#@__feedback` WHERE aid={$arr['aid']} order by dtime asc;";
        $dsql->SetQuery($squery);
        $dsql->Execute('xx');
        while($fRow = $dsql->GetArray('xx'))
        {
            if (in_array($fRow['id'], $feedback_ids)) continue;
            $feedArr['comments'][]=array(
                'cmtid'=>$fRow['id'],
                'ctime'=>date('Y-m-d h:m:s',  $fRow['dtime']),
                'content'=>changyan_autoCharset($fRow['msg']),
                'replyid'=>0,
                'spcount'=>$fRow['good'],
                'opcount'=>$fRow['bad'],
                'user'=>array(
                    'userid'=>$fRow['mid'],
                    'nickname'=>changyan_autoCharset($fRow['username']),
                    'usericon'=>'',
                    'userurl'=>'',
                )
            );
            $inquery = "INSERT INTO `#@__plus_changyan_importids`(`aid`,`feedback_id`) VALUES ('{$arr['aid']}','{$fRow['id']}')";
            $rs = $dsql->ExecuteNoneQuery($inquery);
        }
        if (count($feedArr['comments'])<1) {
            continue;
        }

        $content=json_encode($feedArr);
        $md5 = changyan_hmacsha1($content, $isv_app_key);

        $paramsArr=array(
            'appid'=>$client_id, 
            'md5'=>$md5, 
            'jsondata'=>$content);
        $rs=changyan_http_send(CHANGYAN_API_IMPORT,0,$paramsArr);
    }
    
    $start =$start+$pagesize;
    $end =$start+$pagesize;
    ShowMsg("�ɹ������������ݣ�����������[{$start}-{$end}]����������","?dopost=dedecms_to_changyan&start={$start}");
    //echo json_encode($result);
    exit();
} elseif ($dopost=='changyan_to_dedecms') {
    if(!changyan_islogin())
    {
        ShowMsg("����δ��¼���ԣ����ȵ�¼�����ʹ�á�����",'?');
        exit();
    }
    $last_export=changyan_get_setting('last_export');
    if (empty($last_export)) {
        $start_date='2014-01-01 00:00:00';
    } else {
        $start_date= date('Y-m-d H:i:s',$last_export);
    }
    $recent = changyan_get_recent($client_id, $start_date);
    //var_dump($recent);exit;
    if (count($recent['topics'])<=0) {
        ShowMsg("û�з����µ�����������Ҫ������",-1);
        exit();
    }
    $exports=array();
    foreach ($recent['topics'] as $topic) {
        $exports[]=array(
            'topic_id'=>$topic['topic_id'],
            'aid'=>$topic['topic_source_id'],
            'title'=>$topic['topic_title'],
        );
    }
    foreach ($exports as $export) {
        changyan_insert_comments(changyan_get_comments($export['topic_id']),$export['aid'],$export['title']);
    }
    changyan_set_setting('last_export', time());
    ShowMsg("�ɹ����ݳ������۵�DedeCMSϵͳ��","?dopost=import");
    exit();
} elseif ($dopost=='change_appinfo') {
    if ($action=='do') {
        if (empty($appid) OR empty($isv_app_key)) {
            ShowMsg("��������ȷ��AppID��APPKEY��",-1);
            exit();
        }
        changyan_set_setting('appid',$appid);
        changyan_set_setting('isv_app_key',$isv_app_key);
        ShowMsg("�ɹ������µ�AppID��APPKEY��",'?');
        exit();
    }
    $msg = <<<EOT
<table width="98%" border="0" cellspacing="1" cellpadding="1">
  <tbody>
    <tr>
      <td width="16%" height="30">APP ID��</td>
      <td width="84%" style="text-align:left;"><input class="input-xlarge" type="text" value="" style="width:260px" name="appid"></td>
    </tr>
    <tr>
      <td height="30">APP KEY��</td>
      <td style="text-align:left;"><input class="input-xlarge" type="text" value="" style="width:260px" name="isv_app_key"> </td>
    </tr>
  </tbody>
</table>
EOT;
    $wintitle = '�������۹���';
    $wecome_info = '�������۲�� ���޸�APP��Ϣ';
    $win = new OxWindow();
    $win->Init('?','js/blank.js','POST');
    $win->AddHidden('dopost','change_appinfo');
    $win->AddHidden('action','do');
    $win->AddTitle($wintitle);
    $win->AddMsgItem($msg);
    $winform = $win->GetWindow('ok', '&nbsp;', false);
    $win->Display();
} elseif ($dopost=='checkupdate')
{
    $get_latest_ver = changyan_http_send(CHANGYAN_API_AES.'index.php?c=welcome&m=get_latest_ver');
    if(version_compare($get_latest_ver, CHANGYAN_VER,'>'))
    {
        ShowMsg("��鵽�����°汾����ǰȥ���أ�<br /><a href='http://bbs.dedecms.com/650203.html' target='_blank' style='color:blue'>���ǰȥ����</a> <a href='?' >����</a>","javascript:;");
        exit();
    } else {
        ShowMsg("��ǰΪ���°汾���������ظ��£�","javascript:;");
        exit();
    }
    exit();
} elseif ($dopost=='clearcache')
{
    helper('cache');
    $prefix = 'changyan';
    $key = 'code';
    DelCache($prefix, $key);
    ShowMsg("�ɹ���ձ�ǩ���棡","?");
    exit();
} elseif ($dopost=='logout')
{
    echo <<<EOT
<iframe src="http://changyan.sohu.com/logout" scrolling="no" width="0" height="0"></iframe>
EOT;
    $_SESSION['changyan'] = 0;
    $_SESSION['user'] = '';
    unset($_SESSION['changyan']);
    unset($_SESSION['user']);
    if($nomsg)
    {
        header('Location:?');
        exit;
    }
    ShowMsg("�ɹ��˳����ԣ�",'?');
    exit();
} else {
    $user = changyan_get_setting('user');
    if(empty($user)) $user='';
    $msg = <<<EOT
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset={$cfg_soft_lang}">
<title>�������۹���</title>
<link rel="stylesheet" type="text/css" href="/plus/img/base.css">
</head>
<body background='{$cfg_plus_dir}/img/allbg.gif' leftmargin="8" topmargin='8'>
<table width="98%" border="0" align="center" cellpadding="0" cellspacing="0" bgcolor="#DFF9AA">
  <tr>
    <td height="28" style="border:1px solid #DADADA" background='/plus/img/wbg.gif'>&nbsp;<b>�������۲�� ��</b></td>
  </tr>
  <tr>
  
  <td width="100%" height="80" style="padding-top:5px" bgcolor='#ffffff'>
  
  <script language='javascript'>
function CheckSubmit(){
    return true; 
}
</script>
  <form name='myform' method='POST' onSubmit='return CheckSubmit();' action='?'>
  
  <input type='hidden' name='dopost' value='login'>
  <table width='100%'  border='0' cellpadding='3' cellspacing='1' bgcolor='#DADADA'>
    <tr bgcolor='#DADADA'>
      <td colspan='2' background='{$cfg_plus_dir}/img/wbg.gif' height='26'><font color='#666600'><b>�������۹���</b></font></td>
    </tr>
    <tr bgcolor='#FFFFFF'>
      <td colspan='2'  height='100'><table width="98%" border="0" cellspacing="1" cellpadding="1">
          <tbody>
            <tr>
              <td width="16%" height="30">���䣺</td>
              <td width="84%" style="text-align:left;"><input name="user" type="text" id="user" size="16" style="width:200px" value="{$user}" />
                <a href="?dopost=reg" style="color:blue">û���˺ţ�ȥע�ᡭ��</a></td>
            </tr>
            <tr>
              <td height="30">���룺</td>
              <td style="text-align:left;"><input name="pwd" type="password" id="pwd" size="16" style="width:200px">
                &nbsp;��������'0-9a-zA-Z.@_-!'���ڷ�Χ���ַ��� </td>
            </tr>
            <!--<tr>
      <td height="30">��ס���룺</td>
      <td style="text-align:left;"><input type="checkbox" name="rmpwd" id="rmpwd" />
        <label for="rmpwd">�´ε�¼���������루���Ƽ���</label></td>
    </tr>-->
          </tbody>
        </table></td>
    </tr>
    <tr>
      <td colspan='2' bgcolor='#F9FCEF'><table width='270' border='0' cellpadding='0' cellspacing='0'>
          <tr align='center' height='28'>
            <td width='90'><input name='imageField1' type='image' class='np' src='{$cfg_plus_dir}/img/button_ok.gif' width='60' height='22' border='0' /></td>
            <td width='90'></td>
            <td></td>
          </tr>
        </table></td>
    </tr>
  </table>
  </td>
  </tr>
</table>
</body>
</html>
EOT;
    if(changyan_islogin())
    {
        $changyan_ver = CHANGYAN_VER;
        $isv_app_key = changyan_get_setting('isv_app_key');
        $msg = <<<EOT
<table width="98%" border="0" cellspacing="1" cellpadding="1">
  <tbody>
    <tr>
      <td width="16%" height="30">��¼�û���</td>
      <td width="84%" style="text-align:left;">{$_SESSION['user']}</td>
    </tr>
    <tr>
      <td width="16%" height="30">����ģ��汾��</td>
      <td width="84%" style="text-align:left;">v{$changyan_ver} <a href='?dopost=checkupdate' style='color:blue'>[������]</a> </td>
    </tr>
    <tr>
      <td width="16%" height="30">App  ID��</td>
      <td width="84%" style="text-align:left;"><input class="input-xlarge" type="text" value="{$client_id}" disabled="disabled/" style="width:260px"> <a href='?dopost=change_appinfo' style='color:blue'>[�޸�]</a> </td>
    </tr>
    <tr>
      <td width="16%" height="30">APP Key��</td>
      <td width="84%" style="text-align:left;"><input class="input-xlarge" type="text" value="{$isv_app_key}" disabled="disabled/" style="width:260px"> <a href='?dopost=change_appinfo' style='color:blue'>[�޸�]</a> </td>
    </tr>
    <tr>
      <td height="30" colspan="2">���ѳɹ���¼���ԣ������Խ������²�����</td>
    </tr>
    <tr>
      <td height="30" colspan="2">
      <a href='?dopost=manage' style='color:blue'>[���۹���]</a> 
      <a href='?dopost=stat' style='color:blue'>[����ͳ��]</a> 
      <a href='?dopost=import' style='color:blue'>[���뵼��]</a> 
      <a href='?dopost=clearcache' style='color:blue'>[��ջ���]</a> 
      <a href='?dopost=setting' style='color:blue'>[��������]</a> 
      <a href='?dopost=logout' style='color:blue'>[�˳�]</a></td>
    </tr>
<tr>
      <td height="30" colspan="2">
   <hr>
   ʹ��˵����<br>
   �ڶ�Ӧģ����ʹ�ñ�ǩ��<font color="red">{dede:changyan/}</font>��ֱ�ӽ��е��ü��ɣ���ʽ�趨�ɵ��<a href='?dopost=setting' style='color:blue'>[��������]</a> �������á�
  <hr>
  ����˵����<br>
  <b>[���۹���]</b>��ˡ�ɾ��������Ϣ�����дʹ����û����Բ�����<br>
 <b>[����ͳ��]</b>վ��������Ϣ����ȫ��λͳ�ƣ�<br>
 <b>[���뵼��]</b>������Ϣ���ݵ���/�����������û����ڵ������ݣ�<br>
 <b>[��ջ���]</b>��ճ������۱�ǩ���棬������ĵ�¼�˺Ž�����ջ��������ɣ�<br>
 <b>[��������]</b>������������趨��<br><br>
<hr>
    </tr>
    <tr>
      <td height="30" colspan="2" style="color:#999"><strong>����</strong>��һ���򵥶�ǿ�����ữ���ۼ��ۺ�ƽ̨���û�����ֱ�����Լ�����ữ�����˻��ڵ�������վ�������ۣ�����һ������ͬ�����罻���罫��վ���ݺ��Լ������۷�������ѡ����ӵ�������վ�û���Ծ�ȣ��������Ѳ������ۣ�������վʵ����ữ�����Ż�����Ч������վ��ữ������</td>
    </tr>
  </tbody>
</table>
EOT;
        $wintitle = '�������۹���';
        $wecome_info = '�������۲�� ��';
        $win = new OxWindow();
        $win->AddTitle($wintitle);
        $win->AddMsgItem($msg);
        $winform = $win->GetWindow('hand', '&nbsp;', false);
        $win->Display();
    } else {
        echo $msg;
    }
}
?>