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
    ListNode* swapPairs(ListNode* head) {
        if(!head)
        {
            return nullptr ;
        }
        if(!head->next)
        {
            return head ;
        }
        ListNode* next = head  ;
        ListNode* next2 ;
        ListNode* cur = head ;
        ListNode* ans ;
        ListNode* tail ;
        bool flage  = false ;
        while(cur and cur->next)
        {
// ans is st
// i need to get tail last elemnt 
next = cur->next ;
// 1 2 3 4 
// cur  1 
// next 2 correct 
next2 = next->next;
// 3 4
next->next  = cur ;
// 2 1 
cur->next = next2 ;
// now i need to get tail ok  
if(!flage)
{
flage =  true;
ans = next ;
}
else {
// connect two pairs 
tail->next = next;
}
tail = cur ;
cur = next2;
        }
        return ans ;
    }
};