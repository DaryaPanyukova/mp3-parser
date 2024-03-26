#ifndef LABWORK_7_DARYAPANYUKOVA_RVA2FRAME_H
#define LABWORK_7_DARYAPANYUKOVA_RVA2FRAME_H

#include "abstractframe.h"

class Rva2Frame : public AbstractFrame {
public:
    Rva2Frame(const std::string& id, uint32_t size, char status_flags,
              char format_flags);

    ~Rva2Frame() override = default;

    void Print() override;

    void setIdentification(const std::string& identification);

    void AddChannel(uint8_t type, uint16_t volume_adjustment,
                    const char* peak_volume, uint32_t peak_volume_size);

private:
    struct Channel {
        uint8_t type;
        uint16_t volume_adjustment;
        std::string peak_volume;
    };
    std::string identification_;

    std::vector<Channel> channels_;
};


#endif //LABWORK_7_DARYAPANYUKOVA_RVA2FRAME_H
