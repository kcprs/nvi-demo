// Demo of the Non-Virtual Interface (NVI) idiom
//
// Resources:
// http://www.gotw.ca/publications/mill18.htm
// https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/Non-Virtual_Interface

#include <iostream>

////////////////////////////////////////////////////////////////////////////////
//                     "traditional" implementation
////////////////////////////////////////////////////////////////////////////////

class IBase {
public:
  virtual void foo() const = 0;
  virtual ~IBase() = default;
};

class DerivedA : public IBase {
private:
  void foo() const override { std::cout << "foo in DerivedA\n"; }
};

class DerivedB : public IBase {
private:
  void foo() const override { std::cout << "foo in DerivedB\n"; }
};

////////////////////////////////////////////////////////////////////////////////
//                          NVI implementation
////////////////////////////////////////////////////////////////////////////////

// class IBase {
// public:
//   void foo() const { foo_impl(); }
//   virtual ~IBase() = default;

// private:
//   virtual void foo_impl() const = 0;
// };

// class DerivedA : public IBase {
// private:
//   void foo_impl() const override { std::cout << "foo in DerivedA\n"; }
// };

// class DerivedB : public IBase {
// private:
//   void foo_impl() const override { std::cout << "foo in DerivedB\n"; }
// };

////////////////////////////////////////////////////////////////////////////////

void bar(const IBase &base) { base.foo(); }

int main(int /*unused*/, char ** /*unused*/) {
  DerivedA a;
  DerivedB b;

  bar(a);
  bar(b);
}
