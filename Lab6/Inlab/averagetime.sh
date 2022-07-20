# !/bin/bash  
# Name: Steven Song 
# UVA ID: sqs5hrn 
# Date: March 29, 2021 
# CS2150 Lab 6 In Lab averagetime.sh

# You must have !/bin/bash at the very first line of the script because otherwise it will use the wrong shell and the file won't work correctly
# Just follow the instructions in the PDR for the In Lab, listed under "Average Running Time"

# The shell script takes in two inputs (dictionary file and grid file), in that order, no command-line parameters

# The read command takes in the user input and puts it in a variable 

read dictionary 
# Enter dictionary file

read grid
# Enter grid file

# Prompts the user for the dictionary and grid file names used by your word puzzle executable

runtime = `./a.out $dict $grid | tail -1`

# You have to initialize it the first time. This captures the line by piping it through the tail -1 command. You have to run your program five times & calculate/print average time

# initializes sumnumbers
sumnumbers = $runtime

# It will record the time of each execution run and once the runs are completed, print out the average run time

# NOTE: This exact format for runtime was given to us in the PDR in the In Lab 

runtime = `./a.out $dict $grid | tail -1`

# You have to make sure that you do sumnumbers 4 times 

sumnumbers = $((sum+runtime))
runtime = `./a.out $dict $grid | tail -1`
sumnumbers = $((sum+runtime))
runtime = `./a.out $dict $grid | tail -1`
sumnumbers = $((sum+runtime))
runtime = `./a.out $dict $grid | tail -1`
sumnumbers = $((sum+runtime))

# Prints out the average run time

# From the PDR: You can always print out the value of the variable through the echo command, such as echo ${variable}

echo $((sumnumbers/5))

# Does the vision (saves the output as a variable) 

STUDENT
Steven Song
AUTOGRADER SCORE
10.0 / 10.0
