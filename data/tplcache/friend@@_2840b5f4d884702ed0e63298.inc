<?php
if(!isset($GLOBALS['_vars'])) $GLOBALS['_vars'] = array(); 
$fields = array();
?><!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=<?php echo $cfg_soft_lang; ?>" />
<title>�ҵĺ��� - ��Ա���� - <?php echo $cfg_webname; ?></title>
<link href="templets/style/base.css" rel="stylesheet" type="text/css" />
<script type="text/javascript" src="templets/js/j.js"></script>
<script type="text/javascript" src="templets/js/table_function.js"></script>
<script type="text/javascript" src="../include/dedeajax2.js"></script>
<script type="text/javascript" src="templets/js/load.js"></script>
<script type="text/javascript" src="templets/js/leftmenu.js"></script>
<script type="text/javascript">
  
//���ѡ���ļ����ļ���
function GetCheckfolderItem()
{
	var allSel='';
	if(document.form1.selid.value) return document.form1.selid.value;
	for(i=0;i<document.form1.selid.length;i++)
	{
		if(document.form1.selid[i].checked)
		{
			if(allSel=='')
			allSel=document.form1.selid[i].value;
			else
			allSel=allSel+","+document.form1.selid[i].value;
		}
	}
	return allSel;
}

function DelSel(ftype)
{
	var selid = GetCheckfolderItem();
	if(selid=='') {
		alert("��ûѡ���κκ��ѣ�");
		return false;
	}
	if(window.confirm("��ȷ��Ҫɾ����Щ����ô��"))
	{
		location = "friend.php?dopost=del&ids="+selid+"&ftype="+ftype;
	}
}

function ConvSta(sta,ftype)
{
	var selid = GetCheckfolderItem();
	var stamsg = '';
	if(selid=='') {
		alert("��ûѡ���κκ��ѣ�");
		return false;
	}

	if(sta=='good') stamsg = '�����ע�ĺ���';
	else if(sta=='bad') stamsg = '���������';
	else stamsg = '��Ϊ��ͨ����';

	if(window.confirm("��ȷ��Ҫ����Щ����"+stamsg+"ô��"))
	{
		location = "friend.php?dopost=upsta&sta="+sta+"&ids="+selid+"&ftype="+ftype;
	}
}

function EditMemberGroup(mid)
{
   var taget_obj = document.getElementById('mgp'+mid);
   var myajax = new DedeAjax(taget_obj,false,false,"","","");
   myajax.SendGet2("ajax_membergroup.php?action=show&mid="+mid);
   DedeXHTTP = null;
}

function postMemberGroup(mid){
   obj = document.getElementById('mgp'+mid);
   v = document.getElementById('m_'+mid).value;
   var myajax = new DedeAjax(obj,false,false,"","","");
   <?php
   if(strtolower(substr($cfg_soft_lang, 0, 3)) == 'utf') {
   ?>
   myajax.AddKeyUtf8('action','post');
   myajax.AddKeyUtf8('mid',mid);
   myajax.AddKeyUtf8('membergroup',v);
   myajax.SendPost2('ajax_membergroup.php');
   <?php
   }
   elseif (strtolower(substr($cfg_soft_lang, 0, 2)) == 'gb') {
   	 echo 'myajax.SendGet2("ajax_membergroup.php?action=show&mid="+mid+"&action=post&membergroup="+v);';
   }
   ?>
   DedeXHTTP = null;
}

function EditDescription(mid)
{
   var taget_obj = document.getElementById('des'+mid);
   var myajax = new DedeAjax(taget_obj,false,false,"","","");
   myajax.SendGet2("ajax_membergroup.php?action=desshow&mid="+mid);
   DedeXHTTP = null;
}

