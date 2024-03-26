#ifndef LABWORK_7_DARYAPANYUKOVA_COMRFRAME_H
#define LABWORK_7_DARYAPANYUKOVA_COMRFRAME_H

#include "abstractframe.h"

class ComrFrame : public AbstractFrame {
public:
    ComrFrame(const std::string& id, uint32_t size, char status_flags,
              char format_flags);

    ~ComrFrame() override;

    void Print() override;

    void setEncoding(uint8_t encoding);

    void setPriceString(const std::string& priceString);

    void setValidUntil(char* validUntil);

    void setContactUrl(const std::string& contactUrl);

    void setReceivedAs(char receivedAs);

    void setNameOfSeller(const std::string& nameOfSeller);

    void setDescription(const std::string& description);

    void setPictureMimeType(const std::string& pictureMimeType);

    void setSellerLogo(char* sellerLogo);

private:
    uint8_t encoding_;
    std::string price_string_;
    char* valid_until_;
    std::string contact_url_;
    char received_as_;
    std::string name_of_seller_;
    std::string description_;
    std::string picture_mime_type_;
    char* seller_logo_;
};

#endif //LABWORK_7_DARYAPANYUKOVA_COMRFRAME_H
