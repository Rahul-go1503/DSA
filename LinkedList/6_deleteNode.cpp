/*********************************************************************************************

Question :


Notes :

**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void deleteNode(Node* &head,int pos){
    if(!head) return;
    auto temp = head;
    if(pos==0){
        head= temp->next;
        delete temp;
        return;
    }
    for(int i=0;temp!=NULL&&i<pos;i++){
        temp=temp->next;
    }
    if(temp==NULL || temp->next==NULL){
        return;
    }
    auto next= temp->next->next;
    delete temp->next;
    temp->next =next;
    return;
}

void deleteNode(Node** head_ref, int position)
{
 
    // If linked list is empty
    if (*head_ref == NULL)
        return;
 
    // Store head node
    Node* temp = *head_ref;
 
    // If head needs to be removed
    if (position == 0) {
 
        // Change head
        *head_ref = temp->next;
 
        // Free old head
        free(temp);
        return;
    }
 
    // Find previous node of the node to be deleted
    for (int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;
 
    // If position is more than number of nodes
    if (temp == NULL || temp->next == NULL)
        return;
 
    // Node temp->next is the node to be deleted
    // Store pointer to the next of node to be deleted
    Node* next = temp->next->next;
 
    // Unlink the node from linked list
    free(temp->next); // Free memory
 
    // Unlink the deleted node from list
    temp->next = next;
}