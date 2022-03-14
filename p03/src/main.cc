/**
 * @author Javier Padilla Pío
 * @date 04/03/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practice 3 - La vida en el borde
 * Email: alu0101410463@ull.edu.es
 * main.cc: Punto de entrada para ele ejecutable.
 * Revision history:
 *                04/03/2022 - Creation (first version) of the code
 *                08/03/2022 - Update to practice 2 (second version) of the code
 *                08/03/2022 - Update to practice 3 (third version) of the code
 */

#include <unistd.h>

#include <iostream>

#include "Grid.h"
#include "functions.h"

int main(int argc, char* argv[]) {
  auto args = arguments_parser(argc, argv);

  if (!args.valid) {
    std::cerr << "Error al interpretar los argumentos." << std::endl;
    return 1;
  }

  Grid* grid = args.grid;

  // Bucle principal
  for (int i = 0;; i++) {
    std::system("clear");
    std::cout << "Generación " << i << std::endl;
    std::cout << *grid;
    usleep(50000);
    grid->nextGeneration();
  }

  return 0;
}
