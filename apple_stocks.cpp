//
// Created by vineet on 4/26/24.
//

#include <iostream>
#include<vector>
#include <algorithm>
#include <cassert>

auto getMaxProfit (std::vector <int> stock_prices){
assert(stock_prices.size()>2);
int max_profit =0;
int temp_profit;
for(int i=0;i<stock_prices.size()-1;i++){
    for (int j = i+1; j<stock_prices.size();j++){
        temp_profit = stock_prices[j]-stock_prices[i];
        if(temp_profit>max_profit){
            max_profit =temp_profit;
        }
    }
}

return max_profit;

}

auto getMaxProfitOptimized( std::vector<int> stock_prices) {
    assert(stock_prices.size()>2);
    int min_price = stock_prices[0];
    int max_profit = stock_prices[1]-stock_prices[0];
    int temp_profit;

    for(int i = 0; i<stock_prices.size()-1;i++){
        min_price = std::min(min_price,stock_prices[i]);
        temp_profit = stock_prices[i]-min_price;

        max_profit = std::max(max_profit,temp_profit);

    }

    return max_profit;
}

int main(){
    std::vector <int> stocks ={10, 7, 5, 8, 11, 9,11,21,23,11,41,12,11,5,21,11,7,8,12,15,10,1,23,11};
    int max_profit = getMaxProfitOptimized(stocks);
    std::cout<<"the maximum profit achievable is: "<<max_profit<<std::endl;
    return 0;
}