
<?php

include "connectDb.php";
$message=$pwddb="";
$name="";
$nameError="*";
$nameSuc="";
$pwdError="*";
$checked=$success=true;
if ($_SERVER["REQUEST_METHOD"] == "POST")	{
	#check for empty field
	if(empty($_POST["name"]))	{
		$nameError="Name is Required";
		$checked=false;
	}
	else	{
		$name=processData($_POST["name"]);
	}
	#check for empty field.
	if(empty($_POST["pwd"]))	{
		$pwdError="Password is mandatory";
		$checked=false;
	}
	else	{
		$pwd=processData($_POST["pwd"]);
	}
	
	if($checked==true)	{
		try	{
			$sql="select EncryptPwd from users where userid='".$name."'";
			foreach($conn->query($sql) as $row)
				$pwddb=$row['EncryptPwd'];
			
			#check is user entered the correct password.
			if(md5($pwd)!=$pwddb)	
				$success=false;
			
			#Redirect to dashboard welcome page for correct credentials.
			if($success==true)	{
				$sql="select userid,DisplayName,EncryptPwd,EmailAddr,PhoneNum,Age,Location,Description,ProfileImgURL,Status,UpVotes,DownVotes,Created_TS,LastAccessed_TS from users where userid='".$name."'";
				
				foreach($conn->query($sql) as $row)	{
					$name_db=$row['DisplayName'];
					$desc_db=$row['Description'];
					$location_db=$row['Location'];
					$upvotes_db=$row['UpVotes'];
					$downvotes_db=$row['DownVotes'];
				}
				include "session.php";	#start user session
				echo '<script type="text/javascript">window.location="welcome.php";</script>';
			}
		}
		catch(PDOException $e)	{
			$message= "Error occurred : ".$e->getMessage();
		}
	}
}
#Function to trim extra spaces/backslashes and avoiding cross-scripting
function processData($text)	{
	$text=trim($text);
	$text=stripslashes($text);
	$text=htmlspecialchars($text);
	return $text;
}
?>
<?php include "header.php";

?>
<html>
<head>
<meta name="google-signin-client_id" content="414683916809-9ffnie8m4i1bp0501iiuqg1dfg4sbpm9.apps.googleusercontent.com">
<script src="https://apis.google.com/js/platform.js" async defer></script>
<style>
.err
{color:red;}
.success
{color:#32cd32;}
</style>
</head>

<body>

<h2>Login Portal</h2>
<div id="err">
<?php echo $message; ?></div>
<form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>">
Username : <input type="text" name="name" placeholder="Enter login ID" value="<?php echo $name;?>" /><span class="success">&nbsp;&nbsp;<?php echo $nameSuc; ?></span><span class="err">&nbsp;&nbsp;<?php echo $nameError; ?></span></br></br>
Password : <input type="password" name="pwd" placeholder="Enter password" /><span class="err">&nbsp;&nbsp;<?php echo $pwdError; ?></span></br></br>
<div class="g-signin2" data-onsuccess="onSignIn"></div></br>
<input type="checkbox" name="remMe">Remember me</br></br>
<input type="submit" value="Login" />
<a href="" target="_blank" name="fgtPwd">Forgot Password?</a>
</form>
<?php include "footer.php" ?>
</body>
</html>