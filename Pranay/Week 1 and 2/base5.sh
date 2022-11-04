echo -n "Enter any decimal no: "
read num
rem=1
bno=""
while [ $num -gt 0 ]
do
rem=$((num%5))
bno=$rem$bno
num=$((num/5))
done
echo "The converted base 5 number: $bno"
