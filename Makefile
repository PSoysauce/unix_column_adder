# Filename    Makefile
# Date        5/15/19
# Author      Patrick Soisson
# Email       patrick.b.soisson@gmail.com
# Copyright 2019, All Rights Reserved
#
# Description Makefile is used to create my executable and recompile anycode that has been updated  by default and will also make sure all files are up to date so
# the executable is always has the changes made. It also includes a clean target which will remove unnecessary files. This makefile uses implicit rules to automatically figure out which compiler to call based on the names of the object files

CXX = g++
CXXFLAGS = -Wall -Werror
CPPFLAGS = -I ~/tclap-1.2.1/include
PROJECTNAME = CS3377.HW5
EXECFILE = cs3377dirmond
OBJS = main.o tclap.o

.PHONY: clean all backup

.PRECIOUS:

all: $(EXECFILE)

$(EXECFILE): $(OBJS)
	$(CXX) -static -o $@ $(OBJS)
	
clean:
	rm -f $(OBJS) $(EXECFILE) *.o *~ \#*

backup: clean
	@mkdir -p ~/backups; chmod 700 ~/backups
	@$(eval CURDIRNAME := $(shell basename `pwd`))
	@$(eval MKBKUPNAME := ~/backups/$(PROJECTNAME)-$(shell date +'%Y.%m.%d-%H:%M:%S').tar.gz)
	@echo
	@echo Writing Backup file to: $(MKBKUPNAME)
	@echo
	@-tar zcfv $(MKBKUPNAME) ../$(CURDIRNAME)
	@chmod 600 $(MKBKUPNAME)
	@echo
	@echo Done!
