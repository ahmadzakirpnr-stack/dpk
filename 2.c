#include <stdio.h>

int main() {
    // Mendefinisikan array 2D berukuran 3x3 dengan pola 'x' dan 'o'
    char pola[3][3] = {
        {'x', 'o', 'x'},
        {'o', 'x', 'o'},
        {'x', 'o', 'x'}
    };

    printf("Output:\n");
    
    // Perulangan untuk mengakses dan mencetak setiap elemen array 2D
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c", pola[i][j]);
        }
    }
    
    printf("\n");
    return 0;
}
