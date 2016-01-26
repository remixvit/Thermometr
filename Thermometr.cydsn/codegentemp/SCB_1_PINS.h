/*******************************************************************************
* File Name: SCB_1_PINS.h
* Version 3.0
*
* Description:
*  This file provides constants and parameter values for the pin components
*  buried into SCB Component.
*
* Note:
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_PINS_SCB_1_H)
#define CY_SCB_PINS_SCB_1_H

#include "cydevice_trm.h"
#include "cyfitter.h"
#include "cytypes.h"


/***************************************
*   Conditional Compilation Parameters
****************************************/

/* Unconfigured pins */
#define SCB_1_REMOVE_RX_WAKE_SCL_MOSI_PIN  (1u)
#define SCB_1_REMOVE_RX_SCL_MOSI_PIN      (1u)
#define SCB_1_REMOVE_TX_SDA_MISO_PIN      (1u)
#define SCB_1_REMOVE_SCLK_PIN      (1u)
#define SCB_1_REMOVE_SS0_PIN      (1u)
#define SCB_1_REMOVE_SS1_PIN                 (1u)
#define SCB_1_REMOVE_SS2_PIN                 (1u)
#define SCB_1_REMOVE_SS3_PIN                 (1u)

/* Mode defined pins */
#define SCB_1_REMOVE_I2C_PINS                (1u)
#define SCB_1_REMOVE_SPI_MASTER_PINS         (0u)
#define SCB_1_REMOVE_SPI_MASTER_SCLK_PIN     (0u)
#define SCB_1_REMOVE_SPI_MASTER_MOSI_PIN     (0u)
#define SCB_1_REMOVE_SPI_MASTER_MISO_PIN     (0u)
#define SCB_1_REMOVE_SPI_MASTER_SS0_PIN      (0u)
#define SCB_1_REMOVE_SPI_MASTER_SS1_PIN      (0u)
#define SCB_1_REMOVE_SPI_MASTER_SS2_PIN      (1u)
#define SCB_1_REMOVE_SPI_MASTER_SS3_PIN      (1u)
#define SCB_1_REMOVE_SPI_SLAVE_PINS          (1u)
#define SCB_1_REMOVE_SPI_SLAVE_MOSI_PIN      (1u)
#define SCB_1_REMOVE_SPI_SLAVE_MISO_PIN      (1u)
#define SCB_1_REMOVE_UART_TX_PIN             (1u)
#define SCB_1_REMOVE_UART_RX_TX_PIN          (1u)
#define SCB_1_REMOVE_UART_RX_PIN             (1u)
#define SCB_1_REMOVE_UART_RX_WAKE_PIN        (1u)
#define SCB_1_REMOVE_UART_RTS_PIN            (1u)
#define SCB_1_REMOVE_UART_CTS_PIN            (1u)

/* Unconfigured pins */
#define SCB_1_RX_WAKE_SCL_MOSI_PIN (0u == SCB_1_REMOVE_RX_WAKE_SCL_MOSI_PIN)
#define SCB_1_RX_SCL_MOSI_PIN     (0u == SCB_1_REMOVE_RX_SCL_MOSI_PIN)
#define SCB_1_TX_SDA_MISO_PIN     (0u == SCB_1_REMOVE_TX_SDA_MISO_PIN)
#define SCB_1_SCLK_PIN     (0u == SCB_1_REMOVE_SCLK_PIN)
#define SCB_1_SS0_PIN     (0u == SCB_1_REMOVE_SS0_PIN)
#define SCB_1_SS1_PIN                (0u == SCB_1_REMOVE_SS1_PIN)
#define SCB_1_SS2_PIN                (0u == SCB_1_REMOVE_SS2_PIN)
#define SCB_1_SS3_PIN                (0u == SCB_1_REMOVE_SS3_PIN)

