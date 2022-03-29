/**
 * @author Javier Padilla Pío
 * @date 14/03/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practice 4 - Búsqueda por dispersión
 * Email: alu0101410463@ull.edu.es
 * Sequence.tpp: Interfaz de la clase Sequence.
 * Revision history:
 *                28/03/2022 - Creation (first version) of the code
 */

template <class Key>
bool Sequence<Key>::search(const Key& k) const {
  for (int i = 0; i < occupied_; i++) {
    if (k == sequence_[i]) return true;
  }

  return false;
}

template <class Key>
bool Sequence<Key>::isFull() const {
  return size_ == occupied_;
}
