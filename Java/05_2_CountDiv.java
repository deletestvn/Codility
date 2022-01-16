class Solution {
    public int solution(int A, int B, int K) {
        // write your code in Java SE 8
        int prefix = A;

        // find the first sufficient value
        while(prefix <= B) {
            if(prefix % K == 0) break;
            else prefix++;
        }

        if(prefix == (B + 1)) return 0; // No valid value found
        else return((B - prefix) / K) + 1;
    }

    public int brutalForce(int A, int B, int K) {
        // write your code in Java SE 8
        int count = 0;
        for(int i = A; i <= B; i++) {
            if(i % K == 0) count++;
        }
        return count;
    }
}