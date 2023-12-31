#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/PIC18F4620_Drivers.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/PIC18F4620_Drivers.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=ECU_L/7_segments/segments_7.c ECU_L/BUTTON/button.c ECU_L/DC_MOTOR/dcmotor.c ECU_L/KEYPAD/keypad.c ECU_L/LCD/lcd.c ECU_L/LED/led.c ECU_L/RELAY/relay.c MCAL/ADC/adc.c MCAL/EEPROM/eeprom.c MCAL/GPIO/gpio.c MCAL/INTERRUPT/mcal_exrternal_interrupt.c MCAL/INTERRUPT/mcal_interrupt_manager.c MCAL/INTERRUPT/mcal_internal_interrupt.c app.c MCAL/TIMERS/TIMER0/timer0.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/ECU_L/7_segments/segments_7.p1 ${OBJECTDIR}/ECU_L/BUTTON/button.p1 ${OBJECTDIR}/ECU_L/DC_MOTOR/dcmotor.p1 ${OBJECTDIR}/ECU_L/KEYPAD/keypad.p1 ${OBJECTDIR}/ECU_L/LCD/lcd.p1 ${OBJECTDIR}/ECU_L/LED/led.p1 ${OBJECTDIR}/ECU_L/RELAY/relay.p1 ${OBJECTDIR}/MCAL/ADC/adc.p1 ${OBJECTDIR}/MCAL/EEPROM/eeprom.p1 ${OBJECTDIR}/MCAL/GPIO/gpio.p1 ${OBJECTDIR}/MCAL/INTERRUPT/mcal_exrternal_interrupt.p1 ${OBJECTDIR}/MCAL/INTERRUPT/mcal_interrupt_manager.p1 ${OBJECTDIR}/MCAL/INTERRUPT/mcal_internal_interrupt.p1 ${OBJECTDIR}/app.p1 ${OBJECTDIR}/MCAL/TIMERS/TIMER0/timer0.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/ECU_L/7_segments/segments_7.p1.d ${OBJECTDIR}/ECU_L/BUTTON/button.p1.d ${OBJECTDIR}/ECU_L/DC_MOTOR/dcmotor.p1.d ${OBJECTDIR}/ECU_L/KEYPAD/keypad.p1.d ${OBJECTDIR}/ECU_L/LCD/lcd.p1.d ${OBJECTDIR}/ECU_L/LED/led.p1.d ${OBJECTDIR}/ECU_L/RELAY/relay.p1.d ${OBJECTDIR}/MCAL/ADC/adc.p1.d ${OBJECTDIR}/MCAL/EEPROM/eeprom.p1.d ${OBJECTDIR}/MCAL/GPIO/gpio.p1.d ${OBJECTDIR}/MCAL/INTERRUPT/mcal_exrternal_interrupt.p1.d ${OBJECTDIR}/MCAL/INTERRUPT/mcal_interrupt_manager.p1.d ${OBJECTDIR}/MCAL/INTERRUPT/mcal_internal_interrupt.p1.d ${OBJECTDIR}/app.p1.d ${OBJECTDIR}/MCAL/TIMERS/TIMER0/timer0.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/ECU_L/7_segments/segments_7.p1 ${OBJECTDIR}/ECU_L/BUTTON/button.p1 ${OBJECTDIR}/ECU_L/DC_MOTOR/dcmotor.p1 ${OBJECTDIR}/ECU_L/KEYPAD/keypad.p1 ${OBJECTDIR}/ECU_L/LCD/lcd.p1 ${OBJECTDIR}/ECU_L/LED/led.p1 ${OBJECTDIR}/ECU_L/RELAY/relay.p1 ${OBJECTDIR}/MCAL/ADC/adc.p1 ${OBJECTDIR}/MCAL/EEPROM/eeprom.p1 ${OBJECTDIR}/MCAL/GPIO/gpio.p1 ${OBJECTDIR}/MCAL/INTERRUPT/mcal_exrternal_interrupt.p1 ${OBJECTDIR}/MCAL/INTERRUPT/mcal_interrupt_manager.p1 ${OBJECTDIR}/MCAL/INTERRUPT/mcal_internal_interrupt.p1 ${OBJECTDIR}/app.p1 ${OBJECTDIR}/MCAL/TIMERS/TIMER0/timer0.p1

