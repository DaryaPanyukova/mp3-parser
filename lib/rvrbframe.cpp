#include "rvrbframe.h"

RvrbFrame::RvrbFrame(const std::string &id, uint32_t size, char status_flags, char format_flags) :
        AbstractFrame(id, size, status_flags, format_flags) {}

void RvrbFrame::Print() {
    AbstractFrame::Print();

    std::cout << "Reverb left: " << reverb_left_ << '\n';
    std::cout << "Reverb right: " << reverb_right_ << '\n';

    std::cout << "Reverb bounces, left: " << bounces_left_ << '\n';
    std::cout << "Reverb bounces, right: " << bounces_right_ << '\n';

    std::cout << "Reverb feedback, left to left: " << feedback_left_left_ << '\n';
    std::cout << "Reverb feedback, left to right: " << feedback_left_right_ << '\n';
    std::cout << "Reverb feedback, right to right: " << feedback_right_right_ << '\n';
    std::cout << "Reverb feedback, right to left: " << feedback_right_left_ << '\n';

    std::cout << "Premix left to right: " << premix_left_right_ << '\n';
    std::cout << "Premix right to left: " << premix_right_left_ << "\n";
}


void RvrbFrame::setReverbLeft(uint16_t reverbLeft) {
    reverb_left_ = reverbLeft;
}

void RvrbFrame::setReverbRight(uint16_t reverbRight) {
    reverb_right_ = reverbRight;
}

void RvrbFrame::setBouncesLeft(uint8_t bouncesLeft) {
    bounces_left_ = bouncesLeft;
}

void RvrbFrame::setBouncesRight(uint8_t bouncesRight) {
    bounces_right_ = bouncesRight;
}

void RvrbFrame::setFeedbackLeftLeft(uint8_t feedbackLeftLeft) {
    feedback_left_left_ = feedbackLeftLeft;
}

void RvrbFrame::setFeedbackLeftRight(uint8_t feedbackLeftRight) {
    feedback_left_right_ = feedbackLeftRight;
}

void RvrbFrame::setFeedbackRightRight(uint8_t feedbackRightRight) {
    feedback_right_right_ = feedbackRightRight;
}

void RvrbFrame::setFeedbackRightLeft(uint8_t feedbackRightLeft) {
    feedback_right_left_ = feedbackRightLeft;
}

void RvrbFrame::setPremixLeftRight(uint8_t premixLeftRight) {
    premix_left_right_ = premixLeftRight;
}

void RvrbFrame::setPremixRightLeft(uint8_t premixRightLeft) {
    premix_right_left_ = premixRightLeft;
}

