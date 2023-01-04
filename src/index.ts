/** 360 4-byte emojis */
const EMOJIS = [
    "😀", "😃", "😄", "😁", "😆", "😅", "😂", "🤣", "😊", "😇", "🙂", "🙃", "😉", "😌", "😍", "🥰", "😘", "😗", "😙", "😝", "😎", "🤩", "🥳", "😏", "😒",
    "😞", "😔", "😟", "🙁", "😣", "😖", "😫", "😩", "🥺", "😢", "😭", "😤", "😠", "😡", "🤬", "🤯", "😳", "🥵", "🥶", "😱", "😰", "😥", "😓", "🤗", "🤔",
    "🤭", "🤫", "🤥", "🤢", "🤮", "🤧", "😷", "🤒", "👋", "🤚", "🖐", "🖖", "👌", "🤏", "🤞", "🤟", "🤘", "🤙", "👈", "👉", "👆", "🖕", "👇", "👍", "👎","🤛",
    "🤝", "🙏", "💅", "🤳", "💪", "🦾", "🦵", "🦿", "🦶", "👂", "🦻", "👃", "🧠", "🦷", "🦴", "👀", "👅", "👄", "💋", "🩸", "🧳", "🌂", "🧵", "🧶", "👓", "🥽",
    "🥼", "🦺", "👔", "👕", "👖", "🧣", "🧥", "🧦", "👗", "👘", "🥻", "🩱", "🩲", "🩳", "👙", "👚", "👛", "👝", "🎒", "👞", "👟", "🥾", "🥿", "👠", "👡",
    "🩰","👢", "👑", "👒", "🎩", "🎓", "🧢", "💄", "💍", "💼", "🐶", "🐱", "🐭", "🐹", "🐰", "🦊", "🐻", "🐼", "🐨", "🐯", "🦁", "🐮", "🐷", "🐽", "🐸",
    "🐵", "🙈","🙉", "🙊", "🐒", "🐔", "🐧", "🐦", "🐤", "🐣", "🐥", "🦆", "🦅", "🦉", "🦇", "🐺", "🐗", "🐴", "🦄", "🐝", "🐛", "🦋", "🐌", "🐞", "🐜",
    "🦟", "🦗", "🦂","🐢", "🐍", "🦎", "🦖", "🦕", "🐙", "🦑", "🦐", "🦞", "🐡", "🐠", "🐟", "🐬", "🐳", "🐋", "🦈", "🐊", "🐅", "🐆", "🦓", "🦧", "🐘",
    "🦛", "🦏", "🦥", "🐁","🐀", "🦔", "🐾", "🐉", "🐲", "🌳", "🌴", "🌱", "🌿", "🎍", "🎋", "🍃", "🍂", "🍁", "🐚", "🌾", "💐", "🌷", "🌹", "🥀", "🌺",
    "🌸", "🌼", "🌻", "🌞", "🌝", "🌛","🌜", "🌚", "🌓", "🌙", "🌎", "🌍", "🪐", "💫", "🎇", "🌟", "🔥", "🌈", "💨", "💦", "🌊", "📱", "📲", "💻", "💽",
    "💾", "💿", "📀", "📼", "📷", "📸", "📹", "🎥","📞", "📟", "📠", "📺", "📻", "🧭", "📡", "🧰", "🔧", "🔨", "🔩", "🧱", "🚽", "🚰", "🚿", "🧸", "🛒",
    "🎁", "🎈", "🎏", "🎀", "🎊", "🎉", "🎎", "🏮", "🎐", "🧧","📩", "📨", "📧", "💌", "📥", "📤", "📦", "📪", "📫", "📬", "📭", "📮", "📯", "📜", "📃", "📄",
    "📊", "📈", "📉", "📆", "📅", "📇", "📋", "📁", "📂", "📰", "📓","📔", "📒", "📕", "📗", "📘", "📙", "🔮", "📖", "🔖", "🧷", "🔗", "📎", "📐", "📏", "🧮",
    "📌", "📍", "📝", "🔍", "🔎", "🔏", "🔐", "🔒", "🔓", "🅿", "🕠", "🚃", "💷","🎿", "💯", "🚂", "🏁", "🚶", "🍯", "🎬", "💁", "💠", "👥", "💢", "🈯",
    "🔽", "🉑", "📚", "🕘", "🌖", "🎪"
];

/** The numeral base used */
const BASE = 360n;

/** Split by emoji */
const EMOJI_SPLIT_RE = new RegExp('.{1,2}', 'g');

/**
 * Encode a numeral value into base360
 * @param {Number|String|BigInt|Boolean} integer Any numeral value
 * @returns {String}
 */
const encode = (integer: number|string|bigint|boolean): string => {
    let number = BigInt(integer);
    let emojiNumber = "";

    if (number === 0n) return EMOJIS[0];
    while (number !== 0n) {
        const d = number / BASE;
        const r = number % BASE;
        number = d;
        emojiNumber = EMOJIS[Number(r)] + emojiNumber;
    }

    return emojiNumber;
}

/**
 * Decode a base360 emoji string back into its BigInt numeral form
 * @param {String} emojiNumber Emoji string
 * @returns {bigint}
 */
const decode = (emojiNumber: string): bigint => {
    const split = emojiNumber.match(EMOJI_SPLIT_RE);
    if (split === null) return BigInt(-1);

    let length = split.length;
    const digits = length;
    let number = BigInt(0);

    for (let i = 0; i < digits; i++) {
        length -= 1;
        const index = EMOJIS.indexOf(split[i]);
        number += BigInt(index) * (BASE ** BigInt(length));
    }

    return number;
}

export {
    encode,
    decode
};
