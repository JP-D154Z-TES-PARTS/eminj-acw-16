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
/* �w�b�_�t�@�C���̃C���N���[�h                                      */
/*-------------------------------------------------------------------*/
#include <../inc/common.h>
#include <../inc/gllib.h>
#include <engsrc/espc/ejcc.h>                   /* JEEFI,u1g_EJCC_DUAL,u1g_EJCC_D4,u1g_EJCC_PORT,u1g_EJCC_NOX,JESS,JEMAT_BENCHI */
                                                /* JEPRDEMAND,JEOBDAFIMB_D,JEFFV,JENOX,u1g_EJCC_TWIN,JEEGR,u1g_EJCC_NCYL,JECOMBCCPT_E,u1g_EJCC_SPRAYG_E */
                                                /* u1g_ejcc_NCYL,u1g_ejcc_NOX,JEMAT_BENCH_E,JEEGMG_E,u1g_EJCC_HVPLGR_E,u1g_EJCC_HVDIRECT_E,u1g_EJCC_HVCLUTCH_E,JEALLHV_E,u1g_EJCC_ALLHV_E */
                                                /* JENGPF_E,JEPLMLT_E,JENVCTR,JEMICN_E,u1g_EJCC_SUB_E,JEOBDMF,JEOBDFKG */
                                                /* JERMTCTR */
#include <engsrc/inc/elsb.h>
#include <engsrc/inc/elib.h>

#include <engsrc/eactmedi/einj/eminj.h>

#include <sac/ainjif.h>                          /* u2g_AINJIF_MOD011,vdg_ainjif_renew_injrq() */

#include <engsrc/estate/esin/ene.h>              /* s2g_ene_ene */
#if JEALLHV_E == u1g_EJCC_ALLHV_E               /*�yALL HV�z*/
#include <engsrc/efunc/edrblty/eels/erdnves.h>   /* vdg_erdnves_group00_dataget() */
#endif /* JEALLHV_E */
#if JEEFI == u1g_EJCC_DUAL      /*�y�ޭ��INJ�z*/
#include <engsrc/efunc/eunusual/eplant/edeflair.h> /* vdg_edeflair_emedi_dataget() */
#endif /* JEEFI */
#include <engsrc/efunc/eelsrq/eegstpvs.h>        /* vdg_eegstpvs_emedi_dataget() */
#if (JEEGMG_E == u1g_EJCC_HVPLGR_E) || (JEEGMG_E == u1g_EJCC_HVDIRECT_E)    /*�yEG-MG�V���ޱ�zOR�yEG-MG�����z*/
#include <engsrc/efunc/eeco/ehv/estphv.h>        /* vdg_estphv_emedi_dataget() */
#endif /* JEEGMG_E */
#if (JESS == u1g_EJCC_USE) || (JEEGMG_E == u1g_EJCC_HVCLUTCH_E)         /*�ySS����L�zOR�yEG-MG�ׯ��z*/
#include <engsrc/efunc/eeco/ess/estpss.h>        /* vdg_estpss_emedi_dataget() */
#include <engsrc/efunc/eeco/ess/estass.h>        /* vdg_estass_emedi_dataget() */
#endif /* JESS,JEEGMG_E */
#include <engsrc/efunc/eesta/eclrfld.h>          /* s2g_eclrfld_ekqstmxp,s2g_eclrfld_ekqstmxd */
#if JEEFI == u1g_EJCC_DUAL      /*�y�ޭ��INJ�z*/
#include <engsrc/efunc/eesta/estafrg.h>          /* vdg_estafrg_emedi_dataget() */
#endif /* JEEFI */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
#include <engsrc/efunc/eesta/erestahot.h>        /* vdg_erestahot_emedi_dataget() */
#include <engsrc/efunc/eemi/ecat/esjc/esjc.h>    /* vdg_esjc_emedi_dataget() */
#include <engsrc/efunc/edrblty/eknk/ekcst.h>     /* vdg_ekcst_emedi_dataget() */
#endif /* JEEFI */
#if (JEALLHV_E == u1g_EJCC_ALLHV_E) && (EMINJ_STAHV_MEDI == ON)      /*�yALL HV�zAND�yHV�n������v���g�p�z*/
#include <engsrc/efunc/eeco/ehv/estahv.h>        /* vdg_estahv_emedi_dataget2() */
#endif /* JEALLHV_E,EMINJ_STAHV_MEDI */
#if JEALLHV_E == u1g_EJCC_ALLHV_E               /*�yALL HV�z*/
#include <engsrc/efunc/eemi/ecat/ewupcat/ewupcat.h>  /* vdg_ewupcat_emedi_dataget(),f4g_ewupcat_ek1fptcat,f4g_ewupcat_ekpfitcat */
#endif /* JEALLHV_E */
#if JEEGMG_E == u1g_EJCC_HVCLUTCH_E             /*�yEG-MG�ׯ��z*/
#include <engsrc/efunc/efuncin/ectrlhv.h>        /* u1g_ectrlhv_exast */
#else                                           /* �yEG-MG�ׯ��ȊO�z */
#include <engsrc/estate/estepin/exst.h>          /* u1g_exst_exastefi */
#endif /* JEEGMG_E */
#if (JEALLHV_E == u1g_EJCC_ALLHV_E) && (JEEFI != u1g_EJCC_D4)       /*�yALL HV�zAND�yD-4�ȊO�z*/
#include <engsrc/efunc/eemi/eoutgs/erdpn/erdpn.h>    /* vdg_erdpn_emedi_dataget(),f4g_erdpn_ek1fpt,f4g_erdpn_ekpfit,f4g_erdpn_ekpfitn[] */
#endif /* JEALLHV_E,JEEFI */
#if JEEFI == u1g_EJCC_DUAL      /*�y�ޭ��INJ�z*/
 #if JEFFV != u1g_EJCC_NOT_USE  /*�yFFV����L�z*/
#include <engsrc/efunc/eemi/eactive/eactarefuel.h>   /* vdg_eactarefuel_emedi_dataget(),s2g_eactarefuel_ekpfit */
 #endif /* JEFFV */
#include <engsrc/efunc/eprotectf/efuel/eclrdepi.h>   /* vdg_eclrdepi_emedi_dataget() */
 #if JEPRDEMAND == u1g_EJCC_NOT_USE             /*�y�ϔR�����䖳�z*/
#include <engsrc/efunc/edrblty/estblcomb/efpldlv.h>  /* vdg_efpldlv_emedi_dataget() */
 #endif /* JEPRDEMAND */
 #if (JEOBDAFIMB_D == u1g_EJCC_USE) && (EMINJ_INJIMB_MEDI == ON)    /*�yAF�C���Բ����ݽ�L�zAND�y�����ݽ���̕��ː���v���g�p�z*/
#include <engsrc/efunc/eemi/eactive/einjimb.h>   /* vdg_einjimb_emedi_dataget() */
 #endif /* JEOBDAFIMB_D,EMINJ_INJIMB_MEDI */
 #if EMINJ_ACTOBD_MEDI == ON    /* �yOBD�v���ɂ�鱸è�ސ���v���g�p�z */
#include <engsrc/efunc/eemi/eactive/eactobd.h>   /* vdg_eactobd_emedi_dataget() */
 #endif /* EMINJ_ACTOBD_MEDI */
#include <engsrc/efunc/eemi/eactive/eactgaf.h>   /* vdg_eactgaf_emedi_dataget() */
#endif /* JEEFI */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
#include <engsrc/efunc/eeco/efc/ertnfc.h>        /* vdg_ertnfc_group00_dataget() */
 #if EMINJ_ACTLFG_MEDI == ON    /*�y�߰�����Ċw�K�ׂ̱̈�è�ސ���v���g�p�z*/
#include <engsrc/efunc/eemi/eactive/eactlfg.h>   /* vdg_eactlfg_emedi_dataget(),vdg_eactlfg_emedi_dataget2() */
 #endif /* EMINJ_ACTLFG_MEDI */
#include <engsrc/efunc/eemi/eoutgs/estratist.h>  /* vdg_estratist_emedi_dataget(),s2g_estratist_ekpfit */
#include <engsrc/efunc/edrblty/eknk/ekctrn.h>    /* vdg_ekctrn_emedi_dataget() */
#endif /* JEEFI */
#include <engsrc/efunc/edrblty/etrq/epwrup.h>    /* vdg_epwrup_emedi_dataget() */
#if JEEFI == u1g_EJCC_DUAL      /*�y�ޭ��INJ�z*/
#include <engsrc/efunc/eprotectf/efuel/edwnpr.h> /* vdg_edwnpr_emedi_dataget() */
#include <engsrc/efunc/eprotectf/efuel/erdvap.h> /* vdg_erdvap_emedi_dataget() */
#include <engsrc/efunc/eprotectf/efuel/eprvdil.h> /* vdg_eprvdil_emedi_dataget(),s2g_eprvdil_ekpfit */
#include <engsrc/efunc/efunctran/edthrctrl.h>    /* vdg_edthrctrl_emedi_dataget() */
#endif /* JEEFI */
#if (JENGPF_E != u1g_EJCC_NOT_USE) && (EMINJ_FCFRCTRL_MEDI == ON)  /*�yGPF�L�zAND�y1�C��FC����v���g�p�z*/
#include <engsrc/efunc/efunctran/efcfrctrl.h>    /* vdg_efcfrctrl_emedi_dataget() */
#endif /* JENGPF_E,EMINJ_FCFRCTRL_MEDI */
#if (JEMAT_BENCHI == u1g_EJCC_USE) || (JEMAT_BENCH_E == u1g_EJCC_USE)   /*�y�����K���p��ėL�zOR�y�����K��Ӱ�ޗL�z*/
#include <engsrc/efunc/eunusual/emat/ebench.h>   /* vdg_ebench_emedi_dataget() */
#endif /* JEMAT_BENCHI,JEMAT_BENCH_E */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
#include <engsrc/efunc/eprotectm/eexhaust/ecatotp.h> /* s2g_ecatotp_eainjadd */
#endif /* JEEFI */
#include <engsrc/efunc/eesta/ebstactr/ebstactr.h> /* st_EBSTACTR_EBSTACTR,vdg_ebstactr_ebstactr_dataget() */
#if ((JERMTCTR == u1g_EJCC_USE) || (JENVCTR == u1g_EJCC_USE)) && (JEMICN_E != u1g_EJCC_SUB_E) && (EMINJ_STACM_MEDI == ON)
  /* (�y�Ӱĺ��۰ٗL�zOR�y��޺��۰ٗL�z) AND�ySUB-CPU�ȊO�zAND�y�n���������オ�萧��v���g�p�z */
#include <engsrc/efunc/eesta/estacm.h>           /* vdg_estacm_emedi_dataget() */
#endif /* JERMTCTR,JENVCTR,JEMICN_E,EMINJ_STACM_MEDI */
#if JEEFI == u1g_EJCC_DUAL      /*�y�ޭ��INJ�z*/
 #if (JEOBDAFIMB_D == u1g_EJCC_USE) && (EMINJ_IMBRQ_MEDI == ON)  /*�yAF�C���Բ����ݽ�L�zAND�y�����ݽOBD�v���ɂ�鱸è�ސ���v���g�p�z*/
#include <engsrc/efunc/eemi/eactive/eimbrq.h>  /* vdg_eimbrq_emedi_dataget() */
 #endif /* JEOBDAFIMB_D,EMINJ_IMBRQ_MEDI */
 #if (JEOBDMF == u1g_EJCC_USE) && (EMINJ_MFINJRQ_MEDI == ON)  /*�y����OBD�L�zAND�y����OBD�v���ɂ�鱸è�ސ���v���g�p�z*/
#include <engsrc/efunc/eemi/eactive/emfinjrq.h>  /* vdg_emfinjrq_emedi_dataget() */
 #endif /* JEOBDMF,EMINJ_MFINJRQ_MEDI */
 #if (JEOBDFKG == u1g_EJCC_USE) && (EMINJ_FKGDRQ_MEDI == ON)  /* �y�R��OBD�L�zAND�y�R���nOBD�v���ɂ�鱸è�ސ���v���g�p�z */
#include <engsrc/efunc/eemi/eactive/efkgdrq.h>  /* vdg_efkgdrq_emedi_dataget() */
 #endif /* JEOBDFKG,EMINJ_FKGDRQ_MEDI */
#endif /* JEEFI */
#include <engsrc/etran/einj/ebinjctr.h>          /* st_EBINJCTR_EBINJCTR,vdg_ebinjctr_ebinjctr_dataget() */
#include <engsrc/etran/einj/einjadd.h>           /* s2g_einjadd_eainjpadd,s2g_einjadd_eainjdadd */
#include <engsrc/etran/einj/efasta/emkrichb.h>   /* vdg_emkrichb_ekrichxb_get(),s2g_emkrichb_ekrichxbcrt[] */
#include <engsrc/etran/einj/efcinjctr.h>         /* vdg_efcinjctr_emedi_dataget() */
#include <engsrc/etran/einj/ebinj/eainjcut.h>    /* s2g_eainjcut_eainjcutp,s2g_eainjcut_eainjcutd */
#if (((JEPLMLT_E == u1g_EJCC_USE) && (EMINJ_BINJPLCTR_MEDI == ON)) \
   || ((JEALLHV_E == u1g_EJCC_ALLHV_E) && (JEPLMLT_E == u1g_EJCC_USE) && (EMINJ_BINJPLCTR_WC_MEDI == ON)) \
   || ((JEEGMG_E == u1g_EJCC_HVPLGR_E) && (JEFFV == u1g_EJCC_NOT_USE) && (JEPLMLT_E == u1g_EJCC_USE) && (EMINJ_BINJPLCTR_STAHV_MEDI == ON)) \
   || (((JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)) && (JEPLMLT_E == u1g_EJCC_USE)))
   /* (�yPL������˗L�zAND�y�߰�����ĕ��˂�p������{���ː���v���g�p�z) */
   /* OR (�yALL HV�zAND�yPL������˗L�zAND�y�߰�����ĕ��˂�p������{���ː���(�G�}�g�@��)�v���g�p�z) */
   /* OR (�yEG-MG�V���ޱ�zAND�yFFV���䖳�zAND�yPL������˗L�zAND�y�߰�����ĕ��˂�p������{���ː���(HV�n�����䎞)�v���g�p�z) */
   /* OR ((�y�ޭ��INJ�zOR�yD-4�z) AND�yPL������˗L�z) */
#include <engsrc/etran/einj/ebinjplctr.h>        /* f4g_ebinjplctr_ekpfit,f4g_ebinjplctr_ekpfitn[],vdg_ebinjplctr_emedi_dataget() */
                                                 /* vdg_ebinjplctr_wc_emedi_dataget(),vdg_ebinjplctr_stahv_emedi_dataget() */
                                                 /* s2g_ebinjplctr_eprreq */ /* temp:�d�l�m�F�̓��e���f(DENG-STD-25017�D) */
#endif /* JEPLMLT_E,EMINJ_BINJPLCTR_MEDI,JEALLHV_E,EMINJ_BINJPLCTR_WC_MEDI,JEEGMG_E,JEFFV,EMINJ_BINJPLCTR_STAHV_MEDI,JEEFI */
#if (JEEFI == u1g_EJCC_D4) || (JEEFI == u1g_EJCC_DUAL) /*�yD-4�zOR�y�ޭ��INJ�z*/
#include <engsrc/etran/einj/ebinj/eainjdb.h>     /* s2g_eainjdb_eainjdb1 */
#include <engsrc/etran/einj/ebinj/eprhpb.h>      /* s2g_eprhpb_eprhpb */
#endif /* JEEFI */
#if JEPRDEMAND == u1g_EJCC_USE  /*�y�ϔR������L�z*/
#include <engsrc/eactmedi/einj/emprlp.h>                           /* s2g_emprlp_eprlp */
#else                           /*�y�ϔR�����䖳�z*/
#include <engsrc/eactmedi/einj/emqlp.h>                            /* s2g_emqlp_eqlp */
#endif /* JEPRDEMAND */

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

#if !defined u1g_EJCC_DUAL
#error "u1g_EJCC_DUAL is undeclared"
#endif

#if !defined u1g_EJCC_PORT
#error "u1g_EJCC_PORT is undeclared"
#endif

#if !defined u1g_EJCC_NOX
#error "u1g_EJCC_NOX is undeclared"
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

#if !defined JENOX
#error "JENOX is undeclared"
#endif

#if !defined u1g_EJCC_TWIN
#error "u1g_EJCC_TWIN is undeclared"
#endif

#if !defined JEEGR
#error "JEEGR is undeclared"
#endif

#if !defined u1g_EJCC_NCYL
#error "u1g_EJCC_NCYL is undeclared"
#endif

#if !defined JECOMBCCPT_E
#error "JECOMBCCPT_E is undeclared"
#endif

#if !defined u1g_EJCC_SPRAYG_E
#error "u1g_EJCC_SPRAYG_E is undeclared"
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

#if !defined JEPLMLT_E
#error "JEPLMLT_E is undeclared"
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
/* �^��`                                                            */
/*-------------------------------------------------------------------*/
/* ���˕����W��e�[�u�� */
typedef struct
{
    void (* pt_dataget)( st_EMINJ_EMINJ_DEF * ptt_store );  /* ���˕����f�[�^�擾�֐����ڽ */
    u1 u1_id;                                               /* lsb=1 :ID */
} st_EMINJ_EMINJ_TBL;

typedef struct
{
    void (* pt_dataget2)( st_EMINJ_EMINJ_BUF * ptt_store ); /* ���˕����f�[�^�擾�֐����ڽ */
    u1 u1_id;                                               /* lsb=1 :ID */
} st_EMINJ_EMINJ_TBL2;

/*-------------------------------------------------------------------*/
/* macro��`                                                         */
/*-------------------------------------------------------------------*/
/* $$$�}�N���萔_�W��_v4.11 */
#define s2s_EMINJ_KRICHI (s2g_glround((1.0)/((32.*2.)/128./256.)))      /* m=eminj,lsb=(32*2)/128/256,ofs=,unit=�{ :���ʕ␳�W�������l */

#if (JEEFI != u1g_EJCC_D4)                                              /* �yD-4�ȊO�z */
#define s2s_EMINJ_AINJP_VD (s2g_ELSB_AOP(120.03125))                    /* m=eminj,lsb=1024/128/256,ofs=,unit=BTDC :�߰ĕ��ˊJ�n���������l */
#define s2s_EMINJ_AINJP_MN (s2g_ELSB_AOP(120.03125))                    /* m=eminj,lsb=1024/128/256,ofs=,unit=BTDC :�|�[�g���ˊJ�n���������l */
#define s2s_EMINJ_AINJP_MX (s2g_ELSB_AOP(840.))                         /* m=eminj,lsb=1024/128/256,ofs=,unit=BTDC :�|�[�g���ˊJ�n��������l */
#define s2s_EMINJ_K1F_VD (s2g_glround((0.)/((1.*4.)/128./256.)))        /* m=eminj,lsb=(1*4)/128/256,ofs=,unit=�{ :1��ڕ��˗ʎZ�o�W�������l */
#endif                                                                  /* JEEFI */

#if (JEEFI == u1g_EJCC_PORT)                                            /* �y�߰āz */
#define s2s_EMINJ_AINJPADD_MN (s2g_ELSB_AOP(120.))                      /* m=eminj,lsb=1024/128/256,ofs=,unit=BTDC :�|�[�g�ǉ����ˊJ�n���������l */
#define s2s_EMINJ_AINJPADD_MX (s2g_ELSB_AOP(360.))                      /* m=eminj,lsb=1024/128/256,ofs=,unit=BTDC :�|�[�g�ǉ����ˊJ�n��������l */
#endif                                                                  /* JEEFI */

#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)                  /* �y�ޭ��INJ�zOR�yD-4�z */
#define s2s_EMINJ_AINJD_VD (s2g_ELSB_AOP(-180.))                        /* m=eminj,lsb=1024/128/256,ofs=,unit=BTDC :�������ˊJ�n���������l */

 #if (JECOMBCCPT_E == u1g_EJCC_SPRAYG_E)                                /* �y���ڰ�޲�ށz */
#define s2s_EMINJ_AINJD_MN (s2g_ELSB_AOP(-180.))                        /* m=eminj,lsb=1024/128/256,ofs=,unit=BTDC :�������ˊJ�n���������l */

 #else                                                                  /* �y���ڰ�޲�ވȊO�z */
#define s2s_EMINJ_AINJD_MN (s2g_ELSB_AOP(0.))                           /* m=eminj,lsb=1024/128/256,ofs=,unit=BTDC :�������ˊJ�n���������l */
 #endif                                                                 /* JECOMBCCPT_E */

#define s2s_EMINJ_AINJD_MX (s2g_ELSB_AOP(540.))                         /* m=eminj,lsb=1024/128/256,ofs=,unit=BTDC :�������ˊJ�n��������l */
#define s2s_EMINJ_AINJDADD_MN (s2g_ELSB_AOP(0.))                        /* m=eminj,lsb=1024/128/256,ofs=,unit=BTDC :�����ǉ����ˊJ�n���������l */
#define s2s_EMINJ_AINJDADD_MX (s2g_ELSB_AOP(360.))                      /* m=eminj,lsb=1024/128/256,ofs=,unit=BTDC :�����ǉ����ˊJ�n��������l */
#endif                                                                  /* JEEFI */

#define s4s_EMINJ_QINJI (s4g_glround((0.)/((4096.*1024.)/128./256./256./256.))) /* m=eminj,lsb=(4096*1024)/128/256/256/256,ofs=,unit=mg/st :���˗ʏ����l */
#define s4s_EMINJ_QINJ_VD (s4g_glround((0.)/((4096.*1024.)/128./256./256./256.)))   /* m=eminj,lsb=(4096*1024)/128/256/256/256,ofs=,unit=mg/st :���˗ʖ����l */
#define s4s_EMINJ_QINJ_MN (s4g_glround((0.)/((4096.*1024.)/128./256./256./256.)))   /* m=eminj,lsb=(4096*1024)/128/256/256/256,ofs=,unit=mg/st :���˗ʉ����l */
#define s4s_EMINJ_QINJ_MX (s4g_glround((2800.)/((4096.*1024.)/128./256./256./256.)))    /* m=eminj,lsb=(4096*1024)/128/256/256/256,ofs=,unit=mg/st :���˗ʏ���l */
#define s4s_EMINJ_QINJST_MN (s4g_glround((0.)/((4096.*1024.)/128./256./256./256.))) /* m=eminj,lsb=(4096*1024)/128/256/256/256,ofs=,unit=mg/st :�n�������˗ʉ����l */
#define s4s_EMINJ_QINJST_MX (s4g_glround((2800.)/((4096.*1024.)/128./256./256./256.)))  /* m=eminj,lsb=(4096*1024)/128/256/256/256,ofs=,unit=mg/st :�n�������˗ʏ���l */
#define s4s_EMINJ_QINJFLFIX_VD (s4g_glround((0.)/((4096.*1024.)/128./256./256./256.)))  /* m=eminj,lsb=(4096*1024)/128/256/256/256,ofs=,unit=mg/st :FL�Œ蕬�˗ʖ����l */
#define s4s_EMINJ_QINJPLFIX_VD (s4g_glround((0.)/((4096.*1024.)/128./256./256./256.)))  /* m=eminj,lsb=(4096*1024)/128/256/256/256,ofs=,unit=mg/st :PL�Œ蕬�˗ʖ����l */
#define s2s_EMINJ_K1F_MN (s2g_glround((0.)/((1.*4.)/128./256.)))        /* m=eminj,lsb=(1*4)/128/256,ofs=,unit=�{ :1��ڕ��˗ʎZ�o�W�������l */
#define s2s_EMINJ_K1F_MX (s2g_glround((1.)/((1.*4.)/128./256.)))        /* m=eminj,lsb=(1*4)/128/256,ofs=,unit=�{ :1��ڕ��˗ʎZ�o�W������l */
#define s2s_EMINJ_K1FN_MN (s2g_glround((0.)/((1.*4.)/128./256.)))       /* m=eminj,lsb=(1*4)/128/256,ofs=,unit=�{ :1��ڕ��˗ʎZ�o�W�������l(�o���N��) */
#define s2s_EMINJ_K1FN_MX (s2g_glround((1.)/((1.*4.)/128./256.)))       /* m=eminj,lsb=(1*4)/128/256,ofs=,unit=�{ :1��ڕ��˗ʎZ�o�W������l(�o���N��) */
#define s2s_EMINJ_K2F_MN (s2g_glround((0.)/((1.*4.)/128./256.)))        /* m=eminj,lsb=(1*4)/128/256,ofs=,unit=�{ :2��ڕ��˗ʎZ�o�W�������l */
#define s2s_EMINJ_K2F_MX (s2g_glround((1.)/((1.*4.)/128./256.)))        /* m=eminj,lsb=(1*4)/128/256,ofs=,unit=�{ :2��ڕ��˗ʎZ�o�W������l */
#define s2s_EMINJ_K2FN_MN (s2g_glround((0.)/((1.*4.)/128./256.)))       /* m=eminj,lsb=(1*4)/128/256,ofs=,unit=�{ :2��ڕ��˗ʎZ�o�W�������l(�o���N��) */
#define s2s_EMINJ_K2FN_MX (s2g_glround((1.)/((1.*4.)/128./256.)))       /* m=eminj,lsb=(1*4)/128/256,ofs=,unit=�{ :2��ڕ��˗ʎZ�o�W������l(�o���N��) */
#define s2s_EMINJ_K3F_MN (s2g_glround((0.)/((1.*4.)/128./256.)))        /* m=eminj,lsb=(1*4)/128/256,ofs=,unit=�{ :3��ڕ��˗ʎZ�o�W�������l */
#define s2s_EMINJ_K3F_MX (s2g_glround((1.)/((1.*4.)/128./256.)))        /* m=eminj,lsb=(1*4)/128/256,ofs=,unit=�{ :3��ڕ��˗ʎZ�o�W������l */
#define s2s_EMINJ_K3FN_MN (s2g_glround((0.)/((1.*4.)/128./256.)))       /* m=eminj,lsb=(1*4)/128/256,ofs=,unit=�{ :3��ڕ��˗ʎZ�o�W�������l(�o���N��) */
#define s2s_EMINJ_K3FN_MX (s2g_glround((1.)/((1.*4.)/128./256.)))       /* m=eminj,lsb=(1*4)/128/256,ofs=,unit=�{ :3��ڕ��˗ʎZ�o�W������l(�o���N��) */
#define s2s_EMINJ_KRCHREF_MN (s2g_glround((0.)/((32.*2.)/128./256.)))   /* m=eminj,lsb=(32*2)/128/256,ofs=,unit=�{ :���˗ʕ␳�W�������l */
#define s2s_EMINJ_KRCHREF_MX (s2g_glround((30.)/((32.*2.)/128./256.)))  /* m=eminj,lsb=(32*2)/128/256,ofs=,unit=�{ :���˗ʕ␳�W������l */

#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)                  /* �y�ޭ��INJ�zOR�yD-4�z */
#define u1s_EMINJ_RESTAHOT_ID ((u1)(((32.)/(1.))+0.5))                  /* m=eminj,lsb=1,ofs=,unit=- :�����Ďn������(ID) */
#define u1s_EMINJ_KCST_ID ((u1)(((34.)/(1.))+0.5))                      /* m=eminj,lsb=1,ofs=,unit=- :�n����ɯ��h�~����(ID) */
#endif                                                                  /* JEEFI */

#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)                  /* �y�ޭ��INJ�zOR�yD-4�z */
#define u1s_EMINJ_RTNFC_ID ((u1)(((54.)/(1.))+0.5))                     /* m=eminj,lsb=1,ofs=,unit=- :FC���A����(ID) */
#endif                                                                  /* JEEFI */

#if JEEFI == u1g_EJCC_DUAL                                              /* �y�ޭ��INJ�z */
#define u1s_EMINJ_CLRDEPI_ID ((u1)(((56.)/(1.))+0.5))                   /* m=eminj,lsb=1,ofs=,unit=- :����َ��ݼު�����ߏ�������(ID) */
#endif                                                                  /* JEEFI */

#if (JEEFI == u1g_EJCC_DUAL) && (JEPRDEMAND == u1g_EJCC_NOT_USE)        /* �y�ޭ��INJ�zAND�y�ϔR�����䖳�z */
#define u1s_EMINJ_FPLDLV_ID ((u1)(((60.)/(1.))+0.5))                    /* m=eminj,lsb=1,ofs=,unit=- :�ሳ�����ؓ��R��������𐧌�(ID) */
#endif                                                                  /* JEEFI JEPRDEMAND */

#if (JEOBDAFIMB_D == u1g_EJCC_USE) && (JEEFI == u1g_EJCC_DUAL) && (EMINJ_INJIMB_MEDI == ON) /* �yAF�C���Բ����ݽ�L�zAND�y�ޭ��INJ�zAND�y�����ݽ���̕��ː���v���g�p�z */
#define u1s_EMINJ_INJIMB_ID ((u1)(((72.)/(1.))+0.5))                    /* m=eminj,lsb=1,ofs=,unit=- :�����ݽ���̕��ː���(ID) */
#endif                                                                  /* JEOBDAFIMB_D JEEFI EMINJ_INJIMB_MEDI */

#if (JEEFI == u1g_EJCC_DUAL) && (JEFFV != u1g_EJCC_NOT_USE)             /* �y�ޭ��INJ�zAND�yFFV����L�z */
#define u1s_EMINJ_ACTAREFUEL_ID ((u1)(((74.)/(1.))+0.5))                /* m=eminj,lsb=1,ofs=,unit=- :������̕���������è�ސ���(ID) */
#endif                                                                  /* JEEFI JEFFV */

#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)                  /* �y�ޭ��INJ�zOR�yD-4�z */
#define u1s_EMINJ_KCTRN_ID ((u1)(((86.)/(1.))+0.5))                     /* m=eminj,lsb=1,ofs=,unit=- :���iɯ��h�~����(ID) */
#endif                                                                  /* JEEFI */

#if JEEFI == u1g_EJCC_DUAL                                              /* �y�ޭ��INJ�z */
#define u1s_EMINJ_RDVAP_ID ((u1)(((88.)/(1.))+0.5))                     /* m=eminj,lsb=1,ofs=,unit=- :�ް�߰�}������(ID) */
#define u1s_EMINJ_DWNPR_ID ((u1)(((90.)/(1.))+0.5))                     /* m=eminj,lsb=1,ofs=,unit=- :�R���ጸ����(ID) */
#endif                                                                  /* JEEFI */

#define u1s_EMINJ_PWRUP_ID ((u1)(((92.)/(1.))+0.5))                     /* m=eminj,lsb=1,ofs=,unit=- :�o�͐��\���㐧��(ID) */

#if JEEFI == u1g_EJCC_DUAL                                              /* �y�ޭ��INJ�z */
#define u1s_EMINJ_PRVDIL_ID ((u1)(((96.)/(1.))+0.5))                    /* m=eminj,lsb=1,ofs=,unit=- :��Ԏ���ߖh�~����(ID) */
#endif                                                                  /* JEEFI */

/* $$$�}�N���萔_�W��_v4.11 */
#define u4s_EMINJ_NORQDAT       ((u4)0x00000000U)   /* lsb=1 :����v������ */

/*-------------------------------------------------------------------*/
/* �ϐ���`                                                          */
/*-------------------------------------------------------------------*/
st_EMINJ_EMINJ stg_eminj_eminj;             /* �V���˕�������\���� */
                                            /* ���ӎ��� :�A�N�Z�X�ɂ͐�p�֐����g�p���邱�� */

st_EMINJ_EINJ stg_eminj_einj;               /* ���˕�������\���� */
                                            /* ���ӎ��� :�A�N�Z�X�ɂ͐�p�֐����g�p���邱�� */

u2 u2g_eminj_einjmodfix;                    /* m=eminj,lsb=1 :���݊m�蕬��Ӱ�� */
#if JEEFI != u1g_EJCC_D4        /*�yD-4�ȊO�z*/
f4 f4g_eminj_einjend;                       /* m=eminj,unit=BTDC :�|�[�g���ˏI������ */
s2 s2g_eminj_eainjpn[5];                    /* m=eminj,lsb=1024/128/256,unit=BTDC :�|�[�gn��ڕ��ˊJ�n����(���ˉ񐔔z��) */ /* 2025�N��5�񕬎˂܂ōl�����z��v�f��[5]�Ƃ��Ē�`���� */
f4 f4g_eminj_eainjpn[5];                    /* m=eminj,unit=BTDC :�|�[�gn��ڕ��ˊJ�n����(���ˉ񐔔z��) */ /* 2025�N��5�񕬎˂܂ōl�����z��v�f��[5]�Ƃ��Ē�`���� */
s4 s4g_eminj_eqinjstpn[5];                  /* m=eminj,lsb=(4096*1024)/128/256/256/256,unit=mg/st :�|�[�gn��ڎn�������˗ʁi���ˉ񐔔z��j */ /* 2025�N��5�񕬎˂܂ōl�����z��v�f��[5]�Ƃ��Ē�`���� */
f4 f4g_eminj_eqinjstpn[5];                  /* m=eminj,unit=mg/st :�|�[�gn��ڎn�������˗ʁi���ˉ񐔔z��j */ /* 2025�N��5�񕬎˂܂ōl�����z��v�f��[5]�Ƃ��Ē�`���� */
#endif /* JEEFI */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
f4 f4g_eminj_eainjd1fix;                    /* m=eminj,unit=BTDC :�m�蓛��1��ڕ��ˊJ�n���� */
f4 f4g_eminj_eainjd2fix;                    /* m=eminj,unit=BTDC :�m�蓛��2��ڕ��ˊJ�n���� */
f4 f4g_eminj_eainjd3fix;                    /* m=eminj,unit=BTDC :�m�蓛��3��ڕ��ˊJ�n���� */
f4 f4g_eminj_eainjd4fix;                    /* m=eminj,unit=BTDC :�m�蓛��4��ڕ��ˊJ�n���� */
f4 f4g_eminj_eainjd5fix;                    /* m=eminj,unit=BTDC :�m�蓛��5��ڕ��ˊJ�n���� */
f4 f4g_eminj_eainjd6fix;                    /* m=eminj,unit=BTDC :�m�蓛��6��ڕ��ˊJ�n���� */
s2 s2g_eminj_eainjdn[6];                    /* m=eminj,lsb=1024/128/256,unit=BTDC :����n��ڕ��ˊJ�n����(���ˉ񐔔z��) */ /* �n�����ɍő�6�񕬎�(�����̂�) */
f4 f4g_eminj_eainjdn[6];                    /* m=eminj,unit=BTDC :����n��ڕ��ˊJ�n����(���ˉ񐔔z��) */ /* �n�����ɍő�6�񕬎�(�����̂�) */
f4 f4g_eminj_eqinjstd1;                     /* m=eminj,unit=mg/st :����1��ڎn�������˗� */
f4 f4g_eminj_eqinjstd2;                     /* m=eminj,unit=mg/st :����2��ڎn�������˗� */
f4 f4g_eminj_eqinjstd3;                     /* m=eminj,unit=mg/st :����3��ڎn�������˗� */
f4 f4g_eminj_eqinjstd4;                     /* m=eminj,unit=mg/st :����4��ڎn�������˗� */
s4 s4g_eminj_eqinjstdn[6];                  /* m=eminj,lsb=(4096*1024)/128/256/256/256,unit=mg/st :����n��ڎn�������˗ʁi���ˉ񐔔z��j */ /* �n�����ɍő�6�񕬎�(�����̂�) */
f4 f4g_eminj_eqinjstdn[6];                  /* m=eminj,unit=mg/st :����n��ڎn�������˗ʁi���ˉ񐔔z��j */ /* �n�����ɍő�6�񕬎�(�����̂�) */
#endif /* JEEFI */
s4 s4g_eminj_eqfc[u1g_EJCC_NCYL];           /* m=eminj,lsb=(4096*1024)/128/256/256/256,unit=mg/st :FC�����˗� */
f4 f4g_eminj_eqfc[u1g_EJCC_NCYL];           /* m=eminj,unit=mg/st :FC�����˗� */
s2 s2g_eminj_ek1fn[u1g_EJCC_NOX];           /* m=eminj,lsb=(1*4)/128/256,unit=�{ :1��ڕ��˗ʎZ�o�W��(�o���N��) */
f4 f4g_eminj_ek1fn[u1g_EJCC_NOX];           /* m=eminj,unit=�{ :1��ڕ��˗ʎZ�o�W��(�o���N��) */
s2 s2g_eminj_ek2fn[u1g_EJCC_NOX];           /* m=eminj,lsb=(1*4)/128/256,unit=�{ :2��ڕ��˗ʎZ�o�W��(�o���N��) */
f4 f4g_eminj_ek2fn[u1g_EJCC_NOX];           /* m=eminj,unit=�{ :2��ڕ��˗ʎZ�o�W��(�o���N��) */
s2 s2g_eminj_ek3fn[u1g_EJCC_NOX];           /* m=eminj,lsb=(1*4)/128/256,unit=�{ :3��ڕ��˗ʎZ�o�W��(�o���N��)  */
f4 f4g_eminj_ek3fn[u1g_EJCC_NOX];           /* m=eminj,unit=�{ :3��ڕ��˗ʎZ�o�W��(�o���N��)  */
f4 f4g_eminj_ek1ffix;                       /* m=eminj,unit=�{ :�m��1��ڕ��˗ʎZ�o�W��(��ݸ�ԕ��ϒl(²ݾݻ)) */
f4 f4g_eminj_ek2ffix;                       /* m=eminj,unit=�{ :�m��2��ڕ��˗ʎZ�o�W��(��ݸ�ԕ��ϒl(²ݾݻ)) */
f4 f4g_eminj_ek3ffix;                       /* m=eminj,unit=�{ :�m��3��ڕ��˗ʎZ�o�W��(��ݸ�ԕ��ϒl(²ݾݻ)) */
s2 s2g_eminj_ekpfi;                         /* m=eminj,lsb=(1*4)/128/256,unit=�{ :�|�[�g���˗ʎZ�o�W�� */
f4 f4g_eminj_ekpfi;                         /* m=eminj,unit=�{ :�|�[�g���˗ʎZ�o�W�� */
s2 s2g_eminj_ekpfix;                        /* m=eminj,lsb=(1*4)/128/256,unit=�{ :�߰ĕ��˗ʎZ�o�W��(��ݸ�ԕ��ϒl(²ݾݻ)) */
f4 f4g_eminj_ekpfix;                        /* m=eminj,unit=�{ :�߰ĕ��˗ʎZ�o�W��(��ݸ�ԕ��ϒl(²ݾݻ)) */
s2 s2g_eminj_ekpfin[u1g_EJCC_NOX];          /* m=eminj,lsb=(1*4)/128/256,unit=�{ :�|�[�g���˗ʎZ�o�W��(�o���N��) */
f4 f4g_eminj_ekpfin[u1g_EJCC_NOX];          /* m=eminj,unit=�{ :�|�[�g���˗ʎZ�o�W��(�o���N��) */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
s2 s2g_eminj_eprreq;                        /* m=eminj,lsb=(32*2)/128/256,unit=MPa :�����|���v�ڕW�R�� */
f4 f4g_eminj_eprreq;                        /* m=eminj,unit=MPa :�����|���v�ڕW�R�� */
#endif /* JEEFI */
#if JEPRDEMAND == u1g_EJCC_NOT_USE          /*�y�ϔR�����䖳�z*/
s2 s2g_eminj_eqfreq;                        /* m=eminj,lsb=512/128/256,unit=L/h :�R���|���v�f�o���� */
#else                           /*�y�ϔR������L�z*/
s2 s2g_eminj_eprreql;                       /* m=eminj,lsb=1280/128/256,unit=kPa :�ሳ�|���v�ڕW�R�� */
f4 f4g_eminj_eprreql;                       /* m=eminj,unit=kPa :�ሳ�|���v�ڕW�R�� */
#endif /* JEPRDEMAND */
u1 u1g_eminj_einjmedislid;                  /* m=eminj,lsb=1 :���˕������f���ʎq */
s2 s2g_eminj_ekrichx;                       /* m=eminj,lsb=(32*2)/128/256,unit=�{ :���˗ʕ␳�W�� */
f4 f4g_eminj_ekrichx;                       /* m=eminj,unit=�{ :���˗ʕ␳�W�� */
s2 s2g_eminj_ekrchref[u1g_EJCC_NOX];        /* m=eminj,lsb=(32*2)/128/256,unit=�{ :���˗ʕ␳�W��(�o���N��) */
f4 f4g_eminj_ekrchref[u1g_EJCC_NOX];        /* m=eminj,unit=�{ :���˗ʕ␳�W��(�o���N��) */
#if JEEFI == u1g_EJCC_DUAL      /*�y�ޭ��INJ�z*/
s2 s2g_eminj_ekpfit;                        /* m=eminj,lsb=(1*4)/128/256,unit=�{ :�ڕW�|�[�g���˗ʎZ�o�W�� */
s2 s2g_eminj_ekpfitn[u1g_EJCC_NOX];         /* m=eminj,lsb=(1*4)/128/256,unit=�{ :�ڕW�|�[�g���˗ʎZ�o�W��(�o���N��) */
f4 f4g_eminj_ekpfitn[u1g_EJCC_NOX];         /* m=eminj,unit=�{ :�ڕW�|�[�g���˗ʎZ�o�W��(�o���N��) */
 #if JEEGR == u1g_EJCC_USE      /*�yEGR����L�z*/
f4 f4g_eminj_ekpfiegrn[u1g_EJCC_NOX];       /* m=eminj,unit=�{ :EGR-ON���̖ڕW�|�[�g���˗ʎZ�o�W��(�o���N��) */
 #endif /* JEEGR */
#endif /* JEEFI */
s4 s4g_eminj_eqinjflfix[8];                 /* m=eminj,lsb=(4096*1024)/128/256/256/256,unit=mg/st :FL�Œ蕬�˗� */
f4 f4g_eminj_eqinjflfix[8];                 /* m=eminj,unit=mg/st :FL�Œ蕬�˗� */
s4 s4g_eminj_eqinjplfix[8];                 /* m=eminj,lsb=(4096*1024)/128/256/256/256,unit=mg/st :PL�Œ蕬�˗� */
f4 f4g_eminj_eqinjplfix[8];                 /* m=eminj,unit=mg/st :PL�Œ蕬�˗� */

static u1 u1s_eminj_estpri;                 /* lsb=1 :�n�����v���̗D��x */
static u1 u1s_eminj_estpri2;                /* lsb=1 :�n�����v��2�̗D��x */
static u1 u1s_eminj_estprir;                /* lsb=1 :�n�����v���Ǝn�����v��2����̗D��x���� */
static u1 u1s_eminj_eastpri;                /* lsb=1 :�n����v���̗D��x */
static u1 u1s_eminj_eastpri2;               /* lsb=1 :�n����v��2�̗D��x */
static u1 u1s_eminj_exastmedi;              /* lsb=1 :�n����v�����⋖�t���O */
static u4 u4s_eminj_erqdat[2];              /* lsb=1 :�v�����˕����v���L���ʎq */
static u1 u1s_eminj_epri;                   /* lsb=1 :�ʏ�v���̗D��x */
static u1 u1s_eminj_epri2;                  /* lsb=1 :�ʏ�v��2�̗D��x */
static u1 u1s_eminj_exasto;                 /* lsb=1 :�n����t���O(�O��l) */
static u1 u1s_eminj_exast_lch;              /* lsb=1 :�n����t���O(���b�`�p(t_xast)) */
static u1 u1s_eminj_exnercdfew;             /* lsb=1 :NE�^�X�N������t���O */
static u1 u1s_eminj_eprisel_fix;            /* lsb=1 :�ō��D��x */
static u1 u1s_eminj_eprifix;                /* lsb=1 :�m��D��x(�@�\��͗p������ϐ�) */

/* �W��Ώە��i��dataget�֐���������Q�ƂƂȂ���̂�NRAM�ɑޔ������b�p�[�֐��ɂăA�N�Z�X���� */
/* 8msm���ŏW��Ώۂ�get�֐��R�[����1�x�ɂ��e�[�u���ԂŃf�[�^�̐������Ƃ� */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)          /*�y�ޭ��INJ�zOR�yD-4�z*/
static st_EMINJ_EMINJ_DEF sts_eminj_erestahot_data;
#endif /* JEEFI */
#if (JEALLHV_E == u1g_EJCC_ALLHV_E) && (JEEFI != u1g_EJCC_D4)       /*�yALL HV�zAND�yD-4�ȊO�z*/
static st_EMINJ_EMINJ_DEF sts_eminj_erdpn_data;
#endif /* JEALLHV_E,JEEFI */

/* ���j�^�ϐ���` */
#ifdef M_EMINJ       /* �f�o�b�O���[�h */
#if JEEFI != u1g_EJCC_D4        /*�yD-4�ȊO�z*/
static s2 s2s_eminj_einjend_mon;            /* lsb=1024/128/256,unit=BTDC :�|�[�g���ˏI������(���j�^�p) */
static s2 s2s_eminj_eminj_einjend_mon;      /* lsb=1024/128/256,unit=BTDC :�|�[�g���ˏI������(���j�^�p) */
#endif /* JEEFI */
/* u2s_eminj_einjmod_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* s2s_eminj_eainjp1_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* f4s_eminj_eainjp1_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* s2s_eminj_eainjp2_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* f4s_eminj_eainjp2_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* s2s_eminj_eainjp3_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* f4s_eminj_eainjp3_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* s2s_eminj_eainjp4_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* f4s_eminj_eainjp4_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* s2s_eminj_eainjcutp_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* f4s_eminj_eainjcutp_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* s2s_eminj_eainjd1_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* f4s_eminj_eainjd1_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* s2s_eminj_eainjd2_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* f4s_eminj_eainjd2_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* s2s_eminj_eainjd3_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* f4s_eminj_eainjd3_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* s2s_eminj_eainjd4_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* f4s_eminj_eainjd4_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* s2s_eminj_eainjcutd_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* f4s_eminj_eainjcutd_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* s2s_eminj_eainjpadd_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* s2s_eminj_eainjdadd_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* s4s_eminj_eqinjstp1_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* f4s_eminj_eqinjstp1_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* s4s_eminj_eqinjstp2_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* f4s_eminj_eqinjstp2_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* s4s_eminj_eqinjstp3_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* f4s_eminj_eqinjstp3_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* s4s_eminj_eqinjstp4_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* f4s_eminj_eqinjstp4_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* s4s_eminj_eqinjstd1_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* s4s_eminj_eqinjstd2_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* s4s_eminj_eqinjstd3_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* s4s_eminj_eqinjstd4_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* s4s_eminj_eqinjexp_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* f4s_eminj_eqinjexp_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* s2s_eminj_ek1f_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* f4s_eminj_ek1f_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* s2s_eminj_ek2f_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* f4s_eminj_ek2f_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* s2s_eminj_ek3f_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* f4s_eminj_ek3f_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* u1s_eminj_exqinjast_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* u1s_eminj_explreq_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* f4s_eminj_ekpfit_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* s2s_eminj_ek1fpt_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* f4s_eminj_ek1fpt_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* f4s_eminj_ekpfiegr_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* f4s_eminj_einjend_mon�́Af4g_eminj_einjend�ő�p�\ */
/* f4s_eminj_eqinjstd1_mon�́Af4g_eminj_eqinjstd1�ő�p�\ */
/* f4s_eminj_eqinjstd2_mon�́Af4g_eminj_eqinjstd2�ő�p�\ */
/* f4s_eminj_eqinjstd3_mon�́Af4g_eminj_eqinjstd3�ő�p�\ */
/* f4s_eminj_eqinjstd4_mon�́Af4g_eminj_eqinjstd4�ő�p�\ */
/* s2s_eminj_ekpfit_mon�́As2g_eminj_ekpfit�ő�p�\ */
/* stt_injdat.u1_exqinjast�̃��j�^�ϐ��́Au1s_eminj_exqinjast_mon�ő�p�\ */
/* s4s_eminj_eqfc_mon[u1g_EJCC_NCYL]�́As4g_eminj_eqfc[u1g_EJCC_NCYL]�ő�p�\ */
/* f4s_eminj_eqfc_mon[u1g_EJCC_NCYL]�́Af4g_eminj_eqfc[u1g_EJCC_NCYL]�ő�p�\ */
/* s2s_eminj_ek1fn_mon[u1g_EJCC_NOX]�́As2g_eminj_ek1fn[u1g_EJCC_NOX]�ő�p�\ */
/* f4s_eminj_ek1fn_mon[u1g_EJCC_NOX]�́Af4g_eminj_ek1fn[u1g_EJCC_NOX]�ő�p�\ */
/* s2s_eminj_ek2fn_mon[u1g_EJCC_NOX]�́As2g_eminj_ek2fn[u1g_EJCC_NOX]�ő�p�\ */
/* f4s_eminj_ek2fn_mon[u1g_EJCC_NOX]�́Af4g_eminj_ek2fn[u1g_EJCC_NOX]�ő�p�\ */
/* s2s_eminj_ek3fn_mon[u1g_EJCC_NOX]�́As2g_eminj_ek3fn[u1g_EJCC_NOX]�ő�p�\ */
/* f4s_eminj_ek3fn_mon[u1g_EJCC_NOX]�́Af4g_eminj_ek3fn[u1g_EJCC_NOX]�ő�p�\ */
/* s2s_eminj_ekrchref_mon[u1g_EJCC_NOX]�́As2g_eminj_ekrchref[u1g_EJCC_NOX]�ő�p�\ */
/* f4s_eminj_ekrchref_mon[u1g_EJCC_NOX]�́Af4g_eminj_ekrchref[u1g_EJCC_NOX]�ő�p�\ */
/* s2s_eminj_ekpfitn_mon[u1g_EJCC_NOX]�́As2g_eminj_ekpfitn[u1g_EJCC_NOX]�ő�p�\ */
/* f4s_eminj_ekpfitn_mon[u1g_EJCC_NOX]�́Af4g_eminj_ekpfitn[u1g_EJCC_NOX]�ő�p�\ */
/* f4s_eminj_ekpfiegrn_mon[u1g_EJCC_NOX]�́Af4g_eminj_ekpfiegrn[u1g_EJCC_NOX]�ő�p�\ */
/* u2s_eminj_eminj_einjmod_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* u4s_eminj_eminj_einjptn_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* s2s_eminj_eminj_eainjcutp_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* f4s_eminj_eminj_eainjcutp_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* s2s_eminj_eminj_eainjcutd_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* f4s_eminj_eminj_eainjcutd_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* s2s_eminj_eminj_eainjpadd_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* s2s_eminj_eminj_eainjdadd_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* s4s_eminj_eminj_eqinjexp_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* f4s_eminj_eminj_eqinjexp_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* u1s_eminj_eminj_exqinjast_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* u1s_eminj_eminj_explreq_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* f4s_eminj_eminj_ekpfit_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* s2s_eminj_eminj_ek1fpt_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* f4s_eminj_eminj_ek1fpt_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* f4s_eminj_eminj_ekpfiegr_mon�́Avdg_eminj_8msm�ł̂ݎQ�Ƃ̂��ߊ֐����Œ�` */
/* s2s_eminj_eminj_eainjpn_mon[5]�́As2g_eminj_eainjpn[5]�ő�p�\ */
/* f4s_eminj_eminj_eainjpn_mon[5]�́Af4g_eminj_eainjpn[5]�ő�p�\ */
/* f4s_eminj_eminj_einjend_mon�́Af4g_eminj_einjend�ő�p�\ */
/* s2s_eminj_eminj_eainjdn_mon[6]�́As2g_eminj_eainjdn[6]�ő�p�\ */
/* f4s_eminj_eminj_eainjdn_mon[6]�́Af4g_eminj_eainjdn[6]�ő�p�\ */
/* s4s_eminj_eminj_eqinjstpn_mon[5]�́As4g_eminj_eqinjstpn[5]�ő�p�\ */
/* f4s_eminj_eminj_eqinjstpn_mon[5]�́Af4g_eminj_eqinjstpn[5]�ő�p�\ */
/* s4s_eminj_eminj_eqinjstdn_mon[6]�́As4g_eminj_eqinjstdn[6]�ő�p�\ */
/* f4s_eminj_eminj_eqinjstdn_mon[6]�́Af4g_eminj_eqinjstdn[6]�ő�p�\ */
/* s4s_eminj_eminj_eqfc_mon[u1g_EJCC_NCYL]�́As4g_eminj_eqfc[u1g_EJCC_NCYL]�ő�p�\ */
/* f4s_eminj_eminj_eqfc_mon[u1g_EJCC_NCYL]�́Af4g_eminj_eqfc[u1g_EJCC_NCYL]�ő�p�\ */
/* s2s_eminj_eminj_ek1fn_mon[u1g_EJCC_NOX]�́As2g_eminj_ek1fn[u1g_EJCC_NOX]�ő�p�\ */
/* f4s_eminj_eminj_ek1fn_mon[u1g_EJCC_NOX]�́Af4g_eminj_ek1fn[u1g_EJCC_NOX]�ő�p�\ */
/* s2s_eminj_eminj_ek2fn_mon[u1g_EJCC_NOX]�́As2g_eminj_ek2fn[u1g_EJCC_NOX]�ő�p�\ */
/* f4s_eminj_eminj_ek2fn_mon[u1g_EJCC_NOX]�́Af4g_eminj_ek2fn[u1g_EJCC_NOX]�ő�p�\ */
/* s2s_eminj_eminj_ek3fn_mon[u1g_EJCC_NOX]�́As2g_eminj_ek3fn[u1g_EJCC_NOX]�ő�p�\ */
/* f4s_eminj_eminj_ek3fn_mon[u1g_EJCC_NOX]�́Af4g_eminj_ek3fn[u1g_EJCC_NOX]�ő�p�\ */
/* s2s_eminj_eminj_ekrchref_mon[u1g_EJCC_NOX]�́As2g_eminj_ekrchref[u1g_EJCC_NOX]�ő�p�\ */
/* f4s_eminj_eminj_ekrchref_mon[u1g_EJCC_NOX]�́Af4g_eminj_ekrchref[u1g_EJCC_NOX]�ő�p�\ */
/* stt_injdat2.u1_exqinjast�̃��j�^�ϐ��́Au1s_eminj_eminj_exqinjast_mon�ő�p�\ */
/* s2s_eminj_eminj_ekpfit_mon�́As2g_eminj_ekpfit�ő�p�\ */
/* s2s_eminj_eminj_ekpfitn_mon[u1g_EJCC_NOX]�́As2g_eminj_ekpfitn[u1g_EJCC_NOX]�ő�p�\ */
/* f4s_eminj_eminj_ekpfitn_mon[u1g_EJCC_NOX]�́Af4g_eminj_ekpfitn[u1g_EJCC_NOX]�ő�p�\ */
/* f4s_eminj_eminj_ekpfiegrn_mon[u1g_EJCC_NOX]�́Af4g_eminj_ekpfiegrn[u1g_EJCC_NOX]�ő�p�\ */
/* s4s_eminj_eminj_eqinjflfix_mon[8]�́As4g_eminj_eqinjflfix[8]�ő�p�\ */
/* f4s_eminj_eminj_eqinjflfix_mon[8]�́Af4g_eminj_eqinjflfix[8]�ő�p�\ */
/* s4s_eminj_eminj_eqinjplfix_mon[8]�́As4g_eminj_eqinjplfix[8]�ő�p�\ */
/* f4s_eminj_eminj_eqinjplfix_mon[8]�́Af4g_eminj_eqinjplfix[8]�ő�p�\ */
#endif /* M_EMINJ */

/*-------------------------------------------------------------------*/
/* �֐���prototype�錾                                               */
/*-------------------------------------------------------------------*/
static void vds_eminj_eminj_hpri( st_EMINJ_EMINJ_DEF *ptt_datsel, const st_EMINJ_EMINJ_DEF *ptt_datdft, st_EMINJ_EMINJ_BUF *ptt_datsel2, const st_EMINJ_EMINJ_BUF *ptt_datdft2 );       /* ���˃��[�h�̒���(�D��x�I��) */
static void vds_eminj_eminjlmt_hpri( st_EMINJ_EMINJ_DEF *ptt_datsel, const st_EMINJ_EMINJ_DEF *ptt_datdft, st_EMINJ_EMINJ_BUF *ptt_datsel2, const st_EMINJ_EMINJ_BUF *ptt_datdft2 );    /* ���␧�񎞂̕��˃��[�h�̒���(�D��x�I��) */
static void vds_eminj_einj_dataset( st_EMINJ_EINJ *ptt_store, const st_EMINJ_EINJ *ptt_data, u1 u1t_xnercdfew ); /* �f�[�^�X�V���� */
static void vds_eminj_einj_datacopy( st_EMINJ_EMINJ_DEF *ptt_data, const st_EMINJ_EMINJ_DEF *ptt_copy );         /* �W��Ώۗp�\���̃f�[�^�R�s�[���� */
static void vds_eminj_eminj_dataset( st_EMINJ_EMINJ *ptt_store, const st_EMINJ_EMINJ *ptt_data, u1 u1t_xnercdfew );   /* �f�[�^�X�V���� */
static void vds_eminj_einj_datacopy2( st_EMINJ_EMINJ_BUF *ptt_data, const st_EMINJ_EMINJ_BUF *ptt_copy );             /* �W��Ώۗp�\���̃f�[�^�R�s�[���� */
static void vds_eminj_einj_dataconv( st_EMINJ_EMINJ_BUF *ptt_data_new, const st_EMINJ_EMINJ_DEF *ptt_data_old );      /* �W��Ώۗp�����V�\���̃f�[�^�ڍs���� */
static void vds_eminj_einj_dataconv_rev( st_EMINJ_EMINJ_DEF *ptt_data_old, const st_EMINJ_EMINJ_BUF *ptt_data_new );  /* �W��Ώۗp�V�����\���̃f�[�^�ڍs���� */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)              /*�y�ޭ��INJ�zOR�yD-4�z*/
static void vds_eminj_erestahot_rap_dataget( st_EMINJ_EMINJ_DEF *ptt_store );
#endif /* JEEFI */
#if (JEALLHV_E == u1g_EJCC_ALLHV_E) && (JEEFI != u1g_EJCC_D4)       /*�yALL HV�zAND�yD-4�ȊO�z*/
static void vds_eminj_erdpn_rap_dataget( st_EMINJ_EMINJ_DEF *ptt_store );
#endif /* JEALLHV_E,JEEFI */
static void vds_eminj_dummy_emedi_dataget( st_EMINJ_EMINJ_DEF *ptt_store );
static void vds_eminj_dummy_emedi_dataget2( st_EMINJ_EMINJ_BUF *ptt_store );

/*-------------------------------------------------------------------*/
/* const data��`                                                    */
/*-------------------------------------------------------------------*/
/* �v�f�� */
#define u1s_EMINJ_EMINJ_NUM     ((u1)(sizeof(sts_eminj_eminj_tbl)/sizeof(sts_eminj_eminj_tbl[0])))          /* lsb=256/256,unit=�� :���˕����̗D��x�I��v�f�� */
#define u1s_EMINJ_EMINJLMT_NUM  ((u1)(sizeof(sts_eminj_eminjlmt_tbl)/sizeof(sts_eminj_eminjlmt_tbl[0])))    /* lsb=256/256,unit=�� :���˕����̗D��x�I��v�f��(���␧��) */
#define u1s_EMINJ_EMINJ_NUM2    ((u1)((u1)(sizeof(sts_eminj_eminj_tbl2)/sizeof(sts_eminj_eminj_tbl2[0])) - (u1)1))       /* lsb=256/256,unit=�� :���˕����̗D��x�I��v�f�� -1DUMMY */
#define u1s_EMINJ_EMINJLMT_NUM2 ((u1)((u1)(sizeof(sts_eminj_eminjlmt_tbl2)/sizeof(sts_eminj_eminjlmt_tbl2[0])) - (u1)1)) /* lsb=256/256,unit=�� :���˕����̗D��x�I��v�f��(���␧��) -1DUMMY */
#define u1s_EMINJ_EMINJST_NUM   ((u1)((u1)(sizeof(sts_eminj_eminjst_tbl)/sizeof(sts_eminj_eminjst_tbl[0])) - (u1)1))     /* lsb=256/256,unit=�� :�n�����v���D��x�v�f�� -1DUMMY */
#define u1s_EMINJ_EMINJST_NUM2  ((u1)((u1)(sizeof(sts_eminj_eminjst_tbl2)/sizeof(sts_eminj_eminjst_tbl2[0])) - (u1)1))   /* lsb=256/256,unit=�� :�n�����v���D��x�v�f�� -1DUMMY */
#define u1s_EMINJ_EMINJAST_NUM  ((u1)((u1)(sizeof(sts_eminj_eminjast_tbl)/sizeof(sts_eminj_eminjast_tbl[0])) - (u1)1))   /* lsb=256/256,unit=�� :�n����v���D��x�v�f�� -1DUMMY */
#define u1s_EMINJ_EMINJAST_NUM2 ((u1)((u1)(sizeof(sts_eminj_eminjast_tbl2)/sizeof(sts_eminj_eminjast_tbl2[0])) - (u1)1)) /* lsb=256/256,unit=�� :�n����v���D��x�v�f�� -1DUMMY */

/*-------------------------------------------------------------------*/
/* �֐�                                                              */
/*-------------------------------------------------------------------*/
/*********************************************************************/
/*  �֐���        | vdg_eminj_pwon( )                                */
/*  �������e      | �����l�ݒ�                                       */
/*  ����^�C�~���O| pwon                                             */
/*  ����          | �Ȃ�                                             */
/*  �߂�l        | �Ȃ�                                             */
/*  ���ӎ���      |                                                  */
/*********************************************************************/
void
vdg_eminj_pwon( void )
{
    u1 u1t_mox;    /* lsb=1 :���C���Z���T�� */
    u1 u1t_nox_c;  /* lsb=1 :���C���Z���T�� */
    s2 s2t_kpfi;   /* lsb=(1*4)/128/256,unit=�{ :�|�[�g���˗ʎZ�o�W�� */
    s2 s2t_kpfix;  /* lsb=(1*4)/128/256,unit=�{ :�߰ĕ��˗ʎZ�o�W��(��ݸ�ԕ��ϒl(²ݾݻ)) */
    s2 s2t_kpfin[u1g_EJCC_NOX]; /* lsb=(1*4)/128/256,unit=�{ :�|�[�g���˗ʎZ�o�W��(�o���N��) */
#if JEPRDEMAND == u1g_EJCC_USE       /*�y�ϔR������L�z*/
    s2 s2t_prreql; /* lsb=1280/128/256,unit=kPa :�ሳ�|���v�ڕW�R�� */
#endif /* JEPRDEMAND */
    st_EMINJ_EINJ stt_injdat = { 0 };               /* �������\���̃��[�N(�ꊇ������) */
    st_EMINJ_EMINJ stt_injdat2 = { 0 };             /* �������\���̃��[�N(�ꊇ������) */
#if JEEFI != u1g_EJCC_D4        /*�yD-4�ȊO�z*/
    st_EBINJCTR_EBINJCTR stt_binjctrdat = { 0 };    /* �������\���̃��[�N(�ꊇ������) */
#endif /* JEEFI */

    u1t_nox_c = u1g_ejcc_NOX;

    for ( u1t_mox = (u1)0U; u1t_mox < u1t_nox_c; u1t_mox++ )
    {
        stt_injdat.s2_ekrchref[u1t_mox] = s2s_EMINJ_KRICHI;
        stt_injdat.f4_ekrchref[u1t_mox] = (f4)(stt_injdat.s2_ekrchref[u1t_mox]) * (f4)((32.*2.)/128./256.);
        stt_injdat2.s2_ekrchref[u1t_mox] = stt_injdat.s2_ekrchref[u1t_mox];
        stt_injdat2.f4_ekrchref[u1t_mox] = stt_injdat.f4_ekrchref[u1t_mox];
    }
    s2g_eminj_ekrichx = s2s_EMINJ_KRICHI;
    f4g_eminj_ekrichx = (f4)s2s_EMINJ_KRICHI * (f4)((32.*2.)/128./256.);
#if JEEFI == u1g_EJCC_PORT      /*�y�߰āz*/
    s2t_kpfi = (s2)(((1.)/((1.*4.)/128./256.))+0.5);
    s2t_kpfix = (s2)(((1.)/((1.*4.)/128./256.))+0.5);
    for ( u1t_mox = (u1)0U; u1t_mox < u1t_nox_c; u1t_mox++ )
    {
        s2t_kpfin[u1t_mox] = (s2)(((1.)/((1.*4.)/128./256.))+0.5);
    }
#else                           /*�y�߰ĈȊO�z*/
    s2t_kpfi = (s2)(((0.)/((1.*4.)/128./256.))+0.5);
    s2t_kpfix = (s2)(((0.)/((1.*4.)/128./256.))+0.5);
    for ( u1t_mox = (u1)0U; u1t_mox < u1t_nox_c; u1t_mox++ )
    {
        s2t_kpfin[u1t_mox] = (s2)(((0.)/((1.*4.)/128./256.))+0.5);
    }
#endif /* JEEFI */
    s2g_eminj_ekpfi = s2t_kpfi;
    f4g_eminj_ekpfi = (f4)s2t_kpfi * (f4)((1.*4.)/128./256.);
    s2g_eminj_ekpfix = s2t_kpfix;
    f4g_eminj_ekpfix = (f4)s2t_kpfix * (f4)((1.*4.)/128./256.);
    for ( u1t_mox = (u1)0U; u1t_mox < u1t_nox_c; u1t_mox++ )
    {
        s2g_eminj_ekpfin[u1t_mox] = s2t_kpfin[u1t_mox];
        f4g_eminj_ekpfin[u1t_mox] = (f4)s2t_kpfin[u1t_mox] * (f4)((1.*4.)/128./256.);
    }
#if JEEFI != u1g_EJCC_D4        /*�yD-4�ȊO�z*/
    vdg_ebinjctr_ebinjctr_dataget( &stt_binjctrdat );   /* �������f�[�^�擾 */

    stt_injdat.s2_einjend = stt_binjctrdat.s2_einjendb;
    stt_injdat.f4_einjend = (f4)(stt_injdat.s2_einjend) * (f4)(1024./128./256.);
    stt_injdat2.s2_einjend = stt_injdat.s2_einjend;
    stt_injdat2.f4_einjend = stt_injdat.f4_einjend;
#endif /* JEEFI */
#if JEPRDEMAND == u1g_EJCC_USE       /*�y�ϔR������L�z*/
    s2t_prreql = s2g_emprlp_eprlp;
    s2g_eminj_eprreql = s2t_prreql;
    f4g_eminj_eprreql = (f4)s2t_prreql * (f4)(1280./128./256.);
#endif /* JEPRDEMAND */
    vds_eminj_einj_dataset( &stg_eminj_einj, &stt_injdat, (u1)ON );
    vds_eminj_eminj_dataset( &stg_eminj_eminj, &stt_injdat2, (u1)ON );

#ifdef M_EMINJ       /* �f�o�b�O���[�h */
 #if JEEFI != u1g_EJCC_D4        /*�yD-4�ȊO�z*/
    s2s_eminj_einjend_mon = stt_injdat.s2_einjend;
    s2s_eminj_eminj_einjend_mon = stt_injdat2.s2_einjend;
 #endif /* JEEFI */
    /* s2s_eminj_ekrchref_mon[u1g_EJCC_NOX]�́As2g_eminj_ekrchref[u1g_EJCC_NOX]�ő�p�\ */
    /* f4s_eminj_ekrchref_mon[u1g_EJCC_NOX]�́Af4g_eminj_ekrchref[u1g_EJCC_NOX]�ő�p�\ */
    /* f4s_eminj_einjend_mon�́Af4g_eminj_einjend�ő�p�\ */
    /* s2s_eminj_eminj_ekrchref_mon[u1g_EJCC_NOX]�́As2g_eminj_ekrchref[u1g_EJCC_NOX]�ő�p�\ */
    /* f4s_eminj_eminj_ekrchref_mon[u1g_EJCC_NOX]�́Af4g_eminj_ekrchref[u1g_EJCC_NOX]�ő�p�\ */
    /* f4s_eminj_eminj_einjend_mon�́Af4g_eminj_einjend�ő�p�\ */

    /* �����l��0����������ϐ��́A���j�^�ϐ��ւ̊i�[�s�v */

#endif /* M_EMINJ */
}

/*********************************************************************/
/*  �֐���        | vdg_eminj_8msm( )                                */
/*  �������e      | ���˗v���̒��⏈��                               */
/*  ����^�C�~���O| 8msm                                             */
/*  ����          | �Ȃ�                                             */
/*  �߂�l        | �Ȃ�                                             */
/*  ���ӎ���      |                                                  */
/*********************************************************************/
void
vdg_eminj_8msm( void )
{
    u1 u1t_xnercdfew;           /* lsb=1 :NE�^�X�N������t���O */
    u1 u1t_injmedislid;         /* lsb=1 :���˕������f���ʎq */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    s4 s4t_kqstmxd;             /* lsb=128/128/256,unit=�{ :�����n�������˗ʐ����W�� */
    u2 u2t_injmod;              /* lsb=1 :���˃��[�h */
    u2 u2t_injmod2;             /* lsb=1 :���˃��[�h */
    s2 s2t_ainjdadd;            /* lsb=1024/128/256,unit=BTDC :�����ǉ����ˊJ�n���� */
    s2 s2t_ainjadd;             /* lsb=1024/128/256,unit=BTDC :�u��OT�h�~�ǉ����ˊJ�n���� */
    s2 s2t_ainjdaddmin;         /* lsb=1024/128/256,unit=BTDC :�����ǉ����ˊJ�n����(�ŏ��l�I��p) */
    u2 u2t_binjmodmsk00F0;      /* lsb=1 :ebinjctr�̕��˃��[�h��0x00F0�Ń}�X�N�����l */
    u2 u2t_binjmodmsk0F0F;      /* lsb=1 :ebinjctr�̕��˃��[�h��0x0F0F�Ń}�X�N�����l */
    s2 s2t_ainjdb1;             /* lsb=1024/128/256,unit=BTDC :��{�������ˊJ�n���� */
    s2 s2t_ainjcutd;            /* lsb=1024/128/256,unit=BTDC :�������ˋ�����Ď��� */
    s2 s2t_prhpb;               /* lsb=(32*2)/128/256,unit=MPa :��������ߊ�{�ڕW�R�� */
 #if JEPLMLT_E == u1g_EJCC_USE  /*�yPL������˗L�z*/ /* temp:�d�l�m�F�̓��e���f(DENG-STD-25017�D) start */
    s2 s2t_binjplctr_prreq;     /* lsb=(32*2)/128/256,unit=MPa :�p�[�V�������t�g�}���`���ˍ����|���v�ڕW�R�� */
 #endif /* JEPLMLT_E */ /* temp:�d�l�m�F�̓��e���f(DENG-STD-25017�D) end */
#endif /* JEEFI */
    u4 u4t_rqdat[2];            /* lsb=1 :�v���w���f�[�^ 0:���\���́A1:�V�\���� */
    u1 u1t_injnum;              /* lsb=1 :���˒i�� */
    u1 u1t_mox;                 /* lsb=1 :���C���Z���T�� */
    u1 u1t_nox_c;               /* lsb=1 :���C���Z���T�� */
    u1 u1t_cyl;                 /* lsb=1 :�C���� */
    u1 u1t_ncyl_c;              /* lsb=1 :�C���� */
    s2 s2t_krichxbcrt[u1g_EJCC_NOX]; /* lsb=(32*2)/128/256,unit=�{ :���݊�{���ʕ␳�W�� */
    s2 s2t_krichx;              /* lsb=(32*2)/128/256,unit=�{ :���˗ʕ␳�W�� */
    s2 s2t_kpfi_wk;             /* lsb=(1*4)/128/256,unit=�{ :�߰ĕ��˗ʎZ�o�W�����[�N */
    s2 s2t_kpfin[u1g_EJCC_NOX]; /* lsb=(1*4)/128/256,unit=�{ :�|�[�g���˗ʎZ�o�W��(�o���N��) */
    s4 s4t_k1f;                 /* lsb=(1*4)/128/256,unit=�{ :1��ڕ��˗ʎZ�o�W��(�o���N�ԕ��ϒl(�c�C���Z���T)) */
    s4 s4t_k2f;                 /* lsb=(1*4)/128/256,unit=�{ :2��ڕ��˗ʎZ�o�W��(�o���N�ԕ��ϒl(�c�C���Z���T)) */
    s4 s4t_k3f;                 /* lsb=(1*4)/128/256,unit=�{ :3��ڕ��˗ʎZ�o�W��(�o���N�ԕ��ϒl(�c�C���Z���T)) */
    u1 u1t_xqinjast;            /* lsb=1 :�n���㕬�˗ʗv���׸� */
    u1 u1t_xqinjasto;           /* lsb=1 :�n���㕬�˗ʗv���׸ޑO��l */
    u1 u1t_xast;                /* lsb=1 :�n����t���O */
#if JEEFI != u1g_EJCC_D4        /*�yD-4�ȊO�z*/
    s2 s2t_ainjcutp;            /* lsb=1024/128/256,unit=BTDC :�߰ĕ��ˋ�����Ď��� */
    s4 s4t_kqstmxp;             /* lsb=128/128/256,unit=�{ :�߰Ďn�������˗ʐ����W�� */
    u2 u2t_injmodmsk0F00;       /* lsb=1 :���˃��[�h��0x0F00�Ń}�X�N�����l */
    u2 u2t_injmodmsk00F0;       /* lsb=1 :���˃��[�h��0x00F0�Ń}�X�N�����l */
    u2 u2t_injmodmsk000F;       /* lsb=1 :���˃��[�h��0x000F�Ń}�X�N�����l */
 #if (JEALLHV_E == u1g_EJCC_ALLHV_E) && (JEEFI == u1g_EJCC_PORT)      /*�yALL HV�zAND�y�߰āz*/
    f4 f4t_k1fptcat;            /* unit=�{ :�G�}�g�@�߰ĕ��˂̂ݗv�����߰�1��ڕ��˗ʎZ�o�W�� */
    f4 f4t_k1fpt;               /* unit=�{ :�ڕW�߰�1��ڕ��˗ʎZ�o�W�� */
 #endif /* JEALLHV_E,JEEFI */
#endif /* JEEFI */
#if JEEFI == u1g_EJCC_DUAL      /*�y�ޭ��INJ�z*/
    s4 s4t_kpfi;                /* lsb=(1*4)/128/256,unit=�{ :�߰ĕ��˗ʎZ�o�W��(�n����) */
    s4 s4t_qinjadd;             /* lsb=(4096*1024)/128/256/256/256,unit=mg/st :�߰ĕ��˗ʎZ�o�p */
    s4 s4t_qinjadd2;            /* lsb=(4096*1024)/128/256/256/256,unit=mg/st :�߰ĕ��˗ʎZ�o�p2 */
    s4 s4t_qinjdiv;             /* lsb=(16*64)/128/256/256/256,unit=mg/st :�߰ĕ��˗ʎZ�o�p(�t���l) */
    s2 s2t_kpfit;               /* lsb=(1*4)/128/256,unit=�{ :�ڕW�߰ĕ��˗ʎZ�o�W�� */
    s2 s2t_kpfitn[u1g_EJCC_NOX];    /* lsb=(1*4)/128/256,unit=�{ :�ڕW�|�[�g���˗ʎZ�o�W��(�o���N��) */
    s2 s2t_kpfit_eprvdil;       /* lsb=(1*4)/128/256,unit=�{ :�ڕW�߰ĕ��˗ʎZ�o�W��(eprvdil_ekpfit) */
 #if (((JEPLMLT_E == u1g_EJCC_USE) && (EMINJ_BINJPLCTR_MEDI == ON)) \
   || ((JEALLHV_E == u1g_EJCC_ALLHV_E) && (JEPLMLT_E == u1g_EJCC_USE) && (EMINJ_BINJPLCTR_WC_MEDI == ON)) \
   || ((JEEGMG_E == u1g_EJCC_HVPLGR_E) && (JEFFV == u1g_EJCC_NOT_USE) && (JEPLMLT_E == u1g_EJCC_USE) && (EMINJ_BINJPLCTR_STAHV_MEDI == ON)))
   /* (�yPL������˗L�zAND�y�߰�����ĕ��˂�p������{���ː���v���g�p�z) */
   /* OR (�yALL HV�zAND�yPL������˗L�zAND�y�߰�����ĕ��˂�p������{���ː���(�G�}�g�@��)�v���g�p�z) */
   /* OR (�yEG-MG�V���ޱ�zAND�yFFV���䖳�zAND�yPL������˗L�zAND�y�߰�����ĕ��˂�p������{���ː���(HV�n�����䎞)�v���g�p�z) */
    f4 f4t_kpfit;               /* unit=�{ :�ڕW�|�[�g���˗ʎZ�o�W��(�o���N�ԕ���) */
    f4 f4t_kpfitn[u1g_EJCC_NOX];    /* unit=�{ :�ڕW�|�[�g���˗ʎZ�o�W��(�o���N��) */
    s2 s2t_kpfitplctr;          /* lsb=(1*4)/128/256,unit=�{ :�ڕW�|�[�g���˗ʎZ�o�W��(�o���N�ԕ���) */
    s2 s2t_kpfitnplctr[u1g_EJCC_NOX]; /* lsb=(1*4)/128/256,unit=�{ :�ڕW�|�[�g���˗ʎZ�o�W��(�o���N��) */
 #endif /* JEPLMLT_E,EMINJ_BINJPLCTR_MEDI,JEALLHV_E,EMINJ_BINJPLCTR_WC_MEDI,JEEGMG_E,JEFFV,EMINJ_BINJPLCTR_STAHV_MEDI */
    s2 s2t_kpfit_estratist;     /* lsb=(1*4)/128/256,unit=�{ :���w�n�����䎞�ڕW�߰ĕ��˗ʎZ�o�W�� */
 #if JEALLHV_E == u1g_EJCC_ALLHV_E      /*�yALL HV�z*/
    s2 s2t_kpfitcat;            /* lsb=(1*4)/128/256,unit=�{ :�G�}�g�@���ڕW�߰ĕ��˗ʎZ�o�W��(�߰āE�������ˊ���) */
    s2 s2t_kpfit_erdpn;         /* lsb=(1*4)/128/256,unit=�{ :�n����o�m�ጸ���䎞�ڕW�߰ĕ��˗ʎZ�o�W��(�߰ē������ˊ���) */
 #endif /* JEALLHV_E */
 #if JEFFV != u1g_EJCC_NOT_USE  /*�yFFV����L�z*/
    s2 s2t_kpfit_eactarefuel;   /* lsb=(1*4)/128/256,unit=�{ :������R������ւ��ׂ̖̈ڕW���������� */
 #endif /* JEFFV */
#endif /* JEEFI */
#if JEEFI == u1g_EJCC_PORT      /*�y�߰āz*/
    s2 s2t_ainjpadd;            /* lsb=1024/128/256,unit=BTDC :�߰Ēǉ����ˊJ�n���� */
#endif /* JEEFI */
#if JEPRDEMAND == u1g_EJCC_NOT_USE    /*�y�ϔR�����䖳�z*/
    s2 s2t_qlp;                 /* lsb=512/128/256,unit=L/h :�ሳ����ߖڕW�f�o���� */
#else                                 /*�y�ϔR������L�z*/
    s2 s2t_prlp;                /* lsb=1280/128/256,unit=kPa :�ሳ����ߖڕW�R�� */
#endif /* JEPRDEMAND */
    st_EMINJ_EMINJ_DEF stt_minj_data = { 0 };       /* ����p�������\���̃��[�N(�ꊇ������) */
    st_EMINJ_EMINJ_DEF stt_minj_datdft = { 0 };     /* ����p�������\���̃f�t�H���g�l(�ꊇ������) */
    st_EMINJ_EINJ stt_injdat = { 0 };               /* �������\���̃��[�N(�ꊇ������) */
    st_EBINJCTR_EBINJCTR stt_binjctrdat = { 0 };    /* �������\���̃��[�N(�ꊇ������) */
    st_EBSTACTR_EBSTACTR stt_bstactrdat = { 0 };    /* �������\���̃��[�N(�ꊇ������) */
    st_EMINJ_EMINJ_BUF stt_minj_data2 = { 0 };      /* ����p�������\���̃��[�N(�ꊇ������) */
    st_EMINJ_EMINJ_BUF stt_minj_datdft2 = { 0 };    /* ����p�������\���̃f�t�H���g�l(�ꊇ������) */
    st_EMINJ_EMINJ stt_injdat2 = { 0 };             /* �������\���̃��[�N(�ꊇ������) */

    /* ���j�^�ϐ���` */
#ifdef M_EMINJ       /* �f�o�b�O���[�h */
    volatile static u2 u2s_eminj_einjmod_mon;       /* lsb=1 :���˃��[�h(���j�^�p) */
    volatile static u2 u2s_eminj_eminj_einjmod_mon; /* lsb=1 :���˃��[�h(���j�^�p) */
    volatile static u4 u4s_eminj_eminj_einjptn_mon; /* lsb=1 :���˃p�^�[��(���j�^�p) */
 #if JEEFI != u1g_EJCC_D4        /*�yD-4�ȊO�z*/
    volatile static s2 s2s_eminj_eainjp1_mon;       /* lsb=1024/128/256,unit=BTDC :�|�[�g1��ڕ��ˊJ�n����(���j�^�p) */
    volatile static f4 f4s_eminj_eainjp1_mon;       /* unit=BTDC :�|�[�g1��ڕ��ˊJ�n����(���j�^�p) */
    volatile static s2 s2s_eminj_eainjp2_mon;       /* lsb=1024/128/256,unit=BTDC :�|�[�g2��ڕ��ˊJ�n����(���j�^�p) */
    volatile static f4 f4s_eminj_eainjp2_mon;       /* unit=BTDC :�|�[�g2��ڕ��ˊJ�n����(���j�^�p) */
    volatile static s2 s2s_eminj_eainjp3_mon;       /* lsb=1024/128/256,unit=BTDC :�|�[�g3��ڕ��ˊJ�n����(���j�^�p) */
    volatile static f4 f4s_eminj_eainjp3_mon;       /* unit=BTDC :�|�[�g3��ڕ��ˊJ�n����(���j�^�p) */
    volatile static s2 s2s_eminj_eainjp4_mon;       /* lsb=1024/128/256,unit=BTDC :�|�[�g4��ڕ��ˊJ�n����(���j�^�p) */
    volatile static f4 f4s_eminj_eainjp4_mon;       /* unit=BTDC :�|�[�g4��ڕ��ˊJ�n����(���j�^�p) */
    volatile static s2 s2s_eminj_eainjcutp_mon;     /* lsb=1024/128/256,unit=BTDC :�߰ĕ��ˋ�����Ď���(���j�^�p) */
    volatile static f4 f4s_eminj_eainjcutp_mon;     /* unit=BTDC :�߰ĕ��ˋ�����Ď���(���j�^�p) */
    volatile static s2 s2s_eminj_eminj_eainjcutp_mon;    /* lsb=1024/128/256,unit=BTDC :�߰ĕ��ˋ�����Ď���(���j�^�p) */
    volatile static f4 f4s_eminj_eminj_eainjcutp_mon;    /* unit=BTDC :�߰ĕ��ˋ�����Ď���(���j�^�p) */
 #endif /* JEEFI */
 #if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    volatile static s2 s2s_eminj_eainjd1_mon;       /* lsb=1024/128/256,unit=BTDC :����1��ڕ��ˊJ�n����(���j�^�p) */
    volatile static f4 f4s_eminj_eainjd1_mon;       /* unit=BTDC :����1��ڕ��ˊJ�n����(���j�^�p) */
    volatile static s2 s2s_eminj_eainjd2_mon;       /* lsb=1024/128/256,unit=BTDC :����2��ڕ��ˊJ�n����(���j�^�p) */
    volatile static f4 f4s_eminj_eainjd2_mon;       /* unit=BTDC :����2��ڕ��ˊJ�n����(���j�^�p) */
    volatile static s2 s2s_eminj_eainjd3_mon;       /* lsb=1024/128/256,unit=BTDC :����3��ڕ��ˊJ�n����(���j�^�p) */
    volatile static f4 f4s_eminj_eainjd3_mon;       /* unit=BTDC :����3��ڕ��ˊJ�n����(���j�^�p) */
    volatile static s2 s2s_eminj_eainjd4_mon;       /* lsb=1024/128/256,unit=BTDC :����4��ڕ��ˊJ�n����(���j�^�p) */
    volatile static f4 f4s_eminj_eainjd4_mon;       /* unit=BTDC :����4��ڕ��ˊJ�n����(���j�^�p) */
    volatile static s2 s2s_eminj_eainjcutd_mon;     /* lsb=1024/128/256,unit=BTDC :�������ˋ�����Ď���(���j�^�p) */
    volatile static f4 f4s_eminj_eainjcutd_mon;     /* unit=BTDC :�������ˋ�����Ď���(���j�^�p) */
    volatile static s2 s2s_eminj_eminj_eainjcutd_mon;    /* lsb=1024/128/256,unit=BTDC :�������ˋ�����Ď���(���j�^�p) */
    volatile static f4 f4s_eminj_eminj_eainjcutd_mon;    /* unit=BTDC :�������ˋ�����Ď���(���j�^�p) */
 #endif /* JEEFI */
 #if JEEFI == u1g_EJCC_PORT      /*�y�߰āz*/
    volatile static s2 s2s_eminj_eainjpadd_mon;     /* lsb=1024/128/256,unit=BTDC :�|�[�g�ǉ����ˊJ�n����(���j�^�p) */
    volatile static s2 s2s_eminj_eminj_eainjpadd_mon;    /* lsb=1024/128/256,unit=BTDC :�|�[�g�ǉ����ˊJ�n����(���j�^�p) */
 #endif /* JEEFI */
 #if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    volatile static s2 s2s_eminj_eainjdadd_mon;     /* lsb=1024/128/256,unit=BTDC :�����ǉ����ˊJ�n����(���j�^�p) */
    volatile static s2 s2s_eminj_eminj_eainjdadd_mon;    /* lsb=1024/128/256,unit=BTDC :�����ǉ����ˊJ�n����(���j�^�p) */
 #endif /* JEEFI */
 #if JEEFI != u1g_EJCC_D4        /*�yD-4�ȊO�z*/
    volatile static s4 s4s_eminj_eqinjstp1_mon;     /* lsb=(4096*1024)/128/256/256/256,unit=mg/st :�|�[�g1��ڎn�������˗�(���j�^�p) */
    volatile static f4 f4s_eminj_eqinjstp1_mon;     /* unit=mg/st :�|�[�g1��ڎn�������˗�(���j�^�p) */
    volatile static s4 s4s_eminj_eqinjstp2_mon;     /* lsb=(4096*1024)/128/256/256/256,unit=mg/st :�|�[�g2��ڎn�������˗�(���j�^�p) */
    volatile static f4 f4s_eminj_eqinjstp2_mon;     /* unit=mg/st :�|�[�g2��ڎn�������˗�(���j�^�p) */
    volatile static s4 s4s_eminj_eqinjstp3_mon;     /* lsb=(4096*1024)/128/256/256/256,unit=mg/st :�|�[�g3��ڎn�������˗�(���j�^�p) */
    volatile static f4 f4s_eminj_eqinjstp3_mon;     /* unit=mg/st :�|�[�g3��ڎn�������˗�(���j�^�p) */
    volatile static s4 s4s_eminj_eqinjstp4_mon;     /* lsb=(4096*1024)/128/256/256/256,unit=mg/st :�|�[�g4��ڎn�������˗�(���j�^�p) */
    volatile static f4 f4s_eminj_eqinjstp4_mon;     /* unit=mg/st :�|�[�g4��ڎn�������˗�(���j�^�p) */
 #endif /* JEEFI */
 #if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    volatile static s4 s4s_eminj_eqinjstd1_mon;     /* lsb=(4096*1024)/128/256/256/256,unit=mg/st :����1��ڎn�������˗�(���j�^�p) */
    volatile static s4 s4s_eminj_eqinjstd2_mon;     /* lsb=(4096*1024)/128/256/256/256,unit=mg/st :����2��ڎn�������˗�(���j�^�p) */
    volatile static s4 s4s_eminj_eqinjstd3_mon;     /* lsb=(4096*1024)/128/256/256/256,unit=mg/st :����3��ڎn�������˗�(���j�^�p) */
    volatile static s4 s4s_eminj_eqinjstd4_mon;     /* lsb=(4096*1024)/128/256/256/256,unit=mg/st :����4��ڎn�������˗�(���j�^�p) */
 #endif /* JEEFI */
 #if JECOMBCCPT_E == u1g_EJCC_SPRAYG_E                   /*�y���ڰ�޲�ށz*/
    volatile static s4 s4s_eminj_eqinjexp_mon;      /* lsb=(4096*1024)/128/256/256/256,unit=mg/st :�c���s�����˗�(���j�^�p) */
    volatile static f4 f4s_eminj_eqinjexp_mon;      /* unit=mg/st :�c���s�����˗�(���j�^�p) */
    volatile static s4 s4s_eminj_eminj_eqinjexp_mon;     /* lsb=(4096*1024)/128/256/256/256,unit=mg/st :�c���s�����˗�(���j�^�p) */
    volatile static f4 f4s_eminj_eminj_eqinjexp_mon;     /* unit=mg/st :�c���s�����˗�(���j�^�p) */
 #endif /* JECOMBCCPT_E */
    volatile static s2 s2s_eminj_ek1f_mon;          /* lsb=(1*4)/128/256,unit=�{ :1��ڕ��˗ʎZ�o�W��(���j�^�p) */
    volatile static f4 f4s_eminj_ek1f_mon;          /* unit=�{ :1��ڕ��˗ʎZ�o�W��(���j�^�p) */
    volatile static s2 s2s_eminj_ek2f_mon;          /* lsb=(1*4)/128/256,unit=�{ :2��ڕ��˗ʎZ�o�W��(���j�^�p) */
    volatile static f4 f4s_eminj_ek2f_mon;          /* unit=�{ :2��ڕ��˗ʎZ�o�W��(���j�^�p) */
    volatile static s2 s2s_eminj_ek3f_mon;          /* lsb=(1*4)/128/256,unit=�{ :3��ڕ��˗ʎZ�o�W��(���j�^�p) */
    volatile static f4 f4s_eminj_ek3f_mon;          /* unit=�{ :3��ڕ��˗ʎZ�o�W��(���j�^�p) */
    volatile static u1 u1s_eminj_exqinjast_mon;     /* lsb=1 :�n���㕬�˗ʗv���t���O(���j�^�p) */
    volatile static u1 u1s_eminj_eminj_exqinjast_mon;    /* lsb=1 :�n���㕬�˗ʗv���t���O(���j�^�p) */
 #if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    volatile static u1 u1s_eminj_explreq_mon;       /* lsb=1 :PL���ˎ��{�v��(���j�^�p) */
    volatile static u1 u1s_eminj_eminj_explreq_mon;      /* lsb=1 :PL���ˎ��{�v��(���j�^�p) */
 #endif /* JEEFI */
 #if JEEFI == u1g_EJCC_DUAL      /*�y�ޭ��INJ�z*/
    volatile static f4 f4s_eminj_ekpfit_mon;        /* unit=�{ :�ڕW�|�[�g���˗ʎZ�o�W��(���j�^�p) */
    volatile static f4 f4s_eminj_eminj_ekpfit_mon;       /* unit=�{ :�ڕW�|�[�g���˗ʎZ�o�W��(���j�^�p) */
 #endif /* JEEFI */
 #if JEEFI != u1g_EJCC_D4        /*�yD-4�ȊO�z*/
    volatile static s2 s2s_eminj_ek1fpt_mon;        /* lsb=(1*4)/128/256,unit=�{ :�߰ĕ��˂̂ݗv�����̖ڕW�߰�1��ڕ��˗ʎZ�o�W��(���j�^�p) */
    volatile static f4 f4s_eminj_ek1fpt_mon;        /* unit=�{ :�߰ĕ��˂̂ݗv�����̖ڕW�߰�1��ڕ��˗ʎZ�o�W��(���j�^�p) */
    volatile static s2 s2s_eminj_eminj_ek1fpt_mon;       /* lsb=(1*4)/128/256,unit=�{ :�߰ĕ��˂̂ݗv�����̖ڕW�߰�1��ڕ��˗ʎZ�o�W��(���j�^�p) */
    volatile static f4 f4s_eminj_eminj_ek1fpt_mon;       /* unit=�{ :�߰ĕ��˂̂ݗv�����̖ڕW�߰�1��ڕ��˗ʎZ�o�W��(���j�^�p) */
 #endif /* JEEFI */
 #if JEEFI == u1g_EJCC_DUAL      /*�y�ޭ��INJ�z*/
  #if JEEGR == u1g_EJCC_USE      /*�yEGR����L�z*/
    volatile static f4 f4s_eminj_ekpfiegr_mon;      /* unit=�{ :EGR-ON���̖ڕW�|�[�g���˗ʎZ�o�W��(���j�^�p) */
    volatile static f4 f4s_eminj_eminj_ekpfiegr_mon;     /* unit=�{ :EGR-ON���̖ڕW�|�[�g���˗ʎZ�o�W��(���j�^�p) */
  #endif /* JEEGR */
 #endif /* JEEFI */
#endif /* M_EMINJ */

    /* NE�����^�X�N�ʔ��� */
    u1t_xnercdfew = (u1)OFF;
    if ( s2g_ene_ene < s2s_eminj_NE_RCD )           /* NE�����^�X�N�����Ȃ� */
    {
        u1t_xnercdfew = (u1)ON;
    }
    u1s_eminj_exnercdfew = u1t_xnercdfew;

    u1t_ncyl_c = u1g_ejcc_NCYL;
    u1t_nox_c = u1g_ejcc_NOX;

    /* �������f�[�^�擾 */
    vdg_ebinjctr_ebinjctr_dataget( &stt_binjctrdat );
    vdg_ebstactr_ebstactr_dataget( &stt_bstactrdat );

#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    s2t_ainjdb1 = s2g_eainjdb_eainjdb1;
    s2t_ainjcutd = s2g_eainjcut_eainjcutd;
    s2t_prhpb = s2g_eprhpb_eprhpb;
 #if JEPLMLT_E == u1g_EJCC_USE  /*�yPL������˗L�z*/ /* temp:�d�l�m�F�̓��e���f(DENG-STD-25017�D) start */
    s2t_binjplctr_prreq = s2g_ebinjplctr_eprreq;
 #endif /* JEPLMLT_E */ /* temp:�d�l�m�F�̓��e���f(DENG-STD-25017�D) end */
#endif /* JEEFI */
#if JEEFI == u1g_EJCC_PORT      /*�y�߰āz*/
    s2t_ainjpadd = s2g_einjadd_eainjpadd;
#endif /* JEEFI */
#if JEEFI != u1g_EJCC_D4        /*�yD-4�ȊO�z*/
    s2t_ainjcutp = s2g_eainjcut_eainjcutp;
 #if (JEALLHV_E == u1g_EJCC_ALLHV_E) && (JEEFI == u1g_EJCC_PORT)  /*�yALL HV�zAND�y�߰āz*/
    f4t_k1fptcat = f4g_ewupcat_ek1fptcat;
    f4t_k1fpt = f4g_erdpn_ek1fpt;
 #endif /* JEALLHV_E,JEEFI */
#endif /* JEEFI */

#if JEPRDEMAND == u1g_EJCC_NOT_USE    /*�y�ϔR�����䖳�z*/
    s2t_qlp = s2g_emqlp_eqlp;
#else                                 /*�y�ϔR������L�z*/
    s2t_prlp = s2g_emprlp_eprlp;
#endif /* JEPRDEMAND */

    /* �f�t�H���g�l���b�` */
    stt_minj_datdft.u1_pri = u1g_EMINJ_PRINORQ;
    stt_minj_datdft.u4_einjrq_dat = u4s_EMINJ_NORQDAT;
    stt_minj_datdft.u2_einjmod = stt_binjctrdat.u2_einjmod;
    stt_minj_datdft2.u1_pri = u1g_EMINJ_PRINORQ;
    stt_minj_datdft2.u4_einjrq_dat = u4s_EMINJ_NORQDAT;
    stt_minj_datdft2.u2_einjmod = stt_binjctrdat.u2_einjmod;
    stt_minj_datdft2.u4_einjptn = u4g_EMINJ_INJPTN_VD;
#if JEEFI != u1g_EJCC_D4        /*�yD-4�ȊO�z*/
    stt_minj_datdft.s2_eainjp1 = stt_binjctrdat.s2_eainjpb1;
    stt_minj_datdft.s2_eainjp2 = s2s_EMINJ_AINJP_VD;
    stt_minj_datdft.s2_eainjp3 = s2s_EMINJ_AINJP_VD;
    stt_minj_datdft.s2_eainjp4 = s2s_EMINJ_AINJP_VD;
    stt_minj_datdft.s2_einjend = stt_binjctrdat.s2_einjendb;
    stt_minj_datdft.s2_eainjcutp = s2t_ainjcutp;
    stt_minj_datdft2.s2_eainjpn[0] = stt_binjctrdat.s2_eainjpb1;
    stt_minj_datdft2.s2_eainjpn[1] = s2s_EMINJ_AINJP_VD;
    stt_minj_datdft2.s2_eainjpn[2] = s2s_EMINJ_AINJP_VD;
    stt_minj_datdft2.s2_eainjpn[3] = s2s_EMINJ_AINJP_VD;
    stt_minj_datdft2.s2_einjend = stt_binjctrdat.s2_einjendb;
    stt_minj_datdft2.s2_eainjcutp = s2t_ainjcutp;
#endif /* JEEFI */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    stt_minj_datdft.s2_eainjd1 = s2t_ainjdb1;
    stt_minj_datdft.s2_eainjd2 = stt_binjctrdat.s2_eainjd2;
    stt_minj_datdft.s2_eainjd3 = stt_binjctrdat.s2_eainjd3;
    stt_minj_datdft.s2_eainjd4 = s2s_EMINJ_AINJD_VD;
    stt_minj_datdft.s2_eainjcutd = s2t_ainjcutd;
    stt_minj_datdft.s2_eprreq = s2t_prhpb;
    stt_minj_datdft2.s2_eainjdn[0] = s2t_ainjdb1;
    stt_minj_datdft2.s2_eainjdn[1] = stt_binjctrdat.s2_eainjd2;
    stt_minj_datdft2.s2_eainjdn[2] = stt_binjctrdat.s2_eainjd3;
    stt_minj_datdft2.s2_eainjdn[3] = s2s_EMINJ_AINJD_VD;
    stt_minj_datdft2.s2_eainjdn[4] = s2s_EMINJ_AINJD_VD;
    stt_minj_datdft2.s2_eainjdn[5] = s2s_EMINJ_AINJD_VD;
    stt_minj_datdft2.s2_eainjcutd = s2t_ainjcutd;
    stt_minj_datdft2.s2_eprreq = s2t_prhpb;
#endif /* JEEFI */
#if JEEFI == u1g_EJCC_PORT      /*�y�߰āz*/
    stt_injdat.s2_eainjpadd = s2t_ainjpadd;             /* �D��x������s��Ȃ��ϐ��̂��߂��̈ʒu�ő�� */
    stt_injdat2.s2_eainjpadd = s2t_ainjpadd;            /* �D��x������s��Ȃ��ϐ��̂��߂��̈ʒu�ő�� */
#endif /* JEEFI */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    s2t_ainjdadd = s2g_einjadd_eainjdadd;
    s2t_ainjadd = s2g_ecatotp_eainjadd;
    ELIB_MINSLCT2( s2t_ainjdadd, s2t_ainjadd, s2t_ainjdaddmin );
    stt_injdat.s2_eainjdadd = s2t_ainjdaddmin;          /* �D��x������s��Ȃ��ϐ��̂��߂��̈ʒu�ő�� */
    stt_injdat2.s2_eainjdadd = s2t_ainjdaddmin;         /* �D��x������s��Ȃ��ϐ��̂��߂��̈ʒu�ő�� */
#endif /* JEEFI */
    for ( u1t_cyl = (u1)0U; u1t_cyl < u1t_ncyl_c; u1t_cyl++ )
    {
        stt_minj_datdft.s4_eqfc[u1t_cyl] = stg_eminj_einj.s4_eqfc[u1t_cyl];   /* �O��l */
        stt_minj_datdft2.s4_eqfc[u1t_cyl] = stg_eminj_eminj.s4_eqfc[u1t_cyl]; /* �O��l */
    }
#if JECOMBCCPT_E == u1g_EJCC_SPRAYG_E                   /*�y���ڰ�޲�ށz*/
    stt_minj_datdft.s4_eqinjexp = s4s_EMINJ_QINJ_VD;
    stt_minj_datdft2.s4_eqinjexp = s4s_EMINJ_QINJ_VD;
#endif /* JECOMBCCPT_E */
    for ( u1t_injnum = (u1)0U; u1t_injnum < (u1)8U; u1t_injnum++ )
    {
        stt_minj_datdft2.s4_eqinjflfix[u1t_injnum] = s4s_EMINJ_QINJFLFIX_VD;
        stt_minj_datdft2.s4_eqinjplfix[u1t_injnum] = s4s_EMINJ_QINJPLFIX_VD;
    }
    stt_minj_datdft.s2_ek1f = stt_binjctrdat.s2_ek1f;
    stt_minj_datdft.s2_ek2f = stt_binjctrdat.s2_ek2f;
    stt_minj_datdft.s2_ek3f = stt_binjctrdat.s2_ek3f;
    for ( u1t_mox = (u1)0U; u1t_mox < u1t_nox_c; u1t_mox++ )
    {
        stt_minj_datdft.s2_ek1fn[u1t_mox] = stt_binjctrdat.s2_ek1f;
        stt_minj_datdft.s2_ek2fn[u1t_mox] = stt_binjctrdat.s2_ek2f;
        stt_minj_datdft.s2_ek3fn[u1t_mox] = stt_binjctrdat.s2_ek3f;
        stt_minj_datdft2.s2_ek1fn[u1t_mox] = stt_binjctrdat.s2_ek1f;
        stt_minj_datdft2.s2_ek2fn[u1t_mox] = stt_binjctrdat.s2_ek2f;
        stt_minj_datdft2.s2_ek3fn[u1t_mox] = stt_binjctrdat.s2_ek3f;
    }
#if JEPRDEMAND == u1g_EJCC_NOT_USE    /*�y�ϔR�����䖳�z*/
    stt_minj_datdft.s2_eqfreq = s2t_qlp;
    stt_minj_datdft2.s2_eqfreq = s2t_qlp;
#else                                 /*�y�ϔR������L�z*/
    stt_minj_datdft.s2_eprreql = s2t_prlp;
    stt_minj_datdft2.s2_eprreql = s2t_prlp;
#endif /* JEPRDEMAND */
#if JEEGMG_E == u1g_EJCC_HVCLUTCH_E   /*�yEG-MG�ׯ��z*/
    u1t_xast = u1g_ectrlhv_exast;
#else                                 /*�yEG-MG�ׯ��ȊO�z*/
    u1t_xast = u1g_exst_exastefi;
#endif /* JEEGMG_E */
    u1s_eminj_exast_lch = u1t_xast;

    u1t_xqinjasto = stg_eminj_einj.bi_exqinjast;

    /* t_xqinjast(�n���㕬�˗ʗv���׸�)�̎Z�o */
    if ( ( u1s_eminj_exasto == (u1)ON )                 /* �n���� */
      && ( u1t_xast == (u1)OFF ) )
    {
        u1t_xqinjast = (u1)OFF;
    }
    else if ( u1t_xqinjasto == (u1)OFF )                /* �@�\�v���ɂ��n����v�������� */
    {
        u1t_xqinjast = stt_bstactrdat.u1_exqinjastb;
    }
    else
    {
        u1t_xqinjast = u1t_xqinjasto;
    }
    glbitcp_bibi( u1t_xqinjast, stt_minj_datdft.bi_exqinjast );
    glbitcp_bibi( u1t_xqinjast, stt_minj_datdft2.bi_exqinjast );
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    stt_minj_datdft.u1_explreq = stt_binjctrdat.u1_explreq;
    stt_minj_datdft2.u1_explreq = stt_binjctrdat.u1_explreq;
#endif /* JEEFI */
    if ( u1t_xnercdfew == (u1)ON )                      /* NE�����^�X�N�����Ȃ� */
    {
#if JEEFI != u1g_EJCC_D4        /*�yD-4�ȊO�z*/
        stt_minj_datdft.s4_eqinjstp1 = stt_bstactrdat.s4_eqinjstapb;
        stt_minj_datdft.s4_eqinjstp2 = s4s_EMINJ_QINJ_VD;
        stt_minj_datdft.s4_eqinjstp3 = s4s_EMINJ_QINJ_VD;
        stt_minj_datdft.s4_eqinjstp4 = s4s_EMINJ_QINJ_VD;
        stt_minj_datdft2.s4_eqinjstpn[0] = stt_bstactrdat.s4_eqinjstapb;
        stt_minj_datdft2.s4_eqinjstpn[1] = s4s_EMINJ_QINJ_VD;
        stt_minj_datdft2.s4_eqinjstpn[2] = s4s_EMINJ_QINJ_VD;
        stt_minj_datdft2.s4_eqinjstpn[3] = s4s_EMINJ_QINJ_VD;
#endif /* JEEFI */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
        stt_minj_datdft.s4_eqinjstd1 = stt_bstactrdat.s4_eqinjstad1b;
        stt_minj_datdft.s4_eqinjstd2 = s4s_EMINJ_QINJ_VD;
        stt_minj_datdft.s4_eqinjstd3 = s4s_EMINJ_QINJ_VD;
        stt_minj_datdft.s4_eqinjstd4 = s4s_EMINJ_QINJ_VD;
        stt_minj_datdft2.s4_eqinjstdn[0] = stt_bstactrdat.s4_eqinjstad1b;
        stt_minj_datdft2.s4_eqinjstdn[1] = s4s_EMINJ_QINJ_VD;
        stt_minj_datdft2.s4_eqinjstdn[2] = s4s_EMINJ_QINJ_VD;
        stt_minj_datdft2.s4_eqinjstdn[3] = s4s_EMINJ_QINJ_VD;
        stt_minj_datdft2.s4_eqinjstdn[4] = s4s_EMINJ_QINJ_VD;
        stt_minj_datdft2.s4_eqinjstdn[5] = s4s_EMINJ_QINJ_VD;
#endif /* JEEFI */
#if JEEFI != u1g_EJCC_D4        /*�yD-4�ȊO�z*/
        if ( ( stt_bstactrdat.u1_exainjstab == (u1)ON )     /* ��{�n�����|�[�g���˗v���L�� */
          && ( u1t_xqinjasto == (u1)OFF ) )                 /* �@�\�v���ɂ��n����v�������� */
        {
            stt_minj_datdft.s2_eainjp1 = stt_bstactrdat.s2_eainjpstab;
            stt_minj_datdft.s2_einjend = stt_bstactrdat.s2_einjendstab;
            stt_minj_datdft2.s2_eainjpn[0] = stt_bstactrdat.s2_eainjpstab;
            stt_minj_datdft2.s2_einjend = stt_bstactrdat.s2_einjendstab;
        }
#endif /* JEEFI */
        if ( ( stt_bstactrdat.u1_exqinjastb == (u1)OFF )    /* ��{�n���㕬�˗ʗv������ */
          && ( u1t_xqinjasto == (u1)OFF ) )                 /* �@�\�v���ɂ��n����v�������� */
        {
            stt_minj_datdft.u2_einjmod = stt_bstactrdat.u2_einjmod;
            stt_minj_datdft2.u2_einjmod = stt_bstactrdat.u2_einjmod;
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
            stt_minj_datdft.s2_eainjd1 = stt_bstactrdat.s2_eainjdsta1b;
            stt_minj_datdft.s2_eprreq = stt_bstactrdat.s2_eprreqhstab;
            stt_minj_datdft2.s2_eainjdn[0] = stt_bstactrdat.s2_eainjdsta1b;
            stt_minj_datdft2.s2_eprreq = stt_bstactrdat.s2_eprreqhstab;
#endif /* JEEFI */
        }
    }

    /* �D��x���� */
    if ( u1t_xnercdfew == (u1)ON )                      /* NE�����^�X�N�����Ȃ� */
    {
        vds_eminj_eminj_hpri( &stt_minj_data, &stt_minj_datdft, &stt_minj_data2, &stt_minj_datdft2 );       /* ���␧�񖳂����̒��⏈�� */
    }
    else                                                /* NE�����^�X�N������ */
    {
        vds_eminj_eminjlmt_hpri( &stt_minj_data, &stt_minj_datdft, &stt_minj_data2, &stt_minj_datdft2 );    /* ���␧��L�莞�̒��⏈�� */
    }
    u4t_rqdat[0] = u4s_eminj_erqdat[0];
    u4t_rqdat[1] = u4s_eminj_erqdat[1];

    u1t_injmedislid = u1g_eminj_einjmedislid;
    if ( u1t_injmedislid == u1g_EMINJ_NONE_ID )
    {
        /* �D��I��v������������ */
        vds_eminj_einj_datacopy( &stt_minj_data, &stt_minj_datdft );
        vds_eminj_einj_datacopy2( &stt_minj_data2, &stt_minj_datdft2 );

#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
        if ( ( stt_bstactrdat.u1_exqinjastb == (u1)ON )     /* ��{�n���㕬�˗ʗv���L�� */
          || ( u1t_xqinjasto == (u1)ON ) )                  /* �@�\�v���ɂ��n����v���L�� */
        {
            stt_minj_data.s2_eainjd1 = stt_binjctrdat.s2_eainjd1;
            stt_minj_data.s2_eprreq = stt_binjctrdat.s2_eprreq;
 #if JEPLMLT_E == u1g_EJCC_USE  /*�yPL������˗L�z*/ /* temp:�d�l�m�F�̓��e���f(DENG-STD-25017�D) start */
            ELIB_LOWGD2( stt_minj_data.s2_eprreq, s2t_binjplctr_prreq, stt_minj_data.s2_eprreq );
 #endif /* JEPLMLT_E */ /* temp:�d�l�m�F�̓��e���f(DENG-STD-25017�D) end */
            stt_minj_data2.s2_eainjdn[0] = stt_binjctrdat.s2_eainjd1;
        }
#endif /* JEEFI */
    }
    else
    {
        /* �D��I��v���L�莞���� */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
        u2t_injmod = stt_minj_data.u2_einjmod;
        u2t_injmod2 = stt_minj_data2.u2_einjmod;
        u2t_binjmodmsk00F0 = (stt_binjctrdat.u2_einjmod & (u2)0x00F0U);
        u2t_binjmodmsk0F0F = (stt_binjctrdat.u2_einjmod & (u2)0x0F0FU);
#endif /* JEEFI */

        /* �v�����˕����v���w������������ */
        if ( (u4t_rqdat[0] & u4g_EMINJ_RQINJMODE) == (u4)0U )           /* ���˃��[�h�v������ */
        {
            stt_minj_data.u2_einjmod = stt_minj_datdft.u2_einjmod;
        }
        else                                                            /* ���˃��[�h�v���L�� */
        {
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
            if ( u2t_injmod == u2g_EMINJ_MOD0N1 )                       /* �v������{���ː��䔽�f�v�����蓛���P�O�O���� */
            {
                if ( ( u2t_binjmodmsk00F0 != (u2)0x0000U )              /* ��{���˗v���������P�O�O���� */
                  && ( u2t_binjmodmsk0F0F == (u2)0x0001U ) )
                {
                    stt_minj_data.u2_einjmod = stt_binjctrdat.u2_einjmod;
                }

 #if JEEFI == u1g_EJCC_DUAL     /*�y�ޭ��INJ�z*/
                if ( u2t_binjmodmsk0F0F == (u2)0x0101U )                /* ��{���˗v���������P�O�O���łȂ��� */
                                                                        /* �������ˉ񐔂�0�ȏオ�����̂��߁A���������ȗ� */
                {
                    stt_minj_data.u2_einjmod = u2g_AINJIF_MOD011;
                }
 #endif /* JEEFI */
            }
#endif /* JEEFI */
        }

        if ( (u4t_rqdat[1] & u4g_EMINJ_RQINJMODE) == (u4)0U )           /* ���˃��[�h�v������ */
        {
            stt_minj_data2.u2_einjmod = stt_minj_datdft2.u2_einjmod;
        }
        else                                                            /* ���˃��[�h�v���L�� */
        {
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
            if ( u2t_injmod2 == u2g_EMINJ_MOD0N1 )                      /* �v������{���ː��䔽�f�v�����蓛���P�O�O���� */
            {
                if ( ( u2t_binjmodmsk00F0 != (u2)0x0000U )              /* ��{���˗v���������P�O�O���� */
                  && ( u2t_binjmodmsk0F0F == (u2)0x0001U ) )
                {
                    stt_minj_data2.u2_einjmod = stt_binjctrdat.u2_einjmod;
                }

 #if JEEFI == u1g_EJCC_DUAL     /*�y�ޭ��INJ�z*/
                if ( u2t_binjmodmsk0F0F == (u2)0x0101U )                /* ��{���˗v���������P�O�O���łȂ��� */
                                                                        /* �������ˉ񐔂�0�ȏオ�����̂��߁A���������ȗ� */
                {
                    stt_minj_data2.u2_einjmod = u2g_AINJIF_MOD011;
                }
 #endif /* JEEFI */
            }
#endif /* JEEFI */
        }

        if ( (u4t_rqdat[1] & u4g_EMINJ_RQINJPTN) == (u4)0U )            /* ��������ݗv������ */
        {
            stt_minj_data2.u4_einjptn = stt_minj_datdft2.u4_einjptn;
        }

#if JEEFI != u1g_EJCC_D4        /*�yD-4�ȊO�z*/
        if ( (u1s_eminj_estpri2 != u1s_eminj_eprisel_fix)
          && (u1s_eminj_eastpri2 != u1s_eminj_eprisel_fix)
          && (u1s_eminj_epri2 != u1s_eminj_eprisel_fix) )   /* eminjst_tbl�Aeminjast_tbl�Aeminj_tbl���⎞ */
        {
            if ( ( (u4t_rqdat[0] & u4g_EMINJ_RQAINJP1) == (u4)0U )      /* �|�[�g1��ڕ��ˊJ�n�����v������ */
              && ( (u4t_rqdat[0] & u4g_EMINJ_RQAINJP) == (u4)0U ) )     /* �|�[�g���ˊJ�n�����v������ */
            {
                stt_minj_data.s2_eainjp1 = stt_minj_datdft.s2_eainjp1;
                stt_minj_data2.s2_eainjpn[0] = stt_minj_data.s2_eainjp1;
            }
            if ( (u4t_rqdat[0] & u4g_EMINJ_RQAINJP2) == (u4)0U )        /* �|�[�g2��ڕ��ˊJ�n�����v������ */
            {
                stt_minj_data.s2_eainjp2 = stt_minj_datdft.s2_eainjp2;
                stt_minj_data2.s2_eainjpn[1] = stt_minj_data.s2_eainjp2;
            }
            if ( (u4t_rqdat[0] & u4g_EMINJ_RQAINJP3) == (u4)0U )        /* �|�[�g3��ڕ��ˊJ�n�����v������ */
            {
                stt_minj_data.s2_eainjp3 = stt_minj_datdft.s2_eainjp3;
                stt_minj_data2.s2_eainjpn[2] = stt_minj_data.s2_eainjp3;
            }
            if ( (u4t_rqdat[0] & u4g_EMINJ_RQAINJP4) == (u4)0U )        /* �|�[�g4��ڕ��ˊJ�n�����v������ */
            {
                stt_minj_data.s2_eainjp4 = stt_minj_datdft.s2_eainjp4;
                stt_minj_data2.s2_eainjpn[3] = stt_minj_data.s2_eainjp4;
            }
        }
        else                                                            /* eminjst_tbl2�Aeminjast_tbl2�Aeminj_tbl2���⎞ */
        {
            if ( (u4t_rqdat[1] & u4g_EMINJ_RQAINJPN) == (u4)0U )        /* �|�[�gn��ڕ��ˊJ�n�����v������ */
            {
                stt_minj_data2.s2_eainjpn[0] = stt_minj_datdft2.s2_eainjpn[0];
                stt_minj_data.s2_eainjp1 = stt_minj_data2.s2_eainjpn[0];
                stt_minj_data2.s2_eainjpn[1] = stt_minj_datdft2.s2_eainjpn[1];
                stt_minj_data.s2_eainjp2 = stt_minj_data2.s2_eainjpn[1];
                stt_minj_data2.s2_eainjpn[2] = stt_minj_datdft2.s2_eainjpn[2];
                stt_minj_data.s2_eainjp3 = stt_minj_data2.s2_eainjpn[2];
                stt_minj_data2.s2_eainjpn[3] = stt_minj_datdft2.s2_eainjpn[3];
                stt_minj_data.s2_eainjp4 = stt_minj_data2.s2_eainjpn[3];
            }
        }
        if ( (u4t_rqdat[0] & u4g_EMINJ_RQINJEND) == (u4)0U )            /* �|�[�g���ˏI�������v������ */
        {
            stt_minj_data.s2_einjend = stt_minj_datdft.s2_einjend;
        }
        if ( (u4t_rqdat[1] & u4g_EMINJ_RQINJEND) == (u4)0U )            /* �|�[�g���ˏI�������v������ */
        {
            stt_minj_data2.s2_einjend = stt_minj_datdft2.s2_einjend;
        }
        if ( (u4t_rqdat[0] & u4g_EMINJ_RQAINJCUTP) == (u4)0U )          /* �|�[�g���ˋ����J�b�g�����v������ */
        {
            stt_minj_data.s2_eainjcutp = stt_minj_datdft.s2_eainjcutp;
        }
        if ( (u4t_rqdat[1] & u4g_EMINJ_RQAINJCUTP) == (u4)0U )          /* �|�[�g���ˋ����J�b�g�����v������ */
        {
            stt_minj_data2.s2_eainjcutp = stt_minj_datdft2.s2_eainjcutp;
        }
#endif /* JEEFI */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
        if ( (u1s_eminj_estpri2 != u1s_eminj_eprisel_fix)
          && (u1s_eminj_eastpri2 != u1s_eminj_eprisel_fix)
          && (u1s_eminj_epri2 != u1s_eminj_eprisel_fix) )   /* eminjst_tbl�Aeminjast_tbl�Aeminj_tbl���⎞ */
        {
            if ( (u4t_rqdat[0] & u4g_EMINJ_RQAINJD1) == (u4)0U )        /* ����1��ڕ��ˊJ�n�����v������ */
            {
                stt_minj_data.s2_eainjd1 = stt_minj_datdft.s2_eainjd1;
                stt_minj_data2.s2_eainjdn[0] = stt_minj_data.s2_eainjd1;
            }
            else                                                        /* ����1��ڕ��ˊJ�n�����v���L�� */
            {
                if ( u2t_injmod == u2g_EMINJ_MOD0N1 )                   /* �v������{���ː��䔽�f�v�����蓛���P�O�O���� */
                {
                    if ( ( u2t_binjmodmsk00F0 != (u2)0x0000U )          /* ��{���˗v���������P�O�O%�� */
                      && ( u2t_binjmodmsk0F0F == (u2)0x0001U ) )
                    {
                        stt_minj_data.s2_eainjd1 = stt_binjctrdat.s2_eainjd1;
                        stt_minj_data2.s2_eainjdn[0] = stt_minj_data.s2_eainjd1;
                    }

 #if JEEFI == u1g_EJCC_DUAL     /*�y�ޭ��INJ�z*/
                    if ( u2t_binjmodmsk0F0F == (u2)0x0101U )            /* ��{���˗v���������P�O�O���łȂ��� */
                                                                        /* �������ˉ񐔂�0�ȏオ�����̂��߁A���������ȗ� */
                    {
                        stt_minj_data.s2_eainjd1 = s2t_ainjdb1;
                        stt_minj_data2.s2_eainjdn[0] = stt_minj_data.s2_eainjd1;
                    }
 #endif /* JEEFI */
                }
            }
            if ( (u4t_rqdat[0] & u4g_EMINJ_RQAINJD2) == (u4)0U )        /* ����2��ڕ��ˊJ�n�����v������ */
            {
                stt_minj_data.s2_eainjd2 = stt_minj_datdft.s2_eainjd2;
                stt_minj_data2.s2_eainjdn[1] = stt_minj_data.s2_eainjd2;
            }
            if ( (u4t_rqdat[0] & u4g_EMINJ_RQAINJD3) == (u4)0U )        /* ����3��ڕ��ˊJ�n�����v������ */
            {
                stt_minj_data.s2_eainjd3 = stt_minj_datdft.s2_eainjd3;
                stt_minj_data2.s2_eainjdn[2] = stt_minj_data.s2_eainjd3;
            }
            if ( (u4t_rqdat[0] & u4g_EMINJ_RQAINJD4) == (u4)0U )        /* ����4��ڕ��ˊJ�n�����v������ */
            {
                stt_minj_data.s2_eainjd4 = stt_minj_datdft.s2_eainjd4;
                stt_minj_data2.s2_eainjdn[3] = stt_minj_data.s2_eainjd4;
            }
            stt_minj_data2.s2_eainjdn[4] = s2s_EMINJ_AINJD_VD;
            stt_minj_data2.s2_eainjdn[5] = s2s_EMINJ_AINJD_VD;
        }
        else                                                            /* eminjst_tbl2�Aeminjast_tbl2�Aeminj_tbl2���⎞ */
        {
            if ( (u4t_rqdat[1] & u4g_EMINJ_RQAINJDN) == (u4)0U )        /* ����n��ڕ��ˊJ�n�����v������ */
            {
                stt_minj_data2.s2_eainjdn[0] = stt_minj_datdft2.s2_eainjdn[0];
                stt_minj_data.s2_eainjd1 = stt_minj_data2.s2_eainjdn[0];
                stt_minj_data2.s2_eainjdn[1] = stt_minj_datdft2.s2_eainjdn[1];
                stt_minj_data.s2_eainjd2 = stt_minj_data2.s2_eainjdn[1];
                stt_minj_data2.s2_eainjdn[2] = stt_minj_datdft2.s2_eainjdn[2];
                stt_minj_data.s2_eainjd3 = stt_minj_data2.s2_eainjdn[2];
                stt_minj_data2.s2_eainjdn[3] = stt_minj_datdft2.s2_eainjdn[3];
                stt_minj_data.s2_eainjd4 = stt_minj_data2.s2_eainjdn[3];
                stt_minj_data2.s2_eainjdn[4] = stt_minj_datdft2.s2_eainjdn[4];
                stt_minj_data2.s2_eainjdn[5] = stt_minj_datdft2.s2_eainjdn[5];
            }
            else                                                        /* ����n��ڕ��ˊJ�n�����v���L�� */
            {
                if ( u2t_injmod2 == u2g_EMINJ_MOD0N1 )                  /* �v������{���ː��䔽�f�v�����蓛���P�O�O���� */
                {
                    if ( ( u2t_binjmodmsk00F0 != (u2)0x0000U )          /* ��{���˗v���������P�O�O%�� */
                      && ( u2t_binjmodmsk0F0F == (u2)0x0001U ) )
                    {
                        stt_minj_data2.s2_eainjdn[0] = stt_binjctrdat.s2_eainjd1;
                        stt_minj_data.s2_eainjd1 = stt_minj_data2.s2_eainjdn[0];
                    }

 #if JEEFI == u1g_EJCC_DUAL     /*�y�ޭ��INJ�z*/
                    if ( u2t_binjmodmsk0F0F == (u2)0x0101U )            /* ��{���˗v���������P�O�O���łȂ��� */
                                                                        /* �������ˉ񐔂�0�ȏオ�����̂��߁A���������ȗ� */
                    {
                        stt_minj_data2.s2_eainjdn[0] = s2t_ainjdb1;
                        stt_minj_data.s2_eainjd1 = stt_minj_data2.s2_eainjdn[0];
                    }
 #endif /* JEEFI */
                }
            }
        }
        if ( (u4t_rqdat[0] & u4g_EMINJ_RQAINJCUTD) == (u4)0U )          /* �������ˋ����J�b�g�����v������ */
        {
            stt_minj_data.s2_eainjcutd = stt_minj_datdft.s2_eainjcutd;
        }
        if ( (u4t_rqdat[1] & u4g_EMINJ_RQAINJCUTD) == (u4)0U )          /* �������ˋ����J�b�g�����v������ */
        {
            stt_minj_data2.s2_eainjcutd = stt_minj_datdft2.s2_eainjcutd;
        }

#endif /* JEEFI */
        if ( (u4t_rqdat[0] & u4g_EMINJ_RQQFC) == (u4)0U )               /* FC�����˗ʗv���v������ */
        {
            for ( u1t_cyl = (u1)0U; u1t_cyl < u1t_ncyl_c; u1t_cyl++ )
            {
                stt_minj_data.s4_eqfc[u1t_cyl] = stt_minj_datdft.s4_eqfc[u1t_cyl];
            }
        }
        if ( (u4t_rqdat[1] & u4g_EMINJ_RQQFC) == (u4)0U )               /* FC�����˗ʗv���v������ */
        {
            for ( u1t_cyl = (u1)0U; u1t_cyl < u1t_ncyl_c; u1t_cyl++ )
            {
                stt_minj_data2.s4_eqfc[u1t_cyl] = stt_minj_datdft2.s4_eqfc[u1t_cyl];
            }
        }
#if JECOMBCCPT_E == u1g_EJCC_SPRAYG_E                   /*�y���ڰ�޲�ށz*/
        if ( (u4t_rqdat[0] & u4g_EMINJ_RQQINJEXP) == (u4)0U )           /* �c���s�����˗ʗv������ */
        {
            stt_minj_data.s4_eqinjexp = stt_minj_datdft.s4_eqinjexp;
        }
        if ( (u4t_rqdat[1] & u4g_EMINJ_RQQINJEXP) == (u4)0U )           /* �c���s�����˗ʗv������ */
        {
            stt_minj_data2.s4_eqinjexp = stt_minj_datdft2.s4_eqinjexp;
        }
#endif /* JECOMBCCPT_E */
        if ( (u4t_rqdat[0] & u4g_EMINJ_RQK1FN) != (u4)0U )              /* 1��ڕ��˗ʎZ�o�W��(�o���N��)�v���L�� */
        {
            s4t_k1f = (s4)stt_minj_data.s2_ek1fn[0];
#if JENOX == u1g_EJCC_TWIN      /*�y²ݾݻ�z*/
            s4t_k1f += (s4)stt_minj_data.s2_ek1fn[1];
            s4t_k1f = s4g_glbitcal_s4sftr_s4u1( s4t_k1f, (u1)1U );      /* 1/2 */
#endif /* JENOX */
            stt_minj_data.s2_ek1f = (s2)s4t_k1f;
        }
        else if ( (u4t_rqdat[0] & u4g_EMINJ_RQK1F) != (u4)0U )          /* 1��ڕ��˗ʎZ�o�W���v���L�� */
        {
            for ( u1t_mox = (u1)0U; u1t_mox < u1t_nox_c; u1t_mox++ )
            {
                stt_minj_data.s2_ek1fn[u1t_mox] = stt_minj_data.s2_ek1f;
                stt_minj_data2.s2_ek1fn[u1t_mox] = stt_minj_data.s2_ek1f;
            }
        }
        else                                                            /* 1��ڕ��˗ʎZ�o�W���i�o���N��/�o���N�ʁj�v������ */
        {
            stt_minj_data.s2_ek1f = stt_minj_datdft.s2_ek1f;
            for ( u1t_mox = (u1)0U; u1t_mox < u1t_nox_c; u1t_mox++ )
            {
                stt_minj_data.s2_ek1fn[u1t_mox] = stt_minj_datdft.s2_ek1fn[u1t_mox];
            }
        }
        if ( (u4t_rqdat[1] & u4g_EMINJ_RQK1FN) == (u4)0U )              /* 1��ڕ��˗ʎZ�o�W��(�o���N��)�v������ */
        {
            for ( u1t_mox = (u1)0U; u1t_mox < u1t_nox_c; u1t_mox++ )
            {
                stt_minj_data2.s2_ek1fn[u1t_mox] = stt_minj_datdft2.s2_ek1fn[u1t_mox];
            }
        }

        if ( (u4t_rqdat[0] & u4g_EMINJ_RQK2FN) != (u4)0U )              /* 2��ڕ��˗ʎZ�o�W��(�o���N��)�v���L�� */
        {
            s4t_k2f = (s4)stt_minj_data.s2_ek2fn[0];
#if JENOX == u1g_EJCC_TWIN      /*�y²ݾݻ�z*/
            s4t_k2f += (s4)stt_minj_data.s2_ek2fn[1];
            s4t_k2f = s4g_glbitcal_s4sftr_s4u1( s4t_k2f, (u1)1U );      /* 1/2 */
#endif /* JENOX */
            stt_minj_data.s2_ek2f = (s2)s4t_k2f;
        }
        else if ( (u4t_rqdat[0] & u4g_EMINJ_RQK2F) != (u4)0U )          /* 2��ڕ��˗ʎZ�o�W���v���L�� */
        {
            for ( u1t_mox = (u1)0U; u1t_mox < u1t_nox_c; u1t_mox++ )
            {
                stt_minj_data.s2_ek2fn[u1t_mox] = stt_minj_data.s2_ek2f;
                stt_minj_data2.s2_ek2fn[u1t_mox] = stt_minj_data.s2_ek2f;
            }
        }
        else                                                            /* 2��ڕ��˗ʎZ�o�W���i�o���N��/�o���N�ʁj�v������ */
        {
            stt_minj_data.s2_ek2f = stt_minj_datdft.s2_ek2f;
            for ( u1t_mox = (u1)0U; u1t_mox < u1t_nox_c; u1t_mox++ )
            {
                stt_minj_data.s2_ek2fn[u1t_mox] = stt_minj_datdft.s2_ek2fn[u1t_mox];
            }
        }
        if ( (u4t_rqdat[1] & u4g_EMINJ_RQK2FN) == (u4)0U )              /* 2��ڕ��˗ʎZ�o�W��(�o���N��)�v������ */
        {
            for ( u1t_mox = (u1)0U; u1t_mox < u1t_nox_c; u1t_mox++ )
            {
                stt_minj_data2.s2_ek2fn[u1t_mox] = stt_minj_datdft2.s2_ek2fn[u1t_mox];
            }
        }

        if ( (u4t_rqdat[0] & u4g_EMINJ_RQK3FN) != (u4)0U )              /* 3��ڕ��˗ʎZ�o�W��(�o���N��)�v���L�� */
        {
            s4t_k3f = (s4)stt_minj_data.s2_ek3fn[0];
#if JENOX == u1g_EJCC_TWIN      /*�y²ݾݻ�z*/
            s4t_k3f += (s4)stt_minj_data.s2_ek3fn[1];
            s4t_k3f = s4g_glbitcal_s4sftr_s4u1( s4t_k3f, (u1)1U );      /* 1/2 */
#endif /* JENOX */
            stt_minj_data.s2_ek3f = (s2)s4t_k3f;
        }
        else if ( (u4t_rqdat[0] & u4g_EMINJ_RQK3F) != (u4)0U )          /* 3��ڕ��˗ʎZ�o�W���v���L�� */
        {
            for ( u1t_mox = (u1)0U; u1t_mox < u1t_nox_c; u1t_mox++ )
            {
                stt_minj_data.s2_ek3fn[u1t_mox] = stt_minj_data.s2_ek3f;
                stt_minj_data2.s2_ek3fn[u1t_mox] = stt_minj_data.s2_ek3f;
            }
        }
        else                                                            /* 3��ڕ��˗ʎZ�o�W���i�o���N��/�o���N�ʁj�v������ */
        {
            stt_minj_data.s2_ek3f = stt_minj_datdft.s2_ek3f;
            for ( u1t_mox = (u1)0U; u1t_mox < u1t_nox_c; u1t_mox++ )
            {
                stt_minj_data.s2_ek3fn[u1t_mox] = stt_minj_datdft.s2_ek3fn[u1t_mox];
            }
        }
        if ( (u4t_rqdat[1] & u4g_EMINJ_RQK3FN) == (u4)0U )              /* 3��ڕ��˗ʎZ�o�W��(�o���N��)�v������ */
        {
            for ( u1t_mox = (u1)0U; u1t_mox < u1t_nox_c; u1t_mox++ )
            {
                stt_minj_data2.s2_ek3fn[u1t_mox] = stt_minj_datdft2.s2_ek3fn[u1t_mox];
            }
        }

#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
        if ( (u4t_rqdat[0] & u4g_EMINJ_RQPRREQ) == (u4)0U )             /* �����|���v�ڕW�R���v������ */
        {
            stt_minj_data.s2_eprreq = stt_minj_datdft.s2_eprreq;
        }
        else                                                            /* �����|���v�ڕW�R���v���L�� */
        {
            if ( ( u2t_injmod == u2g_EMINJ_MOD0N1 )                     /* �v������{���ː��䔽�f�v�����蓛���P�O�O���� */
              && ( ( u2t_binjmodmsk00F0 != (u2)0x0000U )                /* ��{���˗v���������P�O�O%�� */
                && ( u2t_binjmodmsk0F0F == (u2)0x0001U ) ) )
            {
                stt_minj_data.s2_eprreq = stt_binjctrdat.s2_eprreq;
            }
        }
#endif /* JEEFI */
#if JEPRDEMAND == u1g_EJCC_NOT_USE    /*�y�ϔR�����䖳�z*/
        if ( (u4t_rqdat[0] & u4g_EMINJ_RQQFREQ) == (u4)0U )             /* �R���|���v�f�o���ʗv������ */
        {
            stt_minj_data.s2_eqfreq = stt_minj_datdft.s2_eqfreq;
        }
#else                           /*�y�ϔR������L�z*/
        if ( (u4t_rqdat[0] & u4g_EMINJ_RQPRREQL) == (u4)0U )            /* �ሳ�|���v�ڕW�R���v������ */
        {
            stt_minj_data.s2_eprreql = stt_minj_datdft.s2_eprreql;
        }
#endif /* JEPRDEMAND */
        if ( (u4t_rqdat[0] & u4g_EMINJ_RQXQINJAST) == (u4)0U )          /* �n���㕬�˗ʗv���t���O�v������ */
                                                                        /* eminj_eminj_hpri()�ɂ����l�̏��������邽�ߕύX���͍��킹�Č��������� */
        {
            glbitcp_bibi( stt_minj_datdft.bi_exqinjast, stt_minj_data.bi_exqinjast );
        }
        if ( (u4t_rqdat[1] & u4g_EMINJ_RQXQINJAST) == (u4)0U )          /* �n���㕬�˗ʗv���t���O�v������ */
                                                                        /* eminj_eminj_hpri()�ɂ����l�̏��������邽�ߕύX���͍��킹�Č��������� */
        {
            glbitcp_bibi( stt_minj_datdft2.bi_exqinjast, stt_minj_data2.bi_exqinjast );
        }

        /* ekrchref[]�̏�����einjmodfix,ekpfix�Z�o��Ɏ��{ */

#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
        if ( (u4t_rqdat[0] & u4g_EMINJ_RQPLREQ) == (u4)0U )             /* �o�k���ˎ��{�v������ */
        {
            stt_minj_data.u1_explreq = stt_minj_datdft.u1_explreq;
        }
        if ( (u4t_rqdat[1] & u4g_EMINJ_RQPLREQ) == (u4)0U )             /* �o�k���ˎ��{�v������ */
        {
            stt_minj_data2.u1_explreq = stt_minj_datdft2.u1_explreq;
        }

#endif /* JEEFI */

        if ( (u4t_rqdat[1] & u4g_EMINJ_RQQINJFLFIX) == (u4)0U )         /* �e�k�Œ蕬�˗ʗv������ */
        {
            for ( u1t_injnum = (u1)0U; u1t_injnum < (u1)8U; u1t_injnum++ )
            {
                stt_minj_data2.s4_eqinjflfix[u1t_injnum] = stt_minj_datdft2.s4_eqinjflfix[u1t_injnum];
            }
        }

        if ( (u4t_rqdat[1] & u4g_EMINJ_RQQINJPLFIX) == (u4)0U )         /* �o�k�Œ蕬�˗ʗv������ */
        {
            for ( u1t_injnum = (u1)0U; u1t_injnum < (u1)8U; u1t_injnum++ )
            {
                stt_minj_data2.s4_eqinjplfix[u1t_injnum] = stt_minj_datdft2.s4_eqinjplfix[u1t_injnum];
            }
        }

        if ( u1t_xnercdfew == (u1)ON )                      /* NE�����^�X�N�����Ȃ� */
        {
#if JEEFI != u1g_EJCC_D4        /*�yD-4�ȊO�z*/
            s4t_kqstmxp = (s4)s2g_eclrfld_ekqstmxp;
            if ( (u1s_eminj_estpri2 != u1s_eminj_eprisel_fix)
              && (u1s_eminj_eastpri2 != u1s_eminj_eprisel_fix)
              && (u1s_eminj_epri2 != u1s_eminj_eprisel_fix) )   /* eminjst_tbl�Aeminjast_tbl�Aeminj_tbl���⎞ */
            {
                if ( ( (u4t_rqdat[0] & u4g_EMINJ_RQQINJSTP1) == (u4)0U )    /* �|�[�g1��ڎn�������˗ʗv������ */
                  && ( (u4t_rqdat[0] & u4g_EMINJ_RQQINJSTP) == (u4)0U ) )   /* �|�[�g�n�������˗ʗv������ */
                {
                    stt_minj_data.s4_eqinjstp1 = stt_minj_datdft.s4_eqinjstp1;
                }
                else                                                        /* �|�[�g1��ڎn�������˗ʗv���L�� */
                {
                    stt_minj_data.s4_eqinjstp1 = s4g_glmulst_s4s4u2( stt_minj_data.s4_eqinjstp1, s4t_kqstmxp, (u2)8U );
                                    /* lsb= (4096*1024)/128/256/256/256 * 128/128/256 -> (4096*1024)/128/256/256/256 */
                }
                if ( (u4t_rqdat[0] & u4g_EMINJ_RQQINJSTP2) == (u4)0U )      /* �|�[�g2��ڎn�������˗ʗv������ */
                {
                    stt_minj_data.s4_eqinjstp2 = stt_minj_datdft.s4_eqinjstp2;
                }
                else                                                        /* �|�[�g2��ڎn�������˗ʗv���L�� */
                {
                    stt_minj_data.s4_eqinjstp2 = s4g_glmulst_s4s4u2( stt_minj_data.s4_eqinjstp2, s4t_kqstmxp, (u2)8U );
                                    /* lsb= (4096*1024)/128/256/256/256 * 128/128/256 -> (4096*1024)/128/256/256/256 */
                }
                if ( (u4t_rqdat[0] & u4g_EMINJ_RQQINJSTP3) == (u4)0U )      /* �|�[�g3��ڎn�������˗ʗv������ */
                {
                    stt_minj_data.s4_eqinjstp3 = stt_minj_datdft.s4_eqinjstp3;
                }
                else                                                        /* �|�[�g3��ڎn�������˗ʗv���L�� */
                {
                    stt_minj_data.s4_eqinjstp3 = s4g_glmulst_s4s4u2( stt_minj_data.s4_eqinjstp3, s4t_kqstmxp, (u2)8U );
                                    /* lsb= (4096*1024)/128/256/256/256 * 128/128/256 -> (4096*1024)/128/256/256/256 */
                }
                if ( (u4t_rqdat[0] & u4g_EMINJ_RQQINJSTP4) == (u4)0U )      /* �|�[�g4��ڎn�������˗ʗv������ */
                {
                    stt_minj_data.s4_eqinjstp4 = stt_minj_datdft.s4_eqinjstp4;
                }
                else                                                        /* �|�[�g4��ڎn�������˗ʗv���L�� */
                {
                    stt_minj_data.s4_eqinjstp4 = s4g_glmulst_s4s4u2( stt_minj_data.s4_eqinjstp4, s4t_kqstmxp, (u2)8U );
                                    /* lsb= (4096*1024)/128/256/256/256 * 128/128/256 -> (4096*1024)/128/256/256/256 */
                }
                stt_minj_data2.s4_eqinjstpn[0] = stt_minj_data.s4_eqinjstp1;
                stt_minj_data2.s4_eqinjstpn[1] = stt_minj_data.s4_eqinjstp2;
                stt_minj_data2.s4_eqinjstpn[2] = stt_minj_data.s4_eqinjstp3;
                stt_minj_data2.s4_eqinjstpn[3] = stt_minj_data.s4_eqinjstp4;
            }
            else                                                            /* eminjst_tbl2�Aeminjast_tbl2�Aeminj_tbl2���⎞ */
            {
                if ( (u4t_rqdat[1] & u4g_EMINJ_RQQINJSTPN) == (u4)0U )      /* �|�[�gn��ڎn�������˗ʗv������ */
                {
                    stt_minj_data2.s4_eqinjstpn[0] = stt_minj_datdft2.s4_eqinjstpn[0];
                    stt_minj_data2.s4_eqinjstpn[1] = stt_minj_datdft2.s4_eqinjstpn[1];
                    stt_minj_data2.s4_eqinjstpn[2] = stt_minj_datdft2.s4_eqinjstpn[2];
                    stt_minj_data2.s4_eqinjstpn[3] = stt_minj_datdft2.s4_eqinjstpn[3];
                }
                else                                                        /* �|�[�gn��ڎn�������˗ʗv���L�� */
                {
                    stt_minj_data2.s4_eqinjstpn[0] = s4g_glmulst_s4s4u2( stt_minj_data2.s4_eqinjstpn[0], s4t_kqstmxp, (u2)8U );
                    stt_minj_data2.s4_eqinjstpn[1] = s4g_glmulst_s4s4u2( stt_minj_data2.s4_eqinjstpn[1], s4t_kqstmxp, (u2)8U );
                    stt_minj_data2.s4_eqinjstpn[2] = s4g_glmulst_s4s4u2( stt_minj_data2.s4_eqinjstpn[2], s4t_kqstmxp, (u2)8U );
                    stt_minj_data2.s4_eqinjstpn[3] = s4g_glmulst_s4s4u2( stt_minj_data2.s4_eqinjstpn[3], s4t_kqstmxp, (u2)8U );
                                    /* lsb= (4096*1024)/128/256/256/256 * 128/128/256 -> (4096*1024)/128/256/256/256 */
                }
                stt_minj_data.s4_eqinjstp1 = stt_minj_data2.s4_eqinjstpn[0];
                stt_minj_data.s4_eqinjstp2 = stt_minj_data2.s4_eqinjstpn[1];
                stt_minj_data.s4_eqinjstp3 = stt_minj_data2.s4_eqinjstpn[2];
                stt_minj_data.s4_eqinjstp4 = stt_minj_data2.s4_eqinjstpn[3];
            }
#endif /* JEEFI */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
            s4t_kqstmxd = (s4)s2g_eclrfld_ekqstmxd;
            if ( (u1s_eminj_estpri2 != u1s_eminj_eprisel_fix)
              && (u1s_eminj_eastpri2 != u1s_eminj_eprisel_fix)
              && (u1s_eminj_epri2 != u1s_eminj_eprisel_fix) )   /* eminjst_tbl�Aeminjast_tbl�Aeminj_tbl���⎞ */
            {
                if ( (u4t_rqdat[0] & u4g_EMINJ_RQQINJSTD1) == (u4)0U )      /* ����1��ڎn�������˗ʗv������ */
                {
                    stt_minj_data.s4_eqinjstd1 = stt_minj_datdft.s4_eqinjstd1;
                }
                else                                                        /* ����1��ڎn�������˗ʗv���L�� */
                {
                    stt_minj_data.s4_eqinjstd1 = s4g_glmulst_s4s4u2( stt_minj_data.s4_eqinjstd1, s4t_kqstmxd, (u2)8U );
                                    /* lsb= (4096*1024)/128/256/256/256 * 128/128/256 -> (4096*1024)/128/256/256/256 */
                }
                if ( (u4t_rqdat[0] & u4g_EMINJ_RQQINJSTD2) == (u4)0U )      /* ����2��ڎn�������˗ʗv������ */
                {
                    stt_minj_data.s4_eqinjstd2 = stt_minj_datdft.s4_eqinjstd2;
                }
                else                                                        /* ����2��ڎn�������˗ʗv���L�� */
                {
                    stt_minj_data.s4_eqinjstd2 = s4g_glmulst_s4s4u2( stt_minj_data.s4_eqinjstd2, s4t_kqstmxd, (u2)8U );
                                    /* lsb= (4096*1024)/128/256/256/256 * 128/128/256 -> (4096*1024)/128/256/256/256 */
                }
                if ( (u4t_rqdat[0] & u4g_EMINJ_RQQINJSTD3) == (u4)0U )      /* ����3��ڎn�������˗ʗv������ */
                {
                    stt_minj_data.s4_eqinjstd3 = stt_minj_datdft.s4_eqinjstd3;
                }
                else                                                        /* ����3��ڎn�������˗ʗv���L�� */
                {
                    stt_minj_data.s4_eqinjstd3 = s4g_glmulst_s4s4u2( stt_minj_data.s4_eqinjstd3, s4t_kqstmxd, (u2)8U );
                                    /* lsb= (4096*1024)/128/256/256/256 * 128/128/256 -> (4096*1024)/128/256/256/256 */
                }
                if ( (u4t_rqdat[0] & u4g_EMINJ_RQQINJSTD4) == (u4)0U )      /* ����4��ڎn�������˗ʗv������ */
                {
                    stt_minj_data.s4_eqinjstd4 = stt_minj_datdft.s4_eqinjstd4;
                }
                else                                                        /* ����4��ڎn�������˗ʗv���L�� */
                {
                    stt_minj_data.s4_eqinjstd4 = s4g_glmulst_s4s4u2( stt_minj_data.s4_eqinjstd4, s4t_kqstmxd, (u2)8U );
                                    /* lsb= (4096*1024)/128/256/256/256 * 128/128/256 -> (4096*1024)/128/256/256/256 */
                }
                stt_minj_data2.s4_eqinjstdn[0] = stt_minj_data.s4_eqinjstd1;
                stt_minj_data2.s4_eqinjstdn[1] = stt_minj_data.s4_eqinjstd2;
                stt_minj_data2.s4_eqinjstdn[2] = stt_minj_data.s4_eqinjstd3;
                stt_minj_data2.s4_eqinjstdn[3] = stt_minj_data.s4_eqinjstd4;
                stt_minj_data2.s4_eqinjstdn[4] = s4s_EMINJ_QINJ_VD;
                stt_minj_data2.s4_eqinjstdn[5] = s4s_EMINJ_QINJ_VD;
            }
            else                                                            /* eminjst_tbl2�Aeminjast_tbl2�Aeminj_tbl2���⎞ */
            {
                if ( (u4t_rqdat[1] & u4g_EMINJ_RQQINJSTDN) == (u4)0U )      /* ����n��ڎn�������˗ʗv������ */
                {
                    stt_minj_data2.s4_eqinjstdn[0] = stt_minj_datdft2.s4_eqinjstdn[0];
                    stt_minj_data2.s4_eqinjstdn[1] = stt_minj_datdft2.s4_eqinjstdn[1];
                    stt_minj_data2.s4_eqinjstdn[2] = stt_minj_datdft2.s4_eqinjstdn[2];
                    stt_minj_data2.s4_eqinjstdn[3] = stt_minj_datdft2.s4_eqinjstdn[3];
                    stt_minj_data2.s4_eqinjstdn[4] = stt_minj_datdft2.s4_eqinjstdn[4];
                    stt_minj_data2.s4_eqinjstdn[5] = stt_minj_datdft2.s4_eqinjstdn[5];
                }
                else                                                        /* ����n��ڎn�������˗ʗv���L�� */
                {
                    stt_minj_data2.s4_eqinjstdn[0] = s4g_glmulst_s4s4u2( stt_minj_data2.s4_eqinjstdn[0], s4t_kqstmxd, (u2)8U );
                    stt_minj_data2.s4_eqinjstdn[1] = s4g_glmulst_s4s4u2( stt_minj_data2.s4_eqinjstdn[1], s4t_kqstmxd, (u2)8U );
                    stt_minj_data2.s4_eqinjstdn[2] = s4g_glmulst_s4s4u2( stt_minj_data2.s4_eqinjstdn[2], s4t_kqstmxd, (u2)8U );
                    stt_minj_data2.s4_eqinjstdn[3] = s4g_glmulst_s4s4u2( stt_minj_data2.s4_eqinjstdn[3], s4t_kqstmxd, (u2)8U );
                    stt_minj_data2.s4_eqinjstdn[4] = s4g_glmulst_s4s4u2( stt_minj_data2.s4_eqinjstdn[4], s4t_kqstmxd, (u2)8U );
                    stt_minj_data2.s4_eqinjstdn[5] = s4g_glmulst_s4s4u2( stt_minj_data2.s4_eqinjstdn[5], s4t_kqstmxd, (u2)8U );
                                    /* lsb= (4096*1024)/128/256/256/256 * 128/128/256 -> (4096*1024)/128/256/256/256 */
                }
                stt_minj_data.s4_eqinjstd1 = stt_minj_data2.s4_eqinjstdn[0];
                stt_minj_data.s4_eqinjstd2 = stt_minj_data2.s4_eqinjstdn[1];
                stt_minj_data.s4_eqinjstd3 = stt_minj_data2.s4_eqinjstdn[2];
                stt_minj_data.s4_eqinjstd4 = stt_minj_data2.s4_eqinjstdn[3];
            }
#endif /* JEEFI */
        }
    }

    /* ekpfi�i�|�[�g���˗ʎZ�o�W���j�Aekpfin[NOX]�i�|�[�g���˗ʎZ�o�W��(�o���N��)�j�̎Z�o */
#if JEEFI != u1g_EJCC_D4        /*�yD-4�ȊO�z*/
    u2t_injmodmsk0F00 = (stt_minj_data.u2_einjmod & (u2)0x0F00U);
    u2t_injmodmsk00F0 = (stt_minj_data.u2_einjmod & (u2)0x00F0U);
    u2t_injmodmsk000F = (stt_minj_data.u2_einjmod & (u2)0x000FU);
#endif /* JEEFI */
#if JEEFI == u1g_EJCC_DUAL      /*�y�ޭ��INJ�z*/
    if ( u2t_injmodmsk000F == (u2)0x0000U )                  /* ���˒�~�� */
    {
        s2t_kpfi_wk = (s2)(((0.)/((1.*4.)/128./256.))+0.5);
        for ( u1t_mox = (u1)0U; u1t_mox < u1t_nox_c; u1t_mox++ )
        {
            s2t_kpfin[u1t_mox] = (s2)(((0.)/((1.*4.)/128./256.))+0.5);
        }
    }
    else if ( u2t_injmodmsk00F0 == (u2)0x0000U )             /* �|�[�g���ˎ� */
    {
        s2t_kpfi_wk = (s2)(((1.)/((1.*4.)/128./256.))+0.5);
        for ( u1t_mox = (u1)0U; u1t_mox < u1t_nox_c; u1t_mox++ )
        {
            s2t_kpfin[u1t_mox] = (s2)(((1.)/((1.*4.)/128./256.))+0.5);
        }
    }
    else if ( u2t_injmodmsk0F00 == (u2)0x0000U )             /* �������ˎ� */
    {
        s2t_kpfi_wk = (s2)(((0.)/((1.*4.)/128./256.))+0.5);
        for ( u1t_mox = (u1)0U; u1t_mox < u1t_nox_c; u1t_mox++ )
        {
            s2t_kpfin[u1t_mox] = (s2)(((0.)/((1.*4.)/128./256.))+0.5);
        }
    }
    else if ( u2t_injmodmsk0F00 == (u2)0x0100U )             /* �f���A������ */
    {
        if ( stt_minj_data.bi_exqinjast == (u1)ON )          /* �n���� */
        {
            s2t_kpfi_wk = stt_minj_data.s2_ek1fn[0];
            for ( u1t_mox = (u1)0U; u1t_mox < u1t_nox_c; u1t_mox++ )
            {
                s2t_kpfin[u1t_mox] = stt_minj_data.s2_ek1fn[u1t_mox];
            }
        }
        else
        {
            s4t_qinjadd = s4g_gladdst_s4s4( stt_minj_data.s4_eqinjstp1, stt_minj_data.s4_eqinjstp2 );
            s4t_qinjadd = s4g_gladdst_s4s4( s4t_qinjadd, stt_minj_data.s4_eqinjstp3 );
            s4t_qinjadd = s4g_gladdst_s4s4( s4t_qinjadd, stt_minj_data.s4_eqinjstp4 );
            s4t_qinjadd2 = s4g_gladdst_s4s4( s4t_qinjadd, stt_minj_data.s4_eqinjstd1 );
            s4t_qinjadd2 = s4g_gladdst_s4s4( s4t_qinjadd2, stt_minj_data.s4_eqinjstd2 );
            s4t_qinjadd2 = s4g_gladdst_s4s4( s4t_qinjadd2, stt_minj_data.s4_eqinjstd3 );
            s4t_qinjadd2 = s4g_gladdst_s4s4( s4t_qinjadd2, stt_minj_data.s4_eqinjstd4 );

            s4t_qinjdiv = s4g_gldiv_s4s4( (s4)(((1.)/(2./128./256./256./256.))+0.5), s4t_qinjadd2 );
                                /* lsb= 2/128/256/256/256 / (4096*1024)/128/256/256/256 -> (16*64)/128/256/256/256 */
                                /* s4t_qinjadd�̍�13bit�V�t�g������邽�߁A���Z���̋t�������߂ď�Z�����ɂ��� */
            s4t_kpfi = s4g_glmulst_s4s4u2( s4t_qinjadd, s4t_qinjdiv, (u2)17U );
                                /* lsb= (4096*1024)/128/256/256/256 * (16*64)/128/256/256/256 -> (1*4)/128/256 */

            ELIB_HILOGD2( s4t_kpfi, (s4)s2g_S2MAX, (s4)s2g_S2MIN, s4t_kpfi );
            s2t_kpfi_wk = (s2)s4t_kpfi;
            for ( u1t_mox = (u1)0U; u1t_mox < u1t_nox_c; u1t_mox++ )
            {
                s2t_kpfin[u1t_mox] = (s2)s4t_kpfi;
            }
        }
    }
    else
    {
        s2t_kpfi_wk = (s2)(((1.)/((1.*4.)/128./256.))+0.5);
        for ( u1t_mox = (u1)0U; u1t_mox < u1t_nox_c; u1t_mox++ )
        {
            s2t_kpfin[u1t_mox] = (s2)(((1.)/((1.*4.)/128./256.))+0.5);
        }
    }
#elif JEEFI == u1g_EJCC_PORT    /*�y�߰āz*/
    s2t_kpfi_wk = (s2)(((1.)/((1.*4.)/128./256.))+0.5);
    for ( u1t_mox = (u1)0U; u1t_mox < u1t_nox_c; u1t_mox++ )
    {
        s2t_kpfin[u1t_mox] = (s2)(((1.)/((1.*4.)/128./256.))+0.5);
    }
#else                           /* (�y�ޭ��INJ�zOR�y�߰āz)�ȊO */
    s2t_kpfi_wk = (s2)(((0.)/((1.*4.)/128./256.))+0.5);
    for ( u1t_mox = (u1)0U; u1t_mox < u1t_nox_c; u1t_mox++ )
    {
        s2t_kpfin[u1t_mox] = (s2)(((0.)/((1.*4.)/128./256.))+0.5);
    }
#endif /* JEEFI */

#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    /* �������ˊJ�n�����̐��� */
    stt_injdat.s2_eainjd1 = stt_minj_data.s2_eainjd1;
    ELIB_HILOGD2( stt_injdat.s2_eainjd1, s2s_EMINJ_AINJD_MX, s2s_EMINJ_AINJD_MN, stt_injdat.s2_eainjd1 );
    stt_injdat.f4_eainjd1 = (f4)stt_injdat.s2_eainjd1 * (f4)(1024./128./256.);
    stt_injdat.s2_eainjd2 = stt_minj_data.s2_eainjd2;
    ELIB_HILOGD2( stt_injdat.s2_eainjd2, s2s_EMINJ_AINJD_MX, s2s_EMINJ_AINJD_MN, stt_injdat.s2_eainjd2 );
    stt_injdat.f4_eainjd2 = (f4)stt_injdat.s2_eainjd2 * (f4)(1024./128./256.);
    stt_injdat.s2_eainjd3 = stt_minj_data.s2_eainjd3;
    ELIB_HILOGD2( stt_injdat.s2_eainjd3, s2s_EMINJ_AINJD_MX, s2s_EMINJ_AINJD_MN, stt_injdat.s2_eainjd3 );
    stt_injdat.f4_eainjd3 = (f4)stt_injdat.s2_eainjd3 * (f4)(1024./128./256.);
    stt_injdat.s2_eainjd4 = stt_minj_data.s2_eainjd4;
    ELIB_HILOGD2( stt_injdat.s2_eainjd4, s2s_EMINJ_AINJD_MX, s2s_EMINJ_AINJD_MN, stt_injdat.s2_eainjd4 );
    stt_injdat.f4_eainjd4 = (f4)stt_injdat.s2_eainjd4 * (f4)(1024./128./256.);
    stt_injdat2.s2_eainjdn[0] = stt_minj_data2.s2_eainjdn[0];
    ELIB_HILOGD2( stt_injdat2.s2_eainjdn[0], s2s_EMINJ_AINJD_MX, s2s_EMINJ_AINJD_MN, stt_injdat2.s2_eainjdn[0] );
    stt_injdat2.f4_eainjdn[0] = (f4)stt_injdat2.s2_eainjdn[0] * (f4)(1024./128./256.);
    stt_injdat2.s2_eainjdn[1] = stt_minj_data2.s2_eainjdn[1];
    ELIB_HILOGD2( stt_injdat2.s2_eainjdn[1], s2s_EMINJ_AINJD_MX, s2s_EMINJ_AINJD_MN, stt_injdat2.s2_eainjdn[1] );
    stt_injdat2.f4_eainjdn[1] = (f4)stt_injdat2.s2_eainjdn[1] * (f4)(1024./128./256.);
    stt_injdat2.s2_eainjdn[2] = stt_minj_data2.s2_eainjdn[2];
    ELIB_HILOGD2( stt_injdat2.s2_eainjdn[2], s2s_EMINJ_AINJD_MX, s2s_EMINJ_AINJD_MN, stt_injdat2.s2_eainjdn[2] );
    stt_injdat2.f4_eainjdn[2] = (f4)stt_injdat2.s2_eainjdn[2] * (f4)(1024./128./256.);
    stt_injdat2.s2_eainjdn[3] = stt_minj_data2.s2_eainjdn[3];
    ELIB_HILOGD2( stt_injdat2.s2_eainjdn[3], s2s_EMINJ_AINJD_MX, s2s_EMINJ_AINJD_MN, stt_injdat2.s2_eainjdn[3] );
    stt_injdat2.f4_eainjdn[3] = (f4)stt_injdat2.s2_eainjdn[3] * (f4)(1024./128./256.);
    stt_injdat2.s2_eainjdn[4] = stt_minj_data2.s2_eainjdn[4];
    ELIB_HILOGD2( stt_injdat2.s2_eainjdn[4], s2s_EMINJ_AINJD_MX, s2s_EMINJ_AINJD_MN, stt_injdat2.s2_eainjdn[4] );
    stt_injdat2.f4_eainjdn[4] = (f4)stt_injdat2.s2_eainjdn[4] * (f4)(1024./128./256.);
    stt_injdat2.s2_eainjdn[5] = stt_minj_data2.s2_eainjdn[5];
    ELIB_HILOGD2( stt_injdat2.s2_eainjdn[5], s2s_EMINJ_AINJD_MX, s2s_EMINJ_AINJD_MN, stt_injdat2.s2_eainjdn[5] );
    stt_injdat2.f4_eainjdn[5] = (f4)stt_injdat2.s2_eainjdn[5] * (f4)(1024./128./256.);
#endif /* JEEFI */

    /* einjmodfix�i���݊m�蕬�˃��[�h�j�Aekpfix�i�|�[�g���˗ʎZ�o�W���j�̎Z�o */
    u2g_eminj_einjmodfix = stt_minj_data.u2_einjmod;
    s2g_eminj_ekpfix = s2t_kpfi_wk;
    f4g_eminj_ekpfix = (f4)s2t_kpfi_wk * (f4)((1.*4.)/128./256.);

#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    /* eainjd1fix�i�m�蓛��1��ڕ��ˊJ�n�����j�Aeainjd2fix�i�m�蓛��2��ڕ��ˊJ�n�����j�A     */
    /* eainjd3fix�i�m�蓛��3��ڕ��ˊJ�n�����j�Aeainjd4fix�i�m�蓛��4��ڕ��ˊJ�n�����j�A     */
    /* eainjd5fix�i�m�蓛��5��ڕ��ˊJ�n�����j�Aeainjd6fix�i�m�蓛��6��ڕ��ˊJ�n�����j�̎Z�o */
    if ( ( u1s_eminj_estpri2 == u1s_eminj_eprisel_fix )
      || ( u1s_eminj_eastpri2 == u1s_eminj_eprisel_fix )
      || ( u1s_eminj_epri2 == u1s_eminj_eprisel_fix ) )     /* eminjst_tbl2�Aeminjast_tbl2�Aeminj_tbl2���⎞ */
    {
        f4g_eminj_eainjd1fix = stt_injdat2.f4_eainjdn[0];
        f4g_eminj_eainjd2fix = stt_injdat2.f4_eainjdn[1];
        f4g_eminj_eainjd3fix = stt_injdat2.f4_eainjdn[2];
        f4g_eminj_eainjd4fix = stt_injdat2.f4_eainjdn[3];
        f4g_eminj_eainjd5fix = stt_injdat2.f4_eainjdn[4];
        f4g_eminj_eainjd6fix = stt_injdat2.f4_eainjdn[5];
    }
    else                                                    /* eminjst_tbl�Aeminjast_tbl�Aeminj_tbl���⎞ */
    {
        f4g_eminj_eainjd1fix = stt_injdat.f4_eainjd1;
        f4g_eminj_eainjd2fix = stt_injdat.f4_eainjd2;
        f4g_eminj_eainjd3fix = stt_injdat.f4_eainjd3;
        f4g_eminj_eainjd4fix = stt_injdat.f4_eainjd4;
        f4g_eminj_eainjd5fix = (f4)s2s_EMINJ_AINJD_VD * (f4)(1024./128./256.);
        f4g_eminj_eainjd6fix = (f4)s2s_EMINJ_AINJD_VD * (f4)(1024./128./256.);
    }
#endif /* JEEFI */

    /* ek1ffix�i�m��1��ڕ��˗ʎZ�o�W���j�Aek2ffix�i�m��2��ڕ��˗ʎZ�o�W���j�A */
    /* ek3ffix�i�m��3��ڕ��˗ʎZ�o�W���j�̎Z�o                                 */
    /* �K�[�h�܂ލŏI�l�Ɠ����̒��Ԓl���g�����Ƃ��\�Ȃ��߁A�����ȑf���̂��߂ɒ��Ԓl�Q�Ƃ��� */
    f4g_eminj_ek1ffix = (f4)stt_minj_data.s2_ek1f * (f4)((1.*4.)/128./256.);
    f4g_eminj_ek2ffix = (f4)stt_minj_data.s2_ek2f * (f4)((1.*4.)/128./256.);
    f4g_eminj_ek3ffix = (f4)stt_minj_data.s2_ek3f * (f4)((1.*4.)/128./256.);

    /* ekrchref[NOX]�i���˗ʕ␳�W���j�̎Z�o */
    /* ekrchref[]�̏�����einjmodfix�Aekpfix�Aeainjd1fix�Aeainjd2fix�Aeainjd3fix�Aeainjd4fix�Aek1ffix�Aek2ffix�Aek3ffix�Z�o���{��ɍs������ */
    vdg_emkrichb_ekrichxb_get();                                      /* �R�[�����einjmodfix,ekpfix�Aeainjd1fix�Aeainjd2fix�Aeainjd3fix�Aeainjd4fix�Aek1ffix�Aek2ffix�Aek3ffix���Q�ƁAemkrichb_ekrichxbcrt[]���X�V */
    for ( u1t_mox = (u1)0U; u1t_mox < u1t_nox_c; u1t_mox++ )
    {
        s2t_krichxbcrt[u1t_mox] = s2g_emkrichb_ekrichxbcrt[u1t_mox];  /* emkrichb_ekrichxb_get()�R�[����ɎQ�Ƃ��邱�� */
        stt_minj_datdft.s2_ekrchref[u1t_mox] = s2t_krichxbcrt[u1t_mox];
        stt_minj_datdft2.s2_ekrchref[u1t_mox] = s2t_krichxbcrt[u1t_mox];
    }

    if ( ( u1t_injmedislid == u1g_EMINJ_NONE_ID )               /* �D��I��v�������� */
      || ( ( u1t_injmedislid != u1g_EMINJ_NONE_ID )             /* �D��I��v�����莞 */
        && ( (u4t_rqdat[0] & u4g_EMINJ_RQKRCHREF) == (u4)0U ) ) )  /* ���˗ʕ␳�W���v������ */
    {
        for ( u1t_mox = (u1)0U; u1t_mox < u1t_nox_c; u1t_mox++ )
        {
            stt_minj_data.s2_ekrchref[u1t_mox] = stt_minj_datdft.s2_ekrchref[u1t_mox];
        }
    }

    if ( ( u1t_injmedislid == u1g_EMINJ_NONE_ID )               /* �D��I��v�������� */
      || ( ( u1t_injmedislid != u1g_EMINJ_NONE_ID )             /* �D��I��v�����莞 */
        && ( (u4t_rqdat[1] & u4g_EMINJ_RQKRCHREF) == (u4)0U ) ) )  /* ���˗ʕ␳�W���v������ */
    {
        for ( u1t_mox = (u1)0U; u1t_mox < u1t_nox_c; u1t_mox++ )
        {
            stt_minj_data2.s2_ekrchref[u1t_mox] = stt_minj_datdft2.s2_ekrchref[u1t_mox];
        }
    }

    /* ekrichx�i���˗ʕ␳�W���j�̎Z�o */
    s2t_krichx = s2t_krichxbcrt[0];
#if JENOX == u1g_EJCC_TWIN      /*�y²ݾݻ�z*/
    ELIB_MAXSLCT2( s2t_krichx, s2t_krichxbcrt[1], s2t_krichx );
#endif /* JENOX */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    if ( ( u1t_injmedislid == u1g_EMINJ_SJC_ID )        /* �G�}�}���g�@���䕬�ˑI���� */
      || ( u1t_injmedislid == u1g_EMINJ_STRATIST_ID ) ) /* ���w�n�����䎞���ˑI���� */
    {
        s2t_krichx = stt_minj_data.s2_ekrchref[0];
                    /* ekrchref[0]�́Aeinjmedislid��SJC_ID����esjc_efsjc�A */
                    /* STRATIST_ID����estratist_efstrt���i�[����Ă��邽�ߎd�l�ƈ�v���� */
    }
#endif /* JEEFI */

    if ( u1t_xnercdfew == (u1)ON )                      /* NE�����^�X�N�����Ȃ� */
    {
        /* �|�[�g���˗ʎZ�o�W��(ekpfi)�ɉ������n�������˗ʂ̃N���A */
#if JEEFI != u1g_EJCC_D4        /*�yD-4�ȊO�z*/
        if ( s2t_kpfi_wk == (s2)(((0.)/((1.*4.)/128./256.))+0.5) )    /* �������ˎ� */
        {
            stt_minj_data.s4_eqinjstp1 = s4s_EMINJ_QINJI;
            stt_minj_data.s4_eqinjstp2 = s4s_EMINJ_QINJI;
            stt_minj_data.s4_eqinjstp3 = s4s_EMINJ_QINJI;
            stt_minj_data.s4_eqinjstp4 = s4s_EMINJ_QINJI;
            stt_minj_data2.s4_eqinjstpn[0] = s4s_EMINJ_QINJI;
            stt_minj_data2.s4_eqinjstpn[1] = s4s_EMINJ_QINJI;
            stt_minj_data2.s4_eqinjstpn[2] = s4s_EMINJ_QINJI;
            stt_minj_data2.s4_eqinjstpn[3] = s4s_EMINJ_QINJI;
        }
#endif /* JEEFI */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
        if ( s2t_kpfi_wk == (s2)(((1.)/((1.*4.)/128./256.))+0.5) )    /* �|�[�g���ˎ� */
        {
            stt_minj_data.s4_eqinjstd1 = s4s_EMINJ_QINJI;
            stt_minj_data.s4_eqinjstd2 = s4s_EMINJ_QINJI;
            stt_minj_data.s4_eqinjstd3 = s4s_EMINJ_QINJI;
            stt_minj_data.s4_eqinjstd4 = s4s_EMINJ_QINJI;
            stt_minj_data2.s4_eqinjstdn[0] = s4s_EMINJ_QINJI;
            stt_minj_data2.s4_eqinjstdn[1] = s4s_EMINJ_QINJI;
            stt_minj_data2.s4_eqinjstdn[2] = s4s_EMINJ_QINJI;
            stt_minj_data2.s4_eqinjstdn[3] = s4s_EMINJ_QINJI;
            stt_minj_data2.s4_eqinjstdn[4] = s4s_EMINJ_QINJI;
            stt_minj_data2.s4_eqinjstdn[5] = s4s_EMINJ_QINJI;
        }
#endif /* JEEFI */
    }

#if JEEFI == u1g_EJCC_DUAL      /*�y�ޭ��INJ�z*/
 #if (((JEPLMLT_E == u1g_EJCC_USE) && (EMINJ_BINJPLCTR_MEDI == ON)) \
   || ((JEALLHV_E == u1g_EJCC_ALLHV_E) && (JEPLMLT_E == u1g_EJCC_USE) && (EMINJ_BINJPLCTR_WC_MEDI == ON)) \
   || ((JEEGMG_E == u1g_EJCC_HVPLGR_E) && (JEFFV == u1g_EJCC_NOT_USE) && (JEPLMLT_E == u1g_EJCC_USE) && (EMINJ_BINJPLCTR_STAHV_MEDI == ON)))
   /* (�yPL������˗L�zAND�y�߰�����ĕ��˂�p������{���ː���v���g�p�z) */
   /* OR (�yALL HV�zAND�yPL������˗L�zAND�y�߰�����ĕ��˂�p������{���ː���(�G�}�g�@��)�v���g�p�z) */
   /* OR (�yEG-MG�V���ޱ�zAND�yFFV���䖳�zAND�yPL������˗L�zAND�y�߰�����ĕ��˂�p������{���ː���(HV�n�����䎞)�v���g�p�z) */
    f4t_kpfit = f4g_ebinjplctr_ekpfit;
    for ( u1t_mox = (u1)0U; u1t_mox < u1t_nox_c; u1t_mox++ )
    {
        f4t_kpfitn[u1t_mox] = f4g_ebinjplctr_ekpfitn[u1t_mox];
    }
 #endif /* JEPLMLT_E,EMINJ_BINJPLCTR_MEDI,JEALLHV_E,EMINJ_BINJPLCTR_WC_MEDI,JEEGMG_E,JEFFV,EMINJ_BINJPLCTR_STAHV_MEDI */

    /* ekpfit�i�ڕW�|�[�g���˗ʎZ�o�W���j�Aekpfitn[NOX]�i�ڕW�|�[�g���˗ʎZ�o�W��(�o���N��)�j�̎Z�o */
    if ( u1t_injmedislid == u1g_EMINJ_STRATIST_ID )      /* ���w�n������I���� */
    {
        s2t_kpfit_estratist = s2g_estratist_ekpfit;
        s2t_kpfit = s2t_kpfit_estratist;
        for ( u1t_mox = (u1)0U; u1t_mox < u1t_nox_c; u1t_mox++ )
        {
            s2t_kpfitn[u1t_mox] = s2t_kpfit_estratist;
        }
    }
    else if ( u1t_injmedislid == u1s_EMINJ_PRVDIL_ID )   /* ��Ԏ���ߖh�~����I���� */
    {
        s2t_kpfit_eprvdil = s2g_eprvdil_ekpfit;
        s2t_kpfit = s2t_kpfit_eprvdil;
        for ( u1t_mox = (u1)0U; u1t_mox < u1t_nox_c; u1t_mox++ )
        {
            s2t_kpfitn[u1t_mox] = s2t_kpfit_eprvdil;
        }
    }
 #if (JEPLMLT_E == u1g_EJCC_USE) && (EMINJ_BINJPLCTR_MEDI == ON)   /*�yPL������˗L�zAND�y�߰�����ĕ��˂�p������{���ː���v���g�p�z*/
    else if ( u1t_injmedislid == u1g_EMINJ_BINJPLCTR_ID )  /* �p�[�V�������t�g���˂�p������{���ː���I���� */
    {
        ELIB_FLP2FXP_S2( f4t_kpfit, (f4)((1.*4.)/128./256.), s2t_kpfitplctr );
        s2t_kpfit = s2t_kpfitplctr;
        for ( u1t_mox = (u1)0U; u1t_mox < u1t_nox_c; u1t_mox++ )
        {
            ELIB_FLP2FXP_S2( f4t_kpfitn[u1t_mox], (f4)((1.*4.)/128./256.), s2t_kpfitnplctr[u1t_mox] );
            s2t_kpfitn[u1t_mox] = s2t_kpfitnplctr[u1t_mox];
        }
    }
 #endif /* JEPLMLT_E,EMINJ_BINJPLCTR_MEDI */
 #if JEALLHV_E == u1g_EJCC_ALLHV_E      /*�yALL HV�z*/
    else if ( u1t_injmedislid == u1g_EMINJ_WUPCAT_ID )   /* �G�}�g�@����I���� */
    {
        ELIB_FLP2FXP_S2( f4g_ewupcat_ekpfitcat, (f4)((1.*4.)/128./256.), s2t_kpfitcat );
        s2t_kpfit = s2t_kpfitcat;
        for ( u1t_mox = (u1)0U; u1t_mox < u1t_nox_c; u1t_mox++ )
        {
            s2t_kpfitn[u1t_mox] = s2t_kpfitcat;
        }
    }
    else if ( u1t_injmedislid == u1g_EMINJ_RDPN_ID )     /* �n����o�m�ጸ����I���� */
    {
        ELIB_FLP2FXP_S2( f4g_erdpn_ekpfit, (f4)((1.*4.)/128./256.), s2t_kpfit_erdpn );
        s2t_kpfit = s2t_kpfit_erdpn;
        for ( u1t_mox = (u1)0U; u1t_mox < u1t_nox_c; u1t_mox++ )
        {
            ELIB_FLP2FXP_S2( f4g_erdpn_ekpfitn[u1t_mox], (f4)((1.*4.)/128./256.), s2t_kpfitn[u1t_mox]);
        }
    }
 #endif /* JEALLHV_E */
 #if (JEALLHV_E == u1g_EJCC_ALLHV_E) && (JEPLMLT_E == u1g_EJCC_USE) && (EMINJ_BINJPLCTR_WC_MEDI == ON)  /*�yALL HV�zAND�yPL������˗L�zAND�y�߰�����ĕ��˂�p������{���ː���(�G�}�g�@��)�v���g�p�z*/
    else if ( u1t_injmedislid == u1g_EMINJ_BINJPLCTR_WC_ID )    /* �p�[�V�������t�g���˂�p������{���ː���(�G�}�g�@��)�I���� */
    {
        ELIB_FLP2FXP_S2( f4t_kpfit, (f4)((1.*4.)/128./256.), s2t_kpfitplctr );
        s2t_kpfit = s2t_kpfitplctr;
        for ( u1t_mox = (u1)0U; u1t_mox < u1t_nox_c; u1t_mox++ )
        {
            ELIB_FLP2FXP_S2( f4t_kpfitn[u1t_mox], (f4)((1.*4.)/128./256.), s2t_kpfitnplctr[u1t_mox] );
            s2t_kpfitn[u1t_mox] = s2t_kpfitnplctr[u1t_mox];
        }
    }
 #endif /* JEALLHV_E,JEPLMLT_E,EMINJ_BINJPLCTR_WC_MEDI */
 #if (JEEGMG_E == u1g_EJCC_HVPLGR_E) && (JEFFV == u1g_EJCC_NOT_USE) && (JEPLMLT_E == u1g_EJCC_USE) && (EMINJ_BINJPLCTR_STAHV_MEDI == ON)    /*�yEG-MG�V���ޱ�zAND�yFFV���䖳�zAND�yPL������˗L�zAND�y�߰�����ĕ��˂�p������{���ː���(HV�n�����䎞)�v���g�p�z*/
    else if ( u1t_injmedislid == u1g_EMINJ_BINJPLCTR_STAHV_ID ) /* �p�[�V�������t�g���˂�p������{���ː���(HV�n�����䎞)�I���� */
    {
        ELIB_FLP2FXP_S2( f4t_kpfit, (f4)((1.*4.)/128./256.), s2t_kpfitplctr );
        s2t_kpfit = s2t_kpfitplctr;
        for ( u1t_mox = (u1)0U; u1t_mox < u1t_nox_c; u1t_mox++ )
        {
            ELIB_FLP2FXP_S2( f4t_kpfitn[u1t_mox], (f4)((1.*4.)/128./256.), s2t_kpfitnplctr[u1t_mox] );
            s2t_kpfitn[u1t_mox] = s2t_kpfitnplctr[u1t_mox];
        }
    }
 #endif /* JEEGMG_E,JEFFV,JEPLMLT_E,EMINJ_BINJPLCTR_STAHV_MEDI */
 #if JEFFV != u1g_EJCC_NOT_USE  /*�yFFV����L�z*/
    else if ( u1t_injmedislid == u1s_EMINJ_ACTAREFUEL_ID )  /* ������̕��������A�N�e�B�u����I���� */
    {
        s2t_kpfit_eactarefuel = s2g_eactarefuel_ekpfit;
        s2t_kpfit = s2t_kpfit_eactarefuel;
        for ( u1t_mox = (u1)0U; u1t_mox < u1t_nox_c; u1t_mox++ )
        {
            s2t_kpfitn[u1t_mox] = s2t_kpfit_eactarefuel;
        }
    }
 #endif /* JEFFV */
    else
    {
        if ( u1t_injmedislid == u1g_EMINJ_NONE_ID )
        {
            s2t_kpfit = stt_binjctrdat.s2_ekpfit;
            for ( u1t_mox = (u1)0U; u1t_mox < u1t_nox_c; u1t_mox++ )
            {
                s2t_kpfitn[u1t_mox] = stt_binjctrdat.s2_ekpfit;
            }
        }
        else
        {
            s2t_kpfit = s2t_kpfi_wk;
            for ( u1t_mox = (u1)0U; u1t_mox < u1t_nox_c; u1t_mox++ )
            {
                s2t_kpfitn[u1t_mox] = s2t_kpfin[u1t_mox];
            }
        }
    }
#endif /* JEEFI */

#if JEEFI != u1g_EJCC_D4        /*�yD-4�ȊO�z*/
    /* ek1fpt�i�|�[�g���˂̂ݗv�����̖ڕW�|�[�g1��ڕ��˗ʎZ�o�W���j�̎Z�o */
 #if (JEALLHV_E == u1g_EJCC_ALLHV_E) && (JEEFI == u1g_EJCC_PORT)  /*�yALL HV�zAND�y�߰āz*/
    if ( u1t_injmedislid == u1g_EMINJ_WUPCAT_ID )       /* �G�}�g�@����I���� */
    {
        stt_injdat.f4_ek1fpt = f4t_k1fptcat;
        stt_injdat2.f4_ek1fpt = f4t_k1fptcat;
    }
    else if ( u1t_injmedislid == u1g_EMINJ_RDPN_ID )    /* �o�m�ጸ����I���� */
    {
        stt_injdat.f4_ek1fpt = f4t_k1fpt;
        stt_injdat2.f4_ek1fpt = f4t_k1fpt;
    }
    else
 #endif /* JEALLHV_E,JEEFI */
    {
        if ( ( u2t_injmodmsk0F00 == (u2)0x0100U )        /* �|�[�g�P�񕬎ˊ܂ޕ��������� */
          && ( u2t_injmodmsk000F != (u2)0x0000U ) )      /* �������ˉ񐔂�0�ȏオ�����̂��߁A���������ȗ� */
        {
            stt_injdat.f4_ek1fpt = (f4)(1.);
            stt_injdat2.f4_ek1fpt = (f4)(1.);
        }
        else if ( ( u2t_injmodmsk0F00 == (u2)0x0000U )   /* ���˗v���������P�O�O���� */
               && ( u2t_injmodmsk00F0 != (u2)0x0000U )
               && ( u2t_injmodmsk000F != (u2)0x0000U ) )
        {
            stt_injdat.f4_ek1fpt = (f4)s2s_EMINJ_K1F_VD * (f4)((1.*4.)/128./256.);
            stt_injdat2.f4_ek1fpt = (f4)s2s_EMINJ_K1F_VD * (f4)((1.*4.)/128./256.);
        }
        else
        {
            stt_injdat.f4_ek1fpt = stg_eminj_einj.f4_ek1fpt; /* �O��l */
            stt_injdat2.f4_ek1fpt = stg_eminj_eminj.f4_ek1fpt; /* �O��l */
        }
    }
    ELIB_FLP2FXP_S2( stt_injdat.f4_ek1fpt, (f4)((1.*4.)/128./256.), stt_injdat.s2_ek1fpt );
    ELIB_FLP2FXP_S2( stt_injdat2.f4_ek1fpt, (f4)((1.*4.)/128./256.), stt_injdat2.s2_ek1fpt );
#endif /* JEEFI */

#if (JEEFI == u1g_EJCC_DUAL) && (JEEGR == u1g_EJCC_USE)      /*�y�ޭ��INJ�zAND�yEGR����L�z*/
    /* ekpfiegr�iEGR-ON���̖ڕW�|�[�g���˗ʎZ�o�W���j�Aekpfiegrn[NOX]�iEGR-ON���̖ڕW�|�[�g���˗ʎZ�o�W��(�o���N��)�j�̎Z�o */
    if ( u1t_injmedislid == u1g_EMINJ_NONE_ID )
    {
        stt_injdat.f4_ekpfiegr = (f4)stt_binjctrdat.s2_ekpfiegr * (f4)((1.*4.)/128./256.);
        stt_injdat2.f4_ekpfiegr = (f4)stt_binjctrdat.s2_ekpfiegr * (f4)((1.*4.)/128./256.);
        for ( u1t_mox = (u1)0U; u1t_mox < u1t_nox_c; u1t_mox++ )
        {
            stt_injdat.f4_ekpfiegrn[u1t_mox] = (f4)stt_binjctrdat.s2_ekpfiegr * (f4)((1.*4.)/128./256.);
            stt_injdat2.f4_ekpfiegrn[u1t_mox] = (f4)stt_binjctrdat.s2_ekpfiegr * (f4)((1.*4.)/128./256.);
        }
    }
    else
    {
        stt_injdat.f4_ekpfiegr = (f4)s2t_kpfi_wk * (f4)((1.*4.)/128./256.);
        stt_injdat2.f4_ekpfiegr = (f4)s2t_kpfi_wk * (f4)((1.*4.)/128./256.);
        for ( u1t_mox = (u1)0U; u1t_mox < u1t_nox_c; u1t_mox++ )
        {
            stt_injdat.f4_ekpfiegrn[u1t_mox] = (f4)s2t_kpfin[u1t_mox] * (f4)((1.*4.)/128./256.);
            stt_injdat2.f4_ekpfiegrn[u1t_mox] = (f4)s2t_kpfin[u1t_mox] * (f4)((1.*4.)/128./256.);
        }
    }
#endif /* JEEFI,JEEGR */

    /* �i�[ */
    stt_injdat.u2_einjmod = stt_minj_data.u2_einjmod;
    stt_injdat2.u2_einjmod = stt_minj_data2.u2_einjmod;
    stt_injdat2.u4_einjptn = stt_minj_data2.u4_einjptn;
#if JEEFI != u1g_EJCC_D4        /*�yD-4�ȊO�z*/
    stt_injdat.s2_eainjp1 = stt_minj_data.s2_eainjp1;
    ELIB_HILOGD2( stt_injdat.s2_eainjp1, s2s_EMINJ_AINJP_MX, s2s_EMINJ_AINJP_MN, stt_injdat.s2_eainjp1 );
    stt_injdat.f4_eainjp1 = (f4)stt_injdat.s2_eainjp1 * (f4)(1024./128./256.);
    stt_injdat.s2_eainjp2 = stt_minj_data.s2_eainjp2;
    ELIB_HILOGD2( stt_injdat.s2_eainjp2, s2s_EMINJ_AINJP_MX, s2s_EMINJ_AINJP_MN, stt_injdat.s2_eainjp2 );
    stt_injdat.f4_eainjp2 = (f4)stt_injdat.s2_eainjp2 * (f4)(1024./128./256.);
    stt_injdat.s2_eainjp3 = stt_minj_data.s2_eainjp3;
    ELIB_HILOGD2( stt_injdat.s2_eainjp3, s2s_EMINJ_AINJP_MX, s2s_EMINJ_AINJP_MN, stt_injdat.s2_eainjp3 );
    stt_injdat.f4_eainjp3 = (f4)stt_injdat.s2_eainjp3 * (f4)(1024./128./256.);
    stt_injdat.s2_eainjp4 = stt_minj_data.s2_eainjp4;
    ELIB_HILOGD2( stt_injdat.s2_eainjp4, s2s_EMINJ_AINJP_MX, s2s_EMINJ_AINJP_MN, stt_injdat.s2_eainjp4 );
    stt_injdat.f4_eainjp4 = (f4)stt_injdat.s2_eainjp4 * (f4)(1024./128./256.);
    stt_injdat.s2_einjend = stt_minj_data.s2_einjend;
    stt_injdat.f4_einjend = (f4)stt_injdat.s2_einjend * (f4)(1024./128./256.);
    stt_injdat.s2_eainjcutp = stt_minj_data.s2_eainjcutp;
    stt_injdat.f4_eainjcutp = (f4)stt_injdat.s2_eainjcutp * (f4)(1024./128./256.);
    stt_injdat2.s2_eainjpn[0] = stt_minj_data2.s2_eainjpn[0];
    ELIB_HILOGD2( stt_injdat2.s2_eainjpn[0], s2s_EMINJ_AINJP_MX, s2s_EMINJ_AINJP_MN, stt_injdat2.s2_eainjpn[0] );
    stt_injdat2.f4_eainjpn[0] = (f4)stt_injdat2.s2_eainjpn[0] * (f4)(1024./128./256.);
    stt_injdat2.s2_eainjpn[1] = stt_minj_data2.s2_eainjpn[1];
    ELIB_HILOGD2( stt_injdat2.s2_eainjpn[1], s2s_EMINJ_AINJP_MX, s2s_EMINJ_AINJP_MN, stt_injdat2.s2_eainjpn[1] );
    stt_injdat2.f4_eainjpn[1] = (f4)stt_injdat2.s2_eainjpn[1] * (f4)(1024./128./256.);
    stt_injdat2.s2_eainjpn[2] = stt_minj_data2.s2_eainjpn[2];
    ELIB_HILOGD2( stt_injdat2.s2_eainjpn[2], s2s_EMINJ_AINJP_MX, s2s_EMINJ_AINJP_MN, stt_injdat2.s2_eainjpn[2] );
    stt_injdat2.f4_eainjpn[2] = (f4)stt_injdat2.s2_eainjpn[2] * (f4)(1024./128./256.);
    stt_injdat2.s2_eainjpn[3] = stt_minj_data2.s2_eainjpn[3];
    ELIB_HILOGD2( stt_injdat2.s2_eainjpn[3], s2s_EMINJ_AINJP_MX, s2s_EMINJ_AINJP_MN, stt_injdat2.s2_eainjpn[3] );
    stt_injdat2.f4_eainjpn[3] = (f4)stt_injdat2.s2_eainjpn[3] * (f4)(1024./128./256.);
    stt_injdat2.s2_einjend = stt_minj_data2.s2_einjend;
    stt_injdat2.f4_einjend = (f4)stt_injdat2.s2_einjend * (f4)(1024./128./256.);
    stt_injdat2.s2_eainjcutp = stt_minj_data2.s2_eainjcutp;
    stt_injdat2.f4_eainjcutp = (f4)stt_injdat2.s2_eainjcutp * (f4)(1024./128./256.);
#endif /* JEEFI */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    stt_injdat.s2_eainjcutd = stt_minj_data.s2_eainjcutd;
    stt_injdat.f4_eainjcutd = (f4)stt_injdat.s2_eainjcutd * (f4)(1024./128./256.);
    stt_injdat2.s2_eainjcutd = stt_minj_data2.s2_eainjcutd;
    stt_injdat2.f4_eainjcutd = (f4)stt_injdat2.s2_eainjcutd * (f4)(1024./128./256.);
#endif /* JEEFI */
#if JEEFI == u1g_EJCC_PORT      /*�y�߰āz*/
    /* stt_injdat.s2_eainjpadd�̑���̓f�t�H���g�l���b�`�����ɂĎ��{�ς� */
    ELIB_HILOGD2( stt_injdat.s2_eainjpadd, s2s_EMINJ_AINJPADD_MX, s2s_EMINJ_AINJPADD_MN, stt_injdat.s2_eainjpadd );
    ELIB_HILOGD2( stt_injdat2.s2_eainjpadd, s2s_EMINJ_AINJPADD_MX, s2s_EMINJ_AINJPADD_MN, stt_injdat2.s2_eainjpadd );
#endif /* JEEFI */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    /* stt_injdat.s2_eainjdadd�̑���̓f�t�H���g�l���b�`�����ɂĎ��{�ς� */
    ELIB_HILOGD2( stt_injdat.s2_eainjdadd, s2s_EMINJ_AINJDADD_MX, s2s_EMINJ_AINJDADD_MN, stt_injdat.s2_eainjdadd );
    ELIB_HILOGD2( stt_injdat2.s2_eainjdadd, s2s_EMINJ_AINJDADD_MX, s2s_EMINJ_AINJDADD_MN, stt_injdat2.s2_eainjdadd );
#endif /* JEEFI */
    stt_injdat.s2_ek1f = stt_minj_data.s2_ek1f;
    ELIB_HILOGD2( stt_injdat.s2_ek1f, s2s_EMINJ_K1F_MX, s2s_EMINJ_K1F_MN, stt_injdat.s2_ek1f );
    stt_injdat.f4_ek1f = (f4)stt_injdat.s2_ek1f * (f4)((1.*4.)/128./256.);
    stt_injdat.s2_ek2f = stt_minj_data.s2_ek2f;
    ELIB_HILOGD2( stt_injdat.s2_ek2f, s2s_EMINJ_K2F_MX, s2s_EMINJ_K2F_MN, stt_injdat.s2_ek2f );
    stt_injdat.f4_ek2f = (f4)stt_injdat.s2_ek2f * (f4)((1.*4.)/128./256.);
    stt_injdat.s2_ek3f = stt_minj_data.s2_ek3f;
    ELIB_HILOGD2( stt_injdat.s2_ek3f, s2s_EMINJ_K3F_MX, s2s_EMINJ_K3F_MN, stt_injdat.s2_ek3f );
    stt_injdat.f4_ek3f = (f4)stt_injdat.s2_ek3f * (f4)((1.*4.)/128./256.);
    for ( u1t_mox = (u1)0U; u1t_mox < u1t_nox_c; u1t_mox++ )
    {
        stt_injdat.s2_ek1fn[u1t_mox] = stt_minj_data.s2_ek1fn[u1t_mox];
        ELIB_HILOGD2( stt_injdat.s2_ek1fn[u1t_mox], s2s_EMINJ_K1FN_MX, s2s_EMINJ_K1FN_MN, stt_injdat.s2_ek1fn[u1t_mox] );
        stt_injdat.f4_ek1fn[u1t_mox] = (f4)stt_injdat.s2_ek1fn[u1t_mox] * (f4)((1.*4.)/128./256.);
        stt_injdat.s2_ek2fn[u1t_mox] = stt_minj_data.s2_ek2fn[u1t_mox];
        ELIB_HILOGD2( stt_injdat.s2_ek2fn[u1t_mox], s2s_EMINJ_K2FN_MX, s2s_EMINJ_K2FN_MN, stt_injdat.s2_ek2fn[u1t_mox] );
        stt_injdat.f4_ek2fn[u1t_mox] = (f4)stt_injdat.s2_ek2fn[u1t_mox] * (f4)((1.*4.)/128./256.);
        stt_injdat.s2_ek3fn[u1t_mox] = stt_minj_data.s2_ek3fn[u1t_mox];
        ELIB_HILOGD2( stt_injdat.s2_ek3fn[u1t_mox], s2s_EMINJ_K3FN_MX, s2s_EMINJ_K3FN_MN, stt_injdat.s2_ek3fn[u1t_mox] );
        stt_injdat.f4_ek3fn[u1t_mox] = (f4)stt_injdat.s2_ek3fn[u1t_mox] * (f4)((1.*4.)/128./256.);
        stt_injdat.s2_ekrchref[u1t_mox] = stt_minj_data.s2_ekrchref[u1t_mox];
        ELIB_HILOGD2( stt_injdat.s2_ekrchref[u1t_mox], s2s_EMINJ_KRCHREF_MX, s2s_EMINJ_KRCHREF_MN, stt_injdat.s2_ekrchref[u1t_mox] );
        stt_injdat.f4_ekrchref[u1t_mox] = (f4)stt_injdat.s2_ekrchref[u1t_mox] * (f4)((32.*2.)/128./256.);
    }
    glbitcp_bibi( stt_minj_data.bi_exqinjast, stt_injdat.bi_exqinjast );
    stt_injdat.u1_exqinjast = (u1)stt_injdat.bi_exqinjast;
    for ( u1t_mox = (u1)0U; u1t_mox < u1t_nox_c; u1t_mox++ )
    {
        stt_injdat2.s2_ek1fn[u1t_mox] = stt_minj_data2.s2_ek1fn[u1t_mox];
        ELIB_HILOGD2( stt_injdat2.s2_ek1fn[u1t_mox], s2s_EMINJ_K1FN_MX, s2s_EMINJ_K1FN_MN, stt_injdat2.s2_ek1fn[u1t_mox] );
        stt_injdat2.f4_ek1fn[u1t_mox] = (f4)stt_injdat2.s2_ek1fn[u1t_mox] * (f4)((1.*4.)/128./256.);
        stt_injdat2.s2_ek2fn[u1t_mox] = stt_minj_data2.s2_ek2fn[u1t_mox];
        ELIB_HILOGD2( stt_injdat2.s2_ek2fn[u1t_mox], s2s_EMINJ_K2FN_MX, s2s_EMINJ_K2FN_MN, stt_injdat2.s2_ek2fn[u1t_mox] );
        stt_injdat2.f4_ek2fn[u1t_mox] = (f4)stt_injdat2.s2_ek2fn[u1t_mox] * (f4)((1.*4.)/128./256.);
        stt_injdat2.s2_ek3fn[u1t_mox] = stt_minj_data2.s2_ek3fn[u1t_mox];
        ELIB_HILOGD2( stt_injdat2.s2_ek3fn[u1t_mox], s2s_EMINJ_K3FN_MX, s2s_EMINJ_K3FN_MN, stt_injdat2.s2_ek3fn[u1t_mox] );
        stt_injdat2.f4_ek3fn[u1t_mox] = (f4)stt_injdat2.s2_ek3fn[u1t_mox] * (f4)((1.*4.)/128./256.);
        stt_injdat2.s2_ekrchref[u1t_mox] = stt_minj_data2.s2_ekrchref[u1t_mox];
        ELIB_HILOGD2( stt_injdat2.s2_ekrchref[u1t_mox], s2s_EMINJ_KRCHREF_MX, s2s_EMINJ_KRCHREF_MN, stt_injdat2.s2_ekrchref[u1t_mox] );
        stt_injdat2.f4_ekrchref[u1t_mox] = (f4)stt_injdat2.s2_ekrchref[u1t_mox] * (f4)((32.*2.)/128./256.);
    }
    glbitcp_bibi( stt_minj_data2.bi_exqinjast, stt_injdat2.bi_exqinjast );
    stt_injdat2.u1_exqinjast = (u1)stt_injdat2.bi_exqinjast;
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    stt_injdat.u1_explreq = stt_minj_data.u1_explreq;
    stt_injdat2.u1_explreq = stt_minj_data2.u1_explreq;
#endif /* JEEFI */
    for ( u1t_cyl = (u1)0U; u1t_cyl < u1t_ncyl_c; u1t_cyl++ )
    {
        ELIB_HILOGD2( stt_minj_data.s4_eqfc[u1t_cyl], s4s_EMINJ_QINJ_MX, s4s_EMINJ_QINJ_MN, stt_injdat.s4_eqfc[u1t_cyl] );
        stt_injdat.f4_eqfc[u1t_cyl] = (f4)stt_injdat.s4_eqfc[u1t_cyl] * (f4)((4096.*1024.)/128./256./256./256.);
        ELIB_HILOGD2( stt_minj_data2.s4_eqfc[u1t_cyl], s4s_EMINJ_QINJ_MX, s4s_EMINJ_QINJ_MN, stt_injdat2.s4_eqfc[u1t_cyl] );
        stt_injdat2.f4_eqfc[u1t_cyl] = (f4)stt_injdat2.s4_eqfc[u1t_cyl] * (f4)((4096.*1024.)/128./256./256./256.);
    }
#if JECOMBCCPT_E == u1g_EJCC_SPRAYG_E                   /*�y���ڰ�޲�ށz*/
    stt_injdat.s4_eqinjexp = stt_minj_data.s4_eqinjexp;
    ELIB_HILOGD2( stt_injdat.s4_eqinjexp, s4s_EMINJ_QINJ_MX, s4s_EMINJ_QINJ_MN, stt_injdat.s4_eqinjexp );
    stt_injdat.f4_eqinjexp = (f4)stt_injdat.s4_eqinjexp * (f4)((4096.*1024.)/128./256./256./256.);
    stt_injdat2.s4_eqinjexp = stt_minj_data2.s4_eqinjexp;
    ELIB_HILOGD2( stt_injdat2.s4_eqinjexp, s4s_EMINJ_QINJ_MX, s4s_EMINJ_QINJ_MN, stt_injdat2.s4_eqinjexp );
    stt_injdat2.f4_eqinjexp = (f4)stt_injdat2.s4_eqinjexp * (f4)((4096.*1024.)/128./256./256./256.);
#endif /* JECOMBCCPT_E */
#if JEEFI == u1g_EJCC_DUAL      /*�y�ޭ��INJ�z*/
    stt_injdat.s2_ekpfit = s2t_kpfit;
    stt_injdat.f4_ekpfit = (f4)s2t_kpfit * (f4)((1.*4.)/128./256.);
    stt_injdat2.s2_ekpfit = s2t_kpfit;
    stt_injdat2.f4_ekpfit = (f4)s2t_kpfit * (f4)((1.*4.)/128./256.);
    for ( u1t_mox = (u1)0U; u1t_mox < u1t_nox_c; u1t_mox++ )
    {
        stt_injdat.s2_ekpfitn[u1t_mox] = s2t_kpfitn[u1t_mox];
        stt_injdat.f4_ekpfitn[u1t_mox] = (f4)s2t_kpfitn[u1t_mox] * (f4)((1.*4.)/128./256.);
        stt_injdat2.s2_ekpfitn[u1t_mox] = s2t_kpfitn[u1t_mox];
        stt_injdat2.f4_ekpfitn[u1t_mox] = (f4)s2t_kpfitn[u1t_mox] * (f4)((1.*4.)/128./256.);
    }
#endif /* JEEFI */
    for ( u1t_injnum = (u1)0U; u1t_injnum < (u1)8U; u1t_injnum++ )
    {
        stt_injdat2.s4_eqinjflfix[u1t_injnum] = stt_minj_data2.s4_eqinjflfix[u1t_injnum];
        ELIB_HILOGD2( stt_injdat2.s4_eqinjflfix[u1t_injnum], s4s_EMINJ_QINJ_MX, s4s_EMINJ_QINJ_MN, stt_injdat2.s4_eqinjflfix[u1t_injnum] );
        stt_injdat2.f4_eqinjflfix[u1t_injnum] = (f4)stt_injdat2.s4_eqinjflfix[u1t_injnum] * (f4)((4096.*1024.)/128./256./256./256.);
        stt_injdat2.s4_eqinjplfix[u1t_injnum] = stt_minj_data2.s4_eqinjplfix[u1t_injnum];
        ELIB_HILOGD2( stt_injdat2.s4_eqinjplfix[u1t_injnum], s4s_EMINJ_QINJ_MX, s4s_EMINJ_QINJ_MN, stt_injdat2.s4_eqinjplfix[u1t_injnum] );
        stt_injdat2.f4_eqinjplfix[u1t_injnum] = (f4)stt_injdat2.s4_eqinjplfix[u1t_injnum] * (f4)((4096.*1024.)/128./256./256./256.);
    }
    if ( u1t_xnercdfew == (u1)ON )                      /* NE�����^�X�N�����Ȃ� */
    {
#if JEEFI != u1g_EJCC_D4        /*�yD-4�ȊO�z*/
        stt_injdat.s4_eqinjstp1 = stt_minj_data.s4_eqinjstp1;
        ELIB_HILOGD2( stt_injdat.s4_eqinjstp1, s4s_EMINJ_QINJST_MX, s4s_EMINJ_QINJST_MN, stt_injdat.s4_eqinjstp1 );
        stt_injdat.f4_eqinjstp1 = (f4)stt_injdat.s4_eqinjstp1 * (f4)((4096.*1024.)/128./256./256./256.);
        stt_injdat.s4_eqinjstp2 = stt_minj_data.s4_eqinjstp2;
        ELIB_HILOGD2( stt_injdat.s4_eqinjstp2, s4s_EMINJ_QINJST_MX, s4s_EMINJ_QINJST_MN, stt_injdat.s4_eqinjstp2 );
        stt_injdat.f4_eqinjstp2 = (f4)stt_injdat.s4_eqinjstp2 * (f4)((4096.*1024.)/128./256./256./256.);
        stt_injdat.s4_eqinjstp3 = stt_minj_data.s4_eqinjstp3;
        ELIB_HILOGD2( stt_injdat.s4_eqinjstp3, s4s_EMINJ_QINJST_MX, s4s_EMINJ_QINJST_MN, stt_injdat.s4_eqinjstp3 );
        stt_injdat.f4_eqinjstp3 = (f4)stt_injdat.s4_eqinjstp3 * (f4)((4096.*1024.)/128./256./256./256.);
        stt_injdat.s4_eqinjstp4 = stt_minj_data.s4_eqinjstp4;
        ELIB_HILOGD2( stt_injdat.s4_eqinjstp4, s4s_EMINJ_QINJST_MX, s4s_EMINJ_QINJST_MN, stt_injdat.s4_eqinjstp4 );
        stt_injdat.f4_eqinjstp4 = (f4)stt_injdat.s4_eqinjstp4 * (f4)((4096.*1024.)/128./256./256./256.);
        stt_injdat2.s4_eqinjstpn[0] = stt_minj_data2.s4_eqinjstpn[0];
        ELIB_HILOGD2( stt_injdat2.s4_eqinjstpn[0], s4s_EMINJ_QINJST_MX, s4s_EMINJ_QINJST_MN, stt_injdat2.s4_eqinjstpn[0] );
        stt_injdat2.f4_eqinjstpn[0] = (f4)stt_injdat2.s4_eqinjstpn[0] * (f4)((4096.*1024.)/128./256./256./256.);
        stt_injdat2.s4_eqinjstpn[1] = stt_minj_data2.s4_eqinjstpn[1];
        ELIB_HILOGD2( stt_injdat2.s4_eqinjstpn[1], s4s_EMINJ_QINJST_MX, s4s_EMINJ_QINJST_MN, stt_injdat2.s4_eqinjstpn[1] );
        stt_injdat2.f4_eqinjstpn[1] = (f4)stt_injdat2.s4_eqinjstpn[1] * (f4)((4096.*1024.)/128./256./256./256.);
        stt_injdat2.s4_eqinjstpn[2] = stt_minj_data2.s4_eqinjstpn[2];
        ELIB_HILOGD2( stt_injdat2.s4_eqinjstpn[2], s4s_EMINJ_QINJST_MX, s4s_EMINJ_QINJST_MN, stt_injdat2.s4_eqinjstpn[2] );
        stt_injdat2.f4_eqinjstpn[2] = (f4)stt_injdat2.s4_eqinjstpn[2] * (f4)((4096.*1024.)/128./256./256./256.);
        stt_injdat2.s4_eqinjstpn[3] = stt_minj_data2.s4_eqinjstpn[3];
        ELIB_HILOGD2( stt_injdat2.s4_eqinjstpn[3], s4s_EMINJ_QINJST_MX, s4s_EMINJ_QINJST_MN, stt_injdat2.s4_eqinjstpn[3] );
        stt_injdat2.f4_eqinjstpn[3] = (f4)stt_injdat2.s4_eqinjstpn[3] * (f4)((4096.*1024.)/128./256./256./256.);
#endif /* JEEFI */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
        stt_injdat.s4_eqinjstd1 = stt_minj_data.s4_eqinjstd1;
        ELIB_HILOGD2( stt_injdat.s4_eqinjstd1, s4s_EMINJ_QINJST_MX, s4s_EMINJ_QINJST_MN, stt_injdat.s4_eqinjstd1 );
        stt_injdat.f4_eqinjstd1 = (f4)stt_injdat.s4_eqinjstd1 * (f4)((4096.*1024.)/128./256./256./256.);
        stt_injdat.s4_eqinjstd2 = stt_minj_data.s4_eqinjstd2;
        ELIB_HILOGD2( stt_injdat.s4_eqinjstd2, s4s_EMINJ_QINJST_MX, s4s_EMINJ_QINJST_MN, stt_injdat.s4_eqinjstd2 );
        stt_injdat.f4_eqinjstd2 = (f4)stt_injdat.s4_eqinjstd2 * (f4)((4096.*1024.)/128./256./256./256.);
        stt_injdat.s4_eqinjstd3 = stt_minj_data.s4_eqinjstd3;
        ELIB_HILOGD2( stt_injdat.s4_eqinjstd3, s4s_EMINJ_QINJST_MX, s4s_EMINJ_QINJST_MN, stt_injdat.s4_eqinjstd3 );
        stt_injdat.f4_eqinjstd3 = (f4)stt_injdat.s4_eqinjstd3 * (f4)((4096.*1024.)/128./256./256./256.);
        stt_injdat.s4_eqinjstd4 = stt_minj_data.s4_eqinjstd4;
        ELIB_HILOGD2( stt_injdat.s4_eqinjstd4, s4s_EMINJ_QINJST_MX, s4s_EMINJ_QINJST_MN, stt_injdat.s4_eqinjstd4 );
        stt_injdat.f4_eqinjstd4 = (f4)stt_injdat.s4_eqinjstd4 * (f4)((4096.*1024.)/128./256./256./256.);
        stt_injdat2.s4_eqinjstdn[0] = stt_minj_data2.s4_eqinjstdn[0];
        ELIB_HILOGD2( stt_injdat2.s4_eqinjstdn[0], s4s_EMINJ_QINJST_MX, s4s_EMINJ_QINJST_MN, stt_injdat2.s4_eqinjstdn[0] );
        stt_injdat2.f4_eqinjstdn[0] = (f4)stt_injdat2.s4_eqinjstdn[0] * (f4)((4096.*1024.)/128./256./256./256.);
        stt_injdat2.s4_eqinjstdn[1] = stt_minj_data2.s4_eqinjstdn[1];
        ELIB_HILOGD2( stt_injdat2.s4_eqinjstdn[1], s4s_EMINJ_QINJST_MX, s4s_EMINJ_QINJST_MN, stt_injdat2.s4_eqinjstdn[1] );
        stt_injdat2.f4_eqinjstdn[1] = (f4)stt_injdat2.s4_eqinjstdn[1] * (f4)((4096.*1024.)/128./256./256./256.);
        stt_injdat2.s4_eqinjstdn[2] = stt_minj_data2.s4_eqinjstdn[2];
        ELIB_HILOGD2( stt_injdat2.s4_eqinjstdn[2], s4s_EMINJ_QINJST_MX, s4s_EMINJ_QINJST_MN, stt_injdat2.s4_eqinjstdn[2] );
        stt_injdat2.f4_eqinjstdn[2] = (f4)stt_injdat2.s4_eqinjstdn[2] * (f4)((4096.*1024.)/128./256./256./256.);
        stt_injdat2.s4_eqinjstdn[3] = stt_minj_data2.s4_eqinjstdn[3];
        ELIB_HILOGD2( stt_injdat2.s4_eqinjstdn[3], s4s_EMINJ_QINJST_MX, s4s_EMINJ_QINJST_MN, stt_injdat2.s4_eqinjstdn[3] );
        stt_injdat2.f4_eqinjstdn[3] = (f4)stt_injdat2.s4_eqinjstdn[3] * (f4)((4096.*1024.)/128./256./256./256.);
        stt_injdat2.s4_eqinjstdn[4] = stt_minj_data2.s4_eqinjstdn[4];
        ELIB_HILOGD2( stt_injdat2.s4_eqinjstdn[4], s4s_EMINJ_QINJST_MX, s4s_EMINJ_QINJST_MN, stt_injdat2.s4_eqinjstdn[4] );
        stt_injdat2.f4_eqinjstdn[4] = (f4)stt_injdat2.s4_eqinjstdn[4] * (f4)((4096.*1024.)/128./256./256./256.);
        stt_injdat2.s4_eqinjstdn[5] = stt_minj_data2.s4_eqinjstdn[5];
        ELIB_HILOGD2( stt_injdat2.s4_eqinjstdn[5], s4s_EMINJ_QINJST_MX, s4s_EMINJ_QINJST_MN, stt_injdat2.s4_eqinjstdn[5] );
        stt_injdat2.f4_eqinjstdn[5] = (f4)stt_injdat2.s4_eqinjstdn[5] * (f4)((4096.*1024.)/128./256./256./256.);
#endif /* JEEFI */
    }

    vds_eminj_einj_dataset( &stg_eminj_einj, &stt_injdat, u1t_xnercdfew );
    vds_eminj_eminj_dataset( &stg_eminj_eminj, &stt_injdat2, u1t_xnercdfew );

#ifdef M_EMINJ       /* �f�o�b�O���[�h */
    u2s_eminj_einjmod_mon = stt_injdat.u2_einjmod;
    u2s_eminj_eminj_einjmod_mon = stt_injdat2.u2_einjmod;
    u4s_eminj_eminj_einjptn_mon = stt_injdat2.u4_einjptn;
 #if JEEFI != u1g_EJCC_D4        /*�yD-4�ȊO�z*/
    s2s_eminj_eainjp1_mon = stt_injdat.s2_eainjp1;
    f4s_eminj_eainjp1_mon = stt_injdat.f4_eainjp1;
    s2s_eminj_eainjp2_mon = stt_injdat.s2_eainjp2;
    f4s_eminj_eainjp2_mon = stt_injdat.f4_eainjp2;
    s2s_eminj_eainjp3_mon = stt_injdat.s2_eainjp3;
    f4s_eminj_eainjp3_mon = stt_injdat.f4_eainjp3;
    s2s_eminj_eainjp4_mon = stt_injdat.s2_eainjp4;
    f4s_eminj_eainjp4_mon = stt_injdat.f4_eainjp4;
    s2s_eminj_einjend_mon = stt_injdat.s2_einjend;
    s2s_eminj_eminj_einjend_mon = stt_injdat2.s2_einjend;
    s2s_eminj_eainjcutp_mon = stt_injdat.s2_eainjcutp;
    f4s_eminj_eainjcutp_mon = stt_injdat.f4_eainjcutp;
    s2s_eminj_eminj_eainjcutp_mon = stt_injdat2.s2_eainjcutp;
    f4s_eminj_eminj_eainjcutp_mon = stt_injdat2.f4_eainjcutp;
 #endif /* JEEFI */
 #if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    s2s_eminj_eainjd1_mon = stt_injdat.s2_eainjd1;
    f4s_eminj_eainjd1_mon = stt_injdat.f4_eainjd1;
    s2s_eminj_eainjd2_mon = stt_injdat.s2_eainjd2;
    f4s_eminj_eainjd2_mon = stt_injdat.f4_eainjd2;
    s2s_eminj_eainjd3_mon = stt_injdat.s2_eainjd3;
    f4s_eminj_eainjd3_mon = stt_injdat.f4_eainjd3;
    s2s_eminj_eainjd4_mon = stt_injdat.s2_eainjd4;
    f4s_eminj_eainjd4_mon = stt_injdat.f4_eainjd4;
    s2s_eminj_eainjcutd_mon = stt_injdat.s2_eainjcutd;
    f4s_eminj_eainjcutd_mon = stt_injdat.f4_eainjcutd;
    s2s_eminj_eminj_eainjcutd_mon = stt_injdat2.s2_eainjcutd;
    f4s_eminj_eminj_eainjcutd_mon = stt_injdat2.f4_eainjcutd;
 #endif /* JEEFI */
 #if JEEFI == u1g_EJCC_PORT      /*�y�߰āz*/
    s2s_eminj_eainjpadd_mon = stt_injdat.s2_eainjpadd;
    s2s_eminj_eminj_eainjpadd_mon = stt_injdat2.s2_eainjpadd;
 #endif /* JEEFI */
 #if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    s2s_eminj_eainjdadd_mon = stt_injdat.s2_eainjdadd;
    s2s_eminj_eminj_eainjdadd_mon = stt_injdat2.s2_eainjdadd;
 #endif /* JEEFI */
 #if JECOMBCCPT_E == u1g_EJCC_SPRAYG_E                   /*�y���ڰ�޲�ށz*/
    s4s_eminj_eqinjexp_mon = stt_injdat.s4_eqinjexp;
    f4s_eminj_eqinjexp_mon = stt_injdat.f4_eqinjexp;
    s4s_eminj_eminj_eqinjexp_mon = stt_injdat2.s4_eqinjexp;
    f4s_eminj_eminj_eqinjexp_mon = stt_injdat2.f4_eqinjexp;
 #endif /* JECOMBCCPT_E */
    s2s_eminj_ek1f_mon = stt_injdat.s2_ek1f;
    f4s_eminj_ek1f_mon = stt_injdat.f4_ek1f;
    s2s_eminj_ek2f_mon = stt_injdat.s2_ek2f;
    f4s_eminj_ek2f_mon = stt_injdat.f4_ek2f;
    s2s_eminj_ek3f_mon = stt_injdat.s2_ek3f;
    f4s_eminj_ek3f_mon = stt_injdat.f4_ek3f;
    u1s_eminj_exqinjast_mon = (u1)(stt_injdat.bi_exqinjast);
    u1s_eminj_eminj_exqinjast_mon = (u1)(stt_injdat2.bi_exqinjast);
 #if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    u1s_eminj_explreq_mon = stt_injdat.u1_explreq;
    u1s_eminj_eminj_explreq_mon = stt_injdat2.u1_explreq;
 #endif /* JEEFI */
 #if JEEFI == u1g_EJCC_DUAL            /*�y�ޭ��INJ�z*/
    f4s_eminj_ekpfit_mon = stt_injdat.f4_ekpfit;
    f4s_eminj_eminj_ekpfit_mon = stt_injdat2.f4_ekpfit;
  #if JEEGR == u1g_EJCC_USE      /*�yEGR����L�z*/
    f4s_eminj_ekpfiegr_mon = stt_injdat.f4_ekpfiegr;
    f4s_eminj_eminj_ekpfiegr_mon = stt_injdat2.f4_ekpfiegr;
  #endif /* JEEGR */
 #endif /* JEEFI */
 #if JEEFI != u1g_EJCC_D4              /*�yD-4�ȊO�z*/
    s2s_eminj_ek1fpt_mon = stt_injdat.s2_ek1fpt;
    f4s_eminj_ek1fpt_mon = stt_injdat.f4_ek1fpt;
    s2s_eminj_eminj_ek1fpt_mon = stt_injdat2.s2_ek1fpt;
    f4s_eminj_eminj_ek1fpt_mon = stt_injdat2.f4_ek1fpt;
 #endif /* JEEFI */
    /* f4s_eminj_einjend_mon�́Af4g_eminj_einjend�ő�p�\ */
    /* s2s_eminj_ekpfit_mon�́As2g_eminj_ekpfit�ő�p�\ */
    /* stt_injdat.u1_exqinjast�̃��j�^�ϐ��́Au1s_eminj_exqinjast_mon�ő�p�\ */
    /* s4s_eminj_eqfc_mon[u1g_EJCC_NCYL]�́As4g_eminj_eqfc[u1g_EJCC_NCYL]�ő�p�\ */
    /* f4s_eminj_eqfc_mon[u1g_EJCC_NCYL]�́Af4g_eminj_eqfc[u1g_EJCC_NCYL]�ő�p�\ */
    /* s2s_eminj_ek1fn_mon[u1g_EJCC_NOX]�́As2g_eminj_ek1fn[u1g_EJCC_NOX]�ő�p�\ */
    /* f4s_eminj_ek1fn_mon[u1g_EJCC_NOX]�́Af4g_eminj_ek1fn[u1g_EJCC_NOX]�ő�p�\ */
    /* s2s_eminj_ek2fn_mon[u1g_EJCC_NOX]�́As2g_eminj_ek2fn[u1g_EJCC_NOX]�ő�p�\ */
    /* f4s_eminj_ek2fn_mon[u1g_EJCC_NOX]�́Af4g_eminj_ek2fn[u1g_EJCC_NOX]�ő�p�\ */
    /* s2s_eminj_ek3fn_mon[u1g_EJCC_NOX]�́As2g_eminj_ek3fn[u1g_EJCC_NOX]�ő�p�\ */
    /* f4s_eminj_ek3fn_mon[u1g_EJCC_NOX]�́Af4g_eminj_ek3fn[u1g_EJCC_NOX]�ő�p�\ */
    /* s2s_eminj_ekrchref_mon[u1g_EJCC_NOX]�́As2g_eminj_ekrchref[u1g_EJCC_NOX]�ő�p�\ */
    /* f4s_eminj_ekrchref_mon[u1g_EJCC_NOX]�́Af4g_eminj_ekrchref[u1g_EJCC_NOX]�ő�p�\ */
    /* s2s_eminj_ekpfitn_mon[u1g_EJCC_NOX]�́As2g_eminj_ekpfitn[u1g_EJCC_NOX]�ő�p�\ */
    /* f4s_eminj_ekpfitn_mon[u1g_EJCC_NOX]�́Af4g_eminj_ekpfitn[u1g_EJCC_NOX]�ő�p�\ */
    /* f4s_eminj_ekpfiegrn_mon[u1g_EJCC_NOX]�́Af4g_eminj_ekpfiegrn[u1g_EJCC_NOX]�ő�p�\ */
    /* s2s_eminj_eminj_eainjpn_mon[5]�́As2g_eminj_eainjpn[5]�ő�p�\ */
    /* f4s_eminj_eminj_eainjpn_mon[5]�́Af4g_eminj_eainjpn[5]�ő�p�\ */
    /* f4s_eminj_eminj_einjend_mon�́Af4g_eminj_einjend�ő�p�\ */
    /* s2s_eminj_eminj_eainjdn_mon[6]�́As2g_eminj_eainjdn[6]�ő�p�\ */
    /* f4s_eminj_eminj_eainjdn_mon[6]�́Af4g_eminj_eainjdn[6]�ő�p�\ */
    /* s4s_eminj_eminj_eqfc_mon[u1g_EJCC_NCYL]�́As4g_eminj_eqfc[u1g_EJCC_NCYL]�ő�p�\ */
    /* f4s_eminj_eminj_eqfc_mon[u1g_EJCC_NCYL]�́Af4g_eminj_eqfc[u1g_EJCC_NCYL]�ő�p�\ */
    /* s2s_eminj_eminj_ek1fn_mon[u1g_EJCC_NOX]�́As2g_eminj_ek1fn[u1g_EJCC_NOX]�ő�p�\ */
    /* f4s_eminj_eminj_ek1fn_mon[u1g_EJCC_NOX]�́Af4g_eminj_ek1fn[u1g_EJCC_NOX]�ő�p�\ */
    /* s2s_eminj_eminj_ek2fn_mon[u1g_EJCC_NOX]�́As2g_eminj_ek2fn[u1g_EJCC_NOX]�ő�p�\ */
    /* f4s_eminj_eminj_ek2fn_mon[u1g_EJCC_NOX]�́Af4g_eminj_ek2fn[u1g_EJCC_NOX]�ő�p�\ */
    /* s2s_eminj_eminj_ek3fn_mon[u1g_EJCC_NOX]�́As2g_eminj_ek3fn[u1g_EJCC_NOX]�ő�p�\ */
    /* f4s_eminj_eminj_ek3fn_mon[u1g_EJCC_NOX]�́Af4g_eminj_ek3fn[u1g_EJCC_NOX]�ő�p�\ */
    /* s2s_eminj_eminj_ekrchref_mon[u1g_EJCC_NOX]�́As2g_eminj_ekrchref[u1g_EJCC_NOX]�ő�p�\ */
    /* f4s_eminj_eminj_ekrchref_mon[u1g_EJCC_NOX]�́Af4g_eminj_ekrchref[u1g_EJCC_NOX]�ő�p�\ */
    /* stt_injdat2.u1_exqinjast�̃��j�^�ϐ��́Au1s_eminj_eminj_exqinjast_mon�ő�p�\ */
    /* s2s_eminj_eminj_ekpfit_mon�́As2g_eminj_ekpfit�ő�p�\ */
    /* s2s_eminj_eminj_ekpfitn_mon[u1g_EJCC_NOX]�́As2g_eminj_ekpfitn[u1g_EJCC_NOX]�ő�p�\ */
    /* f4s_eminj_eminj_ekpfitn_mon[u1g_EJCC_NOX]�́Af4g_eminj_ekpfitn[u1g_EJCC_NOX]�ő�p�\ */
    /* f4s_eminj_eminj_ekpfiegrn_mon[u1g_EJCC_NOX]�́Af4g_eminj_ekpfiegrn[u1g_EJCC_NOX]�ő�p�\ */
    /* s4s_eminj_eminj_eqinjflfix_mon[8]�́As4g_eminj_eqinjflfix[8]�ő�p�\ */
    /* f4s_eminj_eminj_eqinjflfix_mon[8]�́Af4g_eminj_eqinjflfix[8]�ő�p�\ */
    /* s4s_eminj_eminj_eqinjplfix_mon[8]�́As4g_eminj_eqinjplfix[8]�ő�p�\ */
    /* f4s_eminj_eminj_eqinjplfix_mon[8]�́Af4g_eminj_eqinjplfix[8]�ő�p�\ */

    if ( u1t_xnercdfew == (u1)ON )                      /* NE�����^�X�N�����Ȃ� */
    {
 #if JEEFI != u1g_EJCC_D4        /*�yD-4�ȊO�z*/
        s4s_eminj_eqinjstp1_mon = stt_injdat.s4_eqinjstp1;
        f4s_eminj_eqinjstp1_mon = stt_injdat.f4_eqinjstp1;
        s4s_eminj_eqinjstp2_mon = stt_injdat.s4_eqinjstp2;
        f4s_eminj_eqinjstp2_mon = stt_injdat.f4_eqinjstp2;
        s4s_eminj_eqinjstp3_mon = stt_injdat.s4_eqinjstp3;
        f4s_eminj_eqinjstp3_mon = stt_injdat.f4_eqinjstp3;
        s4s_eminj_eqinjstp4_mon = stt_injdat.s4_eqinjstp4;
        f4s_eminj_eqinjstp4_mon = stt_injdat.f4_eqinjstp4;
 #endif /* JEEFI */
 #if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
        s4s_eminj_eqinjstd1_mon = stt_injdat.s4_eqinjstd1;
        s4s_eminj_eqinjstd2_mon = stt_injdat.s4_eqinjstd2;
        s4s_eminj_eqinjstd3_mon = stt_injdat.s4_eqinjstd3;
        s4s_eminj_eqinjstd4_mon = stt_injdat.s4_eqinjstd4;
 #endif /* JEEFI */
        /* f4s_eminj_eqinjstd1_mon�́Af4g_eminj_eqinjstd1�ő�p�\ */
        /* f4s_eminj_eqinjstd2_mon�́Af4g_eminj_eqinjstd2�ő�p�\ */
        /* f4s_eminj_eqinjstd3_mon�́Af4g_eminj_eqinjstd3�ő�p�\ */
        /* f4s_eminj_eqinjstd4_mon�́Af4g_eminj_eqinjstd4�ő�p�\ */
        /* s4s_eminj_eminj_eqinjstpn_mon[5]�́As4g_eminj_eqinjstpn[5]�ő�p�\ */
        /* f4s_eminj_eminj_eqinjstpn_mon[5]�́Af4g_eminj_eqinjstpn[5]�ő�p�\ */
        /* s4s_eminj_eminj_eqinjstdn_mon[6]�́As4g_eminj_eqinjstdn[6]�ő�p�\ */
        /* f4s_eminj_eminj_eqinjstdn_mon[6]�́Af4g_eminj_eqinjstdn[6]�ő�p�\ */
    }
#endif /* M_EMINJ */

#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    s2g_eminj_eprreq = stt_minj_data.s2_eprreq;
    f4g_eminj_eprreq = (f4)(stt_minj_data.s2_eprreq) * (f4)((32.*2.)/128./256.);
#endif /* JEEFI */
#if JEPRDEMAND == u1g_EJCC_NOT_USE                      /*�y�ϔR�����䖳�z*/
    s2g_eminj_eqfreq = stt_minj_data.s2_eqfreq;
#else                           /*�y�ϔR������L�z*/
    s2g_eminj_eprreql = stt_minj_data.s2_eprreql;
    f4g_eminj_eprreql = (f4)(stt_minj_data.s2_eprreql) * (f4)(1280./128./256.);
#endif /* JEPRDEMAND */
    s2g_eminj_ekrichx = s2t_krichx;
    f4g_eminj_ekrichx = (f4)s2t_krichx * (f4)((32.*2.)/128./256.);
    s2g_eminj_ekpfi = s2t_kpfi_wk;
    f4g_eminj_ekpfi = (f4)s2t_kpfi_wk * (f4)((1.*4.)/128./256.);
    for ( u1t_mox = (u1)0U; u1t_mox < u1t_nox_c; u1t_mox++ )
    {
        s2g_eminj_ekpfin[u1t_mox] = s2t_kpfin[u1t_mox];
        f4g_eminj_ekpfin[u1t_mox] = (f4)s2t_kpfin[u1t_mox] * (f4)((1.*4.)/128./256.);
    }

    u1s_eminj_exasto = u1t_xast;

    /* ecqinjast_8m�i�n���㕬�˗ʗv����J�E���^�j�̑��� */
    if ( stt_injdat.u1_exqinjast == (u1)OFF )   /* �n���� */
    {
        s2g_eminj_ecqinjast_8m = (s2)(((0.)/(268435.456/128./256.))+0.5);
    }

    /* ���˂r�`�b�̊m��O���˗v���X�V���� */
    /* ���{�����́A�{���i�̑S�Ă̂W�������^�X�N�������{��ɍs������ */
    vdg_ainjif_renew_injrq();
}

/*********************************************************************/
/*  �֐���        | vdg_eminj_einj_dataget( )                        */
/*  �������e      | ���ˏ��擾����                                 */
/*  ����^�C�~���O| �����v����                                       */
/*  ����          | ptt_retval:���ˏ��擾�o�b�t�@�̃A�h���X        */
/*  �߂�l        | �Ȃ�                                             */
/*  ���ӎ���      |                                                  */
/*********************************************************************/
void
vdg_eminj_einj_dataget( st_EMINJ_EINJ *ptt_retval )
{
    u1 u1t_mox;    /* lsb=1 :���C���Z���T�� */
    u1 u1t_nox_c;  /* lsb=1 :���C���Z���T�� */
    u1 u1t_cyl;    /* lsb=1 :�C���� */
    u1 u1t_ncyl_c; /* lsb=1 :�C���� */

    u1t_ncyl_c = u1g_ejcc_NCYL;
    u1t_nox_c = u1g_ejcc_NOX;

    glint_di();         /* �������m�� �J�n */
    ptt_retval->u2_einjmod = stg_eminj_einj.u2_einjmod;
#if JEEFI != u1g_EJCC_D4        /*�yD-4�ȊO�z*/
    ptt_retval->s2_eainjp1 = stg_eminj_einj.s2_eainjp1;
    ptt_retval->f4_eainjp1 = stg_eminj_einj.f4_eainjp1;
    ptt_retval->s2_eainjp2 = stg_eminj_einj.s2_eainjp2;
    ptt_retval->f4_eainjp2 = stg_eminj_einj.f4_eainjp2;
    ptt_retval->s2_eainjp3 = stg_eminj_einj.s2_eainjp3;
    ptt_retval->f4_eainjp3 = stg_eminj_einj.f4_eainjp3;
    ptt_retval->s2_eainjp4 = stg_eminj_einj.s2_eainjp4;
    ptt_retval->f4_eainjp4 = stg_eminj_einj.f4_eainjp4;
    ptt_retval->s2_einjend = stg_eminj_einj.s2_einjend;
    ptt_retval->f4_einjend = stg_eminj_einj.f4_einjend;
    ptt_retval->s2_eainjcutp = stg_eminj_einj.s2_eainjcutp;
    ptt_retval->f4_eainjcutp = stg_eminj_einj.f4_eainjcutp;
#endif /* JEEFI */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    ptt_retval->s2_eainjd1 = stg_eminj_einj.s2_eainjd1;
    ptt_retval->f4_eainjd1 = stg_eminj_einj.f4_eainjd1;
    ptt_retval->s2_eainjd2 = stg_eminj_einj.s2_eainjd2;
    ptt_retval->f4_eainjd2 = stg_eminj_einj.f4_eainjd2;
    ptt_retval->s2_eainjd3 = stg_eminj_einj.s2_eainjd3;
    ptt_retval->f4_eainjd3 = stg_eminj_einj.f4_eainjd3;
    ptt_retval->s2_eainjd4 = stg_eminj_einj.s2_eainjd4;
    ptt_retval->f4_eainjd4 = stg_eminj_einj.f4_eainjd4;
    ptt_retval->s2_eainjcutd = stg_eminj_einj.s2_eainjcutd;
    ptt_retval->f4_eainjcutd = stg_eminj_einj.f4_eainjcutd;
#endif /* JEEFI */
#if JEEFI == u1g_EJCC_PORT      /*�y�߰āz*/
    ptt_retval->s2_eainjpadd = stg_eminj_einj.s2_eainjpadd;
#endif /* JEEFI */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    ptt_retval->s2_eainjdadd = stg_eminj_einj.s2_eainjdadd;
#endif /* JEEFI */
#if JEEFI != u1g_EJCC_D4        /*�yD-4�ȊO�z*/
    ptt_retval->s4_eqinjstp1 = stg_eminj_einj.s4_eqinjstp1;
    ptt_retval->f4_eqinjstp1 = stg_eminj_einj.f4_eqinjstp1;
    ptt_retval->s4_eqinjstp2 = stg_eminj_einj.s4_eqinjstp2;
    ptt_retval->f4_eqinjstp2 = stg_eminj_einj.f4_eqinjstp2;
    ptt_retval->s4_eqinjstp3 = stg_eminj_einj.s4_eqinjstp3;
    ptt_retval->f4_eqinjstp3 = stg_eminj_einj.f4_eqinjstp3;
    ptt_retval->s4_eqinjstp4 = stg_eminj_einj.s4_eqinjstp4;
    ptt_retval->f4_eqinjstp4 = stg_eminj_einj.f4_eqinjstp4;
#endif /* JEEFI */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    ptt_retval->s4_eqinjstd1 = stg_eminj_einj.s4_eqinjstd1;
    ptt_retval->f4_eqinjstd1 = stg_eminj_einj.f4_eqinjstd1;
    ptt_retval->s4_eqinjstd2 = stg_eminj_einj.s4_eqinjstd2;
    ptt_retval->f4_eqinjstd2 = stg_eminj_einj.f4_eqinjstd2;
    ptt_retval->s4_eqinjstd3 = stg_eminj_einj.s4_eqinjstd3;
    ptt_retval->f4_eqinjstd3 = stg_eminj_einj.f4_eqinjstd3;
    ptt_retval->s4_eqinjstd4 = stg_eminj_einj.s4_eqinjstd4;
    ptt_retval->f4_eqinjstd4 = stg_eminj_einj.f4_eqinjstd4;
#endif /* JEEFI */
    for ( u1t_cyl = (u1)0U; u1t_cyl < u1t_ncyl_c; u1t_cyl++ )
    {
        ptt_retval->s4_eqfc[u1t_cyl] = stg_eminj_einj.s4_eqfc[u1t_cyl];
        ptt_retval->f4_eqfc[u1t_cyl] = stg_eminj_einj.f4_eqfc[u1t_cyl];
    }
#if JECOMBCCPT_E == u1g_EJCC_SPRAYG_E                   /*�y���ڰ�޲�ށz*/
    ptt_retval->s4_eqinjexp = stg_eminj_einj.s4_eqinjexp;
    ptt_retval->f4_eqinjexp = stg_eminj_einj.f4_eqinjexp;
#endif /* JECOMBCCPT_E */
    ptt_retval->s2_ek1f = stg_eminj_einj.s2_ek1f;
    ptt_retval->f4_ek1f = stg_eminj_einj.f4_ek1f;
    ptt_retval->s2_ek2f = stg_eminj_einj.s2_ek2f;
    ptt_retval->f4_ek2f = stg_eminj_einj.f4_ek2f;
    ptt_retval->s2_ek3f = stg_eminj_einj.s2_ek3f;
    ptt_retval->f4_ek3f = stg_eminj_einj.f4_ek3f;
    for ( u1t_mox = (u1)0U; u1t_mox < u1t_nox_c; u1t_mox++ )
    {
        ptt_retval->s2_ek1fn[u1t_mox] = stg_eminj_einj.s2_ek1fn[u1t_mox];
        ptt_retval->f4_ek1fn[u1t_mox] = stg_eminj_einj.f4_ek1fn[u1t_mox];
        ptt_retval->s2_ek2fn[u1t_mox] = stg_eminj_einj.s2_ek2fn[u1t_mox];
        ptt_retval->f4_ek2fn[u1t_mox] = stg_eminj_einj.f4_ek2fn[u1t_mox];
        ptt_retval->s2_ek3fn[u1t_mox] = stg_eminj_einj.s2_ek3fn[u1t_mox];
        ptt_retval->f4_ek3fn[u1t_mox] = stg_eminj_einj.f4_ek3fn[u1t_mox];
        ptt_retval->s2_ekrchref[u1t_mox] = stg_eminj_einj.s2_ekrchref[u1t_mox];
        ptt_retval->f4_ekrchref[u1t_mox] = stg_eminj_einj.f4_ekrchref[u1t_mox];
    }
    glbitcp_bibi( stg_eminj_einj.bi_exqinjast, ptt_retval->bi_exqinjast );
    ptt_retval->u1_exqinjast = stg_eminj_einj.u1_exqinjast;
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    ptt_retval->u1_explreq = stg_eminj_einj.u1_explreq;
#endif /* JEEFI */
#if JEEFI == u1g_EJCC_DUAL      /*�y�ޭ��INJ�z*/
    ptt_retval->s2_ekpfit = stg_eminj_einj.s2_ekpfit;
    ptt_retval->f4_ekpfit = stg_eminj_einj.f4_ekpfit;
 #if JEEGR == u1g_EJCC_USE      /*�yEGR����L�z*/
    ptt_retval->f4_ekpfiegr = stg_eminj_einj.f4_ekpfiegr;
 #endif /* JEEGR */
    for ( u1t_mox = (u1)0U; u1t_mox < u1t_nox_c; u1t_mox++ )
    {
        ptt_retval->s2_ekpfitn[u1t_mox] = stg_eminj_einj.s2_ekpfitn[u1t_mox];
        ptt_retval->f4_ekpfitn[u1t_mox] = stg_eminj_einj.f4_ekpfitn[u1t_mox];
 #if JEEGR == u1g_EJCC_USE      /*�yEGR����L�z*/
        ptt_retval->f4_ekpfiegrn[u1t_mox] = stg_eminj_einj.f4_ekpfiegrn[u1t_mox];
 #endif /* JEEGR */
    }
#endif /* JEEFI */
#if JEEFI != u1g_EJCC_D4        /*�yD-4�ȊO�z*/
    ptt_retval->s2_ek1fpt = stg_eminj_einj.s2_ek1fpt;
    ptt_retval->f4_ek1fpt = stg_eminj_einj.f4_ek1fpt;
#endif /* JEEFI */
    glint_ei();       /* �������m�� �I�� */
}

/*********************************************************************/
/*  �֐���        | vdg_eminj_eminj_dataget( )                       */
/*  �������e      | ���ˏ��擾�����i�\����2�j                      */
/*  ����^�C�~���O| �����v����                                       */
/*  ����          | ptt_retval:���ˏ��擾�o�b�t�@�̃A�h���X        */
/*  �߂�l        | �Ȃ�                                             */
/*  ���ӎ���      | �V�\���̗p                                       */
/*********************************************************************/
void
vdg_eminj_eminj_dataget( st_EMINJ_EMINJ *ptt_retval )
{
    u1 u1t_mox;    /* lsb=1 :���C���Z���T�� */
    u1 u1t_nox_c;  /* lsb=1 :���C���Z���T�� */
    u1 u1t_cyl;    /* lsb=1 :�C���� */
    u1 u1t_ncyl_c; /* lsb=1 :�C���� */
    u1 u1t_injnum; /* lsb=1 :���ˉ� */

    u1t_ncyl_c = u1g_ejcc_NCYL;
    u1t_nox_c = u1g_ejcc_NOX;

    glint_di();         /* �������m�� �J�n */
    ptt_retval->u2_einjmod = stg_eminj_eminj.u2_einjmod;
    ptt_retval->u4_einjptn = stg_eminj_eminj.u4_einjptn;
#if JEEFI != u1g_EJCC_D4        /*�yD-4�ȊO�z*/
    for ( u1t_injnum = (u1)0U; u1t_injnum < (u1)4U; u1t_injnum++ )
    {
        ptt_retval->s2_eainjpn[u1t_injnum] = stg_eminj_eminj.s2_eainjpn[u1t_injnum];
        ptt_retval->f4_eainjpn[u1t_injnum] = stg_eminj_eminj.f4_eainjpn[u1t_injnum];
    }
    ptt_retval->s2_einjend = stg_eminj_eminj.s2_einjend;
    ptt_retval->f4_einjend = stg_eminj_eminj.f4_einjend;
    ptt_retval->s2_eainjcutp = stg_eminj_eminj.s2_eainjcutp;
    ptt_retval->f4_eainjcutp = stg_eminj_eminj.f4_eainjcutp;
#endif /* JEEFI */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    for ( u1t_injnum = (u1)0U; u1t_injnum < (u1)6U; u1t_injnum++ )
    {
        ptt_retval->s2_eainjdn[u1t_injnum] = stg_eminj_eminj.s2_eainjdn[u1t_injnum];
        ptt_retval->f4_eainjdn[u1t_injnum] = stg_eminj_eminj.f4_eainjdn[u1t_injnum];
    }
    ptt_retval->s2_eainjcutd = stg_eminj_eminj.s2_eainjcutd;
    ptt_retval->f4_eainjcutd = stg_eminj_eminj.f4_eainjcutd;
#endif /* JEEFI */
#if JEEFI == u1g_EJCC_PORT      /*�y�߰āz*/
    ptt_retval->s2_eainjpadd = stg_eminj_eminj.s2_eainjpadd;
#endif /* JEEFI */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    ptt_retval->s2_eainjdadd = stg_eminj_eminj.s2_eainjdadd;
#endif /* JEEFI */
#if JEEFI != u1g_EJCC_D4        /*�yD-4�ȊO�z*/
    for ( u1t_injnum = (u1)0U; u1t_injnum < (u1)4U; u1t_injnum++ )
    {
        ptt_retval->s4_eqinjstpn[u1t_injnum] = stg_eminj_eminj.s4_eqinjstpn[u1t_injnum];
        ptt_retval->f4_eqinjstpn[u1t_injnum] = stg_eminj_eminj.f4_eqinjstpn[u1t_injnum];
    }
#endif /* JEEFI */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    for ( u1t_injnum = (u1)0U; u1t_injnum < (u1)6U; u1t_injnum++ )
    {
        ptt_retval->s4_eqinjstdn[u1t_injnum] = stg_eminj_eminj.s4_eqinjstdn[u1t_injnum];
        ptt_retval->f4_eqinjstdn[u1t_injnum] = stg_eminj_eminj.f4_eqinjstdn[u1t_injnum];
    }
#endif /* JEEFI */
    for ( u1t_cyl = (u1)0U; u1t_cyl < u1t_ncyl_c; u1t_cyl++ )
    {
        ptt_retval->s4_eqfc[u1t_cyl] = stg_eminj_eminj.s4_eqfc[u1t_cyl];
        ptt_retval->f4_eqfc[u1t_cyl] = stg_eminj_eminj.f4_eqfc[u1t_cyl];
    }
#if JECOMBCCPT_E == u1g_EJCC_SPRAYG_E                   /*�y���ڰ�޲�ށz*/
    ptt_retval->s4_eqinjexp = stg_eminj_eminj.s4_eqinjexp;
    ptt_retval->f4_eqinjexp = stg_eminj_eminj.f4_eqinjexp;
#endif /* JECOMBCCPT_E */
    /* �V�\���̂ł̓����oek1f,ek2f,ek3f�͏������Ȃ� */

    for ( u1t_mox = (u1)0U; u1t_mox < u1t_nox_c; u1t_mox++ )
    {
        ptt_retval->s2_ek1fn[u1t_mox] = stg_eminj_eminj.s2_ek1fn[u1t_mox];
        ptt_retval->f4_ek1fn[u1t_mox] = stg_eminj_eminj.f4_ek1fn[u1t_mox];
        ptt_retval->s2_ek2fn[u1t_mox] = stg_eminj_eminj.s2_ek2fn[u1t_mox];
        ptt_retval->f4_ek2fn[u1t_mox] = stg_eminj_eminj.f4_ek2fn[u1t_mox];
        ptt_retval->s2_ek3fn[u1t_mox] = stg_eminj_eminj.s2_ek3fn[u1t_mox];
        ptt_retval->f4_ek3fn[u1t_mox] = stg_eminj_eminj.f4_ek3fn[u1t_mox];
        ptt_retval->s2_ekrchref[u1t_mox] = stg_eminj_eminj.s2_ekrchref[u1t_mox];
        ptt_retval->f4_ekrchref[u1t_mox] = stg_eminj_eminj.f4_ekrchref[u1t_mox];
    }
    glbitcp_bibi( stg_eminj_eminj.bi_exqinjast, ptt_retval->bi_exqinjast );
    ptt_retval->u1_exqinjast = stg_eminj_eminj.u1_exqinjast;
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    ptt_retval->u1_explreq = stg_eminj_eminj.u1_explreq;
#endif /* JEEFI */
#if JEEFI == u1g_EJCC_DUAL      /*�y�ޭ��INJ�z*/
    ptt_retval->s2_ekpfit = stg_eminj_eminj.s2_ekpfit;
    ptt_retval->f4_ekpfit = stg_eminj_eminj.f4_ekpfit;
 #if JEEGR == u1g_EJCC_USE      /*�yEGR����L�z*/
    ptt_retval->f4_ekpfiegr = stg_eminj_eminj.f4_ekpfiegr;
 #endif /* JEEGR */
    for ( u1t_mox = (u1)0U; u1t_mox < u1t_nox_c; u1t_mox++ )
    {
        ptt_retval->s2_ekpfitn[u1t_mox] = stg_eminj_eminj.s2_ekpfitn[u1t_mox];
        ptt_retval->f4_ekpfitn[u1t_mox] = stg_eminj_eminj.f4_ekpfitn[u1t_mox];
 #if JEEGR == u1g_EJCC_USE      /*�yEGR����L�z*/
        ptt_retval->f4_ekpfiegrn[u1t_mox] = stg_eminj_eminj.f4_ekpfiegrn[u1t_mox];
 #endif /* JEEGR */
    }
#endif /* JEEFI */
#if JEEFI != u1g_EJCC_D4        /*�yD-4�ȊO�z*/
    ptt_retval->s2_ek1fpt = stg_eminj_eminj.s2_ek1fpt;
    ptt_retval->f4_ek1fpt = stg_eminj_eminj.f4_ek1fpt;
#endif /* JEEFI */
    for ( u1t_injnum = (u1)0U; u1t_injnum < (u1)8U; u1t_injnum++ )
    {
        ptt_retval->s4_eqinjflfix[u1t_injnum] = stg_eminj_eminj.s4_eqinjflfix[u1t_injnum];
        ptt_retval->f4_eqinjflfix[u1t_injnum] = stg_eminj_eminj.f4_eqinjflfix[u1t_injnum];
        ptt_retval->s4_eqinjplfix[u1t_injnum] = stg_eminj_eminj.s4_eqinjplfix[u1t_injnum];
        ptt_retval->f4_eqinjplfix[u1t_injnum] = stg_eminj_eminj.f4_eqinjplfix[u1t_injnum];
    }
    glint_ei();       /* �������m�� �I�� */
}

/*-------------------------------------------------------------------*/
/* �֐��i�����֐��j                                                  */
/*-------------------------------------------------------------------*/
/*********************************************************************/
/*  �֐���        | vds_eminj_eminj_hpri( )                          */
/*  �������e      | �D��x�I������                                   */
/*  ����^�C�~���O| �����v����                                       */
/*  ����          | ptt_datsel:����f�[�^�i�[��̃A�h���X            */
/*                | ptt_datdft:����f�[�^�f�t�H���g�l�̃A�h���X      */
/*                | ptt_datsel2:�V����f�[�^�i�[��̃A�h���X         */
/*                | ptt_datdft2:�V����f�[�^�f�t�H���g�l�̃A�h���X   */
/*  �߂�l        | ����                                             */
/*  ���ӎ���      |                                                  */
/*********************************************************************/
static void
vds_eminj_eminj_hpri( st_EMINJ_EMINJ_DEF *ptt_datsel, const st_EMINJ_EMINJ_DEF *ptt_datdft, st_EMINJ_EMINJ_BUF *ptt_datsel2, const st_EMINJ_EMINJ_BUF *ptt_datdft2 )
{
/* �W��e�[�u����` */
#pragma ghs startdata
/*-------------------------------------------------------------------*/
/* �n�����v���D��I���e�[�u���̒�`                                  */
/*-------------------------------------------------------------------*/
    static volatile const st_EMINJ_EMINJ_TBL sts_eminj_eminjst_tbl[] = /* ���ӎ���:sts_eminj_eminjst_tbl[]�ύX���́A�ȉ��̕����������ύX�K�v  */
                                                                       /*         :ID�ݒ�,�D��x�ݒ�,�v���w���p�f�[�^�ݒ�                     */
                                                                       /*         :����֐�eminj_eminj_hpri()���̃X�^�b�N�Z�o����             */
                                                                       /*         :���̗D��I���e�[�u���ƕ�����Q�ƂƂȂ�v����ݒ肷��ꍇ�� */
                                                                       /*         :rap�֐����쐬���ݒ肷�邱��                                */
    {
#if ((JERMTCTR == u1g_EJCC_USE) || (JENVCTR == u1g_EJCC_USE)) && (JEMICN_E != u1g_EJCC_SUB_E) && (EMINJ_STACM_MEDI == ON) /* (�y�Ӱĺ��۰ٗL�zOR�y��޺��۰ٗL�z) AND�ySUB-CPU�ȊO�zAND�y�n���������オ�萧��v���g�p�z*/
        { &vdg_estacm_emedi_dataget,        u1g_EMINJ_STACM_ID    }, /* �D��x=28 :�n���������オ�萧�� */
#endif /* JERMTCTR,JENVCTR,JEMICN_E,EMINJ_STACM_MEDI */
#if (JESS == u1g_EJCC_USE) || (JEEGMG_E == u1g_EJCC_HVCLUTCH_E)      /*�ySS����L�zOR�yEG-MG�ׯ��z*/
        { &vdg_estass_emedi_dataget,        u1g_EMINJ_STASS_ID    }, /* �D��x=30 :SS�n������ */
#endif /* JESS,JEEGMG_E */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)               /*�y�ޭ��INJ�zOR�yD-4�z*/
        { &vds_eminj_erestahot_rap_dataget, u1s_EMINJ_RESTAHOT_ID }, /* �D��x=32 :�����Ďn������ */
        { &vdg_ekcst_emedi_dataget,         u1s_EMINJ_KCST_ID     }, /* �D��x=34 :�n����ɯ��h�~���� */
#endif /* JEEFI */
#if (JEALLHV_E == u1g_EJCC_ALLHV_E) && (JEEFI == u1g_EJCC_PORT)      /*�yALL HV�zAND�y�߰āz*/
        { &vds_eminj_erdpn_rap_dataget,     u1g_EMINJ_RDPN_ST_ID  }, /* �D��x=36 :PN�ጸ����(�n����) */
                                                                     /* �ʏ�v���̂o�m�ጸ����Ǝ擾�֐��������ꂽ�ꍇ�́A */
                                                                     /* �n�����v������A�ʏ펞�v������̂o�m�ጸ����̔���Arap�֐����폜���邱�� */
#endif /* JEALLHV_E,JEEFI */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)               /*�y�ޭ��INJ�zOR�yD-4�z*/
        { &vdg_estratist_emedi_dataget,     u1g_EMINJ_STRATIST_ID }, /* �D��x=42 :���w�n������ */
#endif /* JEEFI */
#if JEEFI == u1g_EJCC_DUAL                                           /*�y�ޭ��INJ�z*/
        { &vdg_estafrg_emedi_dataget,       u1g_EMINJ_STAFRG_ID   }, /* �D��x=44 :�ɒቷ�n������ */
#endif /* JEEFI */
#if EMINJ_FREE4 == ON   /*�y�ذ�߰�4�g�p�z*/
        { &vdg_eminj_efree4_emedi_dataget,  u1g_EMINJ_FREE4_ID    }, /* �D��x=204 :�ذ�߰�4�p���˗v�� */
#endif /* EMINJ_FREE4 */
#if EMINJ_FREE5 == ON   /*�y�ذ�߰�5�g�p�z*/
        { &vdg_eminj_efree5_emedi_dataget,  u1g_EMINJ_FREE5_ID    }, /* �D��x=205 :�ذ�߰�5�p���˗v�� */
#endif /* EMINJ_FREE5 */
/* ���������������������������������������������������������������������������������������� */
        /* �K���e�[�u���̏I�[�ɐݒ肷�邱�� */
        { &vds_eminj_dummy_emedi_dataget,   u1g_EMINJ_NONE_ID     }  /* �D��x=�Ȃ� :�_�~�[ */
/* ���������������������������������������������������������������������������������������� */
    };

/*-------------------------------------------------------------------*/
/* �n�����v���D��I���e�[�u���Q�̒�`                                */
/*-------------------------------------------------------------------*/
    static volatile const st_EMINJ_EMINJ_TBL2 sts_eminj_eminjst_tbl2[] = /* ���ӎ���:sts_eminj_eminjst_tbl2[]�ύX���́A�ȉ��̕����������ύX�K�v  */
                                                                         /*         :ID�ݒ�,�D��x�ݒ�,�v���w���p�f�[�^�ݒ�                      */
                                                                         /*         :����֐�eminj_eminj_hpri()���̃X�^�b�N�Z�o����              */
                                                                         /*         :���̗D��I���e�[�u���ƕ�����Q�ƂƂȂ�v����ݒ肷��ꍇ��  */
                                                                         /*         :rap�֐����쐬���ݒ肷�邱��                                 */
    {
#if (JEALLHV_E == u1g_EJCC_ALLHV_E) && (EMINJ_STAHV_MEDI == ON)      /*�yALL HV�zAND�yHV�n������v���g�p�z*/
        { &vdg_estahv_emedi_dataget2,       u1g_EMINJ_STAHV_ID    }, /* �D��x=46 :HV�n������ */
#endif /* JEALLHV_E,EMINJ_STAHV_MEDI */
#if EMINJ_FREE6 == ON   /*�y�ذ�߰�6�g�p�z*/
        { &vdg_eminj_efree6_emedi_dataget,  u1g_EMINJ_FREE6_ID    }, /* �D��x=206 :�ذ�߰�6�p���˗v�� */
#endif /* EMINJ_FREE6 */
#if EMINJ_FREE7 == ON   /*�y�ذ�߰�7�g�p�z*/
        { &vdg_eminj_efree7_emedi_dataget,  u1g_EMINJ_FREE7_ID    }, /* �D��x=207 :�ذ�߰�7�p���˗v�� */
#endif /* EMINJ_FREE7 */
/* ���������������������������������������������������������������������������������������� */
        /* �K���e�[�u���̏I�[�ɐݒ肷�邱�� */
        { &vds_eminj_dummy_emedi_dataget2,  u1g_EMINJ_NONE_ID     }  /* �D��x=�Ȃ� :�_�~�[ */
/* ���������������������������������������������������������������������������������������� */
    };

/*-------------------------------------------------------------------*/
/* �n����v���D��I���e�[�u���̒�`                                  */
/*-------------------------------------------------------------------*/
    static volatile const st_EMINJ_EMINJ_TBL sts_eminj_eminjast_tbl[] = /* ���ӎ���:sts_eminj_eminjast_tbl[]�ύX���́A�ȉ��̕����������ύX�K�v */
                                                                        /*         :ID�ݒ�,�D��x�ݒ�,�v���w���p�f�[�^�ݒ�                     */
                                                                        /*         :����֐�eminj_eminj_hpri()���̃X�^�b�N�Z�o����             */
                                                                        /*         :���̗D��I���e�[�u���ƕ�����Q�ƂƂȂ�v����ݒ肷��ꍇ�� */
                                                                        /*         :rap�֐����쐬���ݒ肷�邱��                                */
    {
#if ((JERMTCTR == u1g_EJCC_USE) || (JENVCTR == u1g_EJCC_USE)) && (JEMICN_E != u1g_EJCC_SUB_E) && (EMINJ_STACM_MEDI == ON) /* (�y�Ӱĺ��۰ٗL�zOR�y��޺��۰ٗL�z) AND�ySUB-CPU�ȊO�zAND�y�n���������オ�萧��v���g�p�z*/
        { &vdg_estacm_emedi_dataget,        u1g_EMINJ_STACM_ID    }, /* �D��x=28 :�n���������オ�萧�� */
#endif /* JERMTCTR,JENVCTR,JEMICN_E,EMINJ_STACM_MEDI */
#if (JESS == u1g_EJCC_USE) || (JEEGMG_E == u1g_EJCC_HVCLUTCH_E)             /*�ySS����L�zOR�yEG-MG�ׯ��z*/
        { &vdg_estass_emedi_dataget,        u1g_EMINJ_STASS_ID    },    /* �D��x=30 :SS�n������ */
#endif /* JESS,JEEGMG_E */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)                      /*�y�ޭ��INJ�zOR�yD-4�z*/
        { &vdg_estratist_emedi_dataget,     u1g_EMINJ_STRATIST_ID },    /* �D��x=42 :���w�n������ */
#endif /* JEEFI */
#if EMINJ_FREE8 == ON   /*�y�ذ�߰�8�g�p�z*/
        { &vdg_eminj_efree8_emedi_dataget,  u1g_EMINJ_FREE8_ID    },    /* �D��x=208 :�ذ�߰�8�p���˗v�� */
#endif /* EMINJ_FREE8 */
#if EMINJ_FREE9 == ON   /*�y�ذ�߰�9�g�p�z*/
        { &vdg_eminj_efree9_emedi_dataget,  u1g_EMINJ_FREE9_ID    },    /* �D��x=209 :�ذ�߰�9�p���˗v�� */
#endif /* EMINJ_FREE9 */
/* ���������������������������������������������������������������������������������������� */
        /* �K���e�[�u���̏I�[�ɐݒ肷�邱�� */
        { &vds_eminj_dummy_emedi_dataget,   u1g_EMINJ_NONE_ID }         /* �D��x=�Ȃ� :�_�~�[ */
/* ���������������������������������������������������������������������������������������� */
    };

/*-------------------------------------------------------------------*/
/* �n����v���D��I���e�[�u���Q�̒�`                                */
/*-------------------------------------------------------------------*/
    static volatile const st_EMINJ_EMINJ_TBL2 sts_eminj_eminjast_tbl2[] = /* ���ӎ���:sts_eminj_eminjast_tbl2[]�ύX���́A�ȉ��̕����������ύX�K�v */
                                                                          /*         :ID�ݒ�,�D��x�ݒ�,�v���w���p�f�[�^�ݒ�                      */
                                                                          /*         :����֐�eminj_eminj_hpri()���̃X�^�b�N�Z�o����              */
                                                                          /*         :���̗D��I���e�[�u���ƕ�����Q�ƂƂȂ�v����ݒ肷��ꍇ��  */
                                                                          /*         :rap�֐����쐬���ݒ肷�邱��                                 */
    {
#if (JEALLHV_E == u1g_EJCC_ALLHV_E) && (EMINJ_STAHV_MEDI == ON)      /*�yALL HV�zAND�yHV�n������v���g�p�z*/
        { &vdg_estahv_emedi_dataget2,        u1g_EMINJ_STAHV_ID    },     /* �D��x=46 :HV�n������ */
#endif /* JEALLHV_E,EMINJ_STAHV_MEDI */
#if EMINJ_FREE10 == ON   /*�y�ذ�߰�10�g�p�z*/
        { &vdg_eminj_efree10_emedi_dataget,  u1g_EMINJ_FREE10_ID    },    /* �D��x=210 :�ذ�߰�10�p���˗v�� */
#endif /* EMINJ_FREE10 */
#if EMINJ_FREE11 == ON   /*�y�ذ�߰�11�g�p�z*/
        { &vdg_eminj_efree11_emedi_dataget,  u1g_EMINJ_FREE11_ID    },    /* �D��x=211 :�ذ�߰�11�p���˗v�� */
#endif /* EMINJ_FREE11 */
/* ���������������������������������������������������������������������������������������� */
        /* �K���e�[�u���̏I�[�ɐݒ肷�邱�� */
        { &vds_eminj_dummy_emedi_dataget2,   u1g_EMINJ_NONE_ID }         /* �D��x=�Ȃ� :�_�~�[ */
/* ���������������������������������������������������������������������������������������� */
    };

/*-------------------------------------------------------------------*/
/* �ʏ�D��I���e�[�u���̒�`                                        */
/*-------------------------------------------------------------------*/

    static volatile const st_EMINJ_EMINJ_TBL sts_eminj_eminj_tbl[] = /* ���ӎ���:sts_eminj_eminj_tbl[]�ύX���́A�ȉ��̕����������ύX�K�v    */
                                                                     /*         :ID�ݒ�,�D��x�ݒ�,�v���w���p�f�[�^�ݒ�                     */
                                                                     /*         :����֐�eminj_eminj_hpri()���̃X�^�b�N�Z�o����             */
                                                                     /*         :���̗D��I���e�[�u���ƕ�����Q�ƂƂȂ�v����ݒ肷��ꍇ�� */
                                                                     /*         :rap�֐����쐬���ݒ肷�邱��                                */
    {
#if (JEMAT_BENCHI == u1g_EJCC_USE) || (JEMAT_BENCH_E == u1g_EJCC_USE)   /*�y�����K���p��ėL�zOR�y�����K��Ӱ�ޗL�z*/
        { &vdg_ebench_emedi_dataget,        u1g_EMINJ_BENCH_ID    }, /* �D��x=2 :�����K���p���˗v�� */
#endif /* JEMAT_BENCHI,JEMAT_BENCH_E */
        { &vdg_eegstpvs_emedi_dataget,      u1g_EMINJ_EGSTPVS_ID  }, /* �D��x=4 :���˒�~ */
#if JEEFI == u1g_EJCC_DUAL      /*�y�ޭ��INJ�z*/
        { &vdg_edeflair_emedi_dataget,      u1g_EMINJ_DEFLAIR_ID  }, /* �D��x=6 :�H�괱�������� */
#endif /* JEEFI */
#if (JEEGMG_E == u1g_EJCC_HVPLGR_E) || (JEEGMG_E == u1g_EJCC_HVDIRECT_E)    /*�yEG-MG�V���ޱ�zOR�yEG-MG�����z*/
        { &vdg_estphv_emedi_dataget,        u1g_EMINJ_STPHV_ID    }, /* �D��x=12 :HV��~���� */
#endif /* JEEGMG_E */
#if (JESS == u1g_EJCC_USE) || (JEEGMG_E == u1g_EJCC_HVCLUTCH_E)         /*�ySS����L�zOR�yEG-MG�ׯ��z*/
        { &vdg_estpss_emedi_dataget,        u1g_EMINJ_STPSS_ID    }, /* �D��x=14 :SS��~���� */
#endif /* JESS,JEEGMG_E */
#if JEALLHV_E == u1g_EJCC_ALLHV_E                                       /*�yALL HV�z*/
        { &vdg_erdnves_group00_dataget,     u1g_EMINJ_RDNVES_ID   }, /* �D��x=16 :�ݼ�ݒ�~�E�n�����̐U���ጸ */
#endif /* JEALLHV_E */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
        { &vdg_esjc_emedi_dataget,          u1g_EMINJ_SJC_ID      }, /* �D��x=20 :�G�}�}���g�@���� */
#endif /* JEEFI */
#if JEALLHV_E == u1g_EJCC_ALLHV_E                                       /*�yALL HV�z*/
        { &vdg_ewupcat_emedi_dataget,       u1g_EMINJ_WUPCAT_ID   }, /* �D��x=24 :�G�}�g�@���� */
#endif /* JEALLHV_E */
#if (JENGPF_E != u1g_EJCC_NOT_USE) && (EMINJ_FCFRCTRL_MEDI == ON)  /*�yGPF�L�zAND�y1�C��FC����v���g�p�z*/
        { &vdg_efcfrctrl_emedi_dataget,     u1g_EMINJ_FCFRCTRL_ID }, /* �D��x=26 :1�C��FC���� */
                                                                     /* ��AES�Ώۋ@�\�ł��邽�߁AAES�Ώێd���ɂ͎g�p�֎~ */
#endif /* JENGPF_E,EMINJ_FCFRCTRL_MEDI */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
        { &vds_eminj_erestahot_rap_dataget, u1s_EMINJ_RESTAHOT_ID }, /* �D��x=32 :�����Ďn������ */
#endif /* JEEFI */
        { &vdg_efcinjctr_emedi_dataget,     u1g_EMINJ_FCINJCTR_ID }, /* �D��x=50 :FC���R�����ː��� */
#if (JEALLHV_E == u1g_EJCC_ALLHV_E) && (JEEFI != u1g_EJCC_D4)       /*�yALL HV�zAND�yD-4�ȊO�z*/
        { &vds_eminj_erdpn_rap_dataget,     u1g_EMINJ_RDPN_ID     }, /* �D��x=52 :PN�ጸ���� */
                                                                     /* �n�����v���̂o�m�ጸ����Ǝ擾�֐��������ꂽ�ꍇ�́A */
                                                                     /* �n�����v������A�ʏ펞�v������̂o�m�ጸ����̔���,rap�֐����폜���邱�� */
#endif /* JEALLHV_E,JEEFI */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
        { &vdg_ertnfc_group00_dataget,      u1s_EMINJ_RTNFC_ID    }, /* �D��x=54 :FC���A���� */
#endif /* JEEFI */
#if JEEFI == u1g_EJCC_DUAL      /*�y�ޭ��INJ�z*/
        { &vdg_eclrdepi_emedi_dataget,      u1s_EMINJ_CLRDEPI_ID  }, /* �D��x=56 :����َ��ݼު�����ߏ������� */
 #if JEPRDEMAND == u1g_EJCC_NOT_USE     /*�y�ϔR�����䖳�z*/
        { &vdg_efpldlv_emedi_dataget,       u1s_EMINJ_FPLDLV_ID   }, /* �D��x=60 :�ሳ�����ؓ��R��������𐧌� */
 #endif /* JEPRDEMAND */
#endif /* JEEFI */
#if JEEFI == u1g_EJCC_DUAL      /*�y�ޭ��INJ�z*/
        { &vdg_edthrctrl_emedi_dataget,     u1g_EMINJ_DTHRCTRL_ID }, /* �D��x=64 :�C�����ި�ސ��� */
#endif /* JEEFI */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
 #if (JEPLMLT_E == u1g_EJCC_NOT_USE) && (EMINJ_ACTLFG_MEDI == ON)  /*�yPL������˖��zAND�y�߰�����Ċw�K�ׂ̱̈�è�ސ���v���g�p�z*/
        { &vdg_eactlfg_emedi_dataget,       u1g_EMINJ_ACTLFG_ID   }, /* �D��x=66 :�߰�����Ċw�K�ׂ̱̈�è�ސ��� */
 #endif /* JEPLMLT_E,EMINJ_ACTLFG_MEDI */
#endif /* JEEFI */
#if JEEFI == u1g_EJCC_DUAL      /*�y�ޭ��INJ�z*/
 #if (JEOBDAFIMB_D == u1g_EJCC_USE) && (EMINJ_INJIMB_MEDI == ON)    /*�yAF�C���Բ����ݽ�L�zAND�y�����ݽ���̕��ː���v���g�p�z*/
        { &vdg_einjimb_emedi_dataget,       u1s_EMINJ_INJIMB_ID   }, /* �D��x=72 :�����ݽ���̕��ː��� */
 #endif /* JEOBDAFIMB_D,EMINJ_INJIMB_MEDI */
 #if JEFFV != u1g_EJCC_NOT_USE  /*�yFFV����L�z*/
        { &vdg_eactarefuel_emedi_dataget,   u1s_EMINJ_ACTAREFUEL_ID }, /* �D��x=74 :������̕���������è�ސ��� */
 #endif /* JEFFV */
 #if EMINJ_ACTOBD_MEDI == ON    /* �yOBD�v���ɂ�鱸è�ސ���v���g�p�z */
        { &vdg_eactobd_emedi_dataget,       u1g_EMINJ_ACTOBD_ID   }, /* �D��x=76 :OBD�v���ɂ�鱸è�ސ��� */
 #endif /* EMINJ_ACTOBD_MEDI */
 #if (JEOBDAFIMB_D == u1g_EJCC_USE) && (EMINJ_IMBRQ_MEDI == ON)  /*�yAF�C���Բ����ݽ�L�zAND�y�����ݽOBD�v���ɂ�鱸è�ސ���v���g�p�z*/
        { &vdg_eimbrq_emedi_dataget,        u1g_EMINJ_IMBRQ_ID    }, /* �D��x=78 :�����ݽOBD�v���ɂ�鱸è�ސ��� */
 #endif /* JEOBDAFIMB_D,EMINJ_IMBRQ_MEDI */
 #if (JEOBDMF == u1g_EJCC_USE) && (EMINJ_MFINJRQ_MEDI == ON)  /*�y����OBD�L�zAND�y����OBD�v���ɂ�鱸è�ސ���v���g�p�z*/
        { &vdg_emfinjrq_emedi_dataget,      u1g_EMINJ_MFINJRQ_ID  }, /* �D��x=80 :����OBD�v���ɂ�鱸è�ސ��� */
 #endif /* JEOBDMF,EMINJ_MFINJRQ_MEDI */
 #if (JEOBDFKG == u1g_EJCC_USE) && (EMINJ_FKGDRQ_MEDI == ON)  /* �y�R��OBD�L�zAND�y�R���nOBD�v���ɂ�鱸è�ސ���v���g�p�z */
        { &vdg_efkgdrq_emedi_dataget,       u1g_EMINJ_FKGDRQ_ID   }, /* �D��x=82 :�R���nOBD�v���ɂ�鱸è�ސ��� */
 #endif /* JEOBDFKG,EMINJ_FKGDRQ_MEDI */
        { &vdg_eactgaf_emedi_dataget,       u1g_EMINJ_ACTGAF_ID   }, /* �D��x=84 :A/F�w�K�ׂ̱̈�è�ސ��� */
#endif /* JEEFI */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
        { &vdg_ekctrn_emedi_dataget,        u1s_EMINJ_KCTRN_ID    }, /* �D��x=86 :���iɯ��h�~���� */
#endif /* JEEFI */
#if JEEFI == u1g_EJCC_DUAL      /*�y�ޭ��INJ�z*/
        { &vdg_erdvap_emedi_dataget,        u1s_EMINJ_RDVAP_ID    }, /* �D��x=88 :�ް�߰�}������ */
        { &vdg_edwnpr_emedi_dataget,        u1s_EMINJ_DWNPR_ID    }, /* �D��x=90 :�R���ጸ���� */
#endif /* JEEFI */
        { &vdg_epwrup_emedi_dataget,        u1s_EMINJ_PWRUP_ID    }  /* �D��x=92 :�o�͐��\���㐧�� */
#if JEEFI == u1g_EJCC_DUAL      /*�y�ޭ��INJ�z*/
       ,{ &vdg_eprvdil_emedi_dataget,       u1s_EMINJ_PRVDIL_ID   }  /* �D��x=96 :��Ԋ�ߖh�~���� */
#endif /* JEEFI */
#if EMINJ_FREE0 == ON   /*�y�ذ�߰�0�g�p�z*/
       ,{ &vdg_eminj_efree0_emedi_dataget,  u1g_EMINJ_FREE0_ID    }  /* �D��x=200 :�ذ�߰�0�p���˗v�� */
#endif /* EMINJ_FREE0 */
#if EMINJ_FREE1 == ON   /*�y�ذ�߰�1�g�p�z*/
       ,{ &vdg_eminj_efree1_emedi_dataget,  u1g_EMINJ_FREE1_ID    }  /* �D��x=201 :�ذ�߰�1�p���˗v�� */
#endif /* EMINJ_FREE1 */
    };

    static volatile const st_EMINJ_EMINJ_TBL2 sts_eminj_eminj_tbl2[] = /* ���ӎ���:sts_eminj_eminj_tbl2[]�ύX���́A�ȉ��̕����������ύX�K�v   */
                                                                       /*         :ID�ݒ�,�D��x�ݒ�,�v���w���p�f�[�^�ݒ�                     */
                                                                       /*         :����֐�eminj_eminj_hpri()���̃X�^�b�N�Z�o����             */
                                                                       /*         :���̗D��I���e�[�u���ƕ�����Q�ƂƂȂ�v����ݒ肷��ꍇ�� */
                                                                       /*         :rap�֐����쐬���ݒ肷�邱��                                */
    {
#if (JEALLHV_E == u1g_EJCC_ALLHV_E) && (JEPLMLT_E == u1g_EJCC_USE) && (EMINJ_BINJPLCTR_WC_MEDI == ON) /*�yALL HV�zAND�yPL������˗L�zAND�y�߰�����ĕ��˂�p������{���ː���(�G�}�g�@��)�v���g�p�z*/
        { &vdg_ebinjplctr_wc_emedi_dataget,  u1g_EMINJ_BINJPLCTR_WC_ID   },    /* �D��x=22 :�߰�����ĕ��˂�p������{���ː���(�G�}�g�@��) */
#endif /* JEALLHV_E,JEPLMLT_E,EMINJ_BINJPLCTR_WC_MEDI */
#if (JEEGMG_E == u1g_EJCC_HVPLGR_E) && (JEFFV == u1g_EJCC_NOT_USE) && (JEPLMLT_E == u1g_EJCC_USE) && (EMINJ_BINJPLCTR_STAHV_MEDI == ON) /*�yEG-MG�V���ޱ�zAND�yFFV���䖳�zAND�yPL������˗L�zAND�y�߰�����ĕ��˂�p������{���ː���(HV�n�����䎞)�v���g�p�z*/
        { &vdg_ebinjplctr_stahv_emedi_dataget, u1g_EMINJ_BINJPLCTR_STAHV_ID },    /* �D��x=48 :�߰�����ĕ��˂�p������{���ː���(HV�n�����䎞) */
#endif /* JEEGMG_E,JEFFV,JEPLMLT_E,EMINJ_BINJPLCTR_STAHV_MEDI */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
 #if (JEPLMLT_E == u1g_EJCC_USE) && (EMINJ_ACTLFG_MEDI == ON)  /*�yPL������˗L�zAND�y�߰�����Ċw�K�ׂ̱̈�è�ސ���v���g�p�z*/
        { &vdg_eactlfg_emedi_dataget2,       u1g_EMINJ_ACTLFG_ID   },    /* �D��x=66 :�߰�����Ċw�K�ׂ̱̈�è�ސ��� */
 #endif /* JEPLMLT_E,EMINJ_ACTLFG_MEDI */
#endif /* JEEFI */
#if JEPLMLT_E == u1g_EJCC_USE  /*�yPL������˗L�z*/
 #if EMINJ_BINJPLCTR_MEDI == ON   /*�y�߰�����ĕ��˂�p������{���ː���v���g�p�z*/
        { &vdg_ebinjplctr_emedi_dataget,    u1g_EMINJ_BINJPLCTR_ID   },  /* �D��x=98 :�߰�����ĕ��˂�p������{���ː��� */
 #endif /* EMINJ_BINJPLCTR_MEDI */
#endif /* JEPLMLT_E */
#if EMINJ_FREE2 == ON   /*�y�ذ�߰�2�g�p�z*/
        { &vdg_eminj_efree2_emedi_dataget,  u1g_EMINJ_FREE2_ID    },     /* �D��x=202 :�ذ�߰�2�p���˗v�� */
#endif /* EMINJ_FREE2 */
#if EMINJ_FREE3 == ON   /*�y�ذ�߰�3�g�p�z*/
        { &vdg_eminj_efree3_emedi_dataget,  u1g_EMINJ_FREE3_ID    },     /* �D��x=203 :�ذ�߰�3�p���˗v�� */
#endif /* EMINJ_FREE3 */
/* ���������������������������������������������������������������������������������������� */
        /* �K���e�[�u���̏I�[�ɐݒ肷�邱�� */
        { &vds_eminj_dummy_emedi_dataget2,  u1g_EMINJ_NONE_ID }         /* �D��x=�Ȃ� :�_�~�[ */
/* ���������������������������������������������������������������������������������������� */
    };

#pragma ghs enddata

    u1 u1t_prisel;                              /* lsb=1 :�ō��D��x */
    u1 u1t_idsel;                               /* lsb=1 :�v�����˕����D��x�I�𔽉f���ʎq */
    u1 u1t_did;                                 /* lsb=1 :�W��e�[�u���C���f�b�N�X */
    u1 u1t_pri;                                 /* lsb=1 :�D��x */
    u4 u4t_rqdat[2];                            /* lsb=1 :�v���w���f�[�^ 0:���\���́A1:�V�\���̃��[�N */
    st_EMINJ_EMINJ_DEF stt_minj_data = { 0 };   /* �W��f�[�^���[�N(�ꊇ������) */
    u1 u1t_prisel2;                             /* lsb=1 :�ō��D��x */
    u1 u1t_prisel_fix;                          /* lsb=1 :�ō��D��x */
    u1 u1t_prifix;                              /* lsb=1 :�m��D��x */
    st_EMINJ_EMINJ_BUF stt_minj_data2 = { 0 };  /* �W��f�[�^���[�N(�ꊇ������) */
    u1 u1t_stprisel;                            /* lsb=1 :�I�����ꂽ�D��x(�n����) */
    u1 u1t_stprisel2;                           /* lsb=1 :�I�����ꂽ�D��x(�n����2) */
    u1 u1t_stdid;                               /* lsb=1 :�n�����v���W��e�[�u���C���f�b�N�X */
    u1 u1t_stpri;                               /* lsb=1 :�n�����v���̗D��x */
    u1 u1t_stpri2;                              /* lsb=1 :�n�����v��2�̗D��x */
    u4 u4t_strqdat;                             /* lsb=1 :�v���w���f�[�^ */
    u4 u4t_strqdat2;                            /* lsb=1 :�v���w���f�[�^2 */
    u1 u1t_astprisel;                           /* lsb=1 :�I�����ꂽ�D��x(�n����) */
    u1 u1t_astprisel2;                          /* lsb=1 :�I�����ꂽ�D��x(�n����2) */
    u1 u1t_astdid;                              /* lsb=1 :�n����v���W��e�[�u���C���f�b�N�X */
    u1 u1t_astpri;                              /* lsb=1 :�n����v���̗D��x */
    u1 u1t_astpri2;                             /* lsb=1 :�n����v��2�̗D��x */
    u1 u1t_xast_edge;                           /* lsb=1 :ON->OFF�G�b�W�����t���O */
    u1 u1t_xastmedi;                            /* lsb=1 :�n����v�����⋖�t���O  */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    st_EMINJ_EMINJ_DEF stt_minjst_data = { 0 }; /* �W��f�[�^�ޔ�p�F�n����(�ꊇ������) */
    st_EMINJ_EMINJ_BUF stt_minjst_data2 = { 0 }; /* �W��f�[�^�ޔ�p�F�n����2(�ꊇ������) */
    u1 u1t_stidsel;                             /* lsb=1 :�v�����˕����D��x�I�𔽉f���ʎq */
    u1 u1t_stprisel_fix;                        /* lsb=1 :�n�����̍ō��D��x */
    u1 u1t_sjc_pri_c;                           /* lsb=1 :�G�}�}���g�@����̗D��x */
#endif /* JEEFI */
#if (JEALLHV_E == u1g_EJCC_ALLHV_E) && (JEEFI == u1g_EJCC_PORT)     /*�yALL HV�zAND�y�߰āz*/
    u1 u1t_rdpn_pri_c;                          /* lsb=1 :PN�ጸ����̗D��x */
    u1 u1t_rdpn_st_pri_c;                       /* lsb=1 :PN�ጸ����(�n����)�̗D��x */
#endif /* JEALLHV_E,JEEFI */

#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    u1t_sjc_pri_c = u1g_eminj_SJC_PRI;
    u1t_stidsel = u1g_EMINJ_NONE_ID;   /* �v�����˕������f���ʎq������ */
    u1t_stprisel_fix = u1g_EMINJ_PRINORQ;   /* �D��x������ */
#endif /* JEEFI */
    u4t_strqdat  = u4s_EMINJ_NORQDAT;   /* �v�����˕����v���L���ʎq������ */
    u4t_strqdat2 = u4s_EMINJ_NORQDAT;   /* �v�����˕����v���L���ʎq������ */
    u1t_prisel = u1g_EMINJ_PRINORQ;    /* �D��x������ */
    u1t_idsel = u1g_EMINJ_NONE_ID;     /* �v�����˕������f���ʎq������ */
    u4t_rqdat[0] = u4s_EMINJ_NORQDAT;  /* �v�����˕����v���L���ʎq������ */
    u1t_prisel2 = u1g_EMINJ_PRINORQ;   /* �D��x������ */
    u1t_prisel_fix = u1g_EMINJ_PRINORQ;    /* �D��x������ */
    u1t_prifix = u1g_EMINJ_PRINORQ;    /* �D��x������ */

    /* �W��Ώە��i��dataget�֐���������Q�ƂƂȂ���̂�NRAM�ɑޔ� */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)              /*�y�ޭ��INJ�zOR�yD-4�z*/
    vds_eminj_einj_datacopy( &sts_eminj_erestahot_data, ptt_datdft );
    vdg_erestahot_emedi_dataget(&sts_eminj_erestahot_data);     /* ����������ł̂ݎQ�Ƃ��邽�ߕ����񏑂����ݖ�薳 */
#endif /* JEEFI */
#if (JEALLHV_E == u1g_EJCC_ALLHV_E) && (JEEFI != u1g_EJCC_D4)       /*�yALL HV�zAND�yD-4�ȊO�z*/
    vds_eminj_einj_datacopy( &sts_eminj_erdpn_data, ptt_datdft );
    vdg_erdpn_emedi_dataget( &sts_eminj_erdpn_data );           /* ����������ł̂ݎQ�Ƃ��邽�ߕ����񏑂����ݖ�薳 */
#endif /* JEALLHV_E,JEEFI */

    /* exastmedi�i�n����v�����⋖�t���O�j�̃N���A���� */
    u1t_xast_edge = (u1)OFF;
    u1t_xastmedi = u1s_eminj_exastmedi;
    if ( ( u1s_eminj_exasto == (u1)ON )             /* �n�����莞 */
      && ( u1s_eminj_exast_lch == (u1)OFF ) )
    {
        u1t_xast_edge = (u1)ON; /* ON->OFF�G�b�W���� */
        u1t_xastmedi = (u1)OFF;
    }

    /* eminjst_tbl��eminjast_tbl�Aeminjst_tbl2��eminjast_tbl2���g���v���̒��� */
    if ( u1t_xastmedi == (u1)OFF )  /* �n�����v�����⎞ */
    {
        /* �n����,�n����̒���͔w�������̂���if~else�����Ƃ��Ă��邪 */
        /* if~if�������s���ꍇ��estpri�Aestpri2�Aeastpri�Aeastpri2�Aeinjmedislid�̃��b�`���K�v�ɂȂ邽�ߒ��ӂ��邱�� */
        /* �D��x�̔�r���s���ꍇ�́A�v���Ȃ�����u1g_EMINJ_PRINORQ(0)�ƂȂ荂�D��ƌ���Ĕ��肷�邽�ߒ��ӂ��邱�� */
        u1t_stprisel   = u1g_EMINJ_PRINORQ;
        u1t_stprisel2  = u1g_EMINJ_PRINORQ;
        u1t_astprisel  = u1g_EMINJ_PRINORQ; /* ������ */ /* temp:�d�l�m�F�̓��e���f(DENG-STD-25017�A) */
        u1t_astprisel2 = u1g_EMINJ_PRINORQ; /* ������ */ /* temp:�d�l�m�F�̓��e���f(DENG-STD-25017�A) */

        /* �n�����v���e�[�u������ */
        for ( u1t_stdid = (u1)0U; u1t_stdid < u1s_EMINJ_EMINJST_NUM; u1t_stdid++ )
        {
            vds_eminj_einj_datacopy( &stt_minj_data, ptt_datdft );
            sts_eminj_eminjst_tbl[u1t_stdid].pt_dataget( &stt_minj_data );
#ifdef JGXSTACK         /* �X�^�b�N�Z�o�p */
 #if ((JERMTCTR == u1g_EJCC_USE) || (JENVCTR == u1g_EJCC_USE)) && (JEMICN_E != u1g_EJCC_SUB_E) && (EMINJ_STACM_MEDI == ON) /* (�y�Ӱĺ��۰ٗL�zOR�y��޺��۰ٗL�z) AND�ySUB-CPU�ȊO�zAND�y�n���������オ�萧��v���g�p�z*/
            vdg_estacm_emedi_dataget(&stt_minj_data);
 #endif /* JERMTCTR,JENVCTR,JEMICN_E,EMINJ_STACM_MEDI */
 #if (JESS == u1g_EJCC_USE) || (JEEGMG_E == u1g_EJCC_HVCLUTCH_E)    /*�ySS����L�zOR�yEG-MG�ׯ��z*/
            vdg_estass_emedi_dataget(&stt_minj_data);
 #endif /* JESS,JEEGMG_E */
 #if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)             /*�y�ޭ��INJ�zOR�yD-4�z*/
            vds_eminj_erestahot_rap_dataget(&stt_minj_data);
            vdg_ekcst_emedi_dataget(&stt_minj_data);
 #endif /* JEEFI */
 #if (JEALLHV_E == u1g_EJCC_ALLHV_E) && (JEEFI == u1g_EJCC_PORT)    /*�yALL HV�zAND�y�߰āz*/
            vds_eminj_erdpn_rap_dataget(&stt_minj_data);
 #endif /* JEALLHV_E,JEEFI */
 #if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)             /*�y�ޭ��INJ�zOR�yD-4�z*/
            vdg_estratist_emedi_dataget(&stt_minj_data);
 #endif /* JEEFI */
 #if JEEFI == u1g_EJCC_DUAL                                         /*�y�ޭ��INJ�z*/
            vdg_estafrg_emedi_dataget(&stt_minj_data);
 #endif /* JEEFI */
 #if EMINJ_FREE4 == ON   /*�y�ذ�߰�4�g�p�z*/
            vdg_eminj_efree4_emedi_dataget(&stt_minj_data);
 #endif /* EMINJ_FREE4 */
 #if EMINJ_FREE5 == ON   /*�y�ذ�߰�5�g�p�z*/
            vdg_eminj_efree5_emedi_dataget(&stt_minj_data);
 #endif /* EMINJ_FREE5 */

#endif  /* JGXSTACK */
            u1t_stpri = stt_minj_data.u1_pri;      /* �D��x�擾 */

#if (JEALLHV_E == u1g_EJCC_ALLHV_E) && (JEEFI == u1g_EJCC_PORT)     /*�yALL HV�zAND�y�߰āz*/
            u1t_rdpn_pri_c = u1g_eminj_RDPN_PRI;
#endif /* JEALLHV_E,JEEFI */

            if ( ( u1t_stpri != u1g_EMINJ_PRINORQ )     /* ���⋖�� */
#if (JEALLHV_E == u1g_EJCC_ALLHV_E) && (JEEFI == u1g_EJCC_PORT)     /*�yALL HV�zAND�y�߰āz*/
              && ( u1t_stpri != u1t_rdpn_pri_c )        /* �o�m�ጸ����v���łȂ� */
                                                        /* �o�m�ጸ����v����dataget�֐����n�����ƒʏ펞�ŋ��ʂ̂��߁A�ʏ펞�̗v���łȂ����Ƃ𔻒肷�� */
#endif /* JEALLHV_E,JEEFI */
               )
            {
                if ( ( u1t_idsel == u1g_EMINJ_NONE_ID )     /* ����X�V���� */
                  || ( u1t_stprisel > u1t_stpri ) )         /* �D��I��(�D��x��MIN�Z���N�g) */
                {
                    u1t_stprisel = u1t_stpri;                                             /* �D��x�X�V */
                    u1t_prisel_fix = u1t_stpri;                                           /* �D��x�X�V */
                    u1t_prifix = u1t_stpri;                                               /* �m��D��x�X�V */
                    u1t_idsel = sts_eminj_eminjst_tbl[u1t_stdid].u1_id;                   /* ���ʎq�X�V */
                    u4t_rqdat[0] = stt_minj_data.u4_einjrq_dat;                           /* �v���L���ʎq�X�V */
#if JEEFI != u1g_EJCC_D4        /*�yD-4�ȊO�z*/
                    if ( ( (u4t_rqdat[0] & u4g_EMINJ_RQAINJP) != (u4)0U )                 /* �|�[�g���ˊJ�n�����v���L�� */
                      && ( (u4t_rqdat[0] & u4g_EMINJ_RQAINJP1) == (u4)0U ) )              /* �|�[�g1��ڕ��ˊJ�n�����v������ */
                    {
                        stt_minj_data.s2_eainjp1 = stt_minj_data.s2_eainjp;               /* �|�[�g1��ڕ��ˊJ�n�����X�V */
                    }
                    if ( ( (u4t_rqdat[0] & u4g_EMINJ_RQQINJSTP) != (u4)0U )               /* �|�[�g�n�������˗ʗv���L�� */
                      && ( (u4t_rqdat[0] & u4g_EMINJ_RQQINJSTP1) == (u4)0U ) )            /* �|�[�g1��ڎn�������˗ʗv������ */
                    {
                        stt_minj_data.s4_eqinjstp1 = stt_minj_data.s4_eqinjstp;           /* �|�[�g1��ڎn�������˗ʍX�V */
                    }
#endif /* JEEFI */
                    vds_eminj_einj_datacopy( ptt_datsel, &stt_minj_data );

                    /* �n�����̒��⌋�ʂ�ޔ� */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
                    vds_eminj_einj_datacopy( &stt_minjst_data, &stt_minj_data );
                    u1t_stprisel_fix = u1t_stpri;
                    u1t_stidsel = u1t_idsel;
#endif /* JEEFI */
                    u4t_strqdat = u4t_rqdat[0];
                }
            }
        } /* �n�����v���e�[�u�����⃋�[�v�I�� */

        if ( u1t_stprisel != u1g_EMINJ_PRINORQ )   /* �n�����D��I��v�������鎞 */
        {
            if ( (u4t_strqdat & u4g_EMINJ_RQXQINJAST) == (u4)0U )   /* �n���㕬�˗ʗv���t���O�v������ */
                                                                    /* eminj_8msm()�ɂ����l�̏��������邽�ߕύX���͍��킹�Č��������� */
            {
                glbitcp_bibi( ptt_datdft->bi_exqinjast, ptt_datsel->bi_exqinjast ); /* stt_minjst_data.bi_exqinjast�͍X�V���Ȃ����� */
                                                                                    /* exqinjast �� ptt_datsel->bi_exqinjast���Q�Ƃ��邱�� */
            }
            /* exastmedi�i�n����v�����⋖�t���O�j�̃Z�b�g���� */
            if ( ptt_datsel->bi_exqinjast == (u1)ON )   /* �n������ɂ��n���㕬�˗ʗv���� */
            {
                if ( u1t_xast_edge == (u1)OFF )         /* �N���A�D��̂��߁A�N���A�����̋t�����Ŕ��� */
                {
                    u1t_xastmedi = (u1)ON;
                }
                u1s_eminj_estprir = u1t_stprisel;
            }
        }

        /* �����܂ł̋��\���̏����f�t�H���g�Ƃ��ĐV�\���̂ɈڐA */
        vds_eminj_einj_dataconv( ptt_datsel2, ptt_datsel );
        u4t_rqdat[1] = ptt_datsel2->u4_einjrq_dat;
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
        vds_eminj_einj_dataconv( &stt_minjst_data2, &stt_minjst_data );
#endif /* JEEFI */

        /* �n�����v���e�[�u��2���� */
        for ( u1t_stdid = (u1)0U; u1t_stdid < u1s_EMINJ_EMINJST_NUM2; u1t_stdid++ )
        {
            vds_eminj_einj_datacopy2( &stt_minj_data2, ptt_datdft2 );
            sts_eminj_eminjst_tbl2[u1t_stdid].pt_dataget2( &stt_minj_data2 );
#ifdef JGXSTACK         /* �X�^�b�N�Z�o�p */
 #if (JEALLHV_E == u1g_EJCC_ALLHV_E) && (EMINJ_STAHV_MEDI == ON)    /*�yALL HV�zAND�yHV�n������v���g�p�z*/
            vdg_estahv_emedi_dataget2(&stt_minj_data2);
 #endif /* JEALLHV_E,EMINJ_STAHV_MEDI */
 #if EMINJ_FREE6 == ON   /*�y�ذ�߰�6�g�p�z*/
            vdg_eminj_efree6_emedi_dataget(&stt_minj_data2);
 #endif /* EMINJ_FREE6 */
 #if EMINJ_FREE7 == ON   /*�y�ذ�߰�7�g�p�z*/
            vdg_eminj_efree7_emedi_dataget(&stt_minj_data2);
 #endif /* EMINJ_FREE7 */
#endif  /* JGXSTACK */

            u1t_stpri2 = stt_minj_data2.u1_pri; /* �D��x�擾 */

            if ( u1t_stpri2 != u1g_EMINJ_PRINORQ )  /* �n�����D��I��v���Q�����鎞 */
            {
                if ( ( u1t_stprisel2 == u1g_EMINJ_PRINORQ ) /* ����X�V���� */
                  || ( u1t_stprisel2 > u1t_stpri2 ) )       /* �D��I��(�D��x��MIN�Z���N�g) */
                {
                    u1t_stprisel2 = u1t_stpri2;     /* �D��x�X�V */

                    if ( ( u1t_stpri2 < u1t_stprisel )            /* �n�����D��v���i���\���́j��荂�D��x�̎� */
                      || ( u1t_stprisel == u1g_EMINJ_PRINORQ ) )  /* �n�����D��v���i���\���́j�ɗD��x�v���Ȃ� */
                    {
                        u1t_prisel_fix = u1t_stpri2;                            /* �D��x�X�V */
                        u1t_prifix = u1t_stpri2;                                /* �m��D��x�X�V */
                        u1t_idsel = sts_eminj_eminjst_tbl2[u1t_stdid].u1_id;    /* ���ʎq�X�V */
                        u4t_rqdat[1] = stt_minj_data2.u4_einjrq_dat;            /* �v���L���ʎq�X�V */
                        u4t_strqdat2 = u4t_rqdat[1];
                        vds_eminj_einj_datacopy2( ptt_datsel2, &stt_minj_data2 );
                        /* �n�����̒��⌋�ʂ�ޔ� */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
                        vds_eminj_einj_datacopy2( &stt_minjst_data2, &stt_minj_data2 );
                        u1t_stprisel_fix = u1t_stpri2;
                        u1t_stidsel = u1t_idsel;
#endif /* JEEFI */
                    }
                }
            }
        } /* �n�����v���e�[�u��2���⃋�[�v�I�� */

        if ( ( u1t_stprisel2 != u1g_EMINJ_PRINORQ )
          && ( ( u1t_stprisel == u1g_EMINJ_PRINORQ )
            || ( u1t_stprisel2 < u1t_stprisel ) ) ) /* �n�����D��I��v���Q�����鎞�A���A�n�����D��v����荂�D��x�̎� */
        {
            if ( (u4t_strqdat2 & u4g_EMINJ_RQXQINJAST) == (u4)0U )  /* �n���㕬�˗ʗv���t���O�v������ */
                                                                    /* eminj_8msm()�ɂ����l�̏��������邽�ߕύX���͍��킹�Č��������� */
            {
                glbitcp_bibi( ptt_datdft2->bi_exqinjast, ptt_datsel2->bi_exqinjast );   /* stt_minjst_data2.bi_exqinjast�͍X�V���Ă��Ȃ����� */
                                                                                        /* exqinjast �� ptt_datsel2->bi_exqinjast���Q�Ƃ���  */
            }
            /* exastmedi�i�n����v�����⋖�t���O�j�̃Z�b�g���� */
            if ( ptt_datsel2->bi_exqinjast == (u1)ON )  /* �n������ɂ��n���㕬�˗ʗv���� */
            {
                if ( u1t_xast_edge == (u1)OFF )         /* �N���A�D��̂��߁A�N���A�����̋t�����Ŕ��� */
                {
                    u1t_xastmedi = (u1)ON;
                }
                u1s_eminj_estprir = u1t_stprisel2;
            }
            /* �����܂ł̐V�\���̏������\���̂ɈڐA */
            vds_eminj_einj_dataconv_rev( ptt_datsel, ptt_datsel2 );
            u4t_rqdat[0] = ptt_datsel->u4_einjrq_dat;
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
            vds_eminj_einj_dataconv_rev( &stt_minjst_data, &stt_minjst_data2 );
#endif /* JEEFI */
        }

    }
    else            /* �n����v�����⎞ */
    {
        /* �n����,�n����̒���͔w�������̂���if~else�����Ƃ��Ă��邪 */
        /* if~if�������s���ꍇ��estpri�Aeastpri�Aeinjmedislid�̃��b�`���K�v�ɂȂ邽�ߒ��ӂ��邱�� */
        /* �D��x�̔�r���s���ꍇ�́A�v���Ȃ�����u1g_EMINJ_PRINORQ(0)�ƂȂ荂�D��ƌ���Ĕ��肷�邽�ߒ��ӂ��邱�� */
        u1t_stprisel   = u1g_EMINJ_PRINORQ; /* ������ */ /* temp:�d�l�m�F�̓��e���f(DENG-STD-25017�A) */
        u1t_stprisel2  = u1g_EMINJ_PRINORQ; /* ������ */ /* temp:�d�l�m�F�̓��e���f(DENG-STD-25017�A) */
        u1t_astprisel  = u1g_EMINJ_PRINORQ; /* �ύX����eminj_eminjlmt_hpri()�����킹�Č��������� */
        u1t_astprisel2 = u1g_EMINJ_PRINORQ;

        /* �n����v���e�[�u������ */
        for ( u1t_astdid = (u1)0U; u1t_astdid < u1s_EMINJ_EMINJAST_NUM; u1t_astdid++ )
        {
            vds_eminj_einj_datacopy( &stt_minj_data, ptt_datdft );
            sts_eminj_eminjast_tbl[u1t_astdid].pt_dataget( &stt_minj_data );
#ifdef JGXSTACK         /* �X�^�b�N�Z�o�p */
 #if ((JERMTCTR == u1g_EJCC_USE) || (JENVCTR == u1g_EJCC_USE)) && (JEMICN_E != u1g_EJCC_SUB_E) && (EMINJ_STACM_MEDI == ON) /* (�y�Ӱĺ��۰ٗL�zOR�y��޺��۰ٗL�z) AND�ySUB-CPU�ȊO�zAND�y�n���������オ�萧��v���g�p�z*/
            vdg_estacm_emedi_dataget(&stt_minj_data);
 #endif /* JERMTCTR,JENVCTR,JEMICN_E,EMINJ_STACM_MEDI */
 #if (JESS == u1g_EJCC_USE) || (JEEGMG_E == u1g_EJCC_HVCLUTCH_E)    /*�ySS����L�zOR�yEG-MG�ׯ��z*/
            vdg_estass_emedi_dataget(&stt_minj_data);
 #endif /* JESS,JEEGMG_E */
 #if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)             /*�y�ޭ��INJ�zOR�yD-4�z*/
            vdg_estratist_emedi_dataget(&stt_minj_data);
 #endif /* JEEFI */
 #if EMINJ_FREE8 == ON   /*�y�ذ�߰�8�g�p�z*/
            vdg_eminj_efree8_emedi_dataget(&stt_minj_data);
 #endif /* EMINJ_FREE8 */
 #if EMINJ_FREE9 == ON   /*�y�ذ�߰�9�g�p�z*/
            vdg_eminj_efree9_emedi_dataget(&stt_minj_data);
 #endif /* EMINJ_FREE9 */
#endif  /* JGXSTACK */

            u1t_astpri = stt_minj_data.u1_pri;
            if ( u1t_astpri != u1g_EMINJ_PRINORQ )      /* ���⋖�� */
            {
                if ( u1t_astpri == u1s_eminj_estprir )  /* �n��������p�����ꂽ�n����v��������ꍇ */
                                                        /* �p�����ꂽ�@�\��T������݂̂̂��ߗD��x�̔�r�͕s�v */
                {
                    u1t_astprisel = u1t_astpri;                                           /* �D��x�X�V */
                    u1t_prisel_fix = u1t_astpri;                                          /* �D��x�X�V */
                    u1t_prifix = u1t_astpri;                                              /* �m��D��x�X�V */
                    u1t_idsel = sts_eminj_eminjast_tbl[u1t_astdid].u1_id;                 /* ���ʎq�X�V */
                    u4t_rqdat[0] = stt_minj_data.u4_einjrq_dat;                           /* �v���L���ʎq�X�V */
#if JEEFI != u1g_EJCC_D4        /*�yD-4�ȊO�z*/
                    if ( ( (u4t_rqdat[0] & u4g_EMINJ_RQAINJP) != (u4)0U )                 /* �|�[�g���ˊJ�n�����v���L�� */
                      && ( (u4t_rqdat[0] & u4g_EMINJ_RQAINJP1) == (u4)0U ) )              /* �|�[�g1��ڕ��ˊJ�n�����v������ */
                    {
                        stt_minj_data.s2_eainjp1 = stt_minj_data.s2_eainjp;               /* �|�[�g1��ڕ��ˊJ�n�����X�V */
                    }
                    if ( ( (u4t_rqdat[0] & u4g_EMINJ_RQQINJSTP) != (u4)0U )               /* �|�[�g�n�������˗ʗv���L�� */
                      && ( (u4t_rqdat[0] & u4g_EMINJ_RQQINJSTP1) == (u4)0U ) )            /* �|�[�g1��ڎn�������˗ʗv������ */
                    {
                        stt_minj_data.s4_eqinjstp1 = stt_minj_data.s4_eqinjstp;           /* �|�[�g1��ڎn�������˗ʍX�V */
                    }
#endif /* JEEFI */
                    vds_eminj_einj_datacopy( ptt_datsel, &stt_minj_data );
                }
            }
        } /* �n����v���e�[�u�����⃋�[�v�I�� */

        vds_eminj_einj_dataconv( ptt_datsel2, ptt_datsel ); /* �����܂ł̋��\���̏����f�t�H���g�Ƃ��ĐV�\���̂ɈڐA */
        u4t_rqdat[1] = ptt_datsel2->u4_einjrq_dat;          /* �v���L���ʎq�X�V */

        /* �n����v���e�[�u��2���� */
        for ( u1t_astdid = (u1)0U; u1t_astdid < u1s_EMINJ_EMINJAST_NUM2; u1t_astdid++ )
        {
            vds_eminj_einj_datacopy2( &stt_minj_data2, ptt_datdft2 );
            sts_eminj_eminjast_tbl2[u1t_astdid].pt_dataget2( &stt_minj_data2 );
#ifdef JGXSTACK         /* �X�^�b�N�Z�o�p */
 #if (JEALLHV_E == u1g_EJCC_ALLHV_E) && (EMINJ_STAHV_MEDI == ON)    /*�yALL HV�zAND�yHV�n������v���g�p�z*/
            vdg_estahv_emedi_dataget2(&stt_minj_data2);
 #endif /* JEALLHV_E,EMINJ_STAHV_MEDI */
 #if EMINJ_FREE10 == ON     /*�y�ذ�߰�10�g�p�z*/
            vdg_eminj_efree10_emedi_dataget(&stt_minj_data2);
 #endif /* EMINJ_FREE10 */
 #if EMINJ_FREE11 == ON     /*�y�ذ�߰�11�g�p�z*/
            vdg_eminj_efree11_emedi_dataget(&stt_minj_data2);
 #endif /* EMINJ_FREE11 */
#endif  /* JGXSTACK */

            u1t_astpri2 = stt_minj_data2.u1_pri; /* �D��x�擾 */

            if ( u1t_astpri2 != u1g_EMINJ_PRINORQ )     /* �n�����D��I��v���Q�����鎞 */
            {
                if ( u1t_astpri2 == u1s_eminj_estprir ) /* �n��������p�����ꂽ�n����v��������ꍇ */
                                                        /* �p�����ꂽ�@�\��T������݂̂̂��ߗD��x�̔�r�͕s�v */
                {
                    u1t_astprisel2 = u1t_astpri2;                           /* �D��x�X�V */
                    u1t_prisel_fix = u1t_astpri2;                           /* �D��x�X�V */
                    u1t_prifix = u1t_astpri2;                               /* �m��D��x�X�V */
                    u1t_idsel = sts_eminj_eminjast_tbl2[u1t_astdid].u1_id;  /* ���ʎq�X�V */
                    u4t_rqdat[1] = stt_minj_data2.u4_einjrq_dat;            /* �v���L���ʎq�X�V */
                    vds_eminj_einj_datacopy2( ptt_datsel2, &stt_minj_data2 );
                    vds_eminj_einj_dataconv_rev( ptt_datsel, ptt_datsel2 ); /* �����܂ł̐V�\���̏������\���̂ɈڐA */
                    u4t_rqdat[0] = ptt_datsel->u4_einjrq_dat;               /* �v���L���ʎq�X�V */
                }
            }
        } /* �n����v���e�[�u��2���⃋�[�v�I�� */

    }

    u1s_eminj_estpri = u1t_stprisel;
    u1s_eminj_estpri2 = u1t_stprisel2;
    u1s_eminj_eastpri = u1t_astprisel;
    u1s_eminj_eastpri2 = u1t_astprisel2;
    u1s_eminj_exastmedi = u1t_xastmedi;

    /* �D��x�v�f�̒��� */
    for ( u1t_did = (u1)0U; u1t_did < u1s_EMINJ_EMINJ_NUM; u1t_did++ )
    {
        vds_eminj_einj_datacopy( &stt_minj_data, ptt_datdft );
        sts_eminj_eminj_tbl[u1t_did].pt_dataget( &stt_minj_data );
#ifdef JGXSTACK         /* �X�^�b�N�Z�o�p */
 #if (JEMAT_BENCHI == u1g_EJCC_USE) || (JEMAT_BENCH_E == u1g_EJCC_USE)   /*�y�����K���p��ėL�zOR�y�����K��Ӱ�ޗL�z*/
        vdg_ebench_emedi_dataget(&stt_minj_data);
 #endif /* JEMAT_BENCHI,JEMAT_BENCH_E */
        vdg_eegstpvs_emedi_dataget(&stt_minj_data);
 #if JEEFI == u1g_EJCC_DUAL     /*�y�ޭ��INJ�z*/
        vdg_edeflair_emedi_dataget(&stt_minj_data);
 #endif /* JEEFI */
 #if (JEEGMG_E == u1g_EJCC_HVPLGR_E) || (JEEGMG_E == u1g_EJCC_HVDIRECT_E)    /*�yEG-MG�V���ޱ�zOR�yEG-MG�����z*/
        vdg_estphv_emedi_dataget(&stt_minj_data);
 #endif /* JEEGMG_E */
 #if (JESS == u1g_EJCC_USE) || (JEEGMG_E == u1g_EJCC_HVCLUTCH_E)         /*�ySS����L�zOR�yEG-MG�ׯ��z*/
        vdg_estpss_emedi_dataget(&stt_minj_data);
 #endif /* JESS,JEEGMG_E */
 #if JEALLHV_E == u1g_EJCC_ALLHV_E                                       /*�yALL HV�z*/
        vdg_erdnves_group00_dataget(&stt_minj_data);
 #endif /* JEALLHV_E */
 #if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4) /*�y�ޭ��INJ�zOR�yD-4�z*/
        vdg_esjc_emedi_dataget(&stt_minj_data);
 #endif /* JEEFI */
 #if JEALLHV_E == u1g_EJCC_ALLHV_E                                       /*�yALL HV�z*/
        vdg_ewupcat_emedi_dataget(&stt_minj_data);
 #endif /* JEALLHV_E */
 #if (JENGPF_E != u1g_EJCC_NOT_USE) && (EMINJ_FCFRCTRL_MEDI == ON)  /*�yGPF�L�zAND�y1�C��FC����v���g�p�z*/
        vdg_efcfrctrl_emedi_dataget(&stt_minj_data);
 #endif /* JENGPF_E,EMINJ_FCFRCTRL_MEDI */
 #if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4) /*�y�ޭ��INJ�zOR�yD-4�z*/
        vds_eminj_erestahot_rap_dataget(&stt_minj_data);
 #endif /* JEEFI */
        vdg_efcinjctr_emedi_dataget(&stt_minj_data);
 #if (JEALLHV_E == u1g_EJCC_ALLHV_E) && (JEEFI != u1g_EJCC_D4)      /*�yALL HV�zAND�yD-4�ȊO�z*/
        vds_eminj_erdpn_rap_dataget(&stt_minj_data);
 #endif /* JEALLHV_E,JEEFI */
 #if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4) /*�y�ޭ��INJ�zOR�yD-4�z*/
        vdg_ertnfc_group00_dataget(&stt_minj_data);
 #endif /* JEEFI */
 #if JEEFI == u1g_EJCC_DUAL     /*�y�ޭ��INJ�z*/
        vdg_eclrdepi_emedi_dataget(&stt_minj_data);
  #if JEPRDEMAND == u1g_EJCC_NOT_USE    /*�y�ϔR�����䖳�z*/
        vdg_efpldlv_emedi_dataget(&stt_minj_data);
  #endif /* JEPRDEMAND */
 #endif /* JEEFI */
 #if JEEFI == u1g_EJCC_DUAL     /*�y�ޭ��INJ�z*/
        vdg_edthrctrl_emedi_dataget(&stt_minj_data);
 #endif /* JEEFI */
 #if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4) /*�y�ޭ��INJ�zOR�yD-4�z*/
  #if (JEPLMLT_E == u1g_EJCC_NOT_USE) && (EMINJ_ACTLFG_MEDI == ON)  /*�yPL������˖��zAND�y�߰�����Ċw�K�ׂ̱̈�è�ސ���v���g�p�z*/
        vdg_eactlfg_emedi_dataget(&stt_minj_data);
  #endif /* JEPLMLT_E,EMINJ_ACTLFG_MEDI */
 #endif /* JEEFI */
 #if JEEFI == u1g_EJCC_DUAL     /*�y�ޭ��INJ�z*/
  #if (JEOBDAFIMB_D == u1g_EJCC_USE) && (EMINJ_INJIMB_MEDI == ON)   /*�yAF�C���Բ����ݽ�L�zAND�y�����ݽ���̕��ː���v���g�p�z*/
        vdg_einjimb_emedi_dataget(&stt_minj_data);
  #endif /* JEOBDAFIMB_D,EMINJ_INJIMB_MEDI */
  #if JEFFV != u1g_EJCC_NOT_USE     /*�yFFV����L�z*/
        vdg_eactarefuel_emedi_dataget(&stt_minj_data);
  #endif /* JEFFV */
  #if EMINJ_ACTOBD_MEDI == ON    /* �yOBD�v���ɂ�鱸è�ސ���v���g�p�z */
        vdg_eactobd_emedi_dataget(&stt_minj_data);
  #endif /* EMINJ_ACTOBD_MEDI */
  #if (JEOBDAFIMB_D == u1g_EJCC_USE) && (EMINJ_IMBRQ_MEDI == ON)  /*�yAF�C���Բ����ݽ�L�zAND�y�����ݽOBD�v���ɂ�鱸è�ސ���v���g�p�z*/
        vdg_eimbrq_emedi_dataget(&stt_minj_data);
  #endif /* JEOBDAFIMB_D,EMINJ_IMBRQ_MEDI */
  #if (JEOBDMF == u1g_EJCC_USE) && (EMINJ_MFINJRQ_MEDI == ON)  /*�y����OBD�L�zAND�y����OBD�v���ɂ�鱸è�ސ���v���g�p�z*/
        vdg_emfinjrq_emedi_dataget(&stt_minj_data);
  #endif /* JEOBDMF,EMINJ_MFINJRQ_MEDI */
  #if (JEOBDFKG == u1g_EJCC_USE) && (EMINJ_FKGDRQ_MEDI == ON)  /* �y�R��OBD�L�zAND�y�R���nOBD�v���ɂ�鱸è�ސ���v���g�p�z */
        vdg_efkgdrq_emedi_dataget(&stt_minj_data);
  #endif /* JEOBDFKG,EMINJ_FKGDRQ_MEDI */
        vdg_eactgaf_emedi_dataget(&stt_minj_data);
 #endif /* JEEFI */
 #if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4) /*�y�ޭ��INJ�zOR�yD-4�z*/
        vdg_ekctrn_emedi_dataget(&stt_minj_data);
 #endif /* JEEFI */
 #if JEEFI == u1g_EJCC_DUAL     /*�y�ޭ��INJ�z*/
        vdg_erdvap_emedi_dataget(&stt_minj_data);
        vdg_edwnpr_emedi_dataget(&stt_minj_data);
 #endif /* JEEFI */
        vdg_epwrup_emedi_dataget(&stt_minj_data);
 #if JEEFI == u1g_EJCC_DUAL     /*�y�ޭ��INJ�z*/
        vdg_eprvdil_emedi_dataget(&stt_minj_data);
 #endif /* JEEFI */
 #if EMINJ_FREE0 == ON   /*�y�ذ�߰�0�g�p�z*/
        vdg_eminj_efree0_emedi_dataget(&stt_minj_data);
 #endif /* EMINJ_FREE0 */
 #if EMINJ_FREE1 == ON   /*�y�ذ�߰�1�g�p�z*/
        vdg_eminj_efree1_emedi_dataget(&stt_minj_data);
 #endif /* EMINJ_FREE1 */
#endif  /* JGXSTACK */
        u1t_pri = stt_minj_data.u1_pri;      /* �D��x�擾 */

#if (JEALLHV_E == u1g_EJCC_ALLHV_E) && (JEEFI == u1g_EJCC_PORT)     /*�yALL HV�zAND�y�߰āz*/
        u1t_rdpn_st_pri_c = u1g_eminj_RDPN_ST_PRI;
#endif /* JEALLHV_E,JEEFI */

        if ( ( u1t_pri != u1g_EMINJ_PRINORQ )       /* �ʏ핬�ː���v���L�̎� */
#if (JEALLHV_E == u1g_EJCC_ALLHV_E) && (JEEFI == u1g_EJCC_PORT)     /*�yALL HV�zAND�y�߰āz*/
          && ( u1t_pri != u1t_rdpn_st_pri_c )       /* �o�m�ጸ����(�n����)�v���łȂ� */
                                                    /* �o�m�ጸ����v����dataget�֐����n�����ƒʏ펞�ŋ��ʂ̂��߁A�n�����̗v���łȂ����Ƃ𔻒肷�� */
#endif /* JEALLHV_E,JEEFI */
           )
        {
            if ( ( u1t_prisel == u1g_EMINJ_PRINORQ )    /* ����X�V���� */
              || ( u1t_prisel > u1t_pri ) )             /* �D��I��(�D��x��MIN�Z���N�g) */
            {
                u1t_prisel = u1t_pri;   /* �D��x�X�V */

                if ( ( ( u1t_stprisel == u1g_EMINJ_PRINORQ )    /* �n�����v���i���\���́j�ɗD��x�v���Ȃ� */
                    || ( u1t_pri < u1t_stprisel ) )             /* �n�����v���i���\���́j��荂�D��x�v������ */
                  && ( ( u1t_astprisel == u1g_EMINJ_PRINORQ )   /* �n����v���i���\���́j�ɗD��x�v���Ȃ� */
                    || ( u1t_pri < u1t_astprisel ) )            /* �n����v���i���\���́j��荂�D��x�v������ */
                  && ( ( u1t_stprisel2 == u1g_EMINJ_PRINORQ )   /* �n�����v��2�i�V�\���́j�ɗD��x�v���Ȃ� */
                    || ( u1t_pri < u1t_stprisel2 ) )            /* �n�����v��2�i�V�\���́j��荂�D��x�v������ */
                  && ( ( u1t_astprisel2 == u1g_EMINJ_PRINORQ )  /* �n����v��2�i�V�\���́j�ɗD��x�v���Ȃ� */
                    || ( u1t_pri < u1t_astprisel2 ) ) )         /* �n����v��2�i�V�\���́j��荂�D��x�v������ */
                {
                    u1t_prisel_fix = u1t_pri;                                           /* �D��x�X�V */
                    u1t_prifix = u1t_pri;                                               /* �m��D��x�X�V */
                    u1t_idsel = sts_eminj_eminj_tbl[u1t_did].u1_id;                     /* ���ʎq�X�V */
                    u4t_rqdat[0] = stt_minj_data.u4_einjrq_dat;                         /* �v���L���ʎq�X�V */
#if JEEFI != u1g_EJCC_D4        /*�yD-4�ȊO�z*/
                    if ( ( (u4t_rqdat[0] & u4g_EMINJ_RQAINJP) != (u4)0U )               /* �|�[�g���ˊJ�n�����v���L�� */
                      && ( (u4t_rqdat[0] & u4g_EMINJ_RQAINJP1) == (u4)0U ) )            /* �|�[�g1��ڕ��ˊJ�n�����v������ */
                    {
                        stt_minj_data.s2_eainjp1 = stt_minj_data.s2_eainjp;             /* �|�[�g1��ڕ��ˊJ�n�����X�V */
                    }
                    if ( ( (u4t_rqdat[0] & u4g_EMINJ_RQQINJSTP) != (u4)0U )             /* �|�[�g�n�������˗ʗv���L�� */
                      && ( (u4t_rqdat[0] & u4g_EMINJ_RQQINJSTP1) == (u4)0U ) )          /* �|�[�g1��ڎn�������˗ʗv������ */
                    {
                        stt_minj_data.s4_eqinjstp1 = stt_minj_data.s4_eqinjstp;         /* �|�[�g1��ڎn�������˗ʍX�V */
                    }
#endif /* JEEFI */
                    vds_eminj_einj_datacopy( ptt_datsel, &stt_minj_data );
                    vds_eminj_einj_dataconv( ptt_datsel2, ptt_datsel ); /* �����܂ł̋��\���̏���V�\���̂ɈڐA */
                    u4t_rqdat[1] = ptt_datsel2->u4_einjrq_dat;          /* �v���L���ʎq�X�V */
                }
            }
        }
    }

    u1s_eminj_epri = u1t_prisel;

    /* �D��x�v�f�̒��� */
    /* �V�\���̗v����p */
    for ( u1t_did = (u1)0U; u1t_did < u1s_EMINJ_EMINJ_NUM2; u1t_did++ )
    {
        vds_eminj_einj_datacopy2( &stt_minj_data2, ptt_datdft2 );
        sts_eminj_eminj_tbl2[u1t_did].pt_dataget2( &stt_minj_data2 );
#ifdef JGXSTACK         /* �X�^�b�N�Z�o�p */
 #if (JEALLHV_E == u1g_EJCC_ALLHV_E) && (JEPLMLT_E == u1g_EJCC_USE) && (EMINJ_BINJPLCTR_WC_MEDI == ON) /*�yALL HV�zAND�yPL������˗L�zAND�y�߰�����ĕ��˂�p������{���ː���(�G�}�g�@��)�v���g�p�z*/
        vdg_ebinjplctr_wc_emedi_dataget(&stt_minj_data2);
 #endif /* JEALLHV_E,JEPLMLT_E,EMINJ_BINJPLCTR_WC_MEDI */
 #if (JEEGMG_E == u1g_EJCC_HVPLGR_E) && (JEFFV == u1g_EJCC_NOT_USE) && (JEPLMLT_E == u1g_EJCC_USE) && (EMINJ_BINJPLCTR_STAHV_MEDI == ON) /*�yEG-MG�V���ޱ�zAND�yFFV���䖳�zAND�yPL������˗L�zAND�y�߰�����ĕ��˂�p������{���ː���(HV�n�����䎞)�v���g�p�z*/
        vdg_ebinjplctr_stahv_emedi_dataget(&stt_minj_data2);
 #endif /* JEEGMG_E,JEFFV,JEPLMLT_E,EMINJ_BINJPLCTR_STAHV_MEDI */
 #if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
  #if (JEPLMLT_E == u1g_EJCC_USE) && (EMINJ_ACTLFG_MEDI == ON)  /*�yPL������˗L�zAND�y�߰�����Ċw�K�ׂ̱̈�è�ސ���v���g�p�z*/
        vdg_eactlfg_emedi_dataget2(&stt_minj_data2);
  #endif /* JEPLMLT_E,EMINJ_ACTLFG_MEDI */
 #endif /* JEEFI */
 #if JEPLMLT_E == u1g_EJCC_USE  /*�yPL������˗L�z*/
  #if EMINJ_BINJPLCTR_MEDI == ON   /*�y�߰�����ĕ��˂�p������{���ː���v���g�p�z*/
        vdg_ebinjplctr_emedi_dataget(&stt_minj_data2);
  #endif /* EMINJ_BINJPLCTR_MEDI */
 #endif /* JEPLMLT_E */
 #if EMINJ_FREE2 == ON   /*�y�ذ�߰�2�g�p�z*/
        vdg_eminj_efree2_emedi_dataget(&stt_minj_data2);
 #endif /* EMINJ_FREE2 */
 #if EMINJ_FREE3 == ON   /*�y�ذ�߰�3�g�p�z*/
        vdg_eminj_efree3_emedi_dataget(&stt_minj_data2);
 #endif /* EMINJ_FREE3 */
#endif  /* JGXSTACK */

        u1t_pri = stt_minj_data2.u1_pri;    /* �D��x�擾 */

        if ( u1t_pri != u1g_EMINJ_PRINORQ )                 /* �ʏ�v��2�̕��ː���v���L�̎� */
        {
            if ( ( u1t_prisel2 == u1g_EMINJ_PRINORQ )      /* ����X�V���� */
              || ( u1t_prisel2 > u1t_pri ) )               /* �D��I��(�D��x��MIN�Z���N�g) */
            {
                u1t_prisel2 = u1t_pri;  /* �D��x�X�V */

                if ( ( ( u1t_stprisel == u1g_EMINJ_PRINORQ )    /* �n�����v���i���\���́j�ɗD��x�v���Ȃ� */
                    || ( u1t_pri < u1t_stprisel ) )             /* �n�����v���i���\���́j��荂�D��x�v������ */
                  && ( ( u1t_astprisel == u1g_EMINJ_PRINORQ )   /* �n����v���i���\���́j�ɗD��x�v���Ȃ� */
                    || ( u1t_pri < u1t_astprisel ) )            /* �n����v���i���\���́j��荂�D��x�v������ */
                  && ( ( u1t_stprisel2 == u1g_EMINJ_PRINORQ )   /* �n�����v��2�i�V�\���́j�ɗD��x�v���Ȃ� */
                    || ( u1t_pri < u1t_stprisel2 ) )            /* �n�����v��2�i�V�\���́j��荂�D��x�v������ */
                  && ( ( u1t_astprisel2 == u1g_EMINJ_PRINORQ )  /* �n����v��2�i�V�\���́j�ɗD��x�v���Ȃ� */
                    || ( u1t_pri < u1t_astprisel2 ) )           /* �n����v��2�i�V�\���́j��荂�D��x�v������ */
                  && ( ( u1t_prisel == u1g_EMINJ_PRINORQ )      /* �ʏ�v���i���\���́j�ɗD��x�v���Ȃ� */
                    || ( u1t_pri < u1t_prisel ) ) )             /* �ʏ�v���i���\���́j��荂�D��x�v������ */ /* �ʏ�v���i���\���́j����D��x�v���̏ꍇ�͒��⏈�����Ȃ� */
                {
                    u1t_prisel_fix = u1t_pri;                                   /* �D��x�X�V */
                    u1t_prifix = u1t_pri;                                       /* �m��D��x�X�V */
                    u1t_idsel = sts_eminj_eminj_tbl2[u1t_did].u1_id;            /* ���ʎq�X�V */
                    u4t_rqdat[1] = stt_minj_data2.u4_einjrq_dat;                /* �v���L���ʎq�X�V */

                    vds_eminj_einj_datacopy2( ptt_datsel2, &stt_minj_data2 );
                    vds_eminj_einj_dataconv_rev( ptt_datsel, &stt_minj_data2 ); /* �����܂ł̐V�\���̏������\���̂ɈڐA */
                    u4t_rqdat[0] = ptt_datsel->u4_einjrq_dat;                   /* �v���L���ʎq�X�V */
                }
            }

        }
    }

    u1s_eminj_epri2 = u1t_prisel2;                  /* �ύX����eminj_eminjlmt_hpri()�����킹�Č��������� */

#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    if ( ( ( u1t_prisel == u1t_sjc_pri_c )
        && ( u1t_prisel_fix >= u1t_prisel ) )
      && ( ( u1t_stprisel > u1t_sjc_pri_c )
        || ( u1t_stprisel2 > u1t_sjc_pri_c ) ) )    /* �n�����e�[�u���܂��͎n�����e�[�u���Q�̗v�����ʏ�e�[�u���̐G�}�}���g�@�v�������D��ɂȂ����ꍇ */ /* temp:�d�l�m�F�̓��e���f(DENG-STD-25013�B) */
                                                    /* (estpri > eminj_SJC_PRI)�����������A(estpri �� EMINJ_PRINORQ)�͕K���������邽�ߏ�������ȗ�      */
                                                    /* (estpri2 > eminj_SJC_PRI)�����������A(estpri2 �� EMINJ_PRINORQ)�͕K���������邽�ߏ�������ȗ�    */
    {
        vds_eminj_einj_datacopy( ptt_datsel, &stt_minjst_data );    /* �G�}�}���g�@�v�����}�X�N */
        vds_eminj_einj_datacopy2( ptt_datsel2, &stt_minjst_data2 ); /* �G�}�}���g�@�v�����}�X�N */
        u1t_idsel = u1t_stidsel;
        u4t_rqdat[0] = ptt_datsel->u4_einjrq_dat;
        u1t_prisel_fix = u1t_stprisel_fix;
        u1t_prifix = u1t_stprisel_fix;
        u4t_rqdat[1] = ptt_datsel2->u4_einjrq_dat;
    }
#endif /* JEEFI */

    u1g_eminj_einjmedislid = u1t_idsel;
    u1s_eminj_eprisel_fix = u1t_prisel_fix;
    u1s_eminj_eprifix = u1t_prifix;
    u4s_eminj_erqdat[0] = u4t_rqdat[0];             /* �v�����˕����v���L���ʎq�i�[ */
    u4s_eminj_erqdat[1] = u4t_rqdat[1];             /* �v�����˕����v���L���ʎq�i�[ */

}

/*********************************************************************/
/*  �֐���        | vds_eminj_eminjlmt_hpri( )                       */
/*  �������e      | ���␧�񎞂̗D��x�I������                       */
/*  ����^�C�~���O| �����v����                                       */
/*  ����          | ptt_datsel:����f�[�^�i�[��̃A�h���X            */
/*                | ptt_datdft:����f�[�^�f�t�H���g�l�̃A�h���X      */
/*                | ptt_datsel2:�V����f�[�^�i�[��̃A�h���X         */
/*                | ptt_datdft2:�V����f�[�^�f�t�H���g�l�̃A�h���X   */
/*  �߂�l        | ����                                             */
/*  ���ӎ���      |                                                  */
/*********************************************************************/
static void
vds_eminj_eminjlmt_hpri( st_EMINJ_EMINJ_DEF *ptt_datsel, const st_EMINJ_EMINJ_DEF *ptt_datdft, st_EMINJ_EMINJ_BUF *ptt_datsel2, const st_EMINJ_EMINJ_BUF *ptt_datdft2 )
{
/* �W��e�[�u����` */
#pragma ghs startdata
    static volatile const st_EMINJ_EMINJ_TBL sts_eminj_eminjlmt_tbl[] = /* ���ӎ���:sts_eminj_eminjlmt_tbl[]�ύX���́A�ȉ��̕����������ύX�K�v */
                                                                        /*         :ID�ݒ�,�D��x�ݒ�,�v���w���p�f�[�^�ݒ�                     */
                                                                        /*         :����֐�eminj_eminjlmt_hpri()���̃X�^�b�N�Z�o����          */
                                                                        /*         :���̗D��I���e�[�u���ƕ�����Q�ƂƂȂ�v����ݒ肷��ꍇ�� */
                                                                        /*         :rap�֐����쐬���ݒ肷�邱��                                */
    {
#if (JEMAT_BENCHI == u1g_EJCC_USE) || (JEMAT_BENCH_E == u1g_EJCC_USE)   /*�y�����K���p��ėL�zOR�y�����K��Ӱ�ޗL�z*/
        { &vdg_ebench_emedi_dataget,        u1g_EMINJ_BENCH_ID    }, /* �D��x=2 :�����K���p���˗v�� */
#endif /* JEMAT_BENCHI,JEMAT_BENCH_E */
        { &vdg_eegstpvs_emedi_dataget,      u1g_EMINJ_EGSTPVS_ID  }, /* �D��x=4 :���˒�~ */
#if (JEEGMG_E == u1g_EJCC_HVPLGR_E) || (JEEGMG_E == u1g_EJCC_HVDIRECT_E)    /*�yEG-MG�V���ޱ�zOR�yEG-MG�����z*/
        { &vdg_estphv_emedi_dataget,        u1g_EMINJ_STPHV_ID    }, /* �D��x=12 :HV��~���� */
#endif /* JEEGMG_E */
        { &vdg_efcinjctr_emedi_dataget,     u1g_EMINJ_FCINJCTR_ID }, /* �D��x=50 :FC���R�����ː��� */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
 #if (JEPLMLT_E == u1g_EJCC_NOT_USE) && (EMINJ_ACTLFG_MEDI == ON)  /*�yPL������˖��zAND�y�߰�����Ċw�K�ׂ̱̈�è�ސ���v���g�p�z*/
        { &vdg_eactlfg_emedi_dataget,       u1g_EMINJ_ACTLFG_ID   }, /* �D��x=66 :�߰�����Ċw�K�ׂ̱̈�è�ސ��� */
 #endif /* JEPLMLT_E,EMINJ_ACTLFG_MEDI */
#endif /* JEEFI */
#if JEEFI == u1g_EJCC_DUAL      /*�y�ޭ��INJ�z*/
 #if (JEOBDAFIMB_D == u1g_EJCC_USE) && (EMINJ_INJIMB_MEDI == ON)    /*�yAF�C���Բ����ݽ�L�zAND�y�����ݽ���̕��ː���v���g�p�z*/
        { &vdg_einjimb_emedi_dataget,       u1s_EMINJ_INJIMB_ID   }, /* �D��x=72 :�����ݽ���̕��ː��� */
 #endif /* JEOBDAFIMB_D,EMINJ_INJIMB_MEDI */
 #if JEFFV != u1g_EJCC_NOT_USE  /*�yFFV����L�z*/
        { &vdg_eactarefuel_emedi_dataget,   u1s_EMINJ_ACTAREFUEL_ID }, /* �D��x=74 :������̕���������è�ސ��� */
 #endif /* JEFFV */
 #if EMINJ_ACTOBD_MEDI == ON    /* �yOBD�v���ɂ�鱸è�ސ���v���g�p�z */
        { &vdg_eactobd_emedi_dataget,       u1g_EMINJ_ACTOBD_ID   }, /* �D��x=76 :OBD�v���ɂ�鱸è�ސ��� */
 #endif /* EMINJ_ACTOBD_MEDI */
 #if (JEOBDAFIMB_D == u1g_EJCC_USE) && (EMINJ_IMBRQ_MEDI == ON)  /*�yAF�C���Բ����ݽ�L�zAND�y�����ݽOBD�v���ɂ�鱸è�ސ���v���g�p�z*/
        { &vdg_eimbrq_emedi_dataget,        u1g_EMINJ_IMBRQ_ID    }, /* �D��x=78 :�����ݽOBD�v���ɂ�鱸è�ސ��� */
 #endif /* JEOBDAFIMB_D,EMINJ_IMBRQ_MEDI */
 #if (JEOBDMF == u1g_EJCC_USE) && (EMINJ_MFINJRQ_MEDI == ON)  /*�y����OBD�L�zAND�y����OBD�v���ɂ�鱸è�ސ���v���g�p�z*/
        { &vdg_emfinjrq_emedi_dataget,      u1g_EMINJ_MFINJRQ_ID  }, /* �D��x=80 :����OBD�v���ɂ�鱸è�ސ��� */
 #endif /* JEOBDMF,EMINJ_MFINJRQ_MEDI */
 #if (JEOBDFKG == u1g_EJCC_USE) && (EMINJ_FKGDRQ_MEDI == ON)  /* �y�R��OBD�L�zAND�y�R���nOBD�v���ɂ�鱸è�ސ���v���g�p�z */
        { &vdg_efkgdrq_emedi_dataget,       u1g_EMINJ_FKGDRQ_ID   }, /* �D��x=82 :�R���nOBD�v���ɂ�鱸è�ސ��� */
 #endif /* JEOBDFKG,EMINJ_FKGDRQ_MEDI */
        { &vdg_eactgaf_emedi_dataget,       u1g_EMINJ_ACTGAF_ID   }, /* �D��x=84 :A/F�w�K�ׂ̱̈�è�ސ��� */
        { &vdg_erdvap_emedi_dataget,        u1s_EMINJ_RDVAP_ID    }, /* �D��x=88 :�ް�߰�}������ */
        { &vdg_edwnpr_emedi_dataget,        u1s_EMINJ_DWNPR_ID    }, /* �D��x=90 :�R���ጸ���� */
#endif /* JEEFI */
        { &vdg_epwrup_emedi_dataget,        u1s_EMINJ_PWRUP_ID    }  /* �D��x=92 :�o�͐��\���㐧�� */
#if EMINJ_FREE0 == ON   /*�y�ذ�߰�0�g�p�z*/
       ,{ &vdg_eminj_efree0_emedi_dataget,  u1g_EMINJ_FREE0_ID    }  /* �D��x=200 :�ذ�߰�0�p���˗v�� */
#endif /* EMINJ_FREE0 */
#if EMINJ_FREE1 == ON   /*�y�ذ�߰�1�g�p�z*/
       ,{ &vdg_eminj_efree1_emedi_dataget,  u1g_EMINJ_FREE1_ID    }  /* �D��x=201 :�ذ�߰�1�p���˗v�� */
#endif /* EMINJ_FREE1 */
    };

    static volatile const st_EMINJ_EMINJ_TBL2 sts_eminj_eminjlmt_tbl2[] = /* ���ӎ���:sts_eminj_eminjlmt_tbl2[]�ύX���́A�ȉ��̕����������ύX�K�v */
                                                                          /*         :ID�ݒ�,�D��x�ݒ�,�v���w���p�f�[�^�ݒ�                      */
                                                                          /*         :����֐�eminj_eminjlmt_hpri()���̃X�^�b�N�Z�o����           */
                                                                          /*         :���̗D��I���e�[�u���ƕ�����Q�ƂƂȂ�v����ݒ肷��ꍇ��  */
                                                                          /*         :rap�֐����쐬���ݒ肷�邱��                                 */
    {
#if (JEALLHV_E == u1g_EJCC_ALLHV_E) && (JEPLMLT_E == u1g_EJCC_USE) && (EMINJ_BINJPLCTR_WC_MEDI == ON) /*�yALL HV�zAND�yPL������˗L�zAND�y�߰�����ĕ��˂�p������{���ː���(�G�}�g�@��)�v���g�p�z*/
        { &vdg_ebinjplctr_wc_emedi_dataget,  u1g_EMINJ_BINJPLCTR_WC_ID   },    /* �D��x=22 :�߰�����ĕ��˂�p������{���ː���(�G�}�g�@��) */
#endif /* JEALLHV_E,JEPLMLT_E,EMINJ_BINJPLCTR_WC_MEDI */
#if (JEEGMG_E == u1g_EJCC_HVPLGR_E) && (JEFFV == u1g_EJCC_NOT_USE) && (JEPLMLT_E == u1g_EJCC_USE) && (EMINJ_BINJPLCTR_STAHV_MEDI == ON) /*�yEG-MG�V���ޱ�zAND�yFFV���䖳�zAND�yPL������˗L�zAND�y�߰�����ĕ��˂�p������{���ː���(HV�n�����䎞)�v���g�p�z*/
        { &vdg_ebinjplctr_stahv_emedi_dataget, u1g_EMINJ_BINJPLCTR_STAHV_ID },    /* �D��x=48 :�߰�����ĕ��˂�p������{���ː���(HV�n�����䎞) */
#endif /* JEEGMG_E,JEFFV,JEPLMLT_E,EMINJ_BINJPLCTR_STAHV_MEDI */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
 #if (JEPLMLT_E == u1g_EJCC_USE) && (EMINJ_ACTLFG_MEDI == ON)  /*�yPL������˗L�zAND�y�߰�����Ċw�K�ׂ̱̈�è�ސ���v���g�p�z*/
        { &vdg_eactlfg_emedi_dataget2,       u1g_EMINJ_ACTLFG_ID   },    /* �D��x=66 :�߰�����Ċw�K�ׂ̱̈�è�ސ��� */
 #endif /* JEPLMLT_E,EMINJ_ACTLFG_MEDI */
#endif /* JEEFI */
#if JEPLMLT_E == u1g_EJCC_USE  /*�yPL������˗L�z*/
 #if EMINJ_BINJPLCTR_MEDI == ON   /*�y�߰�����ĕ��˂�p������{���ː���v���g�p�z*/
        { &vdg_ebinjplctr_emedi_dataget,    u1g_EMINJ_BINJPLCTR_ID   },  /* �D��x=98 :�߰�����ĕ��˂�p������{���ː��� */
 #endif /* EMINJ_BINJPLCTR_MEDI */
#endif /* JEPLMLT_E */
#if EMINJ_FREE2 == ON   /*�y�ذ�߰�2�g�p�z*/
        { &vdg_eminj_efree2_emedi_dataget,  u1g_EMINJ_FREE2_ID    },     /* �D��x=202 :�ذ�߰�2�p���˗v�� */
#endif /* EMINJ_FREE2 */
#if EMINJ_FREE3 == ON   /*�y�ذ�߰�3�g�p�z*/
        { &vdg_eminj_efree3_emedi_dataget,  u1g_EMINJ_FREE3_ID    },     /* �D��x=203 :�ذ�߰�3�p���˗v�� */
#endif /* EMINJ_FREE3 */
/* ���������������������������������������������������������������������������������������� */
        /* �K���e�[�u���̏I�[�ɐݒ肷�邱�� */
        { &vds_eminj_dummy_emedi_dataget2,   u1g_EMINJ_NONE_ID }         /* �D��x=�Ȃ� :�_�~�[ */
/* ���������������������������������������������������������������������������������������� */
    };

#pragma ghs enddata

    u1 u1t_prisel;                              /* lsb=1 :�ō��D��x */
    u1 u1t_idsel;                               /* lsb=1 :�v�����˕����D��x�I�𔽉f���ʎq */
    u1 u1t_did;                                 /* lsb=1 :�W��e�[�u���C���f�b�N�X */
    u1 u1t_pri;                                 /* lsb=1 :�D��x */
    u4 u4t_rqdat[2];                            /* lsb=1 :�v���w���f�[�^ 0:���\���́A1:�V�\���̃��[�N */
    st_EMINJ_EMINJ_DEF stt_minj_data = { 0 };   /* �W��f�[�^���[�N(�ꊇ������) */
    u1 u1t_prisel2;                             /* lsb=1 :�ō��D��x */
    u1 u1t_prisel_fix;                          /* lsb=1 :�ō��D��x */
    u1 u1t_prifix;                              /* lsb=1 :�m��D��x */
    st_EMINJ_EMINJ_BUF stt_minj_data2 = { 0 };  /* �W��f�[�^���[�N(�ꊇ������) */

    u1t_prisel = u1g_EMINJ_PRINORQ;    /* �D��x������ */
    u1t_idsel = u1g_EMINJ_NONE_ID;     /* �v�����˕������f���ʎq������ */
    u4t_rqdat[0] = u4s_EMINJ_NORQDAT;  /* �v�����˕����v���L���ʎq������ */
    u1t_prisel2 = u1g_EMINJ_PRINORQ;   /* �D��x������ */

    /* eminjst_tbl,eminjst_tbl2,eminjast_tbl,eminjast_tbl2�ɒ��␧��L�̗v�����Ȃ����� */
    /* �n�����A�n����2�A�n����A�n����2�̒���Ɨv���l�̍X�V�������ȗ����� */
    u1s_eminj_estpri = u1g_EMINJ_PRINORQ;   /* �ύX����eminj_eminj_hpri()�����킹�Č��������� */ /* temp:�d�l�m�F�̓��e���f(DENG-STD-25017�A) */
    u1s_eminj_estpri2 = u1g_EMINJ_PRINORQ;  /* �ύX����eminj_eminj_hpri()�����킹�Č��������� */ /* temp:�d�l�m�F�̓��e���f(DENG-STD-25017�A) */
    u1s_eminj_eastpri = u1g_EMINJ_PRINORQ;  /* �ύX����eminj_eminj_hpri()�����킹�Č��������� */ /* temp:�d�l�m�F�̓��e���f(DENG-STD-25017�A) */
    u1s_eminj_eastpri2 = u1g_EMINJ_PRINORQ; /* �ύX����eminj_eminj_hpri()�����킹�Č��������� */ /* temp:�d�l�m�F�̓��e���f(DENG-STD-25017�A) */

    /* �D��x�v�f�̒��� */
    for ( u1t_did = (u1)0U; u1t_did < u1s_EMINJ_EMINJLMT_NUM; u1t_did++ )
    {
        vds_eminj_einj_datacopy( &stt_minj_data, ptt_datdft );
        sts_eminj_eminjlmt_tbl[u1t_did].pt_dataget( &stt_minj_data );
#ifdef JGXSTACK         /* �X�^�b�N�Z�o�p */
 #if (JEMAT_BENCHI == u1g_EJCC_USE) || (JEMAT_BENCH_E == u1g_EJCC_USE)   /*�y�����K���p��ėL�zOR�y�����K��Ӱ�ޗL�z*/
        vdg_ebench_emedi_dataget(&stt_minj_data);
 #endif /* JEMAT_BENCHI,JEMAT_BENCH_E */
        vdg_eegstpvs_emedi_dataget(&stt_minj_data);
 #if (JEEGMG_E == u1g_EJCC_HVPLGR_E) || (JEEGMG_E == u1g_EJCC_HVDIRECT_E)    /*�yEG-MG�V���ޱ�zOR�yEG-MG�����z*/
        vdg_estphv_emedi_dataget(&stt_minj_data);
 #endif /* JEEGMG_E */
        vdg_efcinjctr_emedi_dataget(&stt_minj_data);
 #if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4) /*�y�ޭ��INJ�zOR�yD-4�z*/
  #if (JEPLMLT_E == u1g_EJCC_NOT_USE) && (EMINJ_ACTLFG_MEDI == ON)   /*�yPL������˖��zAND�y�߰�����Ċw�K�ׂ̱̈�è�ސ���v���g�p�z*/
        vdg_eactlfg_emedi_dataget(&stt_minj_data);
  #endif /* JEPLMLT_E,EMINJ_ACTLFG_MEDI */
 #endif /* JEEFI */
 #if JEEFI == u1g_EJCC_DUAL     /*�y�ޭ��INJ�z*/
  #if (JEOBDAFIMB_D == u1g_EJCC_USE) && (EMINJ_INJIMB_MEDI == ON)    /*�yAF�C���Բ����ݽ�L�zAND�y�����ݽ���̕��ː���v���g�p�z*/
        vdg_einjimb_emedi_dataget(&stt_minj_data);
  #endif /* JEOBDAFIMB_D,EMINJ_INJIMB_MEDI */
  #if JEFFV != u1g_EJCC_NOT_USE     /*�yFFV����L�z*/
        vdg_eactarefuel_emedi_dataget(&stt_minj_data);
  #endif /* JEFFV */
  #if EMINJ_ACTOBD_MEDI == ON    /* �yOBD�v���ɂ�鱸è�ސ���v���g�p�z */
        vdg_eactobd_emedi_dataget(&stt_minj_data);
  #endif /* EMINJ_ACTOBD_MEDI */
  #if (JEOBDAFIMB_D == u1g_EJCC_USE) && (EMINJ_IMBRQ_MEDI == ON)  /*�yAF�C���Բ����ݽ�L�zAND�y�����ݽOBD�v���ɂ�鱸è�ސ���v���g�p�z*/
        vdg_eimbrq_emedi_dataget(&stt_minj_data);
  #endif /* JEOBDAFIMB_D,EMINJ_IMBRQ_MEDI */
  #if (JEOBDMF == u1g_EJCC_USE) && (EMINJ_MFINJRQ_MEDI == ON)  /*�y����OBD�L�zAND�y����OBD�v���ɂ�鱸è�ސ���v���g�p�z*/
        vdg_emfinjrq_emedi_dataget(&stt_minj_data);
  #endif /* JEOBDMF,EMINJ_MFINJRQ_MEDI */
  #if (JEOBDFKG == u1g_EJCC_USE) && (EMINJ_FKGDRQ_MEDI == ON)  /* �y�R��OBD�L�zAND�y�R���nOBD�v���ɂ�鱸è�ސ���v���g�p�z */
        vdg_efkgdrq_emedi_dataget(&stt_minj_data);
  #endif /* JEOBDFKG,EMINJ_FKGDRQ_MEDI */
        vdg_eactgaf_emedi_dataget(&stt_minj_data);
        vdg_erdvap_emedi_dataget(&stt_minj_data);
        vdg_edwnpr_emedi_dataget(&stt_minj_data);
 #endif /* JEEFI */
        vdg_epwrup_emedi_dataget(&stt_minj_data);
 #if EMINJ_FREE0 == ON   /*�y�ذ�߰�0�g�p�z*/
        vdg_eminj_efree0_emedi_dataget(&stt_minj_data);
 #endif /* EMINJ_FREE0 */
 #if EMINJ_FREE1 == ON   /*�y�ذ�߰�1�g�p�z*/
        vdg_eminj_efree1_emedi_dataget(&stt_minj_data);
 #endif /* EMINJ_FREE1 */
#endif  /* JGXSTACK */
        u1t_pri = stt_minj_data.u1_pri;      /* �D��x�擾 */

        if ( u1t_pri != u1g_EMINJ_PRINORQ )  /* ���⋖�� */
        {
            if ( ( u1t_idsel == u1g_EMINJ_NONE_ID )     /* ����X�V���� */
              || ( u1t_prisel > u1t_pri ) )             /* �D��I��(�D��x��MIN�Z���N�g) */
            {
                u1t_prisel = u1t_pri;                                                 /* �D��x�X�V */
                u1t_idsel = sts_eminj_eminjlmt_tbl[u1t_did].u1_id;                    /* ���ʎq�X�V */
                u4t_rqdat[0] = stt_minj_data.u4_einjrq_dat;                           /* �v���L���ʎq�X�V */
#if JEEFI != u1g_EJCC_D4        /*�yD-4�ȊO�z*/
                if ( ( (u4t_rqdat[0] & u4g_EMINJ_RQAINJP) != (u4)0U )                 /* �|�[�g���ˊJ�n�����v���L�� */
                  && ( (u4t_rqdat[0] & u4g_EMINJ_RQAINJP1) == (u4)0U ) )              /* �|�[�g1��ڕ��ˊJ�n�����v������ */
                {
                    stt_minj_data.s2_eainjp1 = stt_minj_data.s2_eainjp;               /* �|�[�g1��ڕ��ˊJ�n�����X�V */
                }
                if ( ( (u4t_rqdat[0] & u4g_EMINJ_RQQINJSTP) != (u4)0U )               /* �|�[�g�n�������˗ʗv���L�� */
                  && ( (u4t_rqdat[0] & u4g_EMINJ_RQQINJSTP1) == (u4)0U ) )            /* �|�[�g1��ڎn�������˗ʗv������ */
                {
                    stt_minj_data.s4_eqinjstp1 = stt_minj_data.s4_eqinjstp;           /* �|�[�g1��ڎn�������˗ʍX�V */
                }
#endif /* JEEFI */
                vds_eminj_einj_datacopy( ptt_datsel, &stt_minj_data );

            }
        }
    }

    u1s_eminj_epri = u1t_prisel;
    u1t_prisel_fix = u1t_prisel;
    u1t_prifix = u1t_prisel; /* �m��D��x�X�V */

    /* �D��x�v�f�̒��� */
    /* �V�\���̗v����p */
    vds_eminj_einj_dataconv( ptt_datsel2, ptt_datsel ); /* �����܂ł̋��\���̏����f�t�H���g�Ƃ��ĐV�\���̂ɈڐA */

    u4t_rqdat[1] = ptt_datsel2->u4_einjrq_dat;  /* ������ */

    for ( u1t_did = (u1)0U; u1t_did < u1s_EMINJ_EMINJLMT_NUM2; u1t_did++ )
    {
        vds_eminj_einj_datacopy2( &stt_minj_data2, ptt_datdft2 );
        sts_eminj_eminjlmt_tbl2[u1t_did].pt_dataget2( &stt_minj_data2 );
#ifdef JGXSTACK         /* �X�^�b�N�Z�o�p */
 #if (JEALLHV_E == u1g_EJCC_ALLHV_E) && (JEPLMLT_E == u1g_EJCC_USE) && (EMINJ_BINJPLCTR_WC_MEDI == ON) /*�yALL HV�zAND�yPL������˗L�zAND�y�߰�����ĕ��˂�p������{���ː���(�G�}�g�@��)�v���g�p�z*/
        vdg_ebinjplctr_wc_emedi_dataget(&stt_minj_data2);
 #endif /* JEALLHV_E,JEPLMLT_E,EMINJ_BINJPLCTR_WC_MEDI */
 #if (JEEGMG_E == u1g_EJCC_HVPLGR_E) && (JEFFV == u1g_EJCC_NOT_USE) && (JEPLMLT_E == u1g_EJCC_USE) && (EMINJ_BINJPLCTR_STAHV_MEDI == ON) /*�yEG-MG�V���ޱ�zAND�yFFV���䖳�zAND�yPL������˗L�zAND�y�߰�����ĕ��˂�p������{���ː���(HV�n�����䎞)�v���g�p�z*/
        vdg_ebinjplctr_stahv_emedi_dataget(&stt_minj_data2);
 #endif /* JEEGMG_E,JEFFV,JEPLMLT_E,EMINJ_BINJPLCTR_STAHV_MEDI */
 #if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
  #if (JEPLMLT_E == u1g_EJCC_USE) && (EMINJ_ACTLFG_MEDI == ON)  /*�yPL������˗L�zAND�y�߰�����Ċw�K�ׂ̱̈�è�ސ���v���g�p�z*/
        vdg_eactlfg_emedi_dataget2(&stt_minj_data2);
  #endif /* JEPLMLT_E,EMINJ_ACTLFG_MEDI */
 #endif /* JEEFI */
 #if JEPLMLT_E == u1g_EJCC_USE  /*�yPL������˗L�z*/
  #if EMINJ_BINJPLCTR_MEDI == ON   /*�y�߰�����ĕ��˂�p������{���ː���v���g�p�z*/
        vdg_ebinjplctr_emedi_dataget(&stt_minj_data2);
  #endif /* EMINJ_BINJPLCTR_MEDI */
 #endif /* JEPLMLT_E */
 #if EMINJ_FREE2 == ON   /*�y�ذ�߰�2�g�p�z*/
        vdg_eminj_efree2_emedi_dataget(&stt_minj_data2);
 #endif /* EMINJ_FREE2 */
 #if EMINJ_FREE3 == ON   /*�y�ذ�߰�3�g�p�z*/
        vdg_eminj_efree3_emedi_dataget(&stt_minj_data2);
 #endif /* EMINJ_FREE3 */
#endif  /* JGXSTACK */

        u1t_pri = stt_minj_data2.u1_pri;       /* �D��x�擾 */

        if ( u1t_pri != u1g_EMINJ_PRINORQ )    /* ���⋖�� */
        {
            if ( ( u1t_prisel2 == u1g_EMINJ_PRINORQ )    /* ����X�V���� */
              || ( u1t_prisel2 > u1t_pri ) )             /* �D��I��(�D��x��MIN�Z���N�g) */
            {
                u1t_prisel2 = u1t_pri;  /* �D��x�X�V */

                if ( ( u1t_prisel == u1g_EMINJ_PRINORQ )    /* �ʏ�v���i���\���́j�ɗD��x�v���Ȃ� */
                  || ( u1t_pri < u1t_prisel ) )             /* �ʏ�v���i���\���́j��荂�D��x�v������ */ /* �ʏ�v���i���\���́j����D��x�v���̏ꍇ�͒��⏈�����Ȃ� */
                {
                    u1t_prisel_fix = u1t_pri;                                   /* �D��x�X�V */
                    u1t_prifix = u1t_pri;                                       /* �m��D��x�X�V */
                    u1t_idsel = sts_eminj_eminjlmt_tbl2[u1t_did].u1_id;         /* ���ʎq�X�V */
                    u4t_rqdat[1] = stt_minj_data2.u4_einjrq_dat;                /* �v���L���ʎq�X�V */

                    vds_eminj_einj_datacopy2( ptt_datsel2, &stt_minj_data2 );
                    vds_eminj_einj_dataconv_rev( ptt_datsel, &stt_minj_data2 ); /* �����܂ł̐V�\���̏������\���̂ɈڐA */
                    u4t_rqdat[0] = ptt_datsel->u4_einjrq_dat;                   /* �v���L���ʎq�X�V */
                }
            }
        }
    }

    u1s_eminj_epri2 = u1t_prisel2;                  /* �ύX����eminj_eminjlmt_hpri()�����킹�Č��������� */

    u1g_eminj_einjmedislid = u1t_idsel;
    u1s_eminj_eprisel_fix = u1t_prisel_fix;
    u1s_eminj_eprifix= u1t_prifix;
    u4s_eminj_erqdat[0] = u4t_rqdat[0];             /* �v�����˕����v���L���ʎq�i�[ */
    u4s_eminj_erqdat[1] = u4t_rqdat[1];             /* �v�����˕����v���L���ʎq�i�[ */

}

/*********************************************************************/
/*  �֐���        | vds_eminj_einj_dataset( )                        */
/*  �������e      | �f�[�^�X�V����                                   */
/*  ����^�C�~���O| �����v����                                       */
/*  ����          | ptt_store     : �W��p�\���̂̃A�h���X           */
/*                | ptt_data      : �X�V�f�[�^�̃A�h���X             */
/*                | u1t_xnercdfew : lsb=1 :NE�^�X�N������t���O      */
/*  �߂�l        | �Ȃ�                                             */
/*  ���ӎ���      |                                                  */
/*********************************************************************/
static void
vds_eminj_einj_dataset( st_EMINJ_EINJ *ptt_store, const st_EMINJ_EINJ *ptt_data, u1 u1t_xnercdfew )
{
    u1 u1t_mox;    /* lsb=1 :���C���Z���T�� */
    u1 u1t_nox_c;  /* lsb=1 :���C���Z���T�� */
    u1 u1t_cyl;    /* lsb=1 :�C���� */
    u1 u1t_ncyl_c; /* lsb=1 :�C���� */

    u1t_ncyl_c = u1g_ejcc_NCYL;
    u1t_nox_c = u1g_ejcc_NOX;

    glint_di();       /* �������m�� �J�n */
    ptt_store->u2_einjmod   = ptt_data->u2_einjmod;
#if JEEFI != u1g_EJCC_D4        /*�yD-4�ȊO�z*/
    ptt_store->s2_eainjp1   = ptt_data->s2_eainjp1;
    ptt_store->f4_eainjp1   = ptt_data->f4_eainjp1;
    ptt_store->s2_eainjp2   = ptt_data->s2_eainjp2;
    ptt_store->f4_eainjp2   = ptt_data->f4_eainjp2;
    ptt_store->s2_eainjp3   = ptt_data->s2_eainjp3;
    ptt_store->f4_eainjp3   = ptt_data->f4_eainjp3;
    ptt_store->s2_eainjp4   = ptt_data->s2_eainjp4;
    ptt_store->f4_eainjp4   = ptt_data->f4_eainjp4;
    ptt_store->s2_einjend   = ptt_data->s2_einjend;
    ptt_store->f4_einjend   = ptt_data->f4_einjend;
    f4g_eminj_einjend = ptt_data->f4_einjend;
    ptt_store->s2_eainjcutp = ptt_data->s2_eainjcutp;
    ptt_store->f4_eainjcutp = ptt_data->f4_eainjcutp;
#endif /* JEEFI */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    ptt_store->s2_eainjd1   = ptt_data->s2_eainjd1;
    ptt_store->f4_eainjd1   = ptt_data->f4_eainjd1;
    ptt_store->s2_eainjd2   = ptt_data->s2_eainjd2;
    ptt_store->f4_eainjd2   = ptt_data->f4_eainjd2;
    ptt_store->s2_eainjd3   = ptt_data->s2_eainjd3;
    ptt_store->f4_eainjd3   = ptt_data->f4_eainjd3;
    ptt_store->s2_eainjd4   = ptt_data->s2_eainjd4;
    ptt_store->f4_eainjd4   = ptt_data->f4_eainjd4;
    ptt_store->s2_eainjcutd = ptt_data->s2_eainjcutd;
    ptt_store->f4_eainjcutd = ptt_data->f4_eainjcutd;
#endif /* JEEFI */
#if JEEFI == u1g_EJCC_PORT      /*�y�߰āz*/
    ptt_store->s2_eainjpadd = ptt_data->s2_eainjpadd;
#endif /* JEEFI */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    ptt_store->s2_eainjdadd = ptt_data->s2_eainjdadd;
#endif /* JEEFI */
    for ( u1t_cyl = (u1)0U; u1t_cyl < u1t_ncyl_c; u1t_cyl++ )
    {
        ptt_store->s4_eqfc[u1t_cyl] = ptt_data->s4_eqfc[u1t_cyl];
        ptt_store->f4_eqfc[u1t_cyl] = ptt_data->f4_eqfc[u1t_cyl];
        s4g_eminj_eqfc[u1t_cyl] = ptt_data->s4_eqfc[u1t_cyl];
        f4g_eminj_eqfc[u1t_cyl] = ptt_data->f4_eqfc[u1t_cyl];
    }
#if JECOMBCCPT_E == u1g_EJCC_SPRAYG_E                   /*�y���ڰ�޲�ށz*/
    ptt_store->s4_eqinjexp  = ptt_data->s4_eqinjexp;
    ptt_store->f4_eqinjexp  = ptt_data->f4_eqinjexp;
#endif /* JECOMBCCPT_E */
    ptt_store->s2_ek1f      = ptt_data->s2_ek1f;
    ptt_store->f4_ek1f      = ptt_data->f4_ek1f;
    ptt_store->s2_ek2f      = ptt_data->s2_ek2f;
    ptt_store->f4_ek2f      = ptt_data->f4_ek2f;
    ptt_store->s2_ek3f      = ptt_data->s2_ek3f;
    ptt_store->f4_ek3f      = ptt_data->f4_ek3f;
    for ( u1t_mox = (u1)0U; u1t_mox < u1t_nox_c; u1t_mox++ )
    {
        ptt_store->s2_ek1fn[u1t_mox] = ptt_data->s2_ek1fn[u1t_mox];
        ptt_store->f4_ek1fn[u1t_mox] = ptt_data->f4_ek1fn[u1t_mox];
        s2g_eminj_ek1fn[u1t_mox] = ptt_data->s2_ek1fn[u1t_mox];
        f4g_eminj_ek1fn[u1t_mox] = ptt_data->f4_ek1fn[u1t_mox];
        ptt_store->s2_ek2fn[u1t_mox] = ptt_data->s2_ek2fn[u1t_mox];
        ptt_store->f4_ek2fn[u1t_mox] = ptt_data->f4_ek2fn[u1t_mox];
        s2g_eminj_ek2fn[u1t_mox] = ptt_data->s2_ek2fn[u1t_mox];
        f4g_eminj_ek2fn[u1t_mox] = ptt_data->f4_ek2fn[u1t_mox];
        ptt_store->s2_ek3fn[u1t_mox] = ptt_data->s2_ek3fn[u1t_mox];
        ptt_store->f4_ek3fn[u1t_mox] = ptt_data->f4_ek3fn[u1t_mox];
        s2g_eminj_ek3fn[u1t_mox] = ptt_data->s2_ek3fn[u1t_mox];
        f4g_eminj_ek3fn[u1t_mox] = ptt_data->f4_ek3fn[u1t_mox];
        ptt_store->s2_ekrchref[u1t_mox] = ptt_data->s2_ekrchref[u1t_mox];
        ptt_store->f4_ekrchref[u1t_mox] = ptt_data->f4_ekrchref[u1t_mox];
        s2g_eminj_ekrchref[u1t_mox] = ptt_data->s2_ekrchref[u1t_mox];
        f4g_eminj_ekrchref[u1t_mox] = ptt_data->f4_ekrchref[u1t_mox];
    }
    glbitcp_bibi( ptt_data->bi_exqinjast, ptt_store->bi_exqinjast );
    ptt_store->u1_exqinjast = ptt_data->u1_exqinjast;
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    ptt_store->u1_explreq = ptt_data->u1_explreq;
#endif /* JEEFI */
#if JEEFI == u1g_EJCC_DUAL      /*�y�ޭ��INJ�z*/
    ptt_store->s2_ekpfit = ptt_data->s2_ekpfit;
    ptt_store->f4_ekpfit = ptt_data->f4_ekpfit;
    s2g_eminj_ekpfit = ptt_data->s2_ekpfit;
 #if JEEGR == u1g_EJCC_USE      /*�yEGR����L�z*/
    ptt_store->f4_ekpfiegr = ptt_data->f4_ekpfiegr;
 #endif /* JEEGR */
    for ( u1t_mox = (u1)0U; u1t_mox < u1t_nox_c; u1t_mox++ )
    {
        ptt_store->s2_ekpfitn[u1t_mox] = ptt_data->s2_ekpfitn[u1t_mox];
        ptt_store->f4_ekpfitn[u1t_mox] = ptt_data->f4_ekpfitn[u1t_mox];
        f4g_eminj_ekpfitn[u1t_mox] = ptt_data->f4_ekpfitn[u1t_mox];
        s2g_eminj_ekpfitn[u1t_mox] = ptt_data->s2_ekpfitn[u1t_mox];
 #if JEEGR == u1g_EJCC_USE      /*�yEGR����L�z*/
        ptt_store->f4_ekpfiegrn[u1t_mox] = ptt_data->f4_ekpfiegrn[u1t_mox];
        f4g_eminj_ekpfiegrn[u1t_mox] = ptt_data->f4_ekpfiegrn[u1t_mox];
 #endif /* JEEGR */
    }
#endif /* JEEFI */
#if JEEFI != u1g_EJCC_D4        /*�yD-4�ȊO�z*/
    ptt_store->s2_ek1fpt = ptt_data->s2_ek1fpt;
    ptt_store->f4_ek1fpt = ptt_data->f4_ek1fpt;
#endif /* JEEFI */
    if ( u1t_xnercdfew == (u1)ON )                      /* NE�����^�X�N�����Ȃ� */
    {
#if JEEFI != u1g_EJCC_D4        /*�yD-4�ȊO�z*/
        ptt_store->s4_eqinjstp1  = ptt_data->s4_eqinjstp1;
        ptt_store->f4_eqinjstp1  = ptt_data->f4_eqinjstp1;
        ptt_store->s4_eqinjstp2  = ptt_data->s4_eqinjstp2;
        ptt_store->f4_eqinjstp2  = ptt_data->f4_eqinjstp2;
        ptt_store->s4_eqinjstp3  = ptt_data->s4_eqinjstp3;
        ptt_store->f4_eqinjstp3  = ptt_data->f4_eqinjstp3;
        ptt_store->s4_eqinjstp4  = ptt_data->s4_eqinjstp4;
        ptt_store->f4_eqinjstp4  = ptt_data->f4_eqinjstp4;
#endif /* JEEFI */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
        ptt_store->s4_eqinjstd1 = ptt_data->s4_eqinjstd1;
        ptt_store->f4_eqinjstd1 = ptt_data->f4_eqinjstd1;
        f4g_eminj_eqinjstd1 = ptt_data->f4_eqinjstd1;
        ptt_store->s4_eqinjstd2 = ptt_data->s4_eqinjstd2;
        ptt_store->f4_eqinjstd2 = ptt_data->f4_eqinjstd2;
        f4g_eminj_eqinjstd2 = ptt_data->f4_eqinjstd2;
        ptt_store->s4_eqinjstd3 = ptt_data->s4_eqinjstd3;
        ptt_store->f4_eqinjstd3 = ptt_data->f4_eqinjstd3;
        f4g_eminj_eqinjstd3 = ptt_data->f4_eqinjstd3;
        ptt_store->s4_eqinjstd4 = ptt_data->s4_eqinjstd4;
        ptt_store->f4_eqinjstd4 = ptt_data->f4_eqinjstd4;
        f4g_eminj_eqinjstd4 = ptt_data->f4_eqinjstd4;
#endif /* JEEFI */
    }
    glint_ei();     /* �������m�� �I�� */
}

/*********************************************************************/
/*  �֐���        | vds_eminj_einj_datacopy( )                       */
/*  �������e      | �W��Ώۗp�\���̃f�[�^�R�s�[����                 */
/*  ����^�C�~���O| �����v����                                       */
/*  ����          | ptt_data : �X�V�f�[�^�̃A�h���X                  */
/*                | ptt_copy  : �R�s�[���f�[�^�̃A�h���X             */
/*  �߂�l        | �Ȃ�                                             */
/*  ���ӎ���      |                                                  */
/*********************************************************************/
static void
vds_eminj_einj_datacopy( st_EMINJ_EMINJ_DEF *ptt_data, const st_EMINJ_EMINJ_DEF *ptt_copy )
{
    u1 u1t_mox;    /* lsb=1 :���C���Z���T�� */
    u1 u1t_nox_c;  /* lsb=1 :���C���Z���T�� */
    u1 u1t_cyl;    /* lsb=1 :�C���� */
    u1 u1t_ncyl_c; /* lsb=1 :�C���� */

    u1t_ncyl_c = u1g_ejcc_NCYL;
    u1t_nox_c = u1g_ejcc_NOX;

    ptt_data->u1_pri        = ptt_copy->u1_pri;
    ptt_data->u4_einjrq_dat = ptt_copy->u4_einjrq_dat;
    ptt_data->u2_einjmod    = ptt_copy->u2_einjmod;
#if JEEFI != u1g_EJCC_D4        /*�yD-4�ȊO�z*/
    ptt_data->s2_eainjp1    = ptt_copy->s2_eainjp1;
    ptt_data->s2_eainjp2    = ptt_copy->s2_eainjp2;
    ptt_data->s2_eainjp3    = ptt_copy->s2_eainjp3;
    ptt_data->s2_eainjp4    = ptt_copy->s2_eainjp4;
    ptt_data->s2_einjend    = ptt_copy->s2_einjend;
    ptt_data->s2_eainjcutp  = ptt_copy->s2_eainjcutp;
#endif /* JEEFI */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    ptt_data->s2_eainjd1    = ptt_copy->s2_eainjd1;
    ptt_data->s2_eainjd2    = ptt_copy->s2_eainjd2;
    ptt_data->s2_eainjd3    = ptt_copy->s2_eainjd3;
    ptt_data->s2_eainjd4    = ptt_copy->s2_eainjd4;
    ptt_data->s2_eainjcutd  = ptt_copy->s2_eainjcutd;
#endif /* JEEFI */
#if JEEFI != u1g_EJCC_D4        /*�yD-4�ȊO�z*/
    ptt_data->s4_eqinjstp1  = ptt_copy->s4_eqinjstp1;
    ptt_data->s4_eqinjstp2  = ptt_copy->s4_eqinjstp2;
    ptt_data->s4_eqinjstp3  = ptt_copy->s4_eqinjstp3;
    ptt_data->s4_eqinjstp4  = ptt_copy->s4_eqinjstp4;
#endif /* JEEFI */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    ptt_data->s4_eqinjstd1  = ptt_copy->s4_eqinjstd1;
    ptt_data->s4_eqinjstd2  = ptt_copy->s4_eqinjstd2;
    ptt_data->s4_eqinjstd3  = ptt_copy->s4_eqinjstd3;
    ptt_data->s4_eqinjstd4  = ptt_copy->s4_eqinjstd4;
#endif /* JEEFI */
    for ( u1t_cyl = (u1)0U; u1t_cyl < u1t_ncyl_c; u1t_cyl++ )
    {
        ptt_data->s4_eqfc[u1t_cyl] = ptt_copy->s4_eqfc[u1t_cyl];
    }
#if JECOMBCCPT_E == u1g_EJCC_SPRAYG_E /*�y���ڰ�޲�ށz*/
    ptt_data->s4_eqinjexp   = ptt_copy->s4_eqinjexp;
#endif /* JECOMBCCPT_E */
    ptt_data->s2_ek1f       = ptt_copy->s2_ek1f;
    ptt_data->s2_ek2f       = ptt_copy->s2_ek2f;
    ptt_data->s2_ek3f       = ptt_copy->s2_ek3f;
    for ( u1t_mox = (u1)0U; u1t_mox < u1t_nox_c; u1t_mox++ )
    {
        ptt_data->s2_ek1fn[u1t_mox] = ptt_copy->s2_ek1fn[u1t_mox];
        ptt_data->s2_ek2fn[u1t_mox] = ptt_copy->s2_ek2fn[u1t_mox];
        ptt_data->s2_ek3fn[u1t_mox] = ptt_copy->s2_ek3fn[u1t_mox];
        ptt_data->s2_ekrchref[u1t_mox]   = ptt_copy->s2_ekrchref[u1t_mox];
    }
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    ptt_data->s2_eprreq     = ptt_copy->s2_eprreq;
#endif /* JEEFI */
#if JEPRDEMAND == u1g_EJCC_NOT_USE                      /*�y�ϔR�����䖳�z*/
    ptt_data->s2_eqfreq     = ptt_copy->s2_eqfreq;
#else                           /*�y�ϔR������L�z*/
    ptt_data->s2_eprreql    = ptt_copy->s2_eprreql;
#endif /* JEPRDEMAND */
    glbitcp_bibi( ptt_copy->bi_exqinjast, ptt_data->bi_exqinjast );
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    ptt_data->u1_explreq    = ptt_copy->u1_explreq;
#endif /* JEEFI */
}

/*********************************************************************/
/*  �֐���        | vds_eminj_eminj_dataset( )                       */
/*  �������e      | �f�[�^�X�V����                                   */
/*  ����^�C�~���O| �����v����                                       */
/*  ����          | ptt_store     : �W��p�\���̂̃A�h���X           */
/*                | ptt_data      : �X�V�f�[�^�̃A�h���X             */
/*                | u1t_xnercdfew : lsb=1 :NE�^�X�N������t���O      */
/*  �߂�l        | �Ȃ�                                             */
/*  ���ӎ���      | �V�\���̗p                                       */
/*********************************************************************/
static void
vds_eminj_eminj_dataset( st_EMINJ_EMINJ *ptt_store, const st_EMINJ_EMINJ *ptt_data, u1 u1t_xnercdfew )
{
    u1 u1t_mox;    /* lsb=1 :���C���Z���T�� */
    u1 u1t_nox_c;  /* lsb=1 :���C���Z���T�� */
    u1 u1t_cyl;    /* lsb=1 :�C���� */
    u1 u1t_ncyl_c; /* lsb=1 :�C���� */
    u1 u1t_injnum; /* lsb=1 :���ˉ� */

    u1t_ncyl_c = u1g_ejcc_NCYL;
    u1t_nox_c = u1g_ejcc_NOX;

    glint_di();       /* �������m�� �J�n */
    ptt_store->u2_einjmod   = ptt_data->u2_einjmod;
    ptt_store->u4_einjptn   = ptt_data->u4_einjptn;
#if JEEFI != u1g_EJCC_D4        /*�yD-4�ȊO�z*/
    for ( u1t_injnum = (u1)0U; u1t_injnum < (u1)4U; u1t_injnum++ )
    {
        ptt_store->s2_eainjpn[u1t_injnum]   = ptt_data->s2_eainjpn[u1t_injnum];
        ptt_store->f4_eainjpn[u1t_injnum]   = ptt_data->f4_eainjpn[u1t_injnum];
        s2g_eminj_eainjpn[u1t_injnum] = ptt_data->s2_eainjpn[u1t_injnum];
        f4g_eminj_eainjpn[u1t_injnum] = ptt_data->f4_eainjpn[u1t_injnum];
    }
    ptt_store->s2_einjend   = ptt_data->s2_einjend;
    ptt_store->f4_einjend   = ptt_data->f4_einjend;
    ptt_store->s2_eainjcutp = ptt_data->s2_eainjcutp;
    ptt_store->f4_eainjcutp = ptt_data->f4_eainjcutp;
#endif /* JEEFI */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    for ( u1t_injnum = (u1)0U; u1t_injnum < (u1)6U; u1t_injnum++ )
    {
        ptt_store->s2_eainjdn[u1t_injnum]   = ptt_data->s2_eainjdn[u1t_injnum];
        ptt_store->f4_eainjdn[u1t_injnum]   = ptt_data->f4_eainjdn[u1t_injnum];
        s2g_eminj_eainjdn[u1t_injnum] = ptt_data->s2_eainjdn[u1t_injnum];
        f4g_eminj_eainjdn[u1t_injnum] = ptt_data->f4_eainjdn[u1t_injnum];
    }
    ptt_store->s2_eainjcutd = ptt_data->s2_eainjcutd;
    ptt_store->f4_eainjcutd = ptt_data->f4_eainjcutd;
#endif /* JEEFI */
#if JEEFI == u1g_EJCC_PORT      /*�y�߰āz*/
    ptt_store->s2_eainjpadd = ptt_data->s2_eainjpadd;
#endif /* JEEFI */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    ptt_store->s2_eainjdadd = ptt_data->s2_eainjdadd;
#endif /* JEEFI */
    for ( u1t_cyl = (u1)0U; u1t_cyl < u1t_ncyl_c; u1t_cyl++ )
    {
        ptt_store->s4_eqfc[u1t_cyl] = ptt_data->s4_eqfc[u1t_cyl];
        ptt_store->f4_eqfc[u1t_cyl] = ptt_data->f4_eqfc[u1t_cyl];
    }
#if JECOMBCCPT_E == u1g_EJCC_SPRAYG_E                   /*�y���ڰ�޲�ށz*/
    ptt_store->s4_eqinjexp  = ptt_data->s4_eqinjexp;
    ptt_store->f4_eqinjexp  = ptt_data->f4_eqinjexp;
#endif /* JECOMBCCPT_E */

    for ( u1t_mox = (u1)0U; u1t_mox < u1t_nox_c; u1t_mox++ )
    {
        ptt_store->s2_ek1fn[u1t_mox] = ptt_data->s2_ek1fn[u1t_mox];
        ptt_store->f4_ek1fn[u1t_mox] = ptt_data->f4_ek1fn[u1t_mox];
        ptt_store->s2_ek2fn[u1t_mox] = ptt_data->s2_ek2fn[u1t_mox];
        ptt_store->f4_ek2fn[u1t_mox] = ptt_data->f4_ek2fn[u1t_mox];
        ptt_store->s2_ek3fn[u1t_mox] = ptt_data->s2_ek3fn[u1t_mox];
        ptt_store->f4_ek3fn[u1t_mox] = ptt_data->f4_ek3fn[u1t_mox];
        ptt_store->s2_ekrchref[u1t_mox] = ptt_data->s2_ekrchref[u1t_mox];
        ptt_store->f4_ekrchref[u1t_mox] = ptt_data->f4_ekrchref[u1t_mox];
    }
    glbitcp_bibi( ptt_data->bi_exqinjast, ptt_store->bi_exqinjast );
    ptt_store->u1_exqinjast = ptt_data->u1_exqinjast;
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    ptt_store->u1_explreq = ptt_data->u1_explreq;
#endif /* JEEFI */
#if JEEFI == u1g_EJCC_DUAL      /*�y�ޭ��INJ�z*/
    ptt_store->s2_ekpfit = ptt_data->s2_ekpfit;
    ptt_store->f4_ekpfit = ptt_data->f4_ekpfit;
 #if JEEGR == u1g_EJCC_USE      /*�yEGR����L�z*/
    ptt_store->f4_ekpfiegr = ptt_data->f4_ekpfiegr;
 #endif /* JEEGR */
    for ( u1t_mox = (u1)0U; u1t_mox < u1t_nox_c; u1t_mox++ )
    {
        ptt_store->s2_ekpfitn[u1t_mox] = ptt_data->s2_ekpfitn[u1t_mox];
        ptt_store->f4_ekpfitn[u1t_mox] = ptt_data->f4_ekpfitn[u1t_mox];
 #if JEEGR == u1g_EJCC_USE      /*�yEGR����L�z*/
        ptt_store->f4_ekpfiegrn[u1t_mox] = ptt_data->f4_ekpfiegrn[u1t_mox];
 #endif /* JEEGR */
    }
#endif /* JEEFI */
#if JEEFI != u1g_EJCC_D4        /*�yD-4�ȊO�z*/
    ptt_store->s2_ek1fpt = ptt_data->s2_ek1fpt;
    ptt_store->f4_ek1fpt = ptt_data->f4_ek1fpt;
#endif /* JEEFI */
    for ( u1t_injnum = (u1)0U; u1t_injnum < (u1)8U; u1t_injnum++ )
    {
        ptt_store->s4_eqinjflfix[u1t_injnum] = ptt_data->s4_eqinjflfix[u1t_injnum];
        ptt_store->f4_eqinjflfix[u1t_injnum] = ptt_data->f4_eqinjflfix[u1t_injnum];
        s4g_eminj_eqinjflfix[u1t_injnum] = ptt_data->s4_eqinjflfix[u1t_injnum];
        f4g_eminj_eqinjflfix[u1t_injnum] = ptt_data->f4_eqinjflfix[u1t_injnum];
        ptt_store->s4_eqinjplfix[u1t_injnum] = ptt_data->s4_eqinjplfix[u1t_injnum];
        ptt_store->f4_eqinjplfix[u1t_injnum] = ptt_data->f4_eqinjplfix[u1t_injnum];
        s4g_eminj_eqinjplfix[u1t_injnum] = ptt_data->s4_eqinjplfix[u1t_injnum];
        f4g_eminj_eqinjplfix[u1t_injnum] = ptt_data->f4_eqinjplfix[u1t_injnum];
    }

    if ( u1t_xnercdfew == (u1)ON )                      /* NE�����^�X�N�����Ȃ� */
    {
#if JEEFI != u1g_EJCC_D4        /*�yD-4�ȊO�z*/
        for ( u1t_injnum = (u1)0U; u1t_injnum < (u1)4U; u1t_injnum++ )
        {
            ptt_store->s4_eqinjstpn[u1t_injnum]  = ptt_data->s4_eqinjstpn[u1t_injnum];
            ptt_store->f4_eqinjstpn[u1t_injnum]  = ptt_data->f4_eqinjstpn[u1t_injnum];
            s4g_eminj_eqinjstpn[u1t_injnum] = ptt_data->s4_eqinjstpn[u1t_injnum];
            f4g_eminj_eqinjstpn[u1t_injnum] = ptt_data->f4_eqinjstpn[u1t_injnum];
        }
#endif /* JEEFI */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
        for ( u1t_injnum = (u1)0U; u1t_injnum < (u1)6U; u1t_injnum++ )
        {
            ptt_store->s4_eqinjstdn[u1t_injnum] = ptt_data->s4_eqinjstdn[u1t_injnum];
            ptt_store->f4_eqinjstdn[u1t_injnum] = ptt_data->f4_eqinjstdn[u1t_injnum];
            s4g_eminj_eqinjstdn[u1t_injnum] = ptt_data->s4_eqinjstdn[u1t_injnum];
            f4g_eminj_eqinjstdn[u1t_injnum] = ptt_data->f4_eqinjstdn[u1t_injnum];
        }
#endif /* JEEFI */
    }
    glint_ei();     /* �������m�� �I�� */
}

/*********************************************************************/
/*  �֐���        | vds_eminj_einj_datacopy2( )                      */
/*  �������e      | �W��Ώۗp�V�\���̃f�[�^�R�s�[����               */
/*  ����^�C�~���O| �����v����                                       */
/*  ����          | ptt_data : �X�V�f�[�^�̃A�h���X                  */
/*                | ptt_copy  : �R�s�[���f�[�^�̃A�h���X             */
/*  �߂�l        | �Ȃ�                                             */
/*  ���ӎ���      |                                                  */
/*********************************************************************/
static void
vds_eminj_einj_datacopy2( st_EMINJ_EMINJ_BUF *ptt_data, const st_EMINJ_EMINJ_BUF *ptt_copy )
{
    u1 u1t_mox;    /* lsb=1 :���C���Z���T�� */
    u1 u1t_nox_c;  /* lsb=1 :���C���Z���T�� */
    u1 u1t_cyl;    /* lsb=1 :�C���� */
    u1 u1t_ncyl_c; /* lsb=1 :�C���� */
    u1 u1t_injnum; /* lsb=1 :���ˉ� */

    u1t_ncyl_c = u1g_ejcc_NCYL;
    u1t_nox_c = u1g_ejcc_NOX;

    ptt_data->u1_pri        = ptt_copy->u1_pri;
    ptt_data->u4_einjrq_dat = ptt_copy->u4_einjrq_dat;
    ptt_data->u2_einjmod    = ptt_copy->u2_einjmod;
    ptt_data->u4_einjptn    = ptt_copy->u4_einjptn;
#if JEEFI != u1g_EJCC_D4        /*�yD-4�ȊO�z*/
    for ( u1t_injnum = (u1)0U; u1t_injnum < (u1)4U; u1t_injnum++ )
    {
        ptt_data->s2_eainjpn[u1t_injnum] = ptt_copy->s2_eainjpn[u1t_injnum];
    }
    ptt_data->s2_einjend    = ptt_copy->s2_einjend;
    ptt_data->s2_eainjcutp  = ptt_copy->s2_eainjcutp;
#endif /* JEEFI */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    for ( u1t_injnum = (u1)0U; u1t_injnum < (u1)6U; u1t_injnum++ )
    {
        ptt_data->s2_eainjdn[u1t_injnum] = ptt_copy->s2_eainjdn[u1t_injnum];
    }
    ptt_data->s2_eainjcutd  = ptt_copy->s2_eainjcutd;
#endif /* JEEFI */
    if ( u1s_eminj_exnercdfew == (u1)ON )               /* NE�����^�X�N�����Ȃ� */
    {
#if JEEFI != u1g_EJCC_D4        /*�yD-4�ȊO�z*/
        for ( u1t_injnum = (u1)0U; u1t_injnum < (u1)4U; u1t_injnum++ )
        {
            ptt_data->s4_eqinjstpn[u1t_injnum] = ptt_copy->s4_eqinjstpn[u1t_injnum];
        }
#endif /* JEEFI */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
        for ( u1t_injnum = (u1)0U; u1t_injnum < (u1)6U; u1t_injnum++ )
        {
            ptt_data->s4_eqinjstdn[u1t_injnum] = ptt_copy->s4_eqinjstdn[u1t_injnum];
        }
#endif /* JEEFI */
    }
    for ( u1t_cyl = (u1)0U; u1t_cyl < u1t_ncyl_c; u1t_cyl++ )
    {
        ptt_data->s4_eqfc[u1t_cyl] = ptt_copy->s4_eqfc[u1t_cyl];
    }
#if JECOMBCCPT_E == u1g_EJCC_SPRAYG_E /*�y���ڰ�޲�ށz*/
    ptt_data->s4_eqinjexp   = ptt_copy->s4_eqinjexp;
#endif /* JECOMBCCPT_E */
    for ( u1t_mox = (u1)0U; u1t_mox < u1t_nox_c; u1t_mox++ )
    {
        ptt_data->s2_ek1fn[u1t_mox] = ptt_copy->s2_ek1fn[u1t_mox];
        ptt_data->s2_ek2fn[u1t_mox] = ptt_copy->s2_ek2fn[u1t_mox];
        ptt_data->s2_ek3fn[u1t_mox] = ptt_copy->s2_ek3fn[u1t_mox];
        ptt_data->s2_ekrchref[u1t_mox]   = ptt_copy->s2_ekrchref[u1t_mox];
    }
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    ptt_data->s2_eprreq     = ptt_copy->s2_eprreq;
#endif /* JEEFI */
#if JEPRDEMAND == u1g_EJCC_NOT_USE                      /*�y�ϔR�����䖳�z*/
    ptt_data->s2_eqfreq     = ptt_copy->s2_eqfreq;
#else                           /*�y�ϔR������L�z*/
    ptt_data->s2_eprreql    = ptt_copy->s2_eprreql;
#endif /* JEPRDEMAND */
    glbitcp_bibi( ptt_copy->bi_exqinjast, ptt_data->bi_exqinjast );
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    ptt_data->u1_explreq    = ptt_copy->u1_explreq;
#endif /* JEEFI */
    for ( u1t_injnum = (u1)0U; u1t_injnum < (u1)8U; u1t_injnum++ )
    {
        ptt_data->s4_eqinjflfix[u1t_injnum]  = ptt_copy->s4_eqinjflfix[u1t_injnum];
        ptt_data->s4_eqinjplfix[u1t_injnum]  = ptt_copy->s4_eqinjplfix[u1t_injnum];
    }

}

/*********************************************************************/
/*  �֐���        | vds_eminj_einj_dataconv( )                       */
/*  �������e      | �W��Ώۗp�����V�\���̃f�[�^�ڍs����             */
/*  ����^�C�~���O| �����v����                                       */
/*  ����          | ptt_data_new  : �V�\���̃f�[�^�̃A�h���X         */
/*                | ptt_data_old  : ���\���̃f�[�^�̃A�h���X         */
/*  �߂�l        | �Ȃ�                                             */
/*  ���ӎ���      |                                                  */
/*********************************************************************/
static void
vds_eminj_einj_dataconv( st_EMINJ_EMINJ_BUF *ptt_data_new, const st_EMINJ_EMINJ_DEF *ptt_data_old )
{
    u1 u1t_mox;    /* lsb=1 :���C���Z���T�� */
    u1 u1t_nox_c;  /* lsb=1 :���C���Z���T�� */
    u1 u1t_cyl;    /* lsb=1 :�C���� */
    u1 u1t_ncyl_c; /* lsb=1 :�C���� */
    u4 u4t_rqdat;  /* lsb=1 :�v���w���f�[�^ */

    u1t_ncyl_c = u1g_ejcc_NCYL;
    u1t_nox_c = u1g_ejcc_NOX;

    ptt_data_new->u1_pri        = ptt_data_old->u1_pri;

    u4t_rqdat = u4s_EMINJ_NORQDAT;
    if ( ( ptt_data_old->u4_einjrq_dat & u4g_EMINJ_RQINJMODE ) != (u4)0U )      /* ����Ӱ�ޗv���L */
    {
        u4t_rqdat = ( u4t_rqdat | u4g_EMINJ_RQINJMODE );
    }
#if JEEFI != u1g_EJCC_D4        /*�yD-4�ȊO�z*/
    if ( ( ( ptt_data_old->u4_einjrq_dat & u4g_EMINJ_RQAINJP )  != (u4)0U )     /* �߰ĕ��ˊJ�n�����v���L */
      || ( ( ptt_data_old->u4_einjrq_dat & u4g_EMINJ_RQAINJP1 ) != (u4)0U )     /* �߰�1��ڕ��ˊJ�n�����v���L */
      || ( ( ptt_data_old->u4_einjrq_dat & u4g_EMINJ_RQAINJP2 ) != (u4)0U )     /* �߰�2��ڕ��ˊJ�n�����v���L */
      || ( ( ptt_data_old->u4_einjrq_dat & u4g_EMINJ_RQAINJP3 ) != (u4)0U )     /* �߰�3��ڕ��ˊJ�n�����v���L */
      || ( ( ptt_data_old->u4_einjrq_dat & u4g_EMINJ_RQAINJP4 ) != (u4)0U ) )   /* �߰�4��ڕ��ˊJ�n�����v���L */
    {
        u4t_rqdat = ( u4t_rqdat | u4g_EMINJ_RQAINJPN );
    }
    if ( ( ptt_data_old->u4_einjrq_dat & u4g_EMINJ_RQINJEND ) != (u4)0U )       /* �߰ĕ��ˏI�������v���L */
    {
        u4t_rqdat = ( u4t_rqdat | u4g_EMINJ_RQINJEND );
    }
    if ( ( ptt_data_old->u4_einjrq_dat & u4g_EMINJ_RQAINJCUTP ) != (u4)0U )     /* �߰ĕ��ˋ�����Ď����v���L */
    {
        u4t_rqdat = ( u4t_rqdat | u4g_EMINJ_RQAINJCUTP );
    }
#endif /* JEEFI */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    if ( ( ptt_data_old->u4_einjrq_dat & u4g_EMINJ_RQAINJCUTD ) != (u4)0U )     /* �������ˋ�����Ď����v���L */
    {
        u4t_rqdat = ( u4t_rqdat | u4g_EMINJ_RQAINJCUTD );
    }
    if ( ( ( ptt_data_old->u4_einjrq_dat & u4g_EMINJ_RQAINJD1 ) != (u4)0U )     /* ����1��ڕ��ˊJ�n�����v���L */
      || ( ( ptt_data_old->u4_einjrq_dat & u4g_EMINJ_RQAINJD2 ) != (u4)0U )     /* ����2��ڕ��ˊJ�n�����v���L */
      || ( ( ptt_data_old->u4_einjrq_dat & u4g_EMINJ_RQAINJD3 ) != (u4)0U )     /* ����3��ڕ��ˊJ�n�����v���L */
      || ( ( ptt_data_old->u4_einjrq_dat & u4g_EMINJ_RQAINJD4 ) != (u4)0U ) )   /* ����4��ڕ��ˊJ�n�����v���L */
    {
        u4t_rqdat = ( u4t_rqdat | u4g_EMINJ_RQAINJDN );
    }
#endif /* JEEFI */
#if JEEFI != u1g_EJCC_D4        /*�yD-4�ȊO�z*/
    if ( ( ( ptt_data_old->u4_einjrq_dat & u4g_EMINJ_RQQINJSTP )  != (u4)0U )   /* �߰Ďn�������˗ʗv���L */
      || ( ( ptt_data_old->u4_einjrq_dat & u4g_EMINJ_RQQINJSTP1 ) != (u4)0U )   /* �߰�1��ڎn�������˗ʗv���L */
      || ( ( ptt_data_old->u4_einjrq_dat & u4g_EMINJ_RQQINJSTP2 ) != (u4)0U )   /* �߰�2��ڎn�������˗ʗv���L */
      || ( ( ptt_data_old->u4_einjrq_dat & u4g_EMINJ_RQQINJSTP3 ) != (u4)0U )   /* �߰�3��ڎn�������˗ʗv���L */
      || ( ( ptt_data_old->u4_einjrq_dat & u4g_EMINJ_RQQINJSTP4 ) != (u4)0U ) ) /* �߰�4��ڎn�������˗ʗv���L */
    {
        u4t_rqdat = ( u4t_rqdat | u4g_EMINJ_RQQINJSTPN );
    }
#endif /* JEEFI */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    if ( ( ( ptt_data_old->u4_einjrq_dat & u4g_EMINJ_RQQINJSTD1 ) != (u4)0U )   /* ����1��ڎn�������˗ʗv���L */
      || ( ( ptt_data_old->u4_einjrq_dat & u4g_EMINJ_RQQINJSTD2 ) != (u4)0U )   /* ����2��ڎn�������˗ʗv���L */
      || ( ( ptt_data_old->u4_einjrq_dat & u4g_EMINJ_RQQINJSTD3 ) != (u4)0U )   /* ����3��ڎn�������˗ʗv���L */
      || ( ( ptt_data_old->u4_einjrq_dat & u4g_EMINJ_RQQINJSTD4 ) != (u4)0U ) ) /* ����4��ڎn�������˗ʗv���L */
    {
        u4t_rqdat = ( u4t_rqdat | u4g_EMINJ_RQQINJSTDN );
    }
#endif /* JEEFI */
    if ( ( ptt_data_old->u4_einjrq_dat & u4g_EMINJ_RQQFC ) != (u4)0U )          /* FC�����˗ʗv���L */
    {
        u4t_rqdat = ( u4t_rqdat | u4g_EMINJ_RQQFC );
    }
#if JECOMBCCPT_E == u1g_EJCC_SPRAYG_E                   /*�y���ڰ�޲�ށz*/
    if ( ( ptt_data_old->u4_einjrq_dat & u4g_EMINJ_RQQINJEXP ) != (u4)0U )      /* �c���s�����˗ʗv���L */
    {
        u4t_rqdat = ( u4t_rqdat | u4g_EMINJ_RQQINJEXP );
    }
#endif /* JECOMBCCPT_E */
    if ( ( ( ptt_data_old->u4_einjrq_dat & u4g_EMINJ_RQK1FN ) != (u4)0U )       /* 1��ڕ��˗ʎZ�o�W���v���L(��ݸ��) */
      || ( ( ptt_data_old->u4_einjrq_dat & u4g_EMINJ_RQK1F )  != (u4)0U ) )     /* 1��ڕ��˗ʎZ�o�W���v���L */
    {
        u4t_rqdat = ( u4t_rqdat | u4g_EMINJ_RQK1FN );
    }
    if ( ( ( ptt_data_old->u4_einjrq_dat & u4g_EMINJ_RQK2FN ) != (u4)0U )       /* 2��ڕ��˗ʎZ�o�W���v���L(��ݸ��) */
      || ( ( ptt_data_old->u4_einjrq_dat & u4g_EMINJ_RQK2F )  != (u4)0U ) )     /* 2��ڕ��˗ʎZ�o�W���v���L */
    {
        u4t_rqdat = ( u4t_rqdat | u4g_EMINJ_RQK2FN );
    }
    if ( ( ( ptt_data_old->u4_einjrq_dat & u4g_EMINJ_RQK3FN ) != (u4)0U )       /* 3��ڕ��˗ʎZ�o�W���v���L(��ݸ��) */
      || ( ( ptt_data_old->u4_einjrq_dat & u4g_EMINJ_RQK3F )  != (u4)0U ) )     /* 3��ڕ��˗ʎZ�o�W���v���L */
    {
        u4t_rqdat = ( u4t_rqdat | u4g_EMINJ_RQK3FN );
    }
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    if ( ( ptt_data_old->u4_einjrq_dat & u4g_EMINJ_RQPRREQ ) != (u4)0U )        /* ��������ߖڕW�R���v���L */
    {
        u4t_rqdat = ( u4t_rqdat | u4g_EMINJ_RQPRREQ );
    }
#endif /* JEEFI */
#if JEPRDEMAND == u1g_EJCC_NOT_USE                      /*�y�ϔR�����䖳�z*/
    if ( ( ptt_data_old->u4_einjrq_dat & u4g_EMINJ_RQQFREQ ) != (u4)0U )        /* �R������ߓf�o�ʗv���L */
    {
        u4t_rqdat = ( u4t_rqdat | u4g_EMINJ_RQQFREQ );
    }
#else                                                   /*�y�ϔR������L�z*/
    if ( ( ptt_data_old->u4_einjrq_dat & u4g_EMINJ_RQPRREQL ) != (u4)0U )       /* �ሳ����ߖڕW�R���v���L */
    {
        u4t_rqdat = ( u4t_rqdat | u4g_EMINJ_RQPRREQL );
    }
#endif /* JEPRDEMAND */
    if ( ( ptt_data_old->u4_einjrq_dat & u4g_EMINJ_RQXQINJAST ) != (u4)0U )     /* �n���㕬�˗ʗv���׸ޗv���L */
    {
        u4t_rqdat = ( u4t_rqdat | u4g_EMINJ_RQXQINJAST );
    }
    if ( ( ptt_data_old->u4_einjrq_dat & u4g_EMINJ_RQKRCHREF ) != (u4)0U )      /* ���˗ʕ␳�W���v���L */
    {
        u4t_rqdat = ( u4t_rqdat | u4g_EMINJ_RQKRCHREF );
    }
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    if ( ( ptt_data_old->u4_einjrq_dat & u4g_EMINJ_RQPLREQ ) != (u4)0U )        /* PL���ˎ��{�v���L */
    {
        u4t_rqdat = ( u4t_rqdat | u4g_EMINJ_RQPLREQ );
    }
#endif /* JEEFI */

    ptt_data_new->u4_einjrq_dat = u4t_rqdat;

    ptt_data_new->u2_einjmod    = ptt_data_old->u2_einjmod;
#if JEEFI != u1g_EJCC_D4        /*�yD-4�ȊO�z*/
    ptt_data_new->s2_eainjpn[0] = ptt_data_old->s2_eainjp1;
    ptt_data_new->s2_eainjpn[1] = ptt_data_old->s2_eainjp2;
    ptt_data_new->s2_eainjpn[2] = ptt_data_old->s2_eainjp3;
    ptt_data_new->s2_eainjpn[3] = ptt_data_old->s2_eainjp4;
    ptt_data_new->s2_einjend    = ptt_data_old->s2_einjend;
    ptt_data_new->s2_eainjcutp  = ptt_data_old->s2_eainjcutp;
#endif /* JEEFI */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    ptt_data_new->s2_eainjdn[0] = ptt_data_old->s2_eainjd1;
    ptt_data_new->s2_eainjdn[1] = ptt_data_old->s2_eainjd2;
    ptt_data_new->s2_eainjdn[2] = ptt_data_old->s2_eainjd3;
    ptt_data_new->s2_eainjdn[3] = ptt_data_old->s2_eainjd4;
    ptt_data_new->s2_eainjcutd  = ptt_data_old->s2_eainjcutd;
#endif /* JEEFI */
    if ( u1s_eminj_exnercdfew == (u1)ON )               /* NE�����^�X�N�����Ȃ� */
    {
#if JEEFI != u1g_EJCC_D4        /*�yD-4�ȊO�z*/
        ptt_data_new->s4_eqinjstpn[0] = ptt_data_old->s4_eqinjstp1;
        ptt_data_new->s4_eqinjstpn[1] = ptt_data_old->s4_eqinjstp2;
        ptt_data_new->s4_eqinjstpn[2] = ptt_data_old->s4_eqinjstp3;
        ptt_data_new->s4_eqinjstpn[3] = ptt_data_old->s4_eqinjstp4;
#endif /* JEEFI */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
        ptt_data_new->s4_eqinjstdn[0] = ptt_data_old->s4_eqinjstd1;
        ptt_data_new->s4_eqinjstdn[1] = ptt_data_old->s4_eqinjstd2;
        ptt_data_new->s4_eqinjstdn[2] = ptt_data_old->s4_eqinjstd3;
        ptt_data_new->s4_eqinjstdn[3] = ptt_data_old->s4_eqinjstd4;
#endif /* JEEFI */
    }
    for ( u1t_cyl = (u1)0U; u1t_cyl < u1t_ncyl_c; u1t_cyl++ )
    {
        ptt_data_new->s4_eqfc[u1t_cyl] = ptt_data_old->s4_eqfc[u1t_cyl];
    }
#if JECOMBCCPT_E == u1g_EJCC_SPRAYG_E /*�y���ڰ�޲�ށz*/
    ptt_data_new->s4_eqinjexp   = ptt_data_old->s4_eqinjexp;
#endif /* JECOMBCCPT_E */
    for ( u1t_mox = (u1)0U; u1t_mox < u1t_nox_c; u1t_mox++ )
    {
        ptt_data_new->s2_ek1fn[u1t_mox] = ptt_data_old->s2_ek1fn[u1t_mox];
        ptt_data_new->s2_ek2fn[u1t_mox] = ptt_data_old->s2_ek2fn[u1t_mox];
        ptt_data_new->s2_ek3fn[u1t_mox] = ptt_data_old->s2_ek3fn[u1t_mox];
        ptt_data_new->s2_ekrchref[u1t_mox]   = ptt_data_old->s2_ekrchref[u1t_mox];
    }
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    ptt_data_new->s2_eprreq     = ptt_data_old->s2_eprreq;
#endif /* JEEFI */
#if JEPRDEMAND == u1g_EJCC_NOT_USE                      /*�y�ϔR�����䖳�z*/
    ptt_data_new->s2_eqfreq     = ptt_data_old->s2_eqfreq;
#else                           /*�y�ϔR������L�z*/
    ptt_data_new->s2_eprreql    = ptt_data_old->s2_eprreql;
#endif /* JEPRDEMAND */
    glbitcp_bibi( ptt_data_old->bi_exqinjast, ptt_data_new->bi_exqinjast );
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    ptt_data_new->u1_explreq    = ptt_data_old->u1_explreq;
#endif /* JEEFI */
}

/**********************************************************************/
/*  �֐���        | vds_eminj_einj_dataconv_rev( )                    */
/*  �������e      | �W��Ώۗp�V�����\���̃f�[�^�ڍs����              */
/*  ����^�C�~���O| �����v����                                        */
/*  ����          | ptt_data_old  : ���\���̃f�[�^�̃A�h���X          */
/*                | ptt_data_new  : �V�\���̃f�[�^�̃A�h���X          */
/*  �߂�l        | �Ȃ�                                              */
/*  ���ӎ���      | �V�\���̂ł̂ݐV���ɑ��݂��郁���o(u4_einjptn     */
/*                | ,s4_eqinjflfix[],s4_eqinjplfix[]                  */
/*                | ,s2_eainjdn[4],s2_eainjdn[5]                      */
/*                | ,s4_eqinjstdn[4],s4_eqinjstdn[5])�͈ڍs���Ă��Ȃ� */
/**********************************************************************/
static void
vds_eminj_einj_dataconv_rev( st_EMINJ_EMINJ_DEF *ptt_data_old, const st_EMINJ_EMINJ_BUF *ptt_data_new )
{
    u1 u1t_mox;    /* lsb=1 :���C���Z���T�� */
    u1 u1t_nox_c;  /* lsb=1 :���C���Z���T�� */
    u1 u1t_cyl;    /* lsb=1 :�C���� */
    u1 u1t_ncyl_c; /* lsb=1 :�C���� */
    u4 u4t_rqdat;  /* lsb=1 :�v���w���f�[�^ */

    u1t_ncyl_c = u1g_ejcc_NCYL;
    u1t_nox_c = u1g_ejcc_NOX;

    ptt_data_old->u1_pri        = ptt_data_new->u1_pri;

    u4t_rqdat = u4s_EMINJ_NORQDAT;
    if ( ( ptt_data_new->u4_einjrq_dat & u4g_EMINJ_RQINJMODE ) != (u4)0U )      /* ����Ӱ�ޗv���L */
    {
        u4t_rqdat = ( u4t_rqdat | u4g_EMINJ_RQINJMODE );
    }
#if JEEFI != u1g_EJCC_D4        /*�yD-4�ȊO�z*/
    if ( ( ptt_data_new->u4_einjrq_dat & u4g_EMINJ_RQAINJPN ) != (u4)0U )       /* �߰�n��ڕ��ˊJ�n�����v���L */
    {
        if ( ptt_data_new->s2_eainjpn[0]  != s2s_EMINJ_AINJP_VD )               /* �߰�1��ڕ��ˊJ�n�����v���L */
        {
            u4t_rqdat = ( u4t_rqdat | u4g_EMINJ_RQAINJP1 );
        }
        if ( ptt_data_new->s2_eainjpn[1]  != s2s_EMINJ_AINJP_VD )               /* �߰�2��ڕ��ˊJ�n�����v���L */
        {
            u4t_rqdat = ( u4t_rqdat | u4g_EMINJ_RQAINJP2 );
        }
        if ( ptt_data_new->s2_eainjpn[2]  != s2s_EMINJ_AINJP_VD )               /* �߰�3��ڕ��ˊJ�n�����v���L */
        {
            u4t_rqdat = ( u4t_rqdat | u4g_EMINJ_RQAINJP3 );
        }
        if ( ptt_data_new->s2_eainjpn[3]  != s2s_EMINJ_AINJP_VD )               /* �߰�4��ڕ��ˊJ�n�����v���L */
        {
            u4t_rqdat = ( u4t_rqdat | u4g_EMINJ_RQAINJP4 );
        }
    }
    if ( ( ptt_data_new->u4_einjrq_dat & u4g_EMINJ_RQINJEND ) != (u4)0U )       /* �߰ĕ��ˏI�������v���L */
    {
        u4t_rqdat = ( u4t_rqdat | u4g_EMINJ_RQINJEND );
    }
    if ( ( ptt_data_new->u4_einjrq_dat & u4g_EMINJ_RQAINJCUTP ) != (u4)0U )     /* �߰ĕ��ˋ�����Ď����v���L */
    {
        u4t_rqdat = ( u4t_rqdat | u4g_EMINJ_RQAINJCUTP );
    }
#endif /* JEEFI */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    if ( ( ptt_data_new->u4_einjrq_dat & u4g_EMINJ_RQAINJCUTD ) != (u4)0U )     /* �������ˋ�����Ď����v���L */
    {
        u4t_rqdat = ( u4t_rqdat | u4g_EMINJ_RQAINJCUTD );
    }
    if ( ( ptt_data_new->u4_einjrq_dat & u4g_EMINJ_RQAINJDN ) != (u4)0U )       /* ����n��ڕ��ˊJ�n�����v���L */
    {
        if ( ptt_data_new->s2_eainjdn[0]  != s2s_EMINJ_AINJD_VD )               /* ����1��ڕ��ˊJ�n�����v���L */
        {
            u4t_rqdat = ( u4t_rqdat | u4g_EMINJ_RQAINJD1 );
        }
        if ( ptt_data_new->s2_eainjdn[1]  != s2s_EMINJ_AINJD_VD )               /* ����2��ڕ��ˊJ�n�����v���L */
        {
            u4t_rqdat = ( u4t_rqdat | u4g_EMINJ_RQAINJD2 );
        }
        if ( ptt_data_new->s2_eainjdn[2]  != s2s_EMINJ_AINJD_VD )               /* ����3��ڕ��ˊJ�n�����v���L */
        {
            u4t_rqdat = ( u4t_rqdat | u4g_EMINJ_RQAINJD3 );
        }
        if ( ptt_data_new->s2_eainjdn[3]  != s2s_EMINJ_AINJD_VD )               /* ����4��ڕ��ˊJ�n�����v���L */
        {
            u4t_rqdat = ( u4t_rqdat | u4g_EMINJ_RQAINJD4 );
        }
    }
#endif /* JEEFI */
#if JEEFI != u1g_EJCC_D4        /*�yD-4�ȊO�z*/
    if ( ( ptt_data_new->u4_einjrq_dat & u4g_EMINJ_RQQINJSTPN ) != (u4)0U )     /* �߰�n��ڕ��ˊJ�n�����v���L */
    {
        if ( ptt_data_new->s4_eqinjstpn[0]  != s4s_EMINJ_QINJ_VD )              /* �߰�1��ڎn�������˗ʗv���L */
        {
            u4t_rqdat = ( u4t_rqdat | u4g_EMINJ_RQQINJSTP1 );
        }
        if ( ptt_data_new->s4_eqinjstpn[1]  != s4s_EMINJ_QINJ_VD )              /* �߰�2��ڎn�������˗ʗv���L */
        {
            u4t_rqdat = ( u4t_rqdat | u4g_EMINJ_RQQINJSTP2 );
        }
        if ( ptt_data_new->s4_eqinjstpn[2]  != s4s_EMINJ_QINJ_VD )              /* �߰�3��ڎn�������˗ʗv���L */
        {
            u4t_rqdat = ( u4t_rqdat | u4g_EMINJ_RQQINJSTP3 );
        }
        if ( ptt_data_new->s4_eqinjstpn[3]  != s4s_EMINJ_QINJ_VD )              /* �߰�4��ڎn�������˗ʗv���L */
        {
            u4t_rqdat = ( u4t_rqdat | u4g_EMINJ_RQQINJSTP4 );
        }
    }
#endif /* JEEFI */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    if ( ( ptt_data_new->u4_einjrq_dat & u4g_EMINJ_RQQINJSTDN ) != (u4)0U )     /* ����n��ڕ��ˊJ�n�����v���L */
    {
        if ( ptt_data_new->s4_eqinjstdn[0]  != s4s_EMINJ_QINJ_VD )              /* ����1��ڎn�������˗ʗv���L */
        {
            u4t_rqdat = ( u4t_rqdat | u4g_EMINJ_RQQINJSTD1 );
        }
        if ( ptt_data_new->s4_eqinjstdn[1]  != s4s_EMINJ_QINJ_VD )              /* ����2��ڎn�������˗ʗv���L */
        {
            u4t_rqdat = ( u4t_rqdat | u4g_EMINJ_RQQINJSTD2 );
        }
        if ( ptt_data_new->s4_eqinjstdn[2]  != s4s_EMINJ_QINJ_VD )              /* ����3��ڎn�������˗ʗv���L */
        {
            u4t_rqdat = ( u4t_rqdat | u4g_EMINJ_RQQINJSTD3 );
        }
        if ( ptt_data_new->s4_eqinjstdn[3]  != s4s_EMINJ_QINJ_VD )              /* ����4��ڎn�������˗ʗv���L */
        {
            u4t_rqdat = ( u4t_rqdat | u4g_EMINJ_RQQINJSTD4 );
        }
    }
#endif /* JEEFI */
    if ( ( ptt_data_new->u4_einjrq_dat & u4g_EMINJ_RQQFC ) != (u4)0U )          /* FC�����˗ʗv���L */
    {
        u4t_rqdat = ( u4t_rqdat | u4g_EMINJ_RQQFC );
    }
#if JECOMBCCPT_E == u1g_EJCC_SPRAYG_E                   /*�y���ڰ�޲�ށz*/
    if ( ( ptt_data_new->u4_einjrq_dat & u4g_EMINJ_RQQINJEXP ) != (u4)0U )      /* �c���s�����˗ʗv���L */
    {
        u4t_rqdat = ( u4t_rqdat | u4g_EMINJ_RQQINJEXP );
    }
#endif /* JECOMBCCPT_E */
    if ( ( ptt_data_new->u4_einjrq_dat & u4g_EMINJ_RQK1FN ) != (u4)0U )         /* 1��ڕ��˗ʎZ�o�W���v���L(��ݸ��) */
    {
        u4t_rqdat = ( u4t_rqdat | u4g_EMINJ_RQK1FN );
    }
    if ( ( ptt_data_new->u4_einjrq_dat & u4g_EMINJ_RQK2FN ) != (u4)0U )         /* 2��ڕ��˗ʎZ�o�W���v���L(��ݸ��) */
    {
        u4t_rqdat = ( u4t_rqdat | u4g_EMINJ_RQK2FN );
    }
    if ( ( ptt_data_new->u4_einjrq_dat & u4g_EMINJ_RQK3FN ) != (u4)0U )         /* 3��ڕ��˗ʎZ�o�W���v���L(��ݸ��) */
    {
        u4t_rqdat = ( u4t_rqdat | u4g_EMINJ_RQK3FN );
    }
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    if ( ( ptt_data_new->u4_einjrq_dat & u4g_EMINJ_RQPRREQ ) != (u4)0U )        /* ��������ߖڕW�R���v���L */
    {
        u4t_rqdat = ( u4t_rqdat | u4g_EMINJ_RQPRREQ );
    }
#endif /* JEEFI */
#if JEPRDEMAND == u1g_EJCC_NOT_USE                      /*�y�ϔR�����䖳�z*/
    if ( ( ptt_data_new->u4_einjrq_dat & u4g_EMINJ_RQQFREQ ) != (u4)0U )        /* �R������ߓf�o�ʗv���L */
    {
        u4t_rqdat = ( u4t_rqdat | u4g_EMINJ_RQQFREQ );
    }
#else                                                   /*�y�ϔR������L�z*/
    if ( ( ptt_data_new->u4_einjrq_dat & u4g_EMINJ_RQPRREQL ) != (u4)0U )       /* �ሳ����ߖڕW�R���v���L */
    {
        u4t_rqdat = ( u4t_rqdat | u4g_EMINJ_RQPRREQL );
    }
#endif /* JEPRDEMAND */
    if ( ( ptt_data_new->u4_einjrq_dat & u4g_EMINJ_RQXQINJAST ) != (u4)0U )     /* �n���㕬�˗ʗv���׸ޗv���L */
    {
        u4t_rqdat = ( u4t_rqdat | u4g_EMINJ_RQXQINJAST );
    }
    if ( ( ptt_data_new->u4_einjrq_dat & u4g_EMINJ_RQKRCHREF ) != (u4)0U )      /* ���˗ʕ␳�W���v���L */
    {
        u4t_rqdat = ( u4t_rqdat | u4g_EMINJ_RQKRCHREF );
    }
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    if ( ( ptt_data_new->u4_einjrq_dat & u4g_EMINJ_RQPLREQ ) != (u4)0U )        /* PL���ˎ��{�v���L */
    {
        u4t_rqdat = ( u4t_rqdat | u4g_EMINJ_RQPLREQ );
    }
#endif /* JEEFI */
    ptt_data_old->u4_einjrq_dat = u4t_rqdat;

    ptt_data_old->u2_einjmod    = ptt_data_new->u2_einjmod;
#if JEEFI != u1g_EJCC_D4        /*�yD-4�ȊO�z*/
    ptt_data_old->s2_eainjp1 = ptt_data_new->s2_eainjpn[0];
    ptt_data_old->s2_eainjp2 = ptt_data_new->s2_eainjpn[1];
    ptt_data_old->s2_eainjp3 = ptt_data_new->s2_eainjpn[2];
    ptt_data_old->s2_eainjp4 = ptt_data_new->s2_eainjpn[3];
    ptt_data_old->s2_einjend = ptt_data_new->s2_einjend;
    ptt_data_old->s2_eainjcutp = ptt_data_new->s2_eainjcutp;
#endif /* JEEFI */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    ptt_data_old->s2_eainjd1 = ptt_data_new->s2_eainjdn[0];
    ptt_data_old->s2_eainjd2 = ptt_data_new->s2_eainjdn[1];
    ptt_data_old->s2_eainjd3 = ptt_data_new->s2_eainjdn[2];
    ptt_data_old->s2_eainjd4 = ptt_data_new->s2_eainjdn[3];
    ptt_data_old->s2_eainjcutd = ptt_data_new->s2_eainjcutd;
#endif /* JEEFI */
    if ( u1s_eminj_exnercdfew == (u1)ON )               /* NE�����^�X�N�����Ȃ� */
    {
#if JEEFI != u1g_EJCC_D4        /*�yD-4�ȊO�z*/
        ptt_data_old->s4_eqinjstp1 = ptt_data_new->s4_eqinjstpn[0];
        ptt_data_old->s4_eqinjstp2 = ptt_data_new->s4_eqinjstpn[1];
        ptt_data_old->s4_eqinjstp3 = ptt_data_new->s4_eqinjstpn[2];
        ptt_data_old->s4_eqinjstp4 = ptt_data_new->s4_eqinjstpn[3];
#endif /* JEEFI */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
        ptt_data_old->s4_eqinjstd1 = ptt_data_new->s4_eqinjstdn[0];
        ptt_data_old->s4_eqinjstd2 = ptt_data_new->s4_eqinjstdn[1];
        ptt_data_old->s4_eqinjstd3 = ptt_data_new->s4_eqinjstdn[2];
        ptt_data_old->s4_eqinjstd4 = ptt_data_new->s4_eqinjstdn[3];
#endif /* JEEFI */
    }
    for ( u1t_cyl = (u1)0U; u1t_cyl < u1t_ncyl_c; u1t_cyl++ )
    {
        ptt_data_old->s4_eqfc[u1t_cyl] = ptt_data_new->s4_eqfc[u1t_cyl];
    }
#if JECOMBCCPT_E == u1g_EJCC_SPRAYG_E /*�y���ڰ�޲�ށz*/
    ptt_data_old->s4_eqinjexp   = ptt_data_new->s4_eqinjexp;
#endif /* JECOMBCCPT_E */
    for ( u1t_mox = (u1)0U; u1t_mox < u1t_nox_c; u1t_mox++ )
    {
        ptt_data_old->s2_ek1fn[u1t_mox] = ptt_data_new->s2_ek1fn[u1t_mox];
        ptt_data_old->s2_ek2fn[u1t_mox] = ptt_data_new->s2_ek2fn[u1t_mox];
        ptt_data_old->s2_ek3fn[u1t_mox] = ptt_data_new->s2_ek3fn[u1t_mox];
        ptt_data_old->s2_ekrchref[u1t_mox] = ptt_data_new->s2_ekrchref[u1t_mox];
    }
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    ptt_data_old->s2_eprreq     = ptt_data_new->s2_eprreq;
#endif /* JEEFI */
#if JEPRDEMAND == u1g_EJCC_NOT_USE                      /*�y�ϔR�����䖳�z*/
    ptt_data_old->s2_eqfreq     = ptt_data_new->s2_eqfreq;
#else                           /*�y�ϔR������L�z*/
    ptt_data_old->s2_eprreql    = ptt_data_new->s2_eprreql;
#endif /* JEPRDEMAND */
    glbitcp_bibi( ptt_data_new->bi_exqinjast, ptt_data_old->bi_exqinjast );
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    ptt_data_old->u1_explreq    = ptt_data_new->u1_explreq;
#endif /* JEEFI */
}

#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)              /*�y�ޭ��INJ�zOR�yD-4�z*/
/*********************************************************************/
/*  �֐���        | vds_eminj_erestahot_rap_dataget( )               */
/*  �������e      | �����Ďn�������ް��擾����(���b�p�[�֐�)         */
/*  ����^�C�~���O| �����v����                                       */
/*  ����          | ptt_store :�D��I�𒲒��ޯ̧�̱��ڽ              */
/*  �߂�l        | �Ȃ�                                             */
/*  ���ӎ���      |�y�ޭ��INJ�zOR�yD-4�z                             */
/*********************************************************************/
static void
vds_eminj_erestahot_rap_dataget( st_EMINJ_EMINJ_DEF *ptt_store )
{
    vds_eminj_einj_datacopy( ptt_store, &sts_eminj_erestahot_data );        /* ���L���R���s2_eainjp�As4_eqinjstp�̍X�V���ȗ� */
                                                                            /* erestahot�͏��ł���s2_eainjp�As4_eqinjstp���g�p���Ă��炸�A */
                                                                            /* �p�~�\��̃����o�Ȃ̂ō�����g�p����Ȃ����� */
}
#endif /* JEEFI */

#if (JEALLHV_E == u1g_EJCC_ALLHV_E) && (JEEFI != u1g_EJCC_D4)       /*�yALL HV�zAND�yD-4�ȊO�z*/
/*********************************************************************/
/*  �֐���        | vds_eminj_erdpn_rap_dataget( )                   */
/*  �������e      | PN�ጸ�����ް��擾����(���b�p�[�֐�)             */
/*  ����^�C�~���O| �����v����                                       */
/*  ����          | ptt_store :�D��I�𒲒��ޯ̧�̱��ڽ              */
/*  �߂�l        | �Ȃ�                                             */
/*  ���ӎ���      | �yALL HV�zAND�yD-4�ȊO�z                         */
/*********************************************************************/
static void
vds_eminj_erdpn_rap_dataget( st_EMINJ_EMINJ_DEF *ptt_store )
{
    vds_eminj_einj_datacopy( ptt_store, &sts_eminj_erdpn_data );            /* ���L���R���s2_eainjp�As4_eqinjstp�̍X�V���ȗ� */
                                                                            /* erdpn�͏��ł���s2_eainjp�As4_eqinjstp���g�p���Ă��炸�A */
                                                                            /* �p�~�\��̃����o�Ȃ̂ō�����g�p����Ȃ����� */
}
#endif /* JEALLHV_E,JEEFI */

/*********************************************************************/
/*  �֐���        | vds_eminj_dummy_emedi_dataget( )                 */
/*  �������e      | �_�~�[�֐�                                       */
/*  ����^�C�~���O| �����v����                                       */
/*  ����          | ptt_store :�D��I�𒲒��ޯ̧�̱��ڽ              */
/*  �߂�l        | �Ȃ�                                             */
/*  ���ӎ���      |                                                  */
/*********************************************************************/
static void
vds_eminj_dummy_emedi_dataget( st_EMINJ_EMINJ_DEF *ptt_store )
{
    /* �_�~�[�̂��ߏ����Ȃ� */
}

/*********************************************************************/
/*  �֐���        | vds_eminj_dummy_emedi_dataget2( )                */
/*  �������e      | �_�~�[�֐�                                       */
/*  ����^�C�~���O| �����v����                                       */
/*  ����          | ptt_store :�D��I�𒲒��ޯ̧�̱��ڽ              */
/*  �߂�l        | �Ȃ�                                             */
/*  ���ӎ���      |                                                  */
/*********************************************************************/
static void
vds_eminj_dummy_emedi_dataget2( st_EMINJ_EMINJ_BUF *ptt_store )
{
    /* �_�~�[�̂��ߏ����Ȃ� */
}

/**** End of File ****************************************************/
