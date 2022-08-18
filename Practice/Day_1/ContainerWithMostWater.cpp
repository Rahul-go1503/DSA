#include<iostream>
#include<vector>
using namespace std;

// TLE
int maxArea(vector<int>& height) {
    int maxWater=0;
        for(int i=0;i<height.size();i++){
            for(int j=i+1;j<height.size();j++){
              int temp= min(height[i],height[j])*(j-i);
              if(temp>maxWater) maxWater =temp; 
            }
        }
        return maxWater;
    }
// solution
int maxArea2(vector<int>& height) {
    int water = 0;
    int i = 0, j = height.size() - 1;
    while (i < j) {
        int h = min(height[i], height[j]);
        water = max(water, (j - i) * h);
        while (height[i] <= h && i < j) i++;
        while (height[j] <= h && i < j) j--;
    }
    return water;
}
int main(){
    int n;
    cin>>n;
    vector<int> height (n,0);
    for(int i=0;i<height.size();i++){
        cin>>height[i];
    }
    for(int i=0;i<height.size();i++){
        cout<<height[i]<<" ";
    }
    cout<<endl;
    cout<<maxArea(height)<<endl;
}