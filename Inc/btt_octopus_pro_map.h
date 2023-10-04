/*
  octopus_pro_map.h - driver code for STM32F446 ARM processors

  Part of grblHAL

  Grbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Grbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
*/

// STM32F446 build only

#if N_ABC_MOTORS > 5 || N_AUTO_SQUARED > 2
#error "Axis configuration is not supported!"
#endif



#if !defined(STM32F446xx) || HSE_VALUE != 12000000
#error "This board has STM32F446 processor with a 12MHz crystal, select a corresponding build!"
#endif



// #ifdef BOARD_BTT_OCTOPUS_PRO
#define BOARD_NAME "BTT OCTOPUS PRO F446"
#define BOARD_URL "https://github.com/bigtreetech/BIGTREETECH-OCTOPUS-Pro/"
// #else
// #define BOARD_NAME "BTT SKR PRO v1.1"
// #define BOARD_URL "https://github.com/bigtreetech/BIGTREETECH-SKR-PRO-V1.1"
// #endif


// USART1 is TFT Header
// USART2 is UART2 Header
// USART3 is ESP-12S Header

#define SERIAL_PORT                 1
#define SERIAL1_PORT                21
#define SERIAL2_PORT                32


// Default pins PB8 (SCL) & PB9 (SDA)
#define I2C_PORT 1
//#define I2C1_ALT_PINMAP // GPIOB, SCL_PIN = 6, SDA_PIN = 7

// TODO: Add support for trinamic
// #if TRINAMIC_ENABLE
// #define HAS_BOARD_INIT
// #endif


// Define step pulse output pins.
#define X_STEP_PORT                 GPIOF
#define X_STEP_PIN                  13                  // X
#define Y_STEP_PORT                 GPIOG
#define Y_STEP_PIN                  0                  // Y
#define Z_STEP_PORT                 GPIOF
#define Z_STEP_PIN                  11                  // Z
#define STEP_OUTMODE                GPIO_BITBAND
//#define STEP_PINMODE                PINMODE_OD // Uncomment for open drain outputs

// Define step direction output pins.
#define X_DIRECTION_PORT            GPIOF
#define X_DIRECTION_PIN             12
#define Y_DIRECTION_PORT            GPIOG
#define Y_DIRECTION_PIN             1
#define Z_DIRECTION_PORT            GPIOG
#define Z_DIRECTION_PIN             3
#define DIRECTION_OUTMODE           GPIO_BITBAND
//#define DIRECTION_PINMODE           PINMODE_OD // Uncomment for open drain outputs

// Define stepper driver enable/disable output pin.
#define X_ENABLE_PORT               GPIOF
#define X_ENABLE_PIN                14
#define Y_ENABLE_PORT               GPIOF
#define Y_ENABLE_PIN                15
#define Z_ENABLE_PORT               GPIOG
#define Z_ENABLE_PIN                5
//#define STEPPERS_ENABLE_PINMODE   PINMODE_OD // Uncomment for open drain outputs


// Define homing/hard limit switch input pins.
#define X_LIMIT_PORT                GPIOG
#define X_LIMIT_PIN                 6                           // X- Limit
#define X_LIMIT_PORT_MAX            GPIOG
#define X_LIMIT_PIN_MAX             12                          // X+ Limit

#define Y_LIMIT_PORT                GPIOG
#define Y_LIMIT_PIN                 9                           // Y- Limit
#define Y_LIMIT_PORT_MAX            GPIOG
#define Y_LIMIT_PIN_MAX             13                          // Y+ Limit

#define Z_LIMIT_PORT                GPIOG
#define Z_LIMIT_PIN                 10                          // Z- Limit
#define Z_LIMIT_PORT_MAX            GPIOG
#define Z_LIMIT_PIN_MAX             14                          // Z+ Limit
#define LIMIT_INMODE                GPIO_BITBAND

// Define ganged axis or A axis step pulse and step direction output pins.
#if N_ABC_MOTORS > 0
#define M3_AVAILABLE                // MOTOR3
#define M3_STEP_PORT                GPIOG
#define M3_STEP_PIN                 4
#define M3_DIRECTION_PORT           GPIOC
#define M3_DIRECTION_PIN            1
#define M3_LIMIT_PORT               GPIOG
#define M3_LIMIT_PIN                11
#define M3_ENABLE_PORT              GPIOA
#define M3_ENABLE_PIN               0
#endif

