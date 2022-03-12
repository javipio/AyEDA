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
 *               clase State.
 * Revision history:
 *                08/03/2022 - Creation (first version) of the code
 */

#include "StateDead.h"

#include "Cell.h"
#include "Grid.h"
#include "StateEgg.h"

void StateDead::neighbors(const Grid& grid, int i, int j) {
  adult_neighbors_ = 0;

  for (int i_offset = -1; i_offset <= 1; i_offset++) {
    for (int j_offset = -1; j_offset <= 1; j_offset++) {
      if (!(i_offset || j_offset)) continue;

      adult_neighbors_ +=
          grid.getCell(i + i_offset, j + j_offset).getState() == state_adult;
    }
  }
};

State* StateDead::nextState() {
  if (adult_neighbors_ >= 2) {
    return new StateEgg();
  }
  return new StateDead();
};

char StateDead::getState() const { return state_dead; };
