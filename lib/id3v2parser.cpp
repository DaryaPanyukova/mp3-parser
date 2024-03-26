#include "id3v2parser.h"

Id3v2Parser::Id3v2Parser(const std::string& filename) {
    filename_ = filename;
    cur_size_ = 0;
}

Id3v2 Id3v2Parser::Parse() {
    in.open(filename_, std::ios::binary);
    Id3v2 tag;
    ParseFileHeader(tag);
    ParseFrames(tag);
    return tag;
}

void Id3v2Parser::ParseFileHeader(Id3v2& tag) {
    char buf[4];
    in.read(buf, 3); // identifier
    buf[3] = '\0';
    if (std::strcmp(buf, "ID3") != 0) {
        throw std::runtime_error("Error: undefined file type");
    }

    in.read(buf, 2); // version
    tag.setVersion(buf[0]);
    tag.setRevision(buf[1]);

    in.read(buf, 1); // flags
    tag.setUnsynch(buf[0] & (1 << 7));
    tag.setExtendedHeader(buf[0] & (1 << 6));
    tag.setExperimentalIndicator(buf[0] & (1 << 5));
    tag.setFooterPresent(buf[0] & (1 << 4));

    in.read(buf, 4);
    tag.setSize(CharToSyncsafe(buf));
}

