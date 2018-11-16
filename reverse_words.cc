#include <string>
#include "algorithm"
#include "test_framework/generic_test.h"
#include "test_framework/timed_executor.h"

using namespace std;

void ReverseWords(string* s) {
/*
 *  Reverse the words in this string s.
 *  This means that the words have to swapped.
 *
 *  Find the white space first, once you find a white space you know where
 *  this word begins and ends. Then just call the function reverseWord
 *  with the corresponding indices.
 * */
  int i=0, j=0;
  reverse(begin(*s), end(*s));
  while( (j = s->find(' ', i)) != string::npos){
      reverse(begin(*s)+i, begin(*s)+j);
      i = j+1;
  }
  reverse(begin(*s)+i, end(*s));
  return;
}
string ReverseWordsWrapper(TimedExecutor& executor, string s) {
  string s_copy = s;

  executor.Run([&] { ReverseWords(&s_copy); });

  return s_copy;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "s"};
  return GenericTestMain(args, "reverse_words.cc", "reverse_words.tsv",
                         &ReverseWordsWrapper, DefaultComparator{},
                         param_names);
}
