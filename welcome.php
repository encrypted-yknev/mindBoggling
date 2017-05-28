<?php
session_start();
include "connectDb.php"
?>
<html>
<head>
<link rel="stylesheet" type="text/css" href="styles/welcome.css">
</head>
<body>
<?php
	include "header.php";
?>


</br></br>
<div id="dboardmain">

	<?php
		$img_url="";
		try	{
			$sql="select ProfileImgURL from users where userid='".$_SESSION["user"]."'";		#fetch image url from users table.
			foreach($conn->query($sql) as $row)
				$img_url=$row["ProfileImgURL"];
		}
		catch(PDOException $e)	{
			echo "Some error occured";
		}
	?>
	<span><img id="proimg" src="<?php echo $img_url; ?>" width=15% height=25% /></span>
	<?php																						#display user details.
		echo "<h2>Welcome ".$_SESSION["name"]."</h2></br>";
		echo "About me - ".$_SESSION["desc"]."</br>";
		echo "Location - ".$_SESSION["location"]."</br>";
		echo "Upvotes - ".$_SESSION["upvotes"]."</br>";
		echo "Downvotes - ".$_SESSION["downvotes"]."</br>";
		
		#session_destroy();
	?>
</div>

<a href="logout.php">Logout</a>																	<!-- logout	-->
<?php
	include "footer.php";
?>
</body>
</html>