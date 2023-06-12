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
#define DEBUG_PRINTS DEBUG_DISABLE
#define HARDENING_IMPLEMENTATION SOFTWARE

volatile int32_T ERR_CODE = 0;
volatile uint32_T Count=0;
volatile int32_T adjustValue=0;
volatile int32_T returnVal=0;
volatile int32_T sum=0;

//int32_T rts[38]={-51,44,-30,-26,75,56,53,16,544,2,952,27,438,253,24,722,4,-61,264,501,-56,710,479,650,855,38,51,72,250,28,359,-838,-728,938,45,-52,-669,515}; rts=cts-subRanpreval
// int32_T signature[38]=145,86,88,94,89,134,193,164,590,42,1022,159,474,437,50,856,120,67,378,585,142,820,633,684,921,184,53,100,416,164,529,980,888,1060,143,148,687,595};cts[]+subRanPrevVal[]

int32_T subRanPrevVal[38]={98,21,59,60,7,39,70,74,23,20,35,66,18,92,13,67,58,64,57,42,99,55,77,17,33,73,1,14,83,68,85,909,808,61,49,100,678,40};
int32_T cts [38]={47,65,29,34,82,95,123,90,567,22,987,93,456,345,37,789,62,3,321,543,43,765,556,667,888,111,52,86,333,96,444,71,80,999,94,48,9,555};
int32_T sumBB[38]={50,0,0,0,50,0,0,0,0,0,36,43,0,0,156,0,0,179,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,261,0,135,0,0};
volatile int32_T signature=145; //cts[0]+subRanPrevVal[0]


#if (HARDENINGIMPLEMENTATION == SOFTWARE)

void UpdSigBegin (int32_T current_mask)
{       
        signature =signature - subRanPrevVal[current_mask];// update of the run-time signature and the only verification instruction per basic block- subRanPrevVal:compile-time signature
      

}
void CheckSig(int32_T current_mask)
{
          if  (signature!=cts[current_mask])//result in the signature having the value of the compile-time signature. CTS:compile_time_signature
        {
                ERR_CODE=current_mask;
                #if (DEBUG_PRINTS == DEBUG_ENABLE)
                printf ("ERR_CODE=");
                printf("%d\n",current_mask);
                #endif
        }
}

void AddRand(int32_T rand)

{
    signature=signature + rand;

}

