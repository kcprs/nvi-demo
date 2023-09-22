# Non-Virtual Interface (NVI) idiom demo

## Resources

- Article by Herb Sutter: <http://www.gotw.ca/publications/mill18.htm>
- More example in a wiki book: <https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/Non-Virtual_Interface>

## Advantages of NVI

- Separates public interface from internal implementation details
  - Allows for more free/natural design of interface and internals thanks to loose coupling
  - Base class (interface) can be modified without the need to change sub-classes (implementation)
- Creates a single place for defining shared behavior of sub-classes

## Drawbacks of NVI

- A little bit of boilerplate code
- Slightly bug-prone if multiple virtual functions are called from one interface function
  - Hence the recommendation to keep to 1 virtual function call per interface function
