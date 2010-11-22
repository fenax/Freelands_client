dnl Process this file with autoconf to produce a configure script.


m4_include(ax_boost_base.m4)

AC_PREREQ(2.65)
AC_INIT([EL_Client],[0.0.1])
          
dnl check for programs
AC_PROG_CC
AC_PROG_CXX
AC_PROG_INSTALL


AC_CANONICAL_TARGET
AM_INIT_AUTOMAKE([-Wall -Werror foreign])


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

PKG_CHECK_MODULES(OIS, OIS)
AC_SUBST(OIS_CFLAGS)
AC_SUBST(OIS_LIBS)

dnl find boost package

AC_CHECK_LIB([boost_system],
            [main],
	    [],
            [AC_MSG_ERROR([-lboost_system was not found!])])
AC_CHECK_LIB([boost_iostreams],
            [main],
	    [],
            [AC_MSG_ERROR([-lboost_iostreams was not found!])])


BOOST_MIN_VERSION=1.35.0
AX_BOOST_BASE([$BOOST_MIN_VERSION])
CPPFLAGS="$CPPFLAGS $BOOST_CPPFLAGS"



AC_CONFIG_HEADERS([include/config.h])
AC_CONFIG_FILES(Makefile src/Makefile)

AC_OUTPUT

