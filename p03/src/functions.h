/**
 * @author Javier Padilla Pío
 * @date 14/03/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practice 3 - La vida en el borde
 * Email: alu0101410463@ull.edu.es
 * main.cc: Punto de entrada para ele ejecutable.
 * Revision history:
 *                14/03/2022 - Creation (first version) of the code
 */

#include <getopt.h>

#include "Grid.h"
#include "GridWithDynamicBorder.h"
#include "GridWithOpenBorder.h"
#include "GridWithPeriodicBorder.h"
#include "GridWithReflectiveBorder.h"

const struct option longopts[] = {
    {"file", required_argument, 0, 'f'}, {"dynamic", no_argument, 0, 'd'},
    {"open", no_argument, 0, 'o'},       {"periodic", no_argument, 0, 'p'},
    {"reflective", no_argument, 0, 'r'}, {0, 0, 0, 0},
};

struct arguments_parser {
  Grid* grid = nullptr;
  bool valid = false;
  std::string filename;

  arguments_parser(int argc, char* argv[]);
};
