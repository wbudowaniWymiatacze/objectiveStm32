# sets defines, include and source code directories proper for given target

# check the target given in the command, set variables values
# according to the target and execute 'all'
ifeq ($(MAKECMDGOALS),f103vb)
	-include Make/boards/f103/f103vb.mk
f103vb : all
endif
ifeq ($(MAKECMDGOALS),f107vc)
	-include Make/boards/f107/f107vc.mk
f107vc : all
endif
