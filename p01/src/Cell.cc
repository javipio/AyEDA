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

Cell::Cell(int i, int j) : i_{i}, j_{j} { state_ = State::ne; }

State Cell::getState() const { return state_; }

State Cell::setState(State state) {
  state_ = state;
  return state_;
}

void Cell::updateState(int neighbors) {
  // if (state_ == State::alive) {
  //   state_ = (neighbors == 3 || neighbors == 2) ? State::alive : State::dead;
  // } else {
  //   state_ = neighbors == 3 ? State::alive : State::dead;
  // }
  state_ = static_cast<State>(neighbors);
}

int Cell::neighbors(const Grid& grid) {
  std::unordered_map<State, int> surrounding;

  State largest = grid.getCell(i_ - 1, j_ - 1).getState();

  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      if (i || j) {
        // if (i || j) alive_cells += grid.getCell(i_ + i, j_ + j).getState();

        State cell_state = grid.getCell(i_ + i, j_ + j).getState();

        if (surrounding.find(cell_state) == surrounding.end()) {
          surrounding[cell_state] = 1;
        } else {
          surrounding[cell_state]++;
        }

        if (surrounding[cell_state] == cell_state) {
          largest = cell_state;
        }
      };
    }
  }

  if (surrounding[largest] != largest) {
    largest = State::ne;
  }

  return largest;
}

std::ostream& operator<<(std::ostream& output_stream, const Cell& cell) {
  switch (cell.getState()) {
    case State::ne:
      return output_stream << "ne";
    case State::r:
      return output_stream << "r ";
    case State::az:
      return output_stream << "az";
    case State::am:
      return output_stream << "am";
    case State::v:
      return output_stream << "v ";
    case State::na:
      return output_stream << "na";
    case State::p:
      return output_stream << "p ";
    case State::b:
      return output_stream << "b ";
    case State::g:
      return output_stream << "g ";
    default:
      return output_stream << ' ';
  }
}
