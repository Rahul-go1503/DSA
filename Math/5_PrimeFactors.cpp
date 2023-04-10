#include <bits/stdc++.h>
using namespace std;

/*
TC- O(n*sqrt(n))
all primes greater than 3 are of the form 6k ± 1, where k is any integer greater than 0.
*/
//n>=1
bool isPrime(int n){
    if(n==2 || n==3) return true;
    if(n<=1 || n%2==0 || n%3==0) return false;

    for(int i=5; i*i<n; i = i+6){
        if(n%i == 0 || n%(i+2)==0) return false;
    }
    return true;
}
vector<int> PrimeFactor(int n){
    vector<int> fac;

    for(int i=2; i<=n; i++){
        if(isPrime(i))  fac.push_back(i);
    }
    return fac;
}

vector<int> PrimeFactors(int n){
    if(n==1) return {};
    vector<int> pf;
    for(int i=2;i*i<=n;i++){
        while(n%i==0){
            pf.push_back(i);
            n /= i;
        }
    }
    if(n>1) pf.push_back(n);
    return pf;
}