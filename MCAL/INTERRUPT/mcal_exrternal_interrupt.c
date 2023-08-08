#include "mcal_exrternal_interrupt.h"

/* Pointer to function to hold the callbacks for INTx & RBx */
static InterruptHandler INT0_InterruptHandler = NULL;  //To store EXT_InterruptHandler value in it
static InterruptHandler INT1_InterruptHandler = NULL;
static InterruptHandler INT2_InterruptHandler = NULL;

static InterruptHandler RB4_InterruptHandler_HIGH = NULL;
static InterruptHandler RB4_InterruptHandler_LOW = NULL;
static InterruptHandler RB5_InterruptHandler_HIGH = NULL;
static InterruptHandler RB5_InterruptHandler_LOW = NULL;
static InterruptHandler RB6_InterruptHandler_HIGH = NULL;
static InterruptHandler RB6_InterruptHandler_LOW = NULL;
static InterruptHandler RB7_InterruptHandler_HIGH = NULL;
static InterruptHandler RB7_InterruptHandler_LOW = NULL;
/*******************************************************************************/
static Std_ReturnType Interrupt_INTx_Enable(const interrupt_INTx_t *int_obj);
static Std_ReturnType Interrupt_INTx_Disable(const interrupt_INTx_t *int_obj);
static Std_ReturnType Interrupt_INTx_Priority_Init(const interrupt_INTx_t *int_obj);
static Std_ReturnType Interrupt_INTx_Edge_Init(const interrupt_INTx_t *int_obj);
static Std_ReturnType Interrupt_INTx_Pin_Init(const interrupt_INTx_t *int_obj);
static Std_ReturnType Interrupt_INTx_Clear_Flag(const interrupt_INTx_t *int_obj);

static Std_ReturnType INT0_SetInterruptHandler(void (*InterruptHandler)(void));
static Std_ReturnType INT1_SetInterruptHandler(void (*InterruptHandler)(void));
static Std_ReturnType INT2_SetInterruptHandler(void (*InterruptHandler)(void));
static Std_ReturnType Interrupt_INTx_SetInterruptHandler(const interrupt_INTx_t *int_obj);
/*******************************************************************************/
Std_ReturnType Interrupt_INTx_Init(const interrupt_INTx_t *int_obj){
    Std_ReturnType ret = E_OK;
    if(NULL == int_obj){
        ret = E_NOT_OK; /* NULL pointer detected */
    }
    else{
        ret = Interrupt_INTx_Disable(int_obj);              /* Disable the External interrupt */
        ret |= Interrupt_INTx_Clear_Flag(int_obj);          /* Clear Interrupt Flag : External interrupt did not occur */
        ret |= Interrupt_INTx_Edge_Init(int_obj);           /* Configure External interrupt edge */
#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE
        ret |= Interrupt_INTx_Priority_Init(int_obj);
#endif
        ret |= Interrupt_INTx_Pin_Init(int_obj);                /* Configure External interrupt I/O pin */
        ret |= Interrupt_INTx_SetInterruptHandler(int_obj);     /* Configure Default Interrupt CallBack */
        ret |= Interrupt_INTx_Enable(int_obj);                  /* Enable the External interrupt */
    }
    return ret;
}

Std_ReturnType Interrupt_RBx_Init(const interrupt_RBx_t *int_obj){
    Std_ReturnType ret = E_OK;
    if(NULL == int_obj){
        ret = E_NOT_OK;
    }
    else{
        EXT_RBx_InterruptDisable();             /* This routine clears the interrupt disable for the external interrupt, RBx */
        EXT_RBx_InterruptFlagClear();           /* This routine clears the interrupt flag for the external interrupt, RBx */
#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE 
        INTERRUPT_PriorityLevelsEnable();
        if(INTERRUPT_LOW_PRIORITY == int_obj->priority){ 
            INTERRUPT_GlobalInterruptLowEnable();         /* This macro will enable low priority global interrupts. */
            EXT_RBx_Priority_Low();                       /* This routine set the RBx External Interrupt Priority to be Low priority */
        }
        else if(INTERRUPT_HIGH_PRIORITY == int_obj->priority){ 
            INTERRUPT_GlobalInterruptHighEnable();          /* This macro will enable high priority global interrupts. */
            EXT_RBx_Priority_High();                        /* This routine set the RBx External Interrupt Priority to be High priority */
        }
        else{ /* Nothing */ }
#else
        INTERRUPT_GlobalInterruptEnable();
        INTERRUPT_PeripheralInterruptEnable();
#endif
        ret = gpio_pin_direction_init(&(int_obj->mcu_pin));           /* Initialize the RBx pin to be input */
        
        /* Initialize the call back functions */
        switch(int_obj->mcu_pin.pin){
            case pin_4 : 
                RB4_InterruptHandler_HIGH = int_obj->EXT_InterruptHandler_HIGH;
                RB4_InterruptHandler_LOW = int_obj->EXT_InterruptHandler_LOW;
                break;
            case pin_5 : 
                RB5_InterruptHandler_HIGH = int_obj->EXT_InterruptHandler_HIGH;
                RB5_InterruptHandler_LOW = int_obj->EXT_InterruptHandler_LOW;
                break;
            case pin_6 : 
                RB6_InterruptHandler_HIGH = int_obj->EXT_InterruptHandler_HIGH;
                RB6_InterruptHandler_LOW = int_obj->EXT_InterruptHandler_LOW;
                break;
            case pin_7 : 
                RB7_InterruptHandler_HIGH = int_obj->EXT_InterruptHandler_HIGH;
                RB7_InterruptHandler_LOW = int_obj->EXT_InterruptHandler_LOW;
                break;
            default:
                ret = E_NOT_OK;
        }
        EXT_RBx_InterruptEnable();          /* This routine sets the interrupt enable for the external interrupt, RBx */
    }
    return ret;
}
/*******************************************************************************/

