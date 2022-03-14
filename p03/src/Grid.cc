#include "Grid.h"

#include "Cell.h"

Grid::Grid(int columns, int rows) : columns_{columns}, rows_{rows} {}

std::ostream& operator<<(std::ostream& output_stream, const Grid& grid) {
  return grid.print(output_stream);
}
