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


// TODO: Check autogang support
#if N_ABC_MOTORS > 3 //|| N_AUTO_SQUARED > 3
#error "Axis configuration is not supported!"
#endif


// TODO: Add other MCU support
#if !defined(STM32F446xx) || HSE_VALUE != 12000000
#error "This board has STM32F446 processor with a 12MHz crystal, select a corresponding build!"
#endif


// TODO: Add other MCU support

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

#if USB_SERIAL_CDC == 0
#define SERIAL_MOD 1
#endif

#if defined(SERIAL_MOD) && SERIAL_MOD == 2
#define SERIAL_MOD_UART2_PORTD 
#endif

#if defined(SERIAL2_MOD) && SERIAL2_MOD == 2
#define SERIAL2_MOD_UART2_PORTD 
#endif

// Default pins PB8 (SCL) & PB9 (SDA)
#define I2C_PORT 1
//#define I2C1_ALT_PINMAP // GPIOB, SCL_PIN = 6, SDA_PIN = 7

// TODO: Add support for trinamic
// #if TRINAMIC_ENABLE
// #define HAS_BOARD_INIT
// #endif

// TODO: Check all stepper IO

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
#define Y_LIMIT_PORT                GPIOG
#define Y_LIMIT_PIN                 9                           // Y- Limit
#define Z_LIMIT_PORT                GPIOG
#define Z_LIMIT_PIN                 10                          // Z- Limit
#define LIMIT_INMODE                GPIO_BITBAND

// Define ganged axis or A axis step pulse and step direction output pins.
#if N_ABC_MOTORS > 0
#define M3_AVAILABLE                // E0
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
#define M4_AVAILABLE                // E1
#define M4_STEP_PORT                GPIOF
#define M4_STEP_PIN                 9
#define M4_DIRECTION_PORT           GPIOF
#define M4_DIRECTION_PIN            10
#define M4_LIMIT_PORT               GPIOG
#define M4_LIMIT_PIN                12
#define M4_ENABLE_PORT              GPIOG
#define M4_ENABLE_PIN               2
#endif

// Define ganged axis or C axis step pulse and step direction output pins.
#if N_ABC_MOTORS == 3
#define M5_AVAILABLE                // E2
#define M5_STEP_PORT                GPIOC
#define M5_STEP_PIN                 13
#define M5_DIRECTION_PORT           GPIOF
#define M5_DIRECTION_PIN            0
#define M5_LIMIT_PORT               GPIOG
#define M5_LIMIT_PIN                13
#define M5_ENABLE_PORT              GPIOF
#define M5_ENABLE_PIN               1
#endif

/*
// Define ganged axis or C axis step pulse and step direction output pins.
#if N_ABC_MOTORS == 4
#define M6_AVAILABLE                // E3
#define M6_STEP_PORT                GPIOE
#define M6_STEP_PIN                 2
#define M6_DIRECTION_PORT           GPIOE
#define M6_DIRECTION_PIN            3
#define M6_LIMIT_PORT               GPIOG
#define M6_LIMIT_PIN                14
#define M6_ENABLE_PORT              GPIOD
#define M6_ENABLE_PIN               4
#endif

// Define ganged axis or C axis step pulse and step direction output pins.
#if N_ABC_MOTORS == 5
#define M7_AVAILABLE                // E4
#define M7_STEP_PORT                GPIOE
#define M7_STEP_PIN                 6
#define M7_DIRECTION_PORT           GPIOA
#define M7_DIRECTION_PIN            14
#define M7_LIMIT_PORT               GPIOG
#define M7_LIMIT_PIN                15
#define M7_ENABLE_PORT              GPIOE
#define M7_ENABLE_PIN               0
#endif

*/
  // Define spindle enable and spindle direction output pins.
#define SPINDLE_ENABLE_PORT         GPIOE
#define SPINDLE_ENABLE_PIN          5                           // FAN1
#define SPINDLE_DIRECTION_PORT      GPIOD
#define SPINDLE_DIRECTION_PIN       12                          // FAN2


