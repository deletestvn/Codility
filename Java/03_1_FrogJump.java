class Solution {
    public int solution(int X, int Y, int D) {
        // write your code in Java SE 8
        int gap = Y - X;
        return gap % D == 0 ? gap / D : (gap / D) + 1;
    }
}