#!/bin/bash

filename=$1

# check file exist or not

if [ ! -f $filename ]; then
echo "File doesn't exist!"
exit 1
fi

# check argument

if [ $# -eq 0 ]; then
echo "No argument passed"
exit 2
fi

# use cut to get the IP and page

cut -f 1,4 $filename | grep "^.*/products/" | sort | uniq