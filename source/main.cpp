// ---------------------------------------------------------------------
// main.cpp
// Cﾌﾟﾛｸﾞﾗﾑを見やすく直す
// Visual-C

// 2009.04.22	V1.00	新規作成
// 2009.04.22	V1.01	paramerのdebug
// 2009.04.24	V1.02	"#if"完成の分離
// 2009.04.27	V1.03	"#include"をTAB禁止した.
// 2009.04.28	V1.04	"/*"～"*/"--> "//"～のｵﾌﾟｼｮﾝ指定追加
// 2009.04.28	V1.04	"renew.ini"ﾌｧｲﾙを自動作成追加
// 2009.05.09	V1.05	ｺﾒﾝﾄでもTABを可能にした
// 2009.05.18	V1.06	ｺﾒﾝﾄのdebug
// 2009.05.31	V1.07	debug
// 2009.10.26	V1.08	ﾌﾟﾛｸﾞﾗﾑでTABが4以上でそろえるのをｽﾍﾟｰｽにした
// 2009.10.24	V1.09	修正後のﾌｧｲﾙを原型名+.new とした
// 2009.10.29	V1.10	ｺﾒﾝﾄの見直し。
// 2009.11.13	V1.11	'{'～'}'の見直し, #defineの後のTABを指定できるようにした
// 2009.11.17	V1.12	else の後の改行する/しないを追加.caseのTABズレを修正
// 2009.11.19	V1.13	if(),else の何もしないｺﾏﾝﾄﾞ追加
// 2009.11.28	V1.14	TABの最低と最高の範囲を追加した
// 2009.12.01	V1.15	#ifdef の extern "C" { でｴﾗｰを回避した
// 2009.12.01	V1.16	'{'～'}'の中間ｺﾒﾝﾄを合わせない, ｺﾒﾝﾄの調査を改善した
// 2009.12.09	V1.17	'{'～'}'の最初のTABを自動調整した, #defineの最適化ｺﾏﾝﾄﾞ追加
// 2010.01.04	V1.18	case分と関数の２行の場合のdebug, #include内のｽﾍﾟｰｽｶｯﾄ
// 2010.01.18	V1.19	int* abcd などのtypeのすぐ後の'*'を有効にした
//						long_commentに "2:ﾌﾟﾛｸﾞﾗﾑの場合は調整する"を追加,
// 2010.05.14	V1.20	iniﾌｧｲﾙの修正.ｿｰｽの行数が少ない時のdebug
// 2010.12.18	V1.21	big_kakko_inの削除
// 2011.01.20	V1.22	'\'の処理追加
// 2011.01.26	V1.23	#defineのdebug
// 2011.03.11	V1.24	#ifdefのdebug, ｺﾒﾝﾄのみ行の直し,iniﾌｧｲﾙの見直し
// 2011.03.15	V1.25	TABの範囲設定を追加.cut_comment(全てのｺﾒﾝﾄを削除する)を削除
// 2011.03.18	V1.26	見直し
// 2011.03.23	V1.27	limit_line追加
// 2011.03.24	V1.28	cut_comment(全てのｺﾒﾝﾄを削除する)を復活
// 2011.03.24	V1.29	//+ﾌﾟﾛｸﾞﾗﾑのTAB位置見直し
// 2011.04.13	V1.30	ｿｰｽ名変更
// 2011.04.18	V1.31	iniﾌｧｲﾙ見直し
// 2011.05.12	V1.32	big_kakko_pairの追加
// 2011.05.13	V1.33	big_kakko_pairのdebug
// 2011.05.19	V1.34	return処理の見直し,±数字の見直し
// 2011.05.26	V1.35	その他の{}に改行して追加
// 2011.05.31	V1.36	{}のdebug
// 2011.06.04	V1.37	stackの見直し
// 2011.06.28	V1.38	long_commentの 2:を削除
// 2011.07.09	V1.39	より原文に近くした
// 2011.07.20	V1.40	Visual-C++も可能にした
// 2011.07.21	V1.41	Visual-C++強化
// 2011.07.30	V1.42	Visual-C++強化, 括弧の前後をｽﾍﾟｰｽの有無に変更
// 2011.08.29	V1.43	tmp_ﾌｧｲﾙの作成に変更, ｺﾒﾝﾄ判定の変更
// 2011.08.29	V1.44	#pragma asm～endasm 追加
// 2012.05.14	V1.45	文字列内の'$'を有効とした
// 2012.05.19	V1.46	最後の開業ｺｰﾄﾞが無くてもｴﾗｰとしないようにした
// 2012.05.21	V1.47	-bｵﾌﾟｼｮﾝの-b=2 (oldファイルを作らないを追加した)
// 2012.05.24	V1.48	TAB位置を出来るだけもとのままにするのを削除
// 2012.07.07	V1.49	'\'の処理修正。
// 2012.08.05	V1.50	typedefと追加
// 2012.08.16	V1.51	"//"の後のずれをdebug. CSprig追加
// 2012.08.30	V1.52	"\"の処理追加
// 2012.08.30	V1.53	all-xを追加
// 2012.10.25	V1.54	数字の場合はｽﾍﾟｰｽ等の区切りまで取り込むに変更(不動小数点対策)
// 2013.06.26	V1.55	数字の場合はｽﾍﾟｰｽ等の区切りまで取り込むに変更(不動小数点対策)debug
// 2013.07.09	V1.56	Windows xp,7(32bit/64bit)対応
// 2013.08.06	V1.57	数字の後のL,F,<,+,- のdebug
// 2013.08.09	V1.58	':','::' の前後のｽﾍﾟｰｽの処理を選択式にした。
// 2013.08.20	V1.59	renew.ini の変更
// 2013.08.25	V1.60	'\'の処理変更
// 2013.09.10	V1.61	#if #else #ifend のTAB stack 記録追加
// 2013.09.26	V1.62	TABの見直し
// 2013.10.21	V1.63	struct, unionの見直し
// 2019.08.16	V1.70	utf8対応
// 2019.09.02	V1.71	ShiftJIS/utf8自動判定
// 2020.03.23	V1.72	. の後の処理をスペースカットにした
// 2020.05.04	V1.73	1行の最大ソースを512から1024文字に拡張した
// --------------------------------------------------------------------------------
char environs[] = "Windows 10 用";
char versions[] = "1.73";

#define __RENEW__

#include <windows.h>
#include <stdio.h>
#include <process.h>
#include <stdlib.h>
#include <conio.h>
#include <io.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>
#include <fcntl.h>
#include <time.h>
#include <direct.h>
#include <errno.h>

#include <iostream>
#include <string>
using namespace std;

#include "struct.h"
#include "renew.h"

#include "main_e.h"
#include "sub1_e.h"
#include "sub2_e.h"
#include "sub3_e.h"

// ====================================================================
// 【機能】1byteのﾊﾞｲﾅﾘを2桁のHEXに変換
// 【入力】ﾊﾞｲﾅﾘﾃﾞｰﾀ,書き込みﾊﾞｯﾌｧ
// 【出力】なし
// 【備考】
// ====================================================================
void obj_hex2( int obj_data, char *wr_buf )
{
	obj_data &= 0xff;
	wr_buf[0] = hex_map[obj_data / 16];
	wr_buf[1] = hex_map[obj_data & 0x0f];
}
// ====================================================================
// 【機能】ｱｽｷｰの0からFのHEXをBINに変換
// 【入力】ｱｽｷｰ文字列
// 【出力】HEXﾃﾞｰﾀ(ｴﾗｰ時も0を返す)
// 【備考】
// ====================================================================
int hex_bin( int char_data )
{
	char_data &= 0xff;
	if( (char_data >= '0') && (char_data <= '9') ) return( char_data - '0' );		// 数値 HEX 0 ～ 9
	else if( (char_data >= 'A') && (char_data <= 'F') ) return( char_data - 55 );	// ｱﾙﾌｧﾍﾞｯﾄ A ～ F
	else if( (char_data >= 'a') && (char_data <= 'f') ) return( char_data - 87 );	// ｱﾙﾌｧﾍﾞｯﾄ a ～ f
	else return( 0 );
}
// ====================================================================
// 【機能】hex以外の文字までHEXのみを取り込む
// 【入力】なし
// 【出力】int
// 【備考】
// ====================================================================
int hex_binn( char *s_buf )
{
	int		bin;
	char	moji;

	bin = 0;
	moji = *s_buf++;
	while( isxdigit(moji) )
	{
		bin = bin * 16 + hex_bin( moji );
		moji = *s_buf++;
	}
	return( bin );
}
// ---------------------------------------------------
// 10進/16進を自動判断する
// s_buf 文字列
// cnt 結果
// return 最後に変換した数字の種類 0:error, 10:10進数, 16:16進数
// ---------------------------------------------------
// int bcd_hex_bin( char *s_buf, int *kekka )
// {
//	int type, cnt, n, ret;

//	ret = 0;
//	type = cnt = 0;
//	n = 0;
//	while( s_buf[n] && _isdigit(s_buf[n]) == 0 )
//	{
//		if( s_buf[n] == '-' ) type = 1;
//		else if( s_buf[n] == '+' ) type = 0;
//		else if( s_buf[n] != ' ' )
//		{
//			*kekka = 0;
//			return( 0 );
//		}
//		n++;
//	}
//	if( s_buf[n] == '0' && (s_buf[n + 1] == 'x' || s_buf[n + 1] == 'X') )
//	{
//		cnt = hex_binn( &s_buf[n + 2] ); // 16進
//		ret = 16;
//	}
//	else {
//		cnt = atoi( &s_buf[n] ); // 10進数
//		ret = 10;
//	}
//	if( type ) cnt = -cnt;
//	*kekka = cnt;
//	return( ret );
// }
// ---------------------------------------------------------------------
// ｽﾍﾟ-ｽ, tabをﾊﾟｽ
// ---------------------------------------------------------------------
int pass_space( char *s_buf )
{
	int n;

	for( n = 0; s_buf[n]; n++ )
	{
		if( s_buf[n] != _SOH && s_buf[n] != ' ' ) break;
	}
	return( n );
}
// ---------------------------------------------------------------------
// 一行入力ﾕｰﾃｨﾘﾃｨ
// 【機能】ﾌｧｲﾙから改行文字まで取り込む(CR+LF-->LF)
// 【入力】max_len	1～max_len:最大buf ｻｲｽﾞ
// 【出力】return	1～max_len:長さ, 0: end of file
// 【備考】ｻｲｽﾞは最大max_len - 3 文字まで
// ---------------------------------------------------------------------
int getln( FILE *fp, char *d_buf, int max_len )
{
	int		len, c;
	char	buf[200];

	len = 0;
	while( (c = getc(fp)) != EOF )
	{
		if( c == _CR ) continue; // 無視

		d_buf[len++] = c;
		if( len >= (max_len - 3) )
		{ // 残りは捨てる
			sprintf( buf, "%s(%d) 出力ﾌｧｲﾙ[line=%d]", src_full_name, src_line_no + 1, max_line + 1 );
			err_trap( 2, -36, buf, 0 ); // "1行が長すぎる"
		}
		if( c == _LF ) break;
	}
	d_buf[len] = 0;
	if( len ) // 2012.05.19 削除
	{
		if( d_buf[len - 1] != _LF )
		{ // 最後の行が改行ｺｰﾄﾞなし
//			sprintf( buf, "%s(%d) 出力ﾌｧｲﾙ[line=%d]", src_full_name, src_line_no + 1, max_line + 1 ); // 2012.05.19削除
//			err_trap( 0, -31, buf, 0 ); // "改行コードがない"
			d_buf[len++] = _LF;
			d_buf[len] = 0;
		}
	}
	return( len );
}
// ====================================================================
// 【機能】終了時の処理
// 【出力】なし
// 【備考】
// ====================================================================

