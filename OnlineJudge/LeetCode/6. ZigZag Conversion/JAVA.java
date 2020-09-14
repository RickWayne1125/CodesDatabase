class Solution {
	public String convert(String s, int numRows) {
		String ans = "";
		String [] rows = new String[numRows];
		// init rows
		for(int j = 0; j <numRows; j++){
			rows[j] = "";
		}
		// fill in rows
		for(int i = 0; i < s.length(); i++){
			int flag = i%(2*numRows - 2);
			if(flag < numRows){
				rows[flag] += s.charAt(i);
			}
			else{
				int temp = 2*numRows - 2 - flag;
				rows[temp] += s.charAt(i);
			}
		}
		// fill in ans
		for(int j = 0; j <numRows; j++){
			ans += rows[j];
		}
		return ans;
	}
}