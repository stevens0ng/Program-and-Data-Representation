#!/bin/bash
# Name: Steven Song
# UVA ID: sqs5hrn 
# CS2150 Lab 7 Post Lab averagetime.sh
# Date: April 8, 2021 

#Takes in the number of iterations as a single input value 
read input 
quit="quit"
#If the input is quit, then the script should exit 
if [$quit == $input]
    then
    exit
fi
#The fi "then" must immediately follow the "if" for the body 
#Compiles the program for counter.cpp 
clang++ -O0 counter.cpp
#Your shell script MUST have an if statement to see if it should exit and MUST have either a for loop or a while loop (I used a while loop in mine) 
#There should be NO spaces for around the equal signs when setting variables 
doloop=0
sumtotal=0
#Executes the program a total of 5 times
#This program MUST have a while loop so I used a while loop here  
while [$doloop -lt 5]
do
runtime=`./a.out $e | tail -1`
#To grab program output (such as the output of the binary program), you should use back quotes (')    
#Prints out the execution/run time taken for each iteration 
echo $runtime
#When adding up values, using arithmetic expansion $((..)) there should be spaces around the arithmetic operators as well as an equals sign within the parentheses
sumtotal=$((sumtotal+runtime))
doloop=$[$doloop+1]
done
#Prints out the sum of the time taken for all of the iterations 
echo $sumtotal
#Prints out the average time taken for each iteration 
echo $((sumtotal/5))
