// Code Test - Beenox

/*
Task 2

An array A consisting of N integers is given. A segment of this array is any pair of integers (P, Q) such that 0 <= P < Q < N.

Segment (P,Q) of array A is called monotonic if the sequence consisting of numbers A[P], A[P+1], ..., A[Q] is either strictly
increasing, strictly decreasing or constant.

For example, in array A such that
A[0] = 1, A[1] = 2, A[2] = 4; 
A[3] = 7, A[4] = 6, A[5] = 6; 
A[6] = 6, A[7] = 2, A[8] = 0.

the segment (0,2) is monotonic because the sequence A[0], A[1], A[2] (1,2,4) is strictly increasing
the segment (6,8) is monotonic because the sequence A[6], A[7], A[8] (6,2,0) is strictly decreasing
the segment (4,6) is monotonic because the sequence A[4], A[5], A[6] (6,6,6) is constant

the segment (5,7) is not monotonic because the sequence   A[5], A[6], A[7] (6,6,2) is neither strictly increasing or decreasing nor constant

Write a function:
int solution(vector<int> &A);

that given an array A consisting of N integers, returns the number of monotonic segments it contains

The function should return -1 if this number exceeds 1,000,000,000

For example, given array A such that
A[0] = 1, A[1] = 2, A[2] = 4;
A[3] = 7, A[4] = 6, A[5] = 6;
A[6] = 6, A[7] = 2, A[8] = 0.

the function should return 13 because there are 13 monotonic segments in A, namely:
- 4 decreasing: (3,4), (6,7), (6,8), (7,8)
- 6 increasing: (0,1), (0,2), (0,3), (1,2), (1,3), (2,3)
- 3 constant: (4,5), (4,6), (5,6)

Write an efficient algorithm for the following assumptions:
- N is an integer within the range [0...1,000,000];
- each element of array A is an integer within the range [-1,000,000...1,000,000].
*/

#include <vector>

using namespace std;

int solution(vector<int> &A) {
	int N = A.size();
	if (N < 2) return 0;

	long count = 0;
	int start = 0;
	int end = 1;

	// Increasing +1, constant 0, decreasing -1
	int type;

	// Initialize segment type
	if (A[end] - A[start] > 0) type = 1;
	else if (A[end] - A[start] < 0) type = -1;
	else type = 0;

	// Loop through the array
	while (end < N && start < N - 1) {
		int diff = A[end] - A[end - 1];
		int currType;

		// Check if the next element is still sufficient for current type
		if (diff > 0) currType = 1;
		else if (diff < 0) currType = -1;
		else currType = 0;

		if (currType == type) end += 1;
		else {
			count += ((end - start) * (end - start - 1) / 2);
			start = end - 1;
			type = currType;
		}
	}

	// The last degment was not added
	count += ((end - start) * (end - start - 1) / 2);

	if (count > 1000000000) count = -1;
	return count;
}
