#include "popmframe.h"

PopmFrame::PopmFrame(const std::string& id, uint32_t size, char status_flags, char format_flags) :
        PcntFrame(id, size, status_flags, format_flags) {}

void PopmFrame::Print() {
    PcntFrame::Print();
    std::cout << "Email to user: " << email_to_user_ << '\n';
    std::cout << "Rating: " << rating_ << '\n';
}

void PopmFrame::setRating(uint8_t rating) {
    rating_ = rating;
}

void PopmFrame::setEmailToUser(const std::string &emailToUser) {
    email_to_user_ = emailToUser;
}
