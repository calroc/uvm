
// Monogram 12x7 pixel font

#include <uvm/syscalls.h>
#include <uvm/utils.h>


// > # MONOGRAM FONT
// > 
// > Monogram is a free and Creative Commons Zero pixel font,
// > made by Vinícius Menézio (@vmenezio).
// > 
// > https://datagoblin.itch.io/monogram
// > 
// > # SPECIAL THANKS
// > 
// > thanks to Ateş Göral (@atesgoral) for creating the bitmap font converter:
// > https://codepen.io/atesgoral/details/RwGOvPZ
// > 
// > thanks to Éric Araujo (@merwok_) for the inital port of monogram to PICO-8:
// > https://itch.io/post/2625522

#define FONT_MONOGRAM_NUMBER_OF_CHARACTERS 390
#define FONT_MONOGRAM_HEIGHT 12
#define FONT_MONOGRAM_WIDTH 7

// This is 12 bytes of data per char, as in 12 rows, and each byte
// represents the pixels in that row.
u8 font_monogram_data[FONT_MONOGRAM_NUMBER_OF_CHARACTERS][FONT_MONOGRAM_HEIGHT] = {
    { 0x00, 0x00, 0x00, 0x0e, 0x11, 0x19, 0x15, 0x13, 0x11, 0x0e, 0x00, 0x00, }, // '0'
    { 0x00, 0x00, 0x00, 0x04, 0x06, 0x04, 0x04, 0x04, 0x04, 0x1f, 0x00, 0x00, }, // '1'
    { 0x00, 0x00, 0x00, 0x0e, 0x11, 0x10, 0x08, 0x04, 0x02, 0x1f, 0x00, 0x00, }, // '2'
    { 0x00, 0x00, 0x00, 0x0e, 0x11, 0x10, 0x0c, 0x10, 0x11, 0x0e, 0x00, 0x00, }, // '3'
    { 0x00, 0x00, 0x00, 0x12, 0x12, 0x11, 0x1f, 0x10, 0x10, 0x10, 0x00, 0x00, }, // '4'
    { 0x00, 0x00, 0x00, 0x1f, 0x01, 0x0f, 0x10, 0x10, 0x11, 0x0e, 0x00, 0x00, }, // '5'
    { 0x00, 0x00, 0x00, 0x0e, 0x01, 0x01, 0x0f, 0x11, 0x11, 0x0e, 0x00, 0x00, }, // '6'
    { 0x00, 0x00, 0x00, 0x1f, 0x10, 0x10, 0x08, 0x04, 0x04, 0x04, 0x00, 0x00, }, // '7'
    { 0x00, 0x00, 0x00, 0x0e, 0x11, 0x11, 0x0e, 0x11, 0x11, 0x0e, 0x00, 0x00, }, // '8'
    { 0x00, 0x00, 0x00, 0x0e, 0x11, 0x11, 0x1e, 0x10, 0x11, 0x0e, 0x00, 0x00, }, // '9'
    { 0x00, 0x00, 0x00, 0x04, 0x04, 0x04, 0x04, 0x04, 0x00, 0x04, 0x00, 0x00, }, // '!'
    { 0x00, 0x00, 0x00, 0x0a, 0x0a, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, // '"'
    { 0x00, 0x00, 0x00, 0x00, 0x0a, 0x1f, 0x0a, 0x0a, 0x1f, 0x0a, 0x00, 0x00, }, // '#'
    { 0x00, 0x00, 0x00, 0x04, 0x1e, 0x05, 0x0e, 0x14, 0x0f, 0x04, 0x00, 0x00, }, // '$'
    { 0x00, 0x00, 0x00, 0x11, 0x11, 0x08, 0x04, 0x02, 0x11, 0x11, 0x00, 0x00, }, // '%'
    { 0x00, 0x00, 0x00, 0x06, 0x09, 0x09, 0x1e, 0x09, 0x09, 0x16, 0x00, 0x00, }, // '&'
    { 0x00, 0x00, 0x00, 0x04, 0x04, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, // "'"
    { 0x00, 0x00, 0x00, 0x08, 0x04, 0x04, 0x04, 0x04, 0x04, 0x08, 0x00, 0x00, }, // '('
    { 0x00, 0x00, 0x00, 0x02, 0x04, 0x04, 0x04, 0x04, 0x04, 0x02, 0x00, 0x00, }, // ')'
    { 0x00, 0x00, 0x00, 0x00, 0x04, 0x15, 0x0e, 0x15, 0x04, 0x00, 0x00, 0x00, }, // '*'
    { 0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0x1f, 0x04, 0x04, 0x00, 0x00, 0x00, }, // '+'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0x02, 0x00, }, // ','
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, }, // '-'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0x00, 0x00, }, // '.'
    { 0x00, 0x00, 0x00, 0x10, 0x10, 0x08, 0x04, 0x02, 0x01, 0x01, 0x00, 0x00, }, // '/'
    { 0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0x00, 0x00, 0x04, 0x04, 0x00, 0x00, }, // ':'
    { 0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0x00, 0x00, 0x04, 0x04, 0x02, 0x00, }, // ';'
    { 0x00, 0x00, 0x00, 0x00, 0x18, 0x06, 0x01, 0x06, 0x18, 0x00, 0x00, 0x00, }, // '<'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x00, }, // '='
    { 0x00, 0x00, 0x00, 0x00, 0x03, 0x0c, 0x10, 0x0c, 0x03, 0x00, 0x00, 0x00, }, // '>'
    { 0x00, 0x00, 0x00, 0x0e, 0x11, 0x10, 0x08, 0x04, 0x00, 0x04, 0x00, 0x00, }, // '?'
    { 0x00, 0x00, 0x00, 0x0e, 0x19, 0x15, 0x15, 0x19, 0x01, 0x0e, 0x00, 0x00, }, // '@'
    { 0x00, 0x00, 0x00, 0x0e, 0x11, 0x11, 0x11, 0x1f, 0x11, 0x11, 0x00, 0x00, }, // 'A'
    { 0x00, 0x00, 0x00, 0x0f, 0x11, 0x11, 0x0f, 0x11, 0x11, 0x0f, 0x00, 0x00, }, // 'B'
    { 0x00, 0x00, 0x00, 0x0e, 0x11, 0x01, 0x01, 0x01, 0x11, 0x0e, 0x00, 0x00, }, // 'C'
    { 0x00, 0x00, 0x00, 0x0f, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0f, 0x00, 0x00, }, // 'D'
    { 0x00, 0x00, 0x00, 0x1f, 0x01, 0x01, 0x0f, 0x01, 0x01, 0x1f, 0x00, 0x00, }, // 'E'
    { 0x00, 0x00, 0x00, 0x1f, 0x01, 0x01, 0x0f, 0x01, 0x01, 0x01, 0x00, 0x00, }, // 'F'
    { 0x00, 0x00, 0x00, 0x0e, 0x11, 0x01, 0x1d, 0x11, 0x11, 0x0e, 0x00, 0x00, }, // 'G'
    { 0x00, 0x00, 0x00, 0x11, 0x11, 0x11, 0x1f, 0x11, 0x11, 0x11, 0x00, 0x00, }, // 'H'
    { 0x00, 0x00, 0x00, 0x1f, 0x04, 0x04, 0x04, 0x04, 0x04, 0x1f, 0x00, 0x00, }, // 'I'
    { 0x00, 0x00, 0x00, 0x10, 0x10, 0x10, 0x10, 0x11, 0x11, 0x0e, 0x00, 0x00, }, // 'J'
    { 0x00, 0x00, 0x00, 0x11, 0x09, 0x05, 0x03, 0x05, 0x09, 0x11, 0x00, 0x00, }, // 'K'
    { 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x1f, 0x00, 0x00, }, // 'L'
    { 0x00, 0x00, 0x00, 0x11, 0x1b, 0x15, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, }, // 'M'
    { 0x00, 0x00, 0x00, 0x11, 0x11, 0x13, 0x15, 0x19, 0x11, 0x11, 0x00, 0x00, }, // 'N'
    { 0x00, 0x00, 0x00, 0x0e, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0e, 0x00, 0x00, }, // 'O'
    { 0x00, 0x00, 0x00, 0x0f, 0x11, 0x11, 0x0f, 0x01, 0x01, 0x01, 0x00, 0x00, }, // 'P'
    { 0x00, 0x00, 0x00, 0x0e, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0e, 0x18, 0x00, }, // 'Q'
    { 0x00, 0x00, 0x00, 0x0f, 0x11, 0x11, 0x0f, 0x11, 0x11, 0x11, 0x00, 0x00, }, // 'R'
    { 0x00, 0x00, 0x00, 0x0e, 0x11, 0x01, 0x0e, 0x10, 0x11, 0x0e, 0x00, 0x00, }, // 'S'
    { 0x00, 0x00, 0x00, 0x1f, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x00, 0x00, }, // 'T'
    { 0x00, 0x00, 0x00, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0e, 0x00, 0x00, }, // 'U'
    { 0x00, 0x00, 0x00, 0x11, 0x11, 0x11, 0x11, 0x0a, 0x0a, 0x04, 0x00, 0x00, }, // 'V'
    { 0x00, 0x00, 0x00, 0x11, 0x11, 0x11, 0x11, 0x15, 0x1b, 0x11, 0x00, 0x00, }, // 'W'
    { 0x00, 0x00, 0x00, 0x11, 0x11, 0x0a, 0x04, 0x0a, 0x11, 0x11, 0x00, 0x00, }, // 'X'
    { 0x00, 0x00, 0x00, 0x11, 0x11, 0x0a, 0x04, 0x04, 0x04, 0x04, 0x00, 0x00, }, // 'Y'
    { 0x00, 0x00, 0x00, 0x1f, 0x10, 0x08, 0x04, 0x02, 0x01, 0x1f, 0x00, 0x00, }, // 'Z'
    { 0x00, 0x00, 0x00, 0x0c, 0x04, 0x04, 0x04, 0x04, 0x04, 0x0c, 0x00, 0x00, }, // '['
    { 0x00, 0x00, 0x00, 0x01, 0x01, 0x02, 0x04, 0x08, 0x10, 0x10, 0x00, 0x00, }, // '\\'
    { 0x00, 0x00, 0x00, 0x06, 0x04, 0x04, 0x04, 0x04, 0x04, 0x06, 0x00, 0x00, }, // ']'
    { 0x00, 0x00, 0x00, 0x04, 0x0a, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, // '^'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x00, }, // '_'
    { 0x00, 0x00, 0x00, 0x02, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, // '`'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x11, 0x11, 0x11, 0x1e, 0x00, 0x00, }, // 'a'
    { 0x00, 0x00, 0x00, 0x01, 0x01, 0x0f, 0x11, 0x11, 0x11, 0x0f, 0x00, 0x00, }, // 'b'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x11, 0x01, 0x11, 0x0e, 0x00, 0x00, }, // 'c'
    { 0x00, 0x00, 0x00, 0x10, 0x10, 0x1e, 0x11, 0x11, 0x11, 0x1e, 0x00, 0x00, }, // 'd'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x11, 0x1f, 0x01, 0x0e, 0x00, 0x00, }, // 'e'
    { 0x00, 0x00, 0x00, 0x0c, 0x12, 0x02, 0x0f, 0x02, 0x02, 0x02, 0x00, 0x00, }, // 'f'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x11, 0x11, 0x11, 0x1e, 0x10, 0x0e, }, // 'g'
    { 0x00, 0x00, 0x00, 0x01, 0x01, 0x0f, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, }, // 'h'
    { 0x00, 0x00, 0x00, 0x04, 0x00, 0x06, 0x04, 0x04, 0x04, 0x1f, 0x00, 0x00, }, // 'i'
    { 0x00, 0x00, 0x00, 0x10, 0x00, 0x18, 0x10, 0x10, 0x10, 0x10, 0x11, 0x0e, }, // 'j'
    { 0x00, 0x00, 0x00, 0x01, 0x01, 0x11, 0x09, 0x07, 0x09, 0x11, 0x00, 0x00, }, // 'k'
    { 0x00, 0x00, 0x00, 0x03, 0x02, 0x02, 0x02, 0x02, 0x02, 0x1c, 0x00, 0x00, }, // 'l'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x15, 0x15, 0x15, 0x15, 0x00, 0x00, }, // 'm'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, }, // 'n'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x11, 0x11, 0x11, 0x0e, 0x00, 0x00, }, // 'o'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x11, 0x11, 0x11, 0x0f, 0x01, 0x01, }, // 'p'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x11, 0x11, 0x11, 0x1e, 0x10, 0x10, }, // 'q'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x0d, 0x13, 0x01, 0x01, 0x01, 0x00, 0x00, }, // 'r'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x01, 0x0e, 0x10, 0x0f, 0x00, 0x00, }, // 's'
    { 0x00, 0x00, 0x00, 0x02, 0x02, 0x0f, 0x02, 0x02, 0x02, 0x1c, 0x00, 0x00, }, // 't'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x11, 0x11, 0x1e, 0x00, 0x00, }, // 'u'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x11, 0x0a, 0x04, 0x00, 0x00, }, // 'v'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x15, 0x15, 0x0a, 0x00, 0x00, }, // 'w'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x0a, 0x04, 0x0a, 0x11, 0x00, 0x00, }, // 'x'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x11, 0x11, 0x1e, 0x10, 0x0e, }, // 'y'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x08, 0x04, 0x02, 0x1f, 0x00, 0x00, }, // 'z'
    { 0x00, 0x00, 0x00, 0x08, 0x04, 0x04, 0x02, 0x04, 0x04, 0x08, 0x00, 0x00, }, // '{'
    { 0x00, 0x00, 0x00, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x00, 0x00, }, // '|'
    { 0x00, 0x00, 0x00, 0x02, 0x04, 0x04, 0x08, 0x04, 0x04, 0x02, 0x00, 0x00, }, // '}'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x12, 0x0d, 0x00, 0x00, 0x00, 0x00, 0x00, }, // '~'
    { 0x00, 0x00, 0x00, 0x04, 0x00, 0x04, 0x04, 0x04, 0x04, 0x04, 0x00, 0x00, }, // '¡'
    { 0x00, 0x00, 0x00, 0x04, 0x0e, 0x15, 0x05, 0x15, 0x0e, 0x04, 0x00, 0x00, }, // '¢'
    { 0x00, 0x00, 0x00, 0x0c, 0x12, 0x02, 0x0f, 0x02, 0x02, 0x1f, 0x00, 0x00, }, // '£'
    { 0x00, 0x00, 0x00, 0x00, 0x11, 0x0e, 0x0a, 0x0e, 0x11, 0x00, 0x00, 0x00, }, // '¤'
    { 0x00, 0x00, 0x00, 0x11, 0x0a, 0x04, 0x1f, 0x04, 0x1f, 0x04, 0x00, 0x00, }, // '¥'
    { 0x00, 0x00, 0x00, 0x04, 0x04, 0x04, 0x00, 0x04, 0x04, 0x04, 0x00, 0x00, }, // '¦'
    { 0x00, 0x00, 0x00, 0x1e, 0x01, 0x0e, 0x11, 0x0e, 0x10, 0x0f, 0x00, 0x00, }, // '§'
    { 0x00, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, // '¨'
    { 0x00, 0x00, 0x00, 0x0e, 0x1b, 0x15, 0x1d, 0x15, 0x1b, 0x0e, 0x00, 0x00, }, // '©'
    { 0x00, 0x00, 0x00, 0x0e, 0x09, 0x09, 0x09, 0x0e, 0x00, 0x00, 0x00, 0x00, }, // 'ª'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x12, 0x09, 0x12, 0x00, 0x00, 0x00, 0x00, }, // '«'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x10, 0x00, 0x00, 0x00, 0x00, }, // '¬'
    { 0x00, 0x00, 0x00, 0x0e, 0x19, 0x15, 0x15, 0x19, 0x15, 0x0e, 0x00, 0x00, }, // '®'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, }, // '¯'
    { 0x00, 0x00, 0x00, 0x06, 0x09, 0x09, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, }, // '°'
    { 0x00, 0x00, 0x00, 0x04, 0x04, 0x1f, 0x04, 0x04, 0x00, 0x1f, 0x00, 0x00, }, // '±'
    { 0x00, 0x00, 0x00, 0x03, 0x04, 0x02, 0x01, 0x07, 0x00, 0x00, 0x00, 0x00, }, // '²'
    { 0x00, 0x00, 0x00, 0x03, 0x04, 0x02, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, }, // '³'
    { 0x00, 0x00, 0x08, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, // '´'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x11, 0x11, 0x0f, 0x01, 0x01, }, // 'µ'
    { 0x00, 0x00, 0x00, 0x1e, 0x17, 0x17, 0x17, 0x16, 0x14, 0x14, 0x00, 0x00, }, // '¶'
    { 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, // '·'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x08, 0x06, }, // '¸'
    { 0x00, 0x00, 0x00, 0x02, 0x03, 0x02, 0x02, 0x07, 0x00, 0x00, 0x00, 0x00, }, // '¹'
    { 0x00, 0x00, 0x00, 0x06, 0x09, 0x09, 0x09, 0x06, 0x00, 0x00, 0x00, 0x00, }, // 'º'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x12, 0x09, 0x00, 0x00, 0x00, 0x00, }, // '»'
    { 0x00, 0x00, 0x00, 0x01, 0x09, 0x05, 0x02, 0x15, 0x1c, 0x10, 0x00, 0x00, }, // '¼'
    { 0x00, 0x00, 0x00, 0x01, 0x09, 0x05, 0x0e, 0x11, 0x08, 0x1c, 0x00, 0x00, }, // '½'
    { 0x00, 0x00, 0x00, 0x07, 0x16, 0x0f, 0x04, 0x16, 0x1d, 0x10, 0x00, 0x00, }, // '¾'
    { 0x00, 0x00, 0x00, 0x04, 0x00, 0x04, 0x02, 0x01, 0x11, 0x0e, 0x00, 0x00, }, // '¿'
    { 0x02, 0x04, 0x00, 0x0e, 0x11, 0x11, 0x1f, 0x11, 0x11, 0x11, 0x00, 0x00, }, // 'À'
    { 0x08, 0x04, 0x00, 0x0e, 0x11, 0x11, 0x1f, 0x11, 0x11, 0x11, 0x00, 0x00, }, // 'Á'
    { 0x04, 0x0a, 0x00, 0x0e, 0x11, 0x11, 0x1f, 0x11, 0x11, 0x11, 0x00, 0x00, }, // 'Â'
    { 0x16, 0x09, 0x00, 0x0e, 0x11, 0x11, 0x1f, 0x11, 0x11, 0x11, 0x00, 0x00, }, // 'Ã'
    { 0x00, 0x0a, 0x00, 0x0e, 0x11, 0x11, 0x1f, 0x11, 0x11, 0x11, 0x00, 0x00, }, // 'Ä'
    { 0x04, 0x0a, 0x04, 0x0e, 0x11, 0x11, 0x1f, 0x11, 0x11, 0x11, 0x00, 0x00, }, // 'Å'
    { 0x00, 0x00, 0x00, 0x1e, 0x05, 0x05, 0x1f, 0x05, 0x05, 0x1d, 0x00, 0x00, }, // 'Æ'
    { 0x00, 0x00, 0x00, 0x0e, 0x11, 0x01, 0x01, 0x01, 0x11, 0x0e, 0x08, 0x06, }, // 'Ç'
    { 0x02, 0x04, 0x00, 0x1f, 0x01, 0x01, 0x0f, 0x01, 0x01, 0x1f, 0x00, 0x00, }, // 'È'
    { 0x08, 0x04, 0x00, 0x1f, 0x01, 0x01, 0x0f, 0x01, 0x01, 0x1f, 0x00, 0x00, }, // 'É'
    { 0x04, 0x0a, 0x00, 0x1f, 0x01, 0x01, 0x0f, 0x01, 0x01, 0x1f, 0x00, 0x00, }, // 'Ê'
    { 0x00, 0x0a, 0x00, 0x1f, 0x01, 0x01, 0x0f, 0x01, 0x01, 0x1f, 0x00, 0x00, }, // 'Ë'
    { 0x02, 0x04, 0x00, 0x1f, 0x04, 0x04, 0x04, 0x04, 0x04, 0x1f, 0x00, 0x00, }, // 'Ì'
    { 0x08, 0x04, 0x00, 0x1f, 0x04, 0x04, 0x04, 0x04, 0x04, 0x1f, 0x00, 0x00, }, // 'Í'
    { 0x04, 0x0a, 0x00, 0x1f, 0x04, 0x04, 0x04, 0x04, 0x04, 0x1f, 0x00, 0x00, }, // 'Î'
    { 0x00, 0x0a, 0x00, 0x1f, 0x04, 0x04, 0x04, 0x04, 0x04, 0x1f, 0x00, 0x00, }, // 'Ï'
    { 0x00, 0x00, 0x00, 0x0f, 0x11, 0x11, 0x13, 0x11, 0x11, 0x0f, 0x00, 0x00, }, // 'Ð'
    { 0x16, 0x09, 0x00, 0x11, 0x11, 0x13, 0x15, 0x19, 0x11, 0x11, 0x00, 0x00, }, // 'Ñ'
    { 0x02, 0x04, 0x00, 0x0e, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0e, 0x00, 0x00, }, // 'Ò'
    { 0x08, 0x04, 0x00, 0x0e, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0e, 0x00, 0x00, }, // 'Ó'
    { 0x04, 0x0a, 0x00, 0x0e, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0e, 0x00, 0x00, }, // 'Ô'
    { 0x16, 0x09, 0x00, 0x0e, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0e, 0x00, 0x00, }, // 'Õ'
    { 0x00, 0x0a, 0x00, 0x0e, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0e, 0x00, 0x00, }, // 'Ö'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0x04, 0x0a, 0x00, 0x00, 0x00, }, // '×'
    { 0x00, 0x00, 0x00, 0x16, 0x09, 0x19, 0x15, 0x13, 0x12, 0x0d, 0x00, 0x00, }, // 'Ø'
    { 0x02, 0x04, 0x00, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0e, 0x00, 0x00, }, // 'Ù'
    { 0x08, 0x04, 0x00, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0e, 0x00, 0x00, }, // 'Ú'
    { 0x04, 0x0a, 0x00, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0e, 0x00, 0x00, }, // 'Û'
    { 0x00, 0x0a, 0x00, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0e, 0x00, 0x00, }, // 'Ü'
    { 0x08, 0x04, 0x00, 0x11, 0x11, 0x0a, 0x04, 0x04, 0x04, 0x04, 0x00, 0x00, }, // 'Ý'
    { 0x00, 0x00, 0x00, 0x01, 0x0f, 0x11, 0x11, 0x11, 0x0f, 0x01, 0x00, 0x00, }, // 'Þ'
    { 0x00, 0x00, 0x00, 0x06, 0x09, 0x09, 0x0d, 0x11, 0x11, 0x0d, 0x00, 0x00, }, // 'ß'
    { 0x00, 0x00, 0x02, 0x04, 0x00, 0x1e, 0x11, 0x11, 0x11, 0x1e, 0x00, 0x00, }, // 'à'
    { 0x00, 0x00, 0x08, 0x04, 0x00, 0x1e, 0x11, 0x11, 0x11, 0x1e, 0x00, 0x00, }, // 'á'
    { 0x00, 0x00, 0x04, 0x0a, 0x00, 0x1e, 0x11, 0x11, 0x11, 0x1e, 0x00, 0x00, }, // 'â'
    { 0x00, 0x00, 0x16, 0x09, 0x00, 0x1e, 0x11, 0x11, 0x11, 0x1e, 0x00, 0x00, }, // 'ã'
    { 0x00, 0x00, 0x00, 0x0a, 0x00, 0x1e, 0x11, 0x11, 0x11, 0x1e, 0x00, 0x00, }, // 'ä'
    { 0x00, 0x04, 0x0a, 0x04, 0x00, 0x1e, 0x11, 0x11, 0x11, 0x1e, 0x00, 0x00, }, // 'å'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x15, 0x1d, 0x05, 0x1e, 0x00, 0x00, }, // 'æ'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x11, 0x01, 0x11, 0x0e, 0x08, 0x06, }, // 'ç'
    { 0x00, 0x00, 0x02, 0x04, 0x00, 0x0e, 0x11, 0x1f, 0x01, 0x0e, 0x00, 0x00, }, // 'è'
    { 0x00, 0x00, 0x08, 0x04, 0x00, 0x0e, 0x11, 0x1f, 0x01, 0x0e, 0x00, 0x00, }, // 'é'
    { 0x00, 0x00, 0x04, 0x0a, 0x00, 0x0e, 0x11, 0x1f, 0x01, 0x0e, 0x00, 0x00, }, // 'ê'
    { 0x00, 0x00, 0x00, 0x0a, 0x00, 0x0e, 0x11, 0x1f, 0x01, 0x0e, 0x00, 0x00, }, // 'ë'
    { 0x00, 0x00, 0x02, 0x04, 0x00, 0x06, 0x04, 0x04, 0x04, 0x1f, 0x00, 0x00, }, // 'ì'
    { 0x00, 0x00, 0x08, 0x04, 0x00, 0x06, 0x04, 0x04, 0x04, 0x1f, 0x00, 0x00, }, // 'í'
    { 0x00, 0x00, 0x04, 0x0a, 0x00, 0x06, 0x04, 0x04, 0x04, 0x1f, 0x00, 0x00, }, // 'î'
    { 0x00, 0x00, 0x00, 0x0a, 0x00, 0x06, 0x04, 0x04, 0x04, 0x1f, 0x00, 0x00, }, // 'ï'
    { 0x00, 0x00, 0x0e, 0x30, 0x18, 0x1e, 0x11, 0x11, 0x11, 0x0e, 0x00, 0x00, }, // 'ð'
    { 0x00, 0x00, 0x16, 0x09, 0x00, 0x0f, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, }, // 'ñ'
    { 0x00, 0x00, 0x02, 0x04, 0x00, 0x0e, 0x11, 0x11, 0x11, 0x0e, 0x00, 0x00, }, // 'ò'
    { 0x00, 0x00, 0x08, 0x04, 0x00, 0x0e, 0x11, 0x11, 0x11, 0x0e, 0x00, 0x00, }, // 'ó'
    { 0x00, 0x00, 0x04, 0x0a, 0x00, 0x0e, 0x11, 0x11, 0x11, 0x0e, 0x00, 0x00, }, // 'ô'
    { 0x00, 0x00, 0x16, 0x09, 0x00, 0x0e, 0x11, 0x11, 0x11, 0x0e, 0x00, 0x00, }, // 'õ'
    { 0x00, 0x00, 0x00, 0x0a, 0x00, 0x0e, 0x11, 0x11, 0x11, 0x0e, 0x00, 0x00, }, // 'ö'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x1f, 0x00, 0x04, 0x00, 0x00, }, // '÷'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x16, 0x09, 0x15, 0x12, 0x0d, 0x00, 0x00, }, // 'ø'
    { 0x00, 0x00, 0x02, 0x04, 0x00, 0x11, 0x11, 0x11, 0x11, 0x1e, 0x00, 0x00, }, // 'ù'
    { 0x00, 0x00, 0x08, 0x04, 0x00, 0x11, 0x11, 0x11, 0x11, 0x1e, 0x00, 0x00, }, // 'ú'
    { 0x00, 0x00, 0x04, 0x0a, 0x00, 0x11, 0x11, 0x11, 0x11, 0x1e, 0x00, 0x00, }, // 'û'
    { 0x00, 0x00, 0x00, 0x0a, 0x00, 0x11, 0x11, 0x11, 0x11, 0x1e, 0x00, 0x00, }, // 'ü'
    { 0x00, 0x00, 0x08, 0x04, 0x00, 0x11, 0x11, 0x11, 0x11, 0x1e, 0x10, 0x0e, }, // 'ý'
    { 0x00, 0x00, 0x00, 0x01, 0x01, 0x0f, 0x11, 0x11, 0x11, 0x0f, 0x01, 0x01, }, // 'þ'
    { 0x00, 0x00, 0x00, 0x0a, 0x00, 0x11, 0x11, 0x11, 0x11, 0x1e, 0x10, 0x0e, }, // 'ÿ'
    { 0x00, 0x0e, 0x00, 0x0e, 0x11, 0x11, 0x1f, 0x11, 0x11, 0x11, 0x00, 0x00, }, // 'Ā'
    { 0x00, 0x00, 0x00, 0x0e, 0x00, 0x1e, 0x11, 0x11, 0x11, 0x1e, 0x00, 0x00, }, // 'ā'
    { 0x0a, 0x04, 0x00, 0x0e, 0x11, 0x11, 0x1f, 0x11, 0x11, 0x11, 0x00, 0x00, }, // 'Ă'
    { 0x00, 0x00, 0x0a, 0x04, 0x00, 0x1e, 0x11, 0x11, 0x11, 0x1e, 0x00, 0x00, }, // 'ă'
    { 0x00, 0x00, 0x00, 0x0e, 0x11, 0x11, 0x1f, 0x11, 0x11, 0x11, 0x08, 0x10, }, // 'Ą'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x11, 0x11, 0x11, 0x1e, 0x04, 0x18, }, // 'ą'
    { 0x08, 0x04, 0x00, 0x0e, 0x11, 0x01, 0x01, 0x01, 0x11, 0x0e, 0x00, 0x00, }, // 'Ć'
    { 0x00, 0x00, 0x08, 0x04, 0x00, 0x0e, 0x11, 0x01, 0x11, 0x0e, 0x00, 0x00, }, // 'ć'
    { 0x04, 0x0a, 0x00, 0x0e, 0x11, 0x01, 0x01, 0x01, 0x11, 0x0e, 0x00, 0x00, }, // 'Ĉ'
    { 0x00, 0x00, 0x04, 0x0a, 0x00, 0x0e, 0x11, 0x01, 0x11, 0x0e, 0x00, 0x00, }, // 'ĉ'
    { 0x00, 0x04, 0x00, 0x0e, 0x11, 0x01, 0x01, 0x01, 0x11, 0x0e, 0x00, 0x00, }, // 'Ċ'
    { 0x00, 0x00, 0x00, 0x04, 0x00, 0x0e, 0x11, 0x01, 0x11, 0x0e, 0x00, 0x00, }, // 'ċ'
    { 0x0a, 0x04, 0x00, 0x0e, 0x11, 0x01, 0x01, 0x01, 0x11, 0x0e, 0x00, 0x00, }, // 'Č'
    { 0x00, 0x00, 0x0a, 0x04, 0x00, 0x0e, 0x11, 0x01, 0x11, 0x0e, 0x00, 0x00, }, // 'č'
    { 0x0a, 0x04, 0x00, 0x0f, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0f, 0x00, 0x00, }, // 'Ď'
    { 0x00, 0x00, 0x50, 0x50, 0x10, 0x1e, 0x11, 0x11, 0x11, 0x1e, 0x00, 0x00, }, // 'ď'
    { 0x00, 0x00, 0x00, 0x0f, 0x11, 0x11, 0x13, 0x11, 0x11, 0x0f, 0x00, 0x00, }, // 'Đ'
    { 0x00, 0x00, 0x10, 0x3c, 0x10, 0x1e, 0x11, 0x11, 0x11, 0x1e, 0x00, 0x00, }, // 'đ'
    { 0x00, 0x0e, 0x00, 0x1f, 0x01, 0x01, 0x07, 0x01, 0x01, 0x1f, 0x00, 0x00, }, // 'Ē'
    { 0x00, 0x00, 0x00, 0x0e, 0x00, 0x0e, 0x11, 0x1f, 0x01, 0x0e, 0x00, 0x00, }, // 'ē'
    { 0x0a, 0x04, 0x00, 0x1f, 0x01, 0x01, 0x07, 0x01, 0x01, 0x1f, 0x00, 0x00, }, // 'Ĕ'
    { 0x00, 0x00, 0x0a, 0x04, 0x00, 0x0e, 0x11, 0x1f, 0x01, 0x0e, 0x00, 0x00, }, // 'ĕ'
    { 0x00, 0x04, 0x00, 0x1f, 0x01, 0x01, 0x07, 0x01, 0x01, 0x1f, 0x00, 0x00, }, // 'Ė'
    { 0x00, 0x00, 0x00, 0x04, 0x00, 0x0e, 0x11, 0x1f, 0x01, 0x0e, 0x00, 0x00, }, // 'ė'
    { 0x00, 0x00, 0x00, 0x1f, 0x01, 0x01, 0x07, 0x01, 0x01, 0x1f, 0x04, 0x18, }, // 'Ę'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x11, 0x1f, 0x01, 0x1e, 0x04, 0x18, }, // 'ę'
    { 0x00, 0x0e, 0x00, 0x1f, 0x01, 0x01, 0x07, 0x01, 0x01, 0x1f, 0x00, 0x00, }, // 'Ě'
    { 0x00, 0x00, 0x00, 0x0a, 0x00, 0x0e, 0x11, 0x1f, 0x01, 0x0e, 0x00, 0x00, }, // 'ě'
    { 0x04, 0x0a, 0x00, 0x0e, 0x11, 0x01, 0x1d, 0x11, 0x11, 0x0e, 0x00, 0x00, }, // 'Ĝ'
    { 0x00, 0x00, 0x04, 0x0a, 0x00, 0x1e, 0x11, 0x11, 0x11, 0x1e, 0x10, 0x0e, }, // 'ĝ'
    { 0x0a, 0x04, 0x00, 0x0e, 0x11, 0x01, 0x1d, 0x11, 0x11, 0x0e, 0x00, 0x00, }, // 'Ğ'
    { 0x00, 0x00, 0x0a, 0x04, 0x00, 0x1e, 0x11, 0x11, 0x11, 0x1e, 0x10, 0x0e, }, // 'ğ'
    { 0x00, 0x04, 0x00, 0x0e, 0x11, 0x01, 0x1d, 0x11, 0x11, 0x0e, 0x00, 0x00, }, // 'Ġ'
    { 0x00, 0x00, 0x00, 0x04, 0x00, 0x1e, 0x11, 0x11, 0x11, 0x1e, 0x10, 0x0e, }, // 'ġ'
    { 0x00, 0x00, 0x00, 0x0e, 0x11, 0x01, 0x1d, 0x11, 0x11, 0x0e, 0x08, 0x06, }, // 'Ģ'
    { 0x00, 0x00, 0x08, 0x04, 0x00, 0x1e, 0x11, 0x11, 0x11, 0x1e, 0x10, 0x0e, }, // 'ģ'
    { 0x04, 0x0a, 0x00, 0x11, 0x11, 0x11, 0x1f, 0x11, 0x11, 0x11, 0x00, 0x00, }, // 'Ĥ'
    { 0x00, 0x00, 0x08, 0x15, 0x01, 0x0f, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, }, // 'ĥ'
    { 0x00, 0x00, 0x00, 0x11, 0x3f, 0x11, 0x1f, 0x11, 0x11, 0x11, 0x00, 0x00, }, // 'Ħ'
    { 0x00, 0x00, 0x00, 0x01, 0x03, 0x01, 0x0f, 0x11, 0x11, 0x11, 0x00, 0x00, }, // 'ħ'
    { 0x16, 0x09, 0x00, 0x1f, 0x04, 0x04, 0x04, 0x04, 0x04, 0x1f, 0x00, 0x00, }, // 'Ĩ'
    { 0x00, 0x00, 0x16, 0x09, 0x00, 0x06, 0x04, 0x04, 0x04, 0x1f, 0x00, 0x00, }, // 'ĩ'
    { 0x00, 0x0e, 0x00, 0x1f, 0x04, 0x04, 0x04, 0x04, 0x04, 0x1f, 0x00, 0x00, }, // 'Ī'
    { 0x00, 0x00, 0x00, 0x0e, 0x00, 0x06, 0x04, 0x04, 0x04, 0x1f, 0x00, 0x00, }, // 'ī'
    { 0x0a, 0x04, 0x00, 0x1f, 0x04, 0x04, 0x04, 0x04, 0x04, 0x1f, 0x00, 0x00, }, // 'Ĭ'
    { 0x00, 0x00, 0x0a, 0x04, 0x00, 0x06, 0x04, 0x04, 0x04, 0x1f, 0x00, 0x00, }, // 'ĭ'
    { 0x00, 0x00, 0x00, 0x1f, 0x04, 0x04, 0x04, 0x04, 0x04, 0x1f, 0x04, 0x18, }, // 'Į'
    { 0x00, 0x00, 0x00, 0x04, 0x00, 0x06, 0x04, 0x04, 0x04, 0x1f, 0x04, 0x18, }, // 'į'
    { 0x16, 0x09, 0x00, 0x1f, 0x04, 0x04, 0x04, 0x04, 0x04, 0x1f, 0x00, 0x00, }, // 'İ'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x04, 0x04, 0x04, 0x1f, 0x00, 0x00, }, // 'ı'
    { 0x00, 0x00, 0x00, 0x17, 0x12, 0x12, 0x12, 0x12, 0x12, 0x0f, 0x00, 0x00, }, // 'Ĳ'
    { 0x00, 0x00, 0x00, 0x12, 0x00, 0x1b, 0x12, 0x12, 0x12, 0x1f, 0x10, 0x0e, }, // 'ĳ'
    { 0x04, 0x0a, 0x00, 0x10, 0x10, 0x10, 0x10, 0x11, 0x11, 0x0e, 0x00, 0x00, }, // 'Ĵ'
    { 0x00, 0x00, 0x10, 0x28, 0x00, 0x18, 0x10, 0x10, 0x10, 0x10, 0x11, 0x0e, }, // 'ĵ'
    { 0x00, 0x00, 0x00, 0x11, 0x09, 0x05, 0x03, 0x05, 0x09, 0x11, 0x04, 0x04, }, // 'Ķ'
    { 0x00, 0x00, 0x00, 0x01, 0x01, 0x11, 0x09, 0x07, 0x09, 0x11, 0x04, 0x04, }, // 'ķ'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x09, 0x07, 0x09, 0x11, 0x00, 0x00, }, // 'ĸ'
    { 0x08, 0x04, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x1f, 0x00, 0x00, }, // 'Ĺ'
    { 0x08, 0x04, 0x00, 0x1f, 0x04, 0x04, 0x04, 0x04, 0x04, 0x1f, 0x00, 0x00, }, // 'ĺ'
    { 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x1f, 0x08, 0x06, }, // 'Ļ'
    { 0x00, 0x00, 0x00, 0x1f, 0x04, 0x04, 0x04, 0x04, 0x04, 0x1f, 0x08, 0x06, }, // 'ļ'
    { 0x00, 0x00, 0x00, 0x11, 0x11, 0x09, 0x01, 0x01, 0x01, 0x1f, 0x00, 0x00, }, // 'Ľ'
    { 0x00, 0x00, 0x00, 0x13, 0x12, 0x0a, 0x02, 0x02, 0x02, 0x1c, 0x00, 0x00, }, // 'ľ'
    { 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x09, 0x01, 0x01, 0x1f, 0x00, 0x00, }, // 'Ŀ'
    { 0x00, 0x00, 0x00, 0x03, 0x02, 0x02, 0x0a, 0x02, 0x02, 0x1c, 0x00, 0x00, }, // 'ŀ'
    { 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x03, 0x01, 0x01, 0x1f, 0x00, 0x00, }, // 'Ł'
    { 0x00, 0x00, 0x00, 0x03, 0x02, 0x02, 0x06, 0x03, 0x02, 0x1c, 0x00, 0x00, }, // 'ł'
    { 0x08, 0x04, 0x00, 0x11, 0x11, 0x13, 0x15, 0x19, 0x11, 0x11, 0x00, 0x00, }, // 'Ń'
    { 0x00, 0x00, 0x08, 0x04, 0x00, 0x0f, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, }, // 'ń'
    { 0x00, 0x00, 0x00, 0x11, 0x11, 0x13, 0x15, 0x19, 0x11, 0x11, 0x04, 0x03, }, // 'Ņ'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x11, 0x11, 0x11, 0x11, 0x04, 0x03, }, // 'ņ'
    { 0x0a, 0x04, 0x00, 0x11, 0x11, 0x13, 0x15, 0x19, 0x11, 0x11, 0x00, 0x00, }, // 'Ň'
    { 0x00, 0x00, 0x0a, 0x04, 0x00, 0x0f, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, }, // 'ň'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, }, // 'ŉ'
    { 0x00, 0x00, 0x00, 0x11, 0x11, 0x13, 0x15, 0x19, 0x11, 0x11, 0x10, 0x0c, }, // 'Ŋ'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x11, 0x11, 0x11, 0x11, 0x10, 0x0c, }, // 'ŋ'
    { 0x00, 0x0e, 0x00, 0x0e, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0e, 0x00, 0x00, }, // 'Ō'
    { 0x00, 0x00, 0x00, 0x0e, 0x00, 0x0e, 0x11, 0x11, 0x11, 0x0e, 0x00, 0x00, }, // 'ō'
    { 0x0a, 0x04, 0x00, 0x0e, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0e, 0x00, 0x00, }, // 'Ŏ'
    { 0x00, 0x00, 0x0a, 0x04, 0x00, 0x0e, 0x11, 0x11, 0x11, 0x0e, 0x00, 0x00, }, // 'ŏ'
    { 0x14, 0x0a, 0x00, 0x0e, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0e, 0x00, 0x00, }, // 'Ő'
    { 0x00, 0x00, 0x14, 0x0a, 0x00, 0x0e, 0x11, 0x11, 0x11, 0x0e, 0x00, 0x00, }, // 'ő'
    { 0x00, 0x00, 0x00, 0x1e, 0x05, 0x05, 0x1d, 0x05, 0x05, 0x1e, 0x00, 0x00, }, // 'Œ'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x15, 0x1d, 0x05, 0x0e, 0x00, 0x00, }, // 'œ'
    { 0x08, 0x04, 0x00, 0x0f, 0x11, 0x11, 0x0f, 0x11, 0x11, 0x11, 0x00, 0x00, }, // 'Ŕ'
    { 0x00, 0x00, 0x08, 0x04, 0x00, 0x0d, 0x13, 0x01, 0x01, 0x01, 0x00, 0x00, }, // 'ŕ'
    { 0x00, 0x00, 0x00, 0x0f, 0x11, 0x11, 0x0f, 0x11, 0x11, 0x11, 0x04, 0x03, }, // 'Ŗ'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x0d, 0x13, 0x01, 0x01, 0x01, 0x04, 0x03, }, // 'ŗ'
    { 0x0a, 0x04, 0x00, 0x0f, 0x11, 0x11, 0x0f, 0x11, 0x11, 0x11, 0x00, 0x00, }, // 'Ř'
    { 0x00, 0x00, 0x0a, 0x04, 0x00, 0x0d, 0x13, 0x01, 0x01, 0x01, 0x00, 0x00, }, // 'ř'
    { 0x08, 0x04, 0x00, 0x0e, 0x11, 0x01, 0x0e, 0x10, 0x11, 0x0e, 0x00, 0x00, }, // 'Ś'
    { 0x00, 0x00, 0x08, 0x04, 0x00, 0x1e, 0x01, 0x0e, 0x10, 0x0f, 0x00, 0x00, }, // 'ś'
    { 0x04, 0x0a, 0x00, 0x0e, 0x11, 0x01, 0x0e, 0x10, 0x11, 0x0e, 0x00, 0x00, }, // 'Ŝ'
    { 0x00, 0x00, 0x04, 0x0a, 0x00, 0x1e, 0x01, 0x0e, 0x10, 0x0f, 0x00, 0x00, }, // 'ŝ'
    { 0x00, 0x00, 0x00, 0x0e, 0x11, 0x01, 0x0e, 0x10, 0x11, 0x0e, 0x04, 0x03, }, // 'Ş'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x01, 0x0e, 0x10, 0x0f, 0x04, 0x03, }, // 'ş'
    { 0x0a, 0x04, 0x00, 0x0e, 0x11, 0x01, 0x0e, 0x10, 0x11, 0x0e, 0x00, 0x00, }, // 'Š'
    { 0x00, 0x00, 0x0a, 0x04, 0x00, 0x1e, 0x01, 0x0e, 0x10, 0x0f, 0x00, 0x00, }, // 'š'
    { 0x00, 0x00, 0x00, 0x1f, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x03, }, // 'Ţ'
    { 0x00, 0x00, 0x00, 0x02, 0x02, 0x0f, 0x02, 0x02, 0x02, 0x1c, 0x08, 0x06, }, // 'ţ'
    { 0x0a, 0x04, 0x00, 0x1f, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x00, 0x00, }, // 'Ť'
    { 0x00, 0x00, 0x08, 0x0a, 0x02, 0x0f, 0x02, 0x02, 0x02, 0x1c, 0x00, 0x00, }, // 'ť'
    { 0x00, 0x00, 0x00, 0x1f, 0x04, 0x0e, 0x04, 0x04, 0x04, 0x04, 0x00, 0x00, }, // 'Ŧ'
    { 0x00, 0x00, 0x00, 0x02, 0x0f, 0x02, 0x0f, 0x02, 0x02, 0x1c, 0x00, 0x00, }, // 'ŧ'
    { 0x16, 0x09, 0x00, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0e, 0x00, 0x00, }, // 'Ũ'
    { 0x00, 0x00, 0x16, 0x09, 0x00, 0x11, 0x11, 0x11, 0x11, 0x1e, 0x00, 0x00, }, // 'ũ'
    { 0x00, 0x0e, 0x00, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0e, 0x00, 0x00, }, // 'Ū'
    { 0x00, 0x00, 0x00, 0x0e, 0x00, 0x11, 0x11, 0x11, 0x11, 0x1e, 0x00, 0x00, }, // 'ū'
    { 0x0a, 0x04, 0x00, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0e, 0x00, 0x00, }, // 'Ŭ'
    { 0x00, 0x00, 0x0a, 0x04, 0x00, 0x11, 0x11, 0x11, 0x11, 0x1e, 0x00, 0x00, }, // 'ŭ'
    { 0x0a, 0x04, 0x00, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0e, 0x00, 0x00, }, // 'Ů'
    { 0x00, 0x04, 0x0a, 0x04, 0x00, 0x11, 0x11, 0x11, 0x11, 0x1e, 0x00, 0x00, }, // 'ů'
    { 0x14, 0x0a, 0x00, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0e, 0x00, 0x00, }, // 'Ű'
    { 0x00, 0x00, 0x14, 0x0a, 0x00, 0x11, 0x11, 0x11, 0x11, 0x1e, 0x00, 0x00, }, // 'ű'
    { 0x00, 0x00, 0x00, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0e, 0x04, 0x18, }, // 'Ų'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x11, 0x11, 0x1e, 0x04, 0x18, }, // 'ų'
    { 0x04, 0x0a, 0x00, 0x11, 0x11, 0x11, 0x11, 0x15, 0x1b, 0x11, 0x00, 0x00, }, // 'Ŵ'
    { 0x00, 0x00, 0x04, 0x0a, 0x00, 0x11, 0x11, 0x15, 0x15, 0x0a, 0x00, 0x00, }, // 'ŵ'
    { 0x04, 0x0a, 0x00, 0x11, 0x11, 0x0a, 0x04, 0x04, 0x04, 0x04, 0x00, 0x00, }, // 'Ŷ'
    { 0x00, 0x00, 0x04, 0x0a, 0x00, 0x11, 0x11, 0x11, 0x11, 0x1e, 0x10, 0x0e, }, // 'ŷ'
    { 0x00, 0x0a, 0x00, 0x11, 0x11, 0x0a, 0x04, 0x04, 0x04, 0x04, 0x00, 0x00, }, // 'Ÿ'
    { 0x08, 0x04, 0x00, 0x1f, 0x10, 0x08, 0x04, 0x02, 0x01, 0x1f, 0x00, 0x00, }, // 'Ź'
    { 0x00, 0x00, 0x08, 0x04, 0x00, 0x1f, 0x08, 0x04, 0x02, 0x1f, 0x00, 0x00, }, // 'ź'
    { 0x00, 0x04, 0x00, 0x1f, 0x10, 0x08, 0x04, 0x02, 0x01, 0x1f, 0x00, 0x00, }, // 'Ż'
    { 0x00, 0x00, 0x00, 0x04, 0x00, 0x1f, 0x08, 0x04, 0x02, 0x1f, 0x00, 0x00, }, // 'ż'
    { 0x0a, 0x04, 0x00, 0x1f, 0x10, 0x08, 0x04, 0x02, 0x01, 0x1f, 0x00, 0x00, }, // 'Ž'
    { 0x00, 0x00, 0x0a, 0x04, 0x00, 0x1f, 0x08, 0x04, 0x02, 0x1f, 0x00, 0x00, }, // 'ž'
    { 0x00, 0x0a, 0x00, 0x1f, 0x01, 0x01, 0x0f, 0x01, 0x01, 0x1f, 0x00, 0x00, }, // 'Ё'
    { 0x00, 0x00, 0x00, 0x0e, 0x11, 0x11, 0x11, 0x1f, 0x11, 0x11, 0x00, 0x00, }, // 'А'
    { 0x00, 0x00, 0x00, 0x1f, 0x01, 0x01, 0x0f, 0x11, 0x11, 0x0f, 0x00, 0x00, }, // 'Б'
    { 0x00, 0x00, 0x00, 0x0f, 0x11, 0x11, 0x0f, 0x11, 0x11, 0x0f, 0x00, 0x00, }, // 'В'
    { 0x00, 0x00, 0x00, 0x1f, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, }, // 'Г'
    { 0x00, 0x00, 0x00, 0x0c, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x1f, 0x11, 0x00, }, // 'Д'
    { 0x00, 0x00, 0x00, 0x1f, 0x01, 0x01, 0x0f, 0x01, 0x01, 0x1f, 0x00, 0x00, }, // 'Е'
    { 0x00, 0x00, 0x00, 0x15, 0x15, 0x15, 0x0e, 0x15, 0x15, 0x15, 0x00, 0x00, }, // 'Ж'
    { 0x00, 0x00, 0x00, 0x0e, 0x11, 0x10, 0x0e, 0x10, 0x11, 0x0e, 0x00, 0x00, }, // 'З'
    { 0x00, 0x00, 0x00, 0x11, 0x11, 0x19, 0x15, 0x13, 0x11, 0x11, 0x00, 0x00, }, // 'И'
    { 0x00, 0x0a, 0x04, 0x11, 0x11, 0x19, 0x15, 0x13, 0x11, 0x11, 0x00, 0x00, }, // 'Й'
    { 0x00, 0x00, 0x00, 0x19, 0x05, 0x05, 0x03, 0x05, 0x09, 0x11, 0x00, 0x00, }, // 'К'
    { 0x00, 0x00, 0x00, 0x1e, 0x12, 0x12, 0x12, 0x12, 0x12, 0x11, 0x00, 0x00, }, // 'Л'
    { 0x00, 0x00, 0x00, 0x11, 0x1b, 0x15, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, }, // 'М'
    { 0x00, 0x00, 0x00, 0x11, 0x11, 0x11, 0x1f, 0x11, 0x11, 0x11, 0x00, 0x00, }, // 'Н'
    { 0x00, 0x00, 0x00, 0x0e, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0e, 0x00, 0x00, }, // 'О'
    { 0x00, 0x00, 0x00, 0x1f, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, }, // 'П'
    { 0x00, 0x00, 0x00, 0x0f, 0x11, 0x11, 0x0f, 0x01, 0x01, 0x01, 0x00, 0x00, }, // 'Р'
    { 0x00, 0x00, 0x00, 0x0e, 0x11, 0x01, 0x01, 0x01, 0x11, 0x0e, 0x00, 0x00, }, // 'С'
    { 0x00, 0x00, 0x00, 0x1f, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x00, 0x00, }, // 'Т'
    { 0x00, 0x00, 0x00, 0x11, 0x11, 0x11, 0x11, 0x1e, 0x10, 0x0e, 0x00, 0x00, }, // 'У'
    { 0x00, 0x00, 0x00, 0x04, 0x0e, 0x15, 0x15, 0x15, 0x0e, 0x04, 0x00, 0x00, }, // 'Ф'
    { 0x00, 0x00, 0x00, 0x11, 0x11, 0x0a, 0x04, 0x0a, 0x11, 0x11, 0x00, 0x00, }, // 'Х'
    { 0x00, 0x00, 0x00, 0x00, 0x09, 0x09, 0x09, 0x09, 0x09, 0x1f, 0x10, 0x00, }, // 'Ц'
    { 0x00, 0x00, 0x00, 0x11, 0x11, 0x11, 0x1e, 0x10, 0x10, 0x10, 0x00, 0x00, }, // 'Ч'
    { 0x00, 0x00, 0x00, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x1f, 0x00, 0x00, }, // 'Ш'
    { 0x00, 0x00, 0x00, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x1f, 0x10, 0x00, }, // 'Щ'
    { 0x00, 0x00, 0x00, 0x00, 0x03, 0x02, 0x0e, 0x12, 0x12, 0x0e, 0x00, 0x00, }, // 'Ъ'
    { 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x13, 0x15, 0x15, 0x13, 0x00, 0x00, }, // 'Ы'
    { 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x0f, 0x11, 0x11, 0x0f, 0x00, 0x00, }, // 'Ь'
    { 0x00, 0x00, 0x00, 0x0e, 0x11, 0x10, 0x1c, 0x10, 0x11, 0x0e, 0x00, 0x00, }, // 'Э'
    { 0x00, 0x00, 0x00, 0x09, 0x15, 0x15, 0x17, 0x15, 0x15, 0x09, 0x00, 0x00, }, // 'Ю'
    { 0x00, 0x00, 0x00, 0x00, 0x1e, 0x11, 0x11, 0x1e, 0x11, 0x11, 0x00, 0x00, }, // 'Я'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x10, 0x1e, 0x11, 0x1e, 0x00, 0x00, }, // 'а'
    { 0x00, 0x00, 0x00, 0x1e, 0x01, 0x0d, 0x13, 0x11, 0x11, 0x0e, 0x00, 0x00, }, // 'б'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x11, 0x0f, 0x11, 0x0f, 0x00, 0x00, }, // 'в'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, }, // 'г'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x0a, 0x0a, 0x0a, 0x1f, 0x11, 0x00, }, // 'д'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x11, 0x1f, 0x01, 0x0e, 0x00, 0x00, }, // 'е'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x15, 0x0e, 0x04, 0x0e, 0x15, 0x00, 0x00, }, // 'ж'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x09, 0x04, 0x09, 0x06, 0x00, 0x00, }, // 'з'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x19, 0x15, 0x13, 0x11, 0x00, 0x00, }, // 'и'
    { 0x00, 0x00, 0x00, 0x0a, 0x04, 0x11, 0x19, 0x15, 0x13, 0x11, 0x00, 0x00, }, // 'й'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x09, 0x07, 0x09, 0x11, 0x00, 0x00, }, // 'к'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x12, 0x12, 0x12, 0x11, 0x00, 0x00, }, // 'л'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x1b, 0x15, 0x11, 0x11, 0x00, 0x00, }, // 'м'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x1f, 0x11, 0x11, 0x00, 0x00, }, // 'н'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x11, 0x11, 0x11, 0x0e, 0x00, 0x00, }, // 'о'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, }, // 'п'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x0d, 0x13, 0x11, 0x11, 0x0f, 0x01, 0x01, }, // 'р'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x11, 0x01, 0x11, 0x0e, 0x00, 0x00, }, // 'с'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x04, 0x04, 0x04, 0x04, 0x00, 0x00, }, // 'т'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x11, 0x11, 0x1e, 0x10, 0x0e, }, // 'у'
    { 0x00, 0x00, 0x00, 0x04, 0x04, 0x0e, 0x15, 0x15, 0x15, 0x0e, 0x04, 0x04, }, // 'ф'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x0a, 0x04, 0x0a, 0x11, 0x00, 0x00, }, // 'х'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x09, 0x09, 0x09, 0x1f, 0x10, 0x00, }, // 'ц'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x11, 0x1e, 0x10, 0x00, 0x00, }, // 'ч'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x15, 0x15, 0x15, 0x15, 0x1f, 0x00, 0x00, }, // 'ш'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x15, 0x15, 0x15, 0x15, 0x1f, 0x10, 0x00, }, // 'щ'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x02, 0x0e, 0x12, 0x0e, 0x00, 0x00, }, // 'ъ'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x13, 0x15, 0x13, 0x00, 0x00, }, // 'ы'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x0f, 0x11, 0x0f, 0x00, 0x00, }, // 'ь'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x11, 0x1c, 0x11, 0x0e, 0x00, 0x00, }, // 'э'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x15, 0x17, 0x15, 0x09, 0x00, 0x00, }, // 'ю'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x11, 0x11, 0x1e, 0x11, 0x00, 0x00, }, // 'я'
    { 0x00, 0x00, 0x00, 0x0a, 0x00, 0x0e, 0x11, 0x1f, 0x01, 0x0e, 0x00, 0x00, }, // 'ё'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, }, // '—'
    { 0x00, 0x00, 0x00, 0x08, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, // '’'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x15, 0x15, 0x00, 0x00, }, // '…'
    { 0x00, 0x00, 0x00, 0x0c, 0x12, 0x07, 0x02, 0x07, 0x12, 0x0c, 0x00, 0x00, }, // '€'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x1e, 0x1f, 0x1e, 0x04, 0x00, 0x00, }, // '←'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x0e, 0x1f, 0x0e, 0x0e, 0x00, 0x00, }, // '↑'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x0f, 0x1f, 0x0f, 0x04, 0x00, 0x00, }, // '→'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x0e, 0x1f, 0x0e, 0x04, 0x00, 0x00, }, // '↓'
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, // ' '
};

u32 monogram_ascii_to_idx[127] = {
    0xFFFF,
    0xFFFF,
    0xFFFF,
    0xFFFF,
    0xFFFF,
    0xFFFF,
    0xFFFF,
    0xFFFF,
    0xFFFF,
    0xFFFF,
    0xFFFF,
    0xFFFF,
    0xFFFF,
    0xFFFF,
    0xFFFF,
    0xFFFF,
    0xFFFF,
    0xFFFF,
    0xFFFF,
    0xFFFF,
    0xFFFF,
    0xFFFF,
    0xFFFF,
    0xFFFF,
    0xFFFF,
    0xFFFF,
    0xFFFF,
    0xFFFF,
    0xFFFF,
    0xFFFF,
    0xFFFF,
    0xFFFF,
    389, // 0x20 ' '
    10, // 0x21 '!'
    11, // 0x22 '"'
    12, // 0x23 '#'
    13, // 0x24 '$'
    14, // 0x25 '%'
    15, // 0x26 '&'
    16, // 0x27 '''
    17, // 0x28 '('
    18, // 0x29 ')'
    19, // 0x2a '*'
    20, // 0x2b '+'
    21, // 0x2c ','
    22, // 0x2d '-'
    23, // 0x2e '.'
    24, // 0x2f '/'
    0, // 0x30 '0'
    1, // 0x31 '1'
    2, // 0x32 '2'
    3, // 0x33 '3'
    4, // 0x34 '4'
    5, // 0x35 '5'
    6, // 0x36 '6'
    7, // 0x37 '7'
    8, // 0x38 '8'
    9, // 0x39 '9'
    25, // 0x3a ':'
    26, // 0x3b ';'
    27, // 0x3c '<'
    28, // 0x3d '='
    29, // 0x3e '>'
    30, // 0x3f '?'
    31, // 0x40 '@'
    32, // 0x41 'A'
    33, // 0x42 'B'
    34, // 0x43 'C'
    35, // 0x44 'D'
    36, // 0x45 'E'
    37, // 0x46 'F'
    38, // 0x47 'G'
    39, // 0x48 'H'
    40, // 0x49 'I'
    41, // 0x4a 'J'
    42, // 0x4b 'K'
    43, // 0x4c 'L'
    44, // 0x4d 'M'
    45, // 0x4e 'N'
    46, // 0x4f 'O'
    47, // 0x50 'P'
    48, // 0x51 'Q'
    49, // 0x52 'R'
    50, // 0x53 'S'
    51, // 0x54 'T'
    52, // 0x55 'U'
    53, // 0x56 'V'
    54, // 0x57 'W'
    55, // 0x58 'X'
    56, // 0x59 'Y'
    57, // 0x5a 'Z'
    58, // 0x5b '['
    59, // 0x5c '\'
    60, // 0x5d ']'
    61, // 0x5e '^'
    62, // 0x5f '_'
    63, // 0x60 '`'
    64, // 0x61 'a'
    65, // 0x62 'b'
    66, // 0x63 'c'
    67, // 0x64 'd'
    68, // 0x65 'e'
    69, // 0x66 'f'
    70, // 0x67 'g'
    71, // 0x68 'h'
    72, // 0x69 'i'
    73, // 0x6a 'j'
    74, // 0x6b 'k'
    75, // 0x6c 'l'
    76, // 0x6d 'm'
    77, // 0x6e 'n'
    78, // 0x6f 'o'
    79, // 0x70 'p'
    80, // 0x71 'q'
    81, // 0x72 'r'
    82, // 0x73 's'
    83, // 0x74 't'
    84, // 0x75 'u'
    85, // 0x76 'v'
    86, // 0x77 'w'
    87, // 0x78 'x'
    88, // 0x79 'y'
    89, // 0x7a 'z'
    90, // 0x7b '{'
    91, // 0x7c '|'
    92, // 0x7d '}'
    93, // 0x7e '~'
};

void draw_monogram_char(u32* dest, size_t dest_w, char ch, u64 dest_x, u64 dest_y, u8 scale, u32 color)
{
    u32 char_idx = monogram_ascii_to_idx[ch];

    //print_i64(ch);
    //print_endl();
    //print_i64(char_idx);
    //print_endl();

    u32* d = dest + dest_x + dest_w * dest_y;

    for (u64 y = 0; y < FONT_MONOGRAM_HEIGHT; ++y)
    {
        u8 pixel_bits = font_monogram_data[char_idx][y];
        for (u8 i = 0; i < scale; ++i)
        {
            u64 x = 0;
            u8 pb = pixel_bits;

            while (pb)
            {
                if (pb & 1) memset32(d + x, color, scale);
                x = x + scale;
                pb = pb >> 1;
            }

            d = d + dest_w;
        }
    }
}

size_t FRAME_WIDTH = 400;
size_t FRAME_HEIGHT = 400;

u32 frame_buffer[161600];

void anim_callback()
{
    u8 scale = 2;

    // Grey background.
    //memset(frame_buffer, 0x7f, sizeof(frame_buffer));

    rainbow_background(frame_buffer, FRAME_WIDTH-1, FRAME_HEIGHT);

    for (size_t ch = 32; ch < 127; ++ch) {
        u64 x = ch % 26 * FONT_MONOGRAM_WIDTH * scale;
        u64 y = ch / 26 * FONT_MONOGRAM_HEIGHT * scale;

        // Drop shadow.
        draw_monogram_char(
            frame_buffer,
            FRAME_WIDTH,
            ch,
            scale * 11 + x,
            scale * 11 + y,
            scale,
            0x00000000
        );

        // Foreground font glyphs.
        draw_monogram_char(
            frame_buffer,
            FRAME_WIDTH,
            ch,
            scale * 10 + x,
            scale * 10 + y,
            scale,
            0x00FFFFFF
        );
    }

<<<<<<< HEAD
    time_delay_cb(100, anim_callback);
=======
    window_draw_frame(0, frame_buffer);
    time_delay_cb(10, anim_callback);
>>>>>>> a215ee22c43a2d208774a8277013b82a97eafbe5
}

void main()
{
    window_create(FRAME_WIDTH, FRAME_HEIGHT, "Monogram Font Example", 0);

    time_delay_cb(0, anim_callback);

    enable_event_loop();
}

