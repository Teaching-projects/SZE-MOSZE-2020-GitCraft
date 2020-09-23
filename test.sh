#!/bin/bash

IFS=$"\n"
rm output.txt
echo `./main Orc.json Elf.json`
echo `./main Elf.json Orc.json`
echo `./main Orc.json Troll.json`
echo `./main Troll.json Orc.json`
echo `./main Elf.json Troll.json`
echo `./main Troll.json Elf.json`