/**
 * @author Javier Padilla Pío
 * @date 08/03/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practice 2 - Juego de la vida
 * Email: alu0101410463@ull.edu.es
 * StateAlive.cc: Implementación de la clase StateAlive, estado concreto de la
 *                clase State.
 * Revision history:
 *                08/03/2022 - Creation (first version) of the code
 */

#include "StateAlive.h"

#include "Cell.h"
#include "Grid.h"
#include "StateDead.h"

State* StateAlive::nextState() {
  if (alive_neighbors_ == 3 || alive_neighbors_ == 2) {
    return new StateAlive();
  }

  return new StateDead();
};

char StateAlive::getState() const { return state_alive; };
