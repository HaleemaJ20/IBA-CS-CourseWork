#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
using namespace std;

struct MemoryPage {
    int pageId;
    int sizeKB;
    long lastAccessed;
};

int fullFold(const vector<MemoryPage>& pages) {
    int total = 0;
    for (const auto& p : pages) {
        total += p.sizeKB;
    }
    return total;
}

pair<int, int> partialFold(vector<MemoryPage>& pages, int limit) {
    int sum = 0;

    for (int i = 0; i < pages.size(); i++) {
        sum += pages[i].sizeKB;

        if (sum > limit) {
            return {sum, i};  
        }
    }

    return {sum, -1}; // -1 means never exceeded
}

int main() {

    vector<MemoryPage> pages;

    // Generate 20 random pages
    for (int i = 0; i < 20; i++) {
        MemoryPage p;
        p.pageId = i;
        p.sizeKB = rand() % 100 + 1; // 1–100 KB
        p.lastAccessed = rand();

        pages.push_back(p);
    }

    // Full fold
    int total = fullFold(pages);
    cout << "Total Memory (Full Fold): " << total << " KB\n";

    // Partial fold (limit = 512 KB)
    pair<int, int> result = partialFold(pages, 512);

    cout << "Partial Sum: " << result.first << " KB\n";
    cout << "Stopped at index: " << result.second << endl;

    /*
    Explanation:
    Partial folding is preferable when:
     You only need memory up to a threshold (eg quota = 512 KB)
     It avoids scanning all pages
     Saves CPU time in large systems
    */

    return 0;
}