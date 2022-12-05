#include <bits/stdc++.h>
using namespace std;
/*
    a.b : a is class b is method ;
    a-> : a is pointer to a class (*a).b
*/


int main(){
    vector<int> a[]={{2,3,4},{2}};
    // here a is a pointer pointing to a[0] means vector<int> or a container or class(Vector)
    // cout<<a.size();
    cout<<a->size();

    int a[] = {1,2};
    // a is a pointer pointing to a int type
    // type of a is int*
    // cout<<a.size();
    cout<<sizeof(a)/sizeof(int);
}