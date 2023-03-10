#include "Base360.h"

#include <cmath>
#include <string>
#include <vector>
#include <algorithm>

// all 360 emojis used
std::string emojis = "๐ ๐ ๐ ๐ ๐ ๐ ๐ ๐คฃ ๐ ๐ ๐ ๐ ๐ ๐ ๐ ๐ฅฐ ๐ ๐ ๐ ๐ ๐คฉ ๐ฅณ ๐ ๐ ๐ ๐ ๐ ๐ โน๏ธ ๐ฃ ๐ ๐ซ ๐ฉ ๐ฅบ ๐ข ๐ญ ๐ค ๐  ๐ก ๐คฌ ๐คฏ ๐ณ ๐ฅต ๐ฅถ ๐ฑ ๐ฐ ๐ฅ ๐ ๐ค ๐ค ๐คญ ๐คซ ๐คฅ ๐คข ๐คฎ ๐คง ๐ท ๐ค ๐ ๐ค ๐ โ ๐ ๐ ๐ค โ๏ธ ๐ค ๐ค ๐ค ๐ค ๐ ๐ ๐ ๐ ๐ โ๏ธ ๐ ๐ โ ๐ค ๐ค ๐ โ๏ธ ๐ ๐คณ ๐ช ๐ฆพ ๐ฆต ๐ฆฟ ๐ฆถ ๐ ๐ฆป ๐ ๐ง  ๐ฆท ๐ฆด ๐ ๐ ๐ ๐ ๐ฉธ ๐งณ ๐ โ๏ธ ๐งต ๐งถ ๐ ๐ฅฝ ๐ฅผ ๐ฆบ ๐ ๐ ๐ ๐งฃ ๐งฅ ๐งฆ ๐ ๐ ๐ฅป ๐ฉฑ ๐ฉฒ ๐ฉณ ๐ ๐ ๐ ๐ ๐ ๐ ๐ ๐ฅพ ๐ฅฟ ๐  ๐ก ๐ฉฐ ๐ข ๐ ๐ ๐ฉ ๐ ๐งข ๐ ๐ ๐ผ ๐ถ ๐ฑ ๐ญ ๐น ๐ฐ ๐ฆ ๐ป ๐ผ ๐จ ๐ฏ ๐ฆ ๐ฎ ๐ท ๐ฝ ๐ธ ๐ต ๐ ๐ ๐ ๐ ๐ ๐ง ๐ฆ ๐ค ๐ฃ ๐ฅ ๐ฆ ๐ฆ ๐ฆ ๐ฆ ๐บ ๐ ๐ด ๐ฆ ๐ ๐ ๐ฆ ๐ ๐ ๐ ๐ฆ ๐ฆ ๐ฆ ๐ข ๐ ๐ฆ ๐ฆ ๐ฆ ๐ ๐ฆ ๐ฆ ๐ฆ ๐ก ๐  ๐ ๐ฌ ๐ณ ๐ ๐ฆ ๐ ๐ ๐ ๐ฆ ๐ฆง ๐ ๐ฆ ๐ฆ ๐ฆฅ ๐ ๐ ๐ฆ ๐พ ๐ ๐ฒ ๐ณ ๐ด ๐ฑ ๐ฟ โ๏ธ ๐ ๐ ๐ ๐ ๐ ๐ ๐พ ๐ ๐ท ๐น ๐ฅ ๐บ ๐ธ ๐ผ ๐ป ๐ ๐ ๐ ๐ ๐ ๐ ๐ ๐ ๐ ๐ช ๐ซ ๐ โจ โ๏ธ ๐ฅ ๐ โ๏ธ โ๏ธ โ๏ธ ๐จ ๐ฆ โ๏ธ ๐ ๐ฑ ๐ฒ ๐ป โจ๏ธ ๐ฝ ๐พ ๐ฟ ๐ ๐ผ ๐ท ๐ธ ๐น ๐ฅ ๐ โ๏ธ ๐ ๐  ๐บ ๐ป ๐งญ โฐ โณ ๐ก โ๏ธ ๐งฐ ๐ง ๐จ ๐ฉ โ๏ธ ๐งฑ ๐ฝ ๐ฐ ๐ฟ ๐งธ ๐ ๐ ๐ ๐ ๐ ๐ ๐ ๐ ๐ฎ ๐ ๐งง โ๏ธ ๐ฉ ๐จ ๐ง ๐ ๐ฅ ๐ค ๐ฆ ๐ช ๐ซ ๐ฌ ๐ญ ๐ฎ ๐ฏ ๐ ๐ ๐ ๐ ๐ ๐ ๐ ๐ ๐ ๐ ๐ ๐ ๐ฐ ๐ ๐ ๐ ๐ ๐ ๐ ๐ ๐ ๐ ๐ ๐งท ๐ ๐ ๐ ๐ ๐งฎ ๐ ๐ โ๏ธ โ๏ธ ๐ โ๏ธ ๐ ๐ ๐ ๐ ๐ ๐";
std::vector<std::string> emoji_list = std::vector<std::string>();

int getIndexOfVector(std::vector<std::string> v, std::string s)
{
    int index = 0;
    auto it = std::find(v.begin(), v.end(), s);
    if (it != v.end())
    {
        index = std::distance(v.begin(), it);

    }
    return index;
}

inline unsigned utf8_byte_count(uint8_t c)
{
    uint8_t mask = 0x80u;
    unsigned result = 0;
    while (c & mask)
    {
        ++result;
        mask >>= 1;
    }
    return (result == 0) ? 1 : ((result > 4) ? 4 : result);
}

std::vector<std::string> split_by_codepoint(std::string input)
{
    std::vector<std::string> ret;
    auto it = input.cbegin();
    while (it != input.cend())
    {
        uint8_t count = utf8_byte_count(*it);
        ret.emplace_back(std::string{it, it+count});
        it += count;
    }
    return ret;
}

std::string base360_encode(int number)
{
    int n = number;
    std::string m = "";
    int b = 360;
    while (n != 0)
    {
        int d = floor(n / b);
        int r = n % b;
        n = d;
        m = emoji_list[r] + m;
    }
    return m;
}

int base360_decode(std::string base360)
{
    auto split = split_by_codepoint(base360);
    
    int n = split.size();
    int digits = n;
    int b = 360;
    int s = 0;
    for (int i = 0; i < digits; i++)
    {
        n -= 1;
        std::vector<std::string>::iterator it = std::find(emoji_list.begin(), emoji_list.end(), split[i]);
        if (it != emoji_list.end())
        {
            int index = std::distance(emoji_list.begin(), it);
            s += index * pow(b, n);
        }
    }
    return s;
}

void base360_init()
{
    // get their numbered mapped
    size_t pos = 0;
    std::string token;
    std::string delimiter = " ";
    while ((pos = emojis.find(delimiter)) != std::string::npos)
    {
        token = emojis.substr(0, pos);
        emoji_list.push_back(token);
        emojis.erase(0, pos + delimiter.length());
    }
    emoji_list.push_back(emojis);
}