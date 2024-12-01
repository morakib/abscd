#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int stepCountRecursive = 0;

int fibonacciRecursive(int n)
{
    stepCountRecursive++;
    if (n <= 1)
        return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

vector<int> generateFibonacciRecursive(int n)
{
    stepCountRecursive = 0; // Reset step count
    vector<int> fibSeries;
    for (int i = 0; i < n; i++)
    {
        fibSeries.push_back(fibonacciRecursive(i));
    }
    return fibSeries;
}

int stepCountIterative = 0;

vector<int> fibonacciIterative(int n)
{
    stepCountIterative = 0; // Reset step count
    vector<int> fibSeries;
    if (n == 0)
        return fibSeries;
    if (n >= 1)
        fibSeries.push_back(0);
    if (n >= 2)
        fibSeries.push_back(1);

    for (int i = 2; i < n; i++)
    {
        stepCountIterative++;
        fibSeries.push_back(fibSeries[i - 1] + fibSeries[i - 2]);
    }
    return fibSeries;
}

int main()
{
    // Read values of n from fibonacci.txt
    ifstream inputFile("fibonacci.txt");
    if (!inputFile)
    {
        cout << "Error: Unable to open file fibonacci.txt." << endl;
        return 1;
    }

    vector<int> nValues;
    int n;
    while (inputFile >> n)
    {
        nValues.push_back(n);
    }
    inputFile.close();

    // Vector to store steps for recursive and iterative approaches
    vector<int> recursiveSteps, iterativeSteps;

    // Process each n value
    for (int n : nValues)
    {
        generateFibonacciRecursive(n);
        recursiveSteps.push_back(stepCountRecursive);

        fibonacciIterative(n);
        iterativeSteps.push_back(stepCountIterative);

        cout << "For n = " << n << ":" << endl;
        cout << "Recursive steps: " << stepCountRecursive << endl;
        cout << "Iterative steps: " << stepCountIterative << endl;
        cout << "------------------------------" << endl;
    }

    // Optional: Print the step counts for each n in the vectors
    cout << "Recursive Step Counts: ";
    for (int steps : recursiveSteps)
    {
        cout << steps << " ";
    }
    cout << endl;

    cout << "Iterative Step Counts: ";
    for (int steps : iterativeSteps)
    {
        cout << steps << " ";
    }
    cout << endl;

    return 0;
}
