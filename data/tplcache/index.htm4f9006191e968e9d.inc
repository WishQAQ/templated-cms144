<?php
$z[0]=Array("global","",325,352);
$z[0][4]['name']="cfg_keywords";
$z[1]=Array("global","",392,422);
$z[1][4]['name']="cfg_description";
$z[2]=Array("global","",457,489);
$z[2][4]['name']="cfg_templets_skin";
$z[3]=Array("global","",635,667);
$z[3][4]['name']="cfg_templets_skin";
$z[4]=Array("global","",742,774);
$z[4][4]['name']="cfg_templets_skin";
$z[5]=Array("global","",848,880);
$z[5][4]['name']="cfg_templets_skin";
$z[6]=Array("global","",958,990);
$z[6][4]['name']="cfg_templets_skin";
$z[7]=Array("include","",1342,1377);
$z[7][4]['filename']="head.htm";
$z[8]=Array("arclist","\r\n        	<div class=\"item\">\r\n\r\n			\r\n<A href=\"[field:arcurl/]\"><IMG alt=\"[field:title/]\" src=\"[field:litpic/]\" height=\"200\" width=\"300\"></A><p><a href=\"[field:arcurl/]\">[field:title/]</a>\r\n  \r\n\r\n			\r\n			</div>\r\n",1457,1758);
$z[8][4]['flag']="c";
$z[8][4]['row']="3";
$z[8][4]['titlelen']="40";
$z[8][4]['orderby']="rand";
$z[8][4]['type']="image.";
$z[9]=Array("arclist","\r\n        	<div class=\"item\">\r\n\r\n			\r\n<A href=\"[field:arcurl/]\"><IMG alt=\"[field:title/]\" src=\"[field:litpic/]\" height=\"200\" width=\"300\"></A><p><a href=\"[field:arcurl/]\">[field:title/]</a>\r\n  \r\n\r\n			\r\n			</div>\r\n",1791,2092);
$z[9][4]['flag']="c";
$z[9][4]['row']="3";
$z[9][4]['titlelen']="40";
$z[9][4]['orderby']="rand";
$z[9][4]['type']="image.";
$z[10]=Array("arclist","\r\n        	<div class=\"item\">\r\n\r\n			\r\n<A href=\"[field:arcurl/]\"><IMG alt=\"[field:title/]\" src=\"[field:litpic/]\" height=\"200\" width=\"300\"></A><p><a href=\"[field:arcurl/]\">[field:title/]</a>\r\n  \r\n\r\n			\r\n			</div>\r\n",2125,2426);
$z[10][4]['flag']="c";
$z[10][4]['row']="3";
$z[10][4]['titlelen']="40";
$z[10][4]['orderby']="rand";
$z[10][4]['type']="image.";
$z[11]=Array("arclist","\r\n  <A href=\"[field:arcurl/]\" target=\"_blank\">[field:title/]</A>\r\n 	\r\n				\r\n            </h2>\r\n            <p><span class=\"c1\">作者：[field:writer /]</span><span class=\"c2\">[field:pubdate function=\"GetDateTimeMK(@me)\"/]</span></p>\r\n            <div class=\"c3\">[field:click/] ℃</div>\r\n        </div>\r\n        <div class=\"m_Grid1\">\r\n        	<img src=\"[field:litpic/]\" alt=\"[field:title/]\" height=\"400\" width=\"610\" />\r\n            <p class=\"p1\">[field:info  function=\"cn_substr(@me,360)\"/] ...</p>\r\n            <p class=\"p2\"><span>标签：</span>\r\n[field:id function=GetTags(@me)/]\r\n			</p>\r\n\r\n            <p class=\"p3\"><a href=\"[field:arcurl/]\" target=\"_blank\">共[field:click/]人看过，阅读全文>></a></p>\r\n			\r\n",2632,3414);
$z[11][4]['row']="1";
$z[11][4]['titlelen']="42";
$z[11][4]['flag']="h";
$z[11][4]['type']="image.";
$z[12]=Array("arclist","      \r\n        <div class=\"m_Grid2\">\r\n        	<div class=\"m_T2\">\r\n\r\n            	<p class=\"p4\"><a href=\"[field:arcurl/]\"><b>[field:title/]</b></a></p>\r\n                <p class=\"p5\">\r\n                	<span class=\"c4\">[field:typelink/]</span>\r\n                    <span class=\"c5\">[field:pubdate function=strftime('%Y.%m.%d',@me)/]</span>\r\n                    <span class=\"c6\">[field:click/]次浏览</span>\r\n                </p>\r\n            </div>\r\n            <div class=\"m_Box1\">\r\n            	<a href=\"[field:arcurl/]\"><img src=\"[field:litpic/]\" alt=\"[field:title/]\" height=\"100\" width=\"150\" /></a>\r\n		[field:description/]...\r\n            </div>\r\n            <div class=\"d1\">\r\n            	<span class=\"c7\">作者：[field:writer /]</span>\r\n                <span class=\"c8\">标签：\r\n[field:id runphp='yes']  \r\n    global \$cfg_cmspath;  \r\n       \$tags = GetTags(@me);  \r\n       \$revalue = '';  \r\n       \$tags = explode(',', \$tags);  \r\n        foreach(\$tags as \$key => \$value){  \r\n           if(\$value){  \r\n               \$revalue .= '<a href=\"'.\$cfg_cmspath.'/tags.php?/'.\$value.'/\">'.\$value.'</a>&nbsp;';           \r\n            }  \r\n       }  \r\n        @me = \$revalue;  \r\n    [/field:id]\r\n\r\n            	</span><div class=\"c9\"><a title=\"[field:title function='htmlspecialchars(@me)'/]\" href=\"[field:arcurl/]\">阅读全文</a></div>\r\n            </div>\r\n            </div>",3445,4883);
$z[12][4]['row']="9";
$z[12][4]['titlelen']="42";
$z[12][4]['orderby']="sortrank";
$z[13]=Array("global","",5327,5359);
$z[13][4]['name']="cfg_templets_skin";
$z[14]=Array("global","",5485,5517);
$z[14][4]['name']="cfg_templets_skin";
$z[15]=Array("global","",5913,5945);
$z[15][4]['name']="cfg_templets_skin";
$z[16]=Array("global","",6036,6068);
$z[16][4]['name']="cfg_templets_skin";
$z[17]=Array("arclist","\r\n<a title=\"[field:title function='htmlspecialchars(@me)'/]\" href=\"[field:arcurl /]\">[field:title /]</a>\r\n",6194,6367);
$z[17][4]['orderby']="click";
$z[17][4]['titlelen']="40";
$z[17][4]['row']="9";
$z[18]=Array("arclist","\r\n        	<li><a href=\"[field:arcurl/]\"><img src=\"[field:litpic/]\" alt=\"[field:title function='htmlspecialchars(@me)'/]\" height=\"168\" width=\"120\" />[field:title /]</a></li>\r\n",6509,6764);
$z[18][4]['orderby']="rand";
$z[18][4]['titlelen']="20";
$z[18][4]['row']="2";
$z[18][4]['type']="image.";
$z[19]=Array("arclist","\r\n<li><a title=\"[field:title function='htmlspecialchars(@me)'/]\" href=\"[field:arcurl /]\">[field:title /]</a></li>\r\n",6812,6993);
$z[19][4]['orderby']="rand";
$z[19][4]['titlelen']="40";
$z[19][4]['row']="5";
$z[20]=Array("arclist","\r\n<li><a title=\"[field:title function='htmlspecialchars(@me)'/]\" href=\"[field:arcurl /]\">[field:title /]</a></li>\r\n",7197,7381);
$z[20][4]['orderby']="pubdate";
$z[20][4]['titlelen']="40";
$z[20][4]['row']="8";
$z[21]=Array("global","",7673,7705);
$z[21][4]['name']="cfg_templets_skin";
$z[22]=Array("global","",7848,7880);
$z[22][4]['name']="cfg_templets_skin";
$z[23]=Array("global","",8030,8062);
$z[23][4]['name']="cfg_templets_skin";
$z[24]=Array("flink","",8879,8912);
$z[24][4]['row']="24";
$z[24][4]['linktype']="1";
$z[25]=Array("include","",8971,9008);
$z[25][4]['filename']="footer.htm";

?>