#include <bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>& prices) {
        int profit=0;
        int n= prices.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                // cout<<prices[j]<<" "<<prices[i]<<endl;
                if(prices[j]>prices[i]){
                    profit=max(profit,(prices[j]-prices[i]));
                    // cout<<profit<<endl;
                }else break;
            }
        }
        return profit;
    }
int maxProfit2(vector<int> &prices) {
    int maxPro = 0;
    int minPrice = INT_MAX;
    for(int i = 0; i < prices.size(); i++){
        minPrice = min(minPrice, prices[i]);
        maxPro = max(maxPro, prices[i] - minPrice);
    }
    return maxPro;
}
int maxProfit3(vector<int>& prices) {
      if (prices.empty()) return 0;
      
      int minPrice = prices[0], maxProfit = 0;
      for (int p : prices)
        if (p < minPrice) minPrice = p; // no min calculation
        else maxProfit = max(maxProfit, p - minPrice);
      
      return maxProfit;        
    }
int main(){
    vector<int> prices={1,2};
    cout<<maxProfit(prices)<<endl;
}