#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
//memcpy
//size_t为无符号数
struct {
	char name[40];
	int age;
} person, person_copy;
void * my_memcpy(void * dest,const void * source, size_t num){        //dest 和 source 的内容不可以重叠
	assert(dest);
	assert(source);
	char * dest1 = (char*)dest;
	char * source1 = (char*)source;
	while (num){
		*dest1++ = *source1++;
		num--;
	}
	return dest;
}
int main6(){
	char myname[] = "Pierre de Fermat";

	///* using memcpy to copy string: */
	//memcpy(person.name, myname, strlen(myname) + 1);
	//person.age = 46;

	///* using memcpy to copy structure: */
	//memcpy(&person_copy, &person, sizeof(person));

	//printf("person_copy: %s, %d \n", person_copy.name, person_copy.age);

	my_memcpy(person.name, myname, strlen(myname) + 1);
	person.age = 46;

	/* using memcpy to copy structure: */
	my_memcpy(&person_copy, &person, sizeof(person));

	printf("person_copy: %s, %d \n", person_copy.name, person_copy.age);
	system("pause");
	return 0;
}