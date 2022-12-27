#include <bits/stdc++.h>
using namespace std;

/*
My understanding of Newton's method:

Given y = f(x), find the root x such that f(x) = 0, geometrically
speaking, find the intersection of the function y and the x-axis.

For a roughly estimated root x0, it's coordinate on the function
is P(x0, f(x0)). We can find P's tangent line L whose slope is m,
such that the intersection of the L and the x-axis, say S(x1, 0),
it's function value f(x1) is closer to the real root of y = f(x),
comparing to the f(x0).

Set m = f'(x0), where f' denotes the differential on x0 ... (1)
The slope m is defined by PS: m = (f(x0) - 0) / (x0 - x1) ... (2)
Combine (1) (2), f'(x0) = f(x0) / (x0 - x1)
=> x0 - x1 = f(x0) / f'(x0)
=> x1 = x0 - f(x0) / f'(x0)
x(n+1) = x(n) - f(x(n)) / f'(x(n))
 
 By applying Newton's method to the root problem, finding the
r such that r^2 equals to the input x is the same as finding the
root of f(r) where

f(r) = r^2 - x = 0
=> r(n+1) = r(n) - f(r(n)) / f'(r(n))
=> r(n+1) = r(n) - (r(n)^2 - x) / 2 * r(n)
=> r(n+1) = r(n) - r(n) / 2 + x / 2 * r(n)
=> r(n+1) = (r(n) + x / r(n)) / 2

The pseudo recursive code:

while ( r^2 - x > 0) {
    r = ( r + x / r ) / 2
}
*/
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