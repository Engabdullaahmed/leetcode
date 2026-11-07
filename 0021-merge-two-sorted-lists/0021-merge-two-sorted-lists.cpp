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
        ListNode* cur = new ListNode; 
        ListNode* head =cur; 
      
        ListNode* cur_1 = list1 ;
        ListNode* cur_2 = list2;
       while (cur_1 != nullptr && cur_2 != nullptr)
        {
            if(cur_1->val<=cur_2->val)
            {
                cur->next = cur_1;
                cur = cur_1; 
                cur_1 = cur_1->next ;

            }
            else {
          
                cur->next = cur_2;
                cur = cur_2 ;
                cur_2 = cur_2->next ;
            }
        }
         while (cur_1 != nullptr)
        {
            
                cur->next = cur_1;
                cur = cur_1; 
                cur_1 = cur_1->next ;

        }
        while (cur_2 != nullptr)
        {
            
                cur->next = cur_2;
                cur = cur_2; 
                cur_2 = cur_2->next ;

        }
        
        return head->next;
    }
};