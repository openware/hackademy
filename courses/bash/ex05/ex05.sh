 #!/bin/bash

if [ "$#" -lt 2 ]; then
    echo "Usage: $0 {-m|-s|-e|-o} number1 number2 ..." >&2
    exit 1
fi

operation=$1
shift

sum=0
count=0
even_sum=0
odd_sum=0

for number in "$@"; do
    sum=$(echo "$sum + $number" | bc)
    count=$((count + 1))
    if [ $((number % 2)) -eq 0 ]; then
        even_sum=$(echo "$even_sum + $number" | bc)
    else
        odd_sum=$(echo "$odd_sum + $number" | bc)
    fi
done

case $operation in
    -s)
        echo "Sum: $sum"
        ;;
    -e)
        echo "Sum of even numbers: $even_sum"
        ;;
    -o)
        echo "Sum of odd numbers: $odd_sum"
        ;;
    -m)
        if [ $count -ne 0 ]; then
            mean=$(echo "scale=2; $sum / $count" | bc)
            echo "Mean: $mean"
        else
            echo "No numbers provided to calculate mean"
        fi
        ;;
    *)
        echo "Invalid option. Usage: $0 {-m|-s|-e|-o} number1 number2 ..." >&2
        exit 1
        ;;
esac

exit 0
