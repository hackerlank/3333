noinst_LTLIBRARIES = libplatcommon.la

platcommonincdir = $(top_srcdir)/3Party/protobuf-2.6.1/src

INCLUDES = -I$(top_srcdir)/3Party/protobuf-2.6.1/src -I$(top_srcdir)/gbuffer

libplatcommon_la_SOURCES = \
							nullcommand.pb.cc		\
							sdkcommand.pb.cc		

libplatcommon_la_LIBADD = @LIBS_XML@ @LIBS_MYSQL@ \
					 $(top_builddir)/common/libcommon.la \
					 $(top_builddir)/gbuffer/libgbuffer.la \
					 $(top_builddir)/3Party/protobuf-2.6.1/src/libprotobuf.la \
					 $(top_builddir)/3Party/protobuf-2.6.1/src/libprotobuf-lite.la \
					 $(top_builddir)/3Party/protobuf-2.6.1/src/libprotoc.la \
					 $(top_srcdir)/3Party/tinyxml-2.5.3/libtinyxml.la

