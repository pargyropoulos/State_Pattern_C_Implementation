#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/event.o \
	${OBJECTDIR}/fsm.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/menu.o \
	${OBJECTDIR}/state_option_edit.o \
	${OBJECTDIR}/state_option_nav.o \
	${OBJECTDIR}/state_special_nav.o \
	${OBJECTDIR}/state_standard_nav.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/statepattern_menu_nav.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/statepattern_menu_nav.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/statepattern_menu_nav ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/event.o: event.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/event.o event.c

${OBJECTDIR}/fsm.o: fsm.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/fsm.o fsm.c

${OBJECTDIR}/main.o: main.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.c

${OBJECTDIR}/menu.o: menu.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/menu.o menu.c

${OBJECTDIR}/state_option_edit.o: state_option_edit.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/state_option_edit.o state_option_edit.c

${OBJECTDIR}/state_option_nav.o: state_option_nav.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/state_option_nav.o state_option_nav.c

${OBJECTDIR}/state_special_nav.o: state_special_nav.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/state_special_nav.o state_special_nav.c

${OBJECTDIR}/state_standard_nav.o: state_standard_nav.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/state_standard_nav.o state_standard_nav.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
