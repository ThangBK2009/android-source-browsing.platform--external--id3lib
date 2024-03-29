dnl ACCONFIG TEMPLATE
dnl #undef ID3_ICONV_FORMAT_UTF16BE
dnl #undef ID3_ICONV_FORMAT_UTF16LE
dnl #undef ID3_ICONV_FORMAT_UTF8
dnl #undef ID3_ICONV_FORMAT_ISO_8859_1
dnl END ACCONFIG

AC_DEFUN(ID3_CHECK_ICONV_FORMAT,[
  if eval "test \"x\$$1\" = \"xno\""; then
    AC_MSG_CHECKING(whether iconv supports $2)
    AC_TRY_RUN([#include <iconv.h>
        int main() { return iconv_open("$2", "$2") == -1; } ],
      [ eval $1=yes
        AC_MSG_RESULT(yes)
        AC_DEFINE_UNQUOTED($1, "$2") ],
      [ AC_MSG_RESULT(no) ],
      [ AC_MSG_WARN(Don't cross-compile) ])
  fi
])

AC_DEFUN([ID3_UNICODE],[
  if test "x$ac_cv_header_iconv_h" = "xyes"; then
    ID3_ICONV_FORMAT_UTF8=no
    ID3_ICONV_FORMAT_UTF16LE=no
    ID3_ICONV_FORMAT_UTF16BE=no
    ID3_ICONV_FORMAT_ISO_8859_1=no

    ID3_CHECK_ICONV_FORMAT(ID3_ICONV_FORMAT_UTF8,    UTF-8)
    ID3_CHECK_ICONV_FORMAT(ID3_ICONV_FORMAT_UTF8,    UTF8)
#    ID3_CLEAR_ICONV_FORMAT(ID3_ICONV_FORMAT_UTF8)

    ID3_CHECK_ICONV_FORMAT(ID3_ICONV_FORMAT_UTF16BE, UTF-16BE)
    ID3_CHECK_ICONV_FORMAT(ID3_ICONV_FORMAT_UTF16BE, UTF16BE)
    ID3_CHECK_ICONV_FORMAT(ID3_ICONV_FORMAT_UTF16BE, UCS-2BE)
    ID3_CHECK_ICONV_FORMAT(ID3_ICONV_FORMAT_UTF16BE, UCS2BE)
    ID3_CHECK_ICONV_FORMAT(ID3_ICONV_FORMAT_UTF16BE, UNICODEBIG)
#    ID3_CLEAR_ICONV_FORMAT(ID3_ICONV_FORMAT_UTF16BE)

    ID3_CHECK_ICONV_FORMAT(ID3_ICONV_FORMAT_UTF16LE, UTF-16LE)
    ID3_CHECK_ICONV_FORMAT(ID3_ICONV_FORMAT_UTF16LE, UTF16LE)
    ID3_CHECK_ICONV_FORMAT(ID3_ICONV_FORMAT_UTF16LE, UCS-2LE)
    ID3_CHECK_ICONV_FORMAT(ID3_ICONV_FORMAT_UTF16LE, UCS2LE)
    ID3_CHECK_ICONV_FORMAT(ID3_ICONV_FORMAT_UTF16LE, UNICODE)
#    ID3_CLEAR_ICONV_FORMAT(ID3_ICONV_FORMAT_UTF16LE)

    ID3_CHECK_ICONV_FORMAT(ID3_ICONV_FORMAT_ISO_8859_1,   ISO-8859-1)
    ID3_CHECK_ICONV_FORMAT(ID3_ICONV_FORMAT_ISO_8859_1,   ASCII)
    ID3_CHECK_ICONV_FORMAT(ID3_ICONV_FORMAT_ISO_8859_1,   US-ASCII)
    ID3_CHECK_ICONV_FORMAT(ID3_ICONV_FORMAT_ISO_8859_1,   US)
#    ID3_CLEAR_ICONV_FORMAT(ID3_ICONV_FORMAT_ASCII)
  fi
])

