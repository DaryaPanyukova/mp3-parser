#ifndef LABWORK_7_DARYAPANYUKOVA_USLTCOMM_H
#define LABWORK_7_DARYAPANYUKOVA_USLTCOMM_H

#include "abstractframe.h"

class UsltComm : public AbstractFrame {
public:
    UsltComm(const std::string& id, uint32_t size, char status_flags,
             char format_flags);

    ~UsltComm() override = default;

    void Print() override;

    void setEncoding(uint8_t encoding);

    void setLang(const char* lang);

    void setContentDescriptor(const std::string& contentDescriptor);

    void setText(const char* text, uint32_t size);

private:
    uint8_t encoding_;
    std::string lang_;
    std::string content_descriptor_;
    std::string text_;
};


#endif //LABWORK_7_DARYAPANYUKOVA_USLTCOMM_H
