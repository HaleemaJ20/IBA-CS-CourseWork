#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

template<typename T, typename F>
vector<T> mapFunc(const vector<T>& v, F func) {
    vector<T> result(v.size());

    transform(v.begin(), v.end(), result.begin(), func);

    return result;
}

template<typename T, typename P>
vector<T> filterFunc(const vector<T>& v, P pred) {
    vector<T> result;

    copy_if(v.begin(), v.end(), back_inserter(result), pred);

    return result;
}

template<typename T>
double reduceFunc(const vector<T>& v) {
    double sum = accumulate(v.begin(), v.end(), 0.0);
    return sum / v.size();
}

void printVector(const vector<double>& v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {

    vector<double> tempsC = {-5, 0, 15, 20, 25, 30, 35, 40};

    cout << "Original (C): ";
    printVector(tempsC);

    vector<double> tempsF = mapFunc(tempsC,
        [](double c) {
            return c * 9.0 / 5 + 32 + 5;
        });

    cout << "After Map (F): ";
    printVector(tempsF);

    vector<double> filtered = filterFunc(tempsF,
        [](double f) {
            return f > 70;
        });

    cout << "After Filter (>70F): ";
    printVector(filtered);

    double avg = reduceFunc(filtered);

    cout << "Average: " << avg << endl;

    return 0;
}