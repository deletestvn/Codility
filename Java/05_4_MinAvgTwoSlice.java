class Solution {
    public int solution(int[] A) {
        // write your code in Java SE 8
        float avg_min = Integer.MAX_VALUE;
        int index_min = -1;        
        int N = A.length;
        
        for(int i = 0; i < N - 2; i++) {
            float avg_2 = (float) (A[i] + A[i + 1]) / 2;
            float avg_3 = (float) (A[i] + A[i + 1] + A[i + 2]) / 3;

            float curr_min = avg_2 < avg_3 ? avg_2 : avg_3;
            if(curr_min < avg_min) {
                avg_min = curr_min;
                index_min = i;
            }
        }
        float avg_2 = (float) (A[N - 2] + A[N - 1]) / 2;
        if(avg_2 < avg_min) {
            index_min = N - 2;
        }
        return index_min;
    }
}