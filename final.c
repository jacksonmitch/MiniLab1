#include <stdio.h>
#include <stdlib.h>


int main(){

    char inputFile[255], outputFile[255],ch,type;
    int numAscii;

    //allow user to pick if they would like to encrypt or decrypt
    printf("Would you like to Enctypt 'E' or Decrypt 'D':\n");
    scanf("%c", &type);

    //if statement if user selects "E" causing program to run the encryption portion
    if(type == 'E'){
    FILE *fd1, *fd2;
    //allows the user to input file name they would like to be encrypted
    printf("\nEnter the name of the file that you would like to be encrypted(if not in the same file give file location: ");
    scanf("%s", inputFile);
    //still need to figure out how to make this automatically go to a .crp file like wanted
    printf("\nEnter the name of the file that you would like to be outputed: ");
    scanf("%s", outputFile);
    
    //opens the file inputed by user in "reading mode"
    fd1=fopen(inputFile, "r");
    if(fd1==NULL){
        //if the file does not exist it will exit the program and print the error message
        printf("file does not exist");
        exit(0);
    }
        else{
            fd2=fopen(outputFile, "w"); //open the file in "write mode allowing edits to be made"
            ch=fgetc(fd1);
            while(ch !=EOF){ //a while loop that goes throuhgh ever ch value until there is an end of file error
                numAscii=(int)ch; //reads the ASCII value that is given to each char
                numAscii=numAscii+5; //adds a ASCII value of 5 to each value ex. if the ASCII is 10 itll now be 15
                fprintf(fd2, "%c", numAscii); //assigns this to the new file
                ch=fgetc(fd1);
        }
        fclose(fd2);
    }
    fclose(fd1); // closes initial file
    printf("\nFile is now encrypted under then name %s.", outputFile);//working on this being an automatic output
    return 0;
    }
    
    //most of the same process for decryption except for line 67
    if(type == 'D'){

    FILE *fd1, *fd2;
    printf("\nEnter the name of the file that you would like to be decrypted: ");
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
                numAscii=numAscii-5; //takes previous encryptions and sets it back
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