// TODO Check this
// Define spindle PWM output pin.
#define SPINDLE_PWM_PORT_BASE       GPIOA_BASEA
#define SPINDLE_PWM_PIN             8                           // FAN0

// Define flood and mist coolant enable output pins.
#define COOLANT_FLOOD_PORT          GPIOA
#define COOLANT_FLOOD_PIN           2                           // HEAT0
#define COOLANT_MIST_PORT           GPIOA
#define COOLANT_MIST_PIN            3                           // HEAT1


// TODO
// Define user-control controls (cycle start, reset, feed hold) input pins.
#define RESET_PORT                  GPIOG
#define RESET_PIN                   6                           // EXP1 PG6
#define FEED_HOLD_PORT              GPIOD
#define FEED_HOLD_PIN               11                          // EXP1 PD11
#define CYCLE_START_PORT            GPIOG
#define CYCLE_START_PIN             2                           // EXP1 PG2
#define SAFETY_DOOR_PORT            GPIOG
#define SAFETY_DOOR_PIN             4                           // EXP1 PG4
#define CONTROL_INMODE GPIO_BITBAND


// Probe C5
// Bl-touch PB6(pin 3) & PB7(pin 1)
// Define probe switch input pin.
#define PROBE_PORT                  GPIOC
#define PROBE_PIN                   5                           // Probe Switch


// TODO
#if SDCARD_ENABLE
// Connect to the  EXP2 Header
#define SD_CS_PORT                  GPIOB
#define SD_CS_PIN                   12
#define SPI_PORT                    2 // GPIOB, SCK_PIN = 13, MISO_PIN = 14, MOSI_PIN = 15
#endif


// TODO 
/*
#if TRINAMIC_UART_ENABLE

#undef TRINAMIC_UART_ENABLE
#define TRINAMIC_UART_ENABLE        2

#define MOTOR_UARTX_PORT            GPIOC
#define MOTOR_UARTX_PIN             13
#define MOTOR_UARTY_PORT            GPIOE
#define MOTOR_UARTY_PIN             3
#define MOTOR_UARTZ_PORT            GPIOE
#define MOTOR_UARTZ_PIN             1

#ifdef  M3_AVAILABLE
#define MOTOR_UARTM3_PORT           GPIOD
#define MOTOR_UARTM3_PIN            4
#endif

#ifdef  M4_AVAILABLE
#define MOTOR_UARTM4_PORT           GPIOD
#define MOTOR_UARTM4_PIN            1
#endif

#ifdef  M5_AVAILABLE
#define MOTOR_UARTM5_PORT           GPIOD
#define MOTOR_UARTM5_PIN            6
#endif

#endif

#if TRINAMIC_SPI_ENABLE

#define TRINAMIC_SPI_PORT           3 // GPIOC, SCK_PIN = 10, MISO_PIN = 12, MOSI_PIN = 11

#define MOTOR_CSX_PORT              GPIOA
#define MOTOR_CSX_PIN               15
#define MOTOR_CSY_PORT              GPIOB
#define MOTOR_CSY_PIN               8
#define MOTOR_CSZ_PORT              GPIOB
#define MOTOR_CSZ_PIN               9

#ifdef  M3_AVAILABLE
#define MOTOR_CSM3_PORT             GPIOB
#define MOTOR_CSM3_PIN              3
#endif

#ifdef  M4_AVAILABLE
#define MOTOR_CSM4_PORT             GPIOG
#define MOTOR_CSM4_PIN              15
#endif

#ifdef  M5_AVAILABLE
#define MOTOR_CSM5_PORT             GPIOG
#define MOTOR_CSM5_PIN              12
#endif

#ifdef  M6_AVAILABLE
#define MOTOR_CSM6_PORT             GPIOG
#define MOTOR_CSM6_PIN              12
#endif

#ifdef  M7_AVAILABLE
#define MOTOR_CSM7_PORT             GPIOG
#define MOTOR_CSM7_PIN              12
#endif

#endif
*/