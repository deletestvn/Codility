import java.util.*;
class Solution {
    public int solution(int[] A) {
        // write your code in Java SE 8
        int N = A.length;
        if(N == 3) return A[0] * A[1] * A[2];
        
        int currMax = Integer.MIN_VALUE + 2;
        int prevMax = Integer.MIN_VALUE + 1;
        int thirdMax = Integer.MIN_VALUE;

        int currMin = Integer.MAX_VALUE - 1;
        int prevMin = Integer.MAX_VALUE;

        for(int i = 0; i < N; i++) {
            int num = A[i];
            if(num > currMax) {
                thirdMax = prevMax;
                prevMax = currMax;
                currMax = num;
            }
            else if(num > prevMax) {
                thirdMax = prevMax;
                prevMax = num;
            }
            else if(num > thirdMax) thirdMax = num;

            if(num < currMin) {
                prevMin = currMin;
                currMin = num;
            }
            else if(num < prevMin) prevMin = num;
        }
        

        int productOne = currMax * prevMax * thirdMax;
        int productTwo = currMax * currMin * prevMin;

        return productOne > productTwo ? productOne : productTwo;
    }

    public int sortSolution(int[] A) {
        int N = A.length;
        if(N == 3) return A[0] * A[1] * A[2];

        Arrays.sort(A);

        int candidateProductOne = A[0] * A[1] * A[N - 1];
        int candidateProductTwo = A[N - 3] * A[N - 2] * A[N - 1];

        return candidateProductOne > candidateProductTwo ? candidateProductOne : candidateProductTwo;
    }
}