// Font for a Christmas card with a Charlieplexed display
// By:   _           _               
//      (_)_  _ _ _ (_)_ __  ___ _ _ 
//      | | || | ' \| | '_ \/ -_) '_|
//     _/ |\_,_|_||_|_| .__/\___|_|  
//    |__/            |_|  
// Filename: christmasfont.h
// Date: Nov 24, 2019

#ifndef CHRISTMASFONT_H
#define CHRISTMASFONT_H

// Declare font array constant.
static const uint8_t font[128][4] = {
    {0x00, 0x00, 0x00, 0x00}, // NUL [0]
    {0x00, 0x00, 0x00, 0x00}, //  [1]
    {0x00, 0x00, 0x00, 0x00}, //  [2]
    {0x00, 0x00, 0x00, 0x00}, //  [3]
    {0x00, 0x00, 0x00, 0x00}, //  [4]
    {0x00, 0x00, 0x00, 0x00}, //  [5]
    {0x00, 0x00, 0x00, 0x00}, //  [6]
    {0x00, 0x00, 0x00, 0x00}, //  [7]
    {0x00, 0x00, 0x00, 0x00}, //  [8]
    {0x00, 0x00, 0x00, 0x00}, //  [9]
    {0x00, 0x00, 0x00, 0x00}, //  [10]
    {0x00, 0x00, 0x00, 0x00}, //  [11]
    {0x00, 0x00, 0x00, 0x00}, //  [12]
    {0x00, 0x00, 0x00, 0x00}, //  [13]
    {0x00, 0x00, 0x00, 0x00}, //  [14]
    {0x00, 0x00, 0x00, 0x00}, //  [15]
    {0x00, 0x00, 0x00, 0x00}, //  [16]
    {0x00, 0x00, 0x00, 0x00}, //  [17]
    {0x00, 0x00, 0x00, 0x00}, //  [18]
    {0x00, 0x00, 0x00, 0x00}, //  [19]
    {0x00, 0x00, 0x00, 0x00}, //  [20]
    {0x00, 0x00, 0x00, 0x00}, //  [21]
    {0x00, 0x00, 0x00, 0x00}, //  [22]
    {0x00, 0x00, 0x00, 0x00}, //  [23]
    {0x00, 0x00, 0x00, 0x00}, //  [24]
    {0x00, 0x00, 0x00, 0x00}, //  [25]
    {0x00, 0x00, 0x00, 0x00}, //  [26]
    {0x00, 0x00, 0x00, 0x00}, //  [27]
    {0x00, 0x00, 0x00, 0x00}, //  [28]
    {0x00, 0x00, 0x00, 0x00}, //  [29]
    {0x00, 0x00, 0x00, 0x00}, //  [30]
    {0x00, 0x00, 0x00, 0x00}, //  [31]
    {0x00, 0x00, 0x00, 0x00}, // Space [32]
    {0x00, 0x1D, 0x00, 0x00}, // ! [33]
    {0x18, 0x00, 0x18, 0x00}, // " [34]
    {0x00, 0x00, 0x00, 0x00}, // # [35] TBA
    {0x09, 0x1F, 0x12, 0x00}, // $ [36]
    {0x13, 0x04, 0x19, 0x00}, // % [37]
    {0x00, 0x00, 0x00, 0x00}, // & [38] TBA
    {0x00, 0x18, 0x00, 0x00}, // ' [39]
    {0x00, 0x0E, 0x11, 0x00}, // ( [40]
    {0x11, 0x0E, 0x00, 0x00}, // ) [41]
    {0x04, 0x0A, 0x04, 0x00}, // * [42]
    {0x04, 0x0E, 0x04, 0x00}, // + [43]
    {0x01, 0x02, 0x00, 0x00}, // , [44]
    {0x04, 0x04, 0x04, 0x00}, // - [45]
    {0x00, 0x01, 0x00, 0x00}, // . [46]
    {0x03, 0x04, 0x18, 0x00}, // / [47]
    {0x1F, 0x11, 0x1F, 0x00}, // 0 [48]
    {0x09, 0x1F, 0x01, 0x00}, // 1 [49]
    {0x13, 0x15, 0x09, 0x00}, // 2 [50]
    {0x11, 0x15, 0x0A, 0x00}, // 3 [51]
    {0x1C, 0x04, 0x1F, 0x00}, // 4 [52]
    {0x19, 0x15, 0x12, 0x00}, // 5 [53]
    {0x0E, 0x15, 0x12, 0x00}, // 6 [54]
    {0x13, 0x14, 0x18, 0x00}, // 7 [55]
    {0x0A, 0x15, 0x0A, 0x00}, // 8 [56]
    {0x09, 0x15, 0x0E, 0x00}, // 9 [57]
    {0x00, 0x0A, 0x00, 0x00}, // : [58]
    {0x01, 0x0A, 0x00, 0x00}, // ; [59]
    {0x04, 0x0A, 0x11, 0x00}, // < [60]
    {0x0A, 0x0A, 0x0A, 0x00}, // = [61]
    {0x11, 0x0A, 0x04, 0x00}, // > [62]
    {0x10, 0x15, 0x08, 0x00}, // ? [39]
    {0x00, 0x00, 0x00, 0x00}, // @ [64] TBA
    {0x0F, 0x14, 0x0F, 0x00}, // A [65]
    {0x1F, 0x15, 0x0A, 0x00}, // B [66]
    {0x0E, 0x11, 0x11, 0x00}, // C [67]
    {0x1F, 0x11, 0x0E, 0x00}, // D [68]
    {0x1F, 0x15, 0x11, 0x00}, // E [69]
    {0x1F, 0x14, 0x10, 0x00}, // F [70]
    {0x0E, 0x11, 0x16, 0x00}, // G [71]
    {0x1F, 0x04, 0x1F, 0x00}, // H [72]
    {0x11, 0x1F, 0x11, 0x00}, // I [73]
    {0x02, 0x01, 0x1E, 0x00}, // J [74]
    {0x1F, 0x04, 0x1B, 0x00}, // K [75]
    {0x1F, 0x01, 0x01, 0x00}, // L [76]
    {0x1F, 0x08, 0x1F, 0x00}, // M [77]
    {0x1F, 0x10, 0x0F, 0x00}, // N [78]
    {0x0E, 0x11, 0x0E, 0x00}, // O [79]
    {0x1F, 0x14, 0x08, 0x00}, // P [80]
    {0x0C, 0x12, 0x0D, 0x00}, // Q [81]
    {0x1F, 0x14, 0x0B, 0x00}, // R [82]
    {0x09, 0x15, 0x12, 0x00}, // S [83]
    {0x10, 0x1F, 0x10, 0x00}, // T [84]
    {0x1F, 0x01, 0x1F, 0x00}, // U [85]
    {0x1E, 0x01, 0x1E, 0x00}, // V [86]
    {0x1F, 0x02, 0x1F, 0x00}, // W [87]
    {0x1B, 0x04, 0x1B, 0x00}, // X [88]
    {0x18, 0x07, 0x18, 0x00}, // Y [89]
    {0x13, 0x15, 0x19, 0x00}, // Z [90]
    {0x00, 0x00, 0x00, 0x00}, // [ [91] TBA
    {0x18, 0x04, 0x03, 0x00}, // \ [92]
    {0x00, 0x00, 0x00, 0x00}, // ] [93] TBA
    {0x00, 0x00, 0x00, 0x00}, // ^ [94] TBA
    {0x00, 0x00, 0x00, 0x00}, // _ [95] TBA
    {0x00, 0x00, 0x00, 0x00}, // ` [96] TBA
    {0x00, 0x00, 0x00, 0x00}, // a [97] TBA
    {0x00, 0x00, 0x00, 0x00}, // b [98] TBA
    {0x00, 0x00, 0x00, 0x00}, // c [99] TBA
    {0x00, 0x00, 0x00, 0x00}, // d [100] TBA
    {0x00, 0x00, 0x00, 0x00}, // e [101] TBA
    {0x00, 0x00, 0x00, 0x00}, // f [102] TBA
    {0x00, 0x00, 0x00, 0x00}, // g [103] TBA
    {0x00, 0x00, 0x00, 0x00}, // h [104] TBA
    {0x00, 0x00, 0x00, 0x00}, // i [105] TBA
    {0x00, 0x00, 0x00, 0x00}, // j [106] TBA
    {0x00, 0x00, 0x00, 0x00}, // k [107] TBA
    {0x00, 0x00, 0x00, 0x00}, // l [108] TBA
    {0x00, 0x00, 0x00, 0x00}, // m [109] TBA
    {0x00, 0x00, 0x00, 0x00}, // n [110] TBA
    {0x00, 0x00, 0x00, 0x00}, // o [111] TBA
    {0x00, 0x00, 0x00, 0x00}, // p [112] TBA
    {0x00, 0x00, 0x00, 0x00}, // q [113] TBA
    {0x00, 0x00, 0x00, 0x00}, // r [114] TBA
    {0x00, 0x00, 0x00, 0x00}, // s [115] TBA
    {0x00, 0x00, 0x00, 0x00}, // t [116] TBA
    {0x00, 0x00, 0x00, 0x00}, // u [117] TBA
    {0x00, 0x00, 0x00, 0x00}, // v [118] TBA
    {0x00, 0x00, 0x00, 0x00}, // w [119] TBA
    {0x00, 0x00, 0x00, 0x00}, // x [120] TBA
    {0x00, 0x00, 0x00, 0x00}, // y [121] TBA
    {0x00, 0x00, 0x00, 0x00}, // z [122] TBA
    {0x00, 0x00, 0x00, 0x00}, // { [123] TBA
    {0x00, 0x00, 0x00, 0x00}, // | [124] TBA
    {0x00, 0x00, 0x00, 0x00}, // } [125] TBA
    {0x00, 0x00, 0x00, 0x00}, // ~ [126] TBA
    {0x00, 0x00, 0x00, 0x00}, // DEL [127]
};

#endif 