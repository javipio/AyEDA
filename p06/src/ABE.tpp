/**
 * @author Javier Padilla Pío
 * @date 01/05/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practice 6 - Implementación de árboles binarios equilibrados
 * Email: alu0101410463@ull.edu.es
 * ABE.tpp: Implementación de la clase ABE, concreción de la clase AB.
 * Revision history:
 *                01/05/2022 - Creation (first version) of the code
 */

template <class Key>
bool ABE<Key>::Insert(const Key k) {
  if (!this->root_) {
    this->root_ = new Node<Key>(k);
    return true;
  }

  std::queue<Node<Key>*> trace;
  trace.push(this->root_);
  while (!trace.empty()) {
    if (!trace.front()->left()) {
      trace.front()->set_left(new Node<Key>(k));
      return true;
    } else if (!trace.front()->right()) {
      trace.front()->set_right(new Node<Key>(k));
      return true;
    } else {
      trace.push(trace.front()->left());
      trace.push(trace.front()->right());
      trace.pop();
    }
  }

  return false;
};

template <class Key>
bool ABE<Key>::Search(const Key& k) const {
  std::stack<Node<Key>*> trace;
  trace.push(this->root_);

  Node<Key>* current = nullptr;

  while (!trace.empty()) {
    current = trace.top();
    trace.pop();

    if (current->value() == k) return true;

    if (current->left()) trace.push(current->left());
    if (current->right()) trace.push(current->right());
  }

  return false;
};
