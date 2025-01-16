//Catherien Nicholson
//COSC 1437
//Program Set 3- Extra credit #1
// Refernces: Chapter 20, recursive funcitons, pdf attatched to problem to get list of some of the carmichael numbers
//ch 16, try/catch.


#include <iostream>
#include <string>
#include <cmath>
using namespace std;

//function to check if a number is a prime when entered by the user
bool isPrime(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
//Helper function to check if a number is a Carmichael number
bool isCarmichaelHelper(int n, int a) {
    if (a == n) {
        return true;
    }
    if (a <= 1 || n % a == 0) {
        return false;
    }
    int r = 1;
    for (int i = 0; i < n - 1; i++) {
        r = (r * a) % n;
    }
    return r == 1 && isCarmichaelHelper(n, a + 1);
}
//Recursive function to check list of carmichael numbers to see if input is a carmichael
bool isCarmichaelRecursive(int n) {
    if (n <= 2 || isPrime(n)) {
        return false;
    }
    //numbers from pdf attatched to the problem.
    int carmichaels[] = { 561, 1105, 1729, 2465, 2821, 6601, 8911, 10585, 15841, 29341,
        41041, 46657, 52633, 62745, 63973, 75361, 101101, 115921, 126217, 162401,
        172081, 188461, 252601, 278545, 294409, 314821, 334153, 340561, 399001,
        410041, 449065, 488881, 512461 };
    for (int i = 0; i < sizeof(carmichaels) / sizeof(carmichaels[0]); i++) {
        if (n == carmichaels[i]) {
            return true;
        }
    }
    return isCarmichaelHelper(n, 2);
}

int main() {
    char choice;
    do {
        string input;//input number onto one line
        cout << "Enter an integer in the range [1 - 1000000]: ";
        cin >> input;

        // Convert the input string to an integer
        int num;
        try {//try statement to make sure input is a string to number
            num = stoi(input);
        }
        catch (const std::invalid_argument& ia) {//catch statement  if user input is not a  number
            cout << "Invalid input. Please enter a valid integer." << endl;
            continue;
        }
        //check if the input number is a Carmichael number from the list
        if (isCarmichaelRecursive(num)) {
            cout << num << " is a Carmichael number." << endl;
        }
        else {
            cout << num << " is not a Carmichael number." << endl;
        }

        cout << "Do you want to run the program again? (y/n): ";// you may enter y,Y,n,N to answer the question
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

        return 0;
}