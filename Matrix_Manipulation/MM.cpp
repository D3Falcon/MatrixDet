#include <iostream>

using namespace std;

/*  Descrição: Este programa lê as ordens de duas matrizes e seus elementos do usuário e as multiplica.
Ele verifica se a multiplicação de matrizes é possível e exibe o resultado da multiplicação. O programa
é limitado pelo tamanho das matrizes definidas pelas constantes MAX_MATRIX_ORDER e MAX_MATRIX_DIMENSION.
As matrizes são lidas usando a função mtx_read, multiplicadas usando a função mtx_multiply e impressas 
usando a função mtx_print. A função mtx_check verifica se as matrizes são multiplicáveis.*/

// Define constantes para limitar o tamanho das matrizes usadas.
const int MAX_MATRIX_ORDER  = 9, MAX_MATRIX_DIMENSION  = 2;

bool mtx_check (int m1_order[], int m2_order[]);
void mtx_read (int M1[][MAX_MATRIX_ORDER], int length[], int m);
void mtx_multiply (int M1[][MAX_MATRIX_ORDER], int M2[][MAX_MATRIX_ORDER], int m1_order[], int m2_order[]);
void mtx_print (int M_result [][MAX_MATRIX_ORDER], int m_order[]);

int main () {
    int M1[MAX_MATRIX_ORDER][MAX_MATRIX_ORDER], M2[MAX_MATRIX_ORDER][MAX_MATRIX_ORDER], m1_order[MAX_MATRIX_DIMENSION], m2_order[MAX_MATRIX_DIMENSION], m;
    bool matrixOrder = true;

    cout << "In order to start the the program you first must enter the matrices order, numbers should be divided by spaces.\n";
    do {
        cout << "Enter first matrix order: ";
        // read matrix order.
        cin >> m1_order[0];
        cin >> m1_order[1];
        cout << "Enter second matrix order: ";
        // read matrix order.
        cin >> m2_order[0];
        cin >> m2_order[1];

        matrixOrder = mtx_check(m1_order, m2_order);
    } while (matrixOrder);

    // A variável "m" existe somente para checar se o programa deve ler a primeira ou a segunda matriz.
    m = 1;
    mtx_read(M1, m1_order, m);
    m = 2;
    mtx_read(M2, m2_order, m);
    
    mtx_multiply(M1, M2, m1_order, m2_order);
    return 0;
}

// Essa função verifica se a ordem de matrizes selecionadas podem ser multiplicadas.
bool mtx_check (int m1_order[], int m2_order[]) {
    if (m1_order[1] != m2_order[0]) {
        cout << "\nNumber of columns in the first matrix must be equals to the number of lines in the second matrix.\nPlease insert the correct order.\n";
        return true;
    } else return false;
}

void mtx_read (int M[][MAX_MATRIX_ORDER], int length[], int m) {
    string matrix;
    if (m == 1) {
        matrix = "first";
    } else matrix = "second";

    for (int i = 0; i < length[0]; i++) {
        for (int j = 0; j < length[1]; j++) {
            cout << "Enter " << matrix << " matrix a" << i + 1 << j + 1 << " element: ";
            cin >> M[i][j];
        }
    }
    
}

void mtx_multiply (int M1[][MAX_MATRIX_ORDER], int M2[][MAX_MATRIX_ORDER], int m1_order[], int m2_order[]){
    int M_result[MAX_MATRIX_ORDER][MAX_MATRIX_ORDER], m_order[MAX_MATRIX_DIMENSION];
    m_order[0] = m1_order[0];
    m_order[1] = m2_order[1];

    // Create a "0" matrix.
    for (int i = 0; i < MAX_MATRIX_ORDER; i++) {
        for (int j = 0; j < MAX_MATRIX_ORDER; j++) {
            M_result[i][j] = 0;
        }
    }

    for (int i = 0; i < m_order[0]; i++) {
        for (int j = 0 ; j < m_order[1]; j++) {
            for (int k = 0; k < m1_order[1]; k++) {
                M_result[i][j] += M1[i][k] * M2[k][j];
            }
        }
    }
    mtx_print (M_result, m_order);
}

void mtx_print(int M_result [][MAX_MATRIX_ORDER], int m_order[]) {
    cout << "This is the resulting matrix after multiplication:";
    for (int i = 0; i < m_order[0]; i++) {
        cout << "\n ";
        for (int j = 0; j < m_order[1]; j++) {
            cout << M_result[i][j] << " ";
        }
    }
}