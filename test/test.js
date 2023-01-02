const Base360 = require('../src/index.js');

/** Sample size for test amounts */
const SAMPLE_SIZE = 1000;

let randomResult = true;
for (let i = 0; i < SAMPLE_SIZE; i++) {
    // Random BigInt numbers (1 - 10000)
    const x = BigInt(Math.floor(Math.random() * 1000) + 1);
    const y = BigInt(Math.floor(Math.random() * 1000) + 1);

    const number = x ** y;
    const b360 = Base360.encode(number);
    const b10 = Base360.decode(b360);

    const result = b10 === number;
    randomResult &= result;
}

console.log(`Test Status: ${randomResult ? "Pass" : "Failed"}`);
