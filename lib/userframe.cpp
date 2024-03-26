#include "userframe.h"

UserFrame::UserFrame(const std::string &id, uint32_t size, char status_flags, char format_flags) :
        AbstractFrame(id, size, status_flags, format_flags) {}

void UserFrame::setEncoding(uint8_t encoding) {
    encoding_ = encoding;
}

void UserFrame::setText(const char* text, uint32_t size) {
    text_ = std::string(text, size);
    delete[] text;
}

void UserFrame::setLang(const std::string &lang) {
    lang_ = lang;
}

void UserFrame::Print() {
    AbstractFrame::Print();
    std::cout << "Language: " << lang_ << '\n';
    std::cout << "Text: " << text_ << "\n";
}