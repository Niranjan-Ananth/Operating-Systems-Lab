#!/bin/sh
#Author: Niranjan A

echo "Enter three numbers"
read a
read b
read c

if [ $a -gt $b ]
then
	if [ $a -gt $c ]
	then 
		echo "$a is the largest"
	else
		echo "$c is the largest"
	fi
else
	if [ $b -gt $c ]
	then 
		echo "$b is the largest"
	else
		echo "$c is the largest"
	fi
fi

