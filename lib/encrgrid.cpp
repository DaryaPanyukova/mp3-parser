#include "encrgrid.h"

EncrGrid::EncrGrid(const std::string &id, uint32_t size, char status_flags, char format_flags) :
        UfidPriv(id, size, status_flags, format_flags) {}

void EncrGrid::setSymbol(char symbol) {
    symbol_ = symbol;
}

void EncrGrid::Print() {
    UfidPriv::Print();
    if (id_ == "ENCR") {
        std::cout << "Method Symbol: " << symbol_ << '\n';
    } else {
        std::cout << "Group symbol: " << symbol_ << '\n';
    }
}
