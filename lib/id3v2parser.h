#pragma once

#include <string>
#include <fstream>
#include <cstring>
#include "id3v2.h"
#include "textframe.h"
#include "urlframe.h"
#include "etcoframe.h"
#include "rbufframe.h"
#include "txxxwxxx.h"
#include "userframe.h"
#include "syltframe.h"
#include "seekframe.h"
#include "ufidpriv.h"
#include "encrgrid.h"
#include "owneframe.h"
#include "usltcomm.h"
#include "linkframe.h"
#include "comrframe.h"
#include "equ2frame.h"
#include "rvrbframe.h"
#include "pcntframe.h"
#include "popmframe.h"
#include "possframe.h"
#include "rva2frame.h"
#include <unordered_set>

class Id3v2Parser {
public:
    Id3v2Parser(const std::string &filename);

    ~Id3v2Parser();

    Id3v2 Parse();

private:
    std::unordered_set<std::string> not_used_frames = {"AENC", "APIC", "ASPI", "GEOB", "MCDI", "MLLT",
                                                       "RVRB", "SIGN", "SYTC", "TFLT", "TMED"};
    uint32_t cur_size_;
    std::string filename_;
    std::ifstream in;

    uint32_t ReadNullSeparatedString(std::string &dest, uint32_t max_size = 4'294'967'295);

    void ParseFileHeader(Id3v2 &tag);

    void ParseFrames(Id3v2 &tag);

    void ParseTextFrame(TextFrame *frame);

    void ParseLinkFrame(UrlFrame *frame);

    void ParseXxxFrame(TxxxWxxx *frame);

    void ParseEtcoFrame(EtcoFrame *frame);

    void ParseRbufFrame(RbufFrame *frame);

    void ParseUserFrame(UserFrame *frame);

    void ParseSyltFrame(SyltFrame *frame);

    void ParseSeekFrame(SeekFrame *frame);

    void ParseUfidPrivFrame(UfidPriv *frame);

    void ParseEncrGridFrame(EncrGrid *frame);

    void ParseOwneFrame(OwneFrame *frame);

    void ParseUsltCommFrame(UsltComm *frame);

    void ParseLinkFrame(LinkFrame *frame);

    void ParseComrFrame(ComrFrame *frame);

    void ParseEqu2Frame(Equ2Frame *frame);

    void ParseRvrbFrame(RvrbFrame *frame);

    void ParsePcntFrame(PcntFrame *frame);

    void ParsePopmFrame(PopmFrame *frame);

    void ParsePossFrame(PossFrame *frame);

    void ParseRva2Frame(Rva2Frame *frame);

    uint32_t CharToSyncsafe(char *buf);

    uint32_t ReadInt32();

    uint16_t ReadInt16();

};
