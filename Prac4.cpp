#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string addLargeNumbers(string num1, string num2) {
    if (num1.length() > num2.length())
        swap(num1, num2);

    string result = "";
    int n1 = num1.length(), n2 = num2.length();
    int carry = 0;

    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    for (int i = 0; i < n1; i++) {
        int sum = (num1[i] - '0') + (num2[i] - '0') + carry;
        result += (sum % 10 + '0');
        carry = sum / 10;
    }

    for (int i = n1; i < n2; i++) {
        int sum = (num2[i] - '0') + carry;
        result += (sum % 10 + '0');
        carry = sum / 10;
    }

    if (carry)
        result += (carry + '0');

    reverse(result.begin(), result.end());
    return result;
}

string subtractLargeNumbers(string num1, string num2) {
    // Ensure num1 >= num2
    if (num1.length() < num2.length() ||
       (num1.length() == num2.length() && num1 < num2)) {
        swap(num1, num2);
        cout << "-"; // optional for showing negative result
    }

    string result = "";
    int n1 = num1.length(), n2 = num2.length();
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    int carry = 0;
    for (int i = 0; i < n2; i++) {
        int sub = (num1[i] - '0') - (num2[i] - '0') - carry;

        if (sub < 0) {
            sub += 10;
            carry = 1;
        } else
            carry = 0;

        result += (sub + '0');
    }

    for (int i = n2; i < n1; i++) {
        int sub = (num1[i] - '0') - carry;
        if (sub < 0) {
            sub += 10;
            carry = 1;
        } else
            carry = 0;
        result += (sub + '0');
    }

    // Remove leading zeros
    while (result.length() > 1 && result.back() == '0')
        result.pop_back();

    reverse(result.begin(), result.end());
    return result;
}



int main(){
    string A = "8251584589632353453545355";
    string B = "6244674757245345457747964";

    cout<<addLargeNumbers(A, B)<<endl;
    cout<<subtractLargeNumbers(A, B)<<endl;
    return 0;
}