/* Mode defined pins */
#define SCB_1_I2C_PINS               (0u == SCB_1_REMOVE_I2C_PINS)
#define SCB_1_SPI_MASTER_PINS        (0u == SCB_1_REMOVE_SPI_MASTER_PINS)
#define SCB_1_SPI_MASTER_SCLK_PIN    (0u == SCB_1_REMOVE_SPI_MASTER_SCLK_PIN)
#define SCB_1_SPI_MASTER_MOSI_PIN    (0u == SCB_1_REMOVE_SPI_MASTER_MOSI_PIN)
#define SCB_1_SPI_MASTER_MISO_PIN    (0u == SCB_1_REMOVE_SPI_MASTER_MISO_PIN)
#define SCB_1_SPI_MASTER_SS0_PIN     (0u == SCB_1_REMOVE_SPI_MASTER_SS0_PIN)
#define SCB_1_SPI_MASTER_SS1_PIN     (0u == SCB_1_REMOVE_SPI_MASTER_SS1_PIN)
#define SCB_1_SPI_MASTER_SS2_PIN     (0u == SCB_1_REMOVE_SPI_MASTER_SS2_PIN)
#define SCB_1_SPI_MASTER_SS3_PIN     (0u == SCB_1_REMOVE_SPI_MASTER_SS3_PIN)
#define SCB_1_SPI_SLAVE_PINS         (0u == SCB_1_REMOVE_SPI_SLAVE_PINS)
#define SCB_1_SPI_SLAVE_MOSI_PIN     (0u == SCB_1_REMOVE_SPI_SLAVE_MOSI_PIN)
#define SCB_1_SPI_SLAVE_MISO_PIN     (0u == SCB_1_REMOVE_SPI_SLAVE_MISO_PIN)
#define SCB_1_UART_TX_PIN            (0u == SCB_1_REMOVE_UART_TX_PIN)
#define SCB_1_UART_RX_TX_PIN         (0u == SCB_1_REMOVE_UART_RX_TX_PIN)
#define SCB_1_UART_RX_PIN            (0u == SCB_1_REMOVE_UART_RX_PIN)
#define SCB_1_UART_RX_WAKE_PIN       (0u == SCB_1_REMOVE_UART_RX_WAKE_PIN)
#define SCB_1_UART_RTS_PIN           (0u == SCB_1_REMOVE_UART_RTS_PIN)
#define SCB_1_UART_CTS_PIN           (0u == SCB_1_REMOVE_UART_CTS_PIN)


/***************************************
*             Includes
****************************************/

#if (SCB_1_RX_WAKE_SCL_MOSI_PIN)
    #include "SCB_1_uart_rx_wake_i2c_scl_spi_mosi.h"
#endif /* (SCB_1_RX_SCL_MOSI) */

#if (SCB_1_RX_SCL_MOSI_PIN)
    #include "SCB_1_uart_rx_i2c_scl_spi_mosi.h"
#endif /* (SCB_1_RX_SCL_MOSI) */

#if (SCB_1_TX_SDA_MISO_PIN)
    #include "SCB_1_uart_tx_i2c_sda_spi_miso.h"
#endif /* (SCB_1_TX_SDA_MISO) */

#if (SCB_1_SCLK_PIN)
    #include "SCB_1_spi_sclk.h"
#endif /* (SCB_1_SCLK) */

#if (SCB_1_SS0_PIN)
    #include "SCB_1_spi_ss0.h"
#endif /* (SCB_1_SS0_PIN) */

#if (SCB_1_SS1_PIN)
    #include "SCB_1_spi_ss1.h"
#endif /* (SCB_1_SS1_PIN) */

#if (SCB_1_SS2_PIN)
    #include "SCB_1_spi_ss2.h"
#endif /* (SCB_1_SS2_PIN) */

#if (SCB_1_SS3_PIN)
    #include "SCB_1_spi_ss3.h"
#endif /* (SCB_1_SS3_PIN) */

#if (SCB_1_I2C_PINS)
    #include "SCB_1_scl.h"
    #include "SCB_1_sda.h"
#endif /* (SCB_1_I2C_PINS) */

#if (SCB_1_SPI_MASTER_PINS)
#if (SCB_1_SPI_MASTER_SCLK_PIN)
    #include "SCB_1_sclk_m.h"
#endif /* (SCB_1_SPI_MASTER_SCLK_PIN) */

#if (SCB_1_SPI_MASTER_MOSI_PIN)
    #include "SCB_1_mosi_m.h"
#endif /* (SCB_1_SPI_MASTER_MOSI_PIN) */

#if (SCB_1_SPI_MASTER_MISO_PIN)
    #include "SCB_1_miso_m.h"
#endif /*(SCB_1_SPI_MASTER_MISO_PIN) */
#endif /* (SCB_1_SPI_MASTER_PINS) */

#if (SCB_1_SPI_SLAVE_PINS)
    #include "SCB_1_sclk_s.h"
    #include "SCB_1_ss_s.h"

#if (SCB_1_SPI_SLAVE_MOSI_PIN)
    #include "SCB_1_mosi_s.h"
#endif /* (SCB_1_SPI_SLAVE_MOSI_PIN) */

#if (SCB_1_SPI_SLAVE_MISO_PIN)
    #include "SCB_1_miso_s.h"
#endif /*(SCB_1_SPI_SLAVE_MISO_PIN) */
#endif /* (SCB_1_SPI_SLAVE_PINS) */

#if (SCB_1_SPI_MASTER_SS0_PIN)
    #include "SCB_1_ss0_m.h"
#endif /* (SCB_1_SPI_MASTER_SS0_PIN) */

#if (SCB_1_SPI_MASTER_SS1_PIN)
    #include "SCB_1_ss1_m.h"
#endif /* (SCB_1_SPI_MASTER_SS1_PIN) */

#if (SCB_1_SPI_MASTER_SS2_PIN)
    #include "SCB_1_ss2_m.h"
#endif /* (SCB_1_SPI_MASTER_SS2_PIN) */

#if (SCB_1_SPI_MASTER_SS3_PIN)
    #include "SCB_1_ss3_m.h"
