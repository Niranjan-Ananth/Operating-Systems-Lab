#!/bin/sh

if [ $# -gt 0 ]
then 
	while [ $# -gt 0 ]
	do
		rev="$1 $rev"
		shift
	done
	echo "$rev"
else
	echo "Invalid number of arguments"
fi
