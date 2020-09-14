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
	ListNode* FindKthToTail(ListNode* p, unsigned int k) {
		if (k == 0 || p == NULL)	return NULL;
		ListNode* l = p;
		ListNode* r = p;
		for (int i = 0; i < k - 1; i++) {
			if (r->next != NULL)	r = r->next;
			else return NULL;
		}
		while (r->next != NULL) {
			l = l->next;
			r = r->next;
		}
		return l;
	}
};