#endif /* (SCB_1_SPI_MASTER_SS3_PIN) */

#if (SCB_1_UART_TX_PIN)
    #include "SCB_1_tx.h"
#endif /* (SCB_1_UART_TX_PIN) */

#if (SCB_1_UART_RX_TX_PIN)
    #include "SCB_1_rx_tx.h"
#endif /* (SCB_1_UART_RX_TX_PIN) */

#if (SCB_1_UART_RX_PIN)
    #include "SCB_1_rx.h"
#endif /* (SCB_1_UART_RX_PIN) */

#if (SCB_1_UART_RX_WAKE_PIN)
    #include "SCB_1_rx_wake.h"
#endif /* (SCB_1_UART_RX_WAKE_PIN) */

#if (SCB_1_UART_RTS_PIN)
    #include "SCB_1_rts.h"
#endif /* (SCB_1_UART_RTS_PIN) */

#if (SCB_1_UART_CTS_PIN)
    #include "SCB_1_cts.h"
#endif /* (SCB_1_UART_CTS_PIN) */


/***************************************
*              Registers
***************************************/

#if (SCB_1_RX_WAKE_SCL_MOSI_PIN)
    #define SCB_1_RX_WAKE_SCL_MOSI_HSIOM_REG \
                            (*(reg32 *) SCB_1_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM)
    #define SCB_1_RX_WAKE_SCL_MOSI_HSIOM_PTR \
                            ( (reg32 *) SCB_1_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM)
    #define SCB_1_RX_WAKE_SCL_MOSI_HSIOM_MASK \
                            (SCB_1_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_MASK)
    #define SCB_1_RX_WAKE_SCL_MOSI_HSIOM_POS \
                            (SCB_1_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_SHIFT)

    #define SCB_1_RX_WAKE_SCL_MOSI_INTCFG_REG \
                            (*(reg32 *) SCB_1_uart_rx_wake_i2c_scl_spi_mosi__0__INTCFG)
    #define SCB_1_RX_WAKE_SCL_MOSI_INTCFG_PTR \
                            ( (reg32 *) SCB_1_uart_rx_wake_i2c_scl_spi_mosi__0__INTCFG)
    #define SCB_1_RX_WAKE_SCL_MOSI_INTCFG_TYPE_POS  (SCB_1_uart_rx_wake_i2c_scl_spi_mosi__SHIFT)
    #define SCB_1_RX_WAKE_SCL_MOSI_INTCFG_TYPE_MASK \
                            ((uint32) SCB_1_INTCFG_TYPE_MASK << \
                                      SCB_1_RX_WAKE_SCL_MOSI_INTCFG_TYPE_POS)
#endif /* (SCB_1_RX_WAKE_SCL_MOSI_PIN) */

#if (SCB_1_RX_SCL_MOSI_PIN)
    #define SCB_1_RX_SCL_MOSI_HSIOM_REG   (*(reg32 *) SCB_1_uart_rx_i2c_scl_spi_mosi__0__HSIOM)
    #define SCB_1_RX_SCL_MOSI_HSIOM_PTR   ( (reg32 *) SCB_1_uart_rx_i2c_scl_spi_mosi__0__HSIOM)
    #define SCB_1_RX_SCL_MOSI_HSIOM_MASK  (SCB_1_uart_rx_i2c_scl_spi_mosi__0__HSIOM_MASK)
    #define SCB_1_RX_SCL_MOSI_HSIOM_POS   (SCB_1_uart_rx_i2c_scl_spi_mosi__0__HSIOM_SHIFT)
#endif /* (SCB_1_RX_SCL_MOSI_PIN) */

#if (SCB_1_TX_SDA_MISO_PIN)
    #define SCB_1_TX_SDA_MISO_HSIOM_REG   (*(reg32 *) SCB_1_uart_tx_i2c_sda_spi_miso__0__HSIOM)
    #define SCB_1_TX_SDA_MISO_HSIOM_PTR   ( (reg32 *) SCB_1_uart_tx_i2c_sda_spi_miso__0__HSIOM)
    #define SCB_1_TX_SDA_MISO_HSIOM_MASK  (SCB_1_uart_tx_i2c_sda_spi_miso__0__HSIOM_MASK)
    #define SCB_1_TX_SDA_MISO_HSIOM_POS   (SCB_1_uart_tx_i2c_sda_spi_miso__0__HSIOM_SHIFT)
#endif /* (SCB_1_TX_SDA_MISO_PIN) */

#if (SCB_1_SCLK_PIN)
    #define SCB_1_SCLK_HSIOM_REG   (*(reg32 *) SCB_1_spi_sclk__0__HSIOM)
    #define SCB_1_SCLK_HSIOM_PTR   ( (reg32 *) SCB_1_spi_sclk__0__HSIOM)
    #define SCB_1_SCLK_HSIOM_MASK  (SCB_1_spi_sclk__0__HSIOM_MASK)
    #define SCB_1_SCLK_HSIOM_POS   (SCB_1_spi_sclk__0__HSIOM_SHIFT)
