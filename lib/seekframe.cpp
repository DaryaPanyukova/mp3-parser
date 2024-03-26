#include "seekframe.h"

SeekFrame::SeekFrame(const std::string &id, uint32_t size, char status_flags, char format_flags) :
        AbstractFrame(id, size, status_flags, format_flags) {}

void SeekFrame::Print() {
    AbstractFrame::Print();
    std::cout << "Minimum offset to next tag: " << offset_ << "\n";
}

void SeekFrame::setOffset(uint32_t offset) {
    offset_ = offset;
}
