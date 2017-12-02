#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {

	int on = 1;

	int fle = 0;
	int flgt = 0;
	int fllt = 0;
	int flgte = 0;
	int fllte = 0;

	unsigned char pc = 0;
	unsigned char retaddress = 0;

	unsigned char Areg = 0;
	unsigned char Breg = 0;
	unsigned char Creg = 0;
	unsigned char MIreg = 0;
	unsigned char MOreg = 0;

	unsigned char memoryOCs[256];
	unsigned char memoryDT[256];
	for (int i = 0; i < sizeof(memoryOCs); ++i)
	{
		memoryOCs[i] = 0;
	}
	for (int i = 0; i < sizeof(memoryDT); ++i)
	{
		memoryDT[i] = 0;
	}
	if (argc != 2) {
		printf("Usage: %s <rom.bin>\n", argv[0]);
		return 1;
	}
		printf("Loading rom \"%s\"...\n", argv[1]);
		if( access( argv[1], F_OK ) == -1 ) {
			printf("Unable to load rom \"%s\"\n", argv[1]);
			return 1;
		}
		FILE *ptr;

		ptr = fopen(argv[1],"rb");

		fread(memoryOCs,1,256,ptr);
		fread(memoryDT,1,256,ptr);
		fclose(ptr);
	
	

	while (on) {
		printf ("%i:", pc);
		switch(memoryOCs[pc]) {
			case 0b00000000: //NOP
				printf("NOP:%i\n", memoryDT[pc]);
				pc++;
				break;
			case 0b00000001: //LDA
				printf ("LDA:%i\n", memoryDT[pc]);
				Areg = memoryDT[memoryDT[pc]];
				pc++;
				break;
			case 0b00000010: //LDB
				printf ("LDB:%i\n", memoryDT[pc]);
				Breg = memoryDT[memoryDT[pc]];
				pc++;
				break;
			case 0b00000011: //LDC
				printf ("LDC:%i\n", memoryDT[pc]);
				Creg = memoryDT[memoryDT[pc]];
				pc++;
				break;
			case 0b00000100: //LDM
				printf ("LDM:%i\n", memoryDT[pc]);
				MIreg = memoryDT[memoryDT[pc]];
				pc++;
				break;
			case 0b00000101: //LDO
				printf ("LDO (OUTPUT):%i\n", memoryDT[memoryDT[pc]]);
				pc++;
				break;
			case 0b00000110: //LAA
				printf ("LAA:%i\n", memoryDT[pc]);
				Areg = memoryDT[pc];
				pc++;
				break;
			case 0b00000111: //LAB
				printf ("LAB:%i\n", memoryDT[pc]);
				Breg = memoryDT[pc];
				pc++;
				break;
			case 0b00001000: //LAC
				printf ("LAC:%i\n", memoryDT[pc]);
				Creg = memoryDT[pc];
				pc++;
				break;
			case 0b00001001: //LAM
				printf ("LAM:%i\n", memoryDT[pc]);
				MIreg = memoryDT[pc];
				pc++;
				break;
			case 0b00001010: //LAO
				printf ("LAO:%i\n", memoryDT[pc]);
				MOreg = memoryDT[pc];
				pc++;
				break;
			case 0b00001011: //ADD
				printf ("ADD:%i\n", memoryDT[pc]);
				MOreg = Areg + MIreg;
				pc++;
				break;
			case 0b00001100: //SUB
				printf ("SUB:%i\n", memoryDT[pc]);
				MOreg = Areg - MIreg;
				pc++;
				break;
			case 0b00001101: //INC
				printf ("INC:%i\n", memoryDT[pc]);
				Areg = Areg + memoryDT[pc];
				pc++;
				break;
			case 0b00001110: //DEC
				printf ("DEC:%i\n", memoryDT[pc]);
				Areg = Areg - memoryDT[pc];
				pc++;
				break;
			case 0b00001111: //MOA
				printf ("MOA:%i\n", memoryDT[pc]);
				memoryDT[memoryDT[pc]] = Areg;
				pc++;
				break;
			case 0b00010000: //MOB
				printf ("MOB:%i\n", memoryDT[pc]);
				memoryDT[memoryDT[pc]] = Breg;
				pc++;
				break;
			case 0b00010001: //MOC
				printf ("MOC:%i\n", memoryDT[pc]);
				memoryDT[memoryDT[pc]] = Creg;
				pc++;
				break;
			case 0b00010010: //MOM
				printf ("MOM:%i\n", memoryDT[pc]);
				memoryDT[memoryDT[pc]] = MIreg;
				pc++;
				break;
			case 0b00010011: //MMO
				printf ("MMO:%i\n", memoryDT[pc]);
				memoryDT[memoryDT[pc]] = MOreg;
				pc++;
				break;
			case 0b00010100: //CMP
				printf ("CMP:%i\n", memoryDT[pc]);
				fle = MIreg == Areg;
				flgt = MIreg > Areg;
				fllt = MIreg < Areg;
				flgte = MIreg >= Areg;
				fllte = MIreg <= Areg;
				pc++;
				break;
			case 0b00010101: //JMP
				printf ("JMP:%i\n", memoryDT[pc]);
				pc = memoryDT[pc];
				break;
			case 0b00010110: //JME
				printf ("JME:%i\n", memoryDT[pc]);
				if (fle)
					pc = memoryDT[pc];
				else
					pc++;
				break;
			case 0b00010111: //JNE
				printf ("JNE:%i\n", memoryDT[pc]);
				if (!fle)
					pc = memoryDT[pc];
				else
					pc++;
				break;
			case 0b00011000: //JGT
				printf ("JGT:%i\n", memoryDT[pc]);
				if (flgt)
					pc = memoryDT[pc];
				else
					pc++;
				break;
			case 0b00011001: //JLT
				printf ("JLT:%i\n", memoryDT[pc]);
				if (fllt)
					pc = memoryDT[pc];
				else
					pc++;
				break;
			case 0b00011010: //GTE
				printf ("GTE:%i\n", memoryDT[pc]);
				if (flgte)
					pc = memoryDT[pc];
				else
					pc++;
				break;
			case 0b00011011: //LTE
				printf ("LTE:%i\n", memoryDT[pc]);
				if (fllte)
					pc = memoryDT[pc];
				else
					pc++;
				break;
			


			case 0b11111101: //CAL
				printf ("CAL:%i\n", memoryDT[pc]);
				retaddress = pc;
				pc = memoryDT[pc];
				break;
			case 0b11111110: //RET
				printf ("RET:%i\n", memoryDT[pc]);
				pc = retaddress;
				break;
			case 0b11111111:  //HLT
				printf ("HLT:%i\n", memoryDT[pc]);
				on = 0;
				break;
			default:
				on = 0;
				printf ("No instruction at %i\n", pc);
				break;
		}

		usleep(1000*10);
	}
	printf("CPU halted\n");
	return 0;
}