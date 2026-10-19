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
        ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
        {
                ListNode *cur1 = l1;
                ListNode *cur2 = l2;
                ListNode *ans = nullptr;
                ListNode *tail = ans;
                int carry = 0;
                while (cur1 || cur2)
                {
                        int sum = carry;
                        if (cur1)
                        {
                                sum += cur1->val;
                                cur1 = cur1->next;
                        }
                        if (cur2)
                        {
                                sum += cur2->val;

                                cur2 = cur2->next;
                        }
                        if (sum <= 9)
                        {
                                if (!ans) // empty
                                {
                                        ans = new ListNode(sum);
                                        tail = ans;
                                        tail->next = nullptr;
                                }
                                else
                                {
                                        tail->next = new ListNode(sum);
                                        tail = tail->next;
                                }
                                carry = 0;
                        }
                        else
                        {
                                int last = sum % 10;
                                sum /=10;
                                carry = sum;
                                if (!ans) // empty
                                {
                                        ans = new ListNode(last);
                                        tail = ans;
                                        tail->next = nullptr;
                                }
                                else
                                {
                                        tail->next = new ListNode(last);
                                        tail = tail->next;
                                }
                        }
                }
                if (carry > 0)
                {
                        tail->next = new ListNode(carry);
                        tail = tail->next;
                }
                return ans;
        }
};