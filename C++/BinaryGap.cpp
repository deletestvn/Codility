// Lesson 1: Iterations
// https://app.codility.com/programmers/lessons/1-iterations/binary_gap/

/*
 A binary gap within a positive integer N is any maximal sequence of consecutive zeros that is surrounded by ones at both ends in the binary representation of N.

 For example, number 9 has binary representation 1001 and contains a binary gap of length 2. 
 The number 529 has binary representation 1000010001 and contains two binary gaps: one of length 4 and one of length 3. 
 The number 20 has binary representation 10100 and contains one binary gap of length 1. 
 The number 15 has binary representation 1111 and has no binary gaps. 
 The number 32 has binary representation 100000 and has no binary gaps.

Write a function:

int solution(int N);

that, given a positive integer N, returns the length of its longest binary gap. 
The function should return 0 if N doesn't contain a binary gap.

For example, given N = 1041 the function should return 5, because N has binary representation 10000010001 and so its longest binary gap is of length 5. 
Given N = 32 the function should return 0, because N has binary representation '100000' and thus no binary gaps.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..2,147,483,647].
*/

#include <iostream>
#include <cmath>

using namespace std;

int solution(int N) {
	int maximumGap = 0;
	int currentGap = 0;
	bool foundOne = false;

	int bitLength = floor(log2(N)) + 1;

	// Starting from the right, examine if the current bit is zero
	for (int i = 0; i < bitLength; i++) {
		// If the current bit is zero and we have already found a 1, the size of current gap plus 1
		if (foundOne && !((N & (1<<i)) >> i)) {
			currentGap++;
		}
		// If the current bit is not zero
		else if ((N & (1 << i)) >> i) {
			// If we have already found a 1
			if (foundOne) {
				// Compare the length of currentGap and maximumGap to
				if (currentGap > maximumGap) {
					// Reset maximumGap
					maximumGap = currentGap;
				}
				// Reset currentGap
				currentGap = 0;
			}
			// We just found a one
			foundOne = true;
		}
	}
	return maximumGap;
}