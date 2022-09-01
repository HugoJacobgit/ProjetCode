#include "Color.h"
#include <string>

Color::Color(){
    Reset = "\033[0m";
    ColorName = "No color";
    ColorCode = "";
}

Color::~Color(){
}

std::string Color::GetReset(){
    return Reset;
}

std::string Color::GetColorCode(){
    return ColorCode;
}

bool Color::SetColor(std::string ColorName){
    bool result = false;
    if(ColorName == "black" || ColorName == "Black" || ColorName == "BLACK"){
        Color::ColorName = "black";
        ColorCode = "\033[1;30m";
        result = true;
    }
    else if(ColorName == "red" || ColorName == "Red" || ColorName == "RED"){
        Color::ColorName = "red";
        ColorCode = "\033[1;31m";
        result = true;
    }
    else if(ColorName == "green" || ColorName == "Green" || ColorName == "GREEN"){
        Color::ColorName = "green";
        ColorCode = "\033[1;32m";
        result = true;
    }
    else if(ColorName == "yellow" || ColorName == "Yellow" || ColorName == "YELLOW"){
        Color::ColorName = "yellow";
        ColorCode = "\033[1;33m";
        result = true;
    }
    else if(ColorName == "blue" || ColorName == "Blue" || ColorName == "BLUE"){
        Color::ColorName = "blue";
        ColorCode = "\033[1;34m";
        result = true;
    }
    else if(ColorName == "magenta" || ColorName == "Magenta" || ColorName == "MAGENTA"){
        Color::ColorName = "magenta";
        ColorCode = "\033[1;35m";
        result = true;
    }
    else if(ColorName == "cyan" || ColorName == "Cyan" || ColorName == "CYAN"){
        Color::ColorName = "cyan";
        ColorCode = "\033[1;36m";
        result = true;
    }
    return result;
}