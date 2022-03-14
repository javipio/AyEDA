/**
 * @author Javier Padilla Pío
 * @date 08/03/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practice 2 - Juego de la vida
 * Email: alu0101410463@ull.edu.es
 * StateDead.cc: Implementación de la clase StateDead, estado concreto de la
 *                clase State.
 * Revision history:
 *                08/03/2022 - Creation (first version) of the code
 */

#include "StateDead.h"

#include "Cell.h"
#include "Grid.h"
#include "StateAlive.h"

State* StateDead::nextState() {
  if (alive_neighbors_ == 3) {
    return new StateAlive();
  }

  return new StateDead();
};

char StateDead::getState() const { return state_dead; };
