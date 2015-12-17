noinst_LTLIBRARIES = libplatcommon.la

platcommonincdir = $(top_srcdir)/3Party/protobuf-2.6.1/src

AM_CPPFLAGS = -I$(top_srcdir)/3Party/protobuf-2.6.1/src -I$(top_srcdir)/bwsdk/gbuffer

libplatcommon_la_LIBADD = @LIBS_XML@ @LIBS_MYSQL@ \
					 $(top_builddir)/common/libcommon.la \
					 $(top_builddir)/bwsdk/gbuffer/libgbuffer.la \
					 $(top_builddir)/3Party/protobuf-2.6.1/src/libprotobuf.la \
					 $(top_builddir)/3Party/protobuf-2.6.1/src/libprotobuf-lite.la \
					 $(top_builddir)/3Party/protobuf-2.6.1/src/libprotoc.la \
					 $(top_srcdir)/3Party/tinyxml-2.5.3/libtinyxml.la


libplatcommon_la_SOURCES =  chatcommand.pb.cc config.pb.cc forwardcommand.pb.cc gmcommand.pb.cc logincommand.pb.cc monitorpmd.pb.cc nullcommand.pb.cc pmd.pb.cc sdkcommand.pb.cc unilightclient.pb.cc
