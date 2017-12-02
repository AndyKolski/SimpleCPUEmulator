# SimpleCPUEmulator
An emulator for a CPU that I designed

## Compilation
Download source `git clone https://github.com/AndyKolski/SimpleCPUEmulator.git`

CD into source directory `cd SimpleCPUEmulator/`

Compile source with `make`

## Usage
Assemble a rom from assembly with `./createrom demo.bin demo.s` or create an empty rom with `./createrom demo.bin`

Boot rom with `./emulator demo.bin`

## Instruction Set

Mnemonic | Binary Representation | Hex | Brief Description
---|---|---|---
NOP |0000 0000 | 00 | Skip instruction
LDA |0000 0001 | 01 | Load RAM to A register
LDB |0000 0010 | 02 | Load RAM to B register
LDC |0000 0011 | 03 | Load RAM to C register
LDM |0000 0100 | 04 | Load RAM to Math In register 
LDO |0000 0101 | 05 | Load RAM to Math Output register 
LAA |0000 0110 | 06 | Load arbitrary value to A register
LAB |0000 0111 | 07 | Load arbitrary value to B register
LAC |0000 1000 | 08 | Load arbitrary value to C register
LAM |0000 1001 | 09 | Load arbitrary value to Math In register 
LAO |0000 1010 | 0A | Load arbitrary value to Math Output register 
ADD |0000 1011 | 0B | Add A register to Math register, storing in Math Out register 
SUB |0000 1100 | 0C | Subtract A register with Math register, storing in Math Out register 
INC |0000 1101 | 0D | Increment A register by arbitrary value
DEC |0000 1110 | 0E | Decrement A register by arbitrary value
MOA |0000 1111 | 0F | Move A register to RAM
MOB |0001 0000 | 10 | Move B register to RAM
MOC |0001 0001 | 11 | Move C register to RAM
MOM |0001 0010 | 12 | Move Math In register to RAM
MMO |0001 0011 | 13 | Move Math Out register to RAM
CMP |0001 0100 | 14 | Compare Math In with A register
JMP |0001 0101 | 15 | Set PC to value from A register
JME |0001 0110 | 16 | Set PC to value from A register if equal flag set
JNE |0001 0111 | 17 | Set PC to value from A register if not equal flag set
JGT |0001 1000 | 18 | Set PC to value from A register if greater than flag set
JLT |0001 1001 | 19 | Set PC to value from A register if lesser than flag set
GTE |0001 1010 | 1A | Set PC to value from A register if greater than  or equal flag set
LTE |0001 1011 | 1B | Set PC to value from A register if lesser than or equal flag set
CAL |1111 1101 | FD | Call subroutine at RAM address
RET |1111 1110 | FE | Return to where the subroutine was called
HLT |1111 1111 | FF | Halt system