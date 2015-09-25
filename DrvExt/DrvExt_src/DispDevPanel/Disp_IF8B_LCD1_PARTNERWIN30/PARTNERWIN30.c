/*
    Display object object panel configuration parameters for TXDT270CDR_2V7

    @file       TXDT270CDR_2V7.c
    @ingroup
    @note       Nothing

    Copyright   Novatek Microelectronics Corp. 2011.  All rights reserved.
*/
#include "debug.h"
#include "display.h"
#include "dispdev_IF8bits.h"
#include "dispdev_panlcomn.h"


/*
    Panel Parameters for TXDT270CDR_2V7
*/
//@{
const tPANEL_CMD tCmdStandby[] =
{
   {CMDDELAY_MS, 10}
};

const tPANEL_CMD tCmdModeRgbd320[] =
{
    {0x00,0x01},  
    {0x08,0x05},
    {0x04,0x2c},
    {0x0c,0x10},
    {0x02,0x33},
    {0x0a,0x04},

    {0x0c,0x05}, 
    {0x0e,0xc8}, 
    {0x01,0x00}, 
    {0x09,0x49},
    {0x05,0xac}, 
    {0x0d,0x45},  
    {0x03,0x03},
    {0x0b,0x03},
    {0x07,0x02},   
    {0x0f,0xcc}, 
    {0x06,0x05}, 
    {0x00,0x01}, 
    {0x08,0x05}, 
    {0x04,0x2c}, 
    {0x0c,0x10},
    {0x05,0x04},  
    {0x06,0x05}, 
    {0x0e,0xc8}, 
    {0x06,0x0d}, 
    {0x01,0x00}, 
    {0x09,0x49}, 
    {0x05,0xac}, 
    {0x0d,0x45}, 
    {0x06,0x0d}, 
    {0x03,0x03}, 
    {0x0b,0x03}, 
    {0x07,0x02}, 
    {0x0f,0xcc},
    {0x06,0x0d},  
    {0x00,0x01},
    {0x08,0x05},
    {0x04,0x2c},
    {0x0c,0x10},    
    {0x06,0x0d},
    {0x02,0xf5}, //0x33BPFP

    {0x0a,0x44},//0x04//0x44yl
    {0x06,0x0b}, 
    {0x0e,0xc8}
};

const tLCD_PARAM tMode[] =
{
    {
        // tPANEL_PARAM
        {
            /* Old prototype */
            PINMUX_LCDMODE_RGB_SERIAL,         //!< LCDMode
            27.0f,                         //!< fDCLK
            1280,                           //!< uiHSyncTotalPeriod
            960,                           //!< uiHSyncActivePeriod
            106,                            //!< uiHSyncBackPorch
            263,                            //!< uiVSyncTotalPeriod
            240,                           //!< uiVSyncActivePeriod
            21,                             //!< uiVSyncBackPorchOdd
            21,                             //!< uiVSyncBackPorchEven
            960,                            //!< uiBufferWidth
            240,                            //!< uiBufferHeight
            960,                            //!< uiWindowWidth
            240,                            //!< uiWindowHeight
            FALSE,                          //!< bYCbCrFormat

            /* New added parameters */
            0x05,                           //!< uiHSyncSYNCwidth
            0x05                            //!< uiVSyncSYNCwidth
        },

        // tIDE_PARAM
        {
            /* Old prototype */
            PINMUX_LCD_SEL_SERIAL_RGB_8BITS,//!< pinmux_select_lcd;
            ICST_CCIR601,                   //!< icst;
            {FALSE,FALSE},                  //!< dithering[2];
            DISPLAY_DEVICE_AU,              //!< **DONT-CARE**
            IDE_PDIR_RGB,                   //!< pdir;
            IDE_LCD_R,                      //!< odd;
            IDE_LCD_B,                      //!< even;
            TRUE,                           //!< hsinv;
            TRUE,                           //!< vsinv;
            FALSE,                          //!< hvldinv;//
            FALSE,                          //!< vvldinv;//
            TRUE,      //FALSE,//                     //!< clkinv;//
            FALSE,                          //!< fieldinv;
            FALSE,                          //!< **DONT-CARE**
            FALSE,                          //!< interlace;
            FALSE,                          //!< **DONT-CARE**
            0x40,                           //!< ctrst;
            0x00,                           //!< brt;
            0x40,//0x58,                           //!< cmults;
            FALSE,                          //!< cex;
            FALSE,                          //!< **DONT-CARE**
            TRUE,                           //!< **DONT-CARE**
            TRUE,                           //!< tv_powerdown;
            {0x00,0x00},                    //!< **DONT-CARE**

            /* New added parameters */
            FALSE,                          //!< YCex
            FALSE,                          //!< HLPF
            {FALSE,FALSE,FALSE},            //!< subpixOdd[3]
            {FALSE,FALSE,FALSE},            //!< subpixEven[3]
            {IDE_DITHER_6BITS,IDE_DITHER_6BITS,IDE_DITHER_6BITS}//!< DitherBits[3]
        },

        (tPANEL_CMD*)tCmdModeRgbd320,                  //!< pCmdQueue
        sizeof(tCmdModeRgbd320)/sizeof(tPANEL_CMD),    //!< nCmd
    }

};
const tPANEL_CMD tCmdRotate_None[] =
{
    {CMDDELAY_MS, 10}
};
const tPANEL_CMD tCmdRotate_180[] =
{
    {CMDDELAY_MS, 10}
};
const tLCD_ROT tRotate[] =
{
    {DISPDEV_LCD_ROTATE_NONE,(tPANEL_CMD*)tCmdRotate_None,1},
    {DISPDEV_LCD_ROTATE_180,(tPANEL_CMD*)tCmdRotate_180,1}
};
//@}

