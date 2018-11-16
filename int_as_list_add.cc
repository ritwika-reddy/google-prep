#include "list_node.h"
#include "test_framework/generic_test.h"


using namespace std;

shared_ptr<ListNode<int>> AddTwoNumbers(shared_ptr<ListNode<int>> L1,
                                        shared_ptr<ListNode<int>> L2) {
  /*
   * Store the
   * */
  shared_ptr<ListNode<int>> dummy_L(new ListNode<int>);
  auto tail = dummy_L;
  int carry = 0;
  while(L1 && L2){
    int val = L1->data + L2->data + carry;
    tail->next = make_shared<ListNode<int>>(ListNode<int>{val % 10, nullptr});
    tail = tail->next;
    carry = val/10;
    L1 = L1->next;
    L2 = L2->next;
  }
  while(L1){
    int val = L1->data + carry;
    tail->next = make_shared<ListNode<int>>(ListNode<int>{val % 10, nullptr});
    L1 = L1->next;
    tail = tail->next;
    carry = val/10;
  }
  while(L2){
    int val = L2->data + carry;
    tail->next = make_shared<ListNode<int>>(ListNode<int>{val % 10, nullptr});
    L2 = L2->next;
    tail = tail->next;
    carry = val/10;
  }
  if(carry)
    tail->next = make_shared<ListNode<int>>(ListNode<int>{carry, nullptr});

  return dummy_L->next;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L1", "L2"};
  return GenericTestMain(args, "int_as_list_add.cc", "int_as_list_add.tsv",
                         &AddTwoNumbers, DefaultComparator{}, param_names);
}
