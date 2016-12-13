#include "stm32f0xx.h"
#include "stdint.h"
#include "xdebug.h"

/** @addtogroup Exported_macros
  * @{
  */
#define SET_BIT(REG, BIT)     ((REG) |= (BIT))
#define CLEAR_BIT(REG, BIT)   ((REG) &= ~(BIT))
#define READ_BIT(REG, BIT)    ((REG) & (BIT))
#define CLEAR_REG(REG)        ((REG) = (0x0))
#define WRITE_REG(REG, VAL)   ((REG) = (VAL))
#define READ_REG(REG)         ((REG))
#define MODIFY_REG(REG, CLEARMASK, SETMASK)  WRITE_REG((REG), (((READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK)))
#define UNUSED(x) ((void)(x))

#define P_CSN_LOW() GPIOA->BSRR = GPIO_BSRR_BR_3
#define P_CSN_HIGH() GPIOA->BSRR = GPIO_BSRR_BS_3

#define P_CE_LOW() GPIOA->BSRR = GPIO_BSRR_BR_4
#define P_CE_HIGH() GPIOA->BSRR = GPIO_BSRR_BS_4

#define DWT_CYCCNT    *(volatile uint32_t *)0xE0001004
#define DWT_CONTROL   *(volatile uint32_t *)0xE0001000
#define SCB_DEMCR     *(volatile uint32_t *)0xE000EDFC
      
void System_Configure (void);
void RTC_Configure (void);
void USART_Configure(void);
void SPI_Configure (void);
void GPIO_Configure (void);
void TIM_Configure (void);
  
void SPI_SendData(uint8_t *Data, uint16_t Length);
void SPI_ReadRxFifoData(uint8_t *Data, uint16_t Length);
void SPI_ReadData(uint8_t *Data, uint16_t Length, uint8_t Dummy);
void SPI_FlushRxFifo(void);

void USART_SendChar( unsigned char ch);
void USART_SendData(uint8_t *Data, uint16_t Length);

void FLASH_WriteData(uint32_t fAddress, uint8_t *Data, uint8_t Size,
                     uint32_t EraseAddress);

void EXTI_IRQHandler(uint8_t Pin);
void TIM_IRQHandler(void);