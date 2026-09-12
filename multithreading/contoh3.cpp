// Love your self
// Tycoon Gold mine
// pABRUK mAKE STUFF TO SELL FOR CASH
// USE CASH LVL UP MORE CASH
#include <iostream>
#include <string>
#include <random>
#include <vector>
#include <chrono>
#include <thread>
#include <mutex>
#include <atomic>
#include <future>
#include <algorithm> // Added for std::all_of if needed later

using namespace std;

// Global mutex to protect shared resources (like Lab's state)
mutex mx;

float marketPrice = 10.0f; // Global value market price
atomic<bool> market_running = true;

void updateMarketPrice(int interval_seconds) {
    random_device random_device;
    mt19937 generator(random_device());
    uniform_real_distribution<float> price_distribution(5.0f, 20.0f);

    while (market_running) {
        this_thread::sleep_for(chrono::seconds(interval_seconds));
        {
            lock_guard<mutex> lock(mx);
            marketPrice = price_distribution(generator);
            cout << "\n[Market] New market price: " << marketPrice << endl;
        }
    }
}

struct pabric {
    float cash = 0.0f;
    int gold = 0;
    int experience = 0; 
};

// Function to simulate resource generation (Gold)
// Passes Lab by reference to modify the shared state safely.
void methgen(pabric& lab, int sleep_seconds) {
    cout << "\n[Worker Thread] Starting work for " << sleep_seconds << " seconds..." << endl;
    this_thread::sleep_for(chrono::seconds(sleep_seconds));
    {
        lock_guard<mutex> lock(mx);
        lab.gold += 1;
        lab.experience += 10;

        cout << "\n--- [Success] ---" << endl;
        cout << "You have made 1 gold and gained 10 XP." << endl;
        cout << "Current State: Gold=" << lab.gold << ", XP=" << lab.experience << endl;
    }
}

// Function to check for experience eligibility (Placeholder for your filtering logic)
bool canAffordFeature(const pabric& lab, int required_experience) {
    return lab.experience >= required_experience;
}

void sellGold(pabric& lab, int amount) {
    lock_guard<mutex> lock(mx);

    if (amount <= 0) {
        cout << "Amount must be greater than zero." << endl;
    } else if (amount > lab.gold) {
        cout << "You only have " << lab.gold << " gold." << endl;
    } else {
        float earnings = amount * marketPrice;
        lab.gold -= amount;
        lab.cash += earnings;
        cout << "Sold " << amount << " gold for " << earnings << " cash." << endl;
    }
}


int main() {
    cout << "===============================================" << endl;
    cout << "Welc0Me tO E**g*l Me** L*b Si*uL*Ti*N" << endl;
    cout << "Lets Continue The last yOU kNOW Dr *******" << endl;
    cout << "Wait, Your acc has been terminated Welp gtg make a new one" << endl;
    cout << "Pls Enter YOur new Name DR" << endl;
    
    string name;
    cin >> name;
    
    cout << "\nOh WOW DR " << name << " What a nice name" << endl;
    cout << "Now lets get started with your new acc" << endl;
    
    pabric lab; // Initialize lab on the stack
    
    // 1. Launch background tasks
    const int MARKET_UPDATE_INTERVAL = 3; // update interval
    thread market_thread(updateMarketPrice, MARKET_UPDATE_INTERVAL); // thread update market price
    thread meth(methgen, ref(lab), 5); // Use ref() to pass lab by reference
    thread meth2(methgen, ref(lab), 12); // Use ref()
    
    // 2. Wait for all threads to complete (Crucial step!)
    meth.join();
    meth2.join();

    cout << "\n===============================================" << endl;
    cout << "Background tasks finished. Market is still running." << endl;

    int choice;
    do {
        cout << "\n[1] Sell gold  [2] Show status  [0] Exit" << endl;
        cout << "Choose an action: ";
        cin >> choice;

        if (choice == 1) {
            int amount;
            cout << "How many gold do you want to sell? ";
            cin >> amount;
            sellGold(lab, amount);
        } else if (choice == 2) {
            lock_guard<mutex> lock(mx);
            cout << "Cash=" << lab.cash << ", Gold=" << lab.gold
                 << ", Experience=" << lab.experience
                 << ", Market price=" << marketPrice << endl;
        } else if (choice != 0) {
            cout << "Invalid choice." << endl;
        }
    } while (choice != 0);

    market_running = false;
    market_thread.join();

    cout << "\nFinal Lab State: Cash=" << lab.cash << ", Gold=" << lab.gold
         << ", Experience=" << lab.experience << endl;

    // 3. Example of using the new filter/check function
    const int REQUIRED_XP = 50;
    if (canAffordFeature(lab, REQUIRED_XP)) {
        cout << "\n[System] Congratulations! You meet the requirement of " << REQUIRED_XP << " XP!" << endl;
    } else {
        cout << "\n[System] You currently only have " << lab.experience << " XP. Need " << REQUIRED_XP - lab.experience << " more to unlock the next feature." << endl;
    }

    return 0;
}