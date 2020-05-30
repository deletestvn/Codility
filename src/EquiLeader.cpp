// Lesson 8 - Leader
// https://app.codility.com/programmers/lessons/8-leader/equi_leader/

/*
A non-empty array A consisting of N integers is given.

The leader of this array is the value that occurs in more than half of the elements of A.

An equi leader is an index S such that 0 ≤ S < N − 1 and two sequences:
A[0], A[1], ..., A[S] and A[S + 1], A[S + 2], ..., A[N − 1] have leaders of the same value.

For example, given array A such that:

A[0] = 4
A[1] = 3
A[2] = 4
A[3] = 4
A[4] = 4
A[5] = 2
we can find two equi leaders:

0, because sequences: (4) and (3, 4, 4, 4, 2) have the same leader, whose value is 4.
2, because sequences: (4, 3, 4) and (4, 4, 2) have the same leader, whose value is 4.
The goal is to count the number of equi leaders.

Write a function:

class Solution { public int solution(int[] A); }

that, given a non-empty array A consisting of N integers, returns the number of equi leaders.

For example, given:

A[0] = 4
A[1] = 3
A[2] = 4
A[3] = 4
A[4] = 4
A[5] = 2
the function should return 2, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [−1,000,000,000..1,000,000,000].
*/

#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> &A) {
	int N = A.size();

	// First, find the leader
	stack<int> candidates;

	for (int i = 0; i < N; i++) {	
		if (candidates.empty()) candidates.push(A[i]);
		else if (candidates.top() == A[i]) candidates.push(A[i]);
		else if (candidates.top() != A[i]) candidates.pop();
	}

	if (candidates.empty()) return 0; // No leader exists

	int leader = candidates.top();
	int count = 0;
	for (int j = 0; j < N; j++) {
		if (A[j] == leader) count++;
	}

	if (count * 2 <= N) return 0; // No leader exists

	// Now, we know that there exists a leader
	// Find the EquiLeader index
	int leftCount = 0;
	int	rightCount = count;
	int result = 0;

	for (int k = 0; k < N; k++) {
		if (A[k] == leader) {
			leftCount += 1;
			rightCount -= 1;
		}
		if (2 * leftCount > (k + 1) && 2 * rightCount > (N - k - 1)) {
			result += 1;
		}
	}
	return result;
}