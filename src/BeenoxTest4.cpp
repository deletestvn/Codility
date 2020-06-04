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
