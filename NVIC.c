/*
 * NVIC.c
 *
 *  Created on: Jul 27, 2024
 *      Author: Administrator
 */

#include "NVIC.h"

void NVIC_EnableIRQ(NVIC_IRQType IRQ_Num)
{
//no base priority access?
    if(IRQ_Num<=31)
        NVIC_EN0_REG |= (1<<IRQ_Num); //0=>portA unlike the vector number

    else if(IRQ_Num > 31 && IRQ_Num<=63)
        NVIC_EN1_REG |= (1<<(IRQ_Num %32));

    else if (IRQ_Num > 63 && IRQ_Num<=95)
        NVIC_EN2_REG |= (1<<(IRQ_Num %64));

    else if (IRQ_Num > 95 && IRQ_Num<=127)
           NVIC_EN3_REG |= (1<<(IRQ_Num %96));

    else if (IRQ_Num > 127 && IRQ_Num<=138)
           NVIC_EN4_REG |= (1<<(IRQ_Num %128));
    else
    {
        //error;
    }

}
void NVIC_DisableIRQ(NVIC_IRQType IRQ_Num)
{

        if(IRQ_Num<=31)
            NVIC_DIS0_REG |= (1<<IRQ_Num); //0=>portA unlike the vector number

        else if(IRQ_Num > 31 && IRQ_Num<=63)
            NVIC_DIS1_REG |= (1<<(IRQ_Num %32));

        else if (IRQ_Num > 63 && IRQ_Num<=95)
            NVIC_DIS2_REG |= (1<<(IRQ_Num %64));

        else if (IRQ_Num > 95 && IRQ_Num<=127)
               NVIC_DIS3_REG |= (1<<(IRQ_Num %96));

        else if (IRQ_Num > 127 && IRQ_Num<=138)
               NVIC_DIS4_REG |= (1<<(IRQ_Num %128));
        else
        {
            //error;
        }
}

