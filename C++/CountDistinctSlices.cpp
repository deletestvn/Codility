// Lesson 15 - Caterpillar Method
// https://app.codility.com/programmers/lessons/15-caterpillar_method/count_distinct_slices/

/*
An integer M and a non-empty array A consisting of N non-negative integers are given. 
All integers in array A are less than or equal to M.

A pair of integers (P, Q), such that 0 ≤ P ≤ Q < N, is called a slice of array A. 
The slice consists of the elements A[P], A[P + 1], ..., A[Q]. 
A distinct slice is a slice consisting of only unique numbers. 
That is, no individual number occurs more than once in the slice.

For example, consider integer M = 6 and array A such that:

A[0] = 3
A[1] = 4
A[2] = 5
A[3] = 5
A[4] = 2
There are exactly nine distinct slices: (0, 0), (0, 1), (0, 2), (1, 1), (1, 2), (2, 2), (3, 3), (3, 4) and (4, 4).

The goal is to calculate the number of distinct slices.

Write a function:

class Solution { public int solution(int M, int[] A); }

that, given an integer M and a non-empty array A consisting of N integers, returns the number of distinct slices.

If the number of distinct slices is greater than 1,000,000,000, the function should return 1,000,000,000.

For example, given integer M = 6 and array A such that:

A[0] = 3
A[1] = 4
A[2] = 5
A[3] = 5
A[4] = 2
the function should return 9, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
M is an integer within the range [0..100,000];
each element of array A is an integer within the range [0..M].
*/

#include <vector>

using namespace std;

int solution(int M, vector<int> &A) {
	int N = A.size();
	if (N == 1) return 1;

	// Generate a list which tracks if a number is already in current slice
	vector<bool> inSlice(M + 1, false);

	// Use caterpillar method to loop through each subarray
	int startIndex = 0;
	int endIndex = 0;
	long count = 0;
	while (startIndex < N && endIndex < N) {
		// Find the longest slice with current startIndex
		while (endIndex < N && !inSlice[A[endIndex]]) {
			inSlice[A[endIndex]] = true;
			count += (long)(endIndex - startIndex + 1); // Add all slices end at current endIndex
			endIndex += 1;
		}

		// Regenerate the startIndex
		// Restore not in slice value to be false
		for(int i = startIndex; i < endIndex; i++){
			inSlice[A[i]] = false;
			if (i == endIndex) startIndex = endIndex;
			else if (A[i] == A[endIndex]) {
				startIndex = i + 1;
				break;
			}
		}
	}

	if (count > 1000000000) count = 1000000000;
	return (int)count;
}