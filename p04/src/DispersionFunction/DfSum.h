/**
 * @author Javier Padilla Pío
 * @date 14/03/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practice 4 - Búsqueda por dispersión
 * Email: alu0101410463@ull.edu.es
 * DfSum.h: Interfaz de la clase DfSum. Implementa una función de
 *          dispersión basada en la suma.
 * Revision history:
 *                28/03/2022 - Creation (first version) of the code
 */

#ifndef DF_SUM_H_
#define DF_SUM_H_

#include "DispersionFunction.h"

template <class Key>
class DfSum : public DispersionFunction<Key> {
 public:
  using DispersionFunction<Key>::DispersionFunction;

  /**
   * @brief Calcula la posición en la que guardar una clave en la tabla.
   * @param[in] k Clave a insertar
   * @return Posición en la que se guardará.
   */
  unsigned operator()(const Key& k) const {
    unsigned d = 0;
    unsigned x = k;

    while (x > 0) {
      unsigned y = x % 10;
      d += y;
      x /= 10;
    }

    return d % this->table_size_;
  }
};

#endif
