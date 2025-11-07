/* eminj-pcw00-1600-a-t-M4 */
/*********************************************************************/
/*  Copyright Toyota Motor Corporation                               */
/*********************************************************************/

/*********************************************************************/
/* �I�u�W�F�N�g��  |  ���˗v���̒���                                 */
/* ���ӎ���        |                                                 */
/*-------------------------------------------------------------------*/
/*  I/F�ύX����    | acw-11 : �W��Ώۗp�\����,�������ް��\���̂���  */
/*                 |          �ȉ��̃����o���폜                     */
/*                 |            s4_eqinjclmt                         */
/*                 |          �ȉ���IF���폜                         */
/*                 |            u4g_EMINJ_RQQINJCLMT                 */
/*                 |          �ȉ���IF�����J                         */
/*                 |          �y�����K���p��ėL�zOR�y�����K��Ӱ�ޗL�z*/
/*                 |            u1g_EMINJ_BENCH_ID                   */
/*                 |          �ȉ���IF�̃R���p�C��SW�ύX             */
/*                 |          �y�����K���p��ėL�z->�y�����K���p��ėL�zOR�y�����K��Ӱ�ޗL�z*/
/*                 |            u1g_eminj_BENCH_PRI                  */
/*                 |          �yHV�z->�yEG-MG�V���ޱ�zOR�yEG-MG�����z*/
/*                 |            u1g_EMINJ_STPHV_ID,u1g_eminj_STPHV_PRI */
/*                 |          �yHV�z->�yALL HV�z                     */
/*                 |            u1g_EMINJ_WUPCAT_ID,u1g_eminj_WUPCAT_PRI */
/*                 |          �ySS����L�z->�ySS����L�zOR�yEG-MG�ׯ��z */
/*                 |            u1g_EMINJ_STPSS_ID,u1g_eminj_STPSS_PRI */
/*                 |            u1g_EMINJ_STASS_ID,u1g_eminj_STASS_PRI */
/*                 |          �yHV�zAND�y�߰āz->�yALL HV�zAND�yD-4�ȊO�z */
/*                 |            u1g_EMINJ_STAHV_ID,u1g_eminj_STAHV_PRI */
/*                 |          �yHV�zAND�yD-4�ȊO�z-> �R���p�C��SW�Ȃ� */
/*                 |            u1g_EMINJ_RDPN_ID,u1g_eminj_RDPN_PRI */
/*                 | acw-12 : �ȉ��̕ϐ���ǉ�                       */
/*                 |            f4g_eminj_eprreql�y�ϔR������L�z  */
/*                 |            s2g_eminj_ecqinjast_8m               */
/*                 |            u1g_eminj_explreq                    */
/*                 |          �ȉ��̒萔��ǉ�                       */
/*                 |            u1g_EMINJ_NONE_ID                    */
/*                 |            u1g_EMINJ_RDNVES_ID�yALL HV�z        */
/*                 |            u1g_EMINJ_RDPN_ST_ID�yALL HV�zAND�y�߰āz*/
/*                 |            u1g_EMINJ_FCFRCTRL_ID�yGPF�L�z       */
/*                 |            u1g_eminj_RDNVES_PRI�yALL HV�z       */
/*                 |            u1g_eminj_RDPN_ST_PRI�yALL HV�zAND�y�߰āz*/
/*                 |            u1g_eminj_FCFRCTRL_PRI�yGPF�L�z      */
/*                 |          �ȉ���IF�̃R���p�C��SW�ύX             */
/*                 |          �R���p�C��SW�Ȃ� ->�yALL HV�zAND�yD-4�ȊO�z */
/*                 |            u1g_EMINJ_RDPN_ID                    */
/*                 |            u1g_eminj_RDPN_PRI                   */
/*                 | acw-13 :                                        */
/*                 |          �ȉ��̕ϐ���ǉ�                       */
/*                 |            u4g_eminj_einjptn                    */
/*                 |            s2g_eminj_eainjpn[5]�yD-4�ȊO�z      */
/*                 |            f4g_eminj_eainjpn[5]�yD-4�ȊO�z      */
/*                 |            s2g_eminj_eainjdn[5]�y�ޭ��INJ�zOR�yD-4�z */
/*                 |            f4g_eminj_eainjdn[5]�y�ޭ��INJ�zOR�yD-4�z */
/*                 |            s4g_eminj_eqinjstpn[5]�yD-4�ȊO�z    */
/*                 |            f4g_eminj_eqinjstpn[5]�yD-4�ȊO�z    */
/*                 |            s4g_eminj_eqinjstdn[5]�y�ޭ��INJ�zOR�yD-4�z */
/*                 |            f4g_eminj_eqinjstdn[5]�y�ޭ��INJ�zOR�yD-4�z */
/*                 |            s4g_eminj_eqinjflfix[8]              */
/*                 |            f4g_eminj_eqinjflfix[8]              */
/*                 |            s4g_eminj_eqinjplfix[8]              */
/*                 |            f4g_eminj_eqinjplfix[8]              */
/*                 |            stg_eminj_eminj                      */
/*                 |          �ȉ��̏W��Ώۗp�\����,�������ް��\���̂�ǉ� */
/*                 |           st_EMINJ_EMINJ_BUF                    */
/*                 |           st_EMINJ_EMINJ                        */
/*                 |          �ȉ���st_EMINJ_EMINJ_DEF,st_EMINJ_EINJ�̃����o�� */
/*                 |           �R���p�C��SW�ύX                      */
/*                 |           �y�ޭ��INJ�zAND�yE-EGR�z              */
/*                 |           ->�y�ޭ��INJ�zAND�yEGR����L�z        */
/*                 |            f4_ekpfiegr                          */
/*                 |            f4_ekpfiegrn[u1g_EJCC_NOX]           */
/*                 |          �ȉ��̊֐���ǉ�                       */
/*                 |            vdg_eminj_eminj_dataget()            */
/*                 |          �ȉ��̒萔��ǉ�                       */
/*                 |            u1g_EMINJ_BINJPLCTR_ID�y�ޭ��INJ�zOR�yD-4�z */
/*                 |            u1g_eminj_BINJPLCTR_PRI�y�ޭ��INJ�zOR�yD-4�z */
/*                 |            u4g_EMINJ_INJPTN_VD                  */
/*                 |            u1g_eminj_FREE2_PRI�y�ذ�߰�2�g�p�z  */
/*                 |            u1g_eminj_FREE3_PRI�y�ذ�߰�3�g�p�z  */
/*                 |            u1g_eminj_FREE4_PRI�y�ذ�߰�4�g�p�z  */
/*                 |            u1g_eminj_FREE5_PRI�y�ذ�߰�5�g�p�z  */
/*                 |            u1g_eminj_FREE6_PRI�y�ذ�߰�6�g�p�z  */
/*                 |            u1g_eminj_FREE7_PRI�y�ذ�߰�7�g�p�z  */
/*                 |            u1g_EMINJ_FREE2_ID�y�ذ�߰�2�g�p�z   */
/*                 |            u1g_EMINJ_FREE3_ID�y�ذ�߰�3�g�p�z   */
/*                 |            u1g_EMINJ_FREE4_ID�y�ذ�߰�4�g�p�z   */
/*                 |            u1g_EMINJ_FREE5_ID�y�ذ�߰�5�g�p�z   */
/*                 |            u1g_EMINJ_FREE6_ID�y�ذ�߰�6�g�p�z   */
/*                 |            u1g_EMINJ_FREE7_ID�y�ذ�߰�7�g�p�z   */
/*                 |            u4g_EMINJ_RQINJPTN                   */
/*                 |            u4g_EMINJ_RQAINJPN                   */
/*                 |            u4g_EMINJ_RQAINJDN                   */
/*                 |            u4g_EMINJ_RQQINJSTPN                 */
/*                 |            u4g_EMINJ_RQQINJSTDN                 */
/*                 |            u4g_EMINJ_RQQINJFLFIX                */
/*                 |            u4g_EMINJ_RQQINJPLFIX                */
/*                 |            u2g_EMINJ_MOD007                     */
/*                 |          �ȉ��̕ϐ����폜                       */
/*                 |            s4g_eminj_eqfccyl[u1g_EJCC_NCYL]     */
/*                 |            f4g_eminj_eqfccyl[u1g_EJCC_NCYL]     */
/*                 |            u1g_eminj_explrq[u1g_EJCC_NCYL]      */
/*                 |          �ȉ���IF�̃R���p�C��SW�ύX             */
/*                 |          �yALL HV�zAND�yD-4�ȊO�z->�yALL HV�z   */
/*                 |           u1g_EMINJ_STAHV_ID,u1g_eminj_STAHV_PRI */
/*                 |          �y�ޭ��INJ�zAND�yE-EGR�z               */
/*                 |           ->�y�ޭ��INJ�zAND�yEGR����L�z        */
/*                 |           f4g_eminj_ekpfiegr,                   */
/*                 |           f4g_eminj_ekpfiegrn[u1g_EJCC_NOX]     */
/*                 | acw-14 : �ȉ��萔�̒ǉ�                         */
/*                 |            u1g_EMINJ_STACM_ID                   */
/*                 |             (�y����ļ޵̪ݼݸޗL�zOR�y��޺��۰ٗL�z)AND�ySUB-CPU�ȊO�zAND�y�����Ӱ�ގ��̎n������v���g�p�z*/
/*                 |            u1g_EMINJ_ACTGAF_ID�y�ޭ��INJ�z      */
/*                 |            u1g_EMINJ_IMBRQ_ID�yAF�C���Բ����ݽ�L�zAND�y�ޭ��INJ�zAND�y�����ݽOBD�v���ɂ�鱸è�ސ���v���g�p�z*/
/*                 |            u1g_EMINJ_MFINJRQ_ID�y����OBD�L�zAND�y�ޭ��INJ�zAND�y����OBD�v���ɂ�鱸è�ސ���v���g�p�z*/
/*                 |            u1g_EMINJ_FKGDRQ_ID�y�R��OBD�L�zAND�y�ޭ��INJ�zAND�y�R���nOBD�v���ɂ�鱸è�ސ���v���g�p�z*/
/*                 |            u1g_eminj_STACM_PRI                  */
/*                 |             (�y����ļ޵̪ݼݸޗL�zOR�y��޺��۰ٗL�z)AND�ySUB-CPU�ȊO�zAND�y�����Ӱ�ގ��̎n������v���g�p�z*/
/*                 |            u1g_eminj_IMBRQ_PRI�yAF�C���Բ����ݽ�L�zAND�y�ޭ��INJ�zAND�y�����ݽOBD�v���ɂ�鱸è�ސ���v���g�p�z*/
/*                 |            u1g_eminj_MFINJRQ_PRI�y����OBD�L�zAND�y�ޭ��INJ�zAND�y����OBD�v���ɂ�鱸è�ސ���v���g�p�z*/
/*                 |            u1g_eminj_FKGDRQ_PRI�y�R��OBD�L�zAND�y�ޭ��INJ�zAND�y�R���nOBD�v���ɂ�鱸è�ސ���v���g�p�z*/
/*                 |          �ȉ��萔�̃R���p�C��SW�ύX             */
/*                 |            u1g_EMINJ_STAHV_ID�yALL HV�zAND�yHV�n������v���g�p�z*/
/*                 |            u1g_EMINJ_FCFRCTRL_ID�yGPF�L�zAND�y1�C��FC����v���g�p�z*/
/*                 |            u1g_EMINJ_ACTOBD_ID�y�ޭ��INJ�zAND�yOBD�v���ɂ�鱸è�ސ���v���g�p�z*/
/*                 |            u1g_EMINJ_ACTLFG_ID(�y�ޭ��INJ�zOR�yD-4�z)AND�y�߰�����Ċw�K�ׂ̱̈�è�ސ���v���g�p�z*/
/*                 |            u1g_EMINJ_BINJPLCTR_ID(�y�ޭ��INJ�zOR�yD-4�z)AND�y�߰�����ĕ��˂�p������{���ː���v���g�p�z*/
/*                 |            u1g_eminj_STAHV_PRI�yALL HV�zAND�yHV�n������v���g�p�z*/
/*                 |            u1g_eminj_FCFRCTRL_PRI�yGPF�L�zAND�y1�C��FC����v���g�p�z*/
/*                 |            u1g_eminj_INJIMB_PRI�yAF�C���Բ����ݽ�L�zAND�y�ޭ��INJ�zAND�y�����ݽ���̕��ː���v���g�p�z*/
/*                 |            u1g_eminj_ACTOBD_PRI�y�ޭ��INJ�zAND�yOBD�v���ɂ�鱸è�ސ���v���g�p�z*/
/*                 |            u1g_eminj_ACTLFG_PRI(�y�ޭ��INJ�zOR�yD-4�z)AND�y�߰�����Ċw�K�ׂ̱̈�è�ސ���v���g�p�z*/
/*                 |            u1g_eminj_BINJPLCTR_PRI(�y�ޭ��INJ�zOR�yD-4�z)AND�y�߰�����ĕ��˂�p������{���ː���v���g�p�z*/
/*                 |          �ȉ��ϐ���ǉ�                         */
/*                 |            f4g_eminj_eainjd1fix�y�ޭ��INJ�zOR�yD-4�z*/
/*                 |            f4g_eminj_eainjd2fix�y�ޭ��INJ�zOR�yD-4�z*/
/*                 |            f4g_eminj_eainjd3fix�y�ޭ��INJ�zOR�yD-4�z*/
/*                 |            f4g_eminj_eainjd4fix�y�ޭ��INJ�zOR�yD-4�z*/
/*                 |            f4g_eminj_ek1ffix                    */
/*                 |            f4g_eminj_ek2ffix                    */
/*                 |            f4g_eminj_ek3ffix                    */
/*                 | acw-15 : �W��Ώۗp�\����st_EMINJ_EMINJ_BUF���� */
/*                 |          �ȉ��̃����o�̔z��v�f����ύX         */
/*                 |            s2_eainjdn[]   �y�ޭ��INJ�zOR�yD-4�z */
/*                 |            s4_eqinjstdn[] �y�ޭ��INJ�zOR�yD-4�z */
/*                 |          �������ް��\����st_EMINJ_EMINJ����     */
/*                 |          �ȉ��̃����o�̔z��v�f����ύX         */
/*                 |            s2_eainjdn[]   �y�ޭ��INJ�zOR�yD-4�z */
/*                 |            f4_eainjdn[]   �y�ޭ��INJ�zOR�yD-4�z */
/*                 |            s4_eqinjstdn[] �y�ޭ��INJ�zOR�yD-4�z */
/*                 |            f4_eqinjstdn[] �y�ޭ��INJ�zOR�yD-4�z */
/*                 |          �ȉ��萔�̒ǉ�                         */
/*                 |            u1g_EMINJ_BINJPLCTR_WC_ID �yALL HV�zAND�yPL������˗L�zAND�y�߰�����ĕ��˂�p������{���ː���(�G�}�g�@��)�v���g�p�z*/
/*                 |            u1g_EMINJ_BINJPLCTR_STAHV_ID �yEG-MG�V���ޱ�zAND�yFFV���䖳�zAND�yPL������˗L�zAND�y�߰�����ĕ��˂�p������{���ː���(HV�n�����䎞)�v���g�p�z*/
/*                 |            u1g_EMINJ_FREE8_ID �y�ذ�߰�8�g�p�z  */
/*                 |            u1g_EMINJ_FREE9_ID �y�ذ�߰�9�g�p�z  */
/*                 |            u1g_EMINJ_FREE10_ID �y�ذ�߰�10�g�p�z*/
/*                 |            u1g_EMINJ_FREE11_ID �y�ذ�߰�11�g�p�z*/
/*                 |            u1g_eminj_BINJPLCTR_WC_PRI �yALL HV�zAND�yPL������˗L�zAND�y�߰�����ĕ��˂�p������{���ː���(�G�}�g�@��)�v���g�p�z*/
/*                 |            u1g_eminj_BINJPLCTR_STAHV_PRI �yEG-MG�V���ޱ�zAND�yFFV���䖳�zAND�yPL������˗L�zAND�y�߰�����ĕ��˂�p������{���ː���(HV�n�����䎞)�v���g�p�z*/
/*                 |            u1g_eminj_FREE8_PRI �y�ذ�߰�8�g�p�z */
/*                 |            u1g_eminj_FREE9_PRI �y�ذ�߰�9�g�p�z */
/*                 |            u1g_eminj_FREE10_PRI �y�ذ�߰�10�g�p�z*/
/*                 |            u1g_eminj_FREE11_PRI �y�ذ�߰�11�g�p�z*/
/*                 |          �ȉ��萔�̃R���p�C��SW�ύX             */
/*                 |            u1g_EMINJ_STACM_ID (�y�Ӱĺ��۰ٗL�zOR�y��޺��۰ٗL�z)AND�ySUB-CPU�ȊO�zAND�y�n���������オ�萧��v���g�p�z*/
/*                 |            u1g_EMINJ_BINJPLCTR_ID �yPL������˗L�zAND�y�߰�����ĕ��˂�p������{���ː���v���g�p�z*/
/*                 |            u1g_eminj_STACM_PRI (�y�Ӱĺ��۰ٗL�zOR�y��޺��۰ٗL�z)AND�ySUB-CPU�ȊO�zAND�y�n���������オ�萧��v���g�p�z*/
/*                 |            u1g_eminj_BINJPLCTR_PRI �yPL������˗L�zAND�y�߰�����ĕ��˂�p������{���ː���v���g�p�z*/
/*                 |            u1g_EMINJ_RDNVES_ID �R���p�C��SW�Ȃ� */
/*                 |          �ȉ��ϐ���ǉ�                         */
/*                 |            f4g_eminj_eainjd5fix �y�ޭ��INJ�zOR�yD-4�z*/
/*                 |            f4g_eminj_eainjd6fix �y�ޭ��INJ�zOR�yD-4�z*/
/*                 |          �ȉ��ϐ��̔z��v�f����ύX             */
/*                 |            s2g_eminj_eainjdn[] �y�ޭ��INJ�zOR�yD-4�z*/
/*                 |            f4g_eminj_eainjdn[] �y�ޭ��INJ�zOR�yD-4�z*/
/*                 |            s4g_eminj_eqinjstdn[] �y�ޭ��INJ�zOR�yD-4�z*/
/*                 |            f4g_eminj_eqinjstdn[] �y�ޭ��INJ�zOR�yD-4�z*/
/*                 |          �ȉ��݊��p�}�N�����폜                 */
/*                 |            u4g_EMINJ_RQPRLREQ                   */
/*-------------------------------------------------------------------*/
/*  �t�@�C���\��   |  eminj_l_mat.c, eminj_c_mat.c, eminj_c.h        */
/*-------------------------------------------------------------------*/
/*     �ʕύX���� �i�ʕύX���͈ȉ��ɕύX���A���e���L�����邱�Ɓj */
/*********************************************************************/

