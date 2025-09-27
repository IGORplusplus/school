#ifndef GARBAGE_H
#define GARBAGE_H

#include <vector>
#include "cell.h"
#include "worker.h"

class GarbageCollection : public Worker{
public:

    virtual void printRoad(std::vector<std::vector<Cell>>& cells);
};

#endif
