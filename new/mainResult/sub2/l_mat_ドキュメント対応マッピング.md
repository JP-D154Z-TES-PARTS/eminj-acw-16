# l_mat.cとドキュメントの対応関係マッピング

## ドキュメント情報
- **作成日**: 2025-11-07
- **対象ファイル**: eminj_l_mat.c
- **ベースバージョン**: eminj-pcw00-1500-a-t-M4 (eminj-acw-15)
- **新バージョン**: eminj-acw-16-a-t
- **文字コード**: CP932

## 1. ファイル構成と役割

### 1.1 eminj_l_mat.c の概要
- **行数**: 4,961行
- **主要機能**: 噴射要求調停処理
- **対応ドキュメント**:
  - ロジック変更シート_ver9.09_eminj.xlsx
  - 参照元チェックシート_ver2.11_eminj-acw-16-a-t.xlsx
  - 参照先チェックシート_eminj-acw-16-a-t.xlsx

## 2. 主要関数マッピング

### 2.1 外部公開関数（Public Functions）

#### vdg_eminj_pwon()
- **役割**: 電源ON時の初期値設定
- **呼び出し元**: vdg_elmng_pwon()
- **ドキュメント対応**:
  - ロジック変更シート: 「初期化処理」セクション
  - 参照元チェックシート: PWONタイミング処理
- **処理内容**:
  - グローバル変数の初期化
  - 各構造体のデフォルト値設定
  - 媒介変数の初期化

#### vdg_eminj_8msm()
- **役割**: 噴射要求調停処理（8ms周期）
- **呼び出し元**: vdg_elmng_8msm()
- **ドキュメント対応**:
  - ロジック変更シート: 「調停処理」セクション
  - 参照元チェックシート: 8MSMタイミング処理
- **処理フロー**:
  1. 各機能モジュールからのデータ取得
  2. 優先度比較による調停
  3. 選択されたデータの格納
  4. リミット処理
  5. 出力データ構造体への変換

#### vdg_eminj_einj_dataget()
- **役割**: 噴射情報取得（媒介データ構造体1）
- **引数**: `st_EMINJ_EINJ *ptt_retval` - 戻り値格納バッファ
- **呼び出し元**: SAC（システム制御）、APL（アプリケーション層）
- **ドキュメント対応**:
  - 参照先チェックシート: データ取得IF
- **処理内容**:
  - 内部データを外部公開構造体にコピー
  - データ型変換（整数→浮動小数点）

#### vdg_eminj_eminj_dataget()
- **役割**: 噴射情報取得（集団対象用構造体2）
- **引数**: `st_EMINJ_EMINJ *ptt_retval` - 戻り値格納バッファ
- **呼び出し元**: SAC、APL
- **ドキュメント対応**:
  - 参照先チェックシート: データ取得IF
- **処理内容**:
  - 内部データを外部公開構造体にコピー
  - 配列データの転送

### 2.2 内部関数（Static Functions）

#### vds_eminj_eminj_hpri()
- **役割**: 優先度に基づくデータ選択（高優先度優先）
- **引数**:
  - `ptt_datsel`: 選択されたデータ格納先
  - `ptt_datdft`: デフォルトデータ
  - `ptt_datsel2`: 選択されたデータ格納先（バッファ構造体）
  - `ptt_datdft2`: デフォルトデータ（バッファ構造体）
- **ドキュメント対応**:
  - ロジック変更シート: 「優先度調停ロジック」
- **処理ロジック**:
  1. 優先度が高いデータを選択
  2. 要求フラグのビット演算処理
  3. データの上書き

#### vds_eminj_eminjlmt_hpri()
- **役割**: リミット付き優先度調停
- **ドキュメント対応**:
  - ロジック変更シート: 「リミット処理」
- **処理内容**:
  - 優先度調停実施
  - 各パラメータの上下限チェック
  - 異常値のクリップ処理

#### vds_eminj_einj_dataset()
- **役割**: 媒介データ構造体への設定
- **ドキュメント対応**:
  - 参照元チェックシート: データ設定処理
- **処理内容**:
  - 構造体メンバーのコピー
  - データ整合性チェック

#### vds_eminj_einj_datacopy()
- **役割**: 標準対象用構造体のコピー
- **処理内容**:
  - メモリコピー
  - ビットフィールドの保持

