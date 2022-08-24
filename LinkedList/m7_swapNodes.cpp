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
    ListNode* swapNodes(ListNode* head, int k) {
        int len =0;
        auto temp = head;
        while(temp) {len++; temp=temp->next;}
        temp=head;
        int i=1;
        if(k>len/2) k = len-k+1;
        for(;i<k;i++) temp=temp->next;
        auto ptr1 = temp;
        for(;i<len-k+1;i++) temp =temp->next;
        swap(ptr1->val,temp->val);
        return head;    
    }
};
// in single pass
ListNode* swapNodes(ListNode* head, int k) 
{
    ListNode *p1 = head;
    for(int i=1; i<k; i++)
        p1 = p1->next;
    
    ListNode *slow = head, *fast = p1->next;
    while(fast)
    {
        fast = fast->next;
        slow = slow->next;
    }
    
    swap(slow->val, p1->val);
    return head;
} 