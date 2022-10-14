/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:55:17 by awillems          #+#    #+#             */
/*   Updated: 2022/10/14 11:33:22 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_lib.h"
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

void check(char *msg, t_vec *vec, void *ptr, char *result, size_t expected_len)
{
	if (expected_len == 0)
		expected_len = strlen(result);
	if (ptr == vec && (((!result || !vec->buffer) && result == vec->buffer) || (expected_len == vec->len && strcmp(result, vec->buffer) == 0)))
		printf("[\e[0;32mV\e[0m] %s\n", msg);
	else
		printf("[\e[0;31mX\e[0m] %s    result: '%s'    expected: '%s'\n", msg, vec->buffer, result);
	v_clear(vec);
}

// TEST DEFAULT
void test1(void)
{
	t_vec	vec = v_init_r(sizeof(int), NULL, NULL, 4);
	t_vec	*ptr = &vec;

	int x = 1;
	int y = 2;

	v_add(ptr, MULTI, 2, &x, &y);
	v_add(ptr, MULTI, 3, &x, &y, &x);

	for (size_t i = 0; i < vec.len; i++)
		printf("%d ", *(int *) v_get(ptr, i));
	printf("\n");

	x = 5;
	y = 6;
	v_insert(ptr, 2, MULTI, 2, &x, &y);
	v_print(ptr);
	
	for (size_t i = 0; i < vec.len; i++)
		printf("%d ", *(int *) v_get(ptr, i));
	printf("\n");

	printf("%zu %zu\n", vec.len, vec.alloc_len);

	v_delete(ptr);
}

// TEST ADD
void test2(void)
{
	t_vec	vec = v_init_r(sizeof(char), NULL, NULL, 4);
	t_vec	*ptr = &vec;

	check("add %", ptr, v_add(ptr, STRING, "%%", 0),			"%"				, 0);
	check("add %", ptr, v_add(ptr, STRING, "[%%]", 0),			"[%]"			, 0);

	check("add c", ptr, v_add(ptr, STRING, "%c", 0),			""				, 1);
	check("add c", ptr, v_add(ptr, STRING, "%c", 'c'),			"c"				, 0);
	check("add c", ptr, v_add(ptr, STRING, "%c", '\\'),			"\\"			, 0);
	check("add c", ptr, v_add(ptr, STRING, "[%c]", 'd'),		"[d]"			, 0);

	check("add s", ptr, v_add(ptr, STRING, "%s", NULL),			"(null)"		, 0);
	check("add s", ptr, v_add(ptr, STRING, "%s", "Hello"),		"Hello"			, 0);
	check("add s", ptr, v_add(ptr, STRING, "[%s]", "Hello"),	"[Hello]"		, 0);

	check("add d", ptr, v_add(ptr, STRING, "%d", 0),			"0"				, 0);
	check("add d", ptr, v_add(ptr, STRING, "%d", -1),			"-1"			, 0);
	check("add d", ptr, v_add(ptr, STRING, "%d", 42),			"42"			, 0);
	check("add d", ptr, v_add(ptr, STRING, "%d", 2147483647),	"2147483647"	, 0);
	check("add d", ptr, v_add(ptr, STRING, "%d", -2147483648),	"-2147483648"	, 0);

	check("add i", ptr, v_add(ptr, STRING, "%i", 0),			"0"				, 0);
	check("add i", ptr, v_add(ptr, STRING, "%i", -1),			"-1"			, 0);
	check("add i", ptr, v_add(ptr, STRING, "%i", 42),			"42"			, 0);
	check("add i", ptr, v_add(ptr, STRING, "%i", 2147483647),	"2147483647"	, 0);
	check("add i", ptr, v_add(ptr, STRING, "%i", -2147483648),	"-2147483648"	, 0);

	check("add u", ptr, v_add(ptr, STRING, "%u", 0),			"0"				, 0);
	check("add u", ptr, v_add(ptr, STRING, "%u", 42),			"42"			, 0);
	check("add u", ptr, v_add(ptr, STRING, "%u", 4294967295),	"4294967295"	, 0);

	check("add x", ptr, v_add(ptr, STRING, "%x", 0),			"0"				, 0);
	check("add x", ptr, v_add(ptr, STRING, "%x", -0x78E45),		"-78e45"		, 0);
	check("add x", ptr, v_add(ptr, STRING, "%x", -0xFFFFFFF),	"-fffffff"		, 0);
	check("add x", ptr, v_add(ptr, STRING, "%x", 0xFFFFFFF),	"fffffff"		, 0);

	check("add X", ptr, v_add(ptr, STRING, "%X", 0),			"0"				, 0);
	check("add X", ptr, v_add(ptr, STRING, "%X", -0x78E45),		"-78E45"		, 0);
	check("add X", ptr, v_add(ptr, STRING, "%X", -0xFFFFFFF),	"-FFFFFFF"		, 0);
	check("add X", ptr, v_add(ptr, STRING, "%X", 0xFFFFFFF),	"FFFFFFF"		, 0);

	check("add p", ptr, v_add(ptr, STRING, "%p", NULL),			"0x0"			, 0);
	check("add p", ptr, v_add(ptr, STRING, "%p", 0x0),			"0x0"			, 0);
	check("add p", ptr, v_add(ptr, STRING, "%p", 0x78E45),		"0x78e45"		, 0);
	check("add p", ptr, v_add(ptr, STRING, "%p", 0xFFFFFFF),	"0xfffffff"		, 0);
	check("add p", ptr, v_add(ptr, STRING, "%p", 0xFFFFFFF),	"0xfffffff"		, 0);

	check("add p", ptr, v_add(ptr, STRING, "%l", NULL),			"%l"			, 0);

	/* ************************************************************************** */

	check("insert %", ptr, v_insert(ptr, 0, STRING, "%%", 0),			"%"				, 0);
	check("insert %", ptr, v_insert(ptr, 0, STRING, "[%%]", 0),			"[%]"			, 0);

	check("insert c", ptr, v_insert(ptr, 0, STRING, "%c", 0),			""				, 1);
	check("insert c", ptr, v_insert(ptr, 0, STRING, "%c", 'c'),			"c"				, 0);
	check("insert c", ptr, v_insert(ptr, 0, STRING, "%c", '\\'),		"\\"			, 0);
	check("insert c", ptr, v_insert(ptr, 0, STRING, "[%c]", 'd'),		"[d]"			, 0);

	check("insert s", ptr, v_insert(ptr, 0, STRING, "%s", NULL),		"(null)"		, 0);
	check("insert s", ptr, v_insert(ptr, 0, STRING, "%s", "Hello"),		"Hello"			, 0);
	check("insert s", ptr, v_insert(ptr, 0, STRING, "[%s]", "Hello"),	"[Hello]"		, 0);

	check("insert d", ptr, v_insert(ptr, 0, STRING, "%d", 0),			"0"				, 0);
	check("insert d", ptr, v_insert(ptr, 0, STRING, "%d", -1),			"-1"			, 0);
	check("insert d", ptr, v_insert(ptr, 0, STRING, "%d", 42),			"42"			, 0);
	check("insert d", ptr, v_insert(ptr, 0, STRING, "%d", 2147483647),	"2147483647"	, 0);
	check("insert d", ptr, v_insert(ptr, 0, STRING, "%d", -2147483648),	"-2147483648"	, 0);

	check("insert i", ptr, v_insert(ptr, 0, STRING, "%i", 0),			"0"				, 0);
	check("insert i", ptr, v_insert(ptr, 0, STRING, "%i", -1),			"-1"			, 0);
	check("insert i", ptr, v_insert(ptr, 0, STRING, "%i", 42),			"42"			, 0);
	check("insert i", ptr, v_insert(ptr, 0, STRING, "%i", 2147483647),	"2147483647"	, 0);
	check("insert i", ptr, v_insert(ptr, 0, STRING, "%i", -2147483648),	"-2147483648"	, 0);

	check("insert u", ptr, v_insert(ptr, 0, STRING, "%u", 0),			"0"				, 0);
	check("insert u", ptr, v_insert(ptr, 0, STRING, "%u", 42),			"42"			, 0);
	check("insert u", ptr, v_insert(ptr, 0, STRING, "%u", 4294967295),	"4294967295"	, 0);

	check("insert x", ptr, v_insert(ptr, 0, STRING, "%x", 0),			"0"				, 0);
	check("insert x", ptr, v_insert(ptr, 0, STRING, "%x", -0x78E45),	"-78e45"		, 0);
	check("insert x", ptr, v_insert(ptr, 0, STRING, "%x", -0xFFFFFFF),	"-fffffff"		, 0);
	check("insert x", ptr, v_insert(ptr, 0, STRING, "%x", 0xFFFFFFF),	"fffffff"		, 0);

	check("insert X", ptr, v_insert(ptr, 0, STRING, "%X", 0),			"0"				, 0);
	check("insert X", ptr, v_insert(ptr, 0, STRING, "%X", -0x78E45),	"-78E45"		, 0);
	check("insert X", ptr, v_insert(ptr, 0, STRING, "%X", -0xFFFFFFF),	"-FFFFFFF"		, 0);
	check("insert X", ptr, v_insert(ptr, 0, STRING, "%X", 0xFFFFFFF),	"FFFFFFF"		, 0);

	check("insert p", ptr, v_insert(ptr, 0, STRING, "%p", NULL),		"0x0"			, 0);
	check("insert p", ptr, v_insert(ptr, 0, STRING, "%p", 0x0),			"0x0"			, 0);
	check("insert p", ptr, v_insert(ptr, 0, STRING, "%p", 0x78E45),		"0x78e45"		, 0);
	check("insert p", ptr, v_insert(ptr, 0, STRING, "%p", 0xFFFFFFF),	"0xfffffff"		, 0);
	check("insert p", ptr, v_insert(ptr, 0, STRING, "%p", 0xFFFFFFF),	"0xfffffff"		, 0);

	check("insert p", ptr, v_insert(ptr, 0, STRING, "%l", NULL),		"%l"			, 0);

	/* ************************************************************************** */


	check("add precision c", ptr, v_add(ptr, STRING, "%.2c",		0),				""				, 1);
	check("add precision c", ptr, v_add(ptr, STRING, "[%.2c]",	'c'),			"[c]"			, 0);
	check("add precision c", ptr, v_add(ptr, STRING, "[%.2c]",	'\\'),			"[\\]"			, 0);
	check("add precision c", ptr, v_add(ptr, STRING, "[%.2c]",	'd'),			"[d]"			, 0);
	check("add precision s", ptr, v_add(ptr, STRING, "[%.2s]",	NULL),			"[(n]"			, 0);
	check("add precision s", ptr, v_add(ptr, STRING, "[%.2s]",	"Hello"),		"[He]"			, 0);
	check("add precision d", ptr, v_add(ptr, STRING, "[%.2d]",	0),				"[0]"			, 0);
	check("add precision d", ptr, v_add(ptr, STRING, "[%.2d]",	-1),			"[-1]"			, 0);
	check("add precision d", ptr, v_add(ptr, STRING, "[%.2d]",	42),			"[42]"			, 0);
	check("add precision d", ptr, v_add(ptr, STRING, "[%.2d]",	2147483647),	"[2147483647]"	, 0);
	check("add precision d", ptr, v_add(ptr, STRING, "[%.2d]",	-2147483648),	"[-2147483648]"	, 0);
	check("add precision i", ptr, v_add(ptr, STRING, "[%.2i]",	0),				"[0]"			, 0);
	check("add precision i", ptr, v_add(ptr, STRING, "[%.2i]",	-1),			"[-1]"			, 0);
	check("add precision i", ptr, v_add(ptr, STRING, "[%.2i]",	42),			"[42]"			, 0);
	check("add precision i", ptr, v_add(ptr, STRING, "[%.2i]",	2147483647),	"[2147483647]"	, 0);
	check("add precision i", ptr, v_add(ptr, STRING, "[%.2i]",	-2147483648),	"[-2147483648]"	, 0);
	check("add precision u", ptr, v_add(ptr, STRING, "[%.2u]",	0),				"[0]"			, 0);
	check("add precision u", ptr, v_add(ptr, STRING, "[%.2u]",	42),			"[42]"			, 0);
	check("add precision u", ptr, v_add(ptr, STRING, "[%.2u]",	4294967295),	"[4294967295]"	, 0);
	check("add precision x", ptr, v_add(ptr, STRING, "[%.2x]",	0),				"[0]"			, 0);
	check("add precision x", ptr, v_add(ptr, STRING, "[%.2x]",	-0x78E45),		"[-78e45]"		, 0);
	check("add precision x", ptr, v_add(ptr, STRING, "[%.2x]",	-0xFFFFFFF),	"[-fffffff]"	, 0);
	check("add precision x", ptr, v_add(ptr, STRING, "[%.2x]",	0xFFFFFFF),		"[fffffff]"		, 0);
	check("add precision X", ptr, v_add(ptr, STRING, "[%.2X]",	0),				"[0]"			, 0);
	check("add precision X", ptr, v_add(ptr, STRING, "[%.2X]",	-0x78E45),		"[-78E45]"		, 0);
	check("add precision X", ptr, v_add(ptr, STRING, "[%.2X]",	-0xFFFFFFF),	"[-FFFFFFF]"	, 0);
	check("add precision X", ptr, v_add(ptr, STRING, "[%.2X]",	0xFFFFFFF),		"[FFFFFFF]"		, 0);
	check("add precision p", ptr, v_add(ptr, STRING, "[%.2p]",	NULL),			"[0x0]"			, 0);
	check("add precision p", ptr, v_add(ptr, STRING, "[%.2p]",	0x0),			"[0x0]"			, 0);
	check("add precision p", ptr, v_add(ptr, STRING, "[%.2p]",	0x78E45),		"[0x78e45]"		, 0);
	check("add precision p", ptr, v_add(ptr, STRING, "[%.2p]",	0xFFFFFFF),		"[0xfffffff]"	, 0);
	check("add precision p", ptr, v_add(ptr, STRING, "[%.2p]",	0xFFFFFFF),		"[0xfffffff]"	, 0);
	check("add precision p", ptr, v_add(ptr, STRING, "[%.2l]",	NULL),			"[%.2l]"		, 0);
	
	/* ************************************************************************** */

	int precison_len = 2;

	check("add var precision c", ptr, v_add(ptr, STRING, "%.*c",	precison_len,	0),				""				, 1);
	check("add var precision c", ptr, v_add(ptr, STRING, "[%.*c]",	precison_len,	'c'),			"[c]"			, 0);
	check("add var precision c", ptr, v_add(ptr, STRING, "[%.*c]",	precison_len,	'\\'),			"[\\]"			, 0);
	check("add var precision c", ptr, v_add(ptr, STRING, "[%.*c]",	precison_len,	'd'),			"[d]"			, 0);
	check("add var precision s", ptr, v_add(ptr, STRING, "[%.*s]",	precison_len,	NULL),			"[(n]"			, 0);
	check("add var precision s", ptr, v_add(ptr, STRING, "[%.*s]",	precison_len,	"Hello"),		"[He]"			, 0);
	check("add var precision d", ptr, v_add(ptr, STRING, "[%.*d]",	precison_len,	0),				"[0]"			, 0);
	check("add var precision d", ptr, v_add(ptr, STRING, "[%.*d]",	precison_len,	-1),			"[-1]"			, 0);
	check("add var precision d", ptr, v_add(ptr, STRING, "[%.*d]",	precison_len,	42),			"[42]"			, 0);
	check("add var precision d", ptr, v_add(ptr, STRING, "[%.*d]",	precison_len,	2147483647),	"[2147483647]"	, 0);
	check("add var precision d", ptr, v_add(ptr, STRING, "[%.*d]",	precison_len,	-2147483648),	"[-2147483648]"	, 0);
	check("add var precision i", ptr, v_add(ptr, STRING, "[%.*i]",	precison_len,	0),				"[0]"			, 0);
	check("add var precision i", ptr, v_add(ptr, STRING, "[%.*i]",	precison_len,	-1),			"[-1]"			, 0);
	check("add var precision i", ptr, v_add(ptr, STRING, "[%.*i]",	precison_len,	42),			"[42]"			, 0);
	check("add var precision i", ptr, v_add(ptr, STRING, "[%.*i]",	precison_len,	2147483647),	"[2147483647]"	, 0);
	check("add var precision i", ptr, v_add(ptr, STRING, "[%.*i]",	precison_len,	-2147483648),	"[-2147483648]"	, 0);
	check("add var precision u", ptr, v_add(ptr, STRING, "[%.*u]",	precison_len,	0),				"[0]"			, 0);
	check("add var precision u", ptr, v_add(ptr, STRING, "[%.*u]",	precison_len,	42),			"[42]"			, 0);
	check("add var precision u", ptr, v_add(ptr, STRING, "[%.*u]",	precison_len,	4294967295),	"[4294967295]"	, 0);
	check("add var precision x", ptr, v_add(ptr, STRING, "[%.*x]",	precison_len,	0),				"[0]"			, 0);
	check("add var precision x", ptr, v_add(ptr, STRING, "[%.*x]",	precison_len,	-0x78E45),		"[-78e45]"		, 0);
	check("add var precision x", ptr, v_add(ptr, STRING, "[%.*x]",	precison_len,	-0xFFFFFFF),	"[-fffffff]"	, 0);
	check("add var precision x", ptr, v_add(ptr, STRING, "[%.*x]",	precison_len,	0xFFFFFFF),		"[fffffff]"		, 0);
	check("add var precision X", ptr, v_add(ptr, STRING, "[%.*X]",	precison_len,	0),				"[0]"			, 0);
	check("add var precision X", ptr, v_add(ptr, STRING, "[%.*X]",	precison_len,	-0x78E45),		"[-78E45]"		, 0);
	check("add var precision X", ptr, v_add(ptr, STRING, "[%.*X]",	precison_len,	-0xFFFFFFF),	"[-FFFFFFF]"	, 0);
	check("add var precision X", ptr, v_add(ptr, STRING, "[%.*X]",	precison_len,	0xFFFFFFF),		"[FFFFFFF]"		, 0);
	check("add var precision p", ptr, v_add(ptr, STRING, "[%.*p]",	precison_len,	NULL),			"[0x0]"			, 0);
	check("add var precision p", ptr, v_add(ptr, STRING, "[%.*p]",	precison_len,	0x0),			"[0x0]"			, 0);
	check("add var precision p", ptr, v_add(ptr, STRING, "[%.*p]",	precison_len,	0x78E45),		"[0x78e45]"		, 0);
	check("add var precision p", ptr, v_add(ptr, STRING, "[%.*p]",	precison_len,	0xFFFFFFF),		"[0xfffffff]"	, 0);
	check("add var precision p", ptr, v_add(ptr, STRING, "[%.*p]",	precison_len,	0xFFFFFFF),		"[0xfffffff]"	, 0);
	check("add var precision p", ptr, v_add(ptr, STRING, "[%.*l]",	precison_len,	NULL),			"[%.*l]"		, 0);

	v_delete(ptr);
}

