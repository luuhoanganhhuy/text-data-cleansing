# Text-Data-Cleansing
## Introduction:
Social media contain variable information so to effectively make use of these contents for analytics purpose, etc, we should sure they are well-formatted. In this project, I will write some basic code to clean up noisy data from a list of user post.

## Implementation:
Assume that I have a input file contains multiple lines. Each lines has at least 1 and at most 280 characters ( at least 1 of the characters is an English letter or digit). There are at least 1 and at most 100 lines.
## Project:
This project will be divided into 5 stages: 
### Stage 1:
Read each line of the input and change all the all the character to lower case.
### Stage 2:
Remove non-alphanumeric characters by keep only English character, digits, and asterisk
### Stage 3:
Remove all the duplicated asterisk ( leading, trailing, and consecutive asterisk).

Return the number of total tweets in input and also return the tweet with the longest length.
### Stage 4: 
Find the tweets that is not fully contained in the other tweets and return the total number of these tweets.

### Stage 5:
Sort the tweets and return them at ascending order of their length.

## Note: 
This project is a university assignment from Foundation of Algorithms subject in The University of Melbourne, Department of Computing and Software System, Semester 1 2019.
