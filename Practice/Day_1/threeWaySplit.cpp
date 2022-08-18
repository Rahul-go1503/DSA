#include<iostream>
#include<vector>
using namespace std;
long long threeWaySplit(int n, vector<int> arr){
    // Write your code here.
    int i=0;
    int j=n-1;
    long long s1=arr[i];
    long long s3=arr[j];
    long long maxSum=0;
    while(i<j){
        if(s1==s3 && i<n && j>=0){
            maxSum=max(maxSum,s1);
            s1+=arr[++i];
            s3+=arr[--j];
        }
        else if(s1>s3 && i<n && j>=0){
            s3+=arr[--j];
        }else{
            s1+=arr[++i];
        }
    }
    return maxSum;
}
int main(){
    int n,t;
    cin>>n;
    cout<<"hello";
    vector<int> arr;
    for(int i=0;i<n;i++){
        cin>>t;
        arr.push_back(t);
    }
    cout<<"ans is : "<< threeWaySplit(n,arr);
}