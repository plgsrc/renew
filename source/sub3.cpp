// ---------------------------------------------------------------------
// sub3.cpp
// 整形出力
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
// 演算子かの検査
// return 0:無効, 1:有効
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
// 【機能】intをｱｽｷｰに変換
// 【入力】obj_data	: 元のﾃﾞｰﾀ
// 【入力】*d_str	: 変換後の収納先
// 【入力】len		: 変換後の長さ(max 10)
// 【出力】なし
// 【備考】
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
// 【機能】longをｱｽｷｰに変換
// 【入力】obj_data	: 元のﾃﾞｰﾀ
// 【入力】*d_str	: 変換後の収納先
// 【入力】len		: 変換後の長さ(max 9)
// 【出力】なし
// 【備考】
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
// 【機能】2word のﾊﾞｲﾅﾘをｱｽｷｰに変換(0を付加)
// 【入力】int obj_data, char *d_str
// 【出力】なし
// 【備考】
// ====================================================================
// void obj_bcd8( int obj_data, char *d_str )
// {
//	static char hex_map[] = "0123456789ABCDEF";
//	int			i;
//	int			sign;
//
//	if( obj_data < 0 )
//	{ // ﾏｲﾅｽ
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
// ---------- n桁(MAX=8)のBCDを2wordのﾊﾞｲﾅﾘに変換 ----------
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
//		if( moji >= '0' && moji <= '9' ) obj_data = ( obj_data * 10 ) + ( moji & 0xf ); // 0～9
//		else return( obj_data );
//	}
//	return( obj_data );
// }
// --------------------------------------------------
int get_key( void )
{
	// ｷｬﾗｸﾀｰｺｰﾄﾞが0x00のときは､ｽｷｬﾝｺｰﾄﾞを読むようになってる
	int keydata;

	keydata = getchar();
	if( keydata == -1 ) return( -1 );

	return( keydata & 0xff );
}
// -------------- 文字のcheck -------------------------
int moji_check( char moji )
{
	int c;

	c = (int)moji & 0xff;
	if( c < ' ' ) return( 1 );									// control code
	if( c < 0x7f ) return( 2 );									// print code
	if( c == 0x7f ) return( 4 );								// delete code
//	if( (c & 0xe0) == 0x80 || (c & 0xe0) == 0xe0 ) return( 8 ); // kanji
	if( (c >= 0x81) && c <= 0x84 ) return( 8 );					// ShiftJIS 漢字
	if( (c >= 0x87) && c <= 0x9F ) return( 8 );					// ShiftJIS 漢字
	if( (c >= 0xE0) && c <= 0xE9 ) return( 8 );					// ShiftJIS 漢字
	if( (c >= 0xED) && c <= 0xEE ) return( 8 );					// ShiftJIS 漢字
	if( (c >= 0xA1) && c <= 0xDF ) return( 0x10 );				// ShiftJIS 半角カナ
	return( 0x20 );												// その他
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
// 【機能】1byteのﾊﾞｲﾅﾘを2桁のBCDに変換
// 【入力】ﾊﾞｲﾅﾘﾃﾞｰﾀ,書き込みﾊﾞｯﾌｧ
// 【出力】なし
// 【備考】
// ====================================================================
//
void obj_bcd2( int obj_data, char *wr_buf )
{
	wr_buf[1] = hex_map[obj_data % 10];
	obj_data /= 10;
	wr_buf[0] = hex_map[obj_data % 10];
}
// ---------------------------------------------------------
//	debug用 t_type文字を得る
//	ﾒｯｾｰｼﾞは10文字固定にする
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
		if( t_type ) sprintf( d_buf, "[%08x]", t_type );	// 10文字固定
		else strcpy( d_buf, "[       0]" );					// 0
	}
}
// ------------------------------------------------------------------
// buffer内の文字列の切り出し
// mode 0: cur_moji_type <- tmp_moji_type
// mode 1: tmp_moji_type 使用
// max 長さは100文字まで
// return s_bufの次の位置
// ------------------------------------------------------------------
int get_tok1( int mode, char *d_buf, char *s_buf, int *tok_len )
{
	int		src_cnt, put_cnt, max_len, loop_type, len, flag, k_cnt, n;
	char	moji;

	k_cnt = 0;
	*tok_len = 0;
	put_cnt = 0;
	max_len = CHAR_SIZE - 3;

	src_cnt = pass_space( s_buf ); // ﾊﾟｽ ｽﾍﾟｰｽ,TAB
	flag = 0;
	while( (moji = s_buf[src_cnt]) != 0 )
	{
		if( flag == 0 )
		{ // 初回
			flag = 1;
			if( moji == 0x22 || moji == 0x27 ) break;
			if( _isdigit(moji) ) break;
			if( moji_check(moji) == 8 && s_buf[src_cnt + 1] ) break; // 漢字
			if( _isalpha(moji) || moji == '_' || moji == '#' )
			{ // 文字列
				d_buf[put_cnt++] = moji;
				src_cnt++;
				flag = 2; // 文字列
			}
			else { // その他
				d_buf[put_cnt++] = moji;
				src_cnt++;
			}
		}
		else if( flag == 1 )
		{ // 通常
			if( moji == _SOH || moji == ' ' ) break;
			else {
				d_buf[put_cnt++] = moji;
				src_cnt++;
				if( put_cnt == 2 )
				{
					if( d_buf[0] == '/' || d_buf[1] == '*' ) break;
					if( d_buf[0] == '*' || d_buf[1] == '/' ) break;
				}
				if( moji_check(moji) == 8 && s_buf[src_cnt + 1] ) break;	// 漢字
				if( put_cnt > 8 ) break;									// 予約語は,8文字が最大(unsigned)
			}
		}
		else { // 文字列
			if( moji_check(moji) == 8 )
			{
				src_cnt++; // 漢字
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
	if( flag == 1 ) flag = 0;							// 特殊(部分一致)
	else flag = 1;										// 全数一致
	tmp_moji_type = search_yoyaku( flag, d_buf, &len ); // 予約文字を探す
	if( tmp_moji_type == C_COM1 )
	{
		src_cnt = strlen( s_buf );
	}
	else if( tmp_moji_type == C_COM2 )
	{ // "/*～*/"
		src_cnt = search_end_comment( s_buf ); // "*/"を探す, return 見つけた位置(-1=なし)
		if( src_cnt >= 0 )
		{
			src_cnt += 2;
			while( (moji = s_buf[src_cnt]) != 0 )
			{ // 次のｽﾍﾟｰｽまでﾊﾟｽ
				if( moji == _SOH || moji == ' ' ) break;
				src_cnt++;
			}
		}
		else {
			src_cnt = strlen( s_buf );	// 最後までなし
			tmp_moji_type = C_COM1;		// "/* ～"(LFの前まで)
		}
	}
	else if( tmp_moji_type == C_COM3 )
	{ // "～*/"
		src_cnt = pass_space( s_buf ) + len; // ﾊﾟｽ ｽﾍﾟｰｽ,TAB
	}
	else if( tmp_moji_type )
	{ // 連続性ありの検査
		// -------------- 切り出しの最後の位置を探す ------------------
		src_cnt = pass_space( s_buf ) + len; // ﾊﾟｽ ｽﾍﾟｰｽ,TAB
		if( (tmp_moji_type & C_MASK_TYPE1) && s_buf[src_cnt] == '*' )
		{ // 続けて'*' or "**"
			while( s_buf[src_cnt] == '*' ) src_cnt++; // "*"ﾊﾟｽ
			while( (moji = s_buf[src_cnt]) != 0 )
			{ // TAB,ｽﾍﾟｰｽまで
				if( moji == _SOH || moji == ' ' ) break;
				tmp_moji_type = C_OTHER;
				src_cnt++;
			}
		}
		else if( tmp_moji_type == C_KOME || tmp_moji_type == C_W_KOME || tmp_moji_type == C_AND )
		{ // '*' or "**" or "&"の後を探す
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
	else { // 最初から探す(その他)
		tmp_moji_type = 0;
		loop_type = 0;
		src_cnt = pass_space( s_buf ); // ﾊﾟｽ ｽﾍﾟｰｽ,TAB
		while( (moji = s_buf[src_cnt]) != 0 )
		{
			if( (loop_type != C_WMOJI && loop_type != C_SMOJI) && (moji == _SOH || moji == ' ') ) break;
			switch( loop_type )
			{
			case 0: // 最初の文字
				if( moji_check(moji) == 8 && s_buf[src_cnt + 1] )
				{
					src_cnt++;				// 漢字
					loop_type = C_ILLEGAL;	// その他
				}
				else if( moji == 0x22 ) loop_type = C_WMOJI;	// """
				else if( moji == 0x27 ) loop_type = C_SMOJI;	// "'"
				else if( _isdigit(moji) ) loop_type = C_DIGIT;
				else loop_type = C_OTHER;						// その他
				tmp_moji_type = loop_type;
				break;

			case C_WMOJI: // '"'
				if( moji == _LF )
				{
					tmp_moji_type = C_ILLEGAL;	// 遺法
					loop_type = -1;				// 中止
					break;
				}
				if( moji_check(moji) == 8 && s_buf[src_cnt + 1] ) src_cnt++; // 漢字
				else if( moji == 0x5c )
				{ // '\\'
					if( s_buf[src_cnt + 1] == 'n' || s_buf[src_cnt + 1] == 'r' || s_buf[src_cnt + 1] == 't' ) src_cnt++;
					else if( (s_buf[src_cnt + 1] == _LF || s_buf[src_cnt + 1] == 0) )
					{
						tmp_moji_type = C_ILLEGAL; // 遺法
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

			case C_SMOJI: // ''' 単独文字
				if( moji == _LF )
				{
					tmp_moji_type = C_ILLEGAL;	// 遺法
					loop_type = -1;				// 中止
					break;
				}
				if( moji_check(moji) == 8 && s_buf[src_cnt + 1] ) src_cnt++; // 漢字
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

			case C_DIGIT: // 数字
				break;

			case C_OTHER: // moji
			case C_ILLEGAL:
				if( moji_check(moji) == 8 && s_buf[src_cnt + 1] )
				{
					src_cnt++; // 漢字
					if( tmp_moji_type != C_ILLEGAL ) loop_type = tmp_moji_type = C_ILLEGAL;
				}
				else if( !(_isalpha(moji) || _isdigit(moji) || moji == '_' || moji == '#' ||
					moji == '-' || moji == '>' || moji == '<' || moji == ':' ||
					moji == '.' || moji == '*' || moji == '[' || moji == ']') ) loop_type = -1; // CR,LF等
				break;

			default:
				break;
			}
			if( loop_type < 0 ) break;
			src_cnt++;
		}
		if( tmp_moji_type == 0 ) tmp_moji_type = C_OTHER; // その他
	}

	n = pass_space( s_buf ); // ﾊﾟｽ ｽﾍﾟｰｽ,TAB
	if( (src_cnt - n) > 0 )
	{
		memcpy( d_buf, &s_buf[n], src_cnt - n );	// copy comment
		d_buf[src_cnt - n] = 0;
		cut_last_space( 1, d_buf );					// 最後のTAB,spaceを削除
		*tok_len = strlen( d_buf );
	}
	else *tok_len = 0;
	if( src_cnt == 0 || *tok_len == 0 ) tmp_moji_type = 0;	// reset

	if( mode == 0 ) cur_moji_type = tmp_moji_type;			// set
	return( src_cnt );
}
// ----------------------------------------------------------------------------
// 文字列の断片の切り出し(s_bufは最後がLFなしに限る)
// ｽﾍﾟｰｽ,TAB,分離記号までの切り出し
// return s_bufの次の位置
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
	{ // cur_moji_typeは既に取り込み完了
		back_pos = pos;
		if( pos == 0 )
		{ // 最初.typeは最初のものとする
			pos = get_tok1( 0, tok_buf, s_buf, &n );
			if( cur_moji_type == 0 || cur_moji_type == C_COM1 ) break;	// ｺﾒﾝﾄ
			tmp_moji_type = cur_moji_type;								// 最初のtype
			if( tmp_moji_type == C_DIGIT || tmp_moji_type == C_PLUS || tmp_moji_type == C_MINUS )
				digit_flag = 1;											// set
		}
		else {
			pos += get_tok1( 1, tok_buf, &s_buf[pos], &n );
			if( tmp_moji_type == 0 || tmp_moji_type == C_COM1 )
			{
				pos = back_pos;
				break; // ｺﾒﾝﾄ
			}
		}
		if( digit_flag == 1 )
		{
			if( tok_buf[n - 1] == ',' ) break;
			if( tmp_moji_type == C_DIGIT || tmp_moji_type == C_PLUS || tmp_moji_type == C_MINUS )
				continue;
			else { // 数字の連続終わり
				pos = back_pos; // １つ戻す
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

	n = pass_space( s_buf ); // ﾊﾟｽ ｽﾍﾟｰｽ,TAB
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
// ｺﾒﾝﾄの手前かｺﾒﾝﾄﾌﾞﾛｯｸの切り出し(s_bufは最後がLFなしに限る)
// "//"は最後までが1ﾌﾞﾛｯｸ
// cur_moji_type: C_COM1, C_OTHER
// return s_bufの次のpos位置
// --------------------------------------------------------
int get_tok3( char *tok_buf, char *s_buf, int *tok_len )
{
	int src_cnt, back_cnt, len;

	src_cnt = get_tok1( 0, tok_buf, s_buf, tok_len );	// 区切り位置まで残り取り込み
	if( cur_moji_type == C_COM1 ) return( src_cnt );	// ｺﾒﾝﾄを取り込み
	else if( *tok_len )
	{ // ｺﾒﾝﾄ以外
		back_cnt = 0;
		do { // ｺﾒﾝﾄの前までﾊﾟｽ
			back_cnt = src_cnt; // 退避
			src_cnt += get_tok1( 1, tok_buf, &s_buf[src_cnt], tok_len ); // 区切り位置まで残り取り込み
			if( tmp_moji_type == C_COM1 )
			{ // ｺﾒﾝﾄ発見
				src_cnt = back_cnt; // 戻す
				break;
			}
		} while( *tok_len );
		len = pass_space( s_buf ); // ﾊﾟｽ ｽﾍﾟｰｽ,TAB
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
// "{～}"のコピー。ｺﾝﾏ単位で区切る
// return s_bufの次のpos位置
// cur_moji_type : C_KOMMA
// cur_moji_type : C_COM1
// cur_moji_type : C_BIG_K_L
// cur_moji_type : C_BIG_K_R
// cur_moji_type : 0
// --------------------------------------------------------
int get_tok4( char *tok_buf, char *s_buf, int *tok_len )
{
	int src_cnt, back_cnt, len, back_moji_type;

//	src_cnt = get_tok1( 0, tok_buf, s_buf, tok_len );	// 区切り位置まで残り取り込み
//	if( cur_moji_type == C_COM1 ) return( src_cnt );	// ｺﾒﾝﾄを取り込み
	src_cnt = 0;
	do { // ｺﾒﾝﾄの前までﾊﾟｽ
		back_cnt = src_cnt; // 退避
		back_moji_type = cur_moji_type;
//		src_cnt += get_tok1( 0, tok_buf, &s_buf[src_cnt], tok_len );	// 区切り位置まで残り取り込み
		src_cnt += get_tok2( tok_buf, &s_buf[src_cnt], tok_len );		// 区切り位置まで残り取り込み
		if( cur_moji_type )
		{
			if( cur_moji_type == C_BIG_K_L || cur_moji_type == C_BIG_K_R || cur_moji_type == C_COM1 )
			{ // 区切り発見
				if( back_cnt )
				{
					src_cnt = back_cnt; // 戻す
					cur_moji_type = back_moji_type;
				}
				break;
			}
			if( cur_moji_type == C_KOMMA ) break; // 区切り発見
			if( tok_buf[*tok_len - 1] == ',' ) break;
		}
	} while( *tok_len );
	len = pass_space( s_buf ); // ﾊﾟｽ ｽﾍﾟｰｽ,TAB
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
// '{'+ｺﾒﾝﾄならﾊﾟｽ
// return( next pos )
// ---------------------------------------------------------------------
int add_comment( char *s_buf )
{
	int		pos, tok_len;
	char	tok_buf[CHAR_SIZE];

	pos = get_tok1( 1, tok_buf, s_buf, &tok_len ); // 区切り位置まで残り取り込み
	if( tmp_moji_type == C_COM1 ) return( pos );
	return( 0 );
}
// ---------------------------------------------------------------------
// '{'ならﾊﾟｽ
// return( next pos )
// ---------------------------------------------------------------------
int add_b_k_l( char *s_buf )
{
	int		pos, tok_len;
	char	tok_buf[CHAR_SIZE];

	pos = get_tok1( 1, tok_buf, s_buf, &tok_len ); // 区切り位置まで残り取り込み
	if( tmp_moji_type != C_BIG_K_L ) pos = 0;

	return( pos );
}
// ---------------------------------------------------------------------
// #typedef の解析
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
		pos += get_block( 1, tok_buf, &s_buf[pos], &tok_len ); // 臨時で1 block取り込み
		if( tmp_moji_type == C_COM1 || tmp_moji_type == C_LF || tmp_moji_type == 0 ) break;
		else if( tmp_moji_type & (C_MASK_TYPE1 | C_MASK_TYPE2) )
		{
			if( s_buf[pos] == ';' && k_cnt == 0 && big_cnt == 0 && flag == 0 && target_pos == 0 )
			{
				target_pos = back_pos; // set
				break;
			}
			else continue; // 予約後はﾊﾟｽ
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

		if( s_buf[pos] != ' ' && s_buf[pos] != _SOH ) flag = 1;						// 続きはﾊﾟｽ
		else flag = 0;
	}

	return( target_pos );
}
// ---------------------------------------------------------------------
// 複数のTYPE MACROをﾊﾟｽ 未使用
// return( next pos )
// ---------------------------------------------------------------------
int add_bind_macro( char *s_buf )
{
	int		pos, tok_len;
	char	tok_buf[CHAR_SIZE];

	pos = get_tok1( 1, tok_buf, s_buf, &tok_len ); // 区切り位置まで残り取り込み
	if( tmp_moji_type == C_OTHER )
	{
		get_tok1( 1, tok_buf, &s_buf[pos], &tok_len );	// 区切り位置まで残り取り込み
		if( tmp_moji_type != C_OTHER ) pos = 0;			// reset
	}
	else pos = 0;

	return( pos );
}
// ---------------------------------------------------------------------
// type 以外かの検査
// return 0:無効, 1:有効
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
	return( 1 ); // 有効
}
// ---------------------------------------------------------------------
// 複数のMASK_TYPEをﾊﾟｽ 未使用
// return( next pos )
// ---------------------------------------------------------------------
int add_bind_type1( char *s_buf )
{
	int		pos, back_pos, before_back_pos, tok_len, mode;
	char	tok_buf[CHAR_SIZE], moji;

	mode = back_pos = pos = 0;
	for(;;)
	{
		before_back_pos = back_pos;								// 退避
		back_pos = pos;											// 退避
//		pos += get_tok1( 1, tok_buf, &s_buf[pos], &tok_len );	// 区切り位置まで残り取り込み
		pos += get_block( 1, tok_buf, &s_buf[pos], &tok_len );	// 区切り位置まで残り取り込み
		if( tok_len == 0 ) break;
//		if( tmp_moji_type & (C_MASK_TYPE1 | C_MASK_TYPE2) ) continue;
		if( tmp_moji_type & C_MASK_TYPE1 )
		{
			mode = 1; // 続きあり
		}
		else if( tmp_moji_type & C_MASK_TYPE2 )
		{
			if( mode == 0 ) mode = 2; // 続きあり
		}
		else if( tmp_moji_type == C_STRUCT || tmp_moji_type == C_UNION )
		{ // ここまで含む
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
		{ // 2つ前
			back_pos = before_back_pos;
			break;
		}
		if( tmp_moji_type != C_OTHER )
		{ // 1つ前
			if( mode == 2 ) break;	// 更新
			else pos = back_pos;	// 戻す
			break;
		}
//		else {
//			back_pos = pos;
//			break;
//		}
	}
	pos = back_pos; // 変更

	return( pos );
}
// ---------------------------------------------------------------------
// 複数の予約語を1つにする
// 行の最初から調べること
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
	back_cur_moji_type = cur_moji_type; // 退避
	before_back_pos = back_pos = pos = 0;
	yuko_pos = 0;
	pos = 0;
	for(;;)
	{
		before_back_pos = back_pos;
		back_pos = pos;											// 退避
//		pos += get_tok1( 0, tok_buf, &s_buf[pos], &tok_len );	// 区切り位置まで残り取り込み
		pos += get_tok2( tok_buf, &s_buf[pos], &tok_len );		// 次を取り込み
		if( tok_len == 0 || cur_moji_type == C_COM1 || cur_moji_type == C_COM2 )
		{
			pos = before_back_pos; // 戻す
			break;
		}
		else if( cur_moji_type == C_STRUCT || cur_moji_type == C_UNION ) break;
		if( cur_moji_type & C_MASK_TYPE1 ) yuko_pos = pos; // 続きあり
		else if( cur_moji_type & C_MASK_TYPE2 )
		{
			if( yuko_pos == 0 ) yuko_pos = pos; // 続きあり
		}
		if( tmp_moji_type == C_IQUAL )
		{ // 2つ前
			pos = before_back_pos;
			break;
		}
		else if( tmp_moji_type == C_K_R )
		{ // 無効
			pos = yuko_pos;
//			pos = back_pos; // 戻す
			break;
		}
		else if( chk_type(tok_buf) == 0 )
		{
			pos = back_pos; // 戻す
			break;
		}
//		if( cur_moji_type != C_OTHER )
//		{
//			if( mode == 2 ) break;	// 更新
//			else pos = back_pos;	// 戻す
//			break;
//		}
//		else {
//			pos = back_pos; // 戻す
//			break;
//		}
	}
	cur_moji_type = back_cur_moji_type; // 戻す

	return( pos );
}
// ---------------------------------------------------------------------
// #define の2番目の定数を得る
// s_buf mesage
// tok_len 定数の区切りの長さ
// return ｽﾍﾟｰｽを含んだ区切りの長さ
// ---------------------------------------------------------------------
int get_define_no2( char *tok_buf, char *s_buf, int *tok_len )
{
	int k_cnt, mode, pos, back_pos;
	int back_cur_moji_type, len;

	pos = get_tok1( 0, tok_buf, s_buf, tok_len );
	if( cur_moji_type == 0 ) return( pos );
	if( cur_moji_type == C_COM1 ) return( pos );
	if( cur_moji_type == C_COM2 ) return( pos ); // "/*～*/"

	back_cur_moji_type = 0;
	mode = 0;
	k_cnt = 0;
	pos = 0;
	for(;;)
	{
		back_pos = pos;
		pos += get_tok2( tok_buf, &s_buf[pos], &len );	// 次を取り込み
		if( len == 0 ) break;							// 無
		if( back_cur_moji_type == 0 ) back_cur_moji_type = cur_moji_type;
//		if( cur_moji_type == C_YEN ) continue;
		if( cur_moji_type == C_COM1 )
		{ // 手前
			pos = back_pos;
			break;
		}
		if( mode == 0 )
		{ // first
			if( cur_moji_type == C_COM2 ) mode = 1; // "/*～*/"
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
				back_pos = pos;										// 戻す
				pos += get_tok1( 1, tok_buf, &s_buf[pos], &len );	// 次を取り込み
				if( tmp_moji_type != C_YEN )
				{
					pos = back_pos; // 戻す
					break;			// 1回目
				}
			}
		}
	}
	cur_moji_type = back_cur_moji_type;
	if( pos )
	{
		memcpy( tok_buf, s_buf, pos );
		tok_buf[pos] = 0;
		len = pass_space( tok_buf );		// ﾊﾟｽ ｽﾍﾟｰｽ,TAB
		strcpy( tok_buf, &tok_buf[len] );	// shift
		cut_last_space( 1, tok_buf );		// 最後のTAB,spaceを削除
		len = strlen( tok_buf );
	}
	else len = 0;

	*tok_len = len;
	return( pos );
}
// ---------------------------------------------------------------------
// s_bufのｽﾍﾟｰｽ 1個追加
// ---------------------------------------------------------------------
int add_space_one( int end_pos, char *s_buf )
{
	s_buf[end_pos++] = ' ';
	s_buf[end_pos] = 0;
	return( end_pos );
}
// ---------------------------------------------------------------------
// TAB計算 実位置
// 最低1つはｽﾍﾟｰｽ追加
// return : 次のend_pos
// ---------------------------------------------------------------------
int arrange_tab_soh( int target_pos, int buf_end_pos, char *s_buf )
{
	int pos;

	if( target_pos <= buf_end_pos ) s_buf[buf_end_pos++] = ' ';
	else {
		pos = ( target_pos / 4 ) * 4; // TABの基本位置
		if( (pos - buf_end_pos) > 1 )
		{
			while( buf_end_pos < pos )
			{ // TABで補う
				s_buf[buf_end_pos++] = _SOH;
				if( buf_end_pos >= (CHAR_SIZE - 5) )
				{
					err_trap_line( 2, -36, 0 ); // "1行が長すぎる"
				}
			}
		}
		while( buf_end_pos < target_pos )
		{ // 残り端数をｽﾍﾟｰｽで埋める
			s_buf[buf_end_pos++] = ' ';
			if( buf_end_pos >= (CHAR_SIZE - 5) )
			{
				err_trap_line( 2, -36, 0 ); // "1行が長すぎる"
			}
		}
	}
	s_buf[buf_end_pos] = 0;

	return( buf_end_pos );
}
// ---------------------------------------------------------------------
// tab_posを展開する
// mode = 0:"//"を追加しない
// mode = 1:"//"+TAB(' ') を追加する
// mode = 2:TAB+ "//" を追加する
// mode = 3:"//"+' ' TABは無視
// ---------------------------------------------------------------------
void open_tab_pos( int mode, int tmp_line )
{
	struct	FDATA *fdata_p;
	int		target_pos, end_pos;

	fdata_p = &ope_buf[tmp_line];

	end_pos = strlen( fdata_p->pri_comment );
	if( mode == 1 || mode == 3 )
	{ // 最初にTAB, TAB無視 ｽﾍﾟｰｽのみ
		if( end_pos ) fdata_p->pri_comment[end_pos++] = ' ';
		fdata_p->pri_comment[end_pos++] = '/';
		fdata_p->pri_comment[end_pos++] = '/';
		if( mode == 3 ) fdata_p->tab_pos = 0;
	}
	fdata_p->pri_comment[end_pos] = 0;

	// ---------ｽﾍﾟｰｽを入れる ---------------
	target_pos = fdata_p->tab_pos * 4;
	if( (target_pos - end_pos) > 0 ) end_pos = arrange_tab_soh( target_pos, end_pos, fdata_p->pri_comment );

	if( mode == 2 )
	{ // 後にTAB
		if( end_pos && fdata_p->pri_comment[end_pos - 1] != _SOH && fdata_p->pri_comment[end_pos - 1] != ' ' ) fdata_p->pri_comment[end_pos++] = ' ';
		fdata_p->pri_comment[end_pos++] = '/';
		fdata_p->pri_comment[end_pos++] = '/';
	}
	fdata_p->pri_comment[end_pos] = 0;
}
// ---------------------------------------------------------------------
// pri_comment, tab_posを展開する
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
	{ // 原文のまま
		open_tab_pos( 0, tmp_line );
	}
	else if( fdata_p->hojo_flag & (H_MES11 | H_MES14) )
	{ // "//"+TAB(' ')+program
		open_tab_pos( 1, tmp_line );
	}
	else if( fdata_p->hojo_flag & H_MES15 )
	{ // TAB+"//"+comments, programの後のｺﾒﾝﾄに合わせる
		open_tab_pos( 2, tmp_line );
	}
	else if( fdata_p->hojo_flag & H_MES16 )
	{ // "//"+' '+message TABは無視
		open_tab_pos( 3, tmp_line );
	}
	else { // 行頭に"//"追加なし
		open_tab_pos( 0, tmp_line );
	}
}
// ---------------------------------------------------------------------
// if(), for(), while()が１行で終わるかの検査
// return 0:１行で終わらない, 1:1行で終わる
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
		pos += get_block( 1, tok_buf, &s_buf[pos], &len );	// 次を取り込み
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
// TAB補正の必要性を確認
// return 0:無効
// ---------------------------------------------------------------------
int chk_tab_enable( int now_line )
{
	int		line_type;
	struct	FDATA *fdata_p;

	fdata_p = &ope_buf[now_line];
	line_type = fdata_p->line_type;

	if( line_type == T_ASM ) return( G_ASM );				// 有効

	if( line_type == T_DEFINE ) return( G_DEFINE );			// 有効
	if( line_type == T_TYPEDEF ) return( G_TYPEDEF );		// 有効
	if( line_type == T_DEF_OTHER ) return( G_DEF_OTHER );	// 有効

	if( line_type == T_TYPE || line_type == T_OTHER_TYPE )
	{
		if( fdata_p->hojo_flag & H_B_K_PAIR ) return( G_TYPE2 );	// 有効
		else return( G_TYPE1 );										// 有効
	}

//	if( line_type == T_EXTERN ) return( G_EXTERN ); // 有効

	if( line_type == T_PROC ) return( G_PROC );		// 有効

	if( line_type == T_STRUCT || line_type == T_UNION )
	{
		if( fdata_p->hojo_flag & H_B_K_PAIR ) return( G_STRUCT2 );	// 有効
		else return( G_STRUCT1 );									// 有効
	}

	if( line_type == T_INCLUDE ) return( G_INCLUDE );	// 有効

	if( line_type & T_MASK_IN ) return( G_TYPE_IN );	// 有効

	if( line_type == T_DIGIT ) return( G_DIGIT );		// 有効
	if( line_type == T_MOJIS ) return( G_MOJIS );		// 有効

	if( line_type == T_B_K_PAIR ) return( G_B_K_PAIR ); // 有効

	if( line_type == T_CASE ) return( G_CASE );			// 有効

	if( line_type == T_OTHER ) return( G_OTHER );		// 有効
	if( line_type == T_CALL ) return( G_OTHER );		// 有効
	if( line_type == T_RETURN ) return( G_OTHER );		// 有効
	if( (line_type == T_WHILE || line_type == T_FOR) && chk_loop_end(fdata_p->mes) ) return( G_OTHER ); // 有効

	if( line_type == T_IF ) return( G_IF );			// 有効
	if( line_type == T_ELSE ) return( G_IF );		// 有効
	if( line_type == T_ELSE_BIG ) return( G_IF );	// 有効
	if( line_type == T_ELSE_IF ) return( G_IF );	// 有効

	return( 0 );									// 無効
}
// ---------------------------------------------------------------------
// MES15の次が同じかの検査
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
			if( ++cnt > 2 ) break; // 2行までOK
			continue;
		}
		if( base_type == chk_tab_enable(line) )
		{
			*line_no = line;	// set new
			return( 1 );		// 有効
		}
		else break;
	}
	return( 0 ); // 無効
}
// ---------------------------------------------------------
// ｿｰｽ文字の一致しない位置を探す
// ｺﾒﾝﾄの場合は0を返す
// end_pos : ｱﾚﾝｼﾞ後のbufferの位置
// *s_buf : 元のｿｰｽ
// *t_buf : ｱﾚﾝｼﾞ後のbuffer
// return : ｿｰｽの位置
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
		{ // TAB,ｽﾍﾟｰｽ ﾊﾟｽ
			while( s_buf[pos] == _SOH || s_buf[pos] == ' ' ) pos++; // TAB,ｽﾍﾟｰｽ ﾊﾟｽ
			pos++;
		}
		if( ++n >= end_pos ) break;
	}
//	while( s_buf[pos] == _SOH || s_buf[pos] == ' ' ) pos++; // TAB,ｽﾍﾟｰｽ ﾊﾟｽ

	return( pos );
}
// ---------------------------------------------------------------------
// comment前のTAB位置を合わせる
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

		if( fdata_p->line_type == T_CRLF ) continue; // 改行のみはﾊﾟｽ
		if( fdata_p->line_type & T_MASK_MES ) continue;
		if( fdata_p->line_type == T_COM_MES ) continue;
		if( (fdata_p->status[teigi_no] & ST_COM) && form_comment_prog == 0 ) continue;

#ifdef _DEBUG
		if( tmp_line >= 4150 && teigi_no >= 1 )
		{
			debug_n = tmp_line;
		}
#endif
		end_pos = fdata_p->top_pos[teigi_no] + fdata_p->block_len[teigi_no];	// last位置
		top_pos = end_pos + pass_space( &fdata_p->mes[end_pos] );				// 次のtop
		if( end_pos && fdata_p->mes[top_pos] )
		{
//			get_tok1( 1, tok_buf, &fdata_p->mes[top_pos], &tok_len );
//			get_tok2( tok_buf, &fdata_p->mes[top_pos], &tok_len );										// 区切り位置まで残り取り込み
			pos = max_pos;
			if( fdata_p->status[teigi_no] & (ST_PAIR_L | ST_PAIR_IN) ) pos = 1;							// ｽﾍﾟｰｽのみ有効
			else if( (fdata_p->status[teigi_no] & ST_TAB) == 0 ) pos = 1;								// ｽﾍﾟｰｽのみ有効
//			else {
//				if( (base_type & (G_DEFINE | G_DEF_OTHER | G_TYPEDEF)) == 0 && teigi_no >= 2 ) pos = 1; // ｽﾍﾟｰｽ
//				if( teigi_no == 1 )
//				{
//					if( bunpu_cnt <= 1 && (base_type & (G_DEFINE | G_DEF_OTHER | G_TYPEDEF)) == 0 &&
//						fdata_p->tab_pos == 0 && bunpu_cnt <= 1 && teigi_no == 1 ) pos = 1; // ｽﾍﾟｰｽ
//				}
//				else if( base_type != G_DEFINE && bunpu_cnt <= 1 ) pos = 1; // ｽﾍﾟｰｽ
//			}
			memcpy( buf, fdata_p->mes, end_pos );
			buf[end_pos] = 0;

			end_pos = arrange_tab_soh( pos, end_pos, buf );
			if( (teigi_no + 1) < MAX_TEIGI_NO )
			{
//				end_pos += pass_space( &fdata_p->mes[end_pos] );	// 次のtop
				fdata_p->top_pos[teigi_no + 1] = end_pos;			// new set
				if( fdata_p->status[teigi_no] & (ST_PAIR_L | ST_PAIR_IN) )
					fdata_p->status[teigi_no + 1] |= ST_PAIR_IN;	// "{～}"の開始位置
			}
			strcat( buf, &fdata_p->mes[top_pos] );	// 残りcopy
			strcpy( fdata_p->mes, buf );			// 戻す
			last_teigi_no = teigi_no;				// 続行
		}
		else if( (teigi_no + 1) < MAX_TEIGI_NO )
		{
			fdata_p->top_pos[teigi_no + 1] = 0;		// なし
			fdata_p->block_len[teigi_no + 1] = 0;	// なし
			fdata_p->status[teigi_no + 1] = 0;		// なし
		}
	}
	return( last_teigi_no );
}
// ---------------------------------------------------------------------
// ｺﾒﾝﾄの処理
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
	// ---------------- ｺﾒﾝﾄ の処理 -----------------
	if( base_type & (G_DEFINE | G_DEF_OTHER | G_TYPEDEF) )
		comment_mode = form_define_com_tab; // #define のｺﾒﾝﾄのTAB位置 0:なにもしない, 1:TABなし(ｽﾍﾟｰｽのみ), 2:自動でTAB作成
	else {
		comment_mode = form_other_com_tab;	// その他 0:何もしない, 1:TABなし(ｽﾍﾟｰｽのみ), 2:最大TAB制限なし
//		if( (base_type == G_CASE || base_type == G_DEFIF) && comment_mode == 2 ) comment_mode = 30; // max TAB = 30
		if( base_type == G_CASE && comment_mode == 2 ) comment_mode = 30;							// max TAB = 30
	}
	if( comment_mode == 0 ) return;
	// ---------- ｺﾒﾝﾄの最大/最小値ﾋﾟｰｸ値を求める -------------
	comment_cnt = 0; // 分布
	least_pos = max_pos = 0;
	total = averrage = 0;
	no_com_cnt = -1; // 最初のｺﾒﾝﾄ文を探す
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
		{ // ｺﾒﾝﾄなし
			if( base_type != G_DEFINE && no_com_cnt >= 10 )
			{ // 10行以上のｺﾒﾝﾄなし
				line_last = tmp_line + 1;
				break; // 一旦ここでまとめる
			}
			continue;
		}
		if( no_com_cnt < 0 ) line_top = tmp_line; // ｺﾒﾝﾄの最初

		end_pos = fdata_p->top_pos[com_teigi_no - 1] + fdata_p->block_len[com_teigi_no - 1];

		// ｺﾒﾝﾄのTAB位置 0:何もしない, 1:TABなし(ｽﾍﾟｰｽのみ), 2:自動でTAB作成, 3～:最大TAB位置
		if( comment_mode > 1 )
		{ // 判定
//			if( (end_pos > 0 && end_pos < MAX_END_MAP) && (fdata_p->status[com_teigi_no] & ST_TAB) )
			if( end_pos > 0 && end_pos < MAX_END_MAP )
			{
//				if( end_pos )
				n = ( (end_pos + 4) / 4 ) * 4; // 実pos位置の計算.TAB最小=1
//				else n = 0;
				if( comment_mode >= 3 && n > (comment_mode * 4) )
				{ // 0:何もしない, 1:TABなし(ｽﾍﾟｰｽのみ), 2:自動でTAB作成, 3～:最大位置
					fdata_p->status[com_teigi_no] &= ~( ST_TAB );	// 指定最大値を超えたらｽﾍﾟｰｽのみ
//					n = 0;											// TABなし
				}
//				else if( fdata_p->line_type == T_DEFIF || fdata_p->line_type == T_DEF_OTHER )
				else if( fdata_p->line_type == T_DEFIF )
					fdata_p->status[com_teigi_no] &= ~( ST_TAB );	// ｽﾍﾟｰｽのみ
				else if( fdata_p->line_type != T_STRUCT_IN && fdata_p->line_type != T_UNION_IN &&
					((fdata_p->hojo_flag & (H_BIG_K_L | H_BIG_K_R)) == H_BIG_K_L ||
					(fdata_p->hojo_flag & (H_BIG_K_L | H_BIG_K_R)) == H_BIG_K_R) )
					fdata_p->status[com_teigi_no] &= ~( ST_TAB );	// ｽﾍﾟｰｽのみ
				else {
					if( ++comment_cnt == 1 ) total = averrage = n;	// 初回
					else {
						if( base_type & (G_DEFINE | G_DEF_OTHER | G_TYPEDEF) )
						{
							if( abs(averrage - n) > 40 )
							{ // 今までの行の判定
								line_last = tmp_line;
								break; // 一旦ここでまとめる
							}
						}
						else {
							if( abs(averrage - n) > 40 )
							{ // 今までの行の判定
								line_last = tmp_line;
								break; // 一旦ここでまとめる
							}
						}
						total += n;
						averrage = total / comment_cnt;
					}
					if( least_pos == 0 ) least_pos = end_pos;			// 最初
					else if( least_pos > end_pos ) least_pos = end_pos; // 小さい位置をｾｯﾄ
					if( max_pos < end_pos ) max_pos = end_pos;			// 大きい位置をｾｯﾄ
					fdata_p->status[com_teigi_no] |= ST_TAB;			// TAB有効
				}
			}
		}
		else { // 1:TABなし(ｽﾍﾟｰｽのみ)
			fdata_p->status[com_teigi_no] &= ~( ST_TAB ); // set space
		}
		no_com_cnt = 0; // reset
	}

	// ----------------- TABが１個の場合は全てｽﾍﾟｰｽとする ------------------
	if( base_type != G_DEFINE && least_pos == max_pos )
	{
//		if( (line_last - line_top) >= 5 || comment_mode >= 3 ) max_pos = 0; // ｽﾍﾟｰｽのみ
		max_pos = 0; // ｽﾍﾟｰｽのみ
	}
	else max_pos = ( (max_pos + 4) / 4 ) * 4; // 実pos位置の計算
	// ----------------- ｺﾒﾝﾄにTAB,ｽﾍﾟｰｽを決める ------------------
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

		if( fdata_p->line_type == T_CRLF ) continue; // 改行のみはﾊﾟｽ
		if( fdata_p->line_type & T_MASK_MES ) continue;
		com_teigi_no = fdata_p->com_teigi_no;
		if( com_teigi_no == 0 ) continue;

		top_pos = fdata_p->top_pos[com_teigi_no];
		end_pos = fdata_p->top_pos[com_teigi_no - 1] + fdata_p->block_len[com_teigi_no - 1];

		if( form_limit_line && (max_pos + fdata_p->block_len[com_teigi_no]) > (form_limit_line * 4) )
		{
			fdata_p->status[com_teigi_no] &= ~( ST_TAB ); // TAB無効
		}
		if( fdata_p->line_type == T_COM_MES && line_same_com_pos > 0 )
		{ // commentのみで、前行に合わせる
			pos = line_same_com_pos;					// 1つ前の位置
			end_pos = 0;
			fdata_p->status[com_teigi_no] |= ST_TAB;	// TAB有効.必要
		}
		else pos = max_pos;

		// 実際のTABを決める
		if( end_pos ) memcpy( buf, fdata_p->mes, end_pos );				// ｺﾒﾝﾄの前までをｺﾋﾟｰ
		if( (fdata_p->status[com_teigi_no] & ST_TAB) == 0 ) pos = 1;	// ｽﾍﾟｰｽのみ有効
		end_pos = arrange_tab_soh( pos, end_pos, buf );
		line_same_com_pos = end_pos;

		if( end_pos )
		{
			strcat( buf, &fdata_p->mes[top_pos] );		// 残りcopy
			fdata_p->top_pos[com_teigi_no] = end_pos;	// set new
			strcpy( fdata_p->mes, buf );				// 戻す
		}
	}

	*line_start = line_last;
}
// ---------------------------------------------------------------------
// '{'～'}'の定数の最大値を調べる
// mode = 0:'{'のみ, =1:'{'の次から
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
	{ // '{'から揃える為teigi_no = 0 から
		// ------ 最大値を検査 -------------
		flag = 0;
		for( tmp_line = line_start; tmp_line < line_last; tmp_line++ )
		{ // 最大end_pos計算
			fdata_p = &ope_buf[tmp_line];
			if( fdata_p->pair_teigi_top == 0 ) continue;

			teigi_no = fdata_p->pair_teigi_top + teigi_ofset;	// mode = 0:'{' から, =1:その次から
			if( teigi_no >= MAX_TEIGI_NO ) continue;
			if( teigi_no > fdata_p->pair_teigi_end ) continue;	// '}' まで

			flag++;
			if( fdata_p->status[teigi_no] & (ST_SPACE | ST_TAB) )
			{
				len = fdata_p->block_len[teigi_no - 1];
				if( len )
				{
					if( pos_map[teigi_ofset] == 0 ) pos_map[teigi_ofset] = len;			// 初期ｾｯﾄ
					else if( pos_map[teigi_ofset] < len ) pos_map[teigi_ofset] = len;	// 最小長さをｾｯﾄ
				}
			}
		}
		if( flag == 0 || mode == 0 ) break;
	}
}
// ---------------------------------------------------------------------
// '{'～'}'の実際のTAB位置を計算
// mode = 0:'{'だけあわせる, 1:'{'以後をあわせる
// ret= 0:正常 , 1:1行over
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
	chk_const_pos( mode, line_start, line_last ); // 定数の最大値を調べる
	if( mode == 0 ) total_pos[0] = 0;
	else memset( &total_pos[1], 0, sizeof(total_pos) - sizeof(int) );

	for( teigi_ofset = mode; teigi_ofset < MAX_TEIGI_NO; teigi_ofset++ )
	{ // '{'から揃える為teigi_no = 0 から
		// ------ 最大値を検査 -------------
		cnt = 0;
		end_pos = 0;
		for( tmp_line = line_start; tmp_line < line_last; tmp_line++ )
		{ // 最大end_pos計算
			fdata_p = &ope_buf[tmp_line];
			if( fdata_p->pair_teigi_top == 0 ) continue;

			teigi_no = fdata_p->pair_teigi_top + teigi_ofset;	// mode = 0:'{' から, = 1:次から
			if( teigi_no >= MAX_TEIGI_NO ) continue;
			if( teigi_no > fdata_p->pair_teigi_end ) continue;	// '}' まで

			cnt++;
			if( teigi_ofset == 0 )
			{
				end_pos = fdata_p->top_pos[teigi_no - 1] + pos_map[teigi_ofset];
//				if( end_pos == 0 ) end_pos = 3; // '{'がtop位置の場合の補正
			}
			else end_pos = total_pos[teigi_ofset - 1] + pos_map[teigi_ofset];

			if( fdata_p->status[teigi_no] & ST_TAB )
			{ // form_big_kakko_pair : '{'～'}'の処理 0:ｽﾍﾟｰｽのみ, 1:左側に揃える(最小TAB=1), 2:自動でTAB作成(ｽﾍﾟｰｽ+TABで合わせる)
				if( form_big_kakko_pair == 0 ) end_pos++;									// ｽﾍﾟｰｽのみ
				else if( form_big_kakko_pair == 1 ) end_pos = ( (end_pos + 4) / 4 ) * 4;	// mode = 0,TABで合わせる
				else end_pos++; // ｽﾍﾟｰｽのみ form_big_kakko_pair = 3

				if( form_limit_line && end_pos > (form_limit_line * 4) )
				{
					for( n = fdata_p->pair_teigi_top + 1; n < MAX_TEIGI_NO; n++ )
					{ // '{' の次から
						if( fdata_p->status[n] ) fdata_p->status[n] &= ~( ST_TAB ); // reset
						else break;
					}
					return( 1 ); // over
				}
			}
			else end_pos++;																// ｽﾍﾟｰｽ1個分

			if( end_pos < 4 ) end_pos = fdata_p->top_pos[teigi_no];						// 補正
			if( end_pos < 4 ) end_pos = 4;
			if( total_pos[teigi_ofset] < end_pos ) total_pos[teigi_ofset] = end_pos;	// 大きい位置をｾｯﾄ
		}
		if( cnt == 0 || mode == 0 ) break;
	}
	return( 0 );
}
// ---------------------------------------------------------------------
// "{～}"の処理 同じ定数の数
// mode = 0:'{'だけあわせる, 1:'{'以後をあわせる
// ---------------------------------------------------------------------
void pair_kakko_parts( int mode, int line_start, int line_last )
{
	struct	FDATA *fdata_p;
	int		teigi_no, tmp_line, len;
	int		top_pos, end_pos, max_pos;
	int		teigi_ofset;
	char	buf[CHAR_SIZE];

	while( chk_teigi_tab_max(mode, line_start, line_last) ); // TAB有効な縦の最大値を調べる

	// ----------- "{}"間はTAB有効, '{'～ TAB,ｽﾍﾟｰｽで揃える ---------------
	for( teigi_ofset = mode; teigi_ofset < MAX_TEIGI_NO; teigi_ofset++ )
	{ // '{'から揃える為pair_teigi_top から
		// ------ 揃える -------------
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
			if( teigi_no > fdata_p->pair_teigi_end ) continue; // '}'はﾊﾟｽ
			if( fdata_p->pair_teigi_top == 0 ) continue;
			if( fdata_p->line_type == T_CALL || fdata_p->line_type == T_PROC ) continue;

			if( fdata_p->status[teigi_no] & (ST_SPACE | ST_TAB) )
			{ // TAB、ｽﾍﾟｰｽ有効
				max_pos = total_pos[teigi_ofset];

				end_pos = fdata_p->top_pos[teigi_no - 1] + fdata_p->block_len[teigi_no - 1];	// mes pos.
				memcpy( buf, fdata_p->mes, end_pos );
				buf[end_pos] = 0;

				end_pos = arrange_tab_soh( max_pos, end_pos, buf );								// TAB調整

				top_pos = fdata_p->top_pos[teigi_no];
				strcpy( &buf[end_pos], &fdata_p->mes[top_pos] );								// 残りcopy
				strcpy( fdata_p->mes, buf );													// 戻す
				len = end_pos - top_pos;

				while( teigi_no < MAX_TEIGI_NO )
				{
					top_pos = fdata_p->top_pos[teigi_no];
					if( top_pos == 0 && teigi_no >= 2 ) break; // 次がない
					fdata_p->top_pos[teigi_no] += len;
					teigi_no++;
				}
			}
		}
		if( mode == 0 ) break;
	}
}
// ---------------------------------------------------------------------
// "{～}"の処理
// 途中で長すぎる場合があるので検査のみのﾓｰﾄﾞを設ける
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

	// ---------------- 最大長さを調べる -------------
	cnt = 0;
	for( tmp_line = line_start; tmp_line < line_last; tmp_line++ )
	{
		fdata_p = &ope_buf[tmp_line];
		if( fdata_p->pair_teigi_top == 0 ) continue;

		if( cnt == 0 ) cnt = fdata_p->pair_teigi_end - fdata_p->pair_teigi_top; // len
		else if( (fdata_p->pair_teigi_end - fdata_p->pair_teigi_top) != cnt )
		{ // 定数の数違い
			pair_kakko_parts( 1, line_start, tmp_line );
			line_start = tmp_line;										// set new
			cnt = fdata_p->pair_teigi_end - fdata_p->pair_teigi_top;	// len
		}
	}
	if( line_start < line_last ) pair_kakko_parts( 1, line_start, line_last );
}
// ---------------------------------------------------------------------
// teigi_no = 0:ｺﾒﾝﾄ補助 + tab_pos の処理
// ---------------------------------------------------------------------
void teigi_zero_syori( int line_start, int line_last )
{
	struct	FDATA *fdata_p;
	int		tmp_line, end_pos, max_pos;
	char	buf[CHAR_SIZE];

	for( tmp_line = line_start; tmp_line < line_last; tmp_line++ )
	{
		fdata_p = &ope_buf[tmp_line];
		if( fdata_p->line_type == T_CRLF ) continue; // 改行のみはﾊﾟｽ
		if( fdata_p->line_type & T_MASK_MES ) continue;

#ifdef _DEBUG
		if( tmp_line >= 22 )
		{
			debug_n = 0;
		}
#endif

		max_pos = fdata_p->tab_pos * 4;
		cut_last_space( 1, fdata_p->pri_comment ); // 最後のTAB,spaceを削除
		end_pos = strlen( fdata_p->pri_comment );
		fdata_p->block_len[0] = end_pos;
		if( end_pos == 0 )
		{ // なし
			fdata_p->status[0] = ST_SPACE;
		}
		else {
			memcpy( buf, fdata_p->pri_comment, end_pos ); // topｺﾒﾝﾄをcopy
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
			strcpy( &buf[end_pos], fdata_p->mes );	// 本文をcopy
			strcpy( fdata_p->mes, buf );			// 本文を戻す
		}
//		fdata_p->story_last_pos = end_pos;	// 本文の最後をｾｯﾄ(徐々に更新する)
		fdata_p->top_pos[1] = end_pos;		// 次のtop
		fdata_p->block_len[1] = 0;
		fdata_p->pair_teigi_top = 0;
		fdata_p->pri_comment[0] = 0;		// clear
	}
}
// ---------------------------------------------------------------------
// GASM 処理
// ---------------------------------------------------------------------
void g_asm_syori( int base_type, int line_start, int line_last )
{
	struct	FDATA *fdata_p;
	int		pos, top_pos, end_pos, teigi_no, last_teigi_no, tmp_line;
	int		tok_len, max_pos, least_pos;
	int		comment_cnt;
	char	tok_buf[CHAR_SIZE];

	// ------------ 変数の最大長を計算する ---------------
	for( tmp_line = line_start; tmp_line < line_last; tmp_line++ )
	{
		fdata_p = &ope_buf[tmp_line];
		if( fdata_p->line_type == T_CRLF ) continue; // 改行のみはﾊﾟｽ

//		fdata_p->status[1] = ST_SPACE | ST_TAB;
		fdata_p->status[1] = ST_SPACE;
		fdata_p->status[2] = 0;
	}

	// ----------------- 各区切り位置を決める --------------------
	comment_cnt = 0; // 最大値
	teigi_zero_syori( line_start, line_last );
	for( teigi_no = 1; teigi_no < MAX_TEIGI_NO; teigi_no++ )
	{ // 0:offset部, 1:定義, 2:定数1, 3:定数2, ...
		last_teigi_no = 0;
		least_pos = max_pos = 0;
		memset( total_pos, 0, sizeof(total_pos) );

		for( tmp_line = line_start; tmp_line < line_last; tmp_line++ )
		{
			fdata_p = &ope_buf[tmp_line];
			if( fdata_p->line_type == T_CRLF ) continue; // 改行のみはﾊﾟｽ
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
					end_pos += get_tok3( tok_buf, &fdata_p->mes[end_pos], &tok_len );	// ﾌﾞﾛｯｸの切り出し("//"は1ﾌﾞﾛｯｸ)
				else end_pos += get_tok2( tok_buf, &fdata_p->mes[end_pos], &tok_len );	// 区切り位置まで残り取り込み

				if( tok_len )
				{
#ifdef _DEBUG
					if( tmp_line >= 127 && teigi_no >= 0 )
					{
						debug_n = fdata_p->mes[0];
					}
#endif
					fdata_p->status[teigi_no] |= ST_SPACE;									// 有効
					fdata_p->block_len[teigi_no] = end_pos - fdata_p->top_pos[teigi_no];	// 実 長さ
					if( cur_moji_type == C_COM1 || cur_moji_type == C_SEMIKOLON )
					{ // ｺﾒﾝﾄ発見。TAB禁止はここで処理する
						pos = fdata_p->top_pos[teigi_no - 1] + fdata_p->block_len[teigi_no - 1];
						fdata_p->status[teigi_no] |= ST_COM; // comment
						fdata_p->com_teigi_no = teigi_no;
						comment_cnt++;
					}
					else { // ----------------- ｿｰｽのTAB位置を調べる --------------------
						if( end_pos < MAX_END_MAP )
						{
							if( fdata_p->status[teigi_no] & ST_TAB )
							{ // 有効
								if( end_pos > max_pos ) max_pos = end_pos;			// 大きい方をset
								if( least_pos == 0 ) least_pos = end_pos;			// 初回
								else if( end_pos < least_pos ) least_pos = end_pos; // 小さい方をset
								total_pos[end_pos] += 1;
							}
						}
					}
				}
				else { // 以後なし
					fdata_p->status[teigi_no] = 0;		// なし
					fdata_p->top_pos[teigi_no] = 0;		// なし
					fdata_p->block_len[teigi_no] = 0;	// 実 長さ
				}
			}
		}

		if( teigi_no == 1 ) max_pos = ( (max_pos + 4) / 4 ) * 4; // pos位置の計算
		else max_pos = 0;
		// ----------------- TAB位置を合わせる --------------------
		if( set_tab(teigi_no, line_start, line_last, max_pos) == 0 ) break;
	}
	if( comment_cnt == 0 ) return; // ｺﾒﾝﾄなし

	// ------------ ｺﾒﾝﾄ のTABを一旦 有効にする -------------
