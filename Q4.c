////#define _CRT_SECURE_NO_WARNINGS
////#define _CRTDBG_MAP_ALLOC
////#include <crtdbg.h> //uncomment this block to check for heap memory allocation leaks.
////// Read https://docs.microsoft.com/en-us/visualstudio/debugger/finding-memory-leaks-using-the-crt-library?view=vs-2019
////#include <stdlib.h>
////#include <stdio.h>
////#include <string.h>
////#include <assert.h>
////
////typedef struct StudentCourseGrade{
////	char courseName[35];
////	int grade;
////}StudentCourseGrade;
////
////typedef struct Student{
////	char name[35];
////	StudentCourseGrade* grades; //dynamic array of courses
////	int numberOfCourses;
////}Student;
////
////
//////Part A
////void countStudentsAndCourses(const char* fileName, int** coursesPerStudent, int* numberOfStudents);
////int countPipes(const char* lineBuffer, int maxCount);
////char*** makeStudentArrayFromFile(const char* fileName, int** coursesPerStudent, int* numberOfStudents);
////void printStudentArray(const char* const* const* students, const int* coursesPerStudent, int numberOfStudents);
////void factorGivenCourse(char** const* students, const int* coursesPerStudent, int numberOfStudents, const char* courseName, int factor);
////void studentsToFile(char*** students, int* coursesPerStudent, int numberOfStudents);
////
//////Part B
////Student* transformStudentArray(char*** students, const int* coursesPerStudent, int numberOfStudents);
////void writeToBinFile(const char* fileName, Student* students, int numberOfStudents);
////Student* readFromBinFile(const char* fileName);
////
////int main(){
////	//Part A
////	int* coursesPerStudent = NULL;
////	int numberOfStudents = 0;
////	char*** students = makeStudentArrayFromFile("studentList.txt", &coursesPerStudent, &numberOfStudents);
////	//factorGivenCourse(students, coursesPerStudent, numberOfStudents, "Advanced Topics in C", +5);
////	printStudentArray(students, coursesPerStudent, numberOfStudents);
////	//studentsToFile(students, coursesPerStudent, numberOfStudents); //this frees all memory. Part B fails if this line runs. uncomment for testing (and comment out Part B)
////
////	//Part B
////	Student* transformedStudents = transformStudentArray(students, coursesPerStudent, numberOfStudents);
////	writeToBinFile("students.bin", transformedStudents, numberOfStudents);
////	Student* testReadStudents = readFromBinFile("students.bin");
////
////	//add code to free all arrays of struct Student
////
////
////	/*_CrtDumpMemoryLeaks();*/ //uncomment this block to check for heap memory allocation leaks.
////	// Read https://docs.microsoft.com/en-us/visualstudio/debugger/finding-memory-leaks-using-the-crt-library?view=vs-2019
////
////	return 0;
////}
////
////void countStudentsAndCourses(const char* fileName, int** coursesPerStudent, int* numberOfStudents){
////	FILE* s_info = fopen("studentList.txt", "r");  // opens file.
////	assert(s_info);  // check that the file was opened properly.
////	int j = 0;
////	int amountOfStudents = 0;
////	int amountOfCourses;
////	char* sentence = "\0";///////////////////////////////////// ask erez!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
////	fgets(sentence, 1023, s_info);
////	int check = countPipes(sentence, 1023);
////	if (check == -1) {  // check that file actually has the neccesary information.
////		printf("file is blank (empty)");
////		return;
////	}
////	rewind(s_info);  // reposintions sentence back to the begining of the file.
////	do{
////		fgets(sentence, 1023, s_info);  // places entire line in to sentence parameter.
////		amountOfStudents++;
////	}while (sentence != NULL);  // counts amount of lines in file which is equal to the amount of students.
////	*coursesPerStudent = (int*)malloc(amountOfStudents * sizeof(int));
////	if (!coursesPerStudent) {  // check allocation success.
////		printf("allocation of coursesPerStudent was unsuccessful");
////		return;
////	}
////	int g = 0;  // will be used as index in coursesPerStudent array.
////	rewind(s_info);  // reposintions sentence back to the begining of the file.
////	do{
////		fgets(sentence, 1023, s_info);  // sentence will become a string of every line in the file.
////		if (sentence == NULL) {  // check sentence before progressing to the rest of the loop.
////			break;
////		}
////		amountOfCourses = countPipes(sentence, 1023);  // call courses counter for each line.
////		coursesPerStudent[g] = amountOfCourses;  // place amount of courses counted in index g of coursesPerStudent array.
////		g++;
////	} while (sentence != NULL);  // will run until the last line.
////	fclose(s_info);
////}/////////////////////////////////////////////////////////// i haven't checked it.
////
////int countPipes(const char* lineBuffer, int maxCount){  // count amount of "|" in lineBuffer.
////	if (lineBuffer == NULL || maxCount < 0) {  // in case lineBuffer is blank.
////		return -1;
////	}
////	int i = 0;
////	int counter = 0;
////	while (i <= maxCount || lineBuffer[i] != "\0") {
////		if (lineBuffer[i] == "|") {  // if pipe "|" is found.
////			counter++;
////		}
////		i++;
////	}
////	return counter;
////}/////////////////////////////////////////////////////////// i haven't checked it.
////
////char*** makeStudentArrayFromFile(const char* fileName, int** coursesPerStudent, int* numberOfStudents){
////	int j = 0;
////	int amountOfStudents = 1;
////	int amountOfCourses = 0;
////	char* sentence = NULL;  ///////////////////////////// ask erez!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
////	int last = 0;
////	countStudentsAndCourses(fileName, coursesPerStudent, numberOfStudents);  // returns numder of students and courses.
////	FILE* s_info;
////	s_info = fopen("fileName", "r");  // opens file.
////	assert(s_info);  // check that the file was opened properly.
////	char*** Students = (char***)malloc(amountOfStudents * sizeof(char**));  // allocating memory for array.
////	for (int i = 0; i < amountOfStudents; i++) {
////		char** eachstudent = (char**)malloc(1 + *coursesPerStudent[i] * 2 * sizeof(char*));
////		for (int t = 0; t < 1 + *coursesPerStudent[t] * 2; t++) {
////			char* student_sem = (char*)malloc(30 * sizeof(char));
////			fgets(sentence, 1023, s_info);  // sentence will become a string of every line in the file.
////			do {
////				if (sentence[j] == "|" || sentence[j] == ",") {
////					break;
////				}
////			} while (sentence[j] != "\n");
////			for (int r = 0; r < (j - 1) - last; r++) {
////				student_sem[r] = sentence[last];
////			}
////			last += 2;
////			eachstudent[t] = student_sem;
////		}
////		Students[i] = eachstudent;
////	}
////	fclose(s_info);
////}
////
//////void factorGivenCourse(char** const* students, const int* coursesPerStudent, int numberOfStudents, const char* courseName, int factor){
//////	int y = 0;
//////	int r = 0;
//////	int s = 1;  // equals 1 in order to not check the name of the student when searching for the name of the course. 
//////	if (factor > 20 || factor < -20) {
//////		return;
//////	}
//////	while (y < numberOfStudents) {  // will run on amount students.
//////		while (s < coursesPerStudent[r] * 2 + 1) {  // will run on each students list of courses
//////			if (strchar(students[y][s], courseName)) {  // if name of course matches the course we are searching for.
//////				s += 1;  // progress to the next slot in the list where the grade is.
//////				int grade = atoi(students[y][s]);  // define grade as the integer of the grade that needs changing. 
//////				grade += factor;  // add factor to the grade of the course. 
//////				if (grade > 100) {  // check if grade has past the top limit. 
//////					grade = 100;
//////				}
//////				if (grade < 0) {  // check if grade has past the bottom limit.
//////					grade = 0;
//////				}
//////				char grade = atoi(grade);  // turn grade back in to a char.
//////				students[y][s] = grade;
//////				break;  // if course was found, there is no point in checking the same student again.
//////			}
//////			s++;
//////		}
//////		r++;
//////		y++;
//////	}
//////}  ///////////////////////////////// i haven't checked.
////
////void printStudentArray(const char* const* const* students, const int* coursesPerStudent, int numberOfStudents)
////{
////	for (int i = 0; i < numberOfStudents; i++)
////	{
////		printf("name: %s\n*********\n", students[i][0]);
////		for (int j = 1; j <= 2 * coursesPerStudent[i]; j += 2)
////		{
////			printf("course: %s\n", students[i][j]);
////			printf("grade: %s\n", students[i][j + 1]);
////		}
////		printf("\n");
////	}
////}
////
////void studentsToFile(char*** students, int* coursesPerStudent, int numberOfStudents)
////{
////	//add code here
////}
////
////void writeToBinFile(const char* fileName, Student* students, int numberOfStudents)
////{
////	FILE* binfile;
////	binfile = fopen("filename", "w");
////	assert(binfile);
////	fprintf("binfile", "the amount of student is: %d\t", numberOfStudents);
////	fwrite(students, sizeof(students), numberOfStudents, binfile);
////}
////
////Student* readFromBinFile(const char* fileName)
////{
////	//add code here
////}
////
////Student* transformStudentArray(char*** students, const int* coursesPerStudent, int numberOfStudents){
////	Student* studentArr = (Student*)malloc(sizeof(Student*) * numberOfStudents);
////	if (!studentArr) {
////		printf("allocation failed");
////		return;
////	}
////	for (int m = 0; m < numberOfStudents; m++) {
////		for (int q = 0; q < coursesPerStudent[m] * 2 + 1; q++) {
////			if (q == 0) {
////				studentArr[m].name == students[m][q];
////			}
////			else {
////				if (q % 2 == 1) {
////					studentArr[m].grades->grade = students[m][q];
////
////				}
////				else {
////					*studentArr[m].grades->courseName = students[m][q];
////				}
////			}
////			studentArr->numberOfCourses = coursesPerStudent[m];
////		}
////	}
////	return studentArr;
////}//////////////////////////////// I haven't checked it.
//
//
//
//
//
//
//
//#define _CRT_SECURE_NO_WARNINGS
//#define _CRTDBG_MAP_ALLOC
//#include <stdlib.h>
//#include <crtdbg.h> //uncomment this block to check for heap memory allocation leaks.
//// Read https://docs.microsoft.com/en-us/visualstudio/debugger/finding-memory-leaks-using-the-crt-library?view=vs-2019
//#include <stdio.h>
//#include <string.h>
//#include <assert.h>
//#define MAX 1023
//
//typedef struct StudentCourseGrade
//{
//	char courseName[35];
//	int grade;
//}StudentCourseGrade;
//
//typedef struct Student
//{
//	char name[35];
//	StudentCourseGrade* grades; //dynamic array of courses
//	int numberOfCourses;
//}Student;
//
//
////Part A
//void countStudentsAndCourses(const char* fileName, int** coursesPerStudent, int* numberOfStudents);
//int countPipes(const char* lineBuffer, int maxCount);
//char** makeStudentArrayFromFile(const char fileName, int** coursesPerStudent, int* numberOfStudents);
//void printStudentArray(const char* const* const* students, const int* coursesPerStudent, int numberOfStudents);
//void factorGivenCourse(char** const* students, const int* coursesPerStudent, int numberOfStudents, const char* courseName, int factor);
//void studentsToFile(char** students, int coursesPerStudent, int numberOfStudents);
//
////Part B
//Student* transformStudentArray(char** students, const int coursesPerStudent, int numberOfStudents);
//void writeToBinFile(const char* fileName, Student* students, int numberOfStudents);
//Student* readFromBinFile(const char* fileName);
//
//int main()
//{
//	//Part A
//	int* coursesPerStudent = NULL;
//	int numberOfStudents = 0;
//	countStudentsAndCourses("studentList.txt", &coursesPerStudent, &numberOfStudents);
//	char*** students = makeStudentArrayFromFile("studentList.txt", &coursesPerStudent, &numberOfStudents);
//	printStudentArray(students, coursesPerStudent, numberOfStudents);
//	factorGivenCourse(students, coursesPerStudent, numberOfStudents, "Advanced Topics in C", +5);
//	printStudentArray(students, coursesPerStudent, numberOfStudents);
//	//studentsToFile(students, coursesPerStudent, numberOfStudents); //this frees all memory. Part B fails if this line runs. uncomment for testing (and comment out Part B)
//
//	//Part B
//	Student* transformedStudents = transformStudentArray(students, coursesPerStudent, numberOfStudents);
//	writeToBinFile("students.bin", transformedStudents, numberOfStudents);
//	Student* testReadStudents = readFromBinFile("students.bin");
//
//	//add code to free all arrays of struct Student
//
//
//	 _CrtDumpMemoryLeaks(); //uncomment this block to(t == *(numberOfStudents)-1 check for heap memory allocation leaks.
//	// Read https://docs.microsoft.com/en-us/visualstudio/debugger/finding-memory-leaks-using-the-crt-library?view=vs-2019
//
//		return 0;
//}
//
//void countStudentsAndCourses(const char* fileName, int** coursesPerStudent, int* numberOfStudents)
//{
//	int i = 0, temp2 = 0, temp = 1;
//	FILE* s_info;
//	s_info = fopen("studentsList.txt", "r");
//	assert(s_info);
//	*(numberOfStudents) = 1; //if the file is not empty, count the first student
//	while (temp != -1) {
//		temp = fgetc(s_info);
//		if (temp == '\n') {// Every '\n' add another student
//			*(numberOfStudents) += 1;
//		}
//	}
//	int* temp1 = (int*)malloc(sizeof(int) * (*(numberOfStudents)));
//	if (temp1 == NULL)
//		printf("Allocation failed");
//	temp = 1;
//	i = 0;
//	int t = 0;
//	rewind(s_info); // saman to start
//	while (t < *(numberOfStudents)) {
//		temp = fgetc(s_info);
//		if (temp == '|') // count pipes
//			temp2 += 1;
//		if (temp == '\n' || temp == EOF && t == *(numberOfStudents)-1) {
//			t++;
//			temp1[i] = (int*)malloc(sizeof(int));
//			if (temp1[i] == NULL)
//				printf("allocation failed");
//			temp1[i] = temp2;
//			coursesPerStudent[i] = (temp1 + i); // make the array by value
//			i++;
//			temp2 = 0;
//
//		}
//
//	}
//	fclose(s_info);
//}
//
//
//
//
//
//int countPipes(const char* lineBuffer, int maxCount)
//{
//	if (lineBuffer == NULL)
//		return -1;
//	if (maxCount <= 0)
//		return 0;
//	int numOfPipes = 0;
//	int i = 0;
//	while (lineBuffer[i] != 0) {
//		if (lineBuffer[i] == '|')
//			numOfPipes++;
//		i++;
//	}
//	return numOfPipes;
//}
//
//char** makeStudentArrayFromFile(const char fileName, int** coursesPerStudent, int* numberOfStudents)
//{
//	FILE* s_info;
//	s_info = fopen("studentsList.txt", "r");
//	countStudentsAndCourses(fileName, coursesPerStudent, numberOfStudents); // get the values of the textfile
//	char** students = (char*)malloc(sizeof(char*) * *(numberOfStudents)); // memory allocation for students
//	if (students == NULL) {
//		printf("Allocation failed");
//	}
//	for (int i = 0; i < *(numberOfStudents); i++) { // memory allocation for name,courses and grades
//		students[i] = (char*)malloc((((sizeof(char) * 2) * (*(numberOfStudents)))) + 1);
//		if (students[i] == NULL) {
//			printf("Allocation failed");
//		}
//	}
//	char str[MAX];
//	char* token = str;
//	int LengthOfToken, i = 0, j = 0;
//	while (!feof(s_info)) {
//		fgets(str, MAX, s_info); //get the first line from the text
//		token = strtok(str, "|,"); // get the first word in first line in text (name)
//		while (token != NULL) {
//			LengthOfToken = strlen(token); // count str size for memory allocation
//			*(students[i] + j) = (char)malloc((LengthOfToken * sizeof(char)) + 1);
//			if (*(students[i] + j) == NULL) {
//				printf("Allocation failed");
//			}
//			strcpy(*(students[i] + j), token);
//			j++;
//			token = strtok(NULL, "\n|,"); // keep on line to get all the grades+courses
//		}
//		j = 0;
//		i++;
//	}
//	fclose(s_info);
//	return students;
//}
//
//
//void factorGivenCourse(char** const* students, const int* coursesPerStudent, int numberOfStudents, const char* courseName, int factor)
//{
//	int y = 0;
//	int r = 0;
//	int s = 1;  // equals 1 in order to not check the name of the student when searching for the name of the course. 
//	if (factor > 20 || factor < -20) {
//		return;
//	}
//	while (y < numberOfStudents) {  // will run on amount students.
//		while ((s < coursesPerStudent[r] * 2) + 1) {  // will run on each students list of courses
//			if (strcmp(*(students[y] + s), courseName) == 0) {  // if name of course matches the course we are searching for.
//				s += 1;  // progress to the next slot in the list where the grade is.
//				int grade = atoi(*(students[y] + s + 1));  // define grade as the integer of the grade that needs changing. 
//				grade += factor;  // add factor to the grade of the course. 
//				if (grade > 100) {  // check if grade has past the top limit. 
//					grade = 100;
//				}
//				if (grade < 0) {  // check if grade has past the bottom limit.
//					grade = 0;
//				}
//				grade = atoi(grade);  // turn grade back in to a char.
//				*(students[y] + s) = grade;
//				break;  // if course was found, there is no point in checking the same student again.
//			}
//			s++;
//		}
//		r++;
//		y++;
//	}
//
//}
//
//void printStudentArray(const char* const* const* students, const int* coursesPerStudent, int numberOfStudents)
//{
//	for (int i = 0; i < numberOfStudents; i++)
//	{
//		printf("name: %s\n*****\n", students[i][0]);
//		for (int j = 1; j <= 2 * coursesPerStudent[i]; j += 2)
//		{
//			printf("course: %s\n", students[i][j]);
//			printf("grade: %s\n", students[i][j + 1]);
//		}
//		printf("\n");
//	}
//}
//
//void studentsToFile(char** students, int coursesPerStudent, int numberOfStudents)
//{
//	//add code here
//}
//
//void writeToBinFile(const char* fileName, Student* students, int numberOfStudents)
//{
//	//add code here
//}
//
//Student* readFromBinFile(const char* fileName)
//{
//	//add code here
//}
//
//Student* transformStudentArray(char** students, const int coursesPerStudent, int numberOfStudents)
//{
//	//add code here
//}
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC
//#include <crtdbg.h>
// Read https://docs.microsoft.com/en-us/visualstudio/debugger/finding-memory-leaks-using-the-crt-library?view=vs-2019
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <crtdbg.h>
#define MAX 1023

