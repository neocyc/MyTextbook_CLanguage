﻿<html>
<head>
<title>留言板</title>
</head>
<body>

<?php
//匯入db.php檔案
include("db.php");

//$base64id = isset($_GET["id"]) && intval(trim($_GET["id"])) > 0 ? intval($_GET["id"]) : 0;
//抓取URL參數
$base64id = $_GET["id"];

//URL後端解密:參數
$id=base64_decode($base64id);


//header("location:msgedit.php");

/* 查詢欄位資料 */
$sql="select * from guestbook where no=$id";  //從guestbook讀取資料並依no欄位做遞減排序
$result=mysql_query($sql);

//echo $sql;
?>




<a href="view.php">觀看留言</a><p>
<form name="form1" method="post" action="edit.php"?>

<?php
/* 顯示資料庫資料 */
while (list($no,$name,$mail,$company,$mobile,$subject,$content,$putdate)
      =mysql_fetch_row($result)){
	//$changecontent=(string)$content;
?>

留言編號(message number)：<input type="text" name="no" value="<?echo $no;?>" readonly><br>
姓名(name)：<input type="text" name="name" value="<?echo $name;?>" ><br>
郵件(mail)：<input type="text" name="mail" value="<?echo $mail;?>" ><br>
公司名稱(company name):<input type="text" name="company" value="<?echo $company;?>" ><br>
電話(mobile):<input type="text" name="mobile" value="<?echo $mobile;?>" ><br>
內容(content)：<textarea rows=7 name="content"><?echo $content;?></textarea><br>

<?php }?>

<input type="submit" name="Submit" value="送出(send)">

</form>
參考網站:<a href="http://annar2009.pixnet.net/blog/post/24797365-php-%E7%95%99%E8%A8%80%E7%89%88%E8%A8%AD%E8%A8%88">留言板範例</a>
<a href="https://www.tad0616.net/modules/tad_book3/page.php?tbdsn=91">PHP資料庫</a>
</body>
</html>