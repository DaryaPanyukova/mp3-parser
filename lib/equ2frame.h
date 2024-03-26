#ifndef LABWORK_7_DARYAPANYUKOVA_EQU2FRAME_H
#define LABWORK_7_DARYAPANYUKOVA_EQU2FRAME_H

#include "abstractframe.h"

class Equ2Frame : public AbstractFrame {
public:
    Equ2Frame(const std::string& id, uint32_t size, char status_flags,
              char format_flags);

    ~Equ2Frame() override = default;

    void Print() override;

    void setInterpolationMethod(uint8_t interpolationMethod);

    void setIdentification(const std::string& identification);

    void AddAdjustmentPoint(uint16_t frequency, uint16_t volume_adjustment);

private:
    struct AdjustmentPoint {
        uint16_t frequency;
        uint16_t volume_adjustment;
    };
    uint8_t interpolation_method_;
    std::string identification_;
    std::vector<AdjustmentPoint> adjustment_points;
};


#endif //LABWORK_7_DARYAPANYUKOVA_EQU2FRAME_H
