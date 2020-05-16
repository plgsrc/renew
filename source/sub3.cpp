// ---------------------------------------------------------------------
// sub3.cpp
// ���`�o��
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
#include <string>
using namespace std;

#include "struct.h"
#include "renew.h"

#include "main_e.h"
#include "sub1_e.h"
#include "sub2_e.h"
#include "sub3_e.h"

// ------------------------------------------------------------
struct S_TYPE debug_type_map[] = {
	{ T_IF,			"IF"		 },
	{ T_IF1,		"IF1"		 },
	{ T_IF2,		"IF2"		 },
	{ T_IF3,		"IF3"		 },
	{ T_IF4,		"IF4"		 },
	{ T_IF5,		"IF5"		 },
	{ T_IF6,		"IF6"		 },
	{ T_IFX,		"IFX"		 },

	{ T_ELSE,		"ELSE"		 },
	{ T_ELSE1,		"ELSE1"		 },
	{ T_ELSE2,		"ELSE2"		 },
	{ T_ELSE3,		"ELSE3"		 },
	{ T_ELSE4,		"ELSE4"		 },
	{ T_ELSE5,		"ELSE5"		 },
	{ T_ELSE6,		"ELSE6"		 },
	{ T_ELSE_BIG,	"ELSE_BIG"	 },
	{ T_ELSE_IF,	"ELSE_IF"	 },
	{ T_ELSEX,		"ELSEX"		 },

	{ T_MASK_MES,	"MASK_MES"	 },
	{ T_MES14,		"MES14"		 },
	{ T_MES15,		"MES15"		 },
	{ T_MES16,		"MES16"		 },
	{ T_MES17,		"MES17"		 },

	{ T_SWITCH,		"SWITCH"	 },
	{ T_SWITCH1,	"SWITCH1"	 },
	{ T_SWITCH2,	"SWITCH2"	 },
	{ T_SWITCH3,	"SWITCH3"	 },
	{ T_SWITCH4,	"SWITCH4"	 },
	{ T_SWITCH5,	"SWITCH5"	 },
	{ T_SWITCH6,	"SWITCH6"	 },
	{ T_SWITCHX,	"SWITCHX"	 },

	{ T_CASE,		"CASE"		 },
	{ T_CASE1,		"CASE1"		 },
	{ T_CASE2,		"CASE2"		 },
	{ T_CASE3,		"CASE3"		 },
	{ T_DEFAULT1,	"DEFAULT1"	 },
	{ T_DEFAULT2,	"DEFAULT2"	 },
	{ T_DEFAULT3,	"DEFAULT3"	 },

	{ T_WHILE,		"WHILE"		 },
	{ T_WHILE1,		"WHILE1"	 },
	{ T_WHILE2,		"WHILE2"	 },
	{ T_WHILE3,		"WHILE3"	 },
	{ T_WHILE4,		"WHILE4"	 },
	{ T_WHILE5,		"WHILE5"	 },
	{ T_WHILE6,		"WHILE6"	 },
	{ T_WHILEX,		"WHILEX"	 },

	{ T_DO,			"DO"		 },
	{ T_DO1,		"DO1"		 },
	{ T_DO2,		"DO2"		 },
	{ T_DO3,		"DO3"		 },
	{ T_DO4,		"DO4"		 },
	{ T_DO5,		"DO5"		 },
	{ T_DO6,		"DO6"		 },
	{ T_DOX,		"DOX"		 },

	{ T_FOR,		"FOR"		 },
	{ T_FOR1,		"FOR1"		 },
	{ T_FOR2,		"FOR2"		 },
	{ T_FOR3,		"FOR3"		 },
	{ T_FOR4,		"FOR4"		 },
	{ T_FOR5,		"FOR5"		 },
	{ T_FORX,		"FORX"		 },

	{ T_RETURN,		"RETURN"	 },
	{ T_RETURN1,	"RETURN1"	 },
	{ T_RETURN2,	"RETURN2"	 },
	{ T_RETURN3,	"RETURN3"	 },
	{ T_RETURN4,	"RETURN4"	 },

	{ T_BIG_KAKKO,	"BIG_KAKKO"  },

	{ T_TYPE,		"TYPE"		 },
//	{ T_INT,		"INT"		 },
//	{ T_CHAR,		"CHAR"		 },
//	{ T_SHORT,		"SHORT"		 },
//	{ T_LONG,		"LONG"		 },
//	{ T_BOOL,		"BOOL"		 },
//	{ T_VOID,		"VOID"		 },
	{ T_OTHER_TYPE, "OTHER_TYPE" },

	{ T_STRUCT,		"STRUCT"	 },
	{ T_STRUCT1,	"STRUCT1"	 },
	{ T_STRUCT2,	"STRUCT2"	 },
	{ T_STRUCT3,	"STRUCT3"	 },
	{ T_STRUCT4,	"STRUCT4"	 },
	{ T_STRUCT5,	"STRUCT5"	 },
	{ T_STRUCT6,	"STRUCT6"	 },
	{ T_STRUCTX,	"STRUCTX"	 },

	{ T_UNION,		"UNION"		 },
	{ T_UNION1,		"UNION1"	 },
	{ T_UNION2,		"UNION2"	 },
	{ T_UNION3,		"UNION3"	 },
	{ T_UNION4,		"UNION4"	 },
	{ T_UNION5,		"UNION5"	 },
	{ T_UNION6,		"UNION6"	 },

	{ T_DEFIF,		"DEFIF"		 },
	{ T_DEF_IF1,	"DEF_IF1"	 },
	{ T_DEF_IF2,	"DEF_IF2"	 },

	{ T_DEF_ELSE,	"DEF_ELSE"	 },
	{ T_DEF_ELSE1,	"DEF_ELSE1"  },
	{ T_DEF_ELSE2,	"DEF_ELSE2"  },

	{ T_DEF_END,	"DEF_END"	 },
	{ T_DEF_END1,	"DEF_END1"	 },
	{ T_DEF_END2,	"DEF_END2"	 },

	{ T_DEFINE,		"DEFINE"	 },
	{ T_DEFINE1,	"DEFINE1"	 },
	{ T_DEFINE2,	"DEFINE2"	 },
	{ T_DEFINE3,	"DEFINE3"	 },
	{ T_DEFINEX,	"DEFINEX"	 },

	{ T_DEF_ANO,	"DEF_ANO"	 },

	{ T_TYPEDEF,	"TYPEDEF"	 },

	{ T_CALL,		"CALL"		 },

//	{ T_EXTERN,		"EXTERN"	 },
	{ T_INCLUDE,	"INCLUDE"	 },
	{ T_PRAGMA,		"PRAGMA"	 },
	{ T_DEF_OTHER,	"DEF_OTHER"  },

	{ T_CRLF,		"CRLF"		 },
	{ T_PROC,		"PROC"		 },
	{ T_MULTI,		"MULTI"		 },
	{ T_B_K_PAIR,	"B_K_PAIR"	 },
	{ T_SEMIKOLON,	"SEMIKOLON", },
	{ T_MOJIS,		"MOJIS",	 },
	{ T_DIGIT,		"DIGIT"		 },

	{ T_TYPE_IN,	"TYPE_IN"	 },
	{ T_O_DEF_IN,	"O_DEF_IN"	 },
	{ T_STRUCT_IN,	"STRUCT_IN"  },
	{ T_UNION_IN,	"UNION_IN"	 },
	{ T_OTHER_IN,	"OTHER_IN"	 },

	{ T_COM_MES,	"COM_MES"	 },

	{ T_OTHER,		"OTHER"		 },
	{ T_RENZOKU,	"RENZOKU"	 },
	{ T_ASM,		"ASM"		 },

//	{ G_TAB_EN,		"TAB_EN"	 },
	{ 0,			""			 }
};

