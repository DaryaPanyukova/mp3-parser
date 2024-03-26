#include "ufidpriv.h"

UfidPriv::UfidPriv(const std::string& id, uint32_t size, char status_flags,
                   char format_flags) :
        AbstractFrame(id, size, status_flags, format_flags) {}

void UfidPriv::Print() {
    AbstractFrame::Print();
    std::cout << "Owner identifier: " << owner_identifier_ << '\n';
    std::cout << "Data: " << data_ << "\n";
}

void UfidPriv::setOwnerIdentifier(const std::string& ownerIdentifier) {
    owner_identifier_ = ownerIdentifier;
}

void UfidPriv::setData(char* data) {
    data_ = data;
}

UfidPriv::~UfidPriv() {
    delete[] data_;
}
