/**
 * @author Javier Padilla Pío
 * @date 14/03/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practice 3 - La vida en la frontera
 * Email: alu0101410463@ull.edu.es
 * GridWithDynamicBorder.h: Interfaz de una abstracción de la clase Grid.
 * Revision history:
 *                14/03/2022 - Creation (first version) of the code
 */

#ifndef GRID_WITH_DYNAMIC_BORDER_H_
#define GRID_WITH_DYNAMIC_BORDER_H_

#include <unordered_set>

#include "Grid.h"

class GridWithDynamicBorder : public Grid {
 public:
  GridWithDynamicBorder(int columns, int rows);

  GridWithDynamicBorder(std::string filename);

  ~GridWithDynamicBorder() override;

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
  enum side { top, right, bottom, left };

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

  /**
   * @brief Redimensiona la rejilla hacia un lado dado.
   * @param[in] overflowed_size Lado por el que se redimensionará.
   */
  void resize(side overflowed_size);

  /**
   * @brief Añade una fila muerta por encima de la rejilla.
   */
  Cell** resizeTop();

  /**
   * @brief Añade una columna muerta por la derecha de la rejilla.
   */
  Cell** resizeRight();

  /**
   * @brief Añade una fila muerta por debajo de la rejilla.
   */
  Cell** resizeBottom();

  /**
   * @brief Añade una columna muerta por la izquierda de la rejilla.
   */
  Cell** resizeLeft();
};
#endif
