/**
 * @author Javier Padilla Pío
 * @date 14/03/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practice 4 - Búsqueda por dispersión
 * Email: alu0101410463@ull.edu.es
 * ExplorationFunction.h: Interfaz de la clase ExplorationFunction. Esta clase
 *                        abstracta representa una función de exploración para
 *                        la clase HashTable.
 * Revision history:
 *                28/03/2022 - Creation (first version) of the code
 */

#ifndef EXPLORATION_FUNCTION_H_
#define EXPLORATION_FUNCTION_H_

template <class Key>
class ExplorationFunction {
 public:
  virtual ~ExplorationFunction() {}
  /**
   * @brief Busca una nueva posición para un elemento a insertar en la tabla.
   * @param[in] k Elemento a realocar en la tabla.
   * @param[in] i Número de intento.
   * @return Offset para almacenar el elemento.
   */
  virtual unsigned operator()(const Key& k, unsigned i) const = 0;
};

#endif