#ifndef EMINJ_H
#define EMINJ_H

/*-------------------------------------------------------------------*/
/* �w�b�_�t�@�C���̃C���N���[�h                                      */
/*-------------------------------------------------------------------*/
#include <engsrc/espc/ejcc.h>   /* JEEFI,u1g_EJCC_D4,u1g_EJCC_DUAL,u1g_EJCC_PORT,u1g_EJCC_NOX,JEPRDEMAND,JESS */
                                /* JEEGR,u1g_EJCC_NCYL,JECOMBCCPT_E,u1g_EJCC_SPRAYG_E,JEMAT_BENCHI */
                                /* JEMAT_BENCH_E,JEEGMG_E,u1g_EJCC_HVPLGR_E,u1g_EJCC_HVDIRECT_E,u1g_EJCC_HVCLUTCH_E */
                                /* JEALLHV_E,u1g_EJCC_ALLHV_E */
                                /* JENGPF_E,JENVCTR,JEMICN_E,u1g_EJCC_SUB_E,JEOBDAFIMB_D,JEOBDMF */
                                /* JEOBDFKG,JEPLMLT_E,JERMTCTR,JEFFV */

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

#if !defined JEPRDEMAND
#error "JEPRDEMAND is undeclared"
#endif

#if !defined JESS
#error "JESS is undeclared"
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

#if !defined JEMAT_BENCHI
#error "JEMAT_BENCHI is undeclared"
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

#if !defined JEOBDAFIMB_D
#error "JEOBDAFIMB_D is undeclared"
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

#if !defined JEFFV
#error "JEFFV is undeclared"
#endif

/*-------------------------------------------------------------------*/
/* �^��`                                                            */
/*-------------------------------------------------------------------*/
/* �W��Ώۗp�\���̌^ */
typedef struct
{
    u1 u1_pri;                        /* lsb=1 :�D��x */
    u4 u4_einjrq_dat;                 /* lsb=1 :�v���L���ʎq */
    u2 u2_einjmod;                    /* lsb=1 :���˃��[�h */
#if JEEFI != u1g_EJCC_D4              /*�yD-4�ȊO�z*/
    s2 s2_eainjp1;                    /* lsb=1024/128/256,unit=BTDC :�|�[�g1��ڕ��ˊJ�n���� */
    s2 s2_eainjp2;                    /* lsb=1024/128/256,unit=BTDC :�|�[�g2��ڕ��ˊJ�n���� */
    s2 s2_eainjp3;                    /* lsb=1024/128/256,unit=BTDC :�|�[�g3��ڕ��ˊJ�n���� */
    s2 s2_eainjp4;                    /* lsb=1024/128/256,unit=BTDC :�|�[�g4��ڕ��ˊJ�n���� */
    s2 s2_einjend;                    /* lsb=1024/128/256,unit=BTDC :�|�[�g���ˏI������ */
#endif /* JEEFI */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    s2 s2_eainjd1;                    /* lsb=1024/128/256,unit=BTDC :����1��ڕ��ˊJ�n���� */
    s2 s2_eainjd2;                    /* lsb=1024/128/256,unit=BTDC :����2��ڕ��ˊJ�n���� */
    s2 s2_eainjd3;                    /* lsb=1024/128/256,unit=BTDC :����3��ڕ��ˊJ�n���� */
    s2 s2_eainjd4;                    /* lsb=1024/128/256,unit=BTDC :����4��ڕ��ˊJ�n���� */
#endif /* JEEFI */
#if JEEFI != u1g_EJCC_D4              /*�yD-4�ȊO�z*/
    s4 s4_eqinjstp1;                  /* lsb=(4096*1024)/128/256/256/256,unit=mg/st :�|�[�g1��ڎn�������˗� */
    s4 s4_eqinjstp2;                  /* lsb=(4096*1024)/128/256/256/256,unit=mg/st :�|�[�g2��ڎn�������˗� */
    s4 s4_eqinjstp3;                  /* lsb=(4096*1024)/128/256/256/256,unit=mg/st :�|�[�g3��ڎn�������˗� */
    s4 s4_eqinjstp4;                  /* lsb=(4096*1024)/128/256/256/256,unit=mg/st :�|�[�g4��ڎn�������˗� */
#endif /* JEEFI */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    s4 s4_eqinjstd1;                  /* lsb=(4096*1024)/128/256/256/256,unit=mg/st :����1��ڎn�������˗� */
    s4 s4_eqinjstd2;                  /* lsb=(4096*1024)/128/256/256/256,unit=mg/st :����2��ڎn�������˗� */
    s4 s4_eqinjstd3;                  /* lsb=(4096*1024)/128/256/256/256,unit=mg/st :����3��ڎn�������˗� */
    s4 s4_eqinjstd4;                  /* lsb=(4096*1024)/128/256/256/256,unit=mg/st :����4��ڎn�������˗� */
#endif /* JEEFI */
    s4 s4_eqfc[u1g_EJCC_NCYL];        /* lsb=(4096*1024)/128/256/256/256,unit=mg/st :FC�����˗� */
    s2 s2_ek1f;                       /* lsb=(1*4)/128/256,unit=�{ :1��ڕ��˗ʎZ�o�W��(�o���N�ԕ��ϒl(�c�C���Z���T)) */
    s2 s2_ek1fn[u1g_EJCC_NOX];        /* lsb=(1*4)/128/256,unit=�{ :1��ڕ��˗ʎZ�o�W��(�o���N��) */
    s2 s2_ek2f;                       /* lsb=(1*4)/128/256,unit=�{ :2��ڕ��˗ʎZ�o�W��(�o���N�ԕ��ϒl(�c�C���Z���T)) */
    s2 s2_ek2fn[u1g_EJCC_NOX];        /* lsb=(1*4)/128/256,unit=�{ :2��ڕ��˗ʎZ�o�W��(�o���N��) */
    s2 s2_ek3f;                       /* lsb=(1*4)/128/256,unit=�{ :3��ڕ��˗ʎZ�o�W��(�o���N�ԕ��ϒl(�c�C���Z���T)) */
    s2 s2_ek3fn[u1g_EJCC_NOX];        /* lsb=(1*4)/128/256,unit=�{ :3��ڕ��˗ʎZ�o�W��(�o���N��) */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    s2 s2_eprreq;                     /* lsb=(32*2)/128/256,unit=MPa :�����|���v�ڕW�R�� */
#endif /* JEEFI */
#if JEPRDEMAND == u1g_EJCC_NOT_USE    /*�y�ϔR�����䖳�z*/
    s2 s2_eqfreq;                     /* lsb=512/128/256,unit=L/h :�R���|���v�f�o���� */
#else                                 /*�y�ϔR������L�z*/
    s2 s2_eprreql;                    /* lsb=1280/128/256,unit=kPa :�ሳ�|���v�ڕW�R�� */
#endif /* JEPRDEMAND */
    u1 bi_exqinjast :1;               /* lsb=1 :�n���㕬�˗ʗv���t���O */
    u1 bi_dummy     :7;               /* �_�~�[ */
    s2 s2_ekrchref[u1g_EJCC_NOX];     /* lsb=(32*2)/128/256,unit=�{ :���˗ʕ␳�W��(�o���N��) */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    u1 u1_explreq;                    /* lsb=1 :PL���ˎ��{�v�� */
#endif /* JEEFI */
#if JEEFI != u1g_EJCC_D4              /*�yD-4�ȊO�z*/
    s2 s2_eainjcutp;                  /* lsb=1024/128/256,unit=BTDC :�߰ĕ��ˋ�����Ď��� */
#endif /* JEEFI */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    s2 s2_eainjcutd;                  /* lsb=1024/128/256,unit=BTDC :�������ˋ�����Ď��� */
#endif /* JEEFI */
#if JECOMBCCPT_E == u1g_EJCC_SPRAYG_E /*�y���ڰ�޲�ށz*/
    s4 s4_eqinjexp;                   /* lsb=(4096*1024)/128/256/256/256,unit=mg/st :�c���s�����˗� */
#endif /* JECOMBCCPT_E */
#if JEEFI != u1g_EJCC_D4              /*�yD-4�ȊO�z*/
    s2 s2_eainjp;                     /* lsb=1024/128/256,unit=BTDC :�߰ĕ��ˊJ�n����(�߰�������Ή����i�݊��p) */
    s4 s4_eqinjstp;                   /* lsb=(4096*1024)/128/256/256/256,unit=mg/st :�߰Ďn�������˗�(�߰�������Ή����i�݊��p) */
#endif /* JEEFI */
} st_EMINJ_EMINJ_DEF;

