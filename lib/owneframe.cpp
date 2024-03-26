#include "owneframe.h"

OwneFrame::OwneFrame(const std::string& id, uint32_t size, char status_flags, char format_flags) :
        AbstractFrame(id, size, status_flags, format_flags) {}

void OwneFrame::Print() {
    AbstractFrame::Print();
    std::cout << "Price paid: " << price_paid_ << '\n';
    std::cout << "Date of purchase: " << purch_date_[0] << purch_date_[1] << purch_date_[2] << purch_date_[3] << '.';
    std::cout << purch_date_[4] << purch_date_[5] << '.' << purch_date_[6] << purch_date_[7] << '\n';
    std::cout << "Seller: " << seller_;
    std::cout << "\n";
}

void OwneFrame::setEncoding(uint8_t encoding) {
    encoding_ = encoding;
}

void OwneFrame::setPricePaid(const std::string &pricePaid) {
    price_paid_ = pricePaid;
}

void OwneFrame::setPurchDate(char *purchDate) {
    purch_date_ = purchDate;
}

void OwneFrame::setSeller(const char* seller, uint32_t size) {
    seller_ = std::string(seller, size);
    delete[] seller;
}

OwneFrame::~OwneFrame() {
    delete[] purch_date_;
}
