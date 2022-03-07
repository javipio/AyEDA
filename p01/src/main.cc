/**
 * @author Javier Padilla Pío
 * @date 04/03/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practice 1 - Juego de la vida
 * Email: alu0101410463@ull.edu.es
 * main.cc: Punto de entrada para ele ejecutable.
 * Revision history:
 *                04/03/2022 - Creation (first version) of the code
 */

#include <unistd.h>

#include <iostream>

#include "Cell.h"
#include "Grid.h"

int main(int argc, char* argv[]) {
  if (argc < 2) {
    return 1;
  }

  int iterations = 0;
  std::cout << "Número de generaciones: ";
  std::cin >> iterations;

  Grid grid(argv[1]);

  std::system("clear");
  std::cout << "Generación 0" << std::endl;
  std::cout << grid;
  sleep(2);

  // Bucle principal
  for (int i = 0; i < iterations; i++) {
    std::system("clear");
    std::cout << "Generación " << i << std::endl;
    std::cout << grid;
    usleep(50000);
    grid.nextGeneration();
  }

  std::cout << "Generación " << iterations << std::endl;
  std::cout << grid;

  return 0;
}