/* �������f�[�^�\���̌^ */
typedef struct
{
    u2 u2_einjmod;                    /* lsb=1 :���˃��[�h */
#if JEEFI != u1g_EJCC_D4              /*�yD-4�ȊO�z*/
    s2 s2_eainjp1;                    /* lsb=1024/128/256,unit=BTDC :�|�[�g1��ڕ��ˊJ�n���� */
    f4 f4_eainjp1;                    /* unit=BTDC :�|�[�g1��ڕ��ˊJ�n���� */
    s2 s2_eainjp2;                    /* lsb=1024/128/256,unit=BTDC :�|�[�g2��ڕ��ˊJ�n���� */
    f4 f4_eainjp2;                    /* unit=BTDC :�|�[�g2��ڕ��ˊJ�n���� */
    s2 s2_eainjp3;                    /* lsb=1024/128/256,unit=BTDC :�|�[�g3��ڕ��ˊJ�n���� */
    f4 f4_eainjp3;                    /* unit=BTDC :�|�[�g3��ڕ��ˊJ�n���� */
    s2 s2_eainjp4;                    /* lsb=1024/128/256,unit=BTDC :�|�[�g4��ڕ��ˊJ�n���� */
    f4 f4_eainjp4;                    /* unit=BTDC :�|�[�g4��ڕ��ˊJ�n���� */
    s2 s2_einjend;                    /* lsb=1024/128/256,unit=BTDC :�|�[�g���ˏI������ */
    f4 f4_einjend;                    /* unit=BTDC :�|�[�g���ˏI������ */
#endif /* JEEFI */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    s2 s2_eainjd1;                    /* lsb=1024/128/256,unit=BTDC :����1��ڕ��ˊJ�n���� */
    f4 f4_eainjd1;                    /* unit=BTDC :����1��ڕ��ˊJ�n���� */
    s2 s2_eainjd2;                    /* lsb=1024/128/256,unit=BTDC :����2��ڕ��ˊJ�n���� */
    f4 f4_eainjd2;                    /* unit=BTDC :����2��ڕ��ˊJ�n���� */
    s2 s2_eainjd3;                    /* lsb=1024/128/256,unit=BTDC :����3��ڕ��ˊJ�n���� */
    f4 f4_eainjd3;                    /* unit=BTDC :����3��ڕ��ˊJ�n���� */
    s2 s2_eainjd4;                    /* lsb=1024/128/256,unit=BTDC :����4��ڕ��ˊJ�n���� */
    f4 f4_eainjd4;                    /* unit=BTDC :����4��ڕ��ˊJ�n���� */
#endif /* JEEFI */
#if JEEFI == u1g_EJCC_PORT            /*�y�߰āz*/
    s2 s2_eainjpadd;                  /* lsb=1024/128/256,unit=BTDC :�|�[�g�ǉ����ˊJ�n���� */
#endif /* JEEFI */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    s2 s2_eainjdadd;                  /* lsb=1024/128/256,unit=BTDC :�����ǉ����ˊJ�n���� */
#endif /* JEEFI */
#if JEEFI != u1g_EJCC_D4              /*�yD-4�ȊO�z*/
    s4 s4_eqinjstp1;                  /* lsb=(4096*1024)/128/256/256/256,unit=mg/st :�|�[�g1��ڎn�������˗� */
    f4 f4_eqinjstp1;                  /* unit=mg/st :�|�[�g1��ڎn�������˗� */
    s4 s4_eqinjstp2;                  /* lsb=(4096*1024)/128/256/256/256,unit=mg/st :�|�[�g2��ڎn�������˗� */
    f4 f4_eqinjstp2;                  /* unit=mg/st :�|�[�g2��ڎn�������˗� */
    s4 s4_eqinjstp3;                  /* lsb=(4096*1024)/128/256/256/256,unit=mg/st :�|�[�g3��ڎn�������˗� */
    f4 f4_eqinjstp3;                  /* unit=mg/st :�|�[�g3��ڎn�������˗� */
    s4 s4_eqinjstp4;                  /* lsb=(4096*1024)/128/256/256/256,unit=mg/st :�|�[�g4��ڎn�������˗� */
    f4 f4_eqinjstp4;                  /* unit=mg/st :�|�[�g4��ڎn�������˗� */
#endif /* JEEFI */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    s4 s4_eqinjstd1;                  /* lsb=(4096*1024)/128/256/256/256,unit=mg/st :����1��ڎn�������˗� */
    f4 f4_eqinjstd1;                  /* unit=mg/st :����1��ڎn�������˗� */
    s4 s4_eqinjstd2;                  /* lsb=(4096*1024)/128/256/256/256,unit=mg/st :����2��ڎn�������˗� */
    f4 f4_eqinjstd2;                  /* unit=mg/st :����2��ڎn�������˗� */
    s4 s4_eqinjstd3;                  /* lsb=(4096*1024)/128/256/256/256,unit=mg/st :����3��ڎn�������˗� */
    f4 f4_eqinjstd3;                  /* unit=mg/st :����3��ڎn�������˗� */
    s4 s4_eqinjstd4;                  /* lsb=(4096*1024)/128/256/256/256,unit=mg/st :����4��ڎn�������˗� */
    f4 f4_eqinjstd4;                  /* unit=mg/st :����4��ڎn�������˗� */
#endif /* JEEFI */
    f4 f4_eqfc[u1g_EJCC_NCYL];        /* unit=mg/st :FC�����˗� */
    s2 s2_ek1f;                       /* lsb=(1*4)/128/256,unit=�{ :1��ڕ��˗ʎZ�o�W��(�o���N�ԕ��ϒl(�c�C���Z���T)) */
    f4 f4_ek1f;                       /* unit=�{ :1��ڕ��˗ʎZ�o�W��(�o���N�ԕ��ϒl(�c�C���Z���T)) */
    s2 s2_ek2f;                       /* lsb=(1*4)/128/256,unit=�{ :2��ڕ��˗ʎZ�o�W��(�o���N�ԕ��ϒl(�c�C���Z���T)) */
    f4 f4_ek2f;                       /* unit=�{ :2��ڕ��˗ʎZ�o�W��(�o���N�ԕ��ϒl(�c�C���Z���T)) */
    s2 s2_ek3f;                       /* lsb=(1*4)/128/256,unit=�{ :3��ڕ��˗ʎZ�o�W��(�o���N�ԕ��ϒl(�c�C���Z���T)) */
    f4 f4_ek3f;                       /* unit=�{ :3��ڕ��˗ʎZ�o�W��(�o���N�ԕ��ϒl(�c�C���Z���T)) */
    s2 s2_ek1fn[u1g_EJCC_NOX];        /* lsb=(1*4)/128/256,unit=�{ :1��ڕ��˗ʎZ�o�W��(�o���N��) */
    f4 f4_ek1fn[u1g_EJCC_NOX];        /* unit=�{ :1��ڕ��˗ʎZ�o�W��(�o���N��) */
    s2 s2_ek2fn[u1g_EJCC_NOX];        /* lsb=(1*4)/128/256,unit=�{ :2��ڕ��˗ʎZ�o�W��(�o���N��) */
    f4 f4_ek2fn[u1g_EJCC_NOX];        /* unit=�{ :2��ڕ��˗ʎZ�o�W��(�o���N��) */
    s2 s2_ek3fn[u1g_EJCC_NOX];        /* lsb=(1*4)/128/256,unit=�{ :3��ڕ��˗ʎZ�o�W��(�o���N��) */
    f4 f4_ek3fn[u1g_EJCC_NOX];        /* unit=�{ :3��ڕ��˗ʎZ�o�W��(�o���N��) */
    s2 s2_ekrchref[u1g_EJCC_NOX];     /* lsb=(32*2)/128/256,unit=�{ :���˗ʕ␳�W��(�o���N��) */
    f4 f4_ekrchref[u1g_EJCC_NOX];     /* unit=�{ :���˗ʕ␳�W��(�o���N��) */
    u1 bi_exqinjast :1;               /* lsb=1 :�n���㕬�˗ʗv���t���O */
    u1 bi_dummy     :7;               /* �_�~�[ */
    u1 u1_exqinjast;                  /* lsb=1 :�n���㕬�˗ʗv���t���O */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    u1 u1_explreq;                    /* lsb=1 :PL���ˎ��{�v�� */
#endif /* JEEFI */
#if JEEFI == u1g_EJCC_DUAL            /*�y�ޭ��INJ�z*/
    s2 s2_ekpfit;                     /* lsb=(1*4)/128/256,unit=�{ :�ڕW�߰ĕ��˗ʎZ�o�W��(��ݸ�ԕ��ϒl(²ݾݻ)) */
    f4 f4_ekpfit;                     /* unit=�{ :�ڕW�߰ĕ��˗ʎZ�o�W��(��ݸ�ԕ��ϒl(²ݾݻ)) */
    s2 s2_ekpfitn[u1g_EJCC_NOX];      /* lsb=(1*4)/128/256,unit=�{ :�ڕW�߰ĕ��˗ʎZ�o�W��(��ݸ��) */
    f4 f4_ekpfitn[u1g_EJCC_NOX];      /* unit=�{ :�ڕW�߰ĕ��˗ʎZ�o�W��(��ݸ��) */
#endif /* JEEFI */
#if JEEFI != u1g_EJCC_D4              /*�yD-4�ȊO�z*/
    f4 f4_ek1fpt;                     /* unit=�{ :�߰ĕ��˂̂ݗv�����̖ڕW�߰�1��ڕ��˗ʎZ�o�W�� */
#endif /* JEEFI */
#if JEEFI == u1g_EJCC_DUAL            /*�y�ޭ��INJ�z*/
 #if JEEGR == u1g_EJCC_USE            /*�yEGR����L�z*/
    f4 f4_ekpfiegr;                   /* unit=�{ :EGR-ON���̖ڕW�߰ĕ��˗ʎZ�o�W��(��ݸ�ԕ��ϒl(²ݾݻ)) */
    f4 f4_ekpfiegrn[u1g_EJCC_NOX];    /* unit=�{ :EGR-ON���̖ڕW�߰ĕ��˗ʎZ�o�W��(��ݸ��) */
 #endif /* JEEGR */
#endif /* JEEFI */
#if JEEFI != u1g_EJCC_D4              /*�yD-4�ȊO�z*/
    s2 s2_eainjcutp;                  /* lsb=1024/128/256,unit=BTDC :�߰ĕ��ˋ�����Ď��� */
    f4 f4_eainjcutp;                  /* unit=BTDC :�߰ĕ��ˋ�����Ď��� */
#endif /* JEEFI */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    s2 s2_eainjcutd;                  /* lsb=1024/128/256,unit=BTDC :�������ˋ�����Ď��� */
    f4 f4_eainjcutd;                  /* unit=BTDC :�������ˋ�����Ď��� */
#endif /* JEEFI */
    s4 s4_eqfc[u1g_EJCC_NCYL];        /* lsb=(4096*1024)/128/256/256/256,unit=mg/st :FC�����˗� */
#if JECOMBCCPT_E == u1g_EJCC_SPRAYG_E /*�y���ڰ�޲�ށz*/
    s4 s4_eqinjexp;                   /* lsb=(4096*1024)/128/256/256/256,unit=mg/st :�c���s�����˗� */
    f4 f4_eqinjexp;                   /* unit=mg/st :�c���s�����˗� */
#endif /* JECOMBCCPT_E */
#if JEEFI != u1g_EJCC_D4              /*�yD-4�ȊO�z*/
    s2 s2_ek1fpt;                     /* lsb=(1*4)/128/256,unit=�{ :�߰ĕ��˂̂ݗv�����̖ڕW�߰�1��ڕ��˗ʎZ�o�W�� */
#endif /* JEEFI */
} st_EMINJ_EINJ;

/* �W��Ώۗp�\���̌^ */
typedef struct
{
    u1 u1_pri;                        /* lsb=1 :�D��x */
    u4 u4_einjrq_dat;                 /* lsb=1 :�v���L���ʎq */
    u2 u2_einjmod;                    /* lsb=1 :���˃��[�h */
    u4 u4_einjptn;                    /* lsb=1 :���˃p�^�[�� */
#if JEEFI != u1g_EJCC_D4              /*�yD-4�ȊO�z*/
    s2 s2_eainjpn[5];                 /* lsb=1024/128/256,unit=BTDC :�|�[�gn��ڕ��ˊJ�n�����i���ˉ񐔔z��j */ /* 2025�N��5�񕬎˂܂ōl�����z��v�f��[5]�Ƃ��Ē�`���� */
    s2 s2_einjend;                    /* lsb=1024/128/256,unit=BTDC :�|�[�g���ˏI������ */
#endif /* JEEFI */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    s2 s2_eainjdn[6];                 /* lsb=1024/128/256,unit=BTDC :����n��ڕ��ˊJ�n�����i���ˉ񐔔z��j */ /* �n�����ɍő�6�񕬎�(�����̂�) */
#endif /* JEEFI */
#if JEEFI != u1g_EJCC_D4              /*�yD-4�ȊO�z*/
    s4 s4_eqinjstpn[5];               /* lsb=(4096*1024)/128/256/256/256,unit=mg/st :�|�[�gn��ڎn�������˗ʁi���ˉ񐔔z��j */ /* 2025�N��5�񕬎˂܂ōl�����z��v�f��[5]�Ƃ��Ē�`���� */
#endif /* JEEFI */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    s4 s4_eqinjstdn[6];               /* lsb=(4096*1024)/128/256/256/256,unit=mg/st :����n��ڎn�������˗ʁi���ˉ񐔔z��j */ /* �n�����ɍő�6�񕬎�(�����̂�) */
#endif /* JEEFI */
    s4 s4_eqfc[u1g_EJCC_NCYL];        /* lsb=(4096*1024)/128/256/256/256,unit=mg/st :FC�����˗� */
    s2 s2_ek1fn[u1g_EJCC_NOX];        /* lsb=(1*4)/128/256,unit=�{ :1��ڕ��˗ʎZ�o�W��(�o���N��) */
    s2 s2_ek2fn[u1g_EJCC_NOX];        /* lsb=(1*4)/128/256,unit=�{ :2��ڕ��˗ʎZ�o�W��(�o���N��) */
    s2 s2_ek3fn[u1g_EJCC_NOX];        /* lsb=(1*4)/128/256,unit=�{ :3��ڕ��˗ʎZ�o�W��(�o���N��) */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    s2 s2_eprreq;                     /* lsb=(32*2)/128/256,unit=MPa :�����|���v�ڕW�R�� */
#endif /* JEEFI */
#if JEPRDEMAND == u1g_EJCC_NOT_USE    /*�y�ϔR�����䖳�z*/
    s2 s2_eqfreq;                     /* lsb=512/128/256,unit=L/h :�R���|���v�f�o���� */
#else                                 /*�y�ϔR������L�z*/
    s2 s2_eprreql;                    /* lsb=1280/128/256,unit=kPa :�ሳ�|���v�ڕW�R�� */
#endif /* JEPRDEMAND */
    u1 bi_exqinjast :1;               /* lsb=1 :�n���㕬�˗ʗv���t���O */
    u1 bi_dummy     :7;               /* �_�~�[ */
    s2 s2_ekrchref[u1g_EJCC_NOX];     /* lsb=(32*2)/128/256,unit=�{ :���˗ʕ␳�W��(�o���N��) */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    u1 u1_explreq;                    /* lsb=1 :PL���ˎ��{�v�� */
#endif /* JEEFI */
#if JEEFI != u1g_EJCC_D4              /*�yD-4�ȊO�z*/
    s2 s2_eainjcutp;                  /* lsb=1024/128/256,unit=BTDC :�߰ĕ��ˋ�����Ď��� */
#endif /* JEEFI */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    s2 s2_eainjcutd;                  /* lsb=1024/128/256,unit=BTDC :�������ˋ�����Ď��� */
#endif /* JEEFI */
#if JECOMBCCPT_E == u1g_EJCC_SPRAYG_E /*�y���ڰ�޲�ށz*/
    s4 s4_eqinjexp;                   /* lsb=(4096*1024)/128/256/256/256,unit=mg/st :�c���s�����˗� */
#endif /* JECOMBCCPT_E */
    s4 s4_eqinjflfix[8];              /* lsb=(4096*1024)/128/256/256/256,unit=mg/st :FL�Œ蕬�˗� */
    s4 s4_eqinjplfix[8];              /* lsb=(4096*1024)/128/256/256/256,unit=mg/st :PL�Œ蕬�˗� */
} st_EMINJ_EMINJ_BUF;

