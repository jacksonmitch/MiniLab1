#include <stdio.h>
#include <string.h>

char encryptMath(int x){
    char hex;

    if(x < 10){
        hex = x + '0';
    }
    else if(x > 9){
        hex = (x - 10) + 'A';
    }
    return(hex);
}

void encryptmain(char* x){
    char buffer[1], tab[1], fileName[strlen(x)];
    int a, b=0;

    FILE *f = fopen(x, "r");

    for(int y = 0; y < (strlen(x)-4); y++){
        fileName[y] = x[y];
    }

    FILE *D;

    strcat(fileName, ".crp");
    D = fopen(fileName, "w");
    while(fread(buffer, 1, 1, f)){

        a = buffer[0];

        if (a == 10){
            buffer[0] = '\n';
            fwrite(buffer, 1, 1, D);
        }

        else if(a == 32){
        b = b+1;
        if(b == 4){
            buffer[0] ='T';
            fwrite(buffer, 1, 1, D);
            fwrite(buffer, 1, 1, D);
            b = 0;
        }
        }
        else{
            
            if (b == 1){
                buffer[0] = '8';
                fwrite(buffer, 1, 1, D);
                buffer[0] = '0';
                fwrite(buffer, 1, 1, D);
            }

            b = 0;

            a = a-16;
            if(a < 32){
                a = (a-32) + 144;
            }

            buffer[0] = encryptMath(a / 16);
            fwrite(buffer, 1, 1, D);
            buffer[0] = encryptMath(a % 16);
            fwrite(buffer, 1, 1, D);
            
        }
    }
    fclose(D);
    fclose(f);
    
}

char decryptMath(char x[2]){
    int a = 0, y = x[0], z= x[1];

    if (y > 64){
        a = (y - 65 + 10) * 16;
    }
    else{
        a = (y - 48) * 16;
    }

    if (z > 64){
        a = a + (z - 65 + 10);
    }
    else{
        a = a + (z - 48);
    }
    if (a > 127){
        a = a - 144 + 32;
    }
    if (y - '0' == 8 && z - '0' == 0){
        a = 16;
    }
    if (y - 'T' == 0){
        a = 9 - 16;
    }
    if (z == '\n'){
        a = '\n' - 16;
    }

    return(a + 16);
}

void decryptmain(char* x){
    char buffer[1], hex[2], fileName[strlen(x)];
    int a[1], place = 0;

    FILE *f = fopen(x, "r");
    for(int y = 0; y < (strlen(x) - 4); y++){
        fileName[y] = x[y];
    }

    FILE *D;

    strcat(fileName, ".txt");
    D = fopen(fileName, "w");

    while (fread(buffer, 1, 1, f)){

        if(buffer[0] == '\n'){
            fwrite( buffer, 1, 1, D);
            place = 0;
        }
        else if (place == 0){
            hex[0] = buffer[0];
            place = 1;
        }
        else{
            hex[1] = buffer[0];
            a[0] = decryptMath(hex);

            if (a[0] == '\n' - 1){
                
                a[0] = ' ';
                fwrite(a, 1, 1, D);
                fwrite(a, 1, 1, D);
                fwrite(a, 1, 1, D);
                fwrite(a, 1, 1, D);
                place = 0;
            }
            else{
                place = 0;
                fwrite(a, 1, 1, D);
            }
        }
    
    }
fclose(f);
fclose(D);
}



int main(int argc, char *argv[]){

    if (argc == 3){
        if(strcmp(argv[1],"-D") == 0){
            decryptmain(argv[argc - 1]);
        }
        if(strcmp(argv[1], "-E") == 0){
            encryptmain(argv[argc - 1]);
        }
    }
    if (argc == 2){
        encryptmain(argv[argc - 1]);
    }
    return 0;
}