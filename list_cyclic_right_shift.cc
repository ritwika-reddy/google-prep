#include <memory>
#include "list_node.h"
#include "test_framework/generic_test.h"

using namespace std;

shared_ptr<ListNode<int>> CyclicallyRightShiftList(shared_ptr<ListNode<int>> L,
                                                   int k) {
  /*
   *  Make this singly connected list a cyclic list and
   *  make it uncyclic at the kth position from the
   *  start of the list.
   * */

  auto kthNode = L;
  int i=1;

  while(i++ < k)
    kthNode = kthNode->next;
  if(!L || k == 0)
    return L;

  auto lastNode = L;

  while(lastNode->next)
    lastNode = lastNode->next;

  lastNode->next = L;

  L = kthNode->next;
  kthNode->next = nullptr;
  return L;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L", "k"};
  return GenericTestMain(
      args, "list_cyclic_right_shift.cc", "list_cyclic_right_shift.tsv",
      &CyclicallyRightShiftList, DefaultComparator{}, param_names);
}
