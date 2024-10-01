#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int pack4Chars2Int(char c1, char c2, char c3, char c4); // signetures
int checkEvenParity(short input);

int main(){
	char c1 = "a", c2 = "b", c3 = "c", c4 = "d";
	int sum = pack4Chars2Int(c1, c2, c3, c4);  // first function call.
	printf("pack4Chars2Int had returned %d\n", sum);
	short val = 4;
	int back = checkEvenParity(val);  // second function call.
	printf("checkEvenParity returned %d", back);  
}

int pack4Chars2Int(char c1, char c2, char c3, char c4) {
	int res = 0;  // final valuble to return.
	res |= c1;  // add c1 in to final return valuble.
	res <<= 8;  // shift final valuble 8 spaces to the left.
	res |= c2;  // add c2 in to final return valuble.
	res <<= 8;  // shift final valuble 8 spaces to the left.
	res |= c3;  // add c3 in to final return valuble.
	res <<= 8;  // shift final valuble 8 spaces to the left.
	res |= c4;  // add c4 in to final return valuble.
	return res;
}

int checkEvenParity(short input) {
	short sec_num = input;  // creat duplicate short in order to not lose the input.
	short one = 1;
	int counter = 0;  // will count amount of 1's in duplicate input.
	int check = 0;  // will recieve resault of bit check.
	for (int index = 0; index < 16; index++) {  // run 16 times (amount of bits).
		check = sec_num & one;  // check first bit.
		if (check == 1) {
			counter += 1;  // in case 1 was found raise counter by 1.
		}
		sec_num >>= 1;  // shift duplicate to the right in order for next bit to be checked.
	}
	if (counter % 2 == 1) {  // evaluate how many 1's were found.
		return 0;
	}
	return 1;
}