/**
 * @author Javier Padilla Pío
 * @date 22/04/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practice 5 - Implementación de algoritmos de ordenación
 * Email: alu0101410463@ull.edu.es
 * main.cc: Punto de entrada al programa.
 * Revision history:
 *                22/04/2022 - Creation (first version) of the code
 */

#include <stdio.h>

#include <cstdlib>
#include <ctime>
#include <fstream>

#include "Key.h"
#include "functions.h"

int main(int argc, char* argv[]) {
  auto args = arguments_parser<Key<int>, 5>(argc, argv);
  Key<int>* seq = new Key<int>[args.size];

  if (args.size < 0 || args.sort == nullptr) {
    std::cerr << "Error procesando los parámetros." << std::endl;

    return 1;
  }

  if (args.filename == "") {
    srand(time(nullptr));

    for (int i = 0; i < args.size; i++) {
      seq[i] = rand() % 9000 + 1000;
    }
  } else {
    std::ifstream file(args.filename);
    std::string line;
    std::string acc;
    getline(file, line);

    int i = 0;
    for (const auto ch : line) {
      if (ch == ',' && acc != "") {
        seq[i++] = stoi(acc);
        acc = "";
      }
      if (ch != ',') acc += ch;
    }

    if (acc != "") {
      seq[i] = stoi(acc);
    }
  }

  std::cout << "Input array: ";
  print(seq, args.size);
  std::cout << "\n";

  args.sort(seq, args.size);

  std::cout << "\nOutput array: ";

  for (int i = 0; i < args.size; i++) {
    std::cout << seq[i].to_string() << " ";
  }
  std::cout << std::endl;

  delete[] seq;

  return 0;
}