/* �������f�[�^�\���̌^ */
typedef struct
{
    u2 u2_einjmod;                    /* lsb=1 :���˃��[�h */
    u4 u4_einjptn;                    /* lsb=1 :���˃p�^�[�� */
#if JEEFI != u1g_EJCC_D4              /*�yD-4�ȊO�z*/
    s2 s2_eainjpn[5];                 /* lsb=1024/128/256,unit=BTDC :�|�[�gn��ڕ��ˊJ�n�����i���ˉ񐔔z��j */ /* 2025�N��5�񕬎˂܂ōl�����z��v�f��[5]�Ƃ��Ē�`���� */
    f4 f4_eainjpn[5];                 /* unit=BTDC :�|�[�gn��ڕ��ˊJ�n�����i���ˉ񐔔z��j */ /* 2025�N��5�񕬎˂܂ōl�����z��v�f��[5]�Ƃ��Ē�`���� */
    s2 s2_einjend;                    /* lsb=1024/128/256,unit=BTDC :�|�[�g���ˏI������ */
    f4 f4_einjend;                    /* unit=BTDC :�|�[�g���ˏI������ */
#endif /* JEEFI */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    s2 s2_eainjdn[6];                 /* lsb=1024/128/256,unit=BTDC :����n��ڕ��ˊJ�n�����i���ˉ񐔔z��j */ /* �n�����ɍő�6�񕬎�(�����̂�) */
    f4 f4_eainjdn[6];                 /* unit=BTDC :����n��ڕ��ˊJ�n�����i���ˉ񐔔z��j */ /* �n�����ɍő�6�񕬎�(�����̂�) */
#endif /* JEEFI */
#if JEEFI == u1g_EJCC_PORT            /*�y�߰āz*/
    s2 s2_eainjpadd;                  /* lsb=1024/128/256,unit=BTDC :�|�[�g�ǉ����ˊJ�n���� */
#endif /* JEEFI */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    s2 s2_eainjdadd;                  /* lsb=1024/128/256,unit=BTDC :�����ǉ����ˊJ�n���� */
#endif /* JEEFI */
#if JEEFI != u1g_EJCC_D4              /*�yD-4�ȊO�z*/
    s4 s4_eqinjstpn[5];               /* lsb=(4096*1024)/128/256/256/256,unit=mg/st :�|�[�gn��ڎn�������˗ʁi���ˉ񐔔z��j */ /* 2025�N��5�񕬎˂܂ōl�����z��v�f��[5]�Ƃ��Ē�`���� */
    f4 f4_eqinjstpn[5];               /* unit=mg/st :�|�[�gn��ڎn�������˗ʁi���ˉ񐔔z��j */ /* 2025�N��5�񕬎˂܂ōl�����z��v�f��[5]�Ƃ��Ē�`���� */
#endif /* JEEFI */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    s4 s4_eqinjstdn[6];               /* lsb=(4096*1024)/128/256/256/256,unit=mg/st :����n��ڎn�������˗ʁi���ˉ񐔔z��j */ /* �n�����ɍő�6�񕬎�(�����̂�) */
    f4 f4_eqinjstdn[6];               /* unit=mg/st :����n��ڎn�������˗ʁi���ˉ񐔔z��j */ /* �n�����ɍő�6�񕬎�(�����̂�) */
#endif /* JEEFI */
    s4 s4_eqfc[u1g_EJCC_NCYL];        /* lsb=(4096*1024)/128/256/256/256,unit=mg/st :FC�����˗� */
    f4 f4_eqfc[u1g_EJCC_NCYL];        /* unit=mg/st :FC�����˗� */
    s2 s2_ek1fn[u1g_EJCC_NOX];        /* lsb=(1*4)/128/256,unit=�{ :1��ڕ��˗ʎZ�o�W��(�o���N��) */
    f4 f4_ek1fn[u1g_EJCC_NOX];        /* unit=�{ :1��ڕ��˗ʎZ�o�W��(�o���N��) */
    s2 s2_ek2fn[u1g_EJCC_NOX];        /* lsb=(1*4)/128/256,unit=�{ :2��ڕ��˗ʎZ�o�W��(�o���N��) */
    f4 f4_ek2fn[u1g_EJCC_NOX];        /* unit=�{ :2��ڕ��˗ʎZ�o�W��(�o���N��) */
    s2 s2_ek3fn[u1g_EJCC_NOX];        /* lsb=(1*4)/128/256,unit=�{ :3��ڕ��˗ʎZ�o�W��(�o���N��) */
    f4 f4_ek3fn[u1g_EJCC_NOX];        /* unit=�{ :3��ڕ��˗ʎZ�o�W��(�o���N��) */
    s2 s2_ekrchref[u1g_EJCC_NOX];     /* lsb=(32*2)/128/256,unit=�{ :���˗ʕ␳�W��(�o���N��) */
    f4 f4_ekrchref[u1g_EJCC_NOX];     /* unit=�{ :���˗ʕ␳�W��(�o���N��) */
    u1 bi_exqinjast :1;               /* lsb=1 :�n���㕬�˗ʗv���t���O */
    u1 bi_dummy     :7;               /* �_�~�[ */
    u1 u1_exqinjast;                  /* lsb=1 :�n���㕬�˗ʗv���t���O */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    u1 u1_explreq;                    /* lsb=1 :PL���ˎ��{�v�� */
#endif /* JEEFI */
#if JEEFI == u1g_EJCC_DUAL            /*�y�ޭ��INJ�z*/
    s2 s2_ekpfit;                     /* lsb=(1*4)/128/256,unit=�{ :�ڕW�߰ĕ��˗ʎZ�o�W��(��ݸ�ԕ��ϒl(²ݾݻ)) */
    f4 f4_ekpfit;                     /* unit=�{ :�ڕW�߰ĕ��˗ʎZ�o�W��(��ݸ�ԕ��ϒl(²ݾݻ)) */
    s2 s2_ekpfitn[u1g_EJCC_NOX];      /* lsb=(1*4)/128/256,unit=�{ :�ڕW�߰ĕ��˗ʎZ�o�W��(��ݸ��) */
    f4 f4_ekpfitn[u1g_EJCC_NOX];      /* unit=�{ :�ڕW�߰ĕ��˗ʎZ�o�W��(��ݸ��) */
#endif /* JEEFI */
#if JEEFI != u1g_EJCC_D4              /*�yD-4�ȊO�z*/
    s2 s2_ek1fpt;                     /* lsb=(1*4)/128/256,unit=�{ :�߰ĕ��˂̂ݗv�����̖ڕW�߰�1��ڕ��˗ʎZ�o�W�� */
    f4 f4_ek1fpt;                     /* unit=�{ :�߰ĕ��˂̂ݗv�����̖ڕW�߰�1��ڕ��˗ʎZ�o�W�� */
#endif /* JEEFI */
#if JEEFI == u1g_EJCC_DUAL            /*�y�ޭ��INJ�z*/
 #if JEEGR == u1g_EJCC_USE            /*�yEGR����L�z*/
    f4 f4_ekpfiegr;                   /* unit=�{ :EGR-ON���̖ڕW�߰ĕ��˗ʎZ�o�W��(��ݸ�ԕ��ϒl(²ݾݻ)) */
    f4 f4_ekpfiegrn[u1g_EJCC_NOX];    /* unit=�{ :EGR-ON���̖ڕW�߰ĕ��˗ʎZ�o�W��(��ݸ��) */
 #endif /* JEEGR */
#endif /* JEEFI */
#if JEEFI != u1g_EJCC_D4              /*�yD-4�ȊO�z*/
    s2 s2_eainjcutp;                  /* lsb=1024/128/256,unit=BTDC :�߰ĕ��ˋ�����Ď��� */
    f4 f4_eainjcutp;                  /* unit=BTDC :�߰ĕ��ˋ�����Ď��� */
#endif /* JEEFI */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*�y�ޭ��INJ�zOR�yD-4�z*/
    s2 s2_eainjcutd;                  /* lsb=1024/128/256,unit=BTDC :�������ˋ�����Ď��� */
    f4 f4_eainjcutd;                  /* unit=BTDC :�������ˋ�����Ď��� */
#endif /* JEEFI */
#if JECOMBCCPT_E == u1g_EJCC_SPRAYG_E /*�y���ڰ�޲�ށz*/
    s4 s4_eqinjexp;                   /* lsb=(4096*1024)/128/256/256/256,unit=mg/st :�c���s�����˗� */
    f4 f4_eqinjexp;                   /* unit=mg/st :�c���s�����˗� */
#endif /* JECOMBCCPT_E */
    s4 s4_eqinjflfix[8];              /* lsb=(4096*1024)/128/256/256/256,unit=mg/st :FL�Œ蕬�˗� */
    f4 f4_eqinjflfix[8];              /* unit=mg/st :FL�Œ蕬�˗� */
    s4 s4_eqinjplfix[8];              /* lsb=(4096*1024)/128/256/256/256,unit=mg/st :PL�Œ蕬�˗� */
    f4 f4_eqinjplfix[8];              /* unit=mg/st :PL�Œ蕬�˗� */
} st_EMINJ_EMINJ;

/*-------------------------------------------------------------------*/
/* �t���[�|�[�g�p�w�b�_�t�@�C���̃C���N���[�h                        */
/*-------------------------------------------------------------------*/
#include <engsrc/eactmedi/einj/eminj_c.h>

/*-------------------------------------------------------------------*/
/* �R���p�C��SW����`�`�F�b�N                                        */
/*-------------------------------------------------------------------*/
#if !defined EMINJ_STAHV_MEDI
#error "EMINJ_STAHV_MEDI is undeclared"
#endif

#if !defined EMINJ_FCFRCTRL_MEDI
#error "EMINJ_FCFRCTRL_MEDI is undeclared"
#endif

#if !defined EMINJ_STACM_MEDI
#error "EMINJ_STACM_MEDI is undeclared"
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
/* �}�N����`                                                        */
/*-------------------------------------------------------------------*/
/* $$$�}�N���萔_�W��_v4.11 */

#if (JEEFI == u1g_EJCC_D4)                                              /* �yD-4�z */
#define u4g_EMINJ_INJPTN_VD ((u4)(0x30000000U))                         /* m=eminj,lsb=,ofs=,unit= :��������ݖ����l */

#else                                                                   /* �yD-4�ȊO�z */
#define u4g_EMINJ_INJPTN_VD ((u4)(0x10000000U))                         /* m=eminj,lsb=,ofs=,unit= :��������ݖ����l */
#endif                                                                  /* JEEFI */

#define u1g_EMINJ_PRINORQ ((u1)(((0.)/(1.))+0.5))                       /* m=eminj,lsb=1,ofs=,unit=- :�D��v����������l */
#define u1g_EMINJ_NONE_ID ((u1)(((0.)/(1.))+0.5))                       /* m=eminj,lsb=1,ofs=,unit=- :���ː���̗D�撲��v������ID */

#if (JEMAT_BENCHI == u1g_EJCC_USE) || (JEMAT_BENCH_E == u1g_EJCC_USE)   /* �y�����K���p��ėL�zOR�y�����K��Ӱ�ޗL�z */
#define u1g_EMINJ_BENCH_ID ((u1)(((2.)/(1.))+0.5))                      /* m=eminj,lsb=1,ofs=,unit=- :�����K���p���˗v��(ID) */
#endif                                                                  /* JEMAT_BENCHI JEMAT_BENCH_E */

#define u1g_EMINJ_EGSTPVS_ID ((u1)(((4.)/(1.))+0.5))                    /* m=eminj,lsb=1,ofs=,unit=- :���˒�~(ID) */

#if JEEFI == u1g_EJCC_DUAL                                              /* �y�ޭ��INJ�z */
#define u1g_EMINJ_DEFLAIR_ID ((u1)(((6.)/(1.))+0.5))                    /* m=eminj,lsb=1,ofs=,unit=- :�H�괱��������(ID) */
#endif                                                                  /* JEEFI */

#if (JEEGMG_E == u1g_EJCC_HVPLGR_E) || (JEEGMG_E == u1g_EJCC_HVDIRECT_E)    /* �yEG-MG�V���ޱ�zOR�yEG-MG�����z */
#define u1g_EMINJ_STPHV_ID ((u1)(((12.)/(1.))+0.5))                     /* m=eminj,lsb=1,ofs=,unit=- :HV��~����(ID) */
#endif                                                                  /* JEEGMG_E */

#if (JESS == u1g_EJCC_USE) || (JEEGMG_E == u1g_EJCC_HVCLUTCH_E)         /* �ySS����L�zOR�yEG-MG�ׯ��z */
#define u1g_EMINJ_STPSS_ID ((u1)(((14.)/(1.))+0.5))                     /* m=eminj,lsb=1,ofs=,unit=- :SS��~����(ID) */
#endif                                                                  /* JESS JEEGMG_E */

#define u1g_EMINJ_RDNVES_ID ((u1)(((16.)/(1.))+0.5))                    /* m=eminj,lsb=1,ofs=,unit=- :�ݼ�ݒ�~�E�n�����̐U���ጸ����(ID) */

#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)                  /* �y�ޭ��INJ�zOR�yD-4�z */
#define u1g_EMINJ_SJC_ID ((u1)(((20.)/(1.))+0.5))                       /* m=eminj,lsb=1,ofs=,unit=- :�G�}�}���g�@����(ID) */
#endif                                                                  /* JEEFI */

#if (JEALLHV_E == u1g_EJCC_ALLHV_E) && (JEPLMLT_E == u1g_EJCC_USE) && (EMINJ_BINJPLCTR_WC_MEDI == ON)   /* �yALL HV�zAND�yPL������˗L�zAND�y�߰�����ĕ��˂�p������{���ː���(�G�}�g�@��)�v���g�p�z */
#define u1g_EMINJ_BINJPLCTR_WC_ID ((u1)(((22.)/(1.))+0.5))              /* m=eminj,lsb=1,ofs=,unit=- :�߰�����ĕ��˂�p������{���ː���(�G�}�g�@��)(ID) */
#endif                                                                  /* JEALLHV_E JEPLMLT_E EMINJ_BINJPLCTR_WC_MEDI */

#if JEALLHV_E == u1g_EJCC_ALLHV_E                                       /* �yALL HV�z */
#define u1g_EMINJ_WUPCAT_ID ((u1)(((24.)/(1.))+0.5))                    /* m=eminj,lsb=1,ofs=,unit=- :�G�}�g�@����(ID) */
#endif                                                                  /* JEALLHV_E */

#if (JENGPF_E != u1g_EJCC_NOT_USE) && (EMINJ_FCFRCTRL_MEDI == ON)       /* �yGPF�L�zAND�y1�C��FC����v���g�p�z */
#define u1g_EMINJ_FCFRCTRL_ID ((u1)(((26.)/(1.))+0.5))                  /* m=eminj,lsb=1,ofs=,unit=- :1�C��FC����(ID) */
#endif                                                                  /* JENGPF_E EMINJ_FCFRCTRL_MEDI */

#if ((JERMTCTR == u1g_EJCC_USE) || (JENVCTR == u1g_EJCC_USE)) && (JEMICN_E != u1g_EJCC_SUB_E) && (EMINJ_STACM_MEDI == ON)   /* (�y�Ӱĺ��۰ٗL�zOR�y��޺��۰ٗL�z)AND�ySUB-CPU�ȊO�zAND�y�n���������オ�萧��v���g�p�z */
#define u1g_EMINJ_STACM_ID ((u1)(((28.)/(1.))+0.5))                     /* m=eminj,lsb=1,ofs=,unit=- :�n���������オ�萧��(ID) */
#endif                                                                  /* JERMTCTR JENVCTR JEMICN_E EMINJ_STACM_MEDI */

#if (JESS == u1g_EJCC_USE) || (JEEGMG_E == u1g_EJCC_HVCLUTCH_E)         /* �ySS����L�zOR�yEG-MG�ׯ��z */
#define u1g_EMINJ_STASS_ID ((u1)(((30.)/(1.))+0.5))                     /* m=eminj,lsb=1,ofs=,unit=- :SS�n������(ID) */
#endif                                                                  /* JESS JEEGMG_E */

#if (JEALLHV_E == u1g_EJCC_ALLHV_E) && (JEEFI == u1g_EJCC_PORT)         /* �yALL HV�zAND�y�߰āz */
#define u1g_EMINJ_RDPN_ST_ID ((u1)(((36.)/(1.))+0.5))                   /* m=eminj,lsb=1,ofs=,unit=- :PN�ጸ����(�n����)(ID) */
#endif                                                                  /* JEALLHV_E JEEFI */

#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)                  /* �y�ޭ��INJ�zOR�yD-4�z */
#define u1g_EMINJ_STRATIST_ID ((u1)(((42.)/(1.))+0.5))                  /* m=eminj,lsb=1,ofs=,unit=- :���w�n������(ID) */
#endif                                                                  /* JEEFI */

#if JEEFI == u1g_EJCC_DUAL                                              /* �y�ޭ��INJ�z */
#define u1g_EMINJ_STAFRG_ID ((u1)(((44.)/(1.))+0.5))                    /* m=eminj,lsb=1,ofs=,unit=- :�ɒቷ�n������(ID) */
#endif                                                                  /* JEEFI */

#if (JEALLHV_E == u1g_EJCC_ALLHV_E) && (EMINJ_STAHV_MEDI == ON)         /* �yALL HV�zAND�yHV�n������v���g�p�z */
#define u1g_EMINJ_STAHV_ID ((u1)(((46.)/(1.))+0.5))                     /* m=eminj,lsb=1,ofs=,unit=- :HV�n������(ID) */
#endif                                                                  /* JEALLHV_E EMINJ_STAHV_MEDI */

#if (JEEGMG_E == u1g_EJCC_HVPLGR_E) && (JEFFV == u1g_EJCC_NOT_USE) && (JEPLMLT_E == u1g_EJCC_USE) && (EMINJ_BINJPLCTR_STAHV_MEDI == ON) /* �yEG-MG�V���ޱ�zAND�yFFV���䖳�zAND�yPL������˗L�zAND�y�߰�����ĕ��˂�p������{���ː���(HV�n�����䎞)�v���g�p�z */
#define u1g_EMINJ_BINJPLCTR_STAHV_ID ((u1)(((48.)/(1.))+0.5))           /* m=eminj,lsb=1,ofs=,unit=- :�߰�����ĕ��˂�p������{���ː���(HV�n�����䎞)(ID) */
#endif                                                                  /* JEEGMG_E JEFFV JEPLMLT_E EMINJ_BINJPLCTR_STAHV_MEDI */

#define u1g_EMINJ_FCINJCTR_ID ((u1)(((50.)/(1.))+0.5))                  /* m=eminj,lsb=1,ofs=,unit=- :FC���R�����ː���(ID) */

#if (JEALLHV_E == u1g_EJCC_ALLHV_E) && (JEEFI != u1g_EJCC_D4)           /* �yALL HV�zAND�yD-4�ȊO�z */
#define u1g_EMINJ_RDPN_ID ((u1)(((52.)/(1.))+0.5))                      /* m=eminj,lsb=1,ofs=,unit=- :PN�ጸ����(ID) */
#endif                                                                  /* JEALLHV_E JEEFI */

#if JEEFI == u1g_EJCC_DUAL                                              /* �y�ޭ��INJ�z */
#define u1g_EMINJ_DTHRCTRL_ID ((u1)(((64.)/(1.))+0.5))                  /* m=eminj,lsb=1,ofs=,unit=- :�C�����ި�ސ���(ID) */
#endif                                                                  /* JEEFI */

#if ((JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)) && (EMINJ_ACTLFG_MEDI == ON)   /* (�y�ޭ��INJ�zOR�yD-4�z)AND�y�߰�����Ċw�K�ׂ̱̈�è�ސ���v���g�p�z */
#define u1g_EMINJ_ACTLFG_ID ((u1)(((66.)/(1.))+0.5))                    /* m=eminj,lsb=1,ofs=,unit=- :�߰�����Ċw�K�ׂ̱̈�è�ސ���(ID) */
#endif                                                                  /* JEEFI EMINJ_ACTLFG_MEDI */

