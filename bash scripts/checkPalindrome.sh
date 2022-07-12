#!/bin/bash
echo "Enter a string>> "
echo
read str1
str2=$str1|rev
if [$str1==$str2]
then
  echo "$str1 is a palincrome"
else
  echo "$str1 is not a palindrome"
fi
