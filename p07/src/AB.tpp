/**
 * @author Javier Padilla Pío
 * @date 01/05/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practice 6 - Implementación de árboles binarios equilibrados
 * Email: alu0101410463@ull.edu.es
 * AB.tpp: Implementación de la clase abstracta AB que representa un arbol
 * binario. Revision history: 01/05/2022 - Creation (first version) of the code
 */

template <class Key>
void AB<Key>::Print(std::ostream& output_stream) const {
  std::queue<Node<Key>*> trace;
  trace.push(root_);

  int level_size = 1;
  int position = 0;

  while (!trace.empty()) {
    position++;

    Node<Key>* current = trace.front();
    output_stream << (current ? std::to_string(current->value()) : "[.]")
                  << " ";
    trace.pop();

    if (current) {
      trace.push(current->left());
      trace.push(current->right());
    }

    if (position == level_size) {
      level_size *= 2;
      position = 0;
      std::cout << std::endl;
    }
  }
}

template <class Key>
void AB<Key>::Inorder() const {
  std::stack<Node<Key>*> trace;
  Node<Key>* current = this->root_;

  while (!trace.empty() || current) {
    if (current) {
      trace.push(current);
      current = current->left();
    } else {
      current = trace.top();
      std::cout << current->value() << ", ";
      trace.pop();
      current = current->right();
    }
  }

  std::cout << std::endl;
}

template <class Key>
std::ostream& operator<<(std::ostream& output_stream, const AB<Key>& tree) {
  tree.Print(output_stream);
  return output_stream;
}
