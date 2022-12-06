#include <bits/stdc++.h>
using namespace std;

// Link - https://www.geeksforgeeks.org/stl-priority-queue-for-structure-or-class/ 
class Node {
public:
    // variable should be public
    int x; int y; int d;
    Node(int dis,int i ,int j){
        d=dis;
        x=i;
        y=j;
    }
};
// For min- heap carefull operator should be >
bool operator>(const Node& n1, const Node& n2)
{
 
    // this will return true when second Node
    // has lesser dis.The object which
    // have min dis will be at the top(or
    // min priority)
    return n1.d > n2.d;
}
// For max heap 
bool operator<(const Node& n1, const Node& n2)
{
 
    // this will return true when second Node
    // has greater dis.The object which
    // have max dis will be at the top(or
    // max priority)
    if(n1.d==n2.d){
        if(n1.x==n2.x){
            return n1.y < n2.y;
        }
        return n1.x < n2.x;
    }
    return n1.d < n2.d;
}
int main(){
    // For min - heap
    priority_queue<Node,vector<Node>,greater<Node>> mn;
    // For max - heap
    priority_queue<Node> mx;
    mx.push(Node(4,5,7));
    mx.push(Node(4,5,6));
    mx.push(Node(1,2,3));

    mn.push(Node(4,5,6));
    mn.push(Node(6,5,6));
    mn.push(Node(1,2,3));

    cout<<mx.top().y<<endl;
    cout<<mn.top().y<<endl;
}