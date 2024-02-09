#include<bits/stdc++.h>
using namespace std;
const int N = 10005;
vector<string> mat(N) , par(N, string(N,'#'));
int dis[N][N];
struct Node
{
    int x, y;
    Node(){}
    Node(int a, int b) : x(a), y(b) {}
};
queue<Node> pq;
int bfs(int n, int m){
    int lv = -1;
    while(pq.size()){
        int sz = pq.size();
        lv++;
        while(sz--){
            auto p = pq.front();
            pq.pop();

            int i = p.x, j = p.y;
            int dir[] = {-1,0,1,0,-1};
            for(int d=0;d<4;d++){
                int x = i + dir[d];
                int y = j + dir[d+1];
                if(x<0 || y<0 || x>=n || y>=m || mat[x][y] != '.') continue;
                dis[x][y] = lv + 1;
                mat[x][y] = '#';
                pq.push(Node(x,y));
            }
        }
    }
    return -1;
}

int check(int n, int m){
    int lv = -1;
    while(pq.size()){
        int sz = pq.size();
        lv++;
        while(sz--){
            auto p = pq.front();
            pq.pop();

            int i = p.x, j = p.y;
            int dir[] = {-1,0,1,0,-1};
            string path = "URDL";
            for(int d=0;d<4;d++){
                int x = i + dir[d];
                int y = j + dir[d+1];
                if(x<0 || y<0 || x>=n || y>=m || dis[x][y] <= lv + 1) continue;
                dis[x][y] = lv + 1;
                mat[x][y] = '#';
                pq.push(Node(x,y));
            }
        }
    }
    return -1;
}
int main(){
    int r,c;
    cin>>r>>c;
    Node A;
    for(int i=0;i<r;i++){
        string s;
        cin>>s;
        for(int j=0;j<c;j++){
            if(s[j]=='A'){
                A = Node(i,j);
            }
            else if(s[j] == 'M'){
                pq.push(Node(i,j));
            }
        }
        mat[i] = s;
    }

    bfs(r,c);
    pq.push(A);
    int dis = check(r,c);
    if(dis==-1){
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl<<dis<<endl;

}
