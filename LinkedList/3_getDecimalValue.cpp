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
int getDecimalValue(ListNode* head) {
    int ans=0,i=0;
    ListNode* temp = head;
    int nodes = 0;
    while(temp){
        nodes++;
        temp=temp->next;
    }
    while(nodes){
        ans+=head->val*pow(2,--nodes);
        head=head->next;
    }
    return ans;        
}

/* Approach 2
    to convert binary integer to decimal, start from the left. Take your current total, multiply it by two and add the current digit. Continue until there are no more digits left. Here is an example 1011
    2.0 + 1 = 1
    2.1 + 0 = 2
    2.2 + 1 = 5
    2.5 + 1 + 11
    Operation is always the previous multiplied by the counting system. In this , we're doing decimal so x10. If we were doing hex, it'll x16. Binary will be x 2.
*/
int getDecimalValue(ListNode* head) {
        int res=0;
        while(head!=NULL){
            res=res*2+head->val;
            head=head->next;
        }
        return res;
}
/*
Approach is same actually , it's just we are gonna achieve it via bitwise operators, it is beneficial as they work faster than the arithmatic operators !!


To visualize it -->
our sum = 0
And we are gonna do 2 steps --->>>

sum * 2 = sum (left shift <<)

sum + 1 or 0 = sum
And will run a loop over these 2 steps until head becomes NULL.....

Dry run yourself
*/
int getDecimalValue(ListNode* head) {
        int res = 0;
        ListNode* iter = head;
        while (iter != NULL) {
            res <<= 1;
            res |= iter->val;
            iter = iter->next;
        }
        return res;
}