// 此方法使用map存储，执行用时相比数组减少至8ms，缺点在于内存消耗仍然很大
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int len = s.length();
        int ans = 1;
        int start = 0;
        int end = 0;
        Map<Character, Integer> m = new HashMap<Character, Integer>();
        for(end=0; end < len; end++){
            char temp = s.charAt(end);
            if(m.containsKey(temp) && start < m.get(temp)){
                start = m.get(temp);
            }
            m.put(s.charAt(end), end + 1);
            ans = Math.max(end - start + 1, ans);
        }
        return ans;
    }
}