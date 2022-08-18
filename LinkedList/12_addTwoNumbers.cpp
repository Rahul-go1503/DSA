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
    int carrry =0;
    while(l1 && l2){
        sum = l1->val + l2->val;
    }        
}