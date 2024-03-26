#ifndef LABWORK_7_DARYAPANYUKOVA_OWNEFRAME_H
#define LABWORK_7_DARYAPANYUKOVA_OWNEFRAME_H

#include "abstractframe.h"

class OwneFrame : public AbstractFrame {
public:
    OwneFrame(const std::string& id, uint32_t size, char status_flags, char format_flags);

    ~OwneFrame() override;

    void Print() override;

    void setEncoding(uint8_t encoding);

    void setPricePaid(const std::string &pricePaid);

    void setPurchDate(char *purchDate);

    void setSeller(const char* seller, uint32_t size);

private:
    uint8_t encoding_;
    std::string price_paid_;
    char *purch_date_;
    std::string seller_;
};


#endif //LABWORK_7_DARYAPANYUKOVA_OWNEFRAME_H
