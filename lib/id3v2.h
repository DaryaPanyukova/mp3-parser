#pragma once

#include <vector>
#include <stdint.h>
#include "abstractframe.h"
#include <string>
#include <unordered_map>

class Id3v2 {
public:
    Id3v2();

    ~Id3v2();

    void setUnsynch(bool unsynch);

    void setExtendedHeader(bool extendedHeader);

    void setExperimentalIndicator(bool experimentalIndicator);

    void setFooterPresent(bool footerPresent);

    uint32_t getSize() const;

    void setSize(uint32_t size);

    bool isExtendedHeader() const;

    void AddFrame(AbstractFrame *frame);

    void setVersion(uint8_t version);

    void setRevision(uint8_t revision);

    void PrintAllFrames();

    void PrintFrame(const std::string &frame_name);

private:

    uint8_t version_;
    uint8_t revision_;
    uint32_t size_;
    bool unsynch_;
    bool extended_header_;
    bool experimental_indicator_;
    bool footer_present_;

    std::unordered_map<std::string, std::vector<AbstractFrame *>> frames_;
};
