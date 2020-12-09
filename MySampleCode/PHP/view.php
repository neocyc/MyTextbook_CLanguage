<html>
<head>
<title>列出所有留言</title>
        
<?php
//匯入db.php檔案
include("db.php");

/* 查詢欄位資料 */
$sql="select * from guestbook order by no desc";  //從guestbook讀取資料並依no欄位做遞減排序
$result=mysql_query($sql);
?>

<script type="text/javascript">
	//document.write('Hello world!');
	function is_remove(no)
	{				
		if(confirm("確實要删除此條紀錄嗎？"))
		{	
			//URL前端加密:參數
			//window.location.href = "./remove.php?id=" + no;
			//window.location.href = "./remove.php?id="+window.btoa(window.encodeURIComponent("id="+no));
			var str = no; 
			var encodedData = window.btoa(str); //編碼
			var encodeid = encodeURIComponent(encodedData); //轉URI編碼
			window.location.href = "./remove.php?id=" + encodeid;
		}		
	}

	function is_edit(no)
	{		
		if(confirm("前往編輯頁面"))
		{	
			//URL前端加密:參數				
			//window.location.href = "./msgedit.php?id=" + no;
			//window.location.href = "./msgedit.php?id="+window.btoa(window.encodeURIComponent("id="+no));
			var str = no; 
			var encodedData = window.btoa(str); //編碼
			var encodeid = encodeURIComponent(encodedData); //轉URI編碼
			window.location.href = "./msgedit.php?id=" + encodeid;
		}
	}
</script>

</head>
<body>
<a href="msg.php">寫寫留言</a><p>
<a href="http://127.0.0.1/ccyofphp/myfirstwebpage.php">回自我介紹</a><p>


<table width="700" border="1">
<tr>
	<td>留言編號</td>
	<td>訪客姓名</td>
	<td>E-mail</td>
	<td>公司名稱</td>
	<td>連絡電話</td>	
	<td>留言內容</td>
	<td>留言時間</td>
	<td>驗證碼</td>	
	<td colspan="18">管理</td>
</tr>

<?php
/* 顯示資料庫資料 */
while (list($no,$name,$mail,$company,$mobile,$subject,$content,$putdate)
      =mysql_fetch_row($result)){

//$rs=mysql_fetch_row($result);

//for($i=1;$i<=mysql_fetch_row($result);$i++){
//$rs=mysql_fetch_row($result);

$encodedData = base64_encode($no);
$idbase64=urlencode($encodedData);

?>

<tr>
	<td><?php echo $no;?></td>
	<td><?php echo $name;?></td>
	<td><?php echo $mail;?></td>
	<td><?php echo $company;?></td>
	<td><?php echo $mobile;?></td>
	<td><?php echo $content;?></td>
	<td><?php echo $putdate;?></td>	
	<td><?php echo $idbase64?></td>
	<td colspan="9"><button onclick="is_remove(<?php echo $no;?>);">删除</button></td>
	<td colspan="9"><button onclick="is_edit(<?php echo $no;?>);">編輯</button></td>　    
		
</tr>

<?php }?>	
     	
<hr>

</td>　 

</table>
<?php
echo "共".mysql_num_rows($result)."筆留言";

?>




</body>
</html>