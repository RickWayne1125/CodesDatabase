class Solution {
    public int strStr(String haystack, String needle) {
        if (needle.equals("") || haystack.equals(needle)) {
            return 0;
        }
        if (haystack.equals("") || haystack.length() < needle.length()) {
            return -1;
        }
        int flag = 0;
        for (int i = 0; i < haystack.length() - needle.length() + 1; i++) {
            int tmp = 1;
            for (int j = i; j < i + needle.length(); j++) {
                if (needle.charAt(j - i) != haystack.charAt(j)) {
                    tmp = 0;
                    break;
                }
            }
            if (tmp == 1) {
                return i;
            }
        }
        return -1;
    }
}