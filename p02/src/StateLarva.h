/**
 * @author Javier Padilla Pío
 * @date 08/03/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practice 2 - Juego de la vida
 * Email: alu0101410463@ull.edu.es
 * StateLarva.h: Interfaz de la clase StateLarva, estado concreto de la clase
 *               State.
 * Revision history:
 *                08/03/2022 - Creation (first version) of the code
 */

#ifndef STATE_LARVA_H
#define STATE_LARVA_H

#include "State.h"

class StateLarva : public State {
 public:
  void neighbors(const Grid&, int i, int j);

  State* nextState();

  char getState() const;

 private:
  int larva_neighbors_;
  int not_dead_neighbors_;
};
#endif