// bcm2835.h
//
// C and C++ support for Broadcom BCM 2835 as used in Raspberry Pi
//
// Author: Mike McCauley
// Copyright (C) 2011-2013 Mike McCauley
// $Id: bcm2835.h,v 1.14 2014/08/21 01:26:42 mikem Exp mikem $
//



// Defines for BCM2835
#ifndef BCM2835_H
#define BCM2835_H

#include <stdint.h>



#define HIGH 0x1
#define LOW 0x0

#define BCM2835_CORE_CLK_HZ 250000000

#define BMC2835_RPI2_DT_FILENAME "/proc/device-tree/soc/ranges"
#define BMC2835_RPI2_DT_PERI_BASE_ADDRESS_OFFSET 4
#define BMC2835_RPI2_DT_PERI_SIZE_OFFSET 8

#define BCM2835_PERI_BASE 0x20000000
#define BCM2835_PERI_SIZE 0x01000000

#define BCM2835_ST_BASE 0x3000
#define BCM2835_GPIO_PADS 0x100000
#define BCM2835_CLOCK_BASE 0x101000
#define BCM2835_GPIO_BASE 0x200000
#define BCM2835_SPI0_BASE 0x204000
#define BCM2835_BSC0_BASE 0x205000
#define BCM2835_GPIO_PWM 0x20C000
#define BCM2835_BSC1_BASE 0x804000

extern uint32_t *bcm2835_peripherals_base;
extern uint32_t bcm2835_peripherals_size;

extern void *bcm2835_peripherals;

extern uint32_t *bcm2835_st;

extern uint32_t *bcm2835_gpio;

extern uint32_t *bcm2835_pwm;

extern uint32_t *bcm2835_clk;

extern uint32_t *bcm2835_pads;

extern uint32_t *bcm2835_spi0;

extern uint32_t *bcm2835_bsc0;

extern uint32_t *bcm2835_bsc1;

typedef enum
{
 BCM2835_REGBASE_ST = 1,
 BCM2835_REGBASE_GPIO = 2,
 BCM2835_REGBASE_PWM = 3,
 BCM2835_REGBASE_CLK = 4,
 BCM2835_REGBASE_PADS = 5,
 BCM2835_REGBASE_SPI0 = 6,
 BCM2835_REGBASE_BSC0 = 7,
 BCM2835_REGBASE_BSC1 = 8
} bcm2835RegisterBase;

#define BCM2835_PAGE_SIZE (4*1024)
#define BCM2835_BLOCK_SIZE (4*1024)


// Defines for GPIO
// The BCM2835 has 54 GPIO pins.
// BCM2835 data sheet, Page 90 onwards.
#define BCM2835_GPFSEL0 0x0000
#define BCM2835_GPFSEL1 0x0004
#define BCM2835_GPFSEL2 0x0008
#define BCM2835_GPFSEL3 0x000c
#define BCM2835_GPFSEL4 0x0010
#define BCM2835_GPFSEL5 0x0014
#define BCM2835_GPSET0 0x001c
#define BCM2835_GPSET1 0x0020
#define BCM2835_GPCLR0 0x0028
#define BCM2835_GPCLR1 0x002c
#define BCM2835_GPLEV0 0x0034
#define BCM2835_GPLEV1 0x0038
#define BCM2835_GPEDS0 0x0040
#define BCM2835_GPEDS1 0x0044
#define BCM2835_GPREN0 0x004c
#define BCM2835_GPREN1 0x0050
#define BCM2835_GPFEN0 0x0058
#define BCM2835_GPFEN1 0x005c
#define BCM2835_GPHEN0 0x0064
#define BCM2835_GPHEN1 0x0068
#define BCM2835_GPLEN0 0x0070
#define BCM2835_GPLEN1 0x0074
#define BCM2835_GPAREN0 0x007c
#define BCM2835_GPAREN1 0x0080
#define BCM2835_GPAFEN0 0x0088
#define BCM2835_GPAFEN1 0x008c
#define BCM2835_GPPUD 0x0094
#define BCM2835_GPPUDCLK0 0x0098
#define BCM2835_GPPUDCLK1 0x009c

