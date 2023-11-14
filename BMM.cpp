#include <iostream>

void MultiplyWithOutAMP() {
    //int aMatrix[3][2] = { 
    //    {1, 4},
    //    {2, 5}, 
    //    {3, 6} };

    //int bMatrix[2][3] = { 
    //    {7, 8, 9},
    //    {10, 11, 12} };

    //int product[3][3] = { 
    //    {0, 0, 0},
    //    {0, 0, 0}, 
    //    {0, 0, 0} };

    const int a_row = 1;
    const int a_col = 5;
    const int b_row = 5;
    const int b_col = 9;

    unsigned short aMatrix[a_row][a_col] = {
        {1, 0, 1, 0, 1}
    };

    unsigned short bMatrix[b_row][b_col] = {
        {1, 0, 0, 0, 0,     0, 0, 1, 1},
        {0, 1, 0, 0, 0,     0, 1, 1, 0},
        {0, 0, 1, 0, 0,     1, 1, 0, 0},
        {0, 0, 0, 1, 0,     1, 0, 0, 1},
        {0, 0, 0, 0, 1,     1, 0, 1, 0}
    };

    unsigned short product[1][9] = {
        {0, 0, 0, 0, 0,     0, 0, 0, 0}
    };

    for (int row = 0; row < a_row; row++) {
        for (int col = 0; col < b_col; col++) {
            // Multiply the row of A by the column of B to get the row, column of product.
            for (int inner = 0; inner < a_col; inner++) {
                product[row][col] = product[row][col] ^ (aMatrix[row][inner] & bMatrix[inner][col]);
            }
            std::cout << std::hex << product[row][col] << "  ";
        }
        std::cout << "\n";
    }
}

int main() {
    MultiplyWithOutAMP();
    //getchar();
}