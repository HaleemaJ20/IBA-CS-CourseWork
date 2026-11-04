#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(nullptr));

    const int fam_sim = 50;
    int totalchildren = 0;

    for (int t = 0; t < fam_sim; t++) {
        bool havegirl = false;
        bool haveboy = false;
        int children = 0;

        while (!(havegirl && haveboy)) {           
            int child = rand() % 2;
            children++;                            

                if (child == 0) {
                    haveboy = true;                    
                    cout << "child " << children << ": boy\n";
                } else {
                    havegirl = true;
                    cout << "child " << children << ": girl\n";
                }
        }
        totalchildren += children;
    }
    double average = totalchildren/fam_sim;

    cout << "Total children: " << totalchildren << "\n";
    cout << "The average childern per family are " << average;
    return 0;
}