typedef enum
{
 BCM2835_GPIO_FSEL_INPT = 0b000,
 BCM2835_GPIO_FSEL_OUTP = 0b001,
 BCM2835_GPIO_FSEL_ALT0 = 0b100,
 BCM2835_GPIO_FSEL_ALT1 = 0b101,
 BCM2835_GPIO_FSEL_ALT2 = 0b110,
 BCM2835_GPIO_FSEL_ALT3 = 0b111,
 BCM2835_GPIO_FSEL_ALT4 = 0b011,
 BCM2835_GPIO_FSEL_ALT5 = 0b010,
 BCM2835_GPIO_FSEL_MASK = 0b111
} bcm2835FunctionSelect;

typedef enum
{
 BCM2835_GPIO_PUD_OFF = 0b00,
 BCM2835_GPIO_PUD_DOWN = 0b01,
 BCM2835_GPIO_PUD_UP = 0b10
} bcm2835PUDControl;

#define BCM2835_PADS_GPIO_0_27 0x002c
#define BCM2835_PADS_GPIO_28_45 0x0030
#define BCM2835_PADS_GPIO_46_53 0x0034

#define BCM2835_PAD_PASSWRD (0x5A << 24)
#define BCM2835_PAD_SLEW_RATE_UNLIMITED 0x10
#define BCM2835_PAD_HYSTERESIS_ENABLED 0x08
#define BCM2835_PAD_DRIVE_2mA 0x00
#define BCM2835_PAD_DRIVE_4mA 0x01
#define BCM2835_PAD_DRIVE_6mA 0x02
#define BCM2835_PAD_DRIVE_8mA 0x03
#define BCM2835_PAD_DRIVE_10mA 0x04
#define BCM2835_PAD_DRIVE_12mA 0x05
#define BCM2835_PAD_DRIVE_14mA 0x06
#define BCM2835_PAD_DRIVE_16mA 0x07

typedef enum
{
 BCM2835_PAD_GROUP_GPIO_0_27 = 0,
 BCM2835_PAD_GROUP_GPIO_28_45 = 1,
 BCM2835_PAD_GROUP_GPIO_46_53 = 2
} bcm2835PadGroup;

typedef enum
{
 RPI_GPIO_P1_03 = 0,
 RPI_GPIO_P1_05 = 1,
 RPI_GPIO_P1_07 = 4,
 RPI_GPIO_P1_08 = 14,
 RPI_GPIO_P1_10 = 15,
 RPI_GPIO_P1_11 = 17,
 RPI_GPIO_P1_12 = 18,
 RPI_GPIO_P1_13 = 21,
 RPI_GPIO_P1_15 = 22,
 RPI_GPIO_P1_16 = 23,
 RPI_GPIO_P1_18 = 24,
 RPI_GPIO_P1_19 = 10,
 RPI_GPIO_P1_21 = 9,
 RPI_GPIO_P1_22 = 25,
 RPI_GPIO_P1_23 = 11,
 RPI_GPIO_P1_24 = 8,
 RPI_GPIO_P1_26 = 7,

 // RPi Version 2
 RPI_V2_GPIO_P1_03 = 2,
 RPI_V2_GPIO_P1_05 = 3,
 RPI_V2_GPIO_P1_07 = 4,
 RPI_V2_GPIO_P1_08 = 14,
 RPI_V2_GPIO_P1_10 = 15,
 RPI_V2_GPIO_P1_11 = 17,
 RPI_V2_GPIO_P1_12 = 18,
 RPI_V2_GPIO_P1_13 = 27,
 RPI_V2_GPIO_P1_15 = 22,
 RPI_V2_GPIO_P1_16 = 23,
 RPI_V2_GPIO_P1_18 = 24,
 RPI_V2_GPIO_P1_19 = 10,
 RPI_V2_GPIO_P1_21 = 9,
 RPI_V2_GPIO_P1_22 = 25,
 RPI_V2_GPIO_P1_23 = 11,
 RPI_V2_GPIO_P1_24 = 8,
 RPI_V2_GPIO_P1_26 = 7,

 // RPi Version 2, new plug P5
 RPI_V2_GPIO_P5_03 = 28,
 RPI_V2_GPIO_P5_04 = 29,
 RPI_V2_GPIO_P5_05 = 30,
 RPI_V2_GPIO_P5_06 = 31,

 // RPi B+ J8 header
 RPI_BPLUS_GPIO_J8_03 = 2,
 RPI_BPLUS_GPIO_J8_05 = 3,
 RPI_BPLUS_GPIO_J8_07 = 4,
 RPI_BPLUS_GPIO_J8_08 = 14,
 RPI_BPLUS_GPIO_J8_10 = 15,
 RPI_BPLUS_GPIO_J8_11 = 17,
 RPI_BPLUS_GPIO_J8_12 = 18,
 RPI_BPLUS_GPIO_J8_13 = 27,
 RPI_BPLUS_GPIO_J8_15 = 22,
 RPI_BPLUS_GPIO_J8_16 = 23,
 RPI_BPLUS_GPIO_J8_18 = 24,
 RPI_BPLUS_GPIO_J8_19 = 10,
 RPI_BPLUS_GPIO_J8_21 = 9,
 RPI_BPLUS_GPIO_J8_22 = 25,
 RPI_BPLUS_GPIO_J8_23 = 11,
 RPI_BPLUS_GPIO_J8_24 = 8,
 RPI_BPLUS_GPIO_J8_26 = 7,
 RPI_BPLUS_GPIO_J8_29 = 5,
 RPI_BPLUS_GPIO_J8_31 = 6,
 RPI_BPLUS_GPIO_J8_32 = 12,
 RPI_BPLUS_GPIO_J8_33 = 13,
 RPI_BPLUS_GPIO_J8_35 = 19,
 RPI_BPLUS_GPIO_J8_36 = 16,
 RPI_BPLUS_GPIO_J8_37 = 26,
 RPI_BPLUS_GPIO_J8_38 = 20,
 RPI_BPLUS_GPIO_J8_40 = 21,
} RPiGPIOPin;

