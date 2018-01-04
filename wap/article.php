<!DOCTYPE html>
<head>
<meta http-equiv="Cache-Control" content="must-revalidate,no-cache,no-transform">
<meta content="mobiSiteGalore" name="Generator" />
<meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1"/>
<meta name="apple-touch-fullscreen" content="YES" />
<meta name="apple-mobile-web-app-capable" content="yes" />
<meta name="viewport" content="width=device-width, user-scalable=no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0" />
<meta name="format-detection" content="telephone=no">
<title><?php echo $title; ?></title>
<link href="<?php echo $cfg_cmspath; ?>/wap/all.css" rel="stylesheet" type="text/css">
<script src="<?php echo $cfg_cmspath; ?>/wap/images/jquery.js" type="text/javascript"></script>
<script type="text/javascript" src="<?php echo $cfg_cmspath; ?>/wap/images/jquery.flexslider-min.js"></script>
<script type="text/javascript" src="<?php echo $cfg_cmspath; ?>/wap/images/jquery.nivo.slider.pack.html"></script>
<script type="text/javascript">
$(document).ready(function(){
  $(".catebar").click(function(){
  $("nav").slideToggle();
  });
});
$(window).load(function() {
$(".flexslider").flexslider();
});
</script>
</head>
<body>
<header>
  <div class="topbar"><a class="home" href="<?php echo $cfg_cmspath;?>/wap.php"></a>
    <div class="webname"><?php echo $cfg_webname; ?></div>
    <a class="catebar" href="#">导航</a></div>
  <nav style="display: none;"><?php echo $channellist; ?></nav>
</header>
<main>
  <section> 
  <h3><a href="wap.php">首页</a> &gt; <a href="wap.php?action=list&amp;id=<?php echo $typeid; ?>"><?php echo $typename; ?></a> &gt; 详细内容</h3>
  <article class="pd10">
  <h1><?php echo $title; ?></h1>
  <div class="info">发布时间:<time><?php echo $pubdate; ?></time>&nbsp;&nbsp;浏览:<?php echo $click; ?> 次&nbsp;&nbsp;作者:<?php echo $writer; ?></div>
  <div class="content">
  <?php echo $body; ?>
  <p class="tags">关键词：<?php echo $tags;?></p>
  </div>
  </article>
  <h3>相关文章</h3>
  <ul class="list1 pd10">
 <?php echo $likearticle;?>
  </ul>
  <div class="backlist"><a href="wap.php?action=list&amp;id=<?php echo $typeid; ?>">返回：【<?php echo $typename; ?>】栏目列表</a></div>
  </section>
</main>
<footer><?php echo $cfg_powerby; ?></footer>
<?php echo "</body></html>";
?>