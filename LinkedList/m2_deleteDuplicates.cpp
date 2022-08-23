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
// resolve 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
       if(!head||!head->next) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = dummy;
        int duplicate;
        while (cur->next && cur->next->next) {
            if (cur->next->val == cur->next->next->val) {
                duplicate = cur->next->val;
                while (cur->next && cur->next->val == duplicate){
                    auto temp = cur->next;
                    cur->next = cur->next->next;
                    delete temp;
                }
            }
            else cur = cur->next;
        }
        auto ans = dummy->next;
        delete dummy;
	return ans; 
    }
};