//This function only hndle IRQ: interrupts starts from vector num 16 and up. so, Systick isn't included
void NVIC_SetPriorityIRQ(NVIC_IRQType IRQ_Num, NVIC_IRQPriorityType IRQ_Priority)
{
    //I get num bet 0 and 138
    uint8 n = IRQ_Num/4  ; //PRIn to get n
    uint8 section = IRQ_Num % 4; //gets the parts within the register
    // 0=>  bit 5
    // 1=>  bit 13
    // 2=>  bit 21
    // 3=>  bit 29
    uint8 Bit_Position = (1<<(section*8+5));

    switch(n)
    {
        case 0:
            NVIC_PRI0_REG |= (IRQ_Priority << Bit_Position); // do I have to mask?
            break;
        case 1:
            NVIC_PRI1_REG |= (IRQ_Priority << Bit_Position);
            break;
        case 2:
            NVIC_PRI2_REG |= (IRQ_Priority << Bit_Position);
            break;
        case 3:
            NVIC_PRI3_REG |= (IRQ_Priority << Bit_Position);
            break;
        case 4:
            NVIC_PRI4_REG |= (IRQ_Priority << Bit_Position);
            break;
        case 5:
            NVIC_PRI5_REG |= (IRQ_Priority << Bit_Position);
            break;
        case 6:
            NVIC_PRI6_REG |= (IRQ_Priority << Bit_Position);
            break;
        case 7:
            NVIC_PRI7_REG |= (IRQ_Priority << Bit_Position);
            break;
        case 8:
            NVIC_PRI8_REG |= (IRQ_Priority << Bit_Position);
            break;
        case 9:
            NVIC_PRI9_REG |= (IRQ_Priority << Bit_Position);
            break;
        case 10:
            NVIC_PRI10_REG |= (IRQ_Priority << Bit_Position);
            break;
        case 11:
            NVIC_PRI11_REG |= (IRQ_Priority << Bit_Position);
            break;
        case 12:
            NVIC_PRI12_REG |= (IRQ_Priority << Bit_Position);
            break;
        case 13:
            NVIC_PRI13_REG |= (IRQ_Priority << Bit_Position);
            break;
        case 14:
            NVIC_PRI14_REG |= (IRQ_Priority << Bit_Position);
            break;
        case 15:
            NVIC_PRI15_REG |= (IRQ_Priority << Bit_Position);
            break;
        case 16:
            NVIC_PRI16_REG |= (IRQ_Priority << Bit_Position);
            break;
        case 17:
            NVIC_PRI17_REG |= (IRQ_Priority << Bit_Position);
            break;
        case 18:
            NVIC_PRI18_REG |= (IRQ_Priority << Bit_Position);
            break;
        case 19:
            NVIC_PRI19_REG |= (IRQ_Priority << Bit_Position);
            break;
        case 20:
            NVIC_PRI20_REG |= (IRQ_Priority << Bit_Position);
            break;
        case 21:
            NVIC_PRI21_REG |= (IRQ_Priority << Bit_Position);
            break;
        case 22:
            NVIC_PRI22_REG |= (IRQ_Priority << Bit_Position);
            break;
        case 23:
            NVIC_PRI23_REG |= (IRQ_Priority << Bit_Position);
            break;
        case 24:
            NVIC_PRI24_REG |= (IRQ_Priority << Bit_Position);
            break;
        case 25:
            NVIC_PRI25_REG |= (IRQ_Priority << Bit_Position);
            break;
        case 26:
            NVIC_PRI26_REG |= (IRQ_Priority << Bit_Position);
            break;
        case 27:
            NVIC_PRI27_REG |= (IRQ_Priority << Bit_Position);
            break;
        case 28:
            NVIC_PRI28_REG |= (IRQ_Priority << Bit_Position);
            break;
        case 29:
            NVIC_PRI29_REG |= (IRQ_Priority << Bit_Position);
            break;
        case 30:
            NVIC_PRI30_REG |= (IRQ_Priority << Bit_Position);
            break;
        case 31:
            NVIC_PRI31_REG |= (IRQ_Priority << Bit_Position);
            break;
        case 32:
            NVIC_PRI32_REG |= (IRQ_Priority << Bit_Position);
            break;
        case 33:
            NVIC_PRI33_REG |= (IRQ_Priority << Bit_Position);
            break;
        case 34:
            NVIC_PRI34_REG |= (IRQ_Priority << Bit_Position);
            break;
        default:
            // Handle invalid input if necessary
            break;
    }






}