typedef struct StudentCourseGrade
{
	char courseName[35];
	int grade;
}StudentCourseGrade;

typedef struct Student
{
	char name[35];
	StudentCourseGrade* grades; //dynamic array of courses
	int numberOfCourses;
}Student;


//Part A
void countStudentsAndCourses(const char* fileName, int** coursesPerStudent, int* numberOfStudents);
int countPipes(const char* lineBuffer, int maxCount);
char** makeStudentArrayFromFile(const char fileName, int** coursesPerStudent, int* numberOfStudents);
void printStudentArray(const char* const* const* students, const int* coursesPerStudent, int numberOfStudents);
void factorGivenCourse(char** const* students, const int* coursesPerStudent, int numberOfStudents, const char* courseName, int factor);
void studentsToFile(char** students, int coursesPerStudent, int numberOfStudents);

//Part B
Student* transformStudentArray(char** students, const int coursesPerStudent, int numberOfStudents);
Student* readFromBinFile(const char* fileName);
void writeToBinFile(const char* fileName, Student* students, int numberOfStudents);


int main()
{
	//Part A
	int* coursesPerStudent = NULL;
	int numberOfStudents = 0;
	countStudentsAndCourses("studentList.txt", &coursesPerStudent, &numberOfStudents);
	char*** students = makeStudentArrayFromFile("studentList.txt", &coursesPerStudent, &numberOfStudents);
	printStudentArray(students, coursesPerStudent, numberOfStudents);
	//factorGivenCourse(students, coursesPerStudent, numberOfStudents, "Discrete Mathematics", +10);
	//printStudentArray(students, coursesPerStudent, numberOfStudents);
	//studentsToFile(students, coursesPerStudent, numberOfStudents); ///this frees all memory. Part B fails if this line runs. uncomment for testing (and comment out Part B)

	//Part B
	Student* transformedStudents = transformStudentArray(students, coursesPerStudent, numberOfStudents);
	writeToBinFile("studentsWRITE.bin", transformedStudents, numberOfStudents);
	Student* testReadStudents = readFromBinFile("studentsWRITE.bin");





	//add code to free all arrays of struct Student


	//_CrtDumpMemoryLeaks(); //uncomment this block to(t == *(numberOfStudents)-1 check for heap memory allocation leaks.
	// Read https://docs.microsoft.com/en-us/visualstudio/debugger/finding-memory-leaks-using-the-crt-library?view=vs-2019

	return 0;
}

