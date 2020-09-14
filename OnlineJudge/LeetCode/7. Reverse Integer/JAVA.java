class Solution {
	public int reverse(int x) {
		int ans = 0;
		int flag = 1;
		if(x < 0){
			flag = 0;
		}
		int temp = Math.abs(x);
		while(temp > 0){
			if(ans > (Math.pow(2, 31) - 1) / 10) return 0;
			ans = ans * 10 + temp % 10;
			temp = temp / 10;
		}
		if(flag == 0){
			ans = -ans;
		}
		return ans;
	}
}