#### vds_eminj_eminj_dataset()
- **役割**: 集団対象用構造体への設定
- **処理内容**:
  - 配列データのコピー
  - 噴射パターンの設定

#### vds_eminj_einj_datacopy2()
- **役割**: バッファ構造体のコピー
- **処理内容**:
  - 媒介用バッファのメモリコピー

#### vds_eminj_einj_dataconv()
- **役割**: 標準対象用→集団対象用データ変換
- **ドキュメント対応**:
  - ロジック変更シート: 「データ変換処理」
- **変換内容**:
  - 個別変数→配列形式への変換
  - `s2_eainjp1-4` → `s2_eainjpn[0-3]`
  - `s2_eainjd1-4` → `s2_eainjdn[0-3]`
  - `s4_eqinjstp1-4` → `s4_eqinjstpn[0-3]`
  - `s4_eqinjstd1-4` → `s4_eqinjstdn[0-3]`

#### vds_eminj_einj_dataconv_rev()
- **役割**: 集団対象用→標準対象用データ逆変換
- **変換内容**:
  - 配列形式→個別変数への逆変換

#### vds_eminj_erestahot_rap_dataget()
- **役割**: 再始動時高温保護データ取得（ラッパー関数）
- **ドキュメント対応**:
  - 参照元チェックシート: erestahot IF
- **処理内容**:
  - `vdg_erestahot_emedi_dataget()` を呼び出し
  - 戻り値を内部構造体に格納

#### vds_eminj_erdpn_rap_dataget()
- **役割**: PN抑制保護データ取得（ラッパー関数）
- **ドキュメント対応**:
  - 参照元チェックシート: erdpn IF
- **処理内容**:
  - `vdg_erdpn_emedi_dataget()` を呼び出し
  - 戻り値を内部構造体に格納

#### vds_eminj_dummy_emedi_dataget()
- **役割**: ダミーデータ取得（標準対象用）
- **処理内容**:
  - 構造体の初期化（全メンバー0クリア）
  - 未使用機能モジュール用

#### vds_eminj_dummy_emedi_dataget2()
- **役割**: ダミーデータ取得（集団対象用）
- **処理内容**:
  - バッファ構造体の初期化

## 3. データ取得元マッピング

### 3.1 外部モジュールからのデータ取得

#### HV関連
| 関数 | モジュール | 条件コンパイル | ドキュメント参照 |
|------|-----------|----------------|------------------|
| `vdg_erdnves_group00_dataget()` | 振動低減停止保護 | `JEALLHV_E == ALL_HV` | 参照元チェックシート: erdnves |
| `vdg_estphv_emedi_dataget()` | HV停止保護 | `EG-MGプラグイン or ダイレクト` | 参照元チェックシート: estphv |
| `vdg_estahv_emedi_dataget2()` | HV始動保護 | `ALL_HV and STAHV使用` | 参照元チェックシート: estahv |
| `vdg_ewupcat_emedi_dataget()` | 触媒暖機保護 | `JEALLHV_E == ALL_HV` | 参照元チェックシート: ewupcat |
| `vdg_erdpn_emedi_dataget()` | PN抑制保護 | `ALL_HV and D-4以外` | 参照元チェックシート: erdpn |

#### SS関連
| 関数 | モジュール | 条件コンパイル | ドキュメント参照 |
|------|-----------|----------------|------------------|
| `vdg_estpss_emedi_dataget()` | SS停止保護 | `SS機能有効 or EG-MGクラッチ` | 参照元チェックシート: estpss |
| `vdg_estass_emedi_dataget()` | SS始動保護 | `SS機能有効 or EG-MGクラッチ` | 参照元チェックシート: estass |

