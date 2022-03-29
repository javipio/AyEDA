/**
 * @author Javier Padilla Pío
 * @date 14/03/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practice 4 - Búsqueda por dispersión
 * Email: alu0101410463@ull.edu.es
 * List.h: Interfaz de la clase List. Implementa una lista de tamaño dinámico.
 * Revision history:
 *                28/03/2022 - Creation (first version) of the code
 */

#ifndef LIST_H_
#define LIST_H_

#include <string.h>

#include "Sequence.h"

template <class Key>
class List : public Sequence<Key> {
 public:
  List();

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

  /**
   * @brief Determina si el contenedor está lleno.
   * @return Siempre devuelve falso ya que la lista se redimensiona
   *         dinámicamente.
   */
  bool isFull() const override;

 private:
  void resize(unsigned new_size);
};

#include "List.tpp"
#endif
