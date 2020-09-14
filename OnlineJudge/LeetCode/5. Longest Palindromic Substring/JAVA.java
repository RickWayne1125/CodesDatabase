class Solution {
	public String longestPalindrome(String s) {
		String ans = new String();
		int start = 0;
		int end = 0;
		int len = 0;
		int astart = 0;
		int aend = 0;
		if(s.length()==0)    return "";
		for(int i = 0; i < s.length(); i++){
			start = i;
			end = i;
			int mid = i;
			// left
			while(start >= 0 && s.charAt(start) == s.charAt(mid)){
				start--;
			}
			// right
			while(end < s.length() && s.charAt(end) == s.charAt(i)){
				end++;
			}
			// 2 directions
			while(start >= 0 && end < s.length() && s.charAt(start) == s.charAt(end)){
				start--;
				end++;
			}
			if(len < end - start +1){
				len = end - start + 1;
				astart = start;
				aend = end;
			}
		}
		ans = s.substring(astart + 1, aend);
		return ans;
	}
}