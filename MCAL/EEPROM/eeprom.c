#include "eeprom.h"

Std_ReturnType eeprom_write_byte(uint16 EADD, uint8 EData){
    Std_ReturnType ret = E_OK;
    /* Read the Interrupt Status "Enabled or Disabled" */
    uint8 Global_Interrupt_Status = INTCONbits.GIE;
    /* Update the Address Registers */
    EEADRH = (uint8)((EADD >> 8) & 0x03);
    EEADR = (uint8)(EADD & 0xFF);
    /* Update the Data Register */
    EEDATA = EData;
    /* Select Access data EEPROM memory */
    EECON1bits.EEPGD = 0;
    EECON1bits.CFGS = 0;
    /* Allows write cycles to Flash program/data EEPROM */
    EECON1bits.WREN = 1;
    /* Disable all interrupts "General Interrupt" */
    INTERRUPT_GlobalInterruptDisable();
    /* Write the required sequence : 0x55 -> 0xAA */
    EECON2 = 0x55;
    EECON2 = 0xAA;
    /* Initiates a data EEPROM erase/write cycle */
    EECON1bits.WR = 1;
    /* Wait for write to complete */
    while(EECON1bits.WR);
    /* Inhibits write cycles to Flash program/data EEPROM */
    EECON1bits.WREN = 0;
    /* Restore the Interrupt Status "Enabled or Disabled" */
    INTCONbits.GIE = Global_Interrupt_Status;
    return ret;
}
Std_ReturnType eeprom_read_byte(uint16 EADD, uint8 *EData){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == EData){
        ret = E_NOT_OK;
    }
    else{
        /* Update the Address Registers */
        EEADRH = (uint8)((EADD >> 8) & 0x03);
        EEADR = (uint8)(EADD & 0xFF);
        /* Select Access data EEPROM memory */
        EECON1bits.EEPGD = 0;
        EECON1bits.CFGS = 0;
        /* Initiates a data EEPROM read cycle */
        EECON1bits.RD = 1;
        NOP(); /* NOPs may be required for latency at high frequencies */
        NOP(); /* NOPs may be required for latency at high frequencies */
        /* Return data */
        *EData = EEDATA;
        ret = E_OK;
    }
    return ret;
}