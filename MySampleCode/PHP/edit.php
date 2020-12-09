<?php
//匯入db.php檔案
include("db.php");                    

/* 接收表單資料 */

$no=$_POST["no"];
$name=$_POST["name"];
$mail=$_POST["mail"];
$company=$_POST["company"];
$mobile=$_POST["mobile"];
//$subject=$_POST["subject"];
$content=$_POST["content"];

/* 將欄位資料加入資料庫 */
//$sql="UPDATE guestbook SET (no,name,mail,company,mobile,subject,content,putdate)
//VALUES ('$no','$name','$mail','$company','$mobile','$subject','$content',now())
//WHERE no='$no'";


$sql="UPDATE guestbook SET no='$no',name='$name',mail='$mail',company='$company',mobile='$mobile',subject='$subject',content='$content',putdate=now()
WHERE no='$no'";


mysql_query($sql);
//mysql_db_query("board",$sql);
?>

<script>
	if(confirm("此紀錄已經修改!!"))
	{			
		window.location.href = "./view.php";
	}
	
</script>

