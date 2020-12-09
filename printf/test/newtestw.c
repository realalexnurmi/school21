#include <stddef.h>
#include <stdio.h>
#include <wchar.h>
#include <locale.h>
int main()
{
    setlocale(LC_ALL, "");
    wchar_t* haiku = L"古池や蛙飛び込む水の音ふるいけやかわずとびこむみずのおと";
    printf("%ls\n", haiku);
}
