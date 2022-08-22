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
