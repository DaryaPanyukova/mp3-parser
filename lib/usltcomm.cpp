#include "usltcomm.h"

UsltComm::UsltComm(const std::string& id, uint32_t size, char status_flags,
                   char format_flags) :
        AbstractFrame(id, size, status_flags, format_flags) {}

void UsltComm::Print() {
    AbstractFrame::Print();
    std::cout << "Language: " << lang_ << '\n';
    std::cout << "Content descriptor: " << content_descriptor_ << '\n';
    std::cout << "Text: " << text_ << "\n";
}

void UsltComm::setEncoding(uint8_t encoding) {
    encoding_ = encoding;
}

void UsltComm::setLang(const char* lang) {
    lang_ = std::string(lang, 3);
}

void UsltComm::setContentDescriptor(const std::string& contentDescriptor) {
    content_descriptor_ = contentDescriptor;
}

void UsltComm::setText(const char* text, uint32_t size) {
    text_ = std::string(text, size);
    delete[] text;
}
