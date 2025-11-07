/* eminj-pcw00-1600-a-t-M4 */
/*********************************************************************/
/*  Copyright Toyota Motor Corporation                               */
/*********************************************************************/

/*********************************************************************/
/* �I�u�W�F�N�g��  |  ���˗v���̒���                                 */
/* ���ӎ���        |                                                 */
/*-------------------------------------------------------------------*/
/*     �ʕύX���� �i�ʕύX���͈ȉ��ɕύX���A���e���L�����邱�Ɓj */
/*********************************************************************/

/*-------------------------------------------------------------------*/
/* �K���萔�̃Z�N�V������`                                          */
/*-------------------------------------------------------------------*/
#pragma ghs section rozdata = ".mat_eminj"

/*-------------------------------------------------------------------*/
/* �w�b�_�t�@�C���̃C���N���[�h                                      */
/*-------------------------------------------------------------------*/
#include <../inc/common.h>
#include <../inc/gllib.h>
#include <engsrc/espc/ejcc.h>                   /* JEEFI,u1g_EJCC_D4,u1g_EJCC_PORT,u1g_EJCC_DUAL,JESS,JEMAT_BENCHI */
                                                /* JEPRDEMAND,JEOBDAFIMB_D,JEFFV */
                                                /* JEMAT_BENCH_E,JEEGMG_E,u1g_EJCC_HVPLGR_E,u1g_EJCC_HVDIRECT_E,u1g_EJCC_HVCLUTCH_E */
                                                /* JEALLHV_E,u1g_EJCC_ALLHV_E */
                                                /* JENGPF_E,JENVCTR,JEMICN_E,u1g_EJCC_SUB_E,JEOBDMF,JEOBDFKG */
                                                /* JEPLMLT_E,JERMTCTR */
#include <engsrc/inc/elsb.h>

#include <engsrc/eactmedi/einj/eminj.h>

/*-------------------------------------------------------------------*/
/* �R���p�C���o�[�W������`                                          */
/*-------------------------------------------------------------------*/
#define MK32_ID (0x00000040)            /* R9�R���p�C�����g�p */

#ifdef __GHS_VERSION_NUMBER
 #if ( ( __GHS_VERSION_NUMBER >= 201355 ) \
    && ( __GHS_VERSION_NUMBER < 201400 ) )
 #else
  #error "�R���p�C�������R���p�C�����قȂ��Ă��܂��B"
 #endif
#endif

/*-------------------------------------------------------------------*/
/* �R���p�C��SW����`�`�F�b�N                                        */
/*-------------------------------------------------------------------*/
#if !defined JEEFI
#error "JEEFI is undeclared"
#endif

#if !defined u1g_EJCC_D4
#error "u1g_EJCC_D4 is undeclared"
#endif

#if !defined u1g_EJCC_PORT
#error "u1g_EJCC_PORT is undeclared"
#endif

#if !defined u1g_EJCC_DUAL
#error "u1g_EJCC_DUAL is undeclared"
#endif

#if !defined JESS
#error "JESS is undeclared"
#endif

#if !defined JEMAT_BENCHI
#error "JEMAT_BENCHI is undeclared"
#endif

#if !defined JEPRDEMAND
#error "JEPRDEMAND is undeclared"
#endif

#if !defined JEOBDAFIMB_D
#error "JEOBDAFIMB_D is undeclared"
#endif

#if !defined JEFFV
#error "JEFFV is undeclared"
#endif

#if !defined JEMAT_BENCH_E
#error "JEMAT_BENCH_E is undeclared"
#endif

#if !defined JEEGMG_E
#error "JEEGMG_E is undeclared"
#endif

#if !defined u1g_EJCC_HVPLGR_E
#error "u1g_EJCC_HVPLGR_E is undeclared"
#endif

#if !defined u1g_EJCC_HVDIRECT_E
#error "u1g_EJCC_HVDIRECT_E is undeclared"
#endif

#if !defined u1g_EJCC_HVCLUTCH_E
#error "u1g_EJCC_HVCLUTCH_E is undeclared"
#endif

#if !defined JEALLHV_E
#error "JEALLHV_E is undeclared"
#endif

#if !defined u1g_EJCC_ALLHV_E
#error "u1g_EJCC_ALLHV_E is undeclared"
#endif

#if !defined JENGPF_E
#error "JENGPF_E is undeclared"
#endif

#if !defined JENVCTR
#error "JENVCTR is undeclared"
#endif

#if !defined JEMICN_E
#error "JEMICN_E is undeclared"
#endif

#if !defined u1g_EJCC_SUB_E
#error "u1g_EJCC_SUB_E is undeclared"
#endif

#if !defined JEOBDMF
#error "JEOBDMF is undeclared"
#endif

#if !defined JEOBDFKG
#error "JEOBDFKG is undeclared"
#endif

#if !defined JEPLMLT_E
#error "JEPLMLT_E is undeclared"
#endif

#if !defined JERMTCTR
#error "JERMTCTR is undeclared"
#endif

#if !defined EMINJ_STAHV_MEDI
#error "EMINJ_STAHV_MEDI is undeclared"
#endif

#if !defined EMINJ_FCFRCTRL_MEDI
#error "EMINJ_FCFRCTRL_MEDI is undeclared"
#endif

#if !defined EMINJ_STACM_MEDI
#error "EMINJ_STACM_MEDI is undeclared"
#endif

#if !defined EMINJ_INJIMB_MEDI
#error "EMINJ_INJIMB_MEDI is undeclared"
#endif

#if !defined EMINJ_ACTOBD_MEDI
#error "EMINJ_ACTOBD_MEDI is undeclared"
#endif

#if !defined EMINJ_IMBRQ_MEDI
#error "EMINJ_IMBRQ_MEDI is undeclared"
#endif

#if !defined EMINJ_MFINJRQ_MEDI
#error "EMINJ_MFINJRQ_MEDI is undeclared"
#endif

#if !defined EMINJ_FKGDRQ_MEDI
#error "EMINJ_FKGDRQ_MEDI is undeclared"
#endif

#if !defined EMINJ_ACTLFG_MEDI
#error "EMINJ_ACTLFG_MEDI is undeclared"
#endif

#if !defined EMINJ_BINJPLCTR_MEDI
#error "EMINJ_BINJPLCTR_MEDI is undeclared"
#endif

#if !defined EMINJ_BINJPLCTR_WC_MEDI
#error "EMINJ_BINJPLCTR_WC_MEDI is undeclared"
#endif

#if !defined EMINJ_BINJPLCTR_STAHV_MEDI
#error "EMINJ_BINJPLCTR_STAHV_MEDI is undeclared"
#endif

