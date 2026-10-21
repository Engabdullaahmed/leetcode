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
        if(!head)
        {
            return head ;
        }
      // rotaion as same linked list is same 
    int len = 0 ;
    for(ListNode*cur  = head ;cur ;cur=cur->next)
    {
        len++;
    }
    // remove any additon cycle ;
    k = k % len ;
    ListNode* cur = head ;
    ListNode* tail;
    ListNode* prev;
    while(k>0)
    {
        while(cur->next)
        {
            prev = cur ;
            cur = cur->next ;
        }
        tail = cur;
        
        tail->next = head ;
        head = tail;
        cur = head ;
        prev->next = nullptr ;
        k--;
    }
    return head ;
    
    }
};