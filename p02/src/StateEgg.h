/**
 * @author Javier Padilla Pío
 * @date 08/03/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practice 2 - Juego de la vida
 * Email: alu0101410463@ull.edu.es
 * StateEgg.h: Interfaz de la clase StateEgg, estado concreto de la clase
 *             State.
 * Revision history:
 *                08/03/2022 - Creation (first version) of the code
 */

#ifndef STATE_EGG_H_
#define STATE_EGG_H_

#include "State.h"

class StateEgg : public State {
 public:
  StateEgg() = default;

  void neighbors(const Grid&, int i, int j);

  State* nextState();

  char getState() const;

 private:
  int egg_neighbors_;
  int larva_neighbors_;
};
#endif
