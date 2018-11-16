#include <memory>
#include "list_node.h"
#include "test_framework/generic_test.h"

using namespace std;

shared_ptr<ListNode<int>> RemoveDuplicates(const shared_ptr<ListNode<int>>& L) {

  auto dummy_head = make_shared<ListNode<int>>(ListNode<int>{0, L});
  auto tail = dummy_head->next;

  while(tail){
    if(tail->next && tail->next->data == tail->data)
      tail->next = tail->next->next;
    else
      tail = tail->next;
  }
  return dummy_head->next;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L"};
  return GenericTestMain(args, "remove_duplicates_from_sorted_list.cc",
                         "remove_duplicates_from_sorted_list.tsv",
                         &RemoveDuplicates, DefaultComparator{}, param_names);
}
