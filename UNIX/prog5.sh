#!/bin/sh
#Author: Niranjan A

echo "Enter password"
stty -echo
read pass1

echo "Re-enter password"
read pass2

if [ $pass1 != $pass2 ]
then
	echo "Passwords did not match"
	stty echo
	exit
fi

echo "Password successfully set"
echo "Terminal locked. Enter the correct password to unlock the terminal"
trap '' 2
trap '' 20
while ( true )
do
	echo "Enter password: "
	read pass3
	
	if [ $pass3 = $pass1 ]
	then
		echo "Terminal unlocked"
		stty echo
		trap 2
		trap 20
		exit
	else
		echo "Wrong password"
	fi
done
