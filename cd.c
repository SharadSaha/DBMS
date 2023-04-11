// Q1.Write a program to check whether a given line in a program 
// is comment line or not (find out both the single and multiple comment line).


#include <bits/stdc++.h>
using namespace std;

void isComment(string line)
{

	if (line.size()>=2 && line[0] == '/' && line[1] == '/') {

		cout << "It is a single-line comment";
		return;
	}

	if (line.size()>=4 && line[line.size() - 2] == '*'
		&& line[line.size() - 1] == '/' && line[0] == '/' && line[1] == '*') {

		cout << "It is a multi-line comment";
		return;
	}

	cout << "It is not a comment";
}

int main()
{
	string line = "/*GeeksForGeeks GeeksForGeeks*/";

	isComment(line);

	return 0;
}

// Q2

// Identifier is one of the tokens which are used in C programming language. It is a name which is used to identify the variables, constants, functions, arrays, and also user-defined data.

// We cannot use keywords as identifiers because keywords are reserved for special use. Once declared, we can use the identifier in later program statements which refers to the associated value.

// The special kind of identifier is known as a statement label and it can be used in goto statements.
// Rules

// The rules for naming identifiers are as follows −

//     Identifier names are unique.

//     Cannot use a keyword as identifiers.

//     Identifier has to begin with a letter or underscore (_).

//     It should not contain white space.

//     Special characters are not allowed.

//     Identifiers can consist of only letters, digits, or underscore.

//     Only 31 characters are significant.

//     They are case sensitive.



// Q2. Write a program to check 
// whether a given string is keyword or not

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool isKeyword(char* str)
{
	if (!strcmp(str, "auto") || !strcmp(str, "default")
		|| !strcmp(str, "signed") || !strcmp(str, "enum")
		||!strcmp(str, "extern") || !strcmp(str, "for")
		|| !strcmp(str, "register") || !strcmp(str, "if")
		|| !strcmp(str, "else") || !strcmp(str, "int")
		|| !strcmp(str, "while") || !strcmp(str, "do")
		|| !strcmp(str, "break") || !strcmp(str, "continue")
		|| !strcmp(str, "double") || !strcmp(str, "float")
		|| !strcmp(str, "return") || !strcmp(str, "char")
		|| !strcmp(str, "case") || !strcmp(str, "const")
		|| !strcmp(str, "sizeof") || !strcmp(str, "long")
		|| !strcmp(str, "short") || !strcmp(str, "typedef")
		|| !strcmp(str, "switch") || !strcmp(str, "unsigned")
		|| !strcmp(str, "void") || !strcmp(str, "static")
		|| !strcmp(str, "struct") || !strcmp(str, "goto")
		|| !strcmp(str, "union") || !strcmp(str, "volatile"))
		return (true);
	return (false);
}

int main()
{
	isKeyword("geeks") ? printf("Yes\n")
					: printf("No\n");

	isKeyword("for") ? printf("Yes\n")
					: printf("No\n");
	return 0;
}





// Q2. Write a program to check 
// whether a given string is a valid identifier or not.

#include <bits/stdc++.h>
using namespace std;

bool isValid(string str, int n)
{

	if (!((str[0] >= 'a' && str[0] <= 'z')
		|| (str[0] >= 'A' && str[0] <= 'Z')
		|| str[0] == '_'))
		return false;

	for (int i = 1; i < str.length(); i++) {
		if (!((str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= 'A' && str[i] <= 'Z')
			|| (str[i] >= '0' && str[i] <= '9')
			|| str[i] == '_'))
			return false;
	}

	return true;
}

int main()
{
	string str = "_geeks123";
	int n = str.length();

	if (isValid(str, n))
		cout << "Valid";
	else
		cout << "Invalid";

	return 0;
}


//Q3. WAP to scan and count the no. 
// of characters, words and lines in a file

#include <stdio.h>
#include <stdlib.h>

