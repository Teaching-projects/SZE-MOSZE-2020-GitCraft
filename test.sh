#!/bin/bash

#IFS=$'\n'

#rm output.txt

#echo `./main sc_test.json < testinput.txt` >> output.txt
#cat testinput.txt | ./main sc_test.json >> output.txt


FILE=output.txt
INPF=sc_test.json

if test -f $FILE
then
	rm $FILE
fi

cat testinput.txt | ./main >> $FILE