// ----------------------------------------------
// ���Z�q���̌���
// return 0:����, 1:�L��
// ----------------------------------------------
// int ismath( char *moji_buf )
// {
//	if( moji_buf[1] == 0 )
//	{
//		if( moji_buf[0] == '*' || moji_buf[0] == '/' || moji_buf[0] == '+' || moji_buf[0] == '-' ) return( 1 );
//		else return( 0 );
//	}
//	else return( 0 );
// }
// ====================================================================
// �y�@�\�zint�𱽷��ɕϊ�
// �y���́zobj_data	: �����ް�
// �y���́z*d_str	: �ϊ���̎��[��
// �y���́zlen		: �ϊ���̒���(max 10)
// �y�o�́z�Ȃ�
// �y���l�z
// ====================================================================
// void int_asc( int obj_data, char *d_str, int len )
// {
//	int		n;
//	char	buf[20];
//
//	_itoa( obj_data, buf, 10 );
//	n = (int)strlen( buf );
//	if( n < len )
//	{
//		memset( d_str, ' ', len - n );
//		memcpy( &d_str[len - n], buf, n );
//	}
//	else memcpy( d_str, buf, len );
// }
// ====================================================================
// �y�@�\�zlong�𱽷��ɕϊ�
// �y���́zobj_data	: �����ް�
// �y���́z*d_str	: �ϊ���̎��[��
// �y���́zlen		: �ϊ���̒���(max 9)
// �y�o�́z�Ȃ�
// �y���l�z
// ====================================================================
// void long_asc( long obj_data, char *d_str, int len )
// {
//	int		n;
//	char	buf[20];
//
//	_ltoa( obj_data, buf, 10 );
//	n = (int)strlen( buf );
//	if( n < len )
//	{
//		memset( d_str, ' ', len - n );
//		memcpy( &d_str[len - n], buf, n );
//	}
//	else memcpy( d_str, buf, len );
// }
// ====================================================================
// �y�@�\�z2word ���޲�؂𱽷��ɕϊ�(0��t��)
// �y���́zint obj_data, char *d_str
// �y�o�́z�Ȃ�
// �y���l�z
// ====================================================================
// void obj_bcd8( int obj_data, char *d_str )
// {
//	static char hex_map[] = "0123456789ABCDEF";
//	int			i;
//	int			sign;
//
//	if( obj_data < 0 )
//	{ // ϲŽ
//		obj_data = labs( obj_data );
//		sign = 1;
//	}
//	else sign = 0;
//
//	i = 8;
//	while( i-- )
//	{
//		if( i == 0 && sign ) d_str[0] = '-';
//		else {
//			d_str[i] = hex_map[obj_data % 10];
//			obj_data = obj_data / 10;
//		}
//	}
// }
// ---------- n��(MAX=8)��BCD��2word���޲�؂ɕϊ� ----------
// int bcd_obj8( char *s_buf )
// {
//	int		obj_data;
//	int		i;
//	char	moji;
//
//	obj_data = 0L;
//	for( i = 0; i < 8; i++ )
//	{
//		moji = s_buf[i];
//		if( moji >= '0' && moji <= '9' ) obj_data = ( obj_data * 10 ) + ( moji & 0xf ); // 0�`9
//		else return( obj_data );
//	}
//	return( obj_data );
// }
// --------------------------------------------------
int get_key( void )
{
	// ��׸�����ނ�0x00�̂Ƃ��ͤ���ݺ��ނ�ǂނ悤�ɂȂ��Ă�
	int keydata;

	keydata = getchar();
	if( keydata == -1 ) return( -1 );

	return( keydata & 0xff );
}
// -------------- ������check -------------------------
int moji_check( char moji )
{
	int c;

	c = (int)moji & 0xff;
	if( c < ' ' ) return( 1 );									// control code
	if( c < 0x7f ) return( 2 );									// print code
	if( c == 0x7f ) return( 4 );								// delete code
//	if( (c & 0xe0) == 0x80 || (c & 0xe0) == 0xe0 ) return( 8 ); // kanji
	if( (c >= 0x81) && c <= 0x84 ) return( 8 );					// ShiftJIS ����
	if( (c >= 0x87) && c <= 0x9F ) return( 8 );					// ShiftJIS ����
	if( (c >= 0xE0) && c <= 0xE9 ) return( 8 );					// ShiftJIS ����
	if( (c >= 0xED) && c <= 0xEE ) return( 8 );					// ShiftJIS ����
	if( (c >= 0xA1) && c <= 0xDF ) return( 0x10 );				// ShiftJIS ���p�J�i
	return( 0x20 );												// ���̑�
}
// ---------------------------------------------------------
int _isalpha( int moji )
{
	moji &= 0xff;
	if( moji < 0 || moji > 255 ) return( 0 );
	else return( isalpha(moji) );
}
// ---------------------------------------------------------
int _isupper( int moji )
{
	moji &= 0xff;
	if( moji < 0 || moji > 255 ) return( 0 );
	else return( isupper(moji) );
}
// ---------------------------------------------------------
int _islower( int moji )
{
	moji &= 0xff;
	if( moji < 0 || moji > 255 ) return( 0 );
	else return( islower(moji) );
}
// ---------------------------------------------------------
int _isdigit( int moji )
{
	moji &= 0xff;
	if( moji < 0 || moji > 255 ) return( 0 );
	else return( isdigit(moji) );
}
// ---------------------------------------------------------
int _isxdigit( int moji )
{
	moji &= 0xff;
	if( moji < 0 || moji > 255 ) return( 0 );
	else return( isxdigit(moji) );
}
// ---------------------------------------------------------
int _isspace( int moji )
{
	moji &= 0xff;
	if( moji < 0 || moji > 255 ) return( 0 );
	else return( isspace(moji) );
}
// ---------------------------------------------------------
int _ispunct( int moji )
{
	moji &= 0xff;
	if( moji < 0 || moji > 255 ) return( 0 );
	else return( ispunct(moji) );
}
// ---------------------------------------------------------
int _isalnum( int moji )
{
	moji &= 0xff;
	if( moji < 0 || moji > 255 ) return( 0 );
	else return( isalnum(moji) );
}
// ---------------------------------------------------------
int _isprint( int moji )
{
	moji &= 0xff;
	if( moji < 0 || moji > 255 ) return( 0 );
	else return( isprint(moji) );
}
// ---------------------------------------------------------
int _isgraph( int moji )
{
	moji &= 0xff;
	if( moji < 0 || moji > 255 ) return( 0 );
	else return( isgraph(moji) );
}
// ---------------------------------------------------------
int _iscntrl( int moji )
{
	moji &= 0xff;
	if( moji < 0 || moji > 255 ) return( 0 );
	else return( iscntrl(moji) );
}
//
// ====================================================================
// �y�@�\�z1byte���޲�؂�2����BCD�ɕϊ�
// �y���́z�޲���ް�,���������ޯ̧
// �y�o�́z�Ȃ�
// �y���l�z
// ====================================================================
//
void obj_bcd2( int obj_data, char *wr_buf )
{
	wr_buf[1] = hex_map[obj_data % 10];
	obj_data /= 10;
	wr_buf[0] = hex_map[obj_data % 10];
}
// ---------------------------------------------------------
//	debug�p t_type�����𓾂�
//	ү���ނ�10�����Œ�ɂ���
// ---------------------------------------------------------
void get_debug_type_map( char *d_buf, int t_type )
{
	int n;

	for( n = 0; debug_type_map[n].t_type; n++ )
	{
		if( debug_type_map[n].t_type == t_type ) break;
	}
	if( debug_type_map[n].name[0] ) sprintf( d_buf, "%-10s", debug_type_map[n].name );
	else {
		if( t_type ) sprintf( d_buf, "[%08x]", t_type );	// 10�����Œ�
		else strcpy( d_buf, "[       0]" );					// 0
	}
}
// ------------------------------------------------------------------
// buffer���̕�����̐؂�o��
// mode 0: cur_moji_type <- tmp_moji_type
// mode 1: tmp_moji_type �g�p
// max ������100�����܂�
// return s_buf�̎��̈ʒu
// ------------------------------------------------------------------
int get_tok1( int mode, char *d_buf, char *s_buf, int *tok_len )
{
	int		src_cnt, put_cnt, max_len, loop_type, len, flag, k_cnt, n;
	char	moji;

	k_cnt = 0;
	*tok_len = 0;
	put_cnt = 0;
	max_len = CHAR_SIZE - 3;

	src_cnt = pass_space( s_buf ); // �߽ ��߰�,TAB
	flag = 0;
	while( (moji = s_buf[src_cnt]) != 0 )
	{
		if( flag == 0 )
		{ // ����
			flag = 1;
			if( moji == 0x22 || moji == 0x27 ) break;
			if( _isdigit(moji) ) break;
			if( moji_check(moji) == 8 && s_buf[src_cnt + 1] ) break; // ����
			if( _isalpha(moji) || moji == '_' || moji == '#' )
			{ // ������
				d_buf[put_cnt++] = moji;
				src_cnt++;
				flag = 2; // ������
			}
			else { // ���̑�
				d_buf[put_cnt++] = moji;
				src_cnt++;
			}
		}
		else if( flag == 1 )
		{ // �ʏ�
			if( moji == _SOH || moji == ' ' ) break;
			else {
				d_buf[put_cnt++] = moji;
				src_cnt++;
				if( put_cnt == 2 )
				{
					if( d_buf[0] == '/' || d_buf[1] == '*' ) break;
					if( d_buf[0] == '*' || d_buf[1] == '/' ) break;
				}
				if( moji_check(moji) == 8 && s_buf[src_cnt + 1] ) break;	// ����
				if( put_cnt > 8 ) break;									// �\����,8�������ő�(unsigned)
			}
		}
		else { // ������
			if( moji_check(moji) == 8 )
			{
				src_cnt++; // ����
				break;
			}
			else if( _isalpha(moji) || _isdigit(moji) || moji == '_' || moji == '.' || moji == '#' )
			{
				d_buf[put_cnt++] = moji;
				src_cnt++;
			}
			else break;
		}
	}
	d_buf[put_cnt] = 0;
	if( flag == 1 ) flag = 0;							// ����(������v)
	else flag = 1;										// �S����v
	tmp_moji_type = search_yoyaku( flag, d_buf, &len ); // �\�񕶎���T��
	if( tmp_moji_type == C_COM1 )
	{
		src_cnt = strlen( s_buf );
	}
	else if( tmp_moji_type == C_COM2 )
	{ // "/*�`*/"
		src_cnt = search_end_comment( s_buf ); // "*/"��T��, return �������ʒu(-1=�Ȃ�)
		if( src_cnt >= 0 )
		{
			src_cnt += 2;
			while( (moji = s_buf[src_cnt]) != 0 )
			{ // ���̽�߰��܂��߽
				if( moji == _SOH || moji == ' ' ) break;
				src_cnt++;
			}
		}
		else {
			src_cnt = strlen( s_buf );	// �Ō�܂łȂ�
			tmp_moji_type = C_COM1;		// "/* �`"(LF�̑O�܂�)
		}
	}
	else if( tmp_moji_type == C_COM3 )
	{ // "�`*/"
		src_cnt = pass_space( s_buf ) + len; // �߽ ��߰�,TAB
	}
	else if( tmp_moji_type )
	{ // �A��������̌���
		// -------------- �؂�o���̍Ō�̈ʒu��T�� ------------------
		src_cnt = pass_space( s_buf ) + len; // �߽ ��߰�,TAB
		if( (tmp_moji_type & C_MASK_TYPE1) && s_buf[src_cnt] == '*' )
		{ // ������'*' or "**"
			while( s_buf[src_cnt] == '*' ) src_cnt++; // "*"�߽
			while( (moji = s_buf[src_cnt]) != 0 )
			{ // TAB,��߰��܂�
				if( moji == _SOH || moji == ' ' ) break;
				tmp_moji_type = C_OTHER;
				src_cnt++;
			}
		}
		else if( tmp_moji_type == C_KOME || tmp_moji_type == C_W_KOME || tmp_moji_type == C_AND )
		{ // '*' or "**" or "&"�̌��T��
			moji = s_buf[src_cnt];
			if( _isalpha(moji) || moji == '_' )
			{
				tmp_moji_type = C_OTHER;
				do {
					moji = s_buf[++src_cnt]; // copy
				} while( !(moji == _SOH || moji == ' ' || moji == 0) );
				tmp_moji_type = C_OTHER;
			}
		}
		else if( tmp_moji_type == C_PLUS || tmp_moji_type == C_MINUS )
		{
			moji = s_buf[src_cnt];
			if( _isdigit(moji) || _isalpha(moji) )
			{
				if( _isdigit(moji) ) tmp_moji_type = C_DIGIT;
				else tmp_moji_type = C_OTHER;
				do {
					moji = s_buf[++src_cnt]; // copy
				} while( !(moji == _SOH || moji == ' ' || moji == 0) );
			}
		}
	}
	else { // �ŏ�����T��(���̑�)
		tmp_moji_type = 0;
		loop_type = 0;
		src_cnt = pass_space( s_buf ); // �߽ ��߰�,TAB
		while( (moji = s_buf[src_cnt]) != 0 )
		{
			if( (loop_type != C_WMOJI && loop_type != C_SMOJI) && (moji == _SOH || moji == ' ') ) break;
			switch( loop_type )
			{
			case 0: // �ŏ��̕���
				if( moji_check(moji) == 8 && s_buf[src_cnt + 1] )
				{
					src_cnt++;				// ����
					loop_type = C_ILLEGAL;	// ���̑�
				}
				else if( moji == 0x22 ) loop_type = C_WMOJI;	// """
				else if( moji == 0x27 ) loop_type = C_SMOJI;	// "'"
				else if( _isdigit(moji) ) loop_type = C_DIGIT;
				else loop_type = C_OTHER;						// ���̑�
				tmp_moji_type = loop_type;
				break;

			case C_WMOJI: // '"'
				if( moji == _LF )
				{
					tmp_moji_type = C_ILLEGAL;	// ��@
					loop_type = -1;				// ���~
					break;
				}
				if( moji_check(moji) == 8 && s_buf[src_cnt + 1] ) src_cnt++; // ����
				else if( moji == 0x5c )
				{ // '\\'
					if( s_buf[src_cnt + 1] == 'n' || s_buf[src_cnt + 1] == 'r' || s_buf[src_cnt + 1] == 't' ) src_cnt++;
					else if( (s_buf[src_cnt + 1] == _LF || s_buf[src_cnt + 1] == 0) )
					{
						tmp_moji_type = C_ILLEGAL; // ��@
						src_cnt++;
						loop_type = -1;
					}
					else src_cnt++; // '\"'
				}
				else if( moji == 0x22 )
				{ // '\"'
					src_cnt++;
					loop_type = -1;
				}
				break;

			case C_SMOJI: // ''' �P�ƕ���
				if( moji == _LF )
				{
					tmp_moji_type = C_ILLEGAL;	// ��@
					loop_type = -1;				// ���~
					break;
				}
				if( moji_check(moji) == 8 && s_buf[src_cnt + 1] ) src_cnt++; // ����
				else if( moji == 0x5c )
				{ // '\\'
					if( s_buf[src_cnt + 1] == 0x5c || s_buf[src_cnt + 1] == 'n' ||
						s_buf[src_cnt + 1] == 'r' || s_buf[src_cnt + 1] == 't' ) src_cnt++; // '\"'
				}
				else if( moji == 0x27 )
				{ // '''
					src_cnt++;
					loop_type = -1;
				}
				break;

			case C_DIGIT: // ����
				break;

			case C_OTHER: // moji
			case C_ILLEGAL:
				if( moji_check(moji) == 8 && s_buf[src_cnt + 1] )
				{
					src_cnt++; // ����
					if( tmp_moji_type != C_ILLEGAL ) loop_type = tmp_moji_type = C_ILLEGAL;
				}
				else if( !(_isalpha(moji) || _isdigit(moji) || moji == '_' || moji == '#' ||
					moji == '-' || moji == '>' || moji == '<' || moji == ':' ||
					moji == '.' || moji == '*' || moji == '[' || moji == ']') ) loop_type = -1; // CR,LF��
				break;

			default:
				break;
			}
			if( loop_type < 0 ) break;
			src_cnt++;
		}
		if( tmp_moji_type == 0 ) tmp_moji_type = C_OTHER; // ���̑�
	}

	n = pass_space( s_buf ); // �߽ ��߰�,TAB
	if( (src_cnt - n) > 0 )
	{
		memcpy( d_buf, &s_buf[n], src_cnt - n );	// copy comment
		d_buf[src_cnt - n] = 0;
		cut_last_space( 1, d_buf );					// �Ō��TAB,space���폜
		*tok_len = strlen( d_buf );
	}
	else *tok_len = 0;
	if( src_cnt == 0 || *tok_len == 0 ) tmp_moji_type = 0;	// reset

	if( mode == 0 ) cur_moji_type = tmp_moji_type;			// set
	return( src_cnt );
}
// ----------------------------------------------------------------------------
// ������̒f�Ђ̐؂�o��(s_buf�͍ŌオLF�Ȃ��Ɍ���)
// ��߰�,TAB,�����L���܂ł̐؂�o��
// return s_buf�̎��̈ʒu
// ----------------------------------------------------------------------------
int get_tok2( char *tok_buf, char *s_buf, int *tok_len )
{
	int put_cnt, max_len, pos, k_cnt, back_pos, digit_flag, n;

	max_len = CHAR_SIZE - 3;
	digit_flag = 0;
	k_cnt = 0;
	put_cnt = 0;
	pos = 0;
	for(;;)
	{ // cur_moji_type�͊��Ɏ�荞�݊���
		back_pos = pos;
		if( pos == 0 )
		{ // �ŏ�.type�͍ŏ��̂��̂Ƃ���
			pos = get_tok1( 0, tok_buf, s_buf, &n );
			if( cur_moji_type == 0 || cur_moji_type == C_COM1 ) break;	// ����
			tmp_moji_type = cur_moji_type;								// �ŏ���type
			if( tmp_moji_type == C_DIGIT || tmp_moji_type == C_PLUS || tmp_moji_type == C_MINUS )
				digit_flag = 1;											// set
		}
		else {
			pos += get_tok1( 1, tok_buf, &s_buf[pos], &n );
			if( tmp_moji_type == 0 || tmp_moji_type == C_COM1 )
			{
				pos = back_pos;
				break; // ����
			}
		}
		if( digit_flag == 1 )
		{
			if( tok_buf[n - 1] == ',' ) break;
			if( tmp_moji_type == C_DIGIT || tmp_moji_type == C_PLUS || tmp_moji_type == C_MINUS )
				continue;
			else { // �����̘A���I���
				pos = back_pos; // �P�߂�
				break;
			}
		}

		if( tmp_moji_type == C_K_L )
		{
			if( k_cnt >= 0 ) k_cnt++;
		}
		else if( tmp_moji_type == C_K_R ) k_cnt--;
		if( (s_buf[pos] == _SOH || s_buf[pos] == ' ') && k_cnt <= 0 ) break;
	}

	n = pass_space( s_buf ); // �߽ ��߰�,TAB
	if( (pos - n) > 0 )
	{
		memcpy( tok_buf, &s_buf[n], pos - n ); // copy
		tok_buf[pos - n] = 0;
	}
	else tok_buf[0] = 0;

	*tok_len = strlen( tok_buf );
	if( *tok_len >= max_len ) err_trap_line( 2, -13, 0 ); // "TOK over"

	return( pos );
}
// --------------------------------------------------------
// ���Ă̎�O��������ۯ��̐؂�o��(s_buf�͍ŌオLF�Ȃ��Ɍ���)
// "//"�͍Ō�܂ł�1��ۯ�
// cur_moji_type: C_COM1, C_OTHER
// return s_buf�̎���pos�ʒu
// --------------------------------------------------------
int get_tok3( char *tok_buf, char *s_buf, int *tok_len )
{
	int src_cnt, back_cnt, len;

	src_cnt = get_tok1( 0, tok_buf, s_buf, tok_len );	// ��؂�ʒu�܂Ŏc���荞��
	if( cur_moji_type == C_COM1 ) return( src_cnt );	// ���Ă���荞��
	else if( *tok_len )
	{ // ���ĈȊO
		back_cnt = 0;
		do { // ���Ă̑O�܂��߽
			back_cnt = src_cnt; // �ޔ�
			src_cnt += get_tok1( 1, tok_buf, &s_buf[src_cnt], tok_len ); // ��؂�ʒu�܂Ŏc���荞��
			if( tmp_moji_type == C_COM1 )
			{ // ���Ĕ���
				src_cnt = back_cnt; // �߂�
				break;
			}
		} while( *tok_len );
		len = pass_space( s_buf ); // �߽ ��߰�,TAB
		if( src_cnt - len > 0 )
		{
			memcpy( tok_buf, &s_buf[len], src_cnt - len ); // copy comment
			tok_buf[src_cnt - len] = 0;
		}
		else tok_buf[0] = 0;
		*tok_len = strlen( tok_buf );
		cur_moji_type = C_OTHER; // dummy
	}
	return( src_cnt );
}
// --------------------------------------------------------
// "{�`}"�̃R�s�[�B��ϒP�ʂŋ�؂�
// return s_buf�̎���pos�ʒu
// cur_moji_type : C_KOMMA
// cur_moji_type : C_COM1
// cur_moji_type : C_BIG_K_L
// cur_moji_type : C_BIG_K_R
// cur_moji_type : 0
// --------------------------------------------------------
int get_tok4( char *tok_buf, char *s_buf, int *tok_len )
{
	int src_cnt, back_cnt, len, back_moji_type;

//	src_cnt = get_tok1( 0, tok_buf, s_buf, tok_len );	// ��؂�ʒu�܂Ŏc���荞��
//	if( cur_moji_type == C_COM1 ) return( src_cnt );	// ���Ă���荞��
	src_cnt = 0;
	do { // ���Ă̑O�܂��߽
		back_cnt = src_cnt; // �ޔ�
		back_moji_type = cur_moji_type;
//		src_cnt += get_tok1( 0, tok_buf, &s_buf[src_cnt], tok_len );	// ��؂�ʒu�܂Ŏc���荞��
		src_cnt += get_tok2( tok_buf, &s_buf[src_cnt], tok_len );		// ��؂�ʒu�܂Ŏc���荞��
		if( cur_moji_type )
		{
			if( cur_moji_type == C_BIG_K_L || cur_moji_type == C_BIG_K_R || cur_moji_type == C_COM1 )
			{ // ��؂蔭��
				if( back_cnt )
				{
					src_cnt = back_cnt; // �߂�
					cur_moji_type = back_moji_type;
				}
				break;
			}
			if( cur_moji_type == C_KOMMA ) break; // ��؂蔭��
			if( tok_buf[*tok_len - 1] == ',' ) break;
		}
	} while( *tok_len );
	len = pass_space( s_buf ); // �߽ ��߰�,TAB
	if( src_cnt - len > 0 )
	{
		memcpy( tok_buf, &s_buf[len], src_cnt - len ); // copy comment
		tok_buf[src_cnt - len] = 0;
	}
	else tok_buf[0] = 0;
	*tok_len = strlen( tok_buf );
//	cur_moji_type = tmp_moji_type;

	return( src_cnt );
}
// ---------------------------------------------------------------------
// '{'+���ĂȂ��߽
// return( next pos )
// ---------------------------------------------------------------------
int add_comment( char *s_buf )
{
	int		pos, tok_len;
	char	tok_buf[CHAR_SIZE];

	pos = get_tok1( 1, tok_buf, s_buf, &tok_len ); // ��؂�ʒu�܂Ŏc���荞��
	if( tmp_moji_type == C_COM1 ) return( pos );
	return( 0 );
}
// ---------------------------------------------------------------------
// '{'�Ȃ��߽
// return( next pos )
// ---------------------------------------------------------------------
int add_b_k_l( char *s_buf )
{
	int		pos, tok_len;
	char	tok_buf[CHAR_SIZE];

	pos = get_tok1( 1, tok_buf, s_buf, &tok_len ); // ��؂�ʒu�܂Ŏc���荞��
	if( tmp_moji_type != C_BIG_K_L ) pos = 0;

	return( pos );
}
// ---------------------------------------------------------------------
// #typedef �̉��
// return( next pos )
// ---------------------------------------------------------------------
int kaiseki_typedef( char *s_buf )
{
	int		target_pos, k_cnt, big_cnt, c_cnt, flag;
	int		pos, back_pos, tok_len;
	char	tok_buf[CHAR_SIZE];

	target_pos = pos = back_pos = 0;
	flag = k_cnt = big_cnt = 0;
	for( c_cnt = 0; c_cnt < (MAX_C_MAP - 1); c_cnt++ )
	{
		back_pos = pos;
		pos += get_block( 1, tok_buf, &s_buf[pos], &tok_len ); // �Վ���1 block��荞��
		if( tmp_moji_type == C_COM1 || tmp_moji_type == C_LF || tmp_moji_type == 0 ) break;
		else if( tmp_moji_type & (C_MASK_TYPE1 | C_MASK_TYPE2) )
		{
			if( s_buf[pos] == ';' && k_cnt == 0 && big_cnt == 0 && flag == 0 && target_pos == 0 )
			{
				target_pos = back_pos; // set
				break;
			}
			else continue; // �\�����߽
		}
		else if( tmp_moji_type == C_KOMMA )
		{
			if( k_cnt == 0 && big_cnt == 0 && target_pos ) break;
			continue;
		}
		else if( (tmp_moji_type & C_MASK_KAKKO) || tmp_moji_type == C_STRUCT )
		{
			target_pos = 0; // reset
			break;
		}
		else if( tmp_moji_type == C_BIG_K_L )
		{
			big_cnt++;
			if( k_cnt == 0 && big_cnt == 1 && flag == 0 ) target_pos = back_pos; // set
		}
		else if( tmp_moji_type == C_BIG_K_R ) big_cnt--;
		else if( k_cnt == 0 && big_cnt == 0 && flag == 0 ) target_pos = back_pos;	// set

		if( s_buf[pos] != ' ' && s_buf[pos] != _SOH ) flag = 1;						// �������߽
		else flag = 0;
	}

	return( target_pos );
}
// ---------------------------------------------------------------------
// ������TYPE MACRO���߽ ���g�p
// return( next pos )
// ---------------------------------------------------------------------
int add_bind_macro( char *s_buf )
{
	int		pos, tok_len;
	char	tok_buf[CHAR_SIZE];

	pos = get_tok1( 1, tok_buf, s_buf, &tok_len ); // ��؂�ʒu�܂Ŏc���荞��
	if( tmp_moji_type == C_OTHER )
	{
		get_tok1( 1, tok_buf, &s_buf[pos], &tok_len );	// ��؂�ʒu�܂Ŏc���荞��
		if( tmp_moji_type != C_OTHER ) pos = 0;			// reset
	}
	else pos = 0;

	return( pos );
}
// ---------------------------------------------------------------------
// type �ȊO���̌���
// return 0:����, 1:�L��
// ---------------------------------------------------------------------
int chk_type( char *s_buf )
{
	int		n, len;
	char	moji;

	len = strlen( s_buf );
	moji = s_buf[0];
	if( moji == '*' || moji == '&' || moji == ':' || moji == '[' || moji == ']' ) return( 0 );
	moji = s_buf[len - 1];
	if( moji == ',' || moji == ':' || moji == '[' || moji == ']' || moji == ';' ) return( 0 );
	for( n = 0; n < len - 1; n++ )
	{
		moji = s_buf[n];
		if( isalpha(moji) ) continue;
		if( isdigit(moji) ) continue;
		if( moji == '_' ) continue;
		if( moji == ',' ) return( 0 );
		if( moji == '[' ) return( 0 );
		if( moji == ']' ) return( 0 );
		if( moji == '(' ) return( 0 );
		if( moji == ')' ) return( 0 );
		if( moji == '.' ) return( 0 );
		if( moji == '=' ) return( 0 );
		if( moji == ':' ) return( 0 );
		if( moji == '+' ) return( 0 );
		if( moji == '-' ) return( 0 );
		if( moji == '-' ) return( 0 );
		if( moji == ';' ) return( 0 );
	}
	return( 1 ); // �L��
}
// ---------------------------------------------------------------------
// ������MASK_TYPE���߽ ���g�p
// return( next pos )
// ---------------------------------------------------------------------
int add_bind_type1( char *s_buf )
{
	int		pos, back_pos, before_back_pos, tok_len, mode;
	char	tok_buf[CHAR_SIZE], moji;

	mode = back_pos = pos = 0;
	for(;;)
	{
		before_back_pos = back_pos;								// �ޔ�
		back_pos = pos;											// �ޔ�
//		pos += get_tok1( 1, tok_buf, &s_buf[pos], &tok_len );	// ��؂�ʒu�܂Ŏc���荞��
		pos += get_block( 1, tok_buf, &s_buf[pos], &tok_len );	// ��؂�ʒu�܂Ŏc���荞��
		if( tok_len == 0 ) break;
//		if( tmp_moji_type & (C_MASK_TYPE1 | C_MASK_TYPE2) ) continue;
		if( tmp_moji_type & C_MASK_TYPE1 )
		{
			mode = 1; // ��������
		}
		else if( tmp_moji_type & C_MASK_TYPE2 )
		{
			if( mode == 0 ) mode = 2; // ��������
		}
		else if( tmp_moji_type == C_STRUCT || tmp_moji_type == C_UNION )
		{ // �����܂Ŋ܂�
			back_pos = pos;
			break;
		}
		moji = tok_buf[tok_len - 1];
		if( moji == ',' || moji == ':' || moji == '[' || moji == ']' ) break;
		moji = tok_buf[0];
		if( moji == '*' || moji == '&' || moji == ':' || moji == '[' || moji == ']' ) break;
		if( s_buf[pos] == ',' )
		{
//			back_pos = before_back_pos;
			break;
		}
		if( s_buf[pos] != ' ' && s_buf[pos] != _SOH )
		{
//			back_pos = before_back_pos;
			break;
		}
		if( tmp_moji_type == C_IQUAL )
		{ // 2�O
			back_pos = before_back_pos;
			break;
		}
		if( tmp_moji_type != C_OTHER )
		{ // 1�O
			if( mode == 2 ) break;	// �X�V
			else pos = back_pos;	// �߂�
			break;
		}
//		else {
//			back_pos = pos;
//			break;
//		}
	}
	pos = back_pos; // �ύX

	return( pos );
}
// ---------------------------------------------------------------------
// �����̗\����1�ɂ���
// �s�̍ŏ����璲�ׂ邱��
// return( next pos )
// ---------------------------------------------------------------------
int add_bind_type2( int tmp_line, char *s_buf )
{
	int		pos, back_pos, before_back_pos, tok_len, back_cur_moji_type, yuko_pos;
	char	tok_buf[CHAR_SIZE];

#ifdef _DEBUG
	if( tmp_line >= 53 )
	{
		debug_n = s_buf[0];
	}
#endif
	back_cur_moji_type = cur_moji_type; // �ޔ�
	before_back_pos = back_pos = pos = 0;
	yuko_pos = 0;
	pos = 0;
	for(;;)
	{
		before_back_pos = back_pos;
		back_pos = pos;											// �ޔ�
//		pos += get_tok1( 0, tok_buf, &s_buf[pos], &tok_len );	// ��؂�ʒu�܂Ŏc���荞��
		pos += get_tok2( tok_buf, &s_buf[pos], &tok_len );		// ������荞��
		if( tok_len == 0 || cur_moji_type == C_COM1 || cur_moji_type == C_COM2 )
		{
			pos = before_back_pos; // �߂�
			break;
		}
		else if( cur_moji_type == C_STRUCT || cur_moji_type == C_UNION ) break;
		if( cur_moji_type & C_MASK_TYPE1 ) yuko_pos = pos; // ��������
		else if( cur_moji_type & C_MASK_TYPE2 )
		{
			if( yuko_pos == 0 ) yuko_pos = pos; // ��������
		}
		if( tmp_moji_type == C_IQUAL )
		{ // 2�O
			pos = before_back_pos;
			break;
		}
		else if( tmp_moji_type == C_K_R )
		{ // ����
			pos = yuko_pos;
//			pos = back_pos; // �߂�
			break;
		}
		else if( chk_type(tok_buf) == 0 )
		{
			pos = back_pos; // �߂�
			break;
		}
//		if( cur_moji_type != C_OTHER )
//		{
//			if( mode == 2 ) break;	// �X�V
//			else pos = back_pos;	// �߂�
//			break;
//		}
//		else {
//			pos = back_pos; // �߂�
//			break;
//		}
	}
	cur_moji_type = back_cur_moji_type; // �߂�

	return( pos );
}
// ---------------------------------------------------------------------
// #define ��2�Ԗڂ̒萔�𓾂�
// s_buf mesage
// tok_len �萔�̋�؂�̒���
// return ��߰����܂񂾋�؂�̒���
// ---------------------------------------------------------------------
int get_define_no2( char *tok_buf, char *s_buf, int *tok_len )
{
	int k_cnt, mode, pos, back_pos;
	int back_cur_moji_type, len;

	pos = get_tok1( 0, tok_buf, s_buf, tok_len );
	if( cur_moji_type == 0 ) return( pos );
	if( cur_moji_type == C_COM1 ) return( pos );
	if( cur_moji_type == C_COM2 ) return( pos ); // "/*�`*/"

	back_cur_moji_type = 0;
	mode = 0;
	k_cnt = 0;
	pos = 0;
	for(;;)
	{
		back_pos = pos;
		pos += get_tok2( tok_buf, &s_buf[pos], &len );	// ������荞��
		if( len == 0 ) break;							// ��
		if( back_cur_moji_type == 0 ) back_cur_moji_type = cur_moji_type;
//		if( cur_moji_type == C_YEN ) continue;
		if( cur_moji_type == C_COM1 )
		{ // ��O
			pos = back_pos;
			break;
		}
		if( mode == 0 )
		{ // first
			if( cur_moji_type == C_COM2 ) mode = 1; // "/*�`*/"
			else if( cur_moji_type == C_K_L || cur_moji_type == C_BIG_K_L )
			{
				k_cnt++;
			}
			else if( cur_moji_type == C_K_R || cur_moji_type == C_BIG_K_R )
			{
				k_cnt--;
			}

			if( k_cnt == 0 && s_buf[pos] == ' ' || s_buf[pos] == _SOH )
			{
				back_pos = pos;										// �߂�
				pos += get_tok1( 1, tok_buf, &s_buf[pos], &len );	// ������荞��
				if( tmp_moji_type != C_YEN )
				{
					pos = back_pos; // �߂�
					break;			// 1���
				}
			}
		}
	}
	cur_moji_type = back_cur_moji_type;
	if( pos )
	{
		memcpy( tok_buf, s_buf, pos );
		tok_buf[pos] = 0;
		len = pass_space( tok_buf );		// �߽ ��߰�,TAB
		strcpy( tok_buf, &tok_buf[len] );	// shift
		cut_last_space( 1, tok_buf );		// �Ō��TAB,space���폜
		len = strlen( tok_buf );
	}
	else len = 0;

	*tok_len = len;
	return( pos );
}
// ---------------------------------------------------------------------
// s_buf�̽�߰� 1�ǉ�
// ---------------------------------------------------------------------
int add_space_one( int end_pos, char *s_buf )
{
	s_buf[end_pos++] = ' ';
	s_buf[end_pos] = 0;
	return( end_pos );
}
// ---------------------------------------------------------------------
// TAB�v�Z ���ʒu
// �Œ�1�ͽ�߰��ǉ�
// return : ����end_pos
// ---------------------------------------------------------------------
int arrange_tab_soh( int target_pos, int buf_end_pos, char *s_buf )
{
	int pos;

	if( target_pos <= buf_end_pos ) s_buf[buf_end_pos++] = ' ';
	else {
		pos = ( target_pos / 4 ) * 4; // TAB�̊�{�ʒu
		if( (pos - buf_end_pos) > 1 )
		{
			while( buf_end_pos < pos )
			{ // TAB�ŕ₤
				s_buf[buf_end_pos++] = _SOH;
				if( buf_end_pos >= (CHAR_SIZE - 5) )
				{
					err_trap_line( 2, -36, 0 ); // "1�s����������"
				}
			}
		}
		while( buf_end_pos < target_pos )
		{ // �c��[�����߰��Ŗ��߂�
			s_buf[buf_end_pos++] = ' ';
			if( buf_end_pos >= (CHAR_SIZE - 5) )
			{
				err_trap_line( 2, -36, 0 ); // "1�s����������"
			}
		}
	}
	s_buf[buf_end_pos] = 0;

	return( buf_end_pos );
}
// ---------------------------------------------------------------------
// tab_pos��W�J����
// mode = 0:"//"��ǉ����Ȃ�
// mode = 1:"//"+TAB(' ') ��ǉ�����
// mode = 2:TAB+ "//" ��ǉ�����
// mode = 3:"//"+' ' TAB�͖���
// ---------------------------------------------------------------------
void open_tab_pos( int mode, int tmp_line )
{
	struct	FDATA *fdata_p;
	int		target_pos, end_pos;

	fdata_p = &ope_buf[tmp_line];

	end_pos = strlen( fdata_p->pri_comment );
	if( mode == 1 || mode == 3 )
	{ // �ŏ���TAB, TAB���� ��߰��̂�
		if( end_pos ) fdata_p->pri_comment[end_pos++] = ' ';
		fdata_p->pri_comment[end_pos++] = '/';
		fdata_p->pri_comment[end_pos++] = '/';
		if( mode == 3 ) fdata_p->tab_pos = 0;
	}
	fdata_p->pri_comment[end_pos] = 0;

	// ---------��߰������� ---------------
	target_pos = fdata_p->tab_pos * 4;
	if( (target_pos - end_pos) > 0 ) end_pos = arrange_tab_soh( target_pos, end_pos, fdata_p->pri_comment );

	if( mode == 2 )
	{ // ���TAB
		if( end_pos && fdata_p->pri_comment[end_pos - 1] != _SOH && fdata_p->pri_comment[end_pos - 1] != ' ' ) fdata_p->pri_comment[end_pos++] = ' ';
		fdata_p->pri_comment[end_pos++] = '/';
		fdata_p->pri_comment[end_pos++] = '/';
	}
	fdata_p->pri_comment[end_pos] = 0;
}
// ---------------------------------------------------------------------
// pri_comment, tab_pos��W�J����
// ---------------------------------------------------------------------
void open_tab_mes( int tmp_line )
{
	struct FDATA *fdata_p;

	fdata_p = &ope_buf[tmp_line];

#ifdef _DEBUG
	if( tmp_line >= 32 )
	{
		debug_n = (int)fdata_p->mes;
	}
#endif

	if( fdata_p->hojo_flag & H_MES17 )
	{ // �����̂܂�
		open_tab_pos( 0, tmp_line );
	}
	else if( fdata_p->hojo_flag & (H_MES11 | H_MES14) )
	{ // "//"+TAB(' ')+program
		open_tab_pos( 1, tmp_line );
	}
	else if( fdata_p->hojo_flag & H_MES15 )
	{ // TAB+"//"+comments, program�̌�̺��Ăɍ��킹��
		open_tab_pos( 2, tmp_line );
	}
	else if( fdata_p->hojo_flag & H_MES16 )
	{ // "//"+' '+message TAB�͖���
		open_tab_pos( 3, tmp_line );
	}
	else { // �s����"//"�ǉ��Ȃ�
		open_tab_pos( 0, tmp_line );
	}
}
// ---------------------------------------------------------------------
// if(), for(), while()���P�s�ŏI��邩�̌���
// return 0:�P�s�ŏI���Ȃ�, 1:1�s�ŏI���
// ---------------------------------------------------------------------
int chk_loop_end( char *s_buf )
{
	int		pos, len, type, flag, k_cnt;
	char	tok_buf[CHAR_SIZE];

	k_cnt = 0;
	flag = 0;
	type = 0;
	pos = 0;
	for(;;)
	{
		pos += get_block( 1, tok_buf, &s_buf[pos], &len );	// ������荞��
		if( tmp_moji_type == 0 || tmp_moji_type == C_COM1 ) break;
		else if( tmp_moji_type == C_SEMIKOLON ) flag = 1;	// set
		else if( tmp_moji_type == C_BIG_K_L ) flag = 0;		// reset
		else if( tmp_moji_type == C_K_L ) k_cnt++;
		else if( tmp_moji_type == C_K_R ) k_cnt--;
		else if( tmp_moji_type == C_BIG_K_R ) flag = 1;		// set
		else flag = 0;										// reset
	}
	if( k_cnt ) flag = 0;
	return( flag );
}
// ---------------------------------------------------------------------
// TAB�␳�̕K�v�����m�F
// return 0:����
// ---------------------------------------------------------------------
int chk_tab_enable( int now_line )
{
	int		line_type;
	struct	FDATA *fdata_p;

	fdata_p = &ope_buf[now_line];
	line_type = fdata_p->line_type;

	if( line_type == T_ASM ) return( G_ASM );				// �L��

	if( line_type == T_DEFINE ) return( G_DEFINE );			// �L��
	if( line_type == T_TYPEDEF ) return( G_TYPEDEF );		// �L��
	if( line_type == T_DEF_OTHER ) return( G_DEF_OTHER );	// �L��

	if( line_type == T_TYPE || line_type == T_OTHER_TYPE )
	{
		if( fdata_p->hojo_flag & H_B_K_PAIR ) return( G_TYPE2 );	// �L��
		else return( G_TYPE1 );										// �L��
	}

//	if( line_type == T_EXTERN ) return( G_EXTERN ); // �L��

	if( line_type == T_PROC ) return( G_PROC );		// �L��

	if( line_type == T_STRUCT || line_type == T_UNION )
	{
		if( fdata_p->hojo_flag & H_B_K_PAIR ) return( G_STRUCT2 );	// �L��
		else return( G_STRUCT1 );									// �L��
	}

	if( line_type == T_INCLUDE ) return( G_INCLUDE );	// �L��

	if( line_type & T_MASK_IN ) return( G_TYPE_IN );	// �L��

	if( line_type == T_DIGIT ) return( G_DIGIT );		// �L��
	if( line_type == T_MOJIS ) return( G_MOJIS );		// �L��

	if( line_type == T_B_K_PAIR ) return( G_B_K_PAIR ); // �L��

	if( line_type == T_CASE ) return( G_CASE );			// �L��

	if( line_type == T_OTHER ) return( G_OTHER );		// �L��
	if( line_type == T_CALL ) return( G_OTHER );		// �L��
	if( line_type == T_RETURN ) return( G_OTHER );		// �L��
	if( (line_type == T_WHILE || line_type == T_FOR) && chk_loop_end(fdata_p->mes) ) return( G_OTHER ); // �L��

	if( line_type == T_IF ) return( G_IF );			// �L��
	if( line_type == T_ELSE ) return( G_IF );		// �L��
	if( line_type == T_ELSE_BIG ) return( G_IF );	// �L��
	if( line_type == T_ELSE_IF ) return( G_IF );	// �L��

	return( 0 );									// ����
}
// ---------------------------------------------------------------------
// MES15�̎����������̌���
// return 0:NG, 1~:OK(+skip line)
// ---------------------------------------------------------------------
int chk_same_teigi( int base_type, int skip_mes, int *line_no, int end_line )
{
	struct	FDATA *fdata_p;
	int		line, cnt;

	cnt = 0;
	line = *line_no;
	for( ; line < end_line; line++ )
	{
		fdata_p = &ope_buf[line];

		if( fdata_p->line_type == T_CRLF ) continue;
		if( fdata_p->hojo_flag & (H_YEN1 | H_YEN2) ) break;
		if( fdata_p->line_type == skip_mes )
		{
			if( ++cnt > 2 ) break; // 2�s�܂�OK
			continue;
		}
		if( base_type == chk_tab_enable(line) )
		{
			*line_no = line;	// set new
			return( 1 );		// �L��
		}
		else break;
	}
	return( 0 ); // ����
}
// ---------------------------------------------------------
// ��������̈�v���Ȃ��ʒu��T��
// ���Ă̏ꍇ��0��Ԃ�
// end_pos : ��ݼތ��buffer�̈ʒu
// *s_buf : ���̿��
// *t_buf : ��ݼތ��buffer
// return : ����̈ʒu
// ---------------------------------------------------------
int get_source_pos( int end_pos, char *t_buf, char *s_buf )
{
	int		n, pos;
	char	moji;

	pos = 0;
	n = 0;
	while( (moji = t_buf[n]) != 0 )
	{
		if( moji != _SOH && moji != ' ' )
		{ // TAB,��߰� �߽
			while( s_buf[pos] == _SOH || s_buf[pos] == ' ' ) pos++; // TAB,��߰� �߽
			pos++;
		}
		if( ++n >= end_pos ) break;
	}
//	while( s_buf[pos] == _SOH || s_buf[pos] == ' ' ) pos++; // TAB,��߰� �߽

	return( pos );
}
// ---------------------------------------------------------------------
// comment�O��TAB�ʒu�����킹��
// ---------------------------------------------------------------------
int set_tab( int teigi_no, int line_start, int line_last, int max_pos )
{
	struct	FDATA *fdata_p;
	int		tmp_line, last_teigi_no, top_pos, end_pos, pos;
	char	buf[CHAR_SIZE];

	last_teigi_no = 0;
	for( tmp_line = line_start; tmp_line < line_last; tmp_line++ )
	{
		fdata_p = &ope_buf[tmp_line];

		if( fdata_p->line_type == T_CRLF ) continue; // ���s�݂̂��߽
		if( fdata_p->line_type & T_MASK_MES ) continue;
		if( fdata_p->line_type == T_COM_MES ) continue;
		if( (fdata_p->status[teigi_no] & ST_COM) && form_comment_prog == 0 ) continue;

#ifdef _DEBUG
		if( tmp_line >= 4150 && teigi_no >= 1 )
		{
			debug_n = tmp_line;
		}
#endif
		end_pos = fdata_p->top_pos[teigi_no] + fdata_p->block_len[teigi_no];	// last�ʒu
		top_pos = end_pos + pass_space( &fdata_p->mes[end_pos] );				// ����top
		if( end_pos && fdata_p->mes[top_pos] )
		{
//			get_tok1( 1, tok_buf, &fdata_p->mes[top_pos], &tok_len );
//			get_tok2( tok_buf, &fdata_p->mes[top_pos], &tok_len );										// ��؂�ʒu�܂Ŏc���荞��
			pos = max_pos;
			if( fdata_p->status[teigi_no] & (ST_PAIR_L | ST_PAIR_IN) ) pos = 1;							// ��߰��̂ݗL��
			else if( (fdata_p->status[teigi_no] & ST_TAB) == 0 ) pos = 1;								// ��߰��̂ݗL��
//			else {
//				if( (base_type & (G_DEFINE | G_DEF_OTHER | G_TYPEDEF)) == 0 && teigi_no >= 2 ) pos = 1; // ��߰�
//				if( teigi_no == 1 )
//				{
//					if( bunpu_cnt <= 1 && (base_type & (G_DEFINE | G_DEF_OTHER | G_TYPEDEF)) == 0 &&
//						fdata_p->tab_pos == 0 && bunpu_cnt <= 1 && teigi_no == 1 ) pos = 1; // ��߰�
//				}
//				else if( base_type != G_DEFINE && bunpu_cnt <= 1 ) pos = 1; // ��߰�
//			}
			memcpy( buf, fdata_p->mes, end_pos );
			buf[end_pos] = 0;

			end_pos = arrange_tab_soh( pos, end_pos, buf );
			if( (teigi_no + 1) < MAX_TEIGI_NO )
			{
//				end_pos += pass_space( &fdata_p->mes[end_pos] );	// ����top
				fdata_p->top_pos[teigi_no + 1] = end_pos;			// new set
				if( fdata_p->status[teigi_no] & (ST_PAIR_L | ST_PAIR_IN) )
					fdata_p->status[teigi_no + 1] |= ST_PAIR_IN;	// "{�`}"�̊J�n�ʒu
			}
			strcat( buf, &fdata_p->mes[top_pos] );	// �c��copy
			strcpy( fdata_p->mes, buf );			// �߂�
			last_teigi_no = teigi_no;				// ���s
		}
		else if( (teigi_no + 1) < MAX_TEIGI_NO )
		{
			fdata_p->top_pos[teigi_no + 1] = 0;		// �Ȃ�
			fdata_p->block_len[teigi_no + 1] = 0;	// �Ȃ�
			fdata_p->status[teigi_no + 1] = 0;		// �Ȃ�
		}
	}
	return( last_teigi_no );
}
// ---------------------------------------------------------------------
// ���Ă̏���
// ---------------------------------------------------------------------
void comment_syori( int base_type, int *line_start, int line_last )
{
	#define IF_DIFFER_TAB		40
	#define OTHER_DIFFER_TAB	40

	struct	FDATA *fdata_p;
	int		top_pos, end_pos, tmp_line, no_com_cnt, total, averrage;
	int		comment_mode, comment_cnt, line_same_com_pos, line_top;
	int		least_pos, max_pos, pos, com_teigi_no, n;
	char	buf[CHAR_SIZE2];

	line_top = *line_start;
	// ---------------- ���� �̏��� -----------------
	if( base_type & (G_DEFINE | G_DEF_OTHER | G_TYPEDEF) )
		comment_mode = form_define_com_tab; // #define �̺��Ă�TAB�ʒu 0:�Ȃɂ����Ȃ�, 1:TAB�Ȃ�(��߰��̂�), 2:������TAB�쐬
	else {
		comment_mode = form_other_com_tab;	// ���̑� 0:�������Ȃ�, 1:TAB�Ȃ�(��߰��̂�), 2:�ő�TAB�����Ȃ�
//		if( (base_type == G_CASE || base_type == G_DEFIF) && comment_mode == 2 ) comment_mode = 30; // max TAB = 30
		if( base_type == G_CASE && comment_mode == 2 ) comment_mode = 30;							// max TAB = 30
	}
	if( comment_mode == 0 ) return;
	// ---------- ���Ă̍ő�/�ŏ��l�߰��l�����߂� -------------
	comment_cnt = 0; // ���z
	least_pos = max_pos = 0;
	total = averrage = 0;
	no_com_cnt = -1; // �ŏ��̺��ĕ���T��
	for( tmp_line = line_top; tmp_line < line_last; tmp_line++ )
	{
		fdata_p = &ope_buf[tmp_line];

		if( no_com_cnt >= 0 ) no_com_cnt++;
		if( fdata_p->line_type == T_CRLF ) continue;
		if( fdata_p->line_type & T_MASK_MES ) continue;

#ifdef _DEBUG
		if( tmp_line >= 846 )
		{
			debug_n = (int)fdata_p->mes;
		}
#endif
		com_teigi_no = fdata_p->com_teigi_no;
		if( com_teigi_no == 0 )
		{ // ���ĂȂ�
			if( base_type != G_DEFINE && no_com_cnt >= 10 )
			{ // 10�s�ȏ�̺��ĂȂ�
				line_last = tmp_line + 1;
				break; // ��U�����ł܂Ƃ߂�
			}
			continue;
		}
		if( no_com_cnt < 0 ) line_top = tmp_line; // ���Ă̍ŏ�

		end_pos = fdata_p->top_pos[com_teigi_no - 1] + fdata_p->block_len[com_teigi_no - 1];

		// ���Ă�TAB�ʒu 0:�������Ȃ�, 1:TAB�Ȃ�(��߰��̂�), 2:������TAB�쐬, 3�`:�ő�TAB�ʒu
		if( comment_mode > 1 )
		{ // ����
//			if( (end_pos > 0 && end_pos < MAX_END_MAP) && (fdata_p->status[com_teigi_no] & ST_TAB) )
			if( end_pos > 0 && end_pos < MAX_END_MAP )
			{
//				if( end_pos )
				n = ( (end_pos + 4) / 4 ) * 4; // ��pos�ʒu�̌v�Z.TAB�ŏ�=1
//				else n = 0;
				if( comment_mode >= 3 && n > (comment_mode * 4) )
				{ // 0:�������Ȃ�, 1:TAB�Ȃ�(��߰��̂�), 2:������TAB�쐬, 3�`:�ő�ʒu
					fdata_p->status[com_teigi_no] &= ~( ST_TAB );	// �w��ő�l�𒴂������߰��̂�
//					n = 0;											// TAB�Ȃ�
				}
//				else if( fdata_p->line_type == T_DEFIF || fdata_p->line_type == T_DEF_OTHER )
				else if( fdata_p->line_type == T_DEFIF )
					fdata_p->status[com_teigi_no] &= ~( ST_TAB );	// ��߰��̂�
				else if( fdata_p->line_type != T_STRUCT_IN && fdata_p->line_type != T_UNION_IN &&
					((fdata_p->hojo_flag & (H_BIG_K_L | H_BIG_K_R)) == H_BIG_K_L ||
					(fdata_p->hojo_flag & (H_BIG_K_L | H_BIG_K_R)) == H_BIG_K_R) )
					fdata_p->status[com_teigi_no] &= ~( ST_TAB );	// ��߰��̂�
				else {
					if( ++comment_cnt == 1 ) total = averrage = n;	// ����
					else {
						if( base_type & (G_DEFINE | G_DEF_OTHER | G_TYPEDEF) )
						{
							if( abs(averrage - n) > 40 )
							{ // ���܂ł̍s�̔���
								line_last = tmp_line;
								break; // ��U�����ł܂Ƃ߂�
							}
						}
						else {
							if( abs(averrage - n) > 40 )
							{ // ���܂ł̍s�̔���
								line_last = tmp_line;
								break; // ��U�����ł܂Ƃ߂�
							}
						}
						total += n;
						averrage = total / comment_cnt;
					}
					if( least_pos == 0 ) least_pos = end_pos;			// �ŏ�
					else if( least_pos > end_pos ) least_pos = end_pos; // �������ʒu���
					if( max_pos < end_pos ) max_pos = end_pos;			// �傫���ʒu���
					fdata_p->status[com_teigi_no] |= ST_TAB;			// TAB�L��
				}
			}
		}
		else { // 1:TAB�Ȃ�(��߰��̂�)
			fdata_p->status[com_teigi_no] &= ~( ST_TAB ); // set space
		}
		no_com_cnt = 0; // reset
	}

	// ----------------- TAB���P�̏ꍇ�͑S�Ľ�߰��Ƃ��� ------------------
	if( base_type != G_DEFINE && least_pos == max_pos )
	{
//		if( (line_last - line_top) >= 5 || comment_mode >= 3 ) max_pos = 0; // ��߰��̂�
		max_pos = 0; // ��߰��̂�
	}
	else max_pos = ( (max_pos + 4) / 4 ) * 4; // ��pos�ʒu�̌v�Z
	// ----------------- ���Ă�TAB,��߰������߂� ------------------
	line_same_com_pos = 0;
	for( tmp_line = line_top; tmp_line < line_last; tmp_line++ )
	{
		fdata_p = &ope_buf[tmp_line];

#ifdef _DEBUG
		if( tmp_line >= 57 )
		{
			debug_n = 0;
		}
#endif

		if( fdata_p->line_type == T_CRLF ) continue; // ���s�݂̂��߽
		if( fdata_p->line_type & T_MASK_MES ) continue;
		com_teigi_no = fdata_p->com_teigi_no;
		if( com_teigi_no == 0 ) continue;

		top_pos = fdata_p->top_pos[com_teigi_no];
		end_pos = fdata_p->top_pos[com_teigi_no - 1] + fdata_p->block_len[com_teigi_no - 1];

		if( form_limit_line && (max_pos + fdata_p->block_len[com_teigi_no]) > (form_limit_line * 4) )
		{
			fdata_p->status[com_teigi_no] &= ~( ST_TAB ); // TAB����
		}
		if( fdata_p->line_type == T_COM_MES && line_same_com_pos > 0 )
		{ // comment�݂̂ŁA�O�s�ɍ��킹��
			pos = line_same_com_pos;					// 1�O�̈ʒu
			end_pos = 0;
			fdata_p->status[com_teigi_no] |= ST_TAB;	// TAB�L��.�K�v
		}
		else pos = max_pos;

		// ���ۂ�TAB�����߂�
		if( end_pos ) memcpy( buf, fdata_p->mes, end_pos );				// ���Ă̑O�܂ł��߰
		if( (fdata_p->status[com_teigi_no] & ST_TAB) == 0 ) pos = 1;	// ��߰��̂ݗL��
		end_pos = arrange_tab_soh( pos, end_pos, buf );
		line_same_com_pos = end_pos;

		if( end_pos )
		{
			strcat( buf, &fdata_p->mes[top_pos] );		// �c��copy
			fdata_p->top_pos[com_teigi_no] = end_pos;	// set new
			strcpy( fdata_p->mes, buf );				// �߂�
		}
	}

	*line_start = line_last;
}
// ---------------------------------------------------------------------
// '{'�`'}'�̒萔�̍ő�l�𒲂ׂ�
// mode = 0:'{'�̂�, =1:'{'�̎�����
// ---------------------------------------------------------------------
void chk_const_pos( int mode, int line_start, int line_last )
{
	struct	FDATA *fdata_p;
	int		tmp_line, teigi_ofset, teigi_no, len, flag;

#ifdef _DEBUG
	if( line_start == 55 )
	{
		debug_n = 0;
	}
#endif
	if( mode == 0 ) pos_map[0] = 0;
	else memset( &pos_map[1], 0, sizeof(pos_map) - sizeof(int) );

	for( teigi_ofset = mode; teigi_ofset < MAX_TEIGI_NO; teigi_ofset++ )
	{ // '{'���瑵�����teigi_no = 0 ����
		// ------ �ő�l������ -------------
		flag = 0;
		for( tmp_line = line_start; tmp_line < line_last; tmp_line++ )
		{ // �ő�end_pos�v�Z
			fdata_p = &ope_buf[tmp_line];
			if( fdata_p->pair_teigi_top == 0 ) continue;

			teigi_no = fdata_p->pair_teigi_top + teigi_ofset;	// mode = 0:'{' ����, =1:���̎�����
			if( teigi_no >= MAX_TEIGI_NO ) continue;
			if( teigi_no > fdata_p->pair_teigi_end ) continue;	// '}' �܂�

			flag++;
			if( fdata_p->status[teigi_no] & (ST_SPACE | ST_TAB) )
			{
				len = fdata_p->block_len[teigi_no - 1];
				if( len )
				{
					if( pos_map[teigi_ofset] == 0 ) pos_map[teigi_ofset] = len;			// �������
					else if( pos_map[teigi_ofset] < len ) pos_map[teigi_ofset] = len;	// �ŏ��������
				}
			}
		}
		if( flag == 0 || mode == 0 ) break;
	}
}
// ---------------------------------------------------------------------
// '{'�`'}'�̎��ۂ�TAB�ʒu���v�Z
// mode = 0:'{'�������킹��, 1:'{'�Ȍ�����킹��
// ret= 0:���� , 1:1�sover
// ---------------------------------------------------------------------
int chk_teigi_tab_max( int mode, int line_start, int line_last )
{
	struct	FDATA *fdata_p;
	int		tmp_line, teigi_ofset, teigi_no, end_pos, cnt, n;

#ifdef _DEBUG
	if( line_start == 166 )
	{
		debug_n = 0;
	}
#endif
	chk_const_pos( mode, line_start, line_last ); // �萔�̍ő�l�𒲂ׂ�
	if( mode == 0 ) total_pos[0] = 0;
	else memset( &total_pos[1], 0, sizeof(total_pos) - sizeof(int) );

	for( teigi_ofset = mode; teigi_ofset < MAX_TEIGI_NO; teigi_ofset++ )
	{ // '{'���瑵�����teigi_no = 0 ����
		// ------ �ő�l������ -------------
		cnt = 0;
		end_pos = 0;
		for( tmp_line = line_start; tmp_line < line_last; tmp_line++ )
		{ // �ő�end_pos�v�Z
			fdata_p = &ope_buf[tmp_line];
			if( fdata_p->pair_teigi_top == 0 ) continue;

			teigi_no = fdata_p->pair_teigi_top + teigi_ofset;	// mode = 0:'{' ����, = 1:������
			if( teigi_no >= MAX_TEIGI_NO ) continue;
			if( teigi_no > fdata_p->pair_teigi_end ) continue;	// '}' �܂�

			cnt++;
			if( teigi_ofset == 0 )
			{
				end_pos = fdata_p->top_pos[teigi_no - 1] + pos_map[teigi_ofset];
//				if( end_pos == 0 ) end_pos = 3; // '{'��top�ʒu�̏ꍇ�̕␳
			}
			else end_pos = total_pos[teigi_ofset - 1] + pos_map[teigi_ofset];

			if( fdata_p->status[teigi_no] & ST_TAB )
			{ // form_big_kakko_pair : '{'�`'}'�̏��� 0:��߰��̂�, 1:�����ɑ�����(�ŏ�TAB=1), 2:������TAB�쐬(��߰�+TAB�ō��킹��)
				if( form_big_kakko_pair == 0 ) end_pos++;									// ��߰��̂�
				else if( form_big_kakko_pair == 1 ) end_pos = ( (end_pos + 4) / 4 ) * 4;	// mode = 0,TAB�ō��킹��
				else end_pos++; // ��߰��̂� form_big_kakko_pair = 3

				if( form_limit_line && end_pos > (form_limit_line * 4) )
				{
					for( n = fdata_p->pair_teigi_top + 1; n < MAX_TEIGI_NO; n++ )
					{ // '{' �̎�����
						if( fdata_p->status[n] ) fdata_p->status[n] &= ~( ST_TAB ); // reset
						else break;
					}
					return( 1 ); // over
				}
			}
			else end_pos++;																// ��߰�1��

			if( end_pos < 4 ) end_pos = fdata_p->top_pos[teigi_no];						// �␳
			if( end_pos < 4 ) end_pos = 4;
			if( total_pos[teigi_ofset] < end_pos ) total_pos[teigi_ofset] = end_pos;	// �傫���ʒu���
		}
		if( cnt == 0 || mode == 0 ) break;
	}
	return( 0 );
}
// ---------------------------------------------------------------------
// "{�`}"�̏��� �����萔�̐�
// mode = 0:'{'�������킹��, 1:'{'�Ȍ�����킹��
// ---------------------------------------------------------------------
void pair_kakko_parts( int mode, int line_start, int line_last )
{
	struct	FDATA *fdata_p;
	int		teigi_no, tmp_line, len;
	int		top_pos, end_pos, max_pos;
	int		teigi_ofset;
	char	buf[CHAR_SIZE];

	while( chk_teigi_tab_max(mode, line_start, line_last) ); // TAB�L���ȏc�̍ő�l�𒲂ׂ�

	// ----------- "{}"�Ԃ�TAB�L��, '{'�` TAB,��߰��ő����� ---------------
	for( teigi_ofset = mode; teigi_ofset < MAX_TEIGI_NO; teigi_ofset++ )
	{ // '{'���瑵�����pair_teigi_top ����
		// ------ ������ -------------
		for( tmp_line = line_start; tmp_line < line_last; tmp_line++ )
		{
			fdata_p = &ope_buf[tmp_line];

#ifdef _DEBUG
			if( tmp_line == 234 )
			{

				debug_n = 0;
			}
#endif
			teigi_no = fdata_p->pair_teigi_top + teigi_ofset;
			if( teigi_no >= MAX_TEIGI_NO ) continue;
			if( teigi_no > fdata_p->pair_teigi_end ) continue; // '}'���߽
			if( fdata_p->pair_teigi_top == 0 ) continue;
			if( fdata_p->line_type == T_CALL || fdata_p->line_type == T_PROC ) continue;

			if( fdata_p->status[teigi_no] & (ST_SPACE | ST_TAB) )
			{ // TAB�A��߰��L��
				max_pos = total_pos[teigi_ofset];

				end_pos = fdata_p->top_pos[teigi_no - 1] + fdata_p->block_len[teigi_no - 1];	// mes pos.
				memcpy( buf, fdata_p->mes, end_pos );
				buf[end_pos] = 0;

				end_pos = arrange_tab_soh( max_pos, end_pos, buf );								// TAB����

				top_pos = fdata_p->top_pos[teigi_no];
				strcpy( &buf[end_pos], &fdata_p->mes[top_pos] );								// �c��copy
				strcpy( fdata_p->mes, buf );													// �߂�
				len = end_pos - top_pos;

				while( teigi_no < MAX_TEIGI_NO )
				{
					top_pos = fdata_p->top_pos[teigi_no];
					if( top_pos == 0 && teigi_no >= 2 ) break; // �����Ȃ�
					fdata_p->top_pos[teigi_no] += len;
					teigi_no++;
				}
			}
		}
		if( mode == 0 ) break;
	}
}
// ---------------------------------------------------------------------
// "{�`}"�̏���
// �r���Œ�������ꍇ������̂Ō����݂̂�Ӱ�ނ�݂���
// ---------------------------------------------------------------------
void pair_kakko_arrange( int base_type, int line_start, int line_last )
{
	struct	FDATA *fdata_p;
	int		cnt, tmp_line;

	#define DEBUG_LINE	232

#ifdef _DEBUG
	if( line_start >= DEBUG_LINE )
	{
		debug_n = 0;
	}
#endif
//	if( !(base_type == G_TYPE1 || base_type == G_TYPE2 || base_type == G_TYPE_IN || base_type == G_B_K_PAIR) ) return;

	// ---------------- �ő咷���𒲂ׂ� -------------
	cnt = 0;
	for( tmp_line = line_start; tmp_line < line_last; tmp_line++ )
	{
		fdata_p = &ope_buf[tmp_line];
		if( fdata_p->pair_teigi_top == 0 ) continue;

		if( cnt == 0 ) cnt = fdata_p->pair_teigi_end - fdata_p->pair_teigi_top; // len
		else if( (fdata_p->pair_teigi_end - fdata_p->pair_teigi_top) != cnt )
		{ // �萔�̐��Ⴂ
			pair_kakko_parts( 1, line_start, tmp_line );
			line_start = tmp_line;										// set new
			cnt = fdata_p->pair_teigi_end - fdata_p->pair_teigi_top;	// len
		}
	}
	if( line_start < line_last ) pair_kakko_parts( 1, line_start, line_last );
}
// ---------------------------------------------------------------------
// teigi_no = 0:���ĕ⏕ + tab_pos �̏���
// ---------------------------------------------------------------------
void teigi_zero_syori( int line_start, int line_last )
{
	struct	FDATA *fdata_p;
	int		tmp_line, end_pos, max_pos;
	char	buf[CHAR_SIZE];

	for( tmp_line = line_start; tmp_line < line_last; tmp_line++ )
	{
		fdata_p = &ope_buf[tmp_line];
		if( fdata_p->line_type == T_CRLF ) continue; // ���s�݂̂��߽
		if( fdata_p->line_type & T_MASK_MES ) continue;

#ifdef _DEBUG
		if( tmp_line >= 22 )
		{
			debug_n = 0;
		}
#endif

		max_pos = fdata_p->tab_pos * 4;
		cut_last_space( 1, fdata_p->pri_comment ); // �Ō��TAB,space���폜
		end_pos = strlen( fdata_p->pri_comment );
		fdata_p->block_len[0] = end_pos;
		if( end_pos == 0 )
		{ // �Ȃ�
			fdata_p->status[0] = ST_SPACE;
		}
		else {
			memcpy( buf, fdata_p->pri_comment, end_pos ); // top���Ă�copy
			fdata_p->status[0] = ST_SPACE | ST_TAB;
		}
		buf[end_pos] = 0;

		if( (fdata_p->hojo_flag & H_MES15) == 0 )
		{
			if( (max_pos - end_pos) > 0 ) end_pos = arrange_tab_soh( max_pos, end_pos, buf );
		}

		if( end_pos )
		{
			if( buf[end_pos - 1] != _SOH && buf[end_pos - 1] != ' ' &&
				fdata_p->mes[0] != _SOH && fdata_p->mes[0] != ' ' ) buf[end_pos++] = ' ';
			strcpy( &buf[end_pos], fdata_p->mes );	// �{����copy
			strcpy( fdata_p->mes, buf );			// �{����߂�
		}
//		fdata_p->story_last_pos = end_pos;	// �{���̍Ō���(���X�ɍX�V����)
		fdata_p->top_pos[1] = end_pos;		// ����top
		fdata_p->block_len[1] = 0;
		fdata_p->pair_teigi_top = 0;
		fdata_p->pri_comment[0] = 0;		// clear
	}
}
// ---------------------------------------------------------------------
// GASM ����
// ---------------------------------------------------------------------
void g_asm_syori( int base_type, int line_start, int line_last )
{
	struct	FDATA *fdata_p;
	int		pos, top_pos, end_pos, teigi_no, last_teigi_no, tmp_line;
	int		tok_len, max_pos, least_pos;
	int		comment_cnt;
	char	tok_buf[CHAR_SIZE];

	// ------------ �ϐ��̍ő咷���v�Z���� ---------------
	for( tmp_line = line_start; tmp_line < line_last; tmp_line++ )
	{
		fdata_p = &ope_buf[tmp_line];
		if( fdata_p->line_type == T_CRLF ) continue; // ���s�݂̂��߽

//		fdata_p->status[1] = ST_SPACE | ST_TAB;
		fdata_p->status[1] = ST_SPACE;
		fdata_p->status[2] = 0;
	}

	// ----------------- �e��؂�ʒu�����߂� --------------------
	comment_cnt = 0; // �ő�l
	teigi_zero_syori( line_start, line_last );
	for( teigi_no = 1; teigi_no < MAX_TEIGI_NO; teigi_no++ )
	{ // 0:offset��, 1:��`, 2:�萔1, 3:�萔2, ...
		last_teigi_no = 0;
		least_pos = max_pos = 0;
		memset( total_pos, 0, sizeof(total_pos) );

		for( tmp_line = line_start; tmp_line < line_last; tmp_line++ )
		{
			fdata_p = &ope_buf[tmp_line];
			if( fdata_p->line_type == T_CRLF ) continue; // ���s�݂̂��߽
			if( fdata_p->line_type & T_MASK_MES ) continue;
//			if( fdata_p->hojo_flag & H_YEN2 ) continue;

#ifdef _DEBUG
			if( tmp_line >= 4150 && teigi_no >= 0 )
			{
				debug_n = fdata_p->mes[0];
			}
#endif
			if( teigi_no == 1 || fdata_p->top_pos[teigi_no] )
			{
				top_pos = end_pos = fdata_p->top_pos[teigi_no];
				if( fdata_p->hojo_flag & H_YEN2 )
					end_pos += get_tok3( tok_buf, &fdata_p->mes[end_pos], &tok_len );	// ��ۯ��̐؂�o��("//"��1��ۯ�)
				else end_pos += get_tok2( tok_buf, &fdata_p->mes[end_pos], &tok_len );	// ��؂�ʒu�܂Ŏc���荞��

				if( tok_len )
				{
#ifdef _DEBUG
					if( tmp_line >= 127 && teigi_no >= 0 )
					{
						debug_n = fdata_p->mes[0];
					}
#endif
					fdata_p->status[teigi_no] |= ST_SPACE;									// �L��
					fdata_p->block_len[teigi_no] = end_pos - fdata_p->top_pos[teigi_no];	// �� ����
					if( cur_moji_type == C_COM1 || cur_moji_type == C_SEMIKOLON )
					{ // ���Ĕ����BTAB�֎~�͂����ŏ�������
						pos = fdata_p->top_pos[teigi_no - 1] + fdata_p->block_len[teigi_no - 1];
						fdata_p->status[teigi_no] |= ST_COM; // comment
						fdata_p->com_teigi_no = teigi_no;
						comment_cnt++;
					}
					else { // ----------------- �����TAB�ʒu�𒲂ׂ� --------------------
						if( end_pos < MAX_END_MAP )
						{
							if( fdata_p->status[teigi_no] & ST_TAB )
							{ // �L��
								if( end_pos > max_pos ) max_pos = end_pos;			// �傫������set
								if( least_pos == 0 ) least_pos = end_pos;			// ����
								else if( end_pos < least_pos ) least_pos = end_pos; // ����������set
								total_pos[end_pos] += 1;
							}
						}
					}
				}
				else { // �Ȍ�Ȃ�
					fdata_p->status[teigi_no] = 0;		// �Ȃ�
					fdata_p->top_pos[teigi_no] = 0;		// �Ȃ�
					fdata_p->block_len[teigi_no] = 0;	// �� ����
				}
			}
		}

		if( teigi_no == 1 ) max_pos = ( (max_pos + 4) / 4 ) * 4; // pos�ʒu�̌v�Z
		else max_pos = 0;
		// ----------------- TAB�ʒu�����킹�� --------------------
		if( set_tab(teigi_no, line_start, line_last, max_pos) == 0 ) break;
	}
	if( comment_cnt == 0 ) return; // ���ĂȂ�

	// ------------ ���� ��TAB����U �L���ɂ��� -------------
//	for( tmp_line = line_start; tmp_line < line_last; tmp_line++ )
//	{
//		fdata_p = &ope_buf[tmp_line];
//		teigi_no = fdata_p->com_teigi_no;
//		if( teigi_no == 0 ) continue; // ���ĂȂ�

//		if( teigi_no > 0 && teigi_no < MAX_END_MAP ) fdata_p->status[teigi_no] |= ST_TAB;	// TAB�L��
//		else fdata_p->status[teigi_no] &= ~( ST_TAB );										// TAB����
//	}
	// ------------ ���� �̏��� TAB�ʒu��������,������s�� -------------
	while( line_start < line_last )
	{
		comment_syori( base_type, &line_start, line_last );
	}
}
// ---------------------------------------------------------------------
// ���ނ̘A����TAB�ł��낦��
// �r���ŋ�؂����ق����悢�ꍇ��,���̍s��Ԃ�
// return( line_last )
// ---------------------------------------------------------------------
void ajust_tab( int base_type, int line_start, int line_last )
{
	struct	FDATA *fdata_p;
	int		pos, top_pos, end_pos, teigi_no, last_teigi_no, tmp_line, bunpu_cnt;
	int		tok_len, max_pos, least_pos, type_back_pos;
	int		back_end_pos, back_cur_moji_type, back_tok_len, struct_cnt;
	int		comment_cnt, n, flag, sub_type;
	char	tok_buf[CHAR_SIZE];

	// ------------ �ϐ��̍ő咷���v�Z���� ---------------
	struct_cnt = 0; // struct�̐�
	for( tmp_line = line_start; tmp_line < line_last; tmp_line++ )
	{
		fdata_p = &ope_buf[tmp_line];
		if( fdata_p->line_type == T_CRLF ) continue; // ���s�݂̂��߽

#ifdef _DEBUG
		if( tmp_line >= 4150 )
		{
			debug_n = fdata_p->tab_pos;
		}
#endif
		switch( base_type )
		{
		case G_TYPE1:
//		case G_EXTERN:
		case G_DEF_OTHER:
		case G_TYPEDEF:
		case G_STRUCT1: // struct
		case G_STRUCT2: // stryct {}
		case G_TYPE_IN:
			if( (fdata_p->hojo_flag & (H_BIG_K_L | H_BIG_K_R)) == H_BIG_K_L ||
				(fdata_p->hojo_flag & (H_BIG_K_L | H_BIG_K_R)) == H_BIG_K_R ) fdata_p->status[1] = 0;
			else if( fdata_p->line_type == T_STRUCT_IN || fdata_p->line_type == T_UNION_IN )
			{
				if( fdata_p->hojo_flag & H_B_K_PAIR ) fdata_p->status[1] = 0;
				else if( (tmp_line + 1) < line_last && ope_buf[tmp_line + 1].line_type == T_BIG_KAKKO &&
					(ope_buf[tmp_line + 1].hojo_flag & H_BIG_K_L) ) fdata_p->status[1] = 0;
				else {
					fdata_p->status[1] = ST_SPACE | ST_TAB;
					struct_cnt++; // struct�̐�
				}
			}
			else fdata_p->status[1] = ST_SPACE | ST_TAB;
			fdata_p->status[2] = 0;
			fdata_p->status[3] = 0;
			fdata_p->status[4] = 0;
			break;

		case G_TYPE2: // + {}
			fdata_p->status[1] = ST_SPACE | ST_TAB;
			fdata_p->status[2] = 0;
			fdata_p->status[3] = 0;
			fdata_p->status[4] = 0;
			break;

		case G_B_K_PAIR:
			fdata_p->status[1] = 0;
			fdata_p->status[2] = ST_SPACE | ST_TAB;
			fdata_p->status[3] = ST_SPACE | ST_TAB;
			fdata_p->status[4] = ST_SPACE | ST_TAB;
			break;

		case G_DIGIT:
			fdata_p->status[1] = ST_SPACE | ST_TAB;
			fdata_p->status[2] = ST_SPACE | ST_TAB;
			fdata_p->status[3] = ST_SPACE | ST_TAB;
			fdata_p->status[4] = ST_SPACE | ST_TAB;
			break;

		case G_MOJIS:
			fdata_p->status[1] = 0;
			fdata_p->status[2] = 0;
			fdata_p->status[3] = 0;
			fdata_p->status[4] = 0;
			break;

		case G_DEFINE:
			fdata_p->status[1] = ST_SPACE | ST_TAB;
			fdata_p->status[2] = ST_SPACE | ST_TAB;
			fdata_p->status[3] = 0;
			fdata_p->status[4] = 0;
			break;

//		case G_ASM: // ��������
//			fdata_p->status[1] = ST_SPACE | ST_TAB;
//			fdata_p->status[2] = 0;
//			fdata_p->status[3] = 0;
//			fdata_p->status[4] = 0;
//			break;

		default:
//		case G_IF:
//		case G_INCLUDE:
//		case G_OTHER:
//		case G_PROC:
			fdata_p->status[1] = 0;
			fdata_p->status[2] = 0;
			fdata_p->status[3] = 0;
			fdata_p->status[4] = 0;
			break;
		}
	}
	if( struct_cnt >= 2 )
	{ // ������struct�̏ꍇ�͑�����
		for( tmp_line = line_start; tmp_line < line_last; tmp_line++ )
		{
			fdata_p = &ope_buf[tmp_line];
			if( fdata_p->line_type == T_STRUCT_IN &&
				(fdata_p->hojo_flag & (H_BIG_K_L | H_BIG_K_R)) == 0 ) fdata_p->status[2] = ST_SPACE | ST_TAB;
//			if( fdata_p->line_type == T_STRUCT_IN )
//			{
//				if( ((tmp_line + 1) < line_last && ope_buf[tmp_line + 1].line_type != T_BIG_KAKKO) &&
//					(fdata_p->hojo_flag & (H_BIG_K_L | H_BIG_K_R)) == 0 ) fdata_p->status[2] = ST_SPACE | ST_TAB;
//			}
		}
	}
	// ----------------- �e��؂�ʒu�����߂� --------------------
	comment_cnt = 0;
	teigi_zero_syori( line_start, line_last );
	for( teigi_no = 1; teigi_no < MAX_TEIGI_NO; teigi_no++ )
	{ // 0:offset��, 1:��`, 2:�萔1, 3:�萔2, ...
		last_teigi_no = 0;
		bunpu_cnt = 0;
		end_pos = least_pos = max_pos = 0; // zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz
		memset( total_pos, 0, sizeof(total_pos) );

		for( tmp_line = line_start; tmp_line < line_last; tmp_line++ )
		{
			fdata_p = &ope_buf[tmp_line];
			if( fdata_p->line_type == T_CRLF ) continue; // ���s�݂̂��߽
			if( fdata_p->line_type & T_MASK_MES ) continue;
//			if( fdata_p->hojo_flag & H_YEN2 ) continue;

#ifdef _DEBUG
			if( tmp_line >= 7817 )
			{
				debug_n = fdata_p->mes[0];
			}
#endif
			if( teigi_no == 1 )
			{
//				if( fdata_p->hojo_flag & (H_MES14 | H_MES15 | H_MES_E) ) comment_cnt++;
				fdata_p->big_kakko_cnt = 0;
			}

			if( teigi_no == 1 || fdata_p->top_pos[teigi_no] )
			{
				top_pos = end_pos = fdata_p->top_pos[teigi_no];
				if( teigi_no > 4 ) fdata_p->status[teigi_no] |= fdata_p->status[4] & ( ST_SPACE | ST_TAB ); // �Ȍ㓯���ɂ���

				if( chk_tab_enable(tmp_line) == G_OTHER ) fdata_p->status[teigi_no] = ST_SPACE;				// TAB�֎~

				if( fdata_p->line_type == T_DEFINE )
				{
					if( teigi_no == 1 )
						end_pos += get_tok2( tok_buf, &fdata_p->mes[end_pos], &tok_len );		// ��؂�ʒu�܂Ŏc���荞��
					else if( teigi_no == 2 )
						end_pos += get_define_no2( tok_buf, &fdata_p->mes[end_pos], &tok_len ); // #define�̋�؂�𓾂�
//					else if( form_define_tab == 0 || teigi_no >= 3 )
					else
						end_pos += get_tok3( tok_buf, &fdata_p->mes[end_pos], &tok_len );		// ��ۯ��̐؂�o��("//"��1��ۯ�)
				}
				else if( fdata_p->hojo_flag & H_YEN2 )
					end_pos += get_tok3( tok_buf, &fdata_p->mes[end_pos], &tok_len ); // ��ۯ��̐؂�o��("//"��1��ۯ�)
				else if( fdata_p->line_type == T_DEFIF )
				{
					end_pos += get_tok2( tok_buf, &fdata_p->mes[end_pos], &tok_len ); // ��؂�ʒu�܂Ŏc���荞��
				}
				else {
					type_back_pos = end_pos; // TYPE_MASK�p
					if( fdata_p->status[teigi_no] & (ST_PAIR_R | ST_PAIR_IN) )
					{ // "{�`}"�̃R�s�[�B��ϒP�ʂŋ�؂�. cur_moji_type = C_KOMMA, C_COM1, C_BIG_K_L, C_BIG_K_R
						end_pos += get_tok4( tok_buf, &fdata_p->mes[end_pos], &tok_len );
					}
					else end_pos += get_tok2( tok_buf, &fdata_p->mes[end_pos], &tok_len ); // ��؂�ʒu�܂Ŏc���荞��
					if( cur_moji_type == C_BIG_K_L )
					{
						if( fdata_p->hojo_flag & H_B_K_PAIR )
						{
							if( chk_big_kakko(&fdata_p->mes[top_pos], &pos) <= 0 )
							{
								if( fdata_p->pair_teigi_top )
								{ // ��������
									fdata_p->hojo_flag &= ~( H_B_K_PAIR ); // �������߱����ʂ�,reset
									for( pos = fdata_p->pair_teigi_top; pos <= teigi_no; pos++ )
									{
										fdata_p->status[pos] &= ~( ST_PAIR_L | ST_PAIR_R | ST_PAIR_IN ); // reset "{�`}"
									}
									fdata_p->pair_teigi_top = 0;
									fdata_p->big_kakko_cnt = 0;
								}
								else { // �V�K�o�^
									fdata_p->status[teigi_no] |= ST_PAIR_L; // "{�`}"�̊J�n�ʒu
									fdata_p->pair_teigi_top = teigi_no;
									fdata_p->pair_teigi_end = 0;			// reset
									fdata_p->big_kakko_cnt++;
								}
							}
						}
						else for( n = teigi_no; n < MAX_END_MAP; n++ )
						{
							if( fdata_p->status[n] == 0 ) break;
							fdata_p->status[n] &= ~( ST_TAB );
						}
						end_pos += add_comment( &fdata_p->mes[end_pos] ); // "{"+���ĂȂ�P�ɂ���
					}
					else if( cur_moji_type == C_BIG_K_R )
					{
						if( (fdata_p->hojo_flag & H_B_K_PAIR) && fdata_p->pair_teigi_end == 0 )
						{
							if( --fdata_p->big_kakko_cnt == 0 )
							{ // ��؂�ʒu
								if( (fdata_p->pair_teigi_top + 1) == teigi_no )
								{ // "{}"
									fdata_p->hojo_flag &= ~( H_B_K_PAIR ); // �������߱����ʂ�,reset
									for( pos = fdata_p->pair_teigi_top; pos <= teigi_no; pos++ )
									{
										fdata_p->status[pos] &= ~( ST_PAIR_L | ST_PAIR_R | ST_PAIR_IN ); // reset "{�`}"
									}
									fdata_p->pair_teigi_top = 0;
									fdata_p->big_kakko_cnt = 0;
								}
								else {
									fdata_p->status[teigi_no] |= ST_PAIR_R;
									fdata_p->pair_teigi_end = teigi_no;
								}
							}
						}
						else for( n = teigi_no; n < MAX_END_MAP; n++ )
						{
							if( fdata_p->status[n] == 0 ) break;
							fdata_p->status[n] &= ~( ST_TAB );
						}
//						end_pos += add_comment( &fdata_p->mes[end_pos] ); // "{"+���ĂȂ�P�ɂ���
					}

					if( teigi_no == 1 )
					{
#ifdef _DEBUG
						if( tmp_line >= 96 )
						{
							debug_n = fdata_p->mes[0];
						}
#endif
						if( fdata_p->line_type == T_TYPEDEF )
						{
							back_end_pos = end_pos;													// �ޔ�
							end_pos += kaiseki_typedef( &fdata_p->mes[end_pos] );					// #typedef �̉��
							if( back_end_pos == end_pos ) fdata_p->status[teigi_no] &= ~( ST_TAB ); // tab �֎~
						}
						else {
							if( cur_moji_type == C_KOMMA || cur_moji_type == C_KOLON || cur_moji_type == C_WKOLON )
							{
								back_end_pos = end_pos;												// �ޔ�
								back_cur_moji_type = cur_moji_type;									// �ޔ�
								back_tok_len = tok_len;
								end_pos += get_tok2( tok_buf, &fdata_p->mes[end_pos], &tok_len );	// ��؂�ʒu�܂Ŏc���荞��
								if( cur_moji_type == C_COM1 || cur_moji_type == 0 )
								{ // �߂�
									end_pos = back_end_pos;
									cur_moji_type = back_cur_moji_type;
									tok_len = back_tok_len;
								}
								else type_back_pos = back_end_pos;
							}

							if( cur_moji_type == C_OTHER )
							{
								if( fdata_p->line_type & (T_TYPE | T_MASK_IN | T_STRUCT | T_UNION) )
								{
									// �������Ō�Ɍ����BMASK_TYPE���P�ɂ���
									type_back_pos += add_bind_type2( tmp_line, &fdata_p->mes[type_back_pos] );
									if( end_pos < type_back_pos ) end_pos = type_back_pos;
								}
							}
							else if( cur_moji_type == C_STRUCT || cur_moji_type == C_UNION )
								end_pos += add_b_k_l( &fdata_p->mes[end_pos] ); // struct/union+'{'�Ȃ�P�ɂ���
							else if( cur_moji_type & (C_MASK_TYPE1 | C_MASK_TYPE2) )
							{
								// �������Ō�Ɍ����B������MASK_TYPE���P�ɂ���
								type_back_pos += add_bind_type2( tmp_line, &fdata_p->mes[type_back_pos] );
								if( end_pos < type_back_pos ) end_pos = type_back_pos;
							}
						}
					}
				}
				if( tok_len )
				{
#ifdef _DEBUG
					if( tmp_line >= 4150 && teigi_no >= 1 )
					{
						debug_n = fdata_p->mes[0];
					}
#endif
					fdata_p->status[teigi_no] |= ST_SPACE;											// �L��
					if( fdata_p->line_type == T_DEFIF ) fdata_p->status[teigi_no] &= ~( ST_TAB );	// �֎~
					fdata_p->block_len[teigi_no] = end_pos - fdata_p->top_pos[teigi_no];			// �� ����
					if( cur_moji_type == C_COM1 )
					{ // ���Ĕ����BTAB�֎~�͂����ŏ�������
						pos = fdata_p->top_pos[teigi_no - 1] + fdata_p->block_len[teigi_no - 1];
						fdata_p->status[teigi_no] |= ST_COM; // comment
						fdata_p->com_teigi_no = teigi_no;
						comment_cnt++;
					}
					else { // ----------------- �����TAB�ʒu�𒲂ׂ� --------------------
						if( end_pos < MAX_END_MAP )
						{
							if( (fdata_p->status[teigi_no] & (ST_PAIR_L | ST_PAIR_R | ST_PAIR_IN)) &&
								fdata_p->pair_teigi_end == 0 )
							{
								fdata_p->status[teigi_no + 1] |= ST_PAIR_IN; // �Ȍ�set
							}
							if( (fdata_p->status[teigi_no] & (ST_PAIR_R | ST_PAIR_IN)) == 0 )
							{ // --------- �߱����� "{�`}"���ł͂Ȃ� ---------------------
								if( fdata_p->status[teigi_no] & ST_TAB )
								{ // �L��
									if( end_pos > max_pos ) max_pos = end_pos;			// �傫������set
									if( least_pos == 0 ) least_pos = end_pos;			// ����
									else if( end_pos < least_pos ) least_pos = end_pos; // ����������set
									total_pos[end_pos] += 1;
									bunpu_cnt++;
								}
							}
						}
						else fdata_p->status[teigi_no] &= ~( ST_TAB ); // TAB����
					}
				}
				else { // �Ȍ�Ȃ�
					fdata_p->status[teigi_no] = 0;		// �Ȃ�
					fdata_p->top_pos[teigi_no] = 0;		// �Ȃ�
					fdata_p->block_len[teigi_no] = 0;	// �� ����
				}
			}
		}
//		if( teigi_no >= 2 && (base_type & (G_DEFINE | G_DEF_OTHER | G_TYPEDEF)) == 0 )
		if( (base_type & (G_DEFINE | G_DEF_OTHER | G_TYPEDEF)) == 0 )
		{
			if( bunpu_cnt == 1 || max_pos == least_pos ) max_pos = 0; // �����c�ʒu�̘A�� ' '�̂�
		}
		if( base_type == G_DEFINE )
		{
			max_pos = ( (max_pos + 4) / 4 ) * 4;			// �Œ�1TAB�ȏ�󂯂�
			if( (max_pos - least_pos) < 2 ) max_pos += 4;	// �Œ�2��߰��ȏ�󂯂�
		}
		else if( base_type == G_DIGIT ) max_pos++;
		else max_pos = ( (max_pos + 4) / 4 ) * 4; // pos�ʒu�̌v�Z

		if( teigi_no == 1 )
		{
			switch( base_type )
			{
//			case G_EXTERN:
			case G_DEF_OTHER:
			case G_TYPEDEF:
			case G_TYPE1:
			case G_TYPE2:
//			case G_OTHER_TYPE:
				if( form_global_int_tab > 0 && form_global_int_tab != 2 &&
					max_pos > (form_global_int_tab * 4) ) max_pos = form_global_int_tab * 4;
				break;

			case G_DEFINE:
				max_pos = 0; // space only
				break;

			case G_TYPE_IN:
				if( form_local_int_tab > 0 && form_local_int_tab != 2 &&
					max_pos > (form_local_int_tab * 4) ) max_pos = form_local_int_tab * 4;
				break;

//			case G_STRUCT1:
//			case G_STRUCT2:
//			case G_B_K_PAIR:
//			case G_IF:
//			case G_OTHER:
//			case G_INCLUDE:
//			case G_DEFIF:
//			case G_DIGIT:
//			case G_CASE:
//				break;
			}
		}
		else if( teigi_no == 2 && base_type == G_DEFINE )
		{
			if( form_define_tab == 1 ) max_pos = 0; // ��߰��̂�
			else if( form_define_tab >= 3 )
			{
				if( max_pos < (form_define_tab * 4) ) max_pos = form_define_tab * 4;
			}
		}
		// ----------------- TAB�ʒu�����킹�� --------------------
		if( set_tab(teigi_no, line_start, line_last, max_pos) == 0 ) break;
	}
	// --------------- '{'�����낦�� -----------------------
	pair_kakko_parts( 0, line_start, line_last );

	if( base_type == G_TYPE1 || base_type == G_TYPE2 )
	{
		flag = 0;
		for( tmp_line = line_start; tmp_line < line_last; tmp_line++ )
		{
			fdata_p = &ope_buf[tmp_line];
			if( fdata_p->line_type == T_CRLF ) continue; // ���s�݂̂��߽
#ifdef _DEBUG
			if( tmp_line >= 64 )
			{
				debug_n = (int)fdata_p->mes;
			}
#endif
			if( flag == 0 )
			{ // ����
				n = tmp_line;
				if( (fdata_p->hojo_flag & H_BIG_K_L) && fdata_p->sub_type )
				{ // type�ő�����
					sub_type = fdata_p->sub_type;
					flag = 2;
				}
				else { // ����������
					sub_type = 0;
					flag = 1;
				}
			}
			else if( flag == 1 )
			{ // ����������
				if( (fdata_p->hojo_flag & H_BIG_K_L) && fdata_p->sub_type )
				{ // �ω�
					pair_kakko_arrange( base_type, n, tmp_line );	// "{�`}"�̏���
					n = tmp_line;									// set new
					sub_type = fdata_p->sub_type;
					flag = 2;
				}
			}
			else if( flag == 2 )
			{ // type�ő�����
				if( !((fdata_p->hojo_flag & H_BIG_K_L) && sub_type == fdata_p->sub_type) )
				{ // �ω�����
					pair_kakko_arrange( base_type, n, tmp_line );	// "{�`}"�̏���
					n = tmp_line;									// set new
					if( fdata_p->hojo_flag & H_BIG_K_L )
					{ // type�ő�����
						sub_type = fdata_p->sub_type;
						flag = 2;
					}
					else { // ����������
						sub_type = 0;
						flag = 1;
					}
				}
			}
		}
		if( n < line_last ) pair_kakko_arrange( base_type, n, line_last ); // �c�菈���B"{�`}"�̏���
	}
	else pair_kakko_arrange( base_type, line_start, line_last );	// "{�`}"�̏���

	if( comment_cnt == 0 ) return;									// ���ĂȂ�

	// ------------ ���� ��TAB����U �L���ɂ��� -------------
//	for( tmp_line = line_start; tmp_line < line_last; tmp_line++ )
//	{
//		fdata_p = &ope_buf[tmp_line];
//		teigi_no = fdata_p->com_teigi_no;
//		if( teigi_no == 0 ) continue;					// ���ĂȂ�

//		if( teigi_no > 0 && teigi_no < MAX_END_MAP )
//			fdata_p->status[teigi_no] |= ST_TAB;		// TAB�L��
//		else fdata_p->status[teigi_no] &= ~( ST_TAB );	// TAB����
//	}
	// ------------ ���� �̏��� TAB�ʒu��������,������s�� -------------
	while( line_start < line_last )
	{
		comment_syori( base_type, &line_start, line_last );
	}
}
// ---------------------------------------------------------------------
// ���ނ̘A����TAB�ł��낦��
// ̧�قɏo��
// return 0:�ύX�Ȃ�, -1:�ύX�ӏ�������, >0:�ύX�s��
// ---------------------------------------------------------------------
int save_dst_file( void )
{
	FILE	*fp_dst, *fp_dbg;
	string	srcSJIS_out;
	struct	FDATA *fdata_p;
	int		len, line_no, line_last, base_type, crlf_cnt, com_pos, cur_type, syori_cnt, n;
	int		tmp_type;
	char	dbg_buf[CHAR_SIZE2], buf[CHAR_SIZE2];

	strcpy( tmp_name, "renew_tmp.tmp" );
	fp_dst = fopen( tmp_name, "wb" ); // �폜
	if( fp_dst == NULL )
	{
		printf( "Fatal: can't open file:%s\n", new_name );
		wait_exit( 1 );
	}

	if( debug_mode )
	{
		fp_dbg = fopen( debug_name2, "wb" ); // �폜
		if( fp_dbg == NULL )
		{
			printf( "Fatal: can't open file:%s\n", debug_name2 );
			wait_exit( 1 );
		}
	}
	else fp_dbg = NULL;

	// ---------------- �O�s�̺��Ăɍ��킹�邩�̈ʒu���� -------------------
	com_pos = 0;
	for( line_no = 0; line_no < max_line; line_no++ )
	{
		fdata_p = &ope_buf[line_no];

		if( fdata_p->line_type == T_CRLF ) continue; // ���s�݂̂��߽

#ifdef _DEBUG
		if( line_no >= 77 )
		{
			debug_n = (int)fdata_p->mes;
		}
#endif
		open_tab_mes( line_no ); // pri_comment, tab_pos��W�J����
		if( (fdata_p->line_type == T_MES15) && com_pos && com_pos <= fdata_p->src_com_pos )
		{ // ���Ă݂̂�TAB��,�O�s�̺��Ă�TAB�ƍ��킹��
			fdata_p->src_com_pos = com_pos;
			fdata_p->hojo_flag |= H_MES_E;
			// ---------- change ---------------
			fdata_p->line_type = T_COM_MES; // �O�s�̺��Ĉʒu�ɍ��킹��
			strcpy( buf, "//" );
			if( fdata_p->mes[0] != ' ' && fdata_p->mes[0] != _SOH ) strcat( buf, " " );
			strcat( buf, fdata_p->mes );	// �{����copy
			strcpy( fdata_p->mes, buf );	// �{����߂�
			fdata_p->com_teigi_no = 0;
			fdata_p->pri_comment[0] = 0;
		}
		if( fdata_p->line_type == T_MES15 || (fdata_p->hojo_flag & H_BIG_K_L) ) com_pos = 0;
		else com_pos = fdata_p->src_com_pos; // ���Ă�top�ʒu��save
	}

	crlf_cnt = 1; // �A�����s��. �ŏ��̉��s�͍폜
	line_last = 0;
	for( line_no = 0; line_no < max_line; line_no++ )
	{ // fdata_p �ł͏d������̂ŁA�����ł�fdata�g�p
		fdata = &ope_buf[line_no];

#ifdef _DEBUG
		if( line_no >= 7816 )
		{
			debug_n = (int)fdata->mes;
		}
#endif

		if( line_no >= line_last && fdata->line_type != T_CRLF )
		{ // ����
			base_type = chk_tab_enable( line_no ); // TAB�␳�̕K�v�����m�F
			if( fdata->hojo_flag & (H_YEN1 | H_YEN2) ) base_type = G_YEN;

			if( base_type )
			{ // ------------ �A�����铯��type�𒲂ׂ� ---------------
				for( line_last = line_no; line_last < max_line; line_last++ )
				{
					fdata_p = &ope_buf[line_last];

#ifdef _DEBUG
					if( line_last >= 77 )
					{
						debug_n = (int)fdata_p->mes;
					}
#endif
					if( fdata_p->line_type == T_CRLF ) continue;
					if( fdata_p->line_type == T_COM_MES ) continue;
					if( fdata_p->line_type == T_DEFIF ) continue;
//					if( fdata_p->line_type == T_MES15 ) continue;
					if( base_type != G_TYPE_IN && (fdata_p->hojo_flag & H_MES15) ) continue;
					if( base_type != G_YEN )
					{
						if( fdata_p->hojo_flag & (H_YEN1 | H_YEN2) ) break; // 2012.08.31
					}
					cur_type = chk_tab_enable( line_last );
					if( fdata_p->hojo_flag & (H_YEN1 | H_YEN2) ) cur_type = G_YEN;

					if( base_type == G_DEFINE )
					{
						if( fdata_p->line_type == T_MES14 || fdata_p->line_type == T_MES15 )
						{
							tmp_type = fdata_p->line_type;
							if( chk_same_teigi(base_type, tmp_type, &line_last, max_line) == 0 ) break;
							continue;
						}
						if( base_type != cur_type ) break;
					}
					else if( base_type == G_TYPE_IN )
					{
//						if( fdata_p->tab_pos && fdata_p->line_type == T_BIG_KAKKO ) continue; // 2013.10.10
						if( base_type != cur_type ) break;
					}
					else if( base_type & G_TYPE1 )
					{
						if( fdata_p->line_type == T_OTHER ) continue;
						if( fdata_p->line_type == T_STRUCT ) continue;	// 2013.10.01
						if( fdata_p->line_type == T_UNION ) continue;	// 2013.10.07
						if( fdata_p->line_type == T_MES14 || fdata_p->line_type == T_MES15 )
						{
							tmp_type = fdata_p->line_type;
							if( chk_same_teigi(base_type, tmp_type, &line_last, max_line) == 0 ) break;
							continue;
						}
						if( base_type != cur_type ) break;
					}
					else if( base_type & G_TYPE2 )
					{
						if( fdata_p->line_type == T_MES14 || fdata_p->line_type == T_MES15 )
						{
							tmp_type = fdata_p->line_type;
							if( chk_same_teigi(base_type, tmp_type, &line_last, max_line) == 0 ) break;
							continue;
						}
						if( base_type != cur_type ) break;
					}
					else if( base_type == G_B_K_PAIR )
					{
						if( base_type != cur_type ) break;
					}
					else if( base_type == G_DIGIT )
					{
						if( fdata_p->line_type == T_OTHER ) continue;
						if( fdata_p->line_type == T_MES14 || fdata_p->line_type == T_MES15 )
						{
							tmp_type = fdata_p->line_type;
							if( chk_same_teigi(base_type, tmp_type, &line_last, max_line) == 0 ) break;
							continue;
						}
						if( base_type != cur_type ) break;
					}
					else if( base_type == G_OTHER )
					{
						if( fdata_p->line_type == T_DIGIT ) continue;
						if( fdata_p->line_type == T_MOJIS ) continue;
						if( base_type != cur_type )
						{
							if( form_other_com_tab >= 2 && cur_type == G_IF ) continue;
							else break;
						}
					}
					else if( base_type == G_IF )
					{
						if( base_type != cur_type )
						{
							if( form_other_com_tab >= 2 && cur_type == G_OTHER ) continue;
							else break;
						}
					}
					else if( base_type == G_STRUCT1 || base_type == G_STRUCT2 )
					{
						if( base_type != cur_type && fdata_p->tab_pos == 0 ) break;
					}
//					else if( base_type == G_EXTERN )
//					{
//						if( base_type != cur_type ) break;
//					}
					else if( base_type == G_DEF_OTHER || base_type == G_TYPEDEF )
					{
						if( fdata_p->line_type == T_MOJIS ) continue;
						if( fdata_p->line_type == T_MES14 || fdata_p->line_type == T_MES15 )
						{
							tmp_type = fdata_p->line_type;
							if( chk_same_teigi(base_type, tmp_type, &line_last, max_line) == 0 ) break;
							continue;
						}
						if( base_type != cur_type ) break;
					}
//					else if( base_type == G_MOJIS && cur_type == G_TYPE_IN ) continue;
					else { // ���̑�, G_STRUCT, G_CASE, G_INCLUDE, G_ASM, G_YEN, G_PROC
						if( base_type != cur_type ) break;
					}
				}
#ifdef _DEBUG
				if( line_no >= 7816 )
				{
					debug_n = 0;
				}
#endif
				if( line_no < line_last )
				{ // 2�s�ȏ�
					if( base_type == G_ASM ) g_asm_syori( base_type, line_no, line_last );
					else ajust_tab( base_type, line_no, line_last ); // ���ނ̘A����TAB�ł��낦��
				}
			}
		}

		if( fdata->pri_comment[0] )
//		if( (fdata->hojo_flag & H_MES17) == 0 && fdata->pri_comment[0] )
		{
			strcpy( buf, fdata->pri_comment );
			len = strlen( buf );
			if( buf[len - 1] != _SOH && buf[len - 1] != ' ' &&
				fdata->mes[0] != _SOH && fdata->mes[0] != ' ' ) strcat( buf, " " );
			strcat( buf, fdata->mes );
		}
		else strcpy( buf, fdata->mes );
		cut_last_space( 1, buf );	// �Ō��TAB,space���폜

		chg_soh_tab( 1, buf );		// ��؂�̽�߰���TAB�ɕϊ�

		if( fp_dbg != NULL )
		{
			strcpy( dbg_buf, buf );
			disp_debug_para2( dbg_buf );
		}
		strcat( buf, "\r\n" );
		if( font_type == 1 )
		{ // 0:����, 1:utf8, 2:Shift JIS
			srcSJIS_out = SjistoUTF8( (string)buf );
			strcpy( buf, srcSJIS_out.c_str() );
		}
//		save_error_file( buf ); // �L�^ zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz

		if( fp_dbg != NULL ) strcat( dbg_buf, "\r\n" );
		len = strlen( buf );
		if( len > 2 )
		{
			fwrite( buf, sizeof(char), len, fp_dst );
			if( fp_dbg != NULL )
			{
				len = strlen( dbg_buf );
				fwrite( dbg_buf, sizeof(char), len, fp_dbg );
			}
			crlf_cnt = 0; // reset
		}
		else if( ++crlf_cnt < 2 )
		{ // �A������LF�͖���
			fwrite( buf, sizeof(char), len, fp_dst );
			if( fp_dbg != NULL )
			{
				len = strlen( dbg_buf );
				fwrite( dbg_buf, sizeof(char), len, fp_dbg );
			}
		}
	}
	fclose( fp_dst );
	if( fp_dbg != NULL ) fclose( fp_dbg );
	// ------------------ ���̧�قƔ�r ------------------
	fp_src = fopen( src_name, "rb+" );
	if( fp_src == NULL )
	{
		DeleteFile( tmp_name ); // �폜
		printf( "Fatal: can't open file:%s\n", src_name );
		wait_exit( 1 );
	}

	fp_dst = fopen( tmp_name, "rb+" );
	if( fp_dst == NULL )
	{
		fclose( fp_src );
		fp_src = NULL;
//		DeleteFile( tmp_name ); // �폜
		printf( "Fatal: can't open file:%s\n", tmp_name );
		wait_exit( 1 );
	}
//	fseek( fp_src, 0, SEEK_SET ); // �߂�
//	fseek( fp_dst, 0, SEEK_SET ); // �߂�

	line_no = 0;
	syori_cnt = 0;
	for(;;)
	{
		len = getln( fp_src, r_buf, CHAR_SIZE2 );				// ̧�ق�����s�����܂Ŏ�荞��(CR+LF-->LF)
		line_no++;
		n = getln( fp_dst, w_buf, CHAR_SIZE2 );					// ̧�ق�����s�����܂Ŏ�荞��(CR+LF-->LF)
		if( r_buf[0] == 0 && w_buf[0] == 0 ) break;				// OK
		if( n != len ) syori_cnt++;								// �s��v
		else if( memcmp(r_buf, w_buf, len) != 0 ) syori_cnt++;	// �s��v
	}
	if( fp_src != NULL ) fclose( fp_src );
	fp_src = NULL;
	fclose( fp_dst );

	if( debug_mode == 0 )
	{
		switch( form_source_name )
		{
		case 0: // ������̏��� 0:�����̂�
			break;

		case 1: // �ύX ������̏��� 1:������͕ς�炸+.new��V�K�ɍ��
			DeleteFile( new_name );									// �폜
			if( syori_cnt != 0 ) MoveFile( tmp_name, new_name );	// �ύX
			break;

		case 2: // ������̏��� 2:�������+.old�Ƃ���
			DeleteFile( old_name ); // �폜
			if( syori_cnt != 0 )
			{
				MoveFile( src_name, old_name ); // �ύX ������̏��� 2:�������+.old�Ƃ���
				MoveFile( tmp_name, src_name ); // �ύX
			}
			break;

		case 3: // ������̏��� 3:old�����Ȃ�
			DeleteFile( old_name ); // �폜
			if( syori_cnt != 0 )
			{
				MoveFile( src_name, old_name ); // �ꎞ�I��rename
				MoveFile( tmp_name, src_name ); // �ύX
				DeleteFile( old_name );			// �폜
			}
			break;
		}
	}
	DeleteFile( tmp_name ); // �폜
	return( syori_cnt );
}
// ------------------------------------------
// utf8 to shiftJIS
// ------------------------------------------
std::string UTF8toSjis( std::string srcUTF8 )
{
	// Unicode�֕ϊ���̕����񒷂𓾂�
	int lenghtUnicode = MultiByteToWideChar( CP_UTF8, 0, srcUTF8.c_str(), srcUTF8.size() + 1, NULL, 0 );

	// �K�v�ȕ�����Unicode������̃o�b�t�@���m��
	wchar_t *bufUnicode = new wchar_t[lenghtUnicode];

	// UTF8����Unicode�֕ϊ�
	MultiByteToWideChar( CP_UTF8, 0, srcUTF8.c_str(), srcUTF8.size() + 1, bufUnicode, lenghtUnicode );

	// ShiftJIS�֕ϊ���̕����񒷂𓾂�
	int lengthSJis = WideCharToMultiByte( CP_THREAD_ACP, 0, bufUnicode, -1, NULL, 0, NULL, NULL );

	// �K�v�ȕ�����ShiftJIS������̃o�b�t�@���m��
	char *bufShiftJis = new char[lengthSJis];

	// Unicode����ShiftJIS�֕ϊ�
	WideCharToMultiByte( CP_THREAD_ACP, 0, bufUnicode, lenghtUnicode + 1, bufShiftJis, lengthSJis, NULL, NULL );

	std::string strSJis( bufShiftJis );

	delete bufUnicode;
	delete bufShiftJis;

	return( strSJis );
}

