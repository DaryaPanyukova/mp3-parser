#ifndef LABWORK_7_DARYAPANYUKOVA_TXXXWXXX_H
#define LABWORK_7_DARYAPANYUKOVA_TXXXWXXX_H

#include "abstractframe.h"

class TxxxWxxx : public AbstractFrame {
public:
    TxxxWxxx(const std::string &id, uint32_t size, char status_flags, char format_flags);

    ~TxxxWxxx() override = default;

    void Print() override;

    void setEncoding(uint8_t encoding);

    void setDescription(const std::string &description);

    void setData(const char* data, uint32_t size);

private:
    uint8_t encoding_;
    std::string description_;
    std::string data_;
};


#endif //LABWORK_7_DARYAPANYUKOVA_TXXXWXXX_H
