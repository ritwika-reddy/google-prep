#include <vector>
#include "test_framework/generic_test.h"
#include "algorithm"

using namespace std;

void Print(vector<int> num){
  int n = num.size();
  for(int i=0; i<n; i++)
    cout << num[i] << " ";
  cout << endl;
  return;
}

vector<int> Add(vector<int> num1, vector<int> num2){
  vector<int> num;
  int carry = 0;
  /*
   * Either both the vectors have the same
   * length or they don't have the same length.
   * */
  int m = num1.size(), n = num2.size();
  int i = m-1, j = n-1;

  while(i >= 0 && j >=0 ){
    num.push_back((num1[i]+num2[j]+carry)%10);
    carry = (num1[i--] + num2[j--]+carry)/10;
  }

  if(i>=0){
    while(i >= 0){
      num.push_back((num1[i]+carry)%10);
      carry = (num1[i--]+carry)/10;
    }
    if(carry)
      num.push_back(carry);
  }
  if(j>=0){
    while(j >= 0){
      num.push_back((num2[j]+carry)%10);
      carry = (num2[j--]+carry)/10;
    }
    if(carry)
      num.push_back(carry);
  }
  reverse(num.begin(), num.end());
  cout << "Num 1 " ;
  Print(num1);
  cout << "Num 2 " ;
  Print(num2);
  cout << "Add Num " ;
  Print(num);
  return num;
// Off by one digit, don't know the reason for it.

}

vector<int> Multiply(vector<int> num1, vector<int> num2) {
  /*
   *  Mulitply the two integers represented by num1 and num2.
   *  How to multiply two integers ?
   *  Multiply each digit with num1 and add it to
   *  the running sum after shifting the product m positions
   *  where m is the position of the digit in num2.
   *
   *  Write a function for adding two numbers represented
   *  as vectors first ?
   *  Okay. Let's do that.
   *
   *  Even in multiplication, there's a carry which is the tens
   *  digits of the product of the two digits multiplied.
   *
   * */
//  vector<int> num;
//
//  int m=num1.size(), n = num2.size();
//
//  int i = m-1, j = n-1;
//  bool sign1 = false, sign2 = false, sign;
//  if(m > 0){
//    sign1 = (num1[0] < 0) ? true: false;
//    if(sign1)
//      num1[0] *= -1;
//  }
//
//  if(n > 0){
//    sign2 = (num2[0] < 0) ? true : false;
//    if(sign2)
//      num2[0] *= -1;
//  }
//
//  sign = sign1 ^ sign2;
//
//  while( j >=0 ){
//    int carry = 0;
//    int c = num2[j];
//    vector<int> temp;
//
//    for(int k=0; k<n-1-j;k++)
//      temp.push_back(0);
//
//    for(int i=m-1; i>=0; i--){
//      int p = num1[i]*c + carry;
//      temp.push_back(p%10);
//      cout << num1[i] << " " << carry << " " << c << " " << p%10 << " " << p/10 << endl;
//      carry = p/10;
//    }
//    if(carry)
//      temp.push_back(carry);
//    reverse(temp.begin(), temp.end());
//    cout << "temp " << endl;
//    Print(temp);
//    num = Add(num, temp);
//    j--;
//  }
//  if(num.size()>0 && sign)
//    num[0] *= -1;
//
//  return num;

  vector<int> num(num1.size()+num2.size(), 0);
  int sign = (num1.front() < 0) ^ (num2.front()<0) ? -1: 1;
  num1.front() = abs(num1.front());
  num2.front() = abs(num2.front());

  for(int j= num2.size()-1; j >=0; j--){
    for(int i=num1.size()-1; i>=0; i--){
      num[i+j+1] += (num2[j]*num1[i]);
      num[i+j] += num[i+j+1]/10;
      num[i+j+1] = num[i+j+1]%10;
    }
  }
  // Remove the leading zeros.
  // Remove the leading zeros.
  num = { find_if_not(begin(num), end(num), [](int a){return a==0; }), end(num)};
  if(num.empty())
    return {0};
  num.front() = sign*num.front();
  return num;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"num1", "num2"};
  return GenericTestMain(args, "int_as_array_multiply.cc",
                         "int_as_array_multiply.tsv", &Multiply,
                         DefaultComparator{}, param_names);
}
