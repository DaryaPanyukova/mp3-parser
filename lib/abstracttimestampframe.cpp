#include "abstracttimestampframe.h"

void AbstractTimeStampFrame::setTimeStampFormat(char timeStampFormat) {
    time_stamp_format_ = timeStampFormat;
}

AbstractTimeStampFrame::AbstractTimeStampFrame(const std::string& id,
                                               uint32_t size,
                                               char status_flags,
                                               char format_flags) :
        AbstractFrame(id, size, status_flags, format_flags) {}

void AbstractTimeStampFrame::Print() {
    AbstractFrame::Print();
    std::cout << "Time stamp format: ";
    if (time_stamp_format_ == 1) {
        std::cout << "Absolute time, 32 bit sized, using MPEG frames as unit\n";
    } else {
        std::cout << "Absolute time, 32 bit sized, using milliseconds as unit\n";
    }
}
