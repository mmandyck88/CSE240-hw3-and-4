/* *
* hw03q1 - Pointers
*
* Completion time : 15 hours
*
* @author Melissa Mandyck , Acuna code used
* @ version January 21, 2024
*/

//CSE240 Homework
// Be sure to add the standard header above.
// Melissa Mandyck
// State the IDE that you use: Visual Studio

#include <stdio.h>
#include <string.h>

#pragma warning(disable : 4996)  // compiler directive for Visual Studio only

// Read before you start:
// You are given a partially complete program. Complete the functions in order for this program to work successfully.
// All instructions are given above the required functions, please read them and follow them carefully. 
// You shoud not modify the function return types or parameters.
// You can assume that all inputs are valid. Ex: If prompted for an integer, the user will input an integer.
// You can use only the strlen() of strings.h library to check string length. Do not use any other string functions 
// because you are supposed to use pointers for this homework. 
// **** DO NOT use arrays to store or to index the characters in the string ****

// Global Macro Values. They are used to define the size of 2D array of characters
#define NUM_STRINGS 4
#define STRING_LENGTH 50

// Forward Declarations
void initializeStrings(char[NUM_STRINGS][STRING_LENGTH]);
void printStrings(char[NUM_STRINGS][STRING_LENGTH]);
void encryptStrings(char[NUM_STRINGS][STRING_LENGTH], int);
void decryptStrings(char[NUM_STRINGS][STRING_LENGTH], int);
void reverseStrings(char strings[NUM_STRINGS][STRING_LENGTH]);
char* reverseOneString(char s[STRING_LENGTH]);
int isPalindrome(char s[STRING_LENGTH]);

// Problem 1: initializeStrings (5 points)
// Use pointer p to traverse the 2D array of characters variable 'strings' (input from user in main() ) and set all characters in each
// array to a null terminator so that there is a 4 row and 50 column 2D array full of null terminators.
// The null terminator '\0' is used to denote the end of a string.
void initializeStrings(char strings[NUM_STRINGS][STRING_LENGTH])
{
	char* p = &strings[0][0];
	// enter code here
	// run a loop for each string in the array
	for (int row = 0; row < NUM_STRINGS; row++) {
		// run the loop for each character in the string
		for (int col = 0; col < STRING_LENGTH; col++) {
			// initialize the current character
			*(p + (row * STRING_LENGTH) + col) = '\0';
		}
	}
}

// Problem 2: printStrings (5 points)
// Use pointer p to traverse the 2D character array "strings" and print each string.
// See the example outputs provided in the word document. Each string should be printed on a new line.
void printStrings(char strings[NUM_STRINGS][STRING_LENGTH])
{
	char* p = &strings[0][0];
	// enter code here
	for (int row = 0; row < NUM_STRINGS; row++) {
		// run the loop for each character in the string
		for (int col = 0; col < STRING_LENGTH; col++) {
			// print the current character
			if (*(p + (row * STRING_LENGTH) + col) == '\0')
				break;
			printf("%c", *(p + (row * STRING_LENGTH) + col));
		}
		printf("\n");
	}
}

// Problem 3: reverseOneString (15 points)
// Reverse the string s by using pointer.
// Use pointer p and 'temp' char to swap 1st char with last, then 2nd char with (last-1) and so on..
// Finally return pointer p which points to start of the reversed string.
// You may declare and use more pointers if needed.
// Hint: You might want to check if your logic works with even as well as odd length string.
//       You can write test code to print out the reversed string to check if your function works. (Don't include it in final submission)
char* reverseOneString(char s[STRING_LENGTH])
{				
	char* start = s;			// pointer to start of string
	// enter code here
	char* end = s + strlen(s) - 1;
	while (start < end) {

		char temp = *start;

		*start = *end;

		*end = temp;

		start++;

		end--;

	}
	return s;
}

// Problem 4: reverseStrings (5 points)
// Reverse all the strings in 'strings[][]'
// For each string in 'strings', use the reverseOneString() to reverse it.
// You may declare and use more pointers if needed.
void reverseString(char* str) {
	int len = 0; // to calculate length
	while (str[len] != '\0')len++; // loop till we encounter \0
	// loop till half of the length of strig
	// and swap both ends
	for (int i = 0; i < len / 2; ++i) {
		char a = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = a;
	}

}

