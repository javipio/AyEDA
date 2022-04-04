/**
 * @author Javier Padilla Pío
 * @date 14/03/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practice 4 - Búsqueda por dispersión
 * Email: alu0101410463@ull.edu.es
 * functions.tpp: Implementación de las funciones de ayuda.
 * Revision history:
 *                28/03/2022 - Creation (first version) of the code
 */

template <class Key>
arguments_parser<Key>::arguments_parser(int argc, char* argv[]) {
  int c, idx;

  while ((c = getopt_long(argc, argv, "n:e:d:a:", longopts, &idx)) != -1) {
    std::string stringified_optarg = optarg;

    switch (c) {
      case 'n':
        size = atoi(optarg);
        break;
      case 'd':
        if (!size) {
          return;
        }

        if (stringified_optarg == "sum") {
          fd = new DfSum<Key>(size);
        } else if (stringified_optarg == "random") {
          fd = new DfRandom<Key>(size);
        } else if (stringified_optarg == "module") {
          fd = new DfModule<Key>(size);
        }

        break;
      case 'e':
        if (!size) {
          return;
        }

        if (stringified_optarg == "cuadratic") {
          fe = new EfCuadratic<Key>();
        } else if (stringified_optarg == "lineal") {
          fe = new EfLineal<Key>();
        } else if (stringified_optarg == "redispersion") {
          fe = new EfRedispersion<Key>(size);
        } else if (stringified_optarg == "double") {
          fe = new EfDoubleDispersion<Key>(new DfModule<Key>(size));
        }

        break;
      case 'a':
        if (!size) {
          return;
        }

        if (stringified_optarg == "sum\0") {
          alternative_fd = new DfSum<Key>(size);
        } else if (stringified_optarg == "random\0") {
          alternative_fd = new DfRandom<Key>(size);
        } else if (stringified_optarg == "module\0") {
          alternative_fd = new DfModule<Key>(size);
        }

        break;
      default:
        return;
    }
  }

  valid = size && (fd != nullptr);
  int block_size = fe == nullptr ? 0 : 5;
  table = new HashTable<Key>(size, fd, fe, block_size);
}

bool starts_with(std::string haystack, std::string needle) {
  if (needle.size() > haystack.size()) return false;

  for (int i = 0; i < needle.size(); i++) {
    if (haystack[i] != needle[i]) {
      return false;
    }
  }
  return true;
}

std::vector<std::string> split(const std::string& s) {
  std::stringstream ss(s);
  std::vector<std::string> words;

  while (!ss.eof()) {
    std::string word;
    ss >> word;
    words.push_back(word);
  }

  return words;
}