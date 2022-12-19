#include <bits/stdc++.h>
using namespace std;

/*
Hashing + DSU
TC - O(n)
https://leetcode.com/problems/longest-consecutive-sequence/solutions/127576/longest-consecutive-sequence/
*/

/*
This solution is really helpful for streaming use-case of the problem where we have to find longest 
consecution sequence after every new insertion
*/
class DisjointSet{
    int mx = 1;
    unordered_map<int,int> size,parent;
    // vector<int> size, parent;
public:
    DisjointSet(){
        // size.resize(n+1,1);
        // parent.resize(n+1);
        // for(int i=0;i<n+1;i++) parent[i]=i;
    }
    void addNode(int node){
        parent[node] = node;
        size[node] = 1;
    }
    int findPar(int node){
        if(node==parent[node]) return node;
        return parent[node] = findPar(parent[node]);
    }

    void unionBySize(int u, int v){
        int pu = findPar(u) , pv = findPar(v);
        cout<<pu<<" "<<pv<<endl;
        if(pu==pv) return;

        if(size[pu]<size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
            mx = max(mx, size[pv]);
        }
        else{
            parent[pv] = pu;
            size[pu] +=size[pv];
            mx = max(mx, size[pu]);
        }
    }
    int maxLength(){ return mx;}
};
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        unordered_set<int> s;
        DisjointSet ds;

        for(auto &num : nums){
            if(s.count(num)) continue;
            ds.addNode(num);
            s.insert(num);
            if(s.count(num+1)) ds.unionBySize(num,num+1);
            if(s.count(num-1)) ds.unionBySize(num,num-1);
        }

        return ds.maxLength();
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        for(int i=0;i<n;i++) s.insert(nums[i]);
        // num -> streak
        unordered_map<int,int> mp; // can optimize if we look in both dirn then no need to store streak 

        int mx = 0, curr = 0;
        while(s.size()){
            int num = *s.begin();
            curr = 1;
            int temp = num + 1;
            s.erase(num);
            while(s.count(temp)){
                curr++;
                s.erase(temp);
                temp++;
            }
            if(mp.find(temp) != mp.end()) curr += mp[temp];
            mp[num] = curr;

            mx = max(mx,curr);
        }

        return mx;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> record(num.begin(),num.end());
        int res = 1;
        for(int n : num){
            if(record.find(n)==record.end()) continue;
            record.erase(n);
            int prev = n-1,next = n+1;
            while(record.find(prev)!=record.end()) record.erase(prev--);
            while(record.find(next)!=record.end()) record.erase(next++);
            res = max(res,next-prev-1);
        }
        return res;
    }
};