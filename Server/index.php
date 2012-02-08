<?php extract($_GET);?>
<!DOCTYPE html>
<html>
<head>
<meta name="viewport" content="initial-scale=1.0, user-scalable=no" />
<style type="text/css">
  html { height: 100% }
  body { height: 100%; margin: 0; padding: 0 }
  #map_gps_tracking { height: 100% }
</style>
<script type="text/javascript"
    src="http://maps.googleapis.com/maps/api/js?key=AIzaSyDwzV0CV7pl6n_OLhl0ptI2rbKiBVLSQhA&sensor=true">
</script>
<script type="text/javascript" src="http://code.jquery.com/jquery-latest.js"></script>
<script type="text/javascript">
  var refreshId = setInterval(function() {
	$('#map_gps_position').fadeOut("slow").load('getposition.php').fadeIn("slow");
	}, 5000);
</script>
<script type="text/javascript">
  var _map;
  function initialize(lat, lng) {
    <?php if (!isset($lat) || !isset($lng)):?>
	    var latlng = new google.maps.LatLng(lat, lng);
    <?php else:?>
	    var latlng = new google.maps.LatLng(<?php echo $lat;?>, <?php echo $lng;?>);
    <?php endif;?>
    var myOptions = {
      zoom: 12,
      center: latlng,
      mapTypeId: google.maps.MapTypeId.ROADMAP
    };
    _map = new google.maps.Map(document.getElementById("map_gps_tracking"),
	myOptions);
  }
  function setMarker(lat, lng, _map) {
	var latlng = new google.maps.LatLng(lat, lng);
        var myOptions = {
            position: latlng,
	    map: _map
        };
	var marker = new google.maps.Marker(myOptions);
  }
</script>
</head>
<body>
  <div id="map_gps_tracking" style="float:left;width:80%; height:100%"><center><h2>GPS</h2></center></div>
  <div id="map_gps_position" style="float:left;width:19.6%; height:100%; overflow: auto; padding-left:5px">
<?php mysql_connect('127.0.0.1', 'root', 'lgvvG0ea');
mysql_select_db('gps');
$res = mysql_query('SELECT * FROM location');
if (mysql_num_rows($res) > 0):
	$flag = 0;
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
		if ($flag == 0):?>
			<script type="text/javascript">initialize(<?php echo $lat?>,<?php echo $lon?>);</script>
			<?php $flag = 1;
		endif;
		?>
		<script  type="text/javascript">setMarker(<?php echo $lat?>,<?php echo $lon?>,_map);</script>
		<?php echo "<b>".$val["sid"]."</b> is at position :<br>lat : <b>".$lat."</b><br>lon : <b>".$lon."</b><br><br>";?>
	<?php endwhile;
else:?>
	<script type="text/javascript">initialize(<?php echo $lat?>,<?php echo $lon?>);</script>
<?php endif;?>
   </div>
</body>
</html>
