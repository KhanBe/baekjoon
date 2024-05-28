import java.util.HashMap;

class Solution {
    public int solution(String[][] clothes) {
        int answer = 1;
        
        HashMap<String,Integer> hm = new HashMap<>();
        
        for(String[] key : clothes){
            hm.put(key[1], hm.getOrDefault(key[1], 1) + 1);
        }
        
        for(String key : hm.keySet()){
            answer *= hm.get(key);
        }
        
        return answer-1;
    }
}