#if JEEFI == u1g_EJCC_DUAL                                              /* �y�ޭ��INJ�z */
 #if EMINJ_ACTOBD_MEDI == ON                                            /* �y�ޭ��INJ�zAND�yOBD�v���ɂ�鱸è�ސ���v���g�p�z */
#define u1g_EMINJ_ACTOBD_ID ((u1)(((76.)/(1.))+0.5))                    /* m=eminj,lsb=1,ofs=,unit=- :OBD�v���ɂ�鱸è�ސ���(ID) */
 #endif                                                                 /* EMINJ_ACTOBD_MEDI */

#define u1g_EMINJ_ACTGAF_ID ((u1)(((84.)/(1.))+0.5))                    /* m=eminj,lsb=1,ofs=,unit=- :A/F�w�K�ׂ̱̈�è�ސ���(ID) */

 #if (JEOBDAFIMB_D == u1g_EJCC_USE) && (EMINJ_IMBRQ_MEDI == ON)         /* �yAF�C���Բ����ݽ�L�zAND�y�ޭ��INJ�zAND�y�����ݽOBD�v���ɂ�鱸è�ސ���v���g�p�z */
#define u1g_EMINJ_IMBRQ_ID ((u1)(((78.)/(1.))+0.5))                     /* m=eminj,lsb=1,ofs=,unit=- :�����ݽOBD�v���ɂ�鱸è�ސ���(ID) */
 #endif                                                                 /* JEOBDAFIMB_D EMINJ_IMBRQ_MEDI */

 #if (JEOBDMF == u1g_EJCC_USE) && (EMINJ_MFINJRQ_MEDI == ON)            /* �y����OBD�L�zAND�y�ޭ��INJ�zAND�y����OBD�v���ɂ�鱸è�ސ���v���g�p�z */
#define u1g_EMINJ_MFINJRQ_ID ((u1)(((80.)/(1.))+0.5))                   /* m=eminj,lsb=1,ofs=,unit=- :����OBD�v���ɂ�鱸è�ސ���(ID) */
 #endif                                                                 /* JEOBDMF EMINJ_MFINJRQ_MEDI */

 #if (JEOBDFKG == u1g_EJCC_USE) && (EMINJ_FKGDRQ_MEDI == ON)            /* �y�R��OBD�L�zAND�y�ޭ��INJ�zAND�y�R���nOBD�v���ɂ�鱸è�ސ���v���g�p�z */
#define u1g_EMINJ_FKGDRQ_ID ((u1)(((82.)/(1.))+0.5))                    /* m=eminj,lsb=1,ofs=,unit=- :�R���nOBD�v���ɂ�鱸è�ސ���(ID) */
 #endif                                                                 /* JEOBDFKG EMINJ_FKGDRQ_MEDI */
#endif                                                                  /* JEEFI */

#if (JEPLMLT_E == u1g_EJCC_USE) && (EMINJ_BINJPLCTR_MEDI == ON)         /* �yPL������˗L�zAND�y�߰�����ĕ��˂�p������{���ː���v���g�p�z */
#define u1g_EMINJ_BINJPLCTR_ID ((u1)(((98.)/(1.))+0.5))                 /* m=eminj,lsb=1,ofs=,unit=- :�߰�����ĕ��˂�p������{���ː���(ID) */
#endif                                                                  /* JEPLMLT_E EMINJ_BINJPLCTR_MEDI */

#if EMINJ_FREE0 == ON                                                   /* �y�ذ�߰�0�g�p�z */
#define u1g_EMINJ_FREE0_ID ((u1)(((200.)/(1.))+0.5))                    /* m=eminj,lsb=1,ofs=,unit=- :�ذ�߰�0�p����(ID) */
#endif                                                                  /* EMINJ_FREE0 */

#if EMINJ_FREE1 == ON                                                   /* �y�ذ�߰�1�g�p�z */
#define u1g_EMINJ_FREE1_ID ((u1)(((201.)/(1.))+0.5))                    /* m=eminj,lsb=1,ofs=,unit=- :�ذ�߰�1�p����(ID) */
#endif                                                                  /* EMINJ_FREE1 */

#if EMINJ_FREE2 == ON                                                   /* �y�ذ�߰�2�g�p�z */
#define u1g_EMINJ_FREE2_ID ((u1)(((202.)/(1.))+0.5))                    /* m=eminj,lsb=1,ofs=,unit=- :�ذ�߰�2�p����(ID) */
#endif                                                                  /* EMINJ_FREE2 */

#if EMINJ_FREE3 == ON                                                   /* �y�ذ�߰�3�g�p�z */
#define u1g_EMINJ_FREE3_ID ((u1)(((203.)/(1.))+0.5))                    /* m=eminj,lsb=1,ofs=,unit=- :�ذ�߰�3�p����(ID) */
#endif                                                                  /* EMINJ_FREE3 */

#if EMINJ_FREE4 == ON                                                   /* �y�ذ�߰�4�g�p�z */
#define u1g_EMINJ_FREE4_ID ((u1)(((204.)/(1.))+0.5))                    /* m=eminj,lsb=1,ofs=,unit=- :�ذ�߰�4�p����(ID) */
#endif                                                                  /* EMINJ_FREE4 */

#if EMINJ_FREE5 == ON                                                   /* �y�ذ�߰�5�g�p�z */
#define u1g_EMINJ_FREE5_ID ((u1)(((205.)/(1.))+0.5))                    /* m=eminj,lsb=1,ofs=,unit=- :�ذ�߰�5�p����(ID) */
#endif                                                                  /* EMINJ_FREE5 */

#if EMINJ_FREE6 == ON                                                   /* �y�ذ�߰�6�g�p�z */
#define u1g_EMINJ_FREE6_ID ((u1)(((206.)/(1.))+0.5))                    /* m=eminj,lsb=1,ofs=,unit=- :�ذ�߰�6�p����(ID) */
#endif                                                                  /* EMINJ_FREE6 */

#if EMINJ_FREE7 == ON                                                   /* �y�ذ�߰�7�g�p�z */
#define u1g_EMINJ_FREE7_ID ((u1)(((207.)/(1.))+0.5))                    /* m=eminj,lsb=1,ofs=,unit=- :�ذ�߰�7�p����(ID) */
#endif                                                                  /* EMINJ_FREE7 */

#if EMINJ_FREE8 == ON                                                   /* �y�ذ�߰�8�g�p�z */
#define u1g_EMINJ_FREE8_ID ((u1)(((208.)/(1.))+0.5))                    /* m=eminj,lsb=1,ofs=,unit=- :�ذ�߰�8�p����(ID) */
#endif                                                                  /* EMINJ_FREE8 */

#if EMINJ_FREE9 == ON                                                   /* �y�ذ�߰�9�g�p�z */
#define u1g_EMINJ_FREE9_ID ((u1)(((209.)/(1.))+0.5))                    /* m=eminj,lsb=1,ofs=,unit=- :�ذ�߰�9�p����(ID) */
#endif                                                                  /* EMINJ_FREE9 */

#if EMINJ_FREE10 == ON                                                  /* �y�ذ�߰�10�g�p�z */
#define u1g_EMINJ_FREE10_ID ((u1)(((210.)/(1.))+0.5))                   /* m=eminj,lsb=1,ofs=,unit=- :�ذ�߰�10�p����(ID) */
#endif                                                                  /* EMINJ_FREE10 */

#if EMINJ_FREE11 == ON                                                  /* �y�ذ�߰�11�g�p�z */
#define u1g_EMINJ_FREE11_ID ((u1)(((211.)/(1.))+0.5))                   /* m=eminj,lsb=1,ofs=,unit=- :�ذ�߰�11�p����(ID) */
#endif                                                                  /* EMINJ_FREE11 */

#define u4g_EMINJ_RQID_VD ((u4)(0x00000000U))                           /* m=eminj,lsb=,ofs=,unit= :�v���L���ʎq�����l */
#define u4g_EMINJ_RQINJMODE ((u4)(0x00000001U))                         /* m=eminj,lsb=,ofs=,unit= :����Ӱ�ޗv���L */
#define u4g_EMINJ_RQINJPTN ((u4)(0x00000002U))                          /* m=eminj,lsb=,ofs=,unit= :��������ݗv���L */
#define u4g_EMINJ_RQAINJP1 ((u4)(0x00000002U))                          /* m=eminj,lsb=,ofs=,unit= :�߰�1��ڕ��ˊJ�n�����v���L */
#define u4g_EMINJ_RQAINJPN ((u4)(0x00000004U))                          /* m=eminj,lsb=,ofs=,unit= :�߰�n��ڕ��ˊJ�n�����v���L�i���˖��j */
#define u4g_EMINJ_RQAINJP2 ((u4)(0x00000004U))                          /* m=eminj,lsb=,ofs=,unit= :�߰�2��ڕ��ˊJ�n�����v���L */
#define u4g_EMINJ_RQAINJDN ((u4)(0x00000008U))                          /* m=eminj,lsb=,ofs=,unit= :����n��ڕ��ˊJ�n�����v���L�i���˖��j */
#define u4g_EMINJ_RQAINJP3 ((u4)(0x00000008U))                          /* m=eminj,lsb=,ofs=,unit= :�߰�3��ڕ��ˊJ�n�����v���L */
#define u4g_EMINJ_RQAINJP4 ((u4)(0x00000010U))                          /* m=eminj,lsb=,ofs=,unit= :�߰�4��ڕ��ˊJ�n�����v���L */
#define u4g_EMINJ_RQINJEND ((u4)(0x00000020U))                          /* m=eminj,lsb=,ofs=,unit= :�߰ĕ��ˏI�������v���L */
#define u4g_EMINJ_RQAINJCUTP ((u4)(0x00000040U))                        /* m=eminj,lsb=,ofs=,unit= :�߰ĕ��ˋ�����Ď����v�� */
#define u4g_EMINJ_RQAINJCUTD ((u4)(0x00000080U))                        /* m=eminj,lsb=,ofs=,unit= :�������ˋ�����Ď����v�� */
#define u4g_EMINJ_RQAINJD1 ((u4)(0x00000100U))                          /* m=eminj,lsb=,ofs=,unit= :����1��ڕ��ˊJ�n�����v���L */
#define u4g_EMINJ_RQAINJD2 ((u4)(0x00000200U))                          /* m=eminj,lsb=,ofs=,unit= :����2��ڕ��ˊJ�n�����v���L */
#define u4g_EMINJ_RQAINJD3 ((u4)(0x00000008U))                          /* m=eminj,lsb=,ofs=,unit= :����3��ڕ��ˊJ�n�����v���L */
#define u4g_EMINJ_RQAINJD4 ((u4)(0x00000010U))                          /* m=eminj,lsb=,ofs=,unit= :����4��ڕ��ˊJ�n�����v���L */
#define u4g_EMINJ_RQQINJSTPN ((u4)(0x00000400U))                        /* m=eminj,lsb=,ofs=,unit= :�߰�n��ڎn�������˗ʗv���L�i���˖��j */
#define u4g_EMINJ_RQQINJSTP1 ((u4)(0x00000400U))                        /* m=eminj,lsb=,ofs=,unit= :�߰�1��ڎn�������˗ʗv���L */
#define u4g_EMINJ_RQQINJSTDN ((u4)(0x00000800U))                        /* m=eminj,lsb=,ofs=,unit= :����n��ڎn�������˗ʗv���L�i���˖��j */
#define u4g_EMINJ_RQQINJSTP2 ((u4)(0x00000800U))                        /* m=eminj,lsb=,ofs=,unit= :�߰�2��ڎn�������˗ʗv���L */
#define u4g_EMINJ_RQQINJFLFIX ((u4)(0x00001000U))                       /* m=eminj,lsb=,ofs=,unit= :FL�Œ蕬�˗ʗv���L�i���˖��j */
#define u4g_EMINJ_RQQINJSTP3 ((u4)(0x00001000U))                        /* m=eminj,lsb=,ofs=,unit= :�߰�3��ڎn�������˗ʗv���L */
#define u4g_EMINJ_RQQINJPLFIX ((u4)(0x00002000U))                       /* m=eminj,lsb=,ofs=,unit= :PL�Œ蕬�˗ʗv���L�i���˖��j */
#define u4g_EMINJ_RQQINJSTP4 ((u4)(0x00002000U))                        /* m=eminj,lsb=,ofs=,unit= :�߰�4��ڎn�������˗ʗv���L */
#define u4g_EMINJ_RQQINJSTD1 ((u4)(0x00004000U))                        /* m=eminj,lsb=,ofs=,unit= :����1��ڎn�������˗ʗv���L */
#define u4g_EMINJ_RQQINJSTD2 ((u4)(0x00008000U))                        /* m=eminj,lsb=,ofs=,unit= :����2��ڎn�������˗ʗv���L */
#define u4g_EMINJ_RQQINJSTD3 ((u4)(0x00001000U))                        /* m=eminj,lsb=,ofs=,unit= :����3��ڎn�������˗ʗv���L */
#define u4g_EMINJ_RQQINJSTD4 ((u4)(0x00002000U))                        /* m=eminj,lsb=,ofs=,unit= :����4��ڎn�������˗ʗv���L */
#define u4g_EMINJ_RQQFC ((u4)(0x00010000U))                             /* m=eminj,lsb=,ofs=,unit= :FC�����˗ʗv���L */
#define u4g_EMINJ_RQQINJEXP ((u4)(0x00020000U))                         /* m=eminj,lsb=,ofs=,unit= :�c���s�����˗ʗv���L */
#define u4g_EMINJ_RQK1FN ((u4)(0x00040000U))                            /* m=eminj,lsb=,ofs=,unit= :1��ڕ��˗ʎZ�o�W���v���L(��ݸ��) */
#define u4g_EMINJ_RQK2FN ((u4)(0x00080000U))                            /* m=eminj,lsb=,ofs=,unit= :2��ڕ��˗ʎZ�o�W���v���L(��ݸ��) */
#define u4g_EMINJ_RQK3FN ((u4)(0x00100000U))                            /* m=eminj,lsb=,ofs=,unit= :3��ڕ��˗ʎZ�o�W���v���L(��ݸ��) */
#define u4g_EMINJ_RQK1F ((u4)(0x00200000U))                             /* m=eminj,lsb=,ofs=,unit= :1��ڕ��˗ʎZ�o�W���v���L */
#define u4g_EMINJ_RQK2F ((u4)(0x00400000U))                             /* m=eminj,lsb=,ofs=,unit= :2��ڕ��˗ʎZ�o�W���v���L */
#define u4g_EMINJ_RQK3F ((u4)(0x00800000U))                             /* m=eminj,lsb=,ofs=,unit= :3��ڕ��˗ʎZ�o�W���v���L */
#define u4g_EMINJ_RQPRREQ ((u4)(0x01000000U))                           /* m=eminj,lsb=,ofs=,unit= :��������ߖڕW�R���v���L */
#define u4g_EMINJ_RQQFREQ ((u4)(0x02000000U))                           /* m=eminj,lsb=,ofs=,unit= :�R������ߓf�o�ʗv���L */
#define u4g_EMINJ_RQPRREQL ((u4)(0x04000000U))                          /* m=eminj,lsb=,ofs=,unit= :�ሳ����ߖڕW�R���v���L */
#define u4g_EMINJ_RQXQINJAST ((u4)(0x08000000U))                        /* m=eminj,lsb=,ofs=,unit= :�n���㕬�˗ʗv���׸ޗv���L */
#define u4g_EMINJ_RQKRCHREF ((u4)(0x10000000U))                         /* m=eminj,lsb=,ofs=,unit= :���˗ʕ␳�W���v���L */
#define u4g_EMINJ_RQPLREQ ((u4)(0x20000000U))                           /* m=eminj,lsb=,ofs=,unit= :PL���ˎ��{�v���L */
#define u4g_EMINJ_RQAINJP ((u4)(0x40000000U))                           /* m=eminj,lsb=,ofs=,unit= :�߰ĕ��ˊJ�n�����v���L */
#define u4g_EMINJ_RQQINJSTP ((u4)(0x80000000U))                         /* m=eminj,lsb=,ofs=,unit= :�߰Ďn�������˗ʗv���L */

