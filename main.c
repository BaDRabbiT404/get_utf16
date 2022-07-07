#include <stdio.h>
#include <Windows.h>

wchar_t* get_utf16(const char* str, int codepage)
{
    int sz = MultiByteToWideChar(codepage, 0, &str[0], (int)(strlen(str)), 0, 0);
    wchar_t* res = (wchar_t*)malloc(sz * sizeof(wchar_t));
    ZeroMemory(res, lstrlen(res));
    MultiByteToWideChar(codepage, 0, &str[0], (int)(strlen(str)), &res[0], sz);

    return res;
}
