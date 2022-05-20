#include "include/vector_lib.h"

int main()
{
	t_vec test;

	test = vec_init_strict(5, sizeof(char), 5);
	vec_fill(&test, V_SEP, 0, "t");   vec_print(test);
	vec_fill(&test, V_SEP, 0, "t");   vec_print(test);
	vec_fill(&test, V_SEP, 0, "t");   vec_print(test);
	return (0);
}