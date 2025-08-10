#include <iostream>
#include <string>

#include "Quote.h"

double BulkQuote::net_price(std::size_t cnt) const
{
    if (cnt >= quantity) {
        return cnt * (1 - discount) * price;
    } else {
        return cnt * price;
    }
}