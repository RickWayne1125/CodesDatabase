import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Solution {
    public String longestCommonPrefix(String[] strs) {
        String ans = "";
        int len = strs.length;
        if(len == 0)
            return ans;
        List<Integer> l = new ArrayList<>();
        for(int i=0; i < len; i++){
            l.add(strs[i].length());
        }
        for(int i=0; i < Collections.min(l); i++){
            int flag = 1;
            for(int j=0; j < len; j++){
                if(strs[j].charAt(i) != strs[0].charAt(i)){
                    flag = 0;
                    break;
                }
            }
            if(flag == 1)
                ans += strs[0].charAt(i);
            else
                break;
        }
        return ans;
    }
}