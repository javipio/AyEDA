/**
 * @author Javier Padilla Pío
 * @date 14/03/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practice 3 - La vida en el borde
 * Email: alu0101410463@ull.edu.es
 * Dni.cc: Interfaz de la clase Dni que alamacena un Dni.
 * Revision history:
 *                04/04/2022 - Creation (first version) of the code
 */

#include "Dni.h"

Dni::Dni() = default;

Dni::Dni(std::string raw_dni) {
  if (raw_dni.size() < 10) {
    return;
  }

  first_letter_ = raw_dni[0];
  last_letter_ = raw_dni[9];
  number_ = stoi(raw_dni.substr(1, 8));
}

Dni::Dni(unsigned number, char fist_letter, char last_letter)
    : number_{number}, first_letter_{fist_letter}, last_letter_{last_letter} {};

Dni::operator unsigned() const {
  return number_ + static_cast<unsigned>(first_letter_) +
         static_cast<unsigned>(last_letter_);
}
