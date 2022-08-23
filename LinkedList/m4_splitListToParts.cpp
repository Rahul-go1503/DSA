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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n=0;
        auto temp = head;
        while(temp){
            n++;
            temp=temp->next;
        }
        int size = n/k;
        int ext = n%k;
        vector<ListNode*> ans;
        temp=head;
        while(temp&&ext){
            ans.push_back(temp);
            for(int i=0;i<size;i++) temp=temp->next;
            auto nxt = temp->next;
            temp->next=NULL;
            temp=nxt;
            ext--;
        }
        if(size==0){
            for(int i=0;i<k-n;i++) ans.push_back(NULL);
        }
        while(temp){
            ans.push_back(temp);
            for(int i=0;i<size-1;i++) temp=temp->next;
            auto nxt = temp->next;
            temp->next=NULL;
            temp=nxt;
        }
        return ans;
    }
};
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> parts(k, nullptr);
        int len = 0;
        for (ListNode* node = root; node; node = node->next)
            len++;
        int n = len / k, r = len % k; // n : minimum guaranteed part size; r : extra nodes spread to the first r parts;
        ListNode* node = root, *prev = nullptr;
        for (int i = 0; node && i < k; i++, r--) {
            parts[i] = node;
            for (int j = 0; j < n + (r > 0); j++) {
                prev = node;
                node = node->next;
            }
            prev->next = nullptr;
        }
        return parts;
    }
};