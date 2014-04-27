ARCH="`uname -s`"
LINUX="Linux"
MAC="Darwin"
tools = $(subst \,/,$(GOPATH)/src/git.code4.in/mobilegameserver/tools)
%.pb.go:	%.proto
	@if [ $(ARCH) = $(LINUX) ];\
	then \
		echo $(tools)/protoc-linux --plugin=protoc-gen-go=$(tools)/protoc-gen-go-linux --go_out=. $< ;\
		$(tools)/protoc-linux --plugin=protoc-gen-go=$(tools)/protoc-gen-go-linux --go_out=. $< ;\
	elif [ $(ARCH) = $(MAC) ]; \
	then \
		echo $(tools)/protoc-mac --plugin=protoc-gen-go=$(tools)/protoc-gen-go-mac --go_out=. $< ;\
		$(tools)/protoc-mac --plugin=protoc-gen-go=$(tools)/protoc-gen-go-mac --go_out=. $< ;\
	else \
		echo $(tools)/protoc.exe --plugin=protoc-gen-go=$(tools)/protoc-gen-go.exe --go_out=. $< ;\
		$(tools)/protoc.exe --plugin=protoc-gen-go=$(tools)/protoc-gen-go.exe --go_out=. $< ;\
	fi

define prototype
	if [ $(ARCH) = $(LINUX) ];\
	then \
		echo $(tools)/prototype $1 ;\
		$(tools)/prototype $1 ;\
	elif [ $(ARCH) = $(MAC) ]; \
	then \
		echo echo $(tools)/prototype $1 ;\
		$(tools)/prototype $1 ;\
	else \
		echo $(tools)/prototype.exe $1 ;\
		$(tools)/prototype.exe $1 ;\
	fi
endef
all:    regenerate

regenerate:
	rm -f *.pb.go
	rm -f config/*.pb.go
	rm -rf $(GOPATH)/pkg/linux_amd64/git.code4.in/mobilegameserver/platcommon
	rm -rf $(GOPATH)/pkg/linux_amd64/git.code4.in/mobilegameserver/platcommon.a
	make Pmd.pb.go
	make Config.pb.go
	make LoginCommand.pb.go ;$(call prototype, LoginCommand.pb.go)
	sh $(tools)/enummap.sh Pmd