void UpdSigEnd(int32_T current_mask,int32_T successor_mask)
{

        adjustValue= - (cts[current_mask]+sumBB[current_mask] ) + (cts[successor_mask]+subRanPrevVal[successor_mask]);
    
    signature=signature+adjustValue;

          
        #if (DEBUG_PRINTS == DEBUG_ENABLE)
                printf ("CurrentBB=%d\n",current_mask);
                printf ("signature=%d\n",signature);
    printf("BB=%d Zero=%d\n",current_mask,signature- (cts[current_mask]+sumBB[current_mask] ));
               
        #endif
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
//BB0 RACFED setting adjustvalue successor 1 and 38
//BB0 more than 2 instructions

void controller_step(void)
{
      
UpdSigBegin (0);
CheckSig(0);

  real_T rtb_Diff; 

AddRand(5);  //Jacopo Idea

  real_T rtb_TSamp;

AddRand(10);
  /* SampleTimeMath: '<S2>/TSamp' incorporates:
   *  Inport: '<Root>/Level_cm'
   *
   * About '<S2>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp = controller_U.Level_cm * 10.0;

AddRand(15);

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

AddRand(20);
  /* Chart: '<Root>/Chart' incorporates:
   *  Inport: '<Root>/Level_cm'
   *  Inport: '<Root>/Out_Flow_cm3_s'
   *  Outport: '<Root>/Error'
   *  Outport: '<Root>/HFP_DO'
   *  Outport: '<Root>/LFP_DO'
   */


UpdSigEnd(0,1);

//BB1 YACCA test legal predecessor is 0
//BB1 RACFED setting adjustvalue successor 2,3


UpdSigBegin(1);


  if (controller_DW.temporalCounter_i1 < 63U) {
CheckSig(1);
UpdSigEnd(1,2);

//BB2 YACCA test legal predecessor is 1


UpdSigBegin(2);
CheckSig(2);

    controller_DW.temporalCounter_i1++;

UpdSigEnd(2,3);

  }

  else //RACFED
  {

CheckSig(1);
UpdSigEnd(1,3);

  }

//BB3 YACCA test legal predecessor are 2 &1
//BB3 RACFED setting adjustvalue successor 4,5


UpdSigBegin(3);


  if (controller_DW.is_active_c3_controller == 0U) {

CheckSig(3);
UpdSigEnd(3,4);

//BB4 YACCA test legal predecessor is 3
//BB4 RACFED setting adjustvalue successor 38
//BB4 more than 2 instructions

UpdSigBegin(4);
CheckSig(4);

    controller_DW.is_active_c3_controller = 1U;

AddRand(2);    
    controller_DW.is_Controller = controller_IN_OFF;

AddRand(3);   
    /* Outport: '<Root>/HFP_DO' */
    controller_Y.HFP_DO = false;

AddRand(4);   
    /* Outport: '<Root>/LFP_DO' */
    controller_Y.LFP_DO = false;

AddRand(5); 

    controller_DW.is_Monitor = controller_IN_NO_ERR;

AddRand(6);       

    /* Outport: '<Root>/Error' */
    controller_Y.Error = 0U;

AddRand(30);   

UpdSigEnd(4,38);

//BB5 YACCA test legal predecessor is 3
//BB5 RACFED setting adjustvalue successor 6

  } else {
        
CheckSig(3u);
UpdSigEnd(3,5);

UpdSigBegin(5);
CheckSig(5);
UpdSigEnd(5,6);

//BB6 YACCA test legal predecessor is 5
//BB6 RACFED setting adjustvalue successor 13,19

UpdSigBegin(6);

    switch (controller_DW.is_Controller) {

//BB7 YACCA test legal predecessor is 6
//BB7 RACFED setting adjustvalue successor 8,9,11
     case controller_IN_HFP_ON:
CheckSig(6);
UpdSigEnd(6,7);
UpdSigBegin(7);

      if (((rtb_Diff > 0.0) && (controller_U.Level_cm > 155.0)) ||
          (controller_Y.Error == 2)) {
CheckSig(7);
UpdSigEnd(7,8);   

//BB8   YACCA test legal predecessor is 7
//BB8 RACFED setting adjustvalue successor 12
UpdSigBegin(8);
CheckSig(8);

       controller_DW.is_Controller = controller_IN_LFP_ON;

UpdSigEnd(8,12);

//BB9   YACCA test legal predecessor is 7
//BB9  RACFED setting adjustvalue successor 10,11,12

            } else if (controller_U.Level_cm > 180.0) {

CheckSig(7);
UpdSigEnd(7,10);

//BB10 YACCA test legal predecessor is 9
//BB10 RACFED setting adjustvalue successor 12
//BB10 more than 2 instructions
UpdSigBegin(10);
CheckSig(10);

        controller_DW.is_Controller = controller_IN_OFF;
AddRand(11);
        /* Outport: '<Root>/HFP_DO' */
        controller_Y.HFP_DO = false;
AddRand(12);
        /* Outport: '<Root>/LFP_DO' */
        controller_Y.LFP_DO = false;
AddRand(13);

UpdSigEnd(10,12);

//BB11 YACCA test legal predecessor is 7
//BB11 RACFED setting adjustvalue successor 12
//BB11 more than 2 instructions

      } else {

CheckSig(7u);
UpdSigEnd(7,11);

UpdSigBegin(11);
CheckSig(11);

        /* Outport: '<Root>/HFP_DO' */
        controller_Y.HFP_DO = true;
AddRand(21);
        /* Outport: '<Root>/LFP_DO' */
        controller_Y.LFP_DO = false;
AddRand(22);
UpdSigEnd(11,12);

      }

//BB12 YACCA test legal predecessor are 11,10,8
//BB12 RACFED setting adjustvalue successor 24
UpdSigBegin(12);
CheckSig(12);
UpdSigEnd(12,24);

//for the BB24
UpdSigBegin(24);
CheckSig(24);
     break;
            
//BB13 YACCA test legal predecessor 6
//BB13 RACFED setting adjustvalue successor 14,15,17

     case controller_IN_LFP_ON:

CheckSig(6);
UpdSigEnd(6,13);
UpdSigBegin(13);       

   
    if ((rtb_Diff > 0.0) && (controller_U.Level_cm > 180.0)) {
CheckSig(13);
UpdSigEnd(13,14);

//BB14 YACCA test legal predecessor 13
//BB14 RACFED setting adjustvalue successor 18
//BB14 more than 2 instructions

UpdSigBegin(14);
CheckSig(14);

        controller_DW.is_Controller = controller_IN_OFF;
AddRand(51);
        /* Outport: '<Root>/HFP_DO' */
        controller_Y.HFP_DO = false;
AddRand(52);
        /* Outport: '<Root>/LFP_DO' */
        controller_Y.LFP_DO = false;
AddRand(53);
UpdSigEnd(14,18);

//BB15 YACCA test legal predecessor is 13
//BB15 RACFED setting adjustvalue successor 16

      } else if (((rtb_Diff < 0.0) && (controller_U.Level_cm < 150.0) &&
                  (controller_Y.Error != 2)) || (controller_Y.Error == 1)) {
CheckSig(13);                        
UpdSigEnd(13,15);

UpdSigBegin(15);
CheckSig(15);
UpdSigEnd(15,16);

//BB16 YACCA test legal predecessor is 15
//BB16 RACFED setting adjustvalue successor 18
UpdSigBegin(16);
CheckSig(16); 

        controller_DW.is_Controller = controller_IN_HFP_ON;
UpdSigEnd(16,18);//end of the if-else
          
//BB17 YACCA test legal predecessor is 13
//BB17 RACFED setting adjustvalue successor 18
//BB17 more than 2 instructions
      } else {

CheckSig(13);
UpdSigEnd(13,17);
UpdSigBegin(17);
CheckSig(17);     
        /* Outport: '<Root>/HFP_DO' */
        controller_Y.HFP_DO = false;
AddRand(90);
        /* Outport: '<Root>/LFP_DO' */
        controller_Y.LFP_DO = true;
AddRand(89);

UpdSigEnd(17,18);//end of the if-else

      }

//BB18 YACCA test legal predecessor are 17 & 16 & 14 & 13
//BB18 RACFED setting adjustvalue successor 24
UpdSigBegin(18);
CheckSig(18);
UpdSigEnd(18,24);

//for BB24
UpdSigBegin(24);
CheckSig(24);
      break;

//BB19 YACCA test legal predecessor is 6
//BB19 RACFED setting adjustvalue successor 20,23
     default:
CheckSig(6);
UpdSigEnd(6,19);
UpdSigBegin(19);
      /* case IN_OFF: */
      if ((rtb_Diff < 0.0) && (controller_U.Level_cm < 150.0)) {
CheckSig(19);
UpdSigEnd(19,20);
//BB20 YACCA test legal predecessor is 19
//BB20 RACFED setting adjustvalue successor 23
UpdSigBegin(20);
CheckSig(20);

        controller_DW.is_Controller = controller_IN_HFP_ON;
UpdSigEnd(20,23);


//BB21 YACCA test legal predecessor is 19
//BB21 RACFED setting adjustvalue successor 23

      } else if ((rtb_Diff < 0.0) && (controller_U.Level_cm < 175.0)) {

CheckSig(19);
UpdSigEnd(19,21);
          
UpdSigBegin(21);
CheckSig(21);
UpdSigEnd(21,22);
//BB22 YACCA test legal predecessor is 21
//BB22 RACFED setting adjustvalue successor 23
UpdSigBegin(22);
CheckSig(22);

        controller_DW.is_Controller = controller_IN_LFP_ON;
UpdSigEnd(22,23);

      }

      else //RACFED
      {
CheckSig(19);
UpdSigEnd(19,23);
      }

//BB23 YACCA test legal predecessor are 22 & 21 & 20 & 19
//BB23 RACFED setting adjustvalue successor 24

UpdSigBegin(23);
CheckSig(23);
UpdSigEnd(23,24);
//for BB24
UpdSigBegin(24);
CheckSig(24);
      break;

//BB24
//BB24 RACFED setting adjustvalue successor 29

    }

    switch (controller_DW.is_Monitor) {
            
//BB25 YACCA test legal predecessor is 24
//BB25 RACFED setting adjustvalue successor 26

     case controller_IN_HFP_FAILURE:

UpdSigEnd(24,25);
   
UpdSigBegin(25);
CheckSig(25);
      /* Outport: '<Root>/Error' */
      controller_Y.Error = 2U;
            
UpdSigEnd(25,26);
//BB26 YACCA test legal predecessor is 25
//BB26 RACFED setting adjustvalue successor 27,28
UpdSigBegin(26);     
      if (((controller_DW.temporalCounter_i1 >= 50U) && (!controller_Y.HFP_DO)) ||
          (fabs((3.0 - 0.5 * controller_U.Out_Flow_cm3_s) - rtb_Diff) < 0.1)) {
CheckSig(26); 
UpdSigEnd(26,27);

//BB27 YACCA test legal predecessor is 26
//BB27 RACFED setting adjustvalue successor 28
UpdSigBegin(27);
CheckSig(27); 

        controller_DW.is_Monitor = controller_IN_NO_ERR;
AddRand(5);
        /* Outport: '<Root>/Error' */
        controller_Y.Error = 0U;
AddRand(10);

UpdSigEnd(27,28);
      }

      else //for RACFED
      {
CheckSig(26); 
UpdSigEnd(26,28);
      }

//BB28 YACCA test legal predecessor are 26, 27
//BB28 RACFED setting adjustvalue successor 37
UpdSigBegin(28);
CheckSig(28);
UpdSigEnd(28,37);

//for BB37
UpdSigBegin(37);
CheckSig(37);
      break;

//BB29 YACCA test legal predecessor 24
//BB29 RACFED setting adjustvalue successor 30,31

     case controller_IN_LFP_FAILURE:

   
UpdSigEnd(24,29);
UpdSigBegin(29);  
      /* Outport: '<Root>/Error' */
      controller_Y.Error = 1U;
 
    if (((controller_DW.temporalCounter_i1 >= 50U) && (!controller_Y.LFP_DO)) ||
          (fabs((1.0 - 0.5 * controller_U.Out_Flow_cm3_s) - rtb_Diff) < 0.1)) {
CheckSig(29);     
UpdSigEnd(29,30);

//BB30 YACCA test legal predecessor is 29
//BB30 RACFED setting adjustvalue successor 31
UpdSigBegin(30);
CheckSig(30);

        controller_DW.is_Monitor = controller_IN_NO_ERR;

        /* Outport: '<Root>/Error' */
        controller_Y.Error = 0U;

UpdSigEnd(30,31);
      }

   else //for RACFED
      {
CheckSig(29);      
UpdSigEnd(29,31);
      }

//BB31   YACCA test legal predecessor are 29 & 30
//BB31 RACFED setting adjustvalue successor 37


UpdSigBegin(31);
CheckSig(31);
UpdSigEnd(31,37);


//for BB37
UpdSigBegin(37);
CheckSig(37);
      break;//for BB37

//BB32 YACCA test legal predecessor is 24
//BB32 RACFED setting adjustvalue successor 33,34,36
//BB32 more than 2 instructions

     default:
    
UpdSigEnd(24,32); 

UpdSigBegin(32); 
      /* Outport: '<Root>/Error' */
      /* case IN_NO_ERR: */
      controller_Y.Error = 0U;
     
      if (controller_Y.LFP_DO && (fabs((1.0 - 0.5 * controller_U.Out_Flow_cm3_s)
            - rtb_Diff) > 0.1)) {
CheckSig(32);
UpdSigEnd(32,33); 

//BB33  YACCA test legal predecessor is  32
//BB33 RACFED setting adjustvalue successor 36
//BB33 more than 2 instructions
UpdSigBegin(33u);
CheckSig(33u);

        controller_DW.is_Monitor = controller_IN_LFP_FAILURE;
AddRand(87);        
        controller_DW.temporalCounter_i1 = 0U;
AddRand(88);  
        /* Outport: '<Root>/Error' */
        controller_Y.Error = 1U;
AddRand(86);  

UpdSigEnd(33,36);

//BB34 YACCA test legal predecessor is 32
//BB34 RACFED setting adjustvalue successor 35,36

      } else if (controller_Y.HFP_DO && (fabs((3.0 - 0.5 *
                    controller_U.Out_Flow_cm3_s) - rtb_Diff) > 0.1)) {

CheckSig(32);
UpdSigEnd(32,35);

//BB35 YACCA test legal predecessor is 34
//BB35  RACFED setting adjustvalue successor 36
//BB35 more than 2 instructions
UpdSigBegin(35);
CheckSig(35);

        controller_DW.is_Monitor = controller_IN_HFP_FAILURE;
AddRand(44);        
        controller_DW.temporalCounter_i1 = 0U;
AddRand(45);     
        /* Outport: '<Root>/Error' */
        controller_Y.Error = 2U;
 AddRand(46);            

UpdSigEnd(35,36); 

      }
            
      else
      { //for RACFED
CheckSig(32);
UpdSigEnd(32,36);
      }

//BB 36
//BB36 RACFED setting adjustvalue successor 37
UpdSigBegin(36);
CheckSig(36);
UpdSigEnd(36,37);

//for BB37
UpdSigBegin(37);
CheckSig(37);
      break; 

    }//end of the switch (controller_DW.is_Monitor)

//BB37   //YACCA test legal predecessor are 36 & 31 & 28 & 24
//BB37  RACFED setting adjustvalue successor 38

UpdSigEnd(37,38);

  }//end of the else from line 193

  /* End of Chart: '<Root>/Chart' */

  /* Update for UnitDelay: '<S2>/UD'
   *
   * Block description for '<S2>/UD':
   *
   *  Store in Global RAM
   */

//BB38 YACCA test legal predecessor are 37 & 4
//BB38 RACFED setting adjustvalue successor 0
UpdSigBegin(38);
CheckSig(38);


  controller_DW.UD_DSTATE = rtb_TSamp;
    
UpdSigEnd(38,0);
Count ++;
//printf("Round= %d\n",Count);
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
