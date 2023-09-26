#ifndef __AT_CUSTOM_H__
#define __AT_CUSTOM_H__
#include <stdlib.h>
#include "cav_common.h"
// #include "ps_dev_if.h"
#include "cmsis_os2.h"
#include "at_util.h"
#include "atc_decoder.h"
#include "version.h"
#include "cmisms.h"
#include "ps_sms_if.h"
#include "atqc_dev.h"
#include "atqc_ps.h"
#include "atqc_sim.h"

#if 0
#define CAV_AT_ICCID_CMD                     "+ICCID"
#define CAV_AT_TRB_CMD                       "+TRB"
//#define CAV_AT_GSETSBD_CMD                   "%GSETSBD"

#define CAV_AT_POWER_SAVING_MODE_CMD         "+CPSMS"
#endif
#define CAV_AT_MANUF_REVISION_CMD            "+CGMR"
#define CAV_AT_MANUFACTURER_ID_CMD           "+CGMI"
#define CAV_AT_MANUFACTURER_MODEL_CMD        "+CGMM"
//#define CAV_AT_BAUD_RATE_SET_CMD             "+CBST"
//#define CAV_AT_FS_LIST_FILE_CMD              "+FSLSTFILE"
#define CAV_AT_ATI_CMD                       "I"
#if 0
#define CAV_AT_ATANDF_CMD                    "&F"
#define CAV_AT_LTE_INFO_CMD                  "!LTEINFO"
#define CAV_AT_CEREG_CMD                     "+CEREG"
#define CAV_AT_CGCONTRDP_CMD                 "+CGCONTRDP"
#define CAV_AT_CFUN_CMD                      "+CFUN"
#define CAV_AT_CGDCONT_CMD                   "+CGDCONT"
#define CAV_AT_CGEREP_CMD                    "+CGEREP"
#define CAV_AT_CEMODE_CMD                    "+CEMODE"
#define CAV_AT_CMGW_CMD                      "+CMGW"
#define CAV_AT_CNMI_CMD                      "+CNMI"
#define CAV_AT_CGSN_CMD                      "+CGSN"
#define CAV_AT_PMU_CFG_CMD                   "+PMUCFG"
#define CAV_AT_SIMSWAP_CMD                   "^SIMSWAP"
#define CAV_AT_CALMODE_CMD                   "+CALMODE"
#define CAV_AT_RFSWITCH_CMD                  "+RFSWITCH"
#define CAV_AT_CCLK_CMD		                 "+CCLK"
#define CAV_AT_HWVER_CMD                     "^HWVER"
#define CAV_AT_PARTNUM_CMD                   "^HWPN"
#define CAV_AT_SIMSEL_CMD                    "+GPSET"
#endif
#define CAV_AT_FSLSTFILE_PRINT_BUF_LEN     (256)

/* AT+CPSMS */
#define CAV_AT_CPSMS_0_MODE_VAL_MIN                0
#define CAV_AT_CPSMS_0_MODE_VAL_MAX                1
#define CAV_AT_CPSMS_0_MODE_VAL_DEFAULT            0
#define CAV_AT_CPSMS_1_PRAU_STR_DEFAULT            NULL
#define CAV_AT_CPSMS_1_PRAU_STR_MAX_LEN            8
#define CAV_AT_CPSMS_2_GPRS_STR_DEFAULT            NULL
#define CAV_AT_CPSMS_2_GPRS_STR_MAX_LEN            8
#define CAV_AT_CPSMS_3_PTAU_STR_DEFAULT            "00110100"  /* default 20 hours */
#define CAV_AT_CPSMS_3_PTAU_STR_MAX_LEN            8
#define CAV_AT_CPSMS_4_ACT_STR_DEFAULT             "00100101"  /* default 5 minutes */
#define CAV_AT_CPSMS_4_ACT_STR_MAX_LEN             8

/* AT+CBST */
#define CAV_AT_CBST_MAX_PARM_STR_LEN             32
#define CAV_AT_CBST_MAX_PARM_STR_DEFAULT         NULL

