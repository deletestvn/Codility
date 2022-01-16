class Solution {
    public int solution(int[] A) {
        // write your code in Java SE 8
        int N = A.length;
        long posSum = (long)Integer.MIN_VALUE;
        long maxSum = (long)Integer.MIN_VALUE;

        for(int i = 0; i < N; i++) {
            posSum = posSum + A[i] > A[i] ? posSum + A[i] : A[i];
            maxSum = posSum > maxSum ? posSum : maxSum;
        }

        return (int)maxSum;
    }
}