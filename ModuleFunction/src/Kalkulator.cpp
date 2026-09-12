#include "Kalkulator.h"
#include <stdexcept> //persiapan error handling / exception

double Kalkulator::tambah(double a, double b){
    return a+b;
}
double Kalkulator::bagi(double a, double b){
    if (b == 0.0){
        throw std::invalid_argument("Pembagi tidak boleh nol!!");
    }
    return a/b;
}