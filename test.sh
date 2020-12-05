#!/bin/bash

#echo `./main sc_test.json < testinput.txt`  >> $2
cat testinput.txt | ./main sc_test.json >> $2