static Std_ReturnType Interrupt_INTx_Enable(const interrupt_INTx_t *int_obj){
    Std_ReturnType ret = E_OK;
    if(NULL == int_obj){
        ret = E_NOT_OK;
    }
    else{
        switch(int_obj->source){
            case INTERRUPT_EXTERNAL_INT0 : 
            #if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE 
                INTERRUPT_GlobalInterruptHighEnable();
            #else
                INTERRUPT_GlobalInterruptEnable();
                INTERRUPT_PeripheralInterruptEnable();
            #endif
                EXT_INT0_InterruptEnable(); 
                break;
            case INTERRUPT_EXTERNAL_INT1 : 
            #if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE 
                INTERRUPT_PriorityLevelsEnable();
                if(INTERRUPT_LOW_PRIORITY == int_obj->priority){ 
                    INTERRUPT_GlobalInterruptLowEnable();
                }
                else if(INTERRUPT_HIGH_PRIORITY == int_obj->priority){ 
                    INTERRUPT_GlobalInterruptHighEnable();
                }
                else{ /* Nothing */ }
            #else
                INTERRUPT_GlobalInterruptEnable();
                INTERRUPT_PeripheralInterruptEnable();
            #endif
                EXT_INT1_InterruptEnable(); 
                break;
            case INTERRUPT_EXTERNAL_INT2 : 
            #if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE 
                INTERRUPT_PriorityLevelsEnable();
                if(INTERRUPT_LOW_PRIORITY == int_obj->priority){ 
                    INTERRUPT_GlobalInterruptLowEnable();
                }
                else if(INTERRUPT_HIGH_PRIORITY == int_obj->priority){ 
                    INTERRUPT_GlobalInterruptHighEnable();
                }
                else{ /* Nothing */ }
            #else
                INTERRUPT_GlobalInterruptEnable();
                INTERRUPT_PeripheralInterruptEnable();
            #endif
                EXT_INT2_InterruptEnable(); 
                break;
            default : ret = E_NOT_OK;
        }
    }
    return ret;
}
static Std_ReturnType Interrupt_INTx_Disable(const interrupt_INTx_t *int_obj){
    Std_ReturnType ret = E_OK;
    if(NULL == int_obj){
        ret = E_NOT_OK;
    }
    else{
        switch(int_obj->source){
            case INTERRUPT_EXTERNAL_INT0 : 
                EXT_INT0_InterruptDisable(); /* Disable the INT0 external interrupt */
                break;
            case INTERRUPT_EXTERNAL_INT1 : 
                EXT_INT1_InterruptDisable(); /* Disable the INT1 external interrupt */
                break;
            case INTERRUPT_EXTERNAL_INT2 : 
                EXT_INT2_InterruptDisable(); /* Disable the INT2 external interrupt */
                break;
            default : ret = E_NOT_OK;
        }
    }
    return ret;
}

