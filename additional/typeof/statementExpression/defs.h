#ifndef __DEFS__
#define __DEFS__

/*!
  \file defs.h
  \brief Contains two different forms of macro definitions
 */

/*!
  \def maxInt(a, b)
  \brief Again, finds the larger among \a a and \a b.
  This is a modification of \ref "max(a, b)". Here, (a) and (b) are evaluated only once. Their values are
  assigned to the local variables \a _a and \a _b. Note that since this is actually statement expression,
  therefore, the last statement must always be an expression. So, it is.
 */

/*!
  \brief Finds the larger one among \a a and \a b.
  However this has one problem and that is, \a (a) or \a (b) is evaluated twice. Once
  when they are being compared and once depending on whether the conditional evaluates to true or false.
  \param a An integer value
  \param b Another integer value
  \returns The larger of the two
 */
#define max(a, b) ((a) > (b) ? (a) : (b))

#define maxInt(a, b)							\
  ({									\
    int _a = (a);							\
    int _b = (b);							\
    _a > _b ? _a : _b;/*!< this is like a return statement */		\
  })

#endif
