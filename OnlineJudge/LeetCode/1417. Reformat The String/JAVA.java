import java.util.Vector;

class Solution {
    public String reformat(String s) {
        String ans = "";
        Vector<Character> num = new Vector<>();
        Vector<Character> let = new Vector<>();
        for(int i=0; i<s.length(); i++){
            if(s.charAt(i)<='z' && s.charAt(i)>='a'){
                let.add(s.charAt(i));
            }
            else if(s.charAt(i)<='9' && s.charAt(i)>='0'){
                num.add(s.charAt(i));
            }
        }
        if(let.size()==num.size() || let.size()==num.size()-1){
            int j1 = 0;
            int j2 = 0;
            for(int i=0; i<s.length(); i++){
                if(i%2==0){
                    ans+=num.get(j1);
                    j1++;
                }
                else{
                    ans+=let.get(j2);
                    j2++;
                }
            }
        }
        else if(let.size()-1==num.size()){
            int j1 = 0;
            int j2 = 0;
            for(int i=0; i<s.length(); i++){
                if(i%2==1){
                    ans+=num.get(j1);
                    j1++;
                }
                else{
                    ans+=let.get(j2);
                    j2++;
                }
            }
        }
        return ans;
    }
}