/*-------------------------------------------------------------------*/
/* �K���萔                                                          */
/*-------------------------------------------------------------------*/
/* $$$�K���萔_�W��_v4.11 */
volatile const s2 s2s_eminj_NE_RCD = s2g_ELSB_NE(4000.);                /* m=eminj,lsb=(12800*2)/128/256,ofs=,unit=rpm :�������s����臒l */
/* EMINJ_KRICHI�́Aeminj_l_mat.c�t�@�C���ɒ�`���܂����B */
/* #if (JEEFI == u1g_EJCC_D4) */                                        /* �yD-4�z */
/* EMINJ_INJPTN_VD�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* #else */                                                             /* �yD-4�ȊO�z */
/* EMINJ_INJPTN_VD�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* #endif */                                                            /* JEEFI */
/* #if (JEEFI != u1g_EJCC_D4) */                                        /* �yD-4�ȊO�z */
/* EMINJ_AINJP_VD�́Aeminj_l_mat.c�t�@�C���ɒ�`���܂����B */
/* EMINJ_AINJP_MN�́Aeminj_l_mat.c�t�@�C���ɒ�`���܂����B */
/* EMINJ_AINJP_MX�́Aeminj_l_mat.c�t�@�C���ɒ�`���܂����B */
/* EMINJ_K1F_VD�́Aeminj_l_mat.c�t�@�C���ɒ�`���܂����B */
/* #endif */                                                            /* JEEFI */
/* #if (JEEFI == u1g_EJCC_PORT) */                                      /* �y�߰āz */
/* EMINJ_AINJPADD_MN�́Aeminj_l_mat.c�t�@�C���ɒ�`���܂����B */
/* EMINJ_AINJPADD_MX�́Aeminj_l_mat.c�t�@�C���ɒ�`���܂����B */
/* #endif */                                                            /* JEEFI */
/* #if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4) */            /* �y�ޭ��INJ�zOR�yD-4�z */
/* EMINJ_AINJD_VD�́Aeminj_l_mat.c�t�@�C���ɒ�`���܂����B */
 /* #if (JECOMBCCPT_E == u1g_EJCC_SPRAYG_E) */                          /* �y���ڰ�޲�ށz */
/* EMINJ_AINJD_MN�́Aeminj_l_mat.c�t�@�C���ɒ�`���܂����B */
 /* #else */                                                            /* �y���ڰ�޲�ވȊO�z */
/* EMINJ_AINJD_MN�́Aeminj_l_mat.c�t�@�C���ɒ�`���܂����B */
 /* #endif */                                                           /* JECOMBCCPT_E */
/* EMINJ_AINJD_MX�́Aeminj_l_mat.c�t�@�C���ɒ�`���܂����B */
/* EMINJ_AINJDADD_MN�́Aeminj_l_mat.c�t�@�C���ɒ�`���܂����B */
/* EMINJ_AINJDADD_MX�́Aeminj_l_mat.c�t�@�C���ɒ�`���܂����B */
/* #endif */                                                            /* JEEFI */
/* EMINJ_QINJI�́Aeminj_l_mat.c�t�@�C���ɒ�`���܂����B */
/* EMINJ_QINJ_VD�́Aeminj_l_mat.c�t�@�C���ɒ�`���܂����B */
/* EMINJ_QINJ_MN�́Aeminj_l_mat.c�t�@�C���ɒ�`���܂����B */
/* EMINJ_QINJ_MX�́Aeminj_l_mat.c�t�@�C���ɒ�`���܂����B */
/* EMINJ_QINJST_MN�́Aeminj_l_mat.c�t�@�C���ɒ�`���܂����B */
/* EMINJ_QINJST_MX�́Aeminj_l_mat.c�t�@�C���ɒ�`���܂����B */
/* EMINJ_QINJFLFIX_VD�́Aeminj_l_mat.c�t�@�C���ɒ�`���܂����B */
/* EMINJ_QINJPLFIX_VD�́Aeminj_l_mat.c�t�@�C���ɒ�`���܂����B */
/* EMINJ_K1F_MN�́Aeminj_l_mat.c�t�@�C���ɒ�`���܂����B */
/* EMINJ_K1F_MX�́Aeminj_l_mat.c�t�@�C���ɒ�`���܂����B */
/* EMINJ_K1FN_MN�́Aeminj_l_mat.c�t�@�C���ɒ�`���܂����B */
/* EMINJ_K1FN_MX�́Aeminj_l_mat.c�t�@�C���ɒ�`���܂����B */
/* EMINJ_K2F_MN�́Aeminj_l_mat.c�t�@�C���ɒ�`���܂����B */
/* EMINJ_K2F_MX�́Aeminj_l_mat.c�t�@�C���ɒ�`���܂����B */
/* EMINJ_K2FN_MN�́Aeminj_l_mat.c�t�@�C���ɒ�`���܂����B */
/* EMINJ_K2FN_MX�́Aeminj_l_mat.c�t�@�C���ɒ�`���܂����B */
/* EMINJ_K3F_MN�́Aeminj_l_mat.c�t�@�C���ɒ�`���܂����B */
/* EMINJ_K3F_MX�́Aeminj_l_mat.c�t�@�C���ɒ�`���܂����B */
/* EMINJ_K3FN_MN�́Aeminj_l_mat.c�t�@�C���ɒ�`���܂����B */
/* EMINJ_K3FN_MX�́Aeminj_l_mat.c�t�@�C���ɒ�`���܂����B */
/* EMINJ_KRCHREF_MN�́Aeminj_l_mat.c�t�@�C���ɒ�`���܂����B */
/* EMINJ_KRCHREF_MX�́Aeminj_l_mat.c�t�@�C���ɒ�`���܂����B */
/* $$$�K���萔_�W��_v4.11 */

/*-------------------------------------------------------------------*/
/* �Œ�萔                                                          */
/*-------------------------------------------------------------------*/
/* $$$�Œ�萔_�W��_v4.11 */
/* �Œ�萔 EMINJ_PRINORQ�́Aeminj.h�t�@�C���ɒ�`���܂����B */

#if (JEMAT_BENCHI == u1g_EJCC_USE) || (JEMAT_BENCH_E == u1g_EJCC_USE)   /* �y�����K���p��ėL�zOR�y�����K��Ӱ�ޗL�z */
volatile const u1 u1g_eminj_BENCH_PRI = (u1)(((2.)/(1.))+0.5);          /* m=eminj,lsb=1,ofs=,unit=- :�����K���p���˗v���̗D��x */
#endif                                                                  /* JEMAT_BENCHI JEMAT_BENCH_E */

volatile const u1 u1g_eminj_EGSTPVS_PRI = (u1)(((4.)/(1.))+0.5);        /* m=eminj,lsb=1,ofs=,unit=- :���˒�~�̗D��x */

#if JEEFI == u1g_EJCC_DUAL                                              /* �y�ޭ��INJ�z */
volatile const u1 u1g_eminj_DEFLAIR_PRI = (u1)(((6.)/(1.))+0.5);        /* m=eminj,lsb=1,ofs=,unit=- :�H�괱��������̗D��x */
#endif                                                                  /* JEEFI */