#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)                  /* �y�ޭ��INJ�zOR�yD-4�z */
#define u2g_EMINJ_MOD0N1 ((u2)(0x0081U))                                /* m=eminj,lsb=,ofs=,unit= :��������N��(����v��) */
#endif                                                                  /* JEEFI */

#define u2g_EMINJ_MOD002 ((u2)(0x0002U))                                /* m=eminj,lsb=,ofs=,unit= :�������ˁi�G�}�}���g�@�j */
#define u2g_EMINJ_MOD003 ((u2)(0x0003U))                                /* m=eminj,lsb=,ofs=,unit= :�������ˁi���w�n���j */
#define u2g_EMINJ_MOD004 ((u2)(0x0004U))                                /* m=eminj,lsb=,ofs=,unit= :�R�Č��㐬�w�R�Đ��� */
#define u2g_EMINJ_MOD005 ((u2)(0x0005U))                                /* m=eminj,lsb=,ofs=,unit= :�������ˁi�G�}�}���g�@�F�c���s�����ˁj */
#define u2g_EMINJ_MOD006 ((u2)(0x0006U))                                /* m=eminj,lsb=,ofs=,unit= :�������ˁi���w�n���F�c���s�����ˁj */
#define u2g_EMINJ_MOD007 ((u2)(0x0007U))                                /* m=eminj,lsb=,ofs=,unit= :�C�ӌŒ�������� */
/* $$$�}�N���萔_�W��_v4.11 */

/*-------------------------------------------------------------------*/
/* �֐�                                                              */
/*-------------------------------------------------------------------*/
void vdg_eminj_pwon( void );            /* �����l�ݒ� */
                                        /* �R�[���� : vdg_elmng_pwon() */
                                        /* ���O������ : vdg_emprlp_pwon()�y�ϔR������L�z*/
                                        /*            : vdg_ebinjctr_pwon_seq()�yD-4�ȊO�z*/

void vdg_eminj_8msm( void );            /* ���˗v���̒��⏈�� */
                                        /* �R�[���� : vdg_elmng_8msm() */

void vdg_eminj_einj_dataget( st_EMINJ_EINJ *ptt_retval );   /* ���ˏ��擾�����i�\����1�j */
                                                            /* �R�[���� :����SAC�AAPL */
                                                            /* ���� ptt_retval :���ˏ��擾�o�b�t�@�i�\����1�j�̃A�h���X */

void vdg_eminj_eminj_dataget( st_EMINJ_EMINJ *ptt_retval ); /* ���ˏ��擾�����i�\����2�j */
                                                            /* �R�[���� :����SAC�AAPL */
                                                            /* ���� ptt_retval :���ˏ��擾�o�b�t�@�i�\����2�j�̃A�h���X */

/*-------------------------------------------------------------------*/
/* ���J�ϐ�                                                          */
/*-------------------------------------------------------------------*/
extern st_EMINJ_EINJ stg_eminj_einj;                        /* ���˕�������\���� */
#define u2g_eminj_einjmod   (stg_eminj_einj.u2_einjmod)     /* m=eminj,lsb=1 :���˃��[�h */
                                                            /* �X�V�^�C�~���O �F pwon,8msm */

#define s2g_eminj_eainjp1   (stg_eminj_einj.s2_eainjp1)     /* m=eminj,lsb=1024/128/256,unit=BTDC :�|�[�g1��ڕ��ˊJ�n���� */
#define f4g_eminj_eainjp1   (stg_eminj_einj.f4_eainjp1)     /* m=eminj,unit=BTDC :�|�[�g1��ڕ��ˊJ�n���� */
                                                            /* �X�V�^�C�~���O �F pwon,8msm */
                                                            /* ���ӎ��� :�yD-4�ȊO�z*/

#define s2g_eminj_eainjp2   (stg_eminj_einj.s2_eainjp2)     /* m=eminj,lsb=1024/128/256,unit=BTDC :�|�[�g2��ڕ��ˊJ�n���� */
#define f4g_eminj_eainjp2   (stg_eminj_einj.f4_eainjp2)     /* m=eminj,unit=BTDC :�|�[�g2��ڕ��ˊJ�n���� */
                                                            /* �X�V�^�C�~���O �F pwon,8msm */
                                                            /* ���ӎ��� :�yD-4�ȊO�z*/

#define s2g_eminj_eainjp3   (stg_eminj_einj.s2_eainjp3)     /* m=eminj,lsb=1024/128/256,unit=BTDC :�|�[�g3��ڕ��ˊJ�n���� */
#define f4g_eminj_eainjp3   (stg_eminj_einj.f4_eainjp3)     /* m=eminj,unit=BTDC :�|�[�g3��ڕ��ˊJ�n���� */
                                                            /* �X�V�^�C�~���O �F pwon,8msm */
                                                            /* ���ӎ��� :�yD-4�ȊO�z*/

#define s2g_eminj_eainjp4   (stg_eminj_einj.s2_eainjp4)     /* m=eminj,lsb=1024/128/256,unit=BTDC :�|�[�g4��ڕ��ˊJ�n���� */
#define f4g_eminj_eainjp4   (stg_eminj_einj.f4_eainjp4)     /* m=eminj,unit=BTDC :�|�[�g4��ڕ��ˊJ�n���� */
                                                            /* �X�V�^�C�~���O �F pwon,8msm */
                                                            /* ���ӎ��� :�yD-4�ȊO�z*/

#define s2g_eminj_einjend   (stg_eminj_einj.s2_einjend)     /* m=eminj,lsb=1024/128/256,unit=BTDC :�|�[�g���ˏI������ */
extern f4 f4g_eminj_einjend;                                /* m=eminj,unit=BTDC :�|�[�g���ˏI������ */
                                                            /* �X�V�^�C�~���O �F pwon,8msm */
                                                            /* ���ӎ��� :�yD-4�ȊO�z*/
                                                            /*          : �]�����Q�Ƃ��Ă��镔�i�̃I�u�W�F�N�g���ς�邽��f4�^�ϐ��̓}�N����`�ւ̕ύX�֎~ */

#define s2g_eminj_eainjcutp (stg_eminj_einj.s2_eainjcutp)   /* m=eminj,lsb=1024/128/256,unit=BTDC :�߰ĕ��ˋ�����Ď��� */
#define f4g_eminj_eainjcutp (stg_eminj_einj.f4_eainjcutp)   /* m=eminj,unit=BTDC :�߰ĕ��ˋ�����Ď��� */
                                                            /* �X�V�^�C�~���O �F pwon,8msm */
                                                            /* ���ӎ��� :�yD-4�ȊO�z*/

#define s2g_eminj_eainjd1   (stg_eminj_einj.s2_eainjd1)     /* m=eminj,lsb=1024/128/256,unit=BTDC :����1��ڕ��ˊJ�n���� */
#define f4g_eminj_eainjd1   (stg_eminj_einj.f4_eainjd1)     /* m=eminj,unit=BTDC :����1��ڕ��ˊJ�n���� */
                                                            /* �X�V�^�C�~���O �F pwon,8msm */
                                                            /* ���ӎ��� :�y�ޭ��INJ�zOR�yD-4�z*/

#define s2g_eminj_eainjd2   (stg_eminj_einj.s2_eainjd2)     /* m=eminj,lsb=1024/128/256,unit=BTDC :����2��ڕ��ˊJ�n���� */
#define f4g_eminj_eainjd2   (stg_eminj_einj.f4_eainjd2)     /* m=eminj,unit=BTDC :����2��ڕ��ˊJ�n���� */
                                                            /* �X�V�^�C�~���O �F pwon,8msm */
                                                            /* ���ӎ��� :�y�ޭ��INJ�zOR�yD-4�z*/

#define s2g_eminj_eainjd3   (stg_eminj_einj.s2_eainjd3)     /* m=eminj,lsb=1024/128/256,unit=BTDC :����3��ڕ��ˊJ�n���� */
#define f4g_eminj_eainjd3   (stg_eminj_einj.f4_eainjd3)     /* m=eminj,unit=BTDC :����3��ڕ��ˊJ�n���� */
                                                            /* �X�V�^�C�~���O �F pwon,8msm */
                                                            /* ���ӎ��� :�y�ޭ��INJ�zOR�yD-4�z*/

#define s2g_eminj_eainjd4   (stg_eminj_einj.s2_eainjd4)     /* m=eminj,lsb=1024/128/256,unit=BTDC :����4��ڕ��ˊJ�n���� */
#define f4g_eminj_eainjd4   (stg_eminj_einj.f4_eainjd4)     /* m=eminj,unit=BTDC :����4��ڕ��ˊJ�n���� */
                                                            /* �X�V�^�C�~���O �F pwon,8msm */
                                                            /* ���ӎ��� :�y�ޭ��INJ�zOR�yD-4�z*/

#define s2g_eminj_eainjcutd (stg_eminj_einj.s2_eainjcutd)   /* m=eminj,lsb=1024/128/256,unit=BTDC :�������ˋ�����Ď��� */
#define f4g_eminj_eainjcutd (stg_eminj_einj.f4_eainjcutd)   /* m=eminj,unit=BTDC :�������ˋ�����Ď��� */
                                                            /* �X�V�^�C�~���O �F pwon,8msm */
                                                            /* ���ӎ��� :�y�ޭ��INJ�zOR�yD-4�z*/

#define s4g_eminj_eqinjstp1 (stg_eminj_einj.s4_eqinjstp1)   /* m=eminj,lsb=(4096*1024)/128/256/256/256,unit=mg/st :�|�[�g1��ڎn�������˗� */
#define f4g_eminj_eqinjstp1 (stg_eminj_einj.f4_eqinjstp1)   /* m=eminj,unit=mg/st :�|�[�g1��ڎn�������˗� */
                                                            /* �X�V�^�C�~���O �F pwon,8msm */
                                                            /* ���ӎ��� :�yD-4�ȊO�z*/

#define s4g_eminj_eqinjstp2 (stg_eminj_einj.s4_eqinjstp2)   /* m=eminj,lsb=(4096*1024)/128/256/256/256,unit=mg/st :�|�[�g2��ڎn�������˗� */
#define f4g_eminj_eqinjstp2 (stg_eminj_einj.f4_eqinjstp2)   /* m=eminj,unit=mg/st :�|�[�g2��ڎn�������˗� */
                                                            /* �X�V�^�C�~���O �F pwon,8msm */
                                                            /* ���ӎ��� :�yD-4�ȊO�z*/

#define s4g_eminj_eqinjstp3 (stg_eminj_einj.s4_eqinjstp3)   /* m=eminj,lsb=(4096*1024)/128/256/256/256,unit=mg/st :�|�[�g3��ڎn�������˗� */
#define f4g_eminj_eqinjstp3 (stg_eminj_einj.f4_eqinjstp3)   /* m=eminj,unit=mg/st :�|�[�g3��ڎn�������˗� */
                                                            /* �X�V�^�C�~���O �F pwon,8msm */
                                                            /* ���ӎ��� :�yD-4�ȊO�z*/

#define s4g_eminj_eqinjstp4 (stg_eminj_einj.s4_eqinjstp4)   /* m=eminj,lsb=(4096*1024)/128/256/256/256,unit=mg/st :�|�[�g4��ڎn�������˗� */
#define f4g_eminj_eqinjstp4 (stg_eminj_einj.f4_eqinjstp4)   /* m=eminj,unit=mg/st :�|�[�g4��ڎn�������˗� */
                                                            /* �X�V�^�C�~���O �F pwon,8msm */
                                                            /* ���ӎ��� :�yD-4�ȊO�z*/

#define s4g_eminj_eqinjstd1 (stg_eminj_einj.s4_eqinjstd1)   /* m=eminj,lsb=(4096*1024)/128/256/256/256,unit=mg/st :����1��ڎn�������˗� */
extern f4 f4g_eminj_eqinjstd1;                              /* m=eminj,unit=mg/st :����1��ڎn�������˗� */

                                                            /* �X�V�^�C�~���O �F pwon,8msm */
                                                            /* ���ӎ��� :�y�ޭ��INJ�zOR�yD-4�z*/
                                                            /*          : �]�����Q�Ƃ��Ă��镔�i�̃I�u�W�F�N�g���ς�邽��f4�^�ϐ��̓}�N����`�ւ̕ύX�֎~ */

#define s4g_eminj_eqinjstd2 (stg_eminj_einj.s4_eqinjstd2)   /* m=eminj,lsb=(4096*1024)/128/256/256/256,unit=mg/st :����2��ڎn�������˗� */
extern f4 f4g_eminj_eqinjstd2;                              /* m=eminj,unit=mg/st :����2��ڎn�������˗� */

                                                            /* �X�V�^�C�~���O �F pwon,8msm */
                                                            /* ���ӎ��� :�y�ޭ��INJ�zOR�yD-4�z*/
                                                            /*          : �]�����Q�Ƃ��Ă��镔�i�̃I�u�W�F�N�g���ς�邽��f4�^�ϐ��̓}�N����`�ւ̕ύX�֎~ */

#define s4g_eminj_eqinjstd3 (stg_eminj_einj.s4_eqinjstd3)   /* m=eminj,lsb=(4096*1024)/128/256/256/256,unit=mg/st :����3��ڎn�������˗� */
extern f4 f4g_eminj_eqinjstd3;                              /* m=eminj,unit=mg/st :����3��ڎn�������˗� */

                                                            /* �X�V�^�C�~���O �F pwon,8msm */
                                                            /* ���ӎ��� :�y�ޭ��INJ�zOR�yD-4�z*/
                                                            /*          : �]�����Q�Ƃ��Ă��镔�i�̃I�u�W�F�N�g���ς�邽��f4�^�ϐ��̓}�N����`�ւ̕ύX�֎~ */

#define s4g_eminj_eqinjstd4 (stg_eminj_einj.s4_eqinjstd4)   /* m=eminj,lsb=(4096*1024)/128/256/256/256,unit=mg/st :����4��ڎn�������˗� */
extern f4 f4g_eminj_eqinjstd4;                              /* m=eminj,unit=mg/st :����4��ڎn�������˗� */

                                                            /* �X�V�^�C�~���O �F pwon,8msm */
                                                            /* ���ӎ��� :�y�ޭ��INJ�zOR�yD-4�z*/
                                                            /*          : �]�����Q�Ƃ��Ă��镔�i�̃I�u�W�F�N�g���ς�邽��f4�^�ϐ��̓}�N����`�ւ̕ύX�֎~ */

extern s4 s4g_eminj_eqfc[u1g_EJCC_NCYL];                    /* m=eminj,lsb=(4096*1024)/128/256/256/256,unit=mg/st :FC�����˗� */
extern f4 f4g_eminj_eqfc[u1g_EJCC_NCYL];                    /* m=eminj,unit=mg/st :FC�����˗� */
                                                            /* �X�V�^�C�~���O �F pwon,8msm */

#define s4g_eminj_eqinjexp  (stg_eminj_einj.s4_eqinjexp)    /* m=eminj,lsb=(4096*1024)/128/256/256/256,unit=mg/st :�c���s�����˗� */
#define f4g_eminj_eqinjexp  (stg_eminj_einj.f4_eqinjexp)    /* m=eminj,unit=mg/st :�c���s�����˗� */
                                                            /* �X�V�^�C�~���O �F pwon,8msm */
                                                            /* ���ӎ��� :�y���ڰ�޲�ށz*/

