#include "Function.h"

std::ostream& operator<<(std::ostream& os, const Function& func) {
    func.print(os);
    return os;
}