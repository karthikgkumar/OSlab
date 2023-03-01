echo "Enter the number"
read n 
i=2
while [ $i -le  $(($n/2)) ]
do
    if test `expr $n % $i` -eq 0
    then 
        echo "Not prime"
        exit
    fi
    i=$(($i+1))
done
echo "prime"