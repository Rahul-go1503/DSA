/********************************************************************************************* 
 
Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
string convertToTitle(int columnNumber) {
        string ans;
        unordered_map<int, char> m = {{1, 'A'}, {2, 'B'}, {3, 'C'}, {4, 'D'}, {5, 'E'}, {6, 'F'}, {7, 'G'}, {8, 'H'}, {9, 'I'}, {10, 'J'}, {11, 'K'}, {12, 'L'}, {13, 'M'}, {14, 'N'}, {15, 'O'}, {16, 'P'}, {17, 'Q'}, {18, 'R'}, {19, 'S'}, {20, 'T'}, {21, 'U'}, {22, 'V'}, {23, 'W'}, {24, 'X'}, {25, 'Y'}, {0, 'Z'}};
        while(columnNumber){
        int digit = columnNumber%26;
        ans.push_back(m[digit]);
        if(columnNumber%26==0) columnNumber-=1;
        columnNumber/=26;
        }
        reverse(ans.begin(),ans.end());
     return ans;
    }
    

/********************************************************************************************* 
 
for String ABZ and its corresponding number n:
n = (A+1) * 26^2 + (B+1) * 26^1 + (Z+1) * 26^0

both sides -1
n-1 = (A+1) * 26^2 + (B+1) * 26^1 + Z

(n-1)%26 =  Z                                                  (1)
(n-1)/26 = (A+1) * 26^1 + (B+1) * 26^0

**********************************************************************************************/
    string convertToTitle2(int n) {
        string ans;
        while(n > 0) {
            n--;
            int curr = n % 26;
            n = n / 26;
            ans.push_back(curr + 'A');
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }

string convertToTitle(int n){
        string res;
        char tmp;
        while (n)
        {
            n -= 1;
            tmp = 'A' + n % 26;
            res = tmp + res;
            n /= 26;
        }
        return res;
        }