import java.util.ArrayList;
class Solution {
    public int solution(int[] A) {
        // write your code in Java SE 8
        int N = A.length;
        if(N < 3) return 0;
        ArrayList<Integer> factors = new ArrayList<Integer>();
        boolean[] peaks = new boolean[N];
        
        peaks[0] = false;
        peaks[N - 1] = false;
        for(int i = 1; i < N - 1; i++) {
            peaks[i] = (A[i] > A[i - 1] && A[i] > A[i + 1]) ? true : false;
            if(N % (i + 1) == 0) factors.add(i + 1);
        }
        factors.add(N);

        for(int j = 0; j < factors.size(); j++) {
            int blockSize = factors.get(j);
            boolean hasPeak = false;
            for(int k = 0; k < N; k++) {
                hasPeak |= peaks[k];
                if((k + 1) % blockSize == 0) {
                    if(!hasPeak) break;
                    else if(k == N - 1) continue;
                    else hasPeak = false;
                }
            }
            if(hasPeak) return (N / blockSize);
        }

        return 0;
    }
}