#### 筒内INJ関連
| 関数 | モジュール | 条件コンパイル | ドキュメント参照 |
|------|-----------|----------------|------------------|
| `vdg_edeflair_emedi_dataget()` | 制御異常保護 | `JEEFI == DUAL` | 参照元チェックシート: edeflair |
| `vdg_estafrg_emedi_dataget()` | 燃料種類始動保護 | `JEEFI == DUAL` | 参照元チェックシート: estafrg |
| `vdg_erestahot_emedi_dataget()` | 再始動時高温保護 | `DUAL or D-4` | 参照元チェックシート: erestahot |
| `vdg_esjc_emedi_dataget()` | エマージェンシー保護 | `DUAL or D-4` | 参照元チェックシート: esjc |
| `vdg_ekcst_emedi_dataget()` | 始動時ノック回避保護 | `DUAL or D-4` | 参照元チェックシート: ekcst |
| `vdg_estratist_emedi_dataget()` | 成層始動保護 | `DUAL or D-4` | 参照元チェックシート: estratist |
| `vdg_ertnfc_group00_dataget()` | FC時リッチ保護 | `DUAL or D-4` | 参照元チェックシート: ertnfc |
| `vdg_eactlfg_emedi_dataget()` | ポート学習補正の代替吸気制御 | `DUAL or D-4 and 使用` | 参照元チェックシート: eactlfg |
| `vdg_ekctrn_emedi_dataget()` | 過渡時ノック回避保護 | `DUAL or D-4` | 参照元チェックシート: ekctrn |

#### 筒内INJ専用
| 関数 | モジュール | 条件コンパイル | ドキュメント参照 |
|------|-----------|----------------|------------------|
| `vdg_eclrdepi_emedi_dataget()` | 筒内弁沈降デポジット抑制保護 | `JEEFI == DUAL` | 参照元チェックシート: eclrdepi |
| `vdg_efpldlv_emedi_dataget()` | 低圧燃料系統燃圧基準圧制御 | `DUAL and 可変燃圧無` | 参照元チェックシート: efpldlv |
| `vdg_einjimb_emedi_dataget()` | インバランス時の噴射制御 | `AF学習インバランス and DUAL` | 参照元チェックシート: einjimb |
| `vdg_eactobd_emedi_dataget()` | OBD要件による吸気制御 | `DUAL and 使用` | 参照元チェックシート: eactobd |
| `vdg_eactgaf_emedi_dataget()` | A/F学習補正の代替吸気制御 | `JEEFI == DUAL` | 参照元チェックシート: eactgaf |
| `vdg_eactarefuel_emedi_dataget()` | 燃料種別推定の吸気制御 | `DUAL and FFV有効` | 参照元チェックシート: eactarefuel |
| `vdg_edwnpr_emedi_dataget()` | 燃圧抑制保護 | `JEEFI == DUAL` | 参照元チェックシート: edwnpr |
| `vdg_erdvap_emedi_dataget()` | ベーパ予防保護 | `JEEFI == DUAL` | 参照元チェックシート: erdvap |
| `vdg_eprvdil_emedi_dataget()` | 燃料希釈防止保護 | `JEEFI == DUAL` | 参照元チェックシート: eprvdil |
| `vdg_edthrctrl_emedi_dataget()` | ダイソ吸気制御 | `JEEFI == DUAL` | 参照元チェックシート: edthrctrl |

#### 共通機能
| 関数 | モジュール | 条件コンパイル | ドキュメント参照 |
|------|-----------|----------------|------------------|
| `vdg_eegstpvs_emedi_dataget()` | 噴射停止 | - | 参照元チェックシート: eegstpvs |
| `vdg_epwrup_emedi_dataget()` | 出力制限上昇制御 | - | 参照元チェックシート: epwrup |
| `vdg_efcfrctrl_emedi_dataget()` | 1気筒FC制御 | `GPF有効 and 使用` | 参照元チェックシート: efcfrctrl |

#### ベンチ機能
| 関数 | モジュール | 条件コンパイル | ドキュメント参照 |
|------|-----------|----------------|------------------|
| 専用IF | ベンチ機能用噴射要求 | `ベンチ機能有効 or ベンチ機能ポート有` | 参照元チェックシート: bench |

#### OBD関連（acw-16で追加の可能性）
| 関数候補 | モジュール | 条件コンパイル | ドキュメント参照 |
|----------|-----------|----------------|------------------|
| `vdg_eimbrq_emedi_dataget()`? | インバランスOBD要件 | `AF学習インバランス and DUAL` | 参照元チェックシート: imbrq |
| `vdg_emfinjrq_emedi_dataget()`? | 失火OBD要件 | `失火OBD有 and DUAL` | 参照元チェックシート: mfinjrq |
| `vdg_efkgdrq_emedi_dataget()`? | 燃料系OBD要件 | `燃料系OBD有 and DUAL` | 参照元チェックシート: fkgdrq |