# Source Files
SOURCEFILES=ECU_L/7_segments/segments_7.c ECU_L/BUTTON/button.c ECU_L/DC_MOTOR/dcmotor.c ECU_L/KEYPAD/keypad.c ECU_L/LCD/lcd.c ECU_L/LED/led.c ECU_L/RELAY/relay.c MCAL/ADC/adc.c MCAL/EEPROM/eeprom.c MCAL/GPIO/gpio.c MCAL/INTERRUPT/mcal_exrternal_interrupt.c MCAL/INTERRUPT/mcal_interrupt_manager.c MCAL/INTERRUPT/mcal_internal_interrupt.c app.c MCAL/TIMERS/TIMER0/timer0.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/PIC18F4620_Drivers.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F4620
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/ECU_L/7_segments/segments_7.p1: ECU_L/7_segments/segments_7.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_L/7_segments" 
	@${RM} ${OBJECTDIR}/ECU_L/7_segments/segments_7.p1.d 
	@${RM} ${OBJECTDIR}/ECU_L/7_segments/segments_7.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_L/7_segments/segments_7.p1 ECU_L/7_segments/segments_7.c 
	@-${MV} ${OBJECTDIR}/ECU_L/7_segments/segments_7.d ${OBJECTDIR}/ECU_L/7_segments/segments_7.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_L/7_segments/segments_7.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_L/BUTTON/button.p1: ECU_L/BUTTON/button.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_L/BUTTON" 
	@${RM} ${OBJECTDIR}/ECU_L/BUTTON/button.p1.d 
	@${RM} ${OBJECTDIR}/ECU_L/BUTTON/button.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_L/BUTTON/button.p1 ECU_L/BUTTON/button.c 
	@-${MV} ${OBJECTDIR}/ECU_L/BUTTON/button.d ${OBJECTDIR}/ECU_L/BUTTON/button.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_L/BUTTON/button.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_L/DC_MOTOR/dcmotor.p1: ECU_L/DC_MOTOR/dcmotor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_L/DC_MOTOR" 
	@${RM} ${OBJECTDIR}/ECU_L/DC_MOTOR/dcmotor.p1.d 
	@${RM} ${OBJECTDIR}/ECU_L/DC_MOTOR/dcmotor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_L/DC_MOTOR/dcmotor.p1 ECU_L/DC_MOTOR/dcmotor.c 
	@-${MV} ${OBJECTDIR}/ECU_L/DC_MOTOR/dcmotor.d ${OBJECTDIR}/ECU_L/DC_MOTOR/dcmotor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_L/DC_MOTOR/dcmotor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_L/KEYPAD/keypad.p1: ECU_L/KEYPAD/keypad.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_L/KEYPAD" 
	@${RM} ${OBJECTDIR}/ECU_L/KEYPAD/keypad.p1.d 
	@${RM} ${OBJECTDIR}/ECU_L/KEYPAD/keypad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_L/KEYPAD/keypad.p1 ECU_L/KEYPAD/keypad.c 
	@-${MV} ${OBJECTDIR}/ECU_L/KEYPAD/keypad.d ${OBJECTDIR}/ECU_L/KEYPAD/keypad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_L/KEYPAD/keypad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_L/LCD/lcd.p1: ECU_L/LCD/lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_L/LCD" 
	@${RM} ${OBJECTDIR}/ECU_L/LCD/lcd.p1.d 
	@${RM} ${OBJECTDIR}/ECU_L/LCD/lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_L/LCD/lcd.p1 ECU_L/LCD/lcd.c 
	@-${MV} ${OBJECTDIR}/ECU_L/LCD/lcd.d ${OBJECTDIR}/ECU_L/LCD/lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_L/LCD/lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_L/LED/led.p1: ECU_L/LED/led.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_L/LED" 
	@${RM} ${OBJECTDIR}/ECU_L/LED/led.p1.d 
	@${RM} ${OBJECTDIR}/ECU_L/LED/led.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_L/LED/led.p1 ECU_L/LED/led.c 
	@-${MV} ${OBJECTDIR}/ECU_L/LED/led.d ${OBJECTDIR}/ECU_L/LED/led.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_L/LED/led.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_L/RELAY/relay.p1: ECU_L/RELAY/relay.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_L/RELAY" 
	@${RM} ${OBJECTDIR}/ECU_L/RELAY/relay.p1.d 
	@${RM} ${OBJECTDIR}/ECU_L/RELAY/relay.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_L/RELAY/relay.p1 ECU_L/RELAY/relay.c 
	@-${MV} ${OBJECTDIR}/ECU_L/RELAY/relay.d ${OBJECTDIR}/ECU_L/RELAY/relay.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_L/RELAY/relay.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/ADC/adc.p1: MCAL/ADC/adc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/ADC" 
	@${RM} ${OBJECTDIR}/MCAL/ADC/adc.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/ADC/adc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/ADC/adc.p1 MCAL/ADC/adc.c 
	@-${MV} ${OBJECTDIR}/MCAL/ADC/adc.d ${OBJECTDIR}/MCAL/ADC/adc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/ADC/adc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/EEPROM/eeprom.p1: MCAL/EEPROM/eeprom.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/EEPROM" 
	@${RM} ${OBJECTDIR}/MCAL/EEPROM/eeprom.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/EEPROM/eeprom.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/EEPROM/eeprom.p1 MCAL/EEPROM/eeprom.c 
	@-${MV} ${OBJECTDIR}/MCAL/EEPROM/eeprom.d ${OBJECTDIR}/MCAL/EEPROM/eeprom.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/EEPROM/eeprom.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/GPIO/gpio.p1: MCAL/GPIO/gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL/GPIO/gpio.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/GPIO/gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/GPIO/gpio.p1 MCAL/GPIO/gpio.c 
	@-${MV} ${OBJECTDIR}/MCAL/GPIO/gpio.d ${OBJECTDIR}/MCAL/GPIO/gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/GPIO/gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/INTERRUPT/mcal_exrternal_interrupt.p1: MCAL/INTERRUPT/mcal_exrternal_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/INTERRUPT" 
	@${RM} ${OBJECTDIR}/MCAL/INTERRUPT/mcal_exrternal_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/INTERRUPT/mcal_exrternal_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/INTERRUPT/mcal_exrternal_interrupt.p1 MCAL/INTERRUPT/mcal_exrternal_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL/INTERRUPT/mcal_exrternal_interrupt.d ${OBJECTDIR}/MCAL/INTERRUPT/mcal_exrternal_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/INTERRUPT/mcal_exrternal_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/INTERRUPT/mcal_interrupt_manager.p1: MCAL/INTERRUPT/mcal_interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/INTERRUPT" 
	@${RM} ${OBJECTDIR}/MCAL/INTERRUPT/mcal_interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/INTERRUPT/mcal_interrupt_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/INTERRUPT/mcal_interrupt_manager.p1 MCAL/INTERRUPT/mcal_interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/MCAL/INTERRUPT/mcal_interrupt_manager.d ${OBJECTDIR}/MCAL/INTERRUPT/mcal_interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/INTERRUPT/mcal_interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/INTERRUPT/mcal_internal_interrupt.p1: MCAL/INTERRUPT/mcal_internal_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/INTERRUPT" 
	@${RM} ${OBJECTDIR}/MCAL/INTERRUPT/mcal_internal_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/INTERRUPT/mcal_internal_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/INTERRUPT/mcal_internal_interrupt.p1 MCAL/INTERRUPT/mcal_internal_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL/INTERRUPT/mcal_internal_interrupt.d ${OBJECTDIR}/MCAL/INTERRUPT/mcal_internal_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/INTERRUPT/mcal_internal_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/app.p1: app.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/app.p1.d 
	@${RM} ${OBJECTDIR}/app.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/app.p1 app.c 
	@-${MV} ${OBJECTDIR}/app.d ${OBJECTDIR}/app.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/app.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/TIMERS/TIMER0/timer0.p1: MCAL/TIMERS/TIMER0/timer0.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/TIMERS/TIMER0" 
	@${RM} ${OBJECTDIR}/MCAL/TIMERS/TIMER0/timer0.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/TIMERS/TIMER0/timer0.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/TIMERS/TIMER0/timer0.p1 MCAL/TIMERS/TIMER0/timer0.c 
	@-${MV} ${OBJECTDIR}/MCAL/TIMERS/TIMER0/timer0.d ${OBJECTDIR}/MCAL/TIMERS/TIMER0/timer0.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/TIMERS/TIMER0/timer0.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/ECU_L/7_segments/segments_7.p1: ECU_L/7_segments/segments_7.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_L/7_segments" 
	@${RM} ${OBJECTDIR}/ECU_L/7_segments/segments_7.p1.d 
	@${RM} ${OBJECTDIR}/ECU_L/7_segments/segments_7.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_L/7_segments/segments_7.p1 ECU_L/7_segments/segments_7.c 
	@-${MV} ${OBJECTDIR}/ECU_L/7_segments/segments_7.d ${OBJECTDIR}/ECU_L/7_segments/segments_7.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_L/7_segments/segments_7.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_L/BUTTON/button.p1: ECU_L/BUTTON/button.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_L/BUTTON" 
	@${RM} ${OBJECTDIR}/ECU_L/BUTTON/button.p1.d 
	@${RM} ${OBJECTDIR}/ECU_L/BUTTON/button.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_L/BUTTON/button.p1 ECU_L/BUTTON/button.c 
	@-${MV} ${OBJECTDIR}/ECU_L/BUTTON/button.d ${OBJECTDIR}/ECU_L/BUTTON/button.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_L/BUTTON/button.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_L/DC_MOTOR/dcmotor.p1: ECU_L/DC_MOTOR/dcmotor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_L/DC_MOTOR" 
	@${RM} ${OBJECTDIR}/ECU_L/DC_MOTOR/dcmotor.p1.d 
	@${RM} ${OBJECTDIR}/ECU_L/DC_MOTOR/dcmotor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_L/DC_MOTOR/dcmotor.p1 ECU_L/DC_MOTOR/dcmotor.c 
	@-${MV} ${OBJECTDIR}/ECU_L/DC_MOTOR/dcmotor.d ${OBJECTDIR}/ECU_L/DC_MOTOR/dcmotor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_L/DC_MOTOR/dcmotor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_L/KEYPAD/keypad.p1: ECU_L/KEYPAD/keypad.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_L/KEYPAD" 
	@${RM} ${OBJECTDIR}/ECU_L/KEYPAD/keypad.p1.d 
	@${RM} ${OBJECTDIR}/ECU_L/KEYPAD/keypad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_L/KEYPAD/keypad.p1 ECU_L/KEYPAD/keypad.c 
	@-${MV} ${OBJECTDIR}/ECU_L/KEYPAD/keypad.d ${OBJECTDIR}/ECU_L/KEYPAD/keypad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_L/KEYPAD/keypad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_L/LCD/lcd.p1: ECU_L/LCD/lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_L/LCD" 
	@${RM} ${OBJECTDIR}/ECU_L/LCD/lcd.p1.d 
	@${RM} ${OBJECTDIR}/ECU_L/LCD/lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_L/LCD/lcd.p1 ECU_L/LCD/lcd.c 
	@-${MV} ${OBJECTDIR}/ECU_L/LCD/lcd.d ${OBJECTDIR}/ECU_L/LCD/lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_L/LCD/lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_L/LED/led.p1: ECU_L/LED/led.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_L/LED" 
	@${RM} ${OBJECTDIR}/ECU_L/LED/led.p1.d 
	@${RM} ${OBJECTDIR}/ECU_L/LED/led.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_L/LED/led.p1 ECU_L/LED/led.c 
	@-${MV} ${OBJECTDIR}/ECU_L/LED/led.d ${OBJECTDIR}/ECU_L/LED/led.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_L/LED/led.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_L/RELAY/relay.p1: ECU_L/RELAY/relay.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_L/RELAY" 
	@${RM} ${OBJECTDIR}/ECU_L/RELAY/relay.p1.d 
	@${RM} ${OBJECTDIR}/ECU_L/RELAY/relay.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_L/RELAY/relay.p1 ECU_L/RELAY/relay.c 
	@-${MV} ${OBJECTDIR}/ECU_L/RELAY/relay.d ${OBJECTDIR}/ECU_L/RELAY/relay.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_L/RELAY/relay.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/ADC/adc.p1: MCAL/ADC/adc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/ADC" 
	@${RM} ${OBJECTDIR}/MCAL/ADC/adc.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/ADC/adc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/ADC/adc.p1 MCAL/ADC/adc.c 
	@-${MV} ${OBJECTDIR}/MCAL/ADC/adc.d ${OBJECTDIR}/MCAL/ADC/adc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/ADC/adc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/EEPROM/eeprom.p1: MCAL/EEPROM/eeprom.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/EEPROM" 
	@${RM} ${OBJECTDIR}/MCAL/EEPROM/eeprom.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/EEPROM/eeprom.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/EEPROM/eeprom.p1 MCAL/EEPROM/eeprom.c 
	@-${MV} ${OBJECTDIR}/MCAL/EEPROM/eeprom.d ${OBJECTDIR}/MCAL/EEPROM/eeprom.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/EEPROM/eeprom.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/GPIO/gpio.p1: MCAL/GPIO/gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL/GPIO/gpio.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/GPIO/gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/GPIO/gpio.p1 MCAL/GPIO/gpio.c 
	@-${MV} ${OBJECTDIR}/MCAL/GPIO/gpio.d ${OBJECTDIR}/MCAL/GPIO/gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/GPIO/gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/INTERRUPT/mcal_exrternal_interrupt.p1: MCAL/INTERRUPT/mcal_exrternal_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/INTERRUPT" 
	@${RM} ${OBJECTDIR}/MCAL/INTERRUPT/mcal_exrternal_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/INTERRUPT/mcal_exrternal_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/INTERRUPT/mcal_exrternal_interrupt.p1 MCAL/INTERRUPT/mcal_exrternal_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL/INTERRUPT/mcal_exrternal_interrupt.d ${OBJECTDIR}/MCAL/INTERRUPT/mcal_exrternal_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/INTERRUPT/mcal_exrternal_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/INTERRUPT/mcal_interrupt_manager.p1: MCAL/INTERRUPT/mcal_interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/INTERRUPT" 
	@${RM} ${OBJECTDIR}/MCAL/INTERRUPT/mcal_interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/INTERRUPT/mcal_interrupt_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/INTERRUPT/mcal_interrupt_manager.p1 MCAL/INTERRUPT/mcal_interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/MCAL/INTERRUPT/mcal_interrupt_manager.d ${OBJECTDIR}/MCAL/INTERRUPT/mcal_interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/INTERRUPT/mcal_interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/INTERRUPT/mcal_internal_interrupt.p1: MCAL/INTERRUPT/mcal_internal_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/INTERRUPT" 
	@${RM} ${OBJECTDIR}/MCAL/INTERRUPT/mcal_internal_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/INTERRUPT/mcal_internal_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/INTERRUPT/mcal_internal_interrupt.p1 MCAL/INTERRUPT/mcal_internal_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL/INTERRUPT/mcal_internal_interrupt.d ${OBJECTDIR}/MCAL/INTERRUPT/mcal_internal_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/INTERRUPT/mcal_internal_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/app.p1: app.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/app.p1.d 
	@${RM} ${OBJECTDIR}/app.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/app.p1 app.c 
	@-${MV} ${OBJECTDIR}/app.d ${OBJECTDIR}/app.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/app.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/TIMERS/TIMER0/timer0.p1: MCAL/TIMERS/TIMER0/timer0.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/TIMERS/TIMER0" 
	@${RM} ${OBJECTDIR}/MCAL/TIMERS/TIMER0/timer0.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/TIMERS/TIMER0/timer0.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/TIMERS/TIMER0/timer0.p1 MCAL/TIMERS/TIMER0/timer0.c 
	@-${MV} ${OBJECTDIR}/MCAL/TIMERS/TIMER0/timer0.d ${OBJECTDIR}/MCAL/TIMERS/TIMER0/timer0.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/TIMERS/TIMER0/timer0.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/PIC18F4620_Drivers.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/PIC18F4620_Drivers.${IMAGE_TYPE}.map  -D__DEBUG=1  -mdebugger=none  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/PIC18F4620_Drivers.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} ${DISTDIR}/PIC18F4620_Drivers.${IMAGE_TYPE}.hex 
	
else
${DISTDIR}/PIC18F4620_Drivers.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/PIC18F4620_Drivers.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/PIC18F4620_Drivers.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