#endif /* (SCB_1_SCLK_PIN) */

#if (SCB_1_SS0_PIN)
    #define SCB_1_SS0_HSIOM_REG   (*(reg32 *) SCB_1_spi_ss0__0__HSIOM)
    #define SCB_1_SS0_HSIOM_PTR   ( (reg32 *) SCB_1_spi_ss0__0__HSIOM)
    #define SCB_1_SS0_HSIOM_MASK  (SCB_1_spi_ss0__0__HSIOM_MASK)
    #define SCB_1_SS0_HSIOM_POS   (SCB_1_spi_ss0__0__HSIOM_SHIFT)
#endif /* (SCB_1_SS0_PIN) */

#if (SCB_1_SS1_PIN)
    #define SCB_1_SS1_HSIOM_REG      (*(reg32 *) SCB_1_spi_ss1__0__HSIOM)
    #define SCB_1_SS1_HSIOM_PTR      ( (reg32 *) SCB_1_spi_ss1__0__HSIOM)
    #define SCB_1_SS1_HSIOM_MASK     (SCB_1_spi_ss1__0__HSIOM_MASK)
    #define SCB_1_SS1_HSIOM_POS      (SCB_1_spi_ss1__0__HSIOM_SHIFT)
#endif /* (SCB_1_SS1_PIN) */

#if (SCB_1_SS2_PIN)
    #define SCB_1_SS2_HSIOM_REG     (*(reg32 *) SCB_1_spi_ss2__0__HSIOM)
    #define SCB_1_SS2_HSIOM_PTR     ( (reg32 *) SCB_1_spi_ss2__0__HSIOM)
    #define SCB_1_SS2_HSIOM_MASK    (SCB_1_spi_ss2__0__HSIOM_MASK)
    #define SCB_1_SS2_HSIOM_POS     (SCB_1_spi_ss2__0__HSIOM_SHIFT)
#endif /* (SCB_1_SS2_PIN) */

#if (SCB_1_SS3_PIN)
    #define SCB_1_SS3_HSIOM_REG     (*(reg32 *) SCB_1_spi_ss3__0__HSIOM)
    #define SCB_1_SS3_HSIOM_PTR     ( (reg32 *) SCB_1_spi_ss3__0__HSIOM)
    #define SCB_1_SS3_HSIOM_MASK    (SCB_1_spi_ss3__0__HSIOM_MASK)
    #define SCB_1_SS3_HSIOM_POS     (SCB_1_spi_ss3__0__HSIOM_SHIFT)
#endif /* (SCB_1_SS3_PIN) */

#if (SCB_1_I2C_PINS)
    #define SCB_1_SCL_HSIOM_REG     (*(reg32 *) SCB_1_scl__0__HSIOM)
    #define SCB_1_SCL_HSIOM_PTR     ( (reg32 *) SCB_1_scl__0__HSIOM)
    #define SCB_1_SCL_HSIOM_MASK    (SCB_1_scl__0__HSIOM_MASK)
    #define SCB_1_SCL_HSIOM_POS     (SCB_1_scl__0__HSIOM_SHIFT)

    #define SCB_1_SDA_HSIOM_REG     (*(reg32 *) SCB_1_sda__0__HSIOM)
    #define SCB_1_SDA_HSIOM_PTR     ( (reg32 *) SCB_1_sda__0__HSIOM)
    #define SCB_1_SDA_HSIOM_MASK    (SCB_1_sda__0__HSIOM_MASK)
    #define SCB_1_SDA_HSIOM_POS     (SCB_1_sda__0__HSIOM_SHIFT)
#endif /* (SCB_1_I2C_PINS) */

#if (SCB_1_SPI_MASTER_SCLK_PIN)
    #define SCB_1_SCLK_M_HSIOM_REG   (*(reg32 *) SCB_1_sclk_m__0__HSIOM)
    #define SCB_1_SCLK_M_HSIOM_PTR   ( (reg32 *) SCB_1_sclk_m__0__HSIOM)
    #define SCB_1_SCLK_M_HSIOM_MASK  (SCB_1_sclk_m__0__HSIOM_MASK)
    #define SCB_1_SCLK_M_HSIOM_POS   (SCB_1_sclk_m__0__HSIOM_SHIFT)
#endif /* (SCB_1_SPI_MASTER_SCLK_PIN) */

#if (SCB_1_SPI_MASTER_SS0_PIN)
    #define SCB_1_SS0_M_HSIOM_REG    (*(reg32 *) SCB_1_ss0_m__0__HSIOM)
    #define SCB_1_SS0_M_HSIOM_PTR    ( (reg32 *) SCB_1_ss0_m__0__HSIOM)
    #define SCB_1_SS0_M_HSIOM_MASK   (SCB_1_ss0_m__0__HSIOM_MASK)
    #define SCB_1_SS0_M_HSIOM_POS    (SCB_1_ss0_m__0__HSIOM_SHIFT)
