/**
 * @author Javier Padilla Pío
 * @date 08/03/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practice 2 - Juego de la vida
 * Email: alu0101410463@ull.edu.es
 * StateLarva.cc: Implementación de la clase StateLarva, estado concreto de la
 *                clase State.
 * Revision history:
 *                08/03/2022 - Creation (first version) of the code
 */

#include "StateLarva.h"

#include "Cell.h"
#include "Grid.h"
#include "StateDead.h"
#include "StatePupa.h"

void StateLarva::neighbors(const Grid& grid, int i, int j) {
  larva_neighbors_ = 0;
  not_dead_neighbors_ = 0;

  for (int i_offset = -1; i_offset <= 1; i_offset++) {
    for (int j_offset = -1; j_offset <= 1; j_offset++) {
      if (!(i_offset || j_offset)) continue;

      char cell_state = grid.getCell(i + i_offset, j + j_offset).getState();

      if (cell_state == state_larva) {
        larva_neighbors_++;
      } else if (cell_state != state_dead) {
        not_dead_neighbors_++;
      }
    }
  }
};

State* StateLarva::nextState() {
  if (larva_neighbors_ <= not_dead_neighbors_) {
    return new StatePupa();
  }
  return new StateDead();
};

char StateLarva::getState() const { return state_larva; };