#if (JEEGMG_E == u1g_EJCC_HVPLGR_E) || (JEEGMG_E == u1g_EJCC_HVDIRECT_E)    /* �yEG-MG�V���ޱ�zOR�yEG-MG�����z */
volatile const u1 u1g_eminj_STPHV_PRI = (u1)(((12.)/(1.))+0.5);         /* m=eminj,lsb=1,ofs=,unit=- :HV��~����̗D��x */
#endif                                                                  /* JEEGMG_E */

#if (JESS == u1g_EJCC_USE) || (JEEGMG_E == u1g_EJCC_HVCLUTCH_E)         /* �ySS����L�zOR�yEG-MG�ׯ��z */
volatile const u1 u1g_eminj_STPSS_PRI = (u1)(((14.)/(1.))+0.5);         /* m=eminj,lsb=1,ofs=,unit=- :SS��~����̗D��x */
#endif                                                                  /* JESS JEEGMG_E */

#if JEALLHV_E == u1g_EJCC_ALLHV_E                                       /* �yALL HV�z */
volatile const u1 u1g_eminj_RDNVES_PRI = (u1)(((16.)/(1.))+0.5);        /* m=eminj,lsb=1,ofs=,unit=- :�ݼ�ݒ�~�E�n�����̐U���ጸ����̗D��x */
#endif                                                                  /* JEALLHV_E */

#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)                  /* �y�ޭ��INJ�zOR�yD-4�z */
volatile const u1 u1g_eminj_SJC_PRI = (u1)(((20.)/(1.))+0.5);           /* m=eminj,lsb=1,ofs=,unit=- :�G�}�}���g�@����̗D��x */
#endif                                                                  /* JEEFI */

#if (JEALLHV_E == u1g_EJCC_ALLHV_E) && (JEPLMLT_E == u1g_EJCC_USE) && (EMINJ_BINJPLCTR_WC_MEDI == ON)   /* �yALL HV�zAND�yPL������˗L�zAND�y�߰�����ĕ��˂�p������{���ː���(�G�}�g�@��)�v���g�p�z */
volatile const u1 u1g_eminj_BINJPLCTR_WC_PRI = (u1)(((22.)/(1.))+0.5);  /* m=eminj,lsb=1,ofs=,unit=- :�߰�����ĕ��˂�p������{���ː���(�G�}�g�@��)�̗D��x */
#endif                                                                  /* JEALLHV_E JEPLMLT_E EMINJ_BINJPLCTR_WC_MEDI */

#if JEALLHV_E == u1g_EJCC_ALLHV_E                                       /* �yALL HV�z */
volatile const u1 u1g_eminj_WUPCAT_PRI = (u1)(((24.)/(1.))+0.5);        /* m=eminj,lsb=1,ofs=,unit=- :�G�}�g�@����̗D��x */
#endif                                                                  /* JEALLHV_E */

#if (JENGPF_E != u1g_EJCC_NOT_USE) && (EMINJ_FCFRCTRL_MEDI == ON)       /* �yGPF�L�zAND�y1�C��FC����v���g�p�z */
volatile const u1 u1g_eminj_FCFRCTRL_PRI = (u1)(((26.)/(1.))+0.5);      /* m=eminj,lsb=1,ofs=,unit=- :1�C��FC����̗D��x */
#endif                                                                  /* JENGPF_E EMINJ_FCFRCTRL_MEDI */

#if ((JERMTCTR == u1g_EJCC_USE) || (JENVCTR == u1g_EJCC_USE)) && (JEMICN_E != u1g_EJCC_SUB_E) && (EMINJ_STACM_MEDI == ON)   /* (�y�Ӱĺ��۰ٗL�zOR�y��޺��۰ٗL�z)AND�ySUB-CPU�ȊO�zAND�y�n���������オ�萧��v���g�p�z */
volatile const u1 u1g_eminj_STACM_PRI = (u1)(((28.)/(1.))+0.5);         /* m=eminj,lsb=1,ofs=,unit=- :�n���������オ�萧��̗D��x */
#endif                                                                  /* JERMTCTR JENVCTR JEMICN_E EMINJ_STACM_MEDI */

#if (JESS == u1g_EJCC_USE) || (JEEGMG_E == u1g_EJCC_HVCLUTCH_E)         /* �ySS����L�zOR�yEG-MG�ׯ��z */
volatile const u1 u1g_eminj_STASS_PRI = (u1)(((30.)/(1.))+0.5);         /* m=eminj,lsb=1,ofs=,unit=- :SS�n������̗D��x */
#endif                                                                  /* JESS JEEGMG_E */

#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)                  /* �y�ޭ��INJ�zOR�yD-4�z */
volatile const u1 u1g_eminj_RESTAHOT_PRI = (u1)(((32.)/(1.))+0.5);      /* m=eminj,lsb=1,ofs=,unit=- :�����Ďn������̗D��x */
volatile const u1 u1g_eminj_KCST_PRI = (u1)(((34.)/(1.))+0.5);          /* m=eminj,lsb=1,ofs=,unit=- :�n����ɯ��h�~����̗D��x */
#endif                                                                  /* JEEFI */

#if (JEALLHV_E == u1g_EJCC_ALLHV_E) && (JEEFI == u1g_EJCC_PORT)         /* �yALL HV�zAND�y�߰āz */
volatile const u1 u1g_eminj_RDPN_ST_PRI = (u1)(((36.)/(1.))+0.5);       /* m=eminj,lsb=1,ofs=,unit=- :PN�ጸ����(�n����)�̗D��x */
#endif                                                                  /* JEALLHV_E JEEFI */

#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)                  /* �y�ޭ��INJ�zOR�yD-4�z */
volatile const u1 u1g_eminj_STRATIST_PRI = (u1)(((42.)/(1.))+0.5);      /* m=eminj,lsb=1,ofs=,unit=- :���w�n������̗D��x */
#endif                                                                  /* JEEFI */

#if JEEFI == u1g_EJCC_DUAL                                              /* �y�ޭ��INJ�z */
volatile const u1 u1g_eminj_STAFRG_PRI = (u1)(((44.)/(1.))+0.5);        /* m=eminj,lsb=1,ofs=,unit=- :�ɒቷ�n������̗D��x */
#endif                                                                  /* JEEFI */

#if (JEALLHV_E == u1g_EJCC_ALLHV_E) && (EMINJ_STAHV_MEDI == ON)         /* �yALL HV�zAND�yHV�n������v���g�p�z */
volatile const u1 u1g_eminj_STAHV_PRI = (u1)(((46.)/(1.))+0.5);         /* m=eminj,lsb=1,ofs=,unit=- :HV�n������̗D��x */
#endif                                                                  /* JEALLHV_E EMINJ_STAHV_MEDI */

