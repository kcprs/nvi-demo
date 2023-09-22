#include <iostream>

template<typename Policy>
class Widget : private Policy {
public:
  void foo() const {
    foo_impl();
  }
private:
  using Policy::foo_impl;
};

class PolicyA {
public:
  void foo_impl() const { std::cout << "foo in DerivedA\n"; }
};

class PolicyB {
public:
  void foo_impl() const { std::cout << "foo in DerivedB\n"; }
};

////////////////////////////////////////////////////////////////////////////////


int main(int /*unused*/, char ** /*unused*/) {
  Widget<PolicyA> a;
  Widget<PolicyB> b;
  a.foo();
  b.foo();
}
