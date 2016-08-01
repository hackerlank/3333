#noinst_LTLIBRARIES = libplatcommon.la
lib_LTLIBRARIES=libplatcommon.la

platcommonincdir = $(top_srcdir)/3Party/protobuf-2.6.1/src

AM_CPPFLAGS = -I$(top_srcdir)/3Party/protobuf-2.6.1/src -I$(top_srcdir)/platcommon -I$(top_srcdir)/servercommon -I$(top_srcdir)/common/user -I$(top_srcdir)/common/server -I$(top_srcdir)/bwsdk/inc

libplatcommon_la_LIBADD =  

AUTOMAKE_OPTIONS = subdir-objects

PLATCOMM_SRC = unilightclient.pb.cc loggercommand.pb.cc config.pb.cc pmd.pb.cc sdkcommand.pb.cc chatcommand.pb.cc lobbypmd.pb.cc pushpmd.pb.cc gmcommand.pb.cc logincommand.pb.cc monitorpmd.pb.cc forwardcommand.pb.cc nullcommand.pb.cc
GBUFFER_SRC = gbuffer/Message.cpp gbuffer/MessageSerializer.cpp gbuffer/MessageDispatcher.cpp

libplatcommon_la_SOURCES = $(PLATCOMM_SRC) $(GBUFFER_SRC)
