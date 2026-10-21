/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // fst 
        // sl 
        // detect cycle 
        // if no cycle 
        ListNode* fst = head ;
        ListNode* sl = head ;
        bool falge = false ;
        while(fst && fst->next)
        {
            sl  = sl->next;
            fst = fst->next->next; 
            if(sl == fst)
            {
                falge=  true;
                break;
            }
        }
        if(!falge)
        {
            return nullptr;
        }else {
            sl = head ;
            while(sl != fst)
            {
                sl = sl->next ;
                fst = fst->next ;
            }
            return sl ;
            // int ans = 0 ;
            // for(ListNode* cur = head ;cur ;cur=cur->next)
            // {
            //     if(cur ==sl)
            //     {
            //         ans++;
            //         break;
            //     }
            // }
            // return ans ;
        }
    }
};