// ------------------------------------------
// shiftJIS to utf8
// ------------------------------------------
std::string SjistoUTF8( std::string srcSjis )
{
	// Unicode�֕ϊ���̕����񒷂𓾂�
	int lenghtUnicode = MultiByteToWideChar( CP_THREAD_ACP, 0, srcSjis.c_str(), srcSjis.size() + 1, NULL, 0 );

	// �K�v�ȕ�����Unicode������̃o�b�t�@���m��
	wchar_t* bufUnicode = new wchar_t[lenghtUnicode];

	// ShiftJIS����Unicode�֕ϊ�
	MultiByteToWideChar( CP_THREAD_ACP, 0, srcSjis.c_str(), srcSjis.size() + 1, bufUnicode, lenghtUnicode );

	// UTF8�֕ϊ���̕����񒷂𓾂�
	int lengthUTF8 = WideCharToMultiByte( CP_UTF8, 0, bufUnicode, -1, NULL, 0, NULL, NULL );

	// �K�v�ȕ�����UTF8������̃o�b�t�@���m��
	char* bufUTF8 = new char[lengthUTF8];

	// Unicode����UTF8�֕ϊ�
	WideCharToMultiByte( CP_UTF8, 0, bufUnicode, lenghtUnicode + 1, bufUTF8, lengthUTF8, NULL, NULL );

	std::string strUTF8( bufUTF8 );

	delete bufUnicode;
	delete bufUTF8;

	return( strUTF8 );
}
