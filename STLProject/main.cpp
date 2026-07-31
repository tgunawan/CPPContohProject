#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>


int main() {
    // Contoh penggunaan std::set
    std::set<std::string> product = {
        "GTA xXx",
        "Cyberpunk 2077",
        "The Witcher 3: Wild Hunt",
        "Elden Ring",
        "Resident Evil 4"
    };

    product.insert("Horizon Zero Dawn");
    product.erase("GTA xXx");

    //Display se
    std::cout << "Daftar produk unik (set) setelah modifikasi:\n";
    for (const auto& product : product) {
        std::cout << "- " << product << "\n";
    }

    // Contoh penggunaan std::map
    std::map<std::string, int> productStock;
    productStock["Cyberpunk 2077"] = 5;
    productStock["The Witcher 3: Wild Hunt"] = 3;
    productStock["Resident Evil 4"] = 10;
    productStock["Elden Ring"] = 2;

    //Display map
    std::cout << "\nStok produk (map):\n";
    for (const auto& [name, stock] : productStock) {
        std::cout << "- " << name << ": " << stock << " unit\n";
    }

    // Menggunakan STL algorithm untuk mencari produk dengan stok rendah
    auto isLowStock = [](const std::pair<const std::string, int>& item) {
        return item.second < 4;
    };

    auto lowStockIt = std::find_if(productStock.begin(), productStock.end(), isLowStock);
    if (lowStockIt != productStock.end()) {
        std::cout << "\nProduk stok rendah pertama: " << lowStockIt->first << " (" << lowStockIt->second << " unit)\n";
    }

    // Mengubah map ke vector untuk sorting berdasarkan stok
    std::vector<std::pair<std::string, int>> sortedProducts(productStock.begin(), productStock.end());
    std::sort(sortedProducts.begin(), sortedProducts.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });

    //Display Vector setelah sort
    std::cout << "\nProduk diurutkan berdasarkan stok rendah ke tinggi:\n";
    for (const auto& [name, stock] : sortedProducts) {
        std::cout << "- " << name << ": " << stock << " unit\n";
    }

    return 0;
}