/* ATI */
#define CAV_EVB_MAJOR_VERSION   CAVLI_EVB_MAJOR_VERSION
#define CAV_EVB_MINOR_VERSION   CAVLI_EVB_MINOR_VERSION
#define CAV_MANUFACTURER_NAME   CAVLI_MANUFACTURER_NAME
#define CAV_BOARD_NAME          CAVLI_BOARD_NAME
#define CAV_DEVICE_DESCRIPTION  CAVLI_DEVICE_DESCRIPTION
#define CAV_FIRMWARE_VERSION    CAVLI_FIRMWARE_VERSION
#define CAV_HW_VERSION          CAVLI_HW_VERSION
#define CAV_SERIAL_NUMBER       CAVLI_SERIAL_NUMBER
#define CAV_PART_NUMBER         CAVLI_PART_NUMBER
#define CAV_IMEI_LEN            18
#define CAV_SN_LEN              32
#define CAV_HWVER_LEN           32
#define CAV_HWPN_LEN            32

/* AT&F */
#define CAV_CC_AND_F_0_VAL_MIN      0
#define CAV_CC_AND_F_0_VAL_MAX      0
#define CAV_CC_AND_F_0_VAL_DEFAULT  0

/*AT!LTEINFO*/
#define CAV_AT_LTEINFO_0_VAL_MIN                  0
#define CAV_AT_LTEINFO_0_VAL_MAX                  2
#define CAV_AT_LTEINFO_0_VAL_DEFAULT              0

#define CAV_AT_LTEINFO_1_VAL_MIN                  4
#define CAV_AT_LTEINFO_1_VAL_MAX                  300     /*timeout, MAX: 5 mins*/
#define CAV_AT_LTEINFO_1_VAL_DEFAULT              8       /*default: 8s*/

#define CAV_AT_LTEINFO_2_VAL_MIN                  0
#define CAV_AT_LTEINFO_2_VAL_MAX                  1       /*save_for_later*/
#define CAV_AT_LTEINFO_2_VAL_DEFAULT              0       /*not need to save*/

#define CAV_AT_LTEINFO_3_VAL_MIN                  1       /*max_cell_number*/
#define CAV_AT_LTEINFO_3_VAL_MAX                  7       /*max_cell_number, 1 serving cell + 6 neighber cell */
#define CAV_AT_LTEINFO_3_VAL_DEFAULT              7

#define CAV_AT_LTEINFO_4_VAL_MIN                  0       /*report mode, 0 - report in AT response */
#define CAV_AT_LTEINFO_4_VAL_MAX                  1       /*report mode, 1 - report in URC response */
#define CAV_AT_LTEINFO_4_VAL_DEFAULT              0

/* AT+CEREG */
#define CAV_AT_CEREG_0_VAL_MIN                     0
#define CAV_AT_CEREG_0_VAL_MAX                     3
#define CAV_AT_CEREG_0_VAL_DEFAULT                 0

/* AT+CGCONTRDP */
#define CAV_AT_CGCONTRDP_0_CID_VAL_MIN             1
#define CAV_AT_CGCONTRDP_0_CID_VAL_MAX             15
#define CAV_AT_CGCONTRDP_0_CID_VAL_DEFAULT         1
/* AT+CFUN */
#define CAV_ATC_CFUN_0_FUN_VAL_MIN                0
#define CAV_ATC_CFUN_0_FUN_VAL_MAX                1
#define CAV_ATC_CFUN_0_FUN_VAL_DEFAULT            1
#define CAV_ATC_CFUN_1_RST_VAL_MIN                0
#define CAV_ATC_CFUN_1_RST_VAL_MAX                1
#define CAV_ATC_CFUN_1_RST_VAL_DEFAULT            0

/* AT+CGDCONT */
#define CAV_ATC_CID_VAL_MIN                         1
#define CAV_ATC_CID_VAL_MAX                         15
#define CAV_ATC_CID_VAL_DEFAULT                     1

