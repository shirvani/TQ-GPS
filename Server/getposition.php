<?php mysql_connect('127.0.0.1', 'root', 'lgvvG0ea');
mysql_select_db('gps');
$res = mysql_query('SELECT * FROM location');
if (mysql_num_rows($res) > 0):
	while ($val = mysql_fetch_assoc($res)):
		$lat = ""; $lon = "";
		$latH = substr($val["lat"], 0, 2);
		$latM = substr($val["lat"], 2, strlen($val["lat"])) / 60;
		$lonH = substr($val["lon"], 0, 3);
		$lonM = substr($val["lon"], 3, strlen($val["lon"])) / 60;
		$lat = $latH + $latM;
		$lon = $lonH + $lonM;
		if ($val["lonP"] == 'S') $lon = $lon * -1;		
		if ($val["latP"] == 'W') $lat = $lat * -1;
		?>
		<script  type="text/javascript">setMarker(<?php echo $lat?>,<?php echo $lon?>,_map);</script>
		<?php echo "<b>".$val["sid"]."</b> is at position :<br>lat : <b>".$lat."</b><br>lon : <b>".$lon."</b><br><br>";?>
	<?php endwhile;
endif;?>
