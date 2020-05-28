// Lesson 4 - Counting Elements
// https://app.codility.com/programmers/lessons/4-counting_elements/missing_integer/

/*
Write a function:

int solution(vector<int> &A);

that, given an array A of N integers,
returns the smallest positive integer (greater than 0) that does not occur in A.

For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.

Given A = [1, 2, 3], the function should return 4.

Given A = [−1, −3], the function should return 1.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [−1,000,000..1,000,000].
*/

#include <vector>

int solution(vector<int> &A) {

	// Since elements in A are within the range [−1,000,000..1,000,000], 
	// the maximum integer is 1000000
	vector<bool> tracker(1000000, false);
	int N = A.size();

	for (int i = 0; i < N; i++) {
		if (1 <= A[i] && A[i] <= 1000000) tracker[A[i] - 1] = true;
	}

	for (int j = 0; j < 1000000; j++) {
		if (tracker[j] == false) return (j + 1);
	}

	return 1000001;
}