function passwordStrength(password)
{
 var desc = new Array();
 desc[0] = "������Ϊ��";
 desc[1] = "������С��6λ";
 desc[2] = "�жȰ�ȫ";
 desc[3] = "�߶Ȱ�ȫ";
 desc[4] = "�̼��Ȱ�ȫ";

 var score   = 0;

 if (password.length > 5) score++;

 if ( ( password.match(/[a-z]/) ) && ( password.match(/[A-Z]/) ) ) score++;
 if (password.match(/\d+/)) score++;

 if ( password.match(/.[!,@,#,$,%,^,&,*,?,_,~,-,(,)]/) ) score++;

 if (password.length > 6) score++;

  document.getElementById("passwordDescription").innerHTML = desc[score];
 document.getElementById("passwordStrength").className = "strength" + score;
}
