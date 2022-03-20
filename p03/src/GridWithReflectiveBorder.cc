/**
 * @author Javier Padilla Pío
 * @date 14/03/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practice 3 - La vida en la frontera
 * Email: alu0101410463@ull.edu.es
 * Grid.cc: Implementación de la clase Grid.
 * Revision history:
 *                14/03/2022 - Creation (first version) of the code
 */

#include "GridWithReflectiveBorder.h"

#include "Cell.h"
#include "StateAlive.h"
#include "StateDead.h"

GridWithReflectiveBorder::GridWithReflectiveBorder(int columns, int rows) {
  columns_ = columns;
  rows_ = rows;
  constructGrid();
}

GridWithReflectiveBorder::GridWithReflectiveBorder(std::string filename) {
  std::ifstream input_file(filename);
  std::string line;

  // Se lee el número de columnas y filas.
  getline(input_file, line);
  rows_ = std::stoi(line);

  getline(input_file, line);
  columns_ = std::stoi(line);

  constructGrid();

  // Cambiar estado de las células que están vivas.
  int i = 0;
  while (getline(input_file, line)) {
    for (int j = 0; j < line.size(); j++) {
      if (line[j] != ' ') {
        grid_[i][j].setState(new StateAlive());
      }
    }

    i++;
  }

  input_file.close();
}

GridWithReflectiveBorder::~GridWithReflectiveBorder() {
  for (int i = 0; i < rows_; i++) {
    delete[] grid_[i];
  }
  delete[] grid_;
}

const Cell& GridWithReflectiveBorder::getCell(int i, int j) const {
  int parsed_i = i >= rows_ ? rows_ - (i - rows_ + 1) : i;
  int parsed_j = j >= columns_ ? columns_ - (j - columns_ + 1) : j;

  parsed_i = parsed_i < 0 ? 1 - parsed_i : parsed_i;
  parsed_j = parsed_j < 0 ? 1 - parsed_j : parsed_j;

  return grid_[parsed_i][parsed_j];
}

void GridWithReflectiveBorder::constructGrid() {
  grid_ = new Cell*[rows_];

  for (int i = 0; i < rows_; i++) {
    grid_[i] = new Cell[columns_];

    for (int j = 0; j < columns_; j++) {
      grid_[i][j] = Cell(i, j);
    }
  }
}

std::ostream& GridWithReflectiveBorder::print(
    std::ostream& output_stream) const {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < columns_; j++) {
      output_stream << getCell(i, j);
    }

    output_stream << "\n";
  }

  return output_stream;
}
