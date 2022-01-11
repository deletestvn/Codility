import java.util.*;

class Solution {
    public int solution(int[] A) {
        // write your code in Java SE 8
    }

    public int sortSolution(int[] A) {
        // write your code in Java SE 8
    	int N = A.length;
    	if(N < 3) return 0;

    	Arrays.sort(A);

    	for(int i = 0; i < N - 2; i++) {
    		if(A[i] <= 0) continue;

    		// Only need to compare the adjacent element because:
    		// For sorted list A B C D
    		// (A + C) > D => (B + C) > D
    		else if((long)A[i] + (long)A[i + 1] > (long)A[i + 2]) return 1; // using long to avoid max integer overflow cases
    	}

    	return 0;
    }
}



