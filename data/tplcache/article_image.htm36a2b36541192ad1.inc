<?php
$z[0]=Array("field","",255,274);
$z[0][4]['name']="title";
$z[1]=Array("global","",277,303);
$z[1][4]['name']="cfg_webname";
$z[2]=Array("global","",344,371);
$z[2][4]['name']="cfg_keywords";
$z[3]=Array("field","",409,467);
$z[3][4]['name']="description";
$z[3][4]['function']="html2text(@me)";
$z[4]=Array("global","",500,532);
$z[4][4]['name']="cfg_templets_skin";
$z[5]=Array("global","",585,617);
$z[5][4]['name']="cfg_templets_skin";
$z[6]=Array("global","",685,717);
$z[6][4]['name']="cfg_templets_skin";
$z[7]=Array("global","",801,833);
$z[7][4]['name']="cfg_templets_skin";
$z[8]=Array("global","",994,1026);
$z[8][4]['name']="cfg_templets_skin";
$z[9]=Array("global","",1101,1133);
$z[9][4]['name']="cfg_templets_skin";
$z[10]=Array("global","",1207,1239);
$z[10][4]['name']="cfg_templets_skin";
$z[11]=Array("global","",1317,1349);
$z[11][4]['name']="cfg_templets_skin";
$z[12]=Array("global","",1441,1466);
$z[12][4]['name']="cfg_cmsurl";
$z[13]=Array("global","",1936,1961);
$z[13][4]['name']="cfg_cmsurl";
$z[14]=Array("field","",2919,2946);
$z[14][4]['name']="phpurl";
$z[15]=Array("global","",3791,3816);
$z[15][4]['name']="cfg_phpurl";
$z[16]=Array("global","",4061,4086);
$z[16][4]['name']="cfg_phpurl";
$z[17]=Array("global","",4159,4187);
$z[17][4]['name']="art_shortname";
$z[18]=Array("field","",4205,4233);
$z[18][4]['name']="nowpage";
$z[19]=Array("field","",4253,4283);
$z[19][4]['name']="totalpage";
$z[20]=Array("field","",4303,4332);
$z[20][4]['name']="namehand";
$z[21]=Array("field","",4356,4388);
$z[21][4]['name']="displaytype";
$z[22]=Array("field","",4968,4991);
$z[22][4]['name']="id";
$z[23]=Array("field","",5148,5171);
$z[23][4]['name']="id";
$z[24]=Array("field","",5438,5461);
$z[24][4]['name']="id";
$z[25]=Array("include","",5551,5586);
$z[25][4]['filename']="head.htm";
$z[26]=Array("arclist","\r\n        	<div class=\"item\">\r\n\r\n			\r\n<A href=\"[field:arcurl/]\"><IMG alt=\"[field:title/]\" src=\"[field:litpic/]\" height=\"200\" width=\"300\"></A><p><a href=\"[field:arcurl/]\">[field:title/]</a></p>\r\n  \r\n\r\n			\r\n			</div>\r\n",5666,5962);
$z[26][4]['row']="3";
$z[26][4]['titlelen']="24";
$z[26][4]['orderby']="rand";
$z[26][4]['type']="image.";
$z[27]=Array("arclist","\r\n        	<div class=\"item\">\r\n\r\n			\r\n<A href=\"[field:arcurl/]\"><IMG alt=\"[field:title/]\" src=\"[field:litpic/]\" height=\"200\" width=\"300\"></A><p><a href=\"[field:arcurl/]\">[field:title/]</a></p>\r\n  \r\n\r\n			\r\n			</div>\r\n",5995,6291);
$z[27][4]['row']="3";
$z[27][4]['titlelen']="24";
$z[27][4]['orderby']="rand";
$z[27][4]['type']="image.";
$z[28]=Array("arclist","\r\n        	<div class=\"item\">\r\n\r\n			\r\n<A href=\"[field:arcurl/]\"><IMG alt=\"[field:title/]\" src=\"[field:litpic/]\" height=\"200\" width=\"300\"></A><p><a href=\"[field:arcurl/]\">[field:title/]</a></p>\r\n  \r\n\r\n			\r\n			</div>\r\n",6324,6620);
$z[28][4]['row']="3";
$z[28][4]['titlelen']="24";
$z[28][4]['orderby']="rand";
$z[28][4]['type']="image.";
$z[29]=Array("field","",6781,6810);
$z[29][4]['name']="position";
$z[30]=Array("field","",6894,6913);
$z[30][4]['name']="title";
$z[31]=Array("field","",6993,7049);
$z[31][4]['name']="pubdate";
$z[31][4]['function']="MyDate('Y-m-d H:i',@me)";
$z[32]=Array("field","",7069,7089);
$z[32][4]['name']="source";
$z[33]=Array("field","",7110,7130);
$z[33][4]['name']="writer";
$z[34]=Array("field","",7164,7191);
$z[34][4]['name']="phpurl";
$z[35]=Array("field","",7215,7238);
$z[35][4]['name']="id";
$z[36]=Array("field","",7243,7267);
$z[36][4]['name']="mid";
$z[37]=Array("field","\r\n                if(@me==3) {\r\n                	@me = '<ul class=\"e8\">';\r\n                }\r\n                else if(@me==2) {\r\n                	@me = \"\r\n					<center>\r\n						<a href='javascript:dPlayBig();' class='c1'>原始大图</a>\\r\\n\r\n						<a href='javascript:dPlayPre();' class='c1'>上一张</a>\\r\\n\r\n						<a href='javascript:dPlayNext();' class='c1'>下一张</a>\\r\\n\r\n						<a href='javascript:dStopPlay();' class='c1'>自动播放已关闭</a>\\r\\n\r\n					</center>\r\n                	\";\r\n                }\r\n                else {\r\n                	@me = '';\r\n                }\r\n             ",7392,8074);
$z[37][4]['name']="pagestyle";
$z[37][4]['alt']="根据不同的页面风格输出不同的头信息";
$z[37][4]['runphp']="yes";
$z[38]=Array("field","\r\n                [field:pagestyle runphp='yes'] @me= (@me==3 ? '<li>' : '');[/field:pagestyle]\r\n                <a  target=\"_blank\" href='[field:linkurl/]' [field:pagestyle runphp='yes'] @me= (@me==3 ? 'class=\"pic\"' : ''); [/field:pagestyle]>\r\n                  <img src='[field:imgsrc/]' id='bigimg' [field:imgwidth /] alt='[field:alttext /]' border='0' />\r\n                </a>\r\n\r\n                [field:pagestyle runphp='yes'] @me = (@me==3 ? '</li>' : ''); [/field:pagestyle]\r\n             ",8204,8756);
$z[38][4]['name']="imgurls";
$z[38][4]['alt']="图片输出区";
$z[39]=Array("field","\r\n                if(@me==3) {\r\n                @me = '</ul>';\r\n                }\r\n                else if(@me==2) {\r\n                	@me = \"<script language='javascript'>dStartPlay();</script>\\r\\n\";\r\n               	}\r\n               	else {\r\n               		@me = '';\r\n                }\r\n             ",8773,9172);
$z[39][4]['name']="pagestyle";
$z[39][4]['alt']="根据不同的风格输出不同的结尾信息";
$z[39][4]['runphp']="yes";
$z[40]=Array("pagebreak","",9230,9247);
$z[41]=Array("field","",9292,9310);
$z[41][4]['name']="body";
$z[42]=Array("include","",9451,9488);
$z[42][4]['filename']="footer.htm";

?>