void countStudentsAndCourses(const char* fileName, int** coursesPerStudent, int* numberOfStudents)
{
	int i = 0, temp2 = 0, temp = 1;
	FILE* s_info;
	s_info = fopen("studentList.txt", "r");
	if (s_info == NULL)
		printf("fopen failed");
	*(numberOfStudents) = 1; //if the file is not empty, count the first student
	while (temp != -1) {
		temp = fgetc(s_info);
		if (temp == '\n') {// Every '\n' add another student
			*(numberOfStudents) += 1;
		}
	}
	int* temp1 = (int*)malloc(sizeof(int) * (*(numberOfStudents)));
	if (temp1 == NULL)
		printf("Allocation failed");
	temp = 1;
	i = 0;
	int t = 0;
	rewind(s_info); // saman to start
	while (t < *(numberOfStudents)) {
		temp = fgetc(s_info);
		if (temp == '|') // count pipes
			temp2 += 1;
		if (temp == '\n' || temp == EOF && t == *(numberOfStudents)-1) {
			t++;
			temp1[i] = (int*)malloc(sizeof(int));
			if (temp1[i] == NULL)
				printf("allocation failed");
			temp1[i] = temp2;
			coursesPerStudent[i] = (temp1 + i); // make the array by value
			i++;
			temp2 = 0;

		}

	}
	fclose(s_info);
}





