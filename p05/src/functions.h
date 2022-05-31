/**
 * @author Javier Padilla Pío
 * @date 22/04/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practice 5 - Implementación de algoritmos de ordenación
 * Email: alu0101410463@ull.edu.es
 * functions.h: Interfaz de las funciones de ayuda y algoritmos.
 * Revision history:
 *                22/04/2022 - Creation (first version) of the code
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <getopt.h>
#include <string.h>

#include <iomanip>
#include <iostream>

/**
 * @brief Ordena un array siguiendo el algoritmo selectionSort.
 * @param[out] seq Puntero apuntando al array a ordenar.
 * @param[in] size Tamaño del array.
 */
template <class Key>
void Selection(Key* seq, uint size);

/**
 * @brief Ordena un array siguiendo el algoritmo quickSort.
 * @param[out] seq Puntero apuntando al array a ordenar.
 * @param[in] size Tamaño del array.
 * @param[in] start Posición a partir de la cual ordenar.
 * @param[in] end Posición hasta la que ordenar.
 */
template <class Key>
void QuickSort(Key* seq, uint size, int start, int end);

/**
 * @brief Ordena un array siguiendo el algoritmo shellSort.
 * @param[out] seq Puntero apuntando al array a ordenar.
 * @param[in] size Tamaño del array.
 * @param[in] reduction_factor Factor de reducción.
 */
template <class Key>
void ShellSort(Key* seq, uint size, int reduction_factor = 3);

/**
 * @brief Subrutina de ShellSort ejecutada en cada iteración.
 * @param[in] delta Factor de reducción.
 * @param[out] seq Puntero apuntando al array a ordenar.
 * @param[in] size Tamaño del array.
 */
template <class Key>
void DeltaSort(int delta, Key* seq, int size);

/**
 * @brief Ordena un array siguiendo el algoritmo heapSort.
 * @param[out] seq Puntero apuntando al array a ordenar.
 * @param[in] size Tamaño del array.
 */
template <class Key>
void HeapSort(Key* seq, uint size);

/**
 * @brief Ordena un array siguiendo el algoritmo heapSort.
 * @param[in] i Puntero apuntando al array a ordenar.
 * @param[out] seq Puntero apuntando al array a ordenar.
 * @param[in] size Tamaño del array.
 */
template <class Key>
void Baja(int i, Key* seq, int size);

/**
 * @brief Ordena un array siguiendo el algoritmo radixSort.
 * @param[out] seq Puntero apuntando al array a ordenar.
 * @param[in] size Tamaño del array.
 */
template <class Key>
void RadixSort(Key* seq, uint size);

/**
 * @brief Intercambia los valores de dos variables.
 * @param[out] first Pimer valor a intercambiar.
 * @param[out] second Segundo valor a intercambiar.
 */
template <class Key>
void swap(Key& first, Key& second);

/**
 * @brief Imprime por pantalla un array, con posibilidad de colorear una parte.
 * @param[in] seq Puntero al array a ordenar.
 * @param[in] size Tamaño del array.
 * @param[in] start Principio del segmento a colorear.
 * @param[in] end Final del segmento a colorear.
 */
template <class Key>
void print(Key* seq, uint size, int start = -1, int end = -1);

/**
 * @brief Devuelve el valor máximo de un array.
 * @param[in] seq Puntero al array.
 * @param[in] size Tamaño del array.
 */
template <class Key>
Key max(Key* seq, uint size);

const struct option longopts[] = {
    {"file", required_argument, 0, 'f'},
    {"size", required_argument, 0, 'n'},
    {"algorithm", required_argument, 0, 'a'},
    {0, 0, 0, 0},
};

template <class Key, int delta>
struct arguments_parser {
  void (*sort)(Key* seq, uint size);
  std::string filename;
  int size = -1;

  /**
   * @brief Destructura los argumentos recibidos por línea de comandos
   * rellenando la estructura arguments_parser.
   */
  arguments_parser(int argc, char* argv[]);
};

#include "functions.tpp"
#endif
