<html>
<head>
<title>台灣駭客學院</title>

<style type="text/css">
.marqee {
	height: 3em;
 	margin: 0 auto;
 	overflow: hidden; 
 	position: relative;
 	background: black;
}
 
.marqee > ul {
 	padding-left: 0;
 	display: flex;
 	list-style-type: none;
 	animation: marqee 100s linear infinite;
 	position: absolute;
}
 
.marqee > ul > li {
 	white-space: nowrap;
 	margin-right: 2em;
 	font-weight: bold;
 	color: yellow;
}
 
@keyframes marqee {
 	0% {
  		left: 100%;
  		transform: translateX(0%);
 	}
 	100% {
  		left: 0;
  		transform: translateX(-100%);
 	}
}
</style>

<script>
function ChangePColor(){
	var OrgColor=document.getElementById("StringColor1").innerHTML;
	document.getElementById("StringColor1").innerHTML='<font color="green">'+OrgColor+'</font>';
var OrgColor=document.getElementById("StringColor2").innerHTML;
	document.getElementById("StringColor2").innerHTML='<font color="gray">'+OrgColor+'</font>';
var OrgColor=document.getElementById("StringColor3").innerHTML;
	document.getElementById("StringColor3").innerHTML='<font color="blue">'+OrgColor+'</font>';
}
</script>

</head>
<body bgcolor="#33ccff">
<table width="100%" border="5" bordercolor="red">
<tr><td><h1><p align="center">站長介紹</p></h1></td></tr>
<tr><td>
<p id="StringColor1">我的名字是陳淳澐，出生在基隆的小家庭，是家中學歷最高的長子。「通才」是我個人的優勢與特色：我喜愛做跨領域的資訊整合，更樂於將自身所學的新知識與技能分享給有需要的人。「逆向操作」是我的生活哲學：我擅長透過問題的反向思考，創造出前所未有的可能性。</p>

<div class="marqee">
<ul>
<li><p>大學時期雖然念得是資管系，但是個人對技術層面的實務課程深感興趣，例如：專題製作、程式設計、網頁資料庫......等。
</li>
<li>為了加強自己技術理論方面的知識背景，更進一步地跨修和旁聽資工系的其他相關課程，包括：組合語言、無線網路、作業系統。
</li>
<li>此外，透過證照補習班專員的介紹，使我認識資訊安全方面的相關證照，例如：ECSS、CEH。
</li>
<li>為此我下定決心，逐漸將自己的專業領域轉向資訊安全，並於大三榮獲【大專生國科會計畫】;於此完成我人生中的第一個程式專案計劃：建立電子投票協定的驗證雛型工具。
</li>
<li>在此計畫中我學習到密碼學的實作、研究報告的撰寫、團隊合作，以及溝通協調和訊息整合之各種能力。
</li>
<li>例如：將問題內容分為程式碼工具、密碼學理論兩部份，並分頭詢問相關的專業老師;再將最後得到的回應作整合後，找出問題的最佳解法。
</li>
<li>進修方面雖然沒有完成碩士學位，但也接觸到更困難的資安技術「影像鑑識」。
</li>
<li>本人當時研究領域為「被動式影像竄改」，主要專攻於Image    Resize的偵測技術：透過逆向工程探討Content-aware    影像縮放演算法執行時是否有留下蹤跡，再依據遺留下來的線索，找出可疑的地方。
</li>
<li>我相信在校所學之相關背景知識，將在未來有其發揮的空間。</p>
</li>
</ul>
</div>

<font face="標楷體">
<p id="StringColor2">除學業學習以外，本人還擁有豐富多元的工讀經驗，其中包括：學校資訊室、青輔會暑期社區工讀計畫。這些工作經驗讓我學會電腦維修、網頁製作技巧（HTML和CSS）、網站規劃（網誌行銷）。這些工作經驗讓我學會基本的溝通能力，於以克服各種碰到的問題與狀況。</p>

<p id="StringColor3">很快地我即將成為投入職場找工作的社會新鮮人，未來期望自己可以在資訊安全教育領域，特別是駭客攻防演練方面成為專業人士。於此本人首度創立了<a href="https://zh-tw.facebook.com/pg/MengXiangFangZhou/about/">【台灣駭客學院】</a>的粉絲專頁，希望可以將自身工作、專業、創業同步整合並進，以驗證自我學習成效。</p>
</td></tr>
<tr>
<td><button value="文字變色" onclick="ChangePColor()">改變一下樣貌(change color)</button></td></tr>
<td><a href="http://127.0.0.1/ccyofphp/msg.php">編寫名片留言版(go to messageboard)</a></td>
</table>
</font>

</body>


<?

echo "今天是 ";
echo date("Y年m月d日 H:i:s",time()+60*60*8);

@session_start();
$counterFile = "count.txt"; //讀取寫入的檔案名稱
$counterizo = intval(file_get_contents($counterFile));
if($_SESSION['countizo']!=1){ //檢查SESSION
 $fp = @fopen($counterFile, "w");
 	if($fp){
 	flock($fp, 2);
 	@fwrite($fp, ++$counterizo);
 	flock($fp, 3);
 	fclose($fp);
 	$_SESSION['countizo']=1; //防止重複計算
 	}
}
 
echo "<br> 人氣 ( ".$counterizo." )"; //輸出

?>

<br>
<a href="https://pjchender.blogspot.tw/2015/03/php-mysql.html">環境安裝</a>
<a href="https://izo.tw/php-counter/">PHP計數器</a>
<a href="http://www.flycan.com/deux2/mypaper/html.htm">HTML基礎</a>
<a href="http://kinomelma.pixnet.net/blog/post/30306500-%5Bjquery%2Bphp%2Bcss%5D-%E9%BB%9E%E9%81%B8checkbox%E5%BE%8C%E8%AE%93%E5%BA%95%E6%A1%86%E8%AE%8A%E8%89%B2">基礎格式</a>
<a href="http://limitedcode.blogspot.tw/2017/03/css.html">CSS跑馬燈</a>
<br>
</html>
參考網頁:
1.https://pjchender.blogspot.tw/2015/03/php-mysql.html
2.https://izo.tw/php-counter/
3.http://www.flycan.com/deux2/mypaper/html.htm
4.http://kinomelma.pixnet.net/blog/post/30306500-%5Bjquery%2Bphp%2Bcss%5D-%E9%BB%9E%E9%81%B8checkbox%E5%BE%8C%E8%AE%93%E5%BA%95%E6%A1%86%E8%AE%8A%E8%89%B2
5.http://limitedcode.blogspot.tw/2017/03/css.html