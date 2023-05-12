#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Define a function to calculate the mean of a vector of values
double mean(vector<double> values) {
    double sum = 0;
    for (int i = 0; i < values.size(); i++) {
        sum += values[i];
    }
    return sum / values.size();
}

// Define a function to calculate the variance of a vector of values
double variance(vector<double> values) {
    double sum = 0;
    double mu = mean(values);
    for (int i = 0; i < values.size(); i++) {
        sum += pow(values[i] - mu, 2);
    }
    return sum / (values.size() - 1);
}

// Define a function to calculate the covariance of two vectors of values
double covariance(vector<double> x, vector<double> y) {
    double sum = 0;
    double xmu = mean(x);
    double ymu = mean(y);
    for (int i = 0; i < x.size(); i++) {
        sum += (x[i] - xmu) * (y[i] - ymu);
    }
    return sum / (x.size() - 1);
}

// Define a function to perform linear regression
void linearRegression(vector<double> x, vector<double> y, double& slope, double& intercept) {
    double xmu = mean(x);
    double ymu = mean(y);
    slope = covariance(x, y) / variance(x);
    intercept = ymu - slope * xmu;
}

int main() {
    int n; // Number of data points
    cout << "Enter the number of data points: ";
    cin >> n;

    vector<double> x(n);
    vector<double> y(n);

    // Input x and y values from user
    for (int i = 0; i < n; i++) {
        cout << "Enter x[" << i << "]: ";
        cin >> x[i];
        cout << "Enter y[" << i << "]: ";
        cin >> y[i];
    }

    double slope, intercept;
    linearRegression(x, y, slope, intercept);
    cout << "Slope: " << slope << endl;
    cout << "Intercept: " << intercept << endl;

    // Print equation of line
    cout << "Equation of line: y = " << slope << "x + " << intercept << endl;

    return 0;
}
