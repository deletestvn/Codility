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