#define s2g_eminj_ek1f      (stg_eminj_einj.s2_ek1f)        /* m=eminj,lsb=(1*4)/128/256,unit=�{ :1��ڕ��˗ʎZ�o�W��(�o���N�ԕ��ϒl(�c�C���Z���T)) */
#define f4g_eminj_ek1f      (stg_eminj_einj.f4_ek1f)        /* m=eminj,unit=�{ :1��ڕ��˗ʎZ�o�W��(�o���N�ԕ��ϒl(�c�C���Z���T)) */
                                                            /* �X�V�^�C�~���O �F pwon,8msm */

#define s2g_eminj_ek2f      (stg_eminj_einj.s2_ek2f)        /* m=eminj,lsb=(1*4)/128/256,unit=�{ :2��ڕ��˗ʎZ�o�W��(�o���N�ԕ��ϒl(�c�C���Z���T)) */
#define f4g_eminj_ek2f      (stg_eminj_einj.f4_ek2f)        /* m=eminj,unit=�{ :2��ڕ��˗ʎZ�o�W��(�o���N�ԕ��ϒl(�c�C���Z���T)) */
                                                            /* �X�V�^�C�~���O �F pwon,8msm */

#define s2g_eminj_ek3f      (stg_eminj_einj.s2_ek3f)        /* m=eminj,lsb=(1*4)/128/256,unit=�{ :3��ڕ��˗ʎZ�o�W��(�o���N�ԕ��ϒl(�c�C���Z���T)) */
#define f4g_eminj_ek3f      (stg_eminj_einj.f4_ek3f)        /* m=eminj,unit=�{ :3��ڕ��˗ʎZ�o�W��(�o���N�ԕ��ϒl(�c�C���Z���T)) */
                                                            /* �X�V�^�C�~���O �F pwon,8msm */

extern s2 s2g_eminj_ek1fn[u1g_EJCC_NOX];                    /* m=eminj,lsb=(1*4)/128/256,unit=�{ :1��ڕ��˗ʎZ�o�W��(�o���N��) */
extern f4 f4g_eminj_ek1fn[u1g_EJCC_NOX];                    /* m=eminj,unit=�{ :1��ڕ��˗ʎZ�o�W��(�o���N��) */
                                                            /* �X�V�^�C�~���O �F pwon,8msm */

extern s2 s2g_eminj_ek2fn[u1g_EJCC_NOX];                    /* m=eminj,lsb=(1*4)/128/256,unit=�{ :2��ڕ��˗ʎZ�o�W��(�o���N��) */
extern f4 f4g_eminj_ek2fn[u1g_EJCC_NOX];                    /* m=eminj,unit=�{ :2��ڕ��˗ʎZ�o�W��(�o���N��) */
                                                            /* �X�V�^�C�~���O �F pwon,8msm */

extern s2 s2g_eminj_ek3fn[u1g_EJCC_NOX];                    /* m=eminj,lsb=(1*4)/128/256,unit=�{ :3��ڕ��˗ʎZ�o�W��(�o���N��)  */
extern f4 f4g_eminj_ek3fn[u1g_EJCC_NOX];                    /* m=eminj,unit=�{ :3��ڕ��˗ʎZ�o�W��(�o���N��)  */
                                                            /* �X�V�^�C�~���O �F pwon,8msm */

extern f4 f4g_eminj_ek1ffix;                                /* m=eminj,unit=�{ :�m��1��ڕ��˗ʎZ�o�W��(��ݸ�ԕ��ϒl(²ݾݻ)) */
                                                            /* �X�V�^�C�~���O �F 8msm */

extern f4 f4g_eminj_ek2ffix;                                /* m=eminj,unit=�{ :�m��2��ڕ��˗ʎZ�o�W��(��ݸ�ԕ��ϒl(²ݾݻ)) */
                                                            /* �X�V�^�C�~���O �F 8msm */

extern f4 f4g_eminj_ek3ffix;                                /* m=eminj,unit=�{ :�m��3��ڕ��˗ʎZ�o�W��(��ݸ�ԕ��ϒl(²ݾݻ)) */
                                                            /* �X�V�^�C�~���O �F 8msm */

#define big_eminj_exqinjast (stg_eminj_einj.bi_exqinjast)   /* m=eminj,lsb=1 :�n���㕬�˗ʗv���t���O */
#define u1g_eminj_exqinjast ((u1)stg_eminj_einj.bi_exqinjast)   /* m=eminj,lsb=1 :�n���㕬�˗ʗv���t���O */
                                                            /* �X�V�^�C�~���O : pwon,8msm */
                                                            /* ���ӎ��� : ON = �n���㕬�˗ʗv���L */

#define u1g_eminj_explreq   (stg_eminj_einj.u1_explreq)     /* m=eminj,lsb=1 :PL���ˎ��{�v�� */
                                                            /* �X�V�^�C�~���O : pwon,8msm */
                                                            /* ���ӎ��� : ON = PL���ˎ��{�v���L */
                                                            /*          :�y�ޭ��INJ�zOR�yD-4�z*/

#define f4g_eminj_ekpfit    (stg_eminj_einj.f4_ekpfit)      /* m=eminj,unit=�{ :�ڕW�|�[�g���˗ʎZ�o�W��(�o���N�ԕ��ϒl(�c�C���Z���T)) */
extern s2 s2g_eminj_ekpfit;                                 /* m=eminj,lsb=(1*4)/128/256,unit=�{ :�ڕW�|�[�g���˗ʎZ�o�W��(�o���N�ԕ��ϒl(�c�C���Z���T)) */
                                                            /* �X�V�^�C�~���O �F pwon,8msm */
                                                            /* ���ӎ��� :�y�ޭ��INJ�z*/
                                                            /*          : �]�����Q�Ƃ��Ă��镔�i�̃I�u�W�F�N�g���ς�邽��s2�^�ϐ��̓}�N����`�ւ̕ύX�֎~ */

extern s2 s2g_eminj_ekpfitn[u1g_EJCC_NOX];                  /* m=eminj,lsb=(1*4)/128/256,unit=�{ :�ڕW�|�[�g���˗ʎZ�o�W��(�o���N��) */
extern f4 f4g_eminj_ekpfitn[u1g_EJCC_NOX];                  /* m=eminj,unit=�{ :�ڕW�|�[�g���˗ʎZ�o�W��(�o���N��) */
                                                            /* �X�V�^�C�~���O �F pwon,8msm */
                                                            /* ���ӎ��� :�y�ޭ��INJ�z*/

#define s2g_eminj_ek1fpt    (stg_eminj_einj.s2_ek1fpt)      /* m=eminj,lsb=(1*4)/128/256,unit=�{ :�߰ĕ��˂̂ݗv�����̖ڕW�߰�1��ڕ��˗ʎZ�o�W�� */
#define f4g_eminj_ek1fpt    (stg_eminj_einj.f4_ek1fpt)      /* m=eminj,unit=�{ :�߰ĕ��˂̂ݗv�����̖ڕW�߰�1��ڕ��˗ʎZ�o�W�� */
                                                            /* �X�V�^�C�~���O �F pwon,8msm */
                                                            /* ���ӎ��� :�yD-4�ȊO�z*/

#define f4g_eminj_ekpfiegr  (stg_eminj_einj.f4_ekpfiegr)    /* m=eminj,unit=�{ :EGR-ON���̖ڕW�|�[�g���˗ʎZ�o�W��(�o���N�ԕ��ϒl(�c�C���Z���T)) */
                                                            /* �X�V�^�C�~���O �F pwon,8msm */
                                                            /* ���ӎ��� :�y�ޭ��INJ�zAND�yEGR����L�z*/

extern f4 f4g_eminj_ekpfiegrn[u1g_EJCC_NOX];                /* m=eminj,unit=�{ :EGR-ON���̖ڕW�|�[�g���˗ʎZ�o�W��(�o���N��) */
                                                            /* �X�V�^�C�~���O �F pwon,8msm */
                                                            /* ���ӎ��� :�y�ޭ��INJ�zAND�yEGR����L�z*/

extern u2 u2g_eminj_einjmodfix;             /* m=eminj,lsb=1 :���݊m�蕬��Ӱ�� */
                                            /* �X�V�^�C�~���O : 8msm */

extern s2 s2g_eminj_ekpfix;                 /* m=eminj,lsb=(1*4)/128/256,unit=�{ :�߰ĕ��˗ʎZ�o�W��(��ݸ�ԕ��ϒl(²ݾݻ)) */
extern f4 f4g_eminj_ekpfix;                 /* m=eminj,unit=�{ :�߰ĕ��˗ʎZ�o�W��(��ݸ�ԕ��ϒl(²ݾݻ)) */
                                            /* �X�V�^�C�~���O : pwon,8msm */

extern s2 s2g_eminj_ekpfi;                  /* m=eminj,lsb=(1*4)/128/256,unit=�{ :�|�[�g���˗ʎZ�o�W��(�o���N�ԕ��ϒl(�c�C���Z���T)) */
extern f4 f4g_eminj_ekpfi;                  /* m=eminj,unit=�{ :�|�[�g���˗ʎZ�o�W��(�o���N�ԕ��ϒl(�c�C���Z���T)) */
                                            /* �X�V�^�C�~���O : pwon,8msm */

extern s2 s2g_eminj_ekpfin[u1g_EJCC_NOX];   /* m=eminj,lsb=(1*4)/128/256,unit=�{ :�|�[�g���˗ʎZ�o�W��(�o���N��) */
extern f4 f4g_eminj_ekpfin[u1g_EJCC_NOX];   /* m=eminj,unit=�{ :�|�[�g���˗ʎZ�o�W��(�o���N��) */
                                            /* �X�V�^�C�~���O : pwon,8msm */

extern s2 s2g_eminj_eprreq;                 /* m=eminj,lsb=(32*2)/128/256,unit=MPa :�����|���v�ڕW�R�� */
extern f4 f4g_eminj_eprreq;                 /* m=eminj,unit=MPa :�����|���v�ڕW�R�� */
                                            /* �X�V�^�C�~���O : 8msm */
                                            /* ���ӎ��� :�y�ޭ��INJ�zOR�yD-4�z*/

extern s2 s2g_eminj_eqfreq;                 /* m=eminj,lsb=512/128/256,unit=L/h :�R���|���v�f�o���� */
                                            /* �X�V�^�C�~���O : 8msm */
                                            /* ���ӎ��� :�y�ϔR�����䖳�z*/

extern s2 s2g_eminj_eprreql;                /* m=eminj,lsb=1280/128/256,unit=kPa :�ሳ�|���v�ڕW�R�� */
extern f4 f4g_eminj_eprreql;                /* m=eminj,unit=kPa :�ሳ�|���v�ڕW�R�� */
                                            /* �X�V�^�C�~���O : pwon,8msm */
                                            /* ���ӎ��� :�y�ϔR������L�z*/

extern s2 s2g_eminj_ekrichx;                /* m=eminj,lsb=(32*2)/128/256,unit=�{ :���˗ʕ␳�W�� */
extern f4 f4g_eminj_ekrichx;                /* m=eminj,unit=�{ :���˗ʕ␳�W�� */
                                            /* �X�V�^�C�~���O : pwon,8msm */

extern s2 s2g_eminj_ekrchref[u1g_EJCC_NOX]; /* m=eminj,lsb=(32*2)/128/256,unit=�{ :���˗ʕ␳�W��(�o���N��) */
extern f4 f4g_eminj_ekrchref[u1g_EJCC_NOX]; /* m=eminj,unit=�{ :���˗ʕ␳�W��(�o���N��) */
                                            /* �X�V�^�C�~���O : pwon,8msm */

extern u1 u1g_eminj_einjmedislid;           /* m=eminj,lsb=1 :���˕������f���ʎq */
                                            /* �X�V�^�C�~���O : 8msm */

extern st_EMINJ_EMINJ stg_eminj_eminj;                              /* ���˕�������\���� */

#define u4g_eminj_einjptn       (stg_eminj_eminj.u4_einjptn)        /* m=eminj,lsb=1 :���˃p�^�[�� */
                                                                    /* �X�V�^�C�~���O : 8msm */

extern s2 s2g_eminj_eainjpn[5];                                     /* m=eminj,lsb=1024/128/256,unit=BTDC :�|�[�gn��ڕ��ˊJ�n����(���ˉ񐔔z��) */ /* 2025�N��5�񕬎˂܂ōl�����z��v�f��[5]�Ƃ��Ē�`���� */
extern f4 f4g_eminj_eainjpn[5];                                     /* m=eminj,unit=BTDC :�|�[�gn��ڕ��ˊJ�n����(���ˉ񐔔z��) */ /* 2025�N��5�񕬎˂܂ōl�����z��v�f��[5]�Ƃ��Ē�`���� */
                                                                    /* �X�V�^�C�~���O �F pwon,8msm */
                                                                    /* ���ӎ��� :�yD-4�ȊO�z*/

extern f4 f4g_eminj_eainjd1fix;                                     /* m=eminj,unit=BTDC :�m�蓛��1��ڕ��ˊJ�n���� */
                                                                    /* �X�V�^�C�~���O �F 8msm */
                                                                    /* ���ӎ��� :�y�ޭ��INJ�zOR�yD-4�z*/

extern f4 f4g_eminj_eainjd2fix;                                     /* m=eminj,unit=BTDC :�m�蓛��2��ڕ��ˊJ�n���� */
                                                                    /* �X�V�^�C�~���O �F 8msm */
                                                                    /* ���ӎ��� :�y�ޭ��INJ�zOR�yD-4�z*/

extern f4 f4g_eminj_eainjd3fix;                                     /* m=eminj,unit=BTDC :�m�蓛��3��ڕ��ˊJ�n���� */
                                                                    /* �X�V�^�C�~���O �F 8msm */
                                                                    /* ���ӎ��� :�y�ޭ��INJ�zOR�yD-4�z*/

extern f4 f4g_eminj_eainjd4fix;                                     /* m=eminj,unit=BTDC :�m�蓛��4��ڕ��ˊJ�n���� */
                                                                    /* �X�V�^�C�~���O �F 8msm */
                                                                    /* ���ӎ��� :�y�ޭ��INJ�zOR�yD-4�z*/

extern f4 f4g_eminj_eainjd5fix;                                     /* m=eminj,unit=BTDC :�m�蓛��5��ڕ��ˊJ�n���� */
                                                                    /* �X�V�^�C�~���O �F 8msm */
                                                                    /* ���ӎ��� :�y�ޭ��INJ�zOR�yD-4�z*/

extern f4 f4g_eminj_eainjd6fix;                                     /* m=eminj,unit=BTDC :�m�蓛��6��ڕ��ˊJ�n���� */
                                                                    /* �X�V�^�C�~���O �F 8msm */
                                                                    /* ���ӎ��� :�y�ޭ��INJ�zOR�yD-4�z*/

extern s2 s2g_eminj_eainjdn[6];                                     /* m=eminj,lsb=1024/128/256,unit=BTDC :����n��ڕ��ˊJ�n����(���ˉ񐔔z��) */ /* �n�����ɍő�6�񕬎�(�����̂�) */
extern f4 f4g_eminj_eainjdn[6];                                     /* m=eminj,unit=BTDC :����n��ڕ��ˊJ�n����(���ˉ񐔔z��) */ /* �n�����ɍő�6�񕬎�(�����̂�) */
                                                                    /* �X�V�^�C�~���O �F pwon,8msm */
                                                                    /* ���ӎ��� :�y�ޭ��INJ�zOR�yD-4�z*/

extern s4 s4g_eminj_eqinjstpn[5];                                   /* m=eminj,lsb=(4096*1024)/128/256/256/256,unit=mg/st :�|�[�gn��ڎn�������˗ʁi���ˉ񐔔z��j */ /* 2025�N��5�񕬎˂܂ōl�����z��v�f��[5]�Ƃ��Ē�`���� */
extern f4 f4g_eminj_eqinjstpn[5];                                   /* m=eminj,unit=mg/st :�|�[�gn��ڎn�������˗ʁi���ˉ񐔔z��j */ /* 2025�N��5�񕬎˂܂ōl�����z��v�f��[5]�Ƃ��Ē�`���� */
                                                                    /* �X�V�^�C�~���O �F pwon,8msm */
                                                                    /* ���ӎ��� :�yD-4�ȊO�z*/