#endif /* (SCB_1_SPI_MASTER_SS0_PIN) */

#if (SCB_1_SPI_MASTER_SS1_PIN)
    #define SCB_1_SS1_M_HSIOM_REG    (*(reg32 *) SCB_1_ss1_m__0__HSIOM)
    #define SCB_1_SS1_M_HSIOM_PTR    ( (reg32 *) SCB_1_ss1_m__0__HSIOM)
    #define SCB_1_SS1_M_HSIOM_MASK   (SCB_1_ss1_m__0__HSIOM_MASK)
    #define SCB_1_SS1_M_HSIOM_POS    (SCB_1_ss1_m__0__HSIOM_SHIFT)
#endif /* (SCB_1_SPI_MASTER_SS1_PIN) */

#if (SCB_1_SPI_MASTER_SS2_PIN)
    #define SCB_1_SS2_M_HSIOM_REG    (*(reg32 *) SCB_1_ss2_m__0__HSIOM)
    #define SCB_1_SS2_M_HSIOM_PTR    ( (reg32 *) SCB_1_ss2_m__0__HSIOM)
    #define SCB_1_SS2_M_HSIOM_MASK   (SCB_1_ss2_m__0__HSIOM_MASK)
    #define SCB_1_SS2_M_HSIOM_POS    (SCB_1_ss2_m__0__HSIOM_SHIFT)
#endif /* (SCB_1_SPI_MASTER_SS2_PIN) */

#if (SCB_1_SPI_MASTER_SS3_PIN)
    #define SCB_1_SS3_M_HSIOM_REG    (*(reg32 *) SCB_1_ss3_m__0__HSIOM)
    #define SCB_1_SS3_M_HSIOM_PTR    ( (reg32 *) SCB_1_ss3_m__0__HSIOM)
    #define SCB_1_SS3_M_HSIOM_MASK   (SCB_1_ss3_m__0__HSIOM_MASK)
    #define SCB_1_SS3_M_HSIOM_POS    (SCB_1_ss3_m__0__HSIOM_SHIFT)
#endif /* (SCB_1_SPI_MASTER_SS3_PIN) */

#if (SCB_1_UART_TX_PIN)
    #define SCB_1_TX_HSIOM_REG   (*(reg32 *) SCB_1_tx__0__HSIOM)
    #define SCB_1_TX_HSIOM_PTR   ( (reg32 *) SCB_1_tx_0__HSIOM)
    #define SCB_1_TX_HSIOM_MASK  (SCB_1_tx__0__HSIOM_MASK)
    #define SCB_1_TX_HSIOM_POS   (SCB_1_tx__0__HSIOM_SHIFT)
#endif /* (SCB_1_UART_TX_PIN) */

#if (SCB_1_UART_RTS_PIN)
    #define SCB_1_RTS_HSIOM_REG  (*(reg32 *) SCB_1_rts__0__HSIOM)
    #define SCB_1_RTS_HSIOM_PTR  ( (reg32 *) SCB_1_rts__0__HSIOM)
    #define SCB_1_RTS_HSIOM_MASK (SCB_1_rts__0__HSIOM_MASK)
    #define SCB_1_RTS_HSIOM_POS  (SCB_1_rts__0__HSIOM_SHIFT)
#endif /* (SCB_1_UART_RTS_PIN) */


/***************************************
*        Registers Constants
***************************************/

/* Pins constants */
#define SCB_1_HSIOM_DEF_SEL      (0x00u)
#define SCB_1_HSIOM_GPIO_SEL     (0x00u)
#define SCB_1_HSIOM_UART_SEL     (0x09u)
#define SCB_1_HSIOM_I2C_SEL      (0x0Eu)
#define SCB_1_HSIOM_SPI_SEL      (0x0Fu)

#define SCB_1_RX_WAKE_SCL_MOSI_PIN_INDEX   (0u)
#define SCB_1_RX_SCL_MOSI_PIN_INDEX       (0u)
#define SCB_1_TX_SDA_MISO_PIN_INDEX       (1u)
#define SCB_1_SCLK_PIN_INDEX       (2u)
#define SCB_1_SS0_PIN_INDEX       (3u)
#define SCB_1_SS1_PIN_INDEX                  (4u)
#define SCB_1_SS2_PIN_INDEX                  (5u)
#define SCB_1_SS3_PIN_INDEX                  (6u)

