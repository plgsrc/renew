// -------------------------------------------------------------------
// sub2.cpp
// 書式検査
// ---------------------------------------------------------------------
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
using namespace std;

#include "struct.h"
#include "renew.h"

#include "main_e.h"
#include "sub1_e.h"
#include "sub2_e.h"
#include "sub3_e.h"

// ---------------------------------------------------------------------
// 複数のMASK_TYPEを１つにする 未使用
// d_bufに追加
// return( next pos )
// ---------------------------------------------------------------------
int bind_type( char *d_buf, char *s_buf )
{
	int		pos, back_pos, tok_len;
	char	tok_buf[CHAR_SIZE];

	pos = 0;
	for(;;)
	{
		back_pos = pos;											// 退避
		pos += get_block( 1, tok_buf, &s_buf[pos], &tok_len );	// 区切り位置まで残り取り込み
		if( tok_len == 0 ) break;
		if( (tmp_moji_type & (C_MASK_TYPE1 | C_MASK_TYPE2)) == 0 ) break;
		strcat( d_buf, " " );
		strcat( d_buf, tok_buf );
	}
	pos = back_pos; // 変更

	return( pos );
}
// ---------------------------------------------------------------------
// ｷｬｽﾃｨﾝｸﾞのｽﾍﾟｰｽを削除 '('の後のｽﾍﾟｰｽと')'の前のｽﾍﾟｰｽを削除
// type line_type:もしT_DEFINEなら'('前がつながっているなら,ｽﾍﾟｰｽを入れる)
// ---------------------------------------------------------------------
void delete_casting( char *s_buf )
{
	int		i, n, tok_len, loop_no, kakko_cnt, first, end;
	char	tok_buf[CHAR_SIZE];

	first = 0;
	kakko_cnt = 0;
	loop_no = 0;
	r_pos = 0;
	before_c_type3 = before_c_type2 = before_c_type1 = 0; // n個前をclear
	for(;;)
	{
		r_pos += get_block( 0, tok_buf, &s_buf[r_pos], &tok_len ); // 1 block取り込み
		if( tok_len == 0 || cur_moji_type == C_COM1 ) return;
		switch( loop_no )
		{
		case 0:
			if( cur_moji_type == C_COM2 ) loop_no = 1;
			else if( (before_c_type1 & (C_MASK_FUKUGO | C_MASK_W_ENZAN | C_MASK_ENZAN | C_MASK_RONRI) ||
				before_c_type1 == C_IQUAL || before_c_type1 == C_K_L) && cur_moji_type == C_K_L )
			{
				first = r_pos;
				kakko_cnt = 1;
				loop_no = 2;
			}
			break;

		case 1: // ｺﾒﾝﾄ
			if( cur_moji_type == C_COM3 ) loop_no = 0; // reset
			break;

		case 2: // 確認
			if( cur_moji_type == C_OTHER ) loop_no++;
			else loop_no = 0;
			break;

		case 3:
			if( cur_moji_type == C_K_R )
			{ // ')'
				if( kakko_cnt == 1 )
				{
					end = before_r_pos; // spaceあり
					loop_no++;
					break;
				}
			}
			loop_no = 0;
			break;

		case 4:
			if( cur_moji_type == C_OTHER )
			{
				i = pass_space( &s_buf[before_r_pos] ); // ﾊﾟｽ ｽﾍﾟｰｽ,TAB
				if( i )
				{ // space削除
					i += before_r_pos;
					n = strlen( &s_buf[i] );
					memmove( &s_buf[before_r_pos], &s_buf[i], n + 1 );
				}

				i = pass_space( &s_buf[end] ); // ﾊﾟｽ ｽﾍﾟｰｽ,TAB
				if( i )
				{
					i += end;
					n = strlen( &s_buf[i] );
					memmove( &s_buf[end], &s_buf[i], n + 1 );
				}

				i = pass_space( &s_buf[first] ); // ﾊﾟｽ ｽﾍﾟｰｽ,TAB
				if( i )
				{ // space削除
					i += first;
					n = strlen( &s_buf[i] );
					memmove( &s_buf[first], &s_buf[i], n + 1 );
				}
			}
			loop_no = 0;
			break;

		}
	}
}
// ---------------------------------------------------------------------
// "includeの"< ～ >" --> "<～>" のｽﾍﾟｰｽを削除
//
// ---------------------------------------------------------------------
void reform_include( char *s_buf )
{
	int		n, mode;
	char	moji;

	mode = 0;
	for( n = 0; s_buf[n]; n++ )
	{
		moji = s_buf[n];
		if( moji == '/' && s_buf[n + 1] == '/' ) break;
		switch( mode )
		{
		case 0:
			if( moji == '<' )
			{ // first
				mode = 1;
				if( s_buf[n + 1] == ' ' )
				{
					strcpy( &s_buf[n + 1], &s_buf[n + 2] ); // spaceをcut
				}
			}
			break;

		case 1:
			if( moji == ' ' )
			{
				strcpy( &s_buf[n], &s_buf[n + 1] ); // spaceをcut
				n--;								// 補正(戻す)
			}
			else if( moji == '>' ) mode = 0; // reset
			break;
		}
	}
}
// ---------------------------------------------------------------------
// sizeof()内のspaceの調整
// ---------------------------------------------------------------------
void reform_sizeof( char *s_buf )
{
	int		n, tok_len, loop_no, kakko_cnt, first_kakko, first, type, f1, e1;
	char	tok_buf[CHAR_SIZE];

	type = 0;
	first_kakko = kakko_cnt = 0;
	loop_no = 0;
	before_r_pos = 0;
	before_c_type3 = before_c_type2 = before_c_type1 = 0; // n個前をclear
	r_pos = 0;
	for(;;)
	{
		r_pos += get_block( 0, tok_buf, &s_buf[r_pos], &tok_len ); // 臨時で1 block取り込み
		if( tok_len == 0 || cur_moji_type == C_COM1 ) return;
		switch( loop_no )
		{
		case 0:
			if( cur_moji_type == C_K_L ) first_kakko++;
//			else if( cur_moji_type == C_IQUAL ) first_kakko = 0; // reset
			else if( cur_moji_type == C_SIZEOF )
			{
				type = before_c_type1;
				loop_no++;
			}
			break;

		case 1: // sizeofの後
			if( cur_moji_type == C_K_L )
			{
				first = r_pos;
				kakko_cnt = 1;
				loop_no++;
			}
			else {
				r_pos = before_r_pos;
				loop_no = 0;
			}
			break;

		case 2: // sizeof( の後
			if( cur_moji_type == C_K_L ) kakko_cnt++;
			else if( cur_moji_type == C_K_R )
			{
				if( --kakko_cnt == 0 )
				{ // sizeof(～)の後
					f1 = pass_space( &s_buf[first] );			// ﾊﾟｽ ｽﾍﾟｰｽ,TAB
					e1 = pass_space( &s_buf[before_r_pos] );	// ﾊﾟｽ ｽﾍﾟｰｽ,TAB
					if( first_kakko == 0 )
					{ // spaceを挿入
						if( e1 == 0 )
						{ // spaceなし
							n = strlen( &s_buf[before_r_pos] );
							memmove( &s_buf[before_r_pos + 1], &s_buf[before_r_pos], n + 1 );
							s_buf[before_r_pos] = ' '; // spaceを挿入
							r_pos++;
						}
						if( f1 == 0 )
						{ // spaceなし
							n = strlen( &s_buf[first] );
							memmove( &s_buf[first + 1], &s_buf[first], n + 1 );
							s_buf[first] = ' '; // spaceを挿入
							r_pos++;
						}
					}
					else { // spaceを削除
						if( e1 )
						{
							e1 += before_r_pos;
							n = strlen( &s_buf[before_r_pos] );
							memmove( &s_buf[before_r_pos], &s_buf[e1], n + 1 );
							r_pos--;
						}
						if( f1 )
						{
							f1 += first;
							n = strlen( &s_buf[first] );
							memmove( &s_buf[first], &s_buf[f1], n + 1 );
							r_pos--;
						}
					}
					loop_no = 3;
				}
			}
			break;

		case 3: // sizeof(～) * を調べる
			if( (cur_moji_type & C_MASK_ENZAN) )
			{ // 演算子の前後の処理 space必要(演算子の後から処理すること r_posが変化する)
				if( s_buf[r_pos] != ' ' && s_buf[r_pos] != _SOH && s_buf[r_pos] != _LF )
				{ // space必要
					n = strlen( &s_buf[r_pos] );
					memmove( &s_buf[r_pos + 1], &s_buf[r_pos], n + 1 ); // ｽﾍﾟｰｽを入れる
					s_buf[r_pos] = ' ';									// spaceを挿入
				}
				if( s_buf[before_r_pos] != ' ' && s_buf[before_r_pos] != _SOH && s_buf[before_r_pos] != _LF )
				{ // 演算子の前の処理 space必要
					n = strlen( &s_buf[before_r_pos] );
					memmove( &s_buf[before_r_pos + 1], &s_buf[before_r_pos], n + 1 );	// ｽﾍﾟｰｽを入れる
					s_buf[before_r_pos] = ' ';											// spaceを挿入
				}
			}
			r_pos = before_r_pos;
			loop_no = 0; // reset
			break;

		}
	}
}
// ---------------------------------------------------------------------
// #define の書式を整える。未使用
// ---------------------------------------------------------------------
void reform_define( char *s_buf )
{
	int		n, k_cnt, tok_len;
	char	tok_buf[CHAR_SIZE];

	if( form_define_tab == 0 ) return;
	// --------- 括弧の数を数える ------------
	before_c_type3 = before_c_type2 = before_c_type1 = 0; // n個前をclear
	k_cnt = 0;
	r_pos = 0;
	cur_moji_type = 0;
	for(;;)
	{
		r_pos += get_block( 0, tok_buf, &s_buf[r_pos], &tok_len ); // 1 block取り込み
		if( tok_len == 0 ) break;
		if( cur_moji_type == C_DEFINE ) continue;
		if( cur_moji_type == C_K_L )
		{
			if( ++k_cnt == 1 )
			{
				if( s_buf[r_pos] != ')' && s_buf[r_pos] != _LF && s_buf[r_pos] != ' ' && s_buf[r_pos] != _SOH )
				{
					n = strlen( &s_buf[r_pos] );
					memmove( &s_buf[r_pos + 1], &s_buf[r_pos], n ); // 確保
					s_buf[r_pos] = ' ';								// spaceを挿入
				}
			}
		}
		else if( cur_moji_type == C_K_R )
		{
			if( --k_cnt == 0 )
			{
				if( r_pos >= 2 )
				{
					if( s_buf[r_pos - 2] != '(' && s_buf[r_pos - 2] != ' ' && s_buf[r_pos - 2] != _SOH )
					{
						n = strlen( &s_buf[r_pos - 1] );
						memmove( &s_buf[r_pos], &s_buf[r_pos - 1], n ); // shift
						s_buf[r_pos - 1] = ' ';							// spaceを挿入
						r_pos++;										// 補正
					}
				}
			}
			if( before_c_type1 == C_K_L && (s_buf[r_pos - 2] == ' ' || s_buf[r_pos - 2] == _SOH) )
			{
				n = strlen( &s_buf[r_pos - 1] );
				memmove( &s_buf[r_pos - 2], &s_buf[r_pos - 1], n ); // spaceを削除
				s_buf[r_pos + n - 2] = 0;
				r_pos--;											// 補正
			}
		}
		else if( cur_moji_type == C_KOMMA )
		{
			if( s_buf[r_pos] && s_buf[r_pos] != _LF && s_buf[r_pos] != ' ' && s_buf[r_pos] != _SOH )
			{
				n = strlen( &s_buf[r_pos] );
				memmove( &s_buf[r_pos + 1], &s_buf[r_pos], n ); // 確保
				s_buf[r_pos] = ' ';								// spaceを挿入
			}
		}
		else if( cur_moji_type == C_COM1 || cur_moji_type == C_COM2 ) break;
	}
}
// ---------------------------------------------------------------------
// 連続した(xx) (yy)間のｽﾍﾟｰｽを削除し、連結する
// ---------------------------------------------------------------------
void connecting_kakko( char *s_buf )
{
	#define MAX_KAKKO_MAP	20
	int		i, n, loop_no, kakko_cnt, pos0, pos1, pos2, tok_len, map_no;
	struct	KAKKO_MAPS kakko_map[MAX_KAKKO_MAP];
	char	tok_buf[CHAR_SIZE];

	memset( &kakko_map, 0, sizeof(kakko_map) );

	map_no = 0;
	kakko_cnt = 0;
	loop_no = 0;
	before_r_pos = 0;
	r_pos = 0;
	for( n = 0; n < MAX_KAKKO_MAP; n++ )
	{
		r_pos += get_block( 0, tok_buf, &s_buf[r_pos], &tok_len ); // 1 block取り込み
		if( tok_len == 0 ) break;
		if( loop_no == 0 )
		{
			if( cur_moji_type == C_COM1 ) break;
			if( cur_moji_type == C_COM2 ) loop_no = 1;
			else if( cur_moji_type == C_K_L )
			{
				kakko_cnt++;
				kakko_map[map_no].kakko_cnt = kakko_cnt;
				kakko_map[map_no].c_type = C_K_L;
				kakko_map[map_no].pos = r_pos - 1;
				map_no++;
			}
			else if( cur_moji_type == C_K_R )
			{
				if( kakko_cnt > 0 )
				{
					kakko_map[map_no].kakko_cnt = kakko_cnt;
					kakko_map[map_no].c_type = C_K_R;
					kakko_map[map_no].pos = r_pos - 1;
					kakko_cnt--;
					map_no++;
				}
			}
		}
		else if( loop_no == 1 )
		{ // /* ～ */
			if( cur_moji_type == C_COM3 ) loop_no = 0; // reset
		}
	}
	for( n = 0; n < map_no; n++ )
	{
		if( kakko_map[n + 1].c_type == C_K_R && kakko_map[n + 2].c_type == C_K_L )
		{
			i = n;
			while( i > 0 )
			{
				if( kakko_map[i].kakko_cnt == kakko_map[n + 2].kakko_cnt ) break;
				else i--;
			}
			pos0 = kakko_map[i].pos - 1;
			pos1 = kakko_map[i + 1].pos - 1;
			pos2 = kakko_map[n + 2].pos - 1;
			if( pos0 < 0 || s_buf[pos0] == ' ' || s_buf[pos0] == _SOH )
			{
				if( (s_buf[pos2] == ' ' || s_buf[pos2] == _SOH) && (pos2 - pos1) == 2 ) kakko_map[n + 1].tag_pos = pos2; // ｽﾍﾟｰｽｶｯﾄ位置
			}
		}
	}

	for( n = map_no - 1; n >= 0; n-- )
	{
		if( kakko_map[n].tag_pos )
		{
			i = kakko_map[n].tag_pos;
			strcpy( &s_buf[i], &s_buf[i + 1] ); // ｽﾍﾟｰｽをｶｯﾄ
		}
	}
}
// ---------------------------------------------------------------------
// 区切りのSOHをTABに変換
// mode 0: ｽﾍﾟｰｽに変換
// mode 1: TABに変換
// ---------------------------------------------------------------------
void chg_soh_tab( int mode, char *s_buf )
{
	int		w_pos, pos, n;
	char	buf[CHAR_SIZE], moji;

	w_pos = pos = 0;
	while( (moji = s_buf[pos++]) != 0 )
	{
		if( moji == _SOH )
		{
			if( mode == 0 ) buf[w_pos++] = ' ';
			else {
				n = 1;
				while( (moji = s_buf[pos]) == _SOH )
				{
					n++;
					pos++;
				}
				if( (pos % 4) == 0 )
				{ // TAB位置
					n = ( n + 3 ) / 4; // 必要TAB数
					while( n-- ) buf[w_pos++] = _TAB;
				}
				else while( n-- ) buf[w_pos++] = ' ';
			}
		}
		else buf[w_pos++] = moji;
		if( pos > (CHAR_SIZE - 5) ) err_trap_line( 2, -36, 0 ); // "1行が長すぎる"
	}
	memcpy( s_buf, buf, w_pos );
	s_buf[w_pos] = 0;
}
// ---------------------------------------------------------------------
// 内部変数とｸﾞﾛｰﾊﾞﾙの区別をする
// TABとｽﾍﾟｰｽの調整
// ---------------------------------------------------------------------
void reform_story( void )
{
	FILE	*fp_debug;
//	struct	FDATA *fdata_b;
	int		line_no, tok_len, flag, crlf_cnt, asm_cnt, asm_top, n;
	int		before_line_no, before_line_type;
	char	tok_buf[CHAR_SIZE];

	if( debug_mode ) fp_debug = fopen( "renew_debug.txt", "wb" ); // 古いのは削除
	else fp_debug = NULL;

	asm_cnt = asm_top = 0;
	before_line_no = 0;
	before_line_type = 0;
	crlf_cnt = 0;
	for( line_no = 0; line_no < max_line; line_no++ )
	{
		fdata = &ope_buf[line_no];

		if( fp_debug != NULL )
		{ // debug 記録
			strcpy( tok_buf, fdata->mes );
			chg_soh_tab( 1, tok_buf ); // 区切りのSOHをTABに変換
			n = strlen( tok_buf );
			if( n ) fwrite( tok_buf, sizeof(char), n, fp_debug );
			fwrite( "\r\n", sizeof(char), 2, fp_debug );
		}

		if( fdata->line_type == T_CRLF )
		{
			crlf_cnt++;
			continue; // 無視
		}

#ifdef _DEBUG
		if( line_no >= 458 )
		{
			debug_n = fdata->tab_pos;
		}
#endif
		crlf_cnt = 0;									// reset
		if( fdata->line_type & T_MASK_MES ) continue;	// 無視

		if( fdata->hojo_flag & (H_YEN1 | H_YEN2) )
		{ // \指定,#defineはそのままで行番号あり 2013.08.19
			fdata->tab_pos = ( fdata->head_space_len + 3 ) / 4; // 最初のTAB,ｽﾍﾟｰｽ以外の文字が見つかるまで
			asm_cnt = asm_top = 0;
		}

		if( form_kakko_space == 0 )
		{
			reform_sizeof( fdata->mes );	// sizeof()内のspaceの調整
			delete_casting( fdata->mes );	// ｷｬｽﾃｨﾝｸﾞ
		}
//		if( fdata->line_type == T_DEFINE ) reform_define( fdata->mes );		// #defineの書式を整える
//		else
		if( fdata->line_type == T_INCLUDE ) reform_include( fdata->mes );	// "includeの"< ～ >" --> "<～>" のｽﾍﾟｰｽを削除
		connecting_kakko( fdata->mes );										// () () --> ()()
		before_c_type3 = before_c_type2 = before_c_type1 = 0;				// n個前をclear
		r_pos = 0;
		ope_cnt = 0;														// 項目cnt
		// ---------------- 1行処理 -----------------------------
		while( r_pos >= 0 )
		{
			r_pos += get_block( 0, tok_buf, &fdata->mes[r_pos], &tok_len ); // 1 block取り込み 2012.05.23
//			if( fdata->line_type == T_CRLF ) break;
			if( tok_len == 0 ) break;										// 1行終わり

			if( cur_moji_type == C_COM1 )
			{ // 文 + "//～"
				if( ope_cnt ) fdata->hojo_flag |= H_MES_E;											// +commentあり
				while( tok_len ) r_pos += get_block( 0, tok_buf, &fdata->mes[r_pos], &tok_len );	// 捨てる
				asm_cnt = asm_top = 0;
			}
			else if( cur_moji_type == C_COM2 )
			{ // "/*～*/"
				n = search_end_comment( &fdata->mes[r_pos] );	// "*/"を探す, return 見つけた位置(-1=なし)
				if( n < 0 ) break;								// bug?
				r_pos += n + 2;
				asm_cnt = asm_top = 0;
				continue;
			}

			if( ope_cnt == 0 )
			{ // 1回目
				if( cur_moji_type == C_BIG_K_L )
				{ // asm の検査開始
					asm_top = line_no;
					asm_cnt = 0;
				}
				else if( cur_moji_type == C_BIG_K_R )
				{ // asm の検査終わり
					asm_cnt = asm_top = 0;
				}
				else if( fdata->hojo_flag & H_ASM )
				{
					if( asm_top == 0 ) fdata->hojo_flag &= ~( H_ASM );	// reset
					else {
//						fdata->hojo_flag |= H_ASM;						// set
						fdata->line_type = T_ASM;						// set
						asm_cnt++;
						r_pos = -1;
						break;
					}
				}
				else if( asm_top )
				{
					if( asm_cnt )
					{
//						fdata->hojo_flag |= H_ASM;	// set
						fdata->line_type = T_ASM;	// set
						asm_cnt++;
						r_pos = -1;
						break;
					}
					else asm_cnt = asm_top = 0;
				}

#ifdef _DEBUG
				if( line_no >= 511 )
				{
					debug_n = fdata->tab_pos;
				}
#endif
				if( fdata->line_type & T_TYPE )
				{ // int,long etc
					if( fdata->tab_pos )
					{
						if( fdata->hojo_flag & H_UNION ) fdata->line_type = T_UNION_IN;
						else if( fdata->hojo_flag & H_STRUCT ) fdata->line_type = T_STRUCT_IN;
						else fdata->line_type = T_TYPE_IN; // local
					}
					else fdata->line_type = T_TYPE; // global
				}
				else if( fdata->line_type & T_STRUCT )
				{ // struct
					if( fdata->tab_pos ) fdata->line_type = T_STRUCT_IN; // local
				}
				else if( fdata->line_type & T_UNION )
				{ // union
					if( fdata->tab_pos ) fdata->line_type = T_UNION_IN; // local
				}
				else if( fdata->line_type == T_OTHER )
				{ // その他
					if( cur_moji_type == C_WMOJI || cur_moji_type == C_SMOJI ) r_pos = -1;
					else if( cur_moji_type != C_KOME && (cur_moji_type & C_MASK_ENZAN) ) r_pos = -1;
					else if( cur_moji_type != C_W_KOME && (cur_moji_type & C_MASK_W_ENZAN) ) r_pos = -1;
					else if( cur_moji_type & (C_MASK_RONRI | C_MASK_OTHER | C_MASK_FUKUGO) ) r_pos = -1;
				}
			}
			else { // 2回目以後
#ifdef _DEBUG
				if( line_no >= 514 && r_pos >= 100 )
				{
					debug_n = (int)fdata->mes[0];
				}
#endif

				if( cur_moji_type == C_IQUAL ) fdata->hojo_flag |= H_IQUAL; // =あり
				if( fdata->line_type == T_OTHER )
				{
					if( ope_cnt == 1 && before_c_type1 == C_OTHER )
					{
						flag = 0;
						if( cur_moji_type & (C_MASK_RONRI | C_MASK_FUKUGO | C_MASK_W_ENZAN) ) flag = 0;
						else if( cur_moji_type & (C_MASK_TYPE1 | C_MASK_TYPE2) ) flag = 1;
						else if( cur_moji_type == C_KOME ) flag = 1;									// '*'
						else if( cur_moji_type == C_AND ) flag = 1;										// '&'
						else if( cur_moji_type == C_K_L ) flag = 1;										// '('
						else if( cur_moji_type == C_MID_K_L &&
							(fdata->mes[r_pos - 2] == ' ' || fdata->mes[r_pos - 2] == _SOH) ) flag = 1; // '['
						else if( cur_moji_type == C_OTHER ) flag = 1;									// '#xxxx"
						else if( cur_moji_type == C_DEF_ANOTHER ) flag = 1;								// "# xxxx"
						if( flag )
						{
							if( fdata->tab_pos ) fdata->line_type = T_OTHER_IN; // local
							else fdata->line_type = T_OTHER_TYPE;				// macro
						}
					}
				}
			}
			if( fdata->mes[r_pos] != ' ' && fdata->mes[r_pos] != _SOH )
			{ // 1block ﾊﾟｽ
				r_pos += get_tok2( tok_buf, &fdata->mes[r_pos], &tok_len ); // 1 block取り込み
			}
			ope_cnt++;
		}
		before_line_type = fdata->line_type; // 次で使用
		before_line_no = line_no;
	}
	max_line -= crlf_cnt; // 最後の改行のみを削除
	if( fp_debug != NULL ) fclose( fp_debug );
}
