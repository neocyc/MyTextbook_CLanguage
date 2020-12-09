<html>
<head>
<title>列出所有留言</title>

<?php
include("db.php");
/* 查詢欄位資料 */
$sql="select * from guestbook order by no desc";  //從guestbook讀取資料並依no欄位做遞減排序
$result=mysql_query($sql);
?>

</head>
<body>
<a href="msg.php">寫寫留言</a><p>
<hr>

<table width="700" border="1">
<tr>
	<td>留言編號</td>
	<td>訪客姓名</td>
	<td>E-mail</td>
	<td>留言主題</td>
	<td>留言內容</td>
	<td>留言時間</td>
	<td>公司名稱</td>
	<td>連絡電話</td>
</tr>

<?php
/* 顯示資料庫資料 */
while (list($no,$name,$mail,$company,$mobile,$subject,$content,$putdate)
      =mysql_fetch_row($result)){

//$rs=mysql_fetch_row($result);

//for($i=1;$i<=mysql_fetch_row($result);$i++){
//$rs=mysql_fetch_row($result);
?>

<tr>
	<td><?php echo $no;?></td>
	<td><?php echo $name;?></td>
	<td><?php echo $mail;?></td>
	<td><?php echo $company;?></td>
	<td><?php echo $mobile;?></td>
	<td><?php echo $subject;?></td>
	<td><?php echo $content;?></td>
	<td><?php echo $putdate;?></td>
</tr>
<?php }?>
<hr>



</table>
<?php
echo "共".mysql_num_rows($result)."筆留言";

?>
</body>
</html>