#### PL多段噴射制御（acw-16で追加の可能性）
| 関数候補 | モジュール | 条件コンパイル | ドキュメント参照 |
|----------|-----------|----------------|------------------|
| `vdg_ebinjplctr_emedi_dataget()`? | ポート基本噴射制御 | `PL多段噴射有 and 使用` | 参照元チェックシート: binjplctr |
| `vdg_ebinjplctr_wc_emedi_dataget()`? | ポート基本噴射制御（暖機時） | `ALL_HV and PL多段 and 使用` | 参照元チェックシート: binjplctr_wc |
| `vdg_ebinjplctr_stahv_emedi_dataget()`? | ポート基本噴射制御（HV始動時） | `EG-MGプラグイン and FFV無 and PL多段 and 使用` | 参照元チェックシート: binjplctr_stahv |

#### 始動燃焼制御（acw-16で追加の可能性）
| 関数候補 | モジュール | 条件コンパイル | ドキュメント参照 |
|----------|-----------|----------------|------------------|
| `vdg_estacm_emedi_dataget()`? | 始動燃焼制御保護 | `(遠隔始動 or 車外始動) and SUB-CPU以外 and 使用` | 参照元チェックシート: stacm |

## 4. 調停処理ロジック

### 4.1 優先度ベース調停
```
優先度値が小さいほど高優先度
例: PRI=2 > PRI=4 > PRI=6 ...
```

### 4.2 調停アルゴリズム
```
1. 全機能モジュールからデータ取得
2. 有効なデータ（要求フラグON）をフィルタ
3. 優先度が最も高い（値が最小）データを選択
4. 選択データを出力構造体にコピー
5. リミット処理実施
```

### 4.3 要求ビットフラグ
| ビットフラグ | 意味 | 対応変数 |
|-------------|------|----------|
| `u4g_EMINJ_RQINJMODE` | 噴射モード要求有 | `u2_einjmod` |
| `u4g_EMINJ_RQINJPTN` | 噴射パターン要求有 | `u4_einjptn` |
| `u4g_EMINJ_RQAINJP1` | ポート1回目噴射開始角要求有 | `s2_eainjp1` |
| `u4g_EMINJ_RQAINJPN` | ポートn回目噴射開始角要求有（噴射回数） | `s2_eainjpn[]` |
| `u4g_EMINJ_RQAINJDN` | 筒内n回目噴射開始角要求有（噴射回数） | `s2_eainjdn[]` |
| `u4g_EMINJ_RQQINJSTPN` | ポートn回目始動噴射量要求有（噴射回数） | `s4_eqinjstpn[]` |
| `u4g_EMINJ_RQQINJSTDN` | 筒内n回目始動噴射量要求有（噴射回数） | `s4_eqinjstdn[]` |
| `u4g_EMINJ_RQQINJFLFIX` | FL固定噴射量要求有（噴射回数） | `s4_eqinjflfix[]` |
| `u4g_EMINJ_RQQINJPLFIX` | PL固定噴射量要求有（噴射回数） | `s4_eqinjplfix[]` |
| `u4g_EMINJ_RQQFC` | FC筒内噴射量要求有 | `s4_eqfc[]` |
| `u4g_EMINJ_RQK1F` | 1回目噴射量補正係数要求有 | `s2_ek1f` |
| `u4g_EMINJ_RQK2F` | 2回目噴射量補正係数要求有 | `s2_ek2f` |
| `u4g_EMINJ_RQK3F` | 3回目噴射量補正係数要求有 | `s2_ek3f` |
| `u4g_EMINJ_RQPRREQ` | 高圧燃圧目標圧力要求有 | `s2_eprreq` |
| `u4g_EMINJ_RQPRREQL` | 低圧燃圧目標圧力要求有 | `s2_eprreql` |
| `u4g_EMINJ_RQXQINJAST` | 始動後噴射量要求抑制要求有 | `bi_exqinjast` |
| `u4g_EMINJ_RQPLREQ` | PL噴射実施要求有 | `u1_explreq` |

## 5. 新規仕様（eminj-acw-16）での変更想定箇所

### 5.1 新規追加が想定される関数

