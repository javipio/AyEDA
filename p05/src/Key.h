#ifndef KEY_H_
#define KEY_H_

#include <iostream>
#include <sstream>

template <class T>
class Key {
 public:
  Key() = default;
  Key(T value);
  T get() const;
  void set(T new_value);

  void operator=(Key<T>&);

  void operator=(T);

  void increment_comparisons();

  operator unsigned();

  void operator-=(unsigned);

  std::string to_string() const;

  uint get_comparisons();

 private:
  uint comparisons_ = 0;
  T value_;
};

template <class T>
bool operator<(Key<T>&, Key<T>&);

template <class T>
bool operator>(Key<T>, Key<T>);

template <class T>
bool operator<=(Key<T>&, Key<T>&);

template <class T>
std::ostream& operator<<(std::ostream&, Key<T>&);

template <class T>
Key<T> operator/(Key<T>&, unsigned);

template <class T>
Key<T> operator%(Key<T>, unsigned);

#include "Key.tpp"

#endif
