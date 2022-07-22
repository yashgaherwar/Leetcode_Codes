/*

Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example 1:

Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]

Example 2:

Input: head = [2,1], x = 2
Output: [1,2]
 
Constraints:

The number of nodes in the list is in the range [0, 200].
-100 <= Node.val <= 100
-200 <= x <= 200

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
    ListNode* partition(ListNode* head, int x) {
        ListNode* hg = new ListNode(-1);
        ListNode* lw = new ListNode(-1);
        
        ListNode* hg2 = hg;
        ListNode* lw2 = lw;
        
        while(head!=NULL){
            if(head->val < x){
                lw2->next=head;
                lw2=lw2->next;
            }
            else{
                hg2->next=head;
                hg2=hg2->next;
            }
            
            head=head->next;
        }
        
        lw2->next=hg->next;
        hg2->next=NULL;
        
        return lw->next;
    }
};
