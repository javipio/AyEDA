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

#include "GridWithDynamicBorder.h"

#include "Cell.h"
#include "StateAlive.h"
#include "StateDead.h"

GridWithDynamicBorder::GridWithDynamicBorder(int columns, int rows) {
  columns_ = columns;
  rows_ = rows;
  constructGrid();
}

GridWithDynamicBorder::GridWithDynamicBorder(std::string filename) {
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
  while (getline(input_file, line) && i <= rows_) {
    for (int j = 0; j < line.size() && j < columns_; j++) {
      if (line[j] != ' ') {
        grid_[i][j + 1].setState(new StateAlive());
      }
    }

    i++;
  }

  input_file.close();
}

GridWithDynamicBorder::~GridWithDynamicBorder() {
  for (int i = 0; i < rows_ + 2; i++) {
    delete[] grid_[i];
  }
  delete[] grid_;
}

const Cell& GridWithDynamicBorder::getCell(int i, int j) const {
  return grid_[i][j];
}

void GridWithDynamicBorder::nextGeneration() {
  for (int i = 1; i < rows_ + 1; i++) {
    for (int j = 1; j < columns_ + 1; j++) {
      grid_[i][j].neighbors(*this);
    }
  }

  std::unordered_set<side> overflow;
  for (int i = 1; i < rows_ + 1; i++) {
    for (int j = 1; j < columns_ + 1; j++) {
      grid_[i][j].updateState();

      if (grid_[i][j].getState() == State::state_alive) {
        if (i == 1) overflow.insert(top);
        if (i == rows_) overflow.insert(bottom);
        if (j == 1) overflow.insert(left);
        if (j == columns_) overflow.insert(right);
      }
    }
  }

  for (const auto sd : overflow) {
    resize(sd);
  }
}

void GridWithDynamicBorder::constructGrid() {
  grid_ = new Cell*[rows_ + 2];

  for (int i = 0; i < rows_ + 2; i++) {
    grid_[i] = new Cell[columns_ + 2];

    for (int j = 0; j < columns_ + 2; j++) {
      grid_[i][j] = Cell(i, j);
    }
  }
}

Cell** GridWithDynamicBorder::resizeTop() {
  rows_++;
  Cell** new_grid = new Cell*[rows_ + 2];

  for (int i = 0; i < rows_ + 2; i++) {
    new_grid[i] = new Cell[columns_ + 2];

    for (int j = 0; j < columns_ + 2; j++) {
      new_grid[i][j] = Cell(i, j);

      if (i && grid_[i - 1][j].getState() == State::state_alive) {
        new_grid[i][j].setState(new StateAlive());
      }
    }
  }
  return new_grid;
}

Cell** GridWithDynamicBorder::resizeRight() {
  columns_++;
  Cell** new_grid = new Cell*[rows_ + 2];

  for (int i = 0; i < rows_ + 2; i++) {
    new_grid[i] = new Cell[columns_ + 2];

    for (int j = 0; j < columns_ + 1; j++) {
      new_grid[i][j] = Cell(i, j);

      if (grid_[i][j].getState() == State::state_alive) {
        new_grid[i][j].setState(new StateAlive());
      }
    }
    new_grid[i][columns_ + 1] = Cell(i, columns_ + 1);
  }
  return new_grid;
}

Cell** GridWithDynamicBorder::resizeBottom() {
  rows_++;
  Cell** new_grid = new Cell*[rows_ + 2];

  for (int i = 0; i < rows_ + 1; i++) {
    new_grid[i] = grid_[i];
    grid_[i] = nullptr;
  }

  new_grid[rows_ + 1] = new Cell[columns_ + 2];

  for (int j = 0; j < columns_ + 2; j++) {
    new_grid[rows_ + 1][j] = Cell(rows_ + 1, j);
  }

  return new_grid;
}

Cell** GridWithDynamicBorder::resizeLeft() {
  columns_++;
  Cell** new_grid = new Cell*[rows_ + 2];

  for (int i = 0; i < rows_ + 2; i++) {
    new_grid[i] = new Cell[columns_ + 2];
    new_grid[i][0] = Cell(i, 0);

    for (int j = 1; j < columns_ + 2; j++) {
      new_grid[i][j] = Cell(i, j);

      if (grid_[i][j - 1].getState() == State::state_alive) {
        new_grid[i][j].setState(new StateAlive());
      }
    }
  }

  return new_grid;
}

void GridWithDynamicBorder::resize(side overflowed_side) {
  Cell** new_grid;

  int prev_rows = rows_;

  switch (overflowed_side) {
    case top:
      new_grid = resizeTop();
      break;
    case right:
      new_grid = resizeRight();
      break;
    case bottom:
      new_grid = resizeBottom();
      break;
    case left:
      new_grid = resizeLeft();
      break;
  }

  for (int i = 0; i < prev_rows + 2; i++) {
    delete[] grid_[i];
  }

  delete[] grid_;

  grid_ = new_grid;
}

std::ostream& GridWithDynamicBorder::print(std::ostream& output_stream) const {
  for (int i = 1; i < rows_ + 1; i++) {
    for (int j = 1; j < columns_ + 1; j++) {
      output_stream << getCell(i, j);
    }

    output_stream << "\n";
  }

  return output_stream << std::endl;
}
