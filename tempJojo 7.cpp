#include <thread>
#include <iostream>

void fungsi_tugas_A() {
    std::cout << "Thread A sedang bekerja..." << std::endl;
}

void fungsi_tugas_B() {
    std::cout << "Thread B sedang bekerja..." << std::endl;
}

int main() {
    // Membuat objek thread baru dan menjalankan fungsi secara bersamaan
    std::thread t1(fungsi_tugas_A);
    std::thread t2(fungsi_tugas_B);

    // Menunggu hingga kedua thread selesai sebelum program berakhir
    
    std::cout << "Thread mulai..." << std::endl;
    t1.join();
    t2.join();
    std::cout << "Thread selesai..." << std::endl;

    // fungsi_tugas_A();
    // fungsi_tugas_B();
    return 0;
}
