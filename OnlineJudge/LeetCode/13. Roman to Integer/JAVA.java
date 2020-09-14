class Solution {
    public int get(char c){
        if(c == 'I'){
            return 1;
        }
        else if(c == 'V'){
            return 5;
        }
        else if(c == 'X'){
            return 10;
        }
        else if(c == 'L'){
            return 50;
        }
        else if(c == 'C'){
            return 100;
        }
        else if(c == 'D'){
            return 500;
        }
        else if(c == 'M'){
            return 1000;
        }
        else return 0;
    }
    public int romanToInt(String s) {
        int ans = 0;
        int pre = get(s.charAt(0));
        for(int i=1; i<s.length(); i++){
            int temp = get(s.charAt(i));
            if(pre >= temp){
                ans += pre;
            }
            else{
                ans -= pre;
            }
            pre = temp;
        }
        ans += pre;
        return ans;
    }
}