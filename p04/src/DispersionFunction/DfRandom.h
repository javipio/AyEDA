/**
 * @author Javier Padilla Pío
 * @date 14/03/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practice 4 - Búsqueda por dispersión
 * Email: alu0101410463@ull.edu.es
 * DfRandom.h: Interfaz de la clase DfRandom. Implementa una función de
 *             dispersión basada en la dispersión aleatoria.
 * Revision history:
 *                28/03/2022 - Creation (first version) of the code
 */

#ifndef DF_RANDOM_H_
#define DF_RANDOM_H_

#include <cstdlib>

#include "DispersionFunction.h"

template <class Key>
class DfRandom : public DispersionFunction<Key> {
 public:
  using DispersionFunction<Key>::DispersionFunction;

  /**
   * @brief Calcula la posición en la que guardar una clave en la tabla.
   * @param[in] k Clave a insertar
   * @return Posición en la que se guardará.
   */
  unsigned operator()(const Key& k) const {
    srand(k);
    return rand() % this->table_size_;
  }
};

#endif
