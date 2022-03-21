/**
 * @author Javier Padilla Pío
 * @date 08/03/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practice 2 - Juego de la vida
 * Email: alu0101410463@ull.edu.es
 * StatePupa.h: Interfaz de la clase StatePupa, estado concreto de la clase
 *              State.
 * Revision history:
 *                08/03/2022 - Creation (first version) of the code
 */

#ifndef STATE_PUPA_H
#define STATE_PUPA_H

#include "State.h"

class StatePupa : public State {
 public:
  /**
   * @brief Cuenta los vecinos de una célula.
   * @param[in] grid Rejilla que contiene las células.
   * @param[in] i posición i de la célula.
   * @param[in] j posición j de la célula.
   */
  void neighbors(const Grid& grid, int i, int j) override;

  /**
   * @brief Actualiza el estado teniendo en cuenta los vecinos de la célula,
   * previamente calculados.
   */
  State* nextState() override;

  /**
   * @brief Getter de state.
   */
  char getState() const override;

 private:
  int larva_neighbors_;
};
#endif
