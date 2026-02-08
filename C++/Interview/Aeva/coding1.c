/* Given an integer x, write pseudo-code that multiplies x with 3.5 and returns the integer result. You are not allowed to use %, /, 
*/

Since you can’t use multiplication, division, or modulo, the trick is to use bit shifts and addition.

Recall:

• x << 1 = 2x
• x >> 1 = x / 2 (integer division)

And:

3.5x = 3x + 0.5x = (2x + x) + (x/2)

✅ Pseudo-code
function multiplyBy3Point5(x):
    doubleX = x << 1        // 2x
    tripleX = doubleX + x  // 3x
    halfX   = x >> 1       // x / 2

    result = tripleX + halfX
    return result

📌 Why it works
Expression	Meaning
x << 1	multiply by 2
+ x	adds another x → 3x
x >> 1	divides by 2 → 0.5x
sum	3.5x
⚠ Note

This returns the integer result (fraction truncated) since right shift performs integer division.