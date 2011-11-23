/************************************************************************/
/*																		*/
/*	Board_Defs.h --	Board Customization for Digilent Cerebot 32MX4		*/
/*																		*/
/************************************************************************/
/*	Author:		Gene Apperson											*/
/*	Copyright 2011, Digilent. All rights reserved						*/
/************************************************************************/
/*  File Description:													*/
/*																		*/
/* This file contains the board specific declartions and data structure	*/
/* to customize the chipKIT MPIDE for use with the Digilent Cerebot		*/
/* 32MX4 board.															*/
/*																		*/
/* This code is based on earlier work:									*/
/*		Copyright (c) 2010, 2011 by Mark Sproul							*/
/*		Copyright (c) 2005, 2006 by David A. Mellis						*/
/*																		*/
/************************************************************************/
/*  Revision History:													*/
/*																		*/
/*	10/06/2011(GeneA): Created											*/
/*																		*/
/************************************************************************/
//*	This library is free software; you can redistribute it and/or
//*	modify it under the terms of the GNU Lesser General Public
//*	License as published by the Free Software Foundation; either
//*	version 2.1 of the License, or (at your option) any later version.
//*	
//*	This library is distributed in the hope that it will be useful,
//*	but WITHOUT ANY WARRANTY; without even the implied warranty of
//*	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//*	Lesser General Public License for more details.
//*	
//*	You should have received a copy of the GNU Lesser General
//*	Public License along with this library; if not, write to the
//*	Free Software Foundation, Inc., 59 Temple Place, Suite 330,
//*	Boston, MA  02111-1307  USA
/************************************************************************/

#if !defined(BOARD_DEFS_H)
#define BOARD_DEFS_H

#include <inttypes.h>

/* ------------------------------------------------------------ */
/*				Public Board Declarations						*/
/* ------------------------------------------------------------ */
/* The following define symbols that can be used in a sketch to
** refer to periperhals on the board generically.
*/

#define	_BOARD_NAME_	"Cerebot 32MX4"

/* Define the processor on the board.
*/
#define	_CPU_NAME_	"32MX460F512L"
#define	FLASHEND	(((512 - 4) * 1024L) - 1)
#define	RAMEND		((32 * 1024L) - 1)

/* Define the peripherals available on the board.
*/
#define	NUM_DIGITAL_PINS	70
#define	NUM_ANALOG_PINS		14
#define	NUM_OC_PINS			5
#define	NUM_IC_PINS			5
#define	NUM_TCK_PINS		4
#define	NUM_INT_PINS		5

#define	NUM_SERIAL_PORTS	2
#define	NUM_SPI_PORTS		1
#define	NUM_I2C_PORTS		1

#define	NUM_DSPI_PORTS		2
#define NUM_DTWI_PORTS		2

/* Define I/O devices on the board.
*/
#define	NUM_LED				4
#define NUM_BTN				2
#define	NUM_SWT				0
#define NUM_SERVO			8

/* ------------------------------------------------------------ */
/*						LED Declarations						*/
/* ------------------------------------------------------------ */

/* Define the pin numbers for the LEDs
*/
#define	PIN_LED1	60
#define	PIN_LED2	61
#define	PIN_LED3	62
#define	PIN_LED4	63

/* ------------------------------------------------------------ */
/*					Button Declarations							*/
/* ------------------------------------------------------------ */

/* Define the pin numbers for the buttons
*/
#define	PIN_BTN1	42	
#define	PIN_BTN2	43

/* ------------------------------------------------------------ */
/*					Switch Declarations							*/
/* ------------------------------------------------------------ */

/* No switches on this board.
*/

/* ------------------------------------------------------------ */
/*					Servo Pin Declarations						*/
/* ------------------------------------------------------------ */

/* Define the pin numbers for the servo connectors
*/
#define	PIN_SERVO1	16
#define	PIN_SERVO2	17
#define	PIN_SERVO3	18
#define	PIN_SERVO4	19
#define	PIN_SERVO5	20
#define	PIN_SERVO6	21
#define	PIN_SERVO7	22
#define	PIN_SERVO8	23

/* ------------------------------------------------------------ */
/*					Timer Pin Declarations						*/
/* ------------------------------------------------------------ */

#define PIN_OC1		49
#define	PIN_OC2		25
#define	PIN_OC3		29
#define	PIN_OC4		37
#define	PIN_OC5		14

#define PIN_IC1		50
#define PIN_IC2		26
#define PIN_IC3		30
#define PIN_IC4		38
#define	PIN_IC5		66

//#define	PIN_TCK1	not connected
#define	PIN_TCK2	27
#define	PIN_TCK3	31
#define	PIN_TCK4	39
#define	PIN_TCK5	67

/* ------------------------------------------------------------ */
/*					Interrupt Pin Declarations					*/
/* ------------------------------------------------------------ */

#define	PIN_INT0	49
#define	PIN_INT1	48
#define PIN_INT2	51
#define	PIN_INT3	68
#define	PIN_INT4	69

/* ------------------------------------------------------------ */
/*					SPI Pin Declarations						*/
/* ------------------------------------------------------------ */
/* These symbols are defined for compatibility with the original
** SPI library and the original pins_arduino.h
*/
const static uint8_t SS   = 8;		// PIC32 SS2
const static uint8_t MOSI = 9;		// PIC32 SDO2
const static uint8_t MISO = 10;		// PIC32 SDI2
const static uint8_t SCK  = 11;		// PIC32 SCK2

/* The Digilent DSPI library uses these ports.
**		DSPI0	connector JB
**		DSPI1	connector J1
*/
#define	PIN_DSPI0_SS	8
#define	PIN_DSPI1_SS	26

/* ------------------------------------------------------------ */
/*					Analog Pins									*/
/* ------------------------------------------------------------ */
/* Define symbols for accessing the analog pins. This table is
** used to map an analog pin number to the corresponding digital
** pin number.
*/
#define	A0		52
#define	A1		53
#define A2		54
#define A3		55
#define A4		56
#define A5		57
#define A6		58
#define A7		59
#define A8		60
#define A9		61
#define A10		62
#define A11		63
#define A12		12
#define	A13		15

