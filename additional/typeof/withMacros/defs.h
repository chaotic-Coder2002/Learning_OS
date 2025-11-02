#ifndef __DEFS__
#define __DEFS__

/*!
  \file defs.h
 */

/*!
  \def FINDMAX(m, v, n)
  \brief Finds the maximum element from the vector \c v of size \c n

  \details The statement at line 24 basically determines the type of an element of the given vector \c v and then
  declares a pointer of that type named \c _v. Note that the expression is \c typeof((v)[0]) and not
  \c typeof(v[0]) because \c v could be an expression performing pointer arithmetic as well.
  
  The statement is shown below:
  \code{.c}
  typeof((v)[0]) * _v = v;
  \endcode

 */
#define FINDMAX(m, v, n)\
  {\
    typeof((v)[0]) * _v = v;\
    typeof(n) _n = n;\
    printf("_n = %d\n", _n);\
    typeof(m) _m = _v[0];\
    printf("*_v = %d\n", *_v);\
    for(int i = 1; i < _n; i++) {\
      if(_v[i] > _m)\
	_m = _v[i];\
    }\
    (m) = _m;					\
  }

#endif
