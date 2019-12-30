<?php
	$con = mysqli_connect("localhost","phpmyadmin","qwer1234","testdb");

	if(mysqli_connect_error())
	{
		echo "Failed to connect to MySQL: " . mysqli_connect_error();
	}

	$distance = $_GET['distance'];
	$sql = "INSERT INTO data(distance) VALUES($distance)";

	echo $sql;

	$result = mysqli_query($con, $sql);

	if($result)
	{
		echo $con->affected_rows."data inserted into databases.";
	}
	else
	{
		echo "ERROR: Failed to connect.";
	}

	mysqli_close($con);
?>