// Problem 5: encryptStrings (5 points)
// Use pointer ptr to traverse the 2D character array 'strings' and encrypt each string in 2 step as follows- 
// 1) Reverse the strings. Hint: Use 'reverseStrings()' for this step.
// 2) Shift the characters forward by the integer value of 'key'.
// If the string is "hello" and key = 2, reversing will get you "olleh" and adding key to it will result in "qnngj".
// Once the value of 'key' gets larger, you will extend past alphabetical characters and reach non-alphabetical characters. Thats ok.
// NOTE: DO NOT encrypt the null terminator character. Use the null terminator to find the end string.
//		If you could not implement reverseStrings(), skip using it in this function. You will receive partial credit.
void encryptStrings(char strings[NUM_STRINGS][STRING_LENGTH], int key)
{
	char* ptr = &strings[0][0]; // base address
	// loop till last 
	while (ptr < (char*)(&strings[NUM_STRINGS - 1][STRING_LENGTH - 1])) {
		reverseString(ptr); // reverse the string
		int idx = 0; // set index to zero
		while (ptr[idx] != '\0') { // loop till end
			ptr[idx] += key; // add the key
			idx++; // increment
		}
		// move pointer to next string
		ptr += (sizeof(char) * STRING_LENGTH);
	}

}
// Problem 6: decryptStrings (5 points)
// HINT: This should be very similiar to the encryption function defined above in encryptStrings().
// Use pointer p to traverse the 2D character array 'strings' and decrypt each string in 2 step as follows- 
// 1) Shift the characters backward by the integer value of 'key'.
// 2) Reverse the strings. Hint: Use 'reverseStrings()' for this step.
// NOTE: DO NOT decrypt the null characters.
//		If you could not implement reverseStrings(), skip using it in this function. You will receive partial credit.
void decryptStrings(char strings[NUM_STRINGS][STRING_LENGTH], int key)
{
	char* ptr = &strings[0][0]; // base address
	// loop till last 
	while (ptr < (char*)(&strings[NUM_STRINGS - 1][STRING_LENGTH - 1])) {
		reverseString(ptr); // reverse the string
		int idx = 0; // set index to zero
		while (ptr[idx] != '\0') { // loop till end
			ptr[idx] -= key; // subtract the key
			idx++; // increment
		}
		// move pointer to next string
		ptr += (sizeof(char) * STRING_LENGTH);
	}
}


// Problem 7: isPalindrome (10 points)
// Return 1 if string s is palindrome.
// Parse through the string to check if 1st char==last char, 2nd char == (last-1) char, and so on..
// Return 1 if string is palindrome. Return 0 if string is not palindrome.
// A palindrome is a sequence of characters which when reversed, is the same sequence of characters.
// Palindrome string examples: rotor, noon, madam
// Note: you may use reverseOneString() here but it is not necessary to use it. 
int isPalindrome(char s[STRING_LENGTH])
{
	char* p = s;
	char* p_end = s;

	// Move p_end to the end of the string
	while (*p_end != '\0') {
		p_end++;
	}
	p_end--; // Move it back one position to the last character

	int palindrome = 1; // Assume it's a palindrome initially

	// Check characters while p is less than or equal to p_end
	while (p <= p_end) {
		if (*p != *p_end) {
			palindrome = 0; // Not a palindrome
			break;
		}
		p++;
		p_end--;
	}

	return palindrome;
}


// You should study and understand how main() works.
// *** DO NOT modify it in any way ***
int main()
{
	char strings[NUM_STRINGS][STRING_LENGTH]; // will store four strings each with a max length of 34
	int i, key;
	char input[STRING_LENGTH];
	
	printf("CSE240 HW4: Pointers\n\n");
	initializeStrings(strings);
		
	for (i = 0; i < NUM_STRINGS; i++)
	{
		printf("Enter a string: ");				// prompt for string
		fgets(input, sizeof(input), stdin);		// store input string
		input[strlen(input) - 1] = '\0';		// convert trailing '\n' char to '\0' (null terminator)
		strcpy(strings[i], input);				// copy input to 2D strings array
	}
	
	printf("\nEnter a key value for encryption: "); // prompt for integer key
	scanf("%d", &key); 
	
	encryptStrings(strings, key);
	printf("\nEncrypted Strings:\n");
	printStrings(strings);
	decryptStrings(strings, key);
	printf("\nDecrypted Strings:\n");
	printStrings(strings);

	getchar();									// flush out newline '\n' char

	printf("\nChecking for palindrome. Enter a string: ");				// prompt for string
	fgets(input, sizeof(input), stdin);		// store input string
	input[strlen(input) - 1] = '\0';		// convert trailing '\n' char to '\0' (null terminator)

	if (isPalindrome(input))
		printf("The string is a palindrome");
	else
		printf("The string is not a palindrome");

	getchar();									// keep VS console open
	return 0;
}
