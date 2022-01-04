// Lesson 7 - Stacks and Queues
// https://app.codility.com/programmers/lessons/7-stacks_and_queues/brackets/

/*
A string S consisting of N characters is considered to be properly nested if any of the following conditions is true:

S is empty;
S has the form "(U)" or "[U]" or "{U}" where U is a properly nested string;
S has the form "VW" where V and W are properly nested strings.
For example, the string "{[()()]}" is properly nested but "([)()]" is not.

Write a function:

class Solution { public int solution(String S); }

that, given a string S consisting of N characters, returns 1 if S is properly nested and 0 otherwise.

For example, given S = "{[()()]}", the function should return 1 and given S = "([)()]", the function should return 0, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..200,000];
string S consists only of the following characters: "(", "{", "[", "]", "}" and/or ")".
*/

#include <string>
#include <stack>

using namespace std;

int solution(string &S) {
	int N = S.length();

	if (N == 0) return 1;

	stack<char> nest;
	char leftHalf;
	for (int i = 0; i < N; i++) {
		switch (S[i]) {
			// If the current character is a left-half, push it into stack
		case '(':
		case '[':
		case '{':
			nest.push(S[i]);
			break;
			// If the current character is a right-half, pop the top element of stack
			// If the left-half does not match the right-half, return false
		case ')':
			leftHalf = nest.top();
			nest.pop();
			if (leftHalf != '(') return 0;
			else break;
		case ']':
			leftHalf = nest.top();
			nest.pop();
			if (leftHalf != '[') return 0;
			else break;
		case '}':
			leftHalf = nest.top();
			nest.pop();
			if (leftHalf != '{') return 0;
			else break;
		}
	}

	// Case "((((("
	return (nest.empty() ? 1 : 0);
}
