#!/bin/bash

IFS=$'\n'

echo "$(valgrind --leak-check=yes --log-file=valgrind_check.txt ./a.out Troll.json Elf.json)"
valgrind_check_result="$(cat ./valgrind_check.txt)"
echo $valgrind_check_result

memory_leak_errors="$(echo $valgrind_check_result | sed 's/^.*ERROR SUMMARY: \([0-9]*\) errors.*$/\1/')"

if ["$memory_leak_errors" == "0"]
then
    echo "No memory leaks!"

else
    echo "Memory leaks found!"
    exit 1
fi