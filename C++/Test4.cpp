// Code Test

/*
Task 4

You want to spend your next vacation in a foreign country. In the summer you are free for N consecutive days.
You have consulted Travel Agency and learned that they are offering a trip to some interesting location in the country every day.

For simplicity, each location is identified by a number from 0 to N-1. 
Trips are described in a non-empty array A:
for each K (0<=K<=N), A[K] is the identifier of a location which is the destination of a trip offered on day K.

Travel Agency does not have to offer trips to all locations, and can offer more than one trip to same locations.

You want to go on a trip every day during your vacation. Moreover, you want to visit all locations offered by Travel Agency.
You may visit the same location more than once, but you want to minimize duplicate visits.
The goal is to find the shortest vacation (a range of consecutive days) that will allow you to visit all the locations offered by Travel Agency.

For example, consider array A such that:

A[0] = 7  A[1] = 3  A[2] = 7  A[3] = 3
A[4] = 1  A[5] = 3  A[6] = 4  A[7] = 1

Travel Agency offers trips to four different locations (1,3,4,7).
The shortest vacation starting on day 0 that allows you visit all these locations ends on day 6.
However, a shorter vacation of five days (starting on day 2 and ending on day 6) also permits you to visit all locations.
On every vacation shorter than five days, you will have to miss at least one location.

Write a function:

int solution(vector<int> &A);

that, given a non empty array A consisting of N integers, returns the length of the shortest vacation that allows you to visit all the offered locations.

For example, given array A shown above, the function should return 5

Given A = [2,1,1,3,2,1,1,3], the function should return 3. One of the shortest vacations that visits all the places starts on day 3 and lasts for 3 days

Given A = [7,5,2,7,2,7,4,7], the function should return 6. The shortest vacation that visits all the places starts on day 1 and lasts for 6 days.

Write an efficient algorithm for the following assumptions:
- N is an integer within the range [1...1,000,000];
- each element of array A is an integer within the range [0...N-1].
*/

#include <vector>
#include <utility>

using namespace std;

int solution(vector<int> &A) {
	int N = A.size();
	if (N == 1) return 1;

	int locationNum = 0;
	vector<pair<bool, int>> locations(N, make_pair(false, 0));

	// Generate the number of distinct locations
	for (int i = 0; i < N; i++) {
		if (locations[A[i]].first == false) {
			locationNum++;
			locations[A[i]].first = true;
		}
	}

	int start = 0, end = -1; // Start date and end date in current trip
	int result = -1;
	int visited = 0; // Distinct locations visited in current trip
	while (true) {
		// If we have not visited all available locations
		if (visited < locationNum) {
			end += 1;
			if (end == N) break; // When we cannot visit all locations with current trip
			if (locations[A[end]].second == 0) visited += 1; // If we visit a location that has not been visited
			locations[A[end]].second += 1;
			continue;
		}

		// If we have visited all available locations
		// 1. If we have more than one current start location, start date increase
		while (locations[A[start]].second > 1) {
			locations[A[start]].second -= 1;
			start += 1;
		}

		// 2. Compare the current trip with the best trip
		if (result == -1 || (end - start) < result)	result = end - start + 1;

		// 3, Reset trip
		locations[A[start]].second--;
		start++;
		visited--;
	}
	return result;
}
