#Multiply two numbers
#In this case, 4 and 6 (the first two instructions)
LAA 4
LAB 6
MOA 30
MOB 31

LDM 33 # load RAM address 20 to Math register
LDA 30 # load RAM address 20 to A register 
ADD
MMO 33 #load result into RAM address 33

LDA 32 # load RAM address 32 to A register 
INC 1
MOA 32 # load A register to RAM address 32

LDM 31
CMP
JNE 4

LDO 33
HLT
