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

class Solution
{
public:
        ListNode *oddEvenList(ListNode *head)
        {
            if(!head || !head->next || !head->next->next)
            {
                return head ;
            }
            ListNode* even_connect = head->next ;
            ListNode* odd_connect = head;
            ListNode* even_start = head->next;
            while(odd_connect->next and even_connect->next )
            {
                // all odd
                odd_connect->next = even_connect->next;
                // all even 
                even_connect->next = odd_connect->next->next;
                odd_connect = odd_connect->next ;
                even_connect = even_connect->next;
            }
            // last odd;
            // 1 3 5 

            // 2 4 
            odd_connect->next = even_start ;

            return head ; 

        }
};