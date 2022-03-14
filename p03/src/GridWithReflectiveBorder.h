#ifndef GRID_WITH_REFLECTIVE_BORDER_H_
#define GRID_WITH_REFLECTIVE_BORDER_H_

#include "Grid.h"

class GridWithReflectiveBorder : public Grid {
 public:
  GridWithReflectiveBorder(int columns, int rows);

  GridWithReflectiveBorder(std::string filename);

  ~GridWithReflectiveBorder();

  const Cell& getCell(int i, int j) const;

  void nextGeneration();

 private:
  void constructGrid();

  std::ostream& print(std::ostream&) const;
};
#endif
