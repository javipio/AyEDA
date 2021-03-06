/**
 * @author Javier Padilla Pío
 * @date 14/03/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practice 4 - Búsqueda por dispersión
 * Email: alu0101410463@ull.edu.es
 * main.cc: Punto de entrada para el programa.
 * Revision history:
 *                28/03/2022 - Creation (first version) of the code
 */

#include <iostream>

#include "Dni.h"
#include "HashTable.h"
#include "functions.h"

int main(int argc, char* argv[]) {
  auto args = arguments_parser<Dni>(argc, argv);

  auto table = args.table;

  if (!args.valid) {
    std::cerr << "Error al leer los argumentos." << std::endl;
    return 1;
  }

  std::string input;

  while (true) {
    std::cout << "hash-table $> ";
    std::cin.clear();
    getline(std::cin, input);

    if (starts_with(input, "insert")) {
      Dni key(split(input)[1]);
      std::cout << (table->insert(key) ? "Insertado con éxito"
                                       : "No se ha podido insertar")
                << std::endl;
    } else if (starts_with(input, "search")) {
      Dni key(split(input)[1]);
      std::cout << (table->search(key) ? "El elemento se ha encontrado"
                                       : "No se encontró el elemento")
                << std::endl;
    } else if (input == "exit") {
      break;
    }
  }

  delete table;
  return 0;
}
