#ifndef LABWORK_7_DARYAPANYUKOVA_SEEKFRAME_H
#define LABWORK_7_DARYAPANYUKOVA_SEEKFRAME_H

#include "abstractframe.h"

class SeekFrame : public AbstractFrame {
public:
    SeekFrame(const std::string &id, uint32_t size, char status_flags, char format_flags);

    ~SeekFrame() override = default;

    void Print() override;

    void setOffset(uint32_t offset);

private:
    uint32_t offset_;
};


#endif //LABWORK_7_DARYAPANYUKOVA_SEEKFRAME_H
