/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
	ListNode* ReverseList(ListNode* head) {
		ListNode* pre = NULL;
		ListNode* cur = NULL;
		while (head != NULL) {
			cur = head->next;
			head->next = pre;
			pre = head;
			head = cur;
		}
		return pre;
	}
};