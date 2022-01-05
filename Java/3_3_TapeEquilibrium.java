class Solution {
    public int solution(int[] A) {
        // write your code in Java SE 8
    }

    public int brutalForce(int[] A) {
        int N = A.length;
        int firstHalf = A[0];
        int secondHalf = 0;
        for(int i = 1; i < N; i++) {
            secondHalf += A[i];
        }
        int minDiff = Integer.MAX_VALUE;

        for(int p = 1; p < N; p++) {
            int currDiff = firstHalf > secondHalf ? (firstHalf - secondHalf) : (secondHalf - firstHalf);
            minDiff = currDiff < minDiff ? currDiff : minDiff;

            firstHalf += A[p];
            secondHalf -= A[p];
        }
        return minDiff; 
    }
}