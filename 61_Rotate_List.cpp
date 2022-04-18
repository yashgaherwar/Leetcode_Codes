/*
Given the head of a linked list, rotate the list to the right by k places.

Example 1:

Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

Example 2:

Input: head = [0,1,2], k = 4
Output: [2,0,1]

Constraints:

The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109
*/

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 || head==NULL || head->next==NULL){
            return head;
        }
        
        int count=1;
        ListNode* cur=head;
        while(cur->next!=NULL){
            cur=cur->next;
            count++;
        }
        
        cur->next=head;
        k=k%count;
        k=(count-k);
        
        while(k--){
            cur=cur->next;
            
        }
        head=cur->next;
        cur->next=NULL;
        
        return head;
        
        /*
            Time Complexity=O(n)+O(n-(n%k))
            Space Complexity=o(1)
        */    
    }
};