#if (JEEGMG_E == u1g_EJCC_HVPLGR_E) && (JEFFV == u1g_EJCC_NOT_USE) && (JEPLMLT_E == u1g_EJCC_USE) && (EMINJ_BINJPLCTR_STAHV_MEDI == ON) /* �yEG-MG�V���ޱ�zAND�yFFV���䖳�zAND�yPL������˗L�zAND�y�߰�����ĕ��˂�p������{���ː���(HV�n�����䎞)�v���g�p�z */
volatile const u1 u1g_eminj_BINJPLCTR_STAHV_PRI = (u1)(((48.)/(1.))+0.5);   /* m=eminj,lsb=1,ofs=,unit=- :�߰�����ĕ��˂�p������{���ː���(HV�n�����䎞)�̗D��x */
#endif                                                                  /* JEEGMG_E JEFFV JEPLMLT_E EMINJ_BINJPLCTR_STAHV_MEDI */

volatile const u1 u1g_eminj_FCINJCTR_PRI = (u1)(((50.)/(1.))+0.5);      /* m=eminj,lsb=1,ofs=,unit=- :FC���R�����ː���̗D��x */

#if (JEALLHV_E == u1g_EJCC_ALLHV_E) && (JEEFI != u1g_EJCC_D4)           /* �yALL HV�zAND�yD-4�ȊO�z */
volatile const u1 u1g_eminj_RDPN_PRI = (u1)(((52.)/(1.))+0.5);          /* m=eminj,lsb=1,ofs=,unit=- :PN�ጸ����̗D��x */
#endif                                                                  /* JEALLHV_E JEEFI */

#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)                  /* �y�ޭ��INJ�zOR�yD-4�z */
volatile const u1 u1g_eminj_RTNFC_PRI = (u1)(((54.)/(1.))+0.5);         /* m=eminj,lsb=1,ofs=,unit=- :FC���A����̗D��x */
#endif                                                                  /* JEEFI */

#if JEEFI == u1g_EJCC_DUAL                                              /* �y�ޭ��INJ�z */
volatile const u1 u1g_eminj_CLRDEPI_PRI = (u1)(((56.)/(1.))+0.5);       /* m=eminj,lsb=1,ofs=,unit=- :����َ��ݼު�����ߏ�������̗D��x */
#endif                                                                  /* JEEFI */

#if (JEEFI == u1g_EJCC_DUAL) && (JEPRDEMAND == u1g_EJCC_NOT_USE)        /* �y�ޭ��INJ�zAND�y�ϔR�����䖳�z */
volatile const u1 u1g_eminj_FPLDLV_PRI = (u1)(((60.)/(1.))+0.5);        /* m=eminj,lsb=1,ofs=,unit=- :�ሳ�����ؓ��R��������𐧌�̗D��x */
#endif                                                                  /* JEEFI JEPRDEMAND */

#if JEEFI == u1g_EJCC_DUAL                                              /* �y�ޭ��INJ�z */
volatile const u1 u1g_eminj_DTHRCTRL_PRI = (u1)(((64.)/(1.))+0.5);      /* m=eminj,lsb=1,ofs=,unit=- :�C�����ި�ސ���̗D��x */
#endif                                                                  /* JEEFI */

#if ((JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)) && (EMINJ_ACTLFG_MEDI == ON)   /* (�y�ޭ��INJ�zOR�yD-4�z)AND�y�߰�����Ċw�K�ׂ̱̈�è�ސ���v���g�p�z */
volatile const u1 u1g_eminj_ACTLFG_PRI = (u1)(((66.)/(1.))+0.5);        /* m=eminj,lsb=1,ofs=,unit=- :�߰�����Ċw�K�ׂ̱̈�è�ސ���̗D��x */
#endif                                                                  /* JEEFI EMINJ_ACTLFG_MEDI */

#if (JEOBDAFIMB_D == u1g_EJCC_USE) && (JEEFI == u1g_EJCC_DUAL) && (EMINJ_INJIMB_MEDI == ON) /* �yAF�C���Բ����ݽ�L�zAND�y�ޭ��INJ�zAND�y�����ݽ���̕��ː���v���g�p�z */
volatile const u1 u1g_eminj_INJIMB_PRI = (u1)(((72.)/(1.))+0.5);        /* m=eminj,lsb=1,ofs=,unit=- :�����ݽ���̕��ː���̗D��x */
#endif                                                                  /* JEOBDAFIMB_D JEEFI EMINJ_INJIMB_MEDI */

#if (JEEFI == u1g_EJCC_DUAL) && (JEFFV != u1g_EJCC_NOT_USE)             /* �y�ޭ��INJ�zAND�yFFV����L�z */
volatile const u1 u1g_eminj_ACTAREFUEL_PRI = (u1)(((74.)/(1.))+0.5);    /* m=eminj,lsb=1,ofs=,unit=- :������̕���������è�ސ���̗D��x */
#endif                                                                  /* JEEFI JEFFV */

#if JEEFI == u1g_EJCC_DUAL                                              /* �y�ޭ��INJ�z */
 #if EMINJ_ACTOBD_MEDI == ON                                            /* �y�ޭ��INJ�zAND�yOBD�v���ɂ�鱸è�ސ���v���g�p�z */
volatile const u1 u1g_eminj_ACTOBD_PRI = (u1)(((76.)/(1.))+0.5);        /* m=eminj,lsb=1,ofs=,unit=- :OBD�v���ɂ�鱸è�ސ���̗D��x */
 #endif                                                                 /* EMINJ_ACTOBD_MEDI */

volatile const u1 u1g_eminj_ACTGAF_PRI = (u1)(((84.)/(1.))+0.5);        /* m=eminj,lsb=1,ofs=,unit=- :A/F�w�K�ׂ̱̈�è�ސ���̗D��x */

 #if (JEOBDAFIMB_D == u1g_EJCC_USE) && (EMINJ_IMBRQ_MEDI == ON)         /* �yAF�C���Բ����ݽ�L�zAND�y�ޭ��INJ�zAND�y�����ݽOBD�v���ɂ�鱸è�ސ���v���g�p�z */
volatile const u1 u1g_eminj_IMBRQ_PRI = (u1)(((78.)/(1.))+0.5);         /* m=eminj,lsb=1,ofs=,unit=- :�����ݽOBD�v���ɂ�鱸è�ސ���̗D��x */
 #endif                                                                 /* JEOBDAFIMB_D EMINJ_IMBRQ_MEDI */

 #if (JEOBDMF == u1g_EJCC_USE) && (EMINJ_MFINJRQ_MEDI == ON)            /* �y����OBD�L�zAND�y�ޭ��INJ�zAND�y����OBD�v���ɂ�鱸è�ސ���v���g�p�z */
volatile const u1 u1g_eminj_MFINJRQ_PRI = (u1)(((80.)/(1.))+0.5);       /* m=eminj,lsb=1,ofs=,unit=- :����OBD�v���ɂ�鱸è�ސ���̗D��x */
 #endif                                                                 /* JEOBDMF EMINJ_MFINJRQ_MEDI */

 #if (JEOBDFKG == u1g_EJCC_USE) && (EMINJ_FKGDRQ_MEDI == ON)            /* �y�R��OBD�L�zAND�y�ޭ��INJ�zAND�y�R���nOBD�v���ɂ�鱸è�ސ���v���g�p�z */
