// Lesson 14 - Binary Search Algorithm
// https://app.codility.com/programmers/lessons/14-binary_search_algorithm/min_max_division/

/*
You are given integers K, M and a non-empty array A consisting of N integers. 
Every element of the array is not greater than M.

You should divide this array into K blocks of consecutive elements. 
The size of the block is any integer between 0 and N. Every element of the array should belong to some block.

The sum of the block from X to Y equals A[X] + A[X + 1] + ... + A[Y]. 
The sum of empty block equals 0.

The large sum is the maximal sum of any block.

For example, you are given integers K = 3, M = 5 and array A such that:

A[0] = 2
A[1] = 1
A[2] = 5
A[3] = 1
A[4] = 2
A[5] = 2
A[6] = 2
The array can be divided, for example, into the following blocks:

[2, 1, 5, 1, 2, 2, 2], [], [] with a large sum of 15;
[2], [1, 5, 1, 2], [2, 2] with a large sum of 9;
[2, 1, 5], [], [1, 2, 2, 2] with a large sum of 8;
[2, 1], [5, 1], [2, 2, 2] with a large sum of 6.
The goal is to minimize the large sum. In the above example, 6 is the minimal large sum.

Write a function:

int solution(int K, int M, vector<int> &A);

that, given integers K, M and a non-empty array A consisting of N integers, returns the minimal large sum.

For example, given K = 3, M = 5 and array A such that:

A[0] = 2
A[1] = 1
A[2] = 5
A[3] = 1
A[4] = 2
A[5] = 2
A[6] = 2
the function should return 6, as explained above.

Write an efficient algorithm for the following assumptions:

N and K are integers within the range [1..100,000];
M is an integer within the range [0..10,000];
each element of array A is an integer within the range [0..M].
*/

#include <vector>
#include <algorithm>

using namespace std;

int solution(int K, int M, vector<int> &A) {
	int N = A.size();

	// Calculate the sum of array A and find the maximum number inside
	int sum = 0;
	int maxNum = 0;
	for (int i = 0; i < N; i++) {
		if (A[i] != 0) {
			maxNum = max(maxNum, A[i]);
			sum += A[i];
		}
	}
	
	// 1. When we can have blocks more than elements, return the maximum element
	if (K >= N) return maxNum;
	
	// 2. When we can only have one block, return sum
	if (K == 1) return sum;

	// 3. When the result is between maxNum and sum, use Binary Search:
	int lowerBound = maxNum;
	int upperBound = sum;

	if (lowerBound == upperBound) return maxNum; // 0, 0, 0, maxNum, 0, 0, 0

	int candidate = (lowerBound + upperBound) / 2;

	// All goal is to narrow the bound so that candidate = upperBound = lowerBound
	while (lowerBound <= upperBound) {	
		int blockNum = 1; // This keep track of the number of blocks, with current candidate
		int blockSum = 0; // This keep track of the sum of current block
		bool isValid = true; // This shows if the current candidate is a valid candidate
		
		// Loop through the array
		// Add a element to blockSum, if sum(blockSum + element) <= candidate
		// Add a new block to blockNum. if sum(blockSum + element) > candidate
		for (int i = 0; i < N; i++) {
			blockSum += A[i];
			if (blockSum > candidate) {
				blockNum += 1;
				blockSum = A[i];
			}

			// When we have more blocks than K, current candidate is not valid
			if (blockNum > K) {
				isValid = false;
				break;
			}
		}

		// If current block is valid (we can have smaller candidate)
		// If current block is not valid (we need bigger candidate)
		if (isValid) upperBound = candidate - 1;
		else lowerBound = candidate + 1;
		candidate = (lowerBound + upperBound) / 2;
	}

	return lowerBound;
}