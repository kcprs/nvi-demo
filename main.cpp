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

////////////////////////////////////////////////////////////////////////////////
//                    Example of buggy implementation
////////////////////////////////////////////////////////////////////////////////

// #include <algorithm>
// #include <set>
// #include <vector>

// // Example from
// // https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/Non-Virtual_Interface

// class Set {
//   std::set<int> s_;

// public:
//   void add(int i) {
//     s_.insert(i);
//     add_impl(i); // Note virtual call.
//   }
//   void addAll(int *begin, int *end) {
//     s_.insert(begin, end); // OK
//     // std::for_each(begin, end, [this](auto i) { add(i); }); // Buggy

//     addAll_impl(begin, end); // Note virtual call.
//   }

// private:
//   virtual void add_impl(int i) = 0;
//   virtual void addAll_impl(int *begin, int *end) = 0;
// };
// class CountingSet : public Set {
// public:
//   int count() const { return count_; }

// private:
//   int count_;
//   virtual void add_impl(int i) { count_++; }
//   virtual void addAll_impl(int *begin, int *end) {
//     count_ += std::distance(begin, end);
//   }
// };

// int main(int /*unused*/, char ** /*unused*/) {
// std:
//   std::vector<int> v{1, 2, 3, 4, 5};
//   CountingSet s;

//   s.addAll(v.begin().base(), v.end().base());

//   std::cout << "Count is " << s.count() << std::endl;
// }