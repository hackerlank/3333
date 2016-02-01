#noinst_LTLIBRARIES = libplatcommon.la
lib_LTLIBRARIES=libplatcommon.la

platcommonincdir = $(top_srcdir)/3Party/protobuf-2.6.1/src

AM_CPPFLAGS = -I$(top_srcdir)/3Party/protobuf-2.6.1/src -I$(top_srcdir)/bwsdk/gbuffer

libplatcommon_la_LIBADD =  


libplatcommon_la_SOURCES =  chatcommand.pb.cc config.pb.cc forwardcommand.pb.cc gmcommand.pb.cc logincommand.pb.cc monitorpmd.pb.cc nullcommand.pb.cc pmd.pb.cc sdkcommand.pb.cc unilightclient.pb.cc
