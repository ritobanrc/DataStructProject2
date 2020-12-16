/* 
 * File:   Color.h
 * Author: ritoban
 *
 * Created on October 25, 2020, 7:26 PM
 */

#include <map>
#include <string>
#include <cinttypes>

#ifndef COLOR_H
#define COLOR_H

/* This class represents a Color -- specicially a 4 bit color based on ANSI escape sequences. See https://stackoverflow.com/questions/4842424/list-of-ansi-color-escape-sequences for more info */
class Color {
public:
    Color() { };
    //Color(std::string);
    Color(uint8_t val) : inner(val) {};
    Color(const Color& orig) : inner(orig.inner) {};

    virtual ~Color() {};

    uint8_t AsFG() const { return inner + 30; }
    uint8_t AsBG() const { return inner + 40; }

private:
    uint8_t inner;
};


const static Color Black = Color(0);
const static Color Red = Color(1);
const static Color Green = Color(2);
const static Color Yellow = Color(3);
const static Color Blue = Color(4);
const static Color Magenta = Color(5);
const static Color Cyan = Color(6);
const static Color White = Color(7);



#endif /* COLOR_H */

