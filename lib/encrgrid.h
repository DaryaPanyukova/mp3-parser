#ifndef LABWORK_7_DARYAPANYUKOVA_ENCRGRID_H
#define LABWORK_7_DARYAPANYUKOVA_ENCRGRID_H

#include "ufidpriv.h"

class EncrGrid : public UfidPriv {
public:
    EncrGrid(const std::string &id, uint32_t size, char status_flags, char format_flags);

    ~EncrGrid() override = default;

    void Print() override;

    void setSymbol(char symbol);

private:
    char symbol_;
};


#endif //LABWORK_7_DARYAPANYUKOVA_ENCRGRID_H