// Defines for SPI
// GPIO register offsets from BCM2835_SPI0_BASE.
// Offsets into the SPI Peripheral block in bytes per 10.5 SPI Register Map
#define BCM2835_SPI0_CS 0x0000
#define BCM2835_SPI0_FIFO 0x0004
#define BCM2835_SPI0_CLK 0x0008
#define BCM2835_SPI0_DLEN 0x000c
#define BCM2835_SPI0_LTOH 0x0010
#define BCM2835_SPI0_DC 0x0014

// Register masks for SPI0_CS
#define BCM2835_SPI0_CS_LEN_LONG 0x02000000
#define BCM2835_SPI0_CS_DMA_LEN 0x01000000
#define BCM2835_SPI0_CS_CSPOL2 0x00800000
#define BCM2835_SPI0_CS_CSPOL1 0x00400000
#define BCM2835_SPI0_CS_CSPOL0 0x00200000
#define BCM2835_SPI0_CS_RXF 0x00100000
#define BCM2835_SPI0_CS_RXR 0x00080000
#define BCM2835_SPI0_CS_TXD 0x00040000
#define BCM2835_SPI0_CS_RXD 0x00020000
#define BCM2835_SPI0_CS_DONE 0x00010000
#define BCM2835_SPI0_CS_TE_EN 0x00008000
#define BCM2835_SPI0_CS_LMONO 0x00004000
#define BCM2835_SPI0_CS_LEN 0x00002000
#define BCM2835_SPI0_CS_REN 0x00001000
#define BCM2835_SPI0_CS_ADCS 0x00000800
#define BCM2835_SPI0_CS_INTR 0x00000400
#define BCM2835_SPI0_CS_INTD 0x00000200
#define BCM2835_SPI0_CS_DMAEN 0x00000100
#define BCM2835_SPI0_CS_TA 0x00000080
#define BCM2835_SPI0_CS_CSPOL 0x00000040
#define BCM2835_SPI0_CS_CLEAR 0x00000030
#define BCM2835_SPI0_CS_CLEAR_RX 0x00000020
#define BCM2835_SPI0_CS_CLEAR_TX 0x00000010
#define BCM2835_SPI0_CS_CPOL 0x00000008
#define BCM2835_SPI0_CS_CPHA 0x00000004
#define BCM2835_SPI0_CS_CS 0x00000003

typedef enum
{
 BCM2835_SPI_BIT_ORDER_LSBFIRST = 0,
 BCM2835_SPI_BIT_ORDER_MSBFIRST = 1
}bcm2835SPIBitOrder;

typedef enum
{
 BCM2835_SPI_MODE0 = 0,
 BCM2835_SPI_MODE1 = 1,
 BCM2835_SPI_MODE2 = 2,
 BCM2835_SPI_MODE3 = 3,
}bcm2835SPIMode;

