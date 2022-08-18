#include <bits/stdc++.h> 
using namespace std;
vector<pair<int,int>> twoSum(vector<int>& arr, int target, int n)
{
    sort(arr.begin(),arr.end());
    vector<pair<int,int>> ans;
    int i =0;int j=n-1;
    while(i<j){
        if(arr[i]==target-arr[j]){
            ans.push_back({arr[i++],arr[j--]});
        }else if(arr[i]>target-arr[j]) j--;
        else i++;
    }
    if(ans.empty()) ans.push_back({-1,-1});
    return ans;

}


// using hashmap O(N) + S.C - O(N)

/*
	Time Complexity: O(N)
	Space Complexity: O(N)

	Where 'N' is the total number of elements in the array.
*/

vector<pair<int, int>> twoSum(vector<int>& arr, int target, int n)
{
	unordered_map<int, int> hashMap;

	vector<pair<int, int>> ans;
	
	for(int i = 0; i < n; i++)
	{
        hashMap[arr[i]]++;
        
		if(target - arr[i] == arr[i])
		{
			// Valid pair will only exist if frequency of arr[i] is greater than 1.
			if(hashMap[arr[i]] > 1)
			{
				ans.push_back({arr[i], arr[i]});

				// Frequency will decrease by 2.
				hashMap[arr[i]] -= 2;
			}
		}
		else
		{
			// For a valid pair frequency of arr[i] and target-arr[i] must be greater than 0.
			if(hashMap[arr[i]] > 0 && hashMap[target - arr[i]] > 0)
			{
				ans.push_back({arr[i], target - arr[i]});

				// Frequency will decrease by 1.
				hashMap[arr[i]] -= 1;
				
				hashMap[target - arr[i]] -= 1;
			}
		}
	}

	// If no valid pair exists.
	if(ans.size() == 0)
	{
		ans.push_back({-1, -1});
	}
	
	return ans;
}
