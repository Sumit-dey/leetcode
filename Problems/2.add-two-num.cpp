/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.


*/
public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
    	ListNode ans = new ListNode(0);
    	ListNode head = ans;
        int sum = 0 , carry = 0;
    	while(l1!=null || l2!=null){
    		int x = 0 , y = 0;
    		if(l1!=null) { x = l1.val; l1 = l1.next; }
    		if(l2!=null) { y = l2.val; l2 = l2.next; }
    		sum = (sum + x + y);
    		int cur = sum % 10;
    		sum = sum / 10;
    		ListNode res = new ListNode(cur);
    		ans.next = res;
    		ans = ans.next;
    	}
    	if(sum!=0) {
    		ans.next = new ListNode(sum);
    	}
    	return head.next;
    }
}
