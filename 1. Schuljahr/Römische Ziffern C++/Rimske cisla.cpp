#include <iostream> 
using namespace std;

typedef int Boolean; // Define identifier Boolean as a synonym for int
const int TRUE = 1;
const int FALSE = 0;

void PrintValue( /* in */ int dec1,/* in */ char op,/* in */ int dec2)
{
    cout << "Decimal value: ";
    switch (op) {
    case '+': cout << dec1 + dec2;
        break;
    case '-': cout << dec1 - dec2;
        break;
    case '*': cout << dec1 * dec2;
        break;
    case '/': cout << float(dec1) / float(dec2);
    }
    cout << "\n\n";
}
int DecEquiv( /* in */ const char str[])
{
    Boolean dataValid = TRUE;
    int intSum = 0;
    int i = 0;
    while (dataValid && str[i] != '\0')
    {
        switch (str[i]) {
        case 'M': intSum += 1000; break;
        case 'D': intSum += 500; break;
        case 'C': intSum += 100; break;
        case 'L': intSum += 50; break;
        case 'X': intSum += 10; break;
        case 'V': intSum += 5; break;
        case 'I': intSum += 1; break;
        default: dataValid = FALSE;
        }
        i++;
    }
    return (dataValid ? intSum : 0);
}

void Convert( /* in */ const char str[],
    /* out */ int& decVal,
    /* out */ Boolean& strValid)
{
    decVal = DecEquiv(str);
    strValid = (decVal > 0);
}


int main() {
    char str1[31]; // First Roman numeral string
    char str2[31]; // Second Roman numeral string
    char op; // Operator within expression
    int dec1; // Decimal value of first operand
    int dec2; // " " " second "
    Boolean str1Valid; // First string valid?
    Boolean str2Valid; // Second string valid?
    Boolean opValid; // Operator valid?
    // pokračovanie
    cout << "Roman numeral expression:\n";
    while (cin >> str1) {
        cin >> op >> str2;
        Convert(str1, dec1, str1Valid);
        Convert(str2, dec2, str2Valid);
        opValid = (op == '+' || op == '-' || op == '*' || op == '/');
        if (str1Valid && str2Valid && opValid)
            PrintValue(dec1, op, dec2);
        else
            cout << "BAD DATA\n\n";
        cout << "Roman numeral expression:\n";
    }

    cout << "\n";
    system("pause");
    return 0;
}