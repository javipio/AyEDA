/**
 * @author Javier Padilla Pío
 * @date 14/03/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practice 4 - Búsqueda por dispersión
 * Email: alu0101410463@ull.edu.es
 * EfLineal.h: Interfaz de la clase EfLineal. Implementa una función de
 *             exploración lineal.
 * Revision history:
 *                28/03/2022 - Creation (first version) of the code
 */

#ifndef EF_LINEAL_H_
#define EF_LINEAL_H_

#include "ExplorationFunction.h"

template <class Key>
class EfLineal : public ExplorationFunction<Key> {
 public:
  /**
   * @brief Busca una nueva posición para un elemento a insertar en la tabla.
   * @param[in] k Elemento a realocar en la tabla.
   * @param[in] i Número de intento.
   * @return Offset para almacenar el elemento.
   */
  unsigned operator()(const Key& k, unsigned i) const { return i; }
};

#endif