/* ------------------------------------------------------------ */
/*				Internal Declarations							*/
/* ------------------------------------------------------------ */
/* The following declarations are used to map peripherals for	*/
/* the core and libraries and to provide configuration options	*/
/* for the core. They are not normally needed by a user sketch.	*/
/* ------------------------------------------------------------ */

#if defined(OPT_BOARD_INTERNAL)

/* ------------------------------------------------------------ */
/*					Pin Mapping Macros							*/
/* ------------------------------------------------------------ */
/* Macros used to access the port and pin mapping tables.
** These are mostly generic, but some of them may be board specific.
** These perform slightly better as macros compared to inline functions
*/
#define digitalPinToPort(P) ( digital_pin_to_port_PGM[P]  )
#define digitalPinToBitMask(P) ( digital_pin_to_bit_mask_PGM[P]  )
#define digitalPinToTimerOC(P) ( (digital_pin_to_timer_PGM[P] & _MSK_TIMER_OC)  )
#define digitalPinToTimerIC(P) ( (digital_pin_to_timer_PGM[P] & _MSK_TIMER_IC)  )
#define digitalPinToTimerTCK(P) ( (digital_pin_to_timer_PGM[P] & _MSK_TIMER_TCK)  )
#define	digitalPinToTimer(P)	digitalPinToTimerOC(P)
#define portRegisters(P) ( port_to_tris_PGM[P])
#define portModeRegister(P) ( (volatile uint32_t *)port_to_tris_PGM[P] )
#define portInputRegister(P) ( (volatile uint32_t *)(port_to_tris_PGM[P] + 0x0010) )
#define portOutputRegister(P) ( (volatile uint32_t *)(port_to_tris_PGM[P] + 0x0020) )
#define	digitalPinToAnalog(P) ( ((P) < NUM_ANALOG_PINS) ? (P) : digital_pin_to_analog_PGM[P] )
#define analogInPinToChannel(P) ( analog_pin_to_channel_PGM[P]  )

/* ------------------------------------------------------------ */
/*				Core Configuration Declarations					*/
/* ------------------------------------------------------------ */
/*																*/
/* These are conditional compilation switches that control the	*/
/* board core configuration functions. These functions provide	*/
/* hooks that can call from some of the core functions into		*/
/* functions defined below that can be used to extend or		*/
/* replace the default behavior of the core function. To use	*/
/* this, enter the appropriate code into the appropriate		*/
/* function skeleton below and then set the appropriate switch	*/
/* value to 1. This will cause the configuration function to be	*/
/* compiled into the build and will cause the code to call the	*/
/* hook function to be compiled into the core function.			*/
/*																*/
/* ------------------------------------------------------------ */

#define	OPT_BOARD_INIT			0	//board needs no special init code
#define	OPT_BOARD_DIGITAL_IO	0	//board does not extend digital i/o functions
#define	OPT_BOARD_ANALOG_READ	0	//board does not extend analogRead
#define	OPT_BOARD_ANALOG_WRITE	0	//board does not extend analogWrite

/* ------------------------------------------------------------ */
/*					Serial Port Declarations					*/
/* ------------------------------------------------------------ */

#define	_IPL_UART_ISR	ipl2	//interrupt priority for ISR
#define	_IPL_UART_IPC	2		//interrupt priority for IPC register
#define	_SPL_UART_IPC	0		//interrupt subpriority for IPC register

/* This board uses the USB port for the serial interface to
** talk to the IDE.
*/
#define	_USE_USB_FOR_SERIAL_

/* Serial port 0 uses UART1
*/
#define	_SER0_BASE		_UART1_BASE_ADDRESS
#define	_SER0_IRQ		_UART1_ERR_IRQ
#define	_SER0_VECTOR	_UART_1_VECTOR

/* Serial port 1 uses UART2
*/
#define	_SER1_BASE		_UART2_BASE_ADDRESS
#define	_SER1_IRQ		_UART2_ERR_IRQ
#define	_SER1_VECTOR	_UART_2_VECTOR

/* ------------------------------------------------------------ */
/*					SPI Port Declarations						*/
/* ------------------------------------------------------------ */

#define	_IPL_SPI_ISR	ipl3	//interrupt priority for the ISR
#define	_IPL_SPI_IPC	3		//interrupt priority for the IPC register
#define	_SPL_SPI_IPC	0		//interrupt subpriority for the IPC register

/* The standard SPI port uses SPI2. Connector JB
*/
#define	_SPI_BASE		_SPI2_BASE_ADDRESS
#define _SPI_ERR_IRQ	_SPI2_ERR_IRQ
#define	_SPI_RX_IRQ		_SPI2_RX_IRQ
#define	_SPI_TX_IRQ		_SPI2_TX_IRQ
#define	_SPI_VECTOR		_SPI_2_VECTOR

/* The Digilent DSPI library uses these ports.
**		DSPI0	connector JB
**		DSPI1	connector J1
*/
#define	_DSPI0_BASE			_SPI2_BASE_ADDRESS
#define	_DSPI0_ERR_IRQ		_SPI2_ERR_IRQ
#define	_DSPI0_RX_IRQ		_SPI2_RX_IRQ
#define	_DSPI0_TX_IRQ		_SPI2_TX_IRQ
#define	_DSPI0_VECTOR		_SPI_2_VECTOR

#define	_DSPI1_BASE			_SPI1_BASE_ADDRESS
#define	_DSPI1_ERR_IRQ		_SPI1_ERR_IRQ
#define	_DSPI1_RX_IRQ		_SPI1_RX_IRQ
#define	_DSPI1_TX_IRQ		_SPI1_TX_IRQ
#define	_DSPI1_VECTOR		_SPI_1_VECTOR

/* ------------------------------------------------------------ */
/*					I2C Port Declarations						*/
/* ------------------------------------------------------------ */

#define	_IPL_TWI_ISR	ipl3	//interrupt priority for ISR
#define	_IPL_TWI_IPC	3		//interrupt priority for IPC register
#define	_SPL_TWI_IPC	0		//interrupt subpriority for IPC register

