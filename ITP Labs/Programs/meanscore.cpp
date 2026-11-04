#include <iostream>
#include <vector>

int mean(std:: vector<int> a, size_t start, size_t end) {
    int sum = 0;
    for (size_t i = start; i < end; i++) {
        sum += a[i];
    }
    return sum / (end - start);
}

int scores_mean(std:: vector<int> scores) {
    if (scores.size() < 2) {
        std:: cout << "The vector size should be at least 2." << std:: endl;
        return 0;
    }

    size_t mid = scores.size() / 2;
    int mean1 = mean(scores, 0, mid);
    std:: cout << "The first half mean is " << mean1 << std:: endl;

    int mean2 = mean(scores, mid, scores.size());
    std:: cout << "The second half mean is " << mean2 << std:: endl;

    return (mean1 > mean2) ? mean1 : mean2;
}

int main() {
    int maxmean = scores_mean({9, 6, 4, 5, 1, 2, 3, 7, 6, 1, 9, 4, 2, 3, 1, 5});
    std:: cout << "The bigger mean is " << maxmean;
}
