<?php
echo "Content-Type: text/html\n\n";
?>
<html>
 <head>
  <title>PHP CGI</title>
<body style="background-color:7dcf61;">
<face="purisa">	</face>
	<FONT size=38 face="purisa" color="blue">
		<MARQUEE scrollamount="10" >Hello, World! (from PHP)</MARQUEE>
	</FONT>
 </head>
 <body>
 <span style="font-size:40px; color:blue">Welcome to PHP-script-result page!</span>
 <br>
 <span style="font-size:20px; color:black">
 <?php
 $date = new DateTime("now", new DateTimeZone('Europe/Moscow'));
 echo 'This page generated '. $date->format('d-m-Y H:i:s');
 ?> </span>
 </body>
</html>
