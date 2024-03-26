#ifndef LABWORK_7_DARYAPANYUKOVA_SYLTFRAME_H
#define LABWORK_7_DARYAPANYUKOVA_SYLTFRAME_H

#include "abstracttimestampframe.h"

class SyltFrame : public AbstractTimeStampFrame {
public:
    static std::vector<std::string> content_types;

    SyltFrame(const std::string& id, uint32_t size, char status_flags,
              char format_flags);

    ~SyltFrame() override = default;

    void Print() override;

    void setEncoding(uint8_t encoding);

    void setLang(const std::string& lang);

    void setContentType(uint8_t contentType);

    void AddSync(const std::string& syllable, uint32_t time_stamp);

    void setContentDescriptor(const std::string& contentDescriptor);

private:
    struct Sync {
        std::string syllable;
        uint32_t time_stamp;
    };
    uint8_t encoding_;
    std::string lang_;
    uint8_t content_type_;
    std::string content_descriptor_;

    std::vector <Sync> syncs_;
};


#endif //LABWORK_7_DARYAPANYUKOVA_SYLTFRAME_H
