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
ListNode* deleteDuplicates(ListNode* head) {
    if(!head||!head->next) return head;
    ListNode* curr =head;
    ListNode* nxt =head->next;
    while(nxt){
        if(curr->val==nxt->val){
            curr->next= nxt->next;
            delete nxt;
            nxt=curr->next;
        }else{
            curr=curr->next;
            nxt=nxt->next;
        }
    }
    return head;        
}