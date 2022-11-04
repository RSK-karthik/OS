echo -n "Enter Base 5 number: "
read bno
dec=0
pow=1
while [ $bno -gt 0 ]
do
val=$((bno%10))
dec=$((dec+val*pow))
bno=$((bno/10))
pow=$((pow*5))
done
echo "The Decimal number is: $dec"
