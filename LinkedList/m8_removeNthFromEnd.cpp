/*********************************************************************************************

Question :


Notes :

**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next) return NULL;
        auto p = head;
        for(int i=1;i<n;i++)
            p = p -> next;
        ListNode *slow = head, *fast = p->next;
        while(fast && fast->next){
            slow = slow -> next;
            fast = fast -> next;
        }
        if(!fast){
            ListNode *newHead = head->next;
            delete head;
            return newHead;
        }
        auto temp = slow->next;
        slow->next = temp->next;
        delete temp;
        return head;
    }
};