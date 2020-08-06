# Base360 for C++
#### Made as a joke / for a bet

# Usage
### Encode
```cpp
#include "Base360.h"

int main()
{
    base360_init();
    std::string encoded_text =  base360_encode(1234); // 😁🐮
}
```
### Decode
```cpp
#include "Base360.h"

int main()
{
    base360_init();
    std::string encoded_text =  base360_decode("😁🐮"); // 1234
}
```

# !! Bigger numbers seem to not encode/decode properly !!