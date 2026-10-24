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
             if (!head || !head->next)
                return head;
                ListNode *tail = nullptr;
                ListNode *cur = head;
                ListNode *prev = nullptr;
                int len2 = 0;

                while (cur->next)
                {
                        len2++;

                        cur = cur->next;
                }
                tail = cur;
                len2++;
                // now i have got tail ok
                cur = head;
                int len = 0;
                int even = len2 / 2;

                while (even > 0)
                {
                        len++;
                        if (len % 2 == 0)
                        {
                              if (cur == tail)
                                  break;

                                // that before and after
                                // contain cur 
                                ListNode *temp = cur;
                                // connect before with after 
                                prev->next = temp->next;
                                // handle tail 
                                tail->next = cur;
                                tail = cur;
                                tail->next = nullptr;
                                // move 
                                cur = prev->next;
                                even--;
                        }
                        else
                        {
                                prev = cur;
                                cur = cur->next;
                        }
                }
    
                                
                return head;
        }
};