void close_all( void )
{
	if( fp_src ) fclose( fp_src );
	if( fp_err ) fclose( fp_err );
	fp_src = fp_err = NULL;
}
// -------------- 終了処理 -----------------------
void wait_exit( int ret_no )
{
	int moji;

	close_all();
	printf( "終了\r\n" );
	printf( "\r\n何かのｷｰ入力で終了\r\n" );
	moji = getchar();
//	printf( "moji = %xh", moji );

	exit( ret_no );
}
// ====================================================================
// 【機能】errorをsave
// 【入力】mes_no
// 【出力】なし
// 【備考】
// ====================================================================
void save_error_file( char *mes_err )
{
	if( total_err_cnt > 100 ) return;
	fp_err = fopen( err_name, "a+" );
	if( fp_err == NULL ) return;

//	fseek( fp_err, 0L, SEEK_END ); // 最後へ移動
	fprintf( fp_err, "%s\n", mes_err );
	fclose( fp_err );
	fp_err = NULL;
	total_err_cnt++;
}
// ---------------------------------------------------------------------
// mode 0:記録 & ｴﾗｰﾒｯｾｰｼﾞ表示--> return
// mode 1:記録 & ｴﾗｰﾒｯｾｰｼﾞ表示&ｷｰ入力確認 --> return
// mode 2:記録 & ｴﾗｰﾒｯｾｰｼﾞ表示 --> exit
// mode 3:記録 & 警告ﾒｯｾｰｼﾞ表示--> return
// path_name ﾌｧｲﾙに記録の時追加
// ---------------------------------------------------------------------
void err_trap( int mode, int err_no, char *mes_buf, char *path_name )
{
	static int	err_cnt = 0;
	int			n;
	char		*mes_p, buf[500], buf2[500];

	if( err_no < 0 ) err_no = -err_no;
	if( err_no == 999 ) return;
	if( err_no == 1 ) return; // 中止

	if( mes_buf )
	{
		for( n = 0; mes_buf[n] != 0; n++ )
		{
			if( (Uchar)mes_buf[n] < ' ' ) mes_buf[n] = ' '; // spaceに変換
		}
	}

	switch( err_no )
	{
	case 0:
		return;

	case 1: mes_p = "処理を中断しました"; break;
	case 2: mes_p = "ﾒﾓﾘｰが不足で起動できません"; break;
	case 3: mes_p = "ﾌｧｲﾙが見つかりません"; break;
	case 4: mes_p = "ﾃﾞｰﾀが無いのに読み出した"; break;
	case 5: mes_p = "ﾌｧｲﾙﾘｰﾄﾞｵｰﾌﾟﾝ失敗"; break;
	case 6: mes_p = "ﾌｧｲﾙﾗｲﾄｵｰﾌﾟﾝ失敗"; break;
	case 7: mes_p = "ﾌｧｲﾙが異常です"; break;
	case 8: mes_p = "書き込みが出来ません"; break;
	case 9: mes_p = "ﾌｧｲﾙの長さが足りません"; break;
	case 10: mes_p = "その他の予約語発見"; break;
	case 11: mes_p = "buffer over"; break;
	case 12: mes_p = "TAB over"; break;
	case 13: mes_p = "TOK buffer over"; break;
	case 14: mes_p = "SUB buffer over"; break;
	case 15: mes_p = "TAB stack over"; break;
	case 16: mes_p = "TAB stack under"; break;
	case 17: mes_p = "BUG 切り出し"; break;
	case 18: mes_p = "ｿｰｽﾌｧｲﾙｻｲｽﾞがｾﾞﾛ"; break;
	case 19: mes_p = "malloc()が確保出来ない"; break;
	case 20: mes_p = "内部memoryがoverした(bug)"; break;
	case 21: mes_p = "TAB_stack がｾﾞﾛ"; break;
	case 22: mes_p = "'/*'か'*/'に注意"; break;
	case 23: mes_p = "';'が異常"; break;
	case 24: mes_p = "TAB位置が異常"; break;
	case 25: mes_p = "'}'が異常"; break;
	case 26: mes_p = "')'が異常"; break;
	case 27: mes_p = "TAB stackが異常"; break;
	case 28: mes_p = ".ini ﾌｧｲﾙのｺﾏﾝﾄﾞが異常"; break;
	case 29: mes_p = "';'が2つある"; break;
	case 30: mes_p = "改行後の読み出しが出来ない"; break;
	case 31: mes_p = "改行コードがない"; break;
	case 32: mes_p = "'*/'がない"; break;
	case 33: mes_p = "'#'が異常"; break;
	case 34: mes_p = "プログラム異常"; break;
	case 35: mes_p = "#pragram endasm がない"; break;
	case 36: mes_p = "1行が長すぎる"; break;
	case 37: mes_p = "typedefの定義が長すぎる"; break;
	case 38: mes_p = "typedefの登録数が多すぎる"; break;
	case 39: mes_p = "文字列のﾀﾞﾌﾞﾙｺｰﾃﾝｼｮ+aを注意"; break;

	default: mes_p = "for_debug"; break; // 通常300番台以上
	}
	if( mes_p )
	{
		if( mode == 3 )
		{ // 警告
			if( mes_buf && mes_buf[0] ) sprintf( buf, "%s, warning=#%d:%s", mes_buf, err_no, mes_p );
			else sprintf( buf, "warning=#%d:%s", err_no, mes_p );
		}
		else {
			if( mes_buf && mes_buf[0] ) sprintf( buf, "%s, error=#%d:%s", mes_buf, err_no, mes_p );
			else sprintf( buf, "error=#%d:%s", err_no, mes_p );
		}
	}
	else {
		if( mode == 3 )
		{ // 警告
			if( mes_buf && mes_buf[0] ) sprintf( buf, "%s, warning=#%d:", mes_buf, err_no );
			else sprintf( buf, "warning=#%d:", err_no );
		}
		else {
			if( mes_buf && mes_buf[0] ) sprintf( buf, "%s, error=#%d:", mes_buf, err_no );
			else sprintf( buf, "error=#%d:", err_no );
		}
	}

	if( path_name && path_name[0] )
	{
		sprintf( buf2, "%s\\%s", path_name, buf );
		save_error_file( buf2 ); // 記録
	}
	else save_error_file( buf );	// 記録

	buf[79] = 0;					// 長さ制限する
	if( ++err_cnt < 50 )
	{ // 画面表示を制限する
		printf( "\r" );
		printf( buf );
		printf( "\r\n" );
		if( mode == 1 )
		{
			printf( "何かキーを押して下さい" );
			while( getchar() == -1 );
			printf( "\n\n" );
		}
	}
	if( mode == 2 )
	{
//		reform_story(); // 内部変数とｸﾞﾛｰﾊﾞﾙの区別をする
//		if( max_line ) save_dst_file();
		printf( "\r\nｴﾗｰで中止しました\r\n" );
		wait_exit( 2 );
	}
}
// ---------------------------------------------------
// mode 0:記録 & ｴﾗｰﾒｯｾｰｼﾞ表示--> return
// mode 1:記録 & ｴﾗｰﾒｯｾｰｼﾞ表示&ｷｰ入力確認 --> return
// mode 2:記録 & ｴﾗｰﾒｯｾｰｼﾞ表示 --> exit
// mode 3:記録 & 出力ﾌｧｲﾙに追加出力
// mode 4:mode=2と同じだがdebug情報のsaveする
// messageの代わりに行番号を表示(記録)
// ---------------------------------------------------
void err_trap_line( int mode, int err_no, char *s_buf )
{
	char buf[500];

	if( s_buf == NULL ) sprintf( buf, "%s(%d) 出力ﾌｧｲﾙ[line=%d]", src_full_name, src_line_no, max_line + 1 );	// editerは1番から始まる補正
	else sprintf( buf, "%s(%d) ｿｰｽﾌｧｲﾙ 内容(%s)", src_full_name, src_line_no, s_buf );							// editerは1番から始まる補正
	err_trap( mode, err_no, buf, 0 );
}
// ---------------------------------------------------------------------
// 使い方
// ---------------------------------------------------------------------
void usage( void )
{
	printf(
		"\n"
		" 書式     :   renew.exe file_name < -parameter >\n"
		" file_name: Cのソースファイル.(省略できない) '*','?'が使用可能\n"
		" parameter: オプションンパラメータ(iniﾌｧｲﾙより優先する)\n"
		"\n"
		);
	wait_exit( 1 );
}

// ---------------------------------------------------------------------
// debug情報表示
// ---------------------------------------------------------------------
void disp_debug_para0( void )
{
	printf(
		"\n"
		"debug情報ﾊﾟﾗﾒｰﾀ debug=n\n"
		" n = 1: tab_stack_cnt表示 TABの位置記録番号\n"
		" n = 2: big_kakko_cnt表示 '{'の数\n"
		" n = 3: if_stack_top表示 if()... , else ...のTAB記録番号\n"
		" n = 4: hijo_flag表示 補助名称記録\n"
		" n = 5: tab_pos表示 現在のTAB数\n"
		" n = 6: src_line_no表示 ソース行の番号\n"
		" n = 7: src_com_pos位置表示 ソース コメント位置\n"
		" n = 8: sub_type表示 char, int,long 等\n"
		"\n"
		);
	wait_exit( 1 );
}

