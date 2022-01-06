class Solution {
    public int solution(int[] A) {
        // write your code in Java SE 8
        return prefixSumApproach(A);
    }

    public int prefixSumApproach(int[] A) {
        // write your code in Java SE 8
        int N = A.length;
        int pairCounts = 0;
        int eastCounts = 0;

        for(int i = 0; i < N; i++) {
            if(A[i] == 0) eastCounts++;
            else {
                pairCounts += eastCounts;
                if(pairCounts > 1000000000) return -1;
            }
        }
        return pairCounts;
    }

    public int brutalForce(int[] A) {
        // write your code in Java SE 8
        int N = A.length;
        int pairCounts = 0;
        for(int i = 0; i < N; i++) {
            if(A[i] == 1) continue;
            for(int j = i + 1; j < N; j++) {
                if(A[j] == 1) pairCounts++;
                if(pairCounts > 1000000000) return -1;
            }
        }
        return pairCounts;
    }
}
