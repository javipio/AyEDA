/**
 * @author Javier Padilla Pío
 * @date 08/03/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practice 2 - Juego de la vida
 * Email: alu0101410463@ull.edu.es
 * Cell.cc: Implementación de la clase Cell.
 * Revision history:
 *                04/03/2022 - Creation (first version) of the code
 *                08/03/2022 - Update to practice 2 (second version) of the code
 */

#include "Cell.h"

#include "Grid.h"
#include "StateDead.h"

Cell::Cell() { state_ = new StateDead(); }

Cell::Cell(int i, int j) : i_{i}, j_{j} { state_ = new StateDead(); }

char Cell::getState() const { return state_->getState(); }

void Cell::setState(State* state) {
  delete state_;
  state_ = state;
}

void Cell::updateState() { setState(state_->nextState()); }

void Cell::neighbors(const Grid& grid) {
  return state_->neighbors(grid, i_, j_);
}

std::ostream& operator<<(std::ostream& output_stream, const Cell& cell) {
  return output_stream << cell.getState() << ' ';
}
