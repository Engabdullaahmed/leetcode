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
        int len  = 0;
        ListNode* prev = nullptr ;
       for(ListNode* cur  = head ;cur ;cur= cur->next)
       {
        len++;
       }
       int target = len - n + 1 ;
       int len2 = 0 ;
       if(target == 1)
       {
        head = head->next ;
        return head ;
       }
       for(ListNode* cur  = head ;cur ;cur= cur->next)
       {
        len2++;
        if(len2 == target)
        {
            if(cur->next)
            {
                if(prev)
                {
                prev->next = cur->next;
                }
                else {
                    prev = cur->next ;
                }
            }else {
                if(prev)
                {
                prev->next = nullptr ;
                }
                else {
                return nullptr ;
                }
            }
            break;
        }
        else {
            prev =  cur ;
        }
       }
       return head ;

    }
};