class Solution {
public:
	void replaceSpace(char* str, int length) {
		string ans(str);
		for (int i = 0; i < ans.length(); i++) {
			if (ans[i] == ' ') {
				ans.erase(i, 1);
				ans.insert(i, "%20");
			}
		}
		auto s = ans.c_str();
		strcpy(str, s);
	}
};