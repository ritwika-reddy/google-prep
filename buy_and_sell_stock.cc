#include <vector>
#include "test_framework/generic_test.h"

using namespace std;

double BuyAndSellStockOnce(const vector<double>& prices) {
  /*
   *  Buy and Sell stock once.
   *
   *  You just need to know what's the minimum price before
   *  this index because that would give you the maximum profit
   *  for the price at this index.
   *
   * */
  double profit = 0.0;
  int n = prices.size();
  if(n == 0)
    return profit;

  double min_sofar = prices[0];

  double current = 0.0;
  for(int i=1; i<n; i++){
    current = prices[i] - min_sofar;
    if(current > profit)
      profit = current;
    if(min_sofar > prices[i])
      min_sofar = prices[i];
  }
  return profit;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"prices"};
  return GenericTestMain(args, "buy_and_sell_stock.cc",
                         "buy_and_sell_stock.tsv", &BuyAndSellStockOnce,
                         DefaultComparator{}, param_names);
}
