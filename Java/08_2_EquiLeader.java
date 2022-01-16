import java.util.*;
class Solution {
    public int solution(int[] A) {
        int N = A.length;
        Stack<Integer> stack = new Stack<Integer>();

        for(int i = 0; i < N; i++) {
            if(stack.empty()) stack.push(A[i]);
            else if(A[i] == stack.peek()) stack.push(A[i]);
            else if(A[i] != stack.peek()) stack.pop();
        }

        if(stack.empty()) return 0;
        int dominator = stack.peek();

        int domCount = 0;
        for(int i = 0; i < N; i++) {
            if(A[i] == dominator) domCount += 1;
        }

        if(domCount <= N / 2) return 0;

        int equiCount = 0;
        int leftCount = 0, rightCount = domCount;
        for(int i = 0; i < N - 1; i++) {
            if(A[i] == dominator) {
                leftCount += 1;
                rightCount -= 1;
            }

            if(leftCount > (i + 1) / 2 && rightCount > (N - i - 1) / 2) equiCount += 1;
        }
        return equiCount;
    }
}