#define CAV_ATC_CGDCONT_0_CID_VAL_MIN                   CAV_ATC_CID_VAL_MIN
#define CAV_ATC_CGDCONT_0_CID_VAL_MAX                   CAV_ATC_CID_VAL_MAX
#define CAV_ATC_CGDCONT_0_CID_VAL_DEFAULT               CAV_ATC_CID_VAL_DEFAULT
#define CAV_ATC_CGDCONT_1_PDPTYPE_STR_DEFAULT           "IP"
#define CAV_ATC_CGDCONT_2_APN_STR_DEFAULT               NULL
#define CAV_ATC_CGDCONT_2_APN_STR_MAX_LEN               99+CMS_NULL_CHAR_LEN     /* readable APN should limited in 99 bytes, as encoded APN max: 100 bytes */
#define CAV_ATC_CGDCONT_6_IPV4ADDRALLOC_VAL_MIN         0
#define CAV_ATC_CGDCONT_6_IPV4ADDRALLOC_VAL_MAX         0
#define CAV_ATC_CGDCONT_6_IPV4ADDRALLOC_VAL_DEFAULT     0
#define CAV_ATC_CGDCONT_7_PARA_VAL_MIN                  0
#define CAV_ATC_CGDCONT_7_PARA_VAL_MAX                  2
#define CAV_ATC_CGDCONT_7_PARA_VAL_DEFAULT              0
#define CAV_ATC_CGDCONT_8_PARA_VAL_MIN                  0
#define CAV_ATC_CGDCONT_8_PARA_VAL_MAX                  0
#define CAV_ATC_CGDCONT_8_PARA_VAL_DEFAULT              0
#define CAV_ATC_CGDCONT_9_PARA_VAL_MIN                  0
#define CAV_ATC_CGDCONT_9_PARA_VAL_MAX                  0
#define CAV_ATC_CGDCONT_9_PARA_VAL_DEFAULT              0
#define CAV_ATC_CGDCONT_10_PARA_VAL_MIN                 0
#define CAV_ATC_CGDCONT_10_PARA_VAL_MAX                 1
#define CAV_ATC_CGDCONT_10_PARA_VAL_DEFAULT             0
// #define CAV_ATC_CGDCONT_11_PARA_VAL_MIN                 0
// #define CAV_ATC_CGDCONT_11_PARA_VAL_MAX                 1
#define CAV_ATC_CGDCONT_11_PARA_VAL_DEFAULT             0
// #define CAV_ATC_CGDCONT_12_PARA_VAL_MIN                 0
// #define CAV_ATC_CGDCONT_12_PARA_VAL_MAX                 1
#define CAV_ATC_CGDCONT_12_PARA_VAL_DEFAULT             0
// #define CAV_ATC_CGDCONT_13_PARA_VAL_MIN                 0
// #define CAV_ATC_CGDCONT_13_PARA_VAL_MAX                 1
// #define CAV_ATC_CGDCONT_13_PARA_VAL_DEFAULT             0
// #define CAV_ATC_CGDCONT_14_PARA_VAL_MIN                 0
// #define CAV_ATC_CGDCONT_14_PARA_VAL_MAX                 1
// #define CAV_ATC_CGDCONT_14_PARA_VAL_DEFAULT             0

/* AT+CGEREP */
#define CAV_ATC_CGEREP_0_VAL_MIN                            0
#define CAV_ATC_CGEREP_0_VAL_MAX                            1
#define CAV_ATC_CGEREP_0_VAL_DEFAULT                        0
#define CAV_ATC_CGEREP_1_VAL_MIN                            0
#define CAV_ATC_CGEREP_1_VAL_MAX                            0
#define CAV_ATC_CGEREP_1_VAL_DEFAULT                        0

/* AT+CEMODE */
#define CAV_ATC_CEMODE_VAL_MIN                      0
#define CAV_ATC_CEMODE_VAL_MAX                      1
#define CAV_ATC_CEMODE_VAL_DEFAULT                  0

#define CAV_ATC_ADDR_STR_MAX_LEN                    ((CMI_SMS_MAX_LENGTH_OF_ADDRESS_VALUE + 1) * 4)
#define CAV_ATC_ADDR_STR_DEFAULT                    PNULL
/* AT+CMGW for PDU mode */
#define CAV_ATC_CMGW_0_PDU_LENGTH_MIN               1
#define CAV_ATC_CMGW_0_PDU_LENGTH_MAX               180
#define CAV_ATC_CMGW_0_PDU_LENGTH_DEFAULT           1
#define CAV_ATC_CMGW_1_STAT_VAL_MIN                 0
#define CAV_ATC_CMGW_1_STAT_VAL_MAX                 3
#define CAV_ATC_CMGW_1_STAT_VAL_DEFAULT             2
/* AT+CMGW for Text mode */
#define CAV_ATC_CMGW_0_ADDR_LENGTH_MAX              ATC_ADDR_STR_MAX_LEN
#define CAV_ATC_CMGW_0_ADDR_LENGTH_DEFAULT          ATC_ADDR_STR_DEFAULT
#define CAV_ATC_CMGW_1_STAT_STR_MAX_LEN             20
#define CAV_ATC_CMGW_1_STAT_STR_DEFAULT             PSIL_SMS_STATUS_STRING_STO_UNSENT