// Define ganged axis or B axis step pulse and step direction output pins.
#if N_ABC_MOTORS > 1
#define M4_AVAILABLE                // MOTOR4
#define M4_STEP_PORT                GPIOF
#define M4_STEP_PIN                 9
#define M4_DIRECTION_PORT           GPIOF
#define M4_DIRECTION_PIN            10
#define M4_LIMIT_PORT               GPIOG
#define M4_LIMIT_PIN                15
#define M4_ENABLE_PORT              GPIOG
#define M4_ENABLE_PIN               2
#endif

// Define ganged axis or C axis step pulse and step direction output pins.
#if N_ABC_MOTORS > 2
#define M5_AVAILABLE                // MOTOR5
#define M5_STEP_PORT                GPIOC
#define M5_STEP_PIN                 13
#define M5_DIRECTION_PORT           GPIOF
#define M5_DIRECTION_PIN            0
// #define M5_LIMIT_PORT               GPIOG
// #define M5_LIMIT_PIN                13
#define M5_ENABLE_PORT              GPIOF
#define M5_ENABLE_PIN               1
#endif

// Define ganged axis step pulse and step direction output pins.
#if N_ABC_MOTORS > 3
#define M6_AVAILABLE                // MOTOR6
#define M6_STEP_PORT                GPIOE
#define M6_STEP_PIN                 2
#define M6_DIRECTION_PORT           GPIOE
#define M6_DIRECTION_PIN            3
// #define M6_LIMIT_PORT               GPIOG
// #define M6_LIMIT_PIN                14
#define M6_ENABLE_PORT              GPIOD
#define M6_ENABLE_PIN               4
#endif

// Define ganged axis step pulse and step direction output pins.
#if N_ABC_MOTORS == 4
#define M7_AVAILABLE                // MOTOR7
#define M7_STEP_PORT                GPIOE
#define M7_STEP_PIN                 6
#define M7_DIRECTION_PORT           GPIOA
#define M7_DIRECTION_PIN            14
// #define M7_LIMIT_PORT               GPIOG
// #define M7_LIMIT_PIN                15
#define M7_ENABLE_PORT              GPIOE
#define M7_ENABLE_PIN               0
#endif


// Define spindle enable and spindle direction output pins.
#define SPINDLE_ENABLE_PORT         GPIOE
#define SPINDLE_ENABLE_PIN          5                           // FAN1
#define SPINDLE_DIRECTION_PORT      GPIOD
#define SPINDLE_DIRECTION_PIN       12                          // FAN2


// Define spindle PWM output pin.
#define SPINDLE_PWM_PORT_BASE       GPIOA_BASEA
#define SPINDLE_PWM_PIN             8                           // FAN0

// Define flood and mist coolant enable output pins.
#define COOLANT_FLOOD_PORT          GPIOA
#define COOLANT_FLOOD_PIN           2                           // HEAT0
#define COOLANT_MIST_PORT           GPIOA
#define COOLANT_MIST_PIN            3                           // HEAT1


// Define user-control controls (cycle start, reset, feed hold) input pins.
#define RESET_PORT                  GPIOF
#define RESET_PIN                   3                           // TB PF3
#define FEED_HOLD_PORT              GPIOF
#define FEED_HOLD_PIN               4                           // TH0 PF4
#define CYCLE_START_PORT            GPIOF
#define CYCLE_START_PIN             5                           // TH1 PF5
#define SAFETY_DOOR_PORT            GPIOF
#define SAFETY_DOOR_PIN             6                           // TH2 PF6
#define CONTROL_INMODE GPIO_BITBAND

// 7 inputs
#define AUXINPUT0_PORT              GPIOE
#define AUXINPUT0_PIN               8                           // EXP1.1 PE8
#define AUXINPUT1_PORT              GPIOE
#define AUXINPUT1_PIN               7                           // EXP1.2 PE7
#define AUXINPUT2_PORT              GPIOE
#define AUXINPUT2_PIN               9                           // EXP1.3 PE9
#define AUXINPUT3_PORT              GPIOE
#define AUXINPUT3_PIN               10                          // EXP1.4 PE10
#define AUXINPUT4_PORT              GPIOE
#define AUXINPUT4_PIN               12                          // EXP1.5 PE12
#define AUXINPUT5_PORT              GPIOE
#define AUXINPUT5_PIN               13                          // EXP1.6 PE13
#define AUXINPUT6_PORT              GPIOD
#define AUXINPUT6_PIN               10                          // ESP_IO4 PD10
#define AUXINPUT7_PORT              GPIOF
#define AUXINPUT7_PIN               7                           // TH3 PF7

