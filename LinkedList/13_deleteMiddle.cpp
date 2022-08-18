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
//The number of nodes in the list is in the range [1, 105].
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head->next) return NULL; // handle single node
        if(!head->next->next){  // handle double nodes
            auto temp = head->next;
            delete temp;
            head->next = NULL;
            return head;
        }
        // handle remaining cases 
        ListNode * slow = head;
        ListNode * fast = head;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        // slow pointer is pointing to the desired middle node
        auto temp = slow->next;
        *slow=*temp;
        delete temp;
        return head;
    }
};

ListNode* deleteMiddle2(ListNode* head) {
    if (head->next == nullptr)
        return nullptr;
    auto slow = head, fast = head->next->next;
    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }
    // slow pointer is pointing to the prev to the middle node
    auto temp = slow->next;
    slow->next = slow->next->next;
    delete temp;
    return head;
}