#### OBD関連
```c
// インバランスOBD要件による吸気制御
#if (JEOBDAFIMB_D == u1g_EJCC_USE) && (JEEFI == u1g_EJCC_DUAL) && (EMINJ_IMBRQ_MEDI == ON)
static void vds_eminj_eimbrq_rap_dataget( st_EMINJ_EMINJ_DEF *ptt_store );
#endif

// 失火OBD要件による吸気制御
#if (JEOBDMF == u1g_EJCC_USE) && (JEEFI == u1g_EJCC_DUAL) && (EMINJ_MFINJRQ_MEDI == ON)
static void vds_eminj_emfinjrq_rap_dataget( st_EMINJ_EMINJ_DEF *ptt_store );
#endif

// 燃料系OBD要件による吸気制御
#if (JEOBDFKG == u1g_EJCC_USE) && (JEEFI == u1g_EJCC_DUAL) && (EMINJ_FKGDRQ_MEDI == ON)
static void vds_eminj_efkgdrq_rap_dataget( st_EMINJ_EMINJ_DEF *ptt_store );
#endif
```

#### PL多段噴射制御
```c
// ポート基本噴射制御
#if (JEPLMLT_E == u1g_EJCC_USE) && (EMINJ_BINJPLCTR_MEDI == ON)
static void vds_eminj_ebinjplctr_rap_dataget( st_EMINJ_EMINJ_DEF *ptt_store );
#endif

// ポート基本噴射制御（暖機時）
#if (JEALLHV_E == u1g_EJCC_ALLHV_E) && (JEPLMLT_E == u1g_EJCC_USE) && (EMINJ_BINJPLCTR_WC_MEDI == ON)
static void vds_eminj_ebinjplctr_wc_rap_dataget( st_EMINJ_EMINJ_DEF *ptt_store );
#endif

// ポート基本噴射制御（HV始動時）
#if (JEEGMG_E == u1g_EJCC_HVPLGR_E) && (JEFFV == u1g_EJCC_NOT_USE) && (JEPLMLT_E == u1g_EJCC_USE) && (EMINJ_BINJPLCTR_STAHV_MEDI == ON)
static void vds_eminj_ebinjplctr_stahv_rap_dataget( st_EMINJ_EMINJ_DEF *ptt_store );
#endif
```

#### 始動燃焼制御
```c
// 始動燃焼制御保護
#if ((JERMTCTR == u1g_EJCC_USE) || (JENVCTR == u1g_EJCC_USE)) && (JEMICN_E != u1g_EJCC_SUB_E) && (EMINJ_STACM_MEDI == ON)
static void vds_eminj_estacm_rap_dataget( st_EMINJ_EMINJ_DEF *ptt_store );
#endif
```

### 5.2 配列サイズ変更が想定される箇所

#### acw-15 → acw-16 配列変更
```c
// eminj.h より
// acw-15: 最大4回噴射（ポート）、4回噴射（筒内）
s2 s2_eainjpn[5];      // 5回に拡張（acw-13で追加）
s2 s2_eainjdn[6];      // 6回に拡張（acw-15で追加）
s4 s4_eqinjstpn[5];    // 5回に対応
s4 s4_eqinjstdn[6];    // 6回に対応
```

### 5.3 新規媒介ID追加箇所

vdg_eminj_8msm() 関数内の調停処理に以下のIDを追加：

```c
// OBD関連
#if (条件)
case u1g_EMINJ_IMBRQ_ID:
    vds_eminj_eimbrq_rap_dataget( &sts_data );
    break;
case u1g_EMINJ_MFINJRQ_ID:
    vds_eminj_emfinjrq_rap_dataget( &sts_data );
    break;
case u1g_EMINJ_FKGDRQ_ID:
    vds_eminj_efkgdrq_rap_dataget( &sts_data );
    break;
#endif

// PL多段噴射制御
#if (条件)
case u1g_EMINJ_BINJPLCTR_ID:
    vds_eminj_ebinjplctr_rap_dataget( &sts_data );
    break;
case u1g_EMINJ_BINJPLCTR_WC_ID:
    vds_eminj_ebinjplctr_wc_rap_dataget( &sts_data );
    break;
case u1g_EMINJ_BINJPLCTR_STAHV_ID:
    vds_eminj_ebinjplctr_stahv_rap_dataget( &sts_data );
    break;
#endif

// 始動燃焼制御
#if (条件)
case u1g_EMINJ_STACM_ID:
    vds_eminj_estacm_rap_dataget( &sts_data );
    break;
#endif

// フリーポート（FREE2-FREE11は既存、FREE0-FREE1も対応）
#if EMINJ_FREE0 == ON
case u1g_EMINJ_FREE0_ID:
    vds_eminj_efree0_emedi_dataget( &sts_data );
    break;
#endif
// ... FREE1 - FREE11
```

