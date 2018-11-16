#include "list_node.h"
#include "test_framework/generic_test.h"

using namespace std;

shared_ptr<ListNode<int>> EvenOddMerge(const shared_ptr<ListNode<int>>& L) {

  auto dummy_head = make_shared<ListNode<int>>(ListNode<int>{0, L});
  auto tail = dummy_head->next;

  if(!L)
    return L;
  auto even = L;
  auto odd = L->next;
  auto oddHead = odd;
  while(even->next && odd->next){
    even->next = odd->next;
    even = even->next;

    odd->next = even->next;
    odd = odd->next;
  }

  even->next = oddHead;
  return dummy_head->next;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L"};
  return GenericTestMain(args, "even_odd_list_merge.cc",
                         "even_odd_list_merge.tsv", &EvenOddMerge,
                         DefaultComparator{}, param_names);
}
