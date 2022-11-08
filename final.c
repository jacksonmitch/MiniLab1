#include <stdio.h>
#include <stdlib.h>


int main(){

    char inputFile[255], outputFile[255],ch,type;
    int numAscii;

    printf("Would you like to Enctypt 'E' or Decrypt 'D':\n");
    scanf("%c", &type);

    if(type == 'E'){
    FILE *fd1, *fd2;
    printf("\nEnter the name of the file that you would like to be encrypted:");
    scanf("%s", inputFile);

    printf("\nEnter the name of the file that you would like to be outputed: ");
    scanf("%s", outputFile);
    
    fd1=fopen(inputFile, "r");
    if(fd1==NULL){
        printf("file does not exist");
        exit(0);
    }
        else{
            fd2=fopen(outputFile, "w");
            ch=fgetc(fd1);
            while(ch !=EOF){
                numAscii=(int)ch;
                numAscii=numAscii+5;
                fprintf(fd2, "%c", numAscii);
                ch=fgetc(fd1);
        }
        fclose(fd2);
    }
    fclose(fd1);
    printf("\nFile is now encrypted under then name %s.", outputFile);
    return 0;
    }
    
    if(type == 'D'){

    FILE *fd1, *fd2;
    printf("\nEnter the name of the file that you would like to be decrypted:");
    scanf("%s", inputFile);

    printf("\nEnter the name of the file that you would like to be outputed: ");
    scanf("%s", outputFile);
    
    fd1=fopen(inputFile, "r");
    if(fd1==NULL){
        printf("file does not exist");
        exit(0);
    }
        else{
            fd2=fopen(outputFile, "w");
            ch=fgetc(fd1);
            while(ch !=EOF){
                numAscii=(int)ch;
                numAscii=numAscii-5;
                fprintf(fd2, "%c", numAscii);
                ch=fgetc(fd1);
        }
        fclose(fd2);
    }
    fclose(fd1);
    printf("\nFile is now decrypted under then name %s.", outputFile);
    return 0;
    
}
}
