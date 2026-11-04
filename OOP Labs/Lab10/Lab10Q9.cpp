#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int countWords(string s) {
    if (s.length() == 0) return 0;

    int count = 1; 
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ')
            count++;
    }
    return count;
}

int main() {

    vector<string> sentences = {
        "Hello world",
        "Functional programming is powerful and elegant",
        "C++ supports lambdas",
        "This is a longer sentence with many words",
        "Short",
        "Map filter and reduce are fundamental operations"
    };

    cout << "Original sentences: " << sentences.size() << endl;

    vector<int> wordCounts;

    transform(sentences.begin(), sentences.end(), back_inserter(wordCounts),
        [](string s) {
            int count = 1;
            for (int i = 0; i < s.length(); i++) {
                if (s[i] == ' ')
                    count++;
            }
            return count;
        });

    cout << "Word counts: ";
    for (int i = 0; i < wordCounts.size(); i++) {
        cout << wordCounts[i] << " ";
    }
    cout << endl;

    vector<int> filtered;

    copy_if(wordCounts.begin(), wordCounts.end(), back_inserter(filtered),
        [](int count) {
            return count > 5;
        });

    cout << "After filter (>5 words): " << filtered.size() << " sentences\n";

    int total = accumulate(filtered.begin(), filtered.end(), 0);

    cout << "Total words in long sentences: " << total << endl;

    double avg = (double)total / filtered.size();

    cout << "Average length: " << avg << " words" << endl;

    return 0;
}