/**
 * @author Javier Padilla Pío
 * @date 08/03/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practice 2 - Juego de la vida
 * Email: alu0101410463@ull.edu.es
 * StateAdult.cc: Implementación de la clase StateAdult, estado concreto de la
 *                clase State.
 * Revision history:
 *                08/03/2022 - Creation (first version) of the code
 */

#include "StateAdult.h"

#include "Cell.h"
#include "Grid.h"
#include "StateDead.h"
#include "StateEgg.h"

void StateAdult::neighbors(const Grid& grid, int i, int j) {
  adult_neighbors_ = 0;

  for (int i_offset = -1; i_offset <= 1; i_offset++) {
    for (int j_offset = -1; j_offset <= 1; j_offset++) {
      if (!(i_offset || j_offset)) continue;

      adult_neighbors_ +=
          grid.getCell(i + i_offset, j + j_offset).getState() == state_adult;
    }
  }
};

State* StateAdult::nextState() {
  if (adult_neighbors_) {
    return new StateEgg();
  }
  return new StateDead();
};

char StateAdult::getState() const { return state_adult; };
