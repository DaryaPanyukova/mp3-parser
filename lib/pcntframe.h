#ifndef LABWORK_7_DARYAPANYUKOVA_PCNTFRAME_H
#define LABWORK_7_DARYAPANYUKOVA_PCNTFRAME_H

#include "abstractframe.h"

class PcntFrame : public AbstractFrame {
public:
    PcntFrame(const std::string& id, uint32_t size, char status_flags, char format_flags);

    ~PcntFrame() override = default;

    void Print() override;

    void setCounter(uint64_t counter);

private:
    uint64_t counter_;
    bool has_counter_;
};


#endif //LABWORK_7_DARYAPANYUKOVA_PCNTFRAME_H
