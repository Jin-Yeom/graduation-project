<?php
	$con = mysqli_connect('localhost','phpmyadmin','qwer1234','testdb');
?>

<html>
<head>
<meta charset="utf-8">
<title>내 서랍속의 IOT</title>
<script>
setTimeout("history.go(0);",5000);
</script>
<style>
	body{
		margin: 0;
		background-color: beige;
	}

	.team{
		height: 70px;
		display: flex;
		border-bottom: 1px solid black;
		align-items: center;
	}

	.team-right-items{
		display: flex;
		margin-left: auto;
		margin-right: 40px;
	}

	.team-item{
		margin-left: 10px;
		font-size: 2rem;
	}

	.distance{
		margin-top: 200px;
		font-size: 5rem;
		font-family: 'Lobster', serif;
		color: orange;
		text-align: center;
		font-weight: bold;
	}

	.name{
		margin-top: 100px;
		font-size: rem;
		font-family: 'Lobster', sans-serif;
		color: lightblue;
		font-size: 6rem;
		text-align: center;
	}
</style>
</head>

<body>
<div class="name"><h1>스마트 서랍</h1></div>
<div class="team">
	<div class="team-right-items">
		<div class="team-item">조원 :</div>
		<div class="team-item">김영규,</div>
		<div class="team-item">김석원,</div>
		<div class="team-item">이진염</div>
	</div>
</div>

<div class="distance">
<?php
	$query = "SELECT * FROM data order by date desc limit 1";
	echo "Date : ". date("Y-m-d H:i:s")."<br/>";
	$result = mysqli_query($con, $query);
	//mysquli_data_seek_($resilt, 2);
	while($row = mysqli_fetch_array($result))
	{	echo '<br>';
		echo "Distance : ". $row[distance];
		echo '<br>';

		/* if($row[distance] > 20 && date("s") >= 10)
        	{
                	echo "<h1>서랍을<br/> 닫아주세요!</h1>";
        	}

        	else
        	{
                	echo "<h1>10초가 지나야합니다.</h1>";
        	}*/
	}
	mysqli_close($con);
?>
</div>
</body>
</html>

