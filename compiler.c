#include <stdio.h>
#include <stdlib.h>

#include "compiler/linkedList.c"
#include "compiler/postfix.c"


int main(int argc, char *argv[]){
  LinkedListNodePtr consoleListHead = NULL;

  consoleListHead = linkedListFromString(argv[1]);

  LinkedListNodePtr postfixExpression = infixToPostfix(consoleListHead);
  printLinkedList(postfixExpression);
  printf("\n%d\n", evaluatePostfixExpression(postfixExpression));
}
