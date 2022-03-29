/**
 * @author Javier Padilla Pío
 * @date 14/03/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practice 4 - Búsqueda por dispersión
 * Email: alu0101410463@ull.edu.es
 * EfDoubleDispersion.h: Interfaz de la clase EfDoubleDispersion. Implementa una
 *                función de exploración de doble dispersión.
 * Revision history:
 *                28/03/2022 - Creation (first version) of the code
 */

#ifndef EF_DOUBLE_DISPERSION_H_
#define EF_DOUBLE_DISPERSION_H_

#include "../DispersionFunction/DispersionFunction.h"
#include "ExplorationFunction.h"

template <class Key>
class EfDoubleDispersion : public ExplorationFunction<Key> {
 public:
  EfDoubleDispersion(DispersionFunction<Key>* alternative_function)
      : alternative_function_{alternative_function} {};

  ~EfDoubleDispersion() { delete alternative_function_; }

  /**
   * @brief Busca una nueva posición para un elemento a insertar en la tabla.
   * @param[in] k Elemento a realocar en la tabla.
   * @param[in] i Número de intento.
   * @return Offset para almacenar el elemento.
   */
  unsigned operator()(const Key& k, unsigned i) const {
    return ((*alternative_function_)(k)) * i;
  }

 private:
  DispersionFunction<Key>* alternative_function_;
};

#endif
