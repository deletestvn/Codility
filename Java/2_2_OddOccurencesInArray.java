class Solution {
    public int solution(int[] A) {
        // write your code in Java SE 8
        // Bitwise XOR (^) only 1 ^ 0 == 1
        int oddOccurence = 0;
        for(int i = 0; i < A.length; i++) {
            oddOccurence ^= A[i];
        }
        return oddOccurence;
    }

    public int brutalForce(int[] A) {
        boolean hasPair = False;
        for(int i = 0; i < A.length; i++) {
            for(int j = 0; j < A.length; j++) {
                if(i != j && A[i] = A[j])
            }
        }
    }
}