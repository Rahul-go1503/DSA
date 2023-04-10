#include <bits/stdc++.h>
using namespace std;

/*
 - https://leetcode.com/problems/insert-delete-getrandom-o1/solutions/85422/ac-c-solution-unordered-map-vector/?orderBy=most_votes
 - go through from discussion

        rand() function gives random value in the range of 0 to RAND_MAX(whose value is 32767). x%y gives 
 	    remainder when x is divided by y and this remainder is in the range of 0 to y-1.
	    rand()%a.size() gives random value in the range of (0 to a.size()-1).
	    a[rand()%a.size()] will give random value of array in the range of a[0] to a[a.size()-1].
*/
class RandomizedSet {
        vector<int> nums; // for get random in O(1)
        unordered_map<int,int> mp; // num -> index of num in vector
public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(mp.count(val)) return false;
        nums.push_back(val);
        mp[val] = nums.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(!mp.count(val)) return false;
        int last = nums.back(); // last elm

        mp[last] = mp[val]; // last elem ka index abhi jo remove kr rhe hai usse update kra
        nums[mp[val]] = last; // uss index par last elem ko rkh diya

        mp.erase(val);
        nums.pop_back();
        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */