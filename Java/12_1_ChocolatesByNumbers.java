class Solution {
    // Time complexity: O(log(M+N))
    public int solution(int N, int M) {
        return N / findGreatestCommonDivisor(N, M);
    }

    public int findGreatestCommonDivisor(int N, int M) {
        if(N % M == 0) return M;
        else return findGreatestCommonDivisor(M, N % M);
    }

    // Time complexity: O(M+N)
    public int brutalForce(int N, int M) {
        boolean[] chocolates = new boolean[N];
        int curr = 0;
        int count = 0;
        while(!chocolates[curr]) {
            chocolates[curr] = true;
            curr = (curr + M) % N;
            count++;
        } 
        return count;
    }
}
