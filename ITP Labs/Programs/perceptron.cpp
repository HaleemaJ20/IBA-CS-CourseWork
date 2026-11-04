#include <iostream>
#include <iomanip> 

int main()
{
    double w = 0.0;          
    double b = 0.0;         
    double learningRate = 0.001;
    double x = 3.0;         
    double target = 14.0;    

    double y, error;       

    for (int i = 0; i <= 1000; i++) {
        // Compute the perceptron's current prediction
        y = w * x + b;

        // Compute the error (difference from target)
        error = target - y;

        // Update weight and bias using the learning rule
        w = w + learningRate * error * x;
        b = b + learningRate * error;

        if (i % 100 == 0) {
            std:: cout << std:: fixed << std:: setprecision(6) << std:: endl;
            std:: cout << "Step " << i << ": prediction = " << y << ", error = " << error;
        }
    }

    std:: cout << std::fixed << std:: setprecision(2) << std:: endl;
    std:: cout << "\nFinal prediction at x=3: " << (w * x + b) << std:: endl;
    std:: cout << "Target value: " << target << std:: endl;
    std:: cout << "Final w = " << w << ", b = " << b << std:: endl;

    return 0;
}
