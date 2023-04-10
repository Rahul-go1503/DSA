# stable_partition
    vector<int> v{ 6, 9, 0, 1, 2, 7, 5, 8, 0 };
	stable_partition(v.begin(), v.end(), [](int n) {return n>4; });

# sort
https://www.geeksforgeeks.org/sort-c-stl/


# sliding window
https://leetcode.com/problems/minimum-window-substring/solutions/26808/here-is-a-10-line-template-that-can-solve-most-substring-problems/

# GCC inbuilt function
int __builtin_clz(int x);
int __builtin_ctz(int x);
int __builtin_popcount(int x);