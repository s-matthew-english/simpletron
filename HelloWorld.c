#include <stdio.h>

# define READ       10
# define WRITE      11

# define LOAD       20
# define STORE      21

# define ADD        30
# define SUBTRACT   31
# define DIVIDE     32
# define MULTIPLY   33

# define BRANCH     40
# define BRANCHNEG  41
# define BRANCHZERO 42
# define HALT       43


void memPrint(int arr[]){
    for(int i = 0 ; i < 100 ; i++){
        printf("MEM: %d, %d \n", i, arr[i]);
    }
    return;
}

void inputProgramFromConsole(int memory[]) {
    int i = 0;
    int opcode;

    printf("Enter Byte Codes:\n");
    scanf("%d", &opcode);

    while(opcode != -99999){
        memory[i] = opcode;
        i++;
        scanf("%d", &opcode);
    }
    memPrint(memory);
    // printf("Done\n");
    return;
}


void runProgram(){

    return;
}


int main(){
    int memory[100] = { 0 };
    int accumulater = 0;

    inputProgramFromConsole(memory);

    runProgram();

    return 0;
}



