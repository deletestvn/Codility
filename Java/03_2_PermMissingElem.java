class Solution {
    public int solution(int[] A) {
        // write your code in Java SE 8
        long N = A.length;
        // N is an integer within [0, 100,000]
        // sum is an integer within [0, 5,000,150,001]
        // maximum int is 2,147,483,647
        // therefore, we need to use long here
        long sum = (N + 2) * (N + 1) / 2;
        long missingElem = sum;
        for(int i = 0; i < N; i++) {
            missingElem -= A[i];
        }
        return (int)missingElem;
    }
}