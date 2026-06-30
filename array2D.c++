#include <iostream>

using namespace std;

void board(char data[5][5]) // array dengan tipe data char di dalam 2D dengan ukuran 5x5
{
    cout << " K1 K2 K3 K4 K5\n";

    for(int i = 0; i < 5; i++){
        cout << "R" << i + 1 << " ";

        for(int j= 0; j < 5; j++)
            cout << data[i][j] << " ";

        cout << endl;
    }  
}

int main() {
    // Inisialisasi array 2D
    char data[5][5] = {
        {'A', 'B', 'C', 'D', 'E'},
        {'F', 'G', 'H', 'I', 'J'},
        {'K', 'L', 'M', 'N', 'O'},
        {'P', 'Q', 'R', 'S', 'T'},
        {'U', 'V', 'W', 'X', 'Y'}
    };

    // Memanggil fungsi untuk menampilkan array
    board(data);
    data[0][0] = 'O';
    board(data);
    data[1][1] = 'O';
    board(data);
    data[2][2] = 'O';
    board(data);
    data[3][3] = 'O';
    board(data);
    data[4][4] = 'O';
    board(data);
    return 0;
}