#include <iostream>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

/**
 *  PARTS ADDED
 *  - added relavent comments
 *  - added the base case for checking when the number is equal to 1
 *  - added the 'isOne()' function to check whether the number represented as a vector<int> is 1
 *  - added the 'multiply()' which multiplies two numbers represented in vector<int> format
 *  - called the 'findFactorial()' function from main and printed the output.
 **/

// Function to check if a number is one.
bool isOne(vector<int> &number) {
    // Check if the last digit is not 1.
    if(number[number.size() - 1] != 1) {
        return false;
    }

    // Check if all digits before the last one are not zero.
    for(int i = 0; i < number.size() - 1; i++) {
        if(number[i] != 0) {
            return false;
        }
    }
    // If the last digit is 1 and all other digits are 0, return true.
    return true;
}

// Function to multiply two numbers represented as vectors.
void multiply(vector<int>& num1, vector<int>& num2) {
    int n1 = num1.size();
    int n2 = num2.size();

    // Initialize result vector with size n1+n2.
    vector<int> result(n1 + n2, 0);  

    // Multiply two numbers digit by digit.
    for (int i = n1 - 1; i >= 0; i--) {
        for (int j = n2 - 1; j >= 0; j--) {
            result[i + j + 1] += num1[i] * num2[j];
        }
    }

    // Carry over the tens digit to the next value.
    for (int i = n1 + n2 - 1; i > 0; i--) {
        if (result[i] >= 10) {
            result[i - 1] += result[i] / 10;
            result[i] %= 10;
        }
    }

    // Remove leading zeros.
    while(result.size() > 1 && result[0] == 0) {
        result.erase(result.begin());
    }

    // Update num2 with the result.
    num2 = result;      
}

// Recursive function to find the factorial of a number.
vector<int> findFactorial(vector<int>& number) {
  // Base case: if number is one, return one.
  if(isOne(number)) {
    return {1};
  }
  
  // Create a copy of the original number.
  vector<int> originalNumber = number; 

  // Decrease the number by 1.
  int i = originalNumber.size() - 1;
  while(originalNumber[i] == 0) {
    originalNumber[i] = 9;
    i--;
  }
  originalNumber[i]--;

  // Recursively find the factorial of the decreased number.
  vector<int> factorial = findFactorial(originalNumber);

  // Multiply the original number with the factorial of the decreased number.
  multiply(number, factorial);

  // Return the factorial.
  return factorial;
}

int main() {
  // Initialize a number.
  vector<int> number = {1,5};

  // Find the factorial of the number.
  vector<int> ans = findFactorial(number);

  // Print the factorial.
  for(int i = 0; i < ans.size(); i++) {
    cout<<ans[i];
  }
  
  return 0;
}
