#include "textframe.h"

TextFrame::TextFrame(const std::string &id, uint32_t size, char status_flags, char format_flags) :
        AbstractFrame(id, size, status_flags, format_flags) {}

void TextFrame::setEncoding(uint8_t encoding) {
    TextFrame::encoding_ = encoding;
}

void TextFrame::AddString(const std::string &str) {
    strings_.push_back(str);
}

void TextFrame::Print() {
    AbstractFrame::Print();
    std::cout << "Info: ";

    for (const auto &elem: strings_) {
        std::cout << elem << ' ';
    }
    std::cout << "\n";
}
