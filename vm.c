#include <stdio.h>
#include "testhead.c"

struct vm {
  int memory[100] = { 0 };
  int accumulator;
  int machineHead;
}
