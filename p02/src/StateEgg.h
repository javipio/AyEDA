/**
 * @author Javier Padilla Pío
 * @date 08/03/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practice 2 - Juego de la vida
 * Email: alu0101410463@ull.edu.es
 * StateEgg.h: Interfaz de la clase StateEgg, estado concreto de la clase
 *             State.
 * Revision history:
 *                08/03/2022 - Creation (first version) of the code
 */

#ifndef STATE_EGG_H_
#define STATE_EGG_H_

#include "State.h"

class StateEgg : public State {
 public:
  StateEgg() = default;

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
  int egg_neighbors_;
  int larva_neighbors_;
};
#endif
