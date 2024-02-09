#include<bits/stdc++.h>
using namespace std;

// Range Sum Queries
class SegTree{
public:
    vector<int> seg,arr;
    SegTree(int n, vector<int> &a){
        seg.resize(4*n+1);
        arr = a;
    }

    void build(int i, int low, int high){
        if(low==high){
            seg[i] = arr[low];
            return;
        }
        int mid = low + (high - low)/2;
        build(2*i+1,low,mid);
        build(2*i+2,mid+1,high);
        seg[i] = seg[2*i+1] + seg[2*i+2];
    }

    void update(int i, int low, int high, int ind, int val){
        if(low==high){
            seg[i] = val;
            return;
        }
        int mid = low + (high - low)/2;
        if(ind<=mid) update(2*i+1,low,mid,ind,val);
        else update(2*i+2,mid+1,high,ind,val);
        seg[i] = seg[2*i+1] + seg[2*i+2];
    }

    int query(int i, int low, int high, int l, int r){
        if(r<low || high < l) return 0;
        if(low >= l && high <= r) return seg[i];

        int mid = low + (high-low)/2;
        int left = query(2*i+1,low,mid,l,r);
        int right = query(2*i+2,mid+1,high,l,r);

        return left + right;
    }

};