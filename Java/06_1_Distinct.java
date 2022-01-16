import java.util.*; // Enable Arrays.sort()

class Solution {
    // O(N+2000001)
    public int solution(int[] A) {
        // write your code in Java SE 8
        int N = A.length;
        if(N <= 1) return N;

        boolean[] numbers = new boolean[2000001]; // numbers are within [-1000000, 1000000]
        for(int i = 0; i < 2000001; i++) {
            numbers[i] = false;
        }

        int count = 0;
        for(int j = 0; j < N; j++) {
            int number = A[j];
            if(numbers[number + 1000000] == false) {
                count++;
                numbers[number + 1000000] = true;
            }
        }

        return count;
    }

    // O(Nlog(N))
    // In this question max N is 100000, so max Nlog(N) is 5N = 500000
    // 500000 < 2000001
    // Sort solution is more efficient due to the input
    public int sortSolution(int[] A) {
        int N = A.length;
        if(N <= 1) return N;

        int count = 1;
        Arrays.sort(A);

        for(int i = 1; i < N; i++) {
            if(A[i] != A[i - 1]) count++;
        }

        return count;
    }
}