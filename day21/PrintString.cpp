#include "PrintString.h"

std::ostream& operator<<(std::ostream& os, PrintString& ps)
{
    std::cout << "---------------------------" << std::endl;
    for (const auto& it : ps.svec) {
        os << it << " " << std::endl;
    }

    return os;
}