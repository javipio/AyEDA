/**
 * @author Javier Padilla Pío
 * @date 04/03/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practice 1 - Juego de la vida
 * Email: alu0101410463@ull.edu.es
 * Cell.h: Interfaz de la clase Cell.
 * Revision history:
 *                04/03/2022 - Creation (first version) of the code
 */

#ifndef CELL_H_
#define CELL_H_
#include <iostream>
#include <vector>

class Cell;
#include "Grid.h"

#ifndef CELL_C_
#define CELL_C_
enum State {
  dead,
  alive,
};

class Cell {
 public:
  Cell();
  Cell(int i, int j);

  /**
   * @brief Devuelve el estado interno de una célula.
   */
  State getState() const;

  /**
   * @brief Modifica el estado interno de una célula.
   */
  State setState(State state);

  /**
   * @brief Actualza el estado de la célula siguiendo las reglas descritas según
   * el juego de la vida.
   * @param[in] neighbors Vecinos vivos.
   */
  void updateState(int neighbors);

  /**
   * @brief Contabiliza el número de vecinos vivvos de una célula.
   * @param[in] grid Rejilla que contiene a la instancia de la célula.
   * @return Número de vecinos vivos.
   */
  int neighbors(const Grid& grid);

 private:
  int i_ = -1;
  int j_ = -1;
  State state_;
};

std::ostream& operator<<(std::ostream&, const Cell&);
#endif
#endif
