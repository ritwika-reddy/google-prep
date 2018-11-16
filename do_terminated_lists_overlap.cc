#include <memory>
#include "list_node.h"
#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"

using namespace std;
shared_ptr<ListNode<int>> OverlappingNoCycleLists(
    shared_ptr<ListNode<int>> l0, shared_ptr<ListNode<int>> l1) {
  /*
   *  l0, l1
   *
   * */
  shared_ptr<ListNode<int>> p0 = l0, p1 = l1, p2;

  while(p0 && p1 && p0!= p1){
    p0 = p0->next;
    p1 = p1->next;
  }
  if(p0 == p1)
    return p0;
  if(p0){
    p2 = l0;
    while(p0){
      p2 = p2->next;
      p0 = p0->next;
    }
    p1 = l1;
    while(p1 != p2){
      p2 = p2->next;
      p1 = p1->next;
    }
    return p1;
  }
  if(p1){
    p2 = l1;
    while(p1){
      p2 = p2->next;
      p1 = p1->next;
    }
    p0 = l0;
    while(p0 != p2){
      p2 = p2->next;
      p0 = p0->next;
    }
    return p0;
  }
  return nullptr;
}
void OverlappingNoCycleListsWrapper(TimedExecutor& executor,
                                    shared_ptr<ListNode<int>> l0,
                                    shared_ptr<ListNode<int>> l1,
                                    shared_ptr<ListNode<int>> common) {
  if (common) {
    if (l0) {
      auto i = l0;
      while (i->next) {
        i = i->next;
      }
      i->next = common;
    } else {
      l0 = common;
    }

    if (l1) {
      auto i = l1;
      while (i->next) {
        i = i->next;
      }
      i->next = common;
    } else {
      l1 = common;
    }
  }

  auto result = executor.Run([&] { return OverlappingNoCycleLists(l0, l1); });

  if (result != common) {
    throw TestFailure("Invalid result");
  }
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "l0", "l1", "common"};
  return GenericTestMain(
      args, "do_terminated_lists_overlap.cc", "do_terminated_lists_overlap.tsv",
      &OverlappingNoCycleListsWrapper, DefaultComparator{}, param_names);
}
