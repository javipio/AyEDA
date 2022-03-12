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

#include "Grid.h"

#include "Cell.h"

Grid::Grid(int columns, int rows) : columns_{columns}, rows_{rows} {
  constructGrid();
}

Grid::Grid(std::string filename) {
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
        State* new_state = nullptr;

        switch (line[j]) {
          case State::state_adult:
            new_state = new StateAdult();
            break;
          case State::state_egg:
            new_state = new StateEgg();
            break;
          case State::state_larva:
            new_state = new StateLarva();
            break;
          case State::state_pupa:
            new_state = new StatePupa();
            break;
          case State::state_dead:
          default:
            break;
        }

        grid_[i][j + 1].setState(new_state);
      }
    }

    i++;
  }

  input_file.close();
}

Grid::~Grid() {
  for (int i = 0; i < rows_ + 2; i++) {
    delete[] grid_[i];
  }
  delete[] grid_;
}

const Cell& Grid::getCell(int i, int j) const { return grid_[i][j]; }

void Grid::nextGeneration() {
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

std::ostream& operator<<(std::ostream& output_stream, const Grid& grid) {
  for (int i = 1; i < grid.rows_ + 1; i++) {
    for (int j = 1; j < grid.columns_ + 1; j++) {
      output_stream << grid.getCell(i, j);
    }

    output_stream << "\n";
  }

  return output_stream << std::endl;
}

void Grid::constructGrid() {
  grid_ = new Cell*[rows_ + 2];

  for (int i = 0; i < rows_ + 2; i++) {
    grid_[i] = new Cell[columns_ + 2];

    for (int j = 0; j < columns_ + 2; j++) {
      grid_[i][j] = Cell(i, j);
    }
  }
}
