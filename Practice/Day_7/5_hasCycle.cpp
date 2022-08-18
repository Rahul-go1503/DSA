#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    unordered_map<ListNode*,bool> m;
    ListNode *temp = head;
    if(!temp||!temp->next) return false;
    while(temp->next){
        if(m[temp]) return true;
        else m[temp]= true;
        temp=temp->next;
    }
    return false;
}

bool hasCycle(ListNode *head) {
    ListNode *slow = head;
    if(!slow||!slow->next) return false;
    ListNode *fast = slow->next;
    while(slow!=fast && fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    if(slow==fast) return true;
    else return false;
}

// less compare
bool hasCycle3(ListNode *head)
    {
        auto walker = head, runner = head;
        while (runner && runner->next)
        {
            walker = walker->next;
            runner = runner->next->next;
            if (walker == runner)
                return true;
        }
        return false;
    }