#ifndef LABWORK_7_DARYAPANYUKOVA_POSSFRAME_H
#define LABWORK_7_DARYAPANYUKOVA_POSSFRAME_H

#include "abstracttimestampframe.h"

class PossFrame : public AbstractTimeStampFrame {
public:
    PossFrame(const std::string& id, uint32_t size, char status_flags, char format_flags);

    ~PossFrame() override = default;

    void Print() override;

    void setPosition(uint32_t position);

private:
    uint32_t position_;
};


#endif //LABWORK_7_DARYAPANYUKOVA_POSSFRAME_H
