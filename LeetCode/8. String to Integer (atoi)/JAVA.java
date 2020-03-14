import java.math.BigInteger;

class Solution {
	public int myAtoi(String str) {
		int ans = 0;
		String sans = "0";
		int sym = 1;
		int flag = 0;   // Judge if alredy have the first not null char
		for(int i = 0; i < str.length(); i++){
			if(str.charAt(i) >= '0' && str.charAt(i) <= '9'){
				if (flag == 1 && sym == 1 && Integer.parseInt(sans) > Integer.MAX_VALUE / 10)
					return Integer.MAX_VALUE;
				if (flag == 1 && sym == 1 && Integer.parseInt(sans) == Integer.MAX_VALUE / 10 && str.charAt(i) - '0' > Integer.MAX_VALUE % 10)
					return Integer.MAX_VALUE;
				if (flag == 1 && sym == 0 && -Integer.parseInt(sans) < Integer.MIN_VALUE / 10)
					return Integer.MIN_VALUE;
				if (flag == 1 && sym == 0 && -Integer.parseInt(sans) == Integer.MIN_VALUE / 10 && -(str.charAt(i) - '0') < Integer.MIN_VALUE % 10)
					return Integer.MIN_VALUE;
				if(flag == 0)   flag = 1;
				sans += str.charAt(i);
			}
			else if(str.charAt(i) == '-' && flag == 0){
				sym = 0;
				flag = 1;
			}
			else if(str.charAt(i) == '+' && flag == 0){
				sym = 1;
				flag = 1;
			}
			else if(str.charAt(i) == ' ' && flag == 1){
				break;
			}
			else if(str.charAt(i) == ' ' && flag == 0){
				continue;
			}
			else break;
		}
		BigInteger bans = new BigInteger(sans);
		if(sym == 0)    ans = -bans.intValue();
		else    ans = bans.intValue();
		return ans;
	}
}