typedef enum
{
 BCM2835_SPI_CS0 = 0,
 BCM2835_SPI_CS1 = 1,
 BCM2835_SPI_CS2 = 2,
 BCM2835_SPI_CS_NONE = 3,
} bcm2835SPIChipSelect;

typedef enum
{
 BCM2835_SPI_CLOCK_DIVIDER_65536 = 0,
 BCM2835_SPI_CLOCK_DIVIDER_32768 = 32768,
 BCM2835_SPI_CLOCK_DIVIDER_16384 = 16384,
 BCM2835_SPI_CLOCK_DIVIDER_8192 = 8192,
 BCM2835_SPI_CLOCK_DIVIDER_4096 = 4096,
 BCM2835_SPI_CLOCK_DIVIDER_2048 = 2048,
 BCM2835_SPI_CLOCK_DIVIDER_1024 = 1024,
 BCM2835_SPI_CLOCK_DIVIDER_512 = 512,
 BCM2835_SPI_CLOCK_DIVIDER_256 = 256,
 BCM2835_SPI_CLOCK_DIVIDER_128 = 128,
 BCM2835_SPI_CLOCK_DIVIDER_64 = 64,
 BCM2835_SPI_CLOCK_DIVIDER_32 = 32,
 BCM2835_SPI_CLOCK_DIVIDER_16 = 16,
 BCM2835_SPI_CLOCK_DIVIDER_8 = 8,
 BCM2835_SPI_CLOCK_DIVIDER_4 = 4,
 BCM2835_SPI_CLOCK_DIVIDER_2 = 2,
 BCM2835_SPI_CLOCK_DIVIDER_1 = 1,
} bcm2835SPIClockDivider;

// Defines for I2C
// GPIO register offsets from BCM2835_BSC*_BASE.
// Offsets into the BSC Peripheral block in bytes per 3.1 BSC Register Map
#define BCM2835_BSC_C 0x0000
#define BCM2835_BSC_S 0x0004
#define BCM2835_BSC_DLEN 0x0008
#define BCM2835_BSC_A 0x000c
#define BCM2835_BSC_FIFO 0x0010
#define BCM2835_BSC_DIV 0x0014
#define BCM2835_BSC_DEL 0x0018
#define BCM2835_BSC_CLKT 0x001c

// Register masks for BSC_C
#define BCM2835_BSC_C_I2CEN 0x00008000
#define BCM2835_BSC_C_INTR 0x00000400
#define BCM2835_BSC_C_INTT 0x00000200
#define BCM2835_BSC_C_INTD 0x00000100
#define BCM2835_BSC_C_ST 0x00000080
#define BCM2835_BSC_C_CLEAR_1 0x00000020
#define BCM2835_BSC_C_CLEAR_2 0x00000010
#define BCM2835_BSC_C_READ 0x00000001

// Register masks for BSC_S
#define BCM2835_BSC_S_CLKT 0x00000200
#define BCM2835_BSC_S_ERR 0x00000100
#define BCM2835_BSC_S_RXF 0x00000080
#define BCM2835_BSC_S_TXE 0x00000040
#define BCM2835_BSC_S_RXD 0x00000020
#define BCM2835_BSC_S_TXD 0x00000010
#define BCM2835_BSC_S_RXR 0x00000008
#define BCM2835_BSC_S_TXW 0x00000004
#define BCM2835_BSC_S_DONE 0x00000002
#define BCM2835_BSC_S_TA 0x00000001

#define BCM2835_BSC_FIFO_SIZE 16

typedef enum
{
 BCM2835_I2C_CLOCK_DIVIDER_2500 = 2500,
 BCM2835_I2C_CLOCK_DIVIDER_626 = 626,
 BCM2835_I2C_CLOCK_DIVIDER_150 = 150,
 BCM2835_I2C_CLOCK_DIVIDER_148 = 148,
} bcm2835I2CClockDivider;

typedef enum
{
 BCM2835_I2C_REASON_OK = 0x00,
 BCM2835_I2C_REASON_ERROR_NACK = 0x01,
 BCM2835_I2C_REASON_ERROR_CLKT = 0x02,
 BCM2835_I2C_REASON_ERROR_DATA = 0x04,
} bcm2835I2CReasonCodes;