/* The standard I2C port uses I2C1 on connector J6. This I2C
** bus has fixed pull-ups and contains the EEPROM and DAC.
*/
#define	_TWI_BASE		_I2C1_BASE_ADDRESS
#define	_TWI_BUS_IRQ	_I2C1_BUS_IRQ
#define	_TWI_SLV_IRQ	_I2C1_SLAVE_IRQ
#define	_TWI_MST_IRQ	_I2C1_MASTER_IRQ
#define	_TWI_VECTOR		_I2C_1_VECTOR

/* Declarations for Digilent DTWI library.
**		DTWI0 is on I2C2, connector J2
**		DTWI1 is on I2C1, connector J6.
**
** DTWI1 has the I2C EEPROM and DAC.
*/
#define	_DTWI0_BASE		_I2C2_BASE_ADDRESS
#define	_DTWI0_BUS_IRQ	_I2C2_BUS_IRQ
#define	_DTWI0_SLV_IRQ	_I2C2_SLAVE_IRQ
#define	_DTWI0_MST_IRQ	_I2C2_MASTER_IRQ
#define	_DTWI0_VECTOR	_I2C_2_VECTOR

#define	_DTWI1_BASE		_I2C1_BASE_ADDRESS
#define	_DTWI1_BUS_IRQ	_I2C1_BUS_IRQ
#define	_DTWI1_SLV_IRQ	_I2C1_SLAVE_IRQ
#define	_DTWI1_MST_IRQ	_I2C1_MASTER_IRQ
#define	_DTWI1_VECTOR	_I2C_1_VECTOR

/* ------------------------------------------------------------ */
/*					A/D Converter Declarations					*/
/* ------------------------------------------------------------ */


/* ------------------------------------------------------------ */

#endif		//OPT_BOARD_INTERNAL

/* ------------------------------------------------------------ */
/*					Data Definitions							*/
/* ------------------------------------------------------------ */

/* The following declare externals to access the pin mapping
** tables.
*/

#if !defined(_BOARD_DATA_)

extern const uint32_t	port_to_tris_PGM[];
extern const uint8_t	digital_pin_to_port_PGM[];
extern const uint16_t	digital_pin_to_bit_mask_PGM[];
extern const uint8_t	digital_pin_to_timer_PGM[];
extern const uint8_t 	digital_pin_to_analog_PGM[];
extern const uint8_t	analog_pin_to_channel_PGM[];

#endif

/* The following declarations define data used in the pin mapping.
** These will be compiled when compiling main.cpp so that this
** header file can be included in multiple modules, be we only 
** get one copy of the data.
*/

#if defined(_BOARD_DATA_)

/* ------------------------------------------------------------ */
/* This table is used to map from port number to the address of
** the TRIS register for the port. This is used for setting the
** pin direction.
*/
const uint32_t port_to_tris_PGM[] = {
	NOT_A_PORT,				//index value 0 is not used

#if defined(_PORTA)
	(uint32_t)&TRISA,
#else
	NOT_A_PORT,
#endif

#if defined(_PORTB)
	(uint32_t)&TRISB,
#else
	NOT_A_PORT,
#endif

#if defined(_PORTC)
	(uint32_t)&TRISC,
#else
	NOT_A_PORT,
#endif

#if defined(_PORTD)
	(uint32_t)&TRISD,
#else
	NOT_A_PORT,
#endif

#if defined(_PORTE)
	(uint32_t)&TRISE,
#else
	NOT_A_PORT,
#endif

#if defined(_PORTF)
	(uint32_t)&TRISF,
#else
	NOT_A_PORT,
#endif

#if defined(_PORTG)
	(uint32_t)&TRISG,
#else
	NOT_A_PORT,
#endif

	NOT_A_PORT,
};

