#ifndef LABWORK_7_DARYAPANYUKOVA_UFIDPRIV_H
#define LABWORK_7_DARYAPANYUKOVA_UFIDPRIV_H

#include "abstractframe.h"

class UfidPriv : public AbstractFrame {
public:
    UfidPriv(const std::string &id, uint32_t size, char status_flags, char format_flags);

    ~UfidPriv() override;

    void Print() override;

    void setOwnerIdentifier(const std::string &ownerIdentifier);

    void setData(char *identifier);

private:
    std::string owner_identifier_;

    char *data_;
};


#endif //LABWORK_7_DARYAPANYUKOVA_UFIDPRIV_H
