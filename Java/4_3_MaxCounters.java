class Solution {
    public int[] solution(int N, int[] A) {
        // write your code in Java SE 8
        int[] counters = new int[N];
        int prevMaxCounter = 0; // Used to keep track of the max operation that is not applied to counters
        int currMaxCounter = 0; // Used to keep track of the current max counter in the array (if a max operation is not executed, this will not be used)
        
        // Initialize the array
        for(int i = 0; i < N; i++)
            counters[i] = 0;

        int M = A.length;
        for(int i = 0; i < M; i++) {
            int operation = A[i];
            // When a max operation occurs, update the max operation tracker
            if(operation == N + 1) {prevMaxCounter = currMaxCounter;}

            // Otherwise, update the current counter
            else {
                int index = operation - 1;

                // If a max operation is not applied to the current counter, update it with the max operation
                // Else update it with the addOne operation
                counters[index] = prevMaxCounter > counters[index] ? prevMaxCounter + 1 : counters[index] + 1;
                
                // Update the max counter if necessary
                if(counters[index] > currMaxCounter) 
                    currMaxCounter = counters[operation - 1];
            }
        }

        // Update all counters that have not been applied an operation after the previous max operation
        for(int i = 0; i < N; i++)
            if(prevMaxCounter > counters[i]) counters[i] = prevMaxCounter;

        return counters;
    }

    public int[] brutalForce(int N, int[] A) {
        int[] counters = new int[N];
        int maxCounter = 0;
        for(int i = 0; i < N; i++)
            counters[i] = 0;

        int M = A.length;
        for(int i = 0; i < M; i++) {
            int operation = A[i];
            if(operation == N + 1) {
                for(int j = 0; j < N; j++)
                    counters[j] = maxCounter;
            }
            else {
                counters[operation - 1] += 1;
                maxCounter = counters[operation - 1] > maxCounter ? counters[operation - 1] : maxCounter;
            }
        }
        return counters;
    }
}