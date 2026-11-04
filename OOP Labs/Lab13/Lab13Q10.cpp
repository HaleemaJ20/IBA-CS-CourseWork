#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
#include <functional>

using namespace std;
using namespace chrono;

long long comparisons = 0;

struct Transaction {
    int id;
    string customerName;
    double amount;
    string date; // YYYY-MM-DD
};

void swapFunc(Transaction &a, Transaction &b) {
    Transaction t = a;
    a = b;
    b = t;
}

void insertionSort(vector<Transaction>& a, int lo, int hi,
                   function<bool(const Transaction&, const Transaction&)> comp) {

    for (int i = lo + 1; i <= hi; i++) {
        Transaction key = a[i];
        int j = i - 1;

        while (j >= lo) {
            comparisons++;
            if (comp(key, a[j])) {
                a[j + 1] = a[j];
                j--;
            } else break;
        }

        a[j + 1] = key;
    }
}

int median3(vector<Transaction>& a, int i, int j, int k,
            function<bool(const Transaction&, const Transaction&)> comp) {

    if (comp(a[i], a[j])) {
        if (comp(a[j], a[k])) return j;
        else if (comp(a[i], a[k])) return k;
        else return i;
    } else {
        if (comp(a[i], a[k])) return i;
        else if (comp(a[j], a[k])) return k;
        else return j;
    }
}

int partition(vector<Transaction>& a, int lo, int hi,
              function<bool(const Transaction&, const Transaction&)> comp) {

    Transaction pivot = a[lo];
    int i = lo;
    int j = hi + 1;

    while (true) {

        while (true) {
            i++;
            if (i > hi) break;
            comparisons++;
            if (!comp(a[i], pivot)) break;
        }

        while (true) {
            j--;
            if (j <= lo) break;
            comparisons++;
            if (!comp(pivot, a[j])) break;
        }

        if (i >= j) break;

        swapFunc(a[i], a[j]);
    }

    swapFunc(a[lo], a[j]);
    return j;
}

void quicksortPro(vector<Transaction>& a, int lo, int hi,
                  function<bool(const Transaction&, const Transaction&)> comp,
                  int cutoff = 10) {

    if (hi <= lo) return;

    if (hi - lo + 1 <= cutoff) {
        insertionSort(a, lo, hi, comp);
        return;
    }

    int p = partition(a, lo, hi, comp);

    quicksortPro(a, lo, p - 1, comp, cutoff);
    quicksortPro(a, p + 1, hi, comp, cutoff);
}

void print(vector<Transaction>& a) {
    for (auto &t : a) {
        cout << t.id << " " << t.customerName
             << " $" << t.amount
             << " " << t.date << endl;
    }
}

void runSort(vector<Transaction> data, string title,
             function<bool(const Transaction&, const Transaction&)> comp) {

    comparisons = 0;

    auto start = high_resolution_clock::now();
    quicksortPro(data, 0, data.size() - 1, comp);
    auto end = high_resolution_clock::now();

    long long time = duration_cast<microseconds>(end - start).count();

    cout << "\n=== " << title << " ===\n";
    print(data);
    cout << "Comparisons: " << comparisons
         << " | Time: " << time << " us\n";
}

int main() {

    vector<Transaction> data = {
        {1, "Ali", 1200.50, "2026-04-10"},
        {2, "Sara", 4500.00, "2026-04-15"},
        {3, "Ahmed", 3800.75, "2026-04-10"},
        {4, "Zara", 2100.00, "2026-04-11"},
        {5, "Bilal", 3200.40, "2026-04-09"},
        {6, "Hina", 1500.00, "2026-04-15"},
        {7, "Usman", 2750.20, "2026-04-12"},
        {8, "Ayesha", 5000.00, "2026-04-08"},
        {9, "Omar", 1800.60, "2026-04-11"},
        {10, "Fatima", 4100.00, "2026-04-10"},
        {11, "Noor", 2900.30, "2026-04-09"},
        {12, "Hamza", 3600.00, "2026-04-15"},
        {13, "Laiba", 2200.90, "2026-04-12"},
        {14, "Danish", 3300.00, "2026-04-08"},
        {15, "Kiran", 2750.00, "2026-04-10"}
    };

    double total = 0;
    double maxAmt = 0;

    for (auto &t : data) {
        total += t.amount;
        maxAmt = max(maxAmt, t.amount);
    }

    runSort(data, "Sort i: By Amount (Desc)",
        [](const Transaction& a, const Transaction& b) {
            return a.amount > b.amount;
        });

    runSort(data, "Sort ii: By Date, then Amount",
        [](const Transaction& a, const Transaction& b) {
            if (a.date == b.date)
                return a.amount > b.amount;
            return a.date < b.date;
        });

    runSort(data, "Sort iii: By Name, then Amount",
        [](const Transaction& a, const Transaction& b) {
            if (a.customerName == b.customerName)
                return a.amount < b.amount;
            return a.customerName < b.customerName;
        });

    cout << "\n=== Summary ===\n";
    cout << "Transactions : " << data.size() << endl;
    cout << "Highest Sale  : $" << maxAmt << endl;
    cout << "Total Revenue : $" << total << endl;

    return 0;
}