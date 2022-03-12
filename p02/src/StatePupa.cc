/**
 * @author Javier Padilla Pío
 * @date 08/03/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practice 2 - Juego de la vida
 * Email: alu0101410463@ull.edu.es
 * StatePupa.h: Implementación de la clase StatePupa, estado concreto de la
 *              clase State.
 * Revision history:
 *                08/03/2022 - Creation (first version) of the code
 */

#include "StatePupa.h"

#include "Cell.h"
#include "Grid.h"
#include "StateAdult.h"
#include "StateDead.h"

void StatePupa::neighbors(const Grid& grid, int i, int j) {
  larva_neighbors_ = 0;

  for (int i_offset = -1; i_offset <= 1; i_offset++) {
    for (int j_offset = -1; j_offset <= 1; j_offset++) {
      if (!(i_offset || j_offset)) continue;

      larva_neighbors_ +=
          grid.getCell(i + i_offset, j + j_offset).getState() == state_larva;
    }
  }
};

State* StatePupa::nextState() {
  if (larva_neighbors_ <= 4) {
    return new StateAdult();
  }
  return new StateDead();
};

char StatePupa::getState() const { return state_larva; };
