#include <stdio.h>

#include "testhead.h"  // defines MyClass

int main()
{
  TestHead a; // no longer produces an error, because MyClass is defined
  printf("asdf\n");
  a.foo();
  return 0;
}
