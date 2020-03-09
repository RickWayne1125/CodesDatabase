class Solution {
	public int[] twoSum(int[] nums, int target) {
		int x = 0;
		int y = 0;
		int flag = 0;
		for(int i = 0;i < nums.length; i++){
			if(flag == 1)    break;
			x = i;
			for(int j = i + 1; j < nums.length; j++){
				y = j;
				if(nums[x] + nums[y] == target){
					flag = 1;
					break;
				}
			}
		}
		int[] ans = new int[2];
		ans[0] = x;
		ans[1] = y;
		return ans;
	}
}