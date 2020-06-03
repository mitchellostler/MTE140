#pragma once
#include <stdint.h>
#define CAD_TO_USD 0.71
#define CAD_TO_YEN 76.05
const char YEN_SYMBOL = static_cast<char>(190);

class CurrencyAmountCDN
{

private:
    uint8_t dollars, cents;
    /* data */
public:
    //constructors
    CurrencyAmountCDN();
    CurrencyAmountCDN(uint8_t _dollars, uint8_t _cents);
    CurrencyAmountCDN(double _value);
    ~CurrencyAmountCDN();

    uint8_t getDollars();
    uint8_t getCents();
    
    CurrencyAmountCDN operator+( CurrencyAmountCDN& _currency);
    CurrencyAmountCDN operator-( CurrencyAmountCDN& _currency);
    void printCurrency();

    double convertToYen();
    double convertToUSD();

};

