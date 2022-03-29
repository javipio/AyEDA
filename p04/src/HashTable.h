/**
 * @author Javier Padilla Pío
 * @date 14/03/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practice 4 - Búsqueda por dispersión
 * Email: alu0101410463@ull.edu.es
 * HashTable.h: Interfaz de la clase HashTable.
 * Revision history:
 *                28/03/2022 - Creation (first version) of the code
 */

#ifndef HASH_TABLE_H_
#define HASH_TABLE_H_

#include "DispersionFunction/DispersionFunction.h"
#include "ExplorationFunction/ExplorationFunction.h"
#include "Sequence/Block.h"
#include "Sequence/List.h"
#include "Sequence/Sequence.h"

template <class Key>
class HashTable {
 public:
  HashTable(int table_size, DispersionFunction<Key>* fd,
            ExplorationFunction<Key>* fe = nullptr, int block_size = 0);

  ~HashTable();

  /**
   * @brief Añade un elemento a la tabla.
   * @param[in] k Clave del elemento a añadir.
   * @return Verdadero si se logró almacenar el elemento.
   */
  bool insert(const Key& k);

  /**
   * @brief Busca una clave en la tabla.
   * @param[in] k Clave del elemento a buscar.
   * @return Verdadero si está contenido en la tabla.
   */
  bool search(const Key& k);

 private:
  int table_size_;
  Sequence<Key>* table_;
  int block_size_;
  DispersionFunction<Key>* fd_;
  ExplorationFunction<Key>* fe_;
};

#include "HashTable.tpp"
#endif
