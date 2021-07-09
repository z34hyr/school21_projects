<?php
function getAllCookie()
{
	if (isset($_SERVER["HTTP_COOKIE"])) {
		$cookies = explode(';', $_SERVER['HTTP_COOKIE']);
		if ($cookies === false)
			return [];
		$tmp = [];
		foreach($cookies as $cookie) {
			$tmp2 = explode('=', $cookie);
			if ($tmp2 !== false)
				$tmp[$tmp2[0]] = $tmp2[1];
		}
		return $tmp ?? [];
	}
	return [];
}

$cookies = getAllCookie();
if (!isset($cookies['session']) || !isset($cookies['php_counter'])) {
	echo ("Set-Cookie: php_counter=1\n");
} else {
	$counter_value = (int)$cookies['php_counter'] + 1;
	echo ("Set-Cookie: php_counter=" . $counter_value . "\n");
}
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
 ?> 
<?php 
	if (!isset($cookies['session'])) {
		echo("Hello newbie!");
	} else {
		echo("I know you! You've been there " . ($cookies['php_counter'] ?? 0) . " time(s)");
	}
?>
</span>
 </body>
