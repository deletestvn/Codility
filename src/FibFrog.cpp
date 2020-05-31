// Lesson 13 - Fibonacci Numbers
// https://app.codility.com/programmers/lessons/13-fibonacci_numbers/fib_frog/

/*
The Fibonacci sequence is defined using the following recursive formula:

F(0) = 0
F(1) = 1
F(M) = F(M - 1) + F(M - 2) if M >= 2
A small frog wants to get to the other side of a river. 
The frog is initially located at one bank of the river (position −1) and wants to get to the other bank (position N). 
The frog can jump over any distance F(K), where F(K) is the K-th Fibonacci number. 
Luckily, there are many leaves on the river, and the frog can jump between the leaves, but only in the direction of the bank at position N.

The leaves on the river are represented in an array A consisting of N integers. 
Consecutive elements of array A represent consecutive positions from 0 to N − 1 on the river. Array A contains only 0s and/or 1s:

0 represents a position without a leaf;
1 represents a position containing a leaf.
The goal is to count the minimum number of jumps in which the frog can get to the other side of the river (from position −1 to position N). 
The frog can jump between positions −1 and N (the banks of the river) and every position containing a leaf.

For example, consider array A such that:

A[0] = 0
A[1] = 0
A[2] = 0
A[3] = 1
A[4] = 1
A[5] = 0
A[6] = 1
A[7] = 0
A[8] = 0
A[9] = 0
A[10] = 0
The frog can make three jumps of length F(5) = 5, F(3) = 2 and F(5) = 5.

Write a function:

int solution(vector<int> &A);

that, given an array A consisting of N integers, returns the minimum number of jumps by which the frog can get to the other side of the river. 
If the frog cannot reach the other side of the river, the function should return −1.

For example, given:

A[0] = 0
A[1] = 0
A[2] = 0
A[3] = 1
A[4] = 1
A[5] = 0
A[6] = 1
A[7] = 0
A[8] = 0
A[9] = 0
A[10] = 0
the function should return 3, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..100,000];
each element of array A is an integer that can have one of the following values: 0, 1.
*/

#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> &A) {
	int N = A.size();
	if (N == 0) return 1;

	// Generate all fibonacci numbers less than or equal to N + 1
	// Those are the potential distances a frog can jump
	// e.g. bank | 0 | 0 | 0 | bank, N = 3 and maximum distance is N + 1
	vector<int> fibonacci = { 1, 2 };
	int newFib = fibonacci[0] + fibonacci[1];
	int fibsNum = fibonacci.size();
	while (newFib <= N + 1) {
		fibonacci.push_back(newFib);
		fibsNum = fibonacci.size();
		newFib = fibonacci[fibsNum - 1] + fibonacci[fibsNum - 2];
	}
	

	// Find all leafs and assign them with initial jump 0
	// Assign -1 to tile without a leaf
	// Assign 0 to end bank
	vector<int> jumps;
	for (int i = 0; i < N; i++) {
		if (A[i] == 1) jumps.push_back(0);
		else if (A[i] == 0) jumps.push_back(-1);
	}
	jumps.push_back(0);

	// Calculate minimum jumps between starting bank to each leaf 
	for (int i = 0; i <= N; i++) {
		if (jumps[i] == -1) continue;

		for (int j = 0; j < fibsNum; j++) {
			int f = fibonacci[j];
			int leafCandidate = i - f;

			// 0. If the leafCandidate is before start bank, continue
			if (leafCandidate < -1) continue;

			// 1. If leaf can be jumped to from banks, minimum jump is 1
			if (leafCandidate == -1) jumps[i] = 1;

			// 2. If leaf can be jumped to from another leaf, calculate and compare the minimum jump
			else if (jumps[leafCandidate] > 0) {
				jumps[i] = (jumps[i] == 0) ? 1 + jumps[leafCandidate] : min(jumps[i], 1 + jumps[leafCandidate]);
			}
		}
	}

	return (jumps[N] == 0) ? -1 : jumps[N];
}