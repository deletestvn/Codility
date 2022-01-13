import java.util.*;
class Solution {
    public int solution(String S) {
        // write your code in Java SE 8
        Stack<Character> stack = new Stack<Character>();

        for(int i = 0; i < S.length(); i++) {
            char c = S.charAt(i);
            if(stack.empty() || c == '(' || c == '[' || c == '{') stack.push(c);
            else if(c == ')' && stack.peek() != '(') return 0;
            else if(c == ']' && stack.peek() != '[') return 0;
            else if(c == '}' && stack.peek() != '{') return 0;
            else stack.pop();
        }

        return stack.empty() ? 1 : 0; 
    }
}