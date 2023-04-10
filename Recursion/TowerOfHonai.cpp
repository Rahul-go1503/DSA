#include<iostream>
using namespace std;
class Solution{
    public:
    // You need to complete this function

    // avoid space at the starting of the string in "move disk....."
    long long toh(int N, int from, int to, int aux) {
        if(N==1){
            cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<endl;
            return 1;
        }
        long long cnt = 1;
        cnt += toh(N-1,from,aux,to);
        cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<endl;
        cnt += toh(N-1,aux,to,from);
        return cnt;
    }

};