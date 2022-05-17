/**
 * @author Javier Padilla Pío
 * @date 01/05/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practica 7 - Implementación de árboles binarios de búsqueda
 * Email: alu0101410463@ull.edu.es
 * ABB.tpp: Interfaz de la clase ABB, concreción de la clase AB.
 * Revision history:
 *                01/05/2022 - Creation (first version) of the code
 */

#ifndef ABB_H_
#define ABB_H_
#include <vector>

#include "AB.h"
template <class Key>
class ABB : public AB<Key> {
 public:
  using AB<Key>::AB;

  bool Insert(const Key k) override;
  bool Search(const Key& k) const override;
  bool Delete(const Key k) override;

 private:
  std::vector<Node<Key>*> get_neighbors(const Node<Key>* node) const;

  Node<Key>* extract_closest_low_node(Node<Key>* node);
};

#include "ABB.tpp"

#endif
