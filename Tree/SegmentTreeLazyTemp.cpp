#include<bits/stdc++.h>
using namespace std;

// Range Update Query - SUM
class SegTree{
    vector<int> seg, lazy;
    vector<int> arr;
public:
    SegTree(int n, vector<int> &a){
        seg.resize(4*n);
        lazy.resize(4*n);
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
private:
    void updateLazy(int i, int low, int high){
        if(lazy[i]!=0){
            seg[i] += (high - low + 1)*lazy[i];
            if(low != high){
                lazy[2*i + 1] += lazy[i];
                lazy[2*i + 2] += lazy[i];
            }
            lazy[i] = 0;
        }

    }
public:
    void update(int i, int low, int high, int l, int r, int val){
        updateLazy(i,low,high);
        if(r < low || high < l) return;
        if(low >=l && high <= r){
            lazy[i] = val;
            updateLazy(i,low,high);
            return;
        }
        int mid = low + (high - low)/2;

        update(2*i+1,low,mid,l,r,val);
        update(2*i+2,mid+1,high,l,r,val);
        seg[i] = seg[2*i+1] + seg[2*i+2];
    }

    int query(int i, int low, int high, int l, int r){
        updateLazy(i,low,high);
        if(low == high) return seg[i];

        int mid = low + (high - low)/2;
        int left = query(2*i+1, low, mid, l, r);
		int right = query(2*i+2, mid+1, high, l, r);
		return left + right;
    }
};