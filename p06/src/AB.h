/**
 * @author Javier Padilla Pío
 * @date 01/05/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practice 6 - Implementación de árboles binarios equilibrados
 * Email: alu0101410463@ull.edu.es
 * AB.h: Interfaz de la clase abstracta AB que representa un arbol binario.
 * Revision history:
 *                01/05/2022 - Creation (first version) of the code
 */

#ifndef AB_H_
#define AB_H_

#include <iostream>
#include <queue>
#include <stack>

#include "Node.h"

template <class Key>
class AB {
 public:
  AB(Node<Key>* root = nullptr) : root_{root} {};

  virtual bool Insert(const Key k) = 0;
  virtual bool Search(const Key& k) const = 0;
  void Inorder() const;

  void Print(std::ostream& output_stream) const;

 protected:
  Node<Key>* root_;
};

#include "AB.tpp"

#endif
