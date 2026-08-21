#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;

struct GameResource {
    int id;
    string name;
};

mutex mtx;

void process(GameResource res) {
    lock_guard<mutex> lock(mtx);
    cout << "Processing resource " << res.id << ": " << res.name << endl;
}

int main() {
    vector<GameResource> resources = {
        {1, "Texture"}, {2, "Audio"}, {3, "Model"}
    };

    vector<thread> workers;
    for (auto &r : resources) {
        workers.emplace_back(thread(process, r));
    }

    for (auto &w : workers) {
        w.join();
    }

    cout << "All resources processed." << endl;
    return 0;
}