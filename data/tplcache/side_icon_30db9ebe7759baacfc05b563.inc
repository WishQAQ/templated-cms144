<?php
if(!isset($GLOBALS['_vars'])) $GLOBALS['_vars'] = array(); 
$fields = array();
?><!-- //begin icon -->
<div class="box" id="side_icon">
	  <h2>��������</h2>
	  <div class="profile">
		<div class="text">
		  <div class="profile-pic">
		  	<span id="msg"></span>
			<div>
			<?php if($_vars['face']==''){ ?>
	<img src="images/nopic.gif" alt="nopic" />
	<?php
}
else{
?>
	<img src="<?php echo $GLOBALS['_vars']['face']; ?>" alt="<?php echo $GLOBALS['_vars']['uname']; ?>" />
	<?php } ?>
			</div>
		  </div>
          <div style="height:30px;text-align:center"><?php echo $GLOBALS['_vars']['msg']; ?></div>
		  <dl class="profile">
			<dd class="tac" style="word-break:keep-all">
			  <img src="space/person/images/talk.gif" align="absmiddle" /><a href="index.php?action=guestbook&uid=<?php echo $GLOBALS['_vars']['userid']; ?>">����</a> |
			  <img src="space/person/images/message.gif" align="absmiddle" /><a href="pm.php?dopost=send&uid=<?php echo $GLOBALS['_vars']['userid']; ?>">����Ϣ</a> |
				<img src="space/person/images/team.gif" align="absmiddle" /><a href="index.php?action=newfriend&uid=<?php echo $GLOBALS['_vars']['userid']; ?>">�Ӻ���</a> |
			  <img src="space/person/images/del.png" align="absmiddle" /><img src="space/person/images/addto.gif" align="absmiddle" /><a href="index.php?action=blackfriend&uid=<?php echo $GLOBALS['_vars']['userid']; ?>">�Ӻ�����</a>

			</dd>
			<dd style='margin-top:10px;'>&nbsp;�û��ǳƣ�<?php echo $GLOBALS['_vars']['uname']; ?></dd>
			<dd>&nbsp;����¼��<?php echo MyDate('y-m-d h:i',$GLOBALS['_vars']['logintime']); ?></dd>
			<dd>&nbsp;��Ա�ȼ���<?php echo $GLOBALS['_vars']['membername']; ?></dd>
      <dd>&nbsp;��Ա���֣�<?php echo $GLOBALS['_vars']['scores']; ?> ��</dd>
			<dd>&nbsp;�ռ���ʣ�<?php echo $GLOBALS['_vars']['homecount']; ?> ��</dd>
		  </dl>
		</div>
	  </div>
</div>
<!-- //end icon -->