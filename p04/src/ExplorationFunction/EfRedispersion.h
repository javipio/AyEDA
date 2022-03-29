/**
 * @author Javier Padilla Pío
 * @date 14/03/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practice 4 - Búsqueda por dispersión
 * Email: alu0101410463@ull.edu.es
 * EfRedispersion.h: Interfaz de la clase EfRedispersion. Implementa una
 *                función de exploración de redispersión.
 * Revision history:
 *                28/03/2022 - Creation (first version) of the code
 */

#ifndef EF_REDISPERSION_H_
#define EF_REDISPERSION_H_

#include <cstdlib>

#include "ExplorationFunction.h"

template <class Key>
class EfRedispersion : public ExplorationFunction<Key> {
 public:
  EfRedispersion(unsigned table_size) : table_size_{table_size} {};

  /**
   * @brief Busca una nueva posición para un elemento a insertar en la tabla.
   * @param[in] k Elemento a realocar en la tabla.
   * @param[in] i Número de intento.
   * @return Offset para almacenar el elemento.
   */
  unsigned operator()(const Key& k, unsigned i) const {
    srand(k);
    for (int j = 1; j < i; j++) {
      rand();
    }

    return rand() % table_size_;
  }

 private:
  unsigned table_size_;
};

#endif
