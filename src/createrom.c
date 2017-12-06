#include <stdio.h>
#include <unistd.h>
#include <string.h>

int StartsWith(const char *a, const char *b){
	if(strncmp(a, b, strlen(b)) == 0)
		return 1;
	return 0;
}
int split (const char *str, char c, char ***arr) {
	int count = 1;
	int token_len = 1;
	int i = 0;
	char *p;
	char *t;

	p = str;
	while (*p != '\0')
	{
		if (*p == c)
			count++;
		p++;
	}

	*arr = (char**) malloc(sizeof(char*) * count);
	if (*arr == NULL)
		exit(1);

	p = str;
	while (*p != '\0')
	{
		if (*p == c)
		{
			(*arr)[i] = (char*) malloc( sizeof(char) * token_len );
			if ((*arr)[i] == NULL)
				exit(1);

			token_len = 0;
			i++;
		}
		p++;
		token_len++;
	}
	(*arr)[i] = (char*) malloc( sizeof(char) * token_len );
	if ((*arr)[i] == NULL)
		exit(1);

	i = 0;
	p = str;
	t = ((*arr)[i]);
	while (*p != '\0')
	{
		if (*p != c && *p != '\0')
		{
			*t = *p;
			t++;
		}
		else
		{
			*t = '\0';
			i++;
			t = ((*arr)[i]);
		}
		p++;
	}

	return count;
}
int numbers_only(const char s[]) {
	int n = 0;
    for (int i = 0; i < sizeof(s); ++i)
    {
    	if (s[i]<'0' || s[i]>'9') n = 1;
    }

    return n;
}
int main(int argc, char *argv[]) {
	int mem = 256;
	unsigned char memoryOCs[mem];
	unsigned char memoryDT[mem];

	for (int i = 0; i < sizeof(memoryOCs); ++i)
	{
		memoryOCs[i] = 0;
	}
	for (int i = 0; i < sizeof(memoryDT); ++i)
	{
		memoryDT[i] = 0;
	}
	FILE *ptr;
	if (argc == 3) {
		printf("Loading asm file \"%s\"\n", argv[1]);
		if( access( argv[1], F_OK ) == -1 ) {
			printf("Unable to load asm file \"%s\"\n", argv[1]);
			return 1;
		}
		char str[2048];
		int memaddr = 0;
		char bfr[10];
		ptr = fopen(argv[1],"r");
		char **arr = NULL;
		int adv = 1;

		while (fgets(str, 2048, ptr) != NULL) {
			printf("Line #%i\n", memaddr+1);
			adv = 1;
			if (StartsWith(str, "NOP")) {
				memoryOCs[memaddr] = 0b00000000;
				
				
			} else if (StartsWith(str, "LDA")) {
				memoryOCs[memaddr] = 0b00000001;
				split(str, ' ', &arr);
				memoryDT[memaddr] = atoi(arr[1]);
			} else if (StartsWith(str, "LDB")) {
				memoryOCs[memaddr] = 0b00000010;
				split(str, ' ', &arr);
				memoryDT[memaddr] = atoi(arr[1]);
			} else if (StartsWith(str, "LDC")) {
				memoryOCs[memaddr] = 0b00000011;
				split(str, ' ', &arr);
				memoryDT[memaddr] = atoi(arr[1]);
			} else if (StartsWith(str, "LDM")) {
				memoryOCs[memaddr] = 0b00000100;
				split(str, ' ', &arr);
				memoryDT[memaddr] = atoi(arr[1]);
			} else if (StartsWith(str, "LDO")) {
				memoryOCs[memaddr] = 0b00000101;
				split(str, ' ', &arr);
				memoryDT[memaddr] = atoi(arr[1]);
			} else if (StartsWith(str, "LAA")) {
				memoryOCs[memaddr] = 0b00000110;
				split(str, ' ', &arr);
				memoryDT[memaddr] = atoi(arr[1]);
			} else if (StartsWith(str, "LAB")) {
				memoryOCs[memaddr] = 0b00000111;
				split(str, ' ', &arr);
				memoryDT[memaddr] = atoi(arr[1]);
			} else if (StartsWith(str, "LAC")) {
				memoryOCs[memaddr] = 0b00001000;
				split(str, ' ', &arr);
				memoryDT[memaddr] = atoi(arr[1]);
			} else if (StartsWith(str, "LAM")) {
				memoryOCs[memaddr] = 0b00001001;
				split(str, ' ', &arr);
				memoryDT[memaddr] = atoi(arr[1]);
			} else if (StartsWith(str, "LAO")) {
				memoryOCs[memaddr] = 0b00001010;
				split(str, ' ', &arr);
				memoryDT[memaddr] = atoi(arr[1]);
			} else if (StartsWith(str, "ADD")) {
				memoryOCs[memaddr] = 0b00001011;


			} else if (StartsWith(str, "SUB")) {
				memoryOCs[memaddr] = 0b00001100;


			} else if (StartsWith(str, "INC")) {
				memoryOCs[memaddr] = 0b00001101;
				split(str, ' ', &arr);
				memoryDT[memaddr] = atoi(arr[1]);
			} else if (StartsWith(str, "DEC")) {
				memoryOCs[memaddr] = 0b00001110;
				split(str, ' ', &arr);
				memoryDT[memaddr] = atoi(arr[1]);
			} else if (StartsWith(str, "MOA")) {
				memoryOCs[memaddr] = 0b00001111;
				split(str, ' ', &arr);
				memoryDT[memaddr] = atoi(arr[1]);
			} else if (StartsWith(str, "MOB")) {
				memoryOCs[memaddr] = 0b00010000;
				split(str, ' ', &arr);
				memoryDT[memaddr] = atoi(arr[1]);
			} else if (StartsWith(str, "MOC")) {
				memoryOCs[memaddr] = 0b00010001;
				split(str, ' ', &arr);
				memoryDT[memaddr] = atoi(arr[1]);
			} else if (StartsWith(str, "MOM")) {
				memoryOCs[memaddr] = 0b00010010;
				split(str, ' ', &arr);
				memoryDT[memaddr] = atoi(arr[1]);
			} else if (StartsWith(str, "MMO")) {
				memoryOCs[memaddr] = 0b00010011;
				split(str, ' ', &arr);
				memoryDT[memaddr] = atoi(arr[1]);
			} else if (StartsWith(str, "CMP")) {
				memoryOCs[memaddr] = 0b00010100;
				

			} else if (StartsWith(str, "JMP")) {
				memoryOCs[memaddr] = 0b00010101;
				split(str, ' ', &arr);
				memoryDT[memaddr] = atoi(arr[1]);
			} else if (StartsWith(str, "JME")) {
				memoryOCs[memaddr] = 0b00010110;
				split(str, ' ', &arr);
				memoryDT[memaddr] = atoi(arr[1]);
			} else if (StartsWith(str, "JNE")) {
				memoryOCs[memaddr] = 0b00010111;
				split(str, ' ', &arr);
				memoryDT[memaddr] = atoi(arr[1]);
			} else if (StartsWith(str, "JGT")) {
				memoryOCs[memaddr] = 0b00011000;
				split(str, ' ', &arr);
				memoryDT[memaddr] = atoi(arr[1]);
			} else if (StartsWith(str, "JLT")) {
				memoryOCs[memaddr] = 0b00011001;
				split(str, ' ', &arr);
				memoryDT[memaddr] = atoi(arr[1]);
			} else if (StartsWith(str, "GTE")) {
				memoryOCs[memaddr] = 0b00011010;
				split(str, ' ', &arr);
				memoryDT[memaddr] = atoi(arr[1]);
			} else if (StartsWith(str, "LTE")) {
				memoryOCs[memaddr] = 0b00011011;
				split(str, ' ', &arr);
				memoryDT[memaddr] = atoi(arr[1]);
			} else if (StartsWith(str, "CAL")) {
				memoryOCs[memaddr] = 0b11111101;
				split(str, ' ', &arr);
				memoryDT[memaddr] = atoi(arr[1]);
			} else if (StartsWith(str, "RET")) {
				memoryOCs[memaddr] = 0b11111110;
				

			} else if (StartsWith(str, "HLT")) {
				memoryOCs[memaddr] = 0b11111111;
				

			} else if (StartsWith(str, "#")) {
				adv = 0;
				

			} else if (StartsWith(str, ";")) {
				adv = 0;
				

			} else if (StartsWith(str, "\n")) {
				adv = 0;
				

			}


			else {
				split(str, ' ', &arr);
				printf("Instruction #%i (%s) Not found! Ignoring\n", memaddr+1, arr[0]);
			}
			if (adv) {
				memaddr++;
			}
		}

		fclose(ptr);

		printf("Creating memory map \"%s\"\n", argv[2]);

		ptr = fopen(argv[2],"wb");

		fwrite(memoryOCs,1,mem,ptr);
		fwrite(memoryDT,1,mem,ptr);
		fclose(ptr);
	} else {
		printf("Usage: %s <asm.s> <rom.bin>\n", argv[0]);
		return 1;
	}
	return 0;
}