#include<iostream>
using namespace std;

void merge2(int arr[], int s ,int m ,int e){

    int * temp = new int[e-s+1] ;
    int i = s, j = m+1,k=0;

    while(i<=m && j<=e){
        if(arr[i]<=arr[j]) temp[k++]= arr[i++];
        else temp[k++] = arr[j++];
    }
    while(i<=m) temp[k++] =arr[i++];
    while(j<=e) temp[k++] = arr[j++];
    int idx = s;
    for(int i=0;i<e-s+1;i++){
        arr[idx++]=temp[i];
    }
    // copy(temp,temp+e-s+1,arr);
    delete[] temp;
}

void merge(int arr[], int s, int m , int e){
    int *f = new int[m-s+1];
    int *sa = new int[e-m];
    int i=0, j=0;
    for(int idx=s;idx<=m;idx++) f[i++] = arr[idx];
    for(int idx=m+1;idx<=e;idx++) sa[j++] = arr[idx];
	i=0; j=0;int k=s;
    while(i<m-s+1 && j<e-m){
        if(f[i]<=sa[j]) arr[k++]=f[i++];
        else arr[k++] = sa[j++];
    }
    while(i<m-s+1) arr[k++]= f[i++];
    while(j<e-m) arr[k++] = sa[j++];

    delete []f;
    delete[]sa;
}

void mergeSort(int arr[], int s, int e){
    // at least 2 elem
    if(s>=e) return;

    int mid = (s+e)/2 ;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);

    merge(arr,s,mid,e);
}
int main(){
    int arr[] = {12, 11,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"sorted array is: "<<endl;
    mergeSort(arr,0,size-1);
    for(int i=0;i<size;i++) cout<<arr[i]<<" ";
    cout<<endl;
}