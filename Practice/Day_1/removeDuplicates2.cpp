#include<iostream>
#include<vector>
using namespace std;
int removeDuplicates(vector<int>& nums) {
        int i=0; int cnt =1;
        for (int j=1;j<nums.size();j++){
            // cout<<nums[i]<<" ";
            cout<<"Before entering-"<<nums[j]<<nums[i]<<endl<<endl;
            if(nums[j]!=nums[i]){
                cout<<"inside 1st \n"<<endl;
                nums[++i]=nums[j];
                cnt=1;
            }
            else if(nums[j]== nums[i] && cnt==1){
                cout<<"inside 2nd \n"<<endl;
                nums[++i]=nums[j];
                cnt=2;
            }
        }
        cout<<endl;
        return i+1;
    }

    // 2nd solution ---StefanPochmann
    int removeDuplicates2(vector<int>& nums) {
    int i = 0;
    for (int n : nums)
        if (i < 2 || n > nums[i-2])
            nums[i++] = n;
    return i;
}
int main(){
    vector<int> nums ={0,0,1,1,1,1,2,3,3};
    int ans=removeDuplicates2(nums);
    for(int i=0;i<ans;i++){
        cout<<nums[i]<<" ";
    }cout<<endl;
    cout<<"ans is : "<<ans<<endl;
}