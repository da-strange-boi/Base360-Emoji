# Base360-Emoji

> The idea for this project came about as a joke although this package **may** have some actual usage

## Installing

### Package manager

For npm:
```bash
$ npm install base360-emoji
```

For yarn:
```bash
$ yarn add base360-emoji
```

## Basic Example
```js
const Base360 = require('base360-emoji');

// some very large number
const number = 100n ** 10n;
const encoded = Base360.encode(number); // 🩰🍁🎩🌊🌚🦅🔓🎀
const decoded = Base360.encode(encoded); // 100000000000000000000n
```

## Todo

* Figure out which is faster `new RegExp('.{1,2}', 'g');` or `Buffer.from("😀😄").slice(0, 4).toString()`
* Does this actually save space for larger numbers than base10, base16, and base32?


