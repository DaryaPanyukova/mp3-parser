#ifndef LABWORK_7_DARYAPANYUKOVA_ETCOFRAME_H
#define LABWORK_7_DARYAPANYUKOVA_ETCOFRAME_H

#include "abstracttimestampframe.h"

class EtcoFrame : public AbstractTimeStampFrame {
public:
    static const std::vector<std::string> event_types;

    EtcoFrame(const std::string& id, uint32_t size, char status_flags, char format_flags);

    ~EtcoFrame() override = default;

    void Print() override;

    void AddEvent(uint8_t event_type, uint32_t time_stamp);

private:
    struct Event {
        uint8_t event_type;
        uint32_t time_stamp;
    };

    std::vector<Event> events_;
};

#endif //LABWORK_7_DARYAPANYUKOVA_ETCOFRAME_H
