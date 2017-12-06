#Multiply two numbers
#In this case, 4 and 6 (the first two instructions)
LAA 4
LAB 6
MOA 30
MOB 31

LDM 33 # load 20 to m
LDA 30 # load 20 to a
ADD
MMO 33 #load result into 23

LDA 32 # load 22 to a
INC 1
MOA 32 # load a to 22

LDM 31
CMP
JNE 4

LDO 33
HLT