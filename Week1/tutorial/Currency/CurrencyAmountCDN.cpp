#include <iostream>
#include <string>
#include "CurrencyAmountCDN.hpp"

CurrencyAmountCDN::CurrencyAmountCDN() : dollars(0), cents(0) {}

CurrencyAmountCDN::~CurrencyAmountCDN()
{
}

CurrencyAmountCDN::CurrencyAmountCDN(double _value) {
    if(_value < 0){
        dollars = 0, cents = 0;
    }
    else {
        std::string valString = std::to_string(_value);
        dollars = int(_value);
        int index = 0;
        for(int i = 0; i < valString.length(); i++ ) {
            if(valString[i] == '.') {
                index = i;
                break;
            }
        }
        cents = std::stoi(valString.substr(index + 1, 2));
    }
}

CurrencyAmountCDN::CurrencyAmountCDN(uint8_t _dollars, uint8_t _cents) : 
    dollars(_dollars), cents(_cents) {
}

uint8_t CurrencyAmountCDN::getDollars(){
    return dollars;
}

uint8_t CurrencyAmountCDN::getCents(){
    return cents;
}

void CurrencyAmountCDN::printCurrency() {
    double currencyAmount = double(dollars) + double(cents)/100;
    std::cout << "$" << currencyAmount << std::endl;
}

CurrencyAmountCDN CurrencyAmountCDN::operator+( CurrencyAmountCDN& _currency) {
    CurrencyAmountCDN current(*this);
    uint8_t newDollars = current.getDollars() + _currency.getDollars();
    uint8_t newCents = current.getCents() + _currency.getCents();
    if(newCents >= 100) {
        ++newDollars;
        newCents %= 100;
    }
    CurrencyAmountCDN newCurrency(newDollars, newCents);
    return newCurrency;
}

CurrencyAmountCDN CurrencyAmountCDN::operator-( CurrencyAmountCDN& _currency) {
    CurrencyAmountCDN current(*this);
    uint8_t newDollars = current.getDollars() - _currency.getDollars();
    uint8_t newCents = current.getCents() - _currency.getCents();
    if(newCents < 0) {
        --newDollars;
        newCents += 100;
    }
    if(newDollars < 0) {
        newCents = 0, newDollars = 0;
    }
    CurrencyAmountCDN newCurrency(newDollars, newCents);
    return newCurrency;
}

double CurrencyAmountCDN::convertToUSD(){
    double currencyAmount = double(dollars) + double(cents)/100;
    return currencyAmount * CAD_TO_USD;
}

double CurrencyAmountCDN::convertToYen(){
    double currencyAmount = double(dollars) + double(cents)/100;
    return currencyAmount * CAD_TO_YEN;
}