#include "Base360.h"

#include <cmath>
#include <string>
#include <vector>
#include <algorithm>

// all 360 emojis used
std::string emojis = "😀 😃 😄 😁 😆 😅 😂 🤣 😊 😇 🙂 🙃 😉 😌 😍 🥰 😘 😗 😙 😎 🤩 🥳 😏 😒 😞 😔 😟 🙁 ☹️ 😣 😖 😫 😩 🥺 😢 😭 😤 😠 😡 🤬 🤯 😳 🥵 🥶 😱 😰 😥 😓 🤗 🤔 🤭 🤫 🤥 🤢 🤮 🤧 😷 🤒 👋 🤚 🖐 ✋ 🖖 👌 🤏 ✌️ 🤞 🤟 🤘 🤙 👈 👉 👆 🖕 👇 ☝️ 👍 👎 ✊ 🤛 🤝 🙏 ✍️ 💅 🤳 💪 🦾 🦵 🦿 🦶 👂 🦻 👃 🧠 🦷 🦴 👀 👅 👄 💋 🩸 🧳 🌂 ☂️ 🧵 🧶 👓 🥽 🥼 🦺 👔 👕 👖 🧣 🧥 🧦 👗 👘 🥻 🩱 🩲 🩳 👙 👚 👛 👝 🎒 👞 👟 🥾 🥿 👠 👡 🩰 👢 👑 👒 🎩 🎓 🧢 💄 💍 💼 🐶 🐱 🐭 🐹 🐰 🦊 🐻 🐼 🐨 🐯 🦁 🐮 🐷 🐽 🐸 🐵 🙈 🙉 🙊 🐒 🐔 🐧 🐦 🐤 🐣 🐥 🦆 🦅 🦉 🦇 🐺 🐗 🐴 🦄 🐝 🐛 🦋 🐌 🐞 🐜 🦟 🦗 🦂 🐢 🐍 🦎 🦖 🦕 🐙 🦑 🦐 🦞 🐡 🐠 🐟 🐬 🐳 🐋 🦈 🐊 🐅 🐆 🦓 🦧 🐘 🦛 🦏 🦥 🐁 🐀 🦔 🐾 🐉 🐲 🌳 🌴 🌱 🌿 ☘️ 🎍 🎋 🍃 🍂 🍁 🐚 🌾 💐 🌷 🌹 🥀 🌺 🌸 🌼 🌻 🌞 🌝 🌛 🌜 🌚 🌓 🌙 🌎 🌍 🪐 💫 🌟 ✨ ☄️ 🔥 🌈 ☁️ ❄️ ☃️ 💨 💦 ☂️ 🌊 📱 📲 💻 ⌨️ 💽 💾 💿 📀 📼 📷 📸 📹 🎥 📞 ☎️ 📟 📠 📺 📻 🧭 ⏰ ⏳ 📡 ⚖️ 🧰 🔧 🔨 🔩 ⚙️ 🧱 🚽 🚰 🚿 🧸 🛒 🎁 🎈 🎏 🎀 🎊 🎉 🎎 🏮 🎐 🧧 ✉️ 📩 📨 📧 💌 📥 📤 📦 📪 📫 📬 📭 📮 📯 📜 📃 📄 📊 📈 📉 📆 📅 📇 📋 📁 📂 📰 📓 📔 📒 📕 📗 📘 📙 🔍 📖 🔖 🧷 🔗 📎 📐 📏 🧮 📌 📍 ✂️ ✒️ 📝 ✏️ 🔍 🔎 🔏 🔐 🔒 🔓";
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