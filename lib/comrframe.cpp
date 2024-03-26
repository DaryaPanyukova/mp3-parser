#include "comrframe.h"

ComrFrame::ComrFrame(const std::string& id, uint32_t size, char status_flags,
                     char format_flags) :
        AbstractFrame(id, size, status_flags, format_flags) {}

void ComrFrame::Print() {
    AbstractFrame::Print();
    std::cout << "Price string: " << price_string_ << '\n';
    std::cout << "Valid until: " << valid_until_[0] << valid_until_[1]
              << valid_until_[2] << valid_until_[3] << '.';
    std::cout << valid_until_[4] << valid_until_[5] << '.' << valid_until_[6]
              << valid_until_[7] << '\n';
    std::cout << "Contact URL: " << contact_url_ << '\n';
    std::cout << "Received as: " << received_as_ << '\n';
    std::cout << "Name of seller: " << name_of_seller_ << '\n';
    std::cout << "Description: " << description_ << '\n';
    std::cout << "Picture MIME type: " << picture_mime_type_ << '\n';
    std::cout << "Seller logo: " << seller_logo_ << "\n";
}

void ComrFrame::setEncoding(uint8_t encoding) {
    encoding_ = encoding;
}

void ComrFrame::setPriceString(const std::string& priceString) {
    price_string_ = priceString;
}

void ComrFrame::setValidUntil(char* validUntil) {
    valid_until_ = validUntil;
}

void ComrFrame::setContactUrl(const std::string& contactUrl) {
    contact_url_ = contactUrl;
}

void ComrFrame::setReceivedAs(char receivedAs) {
    received_as_ = receivedAs;
}

void ComrFrame::setNameOfSeller(const std::string& nameOfSeller) {
    name_of_seller_ = nameOfSeller;
}

void ComrFrame::setDescription(const std::string& description) {
    description_ = description;
}

void ComrFrame::setPictureMimeType(const std::string& pictureMimeType) {
    picture_mime_type_ = pictureMimeType;
}

void ComrFrame::setSellerLogo(char* sellerLogo) {
    seller_logo_ = sellerLogo;
}

ComrFrame::~ComrFrame() {
    delete[] valid_until_;
    delete[] seller_logo_;
}
