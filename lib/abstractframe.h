#ifndef LABWORK_7_DARYAPANYUKOVA_ABSTRACTFRAME_H
#define LABWORK_7_DARYAPANYUKOVA_ABSTRACTFRAME_H

#include <stdint.h>
#include <string>
#include <iostream>
#include <vector>

class AbstractFrame {
public:
    virtual void Print();

    AbstractFrame(const std::string& id, uint32_t size, char status_flags, char format_flags);

    virtual ~AbstractFrame() = default;

    std::string getId() const;

    void setSize(uint32_t size);

    void setTagAltPreserve(bool tagAltPreserve);

    void setFileAltPreserve(bool fileAltPreserve);

    void setReadOnly(bool readOnly);

    void setGroupingIdentity(bool groupingIdentity);

    void setCompression(bool compression);

    void setEncryption(bool encryption);

    void setUnsynch(bool unsynch);

    void setDataLenIndicator(bool dataLenIndicator);

    uint32_t getSize() const;

protected:
    std::string id_;
    uint32_t size_;
    bool compression_;
    bool encryption_;
    bool unsynch_;
    bool data_len_indicator_;

    bool tag_alt_preserve_;
    bool file_alt_preserve_;
    bool read_only_;
    bool grouping_identity_;
};


#endif //LABWORK_7_DARYAPANYUKOVA_ABSTRACTFRAME_H
