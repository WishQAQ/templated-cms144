<?php
if(!isset($GLOBALS['_vars'])) $GLOBALS['_vars'] = array(); 
$fields = array();
?><!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN">
<HTML xmlns="http://www.w3.org/1999/xhtml"><HEAD><title>�ÿ���ʷ��¼ - �û����� - <?php echo $cfg_webname; ?></title>
<META content="text/html; charset=gbk" http-equiv=Content-Type>
<META content=IE=EmulateIE7 http-equiv=X-UA-Compatible><META name=GENERATOR content="MSHTML 8.00.7601.17785"></HEAD>
<BODY>
<?php include(DEDEMEMBER."/templets/head@@.htm"); ?>

<DIV class=content-box>
<DIV class=content-box-header>
<H3>�ÿ���ʷ��¼</H3>
<DIV class=clear></DIV></DIV>
<DIV class=content-box-content>


  <div id="content" class="w960 clearfix">



    <div id="mcpmain">
      <div id="appTab">
        <ul>
          <li><a href="friend.php?ftype=0"><span>���к���</span></a></li>
          <li <?php if($dopost == "viewme" || empty($dopost)) echo 'class="thisTab"';?>><a href="history.php?dopost=viewme"><span>��ע�ҵ���</span></a></li>
          <li <?php if($dopost == "meview") echo 'class="thisTab"';?>><a href="history.php?dopost=meview"><span>���������</span></a></li>
        </ul>
      </div>
      <div id="mainCp">
        <ul class="listStyle3">
        <?php
$atts = array();
$atts['tagname'] = 'datalist';
$blockValue = $this->refObj->GetArcList($atts,$this->refObj,$fields); 
if(is_array($blockValue)){
foreach( $blockValue as $key=>$fields )
{
 if($dopost == "viewme" || $dopost==''){ ?>
<li class="clearfix">
  <div class="frdInfo">
    <table width="100%" border="0" cellspacing="0" cellpadding="0">
      <tr>
        <td colspan="3" align="left" valign="middle" class="userTitle"><a href='index.php?uid=<?php echo $fields['vloginid']; ?>' target='_blank'><?php echo $fields['vloginid']; ?></a>
          </td>
        </tr>
      <tr>
        <td>���� <strong><?php echo $fields['count']; ?></strong> ��</td>
        <td>����ʱ�䣺<?php echo MyDate('Y-m-d',$fields['vtime']); ?></td>
        <td align="right" class="doPost"><a href='index.php?uid=<?php echo $fields['vloginid']; ?>&action=infos' target='_blank'>[����]</a></td>
        </tr>
      <tr>
        <td>�Ա�<?php echo $fields['sex']; ?></td>
        <td class="doPost"><a href='index.php?action=newfriend&uid=<?php echo $fields['vloginid']; ?>' target='_blank'>��Ϊ����</a></td>
        <td align="right" class="doPost"><a href='index.php?uid=<?php echo $fields['vloginid']; ?>&action=guestbook' target='_blank'>[����]</a></td>
        </tr>
      </table>
    </div>
   <img src="<?php if(empty($fields['face'])){$face=($fields['sex']=='Ů')? 'templets/images/dfgirl.png' : 'templets/images/dfboy.png';}else{ $face=$fields['face'];} echo $face;?>" width='60' height='60'/></li>
  <?php }else{ ?>
  <li class="clearfix">
  <div class="frdInfo">
    <table width="100%" border="0" cellspacing="0" cellpadding="0">
      <tr>
        <td colspan="3" align="left" valign="middle" class="userTitle"><a href='index.php?uid=<?php echo urlencode($fields['loginid']); ?>' target='_blank'> <?php echo $fields['loginid']; ?></a>
         </td>
      </tr>
      <tr>
        <td>���� <strong><?php echo $fields['count']; ?></strong> ��</td>
        <td>����ʱ�䣺<?php echo MyDate('Y-m-d',$fields['vtime']); ?></td>
        <td align="right" class="doPost"><a href='index.php?uid=<?php echo $fields['loginid']; ?>&action=infos' target='_blank'>[����]</a></td>
        </tr>
      <tr>
        <td>�Ա�<?php echo $fields['sex']; ?></td>
        <td class="doPost"><a href='index.php?action=newfriend&uid=<?php echo $fields['loginid']; ?>' target='_blank' >��Ϊ����</a></td>
        <td align="right" class="doPost"><a href='index.php?uid=<?php echo $fields['loginid']; ?>&action=guestbook' target='_blank'>[����]</a></td>
        </tr>
      </table>
    </div>
      <img src="<?php if(empty($fields['face'])){$face=($fields['sex']=='Ů')? 'templets/images/dfgirl.png' : 'templets/images/dfboy.png';}else{ $face=$fields['face'];} echo $face;?>" width='60' height='60'/></li>
          <?php } 
}
}?>
        </ul>
        <div style="clear:both"></div>
        <div class="listDo appMsg">
          <div class="control fLeft">
          </div>
          <div class="pageList fRight"><?php
$atts = array();
$atts['tagname'] = 'pagelist';
$atts['listsize'] = '5';
 echo $this->refObj->GetPageList($atts,$this->refObj,$fields); 
?>
</div>
        </div>
      </div>
      <!--���������� -->
      <!--���������� -->
    </div>
  </div>





</DIV>
<DIV class=clear></DIV>
<?php include(DEDEMEMBER."/templets/foot@@.htm"); ?>
</BODY></HTML>