/* ------------------------------------------------------------ */
/* This table is used to map the digital pin number to the port
** containing that pin.
*/
const uint8_t	digital_pin_to_port_PGM[] = {
    // Connector JA
	_IOPORT_PE,		//  0 RE0 		PMD0
	_IOPORT_PE,		//  1 RE1		PMD1
	_IOPORT_PE,		//  2 RE2		PMD2
	_IOPORT_PE,		//  3 RE3		PMD3
	_IOPORT_PE,		//  4 RE4		PMD4
	_IOPORT_PE,		//  5 RE5		PMD5
	_IOPORT_PE,		//  6 RE6		PMD6
	_IOPORT_PE,		//  7 RE7		PMD7

    // Connector JB
	_IOPORT_PG,		//  8 RG9		PMA2/SS2/CN11/RG9
	_IOPORT_PG,		//  9 RG8		PMA3/SDO2/CN10/RG8
	_IOPORT_PG,		// 10 RG7		PMA4/SDI2/CN9/RG7
	_IOPORT_PG,		// 11 RG6		PMA5/SCK2/CN8/RG6
	_IOPORT_PB,		// 12 RB15		PMALL/PMA0/AN15/OCFB/CN12/RB15
	_IOPORT_PD,		// 13 RD5		PMRD/CN14/RD5
	_IOPORT_PD,		// 14 RD4		PMWR/OC5/CN13
	_IOPORT_PB,		// 15 RB14		PMALH/PMA1/AN14/RB14

    // Connector JC
	_IOPORT_PG,		// 16 RG12		TRD1/RG12					(S1)
	_IOPORT_PG,		// 17 RG13		TRD0/RG13					(S2)
	_IOPORT_PG,		// 18 RG14		TRD2/RG14					(S3)
	_IOPORT_PG,		// 19 RG15		RG15						(S4)
	_IOPORT_PG,		// 20 RG0		PMD8/RG0					(S5)
	_IOPORT_PG,		// 21 RG1		PMD9/RG1					(S6)
	_IOPORT_PF,		// 22 RF0		PMD11/RF0					(S7)
	_IOPORT_PF,		// 23 RF1		PMD10/RF1					(S8)

    // Connector JD
	_IOPORT_PD,		// 24 RD7		PMD15/CN16/RD7
	_IOPORT_PD,		// 25 RD1		OC2/RD1
	_IOPORT_PD,		// 26 RD9		IC2/SS1/RD9
	_IOPORT_PC,		// 27 RC1		T2CK/RC1
	_IOPORT_PD,		// 28 RD6		PMD14/CN15/RD6
	_IOPORT_PD,		// 29 RD2		OC3/RD2
	_IOPORT_PD,		// 30 RD10		IC3/SCK1/PMCS2/PMA15/RD10
	_IOPORT_PC,		// 31 RC2		T3CK/RC2

    // Connector JE
	_IOPORT_PD,		// 32 RD14		CN20/U1CTS/RD14
	_IOPORT_PD,		// 33 RD15		U1RTS/BCLK1/CN21/RD15
	_IOPORT_PF,		// 34 RF2		U1RX/RF2
	_IOPORT_PF,		// 35 RF8		U1TX/RF8
	_IOPORT_PD,		// 36 RD13		PMD13/CN19/RD13
	_IOPORT_PD,		// 37 RD3		OC4/RD3
	_IOPORT_PD,		// 38 RD11		IC4/PMCS1/PMA14/RD11
	_IOPORT_PC,		// 39 RC3		T4CK/RC3    
    
    // Connector JF
	_IOPORT_PA,		// 40 RA2		SCL2/RA2
	_IOPORT_PA,		// 41 RA3		SDA2/RA3
	_IOPORT_PA,		// 42 RA6		TRCLK/RA6					(BTN1)
	_IOPORT_PA,		// 43 RA7		TRD3/RA7					(BTN2)

    // Connector JH
	_IOPORT_PF,		// 44 RF12		U2CTS/RF12
	_IOPORT_PF,		// 45 RF13		U2RTS/BCLK2/RF13
	_IOPORT_PF,		// 46 RF4		PMA9/U2RX/CN17/RF4
	_IOPORT_PF,		// 47 RF5		PMA8/U2TX/CN18/RF5
	_IOPORT_PE,		// 48 RE8		INT1/RE8
	_IOPORT_PD,		// 49 RD0		SDO1/OC1/INT0/RD0
	_IOPORT_PD,		// 50 RD8		IC1/RTCC/RD8
	_IOPORT_PE,		// 51 RE9		INT2/RE9
    
    // Connector JJ
	_IOPORT_PB,		// 52 RB0		PGD1/FMUD1/AN0/CN2/RB0
	_IOPORT_PB,		// 53 RB1		PGC1/FMUC1/AN1/CN3/RB1
	_IOPORT_PB,		// 54 RB2		C2IN-/AN2/CN4/RB2
	_IOPORT_PB,		// 55 RB3		C2IN+/AN3/CN5/RB3
	_IOPORT_PB,		// 56 RB4		C1IN-/AN4/CN6/RB4
	_IOPORT_PB,		// 57 RB5		VBUSON/C1IN+/AN5/CN7/RB5
	_IOPORT_PB,		// 58 RB8		C1OUT/AN8/RB8
	_IOPORT_PB,		// 59 RB9		C2OUT/AN9/RB9

    // Connector JK
	_IOPORT_PB,		// 60 RB10		CVREFOUT/PMA13/AN10/RB10	(LD1)
	_IOPORT_PB,		// 61 RB11		PMA12/AN11/RB11				(LD2)
	_IOPORT_PB,		// 62 RB12		PMA11/AN12/RB12				(LD3)
	_IOPORT_PB,		// 63 RB13		PMA10/AN13/RB13				(LD4)
	_IOPORT_PA,		// 64 RA9		PMA7/VREF-/CVREF-/RA9
	_IOPORT_PA,		// 65 RA10		PMA6/VREF+/CVREF+/RA10
	_IOPORT_PD,		// 66 RD12		PMD12/IC5/RD12
	_IOPORT_PC,		// 67 RC4		SDI1/T5CK/RC4
	
	//J6 I2C PORT 1
	_IOPORT_PA,		// 68 RA14		SCL1/INT3/RA14				(P32_SCL1)
	_IOPORT_PA,		// 69 RA15		SDA1/INT4/RA15				(P32_SDA1)
};

