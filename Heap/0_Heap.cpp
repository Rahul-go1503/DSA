#include <bits/stdc++.h>
using namespace std;

class Heap{
    vector<int> arr;
public:
    void heapify(int i){

    }

    void buildHeap(vector<int> arr,int i){

    }
    void insert(int n){
        arr.push_back(n);
        int i = arr.size()-1;
        while(i>0){
            int par = (i-1)/2;
            if(arr[par] < arr[i]){
                swap(arr[i],arr[par]);
                i = par;
            }else return;
        }
    }

    void deleteNode(int i){
        int e = arr.size()-1;
        swap(arr[i],arr[e]);
        arr.pop_back();
        heapify(i);
    }
};

// O(logn)
void maxHeapify(int arr[], int n, int i){
    // boundary check
    if(i>=n) return;

    int l = 2*i + 1;
    int r = 2*i + 2;

    int mx = i;
    if(l<n && arr[mx]<arr[l]) mx = l;
    if(r<n && arr[mx]<arr[r]) mx = r;

    // if changes happen
    if(mx != i){
        swap(arr[mx],arr[i]);
        maxHeapify(arr,n,mx); // since mx index is distored;
    }
}

// O(n)
void buildMaxHeap(int arr[],int n){
    for(int i=n/2-1;i>=0;i--) maxHeapify(arr,n,i);
}