// TEST Recursive Clear and Delete
void test3()
{
	t_vec vec = v_init_r(sizeof(t_vec), v_clear, v_delete, 4);
	t_vec tmp = v_init_r(sizeof(char), NULL, NULL, 4);
	
	for (int i = 0; i < 3; i++)
	{
		v_add(&vec, DEFAULT, &tmp);
		v_add(v_get(&vec, i), STRING, "=> %d", i);
	}

	for (int i = 0; i < 3; i++)
		printf("%s\n", v_get(v_get(&vec, i), 0));

	v_print(&vec);

	v_clear(&vec);

	for (int i = 0; i < 3; i++)
		printf("%s\n", v_get(v_get(&vec, i), 0));

	v_print(&vec);
	v_delete(&vec);
}

char *str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int int_to_ptr(int *x, char **res)
{
	
	if (*x < 0 || *x >= 26)
		return (0);
	*res = &str[*x];
	return (1);
}

void test4()
{
	// const char *str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	t_vec vec = v_init_r(sizeof(int), NULL, NULL, 4);

	int x;
	x = 1; v_add(&vec, DEFAULT, &x);
	x = 5; v_add(&vec, DEFAULT, &x);
	x = 8; v_add(&vec, DEFAULT, &x);
	x = 25; v_add(&vec, DEFAULT, &x);


	v_print(&vec);

	if (!v_cast(&vec, sizeof(char *), int_to_ptr))
	{
		printf("Casting Error\n");
		v_delete(&vec);
		return ;
	}

	v_print(&vec);
	
	for (size_t i = 0; i < vec.len; i++)
		printf("[%s]\n", *(char **) v_get(&vec, i));

	v_delete(&vec);
}

void test5()
{
	// const char *str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	t_vec vec = v_init_r(sizeof(char), NULL, NULL, 4);
	int fd = open("./test-files/long_line", O_RDONLY);

	v_readline(&vec, fd);

	close(fd);
	v_delete(&vec);
}

int	main(void)
{
	// test1();
	// test2();
	// test3();
	// test4();
	test5();

	return (0);
}