/* ------------------------------------------------------------ */
/* This table is used to map from digital pin number to a bit mask
** for the corresponding bit within the port.
*/
const uint16_t	digital_pin_to_bit_mask_PGM[] = {
    // Connector JA
	_BV( 0 ) ,	// 0 RE 0		PMD0
	_BV( 1 ) ,	// 1 RE 1		PMD1		
	_BV( 2 ) ,	// 2 RE 2		PMD2
	_BV( 3 ) ,	// 3 RE 3		PMD3
	_BV( 4 ) ,	// 4 RE 4		PMD4
	_BV( 5 ) ,	// 5 RE 5		PMD5
	_BV( 6 ) ,	// 6 RE 6		PMD6
	_BV( 7 ) ,	// 7 RE 7		PMD7

    // Connector JB
	_BV( 9 ) ,	// 8 RG9		PMA2/SS2/CN11/RG9
	_BV( 8 ) ,	// 9 RG8		PMA3/SDO2/CN10/RG8
	_BV( 7 ) ,	// 10 RG7		PMA4/SDI2/CN9/RG7
	_BV( 6 ) ,	// 11 RG6		PMA5/SCK2/CN8/RG6
	_BV( 15 ) ,	// 12 RB15		INT3 or PMALL/PMA0/AN15/OCFB/CN12/RB15 (Selected with JP3)
	_BV( 5 ) ,	// 13 RD5		PMRD/CN14/RD5
	_BV( 4 ) ,	// 14 RD4		PMWR/OC5/CN13
	_BV( 14 ) ,	// 15 RB14		PMALH/PMA1/AN14/RB14

    // Connector JC
	_BV( 12 ) ,	// 16 RG12		TRD1/RG12					(S1)
	_BV( 13 ) ,	// 17 RG13		TRD0/RG13					(S2)
	_BV( 14 ) ,	// 18 RG14		TRD2/RG14					(S3)
	_BV( 15 ) ,	// 19 RG15		RG15						(S4)
	_BV( 0 ) ,	// 20 RG0		PMD8/RG0					(S5)
	_BV( 1 ) ,	// 21 RG1		PMD9/RG1					(S6)
	_BV( 0 ) ,	// 22 RF0		PMD11/RF0					(S7)
	_BV( 1 ) ,	// 23 RF1		PMD10/RF1					(S8)

    // Connector JD
	_BV( 7 ) ,	// 24 RD7		PMD15/CN16/RD7
	_BV( 1 ) ,	// 25 RD1		OC2/RD1
	_BV( 9 ) ,	// 26 RD9		TC2/SS1/RD9
	_BV( 1 ) ,	// 27 RC1		T2CK/RC1
	_BV( 6 ) ,	// 28 RD6		PMD14/CN15/RD6
	_BV( 2 ) ,	// 29 RD2		OC3/RD2
	_BV( 10 ) ,	// 30 RD10		IC3/SCK1/PMCS2/PMA15/RD10
	_BV( 2 ) ,	// 31 RC2		T3CK/RC2

    // Connector JE
	_BV( 14 ) ,	// 32 RD14		CN20/U1CTS/RD14
	_BV( 15 ) ,	// 33 RD15		U1RTS/BCLK1/CN21/RD15
	_BV( 2 ) ,	// 34 RF2		U1RX/RF2
	_BV( 8 ) ,	// 35 RF8		U1TX/RF8
	_BV( 13 ) ,	// 36 RD13		PMD13/CN19/RD13
	_BV( 3 ) ,	// 37 RD3		OC4/RD3
	_BV( 11 ) ,	// 38 RD11		IC4/PMCS1/PMA14/RD11
	_BV( 3 ) ,	// 39 RC3		T4CK/RC3

    // Connector JF
	_BV( 2 ) ,	// 40 RA2		SCL2/RA2
	_BV( 3 ) ,	// 41 RA3		SDA2/RA3
	_BV( 6 ) ,	// 42 RA6		TRCLK/RA6					(BTN1)
	_BV( 7 ) ,	// 43 RA7		TRD3/RA7					(BTN2)

    // Connector JH
	_BV( 12 ) ,	// 44 RF12		U2CTS/RF12
	_BV( 13 ) ,	// 45 RF13		U2RTS/BCLK2/RF13
	_BV( 4 ) ,	// 46 RF4		PMA9/U2RX/CN17/RF4
	_BV( 5 ) ,	// 47 RF5		PMA8/U2TX/CN18/RF5
	_BV( 8 ) ,	// 48 RE8		INT1/RE8
	_BV( 0 ) ,	// 49 RD0		SDO1/OC1/INT0/RD0
	_BV( 8 ) ,	// 50 RD8		IC1/RTCC/RD8
	_BV( 9 ) ,	// 51 RE9		INT2/RE9

    // Connector JJ
	_BV( 0 ) ,	// 52 RB0		PGD1/FMUD1/AN0/CN2/RB0
	_BV( 1 ) ,	// 53 RB1		PGC1/FMUC1/AN1/CN3/RB1
	_BV( 2 ) ,	// 54 RB2		C2IN-/AN2/CN4/RB2
	_BV( 3 ) ,	// 55 RB3		C2IN+/AN3/CN5/RB3
	_BV( 4 ) ,	// 56 RB4		C1IN-/AN4/CN6/RB4
	_BV( 5 ) ,	// 57 RB5		C1IN+/AN5/CN7/RB5
	_BV( 8 ) ,	// 58 RB8		C1OUT/AN8/RB8
	_BV( 9 ) ,	// 59 RB9		C2OUT/AN9/RB9

    // Connector JK
	_BV( 10 ) ,	// 60 RB10		CVREFOUT/PMA13/AN10/RB10	(LD1)
	_BV( 11 ) ,	// 61 RB11		PMA12/AN11/RB11				(LD2)
	_BV( 12 ) ,	// 62 RB12		PMA11/AN12/RB12				(LD3)
	_BV( 13 ) ,	// 63 RB11		PMA10/AN13/RB13				(LD4)
	_BV( 9 ) ,	// 64 RA9		PMA7/VREF-/CVREF-/RA9
	_BV( 10 ) ,	// 65 RA10		PMA6/VREF+/CVREF+/RA10
	_BV( 12 ) ,	// 66 RD12		PMD12/IC5/RD12
	_BV( 4 ) ,	// 67 RC4		SDI1/T5CK/RC4
	
	//J6 I2C PORT 1
	_BV( 14 ) ,	// 68 RA14		SCL1/INT3/RA14				(P32_SCL1)
	_BV( 15 ) 	// 69 RA15		SDA1/INT4/RA15				(P32_SDA1)
};

