<?php
if(!isset($GLOBALS['_vars'])) $GLOBALS['_vars'] = array(); 
$fields = array();
 include $this->CompilerInclude("header.htm");
 ?>
<div class="wrapper mT10">
  <div class="west">
  	<?php include $this->CompilerInclude("side_icon.htm");
 ?>
  </div>
  <div class="east">
    <dl class="border">
      <dt class="caption"><strong>��������</strong></dt>
      <dd class="body pB10">
        <table width="700" align="center" class="tList">
          <tr>
            <td>�ǳƣ�</td>
            <td><?php echo $row['uname']; ?></td>
          </tr>
          <tr>
            <td width="101">�Ա� </td>
            <td width="593"><?php echo $row['sex']; ?></td>
          </tr>
          <tr>
            <td>Ŀǰ���ڵأ�</td>
            <td> ʡ�ݣ�
              <?php
			$places = GetEnumsTypes($row['place']);
			echo ( isset($em_nativeplaces[$places['top']]) ?  $em_nativeplaces[$places['top']] : '');
		  ?>
              &nbsp; ���У�
              <?php
		  echo ( isset($em_nativeplaces[$places['son']]) ?  $em_nativeplaces[$places['son']] : '');
		  ?></td>
          </tr>
          <tr>
            <td>�������ڵأ�</td>
            <td> ʡ�ݣ�
              <?php
			$places = GetEnumsTypes($row['oldplace']);
			echo ( isset($em_nativeplaces[$places['top']]) ?  $em_nativeplaces[$places['top']] : '');
		  ?>
              &nbsp; ���У�
              <?php
		  echo ( isset($em_nativeplaces[$places['son']]) ?  $em_nativeplaces[$places['son']] : '');
		  ?></td>
          </tr>
          <tr>
            <td>�������ڣ�</td>
            <td><?php echo $row['birthday']; ?></td>
          </tr>
          <tr>
            <td>����Ŀ�ģ�</td>
            <td><?php echo GetEnumsValue('datingtype',$row['datingtype']); ?></td>
          </tr>
          <tr>
            <td>����״����</td>
            <td><?php echo GetEnumsValue('marital',$row['marital']); ?></td>
          </tr>
          <tr>
            <td>������</td>
            <td><?php echo GetEnumsValue('star',$row['star']); ?></td>
          </tr>
          <tr>
            <td>Ѫ�ͣ�</td>
            <td><?php echo GetEnumsValue('blood',$row['blood']); ?></td>
          </tr>
          <tr>
            <td>���ߣ�</td>
            <td>><?php echo $row['height']; ?> ����</td>
          </tr>
          <tr>
            <td>���ͣ�</td>
            <td><?php echo GetEnumsValue('bodytype',$row['bodytype']); ?></td>
          </tr>
        </table>
      </dd>
    </dl>
    <dl class="border mT10">
      <dt class="caption"><strong>����״��</strong></dt>
      <dd class="body pB10">
        <table width="700" align="center" class="tList">
          <tr>
            <td width="101">���������</td>
            <td width="593"><?php echo GetEnumsValue('income',$row['income']); ?></td>
          </tr>
          <tr>
            <td>�����̶ȣ�</td>
            <td><?php echo GetEnumsValue('education',$row['education']); ?></td>
          </tr>
          <tr>
            <td>ס�������</td>
            <td><?php echo GetEnumsValue('house',$row['house']); ?></td>
          </tr>
          <tr>
            <td>������ҵ��</td>
            <td><?php echo GetEnumsValue('vocation',$row['vocation']); ?></td>
          </tr>
          <tr>
            <td>�������ԣ�</td>
            <td>
              <?php
    $arr = $dsql->GetOne("Select * From `#@__sys_set` where sname='language' ");
    $sets = explode(',',$arr['items']);
    foreach($sets as $v){
    	if(preg_match("#".$v."#", $row['language'])) echo "  $v ";
    }
    ?></td>
          </tr>
        </table>
      </dd>
    </dl>
    <dl class="border mT10">
      <dt class="caption"><strong>��Ȥ����</strong></dt>
      <dd class="body pB10">
        <table width="700" align="center" class="tList">
          <tr>
            <td width="101">�Ƿ�Ⱦƣ�</td>
            <td width="593"><?php echo GetEnumsValue('drink',$row['drink']); ?></td>
          </tr>
          <tr>
            <td>�Ƿ���̣�</td>
            <td><?php echo GetEnumsValue('smoke',$row['smoke']); ?></td>
          </tr>
          <tr>
            <td>��Ȥ���ã�</td>
            <td> <?php
    	$arr = $dsql->GetOne("Select * From `#@__sys_set` where sname='nature' ");
    	$sets = explode(',',$arr['items']);
    	foreach($sets as $v){
    		if(preg_match("#".$v."#",$row['nature'])) echo " $v ";
    	}
    	?></td>
          </tr>
        </table>
      </dd>
    </dl>
  </div>
</div>
<?php include $this->CompilerInclude("footer.htm");
 ?>
</body>
</html>