int countPipes(const char* lineBuffer, int maxCount)
{
	if (lineBuffer == NULL)
		return -1;
	if (maxCount <= 0)
		return 0;
	int numOfPipes = 0;
	int i = 0;
	while (lineBuffer[i] != 0) {
		if (lineBuffer[i] == '|')
			numOfPipes++;
		i++;
	}
	return numOfPipes;
}

char** makeStudentArrayFromFile(const char fileName, int** coursesPerStudent, int* numberOfStudents)
{
	FILE* s_info;
	s_info = fopen("studentList.txt", "r");
	countStudentsAndCourses(fileName, coursesPerStudent, numberOfStudents); // get the values of the textfile
	char** students = (char*)malloc(sizeof(char*) * *(numberOfStudents)); // memory allocation for students
	if (students == NULL) {
		printf("Allocation failed");
	}
	for (int i = 0; i < *(numberOfStudents); i++) { // memory allocation for name,courses and grades
		students[i] = (char*)malloc((((sizeof(char) * 2) * (*(numberOfStudents)))) + 1);
		if (students[i] == NULL) {
			printf("Allocation failed");
		}
	}
	char str[MAX];
	char* token = str;
	int LengthOfToken, i = 0, j = 0;
	while (!feof(s_info)) {
		fgets(str, MAX, s_info); //get the first line from the text
		token = strtok(str, "|,"); // get the first word in first line in text (name)
		while (token != NULL) {
			LengthOfToken = strlen(token); // count str size for memory allocation
			*(students[i] + j) = (char)malloc((LengthOfToken * sizeof(char)) + 1);
			if (*(students[i] + j) == NULL) {
				printf("Allocation failed");
			}
			strcpy(*(students[i] + j), token);
			j++;
			token = strtok(NULL, "\n|,"); // keep on line to get all the grades+courses
		}
		j = 0;
		i++;
	}
	fclose(s_info);
	return students;
}


