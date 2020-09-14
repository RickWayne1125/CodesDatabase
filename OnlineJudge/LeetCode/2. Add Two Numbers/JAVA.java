/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
	public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
		ListNode temp1 = l1;
		ListNode temp2 = l2;
		ListNode ans = new ListNode(0);
		ListNode curr;
		curr = ans;
		int carry = 0;
		int sum = 0;
		while(temp1 != null || temp2 != null){
			int x, y;
			if(temp1 == null)   x = 0;
			else{
				x = temp1.val;
				temp1 = temp1.next;
			}
			if(temp2 == null)   y = 0;
			else{
				y = temp2.val;
				temp2 = temp2.next;
			}
			sum = (x + y + carry)%10;
			carry = (x + y + carry)/10;
			curr.next = new ListNode(sum);
			curr = curr.next;
		}
		if(carry == 1)   curr.next = new ListNode(1);
		return ans.next;
	}
}