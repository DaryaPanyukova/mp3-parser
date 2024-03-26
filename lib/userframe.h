#ifndef LABWORK_7_DARYAPANYUKOVA_USERFRAME_H
#define LABWORK_7_DARYAPANYUKOVA_USERFRAME_H

#include "abstractframe.h"

class UserFrame : public AbstractFrame {
public:
    UserFrame(const std::string &id, uint32_t size, char status_flags, char format_flags);

    void Print() override;

    void setEncoding(uint8_t encoding);

    void setText(const char* text, uint32_t size);

    void setLang(const std::string &lang);

private:
    uint8_t encoding_;
    std::string lang_;
    std::string text_;
};


#endif //LABWORK_7_DARYAPANYUKOVA_USERFRAME_H
