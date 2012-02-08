<?php
extract($_GET);
if (!isset($lon) || !isset($lat) || !isset($id) || !isset($latP) || !isset($lonP))
	exit();
mysql_connect('127.0.0.1', 'root', 'lgvvG0ea'); 
mysql_select_db('gps');
if (mysql_num_rows(mysql_query('SELECT sid FROM location WHERE sid=\''.$id.'\'')) > 0)
	mysql_query('UPDATE location SET lat=\''.$lat.'\', lon=\''.$lon.'\', lonP=\''.$lonP.'\', latP=\''.$latP.'\' WHERE sid=\''.$id.'\'');
else
	mysql_query('INSERT INTO location(sid, lat, lon, latP, lonP) VALUE(\''.$id.'\',\''.$lat.'\',\''.$lon.'\',\''.$latP.'\',\''.$lonP.'\')');
?>
