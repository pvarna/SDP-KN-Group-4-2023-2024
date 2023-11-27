#pragma once

#include <string>

struct EGN
{
private:
    std::string egn;

public:
    EGN(const char* egn);

    const char* getEgn() const;
    void setEgn(const char* egn);
};