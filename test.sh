#!/bin/bash

IFS=$'\n'

rm output.txt

echo `./main sc_test.json < testinput.txt`  >> $2