int main()
{

    char s, path[100];
    int characters, words, lines;
    characters = words = lines = 0;

    FILE *fptr;
    printf("Enter path of file: ");
    scanf("%s", path);

    fptr = fopen(path, "r");

    if (fptr == NULL)
    {
        printf("File can't be opened\n");
        exit(EXIT_FAILURE);
    }

    s = fgetc(fptr);

    while (s != EOF)
    {

        characters++;

        if (s == '\n' || s == '\0')
            lines++;

        if (s == ' ' || s == '\t' || s == '\n' || s == '\0')
            words++;

        s = fgetc(fptr);
    }

    printf("\n");
    printf("Total characters = %d\n", characters);
    printf("Total words      = %d\n", words);
    printf("Total lines      = %d\n", lines);

    fclose(fptr);

    return 0;
}


// Q3.WAP to read names and marks and store them in another file

#include <stdio.h>
#include <stdlib.h>

int main(){
    int marks; 
    char names[50];

    FILE * fptr;
    fptr = fopen("student.txt", "w"); // creates a file automatically

    if (fptr == NULL){
        printf("File not found!");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i<3; i++){
        printf("Enter name: ");
        scanf("%s", names);

        printf("Enter marks: ");
        scanf("%d", &marks);
        
        fprintf(fptr, "\nName: %s\t Marks: %d", names, marks);
    }

    fclose(fptr);
    return 0;
}


// Q3. WAP to delete a specific line from a file

#include <stdio.h>
#include <stdlib.h>

int main(){

    char path[100], s;
    int del, line = 1;
    FILE * rptr, * wptr;

    printf("Enter path of file: ");
    scanf("%s", path);

    rptr = fopen(path, "r");
    wptr = fopen("deleted.txt", "w");

    printf("Enter line number to be deleted: ");
    scanf("%d", &del);

    s = fgetc(rptr);
    line = 1;
    while ( s != EOF)
    {   
        if (s == '\n')
            line++;
            
        if(line != del)
            putc(s, wptr);

        s = fgetc(rptr);
    }
    
    fclose(rptr);
    fclose(wptr);
    
    return 0;
}


// Q3. WAP to copy contents of one file to another

#include <stdio.h>
#include <stdlib.h>

int main(){

    char path[100], s;
    FILE * rptr, * wptr;

    printf("Enter path of file: ");
    scanf("%s", path);

    rptr = fopen(path, "r");
    wptr = fopen("copy.txt", "w");


    s = fgetc(rptr);

    while ( s != EOF)
    {   
        putc(s, wptr);
        s = fgetc(rptr);
    }
    
    fclose(rptr);
    fclose(wptr);
    
    return 0;
}


// Q3 Write a C program to detect tokens in a C program.


#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool isDelimiter(char ch)
{
	if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' ||
		ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
		ch == '<' || ch == '=' || ch == '(' || ch == ')' ||
		ch == '[' || ch == ']' || ch == '{' || ch == '}')
		return (true);
	return (false);
}

bool isOperator(char ch)
{
	if (ch == '+' || ch == '-' || ch == '*' ||
		ch == '/' || ch == '>' || ch == '<' ||
		ch == '=')
		return (true);
	return (false);
}

bool validIdentifier(char* str)
{
	if (str[0] == '0' || str[0] == '1' || str[0] == '2' ||
		str[0] == '3' || str[0] == '4' || str[0] == '5' ||
		str[0] == '6' || str[0] == '7' || str[0] == '8' ||
		str[0] == '9' || isDelimiter(str[0]) == true)
		return (false);
	return (true);
}

