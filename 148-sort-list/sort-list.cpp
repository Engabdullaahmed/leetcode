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
    ListNode* sortList(ListNode* head) {
        if(!head)
        {
            return nullptr ;
        }
       vector<int>ans ;
       for(ListNode* cur = head; cur;cur=cur->next)
       {
        ans.push_back(cur->val);
       }
       sort(ans.begin(),ans.end());
       int i =0  ;
       for(ListNode* cur = head; cur;cur=cur->next)
       {
        cur->val = ans[i];
        i++;
       }
       return head; 
    }
};