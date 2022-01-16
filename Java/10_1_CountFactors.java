class Solution {
    public int solution(int N) {
        // write your code in Java SE 8
        int root = (int)Math.sqrt(N);
        int count = 0;
        for(int i = 1; i <= root; i++) {
            if(N % i == 0) count++;
        }
        return root * root == N ? 2 * count - 1 : 2 * count;
    }
}