void Id3v2Parser::ParseFrames(Id3v2& tag) {
    uint32_t tag_size = tag.getSize();

    while (cur_size_ < tag_size) {
        // frame header
        char frame_id[5];
        in.read(frame_id, 4); // frame id
        cur_size_ += 4;
        frame_id[4] = '\0';

        if (frame_id[0] == '\0') { // padding
            return;
        }

        char buf_size[4];
        in.read(buf_size, 4); // size
        cur_size_ += 4;
        uint32_t frame_size = CharToSyncsafe(buf_size);

        char flags[2];
        in.read(flags, 2); // flags
        cur_size_ += 2;

        cur_size_ += frame_size;

        // frame data
        if (not_used_frames.count(std::string(frame_id, 4))) {
            in.seekg(frame_size, std::ios::cur);
            continue;
        }

        if (frame_id[0] == 'T' && std::strcmp(frame_id, "TXXX") != 0) {
            auto frame = new TextFrame(std::string(frame_id, 4), frame_size,
                                       flags[0], flags[1]);
            ParseTextFrame(frame);
            tag.AddFrame(frame);
        } else if (frame_id[0] == 'W' && std::strcmp(frame_id, "WXXX") != 0) {
            auto frame = new UrlFrame(std::string(frame_id, 4), frame_size,
                                      flags[0], flags[1]);
            ParseLinkFrame(frame);
            tag.AddFrame(frame);
        } else if (std::strcmp(frame_id, "TXXX") == 0 ||
                   std::strcmp(frame_id, "WXXX") == 0) {
            auto frame = new TxxxWxxx(std::string(frame_id, 4), frame_size,
                                      flags[0], flags[1]);
            ParseXxxFrame(frame);
            tag.AddFrame(frame);
        } else if (std::strcmp(frame_id, "ETCO") == 0) {
            auto frame = new EtcoFrame(std::string(frame_id, 4), frame_size,
                                       flags[0], flags[1]);
            ParseEtcoFrame(frame);
            tag.AddFrame(frame);
        } else if (std::strcmp(frame_id, "RBUF") == 0) {
            auto frame = new RbufFrame(std::string(frame_id, 4), frame_size,
                                       flags[0], flags[1]);
            ParseRbufFrame(frame);
            tag.AddFrame(frame);
        } else if (std::strcmp(frame_id, "USER") == 0) {
            auto frame = new UserFrame(std::string(frame_id, 4), frame_size,
                                       flags[0], flags[1]);
            ParseUserFrame(frame);
            tag.AddFrame(frame);
        } else if (std::strcmp(frame_id, "SYLT") == 0) {
            auto frame = new SyltFrame(std::string(frame_id, 4), frame_size,
                                       flags[0], flags[1]);
            ParseSyltFrame(frame);
            tag.AddFrame(frame);
        } else if (std::strcmp(frame_id, "SEEK") == 0) {
            auto frame = new SeekFrame(std::string(frame_id, 4), frame_size,
                                       flags[0], flags[1]);
            ParseSeekFrame(frame);
            tag.AddFrame(frame);
        } else if (std::strcmp(frame_id, "UFID") == 0 ||
                   std::strcmp(frame_id, "PRIV") == 0) {
            auto frame = new UfidPriv(std::string(frame_id, 4), frame_size,
                                      flags[0], flags[1]);
            ParseUfidPrivFrame(frame);
            tag.AddFrame(frame);
        } else if (std::strcmp(frame_id, "ENCR") == 0 ||
                   std::strcmp(frame_id, "GRID") == 0) {
            auto frame = new EncrGrid(std::string(frame_id, 4), frame_size,
                                      flags[0], flags[1]);
            ParseEncrGridFrame(frame);
            tag.AddFrame(frame);
        } else if (std::strcmp(frame_id, "OWNE") == 0) {
            auto frame = new OwneFrame(std::string(frame_id, 4), frame_size,
                                       flags[0], flags[1]);
            ParseOwneFrame(frame);
            tag.AddFrame(frame);
        } else if (std::strcmp(frame_id, "USLT") == 0 ||
                   std::strcmp(frame_id, "COMM") == 0) {
            auto frame = new UsltComm(std::string(frame_id, 4), frame_size,
                                      flags[0], flags[1]);
            ParseUsltCommFrame(frame);
            tag.AddFrame(frame);
        } else if (std::strcmp(frame_id, "LINK") == 0) {
            auto frame = new LinkFrame(std::string(frame_id, 4), frame_size,
                                       flags[0], flags[1]);
            ParseLinkFrame(frame);
            tag.AddFrame(frame);
        } else if (std::strcmp(frame_id, "COMR") == 0) {
            auto frame = new ComrFrame(std::string(frame_id, 4), frame_size,
                                       flags[0], flags[1]);
            ParseComrFrame(frame);
            tag.AddFrame(frame);
        } else if (std::strcmp(frame_id, "EQU2") == 0) {
            auto frame = new Equ2Frame(std::string(frame_id, 4), frame_size,
                                       flags[0], flags[1]);
            ParseEqu2Frame(frame);
            tag.AddFrame(frame);
        } else if (std::strcmp(frame_id, "RVRB") == 0) {
            auto frame = new RvrbFrame(std::string(frame_id, 4), frame_size,
                                       flags[0], flags[1]);
            ParseRvrbFrame(frame);
            tag.AddFrame(frame);
        } else if (std::strcmp(frame_id, "PCNT") == 0) {
            auto frame = new PcntFrame(std::string(frame_id, 4), frame_size,
                                       flags[0], flags[1]);
            ParsePcntFrame(frame);
            tag.AddFrame(frame);
        } else if (std::strcmp(frame_id, "POPM") == 0) {
            auto frame = new PopmFrame(std::string(frame_id, 4), frame_size,
                                       flags[0], flags[1]);
            ParsePopmFrame(frame);
            tag.AddFrame(frame);
        } else if (std::strcmp(frame_id, "POSS") == 0) {
            auto frame = new PossFrame(std::string(frame_id, 4), frame_size,
                                       flags[0], flags[1]);
            ParsePossFrame(frame);
            tag.AddFrame(frame);
        } else if (std::strcmp(frame_id, "RVA2") == 0) {
            auto frame = new Rva2Frame(std::string(frame_id, 4), frame_size,
                                       flags[0], flags[1]);
            ParseRva2Frame(frame);
            tag.AddFrame(frame);
        }
    }
}


uint32_t Id3v2Parser::CharToSyncsafe(char* buf) {
    uint32_t result = static_cast <uint32_t> (buf[3]) +
                      (static_cast <uint32_t> (buf[2]) << 7) +
                      (static_cast <uint32_t> (buf[1]) << 14) +
                      (static_cast <uint32_t> (buf[0]) << 21);
    return result;
}

uint32_t Id3v2Parser::ReadInt32() {
    char buf[4];
    in.read(buf, 4);

    uint32_t first = static_cast <uint8_t> (buf[3]);
    uint32_t second = static_cast <uint8_t> (buf[2]);
    uint32_t third = static_cast <uint8_t> (buf[1]);
    uint32_t fourth = static_cast <uint8_t> (buf[0]);

    uint32_t result = first + (second << 8) + (third << 16) + (fourth << 24);
    return result;
}

uint16_t Id3v2Parser::ReadInt16() {
    char buf[2];
    in.read(buf, 2);

    uint32_t first = static_cast <uint8_t> (buf[1]);
    uint32_t second = static_cast <uint8_t> (buf[0]);

    uint32_t result = first + (second << 8);
    return result;
}

