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
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
        auto dummy = new ListNode(0);
        dummy->next=head;
        auto temp = head;
        int i = 1;
        ListNode *prev =dummy;
        while(i!=left){
            prev=temp;
            temp=temp->next;
            i++;
        }
        auto ptr1 = prev;
        auto ptr2= temp;
        while(i<=right){
            auto nxt = temp->next;
            temp->next= prev;
            prev= temp;
            temp=nxt;
            i++;
        }
        ptr1->next = prev;
        ptr2->next = temp;
        
        head = dummy->next;
        delete dummy;
        return head;
    }
};
/*
hi-malik
https://leetcode.com/problems/reverse-linked-list-ii/discuss/2311084/JavaC++-Tried-to-Explain-every-step
*/
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode(0); // created dummy node
        dummy->next = head;
        ListNode *prev = dummy; // intialising prev pointer on dummy node
        
        for(int i = 0; i < left - 1; i++)
            prev = prev->next; // adjusting the prev pointer on it's actual index
        
        ListNode *curr = prev->next; // curr pointer will be just after prev
        // reversing
        for(int i = 0; i < right - left; i++){
            ListNode *forw = curr->next; // forw pointer will be after curr
            curr->next = forw->next;
            forw->next = prev->next;
            prev->next = forw;
        }
        return dummy->next;
    }
};