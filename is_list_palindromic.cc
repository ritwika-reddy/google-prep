#include "list_node.h"
#include "test_framework/generic_test.h"

using namespace std;

bool IsLinkedListAPalindrome(shared_ptr<ListNode<int>> L) {
  /*
   *  Reverse half of the list and then compare the two halves.
   * */

  auto slow = L;
  auto fast = L;

  while(fast && fast->next){
    slow = slow->next;
    fast = fast->next->next;
  }

  shared_ptr<ListNode<int>> prev = nullptr;
  if(fast)
    slow = slow->next;

  while(slow){
    shared_ptr<ListNode<int>> temp = slow->next;
    slow->next = prev;
    prev = slow;
    slow = temp;
  }

  fast = L;
  slow = prev;
  while(fast && slow ){
    if(fast->data != slow->data)
      return false;
    fast = fast->next;
    slow = slow->next;
  }

  return true;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L"};
  return GenericTestMain(args, "is_list_palindromic.cc",
                         "is_list_palindromic.tsv", &IsLinkedListAPalindrome,
                         DefaultComparator{}, param_names);
}