#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE 
static Std_ReturnType Interrupt_INTx_Priority_Init(const interrupt_INTx_t *int_obj){
    Std_ReturnType ret = E_OK;
    if(NULL == int_obj){
        ret = E_NOT_OK;
    }
    else{
        switch(int_obj->source){
            case INTERRUPT_EXTERNAL_INT1 : 
                if(INTERRUPT_LOW_PRIORITY == int_obj->priority){ EXT_INT1_LowPrioritySet(); }
                else if(INTERRUPT_HIGH_PRIORITY == int_obj->priority){ EXT_INT1_HighPrioritySet(); }
                else{ /* Nothing */ }
                break;
            case INTERRUPT_EXTERNAL_INT2 : 
                if(INTERRUPT_LOW_PRIORITY == int_obj->priority){ EXT_INT2_LowPrioritySet(); }
                else if(INTERRUPT_HIGH_PRIORITY == int_obj->priority){ EXT_INT2_HighPrioritySet(); }
                else{ /* Nothing */ }
                break;
            default : ret = E_NOT_OK;
        }
    }
    return ret;
}
#endif
static Std_ReturnType Interrupt_INTx_Edge_Init(const interrupt_INTx_t *int_obj){
    Std_ReturnType ret = E_OK;
    if(NULL == int_obj){
        ret = E_NOT_OK;
    }
    else{
        switch(int_obj->source){
            case INTERRUPT_EXTERNAL_INT0 : 
                if(INTERRUPT_FALLING_EDGE == int_obj->edge){ EXT_INT0_FallingEdgeSet(); }
                else if(INTERRUPT_RISING_EDGE == int_obj->edge){ EXT_INT0_RisingEdgeSet(); }
                else{ /* Nothing */ }
                break;
            case INTERRUPT_EXTERNAL_INT1 : 
                if(INTERRUPT_FALLING_EDGE == int_obj->edge){ EXT_INT1_FallingEdgeSet(); }
                else if(INTERRUPT_RISING_EDGE == int_obj->edge){ EXT_INT1_RisingEdgeSet(); }
                else{ /* Nothing */ }
                break;
            case INTERRUPT_EXTERNAL_INT2 : 
                if(INTERRUPT_FALLING_EDGE == int_obj->edge){ EXT_INT2_FallingEdgeSet(); }
                else if(INTERRUPT_RISING_EDGE == int_obj->edge){ EXT_INT2_RisingEdgeSet(); }
                else{ /* Nothing */ }
                break;
            default : ret = E_NOT_OK;
        }
    }
    return ret;
}
static Std_ReturnType Interrupt_INTx_Pin_Init(const interrupt_INTx_t *int_obj){
    Std_ReturnType ret = E_OK;
    if(NULL == int_obj){
        ret = E_NOT_OK;
    }
    else{
        /* Initialize the MCU Pin for INTx with the needed configurations */
        ret = gpio_pin_direction_init(&(int_obj->mcu_pin));
    }
    return ret;
}
static Std_ReturnType Interrupt_INTx_Clear_Flag(const interrupt_INTx_t *int_obj){
    Std_ReturnType ret = E_OK;
    if(NULL == int_obj){
        ret = E_NOT_OK;
    }
    else{
        switch(int_obj->source){
            case INTERRUPT_EXTERNAL_INT0 : 
                EXT_INT0_InterruptFlagClear(); /* Clears the interrupt flag for the external interrupt, INT0 */
                break;
            case INTERRUPT_EXTERNAL_INT1 : 
                EXT_INT1_InterruptFlagClear(); /* Clears the interrupt flag for the external interrupt, INT1 */
                break;
            case INTERRUPT_EXTERNAL_INT2 : 
                EXT_INT2_InterruptFlagClear(); /* Clears the interrupt flag for the external interrupt, INT2 */
                break;
            default : ret = E_NOT_OK;
        }
    }
    return ret;
}

static Std_ReturnType INT0_SetInterruptHandler(void (*InterruptHandler)(void)){
    Std_ReturnType ret = E_OK;
    if(NULL == InterruptHandler){
        ret = E_NOT_OK;
    }
    else{
        /* Set Default Interrupt Handler for INT0 External Interrupt : Application ISR */
        INT0_InterruptHandler = InterruptHandler;
    }
    return ret;
}
static Std_ReturnType INT1_SetInterruptHandler(void (*InterruptHandler)(void)){
    Std_ReturnType ret = E_OK;
    if(NULL == InterruptHandler){
        ret = E_NOT_OK;
    }
    else{
        /* Set Default Interrupt Handler for INT1 External Interrupt : Application ISR */
        INT1_InterruptHandler = InterruptHandler;
    }
    return ret;
}
static Std_ReturnType INT2_SetInterruptHandler(void (*InterruptHandler)(void)){
    Std_ReturnType ret = E_OK;
    if(NULL == InterruptHandler){
        ret = E_NOT_OK;
    }
    else{
        /* Set Default Interrupt Handler for INT2 External Interrupt : Application ISR */
        INT2_InterruptHandler = InterruptHandler;
    }
    return ret;
}
static Std_ReturnType Interrupt_INTx_SetInterruptHandler(const interrupt_INTx_t *int_obj){
    Std_ReturnType ret = E_OK;
    if(NULL == int_obj){
        ret = E_NOT_OK;
    }
    else{
        switch(int_obj->source){
            case INTERRUPT_EXTERNAL_INT0 : 
                /* Set Default Interrupt Handler for INT0 External Interrupt : Application ISR */
                ret = INT0_SetInterruptHandler(int_obj->EXT_InterruptHandler);
                break;
            case INTERRUPT_EXTERNAL_INT1 : 
                /* Set Default Interrupt Handler for INT1 External Interrupt : Application ISR */
                ret = INT1_SetInterruptHandler(int_obj->EXT_InterruptHandler);
                break;
            case INTERRUPT_EXTERNAL_INT2 : 
                /* Set Default Interrupt Handler for INT2 External Interrupt : Application ISR */
                ret = INT2_SetInterruptHandler(int_obj->EXT_InterruptHandler);
                break;
            default : ret = E_NOT_OK;
        }
    }
    return ret;
}




