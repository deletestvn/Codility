// Lesson 4 - Counting Elements
// https://app.codility.com/programmers/lessons/4-counting_elements/max_counters/

/*
You are given N counters, initially set to 0, and you have two possible operations on them:

increase(X) − counter X is increased by 1,
max counter − all counters are set to the maximum value of any counter.
A non-empty array A of M integers is given. This array represents consecutive operations:

if A[K] = X, such that 1 ≤ X ≤ N, then operation K is increase(X),
if A[K] = N + 1 then operation K is max counter.
For example, given integer N = 5 and array A such that:

A[0] = 3
A[1] = 4
A[2] = 4
A[3] = 6
A[4] = 1
A[5] = 4
A[6] = 4
the values of the counters after each consecutive operation will be:

(0, 0, 1, 0, 0)
(0, 0, 1, 1, 0)
(0, 0, 1, 2, 0)
(2, 2, 2, 2, 2)
(3, 2, 2, 2, 2)
(3, 2, 2, 3, 2)
(3, 2, 2, 4, 2)
The goal is to calculate the value of every counter after all operations.

Write a function:

vector<int> solution(int N, vector<int> &A);

that, given an integer N and a non-empty array A consisting of M integers, 
returns a sequence of integers representing the values of the counters.

Result array should be returned as a vector of integers.

For example, given:

A[0] = 3
A[1] = 4
A[2] = 4
A[3] = 6
A[4] = 1
A[5] = 4
A[6] = 4
the function should return [3, 2, 2, 4, 2], as explained above.

Write an efficient algorithm for the following assumptions:

N and M are integers within the range [1..100,000];
each element of array A is an integer within the range [1..N + 1].
*/

#include <vector>

using namespace std;

vector<int> solution(int N, vector<int> &A) {
	int M = A.size();
	vector<int> values(N, 0);

	int maxCounter = 0; // This number keeps track of the maximum number in values
	int previousMax = 0; // This number keeps track of the previous max counter operation
	
	for (int i = 0; i < M; i++) {
		// If we meet a max counter operation, update previousMax
		if (A[i] == N + 1) {
			previousMax = maxCounter;
		}
		// If we meet a normal operation, check if the previous max operation has been proceed on this counter
		// If not, proceed and plus 1
		// else, plus 1
		else {
			values[A[i] - 1] = max(values[A[i] - 1], previousMax) + 1;
			// Update maxCounter
			if (values[A[i] - 1] > maxCounter) maxCounter = values[A[i] - 1];
		}
	}

	// Loop through each counter
	// If the max operation was not fulfilled 
	// (this counter has no operations after the latest max operation)
	// Then assign the value to be previousMax
	for (int j = 0; j < N; j++) {
		values[j] = max(values[j], previousMax);
	}

	return values;
}