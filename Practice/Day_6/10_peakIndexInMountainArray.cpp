#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> & arr,int s , int e){
    if(s>=e) return s;
    int mid= s+(e-s)/2;
    if(arr[mid]<arr[mid+1]){
        return solve(arr,mid+1,e);
    }else{
        return solve(arr,s,mid);
    }
}
int peakIndexInMountainArray2(vector<int>& arr) {
        return solve(arr,0,arr.size()-1);
}
int peakIndexInMountainArray(vector<int>& arr) {
        int s=0;
        int e=arr.size()-1;
        while(s<e){
            int mid=s+(e-s)/2;
            if(arr[mid]>arr[mid+1]) e=mid;
            else s=mid+1;
        }
        return s;
}

int main(){
    vector<int> n ={10,9,18,6,4,2,1};
    cout<<peakIndexInMountainArray(n)<<endl;
}