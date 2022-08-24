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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *prev= new ListNode(0), *curr=head, *ans = head->next;
        prev->next=head;
        while(curr && curr->next){
            auto forw = curr->next;
            curr->next = forw->next;
            curr= curr->next;
            forw->next = prev->next;
            prev->next= forw;
            prev= forw->next;
        }
        return ans;
    }
};
class Solution {
public:
    ListNode* swapPairs(ListNode* head) { 
        if (!head || !(head -> next)) return head;
        ListNode* new_head = new ListNode(0);
        new_head -> next = head;
        ListNode* pre = new_head; 
        ListNode* cur = head;
        while (pre -> next && cur -> next) {
            pre -> next = cur -> next;
            cur -> next = cur -> next -> next;
            pre -> next -> next = cur;
            pre = cur;
            cur = pre -> next;
        }
        return new_head -> next;
    }
};
class Solution {
public:
    //invert the first 2 and then recurse for the rest
    ListNode* swapPairs(ListNode* head) {
        //base case here
        if(!head || !head->next) return head;
        //Swapping part happens here, please draw to visualize
        ListNode *temp = head->next;
        head->next = swapPairs(temp->next); 
        temp->next = head;

        return temp;
    }
};