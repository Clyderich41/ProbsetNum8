#include <iostream>
#include <string>
#include <algorithm> 
using namespace std;

int main() {
    string num1_str = "987654321987654321"; 
    string num2_str = "123456789123456789"; 

    string result = "";
    int carry = 0;

    string temp_num1 = num1_str;
    string temp_num2 = num2_str;


    reverse(temp_num1.begin(), temp_num1.end());
    reverse(temp_num2.begin(), temp_num2.end());

    if (temp_num2.length() > temp_num1.length()) {
        swap(temp_num1, temp_num2);
    }

    for (size_t i = 0; i < temp_num2.length(); ++i) {
        int digit1 = temp_num1[i] - '0'; 
        int digit2 = temp_num2[i] - '0';
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result += (sum % 10) + '0';
    }

    for (size_t i = temp_num2.length(); i < temp_num1.length(); ++i) {
        int digit1 = temp_num1[i] - '0';
        int sum = digit1 + carry;
        carry = sum / 10;
        result += (sum % 10) + '0';
    }

    if (carry != 0) {
        result += carry + '0';
    }

    reverse(result.begin(), result.end());

    cout << "Sum of " << num1_str << " and " << num2_str << " is: " << result << endl;

    return 0;
}