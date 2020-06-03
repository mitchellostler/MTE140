#include <iostream>
#include <iomanip>
#include "CurrencyAmountCDN.hpp"

void testCurrencyAmount() {
    std::cout << std::fixed;
    std::cout << std::setprecision(2);

    CurrencyAmountCDN myCurrency1(15.85);
    CurrencyAmountCDN myCurrency2(12, 15);
    CurrencyAmountCDN myCurrency3;

    CurrencyAmountCDN myCurrency4 = myCurrency1 + myCurrency2;
    CurrencyAmountCDN myCurrency5 = myCurrency1 - myCurrency2;
    CurrencyAmountCDN myCurrency6 = myCurrency2 - myCurrency1;

    CurrencyAmountCDN myCurrency7(10.00);
    double yen = myCurrency7.convertToYen();
    double usd = myCurrency7.convertToUSD();

    std::cout << "This value should be 15.85: ";
    myCurrency1.printCurrency();
    std::cout << "\nThis value should be 12.15: ";
    myCurrency2.printCurrency();
    std::cout << "\nThis value should be 0.00: ";
    myCurrency3.printCurrency();
    std::cout << "\nThis value should be 28.00: ";
    myCurrency4.printCurrency();
    std::cout << "\nThis value should be 3.70: ";
    myCurrency4.printCurrency();
    std::cout << "\nThis value should be 0.00: ";
    myCurrency4.printCurrency();

    std::cout << "10 CAD in USD: $" << myCurrency7.convertToUSD() << " In Yen: " << YEN_SYMBOL << myCurrency7.convertToYen() << std::endl;
}

int main() {
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    testCurrencyAmount();

}