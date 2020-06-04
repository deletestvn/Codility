
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int solution(int A, int B) {
	// write your code in C++14 (g++ 6.2.0)
	vector<int> digits;
	int count = 0;
	for (int i = A; i <= B; i++) {
		// When current number has only two digits, it is lovely
		if (i < 100) {
			count++;
			continue;
		}
		// Loop through digits and assign into vector
		int number = i;
		while (number > 0) {
			int digit = number % 10;
			digits.push_back(digit);
			number /= 10;
		}
		// Sort the digits
		sort(digits.begin(), digits.end());
		// Loop through digits to see if a number occors more than 2 times
		bool isLovely = true;
		for (int j = 0; j < (int)digits.size() - 2; j++) {
			if (digits[j] == digits[j + 1] && digits[j + 1] == digits[j + 2]) {
				isLovely = false;
				break;
			}
		}
		if (isLovely) count++;

		digits.clear();
	}
	return count;
}
