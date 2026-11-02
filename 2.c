#include <stdio.h>

int main() {
    
    char pola[3][3] = {
        {'x', 'o', 'x'},
        {'o', 'x', 'o'},
        {'x', 'o', 'x'}
    };

    printf("Output:\n");
    
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c", pola[i][j]);
        }
    }
    
    printf("\n");
    return 0;
}