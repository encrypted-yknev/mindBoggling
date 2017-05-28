<?php 
session_start();
include "connectDb.php";
include "header.php"; ?>
<html>
<body>

<?php
	$upload_flag=1;
	$updt_db=false;
	$propicErr=$propicSuc="";
	$target_dir="uploads/";
	if(isset($_POST["submit"]))	{
		
		if(isset($_FILES["propic"]))	{
			$file_name=$_FILES["propic"]["name"];									#Image file name
			$file_type=pathinfo($target_dir.$file_name,PATHINFO_EXTENSION);			#type of image - jpg/jpeg/png etc.
			$file_size=$_FILES["propic"]["size"];									#image size
			$temp_file=$_FILES["propic"]["tmp_name"];								#temporary image name on server.
		
			if(file_exists($target_dir.$file_name))	{								#If a file already exists with the same name.
				$propicErr="Please choose different image";
				$upload_flag=0;
			}

			if(($file_type!="jpg" && $file_type!="JPG" ) && 
			   ($file_type!="jpeg" && $file_type!="JPEG"))	{						#check for file types.
				$propicErr="Uh oh! Only jpg/jpeg/png/gif images are allowed";
				$upload_flag=0;
			}
			if($file_size > 500000)	{												#check for file size.
				$propicErr="Sorry! Your file is too large";
				$upload_flag=0;
			}
			
			if($upload_flag==1)	{													#If all validations passed - upload the file.
				if(move_uploaded_file($temp_file,$target_dir.$file_name))
					$updt_db=true;
			}

			if($updt_db)	{														#update users table with image url.
				try	{
					$sql="update users set ProfileImgURL='".$target_dir.$file_name."' where userid='".$_SESSION["user"]."'";
					$stmt=$conn->prepare($sql);
					$stmt->execute();
					
					if($stmt->rowCount()>0)
						$propicSuc="File uploaded successfully";
					else
						$propicErr="Some error occured";
				}
				catch(PDOException $e)	{
					$propicErr="Error Occurred";
				}
			}
		}
		
		else	{
			$propicErr="File not sent to the server";
		}
	}
 ?>
	<h2>Choose your dashboard picture</h2>
 	<form action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>" method="post" enctype="multipart/form-data">
		Upload your image:
		<input type="file" name="propic" id="propic">
			<span class="err"><?php echo $propicErr; ?></span></br>
			<span class="suc"><?php echo $propicSuc; ?></span></br>
		<input type="submit" value="Upload" name="submit"></br></br>
	</form>
	</br>
	<a href="home.php">Go to login page</a>
 <?php include "footer.php"; ?>
 </body>
 </head>
 
 