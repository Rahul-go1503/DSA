#include <bits/stdc++.h>
using namespace std;

// Link - https://www.geeksforgeeks.org/stl-priority-queue-for-structure-or-class/ 
struct Node {
    int x; int y; int d;
    Node(int dis,int i ,int j){
        d=dis;
        x=i;
        y=j;
    }
};
struct cmp {
    // for both min and max
    bool operator()(const Node& n1, const Node& n2)
    {
        // dono me se kisko top par rkhna hai

        // agar dusra bda hai to use top par rkh do (true case) 
        return n1.d < n2.d;
    }
};

int main(){
    // For both min and max heap
    priority_queue<Node,vector<Node>,cmp> pq;

    pq.push(Node(4,5,6));
    pq.push(Node(6,5,6));
    pq.push(Node(10,2,3));

    cout<<pq.top().y<<endl;
    cout<<pq.top().d<<endl;
}