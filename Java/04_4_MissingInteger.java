class Solution {
    public int solution(int[] A) {
        // write your code in Java SE 8
        int N = A.length;
        boolean[] tracker = new boolean[N];
        
        for(int i = 0; i < N; i++)
            tracker[i] = false;

        for(int j = 0; j < N; j++)
            if(A[j] >= 1 && A[j] <= N) tracker[A[j] - 1] = true;
            
        
        for(int i = 0; i < N; i++)
            if(tracker[i] == false) return (i + 1);

        return N + 1;
    }

    public int brutalForce(int[] A) {
        // write your code in Java SE 8
        for(int i = 1; i <= 100000; i++) {
            boolean integerFound = false;
            for(int j = 0; j < A.length; j++) {
                if(A[j] == i) {
                    integerFound = true;
                    break;
                }
            }
            if(integerFound == false) return i;
            integerFound = false;
        }
        return 100001;
    }

}