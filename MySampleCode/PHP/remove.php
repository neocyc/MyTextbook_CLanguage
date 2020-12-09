<?
//echo $_GET["id"]; 
include("db.php");                    //匯入db.php檔案

//$base64id = isset($_GET["id"]) && intval(trim($_GET["id"])) > 0 ? intval($_GET["id"]) : 0;
$base64id = $_GET["id"];

$id=base64_decode($base64id);
      

if($id == 0)
{ 
exit('ID参數不正確');
//exit('抓不到echo $_GET["id"];01');
}
else
{
mysql_query("DELETE FROM guestbook WHERE no='$id'");
//exit('抓不到echo $_GET["id"];02');

}
?>

<script>
	if(confirm("此紀錄已經删除!!"))
	{			
		window.location.href = "./view.php";
	}
	
</script>