void factorGivenCourse(char** const* students, const int* coursesPerStudent, int numberOfStudents, const char* courseName, int factor)
{
	char eden[3];
	int y = 0;
	int r = 0;
	int s = 1;  // equals 1 in order to not check the name of the student when searching for the name of the course. 
	if (factor > 20 || factor < -20) {
		return;
	}
	while (y < numberOfStudents) {  // will run on amount students.
		while (s < coursesPerStudent[r] * 2 + 1) {  // will run on each students list of courses
			if (strcmp(*(students[y] + s), courseName) == 0) {  // if name of course matches the course we are searching for.
				s += 1;  // progress to the next slot in the list where the grade is.
				int grade = atoi(*(students[y] + s));  // define grade as the integer of the grade that needs changing. 
				grade += factor;  // add factor to the grade of the course. 
				if (grade > 100) {  // check if grade has past the top limit. 
					grade = 100;
				}
				if (grade < 0) {  // check if grade has past the bottom limit.
					grade = 0;
				}
				_itoa(grade, eden, 10);  // turn grade back in to a char.
				students[y][s] = eden;
				break;  // if course was found, there is no point in checking the same student again.
			}
			s++;
		}
		r++;
		y++;
		s = 0;
	}

}

void printStudentArray(const char* const* const* students, const int* coursesPerStudent, int numberOfStudents)
{
	for (int i = 0; i < numberOfStudents; i++)
	{
		printf("name: %s\n*****\n", students[i][0]);
		for (int j = 1; j <= 2 * coursesPerStudent[i]; j += 2)
		{
			printf("course: %s\n", students[i][j]);
			printf("grade: %s\n", students[i][j + 1]);
		}
		printf("\n");
	}
}

