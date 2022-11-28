#include <bits/stdc++.h>
using namespace std;
/*********************************************************************************************

Question :

**********************************************************************************************/

// TC - O(), SC - O()

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* reverseList(ListNode* head,int k) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr && k){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev=curr;
            curr=temp;
            k--;
        }
        if(curr) head->next = reverseList(curr,k);
        return prev;
    }