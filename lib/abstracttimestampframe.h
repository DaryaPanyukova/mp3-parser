#ifndef LABWORK_7_DARYAPANYUKOVA_ABSTRACTTIMESTAMPFRAME_H
#define LABWORK_7_DARYAPANYUKOVA_ABSTRACTTIMESTAMPFRAME_H

#include "abstractframe.h"

class AbstractTimeStampFrame : public AbstractFrame {
public:
    AbstractTimeStampFrame(const std::string &id, uint32_t size, char status_flags, char format_flags);

    ~AbstractTimeStampFrame() override = default;

    void Print() override;

    void setTimeStampFormat(char timeStampFormat);

private:
    char time_stamp_format_;
};


#endif //LABWORK_7_DARYAPANYUKOVA_ABSTRACTTIMESTAMPFRAME_H
