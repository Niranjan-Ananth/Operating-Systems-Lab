#!/bin/sh

if [ $# -gt 2 -o $# -lt 2 ]
then
	echo "Invalid number of arguments"
	exit
fi

f1=`ls -l $1|cut -c2-10`
f2=`ls -l $2|cut -c2-10`
if [ $f1 = $f2 ]
then
	echo "Same Permissions"
	echo "$f1"
else
	echo "Different permissions"
	echo "File1: $f1"
	echo "File2: $f2"
fi
	 
	