// 8 outputs
#define AUXOUTPUT0_PORT              GPIOA
#define AUXOUTPUT0_PIN               1                           // HB PA1
#define AUXOUTPUT1_PORT              GPIOB
#define AUXOUTPUT1_PIN               10                          // HEAT2 PB10
#define AUXOUTPUT2_PORT              GPIOB
#define AUXOUTPUT2_PIN               11                          // HEAT3 PB11
#define AUXOUTPUT3_PORT              GPIOD
#define AUXOUTPUT3_PIN               13                          // FAN3 PD13
#define AUXOUTPUT4_PORT              GPIOD
#define AUXOUTPUT4_PIN               14                          // FAN4 PD14
#define AUXOUTPUT5_PORT              GPIOD
#define AUXOUTPUT5_PIN               15                          // FAN5 PD15
#define AUXOUTPUT6_PORT              GPIOE
#define AUXOUTPUT6_PIN               14                          // EXP1.7 PE14
#define AUXOUTPUT7_PORT              GPIOE
#define AUXOUTPUT7_PIN               15                          // EXP1.8 PE15
#define AUXOUTPUT_OUTMODE       GPIO_BITBAND



// Probe C5
// Bl-touch PB6(pin 3) & PB7(pin 1)
// Define probe switch input pin.
#define PROBE_PORT                  GPIOC
#define PROBE_PIN                   5                           // Probe Switch


#if SDCARD_ENABLE
/*
SDIO_D2:    C10
SDIO_D3:    C11
SDIO_CMD:   D2
SDIO_CK:    C12
SDIO_D0:    C8
SDIO_D1:    C9
TF_DET:     C14
*/
#define SDCARD_SDIO                 1
#endif

// Pins correct but untested
/*
#if TRINAMIC_UART_ENABLE

#undef TRINAMIC_UART_ENABLE
#define TRINAMIC_UART_ENABLE        2

#define MOTOR_UARTX_PORT            GPIOC
#define MOTOR_UARTX_PIN             4
#define MOTOR_UARTY_PORT            GPIOD
#define MOTOR_UARTY_PIN             11
#define MOTOR_UARTZ_PORT            GPIOC
#define MOTOR_UARTZ_PIN             6

#ifdef  M3_AVAILABLE
#define MOTOR_UARTM3_PORT           GPIOC
#define MOTOR_UARTM3_PIN            7
#endif

#ifdef  M4_AVAILABLE
#define MOTOR_UARTM4_PORT           GPIOF
#define MOTOR_UARTM4_PIN            2
#endif

#ifdef  M5_AVAILABLE
#define MOTOR_UARTM5_PORT           GPIOE
#define MOTOR_UARTM5_PIN            4
#endif

#ifdef  M6_AVAILABLE
#define MOTOR_UARTM6_PORT           GPIOE
#define MOTOR_UARTM6_PIN            1
#endif

#ifdef  M7_AVAILABLE
#define MOTOR_UARTM7_PORT           GPIOD
#define MOTOR_UARTM7_PIN            3
#endif

#endif
*/

// Untested
#if TRINAMIC_SPI_ENABLE

#define TRINAMIC_SPI_PORT           1 // GPIOA, SCK_PIN = 5, MISO_PIN = 6, MOSI_PIN = 7

#define MOTOR_CSX_PORT              GPIOC
#define MOTOR_CSX_PIN               4
#define MOTOR_CSY_PORT              GPIOD
#define MOTOR_CSY_PIN               11
#define MOTOR_CSZ_PORT              GPIOC
#define MOTOR_CSZ_PIN               6

#ifdef  M3_AVAILABLE
#define MOTOR_CSM3_PORT             GPIOC
#define MOTOR_CSM3_PIN              7
#endif

#ifdef  M4_AVAILABLE
#define MOTOR_CSM4_PORT             GPIOF
#define MOTOR_CSM4_PIN              2
#endif

#ifdef  M5_AVAILABLE
#define MOTOR_CSM5_PORT             GPIOE
#define MOTOR_CSM5_PIN              4
#endif

#ifdef  M6_AVAILABLE
#define MOTOR_CSM6_PORT             GPIOE
#define MOTOR_CSM6_PIN              1
#endif

#ifdef  M7_AVAILABLE
#define MOTOR_CSM7_PORT             GPIOD
#define MOTOR_CSM7_PIN              3
#endif

#endif