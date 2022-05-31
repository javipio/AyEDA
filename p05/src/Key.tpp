template <class T>
Key<T>::Key(T value) : value_{value} {}

template <class T>
T Key<T>::get() const {
  return value_;
};

template <class T>
void Key<T>::increment_comparisons() {
  comparisons_++;
}

template <class T>
void Key<T>::set(T new_value) {
  value_ = new_value;
}

template <class T>
void Key<T>::operator=(Key<T>& rgt) {
  value_ = rgt.get();
  comparisons_ = rgt.get_comparisons();
}

template <class T>
uint Key<T>::get_comparisons() {
  return comparisons_;
}

template <class T>
void Key<T>::operator=(T rgt) {
  value_ = rgt;
}

template <class T>
bool operator<(Key<T>& lft, Key<T>& rgt) {
  lft.increment_comparisons();
  rgt.increment_comparisons();
  return lft.get() < rgt.get();
}

template <class T>
bool operator>(Key<T> lft, Key<T> rgt) {
  lft.increment_comparisons();
  rgt.increment_comparisons();
  return lft.get() > rgt.get();
}

template <class T>
bool operator<=(Key<T>& lft, Key<T>& rgt) {
  lft.increment_comparisons();
  rgt.increment_comparisons();
  return lft.get() <= rgt.get();
}

template <class T>
Key<T> operator%(Key<T> lft, unsigned rgt) {
  return lft.get() % rgt;
}

template <class T>
Key<T> operator/(Key<T>& key, unsigned integer) {
  return key.get() / integer;
}

template <class T>
std::ostream& operator<<(std::ostream& output_stream, Key<T>& key) {
  return output_stream << key.get();
}

template <class T>
Key<T>::operator unsigned() {
  return value_;
}

template <class T>
void Key<T>::operator-=(unsigned rgt) {
  value_ -= rgt;
}

template <class T>
std::string Key<T>::to_string() const {
  std::stringstream ss;
  ss << value_ << " (" << comparisons_ << ") ";
  return ss.str();
}