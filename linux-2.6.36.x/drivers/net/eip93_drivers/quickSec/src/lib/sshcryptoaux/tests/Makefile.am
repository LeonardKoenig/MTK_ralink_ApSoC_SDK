
# Added by filter_add_makefile_libextra_stuff
# To keep automake silent about public and private headers
# not been set when something is added to them

public_headers =
private_headers =

## Process this file with automake to produce Makefile.in

#
# lib/sshcrypt/tests Makefile.am
#
# Author: Tatu Ylonen <ylo@ssh.fi>
#
#  Copyright:
#          Copyright (c) 2002, 2003 SFNT Finland Oy.
#                    All rights reserved
#

AUTOMAKE_OPTIONS = 1.0 foreign dist-zip no-dependencies
WINCONF_OPTIONS = maintainer=tmo@ssh.fi

INCLUDES = -I$(srcdir)/.. -I$(top_srcdir)  -I$(top_srcdir)/lib/sshutil/sshcore  -I$(top_srcdir)/lib/sshutil/sshadt  -I$(top_srcdir)/lib/sshutil/ssheloop  -I$(top_srcdir)/lib/sshutil/sshstrutil  -I$(top_srcdir)/lib/sshutil/sshfsm  -I$(top_srcdir)/lib/sshutil/sshstream  -I$(top_srcdir)/lib/sshutil/sshsysutil  -I$(top_srcdir)/lib/sshutil/sshnet  -I$(top_srcdir)/lib/sshutil/sshmisc  -I$(top_srcdir)/lib/sshutil/sshaudit  -I$(top_srcdir)/lib/sshutil/sshpacketstream  -I$(top_srcdir)/lib/sshutil/sshtestutil  -I$(top_srcdir)/lib/sshutil  -I$(top_srcdir)/lib/zlib  -I$(top_srcdir)/lib/sshmath  -I$(top_srcdir)/lib/sshasn1  -I$(top_srcdir)/lib/sshcrypto/sshcipher  -I$(top_srcdir)/lib/sshcrypto/sshhash  -I$(top_srcdir)/lib/sshcrypto/sshrandom  -I$(top_srcdir)/lib/sshcrypto/sshcryptocore  -I$(top_srcdir)/lib/sshcrypto/sshmac  -I$(top_srcdir)/lib/sshcrypto/sshpk  -I$(top_srcdir)/lib/sshcrypto 
LDADD = ../libsshcryptoaux.a $(top_builddir)/lib/sshcrypto/libsshcrypto.a $(top_builddir)/lib/sshasn1/libsshasn1.a $(top_builddir)/lib/sshmath/libsshmath.a $(top_builddir)/lib/zlib/libz.a $(top_builddir)/lib/sshutil/libsshutil.a 

TESTS_LIGHT =         \
	t-aes-keywrap 




TESTS = $(TESTS_LIGHT) \
	t-compress 




EXTRA_PROGRAMS = $(TESTS) t-key-export

EXTRA_DIST = 





t_aes_keywrap_SOURCES = t-aes-keywrap.c
t_aes_keywrap_DEPENDENCIES = $(LDADD)


t_compress_SOURCES = t-compress.c
t_compress_DEPENDENCIES = $(LDADD)








t_key_export_SOURCES = t-key-export.c
t_key_export_DEPENDENCIES = $(LDADD)


include $(top_srcdir)/Makefile.libextra
include $(top_srcdir)/Makefile.grandlib_provider

# EOF
