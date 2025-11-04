#ifndef __DEFS__
#define __DEFS__

/*!
  \file defs.h
 */

/*!
  \struct Sample
  \brief A sample structure
 */

/*!
  \example main.c
  An example demonstrating how typcasting a <tt>(struct*)</tt> to <tt>(char*)</tt> helps in visualizing the structure
  members clearly.

  In this example, <tt>printf("&s.a: %p\n", &s.a);</tt> displays the address of the field \c a of the struct
  \c Sample.\n

  The line <tt>printf("sptr: %p\n", sptr);</tt> also displays the same address. But here, that address is the address
  of the first byte of the byte array (and also of \c Sample). The consecutive byte addresses can also be accessed
  via simple pointer arithmetic, which cannot be done with the \c Sample instance \c s.\n\n

  In the  next line, <tt>printf("&s.d: %p\n", &s.d);</tt> prints the address of the field \c d. Note that \c d is at
  an offset of 8 bytes from the starting/base address of \c Sample struct. Hence, using this information, we
  can add an 8 to the base address of the byte pointed to by the \c char pointer \c sptr. And so the line
  <tt>printf("sptr + 8: %p\n", sptr + 8);</tt> also produces the same address as that of the <tt>&s.d</tt>.\n\n
  The \c for loop given in this program accesses all the addresses of each byte and prints them onto the screen.
  There will be a total of 16 addresses (one for each byte, hence 16 bytes).
 */

typedef struct Sample {
  int a; // 4 bytes
  // 4 bytes of padding
  double d; // 8 bytes
} Sample;

#endif