bool isKeyword(char* str)
{
	if (!strcmp(str, "if") || !strcmp(str, "else") ||
		!strcmp(str, "while") || !strcmp(str, "do") ||
		!strcmp(str, "break") ||
		!strcmp(str, "continue") || !strcmp(str, "int")
		|| !strcmp(str, "double") || !strcmp(str, "float")
		|| !strcmp(str, "return") || !strcmp(str, "char")
		|| !strcmp(str, "case") || !strcmp(str, "char")
		|| !strcmp(str, "sizeof") || !strcmp(str, "long")
		|| !strcmp(str, "short") || !strcmp(str, "typedef")
		|| !strcmp(str, "switch") || !strcmp(str, "unsigned")
		|| !strcmp(str, "void") || !strcmp(str, "static")
		|| !strcmp(str, "struct") || !strcmp(str, "goto"))
		return (true);
	return (false);
}

bool isInteger(char* str)
{
	int i, len = strlen(str);

	if (len == 0)
		return (false);
	for (i = 0; i < len; i++) {
		if (str[i] != '0' && str[i] != '1' && str[i] != '2'
			&& str[i] != '3' && str[i] != '4' && str[i] != '5'
			&& str[i] != '6' && str[i] != '7' && str[i] != '8'
			&& str[i] != '9' || (str[i] == '-' && i > 0))
			return (false);
	}
	return (true);
}


bool isRealNumber(char* str)
{
	int i, len = strlen(str);
	bool hasDecimal = false;

	if (len == 0)
		return (false);
	for (i = 0; i < len; i++) {
		if (str[i] != '0' && str[i] != '1' && str[i] != '2'
			&& str[i] != '3' && str[i] != '4' && str[i] != '5'
			&& str[i] != '6' && str[i] != '7' && str[i] != '8'
			&& str[i] != '9' && str[i] != '.' ||
			(str[i] == '-' && i > 0))
			return (false);
		if (str[i] == '.')
			hasDecimal = true;
	}
	return (hasDecimal);
}


char* subString(char* str, int left, int right)
{
	int i;
	char* subStr = (char*)malloc(
				sizeof(char) * (right - left + 2));

	for (i = left; i <= right; i++)
		subStr[i - left] = str[i];
	subStr[right - left + 1] = '\0';
	return (subStr);
}


void parse(char* str)
{
	int left = 0, right = 0;
	int len = strlen(str);

	while (right <= len && left <= right) {
		if (isDelimiter(str[right]) == false)
			right++;

		if (isDelimiter(str[right]) == true && left == right) {
			if (isOperator(str[right]) == true)
				printf("'%c' IS AN OPERATOR\n", str[right]);

			right++;
			left = right;
		} else if (isDelimiter(str[right]) == true && left != right
				|| (right == len && left != right)) {
			char* subStr = subString(str, left, right - 1);

			if (isKeyword(subStr) == true)
				printf("'%s' IS A KEYWORD\n", subStr);

			else if (isInteger(subStr) == true)
				printf("'%s' IS AN INTEGER\n", subStr);

			else if (isRealNumber(subStr) == true)
				printf("'%s' IS A REAL NUMBER\n", subStr);

			else if (validIdentifier(subStr) == true
					&& isDelimiter(str[right - 1]) == false)
				printf("'%s' IS A VALID IDENTIFIER\n", subStr);

			else if (validIdentifier(subStr) == false
					&& isDelimiter(str[right - 1]) == false)
				printf("'%s' IS NOT A VALID IDENTIFIER\n", subStr);
			left = right;
		}
	}
	return;
}

int main()
{
	char str[100] = "int a = b + 1c; ";

	parse(str); // calling the parse function

	return (0);
}


// Q3 WAP delete specific word from a file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1000

void removeAll(char *str, const char *toRemove);

