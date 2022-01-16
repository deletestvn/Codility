class Solution {
    public int solution(int[] A) {
        // write your code in Java SE 8
        int N = A.length;
        int[] sumLeft = new int[N];
        int[] sumRight = new int[N];

        sumLeft[0] = 0;
        sumRight[N - 1] = 0;
        for(int i = 1; i < N; i++) {
            sumLeft[i] = Math.max(sumLeft[i - 1] + A[i], 0);
        }

        for(int i = N - 2; i >= 0; i--) {
            sumRight[i] = Math.max(sumRight[i + 1] + A[i], 0);
        }

        int maxDoubleSliceSum = 0;
        for(int i = 1; i < N - 1; i++) {
            maxDoubleSliceSum = Math.max(sumLeft[i - 1] + sumRight[i + 1], maxDoubleSliceSum);
        }
        return maxDoubleSliceSum;
    }
}