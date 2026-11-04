#include <iostream>

int main()
{
    double w = 4.20;
    double b = 1.40;
    double x, y_pred, y_true;
    int correctCount = 0;

    std::cout << "Enter 10 integer values for x:\n";

    for (int i = 0; i < 10; ++i)
    {
        std::cin >> x;

        y_pred = w * x + b;
        y_true = 2 * x * x - 4;

        double diff = y_pred - y_true;
        if (diff < 0)
            diff = -diff;

        std::cout << "x = " << x
                  << ", prediction = " << y_pred
                  << ", target = " << y_true;

        if (diff <= 1.0)
        {
            std::cout << " correct\n";
            correctCount++;
        }
        else
        {
            std::cout << " incorrect\n";
        }
    }

    double accuracy = (correctCount / 10.0) * 100.0;
    std::cout << "\nOverall accuracy = " << accuracy << "%\n";

    return 0;
}