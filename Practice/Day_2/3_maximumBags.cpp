#include<bits/stdc++.h>
using namespace std;
int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int maxbags=0;
        int rockcnt=additionalRocks;
        vector<int> diff(rocks.size());
        for(int j=0;j<rocks.size();j++){
            diff[j]=capacity[j]-rocks[j];
        }
        for(int j=0;j<diff.size();j++){
            cout<<diff[j]<<" ";
        }
        cout<<endl;
        sort(diff.begin(),diff.end());
        for(int j=0;j<diff.size();j++){
            cout<<diff[j]<<" ";
        }
        cout<<endl;
        int i=0;
        while(i<rocks.size()&&rockcnt>0){
           while(diff[i]!=0 && rockcnt>0 ){
            diff[i]--;
            rockcnt--;
            cout<<diff[i]<<" "<< rockcnt<<endl;
        }
            i++;
        cout<<"i is : "<<i<<endl<<endl;
        }
        if(rockcnt>0) return i;
        else return i-1;
    }
int main(){
    int a =2;
    vector <int> nums={2,3,4,5};
    vector <int> nums2={1,2,4,4};
    
    cout<<"ans is: "<<maximumBags(nums,nums2,a);
}