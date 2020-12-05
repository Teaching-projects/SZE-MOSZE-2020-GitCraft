#!/bin/bash

#IFS=$'\n'

#rm output.txt

#echo `./main sc_test.json < testinput.txt` >> output.txt

IFS=$'\n'
rm output.txt
for i in `cat testinput.txt`; do
    echo "$i" | `./main sc_test.json` >> output.txt
done