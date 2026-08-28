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
#include <future>
#include <algorithm> // Added for std::all_of if needed later

using namespace std;

// Global mutex to protect shared resources (like Lab's state)
mutex mx;

struct pabric {
    int cash = 0;
    int gold = 0;
    float market_price = 0.0f;
    // Added Experience tracking member
    int experience = 0; 
};

// Function to simulate resource generation (Gold)
// Passes Lab by reference to modify the shared state safely.
void methgen(pabric& lab, int sleep_seconds) {
    // Use a RAII lock guard to ensure the mutex is released even if an exception occurs
    lock_guard<mutex> lock(mx);
    
    cout << "\n[Worker Thread] Starting work for " << sleep_seconds << " seconds..." << endl;
    this_thread::sleep_for(chrono::seconds(sleep_seconds));
    
    // Update shared state safely
    lab.gold += 1;
    lab.experience += 10; // Example: Earn 10 XP upon completion
    
    cout << "\n--- [Success] ---" << endl;
    cout << "You have made 1 gold and gained 10 XP." << endl;
    cout << "Current State: Gold=" << lab.gold << ", XP=" << lab.experience << endl;
}

// Function to check for experience eligibility (Placeholder for your filtering logic)
bool canAffordFeature(const pabric& lab, int required_experience) {
    return lab.experience >= required_experience;
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
    thread meth(methgen, ref(lab), 5); // Use ref() to pass lab by reference
    thread meth2(methgen, ref(lab), 12); // Use ref()
    
    // 2. Wait for all threads to complete (Crucial step!)
    meth.join();
    meth2.join();
    
    cout << "\n===============================================" << endl;
    cout << "All background tasks finished." << endl;
    cout << "Final Lab State: Cash=" << lab.cash << ", Gold=" << lab.gold 
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