#include<bits/stdc++.h>
using namespace std;

class twoStack{
    private:
    int * arr;
    int head1;
    int head2;
    int size;
    public:
        twoStack(int n){
            size=n;
            head1=-1;
            head2=n;
            arr =new int[n];
        }
        void push1(int n){
            if(head1<head2-1){
                arr[++head1]=n;
            }
        }
        void push2(int n){
            if(head1<head2-1){
                arr[--head2]=n;
            }
        }
        void pop1(){
            if(head1>=0) head1--;
        }
        void pop2(){
            if(head2<size) head2++;
        }
};