// ---------------------------------------------------------------------
// debug情報表示
// ---------------------------------------------------------------------
void disp_debug_para1( void )
{
	switch( debug_mode )
	{
	case 1: fdata->debug_joho = tab_stack_cnt; break;	// debug用 tab_stack表示
	case 2: fdata->debug_joho = big_kakko_cnt; break;	// debug用 big_kakko_cnt表示
	case 3: fdata->debug_joho = if_stack_top; break;	// debug用 if_stack_top表示
	case 4: break;										// debug用 line_type表示
	case 5: break;										// debug用 tab_pos表示
	case 6: break;										// debug用 src_line_no表示
	case 7: break;										// debug用 src_com_pos位置表示
	case 8: break;										// debug用 sub_type表示
	}
}
// ---------------------------------------------------------------------
// debug情報表示
// ---------------------------------------------------------------------
void disp_debug_para2( char *d_buf )
{
	char buf[CHAR_SIZE2];

	switch( debug_mode )
	{
	case 1: // debug用 tab_stack_cnt表示
		get_debug_type_map( buf, fdata->line_type );
		sprintf( &buf[10], "[STACK=%02d]%s", fdata->debug_joho, d_buf );
		strcpy( d_buf, buf );
		break;

	case 2: // debug用 big_kakko_cnt表示
		get_debug_type_map( buf, fdata->ope_type );
		sprintf( &buf[10], "[{=%02d]%s", fdata->debug_joho, d_buf );
		strcpy( d_buf, buf );
		break;

	case 3: // debug用 if_statck_cnt表示
		get_debug_type_map( buf, fdata->line_type );
		sprintf( &buf[10], "[IFSTK=%02d]%s", fdata->debug_joho, d_buf );
		strcpy( d_buf, buf );
		break;

	case 4: // debug用 hijo_flag表示
		get_debug_type_map( buf, fdata->line_type );
		sprintf( &buf[10], "[%08x]%s", fdata->hojo_flag, d_buf );
		strcpy( d_buf, buf );
		break;

	case 5: // debug用 tab_pos表示
		get_debug_type_map( buf, fdata->line_type );
		sprintf( &buf[10], "[TAB  =%02d]%s", fdata->tab_pos, d_buf );
		strcpy( d_buf, buf );
		break;

	case 6: // debug用 src_line_no表示
		get_debug_type_map( buf, fdata->line_type );
		sprintf( &buf[10], "[%08d]%s", fdata->src_line_no, d_buf );
		strcpy( d_buf, buf );
		break;

	case 7: // debug用 src_com_pos位置表示
		get_debug_type_map( buf, fdata->line_type );
		sprintf( &buf[10], "[COM=%04d]%s", fdata->src_com_pos, d_buf );
		strcpy( d_buf, buf );
		break;

	case 8: // debug用 sub_type表示
		get_debug_type_map( buf, fdata->line_type );
		sprintf( &buf[10], "[SUB=0x%02x]%s", fdata->sub_type, d_buf );
		strcpy( d_buf, buf );
		break;
	}
}
// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
int get_cur_path_name( char *p_name, int len )
{
	errno = 0;			// system 用
	if( _getcwd(p_name, len - 2) != NULL ) p_name[len - 1] = 0;
	else p_name[0] = 0; // error
	if( errno )
	{
		p_name[0] = 0;									// error
		printf( "ﾃﾞｨｽｸの準備ができていません\r\n" );	// 表示&ｷｰ入力待ち
		return( -2 );
	}
	return( 0 );
}
// ---------------------------------------------------------------------
// 文字列の切り出し(細かく分離)
// 各分離で切り取り
// max 長さは100文字まで
// return s_bufの次の位置
// ---------------------------------------------------------------------
int get_def_tok( char *d_buf, char *s_buf, int *tok_len )
{
	int		cnt, com_flag, put_cnt, max_len;
	char	moji;

	*tok_len = 0;
	cnt = 0;
	com_flag = 0;
	put_cnt = 0;
	max_len = CHAR_SIZE;
	moji = s_buf[cnt];
	while( moji && moji != _CR && moji != _LF )
	{
		if( com_flag == 2 && (moji == ' ' || moji == _TAB) ) break;
		if( com_flag || (com_flag == 0 && moji != ' ' && moji != _TAB) )
		{ // 文字
			d_buf[put_cnt++] = moji;
			if( put_cnt >= max_len ) break;
			if( com_flag == 0 )
			{ // 最初
				if( moji == ';' ) com_flag = 1; // 以後comment or 擬似命令
				else com_flag = 2;
			}
		}
		moji = s_buf[++cnt];
	}
	d_buf[put_cnt] = 0;

	*tok_len = put_cnt;
	return( cnt );
}
// ---------------------------------------------------------------------
// renew.ini ﾌｧｲﾙを作る
// ---------------------------------------------------------------------
void make_ini_file( void )
{
	char *ini_mes[] =
	{
		";\n",
		"; C用ソース ファイルを見やすく整える\n",
		"; このファイルの行の最初に';'があればコメントとして処理する\n",
		";\n",
		"; renew.exe  実行ファイル\n",
		"; renew.ini  条件ファイル(無い場合は,プログラム起動時新規作成する)\n",
		";\n",
		"; 使い方\n",
		"; 実行     :  renew.exe<Enter> <--- 最初に実行\n",
		"; 書式     :  file_name <-parameter>\n",
		";                ↑            ↑parameter: オプションンパラメータ(iniﾌｧｲﾙより優先する,省略可能)\n",
		";                ↑file_name: Cのソースファイル.(省略できない) '*','?'が使用可能\n",
		";\n",
		"; 起動時に下記書式のparameterを指定するとこのiniﾌｧｲﾙより優先するので一時的に変更したい時に有効\n",
		"; parameterを複数指定する時は,ｽﾍﾟｰｽで区切って指定する事\n",
		"; 例 renew.exe *.c\n",
		"; 例 renew.exe *.h -a3\n",
		";                   ↑高整形 指定\n",
		"; 例 renew.exe *.c -m0 -u0 -t0\n",
		";                   ↑  ↑  ↑\n",
		";                   ↑  ↑  parameterを複数指定する時は,ｽﾍﾟｰｽで区切って指定する事\n",
		";                   ↑  while(){} の'{'～'}'の縦の位置を0:文書整形のみする\n",
		";                   行の処理 0:何もしない\n",
		"; 例 renew.exe *.h -b2 -o1\n",
		";                   ↑  ↑\n",
		";                   ↑  #if, #else, #endif のTABを調正する(TABがずれた時の確認用) 1:TAB調整\n",
		";                   ソース名をリネームして+.oldとし,ソースファイルを整形する\n",
		"; 例 renew.exe *.h -m1\n",
		";                   ↑\n",
		";                  コメント行の処理 1:ﾌﾟﾛｸﾞﾗﾑの場合は調整する+TABを揃える\n",
		"; debug_modeの使い方 範囲は 1～9。renew_debug.txt と renew_debug2.txt が作られる\n",
		"; 例 renew.exe *.c -z9\n",
		";                   ↑\n",
		";                  debugで記録する明細表示\n",
		"; 例 renew.exe *.c -z1\n",
		";                   ↑\n",
		";                   tab_stack番号表示(どこでTABがずれたか分かる)\n",
		";\n",
		";------------------ 以下条件部 ------------------------\n",
		"; 下記の数字(z)の通りの数字を希望に応じて変更する\n",
		"\n",
		";-- ｺﾏﾝﾄﾞ-------- 数字(z) --; ﾊﾟﾗﾒｰﾀ ----- 内容 -------------------------------------------------------\n",
		"\n",
		"all                 0       ; '-a?' 定義、宣言の変換の有無(?=0～9:6から9は自由に書き換え)\n",
		"                            ; ここによく使う番号を指定。0 は下記初期値に従う\n",
		"                            ; 下記 all-番号 のﾊﾟﾗﾒｰﾀ  ?=数字 : 設定値, ?=数字以外 : 全て初期値どうりにする\n",
		"all-1   -b1 -c0 -d2 -e2 -f0 -g0 -h1 -i? -j0 -k0 -l0 -m0 -n? -o0 -p0 -q0 -r0 -s0 -t0 -u0 -v0 -w0 -x0 -y0 -T1 ; 低整形\n",
		"all-2   -b1 -c2 -d2 -e2 -f0 -g2 -h2 -i? -j0 -k0 -l1 -m0 -n? -o0 -p0 -q0 -r2 -s1 -t2 -u2 -v1 -w1 -x2 -y0 -T1 ; 中整形\n",
		"all-3   -b1 -c2 -d2 -e2 -f0 -g2 -h2 -i? -j1 -k0 -l1 -m1 -n? -o? -p1 -q1 -r2 -s1 -t2 -u2 -v1 -w1 -x2 -y2 -T1 ; 高整形\n",
		"all-4   -b2 -c2 -d2 -e2 -f0 -g2 -h2 -i? -j0 -k0 -l1 -m0 -n? -o? -p0 -q0 -r2 -s1 -t2 -u2 -v1 -w1 -x2 -y0 -T1 ; 中整形+ｿｰｽ書換\n",
		"all-5   -b2 -c2 -d2 -e2 -f0 -g2 -h2 -i? -j1 -k0 -l1 -m1 -n? -o? -p1 -q1 -r2 -s1 -t2 -u2 -v1 -w1 -x2 -y2 -T1 ; 高整形+ｿｰｽ書換\n",
		"all-6   -b? -c? -d? -e? -f0 -g? -h? -i? -j? -k? -l? -m? -n? -o? -p? -q? -r? -s? -t? -u? -v? -w? -x? -y? -T? ; ﾌﾘｰ1\n",
		"all-7   -b? -c? -d? -e? -f0 -g? -h? -i? -j? -k? -l? -m? -n? -o? -p? -q? -r? -s? -t? -u? -v? -w? -x? -y? -T? ; ﾌﾘｰ2\n",
		"all-8   -b? -c? -d? -e? -f0 -g? -h? -i? -j? -k? -l? -m? -n? -o? -p? -q? -r? -s? -t? -u? -v? -w? -x? -y? -T? ; ﾌﾘｰ3\n",
		"all-9   -b? -c? -d? -e? -f0 -g? -h? -i? -j? -k? -l? -m? -n? -o? -p? -q? -r? -s? -t? -u? -v? -w? -x? -y? -T? ; ﾌﾘｰ4\n",
		"\n",
		";----------------- 初期値 --;---------------説明 ---------------------------------------------------------\n",
		"source_name         1       ; '-b?' ｿｰｽ名の処理 0:検査のみ, 1:ｿｰｽ名は変わらず,ｿｰｽﾌｧｲﾙを整形し +.newを新規に作る\n",
		"                            ;      2:ｿｰｽﾌｧｲﾙ整形し､古いｿｰｽ名を+.old, 3:ｿｰｽﾌｧｲﾙ整形し,oldを作らない\n",
		"\n",
		"define_tab          2       ; '-c?' #define の第1番目定義と第2番目間定数のTAB位置(?=0～40)\n",
		"                            ;      0:何もしない, 1:TABなし(ｽﾍﾟｰｽのみ), 2:自動でTAB作成, 3～:最小TAB位置\n",
		"                            ;      例 -c0\n",
		"                            ;         0---1---2---3---4 TAB位置   ---> 0---1---2---3---4---5---6---\n",
		"                            ;         #define   ABCD(a) if(a){    ---> #define   ABCD(a) if(a) {\n",
		"                            ;      例 -c1\n",
		"                            ;         0---1---2---3---4 TAB位置   ---> 0---1---2---3---4---5---6---\n",
		"                            ;         #define   ABCD(a) if(a){    ---> #define ABCD( a ) if( a ) {\n",
		"                            ;         #define Uint unsigned int   ---> #define Uint unsignd int\n",
		"                            ;         #define ABCD    1000        ---> #define ABCD 1000\n",
		"                            ;         #define MAX_LENGTH  128     ---> #define MAXLENGTH 128\n",
		"                            ;      例 -c2\n",
		"                            ;         0---1---2---3---4 TAB位置   ---> 0---1---2---3---4---5---6---\n",
		"                            ;         #define   ABCD(a) if(a){    ---> #define ABCD( a )   if( a ) {\n",
		"                            ;         #define Uint unsigned int   ---> #define Uint        unsignd int\n",
		"                            ;         #define ABCD    1000        ---> #define ABCD        1000\n",
		"                            ;         #define MAX_LENGTH  128     ---> #define MAXLENGTH   128\n",
		"                            ;      例 -c5\n",
		"                            ;         0---1---2---3---4 TAB位置   ---> 0---1---2---3---4---5---6---\n",
		"                            ;         #define   ABCD(a) if(a){    ---> #define ABCD( a )   if( a ) {\n",
		"                            ;         #define Uint unsigned int   ---> #define Uint        unsignd int\n",
		"                            ;         #define ABCD    1000        ---> #define ABCD        1000\n",
		"                            ;         #define MAX_LENGTH  128     ---> #define MAXLENGTH   128\n",
		"                            ;      例 -c6\n",
		"                            ;         0---1---2---3---4 TAB位置   ---> 0---1---2---3---4---5---6---\n",
		"                            ;         #define ABCD(a) if(a){      ---> #define ABCD( a )       if( a ) {\n",
		"                            ;         #define Uint unsigned int   ---> #define Uint            unsignd int\n",
		"                            ;         #define ABCD    1000        ---> #define ABCD            1000\n",
		"                            ;         #define MAX_LENGTH  128     ---> #define MAXLENGTH       128\n",
		"\n",
		"define_com_tab      2       ; '-d?' #define のｺﾒﾝﾄのTAB位置(?=0～40)\n",
		"                            ;      0:何もしない, 1:TABなし(ｽﾍﾟｰｽのみ), 2:自動でTAB作成, 3～:最大TAB位置\n",
		"                            ;      例 -d1\n",
		"                            ;         0---1---2---3---4 TAB位置      ---> 0---1---2---3---4---5---6---7\n",
		"                            ;         #define ABC 1234    // comment ---> #define ABC 1234 // comment\n",
		"                            ;         #define ABCDEF abcd123 // test ---> #define ABCDEF abcd123 // test\n",
		"                            ;      例 -d5\n",
		"                            ;         0---1---2---3---4 TAB位置      ---> 0---1---2---3---4---5---6---7\n",
		"                            ;         #define ABC 1234 // comment    ---> #define ABC 1234    // comment\n",
		"                            ;         #define ABCDEF abcd123 // test ---> #define ABCDEF abcd123 // test\n",
		"                            ;      例 -d20\n",
		"                            ;         0---1---2---3---4 TAB位置      ---> 0---1---2---3---4---5---6---7\n",
		"                            ;         #define ABC 1234 // comment    ---> #define ABC 1234        // comment\n",
		"                            ;         #define ABCDEF abcd123 // test ---> #define ABCDEF abcd123  // test\n",
		"\n",
		"other_com_tab       2       ; '-e?' #defien以外のｺﾒﾝﾄのTAB位置(?=0～40)\n",
		"                            ;      0:何もしない, 1:TABなし(ｽﾍﾟｰｽのみ), 2:最大TAB制限なし, 3～:最大TAB位置\n",
		"                            ;      例 -e1\n",
		"                            ;         0---1---2---3---4 TAB位置   ---> 0---1---2---3---4---5---6\n",
		"                            ;         a=0;    // test1            ---> a = 0; // test1\n",
		"                            ;         abcdef1234=0;// test2       ---> abcdef1234 = 0; // test2\n",
		"                            ;      例 -e3\n",
		"                            ;         0---1---2---3---4 TAB位置   ---> 0---1---2---3---4---5---6---\n",
		"                            ;         a=0;    // test1            ---> a = 0;      // test1\n",
		"                            ;         abcdef1234=0;// test2       ---> abcdef1234 = 0; // test2\n",
		"                            ;      例 -e20\n",
		"                            ;         0---1---2---3---4 TAB位置   ---> 0---1---2---3---4---5---6---\n",
		"                            ;         a=0;    // test1            ---> a = 0;          // test1\n",
		"                            ;         abcdef1234=0;// test2       ---> abcdef1234 = 0; // test2\n",
		"\n",
		"shit_jis_mode       0       ; '-f?' ソースが 0:自動, 1:utf8, 2:Shift JIS\n",

//		"global_int_tab      2       ; '-f?' ｸﾞﾛｰﾊﾞﾙ変数のint, char, long, unsignedの第一定義のTAB位置(?=0～40)\n",
//		"                            ;      0:何もしない, 1:TABなし(ｽﾍﾟｰｽのみ), 2:自動でTAB作成, 3～:最大TAB位置\n",
//		"                            ;      例 -f1\n",
//		"                            ;         0---1---2- TAB位置   ---> 0---1---2---3---4---5---6\n",
//		"                            ;         int      abcd1;      ---> int abcd1;\n",
//		"                            ;         char   abcd2;        ---> char abcd2;\n",
//		"                            ;         unsigned long abcd3; ---> unsigned long abcd3;\n",
//		"                            ;      例 -f2\n",
//		"                            ;         0---1---2- TAB位置   ---> 0---1---2---3---4---5---6\n",
//		"                            ;         int abcd1;           ---> int             abcd1;\n",
//		"                            ;         char abcd2;          ---> char            abcd2;\n",
//		"                            ;         unsigned long abcd3; ---> unsigned long   abcd3;\n",
//		"                            ;      例 -f3\n",
//		"                            ;         0---1---2- TAB位置   ---> 0---1---2---3---4---5---6\n",
//		"                            ;         int abcd1;           ---> int         abcd1;\n",
//		"                            ;         char abcd2;          ---> char        abcd2;\n",
//		"                            ;         unsigned long abcd3; ---> unsigned long abcd3;\n",
//		"                            ;      例 -f6\n",
//		"                            ;         0---1---2- TAB位置   ---> 0---1---2---3---4---5---6\n",
//		"                            ;         int abcd1;           ---> int             abcd1;\n",
//		"                            ;         char abcd2;          ---> char            abcd2;\n",
//		"                            ;         unsigned long abcd3; ---> unsigned long   abcd3;\n",
		"\n",
		"local_int_tab       2       ; '-g?' ローカル変数のint, char, long, unsignedの第一定義のTAB位置(?=0～40)\n",
		"                            ;      0:何もしない, 1:TABなし(ｽﾍﾟｰｽのみ), 2:自動でTAB作成, 3～:最大TAB位置\n",
		"                            ;      例 -g1\n",
		"                            ;         0---1---2---3- TAB位置   ---> 0---1---2---3---4---5---6\n",
		"                            ;         void abcd(void)          ---> void abcd(void)\n",
		"                            ;         {                        ---> {\n",
		"                            ;             int  abcd1;          --->     int abcd1;\n",
		"                            ;             char abcd2;          --->     char abcd2;\n",
		"                            ;             unsigned long abcd3; --->     unsigned long abcd3;\n",
		"                            ;      例 -g3\n",
		"                            ;         0---1---2---3- TAB位置   ---> 0---1---2---3---4---5---6\n",
		"                            ;         void abcd(void)          ---> void abcd(void)\n",
		"                            ;         {                        ---> {\n",
		"                            ;             int  abcd1;          --->     int     abcd1;\n",
		"                            ;             char abcd2;          --->     char    abcd2;\n",
		"                            ;             unsigned long abcd3; --->     unsigned long abcd3;\n",
		"                            ;      例 -g7\n",
		"                            ;         0---1---2---3- TAB位置   ---> 0---1---2---3---4---5---6\n",
		"                            ;         void abcd(void)          ---> void abcd(void)\n",
		"                            ;         {                        ---> {\n",
		"                            ;             int  abcd1;          --->     int             abcd1;\n",
		"                            ;             char abcd2;          --->     char            abcd2;\n",
		"                            ;             unsigned long abcd3; --->     unsigned long   abcd3;\n",
		"\n",
		"big_kakko_pair      2       ; '-h?' '{'～'}' 連続の位置\n",
		"                            ;      0:スペースのみ, 1:左側に揃える(最小TAB=1), 2:自動でTAB作成(ｽﾍﾟｰｽ+TABで合わせる)\n",
		"                            ;      例 -h0\n",
		"                            ;       0---1---2---3---4- TAB位置 ---> 0---1---2---3---4---5---6---7---8\n",
		"                            ;       abcd[] =   {123, 456, 789} ---> abcd[] = { 123, 456, 789 }\n",
		"                            ;       d[] = {1,2,3 }             ---> d[] = { 1, 2, 3 }\n",
		"                            ;       ef[] =  { 23, 45, 6789}    ---> ef[] = { 23, 45, 6789 }\n",
		"                            ;      例 -h1\n",
		"                            ;       0---1---2---3---4- TAB位置 ---> 0---1---2---3---4---5---6---7---8\n",
		"                            ;       abcd[] =   {123, 456, 789} ---> abcd[] =    { 123, 456, 789 }\n",
		"                            ;       d[] = {1,2,3 }             ---> d[] =       { 1, 2, 3 }\n",
		"                            ;       ef[] =  { 23, 45, 6789}    ---> ef[] =      { 23, 45, 6789 }\n",
		"                            ;      例 -h2\n",
		"                            ;       0---1---2---3---4- TAB位置 ---> 0---1---2---3---4---5---6---7---8\n",
		"                            ;       abcd[] =    {123, 456, 789} ---> abcd[] = { 123, 45, 789  }\n",
		"                            ;       d[] = {1,2,3 }             ---> d[] =     { 1,   2,  3    }\n",
		"                            ;       ef[] =  { 23, 45, 6789}    ---> ef[] =    { 23,  45, 6789 }\n",
		"\n",
		"limit_line        37        ; '-i?' 1行の最大数(TAB換算)を規制する。1行の最大TAB数(?=0:無制限, ?=20(最小)～99\n",
		"                            ;      文字数は ?の4倍\n",
		"                            ;      この指定文字数を超える場合TABをｽﾍﾟｰｽとする\n",
		"                            ;       例 -p33\n",
		"                            ;         26--27--28--29---30-- TAB位置 ---> ---27---28--29--30--31--32--\n",
		"                            ;             abcd=0;//test             --->    abcd = 0;    // test\n",
		"                            ;             c(1); //commment          --->    c( 1 );      // comment\n",
		"                            ;       例 -p32\n",
		"                            ;         26--27--28--29---30-- TAB位置 ---> ---27---28--29--30--31--32--\n",
		"                            ;             abcd=0;//test             --->    abcd = 0;    // test\n",
		"                            ;             c(1); //commment          --->    c( 1 ); // comment\n",
		"\n",
		"kolon               1       ; '-j?' ':','::' コロンの前後のスペース処理\n",
		"                            ;      0:何もしない, 1:自動でスペースを削除/挿入する\n",
		"                            ;      例 -i1\n",
		"                            ;       0---1---2---3---4- TAB位置 ---> 0---1---2---3---4---5---6\n",
		"                            ;           case abc :             --->     case abc:\n",
		"\n",
		"cut_comment         0       ; '-k?' ｺﾒﾝﾄを削除する。下記番号を加算した番号を指定(?=0～15)\n",
		"                            ;      0:削除しない\n",
		"                            ;      1:1行の右端のｺﾒﾝﾄ(//～, /*～*/)を削除する\n",
		"                            ;      2:1行中の部分ｺﾒﾝﾄ(/*～*/)を削除する\n",
		"                            ;      4:ｺﾒﾝﾄ行(//～)を削除する\n",
		"                            ;      8:ｺﾒﾝﾄ複数行(/*～, ～*/)を削除する\n",
		"                            ;      例 -j3\n",
		"                            ;        1:1行の右端のｺﾒﾝﾄ(//～, /*～*/)を削除する\n",
		"                            ;        2:1行中の部分ｺﾒﾝﾄ(/*～*/)を削除する\n",
		"                            ;      例 -j15\n",
		"                            ;        1:1行の右端のｺﾒﾝﾄ(//～, /*～*/)を削除する\n",
		"                            ;        2:1行中の部分ｺﾒﾝﾄ(/*～*/)を削除する\n",
		"                            ;        4:ｺﾒﾝﾄ行(//～)を削除する\n",
		"                            ;        8:ｺﾒﾝﾄ複数行(/*～, ～*/)を削除する\n",
		"\n",
		"long_comment        1       ; '-l?' '/*～*/' 行の処理\n",
		"                            ;      0:変換しない\n",
		"                            ;      1:行の最後の '/*～*/' を'//'に変換\n",
		"                            ;      2:'/*'で始まる複数行の長い文章までを'//'に変換\n",
		"                            ;     例 -k1\n",
		"                            ;         0---1---2---3----4--- TAB位置 ---> 0---1---2---3---4---5\n",
		"                            ;             abcde= 0;/* test0 */      --->     abcde = 0;  // test0\n",
		"                            ;             a=b;// test1              --->     a = 0;      // test1\n",
		"                            ;             //abc(1);//test2          --->     // abc(1);//test2\n",
		"                            ;      例 -k2\n",
		"                            ;         0---1---2 TAB位置      ---> 0---1---2---3---4---5---6\n",
		"                            ;         /*                     ---> //\n",
		"                            ;           This is sample.      ---> // This is sample.\n",
		"                            ;           20xx年yy月zz日       ---> // 20xx年yy月zz日\n",
		"                            ;           char abcd[]={1,2,3}; ---> // char abcd[]={1,2,3};\n",
		"                            ;         */                     ---> //\n",
		"\n",
		"comment_prog         1      ; '-m?' '//' 行の処理\n",
		"                            ;      0:何もしない, 1:ﾌﾟﾛｸﾞﾗﾑの場合は調整する+TABを揃える\n",
		"                            ;       例 -m1\n",
		"                            ;         0---1---2---3----4--- TAB位置 ---> 0---1---2---3---4---5\n",
		"                            ;             abcde= 0;/* test0 */      --->     abcde = 0;  // test0\n",
		"                            ;             a=b;// test1              --->     a = 0;      // test1\n",
		"                            ;        //abc(1);//test2               ---> //  abc( 1 );   //test2\n",
		"                            ;        ↑'//'位置が先頭+ﾌﾟﾛｸﾞﾗﾑなのでﾌﾟﾛｸﾞﾗﾑとして調整する\n",
		"                            ;             //abc(1);//test2          --->     // abc(1);//test2\n",
		"                            ;             ↑'//'位置が先頭でない場合は何もしない\n",
		"                            ;             b(1); //test3             --->     b( 1 );     // test3\n",
		"                            ;               //ﾃｽﾄ                   --->     // ﾃｽﾄ\n",
		"                            ;               ↑'//'位置が前行とそろってない場合,TAB=0とする\n",
		"                            ;             c(1); //test4             --->     c( 1 );     // test4\n",
		"                            ;                   //ここはｺﾒﾝﾄ        --->                 // ここはｺﾒﾝﾄ\n",
		"                            ;                   ↑'//'位置が前行と同じｺﾒﾝﾄ位置の場合,前行にそろえる\n",
		"\n",
		"kakko_space         0       ; '-n?' 括弧の前後の処理\n",
		"                            ;      0:連続する括弧の最初と最後はｽﾍﾟｰｽを入れる, 1:括弧の内側はｽﾍﾟｰｽを入れない\n",
		"                            ;       例 -n0\n",
		"                            ;         0---1---2---3--- TAB位置   ---> 0---1---2---3---4---5---6\n",
		"                            ;         if( abc( 1 ) == 0 ) d = 0; ---> if( abc(1) == 0 ) d = 0;\n",
		"                            ;       例 -n1:\n",
		"                            ;         0---1---2---3--- TAB位置   ---> 0---1---2---3---4---5---6\n",
		"                            ;         if( abc( 1 ) == 0 ) d = 0; ---> if(abc(1) == 0) d = 0;\n",
		"\n",
		"ifdef_mode          0       ; '-o?' #if, #else, #endif のTABを調正する(TABがずれた時の確認用)\n",
		"                            ;      0:何もしない, 1:TAB調整\n",
		"\n",
		"yen                 1       ; '-p?' '\\'行の処理\n",
		"                            ;      0:最初のTABは変更なし, 1:調整する\n",
		"\n",
		"struct_big_kakko    0       ; '-q?' struct{} の'{'～'}'の縦の位置をそろえる\n",
		"                            ;      0:文書整形のみする, 1:'struct {'+改行 にする, 2:改行+{で,{ }を縦に揃える\n",
		"\n",
		"if_big_kakko        2       ; '-r?' if(){} の'{'～'}'の縦の位置をそろえる('{'～'}'の場合は揃えない)\n",
		"                            ;      0:文書整形のみする, 1:if(...) {+改行 にする, 2:改行+{で,{ }を縦に揃える\n",
		"\n",
		"else_big_kakko      1       ; '-s?' else{} の'{'～'}'の縦の位置をそろえる('{'～'}'の場合は揃えない)\n",
		"                            ;      0:文書整形のみする, 1:else {+改行 にする, 2:改行+{で,{ }を縦に揃える\n",
		"\n",
		"for_big_kakko       2       ; '-t?' for(){} の'{'～'}'の縦の位置をそろえる('{'～'}'の場合は揃えない)\n",
		"                            ;      0:文書整形のみする, 1:for(...) {+改行 にする, 2:改行+{で,{ }を縦に揃える\n",
		"\n",
		"while_big_kakko     2       ; '-u?' while(){} の'{'～'}'の縦の位置をそろえる({'～'}'の場合は揃えない)\n",
		"                            ;      0:文書整形のみする, 1:while(...) {+改行 にする, 2:改行+{で,{ }を縦に揃える\n",
		"\n",
		"do_big_kakko        1       ; '-v?' do{} while() の'{'～'}'の縦の位置をそろえる('{'～'}'の場合は揃えない)\n",
		"                            ;      0:文書整形のみする, 1:do {+改行 にする, 2:改行+{で,{ }を縦に揃える\n",
		"\n",
		"try_big_kakko       1       ; '-w?' try{} の'{'～'}'の縦の位置をそろえる('{'～'}'の場合は揃えない)\n",
		"                            ;      0:文書整形のみする, 1:try {+改行 にする, 2:改行+{で,{ }を縦に揃える\n",
		"\n",
		"switch_big_kakko    2       ; '-x?' switch(){} の'{'～'}'の縦の位置をそろえる('{'～'}'の場合は揃えない)\n",
		"                            ;      0:文書整形のみする, 1:switch(...) {+改行 にする, 2:改行+{で,{ }を縦に揃える\n",
		"\n",
		"other_big_kakko     0       ; '-y?' その他の'{'～'}'の処理('{'～'}'の場合は揃えない)\n",
		"                            ;      0:文書整形のみする, 1,2:改行+{で,{ }を縦に揃える\n",				// {+改行は不可。使ってはいけない
		"\n",
		"debug_mode          0       ; '-z?' debug用 0:記録なし\n",
		"                            ;      1:tab_stack_cnt, 2:big_kakko_cnt, 3:if_stack_top\n",
		"                            ;      4:hojo_flag，5:tab_pos, 6:src_line_no，7:src_com_pos\n",
		"                            ;      8:sub_type，9:debug情報表示\n",
		"\n",

//		"typedef_mode        1       ; '-T?' typedefをマクロとして置き換える 0:定義を無視する, 1:有効とする\n", // V1.61で削除
//		"                            ;      定義は最大50行で,最大35文字まで\n",
//		"                            ;      ①typedef, ②有効は char,short,int,long, long long, unsigned\n",
//		"                            ;      ③文字列で,最後の ; はなくても良い(途中のスペースTABは不可)\n",
//		"                            ;      ④ ; 以後は無視される(コメントが必要な場合)\n",
//		";   ①           ②                ③       ④\n",
//		"typedef    unsigned char       uchar;      // comment\n",
//		"typedef    unsigned short      ushort;     // comment\n",
//		"typedef    unsigned int        uint;       // comment\n",
//		"typedef    unsigned long       ulong;      // comment\n",
//		"typedef    unsigned long long  ulonglong;  // comment\n",
//		"typedef    unsigned char       uint8_t;    // comment\n",
//		"typedef    unsigned short      uint16_t;   // comment\n",
//		"typedef    unsigned long       uint32_t;   // comment\n",
//		"typedef    signed char         int8_t;     // comment\n",
//		"typedef    signed short        int16_t;    // comment\n",
//		"typedef    signed long         int32_t;    // comment\n",
//		"typedef    unsigned long long  uint64_t;\n",
//		"typedef    unsigned short      size_t16;\n",
//		"\n",
		""
	};

	int		n;
	char	buf[CHAR_SIZE];

	ini_fp = fopen( ini_name, "w" );
	if( ini_fp == NULL )
	{
		printf( "新規に %s ﾌｧｲﾙを作成できません\n", ini_name );
		wait_exit( 2 );
	}

	sprintf( buf, "; ===== %s V%s %s Kenjiy ======\n;\n", exe_name, versions, environs );
	fwrite( buf, sizeof(char), strlen(buf), ini_fp );
	sprintf( buf, "; Cのソースファイルの文書整形\n" );
	fwrite( buf, sizeof(char), strlen(buf), ini_fp );

	for( n = 0; *ini_mes[n]; n++ )
	{
		strcpy( buf, ini_mes[n] );
		fwrite( buf, sizeof(char), strlen(buf), ini_fp );
	}
	fclose( ini_fp );
	ini_fp = NULL;
}
// ---------------------------------------------------------------------
// 引数の設定
// ---------------------------------------------------------------------
void para_sub( char command, int para )
{
	switch( command )
	{
	case '?': // 使用方法表示
		usage();
		break;

	case 'a': // -cx ～ -gx の有無指定
		form_all = para;
		break;

	case 'b': // ｿｰｽ名の処理 0:検査のみ, 1:ｿｰｽ名は変わらず+.newを新規に作る, 2:ｿｰｽ名を+.oldとする, 3:oldを作らない
		form_source_name = para;
		break;

	case 'c': // #define の処理 0:何もしない, 1:TABなし(ｽﾍﾟｰｽのみ), 2:自動でTAB作成, 3～:最小TAB位置
		form_define_tab = para;
		if( form_define_tab > 30 ) form_define_tab = 30;
//		else if( form_define_tab == 2 ) form_define_tab = 99;
		break;

	case 'd': // #define のｺﾒﾝﾄTAB 0:何もしない, 1:TABなし(ｽﾍﾟｰｽのみ), 2:自動でTAB作成, 3～:最大TAB位置
		form_define_com_tab = para;
		if( form_define_com_tab > 40 ) form_define_com_tab = 40;
//		else if( form_define_com_tab == 2 ) form_define_com_tab = 99;
		break;

	case 'e': // 関数内のｺﾒﾝﾄ位置のTAB位置, 0:何もしない, 1:ｽﾍﾟｰｽのみ, 2:最大TAB制限なし, 3～:最大TAB位置\n",
		form_other_com_tab = para;
		if( form_other_com_tab > 40 ) form_other_com_tab = 40;
//		else if( form_other_com_tab == 2 ) form_other_com_tab = 99;
		break;

	case 'f': // 0:自動, 1:utf8, 2;Shif JIS
		form_utf8_mode = para;
		if( form_utf8_mode > 2 ) form_utf8_mode = 2;
		break;

//	case 'f': // ｸﾞﾛｰﾊﾞﾙ変数のint,char,long, unsignedのTAB位置 0:何もしない, 1:ｽﾍﾟｰｽのみ, 2:自動でTAB作成, 3～:最大TAB位置
//		form_global_int_tab = para;
//		if( form_global_int_tab > 40 ) form_global_int_tab = 40;
//		break;

	case 'g': // ﾛｰｶﾙ変数のint,char,long, unsignedのTAB位置K 0:何もしない, 1:ｽﾍﾟｰｽのみ, 2:自動でTAB作成, 3～:最大TAB位置\n",
		form_local_int_tab = para;
		if( form_local_int_tab > 40 ) form_local_int_tab = 40;
//		else if( form_local_int_tab == 2 ) form_local_int_tab = 99;
		break;

	case 'h': // '{'～'}'の処理 0:ｽﾍﾟｰｽのみ, 1:左側に揃える(最小TAB=1), 2:自動でTAB作成(ｽﾍﾟｰｽ+TABで合わせる)
		form_big_kakko_pair = para;
		if( form_big_kakko_pair > 2 ) form_big_kakko_pair = 2;
		break;

	case 'i': // TABを無効にする１行の最大TAB数
		form_limit_line = para;
		if( form_limit_line > 0 && form_limit_line <= 20 ) form_limit_line = 20; // 最小=20 TAB
		break;

	case 'j': // ｺﾛﾝの前後のｽﾍﾟｰｽ
		form_kolon = para;
		break;

	case 'k': // ｺﾒﾝﾄを削除する
		form_cut_comment = para;
		break;

	case 'l': // "/*"で始まる長い文章を 0:変換しない, 1:行の最後の '/*～*/' を'//'に変換,
			  // 2:'/*'で始まる複数行の長い文章までを'//'に変換
		form_long_comment = para;
		if( form_long_comment > 2 ) form_long_comment = 2;
		break;

	case 'm': // 0:何もしない, 1:ﾌﾟﾛｸﾞﾗﾑの場合は調整する+TABを揃える
		form_comment_prog = para;
		if( form_comment_prog > 1 ) form_comment_prog = 1;
		break;

	case 'n': // 括弧の前後の処理 0:連続する括弧の最初と最後はｽﾍﾟｰｽを入れる, 1:括弧の内側はｽﾍﾟｰｽを入れない\n",
		form_kakko_space = para;
		if( form_kakko_space > 1 ) form_kakko_space = 1;
		break;

	case 'o': // #if, #else, #endif のグループ番号をコメントに追加
		form_ifdef_mode = para;
		break;

	case 'p': // 0:最初のTABは変更なし, 1:調整する
		form_yen = para;
		if( form_yen > 1 ) form_yen = 1;
		break;

	case 'q': // struct の'{'～'}'の縦の位置をそろえる
		form_struct_big_kakko = para;
		break;

	case 'r': // if(){} の'{'～'}'の縦の位置をそろえる
		form_if_big_kakko = para;
		break;

	case 's': // else{} の'{'～'}'の縦の位置をそろえる
		form_else_big_kakko = para;
		break;

	case 't': // for(){} の'{'～'}'の縦の位置をそろえる
		form_for_big_kakko = para;
		break;

	case 'u': // while(){} の'{'～'}'の縦の位置をそろえる
		form_while_big_kakko = para;
		break;

	case 'v': // do{}while() の'{'～'}'の縦の位置をそろえる
		form_do_big_kakko = para;
		break;

	case 'w': // try{} の'{'～'}'の縦の位置をそろえる
		form_try_big_kakko = para;
		break;

	case 'x': // switch(){} の'{'～'}'の縦の位置をそろえる
		form_switch_big_kakko = para;
		break;

	case 'y': // その他 '{'～'}'の縦の位置をそろえる
		form_other_big_kakko = para;
		if( form_other_big_kakko ) form_other_big_kakko = 2;
		break;

	case 'z': // debug mode 0:なし
		debug_mode = para;
		if( debug_mode == 9 ) disp_debug_para0();
		break;

	case 'T': // typedefをマクロとして置き換える(定義は最大20行まで) 0:無視する, 1:有効とする
		form_typedef_mode = para;
		if( form_typedef_mode ) form_typedef_mode = 1;
		break;

	}
}
// ---------------------------------------------------------------------
// all-x パラメータ指定
// type : all-x=0～9
// n : 指定数字
// ---------------------------------------------------------------------
void parameter_all( int type, char *line_buf )
{
	int		cur_pos, tok_len;
	char	tok_buf[CHAR_SIZE], command;

	cur_pos = 0;
	for(;;)
	{
		cur_pos += get_def_tok( tok_buf, &line_buf[cur_pos], &tok_len );	// get next
		if( tok_len == 0 || tok_buf[0] == ';' ) break;						// １行終わり
		if( tok_len < 3 ) continue;
		if( tok_buf[0] != '-' ) continue;									// '-'以外pass
//		if( (tok_buf[1] < 'a' || tok_buf[1] > 'z') && tok_buf[1] != 'M' && tok_buf[1] != 'T' ) continue;
		command = tok_buf[1];
		if( _isdigit(tok_buf[2]) == 0 ) continue;
		para_sub( command, atoi(&tok_buf[2]) );
	}
}
// ---------------------------------------------------------------------
// iniﾌｧｲﾙを読み込む
// mode 0:ﾕｰｻﾞｰ指定ﾌｧｲﾙ名
// mode 2:ﾕｰｻﾞｰ指定ﾌｧｲﾙ名+form_allは無視
// ---------------------------------------------------------------------
void analize_ini_file( int mode )
{
	int		cur_pos, tok_len, loop_mode, n;
	char	tok_buf[CHAR_SIZE], line_buf[CHAR_SIZE], moji;
	char	command_buf[CHAR_SIZE];

	if( mode == 0 ) form_all = 0;
	form_source_name = 0;
	form_define_tab = 0;
	form_define_com_tab = 0;
	form_other_com_tab = 0;
//	form_global_int_tab = 2;
	form_local_int_tab = 0;
	form_big_kakko_pair = 0;
	form_kolon = 0;
	form_cut_comment = 0;
	form_long_comment = 0;
	form_comment_prog = 0;
	form_kakko_space = 0;
	form_ifdef_mode = 0;
	form_limit_line = 0;
	form_yen = 0;
	form_struct_big_kakko = 0;
	form_if_big_kakko = 0;
	form_else_big_kakko = 0;
	form_for_big_kakko = 0;
	form_while_big_kakko = 0;
	form_do_big_kakko = 0;
	form_try_big_kakko = 0;
	form_switch_big_kakko = 0;
	form_other_big_kakko = 0;
	form_typedef_mode = 0;
	debug_mode = 0;
	form_utf8_mode = 0; // 自動
	ini_fp = fopen( ini_name, "rb+" );
	if( ini_fp == NULL )
	{
		if( mode == 0 )
		{
			printf( "新規に %s ﾌｧｲﾙを作成します\n", ini_name );
			make_ini_file(); // renew.ini ﾌｧｲﾙを作る
		}
		ini_fp = fopen( ini_name, "rb+" );
		if( ini_fp == NULL )
		{
			printf( "新規に %s ﾌｧｲﾙを作成できません\n", ini_name );
			wait_exit( 2 );
		}
	}

	if( fgets(line_buf, sizeof(line_buf) - 2, ini_fp) != NULL )
	{
		sprintf( tok_buf, ".exe V%s", versions );
		n = 0;
		while( (moji = line_buf[n]) != 0 )
		{
			if( moji == '.' && line_buf[n + 1] == 'e' )
			{
				if( strncmp(&line_buf[n], tok_buf, strlen(tok_buf)) != 0 )
				{ // 不一致
					printf( " iniファイルのバージョンが違います。新しく作成します\n" );
					fclose( ini_fp );
					make_ini_file(); // renew.ini ﾌｧｲﾙを作る
					ini_fp = fopen( ini_name, "rb+" );
					if( ini_fp == NULL )
					{
						printf( "新規に %s ﾌｧｲﾙを作成できません\n", ini_name );
						wait_exit( 2 );
					}
				}
				break;
			}
			n++;
		}
		if( moji == 0 )
		{
			fclose( ini_fp );
			printf( " %s ﾌｧｲﾙが壊れてます\n", ini_name );
			wait_exit( 2 );
		}
	}

	command_buf[0] = 0;
	while( fgets(line_buf, sizeof(line_buf) - 2, ini_fp) != NULL )
	{
		loop_mode = 0;
		cur_pos = 0;
		while( loop_mode >= 0 )
		{ // 1行解析
			cur_pos += get_def_tok( tok_buf, &line_buf[cur_pos], &tok_len );	// get next
			if( tok_len == 0 || tok_buf[0] == ';' ) break;						// １行終わり
			if( loop_mode && tok_len == 1 && tok_buf[0] == '=' ) continue;		// pass '='
			if( loop_mode == 0 )
			{ // 行の始め
				if( strcmp(tok_buf, "all") == 0 )
				{
					if( mode == 2 ) break;	// １行終わり
					loop_mode = 'a';		// mode = 2は無視
				}
				else if( strncmp(tok_buf, "all-", 4) == 0 )
				{ // all-x
					moji = tok_buf[4];
					if( moji >= '1' && moji <= '9' )
					{
						if( form_all == (int)(moji & 0x0f) ) strcpy( command_buf, &line_buf[cur_pos] );
					}
					break;
				}
				else if( _stricmp(tok_buf, "source_name") == 0 ) loop_mode = 'b';
				else if( _stricmp(tok_buf, "define_tab") == 0 ) loop_mode = 'c';
				else if( _stricmp(tok_buf, "define_com_tab") == 0 ) loop_mode = 'd';
				else if( _stricmp(tok_buf, "other_com_tab") == 0 ) loop_mode = 'e';
				else if( _stricmp(tok_buf, "shit_jis_mode") == 0 ) loop_mode = 'f';
//				else if( _stricmp(tok_buf, "global_int_tab") == 0 ) loop_mode = 'f';
				else if( _stricmp(tok_buf, "local_int_tab") == 0 ) loop_mode = 'g';
				else if( _stricmp(tok_buf, "big_kakko_pair") == 0 ) loop_mode = 'h';
				else if( _stricmp(tok_buf, "limit_line") == 0 ) loop_mode = 'i';
				else if( _stricmp(tok_buf, "kolon") == 0 ) loop_mode = 'j';
				else if( _stricmp(tok_buf, "cut_comment") == 0 ) loop_mode = 'k';
				else if( _stricmp(tok_buf, "long_comment") == 0 ) loop_mode = 'l';
				else if( _stricmp(tok_buf, "comment_prog") == 0 ) loop_mode = 'm';
				else if( _stricmp(tok_buf, "kakko_space") == 0 ) loop_mode = 'n';
				else if( _stricmp(tok_buf, "ifdef_mode") == 0 ) loop_mode = 'o';
				else if( _stricmp(tok_buf, "yen") == 0 ) loop_mode = 'p';
				else if( _stricmp(tok_buf, "struct_big_kakko") == 0 ) loop_mode = 'q';
				else if( _stricmp(tok_buf, "if_big_kakko") == 0 ) loop_mode = 'r';
				else if( _stricmp(tok_buf, "else_big_kakko") == 0 ) loop_mode = 's';
				else if( _stricmp(tok_buf, "for_big_kakko") == 0 ) loop_mode = 't';
				else if( _stricmp(tok_buf, "while_big_kakko") == 0 ) loop_mode = 'u';
				else if( _stricmp(tok_buf, "do_big_kakko") == 0 ) loop_mode = 'v';
				else if( _stricmp(tok_buf, "try_big_kakko") == 0 ) loop_mode = 'w';
				else if( _stricmp(tok_buf, "switch_big_kakko") == 0 ) loop_mode = 'x';
				else if( _stricmp(tok_buf, "other_big_kakko") == 0 ) loop_mode = 'y';
				else if( _stricmp(tok_buf, "debug_mode") == 0 ) loop_mode = 'z';
				else if( _stricmp(tok_buf, "typedef_mode") == 0 ) loop_mode = 'T';
				else if( _stricmp(tok_buf, "typedef") == 0 )
				{
					if( form_typedef_mode == 1 )
					{
						if( typedef_cnt >= MAX_TYPEDEF_CNT ) err_trap( 0, -38, tok_buf, 0 ); // "typedefの登録数が多すぎる"
					}
					break;
				}
				else {
					err_trap( 0, -28, tok_buf, 0 );
					loop_mode = -1; // １行終わり
				}
			}
			else para_sub( (char)loop_mode, atoi(tok_buf) );
		}
	}
	fclose( ini_fp );
	ini_fp = NULL;

	if( form_all > 0 && command_buf[0] ) parameter_all( form_all, command_buf ); // ﾌｧｲﾙ単位なので再度確認
}
// ---------------------------------------------------
// path name と file name に分離
// ---------------------------------------------------
int bunri_path( char *s_buf, char *p_name, char *f_name, char *e_name )
{
	long i, len, bunri_pos, ext_pos;
//	char buf[400];

	*p_name = *f_name = *e_name = 0;
	i = len = (long)strlen( s_buf );
	if( len == 0 ) return( 0 );
//	if( len >= (sizeof(buf) - 1) ) return( -9 ); // 長さ異常
	bunri_pos = 0;
	ext_pos = len;
	for( i = 0; i < len; i++ )
	{
		if( s_buf[i] == '\\' ) bunri_pos = i;
		if( s_buf[i] == '.' ) ext_pos = i;
	}
	if( bunri_pos > ext_pos ) return( -10 ); // file name異常
	if( bunri_pos )
	{
		memcpy( p_name, s_buf, bunri_pos );
		p_name[bunri_pos] = 0;
		bunri_pos++;
	}
	i = ext_pos - bunri_pos;
	if( i >= 1 )
	{
		memcpy( f_name, &s_buf[bunri_pos], i );
		f_name[i] = 0;
	}
	ext_pos++;
	i = len - ext_pos;
	if( i >= 1 && i <= 3 )
	{
		memcpy( e_name, &s_buf[ext_pos], i );
		e_name[i] = 0;
	}
	return( 0 ); // OK
}
// ---------------------------------------------------------------------
void check_para( int argc )
{
	int		i, ret, back_all;
	char	tok_buf[200];

	ret = get_cur_path_name( cur_path_name, sizeof(cur_path_name) );
	if( ret < 0 ) err_trap( 2, ret, cur_path_name, 0 );

	// ------ check passward --------
	for( i = 0; i < argc; i++ )
	{
		strcpy( tok_buf, src_name_buf[i].name );
		if( tok_buf[0] == '-' )
		{
//			moji = tolower( tok_buf[1] ) & 0xff;
			back_all = form_all; // 退避
			para_sub( tok_buf[1], atoi(&tok_buf[2]) );
			if( form_all != back_all ) analize_ini_file( 2 );
		}
		else if( tok_buf[0] != 0 )
		{ // file name
			ret = bunri_path( tok_buf, path_in_name, file_in_name, ext_in_name );
			if( ret < 0 ) err_trap( 2, ret, tok_buf, path_in_name );
			if( src_name[0] == 0 ) strcpy( src_name, tok_buf ); // source file name
		}
	}
}

