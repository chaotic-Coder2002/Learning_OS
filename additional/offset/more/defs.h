#ifndef __DEFS__
#define __DEFS__

/*!
  \file defs.h
  \example main.c
  This program demonstrates how to get to the address of the parent \c struct using the \c struct nested inside it.

  First, we are assigning the address of \c birdNest to \c nestedStruct by typecasting its address into an array
  of bytes:
  \code{.c}
  char *nestedStruct = (char*) &aTree.birdNest;
  \endcode
  The reason why we are typecasting to \c char* is that in C, a \c char is 1 byte and a \c char* points to
  an array of 1 bytes and the offset that will get for \c birdNest from the base address of the \c struct \c Tree
  will also be in bytes, so performing pointer arithmetic on the offset will actually give us the correct result.

  Now, the line:

  \code{.c}
  Tree *temp = (Tree*)(nestedStruct - (size_t) &((Tree*)0)->birdNest);
  \endcode
  Let's first focus on the second part of the line i.e.
  \code{.c}
  &((Tree*)0)->birdNest;
  \endcode
  Here, <tt>&((Tree*)0)->birdNest</tt> basically gives the address of \c birdNest <em>relative</em> to \c 0.
  This address is then typecast to bytes by the \c size_t type.

  After that the the usual pointer arithmetic is performed. Let's say for example <tt>&((Tree*)0)->birdNest</tt>
  gave the address of \c birdNest to be \c 0x8 (which is \c 8 in decimal), then typecasting it to a \c size_t type
  will give us an \c 8 which is actually \c 8 bytes.
  So, the statement <tt>Tree* temp = (Tree*)(nestedStruct - (size_t) &((Tree*)0)->birdNest);</tt> in this case
  will be simplified to: <tt>Tree* temp = (Tree*)(nestedStruct - 8);</tt>, which is regular pointer arithmetic in C.

  Now, let's understand this with an example, consider that we have a \c char array of 10 characters. For simplicity,
  let's use decimal numbers as addresses of each element. Since there are 10 elements in the array, so let's say that
  the starting address is \c 1001 and let's say that there is an element at address \c 1005 and we have set a pointer
  pointing to that address. Now, we want the pointer to point to the address \c 1001. We can see that the address
  \c 1005 is 4 bytes away from \c 1001. So, now, all we have to do is subtract \c 4 from the address \c 1005 and we
  will get to the starting/base address of the array. Let's assume that \c p is the pointer pointing to address
  \c 1005, so in order for \c p to point to \c 1001, we will do: <tt>p = p - 4</tt> and that way \c p will finally
  point to \c 1001.

  \example example2.c
  This is an example demonstrating the concept of finding the offset relative to a number.

  The structure \c Sample:

  \code{.c}
  typedef struct Sample {
     int a;
     int b;
  } Sample;
  \endcode
  contains two integers, \c 4 bytes each.\n
  \b Note: The base address of a structure is actually the address of the first byte of the structure.

  The statement <tt>printf("%p\n", &((Sample*)0)->b);</tt> basically prints the address of \c b. This will
  be \c 0x4 or 4 bytes (structure padding), because \c b is \c 4 bytes away from the base address,
  if \c 0 is considered as the base address.\n

  The next statement <tt>printf("%p\n", &((Sample*)1)->b);</tt> also prints the address of \c b. But this time, it
  will be \c 0x5 or 5 bytes, because again, \c b is 4 bytes away from the base address, so its address is calculated
  as <tt>(1 + 4) bytes</tt>.
 */

/*!
  \struct Nest
  \brief A Nest containing some eggs and possibly some nestlings.
 */

/*!
  \struct Tree
  \brief A tree with a name and possibly a nest.
*/

typedef struct Nest {
  int eggs; /*!< number of eggs in the nest */
  int nestlings; /*!< number of nestlings in the nest */
} Nest;

typedef struct Tree {
  char name[20]; /*!< name of the tree */
  Nest birdNest; /*!< a bird nest */
} Tree;

#endif
