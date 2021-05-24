#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
/*
A company is looking to hire an employee based on answers to a questionnaire. The questionnaire has
20 yes/no questions (labeled from question 0 to question 19) and an applicant’s set of responses is stored
as a single integer such that the ith bit is set to 1 if the response to question i is yes, and it’s set to 0 if the
response to question i is no. For example, if an applicant answered yes to questions 0, 2, 3, 5, 8, and 10
and no to the other 14 questions, her responses would be stored as the single integer 1325, since
000000000101001011012 = 1325. For all questions, the company prefers yes answers to no answers.
However, since it’s unlikely that a candidate will answer yes to all of the questions, they have developed
a modified scoring system for each candidate. The company has ranked each of the 20 questions in order
of preference from most important to least important. This ranking is an array, preferences, that stores a
permutation of the integers from 0 to 19, inclusive. For example, if preferences[0] = 8, preferences[1] =
10 and preferences[2] = 1, then the company cares most about the answer to question 8, second most
about the answer to question 10 and third most about the answer to question 1. A candidate's score is
simply the maximum number of the most important questions they answered yes without a single no.
For example, the sample candidate described above would have a score of 2, because she said yes to
questions 8 and 10, but no to question 1, which was third on the preference list. Any candidate who said
no to question 8 would be assigned a score of 0. Complete the function below so it returns the score of
the applicant whose answers are stored in the formal parameter applicant. The formal parameter
preferences is an array of size 20 which stores the order of importance of the questions as previously
described. (Note: You must use bitwise operators to earn full credit for this question.)

#define SIZE 20
int score(int preferences[], int applicant) {
 int res = 0; // Grading: 1 pt
 for (res=0; res<SIZE; res++) // Grading: 2 pts
 if ( (applicant & (1<<preferences[res])) == 0) // 5 pts
 break; // Grading: 1 pt
 return res; // Grading: 1 pt
}
//Grading Note: Student answers may look different than this. 4 pts are awarded for the general set
//up of having an variable keeping track of the answer, returning it and loop through the search
//space. 6 pts are allocated for the logic of deciding when to stop. We can break down those points
//as follows:
//2 pts for accessing the right question preference
//1 pt for bit shifting this value or equivalent (could right shift applicant…)
//2 pts for taking the former and bitwise anding it with applicant
//1 pt for stopping the loop at the appropriate time
*/

/*In the game of NIM, there are several piles with stones and two players alternate taking 1 or more stones
from a single pile, until there are no more stones left. The person who takes the last stone wins. It turns
out that if it's someone's turn, if they play optimally, they can win as long as the bitwise XOR of all of
the number of stones in each pile is not equal to 0. Write a function that takes in an array of values
representing the number of stones in the piles of NIM and the length of that array, and returns 1, if the
current player can win, and 0 otherwise, assuming both players play optimally.


int canWinNIM(int piles[], int numPiles)
{
    int ret = piles[0];
    for (int i = 1; i < numPiles; i++)
    {
        ret = ret ^ piles[i];
    }
    if (ret != 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//100 % wouldve gotten 10/10
*/

/*
Imagine a dating website that asks each user 20 yes/no questions and stores their answers in a single
integer in between 0 and 2^20-1, with the answer to the kth question stored in bit 2k-1
, with the bit 0
representing the answer no and the bit 1 representing the answer yes for the corresponding question. (So
for example, if one person’s answers to questions 1, 3 and 4 were yes and the rest of the answers were
no, the integer 11012 = 13 would be used to represent her 20 answers to the questions.) Consider the
problem of finding the “best match” for a client out of a list of prospective matches. We consider a
match A for the client to be better than match B if she shares more answers on corresponding questions
with A than B. Write a function that takes in an integer representing the client’s answers, an array of
integers storing the answers of potential matches, and the length of that array, which returns the index
into the array storing the best match for that client. If there are multiple best matches, you may return the
index associated with any of them. A function has been given that you may call in your code, if you find
it useful.

2 2/3 / 10 = 27%

int count(int mask);

int bestMatch(int client, int *matches, int length)
{
    int bestIndex = 0, currentBest = -1; // 2/3 point on var dec (missed currentBest)
    for(int i = 0; i < length; i++) // 1 point for loop
    {
        int temp = 20 - (count(client ^ matches[i]));//missed 5 points
        if(temp > currentBest)//missed 2 points
        {
            currentBest = temp;
            bestIndex = i;
        }
    }
    return bestIndex;//1 point for return
}
//given helper function
int count(int mask)
{
    int res = 0, i;
    for (i = 0; i < 32; i++)
        if ((mask & (1 << i)) != 0)
            res++;
    return res;
}
*/

// What is the output of the following program?
#include <stdio.h>
int main()
{
    int n = 182, i = 0;
    while (n > 0)
    {
        if ((n & (1 << i)) > 0)
        {
            printf("%d\n", (1 << i));
            n ^= (1 << i);
        }
        i++;
    }
    return 0;
}
