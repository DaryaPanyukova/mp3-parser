#include "abstractframe.h"

void AbstractFrame::setSize(uint32_t size) {
    size_ = size;
}

void AbstractFrame::setTagAltPreserve(bool tagAltPreserve) {
    tag_alt_preserve_ = tagAltPreserve;
}

void AbstractFrame::setFileAltPreserve(bool fileAltPreserve) {
    file_alt_preserve_ = fileAltPreserve;
}

void AbstractFrame::setReadOnly(bool readOnly) {
    read_only_ = readOnly;
}

void AbstractFrame::setGroupingIdentity(bool groupingIdentity) {
    grouping_identity_ = groupingIdentity;
}

void AbstractFrame::setCompression(bool compression) {
    compression_ = compression;
}

void AbstractFrame::setEncryption(bool encryption) {
    encryption_ = encryption;
}

void AbstractFrame::setUnsynch(bool unsynch) {
    unsynch_ = unsynch;
}

void AbstractFrame::setDataLenIndicator(bool dataLenIndicator) {
    data_len_indicator_ = dataLenIndicator;
}

std::string AbstractFrame::getId() const {
    return id_;
}

AbstractFrame::AbstractFrame(const std::string& id, uint32_t size, char status_flags, char format_flags) : id_(id), size_(size) {
    tag_alt_preserve_ = status_flags & (1 << 6);
    file_alt_preserve_ = status_flags & (1 << 5);
    read_only_ = status_flags & (1 << 4);

    grouping_identity_ = format_flags & (1 << 6);
    compression_ = format_flags & (1 << 3);
    encryption_ = format_flags & (1 << 2);
    unsynch_ = format_flags & (1 << 1);
    data_len_indicator_ = format_flags & 1;
}

uint32_t AbstractFrame::getSize() const {
    return size_;
}

void AbstractFrame::Print() {
    std::cout << "------- " << id_ << " -------" << '\n';
}