// Defines for ST
// GPIO register offsets from BCM2835_ST_BASE.
// Offsets into the ST Peripheral block in bytes per 12.1 System Timer Registers
// The System Timer peripheral provides four 32-bit timer channels and a single 64-bit free running counter.
// BCM2835_ST_CLO is the System Timer Counter Lower bits register.
// The system timer free-running counter lower register is a read-only register that returns the current value
// of the lower 32-bits of the free running counter.
// BCM2835_ST_CHI is the System Timer Counter Upper bits register.
// The system timer free-running counter upper register is a read-only register that returns the current value
// of the upper 32-bits of the free running counter.
#define BCM2835_ST_CS 0x0000
#define BCM2835_ST_CLO 0x0004
#define BCM2835_ST_CHI 0x0008



// Defines for PWM, word offsets (ie 4 byte multiples)
#define BCM2835_PWM_CONTROL 0
#define BCM2835_PWM_STATUS 1
#define BCM2835_PWM_DMAC 2
#define BCM2835_PWM0_RANGE 4
#define BCM2835_PWM0_DATA 5
#define BCM2835_PWM_FIF1 6
#define BCM2835_PWM1_RANGE 8
#define BCM2835_PWM1_DATA 9

// Defines for PWM Clock, word offsets (ie 4 byte multiples)
#define BCM2835_PWMCLK_CNTL 40
#define BCM2835_PWMCLK_DIV 41
#define BCM2835_PWM_PASSWRD (0x5A << 24)

#define BCM2835_PWM1_MS_MODE 0x8000
#define BCM2835_PWM1_USEFIFO 0x2000
#define BCM2835_PWM1_REVPOLAR 0x1000
#define BCM2835_PWM1_OFFSTATE 0x0800
#define BCM2835_PWM1_REPEATFF 0x0400
#define BCM2835_PWM1_SERIAL 0x0200
#define BCM2835_PWM1_ENABLE 0x0100

#define BCM2835_PWM0_MS_MODE 0x0080
#define BCM2835_PWM_CLEAR_FIFO 0x0040
#define BCM2835_PWM0_USEFIFO 0x0020
#define BCM2835_PWM0_REVPOLAR 0x0010
#define BCM2835_PWM0_OFFSTATE 0x0008
#define BCM2835_PWM0_REPEATFF 0x0004
#define BCM2835_PWM0_SERIAL 0x0002
#define BCM2835_PWM0_ENABLE 0x0001

typedef enum
{
 BCM2835_PWM_CLOCK_DIVIDER_2048 = 2048,
 BCM2835_PWM_CLOCK_DIVIDER_1024 = 1024,
 BCM2835_PWM_CLOCK_DIVIDER_512 = 512,
 BCM2835_PWM_CLOCK_DIVIDER_256 = 256,
 BCM2835_PWM_CLOCK_DIVIDER_128 = 128,
 BCM2835_PWM_CLOCK_DIVIDER_64 = 64,
 BCM2835_PWM_CLOCK_DIVIDER_32 = 32,
 BCM2835_PWM_CLOCK_DIVIDER_16 = 16,
 BCM2835_PWM_CLOCK_DIVIDER_8 = 8,
 BCM2835_PWM_CLOCK_DIVIDER_4 = 4,
 BCM2835_PWM_CLOCK_DIVIDER_2 = 2,
 BCM2835_PWM_CLOCK_DIVIDER_1 = 1,
} bcm2835PWMClockDivider;

// Historical name compatibility
#ifndef BCM2835_NO_DELAY_COMPATIBILITY
#define delay(x) bcm2835_delay(x)
#define delayMicroseconds(x) bcm2835_delayMicroseconds(x)
#endif

