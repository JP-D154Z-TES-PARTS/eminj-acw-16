# 詳細マッピング: 仕様書 ⇔ eminj_l_mat.c
# Detailed Mapping: Specification ⇔ eminj_l_mat.c

作成日: 2025-11-07

================================================================================

## I. 仕様書の構造分析

### A. 変数定義テーブル (Table 1)

テーブルヘッダー: ['変数名', '機能名', 'bkup', 'chk', '単位', 'ﾚﾝｼﾞ', '算出ﾀｲﾐﾝｸﾞ', '公開先', '型', 'LSB', 'ｺﾝﾊﾟｲﾙSW']

主要変数とコード内の対応:

1. **einjmod** - 噴射ﾓｰﾄﾞ
   - コード内の行: 463, 562, 631

2. **einjmodfix** - 現在確定噴射ﾓｰﾄﾞ
   - コード内の行: 463, 1613, 1916

3. **einjptn** - 噴射ﾊﾟﾀｰﾝ
   - コード内の行: 632, 911, 1047
   - 例: `/* u4s_eminj_eminj_einjptn_monÍAvdg_eminj_8msmÅÌÝQÆÌ½ßÖàÅè` */`

4. **eainjp1** - ﾎﾟｰﾄ1回目噴射開始時期
   - コード内の行: 563, 564, 913
   - 例: `/* s2s_eminj_eainjp1_monÍAvdg_eminj_8msmÅÌÝQÆÌ½ßÖàÅè` */`

5. **eainjp1** - ﾎﾟｰﾄ1回目噴射開始時期
   - コード内の行: 563, 564, 913
   - 例: `/* s2s_eminj_eainjp1_monÍAvdg_eminj_8msmÅÌÝQÆÌ½ßÖàÅè` */`

6. **eainjp2** - ﾎﾟｰﾄ2回目噴射開始時期
   - コード内の行: 565, 566, 915
   - 例: `/* s2s_eminj_eainjp2_monÍAvdg_eminj_8msmÅÌÝQÆÌ½ßÖàÅè` */`

7. **eainjp2** - ﾎﾟｰﾄ2回目噴射開始時期
   - コード内の行: 565, 566, 915
   - 例: `/* s2s_eminj_eainjp2_monÍAvdg_eminj_8msmÅÌÝQÆÌ½ßÖàÅè` */`

8. **eainjp3** - ﾎﾟｰﾄ3回目噴射開始時期
   - コード内の行: 567, 568, 917
   - 例: `/* s2s_eminj_eainjp3_monÍAvdg_eminj_8msmÅÌÝQÆÌ½ßÖàÅè` */`

9. **eainjp3** - ﾎﾟｰﾄ3回目噴射開始時期
   - コード内の行: 567, 568, 917
   - 例: `/* s2s_eminj_eainjp3_monÍAvdg_eminj_8msmÅÌÝQÆÌ½ßÖàÅè` */`

10. **eainjp4** - ﾎﾟｰﾄ4回目噴射開始時期
   - コード内の行: 569, 570, 919
   - 例: `/* s2s_eminj_eainjp4_monÍAvdg_eminj_8msmÅÌÝQÆÌ½ßÖàÅè` */`

11. **eainjp4** - ﾎﾟｰﾄ4回目噴射開始時期
   - コード内の行: 569, 570, 919
   - 例: `/* s2s_eminj_eainjp4_monÍAvdg_eminj_8msmÅÌÝQÆÌ½ßÖàÅè` */`

12. **eainjpn[5]** - ﾎﾟｰﾄn回目噴射開始時期(噴射回数配列)
   - コード内の行: 466, 467, 647

13. **eainjpn[5]** - ﾎﾟｰﾄn回目噴射開始時期(噴射回数配列)
   - コード内の行: 466, 467, 647

14. **einjend** - ﾎﾟｰﾄ噴射終了時期
   - コード内の行: 465, 559, 560

15. **einjend** - ﾎﾟｰﾄ噴射終了時期
   - コード内の行: 465, 559, 560

16. **eainjcutp** - ﾎﾟｰﾄ噴射強制ｶｯﾄ時期
   - コード内の行: 128, 571, 572

17. **eainjcutp** - ﾎﾟｰﾄ噴射強制ｶｯﾄ時期
   - コード内の行: 128, 571, 572

18. **eainjd1** - 筒内1回目噴射開始時期
   - コード内の行: 472, 573, 574

19. **eainjd1** - 筒内1回目噴射開始時期
   - コード内の行: 472, 573, 574

20. **eainjd2** - 筒内2回目噴射開始時期
   - コード内の行: 473, 575, 576


================================================================================

## II. 関数フロー分析

### A. vdg_eminj_pwon() - 初期化処理

**場所:** Line 722-804

**処理内容:**
1. 変数初期化
2. 噴射補正係数の設定
3. データセットの初期化

**コードスニペット:**
```c
vdg_eminj_pwon( void )
{
    u1 u1t_mox;    /* lsb=1 :CZT */
    u1 u1t_nox_c;  /* lsb=1 :CZT */
    s2 s2t_kpfi;   /* lsb=(1*4)/128/256,unit={ :|[g¬ËÊZoW */
    s2 s2t_kpfix;  /* lsb=(1*4)/128/256,unit={ :Îß°Ä¬ËÊZoW(ÊÞÝ¸Ô½Ïl(Â²Ý¾Ý»)) */
    s2 s2t_kpfin[u1g_EJCC_NOX]; /* lsb=(1*4)/128/256,unit={ :|[g¬ËÊZoW(oNÊ) */
#if JEPRDEMAND == u1g_EJCC_USE       /*yÂÏR³§äLz*/
    s2 s2t_prreql; /* lsb=1280/128/256,unit=kPa :á³|vÚWR³ */
#endif /* JEPRDEMAND */
...
```

### B. vdg_eminj_8msm() - 8ms中タスク処理

**場所:** Line 815-2602

**主要処理フロー:**

**処理セクション:**

**コードスニペット (開始部分):**
```c
vdg_eminj_8msm( void )
{
    u1 u1t_xnercdfew;           /* lsb=1 :NE^XN­»ètO */
    u1 u1t_injmedislid;         /* lsb=1 :¬Ëû®½f¯Êq */
#if (JEEFI == u1g_EJCC_DUAL) || (JEEFI == u1g_EJCC_D4)  /*yÃÞ­±ÙINJzORyD-4z*/
    s4 s4t_kqstmxd;             /* lsb=128/128/256,unit={ :àn®¬ËÊ§ÀW */
    u2 u2t_injmod;              /* lsb=1 :¬Ë[h */
    u2 u2t_injmod2;             /* lsb=1 :¬Ë[h */
    s2 s2t_ainjdadd;            /* lsb=1024/128/256,unit=BTDC :àÇÁ¬ËJnú */
    s2 s2t_ainjadd;             /* lsb=1024/128/256,unit=BTDC :uÔOTh~ÇÁ¬ËJnú */
    s2 s2t_ainjdaddmin;         /* lsb=1024/128/256,unit=BTDC :àÇÁ¬ËJnú(Å¬lIðp) */
    u2 u2t_binjmodmsk00F0;      /* lsb=1 :ebinjctrÌ¬Ë[hð0x00F0Å}XNµ½l */
    u2 u2t_binjmodmsk0F0F;      /* lsb=1 :ebinjctrÌ¬Ë[hð0x0F0FÅ}XNµ½l */
    s2 s2t_ainjdb1;             /* lsb=1024/128/256,unit=BTDC :î{à¬ËJnú */
    s2 s2t_ainjcutd;            /* lsb=1024/128/256,unit=BTDC :à¬Ë­§¶¯Äú */
    s2 s2t_prhpb;               /* lsb=(32*2)/128/256,unit=MPa :³ÎßÝÌßî{ÚWR³ */
 #if JEPLMLT_E == u1g_EJCC_USE  /*yPLÏÙÁ¬ËLz*/ /* temp:dlmFÌàe½f(DENG-STD-25017D) start */
    s2 s2t_binjplctr_prreq;     /* lsb=(32*2)/128/256,unit=MPa :p[Vtg}`¬Ë³|vÚWR³ */
 #endif /* JEPLMLT_E */ /* temp:dlmFÌàe½f(DENG-STD-25017D) end */
#endif /* JEEFI */
    u4 u4t_rqdat[2];            /* lsb=1 :vw¦f[^ 0:\¢ÌA1:V\¢Ì */
    u1 u1t_injnum;              /* lsb=1 :¬Ëi */
    u1 u1t_mox;                 /* lsb=1 :CZT */
    u1 u1t_nox_c;               /* lsb=1 :CZT */
    u1 u1t_cyl;                 /* lsb=1 :C */
    u1 u1t_ncyl_c;              /* lsb=1 :C */
    s2 s2t_krichxbcrt[u1g_EJCC_NOX]; /* lsb=(32*2)/128/256,unit={ :»Ýî{Êâ³W */
    s2 s2t_krichx;              /* lsb=(32*2)/128/256,unit={ :¬ËÊâ³W */
    s2 s2t_kpfi_wk;             /* lsb=(1*4)/128/256,unit={ :Îß°Ä¬ËÊZoW[N */
    s2 s2t_kpfin[u1g_EJCC_NOX]; /* lsb=(1*4)/128/256,unit={ :|[g¬ËÊZoW(oNÊ) */
    s4 s4t_k1f;                 /* lsb=(1*4)/128/256,unit={ :1ñÚ¬ËÊZoW(oNÔ½Ïl(cCZT)) */
    s4 s4t_k2f;                 /* lsb=(1*4)/128/256,unit={ :2ñÚ¬ËÊZoW(oNÔ½Ïl(cCZT)) */
    s4 s4t_k3f;                 /* lsb=(1*4)/128/256,unit={ :3ñÚ¬ËÊZoW(oNÔ½Ïl(cCZT)) */
    u1 u1t_xqinjast;            /* lsb=1 :n®ã¬ËÊvÌ×¸Þ */
    u1 u1t_xqinjasto;           /* lsb=1 :n®ã¬ËÊvÌ×¸ÞOñl */
    u1 u1t_xast;                /* lsb=1 :n®ãtO */
...
```

### C. vdg_eminj_einj_dataget() - データ取得

**場所:** Line 2605-2728

**コードスニペット:**
```c
vdg_eminj_einj_dataget( st_EMINJ_EINJ *ptt_retval )
{
    u1 u1t_mox;    /* lsb=1 :CZT */
    u1 u1t_nox_c;  /* lsb=1 :CZT */
    u1 u1t_cyl;    /* lsb=1 :C */
    u1 u1t_ncyl_c; /* lsb=1 :C */

    u1t_ncyl_c = u1g_ejcc_NCYL;
    u1t_nox_c = u1g_ejcc_NOX;

    glint_di();         /* ¯«mÛ Jn */
    ptt_retval->u2_einjmod = stg_eminj_einj.u2_einjmod;
#if JEEFI != u1g_EJCC_D4        /*yD-4ÈOz*/
    ptt_retval->s2_eainjp1 = stg_eminj_einj.s2_eainjp1;
    ptt_retval->f4_eainjp1 = stg_eminj_einj.f4_eainjp1;
    ptt_retval->s2_eainjp2 = stg_eminj_einj.s2_eainjp2;
...
```

### D. vdg_eminj_eminj_dataget() - 調停データ取得

**場所:** Line 2731-2853

**コードスニペット:**
```c
vdg_eminj_eminj_dataget( st_EMINJ_EMINJ *ptt_retval )
{
    u1 u1t_mox;    /* lsb=1 :CZT */
    u1 u1t_nox_c;  /* lsb=1 :CZT */
    u1 u1t_cyl;    /* lsb=1 :C */
    u1 u1t_ncyl_c; /* lsb=1 :C */
    u1 u1t_injnum; /* lsb=1 :¬Ëñ */

    u1t_ncyl_c = u1g_ejcc_NCYL;
    u1t_nox_c = u1g_ejcc_NOX;

    glint_di();         /* ¯«mÛ Jn */
    ptt_retval->u2_einjmod = stg_eminj_eminj.u2_einjmod;
    ptt_retval->u4_einjptn = stg_eminj_eminj.u4_einjptn;
#if JEEFI != u1g_EJCC_D4        /*yD-4ÈOz*/
    for ( u1t_injnum = (u1)0U; u1t_injnum < (u1)4U; u1t_injnum++ )
...
```

================================================================================

## III. 内部関数の詳細マッピング

### vds_eminj_eminj_hpri
  - **行番号:** 2855
  - **説明:** 噴射要求の優先度判定
  - **定義:**
    ```c
    static void
    vds_eminj_eminj_hpri( st_EMINJ_EMINJ_DEF *ptt_datsel, const st_EMINJ_EMINJ_DEF *ptt_datdft, st_EMINJ_EMINJ_BUF *ptt_datsel2, const st_EMINJ_EMINJ_BUF *ptt_datdft2 )
    {
    ```

### vds_eminj_eminjlmt_hpri
  - **行番号:** 3737
  - **説明:** 噴射制限の優先度判定
  - **定義:**
    ```c
    static void
    vds_eminj_eminjlmt_hpri( st_EMINJ_EMINJ_DEF *ptt_datsel, const st_EMINJ_EMINJ_DEF *ptt_datdft, st_EMINJ_EMINJ_BUF *ptt_datsel2, const st_EMINJ_EMINJ_BUF *ptt_datdft2 )
    {
    ```

### vds_eminj_einj_dataset
  - **行番号:** 4014
  - **説明:** 噴射データセット設定
  - **定義:**
    ```c
    static void
    vds_eminj_einj_dataset( st_EMINJ_EINJ *ptt_store, const st_EMINJ_EINJ *ptt_data, u1 u1t_xnercdfew )
    {
    ```

### vds_eminj_einj_datacopy
  - **行番号:** 4163
  - **説明:** 噴射データコピー
  - **定義:**
    ```c
    static void
    vds_eminj_einj_datacopy( st_EMINJ_EMINJ_DEF *ptt_data, const st_EMINJ_EMINJ_DEF *ptt_copy )
    {
    ```

### vds_eminj_eminj_dataset
  - **行番号:** 4245
  - **説明:** 調停データセット設定
  - **定義:**
    ```c
    static void
    vds_eminj_eminj_dataset( st_EMINJ_EMINJ *ptt_store, const st_EMINJ_EMINJ *ptt_data, u1 u1t_xnercdfew )
    {
    ```

### vds_eminj_einj_datacopy2
  - **行番号:** 4380
  - **説明:** 噴射データコピー2
  - **定義:**
    ```c
    static void
    vds_eminj_einj_datacopy2( st_EMINJ_EMINJ_BUF *ptt_data, const st_EMINJ_EMINJ_BUF *ptt_copy )
    {
    ```

### vds_eminj_einj_dataconv
  - **行番号:** 4469
  - **説明:** データ変換
  - **定義:**
    ```c
    static void
    vds_eminj_einj_dataconv( st_EMINJ_EMINJ_BUF *ptt_data_new, const st_EMINJ_EMINJ_DEF *ptt_data_old )
    {
    ```

### vds_eminj_einj_dataconv_rev
  - **行番号:** 4668
  - **説明:** データ逆変換
  - **定義:**
    ```c
    static void
    vds_eminj_einj_dataconv_rev( st_EMINJ_EMINJ_DEF *ptt_data_old, const st_EMINJ_EMINJ_BUF *ptt_data_new )
    {
    ```


================================================================================

## IV. コンパイルスイッチと制御フロー

### JEEFI
  - **説明:** EFI種別 (DUAL/D-4/PORT)
  - **使用回数:** 486
  - **使用例 (Line 34):**
    ```c
    #if JEEFI == u1g_EJCC_DUAL      /*yÃÞ­±ÙINJz*/
    #include <engsrc/efunc/eunusual/eplant/edeflair.h> /* vdg_edeflair_emedi_dataget() */
    #endif /* JEEFI */
    ```

### JESS
  - **説明:** アイドルストップ機能有無
  - **使用回数:** 17
  - **使用例 (Line 41):**
    ```c
    #if (JESS == u1g_EJCC_USE) || (JEEGMG_E == u1g_EJCC_HVCLUTCH_E)         /*ySS§äLzORyEG-MG¸×¯Áz*/
    #include <engsrc/efunc/eeco/ess/estpss.h>        /* vdg_estpss_emedi_dataget() */
    #include <engsrc/efunc/eeco/ess/estass.h>        /* vdg_estass_emedi_dataget() */
    ```

### JEALLHV_E
  - **説明:** ハイブリッド車仕様
  - **使用回数:** 79
  - **使用例 (Line 31):**
    ```c
    #if JEALLHV_E == u1g_EJCC_ALLHV_E               /*yALL HVz*/
    #include <engsrc/efunc/edrblty/eels/erdnves.h>   /* vdg_erdnves_group00_dataget() */
    #endif /* JEALLHV_E */
    ```

### JEEGMG_E
  - **説明:** EG-MG制御種別
  - **使用回数:** 47
  - **使用例 (Line 38):**
    ```c
    #if (JEEGMG_E == u1g_EJCC_HVPLGR_E) || (JEEGMG_E == u1g_EJCC_HVDIRECT_E)    /*yEG-MGV¯·Þ±zORyEG-MG¼z*/
    #include <engsrc/efunc/eeco/ehv/estphv.h>        /* vdg_estphv_emedi_dataget() */
    #endif /* JEEGMG_E */
    ```

### JEFFV
  - **説明:** FFV(フレックス燃料)対応
  - **使用回数:** 35
  - **使用例 (Line 69):**
    ```c
     #if JEFFV != u1g_EJCC_NOT_USE  /*yFFV§äLz*/
    #include <engsrc/efunc/eemi/eactive/eactarefuel.h>   /* vdg_eactarefuel_emedi_dataget(),s2g_eactarefuel_ekpfit */
     #endif /* JEFFV */
    ```

### JEPRDEMAND
  - **説明:** 可変圧制御有無
  - **使用回数:** 41
  - **使用例 (Line 73):**
    ```c
     #if JEPRDEMAND == u1g_EJCC_NOT_USE             /*yÂÏR³§ä³z*/
    #include <engsrc/efunc/edrblty/estblcomb/efpldlv.h>  /* vdg_efpldlv_emedi_dataget() */
     #endif /* JEPRDEMAND */
    ```

### JEOBDAFIMB_D
  - **説明:** AF学習補正診断
  - **使用回数:** 25
  - **使用例 (Line 76):**
    ```c
     #if (JEOBDAFIMB_D == u1g_EJCC_USE) && (EMINJ_INJIMB_MEDI == ON)    /*yAFCÔ²ÝÊÞ×Ý½LzANDy²ÝÊÞ×Ý½Ì¬Ë§ävgpz*/
    #include <engsrc/efunc/eemi/eactive/einjimb.h>   /* vdg_einjimb_emedi_dataget() */
     #endif /* JEOBDAFIMB_D,EMINJ_INJIMB_MEDI */
    ```

### JEPLMLT_E
  - **説明:** パーシャルリフト噴射
  - **使用回数:** 68
  - **使用例 (Line 129):**
    ```c
    #if (((JEPLMLT_E == u1g_EJCC_USE) && (EMINJ_BINJPLCTR_MEDI == ON)) \
       || ((JEALLHV_E == u1g_EJCC_ALLHV_E) && (JEPLMLT_E == u1g_EJCC_USE) && (EMINJ_BINJPLCTR_WC_MEDI == ON)) \
       || ((JEEGMG_E == u1g_EJCC_HVPLGR_E) && (JEFFV == u1g_EJCC_NOT_USE) && (JEPLMLT_E == u1g_EJCC_USE) && (EMINJ_BINJPLCTR_STAHV_MEDI == ON)) \
    ```

### JENOX
  - **説明:** NOx制御
  - **使用回数:** 11
  - **使用例 (Line 207):**
    ```c
    #if !defined JENOX
    #error "JENOX is undeclared"
    #endif
    ```

### JEEGR
  - **説明:** EGR制御
  - **使用回数:** 27
  - **使用例 (Line 215):**
    ```c
    #if !defined JEEGR
    #error "JEEGR is undeclared"
    #endif
    ```
