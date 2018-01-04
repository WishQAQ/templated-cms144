<?php
$z[0]=Array("field","",255,274);
$z[0][4]['name']="title";
$z[1]=Array("field","",275,298);
$z[1][4]['name']="seotitle";
$z[2]=Array("field","",339,368);
$z[2][4]['name']="keywords";
$z[3]=Array("field","",408,466);
$z[3][4]['name']="description";
$z[3][4]['function']="html2text(@me)";
$z[4]=Array("global","",484,511);
$z[4][4]['name']="cfg_basehost";
$z[5]=Array("include","",593,628);
$z[5][4]['filename']="head.htm";
$z[6]=Array("field","",675,704);
$z[6][4]['name']="position";
$z[7]=Array("list","\r\n<div class=\"xnlist\">\r\n   <div class=\"picxn\">[field:imglink/]</div>\r\n  <div class=\"zwlist\">\r\n  <ul>\r\n  <li><span>[field:pubdate function=\"GetDateTimeMK(@me)\"/]</span><a href='[field:arcurl/]'>[field:title/]</a></li>\r\n  <p>[field:description/]...</p>\r\n  </ul>\r\n  </div>\r\n</div>\r\n",745,1075);
$z[7][4]['pagesize']="10";
$z[7][4]['titlelen']="60";
$z[8]=Array("pagelist","",1097,1168);
$z[8][4]['listitem']="info,index,end,pre,next,pageno";
$z[8][4]['listsize']="5";
$z[9]=Array("arclist","\r\n<li><a href='[field:arcurl/]'>[field:title/]</a></li>\r\n",1303,1424);
$z[9][4]['row']="14";
$z[9][4]['titlelen']="36";
$z[9][4]['orderby']="rand";
$z[10]=Array("arclist","\r\n<li><a href='[field:arcurl/]'>[field:title/]</a></li>\r\n",1599,1721);
$z[10][4]['row']="10";
$z[10][4]['titlelen']="36";
$z[10][4]['orderby']="click";
$z[11]=Array("include","",1756,1793);
$z[11][4]['filename']="footer.htm";

?>