void Id3v2Parser::ParseTextFrame(TextFrame* frame) {
    uint32_t frame_size = frame->getSize();
    uint32_t cur_frame_size = 0;

    char encoding;
    in.read(&encoding, 1);
    cur_frame_size++;
    frame->setEncoding(encoding);

    std::string cur;
    while (cur_frame_size < frame_size) {
        cur_frame_size += ReadNullSeparatedString(cur,
                                                  frame_size - cur_frame_size);
        frame->AddString(cur);
    }
}

void Id3v2Parser::ParseLinkFrame(UrlFrame* frame) {
    uint32_t frame_size = frame->getSize();
    char* buf = new char[frame_size];
    in.read(buf, frame_size); // url
    frame->setUrl(buf, frame_size);
}

void Id3v2Parser::ParseXxxFrame(TxxxWxxx* frame) {
    uint32_t frame_size = frame->getSize();
    uint32_t cur_frame_size = 0;

    char encoding;
    in.read(&encoding, 1);
    cur_frame_size++;
    frame->setEncoding(encoding);

    std::string description;
    cur_frame_size += ReadNullSeparatedString(description);
    frame->setDescription(description);

    uint32_t data_size = frame_size - cur_frame_size;
    char* data = new char[data_size];
    in.read(data, data_size);
    frame->setData(data, data_size);
}

void Id3v2Parser::ParseEtcoFrame(EtcoFrame* frame) {
    uint32_t frame_size = frame->getSize();
    uint32_t cur_frame_size = 0;

    char time_stamp_format;
    in.read(&time_stamp_format, 1);
    cur_frame_size++;
    frame->setTimeStampFormat(time_stamp_format);


    while (cur_frame_size < frame_size) {
        char event_type;
        in.read(&event_type, 1);
        cur_frame_size++;

        uint32_t time_stamp = ReadInt32();
        cur_frame_size += 4;

        frame->AddEvent(event_type, time_stamp);
    }
}

void Id3v2Parser::ParseRbufFrame(RbufFrame* frame) {
    uint32_t buffer_size;
    in.read(((char*) &buffer_size) + 1, 3);
    frame->setBufferSize(buffer_size);

    char buf;
    in.read(&buf, 1);
    frame->setEmbeddedInfo(buf & 1);

    uint32_t tag_offset = ReadInt32();
    frame->setTagOffset(tag_offset);
}

void Id3v2Parser::ParseUserFrame(UserFrame* frame) {
    char buf[3];
    in.read(buf, 1);
    frame->setEncoding(buf[0]);

    in.read(buf, 3);
    frame->setLang(std::string(buf, 3));

    uint32_t text_size = frame->getSize() - 4;
    char* text = new char[text_size];
    in.read(text, text_size);
    frame->setText(text, text_size);
}

void Id3v2Parser::ParseSyltFrame(SyltFrame* frame) {
    uint32_t frame_size = frame->getSize();
    uint32_t cur_frame_size = 0;

    char buf[3];
    in.read(buf, 1);
    frame->setEncoding(buf[0]);
    cur_frame_size++;

    in.read(buf, 3);
    frame->setLang(std::string(buf, 3));
    cur_frame_size += 3;

    in.read(buf, 1);
    frame->setTimeStampFormat(buf[0]);
    cur_frame_size++;

    in.read(buf, 1);
    frame->setContentType(buf[0]);
    cur_frame_size += 2;


    std::string text;
    cur_frame_size += ReadNullSeparatedString(text);
    frame->setContentDescriptor(text);

    while (cur_frame_size < frame_size) {
        char buf;
        in.read(&buf, 1);
        cur_frame_size++;

        std::string syllable;
        cur_frame_size += ReadNullSeparatedString(syllable);

        uint32_t time_stamp = ReadInt32();
        cur_frame_size += 4;

        frame->AddSync(syllable, time_stamp);
    }
}

void Id3v2Parser::ParseSeekFrame(SeekFrame* frame) {
    uint32_t offset = ReadInt32();
    frame->setOffset(offset);
}

void Id3v2Parser::ParseUfidPrivFrame(UfidPriv* frame) {
    uint32_t frame_size = frame->getSize();
    uint32_t cur_frame_size = 0;

    std::string owner_identifier;
    cur_frame_size += ReadNullSeparatedString(owner_identifier);
    frame->setOwnerIdentifier(owner_identifier);

    uint32_t data_size = frame_size - cur_frame_size;
    char* data = new char[data_size];
    in.read(data, data_size);
    frame->setData(data);
}

