#include <vector>
#include "test_framework/generic_test.h"
// Given n, return all primes up to and including n.
/*
 * Return all primes up to and including n.
 * A number m is a prime if it is not divisible
 * by any number in 1 to m-1.
 *
 * But we only need to check from 1 to m/2.
 *
 * Or only from 1 to sqrt(m).
 * We only need to test it on the primes less than m.
 *
 * If m is divisible by any of them then it is not a prime.
 * Right ? Yes.
 * */

using namespace std;

bool isPrime(int n, vector<int> primes){
  int s = primes.size();
  int root = sqrt(n);
  for(int i=0; i<s && primes[i] <= root; i++){
    if(n%primes[i] == 0)
      return false;
  }
  return true;
}

vector<int> GeneratePrimes(int n) {
  vector<int> primes;
  cout << "The number is " << n << endl;
  if(n <= 1)
    return {};
  primes.push_back(2);
  for(int i=3; i<=n; i++){
    if(isPrime(i, primes))
      primes.push_back(i);
  }
  return primes;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"n"};
  return GenericTestMain(args, "prime_sieve.cc", "prime_sieve.tsv",
                         &GeneratePrimes, DefaultComparator{}, param_names);
}
