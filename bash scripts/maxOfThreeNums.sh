#!/bin/bash

echo "Enter three nums (space seperated):"
read  a b c

if [ $a -gt $b ]
then if [ $a -gt $c ]
     then echo "$a is Maximum"
     fi
fi
if [ $b -gt $a ]
then if [ $b -gt $c ]
     then echo "$b is Maximum"
     fi
fi
if [ $c -gt $b ]
then if [ $c -gt $a ]
     then echo "$c is Maximum"
     fi
fi
