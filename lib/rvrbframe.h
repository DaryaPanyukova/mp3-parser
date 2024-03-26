#ifndef LABWORK_7_DARYAPANYUKOVA_RVRBFRAME_H
#define LABWORK_7_DARYAPANYUKOVA_RVRBFRAME_H

#include "abstractframe.h"

class RvrbFrame : public AbstractFrame {
public:
    RvrbFrame(const std::string &id, uint32_t size, char status_flags, char format_flags);

    ~RvrbFrame() override = default;

    void Print() override;

    void setReverbLeft(uint16_t reverbLeft);

    void setReverbRight(uint16_t reverbRight);

    void setBouncesLeft(uint8_t bouncesLeft);

    void setBouncesRight(uint8_t bouncesRight);

    void setFeedbackLeftLeft(uint8_t feedbackLeftLeft);

    void setFeedbackLeftRight(uint8_t feedbackLeftRight);

    void setFeedbackRightRight(uint8_t feedbackRightRight);

    void setFeedbackRightLeft(uint8_t feedbackRightLeft);

    void setPremixLeftRight(uint8_t premixLeftRight);

    void setPremixRightLeft(uint8_t premixRightLeft);

private:
    uint16_t reverb_left_;
    uint16_t reverb_right_;

    uint8_t bounces_left_;
    uint8_t bounces_right_;

    uint8_t feedback_left_left_;
    uint8_t feedback_left_right_;
    uint8_t feedback_right_right_;
    uint8_t feedback_right_left_;

    uint8_t premix_left_right_;
    uint8_t premix_right_left_;
};


#endif //LABWORK_7_DARYAPANYUKOVA_RVRBFRAME_H
