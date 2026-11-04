#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class StatisticsCollector {
private:
    int count;
    int sum;
    int minScore;
    int maxScore;

public:
    StatisticsCollector() {
        count = 0;
        sum = 0;
        minScore = 100000; 
        maxScore = -100000; 
    }

    void operator()(int score) {
        count++;
        sum += score;

        if (score < minScore)
            minScore = score;

        if (score > maxScore)
            maxScore = score;
    }

    void displayStats() const {
        double average = (double)sum / count;

        cout << "Students: " << count << endl;
        cout << "Average: " << average << endl;
        cout << "Highest: " << maxScore << endl;
        cout << "Lowest: " << minScore << endl;
    }
};

int main() {

    vector<int> scores = {78, 92, 65, 88, 45, 95, 73};

    StatisticsCollector stats;

    stats = for_each(scores.begin(), scores.end(), stats);

    stats.displayStats();

    return 0;
}