#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    u_int32_t buff[17];
    u_int32_t *pWrite;
    u_int32_t *pRead;
} CYC_BUFF;

void CYC_BUFF_READ(CYC_BUFF *buff, u_int32_t data) {

}
void CYC_BUFF_WRITE(CYC_BUFF *buff, u_int32_t data) {
    *buff->pWrite++ = data;
    if(buff->pWrite == buff->buff+17) {
        buff->pWrite = buff->buff;
}

bool CYC_BUFF_FULL(CYC_BUFF *buff, u_int32_t data) {
    return false;
}
int main() {

    CYC_BUFF buffer;


    return 0;
}