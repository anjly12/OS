echo "Enter the first number:"
read x
echo "Enter the second number:"
read y
echo "Menu: 1.Addition 2.Subtraction 3.Division 4.Multiplication"
read op
case $op in 
     1) rs=$(($x+$y))
        echo "Sum="$rs;;
     2) rs=$(($x-$y))
        echo "Difference="$rs;;
     3) rs=$(($x/$y))
        echo "Quotient="$rs;;
     4) rs=$(($x*$y))
        echo "Product="$rs;;
     *) echo "Invalid Operation!";;
esac