int main()
{
    FILE *fPtr;
    FILE *fTemp;
    char path[100];

    char toRemove[100];
    char buffer[1000];

    printf("Enter path of source file: ");
    scanf("%s", path);

    printf("Enter word to remove: ");
    scanf("%s", toRemove);

    fPtr = fopen(path, "r");
    fTemp = fopen("temp.txt", "w");

    if (fPtr == NULL || fTemp == NULL)
    {
        /* Unable to open file hence exit */
        printf("\nUnable to open file.\n");
        exit(EXIT_SUCCESS);
    }

    while ((fgets(buffer, BUFFER_SIZE, fPtr)) != NULL)
    {
        // Remove all occurrence of word from current line
        removeAll(buffer, toRemove);

        // Write to temp file
        fputs(buffer, fTemp);
    }

	fclose(fPtr);
    fclose(fTemp);


    printf("\nAll occurrence of '%s' removed successfully.", toRemove);

    return 0;
}

void removeAll(char *str, const char *toRemove)
{
    int i, j, stringLen, toRemoveLen;
    int found;

    stringLen = strlen(str);        // Length of string
    toRemoveLen = strlen(toRemove); // Length of word to remove

    for (i = 0; i <= stringLen - toRemoveLen; i++)
    {

        found = 1;
        for (j = 0; j < toRemoveLen; j++)
        {
            if (str[i + j] != toRemove[j])
            {
                found = 0;
                break;
            }
        }

        if (str[i + j] != ' ' && str[i + j] != '\t' && str[i + j] != '\n' && str[i + j] != '\0')
        {
            found = 0;
        }

        if (found == 1)
        {
            for (j = i; j <= stringLen - toRemoveLen; j++)
            {
                str[j] = str[j + toRemoveLen];
            }

            stringLen = stringLen - toRemoveLen;

			i--;
        }
    }
}



// Q5.WAP to identify all types of comments

#include <stdio.h>
#include <string.h>

FILE *fp, *fp2;

void single_comment();
void block_comment();
void check_comment(char c);

void check_comment(char c)
{
    char d;
    if (c == '/')
        d = fgetc(fp);
        if (d == '*')
            block_comment();
        else if (d == '/')
            single_comment();
}

void block_comment(){
    fputc('/', fp2);
    fputc('*', fp2);
    char c, d;
    while((c = fgetc(fp))!=EOF){
        if(c == '*'){
            d = fgetc(fp);
            if(d == '/'){
                fputc('*', fp2);
                fputc('/', fp2);
                return;
            }
        }
        fputc(c, fp2);
    }

}

void single_comment(){

    char c;
    fputc('/', fp2);
    fputc('/', fp2);
    while((c = fgetc(fp)) != '\n'){
        fputc(c, fp2);
    }

    fputc('\n', fp2);
}

int main()
{

    char c;
    fp = fopen("code.txt", "r");
    fp2 = fopen("comments.txt", "w");
    while ((c = fgetc(fp)) != EOF)
    {
        check_comment(c);
    }

    fclose(fp);
    fclose(fp2);

    return 0;
}



//Q6 WAP to create a automata to accept strings over a*, a*b+, abb

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void main() {
    char s[20], c;
    int state = 0, i = 0;
    printf("Enter a string: ");
    gets(s);
    while (s[i] != '\0') {
        switch (state) {
        case 0:
            c = s[i++];
            if (c == 'a')
                state = 1;
            else if (c == 'b')
                state = 2;
            else
                state = 6;
            break;
        case 1:
            c = s[i++];
            if (c == 'a')
                state = 3;
            else if (c == 'b')
                state = 4;
            else
                state = 6;
            break;
        case 2:
            c = s[i++];
            if (c == 'a')
                state = 6;
            else if (c == 'b')
                state = 2;
            else
                state = 6;
            break;
        case 3:
            c = s[i++];
            if (c == 'a')
                state = 3;
            else if (c == 'b')
                state = 2;
            else
                state = 6;
            break;
        case 4:
            c = s[i++];
            if (c == 'a')
                state = 6;
            else if (c == 'b')
                state = 5;
            else
                state = 6;
            break;
        case 5:
            c = s[i++];
            if (c == 'a')
                state = 6;
            else if (c == 'b')
                state = 2;
            else
                state = 6;
            break;
        case 6:
            printf("%s is not recognised", s); 
            exit(0);
        }
    }
    if (state == 1 || state == 0 || state == 3)
        printf("%s is accepted under rule 'a*'", s);
    else if ((state == 2) || (state == 4))
        printf("%s is accepted under rule 'a*b+'", s);
    else if (state == 5)
        printf("%s is accepted under rule 'abb'", s);
    else 
        printf("%s is not recognised", s);

} 