tLCD_ROT* dispdev_getLcdRotateCmd(UINT32 *ModeNumber)
{
    if(tRotate != NULL)
    {
        *ModeNumber = sizeof(tRotate)/sizeof(tLCD_ROT);
    }
    else
    {
        *ModeNumber = 0;
    }
    return (tLCD_ROT*)tRotate;
}

tLCD_PARAM* dispdev_getConfigMode(UINT32 *ModeNumber)
{
    *ModeNumber = sizeof(tMode)/sizeof(tLCD_PARAM);
    return (tLCD_PARAM*)tMode;
}

tPANEL_CMD* dispdev_getStandbyCmd(UINT32 *CmdNumber)
{
    *CmdNumber = sizeof(tCmdStandby)/sizeof(tPANEL_CMD);
    return (tPANEL_CMD*)tCmdStandby;
}

#if 1
void dispdev_writeToLcdSif(DISPDEV_IOCTRL pDispDevControl, UINT32 addr, UINT32 value)
{
    UINT32                  uiSIFData;
    DISPDEV_IOCTRL_PARAM    DevIOCtrl;

    uiSIFData = ((((UINT32)addr << 8)|((UINT32)value)) << 16);

    pDispDevControl(DISPDEV_IOCTRL_GET_REG_IF, &DevIOCtrl);
    sif_send(DevIOCtrl.SEL.GET_REG_IF.uiSifCh, uiSIFData, 0, 0);
}


void dispdev_writeToLcdGpio(DISPDEV_IOCTRL pDispDevControl, UINT32 addr, UINT32 value)
{
    UINT32                  uiSIFData,j;
    UINT32                  SifClk,SifSen,SifData;
    DISPDEV_IOCTRL_PARAM    DevIOCtrl;

    pDispDevControl(DISPDEV_IOCTRL_GET_REG_IF, &DevIOCtrl);
    SifClk  = DevIOCtrl.SEL.GET_REG_IF.uiGpioClk;
    SifSen  = DevIOCtrl.SEL.GET_REG_IF.uiGpioSen;
    SifData = DevIOCtrl.SEL.GET_REG_IF.uiGpioData;

    gpio_setDir(SifSen, GPIO_DIR_OUTPUT);
    gpio_setDir(SifClk, GPIO_DIR_OUTPUT);
    gpio_setDir(SifData, GPIO_DIR_OUTPUT);

    gpio_setPin(SifSen);
    gpio_setPin(SifData);
    gpio_setPin(SifClk);

    uiSIFData = (UINT32)addr << 8 | (UINT32)value;
    //debug_err(("Has not implement dispdev_readFromLcdGpio%x %x  %x\r\n",uiSIFData,addr,value));
    Delay_DelayUs(500);

    gpio_clearPin(SifSen);

    for(j = 16; j > 0; j--)
    {
        if(((uiSIFData >> (j - 1)) & 0x01))
            gpio_setPin(SifData);
        else
            gpio_clearPin(SifData);

        Delay_DelayUs(100);
        gpio_clearPin(SifClk);
        Delay_DelayUs(200);
        gpio_setPin(SifClk);
        Delay_DelayUs(100);
    }

    Delay_DelayUs(500);
    gpio_setPin(SifSen);

}



void dispdev_readFromLcdGpio(DISPDEV_IOCTRL pDispDevControl, UINT32 addr, UINT32* p_value)
{
    debug_err(("Has not implement dispdev_readFromLcdGpio \r\n"));
}
#endif
