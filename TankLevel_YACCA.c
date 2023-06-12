/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: controller.c
 *
 * Code generated for Simulink model 'controller'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Mon Apr 11 09:29:47 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: RISC-V->RV32I
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */



#include "controller.h"
#include "stdio.h"

#define SOFTWARE 0
#define DEBUG_ENABLE  10
#define DEBUG_DISABLE 0
#define DEBUG_PRINTS DEBUG_ENABLE
#define HARDENING_IMPLEMENTATION SOFTWARE

volatile uint64_T ERR_CODE = 0x0;
volatile uint64_T ID=(uint64_T)1<<38;
volatile uint64_T last_predecessor_mask;
volatile uint64_T Count=0;


#if (HARDENINGIMPLEMENTATION == SOFTWARE)

void YACCA_TEST(uint64_T predecessors_mask)
{
    last_predecessor_mask = predecessors_mask;
    ERR_CODE = ERR_CODE + ((ID & (~ predecessors_mask )) >0 ? 1:0);
    
    if (ERR_CODE!=0)
    {
        ERR_CODE=0;
#if (DEBUG_PRINTS == DEBUG_ENABLE)
        printf ("ERR_CODE=");
        printf("%llu\n",predecessors_mask);
#endif
    }
}

void YACCA_SET(uint8_T BB_ID) //BB_ID is the BB that signs
{
    if(BB_ID < 63)
    {
        ID=(ID& (~ last_predecessor_mask)) ^ (( uint64_T)1<<BB_ID);//YACCA SET for BB0
#if (DEBUG_PRINTS == DEBUG_ENABLE)
        printf ("%u\n",BB_ID);
#endif
    }
    else
    {
        ERR_CODE = 255;
#if (DEBUG_PRINTS == DEBUG_ENABLE)
        printf("BB with an ID > 63!!!\n");
#endif
    }
}

#endif

/* Named constants for Chart: '<Root>/Chart' */
#define controller_IN_HFP_FAILURE      ((uint8_T)1U)
#define controller_IN_HFP_ON           ((uint8_T)1U)
#define controller_IN_LFP_FAILURE      ((uint8_T)2U)
#define controller_IN_LFP_ON           ((uint8_T)2U)
#define controller_IN_NO_ERR           ((uint8_T)3U)
#define controller_IN_OFF              ((uint8_T)3U)

/* Block states (default storage) */
DW_controller_T controller_DW;

/* External inputs (root inport signals with default storage) */
ExtU_controller_T controller_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_controller_T controller_Y;

/* Real-time model */
static RT_MODEL_controller_T controller_M_;
RT_MODEL_controller_T *const controller_M = &controller_M_;

