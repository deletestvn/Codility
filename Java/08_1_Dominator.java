import java.util.*;
class Solution {
    public int solution(int[] A) {
        // write your code in Java SE 8
        int N = A.length;
        if(N == 0) return -1;
        Stack<Integer> stack = new Stack<Integer>();

        for(int i = 0; i < N; i++) {
            if(stack.empty()) stack.push(A[i]);
            else if(A[i] == stack.peek()) stack.push(A[i]);
            else if(A[i] != stack.peek()) stack.pop();
        }
        // If dominator exists, the element in the stack should be it

        if(stack.empty()) return -1;
        int dominator = stack.peek();

        int count = 0;
        for(int i = 0; i < N; i++) {
            if(A[i] == dominator) {
                count++;
                if(count > N / 2) return i;
            }
        }

        return -1;
    }
}