/*********************************************************************************************

Question :


Notes :
This removes the memory to which ps pointer points; it doesn’t remove the pointer ps itself. You can reuse ps
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
// Accepted
ListNode* removeElements(ListNode* head, int val) {
    if(!head) return head;
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    auto prev = dummy;
    auto curr = head;
    while(curr){
        if(curr->val==val){
            auto *temp = curr;
            prev->next= curr->next;
            delete temp;
            curr = prev->next;
        }else{
        curr=curr->next;
        prev=prev->next;
        }
    }
    auto head= dummy->next;
    delete dummy;
    return head;
}