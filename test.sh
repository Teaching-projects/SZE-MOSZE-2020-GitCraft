#!/bin/bash

IFS=$'\n'

rm output.txt

#echo `./main sc_test.json < testinput.txt` >> output.txt
cat testinput.txt | ./main >> output.txt