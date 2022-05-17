/**
 * @author Javier Padilla Pío
 * @date 01/05/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practica 7 - Implementación de árboles binarios de búsqueda
 * Email: alu0101410463@ull.edu.es
 * ABB.tpp: Implementación de la clase ABB, concreción de la clase AB.
 * Revision history:
 *                01/05/2022 - Creation (first version) of the code
 */

template <class Key>
bool ABB<Key>::Insert(const Key k) {
  if (!this->root_) {
    this->root_ = new Node<Key>(k);
    return true;
  }

  Node<Key>* current = this->root_;
  while (current) {
    if (k < current->value()) {
      if (current->left()) {
        current = current->left();
      } else {
        current->set_left(new Node<Key>(k));
        return true;
      }
    } else if (k > current->value()) {
      if (current->right()) {
        current = current->right();
      } else {
        current->set_right(new Node<Key>(k));
        return true;
      }
    } else {
      return false;
    }
  }

  return false;
};

template <class Key>
bool ABB<Key>::Search(const Key& k) const {
  Node<Key>* current = this->root_;

  while (current) {
    if (k < current->value()) {
      current = current->left();
    } else if (k > current->value()) {
      current = current->right();
    } else {
      return true;
    }
  }

  return false;
};

template <class Key>
bool ABB<Key>::Delete(const Key k) {
  Node<Key>* current = this->root_;
  Node<Key>* parent = this->root_;

  while (current) {
    if (k < current->value()) {
      parent = current;
      current = current->left();
    } else if (k > current->value()) {
      parent = current;
      current = current->right();
    } else {
      Node<Key>* new_node = extract_closest_low_node(current);

      if (current == this->root_) {
        this->root_ = new_node;
      } else {
        if (parent->left() == current)
          parent->set_left(new_node);
        else
          parent->set_right(new_node);
      }

      if (new_node) {
        new_node->set_left(current->left());
        new_node->set_right(current->right());
      }

      return true;
      // delete current;
    }
  }

  return false;
}

template <class Key>
Node<Key>* ABB<Key>::extract_closest_low_node(Node<Key>* node) {
  Node<Key>* current = node->left();
  Node<Key>* parent = node;

  while (current && current->right()) {
    parent = current;
    current = current->right();
  }

  if (current && parent->left() == current) {
    parent->set_left(current->left());
  } else if (parent->right() == current) {
    parent->set_right(nullptr);
  }

  return current;
}
