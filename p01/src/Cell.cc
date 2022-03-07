/**
 * @author Javier Padilla Pío
 * @date 04/03/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practice 1 - Juego de la vida
 * Email: alu0101410463@ull.edu.es
 * Cell.cc: Implementación de la clase Cell.
 * Revision history:
 *                04/03/2022 - Creation (first version) of the code
 */

#include "Cell.h"

Cell::Cell() = default;

Cell::Cell(int i, int j) : i_{i}, j_{j} { state_ = State::dead; }

State Cell::getState() const { return state_; }

State Cell::setState(State state) {
  state_ = state;
  return state_;
}

void Cell::updateState(int neighbors) {
  if (state_ == State::alive) {
    state_ = (neighbors == 3 || neighbors == 2) ? State::alive : State::dead;
  } else {
    state_ = neighbors == 3 ? State::alive : State::dead;
  }
}

int Cell::neighbors(const Grid& grid) {
  int alive_cells = 0;
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      if (i || j) alive_cells += grid.getCell(i_ + i, j_ + j).getState();
    }
  }

  return alive_cells;
}

std::ostream& operator<<(std::ostream& output_stream, const Cell& cell) {
  return output_stream << (cell.getState() == State::alive ? "x" : " ");
}
