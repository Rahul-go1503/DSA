/*********************************************************************************************

Question :


Notes :
cout<<l1->val<<" "<<l2->val<<" "<<carry<<endl;
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        int digit=0;
        auto head= l1;
        ListNode *temp1 =NULL,*temp2=NULL;
        while(l1&&l2){
            digit=(l1->val+l2->val+carry)%10;
            carry=(l1->val+l2->val+carry)/10;
            l1->val=digit;
            if(!l1->next){
                temp1= l1;
                temp2=l2->next;
                }
            l1=l1->next;l2=l2->next;
        }
        if(!l1){
            temp1->next=temp2;
            while(l2){
                digit=(l2->val+carry)%10;
                carry=(l2->val+carry)/10;
                l2->val=digit;
                if(!l2->next&&carry){
                    l2->next=new ListNode(carry);
                    break;
                }
                l2=l2->next;
            }
        }
        if(!l2){
            while(l1){
                digit=(l1->val+carry)%10;
                carry=(l1->val+carry)/10;
                l1->val=digit;
                if(!l1->next&&carry){
                    l1->next=new ListNode(carry);
                    break;
                }
                l1=l1->next;
            }
        }
        return head;
    }
};