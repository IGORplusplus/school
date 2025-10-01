= Igor Leeck
= CSCE 2610

#v(1em)
#text(font: "Nimbus Roman")[+ ]

#block[
```c
int a = 0x2025A;
int b = 3247;      // little-endian: AF 0C 00 00
```
]

#par[
The first step for both of them is to convert them to hexadecimal. (A already is, B isn't)
Second, pad them the next multiple of bytes(8 bits) (a: 0x0002025A)
Then it is to split them up (a: 00 | 02 | 02 | 5A )
]

#v(1em)

#text(font: "Nimbus Roman")[ ]
