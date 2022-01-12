import java.util.*;
class Solution {
    public int solution(int[] A) {
        // write your code in Java SE 8
        int N = A.length;
        if(N <= 1) return 0;

        long[] startPos = new long[N];
        long[] endPos = new long[N];

        for(int i = 0; i < N; i++) {
            startPos[i] = (long)i - (long)A[i];
            endPos[i] = (long)i + (long)A[i];
        }

        Arrays.sort(startPos);
        Arrays.sort(endPos);

        boolean[] endpoints = new boolean[2 * N];

        int i = 0, j = 0, k = 0;
        while(i < N & j < N) {
            if(startPos[i] <= endPos[j]) {
                endpoints[k] = true;
                i++;
            }
            else {
                endpoints[k] = false;
                j++;
            }
            k++;
        }

        int intersections = 0;
        int activeDisk = 0;
        for(k = 0; k < 2 * N; k++) {
            if(endpoints[k] == true) {
                intersections += activeDisk;
                activeDisk += 1;
            }
            else if(endpoints[k] == false) {
                activeDisk -= 1;
            }

            if(intersections > 1E7) return -1;
        }

        return intersections;
    }

    public int brutalForce(int[] A) {
        int N = A.length;
        if(N <= 1) return 0;
        int count = 0;
        for(int i = 0; i < N - 1; i++) {
            for(int j = i + 1; j < N; j++) {
                if((long)i + (long)A[i] >= (long)j - (long)A[j]) count++;
                if(count > 10000000) return -1;
            }
        }
        return count;
    }
}