/* ------------------------------------------------------------ */
/* This table is used to map from digital pin number to the output
** compare number, input capture number, and timer external clock
** input associated with that pin.
*/
const uint8_t	digital_pin_to_timer_PGM[] = {
    // Connector JA
	NOT_ON_TIMER,	// 0 RE 0		PMD0
	NOT_ON_TIMER,	// 1 RE 1		PMD1		
	NOT_ON_TIMER,	// 2 RE 2		PMD2
	NOT_ON_TIMER,	// 3 RE 3		PMD3
	NOT_ON_TIMER,	// 4 RE 4		PMD4
	NOT_ON_TIMER,	// 5 RE 5		PMD5
	NOT_ON_TIMER,	// 6 RE 6		PMD6
	NOT_ON_TIMER,	// 7 RE 7		PMD7

    // Connector JB
	NOT_ON_TIMER,	// 8 RG9		PMA2/SS2/CN11/RG9
	NOT_ON_TIMER,	// 9 RG8		PMA3/SDO2/CN10/RG8
	NOT_ON_TIMER,	// 10 RG7		PMA4/SDI2/CN9/RG7
	NOT_ON_TIMER,	// 11 RG6		PMA5/SCK2/CN8/RG6
	NOT_ON_TIMER,	// 12 RB15		PMALL/PMA0/AN15/OCFB/CN12/RB15
	NOT_ON_TIMER,	// 13 RD5		PMRD/CN14/RD5
	_TIMER_OC5,		// 14 RD4		PMWR/OC5/CN13
	NOT_ON_TIMER,	// 15 RB14		PMALH/PMA1/AN14/RB14

    // Connector JC
	NOT_ON_TIMER,	// 16 RG12		TRD1/RG12					(S1)
	NOT_ON_TIMER,	// 17 RG13		TRD0/RG13					(S2)
	NOT_ON_TIMER,	// 18 RG14		TRD2/RG14					(S3)
	NOT_ON_TIMER,	// 19 RG15		RG15						(S4)		
	NOT_ON_TIMER,	// 20 RG0		PMD8/RG0					(S5)
	NOT_ON_TIMER,	// 21 RG1		PMD9/RG1					(S6)
	NOT_ON_TIMER,	// 22 RF0		PMD11/RF0					(S7)
	NOT_ON_TIMER,	// 23 RF1		PMD10/RF1					(S8)

    // Connector JD
	NOT_ON_TIMER,	// 24 RD7		PMD15/CN16/RD7
	_TIMER_OC2,		// 25 RD1		OC2/RD1
	_TIMER_IC2,		// 26 RD9		IC2/SS1/RD9
	_TIMER_TCK2,	// 27 RC1		T2CK/RC1
	NOT_ON_TIMER,	// 28 RD6		PMD14/CN15/RD6
	_TIMER_OC3,		// 29 RD2		OC3/RD2
	_TIMER_IC3,		// 30 RD10		IC3/SCK1/PMCS2/PMA15/RD10
	_TIMER_TCK3,	// 31 RC2		T3CK/RC2

    // Connector JE
	NOT_ON_TIMER,	// 32 RD14		CN20/U1CTS/RD14
	NOT_ON_TIMER,	// 33 RF15		U1RTS/BCLK1/CN21/RD15
	NOT_ON_TIMER,	// 34 RF2		U1RX/RF2
	NOT_ON_TIMER,	// 35 RF8		U1TX/RF8
	NOT_ON_TIMER,	// 36 RD13		PMD13/CN19/RD13
	_TIMER_OC4,		// 37 RD3		OC4/RD3
	_TIMER_IC4,		// 38 RD11		IC4/PMCS1/PMA14/RD11
	_TIMER_TCK4,	// 39 RC3		T4CK/RC3

    // Connector JF
	NOT_ON_TIMER,	// 40 RA2		SCL2/RA2
	NOT_ON_TIMER,	// 41 RA3		SDA2/RA3
	NOT_ON_TIMER,	// 42 RA6		TRCLK/RA6					(BTN1)
	NOT_ON_TIMER,	// 43 RA7		TRD3/RA7					(BTN2)

    // Connector JH
	NOT_ON_TIMER,	// 44 RF12		U2CTS/RF12
	NOT_ON_TIMER,	// 45 RF13		U2RTS/BCLK2/RF13
	NOT_ON_TIMER,	// 46 RF4		PMA9/U2RX/CN17/RF4
	NOT_ON_TIMER,	// 47 RF5		PMA8/U2TX/CN18/RF5
	NOT_ON_TIMER,	// 48 RE8		INT1/RE8
	_TIMER_OC1,		// 49 RD0		SDO1/OC1/INT0/RD0
	_TIMER_IC1,		// 50 RD8		IC1/RTCC/RD8
	NOT_ON_TIMER,	// 51 RE9		INT2/RE9

    // Connector JJ
	NOT_ON_TIMER,	// 52 RB0		PGD1/FMUD1/AN0/CN2/RB0
	NOT_ON_TIMER,	// 53 RB1		PGC1/FMUC1/AN1/CN3/RB1
	NOT_ON_TIMER,	// 54 RB2		C2IN-/AN2/CN4/RB2
	NOT_ON_TIMER,	// 55 RB3		C2IN+/AN3/CN5/RB3
	NOT_ON_TIMER,	// 56 RB4		C1IN-/AN4/CN6/RB4
	NOT_ON_TIMER,	// 57 RB5		C1IN+/AN5/CN7/RB5
	NOT_ON_TIMER,	// 58 RB8		C1OUT/AN8/RB8
	NOT_ON_TIMER,	// 59 RB9		C2OUT/AN9/RB9

    // Connector JK
	NOT_ON_TIMER,	// 60 RB10		CVREFOUT/PMA13/AN10/RB10	(LD1)
	NOT_ON_TIMER,	// 61 RB11		PMA12/AN11/RB11				(LD2)
	NOT_ON_TIMER,	// 62 RB12		PMA11/AN12/RB12				(LD3)
	NOT_ON_TIMER,	// 63 RB13		PMA10/AN13/RB13				(LD4)
	NOT_ON_TIMER,	// 64 RA9		PMA7/VREF-/CVREF-/RA9
	NOT_ON_TIMER,	// 65 RA10		PMA6/VREF+/CVREF+/RA10
	_TIMER_IC5,		// 66 RD12		PMD12/IC5/RD12
	_TIMER_TCK5,	// 67 RC4		SDI1/T5CK/RC4	
	
	//J6 /I2C PORT 2
	NOT_ON_TIMER,	// 68 RA14		SCL1/INT3/RA14				(P32_SCL1)
	NOT_ON_TIMER	// 69 RA15		SDA1/INT4/RA15				(P32_SDA1)
};

