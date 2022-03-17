/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

 /*

Add Two Numbers 376+946:
caryy=1	carry=1	   carry=1		 carry=0
		 3             7             6
+        9             4             6
-------------------------------------------
  1 	 3             2             2
-------------------------------------------

Add from right to left:
-> Sum = Val1 + Val2 + Carry
-> n = Sum % 10
-> Carry = Sum / 10

Repeat the process untill left most digit

 Approach:
 1.) Initialize Carry = 0, Sum = 0.
 2.) Create a node t.
 Iterating both the lists:
 3.) Sum = Val1 + Val2 + Carry.
 4.) t->Val = Sum % 10.
 5.) Carry = Sum / 10.
 Moving to next pointer in both the lists.
 7.) l1 = l1 -> next, l2 = l2 -> next.
 Repeat the process from 3 to 7 untill the [ both l1 and l2 is NULL and carry=0 ].

 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* res=new ListNode();
        ListNode* t=res;

        int carry=0;

        while(l1!=NULL or l2!=NULL or carry){

            int sum=0;

            if(l1!=NULL){
                sum+=l1->val;
                l1=l1->next;
            }

            if(l2!=NULL){
                sum+=l2->val;
                l2=l2->next;
            }

            sum+=carry;
            carry=sum/10;

            ListNode* node=new ListNode(sum%10);

            t->next=node;
            t=t->next;

        }

        return res->next;

    }
};
