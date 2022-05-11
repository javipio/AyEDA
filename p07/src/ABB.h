#ifndef ABB_H_
#define ABB_H_
#include <vector>

#include "AB.h"
template <class Key>
class ABB : public AB<Key> {
 public:
  using AB<Key>::AB;

  bool Insert(const Key k) override;
  bool Search(const Key& k) const override;
  bool Delete(const Key k) override;

 private:
  std::vector<Node<Key>*> get_neighbors(const Node<Key>* node) const;

  Node<Key>* extract_closest_low_node(Node<Key>* node);
};

#include "ABB.tpp"

#endif
