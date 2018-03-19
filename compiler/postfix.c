// #include "linkedList.c"

int calculate(int operand1, int operand2, char operator){ 
  if(operator == '+'){ return operand1 + operand2; }
  if(operator == '-'){ return operand1 - operand2; }
  if(operator == '*'){ return operand1 * operand2; }
  if(operator == '/'){ return operand1 / operand2; }
  if(operator == '^'){ return operand1^operand2; }
  printf("CALCULATION ERROR\n");
  return 0;
}


_Bool isOperand(char input){
  return (input != '+') 
    && (input != '-')
    && (input != '*')
    && (input != '/')
    && (input != '^')
    && (input != '(')
    && (input != ')')
    && (input != '[')
    && (input != ']');
}

int getPrecedence(char operator){
  if(operator == '+'){ return 0; }
  if(operator == '-'){ return 0; }
  if(operator == '*'){ return 1; }
  if(operator == '/'){ return 1; }
  if(operator == '^'){ return 2; }

  printf("Error : '%c'\n", operator);
  return 999;
}


LinkedListNodePtr infixToPostfix(LinkedListNodePtr currentInputPtr){
  LinkedListNodePtr stackPtr     = NULL;
  LinkedListNodePtr ouputHeadPtr = NULL;
  LinkedListNodePtr ouputTailPtr = NULL;
  char currentValue;

  for (int i = 0; currentInputPtr; i++){
    currentValue = currentInputPtr->value;
    if(isOperand(currentValue)){
      enqueue(&ouputHeadPtr, &ouputTailPtr, currentValue);
    }else if(currentValue == '(' || currentValue == '['){
      push(&stackPtr, currentValue);
    }else if(currentValue == ')' || currentValue == ']'){
      while(stackPtr->value != '(' && stackPtr->value != '['){
        enqueue(&ouputHeadPtr, &ouputTailPtr, pop(&stackPtr));
      }
      pop(&stackPtr);
    }else{
      while(stackPtr && stackPtr->value != '('  && stackPtr->value != '['
        && getPrecedence(stackPtr->value) >= getPrecedence(currentValue)
      ){
        enqueue(&ouputHeadPtr, &ouputTailPtr, pop(&stackPtr));
      }
      push(&stackPtr, currentValue);
    }
    currentInputPtr = currentInputPtr->nextPtr;
  }
  while(stackPtr){ 
    enqueue(&ouputHeadPtr, &ouputTailPtr, pop(&stackPtr));
  }
  enqueue(&ouputHeadPtr, &ouputTailPtr, '\0');

  return ouputHeadPtr;
}

// int strToInt(char character){
//   return character - '0';
// }

int evaluatePostfixExpression(LinkedListNodePtr expressionPtr){ //must already end in '/0'
  LinkedListNodePtr stackPtr;
  int operand1;
  int operand2;
  int result;

  while(expressionPtr && expressionPtr->value != '\0' ){
    if(isOperand(expressionPtr->value)){
      push(&stackPtr, (pop(&expressionPtr) - '0'));
    }else{//isOperator
      operand2 = pop(&stackPtr);
      operand1 = pop(&stackPtr);
      result = calculate(operand1, operand2, pop(&expressionPtr));
      push(&stackPtr, result);
    }
  }
  return pop(&stackPtr);
}








