// -------------------------------------------------------------------
// sub2.cpp
// ��������
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
// ������MASK_TYPE���P�ɂ��� ���g�p
// d_buf�ɒǉ�
// return( next pos )
// ---------------------------------------------------------------------
int bind_type( char *d_buf, char *s_buf )
{
	int		pos, back_pos, tok_len;
	char	tok_buf[CHAR_SIZE];

	pos = 0;
	for(;;)
	{
		back_pos = pos;											// �ޔ�
		pos += get_block( 1, tok_buf, &s_buf[pos], &tok_len );	// ��؂�ʒu�܂Ŏc���荞��
		if( tok_len == 0 ) break;
		if( (tmp_moji_type & (C_MASK_TYPE1 | C_MASK_TYPE2)) == 0 ) break;
		strcat( d_buf, " " );
		strcat( d_buf, tok_buf );
	}
	pos = back_pos; // �ύX

	return( pos );
}
// ---------------------------------------------------------------------
// ���èݸނ̽�߰����폜 '('�̌�̽�߰���')'�̑O�̽�߰����폜
// type line_type:����T_DEFINE�Ȃ�'('�O���Ȃ����Ă���Ȃ�,��߰�������)
// ---------------------------------------------------------------------
void delete_casting( char *s_buf )
{
	int		i, n, tok_len, loop_no, kakko_cnt, first, end;
	char	tok_buf[CHAR_SIZE];

	first = 0;
	kakko_cnt = 0;
	loop_no = 0;
	r_pos = 0;
	before_c_type3 = before_c_type2 = before_c_type1 = 0; // n�O��clear
	for(;;)
	{
		r_pos += get_block( 0, tok_buf, &s_buf[r_pos], &tok_len ); // 1 block��荞��
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

		case 1: // ����
			if( cur_moji_type == C_COM3 ) loop_no = 0; // reset
			break;

		case 2: // �m�F
			if( cur_moji_type == C_OTHER ) loop_no++;
			else loop_no = 0;
			break;

		case 3:
			if( cur_moji_type == C_K_R )
			{ // ')'
				if( kakko_cnt == 1 )
				{
					end = before_r_pos; // space����
					loop_no++;
					break;
				}
			}
			loop_no = 0;
			break;

		case 4:
			if( cur_moji_type == C_OTHER )
			{
				i = pass_space( &s_buf[before_r_pos] ); // �߽ ��߰�,TAB
				if( i )
				{ // space�폜
					i += before_r_pos;
					n = strlen( &s_buf[i] );
					memmove( &s_buf[before_r_pos], &s_buf[i], n + 1 );
				}

				i = pass_space( &s_buf[end] ); // �߽ ��߰�,TAB
				if( i )
				{
					i += end;
					n = strlen( &s_buf[i] );
					memmove( &s_buf[end], &s_buf[i], n + 1 );
				}

				i = pass_space( &s_buf[first] ); // �߽ ��߰�,TAB
				if( i )
				{ // space�폜
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
// "include��"< �` >" --> "<�`>" �̽�߰����폜
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
					strcpy( &s_buf[n + 1], &s_buf[n + 2] ); // space��cut
				}
			}
			break;

		case 1:
			if( moji == ' ' )
			{
				strcpy( &s_buf[n], &s_buf[n + 1] ); // space��cut
				n--;								// �␳(�߂�)
			}
			else if( moji == '>' ) mode = 0; // reset
			break;
		}
	}
}
// ---------------------------------------------------------------------
// sizeof()����space�̒���
// ---------------------------------------------------------------------
void reform_sizeof( char *s_buf )
{
	int		n, tok_len, loop_no, kakko_cnt, first_kakko, first, type, f1, e1;
	char	tok_buf[CHAR_SIZE];

	type = 0;
	first_kakko = kakko_cnt = 0;
	loop_no = 0;
	before_r_pos = 0;
	before_c_type3 = before_c_type2 = before_c_type1 = 0; // n�O��clear
	r_pos = 0;
	for(;;)
	{
		r_pos += get_block( 0, tok_buf, &s_buf[r_pos], &tok_len ); // �Վ���1 block��荞��
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

		case 1: // sizeof�̌�
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

		case 2: // sizeof( �̌�
			if( cur_moji_type == C_K_L ) kakko_cnt++;
			else if( cur_moji_type == C_K_R )
			{
				if( --kakko_cnt == 0 )
				{ // sizeof(�`)�̌�
					f1 = pass_space( &s_buf[first] );			// �߽ ��߰�,TAB
					e1 = pass_space( &s_buf[before_r_pos] );	// �߽ ��߰�,TAB
					if( first_kakko == 0 )
					{ // space��}��
						if( e1 == 0 )
						{ // space�Ȃ�
							n = strlen( &s_buf[before_r_pos] );
							memmove( &s_buf[before_r_pos + 1], &s_buf[before_r_pos], n + 1 );
							s_buf[before_r_pos] = ' '; // space��}��
							r_pos++;
						}
						if( f1 == 0 )
						{ // space�Ȃ�
							n = strlen( &s_buf[first] );
							memmove( &s_buf[first + 1], &s_buf[first], n + 1 );
							s_buf[first] = ' '; // space��}��
							r_pos++;
						}
					}
					else { // space���폜
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

		case 3: // sizeof(�`) * �𒲂ׂ�
			if( (cur_moji_type & C_MASK_ENZAN) )
			{ // ���Z�q�̑O��̏��� space�K�v(���Z�q�̌ォ�珈�����邱�� r_pos���ω�����)
				if( s_buf[r_pos] != ' ' && s_buf[r_pos] != _SOH && s_buf[r_pos] != _LF )
				{ // space�K�v
					n = strlen( &s_buf[r_pos] );
					memmove( &s_buf[r_pos + 1], &s_buf[r_pos], n + 1 ); // ��߰�������
					s_buf[r_pos] = ' ';									// space��}��
				}
				if( s_buf[before_r_pos] != ' ' && s_buf[before_r_pos] != _SOH && s_buf[before_r_pos] != _LF )
				{ // ���Z�q�̑O�̏��� space�K�v
					n = strlen( &s_buf[before_r_pos] );
					memmove( &s_buf[before_r_pos + 1], &s_buf[before_r_pos], n + 1 );	// ��߰�������
					s_buf[before_r_pos] = ' ';											// space��}��
				}
			}
			r_pos = before_r_pos;
			loop_no = 0; // reset
			break;

		}
	}
}
// ---------------------------------------------------------------------
// #define �̏����𐮂���B���g�p
// ---------------------------------------------------------------------
void reform_define( char *s_buf )
{
	int		n, k_cnt, tok_len;
	char	tok_buf[CHAR_SIZE];

	if( form_define_tab == 0 ) return;
	// --------- ���ʂ̐��𐔂��� ------------
	before_c_type3 = before_c_type2 = before_c_type1 = 0; // n�O��clear
	k_cnt = 0;
	r_pos = 0;
	cur_moji_type = 0;
	for(;;)
	{
		r_pos += get_block( 0, tok_buf, &s_buf[r_pos], &tok_len ); // 1 block��荞��
		if( tok_len == 0 ) break;
		if( cur_moji_type == C_DEFINE ) continue;
		if( cur_moji_type == C_K_L )
		{
			if( ++k_cnt == 1 )
			{
				if( s_buf[r_pos] != ')' && s_buf[r_pos] != _LF && s_buf[r_pos] != ' ' && s_buf[r_pos] != _SOH )
				{
					n = strlen( &s_buf[r_pos] );
					memmove( &s_buf[r_pos + 1], &s_buf[r_pos], n ); // �m��
					s_buf[r_pos] = ' ';								// space��}��
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
						s_buf[r_pos - 1] = ' ';							// space��}��
						r_pos++;										// �␳
					}
				}
			}
			if( before_c_type1 == C_K_L && (s_buf[r_pos - 2] == ' ' || s_buf[r_pos - 2] == _SOH) )
			{
				n = strlen( &s_buf[r_pos - 1] );
				memmove( &s_buf[r_pos - 2], &s_buf[r_pos - 1], n ); // space���폜
				s_buf[r_pos + n - 2] = 0;
				r_pos--;											// �␳
			}
		}
		else if( cur_moji_type == C_KOMMA )
		{
			if( s_buf[r_pos] && s_buf[r_pos] != _LF && s_buf[r_pos] != ' ' && s_buf[r_pos] != _SOH )
			{
				n = strlen( &s_buf[r_pos] );
				memmove( &s_buf[r_pos + 1], &s_buf[r_pos], n ); // �m��
				s_buf[r_pos] = ' ';								// space��}��
			}
		}
		else if( cur_moji_type == C_COM1 || cur_moji_type == C_COM2 ) break;
	}
}
// ---------------------------------------------------------------------
// �A������(xx) (yy)�Ԃ̽�߰����폜���A�A������
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
		r_pos += get_block( 0, tok_buf, &s_buf[r_pos], &tok_len ); // 1 block��荞��
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
		{ // /* �` */
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
				if( (s_buf[pos2] == ' ' || s_buf[pos2] == _SOH) && (pos2 - pos1) == 2 ) kakko_map[n + 1].tag_pos = pos2; // ��߰���Ĉʒu
			}
		}
	}

	for( n = map_no - 1; n >= 0; n-- )
	{
		if( kakko_map[n].tag_pos )
		{
			i = kakko_map[n].tag_pos;
			strcpy( &s_buf[i], &s_buf[i + 1] ); // ��߰����
		}
	}
}
// ---------------------------------------------------------------------
// ��؂��SOH��TAB�ɕϊ�
// mode 0: ��߰��ɕϊ�
// mode 1: TAB�ɕϊ�
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
				{ // TAB�ʒu
					n = ( n + 3 ) / 4; // �K�vTAB��
					while( n-- ) buf[w_pos++] = _TAB;
				}
				else while( n-- ) buf[w_pos++] = ' ';
			}
		}
		else buf[w_pos++] = moji;
		if( pos > (CHAR_SIZE - 5) ) err_trap_line( 2, -36, 0 ); // "1�s����������"
	}
	memcpy( s_buf, buf, w_pos );
	s_buf[w_pos] = 0;
}
// ---------------------------------------------------------------------
// �����ϐ��Ƹ�۰��ق̋�ʂ�����
// TAB�ƽ�߰��̒���
// ---------------------------------------------------------------------
void reform_story( void )
{
	FILE	*fp_debug;
//	struct	FDATA *fdata_b;
	int		line_no, tok_len, flag, crlf_cnt, asm_cnt, asm_top, n;
	int		before_line_no, before_line_type;
	char	tok_buf[CHAR_SIZE];

	if( debug_mode ) fp_debug = fopen( "renew_debug.txt", "wb" ); // �Â��͍̂폜
	else fp_debug = NULL;

	asm_cnt = asm_top = 0;
	before_line_no = 0;
	before_line_type = 0;
	crlf_cnt = 0;
	for( line_no = 0; line_no < max_line; line_no++ )
	{
		fdata = &ope_buf[line_no];

		if( fp_debug != NULL )
		{ // debug �L�^
			strcpy( tok_buf, fdata->mes );
			chg_soh_tab( 1, tok_buf ); // ��؂��SOH��TAB�ɕϊ�
			n = strlen( tok_buf );
			if( n ) fwrite( tok_buf, sizeof(char), n, fp_debug );
			fwrite( "\r\n", sizeof(char), 2, fp_debug );
		}

		if( fdata->line_type == T_CRLF )
		{
			crlf_cnt++;
			continue; // ����
		}

#ifdef _DEBUG
		if( line_no >= 458 )
		{
			debug_n = fdata->tab_pos;
		}
#endif
		crlf_cnt = 0;									// reset
		if( fdata->line_type & T_MASK_MES ) continue;	// ����

		if( fdata->hojo_flag & (H_YEN1 | H_YEN2) )
		{ // \�w��,#define�͂��̂܂܂ōs�ԍ����� 2013.08.19
			fdata->tab_pos = ( fdata->head_space_len + 3 ) / 4; // �ŏ���TAB,��߰��ȊO�̕�����������܂�
			asm_cnt = asm_top = 0;
		}

		if( form_kakko_space == 0 )
		{
			reform_sizeof( fdata->mes );	// sizeof()����space�̒���
			delete_casting( fdata->mes );	// ���èݸ�
		}
//		if( fdata->line_type == T_DEFINE ) reform_define( fdata->mes );		// #define�̏����𐮂���
//		else
		if( fdata->line_type == T_INCLUDE ) reform_include( fdata->mes );	// "include��"< �` >" --> "<�`>" �̽�߰����폜
		connecting_kakko( fdata->mes );										// () () --> ()()
		before_c_type3 = before_c_type2 = before_c_type1 = 0;				// n�O��clear
		r_pos = 0;
		ope_cnt = 0;														// ����cnt
		// ---------------- 1�s���� -----------------------------
		while( r_pos >= 0 )
		{
			r_pos += get_block( 0, tok_buf, &fdata->mes[r_pos], &tok_len ); // 1 block��荞�� 2012.05.23
//			if( fdata->line_type == T_CRLF ) break;
			if( tok_len == 0 ) break;										// 1�s�I���

			if( cur_moji_type == C_COM1 )
			{ // �� + "//�`"
				if( ope_cnt ) fdata->hojo_flag |= H_MES_E;											// +comment����
				while( tok_len ) r_pos += get_block( 0, tok_buf, &fdata->mes[r_pos], &tok_len );	// �̂Ă�
				asm_cnt = asm_top = 0;
			}
			else if( cur_moji_type == C_COM2 )
			{ // "/*�`*/"
				n = search_end_comment( &fdata->mes[r_pos] );	// "*/"��T��, return �������ʒu(-1=�Ȃ�)
				if( n < 0 ) break;								// bug?
				r_pos += n + 2;
				asm_cnt = asm_top = 0;
				continue;
			}

			if( ope_cnt == 0 )
			{ // 1���
				if( cur_moji_type == C_BIG_K_L )
				{ // asm �̌����J�n
					asm_top = line_no;
					asm_cnt = 0;
				}
				else if( cur_moji_type == C_BIG_K_R )
				{ // asm �̌����I���
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
				{ // ���̑�
					if( cur_moji_type == C_WMOJI || cur_moji_type == C_SMOJI ) r_pos = -1;
					else if( cur_moji_type != C_KOME && (cur_moji_type & C_MASK_ENZAN) ) r_pos = -1;
					else if( cur_moji_type != C_W_KOME && (cur_moji_type & C_MASK_W_ENZAN) ) r_pos = -1;
					else if( cur_moji_type & (C_MASK_RONRI | C_MASK_OTHER | C_MASK_FUKUGO) ) r_pos = -1;
				}
			}
			else { // 2��ڈȌ�
#ifdef _DEBUG
				if( line_no >= 514 && r_pos >= 100 )
				{
					debug_n = (int)fdata->mes[0];
				}
#endif

				if( cur_moji_type == C_IQUAL ) fdata->hojo_flag |= H_IQUAL; // =����
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
			{ // 1block �߽
				r_pos += get_tok2( tok_buf, &fdata->mes[r_pos], &tok_len ); // 1 block��荞��
			}
			ope_cnt++;
		}
		before_line_type = fdata->line_type; // ���Ŏg�p
		before_line_no = line_no;
	}
	max_line -= crlf_cnt; // �Ō�̉��s�݂̂��폜
	if( fp_debug != NULL ) fclose( fp_debug );
}
