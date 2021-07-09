
from datetime import datetime
import os
import Cookie

def isNewUser(cookies):
	if (cookies != False):
		return ("session" not in cookies)
	return True

def hasPythonCounter(cookies):
	if (cookies != False):
		return "python_counter" in cookies
	return False

def incrementCounter(cookies):
	cookies = Cookie.SimpleCookie(os.environ["HTTP_COOKIE"])
	if (cookies != False and "python_counter" in cookies):
		cookies["python_counter"] = int(cookies["python_counter"].value) + 1
		print(cookies["python_counter"])

def getCounterValue(cookies):
	if (cookies != False and "python_counter" in cookies):
		return cookies["python_counter"].value
	return 0
def getAllCookie():
	try:
		return Cookie.SimpleCookie(os.environ["HTTP_COOKIE"])
	except (Cookie.CookieError, KeyError):
		return False


now = datetime.now()
dt_string = now.strftime("%d-%m-%Y %H:%M:%S")
cookies = getAllCookie()
if (isNewUser(cookies) or not hasPythonCounter(cookies)):
	print ("Set-Cookie: python_counter=1")
else:
	incrementCounter(cookies)
if (isNewUser(cookies)):
	cookie_string = "Hello newbie!"
else:
	cookie_string = "I know you! You've been there " + str(getCounterValue(cookies)) + " time(s)"
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
 This page generated %s %s</span>
 <br>
 </body>
</html>""" % (dt_string, cookie_string))

