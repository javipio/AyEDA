/**
 * @author Javier Padilla Pío
 * @date 01/05/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practice 6 - Implementación de árboles binarios equilibrados
 * Email: alu0101410463@ull.edu.es
 * AVL.tpp: Implementación de la clase AVL, concreción de la clase AB.
 * Revision history:
 *                01/05/2022 - Creation (first version) of the code
 */

template <class Key>
bool AVL<Key>::Insert(const Key k) {
  if (!this->root_) {
    this->root_ = new Node<Key>(k);
    return true;
  }

  Node<Key>* current = this->root_;
  std::stack<Node<Key>*> trace;

  while (current) {
    trace.push(current);
    if (k < current->value()) {
      if (current->left()) {
        current = current->left();
      } else {
        auto new_node = new Node<Key>(k);
        trace.push(new_node);

        current->set_left(new_node);
        insert_rebalance(trace);
        return true;
      }
    } else if (k > current->value()) {
      if (current->right()) {
        current = current->right();
      } else {
        auto new_node = new Node<Key>(k);
        trace.push(new_node);

        current->set_right(new_node);
        insert_rebalance(trace);
        return true;
      }
    } else {
      return false;
    }
  }

  return false;
};

template <class Key>
bool AVL<Key>::Delete(const Key k) {
  Node<Key>* current = this->root_;
  Node<Key>* parent = this->root_;

  std::stack<Node<Key>*> trace;

  while (current) {
    trace.push(current);

    if (k < current->value()) {
      parent = current;
      current = current->left();
    } else if (k > current->value()) {
      parent = current;
      current = current->right();
    } else {
      Node<Key>* new_node = this->extract_closest_low_node(current);
      Side first_side;

      if (current == this->root_) {  // QUÉ LADO CRACK?
        this->root_ = new_node;
      } else {
        if (parent->left() == current) {
          parent->set_left(new_node);
          first_side = left;

        } else {
          parent->set_right(new_node);
          first_side = right;
        }
      }

      if (new_node) {
        new_node->set_left(current->left());
        new_node->set_right(current->right());
      }

      delete_rebalance(trace, first_side);
      return true;
    }
  }

  return false;
}

template <class Key>
void AVL<Key>::insert_rebalance(std::stack<Node<Key>*> trace) {
  Node<Key>* curr = nullptr;
  auto child = trace.top();
  trace.pop();

  while (!trace.empty()) {
    curr = trace.top();
    trace.pop();

    if (curr->left() == child) {  // +2
      if (curr->bal() == 1) {
        if (child->bal() == 1) {
          rotateLL(curr);
        } else {
          rotateLR(curr);
        }
        break;
      }

      curr->increment_bal();
    } else {  // -2
      if (curr->bal() == -1) {
        if (child->bal() == 1) {
          rotateRL(curr);
        } else {
          rotateRR(curr);
        }
        break;
      }

      curr->decrement_bal();
    }

    if (!curr->bal()) break;
    child = curr;
  }
}

template <class Key>
void AVL<Key>::delete_rebalance(std::stack<Node<Key>*> trace, Side first_side) {
  Node<Key>* curr = nullptr;
  Side* side = &first_side;
  auto child = trace.top();
  trace.pop();

  while (!trace.empty()) {
    curr = trace.top();
    trace.pop();

    if ((side && *side == left) || curr->left() == child) {  // +2
      if (curr->bal() == -1) {
        if (curr->right()->bal() == 1) {
          rotateRL(curr);
        } else if (curr->right()->bal() == -1) {
          rotateRR(curr);
        } else {
          rotateRR(curr);
        }

        if (!curr->bal()) break;
      } else {
        curr->decrement_bal();
      }
    } else {  // -2
      if (curr->bal() == 1) {
        if (curr->left()->bal() == 1) {
          rotateLL(curr);
        } else if (curr->left()->bal() == -1) {
          rotateLR(curr);
        } else {
          rotateLL(curr);
        }

        if (!curr->bal()) break;
      } else {
        curr->increment_bal();
      }
    }

    side = nullptr;
    child = curr;
  }
}

template <class Key>
void AVL<Key>::rotateLL(Node<Key>* current) {
  Node<Key>* child = current->left();
  Node<Key>* parent = find_parent(current);

  if (parent->left() == current) {
    parent->set_left(child);
  } else if (parent->right() == current) {
    parent->set_right(child);
  } else {
    this->root_ = child;
  }

  current->set_left(child->right());
  child->set_right(current);

  if (child->bal() == 1) {
    current->set_bal(0);
    child->set_bal(0);

  } else {
    current->set_bal(1);
    child->set_bal(-1);
  }
}

template <class Key>
void AVL<Key>::rotateRR(Node<Key>* current) {
  Node<Key>* child = current->right();
  Node<Key>* parent = find_parent(current);

  if (parent->left() == current) {
    parent->set_left(child);
  } else if (parent->right() == current) {
    parent->set_right(child);
  } else {
    this->root_ = child;
  }

  current->set_right(child->left());
  child->set_left(current);

  if (child->bal() == -1) {
    current->set_bal(0);
    child->set_bal(0);
  } else {
    current->set_bal(-1);
    child->set_bal(1);
  }
}

template <class Key>
void AVL<Key>::rotateLR(Node<Key>* current) {
  Node<Key>* parent = find_parent(current);
  Node<Key>* child = current->left();
  Node<Key>* grandson = child->right();

  if (parent->left() == current) {
    parent->set_left(grandson);
  } else if (parent->right() == current) {
    parent->set_right(grandson);
  } else {
    this->root_ = grandson;
  }

  child->set_right(grandson->left());
  current->set_left(grandson->right());
  grandson->set_left(child);
  grandson->set_right(current);

  switch (grandson->bal()) {
    case 0:
      current->set_bal(0);
      child->set_bal(0);
      break;
    case 1:
      current->set_bal(-1);
      child->set_bal(0);
      break;
    case -1:
      current->set_bal(0);
      child->set_bal(1);
      break;
  }
  grandson->set_bal(0);
}

template <class Key>
void AVL<Key>::rotateRL(Node<Key>* current) {
  Node<Key>* parent = find_parent(current);
  Node<Key>* child = current->right();
  Node<Key>* grandson = child->left();

  if (parent->left() == current) {
    parent->set_left(grandson);
  } else if (parent->right() == current) {
    parent->set_right(grandson);
  } else {
    this->root_ = grandson;
  }

  current->set_right(grandson->left());
  child->set_left(grandson->right());
  grandson->set_left(current);
  grandson->set_right(child);

  switch (grandson->bal()) {
    case 0:
      current->set_bal(0);
      child->set_bal(0);
      break;
    case 1:
      current->set_bal(0);
      child->set_bal(-1);
      break;
    case -1:
      current->set_bal(1);
      child->set_bal(0);
      break;
  }
  grandson->set_bal(0);
}

template <class Key>
Node<Key>* AVL<Key>::find_parent(Node<Key>* current) {
  if (current == this->root_) {
    return current;
  }

  Node<Key>* parent;
  Node<Key>* temp = this->root_;
  Node<Key>* next_val;

  while (temp) {
    if (current->value() < temp->value()) {
      next_val = temp->left();
    } else if (current->value() > temp->value()) {
      next_val = temp->right();
    } else {
      break;
    }

    parent = temp;
    temp = next_val;
  }

  return parent;
}