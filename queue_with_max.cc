#include <stdexcept>
#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"
#include "test_framework/test_failure.h"
using std::length_error;

using namespace std;

class QueueWithMax {
 public:
    /* Queue, insert into the q from the end
     * and delete it from the front.
     * When we insert a new element the max gets updated
     * and when we delete a new elements the max gets
     * updated.
     *
     *
     * */
  void Enqueue(int x) {
    elements_.push(x);

    // Handling the fact that another element has been inserted into this
    // queue. So we check an element smaller than this element is in the
    // maxs_ queue. If there is we delete that. Why ? Because as long
    // as this element is in the queue, there is no chance that
    // that smaller element can be a max because that has to be
    // deleted before this new element. Thus the elements in the
    // queue are always in the decreasing order where the front
    // is. Also to handle duplicates we only check if this
    // new element is strictly greater than the elements on the
    // queue, only then we pop the elements on maxs. Otherwise
    // we don't pop them. We insert duplicate elements to the
    // queue, that way we can delete it from maxs also when
    // the front of the queue matches the element being
    // dequeued. If there is a duplicate it should be right
    // behind it in the maxs queue.
    while( !maxs_.empty() && elements_.back() > maxs_.back()){
      maxs_.pop_back();
    }
    maxs_.push_back(elements_.back());
//    maxs_.push(elements_.back());
    return;
  }
  int Dequeue() {
    int ans = elements_.front();
    elements_.pop();
    if(ans == maxs_.front())
      maxs_.pop_front();
    return ans;
  }
  int Max() const {
    return maxs_.front();
  }

private:
    queue<int> elements_;
    deque<int> maxs_;

};
struct QueueOp {
  enum { kConstruct, kDequeue, kEnqueue, kMax } op;
  int argument;

  QueueOp(const std::string& op_string, int arg) : argument(arg) {
    if (op_string == "QueueWithMax") {
      op = kConstruct;
    } else if (op_string == "dequeue") {
      op = kDequeue;
    } else if (op_string == "enqueue") {
      op = kEnqueue;
    } else if (op_string == "max") {
      op = kMax;
    } else {
      throw std::runtime_error("Unsupported queue operation: " + op_string);
    }
  }
};

template <>
struct SerializationTraits<QueueOp> : UserSerTraits<QueueOp, std::string, int> {
};

void QueueTester(const std::vector<QueueOp>& ops) {
  try {
    QueueWithMax q;
    for (auto& x : ops) {
      switch (x.op) {
        case QueueOp::kConstruct:
          break;
        case QueueOp::kDequeue: {
          int result = q.Dequeue();
          if (result != x.argument) {
            throw TestFailure("Dequeue: expected " +
                              std::to_string(x.argument) + ", got " +
                              std::to_string(result));
          }
        } break;
        case QueueOp::kEnqueue:
          q.Enqueue(x.argument);
          break;
        case QueueOp::kMax: {
          int s = q.Max();
          if (s != x.argument) {
            throw TestFailure("Max: expected " + std::to_string(x.argument) +
                              ", got " + std::to_string(s));
          }
        } break;
      }
    }
  } catch (const length_error&) {
    throw TestFailure("Unexpected length_error exception");
  }
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"ops"};
  return GenericTestMain(args, "queue_with_max.cc", "queue_with_max.tsv",
                         &QueueTester, DefaultComparator{}, param_names);
}
