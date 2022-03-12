/**
 * @author Javier Padilla Pío
 * @date 08/03/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practice 2 - Juego de la vida
 * Email: alu0101410463@ull.edu.es
 * State.h: Interfaz de la clase State.
 * Revision history:
 *                08/03/2022 - Creation (first version) of the code
 */

#ifndef STATE_H_
#define STATE_H_

class Grid;

class State {
 public:
  static const char state_dead = 'd';
  static const char state_egg = 'e';
  static const char state_larva = 'l';
  static const char state_pupa = 'p';
  static const char state_adult = 'a';

  /**
   * @brief Cuenta los vecinos de una célula.
   * @param[in] grid Rejilla que contiene las células.
   * @param[in] i posición i de la célula.
   * @param[in] j posición j de la célula.
   */
  virtual void neighbors(const Grid& grid, int i, int j) = 0;

  /**
   * @brief Actualiza el estado teniendo en cuenta los vecinos de la célula,
   * previamente calculados.
   */
  virtual State* nextState() = 0;

  /**
   * @brief Getter de state.
   */
  virtual char getState() const = 0;
};
#endif
