import java.util.*;
class Solution {
    public int[] solution(int[] A) {
        // write your code in Java SE 8
        int N = A.length;
        HashMap<Integer, Integer> numCounts = new HashMap<Integer, Integer>();
        for(int i = 0; i < N; i++) {
            if(numCounts.containsKey(A[i])) {
                int count = numCounts.get(A[i]);
                numCounts.put(A[i], count + 1);
            }
            else numCounts.put(A[i], 1);
        }

        int[] results = new int[N];
        
        for(int i = 0; i < N; i++) {
            int num = A[i];
            int divisors = 0;
            for(int j = 1; j * j <= num; j++) {
                if(num % j == 0) {
                    if(numCounts.containsKey(j)) divisors += numCounts.get(j);
                    if(num / j != j && numCounts.containsKey(num / j)) {
                        divisors += numCounts.get(num / j);
                    }
                }
            }
            results[i] = N - divisors;
        }

        return results;
    }

    public int[] brutalForce(int[] A) {
        // write your code in Java SE 8
        int N = A.length;
        int[] results = new int[N];
        for(int i = 0; i < N; i++) {
            results[i] = 0;
        }

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(A[i] % A[j] != 0) results[i]++;
            }
        }

        return results;
    }
}
