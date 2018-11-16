#include <string>
#include "test_framework/generic_test.h"
#include "iostream"
using namespace std;

int getValue(char c){
  return isalpha(c) ? (c-'A') + 10 : c-'0';
}

char getChar(int v){
  return (v<10) ? '0'+v : 'A'+(v-10);
}

string ConvertBase(const string& num_as_string, int b1, int b2) {
  /*
   * Convert the string from base b1 to base b2.
   * We know that b1, b2 >= 2 and <= 16.
   * The string num_as_string is the number in base b1.
   * How to do this ?
   * Convert the number to decimal and then convert from decimal to b2 ?
   * Why ?
   * Get the value of each character, multiply with the position value and
   * get the total integer value.
   *
   * Then how to encode in base b2 ? Find the largest power of b2 less than
   * the decimal number and form the string so on.
   *
   * How about the fact that 10 has to be encoded as 'A' and so on Let's see.
   * */
  int num = 0;
  int n = num_as_string.length();

  bool neg = false;
  int i = 0;
  if(n == 0)
    return num_as_string;
  if(num_as_string[0] == '-' ){
    i++;
    neg = true;
  }
  int p;
  if(neg)
    p = pow(b1, n-2);
  else
    p = pow(b1, n-1);
  for(; i<n; i++){
    char c = num_as_string[i];
    num += getValue(c)*p;
    p /= b1;
  }
  if(num == 0)
    return num_as_string;

  p = (log2(num) / log2(b2));
  p = pow(b2, p);
  string s = (neg) ? "-" : "";

  while(p){
    s += getChar(num/p);
    num %= p;
    p /= b2;
  }
  return s;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"num_as_string", "b1", "b2"};
  return GenericTestMain(args, "convert_base.cc", "convert_base.tsv",
                         &ConvertBase, DefaultComparator{}, param_names);
}