import java.util.HashMap;
import java.util.Map;

class Solution {
	public int countCharacters(String[] words, String chars) {
		int ans = 0;
		int []le = new int[26];
		for(int i=0;i<le.length;i++){
			le[i]=0;
		}
		for(int i=0;i<chars.length();i++){
			int pos = chars.charAt(i)-'a';
			le[pos]++;
		}
		for(int j=0;j<words.length;j++){
			int flag = 1;
			int []temp = new int[26];
			System.arraycopy(le,0,temp,0,le.length);
			for(int k=0;k<words[j].length();k++){
				int pos = words[j].charAt(k)-'a';
				if(temp[pos]==0){
					flag = 0;
					break;
				}
				else{
					temp[pos]-=1;
				}
			}
			if(flag==1){
				ans+=words[j].length();
			}
		}
		return ans;
	}
}