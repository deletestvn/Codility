class Solution {
    public int solution(int[] A) {
        // write your code in Java SE 8
        int N = A.length;
        boolean[] occurs = new boolean[N];

        for(int i = 0; i < N; i++)
            occurs[i] = false;

        for(int i = 0; i < N; i++) {
            int currNum = A[i];
            if(currNum > N) return 0;
            else if(occurs[currNum - 1] == false) occurs[currNum - 1] = true;
            else return 0; 
        }

        return 1;
    }
}