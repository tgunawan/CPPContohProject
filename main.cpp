/* contoh
#include <algorithm>
#include <exception>
#include <iostream>
#include <limits>
#include <random>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

/*
  Contoh real-life project C++ berbasis game sederhana.
  Fokus:
  - Function Template
  - Class Template
  - Exception Handling (try, throw, catch)
  - OOP (Player, Enemy)
  - Vector, Menu, Game Loop, Inventory, Loot, Battle

  Tujuan: membuat satu file `main.cpp` yang mudah dibaca pemula,
  lengkap dengan komentar penjelasan setiap bagian.


// ==============================================
// Part 1: Function Template
// ==============================================

// Function template untuk menjumlahkan dua nilai.
// Template memungkinkan fungsi ini bekerja dengan tipe data apa pun
// selama operator + tersedia untuk tipe tersebut.
template <typename T>
T Add(T a, T b) {
    return a + b;
}

// Function template untuk mencari nilai maksimum.
// Ini juga bisa digunakan untuk int, double, atau tipe lain yang bisa dibandingkan.
template <typename T>
T MaxValue(T a, T b) {
    return (a > b) ? a : b;
}

// Function template untuk menghitung heal value.
// Meski sederhana, ini menunjukkan penggunaan template untuk operasi umum.
template <typename T>
T HealValue(T current, T amount) {
    return current + amount;
}

// ==============================================
// Part 2: Class Template for Inventory
// ==============================================

// Item sederhana untuk game: bisa berupa potion, senjata, armor, dll.
struct Item {
    string name;
    string type;
    int power = 0;
    int value = 0;

    string GetDescription() const {
        return name + " (" + type + ", power=" + to_string(power) + ", value=" + to_string(value) + ")";
    }
};

// Class template Inventory<T> yang dapat menyimpan beragam tipe item.
// Di game ini, kita menggunakan Inventory<Item>.
template <typename T>
class Inventory {
public:
    void AddItem(const T& item) {
        items.push_back(item);
    }

    void RemoveItem(size_t index) {
        if (index >= items.size()) {
            throw out_of_range("Indeks item tidak valid.");
        }
        items.erase(items.begin() + index);
    }

    bool IsEmpty() const {
        return items.empty();
    }

    size_t Size() const {
        return items.size();
    }

    const T& GetItem(size_t index) const {
        if (index >= items.size()) {
            throw out_of_range("Indeks item tidak valid saat mengambil item.");
        }
        return items[index];
    }

    void ListItems() const {
        if (items.empty()) {
            cout << "Inventory kosong." << endl;
            return;
        }
        for (size_t i = 0; i < items.size(); ++i) {
            cout << "[" << i + 1 << "] " << items[i].GetDescription() << "\n";
        }
    }

private:
    vector<T> items;
};

// ==============================================
// Part 3: Player Class dan Enemy Struct
// ==============================================

class Player {
public:
    Player(const string& playerName)
        : name(playerName), level(1), experience(0), expToLevelUp(100),
          maxHealth(100), health(100), attackPower(15), defense(2), gold(50) {}

    void ShowStatus() const {
        cout << "\n=== Status Player ===\n";
        cout << "Nama   : " << name << "\n";
        cout << "Level  : " << level << "\n";
        cout << "EXP    : " << experience << "/" << expToLevelUp << "\n";
        cout << "HP     : " << health << "/" << maxHealth << "\n";
        cout << "Attack : " << attackPower << "\n";
        cout << "Defense: " << defense << "\n";
        cout << "Gold   : " << gold << "\n";
        cout << "======================\n";
    }

    bool IsAlive() const {
        return health > 0;
    }

    int Attack() const {
        return attackPower;
    }

    void TakeDamage(int damage) {
        int actualDamage = max(0, damage - defense);
        health = max(0, health - actualDamage);
        cout << name << " menerima " << actualDamage << " damage. HP sekarang " << health << ".\n";
    }

    void Heal(int amount) {
        if (amount <= 0) {
            throw invalid_argument("Jumlah heal harus positif.");
        }
        health = min(maxHealth, HealValue(health, amount));
        cout << name << " menggunakan potion dan mendapatkan " << amount << " HP. HP sekarang " << health << ".\n";
    }

    void AddExperience(int exp) {
        if (exp < 0) {
            throw invalid_argument("EXP tidak boleh negatif.");
        }
        experience += exp;
        cout << name << " mendapatkan " << exp << " EXP.\n";
        while (experience >= expToLevelUp) {
            experience -= expToLevelUp;
            LevelUp();
        }
    }

    void AddGold(int amount) {
        if (amount < 0) {
            throw invalid_argument("Gold tidak boleh negatif.");
        }
        gold += amount;
    }

    int GetGold() const {
        return gold;
    }

private:
    void LevelUp() {
        level++;
        maxHealth += 20;
        attackPower += 5;
        defense += 1;
        expToLevelUp += 30;
        health = maxHealth;

        cout << "\n*** Level Up! " << name << " sekarang level " << level << " ***\n";
        cout << "HP maksimal meningkat ke " << maxHealth << ".\n";
        cout << "Attack meningkat ke " << attackPower << ".\n";
        cout << "Defense meningkat ke " << defense << ".\n";
        cout << "======================\n";
    }

    string name;
    int level;
    int experience;
    int expToLevelUp;
    int maxHealth;
    int health;
    int attackPower;
    int defense;
    int gold;
};

struct Enemy {
    string name;
    int health;
    int attackPower;
    int rewardExp;
    int rewardGold;
};

// ==============================================
// Part 4: Utility Functions dan Random Loot
// ==============================================

int InputInteger(const string& prompt, int minValue, int maxValue) {
    while (true) {
        cout << prompt;
        int value;
        if (!(cin >> value)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid. Masukkan angka saja.\n";
            continue;
        }
        if (value < minValue || value > maxValue) {
            cout << "Masukkan angka antara " << minValue << " dan " << maxValue << ".\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return value;
    }
}

mt19937& RandomEngine() {
    static random_device rd;
    static mt19937 engine(rd());
    return engine;
}

int RandomRange(int minValue, int maxValue) {
    uniform_int_distribution<int> dist(minValue, maxValue);
    return dist(RandomEngine());
}

Item GenerateLoot() {
    vector<Item> lootTable = {
        {"Potion kecil", "Healing", 20, 10},
        {"Potion besar", "Healing", 45, 25},
        {"Pedang kayu", "Weapon", 6, 15},
        {"Pedang besi", "Weapon", 14, 40},
        {"Perisai kecil", "Armor", 0, 30}
    };
    int index = RandomRange(0, static_cast<int>(lootTable.size()) - 1);
    return lootTable[index];
}

void ShowLoot(const Item& item) {
    cout << "Kamu menemukan loot: " << item.GetDescription() << "\n";
}

// Template function untuk menggunakan item healing, bentuk nyata dari template di context game.
template <typename T>
void UseHealingItem(T& player, const Item& item) {
    if (item.type != "Healing") {
        throw invalid_argument("Item ini bukan item penyembuh.");
    }
    player.Heal(item.power);
}

Enemy CreateEnemy(int stage) {
    vector<Enemy> enemies = {
        {"Goblin", 40 + stage * 5, 8 + stage * 2, 25 + stage * 5, 15 + stage * 5},
        {"Skeleton", 55 + stage * 6, 10 + stage * 2, 30 + stage * 6, 20 + stage * 5},
        {"Serigala", 60 + stage * 7, 12 + stage * 3, 35 + stage * 7, 25 + stage * 6}
    };
    int index = RandomRange(0, static_cast<int>(enemies.size()) - 1);
    return enemies[index];
}

void ShowEnemy(const Enemy& enemy) {
    cout << "Musuh: " << enemy.name << " | HP: " << enemy.health << " | Attack: " << enemy.attackPower << "\n";
}

// ==============================================
// Part 5: Battle, Dungeon, dan Menu
// ==============================================

bool Battle(Player& player, Inventory<Item>& inventory, Enemy enemy) {
    cout << "\n===== Pertarungan Dimulai =====\n";
    while (player.IsAlive() && enemy.health > 0) {
        ShowEnemy(enemy);
        cout << "1. Serang\n";
        cout << "2. Gunakan item\n";
        cout << "3. Lari\n";
        int action = InputInteger("Pilih aksi: ", 1, 3);

        if (action == 1) {
            int damage = player.Attack();
            cout << "Kamu menyerang " << enemy.name << " dengan damage " << damage << ".\n";
            enemy.health = max(0, enemy.health - damage);
        } else if (action == 2) {
            if (inventory.IsEmpty()) {
                cout << "Tidak ada item di inventory.\n";
            } else {
                inventory.ListItems();
                int itemChoice = InputInteger("Pilih item (0 batal): ", 0, static_cast<int>(inventory.Size()));
                if (itemChoice == 0) {
                    cout << "Batal menggunakan item.\n";
                } else {
                    try {
                        const Item& item = inventory.GetItem(itemChoice - 1);
                        UseHealingItem(player, item);
                        inventory.RemoveItem(itemChoice - 1);
                    } catch (const exception& e) {
                        cout << "Kesalahan: " << e.what() << "\n";
                    }
                }
            }
        } else {
            int chance = RandomRange(1, 100);
            if (chance <= 50) {
                cout << "Kamu berhasil melarikan diri!\n";
                return false;
            }
            cout << "Lari gagal! Musuh menyerang.\n";
        }

        if (enemy.health > 0) {
            player.TakeDamage(enemy.attackPower);
        }
    }

    if (!player.IsAlive()) {
        cout << "Kamu kalah! Game over...\n";
        return true;
    }

    cout << "Musuh " << enemy.name << " dikalahkan!\n";
    player.AddExperience(enemy.rewardExp);
    player.AddGold(enemy.rewardGold);
    cout << "Dapatkan " << enemy.rewardGold << " gold dan " << enemy.rewardExp << " EXP.\n";
    return false;
}

void ShowMenu() {
    cout << "\n=== Menu Utama ===\n";
    cout << "1. Mulai eksplorasi dungeon\n";
    cout << "2. Lihat status\n";
    cout << "3. Buka inventory\n";
    cout << "4. Keluar\n";
}

void Explore(Player& player, Inventory<Item>& inventory) {
    cout << "\nKamu memasuki dungeon...\n";
    int stage = RandomRange(1, 3);
    Enemy enemy = CreateEnemy(stage);

    cout << "Tiba-tiba muncul musuh: " << enemy.name << "!\n";
    bool playerDead = Battle(player, inventory, enemy);

    if (playerDead) {
        throw runtime_error("Player mati dalam dungeon.");
    }

    if (RandomRange(1, 100) <= 75) {
        Item loot = GenerateLoot();
        ShowLoot(loot);
        inventory.AddItem(loot);
        cout << "Loot telah ditambahkan ke inventory.\n";
    } else {
        cout << "Tidak ada loot kali ini.\n";
    }
}

// ==============================================
// Part 6: Main Game Loop
// ==============================================

int main() {
    cout << "Selamat datang di Demo Game Template & Exception!\n";
    cout << "Masukkan nama player: ";
    string playerName;
    getline(cin, playerName);
    if (playerName.empty()) {
        playerName = "Hero";
    }

    Player player(playerName);
    Inventory<Item> inventory;

    // Tambahkan item awal ke inventory.
    inventory.AddItem({"Potion kecil", "Healing", 20, 10});
    inventory.AddItem({"Potion besar", "Healing", 45, 25});

    bool isRunning = true;
    while (isRunning) {
        try {
            ShowMenu();
            int choice = InputInteger("Pilih menu: ", 1, 4);
            switch (choice) {
                case 1:
                    Explore(player, inventory);
                    break;
                case 2:
                    player.ShowStatus();
                    break;
                case 3: {
                    cout << "\n=== Inventory ===\n";
                    inventory.ListItems();
                    cout << "1. Gunakan item healing\n";
                    cout << "2. Kembali\n";
                    int subChoice = InputInteger("Pilih aksi: ", 1, 2);
                    if (subChoice == 1) {
                        if (inventory.IsEmpty()) {
                            cout << "Inventory kosong.\n";
                            break;
                        }
                        inventory.ListItems();
                        int itemChoice = InputInteger("Pilih item (0 batal): ", 0, static_cast<int>(inventory.Size()));
                        if (itemChoice == 0) {
                            cout << "Batal.\n";
                            break;
                        }
                        try {
                            const Item& item = inventory.GetItem(itemChoice - 1);
                            UseHealingItem(player, item);
                            inventory.RemoveItem(itemChoice - 1);
                        } catch (const exception& e) {
                            cout << "Kesalahan: " << e.what() << "\n";
                        }
                    }
                    break;
                }
                case 4:
                    cout << "Terima kasih sudah bermain!\n";
                    isRunning = false;
                    break;
                default:
                    cout << "Pilihan tidak valid. Coba lagi.\n";
                    break;
            }
        } catch (const invalid_argument& e) {
            cout << "Input tidak valid: " << e.what() << "\n";
        } catch (const runtime_error& e) {
            cout << "Kesalahan runtime: " << e.what() << "\n";
            cout << "Permainan selesai.\n";
            isRunning = false;
        } catch (const exception& e) {
            cout << "Terjadi kesalahan: " << e.what() << "\n";
        }
    }

    return 0;
}
*/
