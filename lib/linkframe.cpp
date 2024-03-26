#include "linkframe.h"

LinkFrame::LinkFrame(const std::string &id, uint32_t size, char status_flags, char format_flags) :
        AbstractFrame(id, size, status_flags, format_flags) {}

void LinkFrame::Print() {
    AbstractFrame::Print();
    std::cout << "Frame identifier: " << frame_identifier_ << '\n';
    std::cout << "URL: " << url_ << '\n';
    std::cout << "ID and additional data: " << additional_data_ << "\n";
}

void LinkFrame::setFrameIdentifier(char *frameIdentifier) {
    frame_identifier_ = frameIdentifier;
}

void LinkFrame::setUrl(const std::string &url) {
    url_ = url;
}

void LinkFrame::setAdditionalData(const char* additionalData, uint32_t size) {
    additional_data_ = std::string(additionalData, size);
    delete[] additionalData;
}

LinkFrame::~LinkFrame() {
    delete[] frame_identifier_;
}