function postDescription(mid){
   obj = document.getElementById('des'+mid);
   v = document.getElementById('m_'+mid).value;
   var myajax = new DedeAjax(obj,false,false,"","","");
   <?php
   if(strtolower(substr($cfg_soft_lang, 0, 3)) == 'utf') {
   ?>
   myajax.AddKeyUtf8('action','post');
   myajax.AddKeyUtf8('mid',mid);
   myajax.AddKeyUtf8('mdescription',v);
   myajax.SendPost2('ajax_membergroup.php');
   <?php
   }
   elseif (strtolower(substr($cfg_soft_lang, 0, 2)) == 'gb') {
   	 echo 'myajax.SendGet2("ajax_membergroup.php?action=desshow&mid="+mid+"&action=despost&mdescription="+v);';
   }
   ?>
   DedeXHTTP = null;
}
</script>
</head>
<body>
<?php include(DEDEMEMBER."/templets/head@@.htm"); ?>
<DIV class=content-box>
<DIV class=content-box-header>
<H3>�ҵĺ���</H3>
<DIV class=clear></DIV></DIV>
<DIV class=content-box-content>
    <div id="mcpmain">
      <div id="appTab">
        <ul>
          <li class="thisTab"><a href="friend.php?ftype=0"><span>���к���</span></a></li>
          <li><a href="history.php?dopost=viewme"><span>��ע�ҵ���</span></a></li>
          <li><a href="history.php?dopost=meview"><span>���������</span></a></li>
        </ul>
      </div>
      <ul class="tabSub">
        <li <?php echo ($ftype==0)? "class='thisTab'" : "";?>><a href="friend.php?ftype=0"><span>ȫ��</span></a></li>
        <li <?php echo ($ftype==1)? "class='thisTab'" : "";?>><a href="friend.php?ftype=1"><span>��ע����</span></a></li>
        <li <?php echo ($ftype==-1)? "class='thisTab'" : "";?>><a href="friend.php?ftype=-1"><span>������</span></a></li>
      </ul>
      <form name='form1' action="friend.php" method="post">
        <input type='hidden' name='ftype' value='del' />
        <div id="mainCp">
        <h3 class="meTitle">
        	<?php if($ftype == '0') echo '���к���'; if($ftype == '1') echo '��ע����'; if($ftype == '-1') echo '������';?>
            (<?php echo $dlist->totalResult;?>)
        </h3>
        <ul class="listStyle3">
        <?php
$atts = array();
$atts['tagname'] = 'datalist';
$blockValue = $this->refObj->GetArcList($atts,$this->refObj,$fields); 
if(is_array($blockValue)){
foreach( $blockValue as $key=>$fields )
{
?>
          <li class="clearfix">
            <div class="frdInfo">
              <table width="100%" border="0" cellspacing="0" cellpadding="0">
                <tr>
                  <td colspan="3" align="left" valign="middle" class="userTitle"><a href='index.php?uid=<?php echo urlencode($fields['floginid']); ?>' target='_blank'><?php echo $fields['funame']; ?></a>
                    <div class="fRight">
                      <input type="checkbox" name="selid" value="<? echo $fields['id']; ?>" />
                    </div ></td>
                </tr>
                <tr>
                  <td width="40%">���ϣ�<?php echo getUserInfo($fields['fid'],'sex'); 
                  	if(!getUserInfo($fields['fid'],'age')=="")
                    {
                  		echo ",".getUserInfo($fields['fid'],'age')."��";
                        echo ",".getUserInfo($fields['fid'],'birthday');
                   	}
                  ?></td>
                  <td class="doPost"></td>
                  <td align="right" class="doPost"  width="20%"><a href="pm.php?dopost=send&uid=<?php echo urlencode($fields['floginid']); ?>">����������Ϣ</a></td>
                </tr>
                <tr>
                  <td>����: <?php echo getUserInfo($fields['fid'],'email');?></td>
                  <td class="doPost"></td>
                  <td align="right" class="doPost"><a href="index.php?action=delfriend&uid=<?php echo urlencode($fields['floginid']); ?>">������ѹ�ϵ</a></td>
                </tr>
              </table>
            </div>
            <img src="<?php echo getUserInfo($fields['fid'],'face');?>" width="100" height="100" /></li>
         <?php
}
}?>
        </ul>
        <div class="listDo appMsg">
          <div class="control fLeft">
            <button id="checkedClick" type="button" class="button">ȫѡ</button>&nbsp;
            <button class="button" onclick="DelSel('<?php echo $ftype; ?>');" type="button" >ɾ��</button>&nbsp;
           <?php if(empty($ftype)) { ?>
            <button class="button" onclick="ConvSta('good','<?php echo $ftype; ?>');" type="button" >��ע</button>&nbsp;
            <button class="button" onclick="ConvSta('bad','<?php echo $ftype; ?>');" type="button" >���������</button>&nbsp;
           <?php }else { ?>
            <button class="button" onclick="ConvSta('common','<?php echo $ftype; ?>');" type="button"  >��ԭΪ��ͨ</button>
           <?php } ?>
          </div>
          <div class="pageList fRight"><?php
$atts = array();
$atts['tagname'] = 'pagelist';
$atts['listsize'] = '5';
 echo $this->refObj->GetPageList($atts,$this->refObj,$fields); 
?>
</div>
        </div>
      </div></div>
      </form>
      <!--���������� -->
    </div>
  </div>
  <?php include(DEDEMEMBER."/templets/foot@@.htm"); ?>
</div>
</body>
</html>