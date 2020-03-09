// [Warning!]This is not a good solution, still need to be improved
class Solution {
	boolean checkRe(String ss){
		int len = ss.length();
		for(int i = 0; i < len-1; i++){
			for(int j = i + 1; j < len; j++){
				if(ss.charAt(i) == ss.charAt(j))  return false;
			}
		}
		return true;
	}
	public int lengthOfLongestSubstring(String s) {
		int len = s.length();
		if(len == 1)    return 1;
		else if(len == 0)   return 0;
		int ans = 1;
		int end = 1;
		for(int i = 0; i < len - 1; i++){
			while(i >= end)    end++;
			for(int j  = end; j < len; j++){
				int l = j - i + 1;
				char[] temp = new char[l];
				s.getChars(i, j + 1, temp, 0);
				String temp1 = new String(temp);
				if(checkRe(temp1) == false)  {
					end = j;
					break;
				}
				else{
					ans = Math.max(ans, l);
				}
			}
		}
		return ans;
	}
}