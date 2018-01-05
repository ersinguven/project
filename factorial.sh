#!/bin/bash

factorial=1
counter=$1

while [[ "$counter" -ne 0 ]]
do
	factorial=$(($factorial*$counter))
	counter=$(($counter - 1 ))
done
echo $factorial

