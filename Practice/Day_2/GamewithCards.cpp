#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n;
        int* a=new int[n];

        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        cin>>m;
        int* b=new int[m];

        for(int i=0;i<m;i++){
            cin>>b[i];
        }
        sort(a, a+n);
        sort(b, b+m);
        int game=1;
        while(game<=2)
        {
            bool Bmove=true;
            int i=0, j=0;
            if(game==2){
                Bmove=false;
            }
            while(i<n&&j<m)
            {
                while(!Bmove&&i<n&&j<m){
                    if(a[i]>b[j]){
                        Bmove=true;
                        j++;
                    }
                    else i++;
                }
                while(Bmove&&i<n&&j<m){
                    if(b[j]>a[i]){
                        Bmove=false;
                        i++;
                    }
                    else j++;
                }


            }
            if(j>=m&&i<n){
                cout<<"Alice"<<endl;
            }
            if(i>=n&&j<m){
                cout<<"Bob"<<endl;
            }
            game++;
        }


    }
}