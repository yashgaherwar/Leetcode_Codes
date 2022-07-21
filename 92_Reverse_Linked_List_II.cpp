/*

Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

Example 1:

Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]

Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]
 
Constraints:

The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n

*/

/* Solution */

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

class Solution {
public:
  
  // Time Complexity:- O(N)
  
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        ListNode* dummy = new ListNode(-1);
        dummy->next=head;
        
        ListNode* it=dummy;
        ListNode* prev=NULL;
        
        for(int j=0;j<left;j++){
            prev=it;
            it=it->next;
        }
        
        ListNode* it2=it;
        ListNode* prev2=prev;
        
        for(int j=left;j<=right;j++){
            ListNode* fwd=it2->next;
            it2->next=prev2;
            
            prev2=it2;
            it2=fwd;
        }
        
        prev->next=prev2;
        it->next=it2;
        
        return dummy->next;
        
    
    }
};
 
