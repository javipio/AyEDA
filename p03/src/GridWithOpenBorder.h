/**
 * @author Javier Padilla Pío
 * @date 14/03/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practice 3 - La vida en la frontera
 * Email: alu0101410463@ull.edu.es
 * GridWithOpenBorder.h: Interfaz de una abstracción de la clase Grid.
 * Revision history:
 *                14/03/2022 - Creation (first version) of the code
 */

#ifndef GRID_WITH_OPEN_BORDER_H_
#define GRID_WITH_OPEN_BORDER_H_

#include "Grid.h"

class GridWithOpenBorder : public Grid {
 public:
  GridWithOpenBorder(int columns, int rows);

  GridWithOpenBorder(std::string filename);

  ~GridWithOpenBorder() override;

  /**
   * @brief Devuelve un objeto célula dada una posición en la rejilla.
   * @param[in] i Posición i de la rejilla.
   * @param[in] j Posición j de la regilla
   * @return Referencia constante a dicha célula.
   */
  const Cell& getCell(int i, int j) const override;

  /**
   * @brief Computa la siguiente generación de la población.
   */
  void nextGeneration() override;

 private:
  /**
   * @brief Método de ayuda llamado por los constructores para crear la
   * estructura grid_ una vez se sabe el número de columnas y filas. Todas las
   * células son inicializadas muertas.
   */
  void constructGrid() override;

  /**
   * @brief Imprime el estado de la rejilla a través de un stream.
   * @param[out] output_stream Flujo de salida.
   * @return El output_stream modificado.
   */
  std::ostream& print(std::ostream&) const override;
};
#endif
