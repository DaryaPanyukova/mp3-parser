#include "txxxwxxx.h"

TxxxWxxx::TxxxWxxx(const std::string &id, uint32_t size, char status_flags, char format_flags) :
        AbstractFrame(id, size, status_flags, format_flags) {}

void TxxxWxxx::setEncoding(uint8_t encoding) {
    encoding_ = encoding;
}

void TxxxWxxx::setDescription(const std::string &description) {
    description_ = description;
}

void TxxxWxxx::setData(const char* data, uint32_t size) {
    data_ = std::string(data, size);
    delete[] data;
}

void TxxxWxxx::Print() {
    AbstractFrame::Print();
    std::cout << "Description: " << description_ << '\n';
    std::cout << "Data: " << data_ << "\n";
}