/* AT+CNMI */
#define CAV_ATC_CNMI_0_MODE_VAL_MIN                 0
#define CAV_ATC_CNMI_0_MODE_VAL_MAX                 1
#define CAV_ATC_CNMI_0_MODE_VAL_DEFAULT             0
#define CAV_ATC_CNMI_1_MT_VAL_MIN                   0
#define CAV_ATC_CNMI_1_MT_VAL_MAX                   3
#define CAV_ATC_CNMI_1_MT_VAL_DEFAULT               0
#define CAV_ATC_CNMI_2_BM_VAL_MIN                   0
#define CAV_ATC_CNMI_2_BM_VAL_MAX                   3
#define CAV_ATC_CNMI_2_BM_VAL_DEFAULT               0
#define CAV_ATC_CNMI_3_DS_VAL_MIN                   0
#define CAV_ATC_CNMI_3_DS_VAL_MAX                   2
#define CAV_ATC_CNMI_3_DS_VAL_DEFAULT               0
#define CAV_ATC_CNMI_4_BFR_VAL_MIN                  0
#define CAV_ATC_CNMI_4_BFR_VAL_MAX                  1
#define CAV_ATC_CNMI_4_BFR_VAL_DEFAULT              0

/* AT+CGNS */
#define  CAV_CC_CGSN_VALUE_MIN   0
#define  CAV_CC_CGSN_VALUE_MAX   3
#define  CAV_CC_CGSN_VALUE_DEF   1

uint8_t* atCmdGetCbstString(uint8_t atCid);
BOOL appCavsmsGetInputAddrInfo(AtParamValueCP pParamList, INT32 index, CmiSmsAddressInfo *pSmsAddr);

CmsRetId  cavAtCgmr(const AtCmdInputContext *pAtCmdReq);
CmsRetId  cavAtCpsms(const AtCmdInputContext *pAtCmdReq);
CmsRetId  cavAtCgmi(const AtCmdInputContext *pAtCmdReq);
CmsRetId  cavAtCgmm(const AtCmdInputContext *pAtCmdReq);
CmsRetId  cavAtCbst(const AtCmdInputContext *pAtCmdReq);
CmsRetId  cavSimICCID(const AtCmdInputContext *pAtCmdReq);
CmsRetId  cavSYSRST(const AtCmdInputContext *pAtCmdReq);
//CmsRetId  cavGSETSBD(const AtCmdInputContext *pAtCmdReq);
CmsRetId cavAtFslstfile(const AtCmdInputContext *pAtCmdReq);
CmsRetId cavATI(const AtCmdInputContext *pAtCmdReq);
CmsRetId cavATandF(const AtCmdInputContext *pAtCmdReq);
CmsRetId  cavAtLteinfo(const AtCmdInputContext *pAtCmdReq);
CmsRetId  cavAtCereg(const AtCmdInputContext *pAtCmdReq);
CmsRetId  cavAtCgcontrdp(const AtCmdInputContext *pAtCmdReq);
CmsRetId  cavDevCFUN(const AtCmdInputContext *pAtCmdReq);
CmsRetId  cavPsCGDCONT(const AtCmdInputContext *pAtCmdReq);
CmsRetId  cavpsCgerep(const AtCmdInputContext *pAtCmdReq);
CmsRetId  cavpsCemode(const AtCmdInputContext *pAtCmdReq);
CmsRetId  cavsmsCMGW(const AtCmdInputContext *pAtCmdReq);
CmsRetId  cavSmsCNMI(const AtCmdInputContext *pAtCmdReq);
CmsRetId  cavCGSN(const AtCmdInputContext *pAtCmdReq);
CmsRetId  cavPdevECPMUCFG(const AtCmdInputContext *pAtCmdReq);
CmsRetId  cavPsSIMSWAP(const AtCmdInputContext *pAtCmdReq);
CmsRetId  cavCalMode(const AtCmdInputContext *pAtCmdReq);
CmsRetId  cavRfSwitch(const AtCmdInputContext *pAtCmdReq);
CmsRetId  cavMmCCLK(const AtCmdInputContext *pAtCmdReq);
CmsRetId  cavHwVer(const AtCmdInputContext *pAtCmdReq);
CmsRetId  cavPartNum(const AtCmdInputContext *pAtCmdReq);
CmsRetId  cavSimSel(const AtCmdInputContext *pAtCmdReq);
#endif //__AT_CUSTOM_H__
