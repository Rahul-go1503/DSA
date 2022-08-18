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
bool isPalindrome(ListNode* head) {
     if(!head->next) return true;
     auto temp = head;
     int nodes = 0;
     while(temp){
        temp=temp->next;
        nodes++;
     }
     temp =head;   
    int n = nodes/2;
    vector<int> v(n);
    for(int i=n-1;i>=0;i--){
        v[i]=temp->val;
        temp=temp->next;
    }
    if(nodes%2==1) temp=temp->next;
    int i=0;
    while(temp && v[i]==temp->val){
        temp=temp->next;
        i++;
    }
    return temp ? false : true; 
}


class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return true;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL&&fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverseList(slow->next);
        slow=slow->next;
        while(slow!=NULL){
            if(head->val!=slow->val)
                return false;
            head=head->next;
            slow=slow->next;
        }
        return true;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* pre=NULL;
        ListNode* next=NULL;
        while(head!=NULL){
            next=head->next;
            head->next=pre;
            pre=head;
            head=next;
        }
        return pre;
    }
};