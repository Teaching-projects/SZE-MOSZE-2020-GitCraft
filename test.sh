#!/bin/bash

IFS=$'\n'
rm output.txt
echo `./main Orc.json Elf.json` >> $2
echo `./main Elf.json Orc.json` >> $2
echo `./main Orc.json Troll.json` >> $2
echo `./main Troll.json Orc.json` >> $2
echo `./main Elf.json Troll.json` >> $2
echo `./main Troll.json Elf.json` >> $2