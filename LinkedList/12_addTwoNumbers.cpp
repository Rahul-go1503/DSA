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
// not compl
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int sum = 0;
    int digit = 0; 
    int carry =0;
    auto head = l1;
    while(l1 && l2){
        sum = l1->val + l2->val+carry;
        l1->val= sum%10;
        carry = sum/10;
        l1= l1->next;
        l2= l2->next;
    }
    while(l1){
        sum = l1->val +carry;
        l1->val= sum%10;
        carry = sum/10;
        l1= l1->next;
    }
    l1=l2;
    while(l1){
        sum = l1->val+carry;
        l1->val= sum%10;
        carry = sum/10;
        l1= l1->next;
    }
    if(carry){
        auto temp = new ListNode(carry);
        l1=temp;
    }
}