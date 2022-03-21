/**
 * @author Javier Padilla Pío
 * @date 04/03/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practice 1 - Juego de la vida
 * Email: alu0101410463@ull.edu.es
 * Grid.cc: Implementación de la clase Grid.
 * Revision history:
 *                04/03/2022 - Creation (first version) of the code
 *                08/03/2022 - Update to practice 2 (second version) of the code
 */

#include "Grid.h"

#include "Cell.h"

Grid::Grid(int columns, int rows) : columns_{columns}, rows_{rows} {}

std::ostream& operator<<(std::ostream& output_stream, const Grid& grid) {
  return grid.print(output_stream);
}

void Grid::nextGeneration() {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < columns_; j++) {
      grid_[i][j].neighbors(*this);
    }
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < columns_; j++) {
      grid_[i][j].updateState();
    }
  }
}
