/*********************************************************************************************

Question :
What is the time complexity of the following code snippet in C++?

Notes :
 The s = s + s[i] line first makes a copy of the original string and then appends the new character in it, leading to each operation being O(n). So the total time complexity is O(n^2).
**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
void solve() {
   string s = "scaler";
   int n = s.size();
   for(int i = 0; i < n; i++) {
       s = s + s[i];
   }
   cout << s << endl;
}

int main()
{
}