volatile const u1 u1g_eminj_FKGDRQ_PRI = (u1)(((82.)/(1.))+0.5);        /* m=eminj,lsb=1,ofs=,unit=- :�R���nOBD�v���ɂ�鱸è�ސ���̗D��x */
 #endif                                                                 /* JEOBDFKG EMINJ_FKGDRQ_MEDI */
#endif                                                                  /* JEEFI */

#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)                  /* �y�ޭ��INJ�zOR�yD-4�z */
volatile const u1 u1g_eminj_KCTRN_PRI = (u1)(((86.)/(1.))+0.5);         /* m=eminj,lsb=1,ofs=,unit=- :���iɯ��h�~����̗D��x */
#endif                                                                  /* JEEFI */

#if JEEFI == u1g_EJCC_DUAL                                              /* �y�ޭ��INJ�z */
volatile const u1 u1g_eminj_RDVAP_PRI = (u1)(((88.)/(1.))+0.5);         /* m=eminj,lsb=1,ofs=,unit=- :�ް�߰�}������̗D��x */
volatile const u1 u1g_eminj_DWNPR_PRI = (u1)(((90.)/(1.))+0.5);         /* m=eminj,lsb=1,ofs=,unit=- :�R���ጸ����̗D��x */
#endif                                                                  /* JEEFI */

volatile const u1 u1g_eminj_PWRUP_PRI = (u1)(((92.)/(1.))+0.5);         /* m=eminj,lsb=1,ofs=,unit=- :�o�͐��\���㐧��̗D��x */

#if JEEFI == u1g_EJCC_DUAL                                              /* �y�ޭ��INJ�z */
volatile const u1 u1g_eminj_PRVDIL_PRI = (u1)(((96.)/(1.))+0.5);        /* m=eminj,lsb=1,ofs=,unit=- :��Ԏ���ߖh�~����̗D��x */
#endif                                                                  /* JEEFI */

#if (JEPLMLT_E == u1g_EJCC_USE) && (EMINJ_BINJPLCTR_MEDI == ON)         /* �yPL������˗L�zAND�y�߰�����ĕ��˂�p������{���ː���v���g�p�z */
volatile const u1 u1g_eminj_BINJPLCTR_PRI = (u1)(((98.)/(1.))+0.5);     /* m=eminj,lsb=1,ofs=,unit=- :�߰�����ĕ��˂�p������{���ː���̗D��x */
#endif                                                                  /* JEPLMLT_E EMINJ_BINJPLCTR_MEDI */

#if EMINJ_FREE0 == ON                                                   /* �y�ذ�߰�0�g�p�z */
volatile const u1 u1g_eminj_FREE0_PRI = (u1)(((200.)/(1.))+0.5);        /* m=eminj,lsb=1,ofs=,unit=- :�ذ�߰�0�p����̗D��x */
#endif                                                                  /* EMINJ_FREE0 */

#if EMINJ_FREE1 == ON                                                   /* �y�ذ�߰�1�g�p�z */
volatile const u1 u1g_eminj_FREE1_PRI = (u1)(((201.)/(1.))+0.5);        /* m=eminj,lsb=1,ofs=,unit=- :�ذ�߰�1�p����̗D��x */
#endif                                                                  /* EMINJ_FREE1 */

#if EMINJ_FREE2 == ON                                                   /* �y�ذ�߰�2�g�p�z */
volatile const u1 u1g_eminj_FREE2_PRI = (u1)(((202.)/(1.))+0.5);        /* m=eminj,lsb=1,ofs=,unit=- :�ذ�߰�2�p����̗D��x */
#endif                                                                  /* EMINJ_FREE2 */

#if EMINJ_FREE3 == ON                                                   /* �y�ذ�߰�3�g�p�z */
volatile const u1 u1g_eminj_FREE3_PRI = (u1)(((203.)/(1.))+0.5);        /* m=eminj,lsb=1,ofs=,unit=- :�ذ�߰�3�p����̗D��x */
#endif                                                                  /* EMINJ_FREE3 */

#if EMINJ_FREE4 == ON                                                   /* �y�ذ�߰�4�g�p�z */
volatile const u1 u1g_eminj_FREE4_PRI = (u1)(((204.)/(1.))+0.5);        /* m=eminj,lsb=1,ofs=,unit=- :�ذ�߰�4�p����̗D��x */
#endif                                                                  /* EMINJ_FREE4 */

#if EMINJ_FREE5 == ON                                                   /* �y�ذ�߰�5�g�p�z */
volatile const u1 u1g_eminj_FREE5_PRI = (u1)(((205.)/(1.))+0.5);        /* m=eminj,lsb=1,ofs=,unit=- :�ذ�߰�5�p����̗D��x */
#endif                                                                  /* EMINJ_FREE5 */

#if EMINJ_FREE6 == ON                                                   /* �y�ذ�߰�6�g�p�z */
volatile const u1 u1g_eminj_FREE6_PRI = (u1)(((206.)/(1.))+0.5);        /* m=eminj,lsb=1,ofs=,unit=- :�ذ�߰�6�p����̗D��x */
#endif                                                                  /* EMINJ_FREE6 */

#if EMINJ_FREE7 == ON                                                   /* �y�ذ�߰�7�g�p�z */
volatile const u1 u1g_eminj_FREE7_PRI = (u1)(((207.)/(1.))+0.5);        /* m=eminj,lsb=1,ofs=,unit=- :�ذ�߰�7�p����̗D��x */
#endif                                                                  /* EMINJ_FREE7 */

#if EMINJ_FREE8 == ON                                                   /* �y�ذ�߰�8�g�p�z */
volatile const u1 u1g_eminj_FREE8_PRI = (u1)(((208.)/(1.))+0.5);        /* m=eminj,lsb=1,ofs=,unit=- :�ذ�߰�8�p����̗D��x */
#endif                                                                  /* EMINJ_FREE8 */

#if EMINJ_FREE9 == ON                                                   /* �y�ذ�߰�9�g�p�z */
volatile const u1 u1g_eminj_FREE9_PRI = (u1)(((209.)/(1.))+0.5);        /* m=eminj,lsb=1,ofs=,unit=- :�ذ�߰�9�p����̗D��x */
#endif                                                                  /* EMINJ_FREE9 */

#if EMINJ_FREE10 == ON                                                  /* �y�ذ�߰�10�g�p�z */
volatile const u1 u1g_eminj_FREE10_PRI = (u1)(((210.)/(1.))+0.5);       /* m=eminj,lsb=1,ofs=,unit=- :�ذ�߰�10�p����̗D��x */
#endif                                                                  /* EMINJ_FREE10 */

#if EMINJ_FREE11 == ON                                                  /* �y�ذ�߰�11�g�p�z */
volatile const u1 u1g_eminj_FREE11_PRI = (u1)(((211.)/(1.))+0.5);       /* m=eminj,lsb=1,ofs=,unit=- :�ذ�߰�11�p����̗D��x */
#endif                                                                  /* EMINJ_FREE11 */