/* Model step function */
//BB0 YACCA test (legal predecessor 38 and 0)
void controller_step(void)
{
YACCA_TEST((uint64_T) 1<<38|(uint64_T)1u);

  real_T rtb_Diff;
  real_T rtb_TSamp;

  /* SampleTimeMath: '<S2>/TSamp' incorporates:
   *  Inport: '<Root>/Level_cm'
   *
   * About '<S2>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp = controller_U.Level_cm * 10.0;

  /* Sum: '<S2>/Diff' incorporates:
   *  UnitDelay: '<S2>/UD'
   *
   * Block description for '<S2>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S2>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Diff = rtb_TSamp - controller_DW.UD_DSTATE;

  /* Chart: '<Root>/Chart' incorporates:
   *  Inport: '<Root>/Level_cm'
   *  Inport: '<Root>/Out_Flow_cm3_s'
   *  Outport: '<Root>/Error'
   *  Outport: '<Root>/HFP_DO'
   *  Outport: '<Root>/LFP_DO'
   */
YACCA_SET(0u);

//BB1 YACCA test legal predecessor is 0

YACCA_TEST((uint64_T) 1<<0);

  if (controller_DW.temporalCounter_i1 < 63U) {

YACCA_SET(1u);

//BB2 YACCA test legal predecessor is 1

YACCA_TEST((uint64_T) 1<<1);
    controller_DW.temporalCounter_i1++;
YACCA_SET(2u);
  }

  else //YACCA
  {
    YACCA_SET(1u);
  }

//BB3 YACCA test legal predecessor are 2 &1

YACCA_TEST((uint64_T) 1<<2|(uint64_T) 1<<1);
  
  if (controller_DW.is_active_c3_controller == 0U) {

YACCA_SET(3u);

//BB4 YACCA test legal predecessor is 3

YACCA_TEST((uint64_T) 1<< 3);

    controller_DW.is_active_c3_controller = 1U;
    controller_DW.is_Controller = controller_IN_OFF;

    /* Outport: '<Root>/HFP_DO' */
    controller_Y.HFP_DO = false;

    /* Outport: '<Root>/LFP_DO' */
    controller_Y.LFP_DO = false;
    controller_DW.is_Monitor = controller_IN_NO_ERR;

    /* Outport: '<Root>/Error' */
    controller_Y.Error = 0U;

YACCA_SET(4u);

//BB5 YACCA test legal predecessor is 3

  } else {
YACCA_SET(3u);

YACCA_TEST((uint64_T) 1<<3);


YACCA_SET(5u);//add by Maz, not added during our meeting

//BB6 YACCA test legal predecessor is 5

YACCA_TEST((uint64_T) 1<< 5);
    switch (controller_DW.is_Controller) {

//BB7 YACCA test legal predecessor is 6

     case controller_IN_HFP_ON:
YACCA_SET(6u);

YACCA_TEST((uint64_T) 1<< 6);

YACCA_SET(7u);

//BB8   YACCA test legal predecessor is 7

YACCA_TEST((uint64_T) 1<< 7);
      if (((rtb_Diff > 0.0) && (controller_U.Level_cm > 155.0)) ||
          (controller_Y.Error == 2)) {
YACCA_SET(8u);

//BB9   YACCA test legal predecessor is 7

YACCA_TEST((uint64_T) 1<< 8);
        controller_DW.is_Controller = controller_IN_LFP_ON;
YACCA_SET(9u);

//BB10 YACCA test legal predecessor is 9

      } else if (controller_U.Level_cm > 180.0) {
YACCA_SET(8u);
YACCA_TEST((uint64_T) 1<< 8);
        controller_DW.is_Controller = controller_IN_OFF;

        /* Outport: '<Root>/HFP_DO' */
        controller_Y.HFP_DO = false;

        /* Outport: '<Root>/LFP_DO' */
        controller_Y.LFP_DO = false;
YACCA_SET(10u);

//BB11 YACCA test legal predecessor is 7

      } else {
YACCA_SET(8u);
YACCA_TEST((uint64_T) 1<< 8);
        /* Outport: '<Root>/HFP_DO' */
        controller_Y.HFP_DO = true;

        /* Outport: '<Root>/LFP_DO' */
        controller_Y.LFP_DO = false;
YACCA_SET(11u);
      }
//BB12 YACCA test legal predecessor are 11,10,8,9

YACCA_TEST((uint64_T)1<<8|(uint64_T)1<<9|(uint64_T)1<<10 |(uint64_T)1<<11);
YACCA_SET(12u);
YACCA_TEST((uint64_T) 1<< 12);//for the BB24
      break;
            
//BB13 YACCA test legal predecessor 6
     case controller_IN_LFP_ON:
YACCA_SET(6u);

YACCA_TEST((uint64_T) 1<< 6);
            
     
    if ((rtb_Diff > 0.0) && (controller_U.Level_cm > 180.0)) {
        
YACCA_SET(13u);
          

//BB14 YACCA test legal predecessor 13

YACCA_TEST((uint64_T) 1<< 13);
        controller_DW.is_Controller = controller_IN_OFF;

        /* Outport: '<Root>/HFP_DO' */
        controller_Y.HFP_DO = false;

        /* Outport: '<Root>/LFP_DO' */
        controller_Y.LFP_DO = false;
YACCA_SET(14u);

//BB15 YACCA test legal predecessor is 13
YACCA_TEST((uint64_T) 1<< 14);

      } else if (((rtb_Diff < 0.0) && (controller_U.Level_cm < 150.0) &&
                  (controller_Y.Error != 2)) || (controller_Y.Error == 1)) {
YACCA_SET(13u);

YACCA_TEST((uint64_T) 1<< 13);

YACCA_SET(15u);

//BB16 YACCA test legal predecessor is 15
YACCA_TEST((uint64_T) 1<< 15);
          
        controller_DW.is_Controller = controller_IN_HFP_ON;
          
YACCA_SET(16u);
          

//BB17 YACCA test legal predecessor is 13

      } else {
YACCA_SET(13u);
YACCA_TEST((uint64_T) 1<< 13);
          
        /* Outport: '<Root>/HFP_DO' */
        controller_Y.HFP_DO = false;

        /* Outport: '<Root>/LFP_DO' */
        controller_Y.LFP_DO = true;
YACCA_SET(17u);
      }

//BB18 YACCA test legal predecessor are 17 & 16 & 14 & 13 

YACCA_TEST((uint64_T)1<<14|(uint64_T)1<<15 |(uint64_T)1<<16|(uint64_T)1<<17);
YACCA_SET(18u);
YACCA_TEST((uint64_T) 1<< 18);//for BB24
      break;


//BB19 YACCA test legal predecessor is 6

     default:
YACCA_SET(6u);
YACCA_TEST((uint64_T) 1<< 6);
      /* case IN_OFF: */
      if ((rtb_Diff < 0.0) && (controller_U.Level_cm < 150.0)) {
YACCA_SET(19u);

//BB20 YACCA test legal predecessor is 19

YACCA_TEST((uint64_T) 1<< 19);
        controller_DW.is_Controller = controller_IN_HFP_ON;
YACCA_SET(20u);

//BB21 YACCA test legal predecessor is 19

      } else if ((rtb_Diff < 0.0) && (controller_U.Level_cm < 175.0)) {
YACCA_SET(19u);


YACCA_TEST((uint64_T) 1<< 19);
YACCA_SET(21u);
//BB22 YACCA test legal predecessor is 21

YACCA_TEST((uint64_T) 1<< 21);
        controller_DW.is_Controller = controller_IN_LFP_ON;
YACCA_SET(22u);
      }

      else //YACCA
      {
YACCA_SET(19u);
      }

//BB23 YACCA test legal predecessor are 22 & 21 & 20 & 19

YACCA_TEST ((uint64_T)1<<19|(uint64_T)1<<20|(uint64_T)1<<21|(uint64_T)1<<22);
YACCA_SET_OTHERDOMAIN(23u);

YACCA_TEST((uint64_T)1<<23);//for BB24
      break;

//BB24  
//TEST(1<<11 | 1<<16 | 1<<20) 
    }

//SET(24u);

      
    switch (controller_DW.is_Monitor) {
            
//BB25 YACCA test legal predecessor is 24

     case controller_IN_HFP_FAILURE:
YACCA_SET(24u);

YACCA_TEST((uint64_T)1<<24);
      /* Outport: '<Root>/Error' */
      controller_Y.Error = 2U;
YACCA_SET(25u);
            
//BB26 YACCA test legal predecessor is 25
YACCA_TEST((uint64_T)1<<25);
            
      if (((controller_DW.temporalCounter_i1 >= 50U) && (!controller_Y.HFP_DO)) ||
          (fabs((3.0 - 0.5 * controller_U.Out_Flow_cm3_s) - rtb_Diff) < 0.1)) {
YACCA_SET(26u);
//BB27 YACCA test legal predecessor is 26 

YACCA_TEST((uint64_T)1<<26);
        controller_DW.is_Monitor = controller_IN_NO_ERR;

        /* Outport: '<Root>/Error' */
        controller_Y.Error = 0U;
YACCA_SET(27u);
      }

      else //for YACCA
      {
YACCA_SET(26u);
      }
//BB28 YACCA test legal predecessor are 26, 27

YACCA_TEST((uint64_T)1<<26|(uint64_T)1<<27);
YACCA_SET(28u);
YACCA_TEST((uint64_T)1<<28);//for BB Y
      break;

//BB29 YACCA test legal predecessor 24

     case controller_IN_LFP_FAILURE:
YACCA_SET(24u);
YACCA_TEST((uint64_T)1<<24);
      /* Outport: '<Root>/Error' */
      controller_Y.Error = 1U;
    if (((controller_DW.temporalCounter_i1 >= 50U) && (!controller_Y.LFP_DO)) ||
          (fabs((1.0 - 0.5 * controller_U.Out_Flow_cm3_s) - rtb_Diff) < 0.1)) {
YACCA_SET(29u);                

//BB30 YACCA test legal predecessor is 29

YACCA_TEST((uint64_T)1<<29);
        controller_DW.is_Monitor = controller_IN_NO_ERR;

        /* Outport: '<Root>/Error' */
        controller_Y.Error = 0U;
YACCA_SET(30u);
      }
   else //for YACCA
      {
YACCA_SET(29u);
      }

//BB31   YACCA test legal predecessor are 29 & 30

YACCA_TEST((uint64_T)1<<29|(uint64_T)1<<30);
YACCA_SET(31u);
YACCA_TEST((uint64_T)1<<31);   //for BB36
      break;

//BB32 YACCA test legal predecessor is 24

     default:
YACCA_SET(24u);
YACCA_TEST((uint64_T)1<<24);
      /* Outport: '<Root>/Error' */
      /* case IN_NO_ERR: */
      controller_Y.Error = 0U;
      if (controller_Y.LFP_DO && (fabs((1.0 - 0.5 * controller_U.Out_Flow_cm3_s)
            - rtb_Diff) > 0.1)) {
YACCA_SET(32u);                      

//BB33  YACCA test legal predecessor is  32

YACCA_TEST((uint64_T)1<<32);             
        controller_DW.is_Monitor = controller_IN_LFP_FAILURE;
        controller_DW.temporalCounter_i1 = 0U;

        /* Outport: '<Root>/Error' */
        controller_Y.Error = 1U;
YACCA_SET(33u);           
//BB34 YACCA test legal predecessor is 32

      } else if (controller_Y.HFP_DO && (fabs((3.0 - 0.5 *
                    controller_U.Out_Flow_cm3_s) - rtb_Diff) > 0.1)) {

YACCA_SET(32u);   
YACCA_TEST((uint64_T)1<<32);
          
YACCA_SET(34u);       
//BB35 YACCA test legal predecessor is 34  

YACCA_TEST((uint64_T)1<<34);  
        controller_DW.is_Monitor = controller_IN_HFP_FAILURE;
        controller_DW.temporalCounter_i1 = 0U;

        /* Outport: '<Root>/Error' */
        controller_Y.Error = 2U;
YACCA_SET(35u);          
      }
            
      else{ //for YACCA
          YACCA_SET(32u);
      }
//BB 36

YACCA_TEST((uint64_T)1<<35|(uint64_T)1<<34|(uint64_T)1<<33|(uint64_T)1<<32);
            
YACCA_SET(36u);
YACCA_TEST((uint64_T)1<<36); //for BB36

      break;

    }//end of the switch (controller_DW.is_Monitor)

//BB37   //YACCA test legal predecessor are 36 & 31 & 28 & 24



YACCA_TEST((uint64_T) 1<<36|(uint64_T) 1<<31|(uint64_T) 1<<28|(uint64_T) 1<<24);

YACCA_SET(37u);


  }//end of the else from line 193

  /* End of Chart: '<Root>/Chart' */

  /* Update for UnitDelay: '<S2>/UD'
   *
   * Block description for '<S2>/UD':
   *
   *  Store in Global RAM
   */

//BB38 YACCA test legal predecessor are 37 & 4

YACCA_TEST((uint64_T)1<<37|(uint64_T)1<<4);
   
  controller_DW.UD_DSTATE = rtb_TSamp;

YACCA_SET(38u);

Count ++;
printf("Round= %llu\n",Count);
}//end Function

/* Model initialize function */
void controller_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void controller_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