extern s4 s4g_eminj_eqinjstdn[6];                                   /* m=eminj,lsb=(4096*1024)/128/256/256/256,unit=mg/st :����n��ڎn�������˗ʁi���ˉ񐔔z��j */ /* �n�����ɍő�6�񕬎�(�����̂�) */
extern f4 f4g_eminj_eqinjstdn[6];                                   /* m=eminj,unit=mg/st :����n��ڎn�������˗ʁi���ˉ񐔔z��j */ /* �n�����ɍő�6�񕬎�(�����̂�) */
                                                                    /* �X�V�^�C�~���O �F pwon,8msm */
                                                                    /* ���ӎ��� :�y�ޭ��INJ�zOR�yD-4�z*/

extern s4 s4g_eminj_eqinjflfix[8];                                  /* m=eminj,lsb=(4096*1024)/128/256/256/256,unit=mg/st :FL�Œ蕬�˗� */
extern f4 f4g_eminj_eqinjflfix[8];                                  /* m=eminj,unit=mg/st :FL�Œ蕬�˗� */
                                                                    /* �X�V�^�C�~���O �F pwon,8msm */

extern s4 s4g_eminj_eqinjplfix[8];                                  /* m=eminj,lsb=(4096*1024)/128/256/256/256,unit=mg/st :PL�Œ蕬�˗� */
extern f4 f4g_eminj_eqinjplfix[8];                                  /* m=eminj,unit=mg/st :PL�Œ蕬�˗� */
                                                                    /* �X�V�^�C�~���O �F pwon,8msm */

/*-------------------------------------------------------------------*/
/* �K���萔                                                          */
/*-------------------------------------------------------------------*/
/* ����J�i���i�����̂݁j */
extern volatile const s2 s2s_eminj_NE_RCD;              /* m=eminj,lsb=(12800*2)/128/256,unit=rpm :�������s����臒l */

/*-------------------------------------------------------------------*/
/* ���J�Œ�萔                                                      */
/*-------------------------------------------------------------------*/
extern volatile const u1 u1g_eminj_BENCH_PRI;           /* m=eminj,lsb=1 :�����K���p���˗v���̗D��x */
                                                        /* ���ӎ��� :�y�����K���p��ėL�zOR�y�����K��Ӱ�ޗL�z*/
extern volatile const u1 u1g_eminj_DEFLAIR_PRI;         /* m=eminj,lsb=1 :�H�괱��������̗D��x */
                                                        /* ���ӎ��� :�y�ޭ��INJ�z*/
extern volatile const u1 u1g_eminj_EGSTPVS_PRI;         /* m=eminj,lsb=1 :���˒�~�̗D��x */
extern volatile const u1 u1g_eminj_STPHV_PRI;           /* m=eminj,lsb=1 :HV��~����̗D��x */
                                                        /* ���ӎ��� :�yEG-MG�V���ޱ�zOR�yEG-MG�����z*/
extern volatile const u1 u1g_eminj_WUPCAT_PRI;          /* m=eminj,lsb=1 :�G�}�g�@����̗D��x */
                                                        /* ���ӎ��� :�yALL HV�z*/
extern volatile const u1 u1g_eminj_STPSS_PRI;           /* m=eminj,lsb=1 :SS��~����̗D��x */
                                                        /* ���ӎ��� :�ySS����L�zOR�yEG-MG�ׯ��z*/
extern volatile const u1 u1g_eminj_RDNVES_PRI;          /* m=eminj,lsb=1 :�ݼ�ݒ�~�E�n�����̐U���ጸ����̗D��x */
                                                        /* ���ӎ��� :�yALL HV�z*/
extern volatile const u1 u1g_eminj_RDPN_PRI;            /* m=eminj,lsb=1 :PN�ጸ����̗D��x */
                                                        /* ���ӎ��� :�yALL HV�zAND�yD-4�ȊO�z*/
extern volatile const u1 u1g_eminj_RDPN_ST_PRI;         /* m=eminj,lsb=1 :PN�ጸ����(�n����)�̗D��x */
                                                        /* ���ӎ��� :�yALL HV�zAND�y�߰āz*/
extern volatile const u1 u1g_eminj_STAHV_PRI;           /* m=eminj,lsb=1 :HV�n������̗D��x */
                                                        /* ���ӎ��� :�yALL HV�zAND�yHV�n������v���g�p�z*/
extern volatile const u1 u1g_eminj_STASS_PRI;           /* m=eminj,lsb=1 :SS�n������̗D��x */
                                                        /* ���ӎ��� :�ySS����L�zOR�yEG-MG�ׯ��z*/
extern volatile const u1 u1g_eminj_STAFRG_PRI;          /* m=eminj,lsb=1 :�ɒቷ�n������̗D��x */
                                                        /* ���ӎ��� :�y�ޭ��INJ�z*/
extern volatile const u1 u1g_eminj_RESTAHOT_PRI;        /* m=eminj,lsb=1 :�����Ďn������̗D��x */
                                                        /* ���ӎ��� :�y�ޭ��INJ�zOR�yD-4�z*/
extern volatile const u1 u1g_eminj_KCST_PRI;            /* m=eminj,lsb=1 :�n����ɯ��h�~����̗D��x */
                                                        /* ���ӎ��� :�y�ޭ��INJ�zOR�yD-4�z*/
extern volatile const u1 u1g_eminj_SJC_PRI;             /* m=eminj,lsb=1 :�G�}�}���g�@����̗D��x */
                                                        /* ���ӎ��� :�y�ޭ��INJ�zOR�yD-4�z*/
extern volatile const u1 u1g_eminj_STRATIST_PRI;        /* m=eminj,lsb=1 :���w�n������̗D��x */
                                                        /* ���ӎ��� :�y�ޭ��INJ�zOR�yD-4�z*/
extern volatile const u1 u1g_eminj_FCINJCTR_PRI;        /* m=eminj,lsb=1 :FC���R�����ː���̗D��x */
extern volatile const u1 u1g_eminj_RTNFC_PRI;           /* m=eminj,lsb=1 :FC���A����̗D��x */
                                                        /* ���ӎ��� :�y�ޭ��INJ�z*/
extern volatile const u1 u1g_eminj_CLRDEPI_PRI;         /* m=eminj,lsb=1 :����َ��ݼު�����ߏ�������̗D��x */
                                                        /* ���ӎ��� :�y�ޭ��INJ�z*/
extern volatile const u1 u1g_eminj_FPLDLV_PRI;          /* m=eminj,lsb=1 :�ሳ�����ؓ��R��������𐧌�̗D��x */
                                                        /* ���ӎ��� :�y�ޭ��INJ�zAND�y�ϔR�����䖳�z*/
extern volatile const u1 u1g_eminj_FCFRCTRL_PRI;        /* m=eminj,lsb=1 :1�C��FC����̗D��x */
                                                        /* ���ӎ��� :�yGPF�L�zAND�y1�C��FC����v���g�p�z*/
extern volatile const u1 u1g_eminj_STACM_PRI;           /* m=eminj,lsb=1,:�n���������オ�萧��̗D��x */
                                                        /* ���ӎ��� :(�y�Ӱĺ��۰ٗL�zOR�y��޺��۰ٗL�z)AND�ySUB-CPU�ȊO�zAND�y�n���������オ�萧��v���g�p�z*/
extern volatile const u1 u1g_eminj_DTHRCTRL_PRI;        /* m=eminj,lsb=1 :�C�����ި�ސ���̗D��x */
                                                        /* ���ӎ��� :�y�ޭ��INJ�z*/
extern volatile const u1 u1g_eminj_ACTLFG_PRI;          /* m=eminj,lsb=1 :�߰�����Ċw�K�ׂ̱̈�è�ސ���̗D��x */
                                                        /* ���ӎ��� :(�y�ޭ��INJ�zOR�yD-4�z)AND�y�߰�����Ċw�K�ׂ̱̈�è�ސ���v���g�p�z*/
extern volatile const u1 u1g_eminj_INJIMB_PRI;          /* m=eminj,lsb=1 :�����ݽ���̕��ː���̗D��x */
                                                        /* ���ӎ��� :�yAF�C���Բ����ݽ�L�zAND�y�ޭ��INJ�zAND�y�����ݽ���̕��ː���v���g�p�z*/
extern volatile const u1 u1g_eminj_ACTAREFUEL_PRI;      /* m=eminj,lsb=1 :������̕���������è�ސ���̗D��x */
                                                        /* ���ӎ��� :�y�ޭ��INJ�zAND�yFFV����L�z*/
extern volatile const u1 u1g_eminj_ACTOBD_PRI;          /* m=eminj,lsb=1 :OBD�v���ɂ�鱸è�ސ���̗D��x */
                                                        /* ���ӎ��� :�y�ޭ��INJ�zAND�yOBD�v���ɂ�鱸è�ސ���v���g�p�z*/
extern volatile const u1 u1g_eminj_ACTGAF_PRI;          /* m=eminj,lsb=1 :A/F�w�K�ׂ̱̈�è�ސ���̗D��x */
                                                        /* ���ӎ��� :�y�ޭ��INJ�z*/
extern volatile const u1 u1g_eminj_IMBRQ_PRI;           /* m=eminj,lsb=1, :�����ݽOBD�v���ɂ�鱸è�ސ���̗D��x */
                                                        /* ���ӎ��� :�yAF�C���Բ����ݽ�L�zAND�y�ޭ��INJ�zAND�y�����ݽOBD�v���ɂ�鱸è�ސ���v���g�p�z*/
extern volatile const u1 u1g_eminj_MFINJRQ_PRI;         /* m=eminj,lsb=1, :����OBD�v���ɂ�鱸è�ސ���̗D��x */
                                                        /* ���ӎ��� :�y����OBD�L�zAND�y�ޭ��INJ�zAND�y����OBD�v���ɂ�鱸è�ސ���v���g�p�z*/
extern volatile const u1 u1g_eminj_FKGDRQ_PRI;          /* m=eminj,lsb=1, :�R���nOBD�v���ɂ�鱸è�ސ���̗D��x */
                                                        /* ���ӎ��� :�y�R��OBD�L�zAND�y�ޭ��INJ�zAND�y�R���nOBD�v���ɂ�鱸è�ސ���v���g�p�z*/
extern volatile const u1 u1g_eminj_KCTRN_PRI;           /* m=eminj,lsb=1 :���iɯ��h�~����̗D��x */
                                                        /* ���ӎ��� :�y�ޭ��INJ�zOR�yD-4�z*/
extern volatile const u1 u1g_eminj_RDVAP_PRI;           /* m=eminj,lsb=1 :�ް�߰�}������̗D��x */
                                                        /* ���ӎ��� :�y�ޭ��INJ�z*/
extern volatile const u1 u1g_eminj_DWNPR_PRI;           /* m=eminj,lsb=1 :�R���ጸ����̗D��x */
                                                        /* ���ӎ��� :�y�ޭ��INJ�z*/
extern volatile const u1 u1g_eminj_PRVDIL_PRI;          /* m=eminj,lsb=1 :��Ԏ���ߖh�~����̗D��x */
                                                        /* ���ӎ��� :�y�ޭ��INJ�z*/
extern volatile const u1 u1g_eminj_PWRUP_PRI;           /* m=eminj,lsb=1 :�o�͐��\���㐧��̗D��x */

extern volatile const u1 u1g_eminj_BINJPLCTR_PRI;       /* m=eminj,lsb=1 :�߰�����ĕ��˂�p������{���ː���̗D��x */
                                                        /* ���ӎ��� :�yPL������˗L�zAND�y�߰�����ĕ��˂�p������{���ː���v���g�p�z*/
extern volatile const u1 u1g_eminj_BINJPLCTR_WC_PRI;    /* m=eminj,lsb=1 :�߰�����ĕ��˂�p������{���ː���(�G�}�g�@��)�̗D��x */
                                                        /* ���ӎ��� :�yALL HV�zAND�yPL������˗L�zAND�y�߰�����ĕ��˂�p������{���ː���(�G�}�g�@��)�v���g�p�z*/
extern volatile const u1 u1g_eminj_BINJPLCTR_STAHV_PRI; /* m=eminj,lsb=1 :�߰�����ĕ��˂�p������{���ː���(HV�n�����䎞)�̗D��x */
                                                        /* ���ӎ��� :�yEG-MG�V���ޱ�zAND�yFFV���䖳�zAND�yPL������˗L�zAND�y�߰�����ĕ��˂�p������{���ː���(HV�n�����䎞)�v���g�p�z*/

extern volatile const u1 u1g_eminj_FREE0_PRI;           /* m=eminj,lsb=1 :�ذ�߰�0�p����̗D��x */
                                                        /* ���ӎ��� :�y�ذ�߰�0�g�p�z*/
extern volatile const u1 u1g_eminj_FREE1_PRI;           /* m=eminj,lsb=1 :�ذ�߰�1�p����̗D��x */
                                                        /* ���ӎ��� :�y�ذ�߰�1�g�p�z*/
extern volatile const u1 u1g_eminj_FREE2_PRI;           /* m=eminj,lsb=1 :�ذ�߰�2�p����̗D��x */
                                                        /* ���ӎ��� :�y�ذ�߰�2�g�p�z*/
extern volatile const u1 u1g_eminj_FREE3_PRI;           /* m=eminj,lsb=1 :�ذ�߰�3�p����̗D��x */
                                                        /* ���ӎ��� :�y�ذ�߰�3�g�p�z*/
extern volatile const u1 u1g_eminj_FREE4_PRI;           /* m=eminj,lsb=1 :�ذ�߰�4�p����̗D��x */
                                                        /* ���ӎ��� :�y�ذ�߰�4�g�p�z*/
extern volatile const u1 u1g_eminj_FREE5_PRI;           /* m=eminj,lsb=1 :�ذ�߰�5�p����̗D��x */
                                                        /* ���ӎ��� :�y�ذ�߰�5�g�p�z*/
extern volatile const u1 u1g_eminj_FREE6_PRI;           /* m=eminj,lsb=1 :�ذ�߰�6�p����̗D��x */
                                                        /* ���ӎ��� :�y�ذ�߰�6�g�p�z*/
extern volatile const u1 u1g_eminj_FREE7_PRI;           /* m=eminj,lsb=1 :�ذ�߰�7�p����̗D��x */
                                                        /* ���ӎ��� :�y�ذ�߰�7�g�p�z*/
extern volatile const u1 u1g_eminj_FREE8_PRI;           /* m=eminj,lsb=1 :�ذ�߰�8�p����̗D��x */
                                                        /* ���ӎ��� :�y�ذ�߰�8�g�p�z*/
extern volatile const u1 u1g_eminj_FREE9_PRI;           /* m=eminj,lsb=1 :�ذ�߰�9�p����̗D��x */
                                                        /* ���ӎ��� :�y�ذ�߰�9�g�p�z*/
extern volatile const u1 u1g_eminj_FREE10_PRI;          /* m=eminj,lsb=1 :�ذ�߰�10�p����̗D��x */
                                                        /* ���ӎ��� :�y�ذ�߰�10�g�p�z*/
extern volatile const u1 u1g_eminj_FREE11_PRI;          /* m=eminj,lsb=1 :�ذ�߰�11�p����̗D��x */
                                                        /* ���ӎ��� :�y�ذ�߰�11�g�p�z*/

/*-------------------------------------------------------------------*/
/* �K���}�b�v                                                        */
/*-------------------------------------------------------------------*/

/*-------------------------------------------------------------------*/
/* �I�[�g�J�E���^                                                    */
/*-------------------------------------------------------------------*/
extern s2 s2g_eminj_ecqinjast_8m;          /* m=eminj,lsb=268435.456/128/256,unit=ms :�n���㕬�˗ʗv���p������ */

#endif  /* EMINJ_H */
/**** End of File ****************************************************/
