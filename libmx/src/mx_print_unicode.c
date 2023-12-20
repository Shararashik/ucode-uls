#include "../inc/libmx.h"

void mx_print_unicode(wchar_t c) {
    if (c < 0x80) {
        char bytes[1];
        bytes[0] = 0x00 | (c >> 0 & 0x7F);
        write(1, bytes, 1);
    } 
    else if (c < 0x0800) {
        char bytes[2];
        bytes[0] = 0xC0 | ((c >> 6) & 0x1F);
        bytes[1] = 0x80 | (c & 0x3F);     
        write(1, bytes, 2);
    } else if (c < 0x010000) {
        char bytes[3];
        bytes[0] = 0xE0 | ((c >> 12) & 0x0F);
        bytes[1] = 0x80 | ((c >> 6) & 0x3F);
        bytes[2] = 0x80 | (c & 0x3F);      
        write(1, bytes, 3);
    } else if (c < 0x110000) {
        char bytes[4];
        bytes[0] = 0xF0 | ((c >> 18) & 0x07);
        bytes[1] = 0x80 | ((c >> 12) & 0x3F);
        bytes[2] = 0x80 | ((c >> 6) & 0x3F);
        bytes[3] = 0x80 | (c & 0x3F);
        write(1, bytes, 4);
    }
}

