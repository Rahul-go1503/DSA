#include <bits/stdc++.h>
using namespace std;
int solve(int x, int s, int e)
{
        if (s > e)
                return e;
        long long int mid = s + (e - s) / 2;
        cout << "enter " << mid << endl;
        // mid=min(mid,INT_MAX);
        if (mid * mid == x)
                return mid;
        if (mid * mid > x)
                return solve(x, s, mid - 1);
        else
                return solve(x, mid + 1, e);
}
int mySqrt(int x)
{
        return solve(x, 0, x);
}
int mySqrt2(int x)
{
        long r = x;
        while (r * r > x)
                r = (r + x / r) / 2;
        return r;
}
int main()
{
        int x = 2147395599;
        cout << mySqrt(x) << endl;
}