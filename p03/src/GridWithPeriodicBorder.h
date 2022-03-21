/**
 * @author Javier Padilla Pío
 * @date 14/03/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practice 3 - La vida en la frontera
 * Email: alu0101410463@ull.edu.es
 * GridWithPeriodicBorder.cc: Implementación de una abstracción de la clase
 *                              Grid.
 * Revision history:
 *                14/03/2022 - Creation (first version) of the code
 */

#ifndef GRID_WITH_PERIODIC_BORDER_H_
#define GRID_WITH_PERIODIC_BORDER_H_

#include "Grid.h"

class GridWithPeriodicBorder : public Grid {
 public:
  GridWithPeriodicBorder(int columns, int rows);

  GridWithPeriodicBorder(std::string filename);

  ~GridWithPeriodicBorder() override;

  /**
   * @brief Devuelve un objeto célula dada una posición en la rejilla.
   * @param[in] i Posición i de la rejilla.
   * @param[in] j Posición j de la regilla
   * @return Referencia constante a dicha célula.
   */
  const Cell& getCell(int i, int j) const override;

 private:
  /**
   * @brief Método de ayuda llamado por los constructores para crear la
   * estructura grid_ una vez se sabe el número de columnas y filas. Todas las
   * células son inicializadas muertas.
   */
  void constructGrid();

  /**
   * @brief Imprime el estado de la rejilla a través de un stream.
   * @param[out] output_stream Flujo de salida.
   * @return El output_stream modificado.
   */
  std::ostream& print(std::ostream&) const;
};
#endif
