#!/bin/bash
echo "n=?"
read n
for((i=2;i<n/2;i++))
do
  if[ $((n%i)) -eq 0 ]
  then
    flag=1
    break;
  fi
if[$((flag))==1]
then
  echo "$n is not prime no"
else
  echo "$n is a prime no"
fi
done

