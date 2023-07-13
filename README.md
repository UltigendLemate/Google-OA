# Google-OA
Online Coding Assessment of Google

2 questions were asked on HackerEarth. 2 hr window. Could attempt for 1 hour.
The camera was not on. Mic was not on. We could not change tabs. We could not paste anything on the code editor.
In 1 question, the function was implemented and we had to code just the function, in the other question, we had to code main() function ourselves from scratch.

*merse toh hua nahi ek bhi time par. Time end hone ke bad second vala karlia tha. I hope tumhara hojae*

---

## Q1
Given a string, and integer K, find out the number of special subsequences that can be formed.
a sequence is special if:
1) it has a length of exactly K.
2) it contains all unique characters.
3) The sum of the frequencies of all the characters in the subsequence is the maximum possible sum among all special subsequences of length K.

Didn't understand the 3rd point? guess what? I didn't as well! Exactly this was written in the question. no more no less.
every input has n (length of string), k and string

### Contraints
- 1<=T<=10
- 1<=N<=1e5
- 1<=K<=N
- S contains only latin lowercase alphabets

### Sample Inputs
Sample input:
5 4 cppbg\
Output :\
2\
Explanation:\
cpbg (where the index of p is 1)\
cpbg (where the index of p is 2)


Sample Input 1: 12 8 fpbavjsmppdt\
Sample Output 1: 108

Sample Input 2: 16 7 ppzfsncqyzmuwrcv\
Sample Output 2: 1680

Find the code [here](/test.cpp)

---

## Q2
Given an array S of N elements. We need to find the count of distinct arrays A of N elements that exists such that:
- A[i] < A[i+1]
- Sum of digits of A[i] = S[i]
- 1<=A[i]<=1e3

answer modulo 1e9+7

### Input Format
Test Cases\
N\
N spaced integers denoting S

### Constraints
- 1<=T<=5
- 1<=N<=100
- 1<=S<=30

### Sample Inputs
Input:\
1\
2\
2 1\
Output:
10

Explanation:
Following arrays are possible:\
2 10\
2 100\
2 1000\
11 100\
11 1000\
20 100\
20 1000\
101 1000\
110 1000\
200 1000

Sample Input 1:\
4\
3\
10 15 16\
6\
3 6 10 14 12 17\
10\
3 9 9 3 11 7 14 15 11 17\
9\
2 7 3 5 9 14 11

Sample Output 1:\
101776\
142727553\
303300404\
19829619

Sample Input 2:\
2\
3\
8 7 12\
7\
9 3 5 11 12 9 14

Sample Output 2:\
30242\
288757998

You can find the code [here]()










