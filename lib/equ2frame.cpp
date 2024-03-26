#include "equ2frame.h"

Equ2Frame::Equ2Frame(const std::string& id, uint32_t size, char status_flags,
                     char format_flags) :
        AbstractFrame(id, size, status_flags, format_flags) {}

void Equ2Frame::Print() {
    AbstractFrame::Print();
    std::cout << "Interpolation method: ";
    if (interpolation_method_ == 0) {
        std::cout << "band" << '\n';
    } else {
        std::cout << "Linear" << '\n';
    }
    std::cout << "Identification: " << identification_ << '\n';

    std::cout << "Adjustment points:\n";
    for (const auto& elem: adjustment_points) {
        std::cout << "frequency - " << elem.frequency << ", ";
        std::cout << "volume adjustment - " << elem.volume_adjustment << '\n';
    }
}


void Equ2Frame::setInterpolationMethod(uint8_t interpolationMethod) {
    interpolation_method_ = interpolationMethod;
}

void Equ2Frame::setIdentification(const std::string& identification) {
    identification_ = identification;
}

void
Equ2Frame::AddAdjustmentPoint(uint16_t frequency, uint16_t volume_adjustment) {
    adjustment_points.push_back(AdjustmentPoint{frequency, volume_adjustment});
}

