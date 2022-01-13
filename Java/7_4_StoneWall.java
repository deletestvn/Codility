import java.util.*;
class Solution {
    public int solution(int[] H) {
        // write your code in Java SE 8
        int N = H.length;
        Stack<Integer> stack = new Stack<Integer>();

        int count = 0;
        int i = 0;
        while(i < N) {
            if(stack.empty() || stack.peek() < H[i]) stack.push(H[i]);
            else if(stack.peek() > H[i]) {
                stack.pop();
                count += 1;
                continue;
            }
            i++;
        }
        return stack.size() + count;
    }
}