#! /bin/bash
echo "n=?"
read n
a=0
b=1
for((i=0;i<$n;i++))
do 
  c=$((a+b))
  a=$b;
  b=$c;
  echo "$c"
done

