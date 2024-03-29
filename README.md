# NumConvert
This simple command-line utility allows the user to convert
numbers between various systems, from base2 (binary) all
the way to base16 (hexadecimal).

## Local Compilation
You need **GCC** in order to compile and run this program.
You also need to link with C's *math.h* library in order to
avoid compilation errors, as shown below:
```sh
# cd --path-to-numconvert
sudo gcc src/numconvert.c -o /usr/bin/numconvert -lm
```

## Usage
This program has three available formats for base conversion:

---
numconvert  *decimal-number*  -b[**2-16**]

The above format will take in a decimal number, and will
convert it to an equivalent number whose base is specified by
the user.

Example:
```sh
numconvert 90 -b2
```
Output:
```sh
1011010
```

---
numconvert  -b[**2-16**]  *number*

The above format will take in a number whose base is
specified by the user, and convert it to decimal form.

Example:
```sh
numconvert -b2 1011010
```
Output:
```sh
90
```

---
numconvert  -b[**2-16**]  *number*  -b[**2-16**]

The above format will take in a number whose base is
specified by the user, and convert it to an equivalent number
whose base is also specified by the user.

Example:
```sh
numconvert -b8 367 -b16
```
Output:
```sh
F7
```

## Contact
email me
[@garrettjustice@protonmail.com](mailto:garrettjustice@protonmail.com)
to report any issues w/ the program.