/* �Œ�萔 EMINJ_NONE_ID�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* #if (JEMAT_BENCHI == u1g_EJCC_USE) || (JEMAT_BENCH_E == u1g_EJCC_USE) */ /* �y�����K���p��ėL�zOR�y�����K��Ӱ�ޗL�z */
/* �Œ�萔 EMINJ_BENCH_ID�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* #endif */                                                            /* JEMAT_BENCHI JEMAT_BENCH_E */
/* �Œ�萔 EMINJ_EGSTPVS_ID�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* #if JEEFI == u1g_EJCC_DUAL */                                        /* �y�ޭ��INJ�z */
/* �Œ�萔 EMINJ_DEFLAIR_ID�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* #endif */                                                            /* JEEFI */
/* #if (JEEGMG_E == u1g_EJCC_HVPLGR_E) || (JEEGMG_E == u1g_EJCC_HVDIRECT_E) */  /* �yEG-MG�V���ޱ�zOR�yEG-MG�����z */
/* �Œ�萔 EMINJ_STPHV_ID�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* #endif */                                                            /* JEEGMG_E */
/* #if (JESS == u1g_EJCC_USE) || (JEEGMG_E == u1g_EJCC_HVCLUTCH_E) */   /* �ySS����L�zOR�yEG-MG�ׯ��z */
/* �Œ�萔 EMINJ_STPSS_ID�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* #endif */                                                            /* JESS JEEGMG_E */
/* �Œ�萔 EMINJ_RDNVES_ID�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* #if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4) */            /* �y�ޭ��INJ�zOR�yD-4�z */
/* �Œ�萔 EMINJ_SJC_ID�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* #endif */                                                            /* JEEFI */
/* #if (JEALLHV_E == u1g_EJCC_ALLHV_E) && (JEPLMLT_E == u1g_EJCC_USE) && (EMINJ_BINJPLCTR_WC_MEDI == ON) */ /* �yALL HV�zAND�yPL������˗L�zAND�y�߰�����ĕ��˂�p������{���ː���(�G�}�g�@��)�v���g�p�z */
/* �Œ�萔 EMINJ_BINJPLCTR_WC_ID�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* #endif */                                                            /* JEALLHV_E JEPLMLT_E EMINJ_BINJPLCTR_WC_MEDI */
/* #if JEALLHV_E == u1g_EJCC_ALLHV_E */                                 /* �yALL HV�z */
/* �Œ�萔 EMINJ_WUPCAT_ID�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* #endif */                                                            /* JEALLHV_E */
/* #if (JENGPF_E != u1g_EJCC_NOT_USE) && (EMINJ_FCFRCTRL_MEDI == ON) */ /* �yGPF�L�zAND�y1�C��FC����v���g�p�z */
/* �Œ�萔 EMINJ_FCFRCTRL_ID�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* #endif */                                                            /* JENGPF_E EMINJ_FCFRCTRL_MEDI */
/* #if ((JERMTCTR == u1g_EJCC_USE) || (JENVCTR == u1g_EJCC_USE)) && (JEMICN_E != u1g_EJCC_SUB_E) && (EMINJ_STACM_MEDI == ON) */ /* (�y�Ӱĺ��۰ٗL�zOR�y��޺��۰ٗL�z)AND�ySUB-CPU�ȊO�zAND�y�n���������オ�萧��v���g�p�z */
/* �Œ�萔 EMINJ_STACM_ID�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* #endif */                                                            /* JERMTCTR JENVCTR JEMICN_E EMINJ_STACM_MEDI */
/* #if (JESS == u1g_EJCC_USE) || (JEEGMG_E == u1g_EJCC_HVCLUTCH_E) */   /* �ySS����L�zOR�yEG-MG�ׯ��z */
/* �Œ�萔 EMINJ_STASS_ID�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* #endif */                                                            /* JESS JEEGMG_E */
/* #if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4) */            /* �y�ޭ��INJ�zOR�yD-4�z */
/* �Œ�萔 EMINJ_RESTAHOT_ID�́Aeminj_l_mat.c�t�@�C���ɒ�`���܂����B */
/* �Œ�萔 EMINJ_KCST_ID�́Aeminj_l_mat.c�t�@�C���ɒ�`���܂����B */
/* #endif */                                                            /* JEEFI */
/* #if (JEALLHV_E == u1g_EJCC_ALLHV_E) && (JEEFI == u1g_EJCC_PORT) */   /* �yALL HV�zAND�y�߰āz */
/* �Œ�萔 EMINJ_RDPN_ST_ID�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* #endif */                                                            /* JEALLHV_E JEEFI */
/* #if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4) */            /* �y�ޭ��INJ�zOR�yD-4�z */
/* �Œ�萔 EMINJ_STRATIST_ID�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* #endif */                                                            /* JEEFI */
/* #if JEEFI == u1g_EJCC_DUAL */                                        /* �y�ޭ��INJ�z */
/* �Œ�萔 EMINJ_STAFRG_ID�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* #endif */                                                            /* JEEFI */
/* #if (JEALLHV_E == u1g_EJCC_ALLHV_E) && (EMINJ_STAHV_MEDI == ON) */   /* �yALL HV�zAND�yHV�n������v���g�p�z */
/* �Œ�萔 EMINJ_STAHV_ID�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* #endif */                                                            /* JEALLHV_E EMINJ_STAHV_MEDI */
/* #if (JEEGMG_E == u1g_EJCC_HVPLGR_E) && (JEFFV == u1g_EJCC_NOT_USE) && (JEPLMLT_E == u1g_EJCC_USE) && (EMINJ_BINJPLCTR_STAHV_MEDI == ON) */   /* �yEG-MG�V���ޱ�zAND�yFFV���䖳�zAND�yPL������˗L�z */
/* AND�y�߰�����ĕ��˂�p������{���ː���(HV�n�����䎞)�v���g�p�z */
/* �Œ�萔 EMINJ_BINJPLCTR_STAHV_ID�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* #endif */                                                            /* JEEGMG_E JEFFV JEPLMLT_E EMINJ_BINJPLCTR_STAHV_MEDI */
/* �Œ�萔 EMINJ_FCINJCTR_ID�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* #if (JEALLHV_E == u1g_EJCC_ALLHV_E) && (JEEFI != u1g_EJCC_D4) */     /* �yALL HV�zAND�yD-4�ȊO�z */
/* �Œ�萔 EMINJ_RDPN_ID�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* #endif */                                                            /* JEALLHV_E JEEFI */
/* #if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4) */            /* �y�ޭ��INJ�zOR�yD-4�z */
/* �Œ�萔 EMINJ_RTNFC_ID�́Aeminj_l_mat.c�t�@�C���ɒ�`���܂����B */
/* #endif */                                                            /* JEEFI */
/* #if JEEFI == u1g_EJCC_DUAL */                                        /* �y�ޭ��INJ�z */
/* �Œ�萔 EMINJ_CLRDEPI_ID�́Aeminj_l_mat.c�t�@�C���ɒ�`���܂����B */
/* #endif */                                                            /* JEEFI */
/* #if (JEEFI == u1g_EJCC_DUAL) && (JEPRDEMAND == u1g_EJCC_NOT_USE) */  /* �y�ޭ��INJ�zAND�y�ϔR�����䖳�z */
/* �Œ�萔 EMINJ_FPLDLV_ID�́Aeminj_l_mat.c�t�@�C���ɒ�`���܂����B */
/* #endif */                                                            /* JEEFI JEPRDEMAND */
/* #if JEEFI == u1g_EJCC_DUAL */                                        /* �y�ޭ��INJ�z */
/* �Œ�萔 EMINJ_DTHRCTRL_ID�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* #endif */                                                            /* JEEFI */
/* #if ((JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)) && (EMINJ_ACTLFG_MEDI == ON) */ /* (�y�ޭ��INJ�zOR�yD-4�z)AND�y�߰�����Ċw�K�ׂ̱̈�è�ސ���v���g�p�z */
/* �Œ�萔 EMINJ_ACTLFG_ID�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* #endif */                                                            /* JEEFI EMINJ_ACTLFG_MEDI */
/* #if (JEOBDAFIMB_D == u1g_EJCC_USE) && (JEEFI == u1g_EJCC_DUAL) && (EMINJ_INJIMB_MEDI == ON) */   /* �yAF�C���Բ����ݽ�L�zAND�y�ޭ��INJ�zAND�y�����ݽ���̕��ː���v���g�p�z */
/* �Œ�萔 EMINJ_INJIMB_ID�́Aeminj_l_mat.c�t�@�C���ɒ�`���܂����B */
/* #endif */                                                            /* JEOBDAFIMB_D JEEFI EMINJ_INJIMB_MEDI */
/* #if (JEEFI == u1g_EJCC_DUAL) && (JEFFV != u1g_EJCC_NOT_USE) */       /* �y�ޭ��INJ�zAND�yFFV����L�z */
/* �Œ�萔 EMINJ_ACTAREFUEL_ID�́Aeminj_l_mat.c�t�@�C���ɒ�`���܂����B */
/* #endif */                                                            /* JEEFI JEFFV */
/* #if JEEFI == u1g_EJCC_DUAL */                                        /* �y�ޭ��INJ�z */
 /* #if EMINJ_ACTOBD_MEDI == ON */                                      /* �y�ޭ��INJ�zAND�yOBD�v���ɂ�鱸è�ސ���v���g�p�z */
