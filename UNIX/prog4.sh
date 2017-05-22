#!/bin/sh
#Author: Niranjan A
if [ $# -lt 1 ]
then
	echo "Invalid number of arguments"
	exit
fi

for login1 in $*
do
	if grep $login1 /etc/passwd
	then
		echo "Login : $login1"
		dir1=`grep $login1 /etc/passwd | cut -d ":" -f 6`
		lis=`ls $dir1`
		echo "Home directory: $dir1"
		echo "List: $lis"
	else
		echo "Invalid user"
	fi
done