//	for( tmp_line = line_start; tmp_line < line_last; tmp_line++ )
//	{
//		fdata_p = &ope_buf[tmp_line];
//		teigi_no = fdata_p->com_teigi_no;
//		if( teigi_no == 0 ) continue; // ｺﾒﾝﾄなし

//		if( teigi_no > 0 && teigi_no < MAX_END_MAP ) fdata_p->status[teigi_no] |= ST_TAB;	// TAB有効
//		else fdata_p->status[teigi_no] &= ~( ST_TAB );										// TAB無効
//	}
	// ------------ ｺﾒﾝﾄ の処理 TAB位置がずれる為,複数回行う -------------
	while( line_start < line_last )
	{
		comment_syori( base_type, &line_start, line_last );
	}
}
// ---------------------------------------------------------------------
// 同類の連続をTABでそろえる
// 途中で区切ったほうがよい場合は,その行を返す
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

	// ------------ 変数の最大長を計算する ---------------
	struct_cnt = 0; // structの数
	for( tmp_line = line_start; tmp_line < line_last; tmp_line++ )
	{
		fdata_p = &ope_buf[tmp_line];
		if( fdata_p->line_type == T_CRLF ) continue; // 改行のみはﾊﾟｽ

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
					struct_cnt++; // structの数
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

//		case G_ASM: // 分離した
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
	{ // 複数のstructの場合は揃える
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
	// ----------------- 各区切り位置を決める --------------------
	comment_cnt = 0;
	teigi_zero_syori( line_start, line_last );
	for( teigi_no = 1; teigi_no < MAX_TEIGI_NO; teigi_no++ )
	{ // 0:offset部, 1:定義, 2:定数1, 3:定数2, ...
		last_teigi_no = 0;
		bunpu_cnt = 0;
		end_pos = least_pos = max_pos = 0; // zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz
		memset( total_pos, 0, sizeof(total_pos) );

		for( tmp_line = line_start; tmp_line < line_last; tmp_line++ )
		{
			fdata_p = &ope_buf[tmp_line];
			if( fdata_p->line_type == T_CRLF ) continue; // 改行のみはﾊﾟｽ
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
				if( teigi_no > 4 ) fdata_p->status[teigi_no] |= fdata_p->status[4] & ( ST_SPACE | ST_TAB ); // 以後同じにする

				if( chk_tab_enable(tmp_line) == G_OTHER ) fdata_p->status[teigi_no] = ST_SPACE;				// TAB禁止

				if( fdata_p->line_type == T_DEFINE )
				{
					if( teigi_no == 1 )
						end_pos += get_tok2( tok_buf, &fdata_p->mes[end_pos], &tok_len );		// 区切り位置まで残り取り込み
					else if( teigi_no == 2 )
						end_pos += get_define_no2( tok_buf, &fdata_p->mes[end_pos], &tok_len ); // #defineの区切りを得る
//					else if( form_define_tab == 0 || teigi_no >= 3 )
					else
						end_pos += get_tok3( tok_buf, &fdata_p->mes[end_pos], &tok_len );		// ﾌﾞﾛｯｸの切り出し("//"は1ﾌﾞﾛｯｸ)
				}
				else if( fdata_p->hojo_flag & H_YEN2 )
					end_pos += get_tok3( tok_buf, &fdata_p->mes[end_pos], &tok_len ); // ﾌﾞﾛｯｸの切り出し("//"は1ﾌﾞﾛｯｸ)
				else if( fdata_p->line_type == T_DEFIF )
				{
					end_pos += get_tok2( tok_buf, &fdata_p->mes[end_pos], &tok_len ); // 区切り位置まで残り取り込み
				}
				else {
					type_back_pos = end_pos; // TYPE_MASK用
					if( fdata_p->status[teigi_no] & (ST_PAIR_R | ST_PAIR_IN) )
					{ // "{～}"のコピー。ｺﾝﾏ単位で区切る. cur_moji_type = C_KOMMA, C_COM1, C_BIG_K_L, C_BIG_K_R
						end_pos += get_tok4( tok_buf, &fdata_p->mes[end_pos], &tok_len );
					}
					else end_pos += get_tok2( tok_buf, &fdata_p->mes[end_pos], &tok_len ); // 区切り位置まで残り取り込み
					if( cur_moji_type == C_BIG_K_L )
					{
						if( fdata_p->hojo_flag & H_B_K_PAIR )
						{
							if( chk_big_kakko(&fdata_p->mes[top_pos], &pos) <= 0 )
							{
								if( fdata_p->pair_teigi_top )
								{ // 複数ある
									fdata_p->hojo_flag &= ~( H_B_K_PAIR ); // 複数のﾍﾟｱｰ括弧は,reset
									for( pos = fdata_p->pair_teigi_top; pos <= teigi_no; pos++ )
									{
										fdata_p->status[pos] &= ~( ST_PAIR_L | ST_PAIR_R | ST_PAIR_IN ); // reset "{～}"
									}
									fdata_p->pair_teigi_top = 0;
									fdata_p->big_kakko_cnt = 0;
								}
								else { // 新規登録
									fdata_p->status[teigi_no] |= ST_PAIR_L; // "{～}"の開始位置
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
						end_pos += add_comment( &fdata_p->mes[end_pos] ); // "{"+ｺﾒﾝﾄなら１つにする
					}
					else if( cur_moji_type == C_BIG_K_R )
					{
						if( (fdata_p->hojo_flag & H_B_K_PAIR) && fdata_p->pair_teigi_end == 0 )
						{
							if( --fdata_p->big_kakko_cnt == 0 )
							{ // 区切り位置
								if( (fdata_p->pair_teigi_top + 1) == teigi_no )
								{ // "{}"
									fdata_p->hojo_flag &= ~( H_B_K_PAIR ); // 複数のﾍﾟｱｰ括弧は,reset
									for( pos = fdata_p->pair_teigi_top; pos <= teigi_no; pos++ )
									{
										fdata_p->status[pos] &= ~( ST_PAIR_L | ST_PAIR_R | ST_PAIR_IN ); // reset "{～}"
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
//						end_pos += add_comment( &fdata_p->mes[end_pos] ); // "{"+ｺﾒﾝﾄなら１つにする
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
							back_end_pos = end_pos;													// 退避
							end_pos += kaiseki_typedef( &fdata_p->mes[end_pos] );					// #typedef の解析
							if( back_end_pos == end_pos ) fdata_p->status[teigi_no] &= ~( ST_TAB ); // tab 禁止
						}
						else {
							if( cur_moji_type == C_KOMMA || cur_moji_type == C_KOLON || cur_moji_type == C_WKOLON )
							{
								back_end_pos = end_pos;												// 退避
								back_cur_moji_type = cur_moji_type;									// 退避
								back_tok_len = tok_len;
								end_pos += get_tok2( tok_buf, &fdata_p->mes[end_pos], &tok_len );	// 区切り位置まで残り取り込み
								if( cur_moji_type == C_COM1 || cur_moji_type == 0 )
								{ // 戻す
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
									// ここを最後に検査。MASK_TYPEを１つにする
									type_back_pos += add_bind_type2( tmp_line, &fdata_p->mes[type_back_pos] );
									if( end_pos < type_back_pos ) end_pos = type_back_pos;
								}
							}
							else if( cur_moji_type == C_STRUCT || cur_moji_type == C_UNION )
								end_pos += add_b_k_l( &fdata_p->mes[end_pos] ); // struct/union+'{'なら１つにする
							else if( cur_moji_type & (C_MASK_TYPE1 | C_MASK_TYPE2) )
							{
								// ここを最後に検査。複数のMASK_TYPEを１つにする
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
					fdata_p->status[teigi_no] |= ST_SPACE;											// 有効
					if( fdata_p->line_type == T_DEFIF ) fdata_p->status[teigi_no] &= ~( ST_TAB );	// 禁止
					fdata_p->block_len[teigi_no] = end_pos - fdata_p->top_pos[teigi_no];			// 実 長さ
					if( cur_moji_type == C_COM1 )
					{ // ｺﾒﾝﾄ発見。TAB禁止はここで処理する
						pos = fdata_p->top_pos[teigi_no - 1] + fdata_p->block_len[teigi_no - 1];
						fdata_p->status[teigi_no] |= ST_COM; // comment
						fdata_p->com_teigi_no = teigi_no;
						comment_cnt++;
					}
					else { // ----------------- ｿｰｽのTAB位置を調べる --------------------
						if( end_pos < MAX_END_MAP )
						{
							if( (fdata_p->status[teigi_no] & (ST_PAIR_L | ST_PAIR_R | ST_PAIR_IN)) &&
								fdata_p->pair_teigi_end == 0 )
							{
								fdata_p->status[teigi_no + 1] |= ST_PAIR_IN; // 以後set
							}
							if( (fdata_p->status[teigi_no] & (ST_PAIR_R | ST_PAIR_IN)) == 0 )
							{ // --------- ﾍﾟｱｰ括弧 "{～}"内ではない ---------------------
								if( fdata_p->status[teigi_no] & ST_TAB )
								{ // 有効
									if( end_pos > max_pos ) max_pos = end_pos;			// 大きい方をset
									if( least_pos == 0 ) least_pos = end_pos;			// 初回
									else if( end_pos < least_pos ) least_pos = end_pos; // 小さい方をset
									total_pos[end_pos] += 1;
									bunpu_cnt++;
								}
							}
						}
						else fdata_p->status[teigi_no] &= ~( ST_TAB ); // TAB無効
					}
				}
				else { // 以後なし
					fdata_p->status[teigi_no] = 0;		// なし
					fdata_p->top_pos[teigi_no] = 0;		// なし
					fdata_p->block_len[teigi_no] = 0;	// 実 長さ
				}
			}
		}
//		if( teigi_no >= 2 && (base_type & (G_DEFINE | G_DEF_OTHER | G_TYPEDEF)) == 0 )
		if( (base_type & (G_DEFINE | G_DEF_OTHER | G_TYPEDEF)) == 0 )
		{
			if( bunpu_cnt == 1 || max_pos == least_pos ) max_pos = 0; // 同じ縦位置の連続 ' 'のみ
		}
		if( base_type == G_DEFINE )
		{
			max_pos = ( (max_pos + 4) / 4 ) * 4;			// 最低1TAB以上空ける
			if( (max_pos - least_pos) < 2 ) max_pos += 4;	// 最低2ｽﾍﾟｰｽ以上空ける
		}
		else if( base_type == G_DIGIT ) max_pos++;
		else max_pos = ( (max_pos + 4) / 4 ) * 4; // pos位置の計算

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
			if( form_define_tab == 1 ) max_pos = 0; // ｽﾍﾟｰｽのみ
			else if( form_define_tab >= 3 )
			{
				if( max_pos < (form_define_tab * 4) ) max_pos = form_define_tab * 4;
			}
		}
		// ----------------- TAB位置を合わせる --------------------
		if( set_tab(teigi_no, line_start, line_last, max_pos) == 0 ) break;
	}
	// --------------- '{'をそろえる -----------------------
	pair_kakko_parts( 0, line_start, line_last );

	if( base_type == G_TYPE1 || base_type == G_TYPE2 )
	{
		flag = 0;
		for( tmp_line = line_start; tmp_line < line_last; tmp_line++ )
		{
			fdata_p = &ope_buf[tmp_line];
			if( fdata_p->line_type == T_CRLF ) continue; // 改行のみはﾊﾟｽ
#ifdef _DEBUG
			if( tmp_line >= 64 )
			{
				debug_n = (int)fdata_p->mes;
			}
#endif
			if( flag == 0 )
			{ // 初回
				n = tmp_line;
				if( (fdata_p->hojo_flag & H_BIG_K_L) && fdata_p->sub_type )
				{ // typeで揃える
					sub_type = fdata_p->sub_type;
					flag = 2;
				}
				else { // ただ揃える
					sub_type = 0;
					flag = 1;
				}
			}
			else if( flag == 1 )
			{ // ただ揃える
				if( (fdata_p->hojo_flag & H_BIG_K_L) && fdata_p->sub_type )
				{ // 変化
					pair_kakko_arrange( base_type, n, tmp_line );	// "{～}"の処理
					n = tmp_line;									// set new
					sub_type = fdata_p->sub_type;
					flag = 2;
				}
			}
			else if( flag == 2 )
			{ // typeで揃える
				if( !((fdata_p->hojo_flag & H_BIG_K_L) && sub_type == fdata_p->sub_type) )
				{ // 変化あり
					pair_kakko_arrange( base_type, n, tmp_line );	// "{～}"の処理
					n = tmp_line;									// set new
					if( fdata_p->hojo_flag & H_BIG_K_L )
					{ // typeで揃える
						sub_type = fdata_p->sub_type;
						flag = 2;
					}
					else { // ただ揃える
						sub_type = 0;
						flag = 1;
					}
				}
			}
		}
		if( n < line_last ) pair_kakko_arrange( base_type, n, line_last ); // 残り処理。"{～}"の処理
	}
	else pair_kakko_arrange( base_type, line_start, line_last );	// "{～}"の処理

	if( comment_cnt == 0 ) return;									// ｺﾒﾝﾄなし

	// ------------ ｺﾒﾝﾄ のTABを一旦 有効にする -------------
//	for( tmp_line = line_start; tmp_line < line_last; tmp_line++ )
//	{
//		fdata_p = &ope_buf[tmp_line];
//		teigi_no = fdata_p->com_teigi_no;
//		if( teigi_no == 0 ) continue;					// ｺﾒﾝﾄなし

//		if( teigi_no > 0 && teigi_no < MAX_END_MAP )
//			fdata_p->status[teigi_no] |= ST_TAB;		// TAB有効
//		else fdata_p->status[teigi_no] &= ~( ST_TAB );	// TAB無効
//	}
	// ------------ ｺﾒﾝﾄ の処理 TAB位置がずれる為,複数回行う -------------
	while( line_start < line_last )
	{
		comment_syori( base_type, &line_start, line_last );
	}
}
// ---------------------------------------------------------------------
// 同類の連続をTABでそろえる
// ﾌｧｲﾙに出力
// return 0:変更なし, -1:変更箇所多すぎ, >0:変更行数
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
	fp_dst = fopen( tmp_name, "wb" ); // 削除
	if( fp_dst == NULL )
	{
		printf( "Fatal: can't open file:%s\n", new_name );
		wait_exit( 1 );
	}

	if( debug_mode )
	{
		fp_dbg = fopen( debug_name2, "wb" ); // 削除
		if( fp_dbg == NULL )
		{
			printf( "Fatal: can't open file:%s\n", debug_name2 );
			wait_exit( 1 );
		}
	}
	else fp_dbg = NULL;

	// ---------------- 前行のｺﾒﾝﾄに合わせるかの位置調整 -------------------
	com_pos = 0;
	for( line_no = 0; line_no < max_line; line_no++ )
	{
		fdata_p = &ope_buf[line_no];

		if( fdata_p->line_type == T_CRLF ) continue; // 改行のみはﾊﾟｽ

#ifdef _DEBUG
		if( line_no >= 77 )
		{
			debug_n = (int)fdata_p->mes;
		}
#endif
		open_tab_mes( line_no ); // pri_comment, tab_posを展開する
		if( (fdata_p->line_type == T_MES15) && com_pos && com_pos <= fdata_p->src_com_pos )
		{ // ｺﾒﾝﾄのみのTABは,前行のｺﾒﾝﾄのTABと合わせる
			fdata_p->src_com_pos = com_pos;
			fdata_p->hojo_flag |= H_MES_E;
			// ---------- change ---------------
			fdata_p->line_type = T_COM_MES; // 前行のｺﾒﾝﾄ位置に合わせる
			strcpy( buf, "//" );
			if( fdata_p->mes[0] != ' ' && fdata_p->mes[0] != _SOH ) strcat( buf, " " );
			strcat( buf, fdata_p->mes );	// 本文をcopy
			strcpy( fdata_p->mes, buf );	// 本文を戻す
			fdata_p->com_teigi_no = 0;
			fdata_p->pri_comment[0] = 0;
		}
		if( fdata_p->line_type == T_MES15 || (fdata_p->hojo_flag & H_BIG_K_L) ) com_pos = 0;
		else com_pos = fdata_p->src_com_pos; // ｺﾒﾝﾄのtop位置をsave
	}

	crlf_cnt = 1; // 連続改行数. 最初の改行は削除
	line_last = 0;
	for( line_no = 0; line_no < max_line; line_no++ )
	{ // fdata_p では重複するので、ここではfdata使用
		fdata = &ope_buf[line_no];

#ifdef _DEBUG
		if( line_no >= 7816 )
		{
			debug_n = (int)fdata->mes;
		}
#endif

		if( line_no >= line_last && fdata->line_type != T_CRLF )
		{ // 調査
			base_type = chk_tab_enable( line_no ); // TAB補正の必要性を確認
			if( fdata->hojo_flag & (H_YEN1 | H_YEN2) ) base_type = G_YEN;

			if( base_type )
			{ // ------------ 連続する同じtypeを調べる ---------------
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
					else { // その他, G_STRUCT, G_CASE, G_INCLUDE, G_ASM, G_YEN, G_PROC
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
				{ // 2行以上
					if( base_type == G_ASM ) g_asm_syori( base_type, line_no, line_last );
					else ajust_tab( base_type, line_no, line_last ); // 同類の連続をTABでそろえる
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
		cut_last_space( 1, buf );	// 最後のTAB,spaceを削除

		chg_soh_tab( 1, buf );		// 区切りのｽﾍﾟｰｽをTABに変換

		if( fp_dbg != NULL )
		{
			strcpy( dbg_buf, buf );
			disp_debug_para2( dbg_buf );
		}
		strcat( buf, "\r\n" );
		if( font_type == 1 )
		{ // 0:自動, 1:utf8, 2:Shift JIS
			srcSJIS_out = SjistoUTF8( (string)buf );
			strcpy( buf, srcSJIS_out.c_str() );
		}
//		save_error_file( buf ); // 記録 zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz

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
		{ // 連続するLFは無視
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
	// ------------------ ｿｰｽﾌｧｲﾙと比較 ------------------
	fp_src = fopen( src_name, "rb+" );
	if( fp_src == NULL )
	{
		DeleteFile( tmp_name ); // 削除
		printf( "Fatal: can't open file:%s\n", src_name );
		wait_exit( 1 );
	}

	fp_dst = fopen( tmp_name, "rb+" );
	if( fp_dst == NULL )
	{
		fclose( fp_src );
		fp_src = NULL;
//		DeleteFile( tmp_name ); // 削除
		printf( "Fatal: can't open file:%s\n", tmp_name );
		wait_exit( 1 );
	}
//	fseek( fp_src, 0, SEEK_SET ); // 戻す
//	fseek( fp_dst, 0, SEEK_SET ); // 戻す

	line_no = 0;
	syori_cnt = 0;
	for(;;)
	{
		len = getln( fp_src, r_buf, CHAR_SIZE2 );				// ﾌｧｲﾙから改行文字まで取り込む(CR+LF-->LF)
		line_no++;
		n = getln( fp_dst, w_buf, CHAR_SIZE2 );					// ﾌｧｲﾙから改行文字まで取り込む(CR+LF-->LF)
		if( r_buf[0] == 0 && w_buf[0] == 0 ) break;				// OK
		if( n != len ) syori_cnt++;								// 不一致
		else if( memcmp(r_buf, w_buf, len) != 0 ) syori_cnt++;	// 不一致
	}
	if( fp_src != NULL ) fclose( fp_src );
	fp_src = NULL;
	fclose( fp_dst );

	if( debug_mode == 0 )
	{
		switch( form_source_name )
		{
		case 0: // ｿｰｽ名の処理 0:検査のみ
			break;

		case 1: // 変更 ｿｰｽ名の処理 1:ｿｰｽ名は変わらず+.newを新規に作る
			DeleteFile( new_name );									// 削除
			if( syori_cnt != 0 ) MoveFile( tmp_name, new_name );	// 変更
			break;

		case 2: // ｿｰｽ名の処理 2:ｿｰｽ名を+.oldとする
			DeleteFile( old_name ); // 削除
			if( syori_cnt != 0 )
			{
				MoveFile( src_name, old_name ); // 変更 ｿｰｽ名の処理 2:ｿｰｽ名を+.oldとする
				MoveFile( tmp_name, src_name ); // 変更
			}
			break;

		case 3: // ｿｰｽ名の処理 3:oldを作らない
			DeleteFile( old_name ); // 削除
			if( syori_cnt != 0 )
			{
				MoveFile( src_name, old_name ); // 一時的にrename
				MoveFile( tmp_name, src_name ); // 変更
				DeleteFile( old_name );			// 削除
			}
			break;
		}
	}
	DeleteFile( tmp_name ); // 削除
	return( syori_cnt );
}
// ------------------------------------------
// utf8 to shiftJIS
// ------------------------------------------
std::string UTF8toSjis( std::string srcUTF8 )
{
	// Unicodeへ変換後の文字列長を得る
	int lenghtUnicode = MultiByteToWideChar( CP_UTF8, 0, srcUTF8.c_str(), srcUTF8.size() + 1, NULL, 0 );

	// 必要な分だけUnicode文字列のバッファを確保
	wchar_t *bufUnicode = new wchar_t[lenghtUnicode];

	// UTF8からUnicodeへ変換
	MultiByteToWideChar( CP_UTF8, 0, srcUTF8.c_str(), srcUTF8.size() + 1, bufUnicode, lenghtUnicode );

	// ShiftJISへ変換後の文字列長を得る
	int lengthSJis = WideCharToMultiByte( CP_THREAD_ACP, 0, bufUnicode, -1, NULL, 0, NULL, NULL );

	// 必要な分だけShiftJIS文字列のバッファを確保
	char *bufShiftJis = new char[lengthSJis];

	// UnicodeからShiftJISへ変換
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
	// Unicodeへ変換後の文字列長を得る
	int lenghtUnicode = MultiByteToWideChar( CP_THREAD_ACP, 0, srcSjis.c_str(), srcSjis.size() + 1, NULL, 0 );

	// 必要な分だけUnicode文字列のバッファを確保
	wchar_t* bufUnicode = new wchar_t[lenghtUnicode];

	// ShiftJISからUnicodeへ変換
	MultiByteToWideChar( CP_THREAD_ACP, 0, srcSjis.c_str(), srcSjis.size() + 1, bufUnicode, lenghtUnicode );

	// UTF8へ変換後の文字列長を得る
	int lengthUTF8 = WideCharToMultiByte( CP_UTF8, 0, bufUnicode, -1, NULL, 0, NULL, NULL );

	// 必要な分だけUTF8文字列のバッファを確保
	char* bufUTF8 = new char[lengthUTF8];

	// UnicodeからUTF8へ変換
	WideCharToMultiByte( CP_UTF8, 0, bufUnicode, lenghtUnicode + 1, bufUTF8, lengthUTF8, NULL, NULL );

	std::string strUTF8( bufUTF8 );

	delete bufUnicode;
	delete bufUTF8;

	return( strUTF8 );
}
