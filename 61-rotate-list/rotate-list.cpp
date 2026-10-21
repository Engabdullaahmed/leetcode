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
    if(k==0)
    {
        return head ;
    }
   
    ListNode* tail = head ;
    while(tail->next)
    {
        tail = tail->next;
    }
    tail->next = head;
    // 4 5 1 2 3 4 5 cicyle 
    ListNode* new_tail = head;
    for(int i = 1 ;i<len - k;i++)
    {
        new_tail= new_tail->next;
    }
    ListNode* ans  = new_tail->next ;
    new_tail->next = nullptr ;
    return ans;
    }
};