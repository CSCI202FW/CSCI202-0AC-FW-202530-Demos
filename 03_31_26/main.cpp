#include <iostream>
#include <string>
#include <regex>
#include <cmath>
#include "arrayStack.h"
#include "linkedStack.h"

// M03-a come up with 5 binary numbers of test data for the converter
std::string getBinaryNumber();
int convertToDecimal(stackADT<int> &);

int main()
{
    arrayStack<int> aStack;
    linkedStack<int> lStack;
    std::string binNumber1 = getBinaryNumber();
    for (int i = 0; i < binNumber1.size(); i++)
    {
        aStack.push(binNumber1[i] - '0');
    }
    std::cout << binNumber1 << " converted to decimal is " << convertToDecimal(aStack) << std::endl;
    std::string binNumber2 = getBinaryNumber();
    for (int i = 0; i < binNumber2.size(); i++)
    {
        lStack.push(binNumber2[i] - '0');
    }
    std::cout << binNumber2 << " converted to decimal is " << convertToDecimal(lStack) << std::endl;
    return 0;
}

std::string getBinaryNumber()
{
    std::regex binNum(R"([^10]+)");
    std::regex space(R"(\s+)");
    std::string binaryNumber;
    std::cout << "Enter a number in binary: ";
    std::getline(std::cin >> std::ws, binaryNumber);
    binaryNumber = std::regex_replace(binaryNumber, space, "");
    while (std::regex_search(binaryNumber, binNum))
    {
        std::cout << "Please enter only 1s and 0s." << std::endl;
        std::cout << "Enter a number in binary: ";
        std::getline(std::cin >> std::ws, binaryNumber);
        binaryNumber = std::regex_replace(binaryNumber, space, "");
    }
    return binaryNumber;
}

int convertToDecimal(stackADT<int> &binNum)
{
    int digit = 0;
    int position = 0;
    int converted = 0;
    while (!binNum.isEmptyStack())
    {
        digit = binNum.pop();
        converted += pow(2, position) * digit;
        position++;
    }
    return converted;
}
