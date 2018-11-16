#include <string>
#include "test_framework/generic_test.h"
#include "iostream"

using namespace std;

string SSEncodeColId(int col){
    string s = "";
    while(col){
        s += 'A'+(col%26-1);
        col /= 26;
    }
    reverse(s.begin(), s.end());
    return s;
}

int SSDecodeColID(const string& col) {

  /*
   *  Spread sheet encoding, encode the column with
   *  Return a number for the column given.
   *  They are named as follows, A...Z, AA...ZZ,
   *  AAA... ZZZ.
   * */

  int encoding = 0;
  for(auto c: col){
      encoding = encoding*26 + ((c-'A')+1);
  }
  std::cout << "\n" <<  col << " " << encoding << std::endl;
  cout << SSEncodeColId(encoding) << endl;
  return encoding;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"col"};
  return GenericTestMain(args, "spreadsheet_encoding.cc",
                         "spreadsheet_encoding.tsv", &SSDecodeColID,
                         DefaultComparator{}, param_names);
}
