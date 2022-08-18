#include <bits/stdc++.h>
using namespace std;
void print(vector<int> &v){
    for(int i=0;i<v.size();i++){
    cout<<v[i]<<" ";
    }
    cout<<endl;
}
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for (auto n : nums2) {
            auto itr=find(nums1.begin(),nums1.end(),n);
            if(itr!=nums1.end()){
                ans.push_back(n);
                nums1.erase(itr);
            }
        }
        return ans;
}

int main(){
    vector<int> n1={0};
    vector<int> n2={2,2,4};
    vector<int> ans= intersect(n1,n2);
    print(ans);
}