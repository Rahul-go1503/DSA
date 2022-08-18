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

    //pending...
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto ptr1 = head;
        auto ptr2 = head;
        do{
            int t =0;
            while(ptr2&&t<n){
                ptr2=ptr2->next;
                t++;
            }
            if(t!=n){
                
            }
        }while(ptr2);
    }
};