//Q7 WAP for a lexical analyzer for validating operators


#include <stdio.h>
void main()
{
    char s[5];

    printf("\n Enter any operator:");
    scanf("%s", s);
    switch (s[0])
    {
    case '>':
        if (s[1] == '=')
            printf("\n Greater than or equal");
        else
            printf("\n Greater than");
        break;
    case '<':
        if (s[1] == '=')
            printf("\n Less than or equal");
        else
            printf("\nLess than");
        break;
    case '=':
        if (s[1] == '=')
            printf("\nEqual to");
        else
            printf("\nAssignment");
        break;
    case '!':
        if (s[1] == '=')
            printf("\nNot Equal\n");
        else
            printf("\n Bit Not\n");
        break;
    case '&':
        if (s[1] == '&')
            printf("\nLogical AND");
        else
            printf("\n Bitwise AND");
        break;
    case '|':
        if (s[1] == '|')
            printf("\nLogical OR");
        else
            printf("\nBitwise OR");
        break;
    case '+':
        printf("\n Addition\n");
        break;
    case '-':
        printf("\nSubstraction\n");
        break;
    case '*':
        printf("\nMultiplication\n");
        break;
    case '/':
        printf("\nDivision\n");
        break;
    case '%':
        printf("Modulus\n");
        break;
    default:
        printf("\n Not a operator\n");
    }
}



// Q9.WAP to implement shift reduce parsing

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int z = 0, i = 0, j = 0, c = 0;

char a[16], ac[20], stk[15], act[10];

void check()
{
    strcpy(ac, "REDUCE TO E -> ");

    for (z = 0; z < c; z++)
    {

        if (stk[z] == '4')
        {
            printf("%s4", ac);
            stk[z] = 'E';
            stk[z + 1] = '\0';

            printf("\n$%s\t%s$\t", stk, a);
        }
    }

    for (z = 0; z < c - 2; z++)
    {
        if (stk[z] == '2' && stk[z + 1] == 'E' &&
            stk[z + 2] == '2')
        {
            printf("%s2E2", ac);
            stk[z] = 'E';
            stk[z + 1] = '\0';
            stk[z + 2] = '\0';
            printf("\n$%s\t%s$\t", stk, a);
            i = i - 2;
        }
    }

    for (z = 0; z < c - 2; z++)
    {

        if (stk[z] == '3' && stk[z + 1] == 'E' &&
            stk[z + 2] == '3')
        {
            printf("%s3E3", ac);
            stk[z] = 'E';
            stk[z + 1] = '\0';
            stk[z + 1] = '\0';
            printf("\n$%s\t%s$\t", stk, a);
            i = i - 2;
        }
    }
    return;
}


int main()
{
    printf("GRAMMAR is -\nE->2E2 \nE->3E3 \nE->4\n");

    // a is input string
    strcpy(a, "32423");

    c = strlen(a);

    strcpy(act, "SHIFT");

    printf("\nstack \t input \t action");

    printf("\n$\t%s$\t", a);

    for (i = 0; j < c; i++, j++)
    {

        printf("%s", act);

        stk[i] = a[j];
        stk[i + 1] = '\0';

        a[j] = ' ';

        printf("\n$%s\t%s$\t", stk, a);

        check();
    }

    check();

    if (stk[0] == 'E' && stk[1] == '\0')
        printf("Accept\n");
    else
        printf("Reject\n");
}