/* ------------------------------------------------------------ */
/* This table maps from a digital pin number to the corresponding
** analog pin number.
*/
const uint8_t digital_pin_to_analog_PGM[] = {
    // Connector JA
	NOT_ANALOG_PIN,		// 0 RE0		PMD0
	NOT_ANALOG_PIN,		// 1 RE1		PMD1		
	NOT_ANALOG_PIN,		// 2 RE2		PMD2
	NOT_ANALOG_PIN,		// 3 RE3		PMD3
	NOT_ANALOG_PIN,		// 4 RE4		PMD4
	NOT_ANALOG_PIN,		// 5 RE5		PMD5
	NOT_ANALOG_PIN,		// 6 RE6		PMD6
	NOT_ANALOG_PIN,		// 7 RE7		PMD7

    // Connector JB
	NOT_ANALOG_PIN,		// 8 RG9		PMA2/SS2/CN11/RG9
	NOT_ANALOG_PIN,		// 9 RG8		PMA3/SDO2/CN10/RG8
	NOT_ANALOG_PIN,		// 10 RG7		PMA4/SDI2/CN9/RG7
	NOT_ANALOG_PIN,		// 11 RG6		PMA5/SCK2/CN8/RG6
	_BOARD_AN12,		// 12 RB15		PMALL/PMA0/AN15/OCFB/CN12/RB15
	NOT_ANALOG_PIN,		// 13 RD5		PMRD/CN14/RD5
	NOT_ANALOG_PIN,		// 14 RD4		PMWR/OC5/CN13
	_BOARD_AN13,		// 15 RB14		PMALH/PMA1/AN14/RB14

    // Connector JC
	NOT_ANALOG_PIN,		// 16 RG12		TRD1/RG12					(S1)
	NOT_ANALOG_PIN,		// 17 RG13		TRD0/RG13					(S2)
	NOT_ANALOG_PIN,		// 18 RG14		TRD2/RG14					(S3)
	NOT_ANALOG_PIN,		// 19 RG15		RG15						(S4)	
	NOT_ANALOG_PIN,		// 20 RG0		PMD8/RG0					(S5)
	NOT_ANALOG_PIN,		// 21 RG1		PMD9/RG1					(S6)
	NOT_ANALOG_PIN,		// 22 RF0		PMD11/RF0					(S7)
	NOT_ANALOG_PIN,		// 23 RF1		PMD10/RF1					(S8)

    // Connector JD
	NOT_ANALOG_PIN,		// 24 RD7		PMD15/CN16/RD7
	NOT_ANALOG_PIN,		// 25 RD1		OC2/RD1
	NOT_ANALOG_PIN,		// 26 RD9		TC2/SS1/RD9
	NOT_ANALOG_PIN,		// 27 RC1		T2CK/RC1
	NOT_ANALOG_PIN,		// 28 RD6		PMD14/CN15/RD6
	NOT_ANALOG_PIN,		// 29 RD2		OC3/RD2
	NOT_ANALOG_PIN,		// 30 RD10		IC3/SCK1/PMCS2/PMA15/RD10
	NOT_ANALOG_PIN,		// 31 RC2		T3CK/RC2

    // Connector JE
	NOT_ANALOG_PIN,		// 32 RD14		CN20/U1CTS/RD14
	NOT_ANALOG_PIN,		// 33 RD15		U1RTS/BCLK1/CN21/RD15
	NOT_ANALOG_PIN,		// 34 RF2		U1RX/RF2
	NOT_ANALOG_PIN,		// 35 RF8		U1TX/RF8
	NOT_ANALOG_PIN,		// 36 RD13		PMD13/CN19/RD13
	NOT_ANALOG_PIN,		// 37 RD3		OC4/RD3
	NOT_ANALOG_PIN,		// 38 RD11		IC4/PMCS1/PMA14/RD11
	NOT_ANALOG_PIN,		// 39 RC3		T4CK/RC3

    // Connector JF
	NOT_ANALOG_PIN,		// 40 RA2		SCL2/RA2
	NOT_ANALOG_PIN,		// 41 RA3		SDA2/RA3
	NOT_ANALOG_PIN,		// 42 RA6		TRCLK/RA6					(BTN1)
	NOT_ANALOG_PIN,		// 43 RA7		TRD3/RA7					(BTN2)

    // Connector JH
	NOT_ANALOG_PIN,		// 44 RF12		U2CTS/RF12
	NOT_ANALOG_PIN,		// 45 RF13		U2RTS/BCLK2/RF13
	NOT_ANALOG_PIN,		// 46 RF4		PMA9/U2RX/CN17/RF4
	NOT_ANALOG_PIN,		// 47 RF5		PMA8/U2TX/CN18/RF5
	NOT_ANALOG_PIN,		// 48 RE8		INT1/RE8
	NOT_ANALOG_PIN,		// 49 RD0		SDO1/OC1/INT0/RD0
	NOT_ANALOG_PIN,		// 50 RD8		IC1/RTCC/RD8
	NOT_ANALOG_PIN,		// 51 RE9		INT2/RE9

    // Connector JJ
	_BOARD_AN0,			// 52 RB0		PGD1/FMUD1/AN0/CN2/RB0
	_BOARD_AN1,			// 53 RB1		PGC1/FMUC1/AN1/CN3/RB1
	_BOARD_AN2,			// 54 RB2		C2IN-/AN2/CN4/RB2
	_BOARD_AN3,			// 55 RB3		C2IN+/AN3/CN5/RB3
	_BOARD_AN4,			// 56 RB4		C1IN-/AN4/CN6/RB4
	_BOARD_AN5,			// 57 RB5		VBUSON/C1IN+/AN5/CN7/RB5
	_BOARD_AN6,			// 58 RB8		C1OUT/AN8/RB8
	_BOARD_AN7,			// 59 RB9		C2OUT/AN9/RB9

    // Connector JK
	_BOARD_AN8,			// 60 RB10		CVREFOUT/PMA13/AN10/RB10	(LD1)
	_BOARD_AN9,			// 61 RB11		PMA12/AN11/RB11				(LD2)
	_BOARD_AN10,		// 62 RB12		PMA11/AN12/RB12				(LD3)
	_BOARD_AN11,		// 63 RB13		PMA10/AN13/RB13				(LD4)
	NOT_ANALOG_PIN,		// 64 RA9		PMA7/VREF-/CVREF-/RA9
	NOT_ANALOG_PIN,		// 65 RA10		PMA6/VREF+/CVREF+/RA10
	NOT_ANALOG_PIN,		// 66 RD12		PMD12/IC5/RD12
	NOT_ANALOG_PIN,		// 67 RC4		SDI1/T5CK/RC4	
	
	//J6 I2C PORT 1
	NOT_ANALOG_PIN,		// 68 RA14		SCL1/INT3/RA14				(P32_SCL1)
	NOT_ANALOG_PIN		// 69 RA15		SDA1/INT4/RA15				(P32_SDA1)
};

/* ------------------------------------------------------------ */
/* This table is used to map from the analog pin number to the
** actual A/D converter channel used for that pin.
*/
const uint8_t analog_pin_to_channel_PGM[] =
{
			//*	Arduino Pin		PIC32 Analog channel
	0,		//*	A0						AN0
	1,		//*	A1						AN1
	2,		//*	A2						AN2
	3,		//*	A3						AN3
	4,		//*	A4						AN4
	5,		//*	A5						AN5
	8,		//*	A6						AN8
	9,		//*	A7						AN9
	10,		//*	A8						AN10
	11,		//*	A9						AN11
	12,		//*	A10						AN12
	13,		//*	A11						AN13
	15,		//* A12						AN15
	14		//* A13						AN14
};