#ifdef __cplusplus
extern "C" {
#endif


 extern int bcm2835_init(void);

 extern int bcm2835_close(void);

 extern void bcm2835_set_debug(uint8_t debug);



 extern uint32_t* bcm2835_regbase(uint8_t regbase);

 extern uint32_t bcm2835_peri_read(uint32_t* paddr);


 extern uint32_t bcm2835_peri_read_nb(uint32_t* paddr);


 extern void bcm2835_peri_write(uint32_t* paddr, uint32_t value);

 extern void bcm2835_peri_write_nb(uint32_t* paddr, uint32_t value);

 extern void bcm2835_peri_set_bits(uint32_t* paddr, uint32_t value, uint32_t mask);


 extern void bcm2835_gpio_fsel(uint8_t pin, uint8_t mode);

 extern void bcm2835_gpio_set(uint8_t pin);

 extern void bcm2835_gpio_clr(uint8_t pin);

 extern void bcm2835_gpio_set_multi(uint32_t mask);

 extern void bcm2835_gpio_clr_multi(uint32_t mask);

 extern uint8_t bcm2835_gpio_lev(uint8_t pin);

 extern uint8_t bcm2835_gpio_eds(uint8_t pin);

 extern void bcm2835_gpio_set_eds(uint8_t pin);

 extern void bcm2835_gpio_ren(uint8_t pin);

 extern void bcm2835_gpio_clr_ren(uint8_t pin);

  extern void bcm2835_gpio_fen(uint8_t pin);
 
  extern void bcm2835_gpio_clr_fen(uint8_t pin);
 
  extern void bcm2835_gpio_hen(uint8_t pin);
 
  extern void bcm2835_gpio_clr_hen(uint8_t pin);
 
  extern void bcm2835_gpio_len(uint8_t pin);
 
  extern void bcm2835_gpio_clr_len(uint8_t pin);
 
  extern void bcm2835_gpio_aren(uint8_t pin);
 
  extern void bcm2835_gpio_clr_aren(uint8_t pin);
 
  extern void bcm2835_gpio_afen(uint8_t pin);
 
  extern void bcm2835_gpio_clr_afen(uint8_t pin);
 
  extern void bcm2835_gpio_pud(uint8_t pud);
 
  extern void bcm2835_gpio_pudclk(uint8_t pin, uint8_t on);
 
  extern uint32_t bcm2835_gpio_pad(uint8_t group);
 
  extern void bcm2835_gpio_set_pad(uint8_t group, uint32_t control);
 
  extern void bcm2835_delay (unsigned int millis);
 
  extern void bcm2835_delayMicroseconds (uint64_t micros);
 
  extern void bcm2835_gpio_write(uint8_t pin, uint8_t on);
 
  extern void bcm2835_gpio_write_multi(uint32_t mask, uint8_t on);
 
  extern void bcm2835_gpio_write_mask(uint32_t value, uint32_t mask);
 
  extern void bcm2835_gpio_set_pud(uint8_t pin, uint8_t pud);
 
 
 
  extern void bcm2835_spi_begin(void);
 
  extern void bcm2835_spi_end(void);
 
  extern void bcm2835_spi_setBitOrder(uint8_t order);
 
  extern void bcm2835_spi_setClockDivider(uint16_t divider);
 
  extern void bcm2835_spi_setDataMode(uint8_t mode);
 
  extern void bcm2835_spi_chipSelect(uint8_t cs);
 
  extern void bcm2835_spi_setChipSelectPolarity(uint8_t cs, uint8_t active);
 
  extern uint8_t bcm2835_spi_transfer(uint8_t value);
 
  extern void bcm2835_spi_transfernb(char* tbuf, char* rbuf, uint32_t len);
 
  extern void bcm2835_spi_transfern(char* buf, uint32_t len);
 
  extern void bcm2835_spi_writenb(char* buf, uint32_t len);
 
 
 
  extern void bcm2835_i2c_begin(void);
 
  extern void bcm2835_i2c_end(void);
 
  extern void bcm2835_i2c_setSlaveAddress(uint8_t addr);
 
  extern void bcm2835_i2c_setClockDivider(uint16_t divider);
 
  extern void bcm2835_i2c_set_baudrate(uint32_t baudrate);
 
  extern uint8_t bcm2835_i2c_write(const char * buf, uint32_t len);
 
  extern uint8_t bcm2835_i2c_read(char* buf, uint32_t len);
 
  extern uint8_t bcm2835_i2c_read_register_rs(char* regaddr, char* buf, uint32_t len);
 
  extern uint8_t bcm2835_i2c_write_read_rs(char* cmds, uint32_t cmds_len, char* buf, uint32_t buf_len);
 
 
 
  extern uint64_t bcm2835_st_read(void);
 
  extern void bcm2835_st_delay(uint64_t offset_micros, uint64_t micros);
 
 
 
  extern void bcm2835_pwm_set_clock(uint32_t divisor);
 
  extern void bcm2835_pwm_set_mode(uint8_t channel, uint8_t markspace, uint8_t enabled);
 
  extern void bcm2835_pwm_set_range(uint8_t channel, uint32_t range);
 
  extern void bcm2835_pwm_set_data(uint8_t channel, uint32_t data);
 
 #ifdef __cplusplus
 }
 #endif
 
 #endif // BCM2835_H