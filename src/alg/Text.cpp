#include "Text.h"

int Text::fromInt(int c) {
    switch (c) {
        case 0:
            return 68;
        case 1:
            return 69;
        case 2:
            return 70;
        case 3:
            return 71;
        case 4:
            return 72;
        case 5:
            return 73;
        case 6:
            return 74;
        case 7:
            return 75;
        case 8:
            return 76;
        case 9:
            return 77;
        default:
            return 68;
    }
}

int Text::fromChar(char c) {
    switch (c) {
        case '0':
            return 68;
        case '1':
            return 69;
        case '2':
            return 70;
        case '3':
            return 71;
        case '4':
            return 72;
        case '5':
            return 73;
        case '6':
            return 74;
        case '7':
            return 75;
        case '8':
            return 76;
        case '9':
            return 77;
        case 'l':
            return 84;
        case 'e':
            return 85;
        case 'v':
            return 86;
        case 'u':
            return 87;
        case 'p':
            return 88;
        case 'g':
            return 78;
        case 'a':
            return 79;
        case 'm':
            return 95;
        case 'o':
            return 100;
        case 'r':
            return 101;
        case ' ':
            return 31;
        default:
            return 31;
    }
}