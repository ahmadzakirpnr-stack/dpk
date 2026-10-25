#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){
    char *nama1 = "ade";
    char *nama2 ="kaka";
    if (argc<2){
        printf("argumen program kurang\n");
        printf("masukkan argumen seperti %s, %s, %s ", argv[0],nama1,nama2); 
        return -1;
    }  
    printf("hello  %s\n",argv[1]);
    printf("hello juga %s\n",argv[2]);
    return 0;

}