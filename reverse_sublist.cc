#include "list_node.h"
#include "test_framework/generic_test.h"

using namespace std;

shared_ptr<ListNode<int>> ReverseSublist(shared_ptr<ListNode<int>> L, int start,
                                         int finish) {
  /*
   * Reverse sublist from the indices start to finish.
   * */

  auto dummy_head = make_shared<ListNode<int>>(ListNode<int>{0, L});
  auto sublist_head = dummy_head;
  int k = 1;
  cout << start << " " << finish << endl;
  while(k++ < start){
    cout << "start " << k << endl;
    sublist_head = sublist_head->next;
  }
  // 1->2->3->4->5->6, 2 to 4
  //
  // Reverses sublist

  auto sublist_iter = sublist_head->next;
  while(start++<finish){
    cout << start << endl;
    cout << sublist_iter->data << endl;
    auto temp = sublist_iter->next;
    cout << temp->data << endl;
    sublist_iter->next = temp->next;
    temp->next = sublist_head->next;
    sublist_head->next = temp;
  }

  return dummy_head->next;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L", "start", "finish"};
  return GenericTestMain(args, "reverse_sublist.cc", "reverse_sublist.tsv",
                         &ReverseSublist, DefaultComparator{}, param_names);
}
