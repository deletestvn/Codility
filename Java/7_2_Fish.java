import java.util.*;
class Solution {
    public int solution(int[] A, int[] B) {
        // write your code in Java SE 8
        int N = A.length;
        int count = 0; // fish swimming upstream which has eaten all possible downstream fish
        Stack<Integer> stack = new Stack<Integer>(); // fishing swimming downstream which has not been eaten

        for(int i = 0; i < N; i++) {
            if(B[i] == 1) stack.push(A[i]);
            else if(B[i] == 0 && stack.empty()) count += 1;
            else if(B[i] == 0 && !stack.empty()) {
                while(stack.peek() < A[i]) {
                    stack.pop();
                    if(stack.empty()) {
                        count += 1;
                        break;
                    }
                }
            }
        }
        return count + stack.size();
    }
}