class Solution {
    public int[] solution(int[] A, int K) {
        // write your code in Java SE 8
        int length = A.length;
        int[] result = new int[length];
        for(int i = 0; i < length; i++) {
            int pos = (i + K) % length;
            result[pos] = A[i];
        }
        return result;
    }

    public int[] brutalForce(int[] A, int K) {
        int length = A.length;
        if(length == 0 || 1) return A;
        for(int i = 0; i < K; i++) {
            int prevNum = A[length - 1];
            for(int j = 0; j < length; j++) {
                int temp = A[j];
                A[j] = prevNum;
                prevNum = temp;
            }
        }
        return A;
    }
}