/* ------------------------------------------------------------ */
/*				Board Customization Functions					*/
/* ------------------------------------------------------------ */
/*																*/
/* The following can be used to customize the behavior of some	*/
/* of the core API functions. These provide hooks that can be	*/
/* used to extend or replace the default behavior of the core	*/
/* functions. To use one of these functions, add the desired	*/
/* code to the function skeleton below and then set the value	*/
/* of the appropriate compile switch above to 1. This will		*/
/* cause the hook function to be compiled into the build and	*/
/* to cause the code to call the hook function to be compiled	*/
/* into the appropriate core function.							*/
/*																*/
/* ------------------------------------------------------------ */
/***	_board_init
**
**	Parameters:
**		none
**
**	Return Value:
**		none
**
**	Errors:
**		none
**
**	Description:
**		This function is called from the core init() function.
**		This can be used to perform any board specific init
**		that needs to be done when the processor comes out of
**		reset and before the user sketch is run.
*/
#if	(OPT_BOARD_INIT != 0)

void _board_init(void) {

}

#endif

/* ------------------------------------------------------------ */
/***	_board_pinMode
**
**	Parameters:
**		pin		- digital pin number to configure
**		mode	- mode to which the pin should be configured
**
**	Return Value:
**		Returns 0 if not handled, !0 if handled.
**
**	Errors:
**		none
**
**	Description:
**		This function is called at the beginning of the pinMode
**		function. It can perform any special processing needed
**		when setting the pin mode. If this function returns zero,
**		control will pass through the normal pinMode code. If
**		it returns a non-zero value the normal pinMode code isn't
**		executed.
*/
#if	(OPT_BOARD_DIGITAL_IO != 0)

int	_board_pinMode(uint8_t pin, uint8_t mode) {
	
	return 0;

}

#endif

/* ------------------------------------------------------------ */
/***	_board_getPinMode
**
**	Parameters:
**		pin		- digital pin number
**		mode	- pointer to variable to receive mode value
**
**	Return Value:
**		Returns 0 if not handled, !0 if handled.
**
**	Errors:
**		none
**
**	Description:
**		This function is called at the beginning of the getPinMode
**		function. It can perform any special processing needed
**		when getting the pin mode. If this function returns zero,
**		control will pass through the normal getPinMode code. If
**		it returns a non-zero value the normal getPinMode code isn't
**		executed.
*/
#if	(OPT_BOARD_DIGITAL_IO != 0)

int	_board_getPinMode(uint8_t pin, uint8_t * mode) {
	
	return 0;

}

#endif

/* ------------------------------------------------------------ */
/***	_board_digitalWrite
**
**	Parameters:
**		pin		- digital pin number
**		val		- value to write to the pin
**
**	Return Value:
**		Returns 0 if not handled, !0 if handled.
**
**	Errors:
**		none
**
**	Description:
**		This function is called at the beginning of the digitalWrite
**		function. It can perform any special processing needed
**		in writing to the pin. If this function returns zero,
**		control will pass through the normal digitalWrite code. If
**		it returns a non-zero value the normal digitalWrite code isn't
**		executed.
*/#if	(OPT_BOARD_DIGITAL_IO != 0)

int	_board_digitalWrite(uint8_t pin, uint8_t val) {
	
	return 0;

}

#endif

/* ------------------------------------------------------------ */
/***	_board_digitalRead
**
**	Parameters:
**		pin		- digital pin number
**		val		- pointer to variable to receive pin value
**
**	Return Value:
**		Returns 0 if not handled, !0 if handled.
**
**	Errors:
**		none
**
**	Description:
**		This function is called at the beginning of the digitalRead
**		function. It can perform any special processing needed
**		in reading from the pin. If this function returns zero,
**		control will pass through the normal digitalRead code. If
**		it returns a non-zero value the normal digitalRead code isn't
**		executed.
*/
#if	(OPT_BOARD_DIGITAL_IO != 0)

int	_board_digitalRead(uint8_t pin, uint8_t * val) {
	
	return 0;

}

#endif

/* ------------------------------------------------------------ */
/***	_board_analogRead
**
**	Parameters:
**		pin		- analog channel number
**		val		- pointer to variable to receive analog value
**
**	Return Value:
**		Returns 0 if not handled, !0 if handled.
**
**	Errors:
**		none
**
**	Description:
**		This function is called at the beginning of the analogRead
**		function. It can perform any special processing needed
**		in reading from the pin. If this function returns zero,
**		control will pass through the normal analogRead code. If
**		it returns a non-zero value the normal analogRead code isn't
**		executed.
*/
#if (OPT_BOARD_ANALOG_READ != 0)

int	_board_analogRead(uint8_t pin, int * val) {

	return 0;

}

#endif

/* ------------------------------------------------------------ */
/***	_board_analogReference
**
**	Parameters:
**
**	Return Value:
**		Returns 0 if not handled, !0 if handled.
**
**	Errors:
**		none
**
**	Description:
**		This function is called at the beginning of the analogReference
**		function. It can perform any special processing needed
**		to set the reference voltage. If this function returns zero,
**		control will pass through the normal analogReference code. If
**		it returns a non-zero value the normal analogReference code isn't
**		executed.
*/
#if (OPT_BOARD_ANALOG_READ != 0)

int	_board_analogReference(uint8_t mode) {

	return 0;

}

#endif

/* ------------------------------------------------------------ */
/***	_board_analogWrite
**
**	Parameters:
**		pin		- pin number
**		val		- analog value to write
**
**	Return Value:
**		Returns 0 if not handled, !0 if handled.
**
**	Errors:
**		none
**
**	Description:
**		This function is called at the beginning of the analogWrite
**		function. It can perform any special processing needed
**		in writing to the pin. If this function returns zero,
**		control will pass through the normal analogWrite code. If
**		it returns a non-zero value the normal analogWrite code isn't
**		executed.
*/
#if (OPT_BOARD_ANALOG_WRITE != 0)

int	_board_analogWrite(uint8_t pin, int val) {

	return 0;

}

#endif

#endif // _BOARD_DATA_

/* ------------------------------------------------------------ */

#endif	// BOARD_DEFS_H

/************************************************************************/