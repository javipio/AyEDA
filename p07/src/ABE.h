/**
 * @author Javier Padilla Pío
 * @date 01/05/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practice 6 - Implementación de árboles binarios equilibrados
 * Email: alu0101410463@ull.edu.es
 * ABE.h: Interfaz de la clase ABE concreción de la clase AB.
 * Revision history:
 *                01/05/2022 - Creation (first version) of the code
 */

#ifndef ABE_H_
#define ABE_H_

#include <iostream>
#include <queue>

#include "AB.h"

template <class Key>
class ABE : public AB<Key> {
 public:
  using AB<Key>::AB;

  bool Insert(const Key k) override;
  bool Search(const Key& k) const override;
  bool Delete(const Key k) override;
};

#include "ABE.tpp"

#endif