#define SCB_1_RX_WAKE_SCL_MOSI_PIN_MASK ((uint32) 0x01u << SCB_1_RX_WAKE_SCL_MOSI_PIN_INDEX)
#define SCB_1_RX_SCL_MOSI_PIN_MASK     ((uint32) 0x01u << SCB_1_RX_SCL_MOSI_PIN_INDEX)
#define SCB_1_TX_SDA_MISO_PIN_MASK     ((uint32) 0x01u << SCB_1_TX_SDA_MISO_PIN_INDEX)
#define SCB_1_SCLK_PIN_MASK     ((uint32) 0x01u << SCB_1_SCLK_PIN_INDEX)
#define SCB_1_SS0_PIN_MASK     ((uint32) 0x01u << SCB_1_SS0_PIN_INDEX)
#define SCB_1_SS1_PIN_MASK                ((uint32) 0x01u << SCB_1_SS1_PIN_INDEX)
#define SCB_1_SS2_PIN_MASK                ((uint32) 0x01u << SCB_1_SS2_PIN_INDEX)
#define SCB_1_SS3_PIN_MASK                ((uint32) 0x01u << SCB_1_SS3_PIN_INDEX)

/* Pin interrupt constants */
#define SCB_1_INTCFG_TYPE_MASK           (0x03u)
#define SCB_1_INTCFG_TYPE_FALLING_EDGE   (0x02u)

/* Pin Drive Mode constants */
#define SCB_1_PIN_DM_ALG_HIZ  (0u)
#define SCB_1_PIN_DM_DIG_HIZ  (1u)
#define SCB_1_PIN_DM_OD_LO    (4u)
#define SCB_1_PIN_DM_STRONG   (6u)


/***************************************
*          Macro Definitions
***************************************/

/* Return drive mode of the pin */
#define SCB_1_DM_MASK    (0x7u)
#define SCB_1_DM_SIZE    (3)
#define SCB_1_GET_P4_PIN_DM(reg, pos) \
    ( ((reg) & (uint32) ((uint32) SCB_1_DM_MASK << (SCB_1_DM_SIZE * (pos)))) >> \
                                                              (SCB_1_DM_SIZE * (pos)) )

#if (SCB_1_TX_SDA_MISO_PIN)
    #define SCB_1_CHECK_TX_SDA_MISO_PIN_USED \
                (SCB_1_PIN_DM_ALG_HIZ != \
                    SCB_1_GET_P4_PIN_DM(SCB_1_uart_tx_i2c_sda_spi_miso_PC, \
                                                   SCB_1_uart_tx_i2c_sda_spi_miso_SHIFT))
#endif /* (SCB_1_TX_SDA_MISO_PIN) */

#if (SCB_1_SS0_PIN)
    #define SCB_1_CHECK_SS0_PIN_USED \
                (SCB_1_PIN_DM_ALG_HIZ != \
                    SCB_1_GET_P4_PIN_DM(SCB_1_spi_ss0_PC, \
                                                   SCB_1_spi_ss0_SHIFT))
#endif /* (SCB_1_SS0_PIN) */

/* Set bits-mask in register */
#define SCB_1_SET_REGISTER_BITS(reg, mask, pos, mode) \
                    do                                           \
                    {                                            \
                        (reg) = (((reg) & ((uint32) ~(uint32) (mask))) | ((uint32) ((uint32) (mode) << (pos)))); \
                    }while(0)

/* Set bit in the register */
#define SCB_1_SET_REGISTER_BIT(reg, mask, val) \
                    ((val) ? ((reg) |= (mask)) : ((reg) &= ((uint32) ~((uint32) (mask)))))

#define SCB_1_SET_HSIOM_SEL(reg, mask, pos, sel) SCB_1_SET_REGISTER_BITS(reg, mask, pos, sel)
#define SCB_1_SET_INCFG_TYPE(reg, mask, pos, intType) \
                                                        SCB_1_SET_REGISTER_BITS(reg, mask, pos, intType)
#define SCB_1_SET_INP_DIS(reg, mask, val) SCB_1_SET_REGISTER_BIT(reg, mask, val)

/* SCB_1_SET_I2C_SCL_DR(val) - Sets I2C SCL DR register.
*  SCB_1_SET_I2C_SCL_HSIOM_SEL(sel) - Sets I2C SCL HSIOM settings.
*/
/* SCB I2C: scl signal */
#if (SCB_1_CY_SCBIP_V0)
#if (SCB_1_I2C_PINS)
    #define SCB_1_SET_I2C_SCL_DR(val) SCB_1_scl_Write(val)

    #define SCB_1_SET_I2C_SCL_HSIOM_SEL(sel) \
                          SCB_1_SET_HSIOM_SEL(SCB_1_SCL_HSIOM_REG,  \
                                                         SCB_1_SCL_HSIOM_MASK, \
                                                         SCB_1_SCL_HSIOM_POS,  \
                                                         (sel))
    #define SCB_1_WAIT_SCL_SET_HIGH  (0u == SCB_1_scl_Read())

/* Unconfigured SCB: scl signal */
#elif (SCB_1_RX_WAKE_SCL_MOSI_PIN)
    #define SCB_1_SET_I2C_SCL_DR(val) \
                            SCB_1_uart_rx_wake_i2c_scl_spi_mosi_Write(val)

    #define SCB_1_SET_I2C_SCL_HSIOM_SEL(sel) \
                    SCB_1_SET_HSIOM_SEL(SCB_1_RX_WAKE_SCL_MOSI_HSIOM_REG,  \
                                                   SCB_1_RX_WAKE_SCL_MOSI_HSIOM_MASK, \
                                                   SCB_1_RX_WAKE_SCL_MOSI_HSIOM_POS,  \
                                                   (sel))

    #define SCB_1_WAIT_SCL_SET_HIGH  (0u == SCB_1_uart_rx_wake_i2c_scl_spi_mosi_Read())

