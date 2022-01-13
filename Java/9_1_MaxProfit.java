class Solution {
    public int solution(int[] A) {
        int N = A.length;
        if(N <= 1) return 0;
        
        int maxProfit = 0;
        int maxToday = 0;

        for(int i = 1; i < N; i++) {
            int diff = A[i] - A[i - 1];
            maxToday = maxToday + diff > diff ? maxToday + diff : diff;
            maxProfit = maxToday > maxProfit ? maxToday : maxProfit;
        }
        return maxProfit;
    }
}
