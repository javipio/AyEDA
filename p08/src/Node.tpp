/**
 * @author Javier Padilla Pío
 * @date 01/05/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practice 6 - Implementación de árboles binarios equilibrados
 * Email: alu0101410463@ull.edu.es
 * Node.tpp: Implementación de la clase Node que representa un nodo del arbol.
 * Revision history:
 *                01/05/2022 - Creation (first version) of the code
 */

template <class Key>
Node<Key>::Node(Key value, Node<Key>* left, Node<Key>* right)
    : value_{value}, left_{left}, right_{right} {}

template <class Key>
Node<Key>* Node<Key>::left() {
  return left_;
};

template <class Key>
Node<Key>* Node<Key>::right() {
  return right_;
};

template <class Key>
void Node<Key>::set_left(Node<Key>* node) {
  left_ = node;
}

template <class Key>
void Node<Key>::set_right(Node<Key>* node) {
  right_ = node;
}

template <class Key>
Key Node<Key>::value() const {
  return value_;
}

template <class Key>
int Node<Key>::bal() const {
  return bal_;
};

template <class Key>
void Node<Key>::set_bal(int bal) {
  bal_ = bal;
};

template <class Key>
void Node<Key>::increment_bal() {
  bal_++;
};

template <class Key>
void Node<Key>::decrement_bal() {
  bal_--;
};
