#include <iostream>
#include <string>

#include "Quote.h"

double print_total(std::ostream& os, 
                    const Quote& item, std::size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n   
    << " total due: " << ret << std::endl;
    return ret;
}

double BulkQuote::net_price(std::size_t cnt) const
{
    if (cnt >= quantity) {
        return cnt * (1 - discount) * price;
    } else {
        return cnt * price;
    }
}

double Basket::total_receipt(std::ostream& os) const
{
    double sum = 0.0;
    for (auto iter = items.cbegin(); 
        iter != items.cend(); 
        iter = items.upper_bound(*iter))
    {
        sum += print_total(os, **iter, items.count(*iter));
    }

    os << "total sale: " << sum << std::endl;
    return sum;
}
