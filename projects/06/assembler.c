#include <stdio.h>
#include <string.h>

//we shall define first an entry in the symbol table.

#define MAXLENGTH 20  //maximum length of any symbol or variable name.
#define MAXENTRIES 1024  //maximum length of entries in symbol table.

//single entry in symbolTable
struct SymbolTableEntry{
char symbol[MAXLENGTH];
int address;
};

//SymbolTable is define as global variable so that it can be used anywhere 
//creating a SymbolTable of arrays of SymbolTableEntry of  length MAXENTRIES
struct SymbolTableEntry SymbolTable[MAXENTRIES];

//initializing the predefined symbols  and their corresponding address value
void InitializeSymbolTable(){
    strcpy(SymbolTable[0].symbol, "SP");
    SymbolTable[0].address=0;

    strcpy(SymbolTable[1].symbol, "LCL");
    SymbolTable[1].address=1;
    strcpy(SymbolTable[2].symbol, "ARG");
    SymbolTable[2].address=2;
    strcpy(SymbolTable[3].symbol, "THIS");
    SymbolTable[3].address=3;
    strcpy(SymbolTable[4].symbol, "THAT");
    SymbolTable[4].address=4;
    strcpy(SymbolTable[5].symbol, "R0");
    SymbolTable[5].address=0;
    strcpy(SymbolTable[6].symbol, "R1");
    SymbolTable[6].address=1;
    strcpy(SymbolTable[7].symbol, "R2");
    SymbolTable[7].address=2;
    strcpy(SymbolTable[8].symbol, "R3");
    SymbolTable[8].address=3;
    strcpy(SymbolTable[9].symbol, "R4");
    SymbolTable[9].address=4;
    strcpy(SymbolTable[10].symbol, "R5");
    SymbolTable[10].address=5;
    strcpy(SymbolTable[11].symbol, "R6");
    SymbolTable[11].address=6;
    strcpy(SymbolTable[12].symbol, "R7");
    SymbolTable[12].address=7;
    strcpy(SymbolTable[13].symbol, "R8");
    SymbolTable[13].address=8;
    strcpy(SymbolTable[14].symbol, "R9");
    SymbolTable[14].address=9;
    strcpy(SymbolTable[15].symbol, "R10");
    SymbolTable[15].address=10;
    strcpy(SymbolTable[16].symbol, "R11");
    SymbolTable[16].address=11;
    strcpy(SymbolTable[17].symbol, "R12");
    SymbolTable[17].address=12;
    strcpy(SymbolTable[18].symbol, "R13");
    SymbolTable[18].address=13;
    strcpy(SymbolTable[19].symbol, "R14");
    SymbolTable[19].address=14;

     strcpy(SymbolTable[20].symbol, "R15");
    SymbolTable[20].address=15;
     strcpy(SymbolTable[21].symbol, "SCREEN");
    SymbolTable[21].address=16384;
     strcpy(SymbolTable[22].symbol, "KBD");
    SymbolTable[22].address=24576;

    //INITIALIZE ALL OTHER ENTRIES, symbol to "\0" and address to -1
    for(int i=23;i<MAXENTRIES;i++){
         strcpy(SymbolTable[i].symbol, "\0");
         SymbolTable[i].address=-1;

    }
}

//function to add a new entry to a symbolTable 
void addEntry(struct SymbolTableEntry item){

    // int isAvailable=0;
    // for(int i=0;i<MAXENTRIES;i++){
    //     if(item.symbol==SymbolTable[i].symbol){
    //         isAvailable=1;
    //         //break;
    //     }
    //     if(isAvailable==0 && SymbolTable[i].symbol==NULL){
    //         SymbolTable[i].symbol,(item.symbol);
    //         SymbolTable[i].address=-1;
            

    //     }

    // }

    //keep checking till entries is not found 
    int i=0;
    while((strcmp(SymbolTable[i].symbol,item.symbol)) != 0 && (strcmp(SymbolTable[i].symbol,"\0") != 0) && (i<MAXENTRIES)){
        i++;

        //if symbol is not contained in symbol in SymbolTable , we need to add it to the end of our instruction
        if(strcmp(SymbolTable[i].symbol,"\0")==0){
            strcpy(SymbolTable[i].symbol,item.symbol);
            SymbolTable[i].address==item.address;
        }

        //the symbol is contained in symbol table but address is -1
        //this is the process when we already processed  @END before 

        if(strcmp(SymbolTable[i].symbol,item.symbol)==0 && SymbolTable[i].address==-1){
            SymbolTable[i].address=item.address;
        }

        //if we have more symbol than permitted then, this must be reported.
        if(i>=MAXENTRIES){
            printf("ERROR:The SymbolTable is full.Increase the MAXENTRIES the two fold and recompile the assembler");
        }
    }
}


int containGetAddress(char *symbol){
    int i=0;
    while((i<MAXENTRIES) && (SymbolTable[i].address != -1)){
        if(strcmp(SymbolTable[i].symbol,symbol)==0){
           return SymbolTable[i].address;
        }
        i++;
    }
    return -1;
}

void main(){
    struct SymbolTableEntry item;

    InitializeSymbolTable(); //initializing symbol table 

    strcpy(item.symbol,"NEW");
    item.address=16;
    addEntry(item);
  //  printf("NEW is in entry %d\n",containGetAddress("NEW"));

    strcpy(item.symbol,"NEW2");
    item.address=17;
    addEntry(item);
   // printf("NEW2 is in entry %d\n",containGetAddress("NEW2"));
   // printf("NEW3 is in entry %d\n",containGetAddress("NEW3"));







// first pass is going to happen
FILE *inputFile=fopen("/home/abhishek/nand2tetris/projects/06/test.asm","r");
if(inputFile==NULL){
    perror("error opening input file");
    return 1;
}

//output file 
FILE *outputFile=fopen("/home/abhishek/nand2tetris/projects/06/test.inter","w");
if(outputFile==NULL){
    perror("error opening output file ");
    fclose(inputFile);
    return 1;
}



// char line[256];
// while(fgets(line,sizeof(line),inputFile)!=NULL){
    
//     // int i=0;
//     // while(i<sizeof(line)-1){
//     //     if(line[i]=='/'  && line[i+1]=='/'){
//     //         break;
//     //     }
//     //     fprintf(outputFile,"%s",line);
//     //     i++;

//     // }

//     if(line[0]!='/'){
//         fprintf(outputFile,"%s",line);

//     }
// }


int character;
int count=0;
while((character=fgetc(inputFile))!=EOF){
    int isComment=0;

    if(character=='/'){
        isComment=1;

    }
    if(character=='\n'){
        isComment=0;
    }
    if(isComment==0){
        fputc(character,outputFile);
    }
    count++;
}















fclose(inputFile);
fclose(outputFile);
// return 0;



printf("%d ",count);
printf("hello world");
return 0;






















}








