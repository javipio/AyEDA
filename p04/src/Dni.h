/**
 * @author Javier Padilla Pío
 * @date 14/03/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practice 3 - La vida en el borde
 * Email: alu0101410463@ull.edu.es
 * Dni.h: Interfaz de la clase Dni que alamacena un Dni.
 * Revision history:
 *                04/04/2022 - Creation (first version) of the code
 */

#ifndef DNI_H_
#define DNI_H_

#include <iostream>

class Dni {
 public:
  Dni();
  Dni(unsigned number, char fist_letter, char last_letter);
  Dni(std::string raw_dni);

  operator unsigned() const;

 private:
  unsigned number_ = 0;
  char first_letter_ = 'X';
  char last_letter_ = 'X';
};
#endif
