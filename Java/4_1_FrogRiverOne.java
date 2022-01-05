
class Solution {
    public int solution(int X, int[] A) {
        // write your code in Java SE 8
        int N = A.length;
        boolean[] track = new boolean[X];
        for(int i = 0; i < X; i++) {
            track[i] = false;
        }

        int currPos;
        for(int time = 0; time < N; time++) {
            currPos = A[time];
            if(!track[currPos - 1]) {
                track[currPos - 1] = true;
                X--;
            }

            if(X == 0) return time;
        }
        return -1;
    }

    public int brutalForce(int X, int[] A) {
        int N = A.length;
        int[] positions = new int[X];
        int sum = (1 + X) * X / 2;
        for(int i = 0; i < X; i++)
            positions[i] = 0;
        for(int i = 0; i < N; i++) {
            int currPos = A[i];
            if(positions[currPos - 1] != 0)
                continue;
            else {
                positions[currPos - 1] += 1;
                sum -= currPos;
            }

            if(sum == 0) return i;
        }
        return -1;
    }
}
