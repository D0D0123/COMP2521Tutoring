#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNAME 20
#define MAXSTUDENTS 10

typedef struct student {
	int  zid;            // 7-digit number
	char name[MAXNAME];  // names are stored *within* the struct
	int  prog;           // 4-digit number
	int  favnum;         // favourite number
} Student;
 
// return -ve if a < b, +ve if a > b, 0 if a == b
int stuCmp(const void *a, const void *b);
int stuCmp2(const void *a, const void *b);
 
int main(int argc, char *argv[]) {
	
    Student students[MAXSTUDENTS] = {
        {1234567, "John Doe",  1234,  7},
        {2345678, "Jane Smith",  2345,  8},
        {3456789, "Joe Bloggs",  3456,  8},
        {4567890, "John Doe",  4567, 10},
        {5678901, "Jane Smith",  5678, 11},
        {6789012, "Joe Bloggs",  6789, 11},
        {7890123, "John Doe",  7890, 13},
        {8901234, "Jane Smith",  8901, 14},
        {9012345, "Joe Bloggs",  9012, 15}
    };

	// sort the students[] array
    int nstudents = 9;
    // qsort(students, nstudents, sizeof(Student), stuCmp);
    qsort(students, nstudents, sizeof(Student), stuCmp2);

	// print the contents of the students[] array
	for (int i = 0; i < nstudents; i++) {
		printf("%7d %-20s %4d %d\n",
		       students[i].zid, students[i].name, students[i].prog,
		       students[i].favnum);
	}

}

int stuCmp(const void *a, const void *b) {
    Student *sa = (Student *)a;
    Student *sb = (Student *)b;
    int namecmp = strcmp(sa->name, sb->name);
    if (namecmp == 0) {
        return sa->zid - sb->zid;
    } else {
        return namecmp;
    }
}

int stuCmp2(const void *a, const void *b) {
    Student *sa = (Student *)a;
    Student *sb = (Student *)b;
    int favcmp = sa->favnum - sb->favnum;
    if (favcmp == 0) {
        return strcmp(sa->name, sb->name);
    } else {
        return favcmp;
    }
}