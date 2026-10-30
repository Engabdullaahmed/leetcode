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
        ListNode *reverseKGroup(ListNode *head, int k)
        {
                ListNode *cur = head;
                ListNode *prev = nullptr;
                ListNode *prev2 = nullptr;
                ListNode *tail;
                ListNode *prev_tail;
                int len = 0;
                for (ListNode *cur2 = head; cur2; cur2 = cur2->next)
                {
                        len++;
                }
                if (len < k)
                {
                        return head;
                }
                        // start at first part
                        bool remain = true;
                        int counter = 0;
                        while (remain)
                        {
                                for (int c = 0; c < k; c++)
                                {
                                        if (c == 0)
                                        {
                                                tail = cur;
                                        }
                                        ListNode *next = cur->next;
                                        cur->next = prev2;
                                        prev2 = cur;
                                        cur = next;
                                }
                                counter++;
                                // done group 
                                if (counter == 1)
                                {
                                        prev = prev2; // store first element
                                        prev_tail = tail;
                                }
                                else
                                {
                                        prev_tail->next = prev2;
                                        prev_tail = tail;
                                }
                                prev2 = nullptr;
                                if (len - counter * k < k)
                                {
                                        remain = false;
                                }
                        }
                        prev_tail->next = cur;

                        return prev;
        }
};