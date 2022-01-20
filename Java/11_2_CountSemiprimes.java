// Time Complexity: O(N * log(log(N)) + M) 100% performance
class Solution {
    public int[] solution(int N, int[] P, int[] Q) {
        // write your code in Java SE 8
        int[] primes = findAllPrimes(N); // sieve of eratosthenes: O(N*log(log(N))) 
        boolean[] isSemiPrime = findAllSemiPrimes(N, primes); // O(N)
        int[] countSemiPrime = new int[N + 1];

        int count = 0;
        for(int i = 0; i <= N; i++) {
            if(isSemiPrime[i]) count++;
            countSemiPrime[i] = count;
        }
        //System.out.println(Arrays.toString(countSemiPrime));
        int M = P.length;
        int[] result = new int[M];
        for(int j = 0; j < M; j++) {
            int startCount = countSemiPrime[P[j]];
            int endCount = countSemiPrime[Q[j]];
            result[j] = endCount - startCount;
            if(isSemiPrime[P[j]]) result[j] += 1;
        }
        return result;
    }

    public int[] findAllPrimes(int N) {
        boolean[] isPrime = new boolean[N + 1];
        for(int i = 0; i <= N; i++) {
            isPrime[i] = true;
        }
        isPrime[0] = false;
        isPrime[1] = false;

        int count = N - 1;

        for(int i = 2; i * i <= N; i++) {
            if(isPrime[i]) {
                int k = i * i;
                while(k <= N) {
                    if(isPrime[k]){
                        isPrime[k] = false;
                        count -= 1;
                    } 
                    k += i;
                }
            }
        }
        int[] primes = new int[count];
        if(count <= 0) return primes;
        
        int j = 0;
        for(int i = 0; i <= N; i++) {
            if(isPrime[i]) {
                primes[j] = i;
                j++;
            }
        }
        return primes;
    }

    public boolean[] findAllSemiPrimes(int N, int[] primes) {
        boolean[] isSemiPrime = new boolean[N + 1];
        for(int i = 0; i <= N; i++) {
            isSemiPrime[i] = false;
        }

        for(int p = 0; p < primes.length; p++) {
            int q = p;
            while((long)primes[p] * (long)primes[q] <= (long)N && q < primes.length) {
                isSemiPrime[primes[p] * primes[q]] = true;
                q++;
            }
        }
        return isSemiPrime;
    }
}