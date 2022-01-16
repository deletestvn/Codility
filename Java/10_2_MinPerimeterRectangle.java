class Solution {
    public int solution(int N) {
        // write your code in Java SE 8
        int root = (int)Math.sqrt(N);
        for(int i = root; i >= 1; i--) {
            if(N % i == 0) {
                root = i;
                break;
            }
        }
        return 2 * (root + N / root);
    }
}