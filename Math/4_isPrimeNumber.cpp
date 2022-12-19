#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/prime-numbers/
/*
TC- O(sqrt(n))
all primes greater than 3 are of the form 6k ± 1, where k is any integer greater than 0.

We need to check factors upto √n not till n. The resaon is suppose n has 2 factors and both are bigger than √n. 
Then n would be bigger than  n , which is absurd! So n has at least one factor smaller than √n if it isn’t prime.

agr sqrt(n) tak hi koi factor nhi mila to aage kese mil skta hai means prime hai... aage milta hai to iska matlab ek factor ise
phle bhi hona chaiye tha
*/

bool isPrime(int n){
    if(n==2 || n==3) return true;
    if(n<=1 || n%2==0 || n%3==0) return false;

    for(int i=5; i*i<n; i = i+6){
        if(n%i == 0 || n%(i+2)==0) return false;
    }
    return true;
}