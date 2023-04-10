#include <iostream>
using namespace std;
// brian kerningam's algo
int main() {
	int t;
	cin>>t;
	while(t--){
		int n,cnt = 0;
		cin>>n;
		while(n) n &= n-1,cnt++;
		cout<<cnt<<endl;
	}
}

// leetcode
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while(n){
            if(n&1) cnt++;
            n >>= 1;
        }
        return cnt;
    }
};

class Solution {
public:
    int hammingWeight(uint32_t n) {
        return __builtin_popcount(n);
    }
};

// hamming distance
class Solution {
public:
    int hammingDistance(int x, int y) {
        return __builtin_popcount(x^y);
    }
};