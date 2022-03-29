/**
 * @author Javier Padilla Pío
 * @date 14/03/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practice 3 - La vida en el borde
 * Email: alu0101410463@ull.edu.es
 * functions.h: Interfaz de las funciones de ayuda.
 * Revision history:
 *                14/03/2022 - Creation (first version) of the code
 */
#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <getopt.h>

#include <iostream>
#include <sstream>
#include <vector>

#include "DispersionFunction/DfModule.h"
#include "DispersionFunction/DfRandom.h"
#include "DispersionFunction/DfSum.h"
#include "DispersionFunction/DispersionFunction.h"
#include "ExplorationFunction/EfCuadratic.h"
#include "ExplorationFunction/EfDoubleDispersion.h"
#include "ExplorationFunction/EfLineal.h"
#include "ExplorationFunction/EfRedispersion.h"
#include "ExplorationFunction/ExplorationFunction.h"
#include "HashTable.h"

const struct option longopts[] = {
    {"size", required_argument, 0, 'n'},
    {"exploration-func", required_argument, 0, 'e'},
    {"dispersion-func", required_argument, 0, 'd'},
    {0, 0, 0, 0},
};

template <class Key>
struct arguments_parser {
  HashTable<Key>* table = nullptr;
  DispersionFunction<Key>* fd = nullptr;
  ExplorationFunction<Key>* fe = nullptr;
  DispersionFunction<Key>* alternative_fd = nullptr;
  bool valid = false;
  int size = 0;

  /**
   * @brief Destructura los argumentos recibidos por línea de comandos
   * rellenando la estructura arguments_parser.
   */
  arguments_parser(int argc, char* argv[]);
};

/**
 * @brief Devuelve verdadero si una cadena es prefijo de la otra.
 * @param[in] haystack Cadena que puede contener el prefijo.
 * @param[in] needle Prefijo.
 * @return Verdadero si needle es prefijo de haystack.
 */
bool starts_with(std::string haystack, std::string needle);

/**
 * @brief Divide una cadena de texto por los espacios.
 * @param[in] s Cadena a dividir.
 * @return Vector con cada una de las subcadenas.
 */
std::vector<std::string> split(const std::string& s);

#include "functions.tpp"
#endif