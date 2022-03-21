/**
 * @author Javier Padilla Pío
 * @date 14/03/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practice 3 - La vida en el borde
 * Email: alu0101410463@ull.edu.es
 * functions.cc: Implementación de las funciones de ayuda.
 * Revision history:
 *                14/03/2022 - Creation (first version) of the code
 */

#include "functions.h"

arguments_parser::arguments_parser(int argc, char* argv[]) {
  int c, idx;

  while ((c = getopt_long(argc, argv, "f:dopr", longopts, &idx)) != -1) {
    switch (c) {
      case 'f':
        filename = optarg;
        valid = true;
        break;
      case 'd':
        grid = new GridWithDynamicBorder(filename);
        break;
      case 'o':
        grid = new GridWithOpenBorder(filename);
        break;
      case 'p':
        grid = new GridWithPeriodicBorder(filename);
        break;
      case 'r':
        grid = new GridWithReflectiveBorder(filename);
        break;
      default:
        valid = false;
        return;
    }
  }
}
