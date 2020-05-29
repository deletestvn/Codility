// Lesson 7 - Stacks and Queues
// https://app.codility.com/programmers/lessons/7-stacks_and_queues/nesting/

/*
A string S consisting of N characters is called properly nested if:

S is empty;
S has the form "(U)" where U is a properly nested string;
S has the form "VW" where V and W are properly nested strings.
For example, string "(()(())())" is properly nested but string "())" isn't.

Write a function:

class Solution { public int solution(String S); }

that, given a string S consisting of N characters, returns 1 if string S is properly nested and 0 otherwise.

For example, given S = "(()(())())", the function should return 1 and given S = "())", the function should return 0, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..1,000,000];
string S consists only of the characters "(" and/or ")".
*/

#include <string>
#include <stack>

using namespace std;

int solution(string &S) {
	int N = S.length();
	if (N == 0) return 1;
	if (N % 2 != 0) return 0;

	stack<char> nest;

	for (int i = 0; i < N; i++) {
		switch (S[i]) {
			case '(':
				nest.push(S[i]);
				break;
			case ')':
				if (nest.empty()) return 0;
				else nest.pop();
				break;
		}
	}

	return (nest.empty() ? 1 : 0);
}