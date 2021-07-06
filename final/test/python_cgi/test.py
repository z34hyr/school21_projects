
from datetime import datetime
now = datetime.now()
dt_string = now.strftime("%d-%m-%Y %H:%M:%S")
print ("Content-Type: text/html\n")
print ("""<html>
 <head>
  <title>python CGI</title>
<body style="background-color:7dcf61;">
<face="purisa">	</face>
	<FONT size=38 face="purisa" color="blue">
		<MARQUEE scrollamount="10" >Hello, World! (from python)</MARQUEE>
	</FONT>
 </head>
 <body>
 <span style="font-size:40px; color:blue">Welcome to python-script-result page!</span>
 <br>
 <span style="font-size:20px; color:black">
 This page generated %s</span>
 <br>
 </body>
</html>""" % (dt_string))