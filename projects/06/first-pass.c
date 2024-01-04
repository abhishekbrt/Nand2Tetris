#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *file=fopen("/home/abhishek/nand2tetris/projects/06/add/Add.asm","r");
    if(file==NULL){
        perror("Error opening file");
        return 1;
    }

    char line[256];

      // Read and process each line of the file
    while (fgets(line, sizeof(line), file)) {
        // Process the line here
        printf("Line: %s ", line); // For example, you can print the line
    }

    // Close the file
    fclose(file);

    return 0;

}