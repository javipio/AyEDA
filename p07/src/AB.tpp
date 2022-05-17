/**
 * @author Javier Padilla Pío
 * @date 01/05/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practica 7 - Implementación de árboles binarios de búsqueda
 * Email: alu0101410463@ull.edu.es
 * AB.tpp: Implementación de la clase abstracta AB que representa un arbol
 *         binario.
 * Revision history:
 *                01/05/2022 - Creation (first version) of the code
 */

template <class Key>
void AB<Key>::Print(std::ostream& output_stream) const {
  std::queue<Node<Key>*> current_level;
  std::queue<Node<Key>*> next_level;
  current_level.push(root_);
  Node<Key>* current;

  while (!current_level.empty()) {
    current = current_level.front();
    current_level.pop();

    output_stream << (current ? std::to_string(current->value()) : "[.]")
                  << " ";

    if (current) {
      next_level.push(current->left());
      next_level.push(current->right());
    }

    if (current_level.empty() && !next_level.empty()) {
      output_stream << "\n";
      copy_queue(next_level, current_level);
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

template <class Key>
template <class T>
void AB<Key>::copy_queue(std::queue<T>& origin, std::queue<T>& dest) const {
  std::stack<T> temp;
  T current;

  while (!origin.empty()) {
    current = origin.front();
    origin.pop();
    dest.push(current);
  }
};
