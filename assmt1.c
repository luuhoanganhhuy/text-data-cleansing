/* Tweet cleanser:
 * Removes non-alphanumeric characters from tweets
 *
 * Skeleton code written by Yi Han and Jianzhong Qi, April 2019
 *
 */
/*Algorithms are fun */
/*Answer code written by Hoang Anh Huy Luu, StudentID 1025379, May 2019*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
/* stage numbers */
#define STAGE_NUM_ONE 1
#define STAGE_NUM_TWO 2
#define STAGE_NUM_THREE 3
#define STAGE_NUM_FOUR 4
#define STAGE_NUM_FIVE 5
#define STAGE_HEADER "Stage %d\n==========\n"	/* stage header format string */

#define MAX_TWEET_LENGTH 280					/* maximum length of a tweet */
#define MAX_NUM_TWEETS 100						/* maximum number of tweets */

typedef char tweet_t[MAX_TWEET_LENGTH+1];		/* a tweet */

/****************************************************************/

/* function prototypes */
void read_one_tweet(tweet_t one_tweet, int max_len);
void print_stage_header(int stage_num);
void tweet_tolower(tweet_t one_tweet);

void stage_one(tweet_t one_tweet);
void stage_two(tweet_t tweets[], int *num_tweets);
void stage_three(tweet_t tweets[], int num_tweets);
void stage_four(tweet_t tweets[], int num_tweets);
void stage_five(tweet_t tweets[], int num_tweets);

/* add your own function prototypes here */
/****************************************************************/
void remove_nonalpha(char *str);
void remove_aster(char *str);
int is_contained(char *s1, char *s2);
int check_duplicated_array(int position, int *array, int len_array);
void swap_str(char str1[], char str2[]);
void sort_strings(char str[MAX_NUM_TWEETS][MAX_TWEET_LENGTH+1], int len);
/* main function controls all the action, do NOT modify this function */
int
main(int argc, char *argv[]) {
	/* to hold all input tweets */
	tweet_t tweets[MAX_NUM_TWEETS];
	/* to hold the number of input tweets */
	int num_tweets = 0;

	/* stage 1: reading the first tweet */
	stage_one(tweets[num_tweets]);
	num_tweets++;

	/* stage 2: removing non-alphanumeric characters */
	stage_two(tweets, &num_tweets);

	/* stage 3: removing extra asterisks and finding the longest tweet */
	stage_three(tweets, num_tweets);

	/* stage 4: finding the non-contained tweets */
	stage_four(tweets, num_tweets);

	/* stage 5: sorting the tweets */
	stage_five(tweets, num_tweets);

	/* all done; take some rest */
	return 0;
}

/* read a line of input into one_tweet */
void
read_one_tweet(tweet_t one_tweet, int max_len) {
	int i = 0, c;

	while (((c = getchar()) != EOF) && (c != '\n') && (c != '\r')) {
		if (i < max_len) {
			one_tweet[i++] = c;
		} else {
			printf("Invalid input line, toooooooo long.\n");
			exit(EXIT_FAILURE);
		}
	}
	one_tweet[i] = '\0';
}

/* print stage header given stage number */
void
print_stage_header(int stage_num) {
	printf(STAGE_HEADER, stage_num);
}

/****************************************************************/
/* add your code below */

/* scan a tweet and convert all English letters into lowercase */
void
tweet_tolower(tweet_t one_tweet) {
	/* add code here to convert English letters in one_tweet into lowercase */
	for(int i = 0; one_tweet[i]; i++){
		/* convert to lowercase letter by letter */
		one_tweet[i] = tolower(one_tweet[i]);
	}
}

/* stage 1: reading the first tweet */
void
stage_one(tweet_t one_tweet) {
	/* print stage header */
	print_stage_header(STAGE_NUM_ONE);

	/* add code to call the read_one_tweet function to read the first tweet */
	read_one_tweet(one_tweet, MAX_TWEET_LENGTH);

	/* add code into the tweet_tolower function
	 * to convert English letters into lowercase
	 */
	tweet_tolower(one_tweet);

	/* print result */
	printf("%s\n\n", one_tweet);
}

/* stage 2: removing non-alphanumeric characters */

/* a fuction to remove the non-alphanumeric characters in  a string*/
void remove_nonalpha(char *str){
	int i = 0, j = 0;
	char c;
	while ((c = str[i++]) != '\0'){
		/*check if c is a alphanumeric character or a asterisk*/
		if (isalnum(c) || c == '*'){
			/* if c is a alphanumeric character or a asterisk then add c to the string*/
			str[j++] = c;
		}
	}
/*end the string with a null value*/
str[j] = '\0';
}

void
stage_two(tweet_t tweets[], int *num_tweets) {
	/* print the stage header */
	print_stage_header(STAGE_NUM_TWO);

	/*assign all tweets in the input to the corresponding num_tweet*/
	/*check if the program reach the end of the input file*/
	while (tweets[*num_tweets-1][0]  != '\0'){
		/*use the read_one_tweet to assign the tweet to the corresponding
		num_tweets */
		read_one_tweet(tweets[*num_tweets],MAX_TWEET_LENGTH);
		*num_tweets =*num_tweets +1;
	}
	/*count the number of tweets*/
	*num_tweets = *num_tweets -1;

	/*change all tweets to lowercase characters*/
	for (int i =0; i < *num_tweets;i++){
		tweet_tolower(tweets[i]);
	}

	/*remove all the non-alphanumeric characters expect the asterisks*/
	for (int i =0; i < *num_tweets; i++){
			remove_nonalpha(tweets[i]);
	}

	/*print all the non-alphanumeric characters*/
	for (int i =0; i < *num_tweets;i++){
		printf("%s\n",tweets[i]);
	}

	printf("\n");
}