void Id3v2Parser::ParseEncrGridFrame(EncrGrid* frame) {
    uint32_t frame_size = frame->getSize();
    uint32_t cur_frame_size = 0;

    std::string identifier;
    cur_frame_size += ReadNullSeparatedString(identifier);
    frame->setOwnerIdentifier(identifier);

    char buf;
    in.read(&buf, 1);
    frame->setSymbol(buf);
    cur_frame_size++;

    uint32_t data_size = frame_size - cur_frame_size;
    char* data = new char[data_size];
    in.read(data, data_size);
    frame->setData(data);
}

uint32_t
Id3v2Parser::ReadNullSeparatedString(std::string& dest, uint32_t max_size) {
    size_t size = 0;
    uint32_t capacity = 1;
    char* buf = new char[1];
    char next_char = 'n';

    while (size < max_size && next_char != '\0') {
        if (size == capacity) {
            char* new_buf = new char[capacity * 2];
            std::memcpy(new_buf, buf, size);
            delete[] buf;
            buf = new_buf;
            capacity = capacity * 2;
        }
        in.read(&next_char, 1);
        if (next_char != '\0') {
            buf[size] = next_char;
        }
        size++;
    }

    dest = std::string(buf, size);
    delete[] buf;
    return size;
}

void Id3v2Parser::ParseOwneFrame(OwneFrame* frame) {
    uint32_t frame_size = frame->getSize();
    uint32_t cur_frame_size = 0;

    char encoding;
    in.read(&encoding, 1);
    cur_frame_size++;
    frame->setEncoding(encoding);

    std::string price;
    cur_frame_size += ReadNullSeparatedString(price);
    frame->setPricePaid(price);

    char date[8];
    in.read(date, 8);
    cur_frame_size += 8;
    frame->setPurchDate(date);

    uint32_t seller_size = frame_size - cur_frame_size;
    char* seller = new char[seller_size];
    in.read(seller, seller_size);
    frame->setSeller(seller, seller_size);
}

void Id3v2Parser::ParseUsltCommFrame(UsltComm* frame) {
    uint32_t frame_size = frame->getSize();
    uint32_t cur_frame_size = 0;

    char buf[3];
    in.read(buf, 1);
    cur_frame_size++;
    frame->setEncoding(buf[0]);

    in.read(buf, 3);
    cur_frame_size += 3;
    frame->setLang(buf);

    std::string descriptor;
    cur_frame_size += ReadNullSeparatedString(descriptor);
    frame->setContentDescriptor(descriptor);

    uint32_t text_size = frame_size - cur_frame_size;
    char* text = new char[text_size];
    in.read(text, text_size);
    frame->setText(text, text_size);
}

void Id3v2Parser::ParseLinkFrame(LinkFrame* frame) {
    uint32_t frame_size = frame->getSize();
    uint32_t cur_frame_size = 0;

    char frame_identifier[4];
    in.read(frame_identifier, 4);
    cur_frame_size += 4;
    frame->setFrameIdentifier(frame_identifier);

    std::string url;
    cur_frame_size += ReadNullSeparatedString(url);
    frame->setUrl(url);

    uint32_t data_size = frame_size - cur_frame_size;
    char* data = new char[data_size];
    in.read(data, data_size);
    frame->setAdditionalData(data, data_size);
}

void Id3v2Parser::ParseComrFrame(ComrFrame* frame) {
    uint32_t frame_size = frame->getSize();
    uint32_t cur_frame_size = 0;

    char encoding;
    in.read(&encoding, 1);
    cur_frame_size++;
    frame->setEncoding(encoding);

    std::string price_string;
    cur_frame_size += ReadNullSeparatedString(price_string);
    frame->setPriceString(price_string);

    char valid_until[8];
    in.read(valid_until, 8);
    cur_frame_size += 8;
    frame->setValidUntil(valid_until);

    std::string url;
    cur_frame_size += ReadNullSeparatedString(url);
    frame->setContactUrl(url);

    char received_as;
    in.read(&received_as, 1);
    cur_frame_size++;
    frame->setReceivedAs(received_as);

    std::string seller_name;
    cur_frame_size += ReadNullSeparatedString(seller_name);
    frame->setNameOfSeller(seller_name);

    std::string description;
    cur_frame_size += ReadNullSeparatedString(description);
    frame->setDescription(description);

    std::string picture_type;
    cur_frame_size += ReadNullSeparatedString(picture_type);
    frame->setPictureMimeType(picture_type);

    uint32_t seller_logo_size = frame_size - cur_frame_size;
    char* seller_logo = new char[seller_logo_size];
    in.read(seller_logo, seller_logo_size);
    frame->setSellerLogo(seller_logo);
}

