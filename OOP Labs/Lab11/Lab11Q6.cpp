#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <iomanip>
#include <algorithm>
using namespace std;

class Stopwatch
{
    chrono::high_resolution_clock::time_point t_start, t_stop;

public:
    void start() { t_start = chrono::high_resolution_clock::now(); }
    void stop() { t_stop = chrono::high_resolution_clock::now(); }

    double elapsedMs() const
    {
        return chrono::duration_cast<chrono::microseconds>(t_stop - t_start).count() / 1000.0;
    }
};

vector<int> randomArray(int n, int seed)
{
    mt19937 rng(seed);
    uniform_int_distribution<int> dist(1, 100000);

    vector<int> v(n);
    for (int &x : v)
        x = dist(rng);
    return v;
}

void standardInsertionSort(vector<int> &arr, int &cmp)
{
    for (int i = 1; i < arr.size(); i++)
    {
        int key = arr[i], j = i - 1;
        while (j >= 0 && (++cmp && arr[j] > key))
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int binarySearchPos(vector<int> &arr, int key, int low, int high, int &cmp)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;
        cmp++;
        if (arr[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}

void binaryInsertionSort(vector<int> &arr, int &cmp)
{
    for (int i = 1; i < arr.size(); i++)
    {
        int key = arr[i];
        int pos = binarySearchPos(arr, key, 0, i - 1, cmp);

        for (int j = i - 1; j >= pos; j--)
            arr[j + 1] = arr[j];

        arr[pos] = key;
    }
}

int main()
{
    vector<int> sizes = {500, 1000, 2000, 4000, 8000, 16000};

    cout << fixed << setprecision(2);

    for (int n : sizes)
    {
        vector<int> arr = randomArray(n, 42);
        vector<int> a = arr, b = arr;

        Stopwatch sw;

        int cmp1 = 0, cmp2 = 0;

        sw.start();
        standardInsertionSort(a, cmp1);
        sw.stop();
        double t1 = sw.elapsedMs();

        sw.start();
        binaryInsertionSort(b, cmp2);
        sw.stop();
        double t2 = sw.elapsedMs();

        if (a != b)
            cout << "SORT MISMATCH\n";

        cout << n << " | " << t1 << " | " << cmp1
             << " | " << t2 << " | " << cmp2
             << " | " << t1 / t2 << "x\n";
    }

    return 0;
}