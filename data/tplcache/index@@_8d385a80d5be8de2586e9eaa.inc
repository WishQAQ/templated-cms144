<?php
if(!isset($GLOBALS['_vars'])) $GLOBALS['_vars'] = array(); 
$fields = array();
?><!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<HEAD>
<META content="text/html; charset=gbk" http-equiv=Content-Type>
<META content=IE=EmulateIE7 http-equiv=X-UA-Compatible>
<META name=GENERATOR content="MSHTML 8.00.7601.17785">
<TITLE>�û�����-<?php echo $cfg_webname; ?></TITLE>
<link href="templets/style/boxy.css" rel="stylesheet" type="text/css" />
<script type="text/javascript" src="templets/js/jquery.js"></script>
<script type="text/javascript" src="templets/js/face.js"></script>
<script language='javascript'>
	function msgSubmit(form) {
		//var id=form.id.value;
		var content = form.share_textarea.value;
		if( content == '���黹��������߶��ɶ��...' ) content = '';
		if ( content == '' ) {
			alert('����������'); return false;
		}
		$.ajax({
			type:'POST',
			url:'index_do.php?fmdo=moodmsg&dopost=sendmsg',
			cache:false,
			data:'&content='+encodeURIComponent(content),
			dataType:'json',
			success:function(message){
				if ( message.type == 'success' ) {
					$('#share_textarea').val('');
					$('#moodcontent').html(message.data);
				} else {
					alert(message.data);
				}
			}
		});
	}
</script>
</HEAD>
<BODY>
<?php include(DEDEMEMBER."/templets/head_inc@@.htm"); ?>


<DIV class=content-box>
<DIV class=content-box-header>
<H3>���˵�</H3>
<DIV class=clear></DIV></DIV>
<DIV class=content-box-content>
 <div class="imgLink"> <a href="<?php echo $cfg_cmsurl;?>/member/index.php?uid=<?php echo $cfg_ml->M_LoginID; ?>" title="����ռ�" target=_blank><img src="<?php echo $cfg_ml->fields['face']; ?>" width="100" height="100" alt="����ռ�"/></a></div>
<p class="lh22 tc"><a class="blue uline" href="grsz.php">�༭����</a>
            <a class="blue uline" href="tx.php">�޸�ͷ��</a></p>
  <div class="mood_user">
            <em><?php echo $cfg_ml->M_LoginID; ?></em>
            <i class="focus"> ����<b><?php echo $minfos['friend']; ?></b>��</i>
            <i class="fans">���±�����<b><?php echo $minfos['pagecount']; ?></b>��</i>
        </div>
		<DIV class="notification1 information1">
            <?php
             if(is_array($moodmsg)){
            ?>
            <li class="other" id="moodcontent"><?php echo $moodmsg['msg'];?></li>
            <?php
              } else {
            ?>
             <li class="other" id="moodcontent">����������Σ��������������������д</li>
             <?php
             }
             ?>
          </DIV>
      <div class="share">
         <form target="hidden_frame" method="post" enctype="multipart/form-data" name="msgmood" action="#">
            <input id="share_textarea" type="text" value="���黹��������߶��ɶ��..." onclick="showFace()"/>
            <button id="btn_submit" type="button" onclick="msgSubmit(this.form)">����</button>
          </form>
      </div>
 </DIV></DIV>
<!--<DIV class=clear></DIV>
<DIV class=content-box>
<DIV class=content-box-header>
<H3>�ҵ�����</H3>
<DIV class=clear></DIV></DIV>
<DIV class=content-box-content>
<DIV class="notification information png_bg">
<DIV>ĿǰΪֹ�������� <?php echo $minfos['article']; ?> ������, 
���� <?php echo $minfos['homecount']; ?> ��, 
ʹ�ÿռ� <?php echo $minfos['totaluse']."/".$cfg_mb_max; ?>MB, 
��Ϣ<a href="pm.php?TB_iframe=true&height=600&width=700" title="�ҵĶ���Ϣ" target="_blank"><?php echo $pms['nums'];?></a>
</DIV></DIV></DIV></DIV>
<DIV class=clear></DIV>-->
<?php include(DEDEMEMBER."/templets/foot@@.htm"); ?>
</BODY></HTML>