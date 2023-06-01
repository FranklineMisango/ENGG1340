#!/bin/bash

# change directory to the Assignments folder
cd Module2/Assignments/

# set the paths for the input and correct output files
input_file="input.txt"
correct_output_file="correct.txt"

# loop through all the student directories
for student_dir in */; do
  # change directory to the student's folder
  cd "$student_dir"

  # set the path for the student's submission file
  submission_file="submission.txt"

  # execute the student's submission with the input file and store the output in a variable
  student_output=$(./"$submission_file" < ../"$input_file")

  # compare the student's output to the correct output
  if diff -B -Z ../"$correct_output_file" <(echo "$student_output"); then
    # if the output is correct, print "PASS" and save the score to a file
    echo "PASS" > score.txt
  else
    # if the output is incorrect, print "FAIL" and save the score to a file
    echo "FAIL" > score.txt
  fi

  # change directory back to the Assignments folder
  cd ..
done