void studentsToFile(char** students, int coursesPerStudent, int numberOfStudents)
{
	FILE* s_info;
	s_info = fopen("studentList1.txt", "w+");
	for (int i = 0; i < numberOfStudents; i++) {
		for (int j = 0; j < coursesPerStudent[i] * 2 + 1; j++) {
			fputs(students[i][j], s_info); // print student name, courses and grades by order
			fputc('|', s_info); // print | after every element
		}
		fputc('\n', s_info); // print \n after every student
	}
	fclose(s_info); // update new textfile
	free(students);
}

void writeToBinFile(const char* fileName, Student* students, int numberOfStudents)
{
	FILE* s_info;
	s_info = fopen("studentsWRITE.bin", "wb");
	fwrite(&numberOfStudents, sizeof(int), 1, s_info);
	for (int i = 0; i < numberOfStudents; i++) {
		fwrite(students[i].name, sizeof(char) * 10, 1, s_info);
		fwrite(&students[i].numberOfCourses, sizeof(int), 1, s_info);
		int tempo = students[i].numberOfCourses;
		for (int j = 0; j < students[i].numberOfCourses; j++) {
			//fwrite(students[i].grades[j].courseName, sizeof(char) * 35, 1, s_info);
			//fwrite(&students[i].grades[j].grade, sizeof(int) , 1, s_info);
			fwrite(&students[i].grades[j], sizeof(StudentCourseGrade), 1, s_info);
		}
	}



	fclose(s_info);
}

