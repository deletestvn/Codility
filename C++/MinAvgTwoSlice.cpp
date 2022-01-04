// Lesson 5 - Prefix Sums
// https://app.codility.com/programmers/lessons/5-prefix_sums/min_avg_two_slice/

/*
A non-empty array A consisting of N integers is given. 
A pair of integers (P, Q), such that 0 ≤ P < Q < N, is called a slice of array A (notice that the slice contains at least two elements). 
The average of a slice (P, Q) is the sum of A[P] + A[P + 1] + ... + A[Q] divided by the length of the slice. 
To be precise, the average equals (A[P] + A[P + 1] + ... + A[Q]) / (Q − P + 1).

For example, array A such that:

A[0] = 4
A[1] = 2
A[2] = 2
A[3] = 5
A[4] = 1
A[5] = 5
A[6] = 8
contains the following example slices:

slice (1, 2), whose average is (2 + 2) / 2 = 2;
slice (3, 4), whose average is (5 + 1) / 2 = 3;
slice (1, 4), whose average is (2 + 2 + 5 + 1) / 4 = 2.5.
The goal is to find the starting position of a slice whose average is minimal.

Write a function:

class Solution { public int solution(int[] A); }

that, given a non-empty array A consisting of N integers, returns the starting position of the slice with the minimal average. 
If there is more than one slice with a minimal average, you should return the smallest starting position of such a slice.

For example, given array A such that:

A[0] = 4
A[1] = 2
A[2] = 2
A[3] = 5
A[4] = 1
A[5] = 5
A[6] = 8
the function should return 1, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [2..100,000];
each element of array A is an integer within the range [−10,000..10,000].
*/

#include <vector>

int solution(vector<int> &A) {
	// By default, there exists the minimum average slice with length 2 or 3
	// Assume that there exists a slice X with length greater than 3
	// Then we can divide X into two sub-slices x1 and x2
	// If x1/|x1| = x2/|x2|, then both x1 and x2 can be the the minAvgSlice
	// Else. one of the sublice has smaller average than X
	// Therefore, we just need to loop through all the slice with size 2 and 3

	int N = A.size();

	double currAvg;
	double miniAvg = ((double)A[0] + (double)A[1]) / 2.0;
	int miniIndex = 0;

	for (int i = 0; i < N - 2; i++) {
		// Compare slice with size 2
		currAvg = ((double)A[i] + (double)A[i + 1]) / 2.0;
		if (currAvg < miniAvg) {
			miniAvg = currAvg;
			miniIndex = i;
		}
		// Compare slice with size 3
		currAvg = ((double)A[i] + (double)A[i + 1] + (double)A[i + 2]) / 3.0;
		if (currAvg < miniAvg) {
			miniAvg = currAvg;
			miniIndex = i;
		}
	}

	// Compare slice(N-2, N-1)
	currAvg = ((double)A[N - 2] + (double)A[N - 1]) / 2.0;
	if (currAvg < miniAvg) miniIndex = N - 2;

	return miniIndex;
}