## 6. ドキュメント対応表

### 6.1 ロジック変更シート対応
| シート名 | 対応関数/処理 | 変更箇所 |
|---------|-------------|---------|
| 初期化処理 | `vdg_eminj_pwon()` | 変数初期値 |
| 調停処理 | `vdg_eminj_8msm()` | 優先度テーブル、調停ロジック |
| データ取得 | `vdg_eminj_einj_dataget()`, `vdg_eminj_eminj_dataget()` | 出力構造体 |
| 優先度調停ロジック | `vds_eminj_eminj_hpri()` | 比較アルゴリズム |
| リミット処理 | `vds_eminj_eminjlmt_hpri()` | 上下限値 |
| データ変換処理 | `vds_eminj_einj_dataconv()`, `vds_eminj_einj_dataconv_rev()` | 配列変換 |

### 6.2 参照元チェックシート対応
| 参照元モジュール | 呼び出し関数 | 条件 | 対応ID |
|----------------|------------|-----|--------|
| erdnves | `vdg_erdnves_group00_dataget()` | ALL HV | `u1g_EMINJ_RDNVES_ID` |
| estphv | `vdg_estphv_emedi_dataget()` | EG-MG | `u1g_EMINJ_STPHV_ID` |
| estahv | `vdg_estahv_emedi_dataget2()` | ALL HV and 使用 | `u1g_EMINJ_STAHV_ID` |
| ... | ... | ... | ... |
| imbrq (新規?) | `vdg_eimbrq_emedi_dataget()`? | OBD | `u1g_EMINJ_IMBRQ_ID` |
| mfinjrq (新規?) | `vdg_emfinjrq_emedi_dataget()`? | OBD | `u1g_EMINJ_MFINJRQ_ID` |
| fkgdrq (新規?) | `vdg_efkgdrq_emedi_dataget()`? | OBD | `u1g_EMINJ_FKGDRQ_ID` |
| binjplctr (新規?) | `vdg_ebinjplctr_emedi_dataget()`? | PL多段 | `u1g_EMINJ_BINJPLCTR_ID` |
| stacm (新規?) | `vdg_estacm_emedi_dataget()`? | 始動燃焼 | `u1g_EMINJ_STACM_ID` |

### 6.3 参照先チェックシート対応
| 参照先 | 呼び出し元 | IF関数 | データ型 |
|-------|----------|--------|---------|
| SAC | システム制御 | `vdg_eminj_einj_dataget()` | `st_EMINJ_EINJ` |
| APL | アプリケーション | `vdg_eminj_einj_dataget()` | `st_EMINJ_EINJ` |
| SAC | システム制御 | `vdg_eminj_eminj_dataget()` | `st_EMINJ_EMINJ` |

## 7. 変更作業の進め方

### 7.1 ロジック変更シートからの情報抽出
1. Excelファイルを開く
2. 各シートの変更内容を確認
3. 関数名、変数名、ロジック変更箇所を特定
4. ベースコードとの差分を明確化

### 7.2 参照元チェックシートからの情報抽出
1. 新規追加モジュールの特定
2. 呼び出し関数名の確認
3. コンパイル条件の確認
4. 優先度IDの確認

### 7.3 参照先チェックシートからの情報抽出
1. 外部IFの変更確認
2. データ構造体の変更確認
3. 呼び出し元の確認

### 7.4 コード生成手順
1. ベースコード（eminj_l_mat.c）をコピー
2. 新規関数の追加
3. 調停処理への新規ID追加
4. 配列サイズの更新
5. リミット値の更新
6. コンパイルスイッチの追加・更新
7. コメントの更新

## 8. 次ステップ

1. **ロジック変更シートの詳細分析**
   - Excel仕様書から具体的な変更内容を抽出
   
2. **参照チェックシートの詳細分析**
   - 新規モジュールの依存関係を確認
   
3. **差分コード生成**
   - sub4フォルダにeminj_l_mat.c（acw-16版）を生成

---

**作成者**: Copilot Workspace  
**作成日**: 2025-11-07  
**版数**: 1.0
