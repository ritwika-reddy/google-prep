#include <iterator>
#include <string>
#include <vector>
#include "test_framework/generic_test.h"
#include "test_framework/timed_executor.h"
#include "iostream"
using namespace std;

int ReplaceAndRemove(int size, char s[]) {
  /*
   * Replace each a with two ds and remove all the bs
   * We know that we'll not be overwriting any
   * characters if we start reading from the size-1 st character.
   * But how do we know where to start writing from ?
   * Make multiple passes to count the number of bs, as to compute
   * the true length of the new string.
   *
   * This algorithm only works if you can be sure that,
   * the new length is greater than the current length.
   * Otherwise, there's a possibility of overwriting.
   *
   * How to avoid this ? This can be done when we make sure that
   * the true length is greater than the original length.
   * That is guaranteed to take place when we only consider the as.
   * First we can only consider the as and write 2ds in place of
   * each a in the new string. Next after that ? What about bs ?
   *
   * Then make one more pass where you don't write any bs in the array.
   * */
  int bs=0, as=0;
  int i=0;
  int j=0;
  for(int j=0; j<size; j++){
      if(s[j] != 'b'){
          s[i++] = s[j];
      }
  }
  for(int j=0; j<i; j++)
      if(s[j] == 'a')
          as++;

  int m = i;
  j = m+as-1;
  int n = j;
  for(i=m-1; i>=0; i--){
      if(s[i]=='a'){
          s[j--] = 'd';
          s[j--] = 'd';
      }
      else{
          s[j--] = s[i];
      }
  }
  return n+1;
}
vector<string> ReplaceAndRemoveWrapper(TimedExecutor& executor, int size,
                                       const vector<string>& s) {
  std::vector<char> s_copy(s.size(), '\0');
  for (int i = 0; i < s.size(); ++i) {
    if (!s[i].empty()) {
      s_copy[i] = s[i][0];
    }
  }

  int res_size =
      executor.Run([&] { return ReplaceAndRemove(size, s_copy.data()); });

  vector<string> result;
  for (int i = 0; i < res_size; ++i) {
    result.emplace_back(string(1, s_copy[i]));
  }
  return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "size", "s"};
  return GenericTestMain(args, "replace_and_remove.cc",
                         "replace_and_remove.tsv", &ReplaceAndRemoveWrapper,
                         DefaultComparator{}, param_names);
}
