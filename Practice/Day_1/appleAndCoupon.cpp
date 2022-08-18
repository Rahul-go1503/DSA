#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long appleAndCoupon(int n, int m, vector<int> arr){
    // Write your code here.
    long long sum=0;
    sort(arr.begin(), arr.end());
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    return sum-arr[n-m];
}

int main(){
    int n, m, temp; vector<int> arr;

    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>temp;
        arr.push_back(temp);
    }
    cout<<appleAndCoupon(n, m, arr)<<endl;
}

