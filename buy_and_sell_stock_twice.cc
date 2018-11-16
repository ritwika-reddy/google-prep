#include <vector>
#include "test_framework/generic_test.h"

using namespace std;
double BuyAndSellStockTwice(const vector<double>& prices) {
  /*
   *  Buying and selling a stock twice. This means that we need
   *  to do what we did in the previous problem but twice ?
   *
   *  The buying of the second share should take place after
   *  the sell of the first share. That is there should be
   *  no overlap in the buying and selling.
   *
   *  Should I just assume that two shares cannot be bought
   *  on the same date or should I assume that there is
   *  no overlap ?
   *
   *  I think the first.
   *
   *  Okay. What's the brute force method ?
   *
   *  If it were the second case then we can just assume that
   *  we are dividing the array into two parts, find the maximum
   *  in the first part and find the maximum in the second
   *  part and add them both. That would give you the maximum in the
   *  array.
   *
   *  That is we need to find the boundary where we can divide such
   *  that the first part gives us the first max and the second part
   *  gives the second max.
   *
   *  Okay the problem states that the second transaction can only
   *  start after the first transaction is complete.
   *
   *  Fine in this case this problem is equivalent to find the
   *  max profit in both subarrays when we create a boundary
   *  at some position j.
   *
   *  Where the position j can range from 0 to n-1.
   *
   * At any given point when we are traversing the array assume
   * that we are in one of four possible states.
   *
   * Either we just bought the first stock.
   *
   * We bought and sold the first stock.
   *
   * We bought, sold the first stock and bought the second stock.
   *
   * We can solve this problem using the ceiling method
   * in O(n) time and O(1) space complexity.
   *
   * */

  double buy[2];
  double sell[2];
  buy[0] = INT64_MIN;
  buy[1] = INT64_MIN;
  sell[0] = 0;
  sell[1] = 0;
  for(auto price: prices){
    sell[1] = max(sell[1], buy[1] + price);
    buy[1] = max(buy[1], sell[0] - price);
    sell[0] = max(sell[0], buy[0] + price);
    buy[0] = max(buy[0], 0 - price);
  }

  return sell[1];
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"prices"};
  return GenericTestMain(args, "buy_and_sell_stock_twice.cc",
                         "buy_and_sell_stock_twice.tsv", &BuyAndSellStockTwice,
                         DefaultComparator{}, param_names);
}
