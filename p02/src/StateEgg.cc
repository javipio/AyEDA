/**
 * @author Javier Padilla Pío
 * @date 08/03/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practice 2 - Juego de la vida
 * Email: alu0101410463@ull.edu.es
 * StateEgg.cc: Implementación de la clase StateEgg, estado concreto de la clase
 *              State.
 * Revision history:
 *                08/03/2022 - Creation (first version) of the code
 */

#include "StateEgg.h"

#include "Cell.h"
#include "Grid.h"
#include "StateDead.h"
#include "StateLarva.h"

void StateEgg::neighbors(const Grid& grid, int i, int j) {
  egg_neighbors_ = 0;
  larva_neighbors_ = 0;

  for (int i_offset = -1; i_offset <= 1; i_offset++) {
    for (int j_offset = -1; j_offset <= 1; j_offset++) {
      if (!(i_offset || j_offset)) continue;

      egg_neighbors_ +=
          grid.getCell(i + i_offset, j + j_offset).getState() == state_egg;
      larva_neighbors_ +=
          grid.getCell(i + i_offset, j + j_offset).getState() == state_larva;
    }
  }
};

State* StateEgg::nextState() {
  if (larva_neighbors_ > egg_neighbors_) {
    return new StateDead();
  }
  return new StateLarva();
};

char StateEgg::getState() const { return state_egg; };
