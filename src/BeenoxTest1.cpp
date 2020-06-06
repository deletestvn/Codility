// Code Test - Beenox

/*
Task 1

We consider a number to be lovely if it contains fewer than three instances of any distinct digit
(In decimal representation)

- Example of lovely nnumbers: 0, 100, 1232 and 9922
- Example of numbers that are not lovely: 1000 (contains three copies of digit '0'), 33533 (contains four copies of digit 3)

Write a function solution that, given integers A and B, returns the number of lovely integers in the range [A...B]

Examples:
1. Given A = 0, B = 0, your function should return 1, because 0 is lovely
2. Given A = 1, B = 111, your function should return 110, because the only integer in the range [1...111] that is not lovely is 111
3. Given A = 100000, B = 100000, your function should return 0, because 100000 is not lovely

Assume that:
- A and B are integers within the range [0...100,000];
- A <= B
*/

#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int solution(int A, int B) {
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
