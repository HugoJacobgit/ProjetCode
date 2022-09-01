#ifndef __COLOR__
#define __COLOR__

#include <string>

class Color

{

public:

    Color();
    ~Color();

    bool SetColor(std::string ColorName);
    std::string GetColorCode();
    std::string GetReset();

protected:

    std::string ColorCode;
    std::string ColorName;
    std::string Reset;

};

#endif