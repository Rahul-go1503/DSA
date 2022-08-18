/********************************************************************************************* 
 
Question : 


Notes : 

**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        string a,b,c;
        cin>>a>>b;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int i=0,j=0,op1=0,op2=0;
         while(i<n&&j<m){
            if(a[i]<=b[j]){
                if(op1<k){
                    op2=0;
                    c.push_back(a[i++]);
                    op1++;
                }else{
                    op1=0;
                    c.push_back(b[j++]);
                    op2++;
                }
            }else{
                if(op2<k){
                    op1=0;
                    c.push_back(b[j++]);
                    op2++;
                }else{
                    op2=0;
                    c.push_back(a[i++]);
                    op1++;
            }
         }
    }
        cout<<c<<endl;
}
}

void solve()
{
	int n, m, k;
	cin >> n >> m >> k;
	string a, b, c;
	cin >> a >> b;
	sort(all(a)), sort(all(b));
	int p = 0, q = 0;
	int c1 = 0, c2 = 0;
	while (p < n && q < m) {
		if (c1 < k && (a[p] < b[q] || c2 == k)) {
			c2 = 0;
			c1++;
			c += a[p];
			p++;
		}else{
			c1 = 0;
			c2++;
			c += b[q];
			q++;
		}
	}
	cout << c << '\n';
}