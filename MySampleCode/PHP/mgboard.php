<?php
mysql_connect("localhost","root","24572355");
mysql_select_db("contact");
mysql_query("set names utf8");
$data=mysql_query("select * from contact");
?>

<?php
$guestName=$_POST['name'];
$guestGender=$_POST['gender'];
$guestPhone=$_POST['phone'];
$guestMobile=$_POST['mobile'];
$guestCompany=$_POST['company'];
$guestSubject=$_POST['guestSubject'];
$guestContent=$_POST['guestContent'];
$guestTime = date("Y:m:d H:i:s",time()+28800);

if(isset($guestName)){
mysql_query("insert into guest value('','$guestName','$guestGender','$guestSubject','$guestContent','$guestPhone','$guestMobile','$guestCompany','$guestTime')");
}
?>

<?php 
$data=mysql_query('select * from guest order by guestTime desc')//讓資料由最新呈現到最舊
?>

<html>
<head><title>名片留言版</title></head>
<body>
<?php
$rs=mysql_fetch_row($data);
echo "$data<br>$rs<br>$rs[0]<br>";
echo "$data<br>$rs<br>$rs[1]<br>";
echo "$data<br>$rs<br>$rs[2]<br>";
echo "$data<br>$rs<br>$rs[3]<br>";
echo "$data<br>$rs<br>$rs[4]<br>";
echo "$data<br>$rs<br>$rs[5]<br>";
?>

<table width="700" border="1">
<tr>
	<td>姓名</td>
	<td>性別</td>
	<td>市話電話</td>
	<td>手機號碼</td>
	<td>公司名稱</td>
	<td>留言</td>
</tr>
<tr>
	<td><input type="text" class="form-control" placeholder="您的暱稱" name="guestName" id="guestName" /></td>
	<td><input type="text" class="form-control" placeholder="您的性別" name="guestName" id="guestGender" /></td>
	<td><input type="text" class="form-control" placeholder="您的市話電話" name="guestName" id="guestPhone" /></td>
	<td><input type="text" class="form-control" placeholder="您的手機號碼" name="guestName" id="guestMobile" /></td>
	<td><input type="text" class="form-control" placeholder="您的公司名稱" name="guestCompany" id="guestCompany" /></td>
	<td><input type="text" class="form-control" placeholder="您的留言" name="guestName" id="guestContent" /></td>
</tr>

<tr>
	<td><?php echo $rs[0];?></td>
	<td><?php echo $rs[1];?></td>
	<td><?php echo $rs[2];?></td>
	<td><?php echo $rs[3];?></td>
	<td><?php echo $rs[4];?></td>
	<td><?php echo $rs[5];?></td>

</tr>
<?php 
$rs=mysql_fetch_row($data);
?>
<tr>
	<td><?php echo $rs[0];?></td>
	<td><?php echo $rs[1];?></td>
	<td><?php echo $rs[2];?></td>
	<td><?php echo $rs[3];?></td>
	<td><?php echo $rs[4];?></td>
	<td><?php echo $rs[5];?></td>

</tr>

<?php 
for($i=1;$i<=mysql_fetch_row($data);$i++){
$rs=mysql_fetch_row($data);
?>
<tr>
	<td><?php echo $rs[0];?></td>
	<td><?php echo $rs[1];?></td>
	<td><?php echo $rs[2];?></td>
	<td><?php echo $rs[3];?></td>
	<td><?php echo $rs[4];?></td>
	<td><?php echo $rs[5];?></td>
</tr>
<?php }?>

<tr>
	<td>姓名</td>
	<td>性別</td>
	<td>市話電話</td>
	<td>手機號碼</td>
	<td>公司名稱</td>
	<td>留言</td>
</tr>
<tr>
<?php
for($i=1;$i<=mysql_num_rows($data);$i++){
 $rs=mysql_fetch_assoc($data);
?>
<tr>
	<td><?php echo $rs['guestName'];?></td>
	<td><?php echo $rs['guestGender'];?></td>
	<td><?php echo $rs['guestPhone'];?></td>
	<td><?php echo $rs['guestMobile'];?></td>
	<td><?php echo $rs['guestCompany'];?></td>
	<td><?php echo $rs['guestContent'];?></td>
</tr>
<?php }?>

</table>
<input type="submit" name="button" id="button" value="送出" class="btn"/>
</body>
</html>