#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
仕様書差分分析スクリプト
Specification Difference Analysis Script

このスクリプトは、baseとnewフォルダ内の仕様書を比較し、
差分を分析してドキュメントを生成します。
"""

import os
import json
from pathlib import Path
from datetime import datetime

def get_file_info(file_path):
    """ファイル情報を取得"""
    stats = os.stat(file_path)
    return {
        'path': str(file_path),
        'size': stats.st_size,
        'modified': datetime.fromtimestamp(stats.st_mtime).strftime('%Y-%m-%d %H:%M:%S')
    }

def scan_directory(root_path):
    """ディレクトリをスキャンしてファイル情報を収集"""
    files = {}
    root = Path(root_path)
    
    for file_path in root.rglob('*'):
        if file_path.is_file():
            # ルートからの相対パスをキーとする
            rel_path = file_path.relative_to(root)
            files[str(rel_path)] = get_file_info(file_path)
    
    return files

def compare_specifications():
    """仕様書を比較"""
    base_path = Path('base')
    new_path = Path('new')
    
    print("📁 ベース仕様書のスキャン中...")
    base_files = scan_directory(base_path)
    
    print("📁 新規仕様書のスキャン中...")
    new_files = scan_directory(new_path)
    
    # ファイル名のみを比較するための正規化
    base_names = {Path(k).name: k for k in base_files.keys()}
    new_names = {Path(k).name: k for k in new_files.keys()}
    
    # 差分分析
    added_files = []
    removed_files = []
    common_files = []
    modified_files = []
    
    # 新規追加されたファイル
    for name, path in new_names.items():
        if name not in base_names:
            added_files.append(new_files[path])
    
    # 削除されたファイル
    for name, path in base_names.items():
        if name not in new_names:
            removed_files.append(base_files[path])
    
    # 共通ファイル（変更の可能性あり）
    for name in base_names.keys():
        if name in new_names:
            base_path_rel = base_names[name]
            new_path_rel = new_names[name]
            common_files.append({
                'name': name,
                'base': base_files[base_path_rel],
                'new': new_files[new_path_rel]
            })
            
            # サイズが異なる場合は変更ありと判断
            if base_files[base_path_rel]['size'] != new_files[new_path_rel]['size']:
                modified_files.append({
                    'name': name,
                    'base': base_files[base_path_rel],
                    'new': new_files[new_path_rel]
                })
    
    return {
        'added': added_files,
        'removed': removed_files,
        'common': common_files,
        'modified': modified_files,
        'base_total': len(base_files),
        'new_total': len(new_files)
    }

def generate_markdown_report(analysis):
    """マークダウン形式のレポートを生成"""
    report = []
    
    report.append("# 仕様書差分分析レポート")
    report.append("")
    report.append(f"**分析日時**: {datetime.now().strftime('%Y年%m月%d日 %H:%M:%S')}")
    report.append("")
    
    report.append("## 📊 サマリー")
    report.append("")
    report.append(f"- **ベース仕様書ファイル数**: {analysis['base_total']}")
    report.append(f"- **新規仕様書ファイル数**: {analysis['new_total']}")
    report.append(f"- **新規追加ファイル**: {len(analysis['added'])}")
    report.append(f"- **削除ファイル**: {len(analysis['removed'])}")
    report.append(f"- **変更の可能性があるファイル**: {len(analysis['modified'])}")
    report.append("")
    
    if analysis['added']:
        report.append("## ✅ 新規追加ファイル")
        report.append("")
        report.append("| ファイル名 | サイズ | 更新日時 |")
        report.append("|-----------|--------|----------|")
        for file in analysis['added']:
            name = Path(file['path']).name
            size = f"{file['size']:,} bytes"
            modified = file['modified']
            report.append(f"| {name} | {size} | {modified} |")
        report.append("")
    
    if analysis['removed']:
        report.append("## ❌ 削除ファイル")
        report.append("")
        report.append("| ファイル名 | サイズ | 更新日時 |")
        report.append("|-----------|--------|----------|")
        for file in analysis['removed']:
            name = Path(file['path']).name
            size = f"{file['size']:,} bytes"
            modified = file['modified']
            report.append(f"| {name} | {size} | {modified} |")
        report.append("")
    
    if analysis['modified']:
        report.append("## 🔄 変更の可能性があるファイル")
        report.append("")
        report.append("| ファイル名 | ベースサイズ | 新規サイズ | サイズ差分 |")
        report.append("|-----------|------------|----------|----------|")
        for file in analysis['modified']:
            name = file['name']
            base_size = file['base']['size']
            new_size = file['new']['size']
            diff = new_size - base_size
            diff_str = f"+{diff:,}" if diff > 0 else f"{diff:,}"
            report.append(f"| {name} | {base_size:,} | {new_size:,} | {diff_str} bytes |")
        report.append("")
    
    report.append("## 📋 共通ファイル一覧")
    report.append("")
    report.append("| ファイル名 | ベースパス | 新規パス |")
    report.append("|-----------|-----------|---------|")
    for file in analysis['common']:
        name = file['name']
        base_path = Path(file['base']['path']).parent
        new_path = Path(file['new']['path']).parent
        report.append(f"| {name} | {base_path} | {new_path} |")
    report.append("")
    
    return "\n".join(report)

def generate_change_list(analysis):
    """変更点一覧を生成"""
    changes = []
    
    changes.append("# 変更点一覧")
    changes.append("")
    changes.append(f"**作成日**: {datetime.now().strftime('%Y年%m月%d日')}")
    changes.append("")
    
    changes.append("## 変更概要")
    changes.append("")
    changes.append("### バージョン情報")
    changes.append("- **旧バージョン**: eminj-acw-15-c-t")
    changes.append("- **新バージョン**: eminj-acw-16-a-t")
    changes.append("")
    
    changes.append("### ファイル変更統計")
    changes.append(f"- 追加: {len(analysis['added'])}ファイル")
    changes.append(f"- 削除: {len(analysis['removed'])}ファイル")
    changes.append(f"- 変更: {len(analysis['modified'])}ファイル")
    changes.append("")
    
    # 詳細な変更点
    change_num = 1
    
    if analysis['added']:
        changes.append("## 詳細変更点")
        changes.append("")
        for file in analysis['added']:
            name = Path(file['path']).name
            changes.append(f"### 変更 #{change_num}: 新規ファイル追加")
            changes.append(f"- **ファイル名**: {name}")
            changes.append(f"- **種別**: 新規追加")
            changes.append(f"- **サイズ**: {file['size']:,} bytes")
            changes.append("")
            change_num += 1
    
    if analysis['removed']:
        for file in analysis['removed']:
            name = Path(file['path']).name
            changes.append(f"### 変更 #{change_num}: ファイル削除")
            changes.append(f"- **ファイル名**: {name}")
            changes.append(f"- **種別**: 削除")
            changes.append(f"- **元のサイズ**: {file['size']:,} bytes")
            changes.append("")
            change_num += 1
    
    if analysis['modified']:
        for file in analysis['modified']:
            name = file['name']
            base_size = file['base']['size']
            new_size = file['new']['size']
            diff = new_size - base_size
            changes.append(f"### 変更 #{change_num}: ファイル更新")
            changes.append(f"- **ファイル名**: {name}")
            changes.append(f"- **種別**: 更新")
            changes.append(f"- **サイズ変更**: {base_size:,} → {new_size:,} bytes ({diff:+,} bytes)")
            changes.append("")
            change_num += 1
    
    return "\n".join(changes)

def main():
    """メイン処理"""
    print("=" * 60)
    print("🔍 仕様書差分分析ツール")
    print("=" * 60)
    print()
    
    # 分析実行
    analysis = compare_specifications()
    
    print()
    print("=" * 60)
    print("📝 レポート生成中...")
    print("=" * 60)
    
    # マークダウンレポート生成
    markdown_report = generate_markdown_report(analysis)
    with open('差分分析レポート.md', 'w', encoding='utf-8') as f:
        f.write(markdown_report)
    print("✅ 差分分析レポート.md を生成しました")
    
    # 変更点一覧生成
    change_list = generate_change_list(analysis)
    with open('変更点一覧.md', 'w', encoding='utf-8') as f:
        f.write(change_list)
    print("✅ 変更点一覧.md を生成しました")
    
    # JSON形式でも出力
    with open('analysis_result.json', 'w', encoding='utf-8') as f:
        json.dump(analysis, f, ensure_ascii=False, indent=2)
    print("✅ analysis_result.json を生成しました")
    
    print()
    print("=" * 60)
    print("✨ 分析完了")
    print("=" * 60)

if __name__ == '__main__':
    main()
