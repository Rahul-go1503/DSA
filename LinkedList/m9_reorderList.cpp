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
/*
	Time Complexity: O(N)
	Space Complexity: O(N/2)

	Where 'N' is the total number of elements in the array.
*/
class Solution {
public:
    void reorderList(ListNode* head) {
        stack<ListNode*> s;
        auto slow = head;
        auto fast = head->next;
        while(fast && fast->next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        slow = slow -> next;
        while(slow){
            s.push(slow);
            slow = slow -> next;
        }
        
        auto ptr = head;
        while(!s.empty()){
            auto nxt = ptr -> next;
            auto node = s.top(); s.pop();
            ptr -> next = node;
            node -> next = nxt;
            ptr = nxt;
        }
        ptr -> next =NULL;
        return ;
    }
};
/*
	Time Complexity: O(N)
	Space Complexity: O(1)

	Where 'N' is the total number of elements in the array.
*/
class Solution {
    ListNode* reverse(ListNode* head){
        if(!head || !head -> next) return head;
        
        auto temp = reverse(head->next);
        head -> next -> next = head;
        head -> next = NULL;
        return temp;
    }
public:
    void reorderList(ListNode* head) {
         // find the middle node: O(n)
        auto slow = head; auto fast = head;
        while(fast && fast->next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        // cut from the middle and reverse the second half: O(n)
        auto head2 = slow->next;
        slow->next = NULL;
        auto rhead = reverse(head2);
        
        // merge two lists: O(n)
        // for (p1 = head, p2 = head2; p1; ) {
        //     auto t = p1->next;
        //     p1 = p1->next = p2;
        //     p2 = t;
        // }
        auto ptr = head;
        while(rhead){
            auto nxt = ptr -> next;
            ptr -> next = rhead;
            rhead = rhead ->next;
            ptr -> next -> next = nxt;
            ptr = nxt;
        }
        return ;
    }
};