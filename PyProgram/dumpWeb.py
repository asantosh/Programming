#!/usr/bin/python

#import webbrowser
#webbrowser.open('http://www.google.com')

import sys
import urllib

#print entire file
def dumpEntireFile(link):
	f = urllib.urlopen(link)
	myfile = f.read()
	print myfile

# print line by line
def dumpEachLine(link):
	f = urllib.urlopen(link)
	count = 0
	for line in f.readlines():
		count += 1
		print "********  " + str(count) + "  *********"
		print line
	print "*************** END ***************"


def main(argv):
	link = "http://www.google.com"
	arglen = len(sys.argv)
	dumpline = 0
	if arglen > 1:
		link = str(sys.argv[1])
		if arglen == 3:
			dumpline = int(sys.argv[2])
	print "Link is :[" + link +"]"
	
	if dumpline:
		dumpEachLine(link)
	else :
		dumpEntireFile(link)


if __name__ == "__main__":
	main(sys.argv)
