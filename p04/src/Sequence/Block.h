/**
 * @author Javier Padilla Pío
 * @date 14/03/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practice 4 - Búsqueda por dispersión
 * Email: alu0101410463@ull.edu.es
 * Block.h: Interfaz de la clase Block. Implementa una lista de tamaño fijo.
 * Revision history:
 *                28/03/2022 - Creation (first version) of the code
 */

#ifndef BLOCK_H_
#define BLOCK_H_

#include "Sequence.h"

template <class Key>
class Block : public Sequence<Key> {
 public:
  Block(unsigned size);
  Block();

  /**
   * @brief Busca un elemento en el contenedor utilizando búsqueda lineal.
   * @param[in] k Clave del elemento a buscar.
   * @return Verdadero si se encontró el elemento.
   */
  bool search(const Key& k) const;

  /**
   * @brief Inserta un elemento al final del contenedor.
   * @param[in] k Clave del elemento a insertar.
   * @return Verdadero si se pudo insertar.
   */
  bool insert(const Key& k) override;
};

#include "Block.tpp"
#endif
