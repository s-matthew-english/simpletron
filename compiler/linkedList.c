struct LinkedListNode {
  char value;
  struct LinkedListNode * nextPtr;
};
typedef struct LinkedListNode LinkedListNode;
typedef LinkedListNode * LinkedListNodePtr;


void push(LinkedListNodePtr *headPtrPtr, char value){
  LinkedListNodePtr newHeadPtr = malloc(sizeof(LinkedListNode));
  newHeadPtr->value = value;
  newHeadPtr->nextPtr = *headPtrPtr;
  *headPtrPtr = newHeadPtr;
  return;
}
void enqueue(LinkedListNodePtr *headPtrPtr, LinkedListNodePtr *tailPtrPtr, char value){
  LinkedListNodePtr newTailPtr = malloc(sizeof(LinkedListNode));
  newTailPtr->value = value;
  newTailPtr->nextPtr = NULL;
  if(*headPtrPtr == NULL){
    *headPtrPtr = newTailPtr;
  }else{
    (*tailPtrPtr)->nextPtr = newTailPtr;
  }
  *tailPtrPtr = newTailPtr;
  return;
}

char pop(LinkedListNodePtr *topPtrPtr){
  char output = (*topPtrPtr)->value;
  *topPtrPtr = (*topPtrPtr)->nextPtr;
  return output;
}

void printLinkedList(LinkedListNodePtr currentPtr){
  while(currentPtr != NULL){
    printf(" %c ", currentPtr->value);
    currentPtr = currentPtr->nextPtr;
  }
  return;
}

LinkedListNodePtr linkedListFromString(char str[1]){
  LinkedListNodePtr listHeadPtr = NULL;
  LinkedListNodePtr listTailPtr = NULL;

  for (int i = 0; str[i]; i++){
    enqueue(&listHeadPtr, &listTailPtr, str[i]);
  }
  return listHeadPtr;
}
