# Brainfuck Interpreter

![Bower](https://img.shields.io/bower/l/a?style=plastic)\
\
Brainfuck Interpreter written in C++.

## Description

This program reads in a Brainfuck file and executes the program.

## Installation

`
git clone https://github.com/trevortomlin/Brainfuck-Interpreter.git
`

## Usage

```console
$ g++ -o interpreter .\bfinterpreter.cpp
$ .\interpreter.exe .\helloworldbf.txt
```

## Technologies Used

C++, fstream, vector, stack

## Improvements

- Replace data array with vector to allow dynamic expansion.
- Create jump table for faster loops.

## References

[Wikipedia](https://en.wikipedia.org/wiki/Brainfuck)\
[Alex Lugo](https://www.youtube.com/watch?v=UD0EeMzgAPg)\
[Camto](https://www.youtube.com/watch?v=4uNM73pfJn0)

## License

This project is licensed under the GNU General Public License v3.0 - see the LICENSE file for details.
