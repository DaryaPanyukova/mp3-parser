#include "rva2frame.h"

Rva2Frame::Rva2Frame(const std::string& id, uint32_t size, char status_flags,
                     char format_flags) :
        AbstractFrame(id, size, status_flags, format_flags) {}

void Rva2Frame::Print() {
    AbstractFrame::Print();
    std::cout << "Channels:\n";
    for (const auto& elem: channels_) {
        std::cout << "type - " << elem.type << ", ";
        std::cout << "volume adjustment - " << elem.volume_adjustment << ", ";
        std::cout << "peak volume - " << elem.peak_volume << '\n';
    }
}

void Rva2Frame::setIdentification(const std::string& identification) {
    identification_ = identification;
}

void Rva2Frame::AddChannel(uint8_t type, uint16_t volume_adjustment,
                           const char* peak_volume, uint32_t peak_volume_size) {
    channels_.push_back(Channel{type, volume_adjustment,
                                std::string(peak_volume, peak_volume_size)});
    delete[] peak_volume;
}
