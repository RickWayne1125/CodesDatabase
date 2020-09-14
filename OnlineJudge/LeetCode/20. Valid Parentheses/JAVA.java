import java.util.Stack;

class Solution {
    public boolean isValid(String s) {
        Stack<Integer> flag = new Stack<>();
        flag.push(-1);
        int[] a = new int[3];
        a[0] = 0;
        a[1] = 0;
        a[2] = 0;
        for(int i=0; i < s.length(); i++){
            switch (s.charAt(i)){
                case '(':
                    flag.push(0);
                    a[0]++;
                    break;
                case '[':
                    flag.push(1);
                    a[1]++;
                    break;
                case '{':
                    flag.push(2);
                    a[2]++;
                    break;
                case ')':
                    if(flag.peek() != 0 || flag.peek() == -1)
                        return false;
                    a[0]--;
                    if(a[0] < 0)
                        return false;
                    flag.pop();
                    break;
                case ']':
                    if(flag.peek() != 1 || flag.peek() == -1)
                        return false;
                    a[1]--;
                    if(a[1] < 0)
                        return false;
                    flag.pop();
                    break;
                case '}':
                    if(flag.peek() != 2 || flag.peek() == -1)
                        return false;
                    a[2]--;
                    if(a[2] < 0)
                        return false;
                    flag.pop();
                    break;
            }
        }
        if(a[0] == 0 && a[1] == 0 && a[2] == 0)
            return true;
        else
            return false;
    }
}