void Id3v2Parser::ParseEqu2Frame(Equ2Frame* frame) {
    uint32_t frame_size = frame->getSize();
    uint32_t cur_frame_size = 0;

    char interpolation_method;
    in.read(&interpolation_method, 1);
    cur_frame_size++;
    frame->setInterpolationMethod(interpolation_method);

    std::string identification;
    cur_frame_size += ReadNullSeparatedString(identification);
    frame->setIdentification(identification);

    while (cur_frame_size < frame_size) {
        uint16_t frequency = ReadInt16();
        uint16_t volume_adjustment = ReadInt16();

        frame->AddAdjustmentPoint(frequency, volume_adjustment);
        cur_frame_size += 4;
    }
}

void Id3v2Parser::ParseRvrbFrame(RvrbFrame* frame) {
    char buf[2];

    uint16_t reverb_left = ReadInt16();
    frame->setReverbLeft(reverb_left);

    uint16_t reverb_right = ReadInt16();
    frame->setReverbRight(reverb_right);

    in.read(buf, 1);
    frame->setBouncesLeft(buf[0]);
    in.read(buf, 1);
    frame->setBouncesRight(buf[0]);

    in.read(buf, 1);
    frame->setFeedbackLeftLeft(buf[0]);
    in.read(buf, 1);
    frame->setFeedbackLeftRight(buf[0]);
    in.read(buf, 1);
    frame->setFeedbackRightRight(buf[0]);
    in.read(buf, 1);
    frame->setFeedbackRightLeft(buf[0]);

    in.read(buf, 1);
    frame->setPremixLeftRight(buf[0]);
    in.read(buf, 1);
    frame->setPremixRightLeft(buf[0]);
}

void Id3v2Parser::ParsePcntFrame(PcntFrame* frame) {
    uint32_t frame_size = frame->getSize();
    char buf;
    uint64_t counter = 0;
    for (size_t i = 0; i < frame_size; ++i) {
        in.read(&buf, 1);
        counter = counter << 8;
        counter += static_cast <uint8_t> (buf);
    }
    frame->setCounter(counter);
}

void Id3v2Parser::ParsePopmFrame(PopmFrame* frame) {
    uint32_t frame_size = frame->getSize();
    uint32_t cur_frame_size = 0;

    std::string email;
    cur_frame_size += ReadNullSeparatedString(email);
    frame->setEmailToUser(email);

    char rating;
    in.read(&rating, 1);
    cur_frame_size++;
    frame->setRating(rating);

    uint32_t counter_size = frame_size - cur_frame_size;
    char buf;
    uint64_t counter = 0;
    for (size_t i = 0; i < counter_size; ++i) {
        in.read(&buf, 1);
        counter = counter << 8;
        counter += static_cast <uint8_t> (buf);
    }
    frame->setCounter(counter);
}

void Id3v2Parser::ParsePossFrame(PossFrame* frame) {
    char time_stamp_format;
    in.read(&time_stamp_format, 1);
    frame->setTimeStampFormat(time_stamp_format);

    uint16_t position = ReadInt16();
    frame->setPosition(position);
}

void Id3v2Parser::ParseRva2Frame(Rva2Frame* frame) {
    uint32_t frame_size = frame->getSize();
    uint32_t cur_frame_size = 0;

    std::string identification;
    cur_frame_size += ReadNullSeparatedString(identification);
    frame->setIdentification(identification);


    while (cur_frame_size < frame_size) {
        char type;
        in.read(&type, 1);
        cur_frame_size += 1;

        uint16_t volume = ReadInt16();
        cur_frame_size += 2;

        char bits;
        in.read(&bits, 1);
        cur_frame_size++;

        char* peak_volume = new char[bits];
        in.read(peak_volume, bits);
        cur_frame_size += bits;
        frame->AddChannel(type, volume, peak_volume, bits);
    }
}

Id3v2Parser::~Id3v2Parser() {
    in.close();
}

