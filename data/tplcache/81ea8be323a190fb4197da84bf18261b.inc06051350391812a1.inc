<?php
$z[0]=Array("arcurl","",90,105);
$z[1]=Array("title","",110,124);
$z[2]=Array("typelink","",204,221);
$z[3]=Array("pubdate","",267,317);
$z[3][4]['function']="strftime('%Y.%m.%d',@me)";
$z[4]=Array("click","",363,377);
$z[5]=Array("arcurl","",490,505);
$z[6]=Array("litpic","",517,532);
$z[7]=Array("title","",539,553);
$z[8]=Array("description","",590,610);
$z[9]=Array("writer","",701,717);
$z[10]=Array("id","  \r\n    global \$cfg_cmspath;  \r\n       \$tags = GetTags(@me);  \r\n       \$revalue = '';  \r\n       \$tags = explode(',', \$tags);  \r\n        foreach(\$tags as \$key => \$value){  \r\n           if(\$value){  \r\n               \$revalue .= '<a href=\"'.\$cfg_cmspath.'/tags.php?/'.\$value.'/\">'.\$value.'</a>&nbsp;';           \r\n            }  \r\n       }  \r\n        @me = \$revalue;  \r\n    ",767,1172);
$z[10][4]['runphp']="yes";
$z[11]=Array("title","",1222,1269);
$z[11][4]['function']="htmlspecialchars(@me)";
$z[12]=Array("arcurl","",1277,1292);

?>