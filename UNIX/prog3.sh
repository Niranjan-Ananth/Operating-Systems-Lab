#!/bin/sh
#Author: Niranjan A
echo "Enter a directory"
read dir1

if [ ! -d $dir1 ]
then
	echo "Not a directory!"
	exit
fi

large=0
for file1 in `find $dir1 -type f`
do
	size=$(wc -c <"$file1")
	echo "$file1: $size"
	if [ $size -gt $large ]
	then
		large=$size
		larfile=$file1
	fi
done
echo "Largest file is : $larfile"
echo "Size: $large"
