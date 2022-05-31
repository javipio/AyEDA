/**
 * @author Javier Padilla Pío
 * @date 22/04/2022
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en ingeniería informática
 * Curso: 2º
 * Practice 5 - Implementación de algoritmos de ordenación
 * Email: alu0101410463@ull.edu.es
 * functions.tpp: Implementación de las funciones de ayuda y algoritmos.
 * Revision history:
 *                22/04/2022 - Creation (first version) of the code
 */

template <class Key>
void Selection(Key* seq, uint size) {
  for (int i = 0; i < size; i++) {
    int min = i;

    for (int j = i + 1; j < size; j++) {
      min = seq[j] < seq[min] ? j : min;
    }

    swap(seq[min], seq[i]);

    // Mostrar traza
    std::cout << "[i = " << i << "]";
    for (int j = 0; j < size; j++) {
      if (j == min)
        std::cout << "\033[1;31m";
      else if (j < i)
        std::cout << "\033[1;36m";

      std::cout << "  " << seq[j] << "\033[0m";
    }
    std::cout << std::endl;
  }
}

template <class Key>
void QuickSort(Key* seq, uint size, int start, int end) {
  int i = start;
  int f = end;
  Key p = seq[(i + f) / 2];

  while (i <= f) {
    while (seq[i] < p) i++;
    while (seq[f] > p) f--;

    if (i <= f) {
      swap(seq[i], seq[f]);
      i++;
      f--;
    }
  }

  // Mostrar traza
  std::cout << "[pivote = " << p << "] ";
  print(seq, size, start, end);

  if (start < f) QuickSort(seq, size, start, f);
  if (i < end) QuickSort(seq, size, i, end);
}

template <class Key>
void ShellSort(Key* seq, uint size, int reduction_factor) {
  for (int i = 0, delta = reduction_factor; delta >= 1; delta /= 2, i++) {
    std::cout << "[delta = " << delta << "] ";
    DeltaSort(delta, seq, size);
  }
}

template <class Key>
void DeltaSort(int delta, Key* seq, int size) {
  Key x, j;

  for (int i = delta; i < size; i++) {
    x = seq[i];
    j = i;

    while ((j >= delta) && (x < seq[j - delta])) {
      seq[j] = seq[j - delta];
      j -= delta;
    }

    seq[j] = x;

    // Mostrar la traza
    if (i != delta) std::cout << "            ";
    print(seq, size, 0, i);
  }
}

template <class Key>
void HeapSort(Key* seq, uint size) {
  std::cout << " [Inserciones] ";
  for (int i = (size / 2) - 1; i >= 0; i--) {
    Baja(i, seq, size);
    if (i != (size / 2) - 1) std::cout << "               ";
    print(seq, size, i, size);
  }

  std::cout << "\n[Extracciones] ";
  for (int i = size - 1; i > 0; i--) {
    swap(seq[0], seq[i]);
    Baja(0, seq, i);
    if (i != size - 1) std::cout << "               ";
    print(seq, size, 0, i);
  }
}

template <class Key>
void Baja(int i, Key* seq, int size) {
  int child, ch_1, ch_2;

  while ((2 * (i + 1)) - 1 < size) {
    ch_2 = (2 * (i + 1));
    ch_1 = ch_2 - 1;

    child = (ch_1 == size - 1 || seq[ch_1] > seq[ch_2]) ? ch_1 : ch_2;

    if (seq[child] <= seq[i])
      break;
    else {
      swap(seq[i], seq[child]);
      i = child;
    }
  }
}

template <class Key>
void RadixSort(Key* seq, uint size) {
  Key* storage = new Key[size];
  Key max_ = max(seq, size);
  memset(storage, 0, size * sizeof(Key));

  uint* count = new uint[10];

  int phase = 0;
  Key one(1);

  for (int offset = 1; max_ / offset > one; offset *= 10) {
    memset(count, 0, 10 * sizeof(Key));

    for (int i = 0; i < size; i++) {
      uint digit = (seq[i] / offset) % 10;
      count[digit]++;
    }

    for (int i = 1; i < 10; i++) {
      count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
      uint digit = (seq[i] / offset) % 10;
      storage[--count[digit]] = seq[i];
    }

    for (int i = 0; i < size; i++) {
      seq[i] = storage[i];
    }

    // Mostrar traza
    std::cout << "[Fase " << ++phase << "] ";
    print(seq, size);
  }

  delete[] storage;
  delete[] count;
}

template <class Key>
void print(Key* seq, uint size, int start, int end) {
  for (int i = 0; i < size; i++) {
    if (i >= start && i < end) {
      std::cout << "\033[1;36m";
    }

    std::cout << seq[i] << "  \033[0m";
  }

  std::cout << std::endl;
}

template <class Key>
void swap(Key& first, Key& second) {
  Key temp = first;
  first = second;
  second = temp;
};

template <class Key>
Key max(Key* seq, uint size) {
  Key max_ = seq[0];

  for (int i = 0; i < size; i++) {
    max_ = seq[i] > max_ ? seq[i] : max_;
  }

  return max_;
}

template <class Key, int delta>
arguments_parser<Key, delta>::arguments_parser(int argc, char* argv[]) {
  int c, idx;

  while ((c = getopt_long(argc, argv, "f:n:a:", longopts, &idx)) != -1) {
    std::string stringified_optarg = optarg;

    switch (c) {
      case 'f':
        filename = optarg;
        break;
      case 'n':
        size = atoi(optarg);
        break;
      case 'a':
        if (stringified_optarg == "selection") {
          sort = Selection;
        } else if (stringified_optarg == "quick") {
          sort = [](Key* seq, uint size) { QuickSort(seq, size, 0, size - 1); };
        } else if (stringified_optarg == "shell") {
          sort = [](Key* seq, uint size) { ShellSort(seq, size, delta); };
        } else if (stringified_optarg == "heap") {
          sort = HeapSort;
        } else if (stringified_optarg == "radix") {
          sort = RadixSort;
        }
        break;
    }
  }
}
