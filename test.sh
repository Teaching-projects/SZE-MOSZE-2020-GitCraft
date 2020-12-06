#!/bin/bash

IFS=$'\n'
#echo `./main test PreparedGame.json` > io_test.txt
echo `./main prepared PreparedGame.json < testinput.txt` >> output1.txt