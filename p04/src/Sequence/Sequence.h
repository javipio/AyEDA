/**
 * @author Javier Padilla Pío
 * @date 14/03/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practice 4 - Búsqueda por dispersión
 * Email: alu0101410463@ull.edu.es
 * Sequence.h: Interfaz de la clase Sequence. Esta clase abstracta describe un
 *             contenedor con las operaciones básicas de lectura y escritura.
 * Revision history:
 *                28/03/2022 - Creation (first version) of the code
 */

#ifndef SEQUENCE_H_
#define SEQUENCE_H_

template <class Key>
class Sequence {
 public:
  Sequence() = default;

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
  virtual bool insert(const Key& k) = 0;

  /**
   * @brief Determina si el contenedor está lleno.
   * @return Verdadero si está lleno.
   */
  virtual bool isFull() const;

 protected:
  Key* sequence_;
  unsigned occupied_ = 0;
  unsigned size_ = 0;
};

#include "Sequence.tpp"
#endif
