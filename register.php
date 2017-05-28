<html>
<head>
<link rel="stylesheet" type="text/css" href="styles/register.css">
</head>
<body>
<?php include "header.php";
include "connectDb.php";		#connect to mysql database.
$regmsg=$name=$fullname=$pwd=$repwd=$age=$email=$phone=$gender=$countries=$abtme=$propic="";					#Variables to store input values.
$userErr=$nameErr=$pwdErr=$repwdErr=$emailErr=$phoneErr=$ageErr=$countryErr=$ageErr=$genErr=$propicErr="*";		#Variables to return error messages.
$checked=true;	#Boolean variable to check if all fields are correct or not.

if($_SERVER["REQUEST_METHOD"]=="POST")	{
	
	#Check for proper name - empty/invalid characters
	if(!empty($_POST["name"]))	{
		$fullname=processData($_POST["name"]);
		if (!preg_match("/^[a-zA-Z ]*$/",$fullname)) {
			$nameErr = "Only letters and white space allowed"; 
			$checked=false;
			$name="";
		}
	}
	else	{
		$nameErr="Please Enter your name here";
		$checked=false;
	}		
	
	#Validate username - empty field
	if(empty($_POST["user"]))	{
		$userErr="Enter Username";
		$checked=false;
	}
	else
		$name=processData($_POST["user"]);
	
	#validate password - empty field
	if(empty($_POST["pwd"]))	{
		$pwdErr="Enter your password";
		$checked=false;
	}
	else
		$pwd=processData($_POST["pwd"]);
	
	#validate password - empty field
	if(empty($_POST["repwd"]))	{
		$repwdErr="Enter password again";
		$checked=false;
	}
	else
		$repwd=processData($_POST["repwd"]);
	
	#Check if two password fields are same.
	if(checkPwdEquality($pwd,$repwd) != 0)	{
		$repwdErr="Passwords do not match!";
		$checked=false;
	}
	
	#validate email address
	if(!empty($_POST["mail"]))	{
		$email=processData($_POST["mail"]);
		if(!validate_email($email))	{
			$emailErr="Invalid Email - Try again";
			$checked=false;
			$email="";
		}
	}
	else	{
		$emailErr="Enter your EmailId";
		$checked=false;
	}
		
	
	#check for proper mobile number
	if(!empty($_POST["phone"]))	{
		$phone=processData($_POST["phone"]);
		if(filter_var($phone, FILTER_VALIDATE_INT) === false)	{
			$phone_len = strlen((string)$phone);
			if($phone_len < 10)	{
				$phoneErr="Invalid mobile number";
				$checked=false;
				$phone="";
			}
		}
		else	{
			$phoneErr="Enter proper mobile number";
			$phone="";
			$checked=false;
		}
	}
	else	{
		$phoneErr="Please enter your mobile number";
		$checked=false;
	}
	
	#check for empty field
	if(empty($_POST["age"]))	{
		$ageErr="Enter your age";
		$checked=false;
	}
	else
		$age=processData($_POST["age"]);
	
	#check for empty field.
	if(empty($_POST["gender"]))	{
		$genErr="Choose your gender";
		$checked=false;
	}
	else
		$gender=processData($_POST["name"]);
	
	#check for empty field.
	if(empty($_POST["countries"]))	{
		$countryErr="What's your location?";
		$checked=false;
	}
	else
		$countries=processData($_POST["countries"]);

	$abtme=processData($_POST["abtme"]);
	
	#If everything is fine - Add the user.
	if($checked==true)	{
		try	{
			$sql="insert into users
			(userid,DisplayName,EncryptPwd,EmailAddr,PhoneNum,Age,Location,Description,ProfileImgURL,Status,UpVotes,DownVotes,Created_TS,LastAccessed_TS)
			values
			('".$name."','".$fullname."','".md5($pwd)."','".$email."',".$phone.",".$age.",'".$countries."','".$abtme."',NULL,'A',0,0,CURRENT_TIMESTAMP,NULL)";
			
			$conn->exec($sql);
			$regmsg="Registration successfull";
			include "session.php";	#Starting user session
			echo '<script type="text/javascript">window.location="upload.php";</script>';		#On successful registration, redirect to profile pic upload
		}
		catch(PDOException $e)	{
			$regmsg="Some error occured".$e->getMessage();
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

#Password equality check
function checkPwdEquality($pass1,$pass2)	{
	return strcmp($pass1,$pass2);
}

function validate_email($email)	{
	if (!filter_var($email, FILTER_VALIDATE_EMAIL))
		return false;
	return true;
}


 ?>
<h2>User Registration</h2>
</br>
<div id="reg">
<?php echo $regmsg; ?>
</div>
<div>
	<form action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>" method="post" name="userForm" >
		Enter full name: <input type="text" name="name" value="<?php echo $fullname; ?>"  />
			<span class="err"><?php echo $nameErr; ?></span></br></br>		
		Choose User ID: <input type="text" name="user" value="<?php echo $name; ?>"  />
			<span class="err"><?php echo $userErr; ?></span></br></br>
		Password: <input type="password" name="pwd" />
			<span class="err"><?php echo $pwdErr; ?></span></br></br>
		Re-enter Password: <input type="password" name="repwd" />
			<span class="err"><?php echo $repwdErr; ?></span></br></br>
		Email: <input type="text" name="mail" value="<?php echo $email; ?>" />
			<span class="err"><?php echo $emailErr; ?></span></br></br>
		Mobile: <input type="text" name="phone" value="<?php echo $phone; ?>" />
			<span class="err"><?php echo $phoneErr; ?></span></br></br>
		How old are you? <input type="text" name="age" value="<?php echo $age; ?>" />
			<span class="err"><?php echo $ageErr; ?></span></br></br>
		Gender: <input type="radio" name="gender" value="male" >Male
		<input type="radio" name="gender" value="female" >Female
			<span class="err"><?php echo $genErr; ?></span></br></br>
		Tell us your Location: 
		<select name="countries" >
			<option>USA</option>
			<option>India</option>
			<option>Australia</option>
			<option>Canada</option>
			<option>Japan</option>
			<option>China</option>
			<option>New Zealand</option>
			<option>South Africa</option>
		</select>
			<span class="err"><?php echo $countryErr; ?></span></br></br>
		Tell something about yourself: 
		<textarea name="abtme" value="<?php echo $abtme; ?>" rows="10" cols="100"></textarea></br></br>
	
		<input type="submit" value="Register" name="submit"></br></br>
	</form>
	
</div>
<?php include "footer.php"; ?>
</body>
</html>