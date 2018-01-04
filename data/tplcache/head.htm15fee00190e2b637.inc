<?php
$z[0]=Array("global","",494,519);
$z[0][4]['name']="cfg_cmsurl";
$z[1]=Array("global","",1101,1127);
$z[1][4]['name']="cfg_cmspath";
$z[2]=Array("channel","\r\n<li><a href=\"[field:typelink/]\" target=\"_blank\" title=\"\">[field:typename/]</a></li> \r\n",1318,1461);
$z[2][4]['typeid']="10";
$z[2][4]['noself']="yes";
$z[3]=Array("channelartlist","\r\n<li class=\"menu-item mega-menu menu-item-type-taxonomy mega-menu menu-item-object-category mega-menu menu-item-has-children parent-list\"> <a href=\"{dede:field name='typeurl'/}\">{dede:field name='typename'/}<span class=\"sub-indicator\"></span></a><!-- 顶级栏目 -->\r\n<div class=\"mega-menu-block\">\r\n<div class=\"mega-menu-content\"> \r\n<!-- 当前栏目带图头条 --> \r\n{dede:arclist orderby='rand' row='3' titlelen='60' type='image'}\r\n<div class=\"mega-menu-item \"> <a href=\"[field:arcurl/]\" title=\"[field:title/]\"> <img src=\"[field:litpic/]\" width=\"235\" height=\"117\"></a>\r\n<h3 class=\"post-box-title\"> <a class=\"mega-menu-link\" href=\"[field:arcurl/]\" title=\"[field:title/]\">[field:title/]</a> </h3>\r\n</div>\r\n{/dede:arclist} \r\n<!-- 当前栏目带图头条结束 --> \r\n</div>\r\n<!--当前子栏目-->\r\n<ul class=\"sub-menu\">\r\n{dede:channel type='son' noself='yes'}\r\n<li class=\"menu-item  menu-item-type-taxonomy  menu-item-object-category\"> <a href=\"[field:typelink/]\">[field:typename/]</a></li>\r\n{/dede:channel}\r\n</ul>\r\n<!--当前子栏目end--> \r\n</div>\r\n</li>\r\n",3068,4160);
$z[3][4]['typeid']="1,2,3,4,7";

?>