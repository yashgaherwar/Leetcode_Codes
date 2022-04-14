/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.
*/

/*Solution*/

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
     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       
         if(list1==NULL){
             return list2;
         }
         if(list2==NULL){
             return list1;
         }
         
         if(list1->val <= list2->val){
             list1->next=mergeTwoLists(list1->next,list2);
             return list1;
         }
         else{
             
            list2->next=mergeTwoLists(list1,list2->next);
            return list2; 
         }
         
    }
     /*void insert(ListNode** root, int data){
       ListNode* node = new ListNode(data);
       ListNode* ptr;
       if(*root == NULL){
          *root = node;
       }
       else{
          ptr =*root;
          while(ptr->next != NULL){
             ptr = ptr->next;
          }
          ptr->next = node;
       }
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> v;
        while(list1!=NULL){
            v.push_back(list1->val);
            list1=list1->next;
        }
        //v.push_back(list1->val);
        while(list2!=NULL){
            v.push_back(list2->val);
            list2=list2->next;
        }
        //v.push_back(list2->val);
        
        sort(v.begin(),v.end());
        
        ListNode *root = NULL;
        for (int i=0;i<v.size();i++){
            insert(&root, v[i]);
        }    
        
        return root;
    }*/
};
 
