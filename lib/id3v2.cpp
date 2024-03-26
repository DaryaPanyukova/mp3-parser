#include "id3v2.h"

/*
Id3v2::Id3v2(const std::string& filename) {
    filename_ = filename;
    extended_header_ = unsynch_ = experimental_indicator_ = footer_present_ = false;
}
*/

Id3v2::Id3v2() {
    extended_header_ = unsynch_ = experimental_indicator_ = footer_present_ = false;
}

void Id3v2::setUnsynch(bool unsynch) {
    unsynch_ = unsynch;
}

void Id3v2::setExtendedHeader(bool extendedHeader) {
    extended_header_ = extendedHeader;
}

void Id3v2::setExperimentalIndicator(bool experimentalIndicator) {
    experimental_indicator_ = experimentalIndicator;
}

void Id3v2::setFooterPresent(bool footerPresent) {
    footer_present_ = footerPresent;
}

bool Id3v2::isExtendedHeader() const {
    return extended_header_;
}

void Id3v2::setSize(uint32_t size) {
    size_ = size;
}

uint32_t Id3v2::getSize() const {
    return size_;
}

void Id3v2::AddFrame(AbstractFrame *frame) {
    std::string frame_id = frame->getId();
    frames_[frame_id].push_back(frame);
}

void Id3v2::setVersion(uint8_t version) {
    version_ = version;
}

void Id3v2::setRevision(uint8_t revision) {
    revision_ = revision;
}

void Id3v2::PrintAllFrames() {
    for (const auto& elem: frames_) {
        for (const auto& frame: elem.second) {
            frame->Print();
        }
    }
}

void Id3v2::PrintFrame(const std::string &frame_name) {
    if (frames_.count(frame_name) == 0) {
        std::cout << "There's no frame named '" << frame_name << "'\n";
    } else {
        for (const auto& frame: frames_[frame_name]) {
            frame->Print();
        }
    }
}

Id3v2::~Id3v2() {
    for (const auto& elem: frames_) {
        for (auto& frame: elem.second) {
            delete frame;
        }
    }
}