void NVIC_EnableException(NVIC_ExceptionType Exception_Num)
{


       switch(Exception_Num) {
               case EXCEPTION_RESET_TYPE :
                   //dnth
               break;
               case EXCEPTION_NMI_TYPE:
                   //dnth
               break;
               case EXCEPTION_HARD_FAULT_TYPE:
                   //dnth
               break;
               case EXCEPTION_MEM_FAULT_TYPE:
                   NVIC_SYSTEM_SYSHNDCTRL |= MEM_FAULT_ENABLE_MASK;
               break;
               case EXCEPTION_BUS_FAULT_TYPE:
                   NVIC_SYSTEM_SYSHNDCTRL |= BUS_FAULT_ENABLE_MASK;
               break;
               case EXCEPTION_USAGE_FAULT_TYPE:
                   NVIC_SYSTEM_SYSHNDCTRL |= USAGE_FAULT_ENABLE_MASK;
               break;
               case EXCEPTION_SVC_TYPE:
                   //dnth
               break;
               case EXCEPTION_DEBUG_MONITOR_TYPE:
                   //dnth
               break;
               case EXCEPTION_PEND_SV_TYPE:
                   //dnth
               break;
               case EXCEPTION_SYSTICK_TYPE:
                   SYSTICK_CTRL_REG   |= 0x02; //just enable
               break;
               default:
                   //error
                   break;
       }


}
void NVIC_DisableException(NVIC_ExceptionType Exception_Num)
{
    switch(Exception_Num) {
                  case EXCEPTION_RESET_TYPE:
                      //dnth
                  break;
                  case EXCEPTION_NMI_TYPE:
                      //dnth
                  break;
                  case EXCEPTION_HARD_FAULT_TYPE:
                      //dnth
                  break;
                  case EXCEPTION_MEM_FAULT_TYPE:
                      NVIC_SYSTEM_SYSHNDCTRL &= ~(MEM_FAULT_ENABLE_MASK);
                  break;
                  case EXCEPTION_BUS_FAULT_TYPE:
                      NVIC_SYSTEM_SYSHNDCTRL &= ~(BUS_FAULT_ENABLE_MASK);
                  break;
                  case EXCEPTION_USAGE_FAULT_TYPE:
                      NVIC_SYSTEM_SYSHNDCTRL &= ~(USAGE_FAULT_ENABLE_MASK);
                  break;
                  case EXCEPTION_SVC_TYPE:
                      //dnth
                  break;
                  case EXCEPTION_DEBUG_MONITOR_TYPE:
                      //dnth
                  break;
                  case EXCEPTION_PEND_SV_TYPE:
                      //dnth
                  break;
                  case EXCEPTION_SYSTICK_TYPE:
                      SYSTICK_CTRL_REG   &= ~(0x02); //just disable
                  break;
                  default:
                      //error
                      break;
          }


}
void NVIC_SetPriorityException(NVIC_ExceptionType Exception_Num, NVIC_ExceptionPriorityType Exception_Priority)
{
    switch(Exception_Num) {
                      case EXCEPTION_RESET_TYPE:
                          //dnth
                      break;
                      case EXCEPTION_NMI_TYPE:
                          //dnth
                      break;
                      case EXCEPTION_HARD_FAULT_TYPE:
                          //dnth
                      break;
                      case EXCEPTION_MEM_FAULT_TYPE:
                          /* Assign priority level 1 to the MemManage Fault Exception */
                          NVIC_SYSTEM_PRI1_REG = (NVIC_SYSTEM_PRI1_REG & ~(MEM_FAULT_PRIORITY_MASK)) | (Exception_Priority << MEM_FAULT_PRIORITY_BITS_POS);
                      break;
                      case EXCEPTION_BUS_FAULT_TYPE:
                          NVIC_SYSTEM_PRI1_REG = (NVIC_SYSTEM_PRI1_REG & ~(BUS_FAULT_PRIORITY_MASK)) | (Exception_Priority << BUS_FAULT_PRIORITY_BITS_POS);
                      break;
                      case EXCEPTION_USAGE_FAULT_TYPE:
                          NVIC_SYSTEM_PRI1_REG = (NVIC_SYSTEM_PRI1_REG & ~(USAGE_FAULT_PRIORITY_MASK)) | (Exception_Priority << USAGE_FAULT_PRIORITY_BITS_POS);
                      break;
                      case EXCEPTION_SVC_TYPE:
                          NVIC_SYSTEM_PRI2_REG = (NVIC_SYSTEM_PRI2_REG & ~(SVC_PRIORITY_MASK)) | (Exception_Priority << SVC_PRIORITY_BITS_POS);

                      break;
                      case EXCEPTION_DEBUG_MONITOR_TYPE:
                          NVIC_SYSTEM_PRI3_REG = (NVIC_SYSTEM_PRI3_REG & ~(DEBUG_MONITOR_PRIORITY_MASK)) | (Exception_Priority << DEBUG_MONITOR_PRIORITY_BITS_POS);
                      break;
                      case EXCEPTION_PEND_SV_TYPE:
                          NVIC_SYSTEM_PRI3_REG = (NVIC_SYSTEM_PRI3_REG & ~(PENDSV_PRIORITY_MASK)) | (Exception_Priority << PENDSV_PRIORITY_BITS_POS);
                      break;
                      case EXCEPTION_SYSTICK_TYPE:
                          NVIC_SYSTEM_PRI3_REG = (NVIC_SYSTEM_PRI3_REG & ~(SYSTICK_PRIORITY_MASK)) | (Exception_Priority << SYSTICK_PRIORITY_BITS_POS);
                      break;
                      default:
                          //error
                          break;
              }


}
