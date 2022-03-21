/**
 * @author Javier Padilla Pío
 * @date 08/03/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practice 2 - Juego de la vida
 * Email: alu0101410463@ull.edu.es
 * StateAdult.h: Interfaz de la clase StateAdult, estado concreto de la clase
 *               State.
 * Revision history:
 *                08/03/2022 - Creation (first version) of the code
 */

#ifndef STATE_ADULT_H_
#define STATE_ADULT_H_

#include "State.h"

class StateAdult : public State {
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
  int adult_neighbors_;
};
#endif
