
class Solution {
    public int solution(int n) {
        int answer = 0;
        int[] memori = new int[60001];
        
        memori[1] = 1;
        memori[2] = 2;
        for (int i = 3; i <= n; i++){
            memori[i] = memori[i - 1] + memori[i - 2];
            memori[i] %= 1000000007;
        }
        return memori[n];
    }
}