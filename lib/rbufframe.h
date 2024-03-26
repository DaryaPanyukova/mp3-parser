#ifndef LABWORK_7_DARYAPANYUKOVA_RBUFFRAME_H
#define LABWORK_7_DARYAPANYUKOVA_RBUFFRAME_H

#include "abstractframe.h"

class RbufFrame : public AbstractFrame {
public:
    RbufFrame(const std::string &id, uint32_t size, char status_flags, char format_flags);

    ~RbufFrame() override = default;

    void Print() override;

    void setBufferSize(uint32_t bufferSize);

    void setEmbeddedInfo(bool embeddedInfo);

    void setTagOffset(uint32_t tagOffset);

private:
    uint32_t buffer_size_;
    bool embedded_info_;
    uint32_t tag_offset_;
};


#endif //LABWORK_7_DARYAPANYUKOVA_RBUFFRAME_H
