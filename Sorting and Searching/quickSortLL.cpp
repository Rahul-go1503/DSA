#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
};

//you have to complete this function
struct node* partition(struct node *low, struct node * high){
    int pivot = low->data;
    auto i = low;
    for(auto j = low->next; j!= high ; j = j->next){
        if(j->data < pivot){
            i = i->next;
            swap(i->data,j->data);
        }
    }
    swap(low->data,i->data);
    return i;
}
void solve(struct node *head, struct node * end){
    if(head==end || head->next==end) return;
    auto pi = partition(head,end);
    solve(head,pi);
    solve(pi->next,end);
}
void quickSort(struct node **headRef) {
    node* head = *headRef;
    solve(head,NULL);
}