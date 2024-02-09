#include<bits/stdc++.h>
using namespace std;

class BIT { // One-based indexing
    vector<int> bit;
public:
    BIT(int size=0) {
        bit.resize(size + 1);
    }
    int getSum(int idx) { // Get sum in range [1..idx]
        int sum = 0;
        for (; idx > 0; idx -= idx & (-idx))
            sum += bit[idx];
        return sum;
    }
    void addValue(int idx, int val) {
        for (; idx < bit.size(); idx += idx & (-idx))
            bit[idx] += val;
    }
};