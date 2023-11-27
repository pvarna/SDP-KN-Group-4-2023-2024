#include "egn.h"

EGN::EGN(const char* egn)
    : egn(egn) {}

const char* EGN::getEgn() const
{
    return this->egn.c_str();
}
void EGN::setEgn(const char* egn)
{
    this->egn = egn;
}