/**
 * @author Javier Padilla Pío
 * @date 01/05/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practica 7 - Implementación de árboles binarios de búsqueda
 * Email: alu0101410463@ull.edu.es
 * Node.h: Interfaz de la clase Node que representa un nodo del arbol.
 * Revision history:
 *                01/05/2022 - Creation (first version) of the code
 */

#ifndef NODE_H_
#define NODE_H_

template <class Key>
class Node {
 public:
  Node(Key value, Node<Key>* left = nullptr, Node<Key>* right = nullptr);

  Node<Key>* right();
  Node<Key>* left();

  void set_right(Node<Key>* node);
  void set_left(Node<Key>* node);

  Key value() const;

 protected:
  Key value_;
  Node<Key>* left_;
  Node<Key>* right_;
};

#include "Node.tpp"

#endif