Student* readFromBinFile(const char* fileName)
{
	FILE* s_info;
	s_info = fopen("students.bin", "rb");
	if (s_info == NULL) {
		printf("allocation failed");
		return -1;
	}
	int StudentNumber;
	int CoursesNumber;
	fread(&StudentNumber, sizeof(int), 1, s_info);
	Student* stu = (Student*)malloc(sizeof(Student) * StudentNumber); // memory allocation for stu array
	if (stu == NULL) {
		printf("allocation failed");
		return -1;
	}
	for (int i = 0; i < StudentNumber; i++) {
		fread(stu[i].name, sizeof(char) * 35, 1, s_info); // read name of student
		fread(&stu[i].numberOfCourses, sizeof(int), 1, s_info); // read number of courses per student
		stu[i].grades = (StudentCourseGrade*)malloc(sizeof(StudentCourseGrade) * stu[i].numberOfCourses);
		// memory allocation for grades struct
		for (int j = 0; j < stu[i].numberOfCourses; j++) {
			fread(&(stu[i].grades[j]), sizeof(StudentCourseGrade), 1, s_info); // insert course and grade

		}


	}
	fclose(s_info);
	return stu;
}

Student* transformStudentArray(char** students, const int coursesPerStudent, int numberOfStudents)
{
	Student* stu = (Student*)malloc(numberOfStudents * sizeof(Student)); //memo allocation
	if (stu == NULL) {
		printf("Allocation failed");
		return -1;
	}
	for (int i = 0; i < numberOfStudents; i++) { // put the names by order in struct
		strcpy(stu[i].name, students[i][0]); // insert student name
		stu[i].numberOfCourses = *(coursesPerStudent[i]); // insert number of courses per student
		// memory allocation for grades (grades+courses)
		stu[i].grades = (StudentCourseGrade*)malloc(*(coursesPerStudent[i]) * 2 * sizeof(StudentCourseGrade) + 1);
		if (stu[i].grades == NULL) {
			printf("allocation failed");
			return -1;
		}
		for (int j = 1, t = 2, p = 0; j < (coursesPerStudent[i]) * 2; j += 2, t += 2, p++) { // j for courses, t for grades
			strcpy(stu[i].grades[p].courseName, students[i][j]); // insert course name
			stu[i].grades[p].grade = atoi(students[i][t]); // insert grades
		}

	}
	return stu;
}