#include "pcntframe.h"

PcntFrame::PcntFrame(const std::string& id, uint32_t size, char status_flags, char format_flags) :
        AbstractFrame(id, size, status_flags, format_flags), has_counter_(false) {}

void PcntFrame::setCounter(uint64_t counter) {
    counter_ = counter;
    has_counter_ = true;
}

void PcntFrame::Print() {
    AbstractFrame::Print();
    if (has_counter_) {
        std::cout << "Counter:  " << counter_ << "\n";
    }
}
