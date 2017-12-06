#Multiply two numbers
#In this case, 4 and 6 (the first two instructions)
LAA 4
LAB 6 
MOA 20
MOB 21

LDM 23 # load 20 to m
LDA 20 # load 20 to a
ADD
MMO 23 #load result into 23

LDA 22 # load 22 to a
INC 1
MOA 22 # load a to 22

LDM 21
CMP
JNE 5

LDO 23
HLT