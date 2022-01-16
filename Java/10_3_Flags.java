import java.util.ArrayList;
class Solution {
    public int solution(int[] A) {
        // write your code in Java SE 8
        int N = A.length;
        if(N < 3) return 0;
        ArrayList<Integer> peaks = new ArrayList<Integer>();
        for(int i = 1; i < N - 1; i++) {
            if(A[i] > A[i - 1] && A[i] > A[i + 1]) peaks.add(i);
        }
        if(peaks.size() == 0) return 0;
        if(peaks.size() == 1) return 1;
        
        int maxGap = peaks.get(peaks.size() - 1) - peaks.get(0);
        int maxCount = (int) Math.sqrt(maxGap) + 1;

        while(maxCount >= 1) {
            int prevFlag = -maxCount;
            int currCount = 0;

            for(int i = 0; i < peaks.size(); i++) {
                if(peaks.get(i) - prevFlag >= maxCount) {
                    currCount++;
                    prevFlag = peaks.get(i);
                }
                if(currCount == maxCount) return currCount;
            }
            maxCount -= 1;
        }
        return maxCount;
    }
}