#elif (SCB_1_RX_SCL_MOSI_PIN)
    #define SCB_1_SET_I2C_SCL_DR(val) \
                            SCB_1_uart_rx_i2c_scl_spi_mosi_Write(val)


    #define SCB_1_SET_I2C_SCL_HSIOM_SEL(sel) \
                            SCB_1_SET_HSIOM_SEL(SCB_1_RX_SCL_MOSI_HSIOM_REG,  \
                                                           SCB_1_RX_SCL_MOSI_HSIOM_MASK, \
                                                           SCB_1_RX_SCL_MOSI_HSIOM_POS,  \
                                                           (sel))

    #define SCB_1_WAIT_SCL_SET_HIGH  (0u == SCB_1_uart_rx_i2c_scl_spi_mosi_Read())

#else
    #define SCB_1_SET_I2C_SCL_DR(val) \
                                                    do{ /* Does nothing */ }while(0)
    #define SCB_1_SET_I2C_SCL_HSIOM_SEL(sel) \
                                                    do{ /* Does nothing */ }while(0)

    #define SCB_1_WAIT_SCL_SET_HIGH  (0u)
#endif /* (SCB_1_I2C_PINS) */

/* SCB I2C: sda signal */
#if (SCB_1_I2C_PINS)
    #define SCB_1_WAIT_SDA_SET_HIGH  (0u == SCB_1_sda_Read())
/* Unconfigured SCB: sda signal */
#elif (SCB_1_TX_SDA_MISO_PIN)
    #define SCB_1_WAIT_SDA_SET_HIGH  (0u == SCB_1_uart_tx_i2c_sda_spi_miso_Read())
#else
    #define SCB_1_WAIT_SDA_SET_HIGH  (0u)
#endif /* (SCB_1_MOSI_SCL_RX_PIN) */
#endif /* (SCB_1_CY_SCBIP_V0) */


/***************************************
* The following code is DEPRECATED and
* must not be used.
***************************************/

/* Unconfigured pins */
#define SCB_1_REMOVE_MOSI_SCL_RX_WAKE_PIN    SCB_1_REMOVE_RX_WAKE_SCL_MOSI_PIN
#define SCB_1_REMOVE_MOSI_SCL_RX_PIN         SCB_1_REMOVE_RX_SCL_MOSI_PIN
#define SCB_1_REMOVE_MISO_SDA_TX_PIN         SCB_1_REMOVE_TX_SDA_MISO_PIN
#ifndef SCB_1_REMOVE_SCLK_PIN
#define SCB_1_REMOVE_SCLK_PIN                SCB_1_REMOVE_SCLK_PIN
#endif /* SCB_1_REMOVE_SCLK_PIN */
#ifndef SCB_1_REMOVE_SS0_PIN
#define SCB_1_REMOVE_SS0_PIN                 SCB_1_REMOVE_SS0_PIN
#endif /* SCB_1_REMOVE_SS0_PIN */

/* Unconfigured pins */
#define SCB_1_MOSI_SCL_RX_WAKE_PIN   SCB_1_RX_WAKE_SCL_MOSI_PIN
#define SCB_1_MOSI_SCL_RX_PIN        SCB_1_RX_SCL_MOSI_PIN
#define SCB_1_MISO_SDA_TX_PIN        SCB_1_TX_SDA_MISO_PIN
#ifndef SCB_1_SCLK_PIN
#define SCB_1_SCLK_PIN               SCB_1_SCLK_PIN
#endif /* SCB_1_SCLK_PIN */
#ifndef SCB_1_SS0_PIN
#define SCB_1_SS0_PIN                SCB_1_SS0_PIN
#endif /* SCB_1_SS0_PIN */

#if (SCB_1_MOSI_SCL_RX_WAKE_PIN)
    #define SCB_1_MOSI_SCL_RX_WAKE_HSIOM_REG     SCB_1_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define SCB_1_MOSI_SCL_RX_WAKE_HSIOM_PTR     SCB_1_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define SCB_1_MOSI_SCL_RX_WAKE_HSIOM_MASK    SCB_1_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define SCB_1_MOSI_SCL_RX_WAKE_HSIOM_POS     SCB_1_RX_WAKE_SCL_MOSI_HSIOM_REG

    #define SCB_1_MOSI_SCL_RX_WAKE_INTCFG_REG    SCB_1_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define SCB_1_MOSI_SCL_RX_WAKE_INTCFG_PTR    SCB_1_RX_WAKE_SCL_MOSI_HSIOM_REG

    #define SCB_1_MOSI_SCL_RX_WAKE_INTCFG_TYPE_POS   SCB_1_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define SCB_1_MOSI_SCL_RX_WAKE_INTCFG_TYPE_MASK  SCB_1_RX_WAKE_SCL_MOSI_HSIOM_REG
