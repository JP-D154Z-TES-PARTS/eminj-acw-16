# 仕様書とコードの対応関係マッピング
# Specification to Code Mapping for l_mat.c

作成日: 2025-11-07
対象ファイル:
  - 仕様書: base/eminj-acw-15-c-t_spec/11eminj-acw-15-c-t.docx
  - ソースコード: base/eminj-acw-15-c-t_src/eminj_l_mat.c

================================================================================

## 1. 概要 (Overview)

### 1.1 部品名
minj : Mediation INJection (噴射要求の調停)

### 1.2 主要機能
  ● minj ：Mediation INJection
  ● 各機能が要求する噴射モードを集約して最適な混合気を形成する為に、機能の優先調停を行う。
  ● 調停された各機能からの噴射、高圧・低圧燃料ポンプに関する要求値を公開する。
  ● 噴射モード調停後にをコールし、噴射回数に応じた現在基本増量補正係数を取得する。
  ● ＳＡＣの噴射要求受付処理はアプリ要求と同時性を確保する必要があるため、本部品の８ｍｓ中

## 2. ファイル構造 (File Structure)

### 2.1 ソースコード: eminj_l_mat.c
  - 総行数: 4962

  - インクルードファイル数: 57
    主要インクルード:
      Line 16: #include <../inc/common.h>
      Line 17: #include <../inc/gllib.h>
      Line 18: #include <engsrc/espc/ejcc.h>                   /* JEEFI,u1g_EJCC_DUAL,u1g_EJCC_D4,u1g_EJCC_PORT,u1g_EJCC_NOX,JESS,JEMAT_BENCHI */
      Line 23: #include <engsrc/inc/elsb.h>
      Line 24: #include <engsrc/inc/elib.h>
      Line 26: #include <engsrc/eactmedi/einj/eminj.h>
      Line 28: #include <sac/ainjif.h>                          /* u2g_AINJIF_MOD011,vdg_ainjif_renew_injrq() */
      Line 30: #include <engsrc/estate/esin/ene.h>              /* s2g_ene_ene */
      Line 32: #include <engsrc/efunc/edrblty/eels/erdnves.h>   /* vdg_erdnves_group00_dataget() */
      Line 35: #include <engsrc/efunc/eunusual/eplant/edeflair.h> /* vdg_edeflair_emedi_dataget() */

## 3. 公開関数 (Public Functions)

### 3.1 vdg_eminj_pwon
  - 行番号: 722
  - 説明: 初期化処理
  - 定義:
    void
    vdg_eminj_pwon( void )
    {

### 3.2 vdg_eminj_8msm
  - 行番号: 815
  - 説明: 噴射要求の調停処理 (8ms中タスク)
  - 定義:
    void
    vdg_eminj_8msm( void )
    {

### 3.3 vdg_eminj_einj_dataget
  - 行番号: 2605
  - 説明: 噴射データ取得
  - 定義:
    void
    vdg_eminj_einj_dataget( st_EMINJ_EINJ *ptt_retval )
    {

### 3.4 vdg_eminj_eminj_dataget
  - 行番号: 2731
  - 説明: 調停データ取得
  - 定義:
    void
    vdg_eminj_eminj_dataget( st_EMINJ_EMINJ *ptt_retval )
    {

## 4. 内部関数 (Static Functions)

総数: 12

  - Line 680: vds_eminj_eminj_hpri
  - Line 681: vds_eminj_eminjlmt_hpri
  - Line 682: vds_eminj_einj_dataset
  - Line 683: vds_eminj_einj_datacopy
  - Line 684: vds_eminj_eminj_dataset
  - Line 685: vds_eminj_einj_datacopy2
  - Line 686: vds_eminj_einj_dataconv
  - Line 687: vds_eminj_einj_dataconv_rev
  - Line 689: vds_eminj_erestahot_rap_dataget
  - Line 692: vds_eminj_erdpn_rap_dataget
  - Line 694: vds_eminj_dummy_emedi_dataget
  - Line 695: vds_eminj_dummy_emedi_dataget2

## 5. データ構造 (Data Structures)

### st_EMINJ_EMINJ_DEF
  - 初出: Line 345
    void (* pt_dataget)( st_EMINJ_EMINJ_DEF * ptt_store );  /* ¬Ëû®f[^æ¾Ö±ÄÞÚ½ */

### st_EMINJ_EMINJ_BUF
  - 初出: Line 351
    void (* pt_dataget2)( st_EMINJ_EMINJ_BUF * ptt_store ); /* ¬Ëû®f[^æ¾Ö±ÄÞÚ½ */

### st_EMINJ_EMINJ
  - 初出: Line 345
    void (* pt_dataget)( st_EMINJ_EMINJ_DEF * ptt_store );  /* ¬Ëû®f[^æ¾Ö±ÄÞÚ½ */

### st_EMINJ_EINJ
  - 初出: Line 460
    st_EMINJ_EINJ stg_eminj_einj;               /* ¬Ëû®²â\¢Ì */

## 6. コンパイルスイッチ (Compile Switches)

主要なコンパイルスイッチ:
  - JEALLHV_E: 79回使用
  - JEEFI: 486回使用
  - JEEGMG_E: 47回使用
  - JEEGR: 27回使用
  - JEFFV: 35回使用
  - JENOX: 11回使用
  - JEOBDAFIMB_D: 25回使用
  - JEPLMLT_E: 68回使用
  - JEPRDEMAND: 41回使用
  - JESS: 17回使用

## 7. 仕様書テーブル (Specification Tables)

### Table 0
  - ヘッダー: ['要求1', '要求1', '最適な燃料噴射の方式を決定する。']
  - 行数: 9

### Table 1
  - ヘッダー: ['変数名', '機能名', 'bkup', 'chk', '単位', 'ﾚﾝｼﾞ', '算出ﾀｲﾐﾝｸﾞ', '公開先', '型', 'LSB', 'ｺﾝﾊﾟｲﾙSW']
  - 行数: 109
  - サンプル変数: einjmod, einjmodfix, einjptn, eainjp1, eainjp1

### Table 2
  - ヘッダー: ['変数名', '公開先']
  - 行数: 39
  - サンプル変数: einjmod, eainjp1, eainjp2, eainjp3, eainjp4

### Table 3
  - ヘッダー: ['変数名', '公開先']
  - 行数: 27
  - サンプル変数: einjmod, einjptn, eainjpn[], einjend, eainjcutp

### Table 4
  - ヘッダー: ['変数名', '機能名', 'bkup', 'chk', '単位', 'ﾚﾝｼﾞ', 'LSB', '算出ﾀｲﾐﾝｸﾞ', 'ｺﾝﾊﾟｲﾙSW']
  - 行数: 10
  - サンプル変数: estpri, estprir, eastpri

### Table 5
  - ヘッダー: ['ﾊﾞｯｸｱｯﾌﾟRAM名', '初期値', '下限値', '上限値']
  - 行数: 1

### Table 6
  - ヘッダー: ['要求\n(ﾓｼﾞｭｰﾙ名)', '要求\n(機能名)', 'ＩＤ', '優先度', 'ｺﾝﾊﾟｲﾙSW', '調停制約有無']
  - 行数: 11

### Table 7
  - ヘッダー: ['', '', '', '', '', '']
  - 行数: 4

### Table 8
  - ヘッダー: ['要求\n(ﾓｼﾞｭｰﾙ名)', '要求\n(機能名)', 'ＩＤ', '優先度', 'ｺﾝﾊﾟｲﾙSW', '調停制約有無']
  - 行数: 7

### Table 9
  - ヘッダー: ['', '', '', '', '', '']
  - 行数: 4