//Q10. WAP to implement operator precedence parsing
// input string: i*(i+i)*i


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *input;
int i = 0;
char lasthandle[6], stack[50], handles[][5] = {")E(", "E*E", "E+E", "i", "E^E"};


int top = 0, l;
char prec[9][9] = {

    /*input*/

    /*stack    +    -   *   /   ^   i   (   )   $  */

    /*  + */ '>','>','<','<','<','<','<','>','>',

    /*  - */ '>','>','<','<','<','<','<','>','>',

    /*  * */ '>','>','>','>', '<', '<', '<', '>', '>',

    /*  / */ '>','>','>','>','<','<','<','>','>',

    /*  ^ */ '>','>','>','>','<','<','<','>','>',

    /*  i */ '>','>','>','>','>','e','e','>','>',

    /*  ( */ '<','<','<','<','<','<','<','>','e',

    /*  ) */ '>', '>', '>', '>', '>', 'e', 'e', '>', '>',

    /*  $ */ '<', '<', '<', '<', '<', '<', '<', '<', '>',

};

int getindex(char c)
{
    switch (c)
    {
    case '+':
        return 0;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 3;
    case '^':
        return 4;
    case 'i':
        return 5;
    case '(':
        return 6;
    case ')':
        return 7;
    case '$':
        return 8;
    }
}

int shift()
{
    stack[++top] = *(input + i++);
    stack[top + 1] = '\0';
}

int reduce()
{
    int i, len, found, t;
    for (i = 0; i < 5; i++) // selecting handles
    {
        len = strlen(handles[i]);
        if (stack[top] == handles[i][0] && top + 1 >= len)
        {
            found = 1;
            for (t = 0; t < len; t++)
            {
                if (stack[top - t] != handles[i][t])
                {
                    found = 0;
                    break;
                }
            }
            if (found == 1)
            {
                stack[top - t + 1] = 'E';
                top = top - t + 1;
                strcpy(lasthandle, handles[i]);
                stack[top + 1] = '\0';
                return 1; // successful reduction
            }
        }
    }
    return 0;
}

void dispstack()
{
    int j;
    for (j = 0; j <= top; j++)
        printf("%c", stack[j]);
}

void dispinput()
{
    int j;
    for (j = i; j < l; j++)
        printf("%c", *(input + j));
}

void main()
{
    int j;

    input = (char *)malloc(50 * sizeof(char));
    printf("\nEnter the string\n");
    scanf("%s", input);
    input = strcat(input, "$");
    l = strlen(input);
    strcpy(stack, "$");
    printf("\nSTACK\tINPUT\tACTION");
    while (i <= l)
    {
        shift();
        printf("\n");
        dispstack();
        printf("\t");
        dispinput();
        printf("\tShift");
        if (prec[getindex(stack[top])][getindex(input[i])] == '>')
        {
            while (reduce())
            {
                printf("\n");
                dispstack();
                printf("\t");
                dispinput();
                printf("\tReduced: E->%s", lasthandle);
            }
        }
    }

    if (strcmp(stack, "$E$") == 0)
        printf("\nAccepted;");
    else
        printf("\nNot Accepted;");
}





//Q11. WAP to implement recursive descent parsing
// Input String : abab$

#include <stdio.h>
#include <stdlib.h>
char l;

void match(char c)
{
    if (l == c)
        l = getchar();
    else
    {
        printf("Invalid Input\n");
        exit(0);
    }
}

void B()
{
    if (l == 'b')
    {
        match('b');
    }
    else
    {
        printf("Invalid Input\n");
        exit(0);
    }
}

void A()
{
    if (l == 'a')
    {
        match('a');
        B();
    }
    else
        return;
}

void S()
{
    A();
    A();
}

void main()
{
    char input[10];
    printf("Enter String with $ at the end\n");
    l = getchar();
    S();
    if (l == '$')
    {
        printf("\nParsing Successful\n");
    }
    else
    {
        printf("Invalid Input\n");
    }
}

