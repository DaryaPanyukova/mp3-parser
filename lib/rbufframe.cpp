#include "rbufframe.h"


RbufFrame::RbufFrame(const std::string& id, uint32_t size, char status_flags, char format_flags) :
        AbstractFrame(id, size, status_flags, format_flags) {}


void RbufFrame::setBufferSize(uint32_t bufferSize) {
    buffer_size_ = bufferSize;
}

void RbufFrame::setEmbeddedInfo(bool embeddedInfo) {
    embedded_info_ = embeddedInfo;
}

void RbufFrame::setTagOffset(uint32_t tagOffset) {
    tag_offset_ = tagOffset;
}

void RbufFrame::Print() {
    AbstractFrame::Print();
    std::cout << "Buffer size: " << buffer_size_ << '\n';
    std::cout << "Embedded info flag: " << embedded_info_ << '\n';
    std::cout << "Offset to next tag: " << tag_offset_ << "\n";
}
