/**
 * @author Javier Padilla Pío
 * @date 14/03/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practice 4 - Búsqueda por dispersión
 * Email: alu0101410463@ull.edu.es
 * Block.tpp: Implementación de la clase Block.
 * Revision history:
 *                28/03/2022 - Creation (first version) of the code
 */

template <class Key>
Block<Key>::Block() = default;

template <class Key>
Block<Key>::Block(unsigned size) {
  this->size_ = size;
  this->sequence_ = new Key[this->size_];
}

template <class Key>
bool Block<Key>::insert(const Key& k) {
  if (this->occupied_ == this->size_) {
    return false;
  }

  this->sequence_[this->occupied_++] = k;
  return true;
}
