#include "possframe.h"

PossFrame::PossFrame(const std::string& id, uint32_t size, char status_flags, char format_flags) :
        AbstractTimeStampFrame(id, size, status_flags, format_flags) {}

void PossFrame::setPosition(uint32_t position) {
    position_ = position;
}

void PossFrame::Print() {
    AbstractTimeStampFrame::Print();
    std::cout << "Position: " << position_ << "\n";
}
