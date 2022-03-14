#ifndef GRID_WITH_OPEN_BORDER_H_
#define GRID_WITH_OPEN_BORDER_H_

#include "Grid.h"

class GridWithOpenBorder : public Grid {
 public:
  GridWithOpenBorder(int columns, int rows);

  GridWithOpenBorder(std::string filename);

  ~GridWithOpenBorder();

  const Cell& getCell(int i, int j) const;

  void nextGeneration();

 private:
  void constructGrid();

  std::ostream& print(std::ostream&) const;
};
#endif
