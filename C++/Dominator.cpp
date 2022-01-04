// Lesson 8 - Leader
// https://app.codility.com/programmers/lessons/8-leader/dominator/

/*
An array A consisting of N integers is given. The dominator of array A is the value that occurs in more than half of the elements of A.

For example, consider array A such that

A[0] = 3    A[1] = 4    A[2] =  3
A[3] = 2    A[4] = 3    A[5] = -1
A[6] = 3    A[7] = 3
The dominator of A is 3 because it occurs in 5 out of 8 elements of A (namely in those with indices 0, 2, 4, 6 and 7) and 5 is more than a half of 8.

Write a function

class Solution { public int solution(int[] A); }

that, given an array A consisting of N integers, returns index of any element of array A in which the dominator of A occurs. 
The function should return −1 if array A does not have a dominator.

For example, given array A such that

A[0] = 3    A[1] = 4    A[2] =  3
A[3] = 2    A[4] = 3    A[5] = -1
A[6] = 3    A[7] = 3
the function may return 0, 2, 4, 6 or 7, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..100,000];
each element of array A is an integer within the range [−2,147,483,648..2,147,483,647].
*/

#include <vector>
#include <stack>
#include <stdlib.h>

using namespace std;

int solution(vector<int> &A) {
	int N = A.size();
	if (N == 0) return -1;

	stack<int> candidates;

	for (int i = 0; i < N; i++) {
		// If the stack is empty, add current value
		if (candidates.empty()) candidates.push(A[i]);
		// If the top value in stack is same as the current value, add current value
		else if (candidates.top() == A[i]) candidates.push(A[i]);
		// If the top value in stack is different from the current value, remove top of stack
		else if (candidates.top() != A[i]) candidates.pop();
	}

	// The only value left in the stack should be the dominator
	// If stack is empty, no leader exists
	if (candidates.empty()) return -1;
	
	int leader = candidates.top();
	int count = 0;
	vector<int> index;
	
	for (int j = 0; j < N; j++) {
		if (A[j] == leader) {
			count++;
			index.push_back(j);
		}
	}

	// Generate a randome index and return if count is greater than n/2
	int result = (2 * count > N) ? index[rand() % index.size()] : -1;
	return result;
}