#ifndef GRID_WITH_PERIODIC_BORDER_H_
#define GRID_WITH_PERIODIC_BORDER_H_

#include "Grid.h"

class GridWithPeriodicBorder : public Grid {
 public:
  GridWithPeriodicBorder(int columns, int rows);

  GridWithPeriodicBorder(std::string filename);

  ~GridWithPeriodicBorder();

  const Cell& getCell(int i, int j) const;

  void nextGeneration();

 private:
  void constructGrid();

  std::ostream& print(std::ostream&) const;
};
#endif
