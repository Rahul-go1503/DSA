#include <bits/stdc++.h>
using namespace std;
class Solution
{
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    ListNode *solve(ListNode *list1, ListNode *list2)
    {
        ListNode *head1 = list1;
        ListNode *temp = list1;
        list1 = list1->next;
        while (list1 && list2)
        {
            if (list1->val <= list2->val)
            {
                temp->next = list1;
                list1 = list1->next;
            }
            else
            {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }
        if (list2)
            temp->next = list2;

        if (list1)
            temp->next = list1;
        return head1;
    }

public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;
        if (list1->val <= list2->val)
        {
            return solve(list1, list2);
        }
        else
            return solve(list2, list1);
    }
};