/* stage 3: removing extra asterisks and finding the longest tweet */

/*function to remove the extra asterisks*/
void remove_aster(char *str){

	/*change the consecutive asterisks to the '^' characters */
	for (int i=0; i< strlen(str);i++){
		if (str[i] == '*' && str[i+1] =='*'){
			str[i] = '^';
		}
	}

	/*remove the consecutive asterisks via '^' */
	int j = 0;
	for (int i=0; i< strlen(str);i++){
		if (str[i] != '^'){
			str[j] = str[i];
			j++;
		}
	}
	str[j] = '\0';

	/*remove the asterisk at the end of the string*/
	int len = strlen(str);
  if (str[len-1] =='*'){
    str[len-1] = '\0';
  }

	/*remove the asterisk at the start of the sting*/
	int i;
	if (str[0] == '*'){
		for (i= 0; i < (strlen(str)-1);i++){
			str[i] = str[i+1];
		}
	str[i] = '\0';
  }
}

void
stage_three(tweet_t tweets[], int num_tweets) {
	/* add code for stage 3 */
	/*print the header*/
	print_stage_header(STAGE_NUM_THREE);

	/*call the remove_aster function to romore the asterish for every tweet*/
	for (int i =0; i < num_tweets;i++){
		remove_aster(tweets[i]);
	}

	/*print the non-extra asterish tweet*/
	for (int i =0; i < num_tweets;i++){
		printf("%s\n",tweets[i]);
	}

	/*print the number of tweets*/
	printf("Total: %d\n",num_tweets);

	/*find the longest tweet*/
	int max = strlen(tweets[0]);
	int max_num =0;
	for (int i =1; i < num_tweets;i++){
		if (strlen(tweets[i])>max){
			max = strlen(tweets[i]);
			max_num = i;
		}
	}

	/*print the longest tweet and its length*/
	printf("Longest: %s\n",tweets[max_num]);
	printf("Length: %d\n",max);
	printf("\n");
}

/* stage 4: finding the non-contained tweets */

/*check a string is conatined in other strings
using the idea from getword() function in lecture 6 comp10002*/

int is_contained(char *s1, char *s2) {

	 assert(s1);
	 assert(s2);
	  /* loop through each character of both string to find
		the matching characters */
	 while (*s1 && *s2) {
		if (*s1 == *s2) {
			/* match found, can increase both */
			s1++; s2++;
			/*check if they are matching consecutively*/
			if (*s1 != *s2){
				if (*s2 != '*'){
					return 0;
				}
			}
		} else {
			/* no match, increase s2 only */
			s2++;
		}
	}

	if (*s1) {
		/* didn't get to end of s1, so subsequence does not
		   exist */
		return 0;
	} else {
		/* s1 is done, so regardless of where s2 is now, must
		   have matched all characters of s1 */
		return 1;
	}
}


int check_duplicated_array(int position, int *array, int len_array){
	for (int j=0; j< len_array; j++){
		if (position == array[j]){
			return 1;
		}
	}
	return 0;
}

void
stage_four(tweet_t tweets[], int num_tweets) {
	/* add code for stage 4 */
	int arr[MAX_NUM_TWEETS], num_non_contained=0;

	/*print the header*/
	print_stage_header(STAGE_NUM_FOUR);

	/*loop thourgh every tweet to find the contained tweet*/
	for (int i =0; i < num_tweets;i++){
		for(int j=0; j < num_tweets;j++){
			if (i != j){
				/*make sure that don't check on the same tweet*/
				if (is_contained(tweets[i], tweets[j]) == 1){
					/*assign the string to an array corresponding to its position*/
					arr[num_non_contained] = i;
					num_non_contained++;
				}
			}
		}
	}

	/*remove the duplicated array and count the numbers of non-contained array*/
	int count =0;
	for (int i =0; i < num_tweets;i++){
		if (!check_duplicated_array(i, arr, num_non_contained)){
			/*print the non-contained arrays*/
				printf("%s\n",tweets[i]);
				count++;
		}
	}
	/*print the numbers of non-contained arrays*/
	printf("Non-contained: %d\n", count);
	printf("\n");
}

/* stage 5: sorting the tweets */
#define EQUAL 0

/*function to swap the position of two tweets*/
void swap_str(char str1[], char str2[]) {
	char temp[MAX_TWEET_LENGTH];
	strcpy(temp, str1);
  strcpy(str1, str2);
  strcpy(str2, temp);
}

/*function to sort the tweets based on their alphabetical order*/
void sort_strings(char str[MAX_NUM_TWEETS][MAX_TWEET_LENGTH+1], int len) {
	int i = 0;
  while (i < len) {
		int j = 0;
    while (j < len) {
			if ((strcmp(str[i], str[j]) < EQUAL)) {
				/*swap the position if the value of the first tweet bigger than the
				second tweet*/
				swap_str(str[i], str[j]);
      }
		j++;
    }
	i++;
  }
}

void
stage_five(tweet_t tweets[], int num_tweets) {
	/* add code for stage 5 (optional stage) */
	/*print the header*/
	print_stage_header(STAGE_NUM_FIVE);

	/*use sort_strings fuction to re-order the tweets as alphabetical order*/
	sort_strings(tweets,num_tweets);

	/*re-order the tweets based on their length*/
	for (int i =0; i < num_tweets;i++){
		for ( int j = i+1; j< num_tweets;++j){
			if (strlen(tweets[i]) > strlen(tweets[j])) {
				/*swap the position if length of first tweets bigger than length of
				second tweet*/
 				swap_str(tweets[i],tweets[j]);
			}
		}
	}

	/*print tweets which are re-order already*/
	for (int i =0; i< num_tweets;i++){
		printf("%s\n",tweets[i]);
	}
}
/*Algorithms are fun*/
