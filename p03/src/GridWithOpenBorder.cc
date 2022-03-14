/**
 * @author Javier Padilla Pío
 * @date 08/03/2022
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

#include "GridWithOpenBorder.h"

#include "Cell.h"
#include "StateAlive.h"
#include "StateDead.h"

GridWithOpenBorder::GridWithOpenBorder(int columns, int rows) {
  constructGrid();
}

GridWithOpenBorder::GridWithOpenBorder(std::string filename) {
  std::ifstream input_file(filename);
  std::string line;

  // Se lee el número de columnas y filas.
  getline(input_file, line);
  rows_ = std::stoi(line);

  getline(input_file, line);
  columns_ = std::stoi(line);

  constructGrid();

  // Cambiar estado de las células que están vivas.
  int i = 1;
  while (getline(input_file, line)) {
    for (int j = 0; j < line.size(); j++) {
      if (line[j] != ' ') {
        grid_[i][j + 1].setState(new StateAlive());
      }
    }

    i++;
  }

  input_file.close();
}

GridWithOpenBorder::~GridWithOpenBorder() {
  for (int i = 0; i < rows_ + 2; i++) {
    delete[] grid_[i];
  }
  delete[] grid_;
}

const Cell& GridWithOpenBorder::getCell(int i, int j) const {
  return grid_[i][j];
}

void GridWithOpenBorder::nextGeneration() {
  for (int i = 1; i < rows_ + 1; i++) {
    for (int j = 1; j < columns_ + 1; j++) {
      grid_[i][j].neighbors(*this);
    }
  }
  for (int i = 1; i < rows_ + 1; i++) {
    for (int j = 1; j < columns_ + 1; j++) {
      grid_[i][j].updateState();
    }
  }
}

void GridWithOpenBorder::constructGrid() {
  grid_ = new Cell*[rows_ + 2];

  for (int i = 0; i < rows_ + 2; i++) {
    grid_[i] = new Cell[columns_ + 2];

    for (int j = 0; j < columns_ + 2; j++) {
      grid_[i][j] = Cell(i, j);
    }
  }
}

std::ostream& GridWithOpenBorder::print(std::ostream& output_stream) const {
  for (int i = 1; i < rows_ + 1; i++) {
    for (int j = 1; j < columns_ + 1; j++) {
      output_stream << getCell(i, j);
    }

    output_stream << "\n";
  }

  return output_stream << std::endl;
}
