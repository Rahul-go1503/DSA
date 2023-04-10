#include<bits/stdc++.h>
using namespace std;

int isCyclicRotation(string &p, string &q) 
{
    p += p;
    char *c_p = &p[0], *c_q = &q[0];
    auto t =  strstr(c_p,c_q);
    if(t) return 1;
    else return 0;
}