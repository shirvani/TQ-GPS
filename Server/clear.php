<?php 
extract($_GET);
if (!isset($id))
	exit();
mysql_connect('127.0.0.1', 'root', 'lgvvG0ea'); 
mysql_select_db('gps');
mysql_query('DELETE FROM location WHERE sid=\''.$id.'\'');
?>