/***********************************************************************************/
// External Interrupt 0,1,2 MCAL Helper function 
void INT0_ISR(void){
    EXT_INT0_InterruptFlagClear();          /* The INT0 external interrupt occurred (must be cleared in software) */
    /* Code : To be executed from MCAL Interrupt Context */
    if(INT0_InterruptHandler){ INT0_InterruptHandler(); }       /* Application Callback function gets called every time this ISR executes */
    else{ /* Nothing */ }
}
void INT1_ISR(void){
    EXT_INT1_InterruptFlagClear();          /* The INT1 external interrupt occurred (must be cleared in software) */
    /* Code : To be executed from MCAL Interrupt Context */
    if(INT1_InterruptHandler){ INT1_InterruptHandler(); }       /* Application Callback function gets called every time this ISR executes */
    else{ /* Nothing */ }
}
void INT2_ISR(void){
    EXT_INT2_InterruptFlagClear();          /* The INT2 external interrupt occurred (must be cleared in software) */
    /* Code : To be executed from MCAL Interrupt Context */
    if(INT2_InterruptHandler){ INT2_InterruptHandler(); }       /* Application Callback function gets called every time this ISR executes */
    else{ /* Nothing */ }
}

void RB4_ISR(uint8 RB4_Source){
    EXT_RBx_InterruptFlagClear();         /* The RB4 external OnChange interrupt occurred (must be cleared in software) */
    /* Code : To be executed from MCAL Interrupt Context */ 
    /* Application Callback function gets called every time this ISR executes */
    if(0 == RB4_Source){
        if(RB4_InterruptHandler_HIGH){ RB4_InterruptHandler_HIGH(); }
        else{ /* Nothing */ }
    }
    else if (1 == RB4_Source){
        if(RB4_InterruptHandler_LOW){ RB4_InterruptHandler_LOW(); }
        else{ /* Nothing */ }
    }
    else { /* Nothing */ }   
}
void RB5_ISR(uint8 RB5_Source){
    EXT_RBx_InterruptFlagClear();
    /* Code : To be executed from MCAL Interrupt Context */
    /* Application Callback function gets called every time this ISR executes */
    if(0 == RB5_Source){
        if(RB5_InterruptHandler_HIGH){ RB5_InterruptHandler_HIGH(); }
        else{ /* Nothing */ }
    }
    else if (1 == RB5_Source){
        if(RB5_InterruptHandler_LOW){ RB5_InterruptHandler_LOW(); }
        else{ /* Nothing */ }
    }
    else { /* Nothing */ }
}
void RB6_ISR(uint8 RB6_Source){
    EXT_RBx_InterruptFlagClear();
    /* Code : To be executed from MCAL Interrupt Context */
    /* Application Callback function gets called every time this ISR executes */
    if(0 == RB6_Source){
        if(RB6_InterruptHandler_HIGH){ RB6_InterruptHandler_HIGH(); }
        else{ /* Nothing */ }
    }
    else if (1 == RB6_Source){
        if(RB6_InterruptHandler_LOW){ RB6_InterruptHandler_LOW(); }
        else{ /* Nothing */ }
    }
    else { /* Nothing */ }   
}
void RB7_ISR(uint8 RB7_Source){
    EXT_RBx_InterruptFlagClear();
    /* Code : To be executed from MCAL Interrupt Context */
    /* Application Callback function gets called every time this ISR executes */
    if(0 == RB7_Source){
        if(RB7_InterruptHandler_HIGH){ RB7_InterruptHandler_HIGH(); }
        else{ /* Nothing */ }
    }
    else if (1 == RB7_Source){
        if(RB7_InterruptHandler_LOW){ RB7_InterruptHandler_LOW(); }
        else{ /* Nothing */ }
    }
    else { /* Nothing */ }   
}

