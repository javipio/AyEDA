/**
 * @author Javier Padilla Pío
 * @date 01/05/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practice 6 - Implementación de árboles binarios equilibrados
 * Email: alu0101410463@ull.edu.es
 * main.cc: Punto de entrada para el programa.
 * Revision history:
 *                01/05/2022 - Creation (first version) of the code
 */

#include "AVL.h"

int main(int argc, char* argv[]) {
  AB<int>* tree = new AVL<int>;
  int opt;
  bool exit = false;

  std::cout << "[0] Salir\n";
  std::cout << "[1] Insertar clave\n";
  std::cout << "[2] Buscar clave\n";
  std::cout << "[3] Eliminar clave\n";
  std::cout << "[4] Mostrar árbol inorden\n" << std::endl;

  while (!exit) {
    std::cout << "ABE $> ";
    std::cin >> opt;

    switch (opt) {
      case 0:
        std::cout << "\n\nExiting...\nGood bye!!" << std::endl;
        exit = true;
        break;
      case 1:
        int value;
        std::cout << "Valor: ";
        std::cin >> value;
        std::cout << (tree->Insert(value)
                          ? "Se añadió correctamente el elemento."
                          : "Error añadiendo el elemento.")
                  << std::endl;
        std::cout << (*tree) << std::endl;
        break;
      case 2: {
        int key;
        std::cout << "Clave: ";
        std::cin >> key;
        std::cout << (tree->Search(key)
                          ? "Se encontró el elemento."
                          : "El elemento no está contenido en el árbol")
                  << std::endl;
        break;
      }
      case 3: {
        int key;
        std::cout << "Clave: ";
        std::cin >> key;
        std::cout << (tree->Delete(key)
                          ? "Se eliminó el elemento."
                          : "El elemento no se pudo eliminar delárbol")
                  << std::endl;
        std::cout << (*tree) << std::endl;
        break;
      }
      case 4:
        tree->Inorder();
        break;
    }
  }
}