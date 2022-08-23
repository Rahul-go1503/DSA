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
    ListNode* prev =head;
    ListNode* curr =head->next;
    while(curr){
        if(curr->val==prev->val){
            prev->next= curr->next;
            delete curr;
            curr=prev->next;
        }else{
            curr=curr->next;
            prev=prev->next;
        }
    }
    return head;        
}