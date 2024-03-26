#include "syltframe.h"

std::vector<std::string> SyltFrame::content_types{"other", "lyrics",
                                                  "text transcription",
                                                  "movement/part name (e.g. Adagio)",
                                                  "events (e.g. Don Quijote enters the stage)",
                                                  "chord (e.g. Bb F Fsus)",
                                                  "trivia/'pop up' information",
                                                  "URLs to webpages",
                                                  "URLs to images"};


SyltFrame::SyltFrame(const std::string& id, uint32_t size, char status_flags,
                     char format_flags) :
        AbstractTimeStampFrame(id, size, status_flags, format_flags) {}

void SyltFrame::setEncoding(uint8_t encoding) {
    encoding_ = encoding;
}

void SyltFrame::setLang(const std::string& lang) {
    lang_ = lang;
}

void SyltFrame::setContentType(uint8_t contentType) {
    content_type_ = contentType;
}

void SyltFrame::setContentDescriptor(const std::string& contentDescriptor) {
    content_descriptor_ = contentDescriptor;
}

void SyltFrame::Print() {
    AbstractTimeStampFrame::Print();
    std::cout << "Language: " << lang_ << '\n';
    std::cout << "Content type: " << content_types[content_type_] << '\n';
    std::cout << "Content descriptor: " << content_descriptor_ << "\n";

    std::cout << "Syncs:\n";
    for (const auto& sync: syncs_) {
        std::cout << "text - " << sync.syllable << ", ";
        std::cout << "time stamp - " << sync.time_stamp << "\n";
    }
}

void SyltFrame::AddSync(const std::string& syllable, uint32_t time_stamp) {
    syncs_.push_back(Sync{syllable, time_stamp});
}
