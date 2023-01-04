> The idea for this project came about as a joke although this package **may** have some actual usage

## Installing

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
const decoded = Base360.decode(encoded); // 100000000000000000000n
```

## Todo

* Does this actually save space for larger numbers than base10, base16, and base32?
* Time complexity of the functions