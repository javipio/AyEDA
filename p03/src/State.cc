#include "State.h"

#include "Cell.h"
#include "Grid.h"

void State::neighbors(const Grid& grid, int i, int j) {
  for (int i_offset = -1; i_offset <= 1; i_offset++) {
    for (int j_offset = -1; j_offset <= 1; j_offset++) {
      if (!(i_offset || j_offset)) continue;
      alive_neighbors_ +=
          grid.getCell(i + i_offset, j + j_offset).getState() == state_alive;
    }
  }
}