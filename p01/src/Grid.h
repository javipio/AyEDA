/**
 * @author Javier Padilla Pío
 * @date 04/03/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practice 1 - Juego de la vida
 * Email: alu0101410463@ull.edu.es
 * Grid.h: Interfaz de la clase Grid.
 * Revision history:
 *                04/03/2022 - Creation (first version) of the code
 *
 * Los ficheros que guardan la información de la rejilla siguen la siguiente
 * estructura:
//////////////////////////////////
 * 2
 * 7
 *  x   x
 * xx  xxx
//////////////////////////////////
 * Las dos primeras líneas indican el número de filas y columnas
 * respectivamente. A continuación se especifica la rejilla siendo espacios
 * células muertas.
 */

#include "Cell.h"

#ifndef GRID_H_
#define GRID_H_

#include <fstream>
#include <iostream>

class Grid {
 public:
  Grid(int columns, int rows);

  Grid(std::string filename);

  ~Grid();

  /**
   * @brief Devuelve un objeto célula dada una posición en la rejilla.
   * @param[in] i Posición i de la rejilla.
   * @param[in] j Posición j de la regilla
   * @return Referencia constante a dicha célula.
   */
  const Cell& getCell(int i, int j) const;

  /**
   * @brief Computa la siguiente generación de la población.
   */
  void nextGeneration();

  friend std::ostream& operator<<(std::ostream& output_stream,
                                  const Grid& grid);

 private:
  Cell** grid_;
  int columns_ = 0;
  int rows_ = 0;

  /**
   * @brief Método de ayuda llamado por los constructores para crear la
   * estructura grid_ una vez se sabe el número de columnas y filas. Todas las
   * células son inicializadas muertas.
   */
  void constructGrid();
};

#endif