#endif /* (SCB_1_RX_WAKE_SCL_MOSI_PIN) */

#if (SCB_1_MOSI_SCL_RX_PIN)
    #define SCB_1_MOSI_SCL_RX_HSIOM_REG      SCB_1_RX_SCL_MOSI_HSIOM_REG
    #define SCB_1_MOSI_SCL_RX_HSIOM_PTR      SCB_1_RX_SCL_MOSI_HSIOM_PTR
    #define SCB_1_MOSI_SCL_RX_HSIOM_MASK     SCB_1_RX_SCL_MOSI_HSIOM_MASK
    #define SCB_1_MOSI_SCL_RX_HSIOM_POS      SCB_1_RX_SCL_MOSI_HSIOM_POS
#endif /* (SCB_1_MOSI_SCL_RX_PIN) */

#if (SCB_1_MISO_SDA_TX_PIN)
    #define SCB_1_MISO_SDA_TX_HSIOM_REG      SCB_1_TX_SDA_MISO_HSIOM_REG
    #define SCB_1_MISO_SDA_TX_HSIOM_PTR      SCB_1_TX_SDA_MISO_HSIOM_REG
    #define SCB_1_MISO_SDA_TX_HSIOM_MASK     SCB_1_TX_SDA_MISO_HSIOM_REG
    #define SCB_1_MISO_SDA_TX_HSIOM_POS      SCB_1_TX_SDA_MISO_HSIOM_REG
#endif /* (SCB_1_MISO_SDA_TX_PIN_PIN) */

#if (SCB_1_SCLK_PIN)
    #ifndef SCB_1_SCLK_HSIOM_REG
    #define SCB_1_SCLK_HSIOM_REG     SCB_1_SCLK_HSIOM_REG
    #define SCB_1_SCLK_HSIOM_PTR     SCB_1_SCLK_HSIOM_PTR
    #define SCB_1_SCLK_HSIOM_MASK    SCB_1_SCLK_HSIOM_MASK
    #define SCB_1_SCLK_HSIOM_POS     SCB_1_SCLK_HSIOM_POS
    #endif /* SCB_1_SCLK_HSIOM_REG */
#endif /* (SCB_1_SCLK_PIN) */

#if (SCB_1_SS0_PIN)
    #ifndef SCB_1_SS0_HSIOM_REG
    #define SCB_1_SS0_HSIOM_REG      SCB_1_SS0_HSIOM_REG
    #define SCB_1_SS0_HSIOM_PTR      SCB_1_SS0_HSIOM_PTR
    #define SCB_1_SS0_HSIOM_MASK     SCB_1_SS0_HSIOM_MASK
    #define SCB_1_SS0_HSIOM_POS      SCB_1_SS0_HSIOM_POS
    #endif /* SCB_1_SS0_HSIOM_REG */
#endif /* (SCB_1_SS0_PIN) */

#define SCB_1_MOSI_SCL_RX_WAKE_PIN_INDEX SCB_1_RX_WAKE_SCL_MOSI_PIN_INDEX
#define SCB_1_MOSI_SCL_RX_PIN_INDEX      SCB_1_RX_SCL_MOSI_PIN_INDEX
#define SCB_1_MISO_SDA_TX_PIN_INDEX      SCB_1_TX_SDA_MISO_PIN_INDEX
#ifndef SCB_1_SCLK_PIN_INDEX
#define SCB_1_SCLK_PIN_INDEX             SCB_1_SCLK_PIN_INDEX
#endif /* SCB_1_SCLK_PIN_INDEX */
#ifndef SCB_1_SS0_PIN_INDEX
#define SCB_1_SS0_PIN_INDEX              SCB_1_SS0_PIN_INDEX
#endif /* SCB_1_SS0_PIN_INDEX */

#define SCB_1_MOSI_SCL_RX_WAKE_PIN_MASK SCB_1_RX_WAKE_SCL_MOSI_PIN_MASK
#define SCB_1_MOSI_SCL_RX_PIN_MASK      SCB_1_RX_SCL_MOSI_PIN_MASK
#define SCB_1_MISO_SDA_TX_PIN_MASK      SCB_1_TX_SDA_MISO_PIN_MASK
#ifndef SCB_1_SCLK_PIN_MASK
#define SCB_1_SCLK_PIN_MASK             SCB_1_SCLK_PIN_MASK
#endif /* SCB_1_SCLK_PIN_MASK */
#ifndef SCB_1_SS0_PIN_MASK
#define SCB_1_SS0_PIN_MASK              SCB_1_SS0_PIN_MASK
#endif /* SCB_1_SS0_PIN_MASK */

#endif /* (CY_SCB_PINS_SCB_1_H) */


/* [] END OF FILE */