/* �Œ�萔 EMINJ_ACTOBD_ID�́Aeminj.h�t�@�C���ɒ�`���܂����B */
 /* #endif */                                                           /* EMINJ_ACTOBD_MEDI */
/* �Œ�萔 EMINJ_ACTGAF_ID�́Aeminj.h�t�@�C���ɒ�`���܂����B */
 /* #if (JEOBDAFIMB_D == u1g_EJCC_USE) && (EMINJ_IMBRQ_MEDI == ON) */   /* �yAF�C���Բ����ݽ�L�zAND�y�ޭ��INJ�zAND�y�����ݽOBD�v���ɂ�鱸è�ސ���v���g�p�z */
/* �Œ�萔 EMINJ_IMBRQ_ID�́Aeminj.h�t�@�C���ɒ�`���܂����B */
 /* #endif */                                                           /* JEOBDAFIMB_D EMINJ_IMBRQ_MEDI */
 /* #if (JEOBDMF == u1g_EJCC_USE) && (EMINJ_MFINJRQ_MEDI == ON) */      /* �y����OBD�L�zAND�y�ޭ��INJ�zAND�y����OBD�v���ɂ�鱸è�ސ���v���g�p�z */
/* �Œ�萔 EMINJ_MFINJRQ_ID�́Aeminj.h�t�@�C���ɒ�`���܂����B */
 /* #endif */                                                           /* JEOBDMF EMINJ_MFINJRQ_MEDI */
 /* #if (JEOBDFKG == u1g_EJCC_USE) && (EMINJ_FKGDRQ_MEDI == ON) */      /* �y�R��OBD�L�zAND�y�ޭ��INJ�zAND�y�R���nOBD�v���ɂ�鱸è�ސ���v���g�p�z */
/* �Œ�萔 EMINJ_FKGDRQ_ID�́Aeminj.h�t�@�C���ɒ�`���܂����B */
 /* #endif */                                                           /* JEOBDFKG EMINJ_FKGDRQ_MEDI */
