#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct Person {
    char name[200];
    int age;
}Person;

int main(int argc, char *argv[]){
    int fd = open("pessoas.bin", O_CREAT | O_APPEND | O_RDWR, 0644);

    Person person1;
    strcpy(person1.name, "Maria Mourinho");
    person1.age = 50;

    printf("person1.name: %s\n", person1.name);
    printf("person1.age: %d\n", person1.age);

    write(fd,&person1, sizeof(Person));

    //Solution for being able to read from fd

    //  :. Back to position 0.
    lseek(fd,0,SEEK_SET);

    Person person1_read;

    if(read(fd, &person1_read, sizeof(Person)) > 0){
        printf("person1.name: %s\n", person1.name);
        printf("person1.age: %d\n", person1.age);
    }

    return 0;
}