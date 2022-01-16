class Solution {
    public int[] solution(String S, int[] P, int[] Q) {
        // write your code in Java SE 8
        return prefixSumByIndex(S, P, Q);
    }

    public int[] prefixSumByIndex(String S, int[] P, int[] Q) {
        int N = S.length();

        // Track the index of the most recent occurence of nucleotide type
        int previousIndexA = -1;
        int previousIndexC = -1;
        int previousIndexG = -1;
        int previousIndexT = -1;

        int[] A = new int[N];
        int[] C = new int[N];
        int[] G = new int[N];
        int[] T = new int[N];

        for(int i = 0; i < N; i++) {
            A[i] = -1;
            C[i] = -1;
            G[i] = -1;
            T[i] = -1;
        }

        for(int i = 0; i < N; i++) {
            switch (S.charAt(i)) {
                case 'A':
                    previousIndexA = i;
                    break;
                case 'C':
                    previousIndexC = i;
                    break;
                case 'G':
                    previousIndexG = i;
                    break;
                case 'T':
                    previousIndexT = i;
                    break;
            }

            A[i] = previousIndexA;
            C[i] = previousIndexC;
            G[i] = previousIndexG;
            T[i] = previousIndexT;
        }

        // DNA sequence 'CAGCCTA'
        // A = [-1, 1, 1, 1, 1, 1, 6]
        // C = [0, 0, 0, 3, 4, 4, 4]
        // G = [-1, -1, 2, 2, 2, 2, 2]
        // T = [-1, -1, -1, -1, -1, 5, 5]

        int M = P.length;

        int[] impactFactors = new int[M];

        for(int j = 0; j < M; j++) {
            int startIndex = P[j];
            int endIndex = Q[j];

            // If a specific nucleotide type occurs between start and end index, impact factor found
            if(A[endIndex] >= startIndex) impactFactors[j] = 1;
            else if(C[endIndex] >= startIndex) impactFactors[j] = 2;
            else if(G[endIndex] >= startIndex) impactFactors[j] = 3;
            else if(T[endIndex] >= startIndex) impactFactors[j] = 4;
        }

        return impactFactors;
    }

    public int[] prefixSumByOccurences(String S, int[] P, int[] Q) {
        int N = S.length();

        int countA = 0;
        int countC = 0;
        int countG = 0;
        int countT = 0;

        int[] A = new int[N + 1];
        int[] C = new int[N + 1];
        int[] G = new int[N + 1];
        int[] T = new int[N + 1];

        for(int i = 0; i <= N; i++) {
            A[i] = 0;
            C[i] = 0;
            G[i] = 0;
            T[i] = 0;
        }

        for(int i = 1; i <= N; i++) {
            switch (S.charAt(i - 1)) {
                case 'A':
                    countA++;
                    break;
                case 'C':
                    countC++;
                    break;
                case 'G':
                    countG++;
                    break;
                case 'T':
                    countT++;
                    break;
            }

            A[i] = countA;
            C[i] = countC;
            G[i] = countG;
            T[i] = countT;
        }

        int M = P.length;

        int[] impactFactors = new int[M];

        for(int j = 0; j < M; j++) {
            int startIndex = P[j];
            int endIndex = Q[j] + 1;

            if(A[endIndex] > A[startIndex]) impactFactors[j] = 1;
            else if(C[endIndex] > C[startIndex]) impactFactors[j] = 2;
            else if(G[endIndex] > G[startIndex]) impactFactors[j] = 3;
            else if(T[endIndex] > T[startIndex]) impactFactors[j] = 4;
        }

        return impactFactors;
    }
}