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
// here, we are deferecing pointers 
// so we are copying the next node content to current node i.e. (node_value, address_of_next_node)
//now current node has nextNode's value and it has address of (node->next->next) node
// so we updated current node next pointer, by pointing it to (node->next->next) node
// *node = *nextNode; 

// after copying node it looks something like this
// - (head_value, addr_2)---->(val_3, addr_4)        (val_3, addr_4)---->(val_4, addr_5)---->NULL
//                                     |___________________________________________^


// second node has node_value of 3rd node
// also second node has address of 4th node so, 2nd node next pointer point to 4th node
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp = node->next; // copy pointer
        *node = *temp; // copy content of temp pointer
        delete temp; // delete temp variable
    }
};