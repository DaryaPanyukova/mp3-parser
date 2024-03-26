#ifndef LABWORK_7_DARYAPANYUKOVA_TEXTFRAME_H
#define LABWORK_7_DARYAPANYUKOVA_TEXTFRAME_H

#include "abstractframe.h"

class TextFrame : public AbstractFrame {
public:
    TextFrame(const std::string& id, uint32_t size, char status_flags,
              char format_flags);

    ~TextFrame() override = default;

    void Print() override;

    void setEncoding(uint8_t encoding);

    void AddString(const std::string& str);

private:
    uint8_t encoding_;
    std::vector<std::string> strings_;
};


#endif //LABWORK_7_DARYAPANYUKOVA_TEXTFRAME_H
