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
ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return NULL;
        ListNode * node = reverseList(head->next);
        head->next->next = head;
        head->next =NULL;
        return node;
    }

