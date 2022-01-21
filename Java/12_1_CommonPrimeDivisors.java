class Solution {
    public int solution(int[] A, int[] B) {
        int count = 0;
        for(int i = 0; i < A.length; i++) {
            if(hasCommonPrimeDivisors(A[i], B[i])) count++;
        }
        return count;
    }

    public int findGreatestCommonDivisor(int N, int M) {
        if(N % M == 0) return M;
        else return findGreatestCommonDivisor(M, N % M);
    }

    public boolean hasCommonPrimeDivisors(int N, int M) {
        int gcd = findGreatestCommonDivisor(N, M);
        while(N != 1) {
            int gcdN = findGreatestCommonDivisor(N, gcd);
            if(gcdN == 1) break;
            N /= gcdN;
        }
        if(N != 1) return false;

        while(M != 1) {
            int gcdM = findGreatestCommonDivisor(M, gcd);
            if(gcdM == 1) break;
            M /= gcdM;
        }
        if(M != 1) return false;
        
        return true;        
    }

    public boolean brutalForcehasCommonPrimeDivisors(int N, int M) {
        if(N == 1 && M == 1) return true;
        else if(N == 1 || M == 1) return false;    
        
        int i = 2;
        while(i * i <= Math.max(N, M)) {
            if(N % i == 0 && M % i == 0) {
                while(N % i == 0) {
                    N /= i;
                }
                while(M % i == 0) {
                    M /= i;
                }
                i++;
            }
            else if(N % i == 0 && M % i != 0) return false;
            else if(N % i != 0 && M % i == 0) return false;
            else i++;
        }
        if(N == M) return true;
        else return false;
    }
}
