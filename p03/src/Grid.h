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
 *                08/03/2022 - Update to practice 2 (second version) of the code
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

#ifndef GRID_H_
#define GRID_H_

#include <string.h>

#include <fstream>
#include <iostream>

#include "StateAlive.h"
#include "StateDead.h"

class Cell;

class Grid {
 public:
  Grid() = default;
  Grid(int columns, int rows);

  virtual ~Grid(){};

  /**
   * @brief Devuelve un objeto célula dada una posición en la rejilla.
   * @param[in] i Posición i de la rejilla.
   * @param[in] j Posición j de la regilla
   * @return Referencia constante a dicha célula.
   */
  virtual const Cell& getCell(int i, int j) const = 0;

  /**
   * @brief Computa la siguiente generación de la población.
   */
  virtual void nextGeneration();

  /**
   * @brief Operador para imprimir el estado de una rejilla por pantalla.
   * @param[out] output_stream Flujo de salida.
   * @param[in] grid Rejilla a imprimir.
   * @return El output_stream modificado.
   */
  friend std::ostream& operator<<(std::ostream& outputs_stream,
                                  const Grid& grid);

 protected:
  Cell** grid_;
  int columns_ = 0;
  int rows_ = 0;

  /**
   * @brief Método de ayuda llamado por los constructores para crear la
   * estructura grid_ una vez se sabe el número de columnas y filas. Todas las
   * células son inicializadas muertas.
   */
  virtual void constructGrid() = 0;

  /**
   * @brief Imprime el estado de la rejilla a través de un stream.
   * @param[out] output_stream Flujo de salida.
   * @return El output_stream modificado.
   */
  virtual std::ostream& print(std::ostream& output_stream) const = 0;
};

#endif
