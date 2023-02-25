#include <iostream>
#include <stdio.h>
#include <cctype>
#include <cmath>

using namespace std;

/*O propósito desse programa é calcular o determinante de matrizes com imput do user.
Primeiro, o programa pede para entrar com a ordem da matriz e em seguida os elementos.
O resultado é o determinante já calculado. O programa repete até que o user entre com
o número zero, como ordem de matriz para encerrar.*/


int det_2 (int M2[][2]);
int det_3 (int M[][9], int x);

int main() {
    int M[9][9], M2[2][2];
    int x = 0;
    char a = '0';
    do {
        do {
            //Pedido de elemento, ele entra como char e é modificado para interiro.
            cout << "Enter matrix order\n0 kills program\n";
            cin >> a;
        } while (!isdigit(a) && a <= '0' && a > 10);
        x = a - 48;
        int det = 0;

        if (x == 1) {
            cout << "Enter matrix element a11\n ";
            cin >> det;
            cout << "Det = " << det << ".\n";
            } 
        else if (x==2) {
            //Aqui é o pedido de elementos da matrix a ser calculada. Essa chamada vai se repetir em todas as ordens, até que eu faça uma função com esse propósito.
            for (int i = 0; i < x; i++) {
                for (int j = 0; j < x; j++) {
                       cout << "Enter matrix element a" << i+1 << j+1 << "\n ";
                       cin >> M2[i][j];
                }
            }
            det = det_2 (M2);
            cout << "Det = " << det << ".\n";

        } else if (x==3) {
            for (int i = 0; i < x; i++) {
                for (int j = 0; j < x; j++) {
                       cout << "Enter matrix element a" << i+1 << j+1 << "\n ";
                       cin >> M[i][j];
                }
            }
            det = det_3 (M, x);
            cout << "Det = " << det << ".\n";
        } else if (x>3 && x<10) {
            for (int i = 0; i < x; i++) {
                for (int j = 0; j < x; j++) {
                       cout << "Enter matrix element a" << i+1 << j+1 << "\n ";
                       cin >> M[i][j];
                }
            }
            
            det = det_3 (M, x);
            cout << "Det = " << det << ".\n";
        } else if (x > 9) {
            cout << "We don't have support for this order yet. New versions comming soon.\n";
        }
        cout << " " << x << "\n";
    } while (x!=0);  
    return 0;
}

int det_2 (int M[][2])
{
    int det2 = 0;
    det2 = M[0][0] * M[1][1] - M[0][1] * M[1][0];
    return det2;
}

int det_3 (int M[][9], int x) 
{
    //Essa função cria submatrizes para serem utilizadas na função de ordem 2.
    int det = 0;
    int subM[2][2];
    if (x==3) 
    {
        for (int i = 0; i < 3; i++) {
            for ( int j = 1; j < 3; j++){
                //Aqui usamos 3 loops encadeados e um contador para criar as submatrizes.
                int countk = 0;
                for (int k = 0; k < 3; k++){
                    if (k != i){
                        subM[j-1][countk] = M[j][k]; 
                        countk++;
                    }
                }
            }
        det += pow (-1, i+2) * M[0][i] * det_2(subM);
        }
        return det;
    }
    else
    {
        int subM[9][9];
        for (int i = 0; i < x; i++){
            for ( int j = 1; j < x; j++){
                int countk = 0;
                for (int k = 0; k < x; k++){
                     if (k != i){
                        subM[j-1][countk] = M[j][k]; 
                         countk++;
                    }
                }
            }
        det += pow (-1, i+2) * M[0][i] * det_3(subM, x-1);
        }
        return det; 
    }
    
}
