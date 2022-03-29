/**
 * @author Javier Padilla Pío
 * @date 14/03/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practice 4 - Búsqueda por dispersión
 * Email: alu0101410463@ull.edu.es
 * HashTable.tpp: Implementación de la clase HashTable.
 * Revision history:
 *                28/03/2022 - Creation (first version) of the code
 */

template <class Key>
HashTable<Key>::HashTable(int table_size, DispersionFunction<Key>* fd,
                          ExplorationFunction<Key>* fe, int block_size)
    : table_size_{table_size}, fd_{fd}, fe_{fe}, block_size_{block_size} {
  if (fe == nullptr) {
    table_ = new List<Key>[table_size_];
  } else {
    table_ = new Block<Key>[table_size_];

    for (int i = 0; i < table_size_; i++) {
      table_[i] = Block<Key>(block_size_);
    }
  }
};

template <class Key>
HashTable<Key>::~HashTable() {
  delete fd_;
  delete fe_;
};

template <class Key>
bool HashTable<Key>::insert(const Key& k) {
  int posible_index = (*fd_)(k);

  if (!table_[posible_index].isFull()) {
    table_[posible_index].insert(k);

    return true;
  }

  int offset = 0;
  if (fe_ != nullptr) {
    for (int i = 0; (i + posible_index) < table_size_; i++) {
      offset = (*fe_)(k, i);

      if (!table_[posible_index + offset].isFull()) {
        table_[posible_index + offset].insert(k);
        return true;
      }
    }
  }

  return false;
};

template <class Key>
bool HashTable<Key>::search(const Key& k) {
  int posible_index = (*fd_)(k);

  if (table_[posible_index].search(k)) {
    return true;
  }

  if (!table_[posible_index].isFull()) {
    return false;
  }

  if (fe_ != nullptr) {
    int offset = 0;

    for (int i = 0; i < table_size_ - posible_index; i++) {
      offset = (*fe_)(k, i);
      if (table_[posible_index + offset].search(k)) {
        return true;
      };

      if (!table_[posible_index + offset].isFull()) {
        return false;
      }
    }
  }

  return false;
};
