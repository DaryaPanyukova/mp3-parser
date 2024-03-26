#ifndef LABWORK_7_DARYAPANYUKOVA_POPMFRAME_H
#define LABWORK_7_DARYAPANYUKOVA_POPMFRAME_H

#include "pcntframe.h"

class PopmFrame : public PcntFrame {
public:
    PopmFrame(const std::string& id, uint32_t size, char status_flags, char format_flags);

    ~PopmFrame() override = default;

    void Print() override;

    void setRating(uint8_t rating);

    void setEmailToUser(const std::string &emailToUser);

private:
    std::string email_to_user_;
    uint8_t rating_;
};


#endif //LABWORK_7_DARYAPANYUKOVA_POPMFRAME_H
