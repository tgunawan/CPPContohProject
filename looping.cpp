using namespace std;
#include <iostream>

int main() {
//     for (int i = 1; i < 10; i++) {
//         cout << i << endl;
//     }

     //int x = 0;
    // while (x<5)
    // {
    //     cout << x << endl;
    //     x++;
    // }

    // do{
    //     if (x==3)
    //     {
    //         continue;
    //         cout << "Sama dengan 5" << endl;
    //     }
    //     cout << "Bawah" << endl;
    //     cout << x << endl;
    //     x++;
    // } while (x<5);

    for (int i=1; i<=5;i++){
        if (i==3){
            continue;
        }
        cout<< i << endl;
    }
    
    return 0;
}