// ---------------------------------------------------------------------
// 入力ﾃﾞｰﾀの解析
// ---------------------------------------------------------------------
void analize_inline( char *s_buf )
{
	int i, n;

	memset( &src_name_buf, 0, sizeof(src_name_buf) );
	i = para_cnt = 0;
	n = pass_space( s_buf ); // ﾊﾟｽ ｽﾍﾟｰｽ,TAB
	while( s_buf[n] )
	{
		if( s_buf[n] == ' ' || s_buf[n] == _TAB )
		{
			n += pass_space( &s_buf[n] ); // ﾊﾟｽ ｽﾍﾟｰｽ,TAB
			i = 0;
		}
		else {
			if( i == 0 )
			{
				if( ++para_cnt >= MAX_SRC_NAME_LEN ) break;
			}
			src_name_buf[para_cnt - 1].name[i++] = s_buf[n++];
		}
	}
	check_para( para_cnt );
}
// ---------------------------------------------------------------------
// ｿｰｽ名,ﾊﾟﾗﾒｰﾀを入力する
// ---------------------------------------------------------------------
void src_input_name( void )
{
	int		n;
	char	moji, input_buf[200];

	n = 0;
	input_buf[0] = 0;
	printf( "\r\n ソースファイル名を入力して下さい :" );
	for(;;)
	{
		moji = getchar();
//		moji = key_sens();
		if( moji != -1 )
		{
			if( _isprint(moji) ) input_buf[n++] = moji;
			else if( moji == _CR || moji == _LF )
			{
				input_buf[n] = 0;
				if( n ) analize_inline( input_buf );
				break;
			}
		}
	}
}
// ---------------------------------------------------------------------
// ﾜｲﾙﾄﾞｶｰﾄﾞのﾌｧｲﾙ名を探す
// ---------------------------------------------------------------------
int search_src_name( LPCSTR s_name )
{

	WIN32_FIND_DATA FindFileData;
	HANDLE			hFind;
	int				cnt;

	memset( &src_name_buf, 0, sizeof(src_name_buf) );
	cnt = 0;
	hFind = FindFirstFile( s_name, &FindFileData );
	if( hFind != INVALID_HANDLE_VALUE )
	{
		while( cnt < MAX_SRC_NAME_LEN )
		{
			strcpy( src_name_buf[cnt].name, FindFileData.cFileName );
			cnt++;
			if( FindNextFile(hFind, &FindFileData) == 0 ) break; // end
		}
		FindClose( hFind );
	}
	return( cnt );
}
// ---------------------------------------------------------------------
// Shift JISか調べる
//
// &H00～&H7Fのいずれか」の1バイト後に、「&H80～&HBFのいずれか」がある場合
// 　→ Shift_JIS です。
// 「&HC0～&HDFのいずれか」の1バイト後に、「&H80～&HBF以外」のデータが来た場合
// → Shift_JIS です。
// 「&HC0～&HDFのいずれか」の2バイト後に、「&H80～&HBFのいずれか」が来た場合
// → Shift_JIS です。
// 「&HE0～&HEFのいずれか」の1～2バイト後に、「&H80～&HBF以外」のデータが来た場合
// → Shift_JIS です。
// 「&HE0～&HEFのいずれか」の3バイト後に、「&H80～&HBF以外」のデータが来た場合
// → Shift_JIS です。
// ---------------------------------------------------------------------
int chk_shiift_jis( u8 *s_buf, int len )
{
	int n, cnt;

	cnt = 0;
	for( n = 0; n < len - 3; n++ )
	{
		if( s_buf[n] <= 0x7F && s_buf[n + 1] >= 0x80 && s_buf[n + 1] <= 0xBF ) cnt++;
		else if( s_buf[n] >= 0xC0 && s_buf[n] <= 0xDF && !(s_buf[n + 1] >= 0x80 && s_buf[n + 1] <= 0xBF) ) cnt++;
		else if( s_buf[n] >= 0xC0 && s_buf[n] <= 0xDF && s_buf[n + 2] >= 0x80 && s_buf[n + 2] <= 0xBF ) cnt++;
		else if( s_buf[n] >= 0xE0 && s_buf[n] <= 0xEF &&
			!((s_buf[n + 1] >= 0x80 && s_buf[n + 1] <= 0xBF) || (s_buf[n + 2] >= 0x80 && s_buf[n + 2] <= 0xBF) ||
			(s_buf[n + 3] >= 0x80 && s_buf[n + 3] <= 0xBF)) ) cnt++;
	}
	return( cnt );
}
// ---------------------------------------------------------------------
// main
// ---------------------------------------------------------------------
int main( int argc, char **argv )
{
	int		src_size, total_cnt, len, file_cnt, cnt, ret, jis_font, j, n;
	char	buf[CHAR_SIZE2];

	fp_src = NULL;
	fp_err = NULL;
	max_line = 0;
	max_fdata_line = 0;											// 確保したmax memory行数
	total_err_cnt = 0;											// ｴﾗｰ行のｶｳﾝﾀ 100行を超えたら記録しない

	printf( " ===== V%s %s Kenjiy 2009/11-2020/03 ======\r\n\r\n", versions, environs );
	printf( "\r\n C(C++)のソースファイルの文書整形をします(例:*.cpp -b3)\n" );
	// ------------ .ini ﾌｧｲﾙの初期値設定 --------------------
	ret = bunri_path( argv[0], path_in_name, file_in_name, ext_in_name );
	if( ret < 0 ) err_trap( 2, ret, argv[0], path_in_name );

	sprintf( exe_name, "%s.%s", file_in_name, ext_in_name );	// renew.exe
	sprintf( ini_name, "%s.ini", file_in_name );				// default ".ini" file
	sprintf( err_name, "%s_err.txt", file_in_name );			// 変更

	fp_err = fopen( err_name, "w" );
	if( fp_err != NULL )
	{ // 内容削除
		fclose( fp_err );
		fp_err = NULL;
		DeleteFile( err_name );
	}

	// iniﾌｧｲﾙ取り込みがまだ
	if( ini_name[0] ) analize_ini_file( 0 );
	para_cnt = 0;
	if( argc > 1 )
	{
		memset( &src_name_buf, 0, sizeof(src_name_buf) );
		for( cnt = 1; cnt < argc; cnt++ )
		{
			strcpy( src_name_buf[para_cnt++].name, argv[cnt] );
		}
		check_para( para_cnt );
	}
	else src_input_name();

	// ｿｰｽ名の処理 0:検査のみ, 1:ｿｰｽ名は変わらず+.newを新規に作る, 2:ｿｰｽ名を+.oldとする, 3:oldを作らない
	if( debug_mode == 0 )
	{
		if( form_source_name == 0 ) printf( " 検査のみ\n" );
		else if( form_source_name == 1 ) printf( " 結果をソースファイル名+(.new) で作ります\n" );
		else if( form_source_name == 2 ) printf( " ソースファイル名を+(.old) で作り,結果をソースファイル名で作ります\n" );
	}
	else {
		printf( " 結果を renew_debug2.txt で作ります\n" );
		printf( " 初期化 ﾌｧｲﾙ = %s, debug_mode = %d\r\n", ini_name, debug_mode );
	}

	if( src_name[0] ) bunri_path( src_name, path_in_name, file_in_name, ext_in_name ); // retは無視
	if( path_in_name[0] == 0 ) strcpy( path_in_name, cur_path_name );

//	sprintf( buf, "%s\\%s", path_in_name, src_name );
	file_cnt = search_src_name( src_name );
	if( file_cnt == 0 )
	{
		printf( " %s not found file\n", src_name );
		usage(); // 使用方法表示
	}

	DeleteFile( debug_name2 );
	total_cnt = 0; // 変更したファイル数
	for( cnt = 0; cnt < file_cnt; cnt++ )
	{
		strcpy( src_name, src_name_buf[cnt].name );
//		ret = bunri_path( src_name, buf, file_in_name, ext_in_name ); // buf = dummy
//		printf( " ﾌｧｲﾙ %s 解析中\r", src_name ); 2019.09.11

		sprintf( old_name, "%s.old", src_name );
		sprintf( src_full_name, "%s\\%s", path_in_name, src_name );
		sprintf( new_name, "%s.new", src_name );
//		if( form_source_name == 1 ) sprintf( new_name, "%s.new", src_name );
//		else sprintf( new_name, "%s", src_name );

		fp_src = fopen( src_name, "rb+" );
		if( fp_src == NULL )
		{
			printf( "Fatal: can't open file:%s\n", src_name );
			wait_exit( 1 );
		}
		fseek( fp_src, 0, SEEK_END );									// 最後
		src_size = ftell( fp_src );										// next address
		if( src_size == 0 ) err_trap( 2, -18, src_name, path_in_name ); // "ｿｰｽﾌｧｲﾙｻｲｽﾞがｾﾞﾛ"
		fseek( fp_src, 0, SEEK_SET );									// 戻す
		max_fdata_line = 0;
		jis_font = j = 0;
		while( (len = fread(big_buf, sizeof(char), LOADSIZE, fp_src)) != 0 )
		{
			for( n = 0; n < len; n++ )
			{
				if( j < (CHAR_SIZE2 - 3) ) buf[j++] = big_buf[n]; // ｿｰｽ1行取り込み
				if( big_buf[n] == _LF )
				{
					max_fdata_line++;
					buf[j++] = 0;
					buf[j++] = 0;
					buf[j++] = 0;
					jis_font += chk_shiift_jis( (u8 *)buf, j );
					j = 0;
				}
			}
		}
		printf( " Shift JISコード数 = %d\r\n", jis_font );
		if( form_utf8_mode == 0 )
		{
			if( jis_font >= 3 ) font_type = 2;	// Shift JIS
			else font_type = 1;					// utf8
		}
		else font_type = form_utf8_mode;				// 指定

		fseek( fp_src, 0, SEEK_SET );					// 戻す

		max_fdata_line += max_fdata_line / 2;			// ｿｰｽ行の5割り増し
		if( max_fdata_line < 5 ) max_fdata_line = 10;	// 適当に10行未満とした
		len = max_fdata_line * sizeof( struct FDATA );
		ope_buf = (struct FDATA *)malloc( len );		// ｴﾘｱを確保する
		if( ope_buf == NULL ) err_trap( 2, -19, 0, 0 ); // malloc()が確保出来ない
		memset( ope_buf, 0, len );						// clear all

		max_line = 0;
		fdata = &ope_buf[0];
		refresh();										// 実行 sub1.c
		if( fp_src != NULL )
		{
			fclose( fp_src );
			fp_src = NULL;
		}

		reform_story(); // 内部変数とｸﾞﾛｰﾊﾞﾙの区別をする sub2.c
		if( max_line )
		{
//			if( fp_debug2 != NULL )
//			{
//				sprintf( w_buf, "source file %s\r\n", src_name );
//				len = strlen( w_buf );
//				fwrite( w_buf, sizeof(char), len, fp_debug2 );
//			}
			len = save_dst_file();
			if( len > 0 ) total_cnt++;
			if( debug_mode )
			{
				printf( " 入力 ﾌｧｲﾙ   = %s\r\n", src_name );
				printf( " 結果 ﾌｧｲﾙ   = %s\r\n", debug_name2 );
				printf( " 違い %d行, 全数 %d行 処理終了\r\n", len, src_line_no );
			}
			else if( len == 0 )
			{
				printf( " 入力 ﾌｧｲﾙ   = %s\r\n", src_name );
				printf( " 変更はありません\r\n" ); // sub3.c
			}
			else { // TAB埋込み & 記録
				switch( form_source_name )
				{
				case 0: // ｿｰｽ名の処理 0:検査のみ
					printf( " 入力 ﾌｧｲﾙ   = %s\r\n", src_name );
					if( len < 0 ) printf( " 変更 ****行, 全数 %d行 処理終了\r\n", src_line_no );
					else printf( " 違い %d行, 全数 %d行 処理終了\r\n", len, src_line_no );
					break;

				case 1: // ｿｰｽ名の処理 1:ｿｰｽ名は変わらず+.newを新規に作る
					printf( " 入力 ﾌｧｲﾙ   = %s\r\n", src_name );
					printf( " 結果 ﾌｧｲﾙ   = %s\r\n", new_name );
					if( len < 0 ) printf( " 変更 ****行, 全数 %d行 処理終了\r\n", src_line_no );
					else printf( " 変更 %d行, 全数 %d行 処理終了\r\n", len, src_line_no );
					break;

				case 2: // ｿｰｽ名の処理 2:ｿｰｽ名を+.oldとする
					printf( " 入力 ﾌｧｲﾙ   = %s --> %s \r\n", src_name, old_name );
					printf( " 出力 ﾌｧｲﾙ   = %s\r\n", src_name );
					if( len < 0 ) printf( " 変更 ****行, 全数 %d行 処理終了\r\n", src_line_no );
					else printf( " 変更 %d行, 全数 %d行 処理終了\r\n", len, src_line_no );
					break;

				case 3: // ｿｰｽ名の処理 3:oldを作らない
					printf( " 入力 ﾌｧｲﾙ   = 出力 ﾌｧｲﾙ = %s\r\n", src_name );
					if( len < 0 ) printf( " 変更 ****行, 全数 %d行 処理終了\r\n", src_line_no );
					else printf( " 変更 %d行, 全数 %d行 処理終了\r\n", len, src_line_no );
					break;

				}
			}
		}
		free( ope_buf );
	}
//	if( fp_debug2 != NULL )
//	{
//		fclose( fp_debug2 );
//		fp_debug2 = NULL;
//	}
	printf( " ========= 変更ファイル数 = %d ============\r\n", total_cnt );
	wait_exit( 0 );
}
