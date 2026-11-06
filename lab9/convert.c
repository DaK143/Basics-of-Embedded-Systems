#include "convert.h"

void ConvertDec(uint32_t num, char* str) {

    if(num >= 10000){
        str[0] = '*';
        str[1] = '*';
        str[2] = '*';
        str[3] = '*';
        str[4] = ' ';
        str[5] = '\0';
        return;
    }

    str[0] = (num >= 1000) ? ((num/1000)%10 + '0') : ' ';
    str[1] = (num >= 100)  ? ((num/100)%10  + '0') : ' ';
    str[2] = (num >= 10)   ? ((num/10)%10   + '0') : ' ';
    str[3] = (num%10) + '0';
    str[4] = ' ';
    str[5] = '\0';
}

void ConvertDistance(uint32_t num, char* str) {

    if(num >= 10000){
        str[0] = '*';
        str[1] = '.';
        str[2] = '*';
        str[3] = '*';
        str[4] = '*';
        str[5] = ' ';
        str[6] = 'c';
        str[7] = 'm';
        str[8] = '\0';
        return;
    }

    str[0] = (num/1000) + '0';
    str[1] = '.';
    str[2] = ((num/100)%10) + '0';
    str[3] = ((num/10)%10) + '0';
    str[4] = (num%10) + '0';
    str[5] = ' ';
    str[6] = 'c';
    str[7] = 'm';
    str[8] = '\0';
}
