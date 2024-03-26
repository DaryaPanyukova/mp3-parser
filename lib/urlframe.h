#ifndef LABWORK_7_DARYAPANYUKOVA_URLFRAME_H
#define LABWORK_7_DARYAPANYUKOVA_URLFRAME_H

#include "abstractframe.h"

class UrlFrame : public AbstractFrame {
public:
    UrlFrame(const std::string &id, uint32_t size, char status_flags, char format_flags);

    ~UrlFrame() override = default;

    void Print() override;

    void setUrl(const char* url, uint32_t size);

private:
    std::string url_;
};


#endif //LABWORK_7_DARYAPANYUKOVA_URLFRAME_H
