#!/bin/bash

#IFS=$'\n'
#echo `./main test PreparedGame.json` > io_test.txt
#echo `./main prepared PreparedGame.json < testinput.txt` > io_test.txt
echo `printf 'west south south east east south south east east east west north north east north east' | ./main prepared PreparedGame.json` > io_test.txt