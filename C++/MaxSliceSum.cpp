// Lesson 9 - Maximum Slice Problem
// https://app.codility.com/programmers/lessons/9-maximum_slice_problem/max_slice_sum/

/*
A non-empty array A consisting of N integers is given. 
A pair of integers (P, Q), such that 0 ≤ P ≤ Q < N, is called a slice of array A. 
The sum of a slice (P, Q) is the total of A[P] + A[P+1] + ... + A[Q].

Write a function:

int solution(vector<int> &A);

that, given an array A consisting of N integers, returns the maximum sum of any slice of A.

For example, given array A such that:

A[0] = 3  A[1] = 2  A[2] = -6
A[3] = 4  A[4] = 0
the function should return 5 because:

(3, 4) is a slice of A that has sum 4,
(2, 2) is a slice of A that has sum −6,
(0, 1) is a slice of A that has sum 5,
no other slice of A has sum greater than (0, 1).
Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..1,000,000];
each element of array A is an integer within the range [−1,000,000..1,000,000];
the result will be an integer within the range [−2,147,483,648..2,147,483,647].
*/

#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> &A) {
	// Kadane's Algorithm to Maximum Sum Subarry Problem
	// Example: A = [1, -3, 2, 1, -1]
	// 1. For each index, find the max slice such that it ends at current index:
			// 0: 1
			// 1: 1, -3
			// 2: 2
			// 3: 2, 1
			// 4: 2, 1, -1
			// Conclusion: the max slice ends at current index is either A[i] or maxSlice(A[i-1]) + A[i]
	// 2. Compare the max slice ending at each index and find the maxSliceSum

	int N = A.size();

	long maxEnding = (long)A[0];
	long maxSum = (long)A[0];

	for (int i = 1; i < N; i++) {
		maxEnding = max((long)A[i], maxEnding + A[i]);
		maxSum = max(maxEnding, maxSum);
	}

	return maxSum;
}