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
    //LL
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0) return head;
        int n=0;
        auto last = head;
        while(last->next){
            n++;
            last=last->next;
        }
        n++;
        k=k%n;
        auto temp = head;
        int i=1;
        while(i<n-k){
            temp=temp->next;
            i++;
        }
        last->next=head;
        auto ans = temp->next;
        temp->next = NULL;
        return ans;
    }
};