function passwordStrength(password)
{
 var desc = new Array();
 desc[0] = "×不能为空";
 desc[1] = "×不能小于6位";
 desc[2] = "中度安全";
 desc[3] = "高度安全";
 desc[4] = "√极度安全";

 var score   = 0;

 if (password.length > 5) score++;

 if ( ( password.match(/[a-z]/) ) && ( password.match(/[A-Z]/) ) ) score++;
 if (password.match(/\d+/)) score++;

 if ( password.match(/.[!,@,#,$,%,^,&,*,?,_,~,-,(,)]/) ) score++;

 if (password.length > 6) score++;

  document.getElementById("passwordDescription").innerHTML = desc[score];
 document.getElementById("passwordStrength").className = "strength" + score;
}
