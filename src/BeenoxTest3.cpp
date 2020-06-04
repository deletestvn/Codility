#include <vector>
#include <map>

using namespace std;

int solution(vector<int> &ranks) {
	map<int, int> M;
	for (int i : ranks) {
		M[i] += 1;
	}

	int count = 0;
	for (auto pair : M) {
		if (M.count(pair.first + 1) > 0) {
			count += pair.second;
		}
	}
	return count;
}