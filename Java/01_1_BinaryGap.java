class Solution {
    public int solution(int N) {
        // write your code in Java SE 8
        int maxGap = 0;
        int currGap = 0;
        boolean isInGap = false;

        // Bitwise Operators Comparison
        // A & B == 1 (A == 1 && B == 1)
        // 10101 & 00001 = 00001
        while(N != 0) {
            if(isInGap) {
                if((N & 1) == 0) currGap += 1;
                else {
                    maxGap = currGap > maxGap ? currGap : maxGap;
                    currGap = 0;
                }
            }
            else {
                if((N & 1) == 1) isInGap = true;
            }

            // Bit Shift Operators
            // 5 << 3
            // 101 << 3 = 10100            
            N = N >> 1;
        }
        return maxGap;
    }

    private int brutalForce(int N) {
        String binaryN =  Integer.toBinaryString(N);
        int maxGap = 0;
        int currGap = 0;
        for(int i = 0; i < binaryN.length(); i++) {
            if(binaryN.charAt(i) == '1') {
                maxGap = currGap > maxGap ? currGap : maxGap;
                currGap = 0;
            }
            else if(binaryN.charAt(i) == '0') currGap += 1;
        }
        return maxGap;
    }
}