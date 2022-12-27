#include <bits/stdc++.h>
using namespace std;

//TC - nlogn + n
struct Item{
    int value;
    int weight;
};

// it need to be outside the class
// division is done first then he look for data type if it doesn't find any data casting then it look on itself -- my theory 
bool cmp(Item i1, Item i2){
    return (double)i1.value/i1.weight > (double)i2.value/i2.weight;
}
class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr,arr+n,cmp);
        double res = 0;
        int currWt = 0;
        for(int i =0;currWt<W && i<n;i++){
            if(currWt + arr[i].weight <= W) currWt += arr[i].weight, res += arr[i].value;
            else{
                res += (W - currWt)*((double)arr[i].value/arr[i].weight);
                currWt = W;
            }
        }
        return res;
    }
};