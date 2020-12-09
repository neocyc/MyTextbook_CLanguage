<?php
include("db.php");                    //匯入db.php檔案
/* 接收表單資料 */
$no=$_POST["no"];
$name=$_POST["name"];
$mail=$_POST["mail"];
$company=$_POST["company"];
$mobile=$_POST["mobile"];
//$subject=$_POST["subject"];
$content=$_POST["content"];
/* 將欄位資料加入資料庫 */
$sql="INSERT guestbook (no,name,mail,company,mobile,subject,content,putdate)
VALUES ('$no','$name','$mail','$company','$mobile','$subject','$content',now())";

mysql_query($sql);
//mysql_db_query("board",$sql);
?>

<?header("location:view.php");?>       //重新導向到view.php檔案