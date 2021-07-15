#define FILENAME "file_pessoas"

typedef struct Person{
    char name[200];
    int age;
}Person;


//API
int new_person(char * name, int age); // return identifier of new person;
int person_change_age(char* name, int age); //update by name
int person_change_age_v2(long pos, int age); // update by identifier;

// Objetivo e comparar o desempenho da 1º e 2º função