/* #endif */                                                            /* JEEFI */
/* #if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4) */            /* �y�ޭ��INJ�zOR�yD-4�z */
/* �Œ�萔 EMINJ_KCTRN_ID�́Aeminj_l_mat.c�t�@�C���ɒ�`���܂����B */
/* #endif */                                                            /* JEEFI */
/* #if JEEFI == u1g_EJCC_DUAL */                                        /* �y�ޭ��INJ�z */
/* �Œ�萔 EMINJ_RDVAP_ID�́Aeminj_l_mat.c�t�@�C���ɒ�`���܂����B */
/* �Œ�萔 EMINJ_DWNPR_ID�́Aeminj_l_mat.c�t�@�C���ɒ�`���܂����B */
/* #endif */                                                            /* JEEFI */
/* �Œ�萔 EMINJ_PWRUP_ID�́Aeminj_l_mat.c�t�@�C���ɒ�`���܂����B */
/* #if JEEFI == u1g_EJCC_DUAL */                                        /* �y�ޭ��INJ�z */
/* �Œ�萔 EMINJ_PRVDIL_ID�́Aeminj_l_mat.c�t�@�C���ɒ�`���܂����B */
/* #endif */                                                            /* JEEFI */
/* #if (JEPLMLT_E == u1g_EJCC_USE) && (EMINJ_BINJPLCTR_MEDI == ON) */   /* �yPL������˗L�zAND�y�߰�����ĕ��˂�p������{���ː���v���g�p�z */
/* �Œ�萔 EMINJ_BINJPLCTR_ID�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* #endif */                                                            /* JEPLMLT_E EMINJ_BINJPLCTR_MEDI */
/* #if EMINJ_FREE0 == ON */                                             /* �y�ذ�߰�0�g�p�z */
/* �Œ�萔 EMINJ_FREE0_ID�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* #endif */                                                            /* EMINJ_FREE0 */
/* #if EMINJ_FREE1 == ON */                                             /* �y�ذ�߰�1�g�p�z */
/* �Œ�萔 EMINJ_FREE1_ID�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* #endif */                                                            /* EMINJ_FREE1 */
/* #if EMINJ_FREE2 == ON */                                             /* �y�ذ�߰�2�g�p�z */
/* �Œ�萔 EMINJ_FREE2_ID�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* #endif */                                                            /* EMINJ_FREE2 */
/* #if EMINJ_FREE3 == ON */                                             /* �y�ذ�߰�3�g�p�z */
/* �Œ�萔 EMINJ_FREE3_ID�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* #endif */                                                            /* EMINJ_FREE3 */
/* #if EMINJ_FREE4 == ON */                                             /* �y�ذ�߰�4�g�p�z */
/* �Œ�萔 EMINJ_FREE4_ID�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* #endif */                                                            /* EMINJ_FREE4 */
/* #if EMINJ_FREE5 == ON */                                             /* �y�ذ�߰�5�g�p�z */
/* �Œ�萔 EMINJ_FREE5_ID�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* #endif */                                                            /* EMINJ_FREE5 */
/* #if EMINJ_FREE6 == ON */                                             /* �y�ذ�߰�6�g�p�z */
/* �Œ�萔 EMINJ_FREE6_ID�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* #endif */                                                            /* EMINJ_FREE6 */
/* #if EMINJ_FREE7 == ON */                                             /* �y�ذ�߰�7�g�p�z */
/* �Œ�萔 EMINJ_FREE7_ID�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* #endif */                                                            /* EMINJ_FREE7 */
/* #if EMINJ_FREE8 == ON */                                             /* �y�ذ�߰�8�g�p�z */
/* �Œ�萔 EMINJ_FREE8_ID�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* #endif */                                                            /* EMINJ_FREE8 */
/* #if EMINJ_FREE9 == ON */                                             /* �y�ذ�߰�9�g�p�z */
/* �Œ�萔 EMINJ_FREE9_ID�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* #endif */                                                            /* EMINJ_FREE9 */
/* #if EMINJ_FREE10 == ON */                                            /* �y�ذ�߰�10�g�p�z */
/* �Œ�萔 EMINJ_FREE10_ID�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* #endif */                                                            /* EMINJ_FREE10 */
/* #if EMINJ_FREE11 == ON */                                            /* �y�ذ�߰�11�g�p�z */
/* �Œ�萔 EMINJ_FREE11_ID�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* #endif */                                                            /* EMINJ_FREE11 */
/* �Œ�萔 EMINJ_RQID_VD�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* �Œ�萔 EMINJ_RQINJMODE�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* �Œ�萔 EMINJ_RQINJPTN�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* �Œ�萔 EMINJ_RQAINJP1�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* �Œ�萔 EMINJ_RQAINJPN�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* EMINJ_RQAINJPN��EMINJ_RQAINJP,EMINJ_RQAINJP1�`EMINJ_RQAINJP4�͈قȂ�\���̂Ŏg�p����� */
/* �Œ�萔 EMINJ_RQAINJP2�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* �Œ�萔 EMINJ_RQAINJDN�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* EMINJ_RQAINJDN��EMINJ_RQAINJD1�`EMINJ_RQAINJD4�͈قȂ�\���̂Ŏg�p����� */
/* �Œ�萔 EMINJ_RQAINJP3�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* �Œ�萔 EMINJ_RQAINJP4�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* �Œ�萔 EMINJ_RQINJEND�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* �Œ�萔 EMINJ_RQAINJCUTP�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* �Œ�萔 EMINJ_RQAINJCUTD�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* �Œ�萔 EMINJ_RQAINJD1�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* �Œ�萔 EMINJ_RQAINJD2�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* �Œ�萔 EMINJ_RQAINJD3�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* ���ˉ񐔂��߰āE�������킹�čő�4����߰ĂƓ�����3��ڕ��ˊJ�n�����v���͔r���ƂȂ邽�߁A��ح��͓���ɂ��Ă��� */
/* �Œ�萔 EMINJ_RQAINJD4�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* ���ˉ񐔂��߰āE�������킹�čő�4����߰ĂƓ�����4��ڕ��ˊJ�n�����v���͔r���ƂȂ邽�߁A��ح��͓���ɂ��Ă��� */
/* �Œ�萔 EMINJ_RQQINJSTPN�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* EMINJ_RQQINJSTPN��EMINJ_RQQINJSTP,EMINJ_RQQINJSTP1�`EMINJ_RQQINJSTP4�͈قȂ�\���̂Ŏg�p����� */
/* �Œ�萔 EMINJ_RQQINJSTP1�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* �Œ�萔 EMINJ_RQQINJSTDN�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* EMINJ_RQQINJSTDN��EMINJ_RQQINJSTD1�`EMINJ_RQQINJSTD4�͈قȂ�\���̂Ŏg�p����� */
/* �Œ�萔 EMINJ_RQQINJSTP2�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* �Œ�萔 EMINJ_RQQINJFLFIX�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* �Œ�萔 EMINJ_RQQINJSTP3�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* �Œ�萔 EMINJ_RQQINJPLFIX�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* �Œ�萔 EMINJ_RQQINJSTP4�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* �Œ�萔 EMINJ_RQQINJSTD1�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* �Œ�萔 EMINJ_RQQINJSTD2�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* �Œ�萔 EMINJ_RQQINJSTD3�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* ���ˉ񐔂��߰āE�������킹�čő�4����߰ĂƓ�����3��ڎn�������˗v���͔r���ƂȂ邽�߁A��ح��͓���ɂ��Ă��� */
/* �Œ�萔 EMINJ_RQQINJSTD4�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* ���ˉ񐔂��߰āE�������킹�čő�4����߰ĂƓ�����4��ڎn�������˗v���͔r���ƂȂ邽�߁A��ح��͓���ɂ��Ă��� */
/* �Œ�萔 EMINJ_RQQFC�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* �Œ�萔 EMINJ_RQQINJEXP�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* �Œ�萔 EMINJ_RQK1FN�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* �Œ�萔 EMINJ_RQK2FN�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* �Œ�萔 EMINJ_RQK3FN�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* �Œ�萔 EMINJ_RQK1F�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* �Œ�萔 EMINJ_RQK2F�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* �Œ�萔 EMINJ_RQK3F�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* �Œ�萔 EMINJ_RQPRREQ�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* �Œ�萔 EMINJ_RQQFREQ�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* �Œ�萔 EMINJ_RQPRREQL�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* �Œ�萔 EMINJ_RQXQINJAST�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* �Œ�萔 EMINJ_RQKRCHREF�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* �Œ�萔 EMINJ_RQPLREQ�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* �Œ�萔 EMINJ_RQAINJP�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* �Œ�萔 EMINJ_RQQINJSTP�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* #if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4) */            /* �y�ޭ��INJ�zOR�yD-4�z */
/* �Œ�萔 EMINJ_MOD0N1�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* #endif */                                                            /* JEEFI */
/* �Œ�萔 EMINJ_MOD002�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* �Œ�萔 EMINJ_MOD003�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* �Œ�萔 EMINJ_MOD004�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* �Œ�萔 EMINJ_MOD005�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* �Œ�萔 EMINJ_MOD006�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* �Œ�萔 EMINJ_MOD007�́Aeminj.h�t�@�C���ɒ�`���܂����B */
/* $$$�Œ�萔_�W��_v4.11 */

/*-------------------------------------------------------------------*/
/* �K���}�b�v                                                        */
/*-------------------------------------------------------------------*/
/* $$$�K���}�b�v_�W��_v4.11 */
/* $$$�K���}�b�v_�W��_v4.11 */

/**** End of File ****************************************************/
