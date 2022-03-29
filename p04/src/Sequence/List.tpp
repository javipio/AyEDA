/**
 * @author Javier Padilla Pío
 * @date 14/03/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practice 4 - Búsqueda por dispersión
 * Email: alu0101410463@ull.edu.es
 * List.tpp: Interfaz de la clase List.
 * Revision history:
 *                28/03/2022 - Creation (first version) of the code
 */

template <class Key>
List<Key>::List() = default;

template <class Key>
bool List<Key>::insert(const Key& k) {
  if (this->occupied_ == this->size_) {
    resize(this->size_ + 1);
  }

  this->sequence_[this->occupied_++] = k;
  return true;
}

template <class Key>
void List<Key>::resize(unsigned new_size) {
  Key* new_sequence = new Key[new_size];

  memcpy(new_sequence, this->sequence_, this->size_ * sizeof(Key));
  delete[] this->sequence_;

  this->size_ = new_size;
  this->sequence_ = new_sequence;
}

template <class Key>
bool List<Key>::isFull() const {
  return false;
}
