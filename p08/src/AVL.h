#ifndef AVL_H_
#define AVL_H_

#include <stack>

#include "ABB.h"
#include "Node.h"

template <class Key>
class AVL : public ABB<Key> {
  using ABB<Key>::ABB;

  bool Insert(const Key k) override;
  bool Delete(const Key k) override;

 private:
  enum Side { left, right };
  void insert_rebalance(std::stack<Node<Key>*> trace);
  void delete_rebalance(std::stack<Node<Key>*> trace, Side first_side);

  void rotateLL(Node<Key>* current);
  void rotateRR(Node<Key>* current);
  void rotateLR(Node<Key>* current);
  void rotateRL(Node<Key>* current);

  Node<Key>* find_parent(Node<Key>* current);
};

#include "AVL.tpp"

#endif
