<?php
if(!isset($GLOBALS['_vars'])) $GLOBALS['_vars'] = array(); 
$fields = array();
?><!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<HEAD>
<META content="text/html; charset=gbk" http-equiv=Content-Type>
<META content=IE=EmulateIE7 http-equiv=X-UA-Compatible>
<META name=GENERATOR content="MSHTML 8.00.7601.17785">
<TITLE>用户中心-<?php echo $cfg_webname; ?></TITLE>
<link href="templets/style/boxy.css" rel="stylesheet" type="text/css" />
<script type="text/javascript" src="templets/js/jquery.js"></script>
<script type="text/javascript" src="templets/js/face.js"></script>
<script language='javascript'>
	function msgSubmit(form) {
		//var id=form.id.value;
		var content = form.share_textarea.value;
		if( content == '心情还好吗？来唠叨点啥吧...' ) content = '';
		if ( content == '' ) {
			alert('请输入心情'); return false;
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
<H3>个人档</H3>
<DIV class=clear></DIV></DIV>
<DIV class=content-box-content>
 <div class="imgLink"> <a href="<?php echo $cfg_cmsurl;?>/member/index.php?uid=<?php echo $cfg_ml->M_LoginID; ?>" title="进入空间" target=_blank><img src="<?php echo $cfg_ml->fields['face']; ?>" width="100" height="100" alt="进入空间"/></a></div>
<p class="lh22 tc"><a class="blue uline" href="grsz.php">编辑资料</a>
            <a class="blue uline" href="tx.php">修改头像</a></p>
  <div class="mood_user">
            <em><?php echo $cfg_ml->M_LoginID; ?></em>
            <i class="focus"> 好友<b><?php echo $minfos['friend']; ?></b>人</i>
            <i class="fans">文章被访问<b><?php echo $minfos['pagecount']; ?></b>次</i>
        </div>
		<DIV class="notification1 information1">
            <?php
             if(is_array($moodmsg)){
            ?>
            <li class="other" id="moodcontent"><?php echo $moodmsg['msg'];?></li>
            <?php
              } else {
            ?>
             <li class="other" id="moodcontent">今天心情如何？试试在左面输入框中填写</li>
             <?php
             }
             ?>
          </DIV>
      <div class="share">
         <form target="hidden_frame" method="post" enctype="multipart/form-data" name="msgmood" action="#">
            <input id="share_textarea" type="text" value="心情还好吗？来唠叨点啥吧..." onclick="showFace()"/>
            <button id="btn_submit" type="button" onclick="msgSubmit(this.form)">发表</button>
          </form>
      </div>
 </DIV></DIV>
<!--<DIV class=clear></DIV>
<DIV class=content-box>
<DIV class=content-box-header>
<H3>我的文章</H3>
<DIV class=clear></DIV></DIV>
<DIV class=content-box-content>
<DIV class="notification information png_bg">
<DIV>目前为止共发布了 <?php echo $minfos['article']; ?> 个文章, 
人气 <?php echo $minfos['homecount']; ?> 个, 
使用空间 <?php echo $minfos['totaluse']."/".$cfg_mb_max; ?>MB, 
消息<a href="pm.php?TB_iframe=true&height=600&width=700" title="我的短信息" target="_blank"><?php echo $pms['nums'];?></a>
</DIV></DIV></DIV></DIV>
<DIV class=clear></DIV>-->
<?php include(DEDEMEMBER."/templets/foot@@.htm"); ?>
</BODY></HTML>