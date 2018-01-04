<!DOCTYPE html>
<head>
<meta http-equiv="Cache-Control" content="must-revalidate,no-cache,no-transform">
<meta content="mobiSiteGalore" name="Generator" />
<meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1"/>
<meta name="apple-touch-fullscreen" content="YES" />
<meta name="apple-mobile-web-app-capable" content="yes" />
<meta name="viewport" content="width=device-width, user-scalable=no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0" />
<meta name="format-detection" content="telephone=no">
<title><?php echo $cfg_webname;?></title>
<link href="<?php echo $cfg_cmspath;?>/wap/all.css" rel="stylesheet" type="text/css">
<script src="<?php echo $cfg_cmspath;?>/wap/images/jquery.js" type="text/javascript"></script>
<script type="text/javascript" src="<?php echo $cfg_cmspath;?>/wap/images/jquery.flexslider-min.js"></script>
<script type="text/javascript" src="<?php echo $cfg_cmspath;?>/wap/images/jquery.nivo.slider.pack.html"></script>
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
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"></head>
<body>
<header>
<div class="topbar"><a class="home" href="<?php echo $cfg_cmspath;?>/wap.php"></a><div class="webname"><?php echo $cfg_webname;?></div><a class="catebar" href="#">导航</a></div>
<nav style="display:none;"><?php echo $channellist;?></nav>
</header>
<main>
<section>
<h3>推荐新闻</h3>
<ul class="list2"><?php echo $newpiclist;?></ul>	
<div class="hotfoucs">
<h3>最新文章</h3>
<?php echo $hotfoucs;?>
</div>

  </section> 
  </main>
  <footer><?php echo $cfg_powerby;?></footer>
</body>
</html>