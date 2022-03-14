/**
 * @author Javier Padilla Pío
 * @date 08/03/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practice 2 - Juego de la vida
 * Email: alu0101410463@ull.edu.es
 * StateAlive.h: Interfaz de la clase StateAlive, estado concreto de la clase
 *               State.
 * Revision history:
 *                08/03/2022 - Creation (first version) of the code
 */

#ifndef STATE_ALIVE_H_
#define STATE_ALIVE_H_

#include "State.h"

class StateAlive : public State {
 public:
  State* nextState();

  char getState() const;
};
#endif
