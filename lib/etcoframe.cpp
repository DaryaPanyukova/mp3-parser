#include "etcoframe.h"


const std::vector<std::string> EtcoFrame::event_types{
        "padding", "end of initial silence", "intro start",
        "main part start", "outro start", "outro end",
        "verse start", "refrain start", "interlude start",
        "theme start", "variation start", "key change",
        "time change", "momentary unwanted noise (Snap, Crackle & Pop)",
        "sustained noise", "sustained noise end", "intro end",
        "main part end", "verse end", "refrain end",
        "theme end", "profanity", "profanity end"
};

EtcoFrame::EtcoFrame(const std::string& id, uint32_t size, char status_flags,
                     char format_flags) :
        AbstractTimeStampFrame(id, size, status_flags, format_flags) {}

void EtcoFrame::AddEvent(uint8_t event_type, uint32_t time_stamp) {
    events_.push_back(Event{event_type, time_stamp});
}

void EtcoFrame::Print() {
    AbstractTimeStampFrame::Print();

    std::cout << "Events: \n";

    for (const auto& elem: events_) {
        std::string type;
        if (elem.event_type == 253) {
            type = "audio end (start of silence)";
        } else if (elem.event_type == 254) {
            type = "audio file ends";
        } else if (elem.event_type >= 23) {
            type = "reserved";
        } else {
            type = event_types[elem.event_type];
        }
        std::cout << type << " - " << elem.time_stamp << '\n';
    }
}
