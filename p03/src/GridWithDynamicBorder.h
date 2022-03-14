#ifndef GRID_WITH_DYNAMIC_BORDER_H_
#define GRID_WITH_DYNAMIC_BORDER_H_

#include <unordered_set>

#include "Grid.h"

class GridWithDynamicBorder : public Grid {
 public:
  GridWithDynamicBorder(int columns, int rows);

  GridWithDynamicBorder(std::string filename);

  ~GridWithDynamicBorder();

  const Cell& getCell(int i, int j) const;

  void nextGeneration();

 private:
  enum side { top, right, bottom, left };

  void constructGrid();

  std::ostream& print(std::ostream&) const;

  void resize(side overflowed_size);
  Cell** resizeTop();
  Cell** resizeRight();
  Cell** resizeBottom();
  Cell** resizeLeft();
};
#endif
