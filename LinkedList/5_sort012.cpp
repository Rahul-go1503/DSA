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
ListNode* sort012(ListNode* head) {
    auto temp= head;
    auto temp2= head;
    int zeros=0,ones=0,twos=0;
    while(temp){
        switch(temp->val){
            case 0 :
                zeros++;
                break;
            case 1 :
                ones++;
                break;
            case 2 :
                twos++;
                break;
        }
        temp=temp->next;
    }
    
    while(zeros){
        temp2->val=0;
        temp2=temp2->next;
    }
    while(ones){
        temp2->val=1;
        temp2=temp2->next;
    }
    while(twos){
        temp2->val=2;
        temp2=temp2->next;
    }

    return head;        
}
void sortList(ListNode *head)
{
    int count[3] = {0, 0, 0}; // Initialize count of '0', '1' and '2' as 0
    ListNode *ptr = head;
 
    /* count total number of '0', '1' and '2'
    * count[0] will store total number of '0's
    * count[1] will store total number of '1's
    * count[2] will store total number of '2's */
    while (ptr != NULL)
    {
        count[ptr->val] += 1;
        ptr = ptr->next;
    }
 
    int i = 0;
    ptr = head;
 
    /* Let say count[0] = n1, count[1] = n2 and count[2] = n3
    * now start traversing list from head node,
    * 1) fill the list with 0, till n1 > 0
    * 2) fill the list with 1, till n2 > 0
    * 3) fill the list with 2, till n3 > 0 */
    while (ptr != NULL)
    {
        if (count[i] == 0)
            ++i;
        else
        {
            ptr->val = i;
            --count[i];
            ptr = ptr->next;
        }
    }
}