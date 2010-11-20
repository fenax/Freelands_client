dnl Process this file with autoconf to produce a configure script.

AC_PREREQ(2.59)
AC_INIT(EL_Client, 0.0.1)
AM_CONFIG_HEADER(include/config.h)
          
dnl check for programs
AC_PROG_CC
AC_PROG_CXX
AC_PROG_INSTALL

dnl g++ version check, not sure if usefull
  
if test x$GCC = xyes; then
	AC_MSG_CHECKING([version 3.x of gcc])
	if test -n "`$CC --version 2>&1|grep '3.'`"; then
		AC_DEFINE(EXT_HASH,, Use old STL hash options)
		AC_DEFINE(GCC_3_1,, 3.x GCC version)
		AC_MSG_RESULT(yes);
	else
		AC_MSG_RESULT(no);
	fi
fi


dnl find the ogre package

PKG_CHECK_MODULES(OGRE, OGRE)
AC_SUBST(OGRE_CFLAGS)
AC_SUBST(OGRE_LIBS)



AC_CANONICAL_SYSTEM
AM_INIT_AUTOMAKE()

AC_PROG_CXX

AC_CONFIG_FILES(Makefile src/Makefile)
AC_OUTPUT

