# Vector-lib

This a simple vector library where the alloc are done for you. There is two mode of use :

- Use the vector as a string (array of char) wher you will be able to use vec_fill and all it's mode.
- Use the vector as a array of anything. You will only be able to use vec_add and is more limited but can be used for anything.

---

## Nomenclature

In this doc and in the code we use certain terms often. THerefore, here is explonation.

- length : The length is the number of elements within the array.
- size : The size is the size in Bytes of a single element in the array.
- rate *(code only)* : The rate is the speed at which the vector will expand.

---

## Table of content

- [Initialization](#Initialization)
- [Termination](#Termination)
- [Adding content](#Adding-content)

---

## List of commands

- [vec_init](#Initialization)
- [vec_delete](#Termination)
- [vec_delete_content](#Termination)
- [vec_add](#Array-of-any-elements)
- [vec_fill](#Array-of-characters)
- [vec_get](#Adding-content)
- [vec_print](#Adding-content)

---

## Initialization

First of all, you have to include the header file.

```c
#include "vector_lib.h"
```

Right after that, you have to create your vector. For that you will be able to use vec_init.

```c
t_vec my_vector = vec_init(sizeof(char));
```

The only argument of vec_init is the size of the element.

---

## Termination

And at the and of the code but early in here (so you dont forget it), to free the memory of the vector you can use vec_delete.

```c
vec_delete(my_vector_ptr);
```

The only argument of vec_delete is a pointer to the vector you want to destroy.

But if you want to use your vector again you can just reset it with vec_delete_content.

```c
vec_delete_content(my_vector_ptr);
```

The only argument of vec_delete_content is a pointer to the vector you want to reset.

---

## Adding content

To add content, you have two mode of use as previously cited in the intro.

### Array of any elements

For an array where the element could be anything, you have to use vec_add. As an example, here the vector has integers in it.

```c
int my_number = 10;

vec_add(my_vector_ptr, &my_number);
```

The only argument of vec_add is a pointer to the content you want to add.

### Array of characters

For an array of characters, you can use vec_fill.\
To show the result of all the example, i will use the result of [vec_print](#Print-the-vector).

Vec_fill has many options, here is a list :

- [V_DEFAULT](#V_DEFAULT)
- [V_SEP](#V_SEP)
- [V_MULTIPLE](#V_MULTIPLE)
- [V_MULTI_SEP](#V_MULTI_SEP)
- [V_MULTI_ALL_SEP](#V_MULTI_ALL_SEP)
- [V_FIXED_LEN](#V_FIXED_LEN)
- [Fusioning multiple options](#Fusioning-multiple-options)

---

### V_DEFAULT

V_DEFAULT is the default way to use vec_fill and works like this.

```c
t_vec *vec_fill(t_vec *vec, V_DEFAULT, char *str);

vec_fill(my_vector_ptr, V_DEFAULT, "Hello World");
```

```c
>> Hello World.....................
```

That simply added the argument given into the array. But if make a secund call...

```c
>> Hello WorldHello World..........
```

It simply puts it glued to the result of the previous call.

---

### V_SEP

V_SEP is an option of vec_fill and it will separate the result different calls.

```c
t_vec *vec_fill(t_vec *vec, V_SEP, char *separator, char *str);

vec_fill(my_vector_ptr, V_SEP, "___", "Hello World");
```

```c
>> Hello World___Hello World.......
```

But you can also put ``NULL`` instead of a string for the separator and the result will be a ``\0`` between the result of the two calls.

```c
vec_fill(my_vector_ptr, V_SEP, NULL, "Hello World");
```

```c
>> Hello World.Hello World.......
```

---

### V_MULTIPLE

V_MULTIPLE will allow you to add multiple strings at the same time.

```c
t_vec *vec_fill(t_vec *vec, V_MULTIPLE, int nb, char *str1, char *str2);

vec_fill(my_vector_ptr, V_MULTIPLE, 2, "Hello", "World");
```

```c
>> HelloWorld......................
```

---

### V_MULTI_SEP

V_MULTI_SEP will allow you to add multiple strings at the same time and have a separator between the different strings.

```c
t_vec *vec_fill(t_vec *vec, V_MULTI_SEP, char *separator, int nb, char *str1, char *str2);

vec_fill(my_vector_ptr, V_MULTI_SEP, "___", 2, "Hello", "World");
```

```c
>> Hello___World...................
```

But you can also put ``NULL`` instead of a string for the separator and the result will be a ``\0`` between the result of the two calls.

```c
vec_fill(my_vector_ptr, V_MULTI_SEP, NULL, 2, "Hello", "World");
```

```c
>> Hello.World...................
```

---

### V_MULTI_ALL_SEP

V_MULTI_SEP is the combination of [V_SEP](#V_SEP) and [V_MULTI_SEP](#V_MULTI_SEP). It will allow you to put multiple string and to separate within them and between calls.

```c
t_vec *vec_fill(t_vec *vec, V_MULTI_ALL_SEP, char *sep, char *multi_sep, int nb, char *str1, char *str2);

vec_fill(my_vector_ptr, V_MULTI_ALL_SEP, "___", "---", 2, "Hello", "World");
^ * 2
```

```c
>> Hello---World___Hello---World...
```

---

### V_FIXED_LEN

V_FIXED_LEN will allow to limit what the function will copy (for example if your string is not null terminated).

```c
t_vec *vec_fill(t_vec *vec, V_FIXED_LEN, char *str, int len);

vec_fill(my_vector_ptr, V_FIXED_LEN, "Hello World", 5);
```

```c
>> Hello...........................
```

---

### Fusioning multiple options

You saw all the default option but you can also personalize what the function will do using bit or operator (``|``).

```c
t_vec *vec_fill(t_vec *vec, V_SEP | V_FIXED_LEN, ...);
t_vec *vec_fill(t_vec *vec, V_MULTIPLE | V_FIXED_LEN, ...);
...
```

---

## Get an element

To get an element you can use vec_get.

```c
vec_get(my_vector_ptr, index);
```

You need to give the index in the array you want to get and will receive it as ``void *``. You just need to cast it to the element you want to receive and get the first elem and you got it. As an advise, you should create a function to automize the process for simpler use.

```c
int get_my_int_from_vector(t_vec *my_vector_ptr, int index)
{
    return (*((int *) vec_get(my_vector_ptr, index)));
}
```

---

## Print the vector

If you are using the vector to store characters, you can use vec_print.

```c
vec_print(my_vector_ptr);
```

vec_print will print in the std all printable character and will print all the non-printable as a ``'.'``.

---
