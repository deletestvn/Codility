// Code Test - Beenox

/*
Task 3

In the army, each soldier has an assigned rank. 
A sodier of rank X has to report to (any) soldier of rank X + 1.
Many soldiers can report to the same superior.

Write a function:

int solution(vector<int> &ranks);

that, given an array ranks consisting of soldiers' ranks, 
returns the number of soldiers who can report to some superior.

Examples:
1. Given ranks = [3,4,3,0,2,2,3,0,0], your function should return 5, because:
- Three soldiers of rank 3 may report to a soldier of rank 4
- Two soldiers of rank 2 may report to any soldier of rank 3

2. Given ranks = [4,2,0], your function should return 0

3. Given ranks = [4,4,3,3,1,0], your function should return 3, because:
- A soldier of rank 0 can report to a soldier of rank 1
- Two soldiers of rank 3 can report to any soldier of rank 4

Write an efficient algorithm for the following assumptions
- N is an integer within the range [2...100,000];
- each element of array ranks is an integer within the range [0,1,000,000,000].
*/

#include <vector>
#include <map>

using namespace std;

int solution(vector<int> &ranks) {
	map<int, int> M; // (rank, number of this rank)

	// Loop through the ranks
	// When we encounter a rank k, add an element in map with key k
	for (int i : ranks) {
		M[i] += 1;
	}

	int count = 0;
	// Loop through the ranks (map)
	// If there exists at least one element with key = current rank + 1, add the number of current rank
	for (auto pair : M) {
		if (M.count(pair.first + 1) > 0) {
			count += pair.second;
		}
	}
	return count;
}