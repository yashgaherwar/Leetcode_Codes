/*

Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:

Input: head = [1], n = 1
Output: []

Example 3:

Input: head = [1,2], n = 1
Output: [1]
 
Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr=head;
        ListNode* prev=new ListNode(-1,head);
        ListNode* node=prev;
        
        int count=0;
        int sz=0;
        
        while(curr!=NULL){
           sz++;
           curr=curr->next; 
        }
        
        
        
        while(head!=NULL){
            //cout<<count<<endl;
            if(count==sz-n){
               prev->next=head->next; 
               return node->next;
               
            }
            prev=prev->next;
            head=head->next;
//             if(prev->next!=NULL){
//                 prev=prev->next;
//             }
//             else{
//                 break;
//             }
            
            count++;
        }
        
        return node->next;
    }
};
