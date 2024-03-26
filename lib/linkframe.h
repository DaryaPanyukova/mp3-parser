#ifndef LABWORK_7_DARYAPANYUKOVA_LINKFRAME_H
#define LABWORK_7_DARYAPANYUKOVA_LINKFRAME_H

#include "abstractframe.h"

class LinkFrame : public AbstractFrame {
public:
    LinkFrame(const std::string &id, uint32_t size, char status_flags, char format_flags);

    ~LinkFrame() override;

    void Print() override;

    void setFrameIdentifier(char *frameIdentifier);

    void setUrl(const std::string &url);

    void setAdditionalData(const char* additionalData, uint32_t size);

private:
    char *frame_identifier_;
    std::string url_;
    std::string additional_data_;
};


#endif //LABWORK_7_DARYAPANYUKOVA_LINKFRAME_H
