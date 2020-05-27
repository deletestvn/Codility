// Lesson 3 - Time Complexity
// https://app.codility.com/programmers/lessons/3-time_complexity/tape_equilibrium/

/*
A non-empty array A consisting of N integers is given. 
Array A represents numbers on a tape.

Any integer P, such that 0 < P < N, splits this tape into two non-empty parts: 
A[0], A[1], ..., A[P − 1] and 
A[P], A[P + 1], ..., A[N − 1].

The difference between the two parts is the value of: 
|(A[0] + A[1] + ... + A[P − 1]) − (A[P] + A[P + 1] + ... + A[N − 1])|

In other words, it is the absolute difference between the sum of the first part 
and the sum of the second part.

For example, consider array A such that:

A[0] = 3
A[1] = 1
A[2] = 2
A[3] = 4
A[4] = 3
We can split this tape in four places:

P = 1, difference = |3 − 10| = 7
P = 2, difference = |4 − 9| = 5
P = 3, difference = |6 − 7| = 1
P = 4, difference = |10 − 3| = 7
Write a function:

class Solution { public int solution(int[] A); }

that, given a non-empty array A of N integers, 
returns the minimal difference that can be achieved.

For example, given:

A[0] = 3
A[1] = 1
A[2] = 2
A[3] = 4
A[4] = 3
the function should return 1, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [2..100,000];
each element of array A is an integer within the range [−1,000..1,000].
*/

#include <stdlib.h>

int solution(vector<int> &A) {
	long int N = A.size(); // N is an integer within the range [2...100,000]

    // Element of array is an integer within range [-1000...1000], log2(100,000,000) = 29
	long int minuend = 0; 
	long int subtrahend = 0;

	// Initialize subtrahend to be the sum of the array
	for (int i = 0; i < N; i++) {
		subtrahend += A[i];
	}

	// Since 0 < P < N
	// Initialize the minimum value to be |A[0] - sumOfRest|
	long int miniAbsDiff = abs(A[0] - (subtrahend - A[0]));
	long int currAbsDiff;

	// Since P is at least 1 and at most N-1, we need to loop through N-1 possibilities
	for (int j = 0; j < N-1; j++) {
		minuend += A[j];
		subtrahend -= A[j];
		currAbsDiff = abs(minuend - subtrahend);

		if (currAbsDiff < miniAbsDiff) {
			miniAbsDiff = currAbsDiff;
		}
	}

	return miniAbsDiff;
}