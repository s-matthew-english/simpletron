void inputAssemblyFromConsole(int memory[]) {
    int i = 0;
    int opcode;

    printf("Enter Byte Codes:\n");
    scanf("%d", &opcode);

    while(opcode != -99999){
        memory[i] = opcode;
        i++;
        scanf("%d", &opcode);
    }
    return;
}

int stringToInt(char *str){
  int result = 0;
  while ((*str >= '0') && (*str <= '9')){
    result = (result * 10) + ((*str) - '0');
    str++;
  }
  return (result);
}

void inputAssemblyFromFile(int memory[], char *assemblyFilename){
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    int x;
    int i;

    fp = fopen( assemblyFilename, "r" );
    if (fp == NULL){
        printf("--File Not Found--\n");
        exit(EXIT_FAILURE);
    }else{
        while ((read = getline(&line, &len, fp)) != -1) {
            memory[i] = stringToInt(line);
            i++;
            printf( "%c", x ); 
        }
        fclose(fp);
        if (line)
            free(line);
    }
    return ;
}
