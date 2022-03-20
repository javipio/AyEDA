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