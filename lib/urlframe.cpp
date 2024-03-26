#include "urlframe.h"

UrlFrame::UrlFrame(const std::string &id, uint32_t size, char status_flags, char format_flags) :
        AbstractFrame(id, size, status_flags, format_flags) {}

void UrlFrame::setUrl(const char* url, uint32_t size) {
    url_ = std::string(url, size);
    delete[] url;
}

void UrlFrame::Print() {
    AbstractFrame::Print();
    std::cout << "URL: " << url_ << "\n ";
}
