/*********************************************************************************************

Question :


Notes :

**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
int main(){
    int * ipt = new int;   // create new pointer-to-int

cout << ipt << endl;   // 0x200102a0, so pointer ipt points to address 0x200102a0
cout << *ipt << endl;  // 0, so the value at that address for now is 0. Ok, nothing was assigned
*ipt = 1000;     // assign a value to that memory address
cout << *ipt << endl;   // read the new value, it is 1000, ok
cout << *((int *) 0x200102a0) << endl;   // read exactly from the address, 1000 too

delete ipt;   // now I do delete and then check
cout << ipt << endl;  // 0x200102a0, so still points to 0x200102a0
cout << *ipt << endl;  // 1000, the value there is the same
cout << *((int *) 0x200102a0) << endl;    // 1000, also 1000 is the value
}