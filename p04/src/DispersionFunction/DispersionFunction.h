/**
 * @author Javier Padilla Pío
 * @date 14/03/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practice 4 - Búsqueda por dispersión
 * Email: alu0101410463@ull.edu.es
 * DispersionFunction.h: Interfaz de la clase DispersionFunction. Esta clase
 *                       abstracta representa una función de dispersión para
 *                       la clase HashTable.
 * Revision history:
 *                28/03/2022 - Creation (first version) of the code
 */

#ifndef DISPERSION_FUNCTION_H_
#define DISPERSION_FUNCTION_H_

template <class Key>
class DispersionFunction {
 public:
  DispersionFunction(unsigned table_size) : table_size_{table_size} {};

  /**
   * @brief Calcula la posición en la que guardar una clave en la tabla.
   * @param[in] k Clave a insertar
   * @return Posición en la que se guardará.
   */
  virtual unsigned operator()(const Key& k) const = 0;

 protected:
  unsigned table_size_;
};

#endif
