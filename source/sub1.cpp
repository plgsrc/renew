// -------------------------------------------------------------------
// sub1.cpp
// 解析をする
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

// ------- 1つ前の文字種類.比較のため長い文字列から比較 ------------------------
struct B_MAP_S b_map[] = {
//	{ moji_type,	 "name",	  len }
	{ C_PROTECTED,	 "protected", 9   },
	{ C_NAMESPACE,	 "namespace", 9   },

	{ C_UNSIGNED,	 "unsigned",  8   },
	{ C_INCLUDE,	 "#include",  8   },
	{ C_TEMPLATE,	 "template",  8   },
	{ C_VOLATILE,	 "volatile",  8   },

	{ C_DEFINE,		 "#define",   7   },
	{ C_IFNDEF,		 "#ifndef",   7   },
	{ C_PRAGMA,		 "#pragma",   7   },
	{ C_TYPEDEF,	 "typedef",   7   },
	{ C_DEFAULT,	 "default",   7   },
	{ C_DEFINED,	 "defined",   7   },
	{ C_PRIVATE,	 "private",   7   },

	{ C_SIGNED,		 "signed",	  6   },
	{ C_STATIC,		 "static",	  6   },
	{ C_IFDEF,		 "#ifdef",	  6   },
	{ C_UNDEF,		 "#undef",	  6   },
	{ C_ENDIF,		 "#endif",	  6   },
//	{ C_FUSES,		 "#fuses",	  6   },
	{ C_EXTERN,		 "extern",	  6   },
	{ C_STRUCT,		 "struct",	  6   },
	{ C_SWITCH,		 "switch",	  6   },
	{ C_RETURN,		 "return",	  6   },
	{ C_SIZEOF,		 "sizeof",	  6   },
	{ C_ENDASM,		 "endasm",	  6   },
	{ C_DOUBLE,		 "double",	  6   },
	{ C_STRING,		 "string",	  6   }, // c++
	{ C_DELETE,		 "delete",	  6   }, // c++

	{ C_UNION,		 "union",	  5   },
	{ C_SHORT,		 "short",	  5   },
	{ C_FLOAT,		 "float",	  5   },
	{ C_DEF_ELSE,	 "#else",	  5   },
	{ C_ELIF,		 "#elif",	  5   },
	{ C_WHILE,		 "while",	  5   },
	{ C_CONST,		 "const",	  5   },
	{ C_USING,		 "using",	  5   },
	{ C_CONST,		 "const",	  5   },
	{ C_CLASS,		 "class",	  5   },
	{ C_FALSE,		 "false",	  5   },

	{ C_CHAR,		 "char",	  4   },
	{ C_LONG,		 "long",	  4   },
	{ C_VOID,		 "void",	  4   },
	{ C_GOTO,		 "goto",	  4   },
	{ C_CASE,		 "case",	  4   },
	{ C_ELSE,		 "else",	  4   },
	{ C_BOOL,		 "bool",	  4   },
	{ C_TRUE,		 "true",	  4   },
//	{ C_USE,		 "#use",	  4   },

	{ C_FAR,		 "far",		  3   },
	{ C_DEF_IF,		 "#if",		  3   },
	{ C_INT,		 "int",		  3   },
	{ C_FOR,		 "for",		  3   },
	{ C_TRY,		 "try",		  3   },
	{ C_SHL_IQUAL,	 "<<=",		  3   }, // <<=
	{ C_SHR_IQUAL,	 ">>=",		  3   }, // >>=
	{ C_ILLEGAL,	 "+++",		  3   }, // 予約語以外
	{ C_ILLEGAL,	 "---",		  3   }, // 予約語以外
	{ C_ILLEGAL,	 "***",		  3   }, // 予約語以外
	{ C_ILLEGAL,	 "===",		  3   }, // 予約語以外
	{ C_ILLEGAL,	 "%%%",		  3   }, // 予約語以外
	{ C_ILLEGAL,	 "&&&",		  3   }, // 予約語以外
	{ C_ILLEGAL,	 "###",		  3   }, // 予約語以外
	{ C_ILLEGAL,	 "|||",		  3   }, // 予約語以外
	{ C_ILLEGAL,	 "^^^",		  3   }, // 予約語以外
	{ C_ILLEGAL,	 "~~~",		  3   }, // 予約語以外
	{ C_ILLEGAL,	 "$$$",		  3   }, // 予約語以外
	{ C_ILLEGAL,	 "!!!",		  3   }, // 予約語以外
	{ C_ILLEGAL,	 "<--",		  3   }, // 予約語以外
	{ C_ILLEGAL,	 "-->",		  3   }, // 予約語以外
	{ C_ASM,		 "asm",		  3   }, // 予約語
	{ C_NEW,		 "new",		  3   }, // 予約語c++

	{ C_DO,			 "do",		  2   },
	{ C_COM1,		 "//",		  2   }, // ｺﾒﾝﾄ "//"
	{ C_COM2,		 "/*",		  2   }, // ｺﾒﾝﾄ "/*"
	{ C_COM3,		 "*/",		  2   }, // ｺﾒﾝﾄ "*/"
	{ C_IF,			 "if",		  2   }, // if
	{ C_P_IQUAL,	 "+=",		  2   }, // +=
	{ C_MID_IQUAL,	 "-=",		  2   }, // -=
	{ C_MUL_IQUAL,	 "*=",		  2   }, // *=
	{ C_DIV_IQUAL,	 "/=",		  2   }, // /=
	{ C_AMARI_IQUAL, "%=",		  2   }, // %=
	{ C_AND_IQUAL,	 "&=",		  2   }, // &=
	{ C_OR_IQUAL,	 "|=",		  2   }, // |=
	{ C_XOR_IQUAL,	 "^=",		  2   }, // ^=
	{ C_LESS_IQUAL,  "<=",		  2   }, // <=
	{ C_THAN_IQUAL,  ">=",		  2   }, // >=
	{ C_DOKI_IQUAL,  "!=",		  2   }, // !=
	{ C_W_KOME,		 "**",		  2   }, // 演算 "**"
	{ C_W_PLUS,		 "++",		  2   }, // 演算 "++"
	{ C_W_MINUS,	 "--",		  2   }, // 演算 "--"
	{ C_W_AND,		 "&&",		  2   }, // 論理演算 "&&"
	{ C_W_OR,		 "||",		  2   }, // 論理演算 "||"
	{ C_W_SHL,		 "<<",		  2   }, // <<
	{ C_W_SHR,		 ">>",		  2   }, // >>
	{ C_W_IQUAL,	 "==",		  2   }, // ｲｺｰﾙ "=="
	{ C_MID_STRUCT,  "->",		  2   }, // ->
	{ C_ILLEGAL,	 "<-",		  2   }, // 予約語以外
	{ C_ILLEGAL,	 "!!",		  2   }, // 予約語以外
	{ C_ILLEGAL,	 "??",		  2   }, // 予約語以外
	{ C_WKOLON,		 "::",		  2   }, // ::
	{ C_WSHARP,		 "##",		  2   }, // ##

	{ C_KOMMA,		 ",",		  1   }, // ,
	{ C_DOT,		 ".",		  1   }, // .
	{ C_SEMIKOLON,	 ";",		  1   }, // ;
	{ C_KOLON,		 ":",		  1   }, // :
	{ C_MID_K_L,	 "[",		  1   }, // [
	{ C_MID_K_R,	 "]",		  1   }, // ]
	{ C_BIG_K_L,	 "{",		  1   }, // {
	{ C_BIG_K_R,	 "}",		  1   }, // }
	{ C_K_L,		 "(",		  1   }, // (
	{ C_K_R,		 ")",		  1   }, // )
	{ C_KOME,		 "*",		  1   }, // 演算 "*"
	{ C_SURA,		 "/",		  1   }, // 演算 "/"
	{ C_PLUS,		 "+",		  1   }, // 演算 "+"
	{ C_MINUS,		 "-",		  1   }, // 演算 "-"
	{ C_AMARI,		 "%",		  1   }, // 演算 "%"
	{ C_AND,		 "&",		  1   }, // 論理演算 "&"
	{ C_OR,			 "|",		  1   }, // 論理演算 "|"
	{ C_XOR,		 "^",		  1   }, // 論理演算 "^"
	{ C_HANTEN,		 "~",		  1   }, // 論理演算 "~"
	{ C_DOKI,		 "!",		  1   }, // !
	{ C_SHL,		 "<",		  1   }, // <
	{ C_SHR,		 ">",		  1   }, // >
	{ C_IQUAL,		 "=",		  1   }, // ｲｺｰﾙ "="
	{ C_QUESTION,	 "?",		  1   }, // ?
//	{ C_SHARP,		 "#",		  1   }, // #
//	{ C_SMOJI,		 "\x27",	  1   }, // '
//	{ C_WMOJI,		 "\x22",	  1   }, // "
	{ C_YEN,		 "\x5c",	  1   }, // "\"
//	{ C_STX,		 "\x02",	  1   }, // STX
	{ C_CR,			 "\r",		  1   }, // _CR
	{ C_LF,			 "\n",		  1   }, // _LF

	{ 0,			 "",		  0   }
};
// ----------------------------------------------
// 予約文字を探す
// mode 0:最初から一致するものを探す, 1:完全一致を探す
// tok_buf 比較する文字列
// d_len 探した文字列の長さ, 不要なら=0
// return( moji_type )
// ----------------------------------------------
int search_yoyaku( int mode, char *tok_buf, int *d_len )
{
	int n, s_len, len;

	s_len = strlen( tok_buf );
	if( s_len )
	{
		for( n = 0; b_map[n].type; n++ )
		{
			len = b_map[n].len;
			if( strncmp(b_map[n].name, tok_buf, len) == 0 )
			{ // 一致
				if( mode == 0 || (mode == 1 && s_len == len) )
				{ // 最初からlen分の比較で一致
					if( d_len ) *d_len = b_map[n].len;
					return( b_map[n].type ); // 一致
				}
				break;
			}
		}
	}
	// --------- 不一致 -------------
	if( tok_buf[0] == '#' )
	{
		len = strlen( tok_buf );
		if( d_len ) *d_len = len; // NULL以外
		if( len && _isalpha(tok_buf[1]) ) return( C_DEF_OTHER );
		else return( C_DEF_ANOTHER );
	}
	if( form_typedef_mode )
	{ // user macro有効
		for( n = 0; n < typedef_cnt; n++ )
		{
			if( strcmp(typedef_map[n].name, tok_buf) == 0 )
			{ // 一致
				if( d_len ) *d_len = strlen( typedef_map[n].name );
				return( typedef_map[n].type ); // 一致
			}
		}
	}
	if( d_len ) *d_len = 0; // NULL以外
	return( 0 );			// なし
}
// ----------------------------------------------
// r_bufのshift
// fdataは新しくなっている事
// ----------------------------------------------
void shift_r_buf( int pos )
{
	strcpy( r_buf, &r_buf[pos] );		// shift

	fdata->src_line_no = src_line_no;	// 1番から

	r_pos = before_r_pos = 0;
	// n個前をclear
	before_c_type3 = before_c_type2 = before_c_type1 = cur_moji_type = tmp_moji_type = 0;
	next_space_cut = 0;					// 次の文字でspaceを省略する
	fdata->line_type = 0;				// clear
	repeat_flag = 0;					// 1:get_block()をしないで、同じﾃﾞｰﾀを使う, 2:架空の改行処理を追加する
}
// ---------------------------------------------------------------------
// 行末の余分なｽﾍﾟｰｽを取り去る
// mode 0:最後のLF削除, 1:最後がLF追加
// ---------------------------------------------------------------------
void cut_last_space( int mode, char *s )
{
	int pos, p, crlf_pos;

	crlf_pos = -1; // CR,LFがあれば位置
	p = -1;
	for( pos = 0; s[pos] != 0; pos++ )
	{
		if( s[pos] == _LF )
		{
			crlf_pos = pos; // あり
			s[pos] = 0;		// reset
		}
		else if( s[pos] == ' ' || s[pos] == _SOH )
		{
			if( p < 0 ) p = pos;
		}
		else p = -1; // reset
	}
	if( p >= 0 ) s[p] = 0;							// cut
	if( mode && crlf_pos >= 0 ) strcat( s, "\n" );	// ここではLFとする
}
// ---------------------------------------------------------------------------
// ｿｰｽ行から文字列の切り出し(細かく分離)
// mode 0:部分切り出し
// mode 1:臨時で選択部分を部分切り出し(他のﾃﾞｰﾀは更新しない)
// mode 2:最初のTAB,ｽﾍﾟｰｽをﾊﾟｽしないで最後のLFの手前までを切り出し
// max 長さは100文字まで
// return s_bufの次の位置
// ---------------------------------------------------------------------------
int get_block( int mode, char *d_buf, char *s_buf, int *tok_len )
{
	int		src_cnt, put_cnt, max_len, loop_type, len, flag, n;
	char	moji;

	*tok_len = 0;
	put_cnt = 0;
	max_len = CHAR_SIZE - 3;

	if( mode == 2 )
	{ // そのままｺﾋﾟｰ
		src_cnt = 0;
		while( (moji = s_buf[src_cnt]) != 0 )
		{
			if( moji == _LF && mode != 4 ) break;
			d_buf[put_cnt++] = moji;
			if( put_cnt >= max_len ) err_trap_line( 2, -13, 0 ); // "TOK over"
			src_cnt++;
		}
		cur_moji_type = tmp_moji_type = C_OTHER;
	}
	else { // mode = 0, 1
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
			{ // その他
				if( moji == _SOH || moji == ' ' ) break;
				else if( put_cnt && moji == _LF ) break;
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
				if( moji_check(moji) == 8 && s_buf[src_cnt + 1] ) break; // 漢字
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
		if( tmp_moji_type )
		{ // 連続性ありの検査
			put_cnt = len;					// 長さ
			d_buf[put_cnt] = 0;
			// -------------- 切り出しの最後の位置を探す ------------------
			src_cnt = pass_space( s_buf );	// ﾊﾟｽ ｽﾍﾟｰｽ,TAB
			n = 0;
			while( n < put_cnt )
			{ // 探した予約後までﾊﾟｽ
				moji = s_buf[src_cnt++];
				if( moji == 0 ) err_trap_line( 2, -17, 0 ); // "BUG 切り出し"
				if( d_buf[n] == moji ) n++;
			}
			if( (tmp_moji_type & C_MASK_TYPE1) && s_buf[src_cnt] == '*' )
			{ // 続けて'*' or "**"
				d_buf[put_cnt++] = s_buf[src_cnt++]; // '*'
				if( s_buf[src_cnt] == '*' )
				{ // "**"
					d_buf[put_cnt++] = s_buf[src_cnt++];								// "**"
					if( s_buf[src_cnt] == '*' ) d_buf[put_cnt++] = s_buf[src_cnt++];	// "***"
				}
				d_buf[put_cnt] = 0;
				tmp_moji_type = C_OTHER;
			}
//			else if( tmp_moji_type == C_K_R )
//			{ // 続けて "."
//				if( s_buf[src_cnt] == '.' )
//				{
//					d_buf[put_cnt++] = s_buf[src_cnt++]; // '.'
//					while( s_buf[src_cnt] > ' ' && s_buf[src_cnt] <= 0x7E ) d_buf[put_cnt++] = s_buf[src_cnt++];
//					d_buf[put_cnt] = 0;
//				}
//			}
//			else if( tmp_moji_type == C_DELETE )
//			{ // 続けて "[]" ?
//				if( s_buf[src_cnt] == '[' && s_buf[src_cnt + 1] == ']' )
//				{
//					d_buf[put_cnt++] = s_buf[src_cnt++]; // '['
//					d_buf[put_cnt++] = s_buf[src_cnt++]; // ']'
//					d_buf[put_cnt] = 0;
//				}
//			}
		}
		else { // 最初から探す
			loop_type = 0;
			put_cnt = 0;
			src_cnt = pass_space( s_buf ); // ﾊﾟｽ ｽﾍﾟｰｽ,TAB
			while( (moji = s_buf[src_cnt]) != 0 )
			{
				if( (loop_type != C_WMOJI && loop_type != C_SMOJI) && (moji == _SOH || moji == ' ') ) break;
				switch( loop_type )
				{
				case 0: // 最初の文字
					d_buf[put_cnt++] = moji;
					if( moji_check(moji) == 8 && s_buf[src_cnt + 1] )
					{
						d_buf[put_cnt++] = s_buf[++src_cnt];	// 漢字
						loop_type = C_ILLEGAL;					// 漢字
					}
					else if( moji == 0x22 ) loop_type = C_WMOJI;	// """
					else if( moji == 0x27 ) loop_type = C_SMOJI;	// "'"
					else if( _isdigit(moji) ) loop_type = C_DIGIT;
					else loop_type = C_OTHER;						// その他
					tmp_moji_type = loop_type;
					break;

				case C_WMOJI: // '"'
					d_buf[put_cnt++] = moji;
					if( moji == 0x22 )
					{
						src_cnt++;
						loop_type = -1;
					}
					if( moji == _LF )
					{
						tmp_moji_type = C_ILLEGAL;	// 遺法
						loop_type = -1;				// 中止
						break;
					}
					if( moji_check(moji) == 8 && s_buf[src_cnt + 1] ) d_buf[put_cnt++] = s_buf[++src_cnt]; // 漢字
					else if( moji == 0x5c )
					{ // '\'
						if( (s_buf[src_cnt + 1] == _LF || s_buf[src_cnt + 1] == 0) )
						{
							tmp_moji_type = C_ILLEGAL;	// 遺法
							loop_type = -1;				// 中止
						}
						else d_buf[put_cnt++] = s_buf[++src_cnt];
					}
					break;

				case C_SMOJI: // ''' 単独文字
					d_buf[put_cnt++] = moji;
					if( moji == 0x27 )
					{ // '''
						src_cnt++;
						loop_type = -1;
					}
					if( s_buf[src_cnt + 1] == _LF || s_buf[src_cnt + 1] == 0 )
					{
						tmp_moji_type = C_ILLEGAL;	// 遺法
						loop_type = -1;				// 中止
						break;
					}
					if( moji_check(moji) == 8 && s_buf[src_cnt + 1] ) d_buf[put_cnt++] = s_buf[++src_cnt]; // 漢字
					else if( moji == 0x5c )
					{ // '\'
						if( (s_buf[src_cnt + 1] == _LF || s_buf[src_cnt + 1] == 0) )
						{
							tmp_moji_type = C_ILLEGAL;	// 遺法
							loop_type = -1;				// 中止
						}
						else d_buf[put_cnt++] = s_buf[++src_cnt];
					}
					break;

				case C_DIGIT: // 数字
					flag = 0;						// 0:無効, 1:有効
					if( moji >= 'A' && moji <= 'Z' ) n = ( moji | BIT5 ) & 0xff;
					else n = moji & 0xff;
					if( _isdigit(moji) ) flag = 1;	// 有効
					else { // 通常
						if( put_cnt == 1 && n == 'x' )
						{
							tmp_moji_type = C_DIGITX; // 16進数
							flag = 1;
						}
						else if( (n == 'e' || n == 'f') &&
							(s_buf[src_cnt + 1] == _SOH || s_buf[src_cnt + 1] == ' ' || s_buf[src_cnt + 1] == ',' ||
							s_buf[src_cnt + 1] == '+' || s_buf[src_cnt + 1] == '-') )
						{
							tmp_moji_type = C_DIGITF; // 浮動小数点
							flag = 1;
						}
						else if( (n == '+' || n == '-') && tmp_moji_type == C_DIGITF )
						{ // 浮動小数点
							flag = 1;
						}
						else if( n == 'h' )
						{
							tmp_moji_type = C_DIGITH; // intel HEX
							flag = 1;
						}
//						else if( n == 'l' || n == 'u' )
//						{
//							flag = 1;
//						}
						else if( n >= 'a' && n <= 'z' )
						{ // 16進
							flag = 1;
						}
						else if( n == '.' )
						{
							tmp_moji_type = C_DIGITF; // 浮動小数点
							flag = 1;
						}
					}
					if( flag ) d_buf[put_cnt++] = moji; // ｱﾙﾌｧﾍﾞｯﾄ, 数字
					else loop_type = -1;				// end
					break;

				case C_OTHER: // その他
				case C_ILLEGAL:
					if( moji_check(moji) == 8 && s_buf[src_cnt + 1] )
					{
						d_buf[put_cnt++] = moji;
						d_buf[put_cnt++] = s_buf[++src_cnt]; // 漢字
						if( tmp_moji_type != C_ILLEGAL ) tmp_moji_type = C_ILLEGAL;
					}
					else if( _isalpha(moji) || _isdigit(moji) || moji == '_' ||
						moji == '.' || moji == '#' || moji == '$' || moji == '@' )
					{
						d_buf[put_cnt++] = moji; // ｱﾙﾌｧﾍﾞｯﾄ, 数字, 漢字, YEN, @
					}
					else if( moji == '*' )
					{
						if( s_buf[src_cnt + 1] == _SOH || s_buf[src_cnt + 1] == ' ' ||
							s_buf[src_cnt + 1] == '*' ) d_buf[put_cnt++] = moji;	// 連続
						else loop_type = -1;										// 区切る
					}
					else loop_type = -1; // CR,LF等
					break;

				}
				if( loop_type < 0 ) break;
				src_cnt++;
				if( put_cnt >= max_len ) err_trap_line( 2, -13, 0 ); // "TOK over"
			}
			if( put_cnt && tmp_moji_type == 0 ) tmp_moji_type = C_OTHER; // その他
		}
	}
	d_buf[put_cnt] = 0;

	if( tmp_moji_type & C_DIGIT ) tmp_moji_type = C_DIGIT;

	*tok_len = put_cnt;
	if( mode == 0 )
	{
		before_r_pos = r_pos; // 退避
		if( (tmp_moji_type & C_COM) == 0 )
		{ // ｺﾒﾝﾄは,記録しない
			before_c_type3 = before_c_type2;	// 3つ前へｼﾌﾄ
			before_c_type2 = before_c_type1;	// 2つ前へｼﾌﾄ
			before_c_type1 = cur_moji_type;		// 1つ前へｼﾌﾄ
		}
		cur_moji_type = tmp_moji_type; // set
	}
	return( src_cnt );
}
// ---------------------------------------------------------------------
// Cｺﾏﾝﾄﾞの記述
// ---------------------------------------------------------------------
int make_map_ctype( char *s_buf )
{
	int		pos, back_pos, c_cnt, tok_len;
	char	tok_buf[CHAR_SIZE];

	pos = 0;
	for( c_cnt = 0; c_cnt < (MAX_C_MAP - 1); c_cnt++ )
	{
		back_pos = pos;
		pos += get_block( 1, tok_buf, &s_buf[pos], &tok_len ); // 臨時で1 block取り込み
		if( tmp_moji_type == C_COM1 || tmp_moji_type == C_LF || tmp_moji_type == 0 ) break;
		c_map[c_cnt] = tmp_moji_type;
	}
	c_map[c_cnt] = 0;
	return( c_cnt );
}
// ----------------------------------------------
// assemlerのhexかを調べる
// return 0: no HEX, =1:HEX
// ----------------------------------------------
int chk_hex( char *s_buf )
{
	char moji;

	while( (moji = *s_buf++) != 0 )
	{
		if( isdigit(moji) ) continue;
		moji |= BIT5;
		if( moji >= 'a' && moji <= 'f' ) continue;
		if( moji == 'h' && (*s_buf == ' ' || *s_buf == _SOH || *s_buf == C_LF) ) return( 1 ); // hex
	}
	return( 0 ); // 10進数
}
// ----------------------------------------------
// assemblerの予約文字を探す
// tok_buf 比較する文字列
// return 0:no asm form, 1:asm form
// ----------------------------------------------
int chk_asm( void )
{
	int		pos, tok_len, type_cnt, komma_cnt, asm_cnt, mod_kkako_cnt, other_cnt, int_cnt;
	char	tok_buf[CHAR_SIZE];

	type_cnt = komma_cnt = asm_cnt = mod_kkako_cnt = other_cnt = int_cnt = 0;
	pos = 0;
	for(;;)
	{
		pos += get_block( 1, tok_buf, &r_buf[pos], &tok_len ); // 臨時で1 block取り込み
		type_cnt++;
		if( tmp_moji_type == C_COM1 || tmp_moji_type == C_LF || tmp_moji_type == 0 ) break;
		if( tmp_moji_type == C_SEMIKOLON ) return( 0 );
		if( tmp_moji_type == C_IQUAL ) return( 0 );
		if( tmp_moji_type == C_WKOLON ) return( 0 );
		if( tmp_moji_type == C_MID_STRUCT ) return( 0 );
		if( tmp_moji_type == C_K_L || tmp_moji_type == C_K_R ) return( 0 );
		if( tmp_moji_type == C_OTHER ) asm_cnt++;
		else if( tmp_moji_type == C_KOMMA )
		{
			if( type_cnt <= 2 ) return( 0 );
			komma_cnt++;
		}
		else if( tmp_moji_type == C_INT ) int_cnt++;
		else if( tmp_moji_type == C_MID_K_L || tmp_moji_type == C_MID_K_R ) mod_kkako_cnt++;
		else if( tmp_moji_type == C_DIGIT )
		{
			if( chk_hex(tok_buf) ) return( 1 ); // asm
		}
		else if( tmp_moji_type &
			(C_MASK_FUKUGO | C_MASK_W_ENZAN | C_MASK_BIG_K | C_MASK_DEFIF) ) return( 0 );
		else other_cnt++;
	}
	if( int_cnt == 1 )
	{
		if( asm_cnt >= 2 || mod_kkako_cnt || other_cnt ) return( 0 );
		else return( 1 );
	}
	if( (komma_cnt + asm_cnt + mod_kkako_cnt) > other_cnt )
	{
		return( 1 ); // asm
	}
	else return( 0 );
}
// ---------------------------------------------------------------------
// C++ｺﾏﾝﾄﾞ"<...>"の確認
// ---------------------------------------------------------------------
int chk_cpluss( void )
{
	int		pos, len, ret;
	char	buf[CHAR_SIZE];

	ret = 0;
	pos = r_pos;
	for(;;)
	{
		pos += get_block( 1, buf, &r_buf[pos], &len ); // 臨時で1 block取り込み
		if( tmp_moji_type == C_COM1 || tmp_moji_type == C_LF || tmp_moji_type == 0 ) break;
		if( tmp_moji_type == C_SHR )
		{
			ret = 1; // OK
			break;
		}
		else if( tmp_moji_type != C_OTHER &&
			tmp_moji_type != C_KOME &&
			tmp_moji_type != C_W_KOME &&
			tmp_moji_type != C_AND &&
			(tmp_moji_type & (C_MASK_TYPE1 | C_MASK_TYPE2 | C_MASK_RONRI)) == 0 ) break;
	}
	return( ret );
}
// ---------------------------------------------------------------------
// ｺﾒﾝﾄ行かの検査
// #if, #else, #endif は, TABを = 0 としそのままとする
// return 0:ｺﾒﾝﾄ, 1:program
// ---------------------------------------------------------------------
int chk_line( char *s_buf )
{
	int		pri_flag, pos, moji_type2, ret, n, other_cnt, end_flag, c_cnt, hojo_flag, ren_digit, konma_flag;
	int		last_pos, back_pos;
	char	buf[CHAR_SIZE], tok_buf[CHAR_SIZE];

	strcpy( buf, s_buf );
	cut_last_space( 0, buf ); // 最後のTAB,space+最後のLF削除
	last_pos = pos = 0;
	for(;;)
	{
		back_pos = pos;
		pos += get_tok1( 1, tok_buf, &buf[pos], &n ); // 次を取り込み
		if( tmp_moji_type == 0 )
		{
			break;
		}
		else last_pos = back_pos;
		if( tmp_moji_type == C_COM1 ) break;
		if( tmp_moji_type == C_ILLEGAL ) return( 0 );
		if( tmp_moji_type == C_SMOJI && n >= 5 ) return( 0 );
		if( tok_buf[n - 1] == '.' ) return( 0 );
//		if( tok_buf[0] == '#' ) return( 0 );
		if( strcmp(tok_buf, "where") == 0 ) return( 0 );
		if( strcmp(tok_buf, "when") == 0 ) return( 0 );
		if( strcmp(tok_buf, "does") == 0 ) return( 0 );
		if( strcmp(tok_buf, "have") == 0 ) return( 0 );
		if( strcmp(tok_buf, "from") == 0 ) return( 0 );
		if( strcmp(tok_buf, "This") == 0 ) return( 0 );
		if( strcmp(tok_buf, "this") == 0 ) return( 0 );
		if( strcmp(tok_buf, "that") == 0 ) return( 0 );
		if( strcmp(tok_buf, "only") == 0 ) return( 0 );
		if( strcmp(tok_buf, "used") == 0 ) return( 0 );
		if( strcmp(tok_buf, "will") == 0 ) return( 0 );
		if( strcmp(tok_buf, "were") == 0 ) return( 0 );
		if( strcmp(tok_buf, "many") == 0 ) return( 0 );
		if( strcmp(tok_buf, "why") == 0 ) return( 0 );
		if( strcmp(tok_buf, "how") == 0 ) return( 0 );
		if( strcmp(tok_buf, "the") == 0 ) return( 0 );
		if( strcmp(tok_buf, "you") == 0 ) return( 0 );
		if( strcmp(tok_buf, "was") == 0 ) return( 0 );
		if( strcmp(tok_buf, "are") == 0 ) return( 0 );
		if( strcmp(tok_buf, "if") == 0 || strcmp(tok_buf, "for") == 0 )
		{
			get_tok1( 1, tok_buf, &buf[pos], &n ); // 次を取り込み
			if( tok_buf[0] != '(' ) return( 0 );
		}
		if( strcmp(tok_buf, "If") == 0 ) return( 0 );
		if( strcmp(tok_buf, "it") == 0 ) return( 0 );
		if( strcmp(tok_buf, "is") == 0 ) return( 0 );
		if( strcmp(tok_buf, "in") == 0 ) return( 0 );
		if( strcmp(tok_buf, "or") == 0 ) return( 0 );
		if( strcmp(tok_buf, "to") == 0 ) return( 0 );
		if( strcmp(tok_buf, "of") == 0 ) return( 0 );
		if( strcmp(tok_buf, "at") == 0 ) return( 0 );
	}
//	if( tmp_moji_type == 0 )
//	{
//		last_pos += get_tok1( 1, tok_buf, &buf[last_pos], &n ); // 次を取り込み
//		if( n && isalpha(tok_buf[n - 1]) && tok_buf[n - 1] != ';' ) return( 0 );
//	}

	n = pass_space( buf );									// ﾊﾟｽ ｽﾍﾟｰｽ,TAB
	if( buf[n] == 0 ) return( 0 );
	if( buf[n] == '/' && buf[n + 1] == '/' ) return( 0 );	// ｺﾒﾝﾄ

	c_cnt = make_map_ctype( buf );							// Cｺﾏﾝﾄﾞの記述
	if( c_cnt == 0 || (c_cnt == 1 && c_map[0] == C_OTHER) ) return( 0 );

	konma_flag = 0;
	ren_digit = 0;
	hojo_flag = 0;
	end_flag = 0;
	other_cnt = 0;											// 命令数を数える
	pri_flag = 0;
	moji_type2 = 0;
	ret = 1;												// 予約語(program可能)
	pos = 0;
	c_cnt = 0;
	for(;;)
	{
		tmp_moji_type = c_map[c_cnt++];
		if( tmp_moji_type == C_LF || tmp_moji_type == 0 ) break;
		if( tmp_moji_type == C_ILLEGAL || tmp_moji_type == C_COM3 ) return( 0 );
//		if( tmp_moji_type == C_DEF_IF ) return( 0 );	// "if"
//		if( tmp_moji_type == C_DEF_ELSE ) return( 0 );	// "#else"
//		if( tmp_moji_type == C_ELIF ) return( 0 );		// "#elif"
//		if( tmp_moji_type == C_DEF_IF ) return( 0 );	// "#ifndef"
//		if( tmp_moji_type == C_DEF_IF ) return( 0 );	// "#ifdef"
//		if( tmp_moji_type == C_ENDIF ) return( 0 );		// "#endif"
		if( tmp_moji_type == C_QUESTION ) hojo_flag |= H_QUESTION;
		else if( tmp_moji_type == C_CASE ) hojo_flag |= H_CASE;
		else if( tmp_moji_type == C_DEFAULT ) hojo_flag |= H_DEFAULT;

		if( tmp_moji_type == C_DIGIT )
		{ // 連続する数にはｺﾒﾝﾄ
			if( ++ren_digit > 1 )
			{
				ret = 0;
				break;
			}
		}
		else ren_digit = 0;

		if( tmp_moji_type == C_WHILE || tmp_moji_type == C_FOR || tmp_moji_type == C_IF )
		{ // for, while, if の検査
			if( c_map[c_cnt] != C_K_L ) return( 0 ); // '('ではない
		}
		else if( tmp_moji_type == C_DIGIT )
		{ // 数字の検査
			if( c_cnt == 1 )
			{
				if( c_map[c_cnt] != C_KOMMA )
				{ // 数字のみ
					ret = 0;
					break;
				}
			}
			if( c_map[c_cnt] == C_DIGIT )
			{ // 数字のみ
				ret = 0;
				break;
			}
		}
		else if( tmp_moji_type == C_DO )
		{ // do ～ whileの検査
			if( c_map[c_cnt] != C_BIG_K_L ) return( 0 ); // '{'ではない
		}
		else if( c_map[c_cnt] &&
			tmp_moji_type == C_MID_K_L && c_map[c_cnt] != C_MID_K_R &&
			c_map[c_cnt] != C_OTHER && c_map[c_cnt] != C_DIGIT )
		{ // NG
			ret = 0;
			break;
		}

		if( (moji_type2 == C_BIG_K_R && tmp_moji_type == C_BIG_K_R) ||
			(moji_type2 == C_BIG_K_L && tmp_moji_type == C_BIG_K_L) )
		{ // NG. 連続する"{{" or "}}"
			ret = 0;
			break;
		}

		if( tmp_moji_type == C_SEMIKOLON ) before_type = 0;
		if( tmp_moji_type == C_SEMIKOLON || tmp_moji_type == C_BIG_K_L || tmp_moji_type == C_BIG_K_R || tmp_moji_type == C_K_R )
		{
			end_flag = 1;
			other_cnt = 0; // reset
		}

		if( tmp_moji_type == C_OTHER && c_map[c_cnt] != C_SEMIKOLON )
		{
			other_cnt++;
			if( (konma_flag && other_cnt >= 2) || other_cnt >= 3 )
			{ // 式ではない
				end_flag = 0;
				ret = 0;
				break;
			}
		}
		else other_cnt = 0; // reset

//		if( tmp_moji_type == C_DOT ) 2020.03.17
//		{
//			if( (c_map[c_cnt] & C_MASK_OTHER) != 0 || c_map[c_cnt] == 0 )
//			{ // 式ではない
//				ret = 0;
//				break;
//			}
//		}

		if( moji_type2 == C_KOMMA && (tmp_moji_type == C_MID_K_L || tmp_moji_type == C_KOLON || tmp_moji_type == C_WKOLON) )
		{ // 式ではない
			ret = 0;
			break;
		}

		if( tmp_moji_type == C_KOLON )
		{
			if( (hojo_flag & (H_QUESTION | H_CASE | H_DEFAULT)) == 0 )
			{
				ret = 0;
				break;
			}
		}

		if( (tmp_moji_type & (C_MASK_W_ENZAN | C_MASK_FUKUGO)) ||
			tmp_moji_type == C_IQUAL ||
			tmp_moji_type == C_KOMMA ||
			tmp_moji_type == C_CASE ||
			tmp_moji_type == C_DEFAULT ||
			(tmp_moji_type & (C_MASK_KAKKO | C_MASK_MID_K)) ||
			tmp_moji_type == C_DEFINE ) pri_flag = 1; // 演算式あり

		if( pri_flag == 0 &&
			((tmp_moji_type & C_MASK_RONRI) ||
			tmp_moji_type == C_DIGIT ||
//			tmp_moji_type == C_DOT ||
			tmp_moji_type == C_SURA ||
			tmp_moji_type == C_PLUS ||
			tmp_moji_type == C_MINUS ||
			tmp_moji_type == C_AMARI) )
		{ // 式ではない
			ret = 0;
			break;
		}

		if( (moji_type2 & C_MASK_W_ENZAN) && (tmp_moji_type & C_MASK_RONRI) )
		{
			ret = 0; // 式ではない
			break;
		}

		if( tmp_moji_type == C_COM1 ) break;
		else if( tmp_moji_type == C_COM2 )
		{ // "/*"
			while( (tmp_moji_type = c_map[c_cnt++]) != 0 )
			{ // "*/"まで
				if( tmp_moji_type == C_COM3 ) break;
			}
			if( tmp_moji_type != C_COM3 )
			{
				ret = 0;
				break;
			}
		}
		else { // 文字列以外
			if( tmp_moji_type == moji_type2 && (tmp_moji_type & (C_MASK_W_ENZAN | C_MASK_FUKUGO)) )
			{ // 2回同じものが続く
				if( (tmp_moji_type & (C_MASK_W_ENZAN | C_MASK_FUKUGO)) == (moji_type2 & (C_MASK_W_ENZAN | C_MASK_FUKUGO)) )
				{ // ｺﾒﾝﾄ列
					ret = 0;
					break;
				}
			}
			if( tmp_moji_type == C_KOMMA )
			{
				if( (moji_type2 & C_MASK_DEFIF) ||
					(moji_type2 & C_MASK_OTHER_DEF) ||
					(moji_type2 & C_MASK_ENZAN) ||
					(moji_type2 & C_MASK_RONRI) ||
					(moji_type2 & C_MASK_FUKUGO) ||
					(moji_type2 & C_MASK_W_ENZAN) ||
					(moji_type2 == C_IQUAL) ||
					(moji_type2 == C_MID_STRUCT) ||
					(moji_type2 == C_KOLON) ||
					(moji_type2 == C_WKOLON) ||
					(moji_type2 == C_SEMIKOLON) ||
					(moji_type2 == C_MID_K_L) ||
					(moji_type2 == C_BIG_K_L) )
				{ // ｺﾒﾝﾄ列
					ret = 0;
					break;
				}
			}
			if( moji_type2 == C_DEFAULT && tmp_moji_type != C_KOLON )
			{ // ｺﾒﾝﾄ列
				ret = 0;
				break;
			}
		}
		moji_type2 = tmp_moji_type; // shift
	}
	if( c_map[0] & (C_MASK_DEFIF | C_MASK_OTHER_DEF) ) return( 1 );
	if( c_map[0] == C_DEFINE || c_map[0] == C_TYPEDEF ) return( 1 );
	if( ret && other_cnt >= 2 && end_flag == 0 ) ret = 0;

	return( ret );
}
// ---------------------------------------------------------------------
// ｺﾒﾝﾄ行のpush/pop
// mode 0: pop
// mode 2:この行はｺﾒﾝﾄ
// mode 4: 複数行ｺﾒﾝﾄ
// mode 5: LFまで待って endasm処理をする
// ---------------------------------------------------------------------
void store_comment( int mode )
{
	if( mode != comment_line )
	{
		if( mode != 0 )
		{ // push
			before_ope_type = ope_type;
			before_tab_pos = tab_pos;
			before_tab_pos2 = fdata->tab_pos;
			before_kakko_cnt = kakko_cnt;
			before_back_line_type = back_line_type;
			before_big_kakko_cnt = big_kakko_cnt;
//			before_hojo_flag = fdata->hojo_flag;
			before_finish_flag = finish_flag;
			before_tab_stack_cnt = tab_stack_cnt;
			before_if_stack_top = if_stack_top;
			memcpy( &tab_back_stack, &tab_stack, sizeof(tab_back_stack) );
			memcpy( &if_back_stack, &if_tab_stack, sizeof(if_back_stack) );
			comment_line = mode;
		}
		else { // pop
			ope_type = before_ope_type;
			tab_pos = before_tab_pos;
			fdata->tab_pos = before_tab_pos2;
			kakko_cnt = before_kakko_cnt;
			back_line_type = before_back_line_type;
			big_kakko_cnt = before_big_kakko_cnt;
//			fdata->hojo_flag = before_hojo_flag;
			finish_flag = before_finish_flag;
			tab_stack_cnt = before_tab_stack_cnt;
			if_stack_top = before_if_stack_top;
			memcpy( &tab_stack, &tab_back_stack, sizeof(tab_stack) );
			memcpy( &if_tab_stack, &if_back_stack, sizeof(if_tab_stack) );
			comment_line = mode;
		}
	}
}
// ---------------------------------------------------------------------
// TABのstack mode = -1, 4 のみ使用
// mode =-4:登録+一括戻るﾎﾟｲﾝﾄｾｯﾄ( #if, #ifdef, #ifndef, '\' ) 未使用
// mode =-1:登録
// mode =0: 全て破棄して、最初に戻す
// mode =1: big_kakko_cnt, finish_flagは戻さない 未使用
// mode =2: finish_flagは戻さない 未使用
// mode =3: 全部戻す
// mode =4:一括ﾎﾟｲﾝﾄに戻る( #if, #ifdef, #ifndef, '\' )
// mode =5: fdata->line_typeは戻さない
// tag_point : 戻る位置
// return  -1:何もしない, >= 0: stack位置
// ---------------------------------------------------------------------
int position_save( int mode, int tag_point )
{
	struct	TAB_STACK_S *stack_p;
	int		pos;
	char	buf[100];

	if( mode < 0 )
	{ // save
		if( tab_stack_cnt >= MAX_TAB_STACK )
		{
			sprintf( buf, "line number = %d", max_line );
			err_trap( 2, -15, buf, 0 ); // "TAB stack over"
		}
		stack_p = &tab_stack[tab_stack_cnt];
		stack_p->ope_type = ope_type;				// 登録
		stack_p->tab_pos = tab_pos;					// 登録
		stack_p->tab_pos2 = fdata->tab_pos;
		stack_p->kakko_cnt = kakko_cnt;				// 登録
		stack_p->line_type = fdata->line_type;		// 登録
		stack_p->back_line_type = back_line_type;	// 登録
		stack_p->big_kakko_cnt = big_kakko_cnt;		// 登録
		stack_p->finish_flag = finish_flag;
		stack_p->tag_point = tag_point;				// ﾎﾟｲﾝﾄ位置(0:時に指定なし)
		tab_stack_cnt++;
		return( tab_stack_cnt );
	}
	else if( mode > 0 )
	{
		pos = tab_stack_cnt - 1;
		if( pos >= 0 )
		{ // 読み出し
			for( ; pos >= 0; pos-- )
			{
				stack_p = &tab_stack[pos];
				if( tag_point == 0 )
				{
					if( stack_p->tag_point != 0 ) pos = -1;
					break; // 指定有り
				}
				else {
					if( stack_p->tag_point == tag_point ) break; // 指定有り
					else if( mode != 4 )
					{
						pos = -1;
						break;
					}
				}
			}

			if( pos >= 0 )
			{ // 有効
				ope_type = stack_p->ope_type;
				tab_pos = stack_p->tab_pos;
				fdata->tab_pos = stack_p->tab_pos2;
				kakko_cnt = stack_p->kakko_cnt;
				back_line_type = stack_p->back_line_type;
				if( mode != 5 ) fdata->line_type = stack_p->line_type;
				if( mode > 1 ) big_kakko_cnt = stack_p->big_kakko_cnt;
				if( mode > 2 ) finish_flag = stack_p->finish_flag;
			}
			if( pos >= 0 ) tab_stack_cnt = pos; // set new
		}
		return( pos );
	}
	else {
		tab_stack_cnt = 0; // reset
		return( 0 );
	}
}
// ---------------------------------------------------------------------
// if()行のTAB位置登録 & 読み出し
// mode 0: 全て捨てる
// mode -1: save
// mode -4: '{'save
// mode 2: 最新のif()のTAB位置を探す.その後削除
// mode 4: '}'まで戻る
// return : -1:なし, 0～:if()のTAB位置
// ---------------------------------------------------------------------
int store_if( int mode )
{
	struct	IF_STACK_S *stack_p;
	int		tmp_tab, n;

	tmp_tab = -1;
	if( mode < 0 )
	{ // push
		stack_p = &if_tab_stack[if_stack_top];
		stack_p->tab_pos = tmp_tab = fdata->tab_pos;	// save
		if( mode == -4 ) stack_p->tag_point = 1;		// 一括戻るﾎﾟｲﾝﾄ
		else stack_p->tag_point = 0;					// 一括戻るﾎﾟｲﾝﾄなし

		if( ++if_stack_top >= MAX_TAB_STACK )
		{ // 一番古いのを捨てる
			if_stack_top--; // 戻す
			n = sizeof( if_tab_stack ) - sizeof( if_tab_stack[0] );
			memcpy( &if_tab_stack[0], &if_tab_stack[1], n );
		}
	}
	else if( mode == 0 ) if_stack_top = 0; // reset
	else { // read
		if( if_stack_top > 0 )
		{ // 読み出し
			do {
				if_stack_top--;
				stack_p = &if_tab_stack[if_stack_top];
				if( stack_p->tag_point && mode != 4 )
				{ // 一括戻るではないなら中止
					if_stack_top++;
					break;
				}
				tmp_tab = stack_p->tab_pos;
			} while( if_stack_top && mode == 4 && stack_p->tag_point == 0 ); // 一括戻るﾎﾟｲﾝﾄ位置まで戻る
		}
	}
	return( tmp_tab );
}
// ---------------------------------------------------------------------
// sizeof()の書式を整える
// s_buf : sizeofの次の位置
// ---------------------------------------------------------------------
// void bunri_sizeof( char *s_buf )
// {
//	int		n, pos, tok_len, loop_no;
//	char	tok_buf[CHAR_SIZE];
//
	// --------- 括弧の数を数える ------------
//	loop_no = 0;
//	pos = 0;
//	for(;;)
//	{
//		pos += get_block( 1, tok_buf, &s_buf[pos], &tok_len ); // 臨時で1 block取り込み
//		if( tok_len == 0 ) return;
//		switch( loop_no )
//		{
//		case 0:
//			if( tmp_moji_type != C_K_L ) return;
//			loop_no++;
//			break;
//
//		case 1:
//			if( tmp_moji_type == C_K_R )
//			{ // space挿入
//				n = strlen( &s_buf[pos] );
//				memmove( &s_buf[pos + 1], &s_buf[pos], n ); // spaceを挿入
//				s_buf[pos] = ' ';							// spaceを挿入
//			}
//			loop_no++;
//			break;
//
//		case 2:
//			if( tmp_moji_type == C_KOME )
//			{ // space挿入
//				n = strlen( &s_buf[pos] );
//				memmove( &s_buf[pos + 1], &s_buf[pos], n ); // spaceを挿入
//				s_buf[pos] = ' ';							// spaceを挿入
//			}
//			return;
//		}
//	}
// }
// ---------------------------------------------------------------------
// ｷｬｽﾃｨﾝｸﾞのｽﾍﾟｰｽを削除 '('の後のｽﾍﾟｰｽと')'の前のｽﾍﾟｰｽを削除
// return 0:無効, 1:有効
// ---------------------------------------------------------------------
int chk_casting( int type, char *s_buf )
{
	int		top_pos, end_pos, i, loop_type, pos, moji_pos;
	char	buf[CHAR_SIZE], moji;

	moji_pos = 0;
	loop_type = 0;
	top_pos = end_pos = -1;
	for( pos = 0; s_buf[pos]; pos++ )
	{
		moji = s_buf[pos];
		if( loop_type == 0 )
		{
			if( moji_check(moji) == 8 && s_buf[pos + 1] ) pos++;	// 漢字pass
			else if( moji == 0x22 ) loop_type = C_WMOJI;			// """
			else if( moji == 0x27 )
			{
				moji_pos = pos;
				loop_type = C_SMOJI; // "'"
			}
			else if( s_buf[pos] == '(' ) top_pos = pos; // last
			else if( s_buf[pos] == ')' ) end_pos = pos; // last
		}
		if( loop_type == C_WMOJI )
		{ // '"'
			if( moji_check(moji) == 8 && s_buf[pos + 1] ) pos++;	// 漢字
			else if( moji == 0x22 ) loop_type = 0;					// reset
		}
		if( loop_type == C_SMOJI )
		{ // ''' 単独文字
			if( moji_check(moji) == 8 && s_buf[pos + 1] ) pos++;	// 漢字
			else if( moji == 0x27 ) loop_type = 0;					// reset
			else if( (pos - moji_pos) >= 4 ) loop_type = 0;			// reset
		}
	}
	if( top_pos < end_pos )
	{ // 有効
		i = 0;
		for( pos = 0; s_buf[pos]; pos++ )
		{ // '('の後のｽﾍﾟｰｽと')'の前のｽﾍﾟｰｽを削除
			moji = s_buf[pos];
			if( !((pos == (top_pos + 1) || pos == (end_pos - 1)) && moji == ' ') ) buf[i++] = moji;
		}
		buf[i] = 0;
		strcpy( s_buf, buf );
		return( 1 );
	}
	return( 0 );
}
// ---------------------------------------------------------------------
// 吐き出し LFは記録しない
// ｺﾒﾝﾄ行の連続かの検査もする
// mode 1:追加+最後にline_no++ する
// mode	3:改行のみ
// tab		開始位置を 4-TAB毎の位置にする。
// ope_type は変化しない
// return 最後の実ｶｰｿﾙ位置
// ---------------------------------------------------------------------
void save_out_syori( int mode )
{
	static char wr_buf[BUF_SIZE] = { "\0" };
	static int	out_pos = 0; // 次の位置
	static int	losic_pos = 0;
	int			flash_flag;
	char		moji, *s_buf;

	s_buf = w_buf;
	flash_flag = 0; // 吐き出し用
	if( *s_buf )
	{
		while( (moji = *s_buf++) != 0 )
		{
			if( moji == _LF ) flash_flag = 1; // 吐き出し用 LFは記録しない
			else wr_buf[out_pos++] = moji;
		}
		wr_buf[out_pos] = 0;
	}
	if( mode ) flash_flag = 1; // 吐き出し用 LFは記録しない
	if( flash_flag )
	{
		fdata->ope_type = ope_type;			// debug用
		if( mode == 3 ) fdata->line_type = T_CRLF;
		else {
			cut_last_space( 1, wr_buf );	// 最後のTAB,space+最後にLF追加
			strcat( fdata->mes, wr_buf );	// bufferにｾｯﾄ
		}
		wr_buf[0] = 0;
		out_pos = 0;
		if( ++max_line >= max_fdata_line )
		{
			err_trap( 2, -20, 0, 0 ); // "内部memoryがoverした(bug)"
		}
		fdata = &ope_buf[max_line];
		if( mode == 3 ) fdata->tab_pos = ope_buf[max_line - 1].tab_pos;				// 引き継ぐ
		else fdata->tab_pos = tab_pos;												// 引き継ぐ
		if( ope_buf[max_line - 1].hojo_flag & H_YEN1 ) fdata->hojo_flag |= H_YEN2;	// 引き継ぐ
	}
	w_buf[0] = 0;
	ope_cnt = 0; // 1行の処理数
}

// ---------------------------------------------------------------------
// " ++" --> "++" の最初のｽﾍﾟｰｽをｶｯﾄ
// " --" --> "--" の最初のｽﾍﾟｰｽをｶｯﾄ
// ---------------------------------------------------------------------
void chk_w_p_m( char *s_buf )
{
	int n;

	n = strlen( s_buf );
	if( n >= 3 && s_buf[n - 3] == ' ' )
	{
		strcpy( &s_buf[n - 3], &s_buf[n - 2] ); // spaceをcut
	}
}
// ---------------------------------------------------------------------
// ｺﾒﾝﾄの前の位置を調べる
//
// return( pos )
// ---------------------------------------------------------------------
int chk_last_pos( char *s_buf, int pos )
{
	char moji;

	while( --pos >= 0 )
	{
		moji = s_buf[pos];
		if( moji != ' ' && moji != _SOH ) return( pos + 1 );
	}
	return( 0 );
}
// ---------------------------------------------------------------------
// 1つ前が"else"か調べる
//
// return 0:なし, 1:あり
// ---------------------------------------------------------------------
int chk_last_else( char *s_buf )
{
	int		loop_type, pos, moji_pos;
	char	moji;

	moji_pos = 0;
	loop_type = 0;
	for( pos = 0; s_buf[pos]; pos++ )
	{
		moji = s_buf[pos];
		if( loop_type == 0 )
		{
			if( moji_check(moji) == 8 && s_buf[pos + 1] ) pos++;	// 漢字pass
			else if( moji == 0x22 ) loop_type = C_WMOJI;			// """
			else if( moji == 0x27 )
			{
				moji_pos = pos;
				loop_type = C_SMOJI; // "'"
			}
			else if( moji == 'e' )
			{
				if( strncmp(&s_buf[pos], "else", 4) == 0 ) return( 1 );
			}
			else if( moji == '/' && s_buf[pos + 1] == '/' ) break;
			else if( moji == '/' && s_buf[pos + 1] == '*' ) loop_type = 1;
		}
		else if( loop_type == 1 )
		{ // "*/"待ち
			if( moji == '*' && s_buf[pos + 1] == '/' ) loop_type = 0; // reset
		}
		else if( loop_type == C_WMOJI )
		{ // '"'
			if( moji_check(moji) == 8 && s_buf[pos + 1] ) pos++;	// 漢字
			else if( moji == 0x22 ) loop_type = 0;					// reset
		}
		else if( loop_type == C_SMOJI )
		{ // ''' 単独文字
			if( moji_check(moji) == 8 && s_buf[pos + 1] ) pos++;	// 漢字
			else if( moji == 0x27 ) loop_type = 0;					// reset
			else if( (pos - moji_pos) >= 4 ) loop_type = 0;			// reset
		}
	}
	return( 0 );
}
// ---------------------------------------------------------------------
// for( ; --> for(; に変更
//
// ---------------------------------------------------------------------
void chk_for_only( char *s_buf )
{
	int		n;
	char	moji;

	n = strlen( s_buf );
	while( --n > 2 )
	{
		moji = s_buf[n];
		if( moji == ';' && s_buf[n - 1] == ' ' && s_buf[n - 2] == '(' )
		{
			strcpy( &s_buf[n - 1], &s_buf[n] ); // spaceをcut
			break;
		}
	}
}
// ---------------------------------------------------------------------
// ｷｬｽﾃｨﾝｸﾞを調べる
// ---------------------------------------------------------------------
int chk_w_kakko( char *s_buf )
{
	int		n;
	char	moji;

	n = strlen( s_buf );
	while( --n >= 0 )
	{
		moji = s_buf[n];
		if( moji == '(' )
		{
			if( n == 0 ) return( 1 );
			if( s_buf[n - 1] == ' ' || s_buf[n - 1] == _SOH ) return( 1 );
		}
		else if( !(_isalpha(moji) || _isdigit(moji) || moji == '_' || moji == '*' || moji == ' ') ) break;
	}
	return( 0 );
}
// ---------------------------------------------------------------------
// 同一行に '{' と '}'あるかの検査
// return 0:数量なしまたは均等
// return +数字:'{'が多い
// retrun -数字:'}'が多い
// retrun *last_pos ﾍﾟｱｰ括弧の最後の'}'位置
// ---------------------------------------------------------------------
int chk_big_kakko( char *s_buf, int *last_pos )
{
	int		loop_type, pos, moji_pos, k_cnt;
	char	moji;

	*last_pos = 0;
	k_cnt = 0;
	moji_pos = 0;
	loop_type = 0;
	for( pos = 0; s_buf[pos]; pos++ )
	{
		moji = s_buf[pos];
		if( loop_type == 0 )
		{
			if( moji_check(moji) == 8 && s_buf[pos + 1] ) pos++;	// 漢字pass
			else if( moji == 0x22 ) loop_type = C_WMOJI;			// """
			else if( moji == 0x27 )
			{
				moji_pos = pos;
				loop_type = C_SMOJI; // "'"
			}
			else if( moji == '{' ) k_cnt++;
			else if( moji == '}' )
			{
				if( --k_cnt == 0 ) *last_pos = pos; // last位置
			}
			else if( moji == '/' && s_buf[pos + 1] == '/' ) break;			// ｺﾒﾝﾄ
			else if( moji == '/' && s_buf[pos + 1] == '*' ) loop_type = 1;	// ｺﾒﾝﾄ
		}
		else if( loop_type == 1 )
		{ // "*/"待ち
			if( moji == '*' && s_buf[pos + 1] == '/' ) loop_type = 0; // reset
		}
		else if( loop_type == C_WMOJI )
		{ // '"'
			if( moji_check(moji) == 8 && s_buf[pos + 1] ) pos++;	// 漢字
			else if( moji == 0x22 ) loop_type = 0;					// reset
		}
		else if( loop_type == C_SMOJI )
		{ // ''' 単独文字
			if( moji_check(moji) == 8 && s_buf[pos + 1] ) pos++;	// 漢字
			else if( moji == 0x27 ) loop_type = 0;					// reset
			else if( (pos - moji_pos) >= 4 ) loop_type = 0;			// reset
		}
	}
	return( k_cnt );
}
// ---------------------------------------------------------
// TABを含む文字列の見た目の計算
// 最初のTAB,ｽﾍﾟｰｽ以外の文字が見つかるまで
// return : 長さ
// ---------------------------------------------------------
int get_head_tab_pos( char *s_buf )
{
	int		n, len;
	char	moji;

	// 指定の位置のTABを計算する
	len = 0;
	while( *s_buf == '/' )
	{
		s_buf++;
		len++;
	}
	for( n = 0; (moji = s_buf[n]) != 0; n++ )
	{
		if( moji == _LF ) break;
		else if( moji != ' ' && moji != _SOH ) break;
		else len++;
	}
	return( len );
}
// ---------------------------------------------------------
// TABをｽﾍﾟｰｽの代わりにSOHに置き換える
// ret : 最初のTAB,ｽﾍﾟｰｽ以外の文字が見つかるまでの長さ
// ---------------------------------------------------------
void tab_to_soh( char *s_buf )
{
	int		n, len, w_pos;
	char	moji, w_buf[CHAR_SIZE];

	w_pos = 0;
	len = 0;
	for( n = 0; (moji = s_buf[n]) != 0; n++ )
	{
		if( moji == _TAB )
		{
			len = ( len / 4 + 1 ) * 4; // 見た目の長さ
			while( w_pos < len ) w_buf[w_pos++] = _SOH;
		}
		else {
			w_buf[w_pos++] = moji;
			len++;
		}
		if( w_pos >= (CHAR_SIZE - 5) )
		{
			sprintf( w_buf, "%s(%d) 出力ﾌｧｲﾙ[line=%d]", src_full_name, src_line_no + 1, max_line + 1 );
			err_trap( 2, -36, w_buf, 0 ); // "1行が長すぎる"
		}
	}
	memcpy( s_buf, w_buf, w_pos );
	s_buf[w_pos] = 0;
}
// ---------------------------------------------------------
// TABを含む文字列の見た目の計算
// 最初のTAB,ｽﾍﾟｰｽ以外の文字が見つかるまで
// return : 長さ
// ---------------------------------------------------------
int get_first_pos( char *s_buf )
{
	int		n, len;
	char	moji;

	// 指定の位置のTABを計算する
	len = 0;
	for( n = 0; (moji = s_buf[n]) != 0; n++ )
	{
		if( moji == _CR || moji == _LF ) break;
		if( moji == _TAB ) len = ( (len / 4) + 1 ) * 4; // 見た目の長さ
		else if( moji != ' ' && moji != _SOH ) break;
		else len++;
	}
	return( len );
}
// ---------------------------------------------------------------------
// '{'
// mode 0:括弧を 改行しない で文書整形する
// mode 1:括弧を 改行+'{'で 文書整形する+縦に揃える
// mode 2:括弧を '{'+改行で 文書整形する+縦に揃える
// ---------------------------------------------------------------------
void big_kakko_syori1( int mode, char *tok_buf )
{
	int		kakko_pos;
	char	buf[CHAR_SIZE];

#ifdef _DEBUG
	if( max_line >= 9092 )
	{
		debug_n = fdata->tab_pos;
	}
#endif

//	store_if( -4 );						// save
//	position_save( -4, T_BIG_KAKKO );	// save
	if( ope_cnt == 0 )
	{
		if( fdata->line_type == 0 ) fdata->line_type = T_BIG_KAKKO;
		else if( before_c_type1 == C_ELSE ) fdata->line_type = T_ELSE_BIG;
	}
	finish_flag = 0;

	if( chk_big_kakko(&r_buf[r_pos - 1], &kakko_pos) <= 0 )
	{ // "{～}"か "{～}"+'}'が多い
		if( form_big_kakko_pair == 0 && fdata->line_type == T_BIG_KAKKO )
		{
			strcpy( w_buf, r_buf );		// 元をsave
			fdata->line_type = T_MES17; // 原文のまま
			fdata->hojo_flag &= ~( H_MASK_MES );
			fdata->hojo_flag |= H_MES17;
			fdata->tab_pos = 0;
			save_out_syori( 1 );		// 吐き出し+LF
//			position_save( 4, T_BIG_KAKKO );
//			store_if( 4 );				// load
			r_pos = -1;
			return;
		}
		store_if( -4 );						// save
		position_save( -4, T_BIG_KAKKO );	// save

		if( kakko_pos ) fdata->src_pair_kakko_end = r_pos + kakko_pos - 1; // ﾍﾟｱ括弧の最後の位置
		if( fdata->line_type == T_BIG_KAKKO ) fdata->line_type = T_B_K_PAIR;
		fdata->hojo_flag |= H_B_K_PAIR;
		fdata->hojo_flag |= H_BIG_K_L;
		if( ope_cnt ) strcat( w_buf, " " );
		strcat( w_buf, "{" );											// '{'
		ope_cnt++;
		big_kakko_cnt = 1;
		if( ope_cnt == 1 && fdata->tab_pos == 0 ) fdata->tab_pos = 1;	// 最低ﾍﾟｱｰｶｯｺのTAB位置
	}
	else {
		if( (fdata->hojo_flag & (H_MASK_MES | H_YEN1 | H_YEN2)) == 0 && mode == 2 && ope_cnt &&
			(fdata->line_type == T_IF ||
			fdata->line_type == T_ELSE_IF ||
			(fdata->line_type & T_MASK) == T_ELSE ||
			fdata->line_type == T_WHILE ||
			fdata->line_type == T_SWITCH ||
			fdata->line_type == T_FOR ||
			fdata->line_type == T_TRY ||
			fdata->line_type == T_STRUCT ||
			fdata->line_type == T_PROC) )
		{ // mode = 2: 改行 + '{'
			save_out_syori( 1 );								// 吐き出し+LF
			shift_r_buf( r_pos - 1 );							// r_bufのshift
			r_pos = get_block( 0, tok_buf, r_buf, &kakko_pos ); // 次取り込み
			fdata->line_type = T_BIG_KAKKO;
		}
		store_if( -4 );										// save
		position_save( -4, T_BIG_KAKKO );					// save
		if( ope_cnt ) strcat( w_buf, " " );
//		else if( kakko_cnt == 0 ) fdata->tab_pos = tab_pos; // 初回 zzzzzzzzzzzzzzzzzzz
		else fdata->tab_pos = tab_pos;						// 初回 zzzzzzzzzzzzzzzzzzz
		strcat( w_buf, "{" );								// '{'
		ope_cnt++;
		big_kakko_cnt = 1;
		kakko_cnt = 0;										// 初回 zzzzzzzzzzzzzzzzzzz
		if( (fdata->hojo_flag & H_BIG_K_L) == 0 )
		{ // 最初
			fdata->hojo_flag |= H_BIG_K_L;
			tab_pos++;
		}
		get_block( 1, buf, &r_buf[r_pos], &kakko_pos ); // 臨時で区切り位置まで残り取り込み
		// ------------ '{'の後のｺﾒﾝﾄは、続行する --------------
		if( (fdata->hojo_flag & (H_MASK_MES | H_YEN1 | H_YEN2)) == 0 &&
			tmp_moji_type != C_COM1 &&
			tmp_moji_type != C_COM2 &&
			tmp_moji_type != C_LF
			)
		{
			save_out_syori( 1 );	// 吐き出し+LF
			shift_r_buf( r_pos );	// r_bufのshift
		}
	}
}
// ---------------------------------------------------------------------
// '}'
// ---------------------------------------------------------------------
void big_kakko_syori2( char *tok_buf )
{
	int back_type, back_tab_pos, n;

#ifdef _DEBUG
	if( max_line >= 9092 )
	{
		debug_n = fdata->tab_pos;
	}
#endif

	if( ope_cnt && form_other_big_kakko == 2 && before_c_type1 == C_SEMIKOLON &&
		(fdata->hojo_flag & (H_MASK_MES | H_YEN1 | H_YEN2 | H_B_K_PAIR)) == 0 )
	{ // 改行 + '{'
		save_out_syori( 1 );						// 吐き出し+LF
		shift_r_buf( r_pos - 1 );					// r_bufのshift
		r_pos = get_block( 0, tok_buf, r_buf, &n ); // 次取り込み
		fdata->line_type = T_BIG_KAKKO;
	}
	back_tab_pos = fdata->tab_pos;		// 現在のTAB
	back_type = fdata->line_type;		// 退避
	position_save( 4, T_BIG_KAKKO );	// 戻る
	store_if( 4 );						// 戻る
	if( (fdata->hojo_flag & H_B_K_PAIR) && r_pos <= (fdata->src_pair_kakko_end + 1) )
	{ // ﾍﾟｱｰ括弧終わり
		if( ope_cnt ) strcat( w_buf, " " );
		strcat( w_buf, "}" ); // '}'
		if( r_pos == (fdata->src_pair_kakko_end + 1) )
		{
			if( ope_cnt == 0 ) fdata->line_type = T_BIG_KAKKO;
			finish_flag = 1;
		}
	}
	else {
		if( ope_cnt )
		{
			strcat( w_buf, " " );
			fdata->tab_pos = back_tab_pos; // ﾏﾙﾁなのでTABは継続させる
		}
		else {
			fdata->line_type = T_BIG_KAKKO;
			fdata->tab_pos = tab_pos; // 戻す
		}
		strcat( w_buf, tok_buf );
		finish_flag = 1;
	}
	fdata->hojo_flag |= H_BIG_K_R;
	if( back_type == 0 ) fdata->line_type = T_BIG_KAKKO;
	else fdata->line_type = back_type;
	ope_cnt++;
}
// ---------------------------------------------------------------------
// if(), else, for(), while(), do, switch の共通処理
// ﾍﾟｱｰ括弧の場合は改行(分解)しないで文書整形する({～})
// mode '{'～'}'の処理
// mode 0:文書整形のみ
// mode 1:～{～ の場合, ～{改行～ にして文書整形する(括弧の後改行)
// mode 2:～{～ の場合, ～改行{～ にして文書整形する+縦に揃える(括弧の前改行)
// ---------------------------------------------------------------------
void big_kakko_syori3( int mode, char *tok_buf, int *tok_len )
{
	int n, hojo_flag, back_line_type;

	switch( ope_type & 0x0f )
	{
	case 2: // 2回目 後処理
#ifdef _DEBUG
		if( max_line >= 9092 )
		{
			debug_n = tab_pos;
		}
#endif
		if( cur_moji_type == C_BIG_K_L )
		{ // modeは個別で変わるので	big_kakko_syori1()は個別に指定する事
			if( chk_big_kakko(&r_buf[r_pos - 1], &n) > 0 )
			{ // 単独'{'
				if( ope_cnt ) fdata->line_type = ope_type & T_MASK;
				big_kakko_syori1( mode, tok_buf ); // 改行+'{'の処理, 2:改行してﾍﾟｱｰ括弧を分解する
			}
			else big_kakko_syori1( 0, tok_buf );	// 改行なし
			ope_type = ( ope_type & T_MASK ) + 6;	// 終了待ち
		}
		else if( cur_moji_type == C_LF )
		{
			if( kakko_cnt == 0 )
			{ // ()終わり
				if( finish_flag )
				{ // ';'あり
					if( ope_cnt ) save_out_syori( 1 ); // 吐き出し+LF 続行
					if( position_save(4, ope_type & T_MASK) >= 0 ) repeat_flag = 1;
					finish_flag = 1;
					break;
				}
				else { // 複数行処理
					if( mode == 0 || (fdata->hojo_flag & (H_MASK_MES | H_MES_E | H_YEN1 | H_YEN2)) )
					{ // mode 0:何もしない
						hojo_flag = fdata->hojo_flag;	// 現在行の補助を一時退避
						kyotu_syori( tok_buf );			// '()[]'などの共通処理
						if( hojo_flag & (H_MASK_MES | H_MES_E | H_YEN1 | H_YEN2) ) fdata->tab_pos++;
					}
					else {
						back_line_type = fdata->line_type;
						while( cur_moji_type == C_LF )
						{ // ---------- 改行を無視 ------------------
							get_next_line( 0 );											// 一時読み込み
							r_pos += get_block( 0, tok_buf, &r_buf[r_pos], tok_len );	// 次を取り込み
							if( *tok_len == 0 ) break;
						}
						if( *tok_len == 0 )
						{
							err_trap_line( 0, -30, "" );		// ""改行後の読み出しが出来ない"
							if( ope_cnt ) save_out_syori( 1 );	// 吐き出し+LF 続行
							r_pos = -1;							// 異常終了
							break;
						}
						get_next_line( 2 );											// 一時読み込みを正式取り込み
						fdata->line_type = back_line_type;
						r_pos += get_block( 0, tok_buf, &r_buf[r_pos], tok_len );	// 次を取り込み
						if( mode == 1 && cur_moji_type == C_BIG_K_L &&
							(fdata->hojo_flag & (H_MASK_MES | H_MES_E | H_YEN1 | H_YEN2)) == 0 &&
							chk_big_kakko(&r_buf[r_pos - 1], &n) > 0 )
						{ // mode 1:～{～ の場合, ～{改行～ にして文書整形する(括弧の後改行)
//							fdata->line_type = ope_type & T_MASK;
							big_kakko_syori1( mode, tok_buf );		// その他 1:改行
							ope_type = ( ope_type & T_MASK ) + 6;	// '}'終了待ち
						}
						else { // 改行する(元に戻す)
							if( ope_cnt )
							{
								save_out_syori( 1 );									// 吐き出し+LF 続行
								get_next_line( 2 );										// 更新。save_out_syori()の後はこれを実行する事
								r_pos = get_block( 0, tok_buf, &r_buf[0], tok_len );	// 最初から取り込み
							}
							if( cur_moji_type == C_BIG_K_L )
							{ // {～ にする
								big_kakko_syori1( 0, tok_buf );			// そのまま
								ope_type = ( ope_type & T_MASK ) + 6;	// 終了待ち
							}
							else {
								position_save( -1, ope_type & T_MASK ); // save
								if( cur_moji_type == C_IF )
//									cur_moji_type == C_SWITCH ||
//									cur_moji_type == C_FOR ||
//									cur_moji_type == C_WHILE ||
//									cur_moji_type == C_DO ||
//									cur_moji_type == C_TRY )
								{
									tab_pos++;
									fdata->tab_pos = tab_pos;
								}
								else fdata->tab_pos = tab_pos + 1;
								repeat_flag = 1;
							}
						}
					}
				}
			}
			else kyotu_syori( tok_buf ); // 改行処理
		}
		else kyotu_syori( tok_buf ); // '()[]'などの共通処理
		break;

	case 6: // '}'終了待ち
		if( cur_moji_type == C_LF && big_kakko_cnt == 0 && kakko_cnt == 0 && finish_flag )
		{ // 終わり
			if( ope_cnt ) kyotu_syori( tok_buf );						// 改行
			if( position_save(4, T_BIG_KAKKO) >= 0 ) repeat_flag = 1;	// 一括戻りならnext
		}
		else kyotu_syori( tok_buf ); // '()[]'などの共通処理
		break;
	}
}
// ---------------------------------------------------------------------
// "* 数字" --> " * 数字" にする
// ---------------------------------------------------------------------
void add_r_kakko_spase( void )
{
	int n, len;

	n = len = strlen( w_buf );
	while( n > 0 )
	{
		if( w_buf[--n] == '*' ) break;
	}
	if( n < 2 ) return;
	if( w_buf[n - 1] != ' ' )
	{
		memmove( &w_buf[n + 1], &w_buf[n], len - n + 1 );
		w_buf[n] = ' ';
	}
}
// ---------------------------------------------------------------------
// '()[]'などの共通処理
// ---------------------------------------------------------------------
void kyotu_syori( char *tok_buf )
{
	int		n, flag, c_cnt;
	char	buf[CHAR_SIZE];

	if( next_space_cut > 0 )
	{
		space_cut_flag = 1; // 強制
		next_space_cut = 0;
	}
	else space_cut_flag = 0; // reset

	switch( cur_moji_type )
	{
	case C_INT:			// "int"
	case C_CHAR:		// "char"
	case C_SHORT:		// "short"
	case C_LONG:		// "long"
	case C_BOOL:		// "bool"
	case C_FLOAT:		// "float"
	case C_UNSIGNED:	// "unsigned"
	case C_VOID:		// "void"
	case C_DOUBLE:		// "double"
	case C_STRING:		// "string"
	case C_DELETE:		// "delete"
	case C_NEW:			// "new"
		if( ope_cnt == 1 && fdata->line_type == T_OTHER ) fdata->line_type = 0;
		get_block( 1, buf, &r_buf[r_pos], &n ); // 臨時で次を区切り位置まで残り取り込み
		if( before_c_type1 == C_K_L && (form_kakko_space || kakko_cnt != 1) ) space_cut_flag = 1;
		else if( r_buf[r_pos] != ' ' && r_buf[r_pos] != _SOH )
		{
			if( tmp_moji_type == C_W_KOME || tmp_moji_type == C_KOME || tmp_moji_type == C_AND )
				next_space_cut = 1; // 次はｽﾍﾟｰｽなし
		}
		if( fdata->line_type == 0 || fdata->line_type == T_TYPE )
		{
			switch( cur_moji_type )
			{
			case C_INT: // "int"
				if( tmp_moji_type == C_W_KOME || tmp_moji_type == C_KOME )
					fdata->sub_type = S_INT_P;
				else fdata->sub_type = S_INT;
				break;

			case C_CHAR: // "char"
				if( tmp_moji_type == C_W_KOME || tmp_moji_type == C_KOME )
					fdata->sub_type = S_CHAR_P;
				else fdata->sub_type = S_CHAR;
				break;

			case C_SHORT: // "short"
				if( tmp_moji_type == C_W_KOME || tmp_moji_type == C_KOME )
					fdata->sub_type = S_SHORT_P;
				else fdata->sub_type = S_SHORT;
				break;

			case C_LONG: // "long"
				if( tmp_moji_type == C_W_KOME || tmp_moji_type == C_KOME )
					fdata->sub_type = S_LONG_P;
				else fdata->sub_type = S_LONG;
				break;

//			case C_BOOL: // "bool"
//				fdata->line_type = T_BOOL;
//				break;

			case C_FLOAT: // "float"
				if( tmp_moji_type == C_W_KOME || tmp_moji_type == C_KOME )
					fdata->sub_type = S_FLOAT_P;
				else fdata->sub_type = S_FLOAT;
				break;

			case C_VOID: // "void"
				if( tmp_moji_type == C_W_KOME || tmp_moji_type == C_KOME )
					fdata->sub_type = S_VOID_P;
				else fdata->sub_type = S_VOID;
				break;

			case C_DOUBLE: // "double"
				if( tmp_moji_type == C_W_KOME || tmp_moji_type == C_KOME )
					fdata->sub_type = S_DOUBLE_P;
				else fdata->sub_type = S_DOUBLE;
				break;

			case C_UNSIGNED: // "unsigned"
				if( tmp_moji_type == C_W_KOME || tmp_moji_type == C_KOME )
					fdata->sub_type = S_UNSIGNED_P;
				else fdata->sub_type = S_UNSIGNED;
				break;

			case C_SIGNED: // "signed"
				if( tmp_moji_type == C_W_KOME || tmp_moji_type == C_KOME )
					fdata->sub_type = S_SIGNED_P;
				else fdata->sub_type = S_SIGNED;
				break;

			case C_STRING: // "string"
				if( tmp_moji_type == C_W_KOME || tmp_moji_type == C_KOME )
					fdata->sub_type = S_CSTRING_P;
				else fdata->sub_type = S_CSTRING;
				break;

			default:
				fdata->sub_type = S_OTHER_TYPE;
				break;

			}
			fdata->line_type = T_TYPE;
		}
		break;

	case C_STRUCT: // "struct"
		if( ope_cnt == 1 && fdata->line_type == T_OTHER ) fdata->line_type = T_STRUCT;
		else if( fdata->line_type == 0 ) fdata->line_type = T_STRUCT;
		break;

	case C_USING:			// "using"
	case C_CONST:			// "const"
	case C_NAMESPACE:		// "namespace"
	case C_CLASS:			// "class"
	case C_PRIVATE:			// "private"
	case C_PROTECTED:		// "protected"
	case C_MACRO_TYPEDEF:	// typedef xxxx yyyy
		if( ope_cnt == 1 && fdata->line_type == T_OTHER ) fdata->line_type = 0;
		if( before_c_type1 == C_K_L && (form_kakko_space || kakko_cnt != 1) ) space_cut_flag = 1;
		else if( r_buf[r_pos] != ' ' && r_buf[r_pos] != _SOH )
		{
			get_block( 1, buf, &r_buf[r_pos], &n ); // 臨時で区切り位置まで残り取り込み
			if( tmp_moji_type == C_W_KOME || tmp_moji_type == C_KOME || tmp_moji_type == C_AND )
				next_space_cut = 1;					// 次はｽﾍﾟｰｽなし
		}
		if( fdata->line_type == 0 ) fdata->line_type = T_TYPE;
		break;

	case C_STATIC:		// "static"
	case C_PUBLIC:		// "public"
	case C_VOLATILE:	// "volatile"
	case C_FAR:			// "far"
		if( ope_cnt == 0 && fdata->line_type == 0 )
		{
			get_block( 1, buf, &r_buf[r_pos], &n ); // 臨時で区切り位置まで残り取り込み
			if( (tmp_moji_type & (C_MASK_TYPE1 | C_MASK_TYPE2)) || tmp_moji_type == C_OTHER ) fdata->line_type = T_TYPE;
		}
		break;

	case C_W_KOME:	// "**"
	case C_KOME:	// '*'
	case C_AND:		// 論理演算 "&"
#ifdef _DEBUG
		if( src_line_no >= 511 )
		{
			debug_n = ope_type;
		}
#endif

		if( before_c_type1 == C_MID_K_L ) space_cut_flag = 1;
		else if( before_c_type1 == C_K_R )
		{
			if( before_c_type2 == C_KOME || before_c_type2 == C_W_KOME || (before_c_type2 & (C_MASK_TYPE1 | C_MASK_TYPE2)) )
			{
				if( chk_casting(fdata->line_type, w_buf) ) space_cut_flag = 1; // ｷｬｽﾃｨﾝｸﾞのｽﾍﾟ-ｽを削除 '('の後のｽﾍﾟｰｽと')'の前のｽﾍﾟｰｽを削除
			}
			else if( r_buf[before_r_pos] != ' ' && r_buf[before_r_pos] != _SOH ) space_cut_flag = 1; // 判定が難しいので,ｿｰｽに依存する
		}
		else if( before_c_type1 == C_K_L && kakko_cnt >= 2 ) space_cut_flag = 1;	// ｷｬｽﾃｨﾝｸﾞのｽﾍﾟ-ｽを削除 '('の後のｽﾍﾟｰｽと')'の前のｽﾍﾟｰｽを削除

//		if( next_space_cut ) space_cut_flag = 1;									// 強制

		if( before_c_type1 != C_DIGIT && r_buf[r_pos] != ' ' && r_buf[r_pos] != _SOH && r_buf[r_pos] != 0 )
		{ // 判定が難しいので,ｿｰｽに依存する(1語とする)
			get_block( 1, buf, &r_buf[r_pos], &n ); // 臨時で次をr\取り込む。区切り位置まで残り取り込み
			if( tmp_moji_type == C_OTHER || tmp_moji_type == C_K_L || tmp_moji_type == C_K_R || tmp_moji_type == C_CONST )
				next_space_cut = 1;					// 次はｽﾍﾟｰｽなし. 2013.8 C_CONSTはRX600コンパイラ用
		}
		break;

	case C_SHL: // <
	case C_SHR: // >
		break;

	case C_DOT:			// '.' 2020.03.17
	case C_MID_STRUCT:	// ->
		space_cut_flag = 1;
//		if( fdata->line_type == 0 || fdata->line_type == T_OTHER ) fdata->line_type = T_STRUCT;
		break;

	case C_DOKI: // 論理演算 "!"
		next_space_cut = 1; // 次はｽﾍﾟｰｽなし
		break;

	case C_W_AND:	// 論理演算 "&&"
	case C_W_OR:	// 論理演算 "||"
	case C_W_SHL:	// <<
	case C_W_SHR:	// >>
	case C_W_IQUAL: // ｲｺｰﾙ "=="
	case C_OR:		// 論理演算 "|"
	case C_XOR:		// 論理演算 "^"
	case C_HANTEN:	// 論理演算 "~"
		if( before_c_type1 == C_K_L )
		{ // '('
			if( form_kakko_space || kakko_cnt != 1 ) space_cut_flag = 1;
		}
		break;

	case C_W_PLUS:	// "++"
	case C_W_MINUS: // "--"
		get_block( 1, buf, &r_buf[r_pos], &n );					// 臨時で区切り位置まで残り取り込み
		if( before_c_type1 == C_OTHER || before_c_type1 == C_MID_K_L ) space_cut_flag = 1;
		if( tmp_moji_type == C_OTHER ) next_space_cut = 1;		// 次はｽﾍﾟｰｽなし
		else if( before_c_type1 == C_K_R && before_c_type2 == C_OTHER ) space_cut_flag = 1;
		else {
			get_block( 1, buf, &r_buf[r_pos], &n );				// 臨時で区切り位置まで残り取り込み
			if( tmp_moji_type == C_K_L ) next_space_cut = 1;	// 次はｽﾍﾟｰｽなし
		}
		break;

	case C_IQUAL: // '='
		fdata->hojo_flag |= H_IQUAL; // =あり
		break;

	case C_BIG_K_L: // '{'
		big_kakko_syori1( form_other_big_kakko, tok_buf );
		return;

	case C_BIG_K_R: // '}'
		big_kakko_syori2( tok_buf );
		return;

	case C_MID_K_L: // '['
		if( r_pos >= 2 && r_buf[r_pos - 2] != _SOH ) space_cut_flag = 1; // assembler対策 2012.05.23
		break;

	case C_MID_K_R: // ']'
	case C_KOMMA:	// ','
		space_cut_flag = 1;
		break;

	case C_QUESTION: // '?'
		fdata->hojo_flag |= H_QUESTION;
		break;

	case C_KOLON: // ':'
		if( form_kolon )
		{ // 1:自動で調整。ｺﾛﾝの前後のｽﾍﾟｰｽ
			if( before_c_type1 == C_KOLON ) next_space_cut = 1;				// 次はｽﾍﾟｰｽなし
			else if( fdata->hojo_flag & H_QUESTION ) space_cut_flag = 0;	// 比較文
			else if( before_c_type1 & (C_MASK_TYPE1 | C_MASK_TYPE2) )
			{
				if( r_pos >= 2 && r_buf[r_pos - 2] != ' ' && r_buf[r_pos - 2] != _SOH ) space_cut_flag = 1; // 次はｽﾍﾟｰｽなし
				if( r_buf[r_pos] != ' ' && r_buf[r_pos] != _SOH ) next_space_cut = 1;						// 次はｽﾍﾟｰｽなし
			}
			else space_cut_flag = 1;
		}
		else {
			if( r_pos >= 2 && r_buf[r_pos - 2] != ' ' && r_buf[r_pos - 2] != _SOH ) space_cut_flag = 1; // 次はｽﾍﾟｰｽなし
			if( r_buf[r_pos] != ' ' && r_buf[r_pos] != _SOH ) next_space_cut = 1;						// 次はｽﾍﾟｰｽなし
		}
		break;

	case C_WKOLON: // '::'
		if( form_kolon )
		{ // 1:自動で調整。ｺﾛﾝの前後のｽﾍﾟｰｽ
			if( before_c_type1 == C_OTHER || before_c_type1 == C_K_R ) space_cut_flag = 1;
			next_space_cut = 1; // 次はｽﾍﾟｰｽなし
		}
		else {
			if( r_pos >= 3 && r_buf[r_pos - 3] != ' ' && r_buf[r_pos - 3] != _SOH ) space_cut_flag = 1; // 次はｽﾍﾟｰｽなし
			if( r_buf[r_pos] != ' ' && r_buf[r_pos] != _SOH ) next_space_cut = 1;						// 次はｽﾍﾟｰｽなし
		}
		break;

	case C_K_L: // '('
#ifdef _DEBUG
		if( max_line >= 32 )
		{
			debug_n = ope_type;
		}
#endif

		if( (fdata->line_type == T_TYPE || fdata->line_type == T_OTHER || fdata->line_type == T_STRUCT) &&
			(fdata->hojo_flag & H_IQUAL) == 0 && (before_c_type1 & (C_MASK_TYPE1 | C_MASK_TYPE2)) == 0 )
		{ // 関数かを調べる
			if( tab_pos == 0 )
			{
				c_cnt = make_map_ctype( &r_buf[r_pos] ); // Cｺﾏﾝﾄﾞの記述
				for( n = 0; n < c_cnt; n++ ) if( c_map[n] == C_IQUAL ) break;
				if( n >= c_cnt )
				{
					if( ope_cnt < 2 ) fdata->line_type = T_CALL;
					else fdata->line_type = T_PROC; // 関数
				}
				fdata->hojo_flag &= ~H_STRUCT; // reset
			}
			else if( before_c_type1 == C_OTHER ) fdata->line_type = T_CALL; // 必要
		}
		switch( before_c_type1 )
		{
		case C_K_L: // '('
//			store_if( -4 );					// save
//			position_save( -4, T_KAKKO );	// save  zzzzzzzzzzzzzzzzzzzzzzzzzzz
			if( (ope_type & T_MASK) == T_IF && before_c_type2 == C_OTHER ) space_cut_flag = 0;
			else if( form_kakko_space || kakko_cnt >= 2 ) space_cut_flag = 1;
			break;

		case C_K_R: // ')'
			if( before_c_type2 == C_KOME || before_c_type2 == C_W_KOME || (before_c_type2 & (C_MASK_TYPE1 | C_MASK_TYPE2)) )
			{
				if( chk_casting(fdata->line_type, w_buf) ) space_cut_flag = 1; // ｷｬｽﾃｨﾝｸﾞのｽﾍﾟｽを削除 '('の後のｽﾍﾟｰｽと')'の前のｽﾍﾟｰｽを削除
			}
//			else if( (ope_type & T_DEFINE) && kakko_cnt == 0 ) space_cut_flag = 0;	// zzzzzzzzzzzzzzzzz
			else space_cut_flag = 1;
//			position_save( 4, T_KAKKO );											// zzzzzzzzzzzzzzzzzzzzzzzzzzzzz
//			store_if( 4 );															// save
			break;

		case C_W_KOME:	// '**'
		case C_KOME:	// '*'
		case C_AND:		// '&'
//			if( before_c_type2 == C_K_R ) space_cut_flag = 1; // 他で事前に処理済み
			break;

		case C_XOR:		// 論理演算 '^'
		case C_HANTEN:	// 論理演算 '~'
//			if( (before_c_type2 & (C_MASK_FUKUGO | C_MASK_W_ENZAN)) || before_c_type2 == C_IQUAL || before_c_type2 == C_K_L ) space_cut_flag = 1;
			space_cut_flag = 1;
			break;

		case C_MID_K_L: // '['
		case C_MID_K_R: // ']'
		case C_SIZEOF:
		case C_OTHER:
		case C_DEFINED:
		case C_IF:
		case C_SWITCH:
		case C_FOR:
		case C_WHILE:
		case C_DO:
		case C_TRY:
		case C_RETURN:
			space_cut_flag = 1;
			break;
		}
		if( before_c_type1 == C_MINUS && (before_c_type2 & (C_MASK_ENZAN | C_MASK_RONRI | C_MASK_FUKUGO)) )
			space_cut_flag = 1;						// 強制

//		if( next_space_cut ) space_cut_flag = 1;	// 強制

		kakko_cnt++;
		if( kakko_cnt == 1 || form_kakko_space ) back_line_type = fdata->line_type; // save
		if( form_kakko_space ) next_space_cut = 1;
		if( fdata->line_type == T_TYPEDEF && kakko_cnt == 1 && ope_cnt == 2 )
		{ // callback関数
			space_cut_flag = 0;
		}
		break;

	case C_K_R: // ')'
		if( --kakko_cnt < 0 )
		{
			kakko_cnt = 0;
			if( (ope_type & T_DEFIF) == 0 && (fdata->hojo_flag & (H_MASK_MES | H_YEN1 | H_YEN2)) == 0 )
			{
				err_trap_line( 0, -26, 0 ); // "')'が異常"
			}
		}
		else if( kakko_cnt == 0 ) back_line_type = 0; // reset

		if( space_cut_flag )
		{
			strcat( w_buf, tok_buf );
			ope_cnt++;
			if( chk_casting(fdata->line_type, w_buf) )
			{ // ｷｬｽﾃｨﾝｸﾞのｽﾍﾟ-ｽを削除 '('の後のｽﾍﾟｰｽと')'の前のｽﾍﾟｰｽを削除
				get_block( 1, buf, &r_buf[r_pos], &n );											// 臨時で区切り位置まで残り取り込み
				if( tmp_moji_type == C_OTHER || tmp_moji_type == C_KOME || tmp_moji_type == C_W_KOME || tmp_moji_type == C_AND ||
					tmp_moji_type == C_DIGIT || tmp_moji_type == C_K_L ) next_space_cut = 1;	// 次はｽﾍﾟｰｽなし
			}
			tok_buf[0] = 0; // pass
		}

		if( before_c_type1 == C_K_L ) space_cut_flag = 1; // "( )" --> "()"
		else if( kakko_cnt != 0 || (kakko_cnt == 0 && form_kakko_space) ) space_cut_flag = 1;
		else if( before_c_type1 == C_SEMIKOLON && before_c_type2 == C_SEMIKOLON ) space_cut_flag = 1; // for(;;)

		get_block( 1, buf, &r_buf[r_pos], &n ); // 臨時で区切り位置まで残り取り込み
		if( (tmp_moji_type == C_OTHER || tmp_moji_type == C_DIGIT) && chk_w_kakko(w_buf) ) next_space_cut = 1; // 次はｽﾍﾟｰｽなし

// zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz
//		if( ope_type == 0 && isalpha(r_buf[r_pos]) ) next_space_cut = 1; // ifopt( 'r' )printf( "seg:\n" ); <--- 問題あり。ｽﾍﾟｰｽ必要
		break;

	case C_SEMIKOLON: // ';': // ﾀｰﾐﾈｰﾀ
		if( kakko_cnt == 0 )
		{ // 途中ではない
			finish_flag = 1;
			if( before_c_type1 == C_SEMIKOLON ) err_trap_line( 0, -29, 0 ); // ';'が2つある
		}
		if( fdata->line_type == T_FOR && kakko_cnt == 1 && before_c_type1 == C_SEMIKOLON )
			chk_for_only( w_buf );	// for( ; --> for(; に変更
		if( before_c_type1 == C_W_PLUS || before_c_type1 == C_W_MINUS )
			chk_w_p_m( w_buf );		// " ++" --> "++", "  --" --> "--" に変更
		if( !(fdata->line_type == T_FOR && kakko_cnt == 1 && before_c_type1 == C_K_L) ) space_cut_flag = 1;
//		if( fdata->line_type == 0 ) fdata->line_type = T_SEMIKOLON;
		if( fdata->line_type == 0 ) fdata->line_type = T_OTHER;
		if( form_kakko_space ) space_cut_flag = 1;
		break;

	case C_LF:
#ifdef _DEBUG
		if( src_line_no >= 515 )
		{
			debug_n = ope_type;
		}
#endif

		if( ope_cnt )
		{
			if( fdata->hojo_flag & (H_YEN1 | H_YEN2) )
			{
				if( form_yen == 0 || (fdata->hojo_flag & H_MASK_MES) )
				{
					strcpy( w_buf, r_buf );
					fdata->line_type = T_MES17; // 原文のまま
					fdata->hojo_flag |= H_MES17;
					fdata->tab_pos = 0;
				}
			}
			if( kakko_cnt > 0 || (before_c_type1 & C_MASK_ENZAN) ) flag = 1;
			else flag = 0;
			save_out_syori( 1 ); // 吐き出し+LF
			if( flag ) fdata->tab_pos++;
		}
		return;

	case C_DIGIT:
		if( fdata->line_type == 0 ) fdata->line_type = T_DIGIT;
		switch( before_c_type1 )
		{
		case C_MID_K_L:
//		case C_DIGIT:
//		case C_OTHER:
			space_cut_flag = 1;
			break;

		case C_K_L: // '('
			if( form_kakko_space || kakko_cnt != 1 ) space_cut_flag = 1;
			break;

		case C_K_R: // ')'
			if( before_c_type2 == C_KOME || before_c_type2 == C_W_KOME || (before_c_type2 & (C_MASK_TYPE1 | C_MASK_TYPE2)) )
			{ // '*'
				if( chk_casting(fdata->line_type, w_buf) ) space_cut_flag = 1; // ｷｬｽﾃｨﾝｸﾞのｽﾍﾟｽを削除 '('の後のｽﾍﾟｰｽと')'の前のｽﾍﾟｰｽを削除
			}
			break;

		case C_MINUS:	// +
		case C_PLUS:	// -
		case C_XOR:		// 論理演算 '^'
		case C_HANTEN:	// 論理演算 '~'
			if( ope_cnt == 1 )
			{
				if( r_buf[before_r_pos] != ' ' && r_buf[before_r_pos] != _SOH )
				{ // 判定が難しいので,ｿｰｽに依存する(1語とする)
					space_cut_flag = 1;
				}
			}
			else {
				if( before_c_type2 != C_OTHER && before_c_type2 != C_DIGIT &&
					before_c_type2 != C_SMOJI && before_c_type2 != C_MID_K_R && before_c_type2 != C_K_R )
				{
					if( before_c_type3 != C_KOMMA ) space_cut_flag = 1; // +-/%
				}
			}
			break;

		case C_KOME: // '*'
			add_r_kakko_spase(); // "* 数字" --> " * 数字" にする
			break;

//		case C_XOR:		// 論理演算 '^'
//		case C_HANTEN:	// 論理演算 '~'
//			space_cut_flag = 1; // cut
//			break;

		}
//		if( next_space_cut ) space_cut_flag = 1; // 強制
		break;

	case C_SMOJI: // '~'
	case C_WMOJI: // "～"
		if( ope_cnt == 0 && fdata->tab_pos == 0 &&
			(fdata->hojo_flag & H_MASK_MES) == 0 ) fdata->tab_pos = 1; // 最低=1 TAB
		if( before_c_type1 == C_K_L )
		{ // '('
			if( cur_moji_type & C_MASK_TYPE1 ) space_cut_flag = 1;
			else if( form_kakko_space || kakko_cnt != 1 ) space_cut_flag = 1;
		}
	case C_ILLEGAL:
		break;

	case C_OTHER:
		if( before_c_type1 == C_DOT ) space_cut_flag = 1;	// 判定が難しいので,ｿｰｽに依存する 2020.03.23
		c_cnt = make_map_ctype( w_buf );					// Cｺﾏﾝﾄﾞの記述
		if( fdata->line_type == 0 )
		{
#ifdef _DEBUG
			if( max_line >= 567 )
			{
				debug_n = ope_type;
			}
#endif
			for( n = 0; n < c_cnt; n++ )
			{
				if( c_map[n] != C_OTHER &&
					c_map[n] != C_CONST &&
					c_map[n] != C_STATIC &&
					c_map[n] != C_PUBLIC &&
					c_map[n] != C_VOLATILE &&
					c_map[n] != C_EXTERN )
				{
					fdata->line_type = T_OTHER; // その他
					break;
				}
			}
			if( fdata->line_type == 0 )
			{
				get_block( 1, buf, &r_buf[r_pos], &n );
				if( tmp_moji_type == C_KOME || tmp_moji_type == C_W_KOME || tmp_moji_type == C_OTHER )
					fdata->line_type = T_TYPE;
				else fdata->line_type = T_OTHER; // その他
			}
		}
		n = moji_check( tok_buf[0] );
		if( n == 8 || n == 0x10 ) break; // ｶﾀｶﾅ, 漢字
	case C_SIZEOF:
		switch( before_c_type1 )
		{
		case C_KOMMA: // ','
			break;

		case C_K_L: // '('
			if( form_kakko_space || kakko_cnt != 1 ) space_cut_flag = 1;
			break;

		case C_K_R: // ')'
			if( before_c_type2 == C_KOME || before_c_type2 == C_W_KOME || (before_c_type2 & (C_MASK_TYPE1 | C_MASK_TYPE2)) )
			{ // '*'
				if( chk_casting(fdata->line_type, w_buf) ) space_cut_flag = 1; // ｷｬｽﾃｨﾝｸﾞのｽﾍﾟｽを削除 '('の後のｽﾍﾟｰｽと')'の前のｽﾍﾟｰｽを削除
			}
			break;

		case C_MID_STRUCT: // '->'
			space_cut_flag = 1; // '->'
			break;

		case C_MID_K_L: // '['
		case C_MID_K_R: // ']' 2012.7.6
			space_cut_flag = 1;
			break;

		case C_W_KOME:	// '**'
		case C_KOME:	// '*' 他で事前に処理済み
		case C_AND:		// '&'
			break;

		case C_PLUS:	// '+'
		case C_MINUS:	// '-'
			if( (before_c_type2 & (C_MASK_RONRI | C_MASK_FUKUGO | C_MASK_W_ENZAN)) ||
				before_c_type2 == C_K_L || before_c_type2 == C_IQUAL || before_c_type2 == C_KOMMA ) space_cut_flag = 1;
			break;

//		case C_DOT: // '.' 2020.03.17
		case C_XOR: // 論理演算 '^'
			if( (before_c_type2 & C_MASK_FUKUGO) || before_c_type2 == C_IQUAL || before_c_type2 == C_K_L ) space_cut_flag = 1;
			break;

		case C_HANTEN: // 論理演算 '~'
			space_cut_flag = 1;
			break;

		case C_W_PLUS:	// "++"
		case C_W_MINUS: // "--"
			if( before_c_type2 != C_OTHER /* && before_c_type2 != C_K_L */ && before_c_type2 != C_K_R &&
				before_c_type2 != C_DIGIT ) space_cut_flag = 1;
			break;

//		case C_EXTERN:
//			fdata->line_type = T_TYPE;
//			break;

		default:
			if( before_c_type1 & C_MASK_ENZAN )
			{
				if( before_c_type2 != C_OTHER && before_c_type2 != C_K_L && before_c_type2 != C_K_R &&
					before_c_type2 != C_DIGIT ) space_cut_flag = 1;
			}
		}
		if( r_buf[r_pos] == '*' )
		{ // 判定が難しいので,ｿｰｽに依存する
			flag = 0;
			for( n = r_pos; r_buf[n] == '*'; n++ ); // ﾊﾟｽ "*"
			if( r_buf[n] == ' ' || r_buf[n] == _SOH || r_buf[n] == 0 )
			{ // '*'の次がｽﾍﾟｰｽ
				for( ; r_buf[r_pos] == '*'; r_pos++ ) strcat( tok_buf, "*" ); // "*" or "**"
			}
		}
		else if( r_buf[r_pos] == '&' )
		{ // 判定が難しいので,ｿｰｽに依存する
			flag = 0;
			for( n = r_pos; r_buf[n] == '&'; n++ ); // ﾊﾟｽ '&'
			if( r_buf[n] == ' ' || r_buf[n] == _SOH || r_buf[n] == 0 )
			{ // '&'の次がｽﾍﾟｰｽ
				for( ; r_buf[r_pos] == '&'; r_pos++ ) strcat( tok_buf, "&" ); // "&" or "&&"
			}
		}
		if( fdata->line_type == T_TYPE && fdata->sub_type == 0 )
		{
			c_cnt = make_map_ctype( w_buf );	// Cｺﾏﾝﾄﾞの記述
			if( c_cnt && (c_map[c_cnt - 1] & C_MASK_TYPE2) )
				fdata->sub_type = S_OTHER_TYPE; // その他ﾏｸﾛ。全て定義
		}
		break;

	default:
		switch( before_c_type1 )
		{
		case 0:
			break;

		case C_DOKI:	// '!'
		case C_MID_K_L: // '['
			space_cut_flag = 1;
			break;

		case C_IQUAL:
			break;

		case C_K_L: // '('
			if( cur_moji_type & (C_MASK_TYPE1 | C_MASK_TYPE2) ) space_cut_flag = 1;
			else if( form_kakko_space || kakko_cnt != 1 ) space_cut_flag = 1;
			break;

//		default:
//			space_cut_flag = before_c_type1 & ( C_MASK_RONRI | C_MASK_ENZAN );
		}
		break;

	}
	if( tok_buf[0] )
	{
		if( space_cut_flag == 0 && ope_cnt ) strcat( w_buf, " " );
		strcat( w_buf, tok_buf );
		ope_cnt++;
	}
//	if( next_space_cut > 0 ) next_space_cut--;
}
// ---------------------------------------------------------------------
// moji:指定文字かの検査
// return =0:なし, n:検出した位置の次の位置
// ---------------------------------------------------------------------
int check_sitei_moji( char *s_buf, char moji )
{
	int n;

	n = pass_space( s_buf ); // ﾊﾟｽ ｽﾍﾟｰｽ,TAB
	if( s_buf[n] == moji ) return( n + 1 );
	return( 0 );
}
// ---------------------------------------------------------------------
// "/*"と"*/"の中に"/*"と"*/"があるかの調査
// return 見つけた"/*～*/"のﾍﾟｱｰ以外の"/*"の数
// ---------------------------------------------------------------------
int chk_comment( char *s_buf )
{
	int		pos, cnt, loop_type, moji_pos;
	char	moji;

	cnt = 1;
	moji_pos = 0;
	loop_type = 0;
	for( pos = 0; s_buf[pos]; pos++ )
	{
		moji = s_buf[pos];
		if( loop_type == 0 )
		{
			if( moji_check(moji) == 8 && s_buf[pos + 1] ) pos++;	// 漢字pass
			else if( moji == 0x22 ) loop_type = C_WMOJI;			// """
			else if( moji == 0x27 )
			{
				moji_pos = pos;
				loop_type = C_SMOJI; // "'"
			}
			else if( moji == '/' && s_buf[pos + 1] == '*' )
			{
				if( ++cnt > 1 ) break; // NG
			}
			else if( moji == '*' && s_buf[pos + 1] == '/' )
			{
				if( --cnt < 0 ) break;
			}
		}
		else if( loop_type == C_WMOJI )
		{ // '"'
			if( moji_check(moji) == 8 && s_buf[pos + 1] ) pos++;	// 漢字
			else if( moji == 0x22 ) loop_type = 0;					// reset
		}
		else if( loop_type == C_SMOJI )
		{ // ''' 単独文字
			if( moji_check(moji) == 8 && s_buf[pos + 1] ) pos++;	// 漢字
			else if( moji == 0x27 ) loop_type = 0;					// reset
			else if( (pos - moji_pos) >= 4 ) loop_type = 0;			// reset
		}
	}
	return( cnt );
}
// ---------------------------------------------------------------------
// "*/"を探す
// return 見つけた位置(-1=なし)
// ---------------------------------------------------------------------
int search_end_comment( char *s_buf )
{
	int		pos, loop_type, find_pos, moji_pos;
	char	moji;

	moji_pos = 0;
	find_pos = 0; // 0x22か0x27無くても"*/"が見つかった場合は=1
	loop_type = 0;
	for( pos = 0; (moji = s_buf[pos]) != 0; pos++ )
	{
		if( moji == '*' && s_buf[pos + 1] == '/' )
		{
			find_pos = pos; // あり
		}
		if( loop_type == 0 )
		{
			if( moji_check(moji) == 8 && s_buf[pos + 1] ) pos++;	// 漢字pass
			else if( moji == 0x22 ) loop_type = C_WMOJI;			// """
			else if( moji == 0x27 )
			{
				moji_pos = pos;
				loop_type = C_SMOJI; // "'"
			}
			else if( moji == '*' && s_buf[pos + 1] == '/' ) return( pos ); // あり
			find_pos = 0;
		}
		else if( loop_type == C_WMOJI )
		{ // '"'
			if( moji_check(moji) == 8 && s_buf[pos + 1] ) pos++;	// 漢字
			else if( moji == 0x22 ) loop_type = 0;					// reset
		}
//		else if( loop_type == C_SMOJI )
//		{ // ''' 単独文字
//			if( moji_check(moji) == 8 && s_buf[pos + 1] ) pos++;	// 漢字
//			else if( moji == 0x27 ) loop_type = 0;					// reset
//			else if( (pos - moji_pos) >= 2 ) loop_type = 0;			// reset
//		}
	}
	if( loop_type && find_pos ) return( find_pos ); // 0x22か0x27が１つしかない場合=1で文字の一部とする
	return( -1 );									// なし
}
// ---------------------------------------------------------------------
// "//"
// stack操作なし
// ---------------------------------------------------------------------
void comment_syori1( char *tok_buf, int *tok_len )
{
	int		pos, n;
//	char	buf[CHAR_SIZE];

#ifdef _DEBUG
	if( max_line >= 9053 )
	{
		debug_n = fdata->tab_pos;
	}
#endif

	if( ope_cnt == 0 )
	{ // top
		pos = get_first_pos( r_buf ); // 最初のTAB,ｽﾍﾟｰｽ以外の文字が見つかるまで
		if( form_comment_prog == 0 )
		{ // 0:何もしない, 1:ﾌﾟﾛｸﾞﾗﾑの場合は調整する+TABを揃える
			position_save( -4, T_COM1 ); // save
			if( (pos < 2 && (form_cut_comment & BIT2) == 0) ||
				(pos >= 2 && (form_cut_comment & BIT0) == 0) )
			{ // BIT0:1行の右端のｺﾒﾝﾄ(//～, /*～*/)を削除する, BIT2:ｺﾒﾝﾄ行(//～)を削除する
				strcat( w_buf, r_buf );
				fdata->line_type = T_MES17; // 原文のまま
				fdata->hojo_flag |= H_MES17;
				fdata->tab_pos = 0;
			}
			save_out_syori( 1 );		// 吐き出し+LF
			position_save( 4, T_COM1 ); // 全部戻す
			r_pos = -1;					// 1行処理終了
		}
		else {
			get_block( 1, tok_buf, &r_buf[r_pos], tok_len );	// 次,込み
			if( r_buf[r_pos] == ' ' && tmp_moji_type & (C_MASK_ENZAN | C_MASK_RONRI) ) n = 0;
			else n = chk_line( &r_buf[r_pos] );					// 2:ﾌﾟﾛｸﾞﾗﾑの場合は調整する ｺﾒﾝﾄ行かの検査. return 0:ｺﾒﾝﾄ, 1:program

			if( (pos < 2 && (form_cut_comment & BIT2) == 0) ||
				(pos >= 2 && (form_cut_comment & BIT0) == 0) )
			{ // BIT0:1行の右端のｺﾒﾝﾄ(//～, /*～*/)を削除する, BIT2:ｺﾒﾝﾄ行(//～)を削除する
				if( n == 0 || pos >= 4 )
				{ // 最初に"//"がない場合はｺﾒﾝﾄにする
					if( fdata->src_com_pos == 0 ) fdata->src_com_pos = r_pos - 2; // 最初の"//"
					if( pos < 2 )
					{ // "//"+TAB+message(program翻訳なし)
						fdata->line_type = T_MES14;
						fdata->hojo_flag |= H_MES14;
						fdata->tab_pos = 0;
						strcpy( tok_buf, &r_buf[r_pos] ); // そのままLFまで(ｽﾍﾟｰｽも)
					}
					else { // TAB+"//"+message(program翻訳なし)
						// 	ここは使用不可とする
						fdata->line_type = T_MES15;
						fdata->hojo_flag |= H_MES15;
						strcpy( tok_buf, &r_buf[r_pos] ); // そのままLFまで(ｽﾍﾟｰｽも)
					}
					strcat( w_buf, tok_buf );
					save_out_syori( 1 );	// 吐き出し+LF
					fdata->line_type = 0;
					r_pos = -1;				// 1行処理終了
				}
				else { // "//"+TAB+message(program翻訳あり)
					store_comment( 2 ); // 0:pop, 2:この行は1行ｺﾒﾝﾄ("//"あり)
					fdata->hojo_flag |= H_MES11;
					repeat_flag = 3;	// 次から
				}
			}
			else r_pos = -1; // 1行処理終了
		}
	}
	else { // 途中からｺﾒﾝﾄ
		if( (form_cut_comment & BIT0) == 0 )
		{ // BIT0=1:1行の右端のｺﾒﾝﾄ(//～, /*～*/)を削除する
			if( fdata->src_com_pos == 0 )
			{
				fdata->src_com_pos = r_pos - 2;		// ｺﾒﾝﾄ開始位置
				fdata->src_last_pos = before_r_pos; // ｺﾒﾝﾄ前の文章の最後位置
			}
			fdata->hojo_flag |= H_MES_E; // +comment
			if( form_comment_prog == 0 )
			{ // 0:何もしない, 1:ﾌﾟﾛｸﾞﾗﾑの場合は調整する+TABを揃える
				r_pos = before_r_pos + get_block( 2, tok_buf, &r_buf[before_r_pos], tok_len ); // 残り取り込み, CRLFの手前まで
				strcat( w_buf, tok_buf );
				ope_cnt++;
			}
			else {
				r_pos += get_block( 2, tok_buf, &r_buf[r_pos], tok_len ); // 残り取り込み, CRLFの手前まで
				if( ope_cnt ) strcat( w_buf, " " );
				strcat( w_buf, "//" );
				if( tok_buf[0] != _SOH && tok_buf[0] != ' ' ) strcat( w_buf, " " );
				strcat( w_buf, tok_buf );
				ope_cnt++;
			}
		}
		else r_pos += get_block( 2, tok_buf, &r_buf[r_pos], tok_len ); // 捨てる, CRLFの手前まで
		repeat_flag = 3; // 次から
	}
}
// ---------------------------------------------------------------------
// "/*" 1回目
// stack操作なし
// ---------------------------------------------------------------------
void comment_syori2( char *tok_buf, int *tok_len )
{
	int		len, end_pos, pos;
	char	buf[CHAR_SIZE];

#ifdef _DEBUG
	if( max_line >= 9053 )
	{
		debug_n = fdata->tab_pos;
	}
#endif
	pos = r_pos + pass_space( &r_buf[r_pos] ); // ﾊﾟｽ ｽﾍﾟｰｽ,TAB

	if( chk_comment(&r_buf[pos]) >= 2 )
	{ // "/*"と"*/"の中に"/*"があるかの調査.見つけた"/*"数 複数の入れ子なので、そのまま残す
		if( (form_cut_comment & BIT1) == 0 )
		{ // BIT1:本文中の部分ｺﾒﾝﾄ(/*～*/)を削除する
			if( fdata->line_type == 0 )
			{
				fdata->line_type = T_MES17;
				fdata->hojo_flag |= H_MES17;
				fdata->tab_pos = 0;
			}
			strcpy( tok_buf, &r_buf[r_pos] );										// そのままLFまで(ｽﾍﾟｰｽも)
			if( ope_cnt ) strcat( w_buf, " " );
			strcpy( tok_buf, &r_buf[r_pos] );										// 残り取り込み, CRLFまで
			if( tok_buf[0] == _SOH || tok_buf[0] == ' ' ) strcat( w_buf, "/*" );	// ｽﾍﾟｰｽなし
			else strcat( w_buf, "/* " );											// ｽﾍﾟｰｽあり
			strcat( w_buf, tok_buf );
//			err_trap_line( 0, -22, 0 );												// "'/*'か'*/'に注意"
			save_out_syori( 1 );													// 吐き出し+LF
		}
		fdata->line_type = 0;
		r_pos = -1; // 1行処理終了
		return;
	}
	len = search_end_comment( &r_buf[pos] ); // "*/"を探す, return 見つけた位置(-1=なし)
	if( len >= 0 )
	{ // あり
		end_pos = pos + len + 2;
		end_pos += pass_space( &r_buf[end_pos] ); // ﾊﾟｽ ｽﾍﾟｰｽ,TAB
		if( form_long_comment && (r_buf[end_pos] == _LF || r_buf[end_pos] == 0) )
		{ // 以後行の終わりまでｺﾒﾝﾄ "/*～*/" --> "//～”に変更
			r_buf[pos + len] = _LF;		// "*/"を捨てる
			r_buf[pos + len + 1] = 0;	// end
			r_buf[r_pos - 2] = '/';		// 入れ替え
			r_buf[r_pos - 1] = '/';
			repeat_flag = 2;			// 再度 before_r_posから
		}
		else { // 部分ｺﾒﾝﾄ /* ～ */ ～
			if( (form_cut_comment & BIT1) == 0 )
			{ // BIT1:本文中の部分ｺﾒﾝﾄ(/*～*/)を削除する
				if( ope_cnt ) strcat( w_buf, " " );
				strcat( w_buf, "/* " );				// 部分ｺﾋﾟｰ
				memcpy( buf, &r_buf[pos], len );	// 最初のｽﾍﾟｰｽ,TABはﾊﾟｽ済み
				buf[len] = 0;
				cut_last_space( 1, buf );			// 最後のTAB,space+最後にLF追加
				strcat( w_buf, buf );
				strcat( w_buf, " */" );
				if( ope_cnt == 0 && get_first_pos(r_buf) < 2 )
				{ // TAB調整の時分離
					strcpy( fdata->pri_comment, w_buf );
					w_buf[0] = 0; // clear
				}
				else ope_cnt++;
			}
			r_pos = pos + len + 2;
			if( r_pos >= CHAR_SIZE ) err_trap_line( 2, -14, 0 );	// "SUB buffer over"
			repeat_flag = 3;										// 再度 次から
		}
	}
	else { // ----------- 複数行ｺﾒﾝﾄ -------------------
		if( comment_line == 2 && (fdata->hojo_flag & H_MASK_MES) == 0 )
		{ // ｺﾒﾝﾄからの終了で戻す
			store_comment( 0 ); // 0:pop, 2:この行はｺﾒﾝﾄ中
		}
		comment_line = 4;
		if( (form_cut_comment & BIT3) == 0 )
		{ // BIT3:ｺﾒﾝﾄ複数行(/*～, ～*/)を削除する
			if( form_long_comment < 2 )
			{ // 0:何もしない
				if( ope_cnt == 0 )
				{
					strcpy( w_buf, r_buf );		// そのままLFまで(ｽﾍﾟｰｽも)
					fdata->tab_pos = 0;
					fdata->line_type = T_MES17; // 原文のまま
					fdata->hojo_flag |= H_MES17;
				}
				else {
					strcat( w_buf, " " );
					strcat( w_buf, tok_buf );
					if( r_buf[r_pos] != ' ' && r_buf[r_pos] != _SOH ) strcat( w_buf, " " );
					strcat( w_buf, &r_buf[r_pos] ); // 最後(LF)までの切り出し
				}
			}
			else if( ope_cnt == 0 )
			{ // top "//"+TAB+message(program翻訳なし)
				end_pos = get_first_pos( r_buf );
				memset( w_buf, ' ', end_pos );
				w_buf[end_pos] = 0;				// clear
				strcat( w_buf, &r_buf[r_pos] ); // 最後(LF)までの切り出し
				fdata->line_type = T_MES16;
				fdata->hojo_flag |= H_MES16;
				fdata->tab_pos = 0;
			}
			else { // 途中. "//"に変換
				strcat( w_buf, " " );
				strcat( w_buf, "//" );
				fdata->hojo_flag |= H_MES_E;	// set comment
				strcat( w_buf, &r_buf[r_pos] ); // 最後(LF)までの切り出し
			}
			save_out_syori( 1 ); // 吐き出し+LF
			fdata->line_type = 0;
		}
		r_pos = -1; // 1行処理終了
	}
}
// ---------------------------------------------------------------------
// "*/"の処理(行)。"/*～*/"は，そのまま
// form_long_comment 0:"/*"の連続のｺﾒﾝﾄ(変更なし)
// form_long_comment 2:"/*"で始まる長い文章を全て"//"に変換する
// stack操作なし
// ---------------------------------------------------------------------
void comment_syori4( char *tok_buf, int *tok_len )
{
	int		b, n;
	char	buf[CHAR_SIZE];

	n = search_end_comment( r_buf ); // "*/"を探す, return 見つけた位置(-1=なし)
	if( n >= 0 )
	{ // あり
		b = n;							// 退避
		n += 2;
		n += pass_space( &r_buf[n] );	// ﾊﾟｽ ｽﾍﾟｰｽ,TAB
		if( r_buf[n] == _LF )
		{ // 以後行の終わりまでｺﾒﾝﾄ
			if( (form_cut_comment & BIT3) == 0 )
			{ // BIT3:ｺﾒﾝﾄ複数行(/*～, ～*/)を削除する
				if( form_long_comment < 2 )
				{
					fdata->line_type = T_MES17; // 原文のまま
					fdata->hojo_flag |= H_MES17;
					strcpy( buf, r_buf );		// 0:"/*"の連続のｺﾒﾝﾄ(変更なし)
				}
				else { // 1:"/*"で始まる長い文章を全て"//"に変換する
					fdata->line_type = T_MES16;			// 全ｺﾒﾝﾄ  行頭に"//"追加必要
					fdata->hojo_flag |= H_MES16;
					if( b ) memcpy( buf, r_buf, b );	// b = "*/"位置
					buf[b] = 0;
				}
				strcat( w_buf, buf );
				ope_cnt++;
				fdata->tab_pos = 0;
				if( ope_cnt )
				{
					save_out_syori( 1 ); // 吐き出し+LF
					fdata->line_type = 0;
				}
			}
			r_pos = -1; // 1行処理終了
		}
		else { // 部分ｺﾋﾟｰ  "～ */"
			if( (form_cut_comment & BIT3) == 0 )
			{ // BIT3:ｺﾒﾝﾄ複数行(/*～, ～*/)を削除する
				if( form_long_comment < 2 )
				{ // 0:"/*"の連続のｺﾒﾝﾄ(変更なし)
					fdata->line_type = T_MES17; // 原文のまま
					fdata->hojo_flag |= H_MES17;
					memcpy( buf, r_buf, b + 2 );
					buf[b + 2] = 0;
				}
				else if( b == 0 )
				{
					fdata->line_type = T_CRLF;
					buf[0] = 0;
				}
				else { // 2:"/*"で始まる長い文章を"//"に変換する
					fdata->line_type = T_MES16; // 行頭に"// "追加必要
					fdata->hojo_flag |= H_MES16;
					memcpy( buf, r_buf, b );
					buf[b] = 0;
				}
				strcat( w_buf, buf );
				fdata->tab_pos = 0;
				save_out_syori( 1 ); // 吐き出し+LF
				fdata->line_type = 0;
			}
			b += 2;
			if( b >= CHAR_SIZE ) err_trap_line( 2, -14, 0 );	// "SUB buffer over"
			if( r_buf[b] ) strcpy( r_buf, &r_buf[b] );
			r_pos = 0;											// reset
			repeat_flag = 3;									// 再度 次から
		}
		if( comment_line == 2 && (fdata->hojo_flag & H_MASK_MES) == 0 )
		{ // ｺﾒﾝﾄからの終了で戻す
			store_comment( 0 ); // 0:pop, 2:この行はｺﾒﾝﾄ中
		}
		comment_line = 0;
	}
	else { // ----------- 複数行ｺﾒﾝﾄ -------------------
		if( (form_cut_comment & BIT3) == 0 )
		{ // BIT3:ｺﾒﾝﾄ複数行(/*～, ～*/)を削除する
			if( form_long_comment < 2 )
			{
				fdata->line_type = T_MES17; // 原文のまま
				fdata->hojo_flag |= H_MES17;
			}
			else {
				fdata->line_type = T_MES16; // 行頭に"// "追加必要
				fdata->hojo_flag |= H_MES16;
			}
			strcat( w_buf, r_buf ); // LFまで
			fdata->tab_pos = 0;
			save_out_syori( 1 );	// 吐き出し+LF
			fdata->line_type = 0;
		}
		r_pos = -1; // 1行処理終了
	}
}
// ---------------------------------------------------------------------
// #pragma endasm
// ---------------------------------------------------------------------
void comment_syori5( char *tok_buf, int *tok_len )
{
	fdata->tab_pos = 0;
	if( cur_moji_type == C_PRAGMA )
	{
		fdata->tab_pos = 0;
		if( comment_line == 2 && (fdata->hojo_flag & H_MASK_MES) == 0 )
		{ // ｺﾒﾝﾄからの終了で戻す
			store_comment( 0 ); // 0:pop, 2:この行はｺﾒﾝﾄ中
		}
		comment_line = 0; // endasamが無くても終わりとする
	}
	else {
		fdata->line_type = T_MES17;
		fdata->hojo_flag |= H_MES17;
		strcpy( w_buf, r_buf ); // そのままLFまで(ｽﾍﾟｰｽも)
		save_out_syori( 1 );	// 吐き出し+LF
		r_pos = -1;				// 1行処理終了
	}
}
// ---------------------------------------------------------------------
// #if, #defif, #defnif, #else, #elif, #enfif
// ---------------------------------------------------------------------
void defif_syori( char *tok_buf, int *tok_len )
{
	if( (ope_type & 0x0f) == 1 )
	{ // first
		if( (fdata->hojo_flag & H_MASK_MES) == 0 && ope_cnt )
		{
			save_out_syori( 1 );	// 吐き出し
			shift_r_buf( r_pos );	// r_bufのshift
			fdata->line_type = T_DEFIF;
		}
		if( ope_cnt ) strcat( w_buf, " " );
		strcat( w_buf, tok_buf );
		ope_cnt++;
		ope_type++;
	}
	else kyotu_syori( tok_buf ); // 続行 #if, #ifdef, #ifndef or #else 2回目以後
}
// ---------------------------------------------------------------------
// #endif
// ---------------------------------------------------------------------
void endif_syori( char *tok_buf, int *tok_len )
{
	if( (ope_type & 0x0f) == 1 )
	{ // first
		if( (fdata->hojo_flag & H_MASK_MES) == 0 && ope_cnt )
		{
			save_out_syori( 1 );	// 吐き出し
			shift_r_buf( r_pos );	// r_bufのshift
			fdata->line_type = T_DEF_END;
		}
		if( ope_cnt ) strcat( w_buf, " " );
		strcat( w_buf, tok_buf );
		ope_cnt++;
		ope_type++;
	}
	else kyotu_syori( tok_buf ); // 続行 2回目以後
}
// ---------------------------------------------------------------------
// #include
// ---------------------------------------------------------------------
void include_syori( char *tok_buf, int *tok_len )
{
	if( cur_moji_type == C_LF )
	{
		kyotu_syori( tok_buf ); // 改行
		ope_type = 0;			// reset
		r_pos = -1;				// 1行処理終了
	}
	else kyotu_syori( tok_buf );
}
// ---------------------------------------------------------------------
// "#define"
// ---------------------------------------------------------------------
void define_syori( char *tok_buf, int *tok_len )
{
	int flag;

#ifdef _DEBUG
	if( src_line_no >= 173 )
	{
		debug_n = r_buf[0];
	}
#endif
	switch( ope_type & 0x0f )
	{
	case 1: // "#define"
		if( ope_cnt )
		{ // 何もしない
			position_save( 4, T_DEFINE ); // 戻る
			kyotu_syori( tok_buf );
			return;
		}
		fdata->tab_pos = tab_pos;

		strcat( w_buf, tok_buf );
		ope_cnt++;
		kakko_cnt = 0;
		big_kakko_cnt = 0;
		finish_flag = 0;
		ope_type++; // 2回目
		break;

	case 2: // 2回目 宣言部
		if( form_define_tab == 0 )
		{ // 0:行最初のTABは変更しない, 1:TABなし(ｽﾍﾟｰｽのみ), 2:自動でTAB作成, 3～:最小TAB位置
			strcpy( w_buf, r_buf );		// 元をsave
			fdata->line_type = T_MES17; // 原文のまま
			fdata->hojo_flag |= H_MES17;
			fdata->tab_pos = 0;
			save_out_syori( 1 );		// 吐き出し+LF
			if( (fdata->hojo_flag & H_YEN2) == 0 ) position_save( 4, T_DEFINE ); // 戻る
			r_pos = -1;
			break;
		}
		if( cur_moji_type == C_LF )
		{
			if( big_kakko_cnt == 0 )
			{
				save_out_syori( 1 ); // 吐き出し+LF
				position_save( 4, T_DEFINE );
			}
			else kyotu_syori( tok_buf );
		}
		else { // 宣言 1:最適化する
			if( ope_cnt ) strcat( w_buf, " " ); // 定義部save
			strcat( w_buf, tok_buf );
			ope_cnt++;
			if( r_buf[r_pos] != ' ' && r_buf[r_pos] != _SOH && r_buf[r_pos] != _LF )
			{ // ｽﾍﾟｰｽなし
				r_pos += get_block( 0, tok_buf, &r_buf[r_pos], tok_len ); // 次を取り込み
				if( cur_moji_type == C_K_L )
				{
					strcat( w_buf, tok_buf );									// '(' ｽﾍﾟｰｽなし
					kakko_cnt++;
					ope_cnt++;
					// "()"の確認
					r_pos += get_block( 0, tok_buf, &r_buf[r_pos], tok_len );	// 次を取り込み
					if( cur_moji_type == C_K_R )
					{ // "()"の確認
						strcat( w_buf, tok_buf );
						kakko_cnt--;
						ope_cnt++;
					}
					else {
						repeat_flag = 1;
						ope_type += 2;
						break; // 続行
					}
				}
				else r_pos = before_r_pos; // 戻す
			}
			// 定義部との分離する
			before_c_type3 = before_c_type2 = 0;	// 3つ前へｼﾌﾄ
			before_c_type2 = before_c_type1 = 0;	// 2つ前へｼﾌﾄ
			before_c_type1 = cur_moji_type = 0;		// 1つ前へｼﾌﾄ
			cur_moji_type = tmp_moji_type = 0;		// set
		}
		ope_type++;
		break;

	case 3: // 3回目 定義部
		if( fdata->line_type == T_DEFINE )
		{
			if( cur_moji_type == C_LF )
			{
				save_out_syori( 1 ); // 吐き出し+LF
				if( big_kakko_cnt == 0 ) position_save( 4, T_DEFINE );
			}
			else kyotu_syori( tok_buf );
		}
		else { // 2行目以後
			if( form_define_tab == 0 )
			{ // 0:行最初のTABは変更しない, 1:TABなし(ｽﾍﾟｰｽのみ), 2:自動でTAB作成, 3～:最小TAB位置
				strcpy( w_buf, r_buf );		// 元をsave
				fdata->line_type = T_MES17; // 原文のまま
				fdata->hojo_flag |= H_MES17;
				fdata->tab_pos = 0;
				save_out_syori( 1 );		// 吐き出し+LF
				fdata->line_type = T_DEFINEX;
				if( (fdata->hojo_flag & H_YEN2) == 0 ) position_save( 4, T_DEFINE ); // 戻る
				r_pos = -1;
			}
			else if( cur_moji_type == C_LF )
			{
				save_out_syori( 1 ); // 吐き出し+LF
				fdata->line_type = T_DEFINEX;
				if( (fdata->hojo_flag & H_YEN2) == 0 ) position_save( 4, T_DEFINE ); // 戻る
			}
			else kyotu_syori( tok_buf );
		}
		break;

	case 4: // 最初の"()"の確認
#ifdef _DEBUG
		if( src_line_no >= 355 && ope_cnt >= 10 )
		{
			debug_n = r_buf[0];
		}
#endif

		if( cur_moji_type == C_LF )
		{
			save_out_syori( 1 ); // 吐き出し+LF
			fdata->line_type = T_DEFINE;
			if( (fdata->hojo_flag & H_YEN2) == 0 ) position_save( 4, T_DEFINE ); // 戻る
			else ope_type--;
		}
		else if( cur_moji_type == C_K_R && kakko_cnt == 1 )
		{ // 終わり
			strcat( w_buf, " " );		// ｽﾍﾟｰｽ
			strcat( w_buf, tok_buf );	// ')'
			kakko_cnt = 0;				// reset
			ope_cnt++;
			if( r_buf[r_pos] != ' ' && r_buf[r_pos] != _SOH && r_buf[r_pos] != _LF ) flag = 1; // 続きあり
			else flag = 0;								// 分離

			if( flag ) next_space_cut = 1;
			else {
				// 定義部との分離する
				before_c_type3 = before_c_type2 = 0;	// 3つ前へｼﾌﾄ
				before_c_type2 = before_c_type1 = 0;	// 2つ前へｼﾌﾄ
				before_c_type1 = cur_moji_type = 0;		// 1つ前へｼﾌﾄ
				cur_moji_type = tmp_moji_type = 0;		// set
				ope_type--;								// 分離は１つ戻る
			}
		}
		else kyotu_syori( tok_buf );
	}
}
// ---------------------------------------------------------------------
// "#pragma"で始まる
// ---------------------------------------------------------------------
void pragma_syori( char *tok_buf, int *tok_len )
{
	if( (ope_type & 0x0f) == 1 )
	{ // "#pragma"
		if( form_ifdef_mode == 0 ) fdata->tab_pos = tab_pos = 0;
		if( ope_cnt ) strcat( w_buf, " " );
		strcat( w_buf, tok_buf );
		ope_cnt++;
		kakko_cnt = 0;
		big_kakko_cnt = 0;
		finish_flag = 0;
		ope_type++; // 2回目へ
	}
	else if( (ope_type & 0x0f) == 2 )
	{ // parameta
		if( cur_moji_type == C_ASM )
		{
			if( ope_cnt ) strcat( w_buf, " " );
			strcat( w_buf, tok_buf );
			ope_type++; // 3回目へ
		}
		else {
			if( cur_moji_type == C_LF )
			{
				kyotu_syori( tok_buf ); // 改行
				ope_type = 0;			// reset
				r_pos = -1;				// 1行処理終了
			}
			else kyotu_syori( tok_buf );
		}
	}
	else if( (ope_type & 0x0f) == 3 )
	{ // LFまで待って endasm処理をする
		if( cur_moji_type == C_LF )
		{
			kyotu_syori( tok_buf ); // 改行
			fdata->line_type = 0;
			ope_type = 0;			// reset
			r_pos = -1;				// 1行処理終了
			if( comment_line == 2 && (fdata->hojo_flag & H_MASK_MES) == 0 )
			{ // ｺﾒﾝﾄからの終了で戻す
				store_comment( 0 ); // 0:pop, 2:この行はｺﾒﾝﾄ中
			}
			comment_line = 5;
		}
		else kyotu_syori( tok_buf );
	}
}
// ---------------------------------------------------------------------
// "#xxxxx"
// ---------------------------------------------------------------------
void define_another_syori( char *tok_buf, int *tok_len )
{
	int		type, len;
	char	buf[CHAR_SIZE], tmp_buf[CHAR_SIZE];

	if( (ope_type & 0x0f) == 1 )
	{ // "#xxxxx"
		if( fdata->line_type == T_DEF_ANO )
		{ // "# xxxxx"
			if( *tok_len == 1 )
			{
				strcpy( buf, tok_buf );
				r_pos += get_block( 1, tmp_buf, &r_buf[r_pos], &len ); // 次を取り込む
				if( tmp_moji_type != C_LF && tmp_moji_type )
				{
					sprintf( buf, "%s%s", tok_buf, tmp_buf );
					type = search_yoyaku( 1, buf, &len ); // 予約文字を探す, 1:全数一致
					if( type )
					{ // 一致
						strcpy( tok_buf, buf );
						*tok_len = strlen( tok_buf );
						cur_moji_type = type;
//						if( position_save(4, T_DEF_ANO) >= 0 ) repeat_flag = 1; // 4:一括戻る
						position_save( 4, T_DEF_ANO );
						fdata->line_type = 0;
						return;
					}
				}
			}
			strcpy( w_buf, r_buf );
			fdata->line_type = T_MES17; // 原文のまま
			fdata->hojo_flag |= H_MES17;
			fdata->tab_pos = 0;
			save_out_syori( 1 );		// 吐き出し+LF
			if( (fdata->hojo_flag & H_YEN2) == 0 ) position_save( 4, T_DEF_ANO ); // 戻る
			err_trap_line( 0, -33, 0 ); // "'#'が異常"
			r_pos = -1;
			return;
		}

		if( ope_cnt == 0 )
		{
			if( form_ifdef_mode == 0 ) fdata->tab_pos = 0;
		}
		else strcat( w_buf, " " );
		strcat( w_buf, tok_buf );
		ope_cnt++;
		r_pos += get_block( 2, tok_buf, &r_buf[r_pos], tok_len ); // 捨てる, CRLFの手前まで
		strcat( w_buf, tok_buf );
		ope_type++; // 2回目へ
	}
	else if( cur_moji_type == C_LF )
	{
		kyotu_syori( tok_buf ); // 改行
		ope_type = 0;			// reset
		r_pos = -1;				// 1行処理終了
	}
	else kyotu_syori( tok_buf );

}
// ---------------------------------------------------------------------
//	YENの有無を確認
// ---------------------------------------------------------------------
int chk_yen( char *s_buf )
{
	int		pos, tok_len, pos_cnt;
	char	tok_buf[CHAR_SIZE];

	pos_cnt = pos = 0;
	for(;;)
	{
		pos += get_block( 1, tok_buf, &s_buf[pos], &tok_len ); // 臨時で1 block取り込み
		if( (tmp_moji_type == C_COM1 && pos_cnt) || tmp_moji_type == C_LF || tmp_moji_type == 0 ) break;
		if( tmp_moji_type == C_YEN )
		{
			get_block( 1, tok_buf, &s_buf[pos], &tok_len );					// 臨時で1 block取り込み
			if( tmp_moji_type == C_LF || tmp_moji_type == 0 ) return( 1 );	// 有り
		}
		pos_cnt++;
	}
	return( 0 );
}
// ---------------------------------------------------------------------
int lenByte( unsigned char c )
{
	if( c < 0x80 ) return( 1 );
	else if( c < 0xE0 ) return( 2 );
	else if( c < 0xF0 ) return( 3 );
	return( 0 );
}
int lenUtf8( char *str )
{
	int i, n;
	int len = 0;

	for( i = 0; str[i] != '\0'; i++ )
	{
		len++;
		n = lenByte( str[i] );
		if( n == 0 ) break; // 違法文字
		i += n;
	}
	return( len );
}

// ---------------------------------------------------------------------
// 1行ｿｰｽを取り込む
// mode 0:行の連結用。1行を読み込むだけ
// mode 1:新規読み込み
// mode 2:1つ前のｿｰｽを取り込む
// ---------------------------------------------------------------------
void get_next_line( int mode )
{
	std::string srcUTF8, srcUTF8_out;
	static char r_buf_back[CHAR_SIZE2]; // 1つ前のｿｰｽ
	static int	back_ret;
	int			err_flag, len;

#ifdef _DEBUG
	if( max_line >= 4150 )
	{
		debug_n = r_buf[0];
	}
#endif

	r_pos = before_r_pos = 0;
	err_flag = 0;
	if( mode == 2 ) strcpy( r_buf, r_buf_back );	// 戻す
	else {
		len = getln( fp_src, r_buf, CHAR_SIZE );	// ﾌｧｲﾙから改行文字まで取り込む(CR+LF-->LF)
		if( len <= 0 ) err_flag = 1;				// end
		else if( r_buf[0] == 0x1a ) err_flag = 1;	// end
		if( font_type == 1 )
		{ // 0:自動, 1:utf8, 2:Shift JIS
			srcUTF8_out = UTF8toSjis( (std::string)r_buf );
			strcpy( r_buf, srcUTF8_out.c_str() );
		}
//		save_error_file( r_buf );		// 記録 zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz
		strcpy( r_buf_back, r_buf );	// 退避
		src_line_no++;
	}
	if( err_flag == 0 )
	{
		tab_to_soh( r_buf ); // TABを含む文字列をｽﾍﾟｰｽに置き換える
		if( mode != 0 )
		{
			disp_debug_para1();
			fdata->head_space_len = get_head_tab_pos( r_buf );	// 最初のTAB,ｽﾍﾟｰｽ以外の文字が見つかるまで
			fdata->src_line_no = src_line_no;					// 1番から
			if( chk_yen(r_buf) ) fdata->hojo_flag |= H_YEN1;	// 続行指定
			if( (fdata->hojo_flag & (H_YEN1 | H_YEN2)) == H_YEN1 )
			{
				position_save( -4, T_YEN ); // -4:一括戻るを登録
			}
			else if( (fdata->hojo_flag & (H_YEN1 | H_YEN2)) == H_YEN2 )
			{
				back_ret = 1; // 次で戻す
			}
			else if( back_ret )
			{ // 次で戻す
				position_save( 4, T_YEN ); // 一括戻す
				back_ret = 0;
			}
			else back_ret = 0;		// reset

			fdata->line_type = 0;	// reset
			// n個前をclear
			before_c_type3 = before_c_type2 = before_c_type1 = cur_moji_type = tmp_moji_type = 0;
			next_space_cut = 0;		// 次の文字でspaceを省略する
			repeat_flag = 0;		// 1:get_block()をしないで、同じﾃﾞｰﾀを使う, 2:架空の改行処理を追加する
		}
	}
	else r_buf[0] = 0;
}
// ---------------------------------------------------------------------
// ope_typeからline_typeを調べる
// return: line_type
// ---------------------------------------------------------------------
int get_line_type( void )
{
	if( (ope_type & T_MASK) == T_DEFIF ) return( T_DEFIF );
	if( (ope_type & T_MASK) == T_IF ) return( T_IF );
	if( (ope_type & T_MASK) == T_ELSE ) return( T_ELSE );
	if( (ope_type & T_MASK) == T_SWITCH ) return( T_SWITCH );
	if( (ope_type & T_MASK) == T_CASE ) return( T_CASE );
	if( (ope_type & T_MASK) == T_FOR ) return( T_FOR );
	if( (ope_type & T_MASK) == T_WHILE ) return( T_WHILE );
	if( (ope_type & T_MASK) == T_DO ) return( T_DO );
	if( (ope_type & T_MASK) == T_RETURN ) return( T_RETURN );
	if( (ope_type & T_MASK) == T_DEFINE ) return( T_DEFINE );
	if( (ope_type & T_MASK) == T_DEF_OTHER ) return( T_DEF_OTHER );
	if( (ope_type & T_MASK) == T_STRUCT ) return( T_STRUCT );
	if( (ope_type & T_MASK) == T_UNION ) return( T_UNION );
	if( (ope_type & T_MASK) == T_TYPE ) return( T_TYPE );
	return( T_OTHER );
}
// ---------------------------------------------------------------------
// if()
// ---------------------------------------------------------------------
void if_syori( char *tok_buf, int *tok_len )
{
#ifdef _DEBUG
	if( max_line >= 675 )
	{
		debug_n = tab_pos;
	}
#endif

	if( fdata->line_type == T_DEFINE )
	{
		position_save( 4, T_IF );	// 戻る. if()の終わり
		kyotu_syori( tok_buf );		// '()[]'などの共通処理
		return;
	}

	switch( ope_type )
	{
	case T_IF1: // 最初 if()
		if( ope_cnt ) strcat( w_buf, " " );
		else {
			fdata->tab_pos = tab_pos;
			store_if( -1 ); // save
		}
		strcat( w_buf, tok_buf );
		ope_cnt++;
		kakko_cnt = 0;
		big_kakko_cnt = 0;
		finish_flag = 0;
		ope_type++;
		break;

	default:
		big_kakko_syori3( form_if_big_kakko, tok_buf, tok_len ); // if(), else, for(), while(), do, switch, try の共通処理
		break;
	}
}
// ---------------------------------------------------------------------
// "else"
// ---------------------------------------------------------------------
void else_syori( char *tok_buf, int *tok_len )
{
	int		len;
	int		tmp_tab;
	char	buf[CHAR_SIZE];

#ifdef _DEBUG
	if( max_line >= 276 )
	{
		debug_n = tab_pos;
	}
#endif

	if( fdata->line_type == T_DEFINE )
	{
		position_save( 4, T_ELSE ); // 戻る. if()の終わり
		kyotu_syori( tok_buf );		// '()[]'などの共通処理
		return;
	}

	switch( ope_type )
	{
	case T_ELSE1: // 1回目
		if( fdata->line_type == T_ELSE )
		{
			tmp_tab = store_if( 2 );					// read
			if( tmp_tab >= 0 ) fdata->tab_pos = tab_pos = tmp_tab;
			else fdata->tab_pos = tab_pos;
			get_block( 1, buf, &r_buf[r_pos], &len );	// 次を取り込み
			if( tmp_moji_type == C_BIG_K_L ) fdata->line_type = T_ELSE_BIG;
			else if( tmp_moji_type == C_IF )
			{
				fdata->line_type = T_ELSE_IF;	// else if(
				store_if( -1 );					// save
			}
		}
		if( ope_cnt ) strcat( w_buf, " " );
		strcat( w_buf, tok_buf );
		ope_cnt++;
		kakko_cnt = 0;
		big_kakko_cnt = 0;
		finish_flag = 0;
		ope_type++;
		break;

	default:
		big_kakko_syori3( form_else_big_kakko, tok_buf, tok_len ); // if(), else, for(), while(), do, switch, try の共通処理
		break;
	}
}
// ---------------------------------------------------------------------
// switch()
// ---------------------------------------------------------------------
void switch_syori( char *tok_buf, int *tok_len )
{
	if( fdata->line_type == T_DEFINE )
	{
		position_save( 4, T_SWITCH );	// 戻る. if()の終わり
		kyotu_syori( tok_buf );			// '()[]'などの共通処理
		return;
	}
	switch( ope_type )
	{
	case T_SWITCH1: // 最初
		if( ope_cnt ) strcat( w_buf, " " );
		else fdata->tab_pos = tab_pos;
		strcat( w_buf, tok_buf );
		ope_cnt++;
		kakko_cnt = 0;
		big_kakko_cnt = 0;
		finish_flag = 0;
		ope_type++;
		break;

	default:
		big_kakko_syori3( form_switch_big_kakko, tok_buf, tok_len ); // if(), else, for(), while(), do, switch, try の共通処理
		break;

	}
}
// ---------------------------------------------------------------------
// switch文のcase/default
// ---------------------------------------------------------------------
void case_syori( char *tok_buf )
{
	int hojo_flag;

	if( ope_type == T_CASE1 || ope_type == T_DEFAULT1 )
	{ // "case" or "dafault"
		if( ope_cnt == 0 )
		{
			fdata->tab_pos = tab_pos - 1;
			if( fdata->tab_pos < 0 ) fdata->tab_pos = 0;
		}
		else strcat( w_buf, " " );
		strcat( w_buf, tok_buf );
		ope_cnt++;
		ope_type++; // next
	}
	else if( cur_moji_type == C_LF )
	{
		hojo_flag = fdata->hojo_flag;			// 一時退避
		if( ope_cnt ) kyotu_syori( tok_buf );	// 改行
		position_save( 4, T_CASE );				// 戻る
		if( tab_stack_cnt && (hojo_flag & (H_MASK_MES | H_YEN1 | H_YEN2)) == 0 ) repeat_flag = 1;
	}
	else kyotu_syori( tok_buf ); // '()[]'などの共通処理
}
// ---------------------------------------------------------------------
// for()
// ---------------------------------------------------------------------
void for_syori( char *tok_buf, int *tok_len )
{
	if( fdata->line_type == T_DEFINE )
	{
		position_save( 4, T_FOR );	// 戻る. if()の終わり
		kyotu_syori( tok_buf );		// '()[]'などの共通処理
		return;
	}
	switch( ope_type )
	{
	case T_FOR1: // 最初
		if( ope_cnt ) strcat( w_buf, " " );
		else fdata->tab_pos = tab_pos;
		strcat( w_buf, tok_buf );
		ope_cnt++;
		kakko_cnt = 0;
		big_kakko_cnt = 0;
		finish_flag = 0;
		ope_type++;
		break;

	default:
		big_kakko_syori3( form_for_big_kakko, tok_buf, tok_len ); // if(), else, for(), while(), do, switch, try の共通処理
		break;

	}
}
// ---------------------------------------------------------------------
// while()
// ---------------------------------------------------------------------
void while_syori( char *tok_buf, int *tok_len )
{
	if( fdata->line_type == T_DEFINE )
	{
		position_save( 4, T_WHILE );	// 戻る. if()の終わり
		kyotu_syori( tok_buf );			// '()[]'などの共通処理
		return;
	}
	switch( ope_type )
	{
	case T_WHILE1: // 最初
		if( ope_cnt ) strcat( w_buf, " " );
		else fdata->tab_pos = tab_pos;
		strcat( w_buf, tok_buf );
		ope_cnt++;
		kakko_cnt = 0;
		big_kakko_cnt = 0;
		finish_flag = 0;
		if( before_c_type1 == C_BIG_K_R ) fdata->line_type = T_DO;
		else fdata->line_type = T_WHILE;
		ope_type++;
		break;

	default:
		big_kakko_syori3( form_while_big_kakko, tok_buf, tok_len ); // if(), else, for(), while(), do, switch, try の共通処理
		break;

	}
}
// ---------------------------------------------------------------------
// do()
// ---------------------------------------------------------------------
void do_syori( char *tok_buf, int *tok_len )
{
	if( fdata->line_type == T_DEFINE )
	{
		position_save( 4, T_DO );	// 戻る. if()の終わり
		kyotu_syori( tok_buf );		// '()[]'などの共通処理
		return;
	}
	switch( ope_type )
	{
	case T_DO1: // 最初
		if( ope_cnt ) strcat( w_buf, " " );
		else fdata->tab_pos = tab_pos;
		strcat( w_buf, tok_buf );
		ope_cnt++;
		kakko_cnt = 0;
		big_kakko_cnt = 0;
		finish_flag = 0;
		ope_type++;
		break;

	default:
		big_kakko_syori3( form_do_big_kakko, tok_buf, tok_len ); // if(), else, for(), while(), do, switch, try の共通処理
		break;

	}
}
// ---------------------------------------------------------------------
// try {
// ---------------------------------------------------------------------
void try_syori( char *tok_buf, int *tok_len )
{
	if( fdata->line_type == T_DEFINE )
	{
		position_save( 4, T_TRY );	// 戻る. if()の終わり
		kyotu_syori( tok_buf );		// '()[]'などの共通処理
		return;
	}
	switch( ope_type )
	{
	case T_TRY1: // 最初
		if( ope_cnt ) strcat( w_buf, " " );
		else fdata->tab_pos = tab_pos;
		strcat( w_buf, tok_buf );
		ope_cnt++;
		kakko_cnt = 0;
		big_kakko_cnt = 0;
		finish_flag = 0;
		ope_type++;
		break;

	default:
		big_kakko_syori3( form_try_big_kakko, tok_buf, tok_len ); // if(), else, for(), while(), do, switch, try の共通処理
		break;

	}
}
// ---------------------------------------------------------------------
// '<' 未使用
// ---------------------------------------------------------------------
void shl_syori( char *tok_buf, int *tok_len )
{
	int		len;
	char	buf[CHAR_SIZE];

//	if( fdata->line_type == T_DEFINE )
//	{
//		position_save( 4, T_SHL );	// 戻る. if()の終わり
//		kyotu_syori( tok_buf );		// '()[]'などの共通処理
//		return;
//	}
	switch( ope_type )
	{
	case T_SHL1: // 最初
		if( before_c_type1 != C_INCLUDE && chk_cpluss() )
		{ // C++ｺﾏﾝﾄﾞ"<...>"の記述確認
//			if( ope_cnt ) strcat( w_buf, " " );
			strcat( w_buf, tok_buf );
			ope_cnt++;
			ope_type++;
		}
		else {
			position_save( 4, T_SHL );	// 戻る. if()の終わり
			kyotu_syori( tok_buf );		// '()[]'などの共通処理
		}
		break;

	default:
		kyotu_syori( tok_buf ); // '()[]'などの共通処理
		if( cur_moji_type == C_SHR )
		{
			position_save( 4, T_SHL ); // 戻る. if()の終わり
			if( r_buf[r_pos] != _SOH && r_buf[r_pos] != ' ' )
			{ // 判定が難しいので,ｿｰｽに依存する
				get_block( 1, buf, &r_buf[r_pos], &len ); // 臨時で1 block取り込み
				if( tmp_moji_type == C_KOME || tmp_moji_type == C_W_KOME || tmp_moji_type == C_AND ) next_space_cut = 1;
			}
		}
		break;

	}
}
// ---------------------------------------------------------------------
// struct
// ---------------------------------------------------------------------
void struct_syori( char *tok_buf, int *tok_len )
{
	if( fdata->line_type == T_DEFINE )
	{
		position_save( 4, T_STRUCT );	// 戻る. if()の終わり
		kyotu_syori( tok_buf );			// '()[]'などの共通処理
		return;
	}
	switch( ope_type )
	{
	case T_STRUCT1: // 最初
		fdata->hojo_flag |= H_STRUCT;
		if( (ope_cnt == 0 || fdata->line_type == T_TYPEDEF || fdata->line_type == T_OTHER) && kakko_cnt == 0 )
		{ // 定義
//			if( fdata->line_type == T_TYPEDEF ) fdata->line_type = T_STRUCT;
			fdata->line_type = T_STRUCT;
			if( ope_cnt ) strcat( w_buf, " " );
			else fdata->tab_pos = tab_pos;
			strcat( w_buf, tok_buf );
			ope_cnt++;
			big_kakko_cnt = 0;
			finish_flag = 0;
			ope_type++;
		}
		else { // program中
			position_save( 4, T_STRUCT );	// 戻る
			kyotu_syori( tok_buf );			// '()[]'などの共通処理
		}
		break;

	default:
//		if( (fdata->hojo_flag & H_STRUCT) == 0 )
//		{ // struct ---> proc に変更
//			big_kakko_syori3( 2, tok_buf, tok_len ); // if(), else, for(), while(), do, switch, try の共通処理
//		}
//		else
		big_kakko_syori3( form_struct_big_kakko, tok_buf, tok_len ); // if(), else, for(), while(), do, switch, ry の共通処理
		break;

	}
}
// ---------------------------------------------------------------------
// union
// ---------------------------------------------------------------------
void union_syori( char *tok_buf, int *tok_len )
{
	if( fdata->line_type == T_DEFINE )
	{
		position_save( 4, T_UNION );	// 戻る. if()の終わり
		kyotu_syori( tok_buf );			// '()[]'などの共通処理
		return;
	}
	switch( ope_type )
	{
	case T_UNION1: // 最初
		fdata->hojo_flag |= H_UNION;
//		if( ope_cnt == 0 || fdata->line_type == T_TYPEDEF )
		if( (ope_cnt == 0 || fdata->line_type == T_TYPEDEF || fdata->line_type == T_OTHER) && kakko_cnt == 0 )
		{ // 定義
//			if( fdata->line_type == T_TYPEDEF ) fdata->line_type = T_UNION;
			fdata->line_type = T_UNION;
			if( ope_cnt ) strcat( w_buf, " " );
			else fdata->tab_pos = tab_pos;
			strcat( w_buf, tok_buf );
			ope_cnt++;
			big_kakko_cnt = 0;
			finish_flag = 0;
			ope_type++;
		}
		else { // program中
			position_save( 4, T_UNION );	// 戻る
			kyotu_syori( tok_buf );			// '()[]'などの共通処理
		}
		break;

	default:
		big_kakko_syori3( 0, tok_buf, tok_len ); // if(), else, for(), while(), do, switch, try の共通処理
		break;

	}
}
// ---------------------------------------------------------------------
// 外側が括弧でくくられているかの検査
// return 0:括弧不要
// return 1:括弧必要
// ---------------------------------------------------------------------
int chk_return_kakko( char *s_buf )
{
	int		pos, k_cnt, len, mode, end_mark;
	char	buf[CHAR_SIZE];

	end_mark = 0;
	pos = k_cnt = 0;
	mode = 0;
	for(;;)
	{
		pos += get_block( 1, buf, &s_buf[pos], &len ); // 次を取り込み
		if( tmp_moji_type == 0 || tmp_moji_type == C_LF ) break;
		if( mode == 0 )
		{ // first
			if( tmp_moji_type == C_COM1 ) break;
			if( tmp_moji_type == C_SEMIKOLON )
			{
				end_mark = BIT2; // end mark
				break;
			}
			else if( tmp_moji_type == C_K_L )
			{ // 最初が'('
				k_cnt++;
				end_mark = BIT0;
			}
			else if( tmp_moji_type == C_K_R ) k_cnt--;
			mode = 1;
		}
		else if( mode == 1 )
		{
			if( tmp_moji_type == C_COM1 ) break;
			if( tmp_moji_type == C_SEMIKOLON )
			{
				end_mark |= BIT2; // end mark
				break;
			}
			else if( tmp_moji_type == C_COM2 ) mode = 2;
			else if( tmp_moji_type == C_K_L )
			{
				k_cnt++;						// 2回目以後
				end_mark &= ~( BIT1 | BIT2 );	// reset
			}
			else if( tmp_moji_type == C_K_R )
			{
				if( --k_cnt == 0 && (end_mark & BIT0) ) end_mark |= BIT1; // set
			}
			else {
				if( k_cnt == 0 ) end_mark = 0;		// reset
				else end_mark &= ~( BIT1 | BIT2 );	// reset
			}
		}
		else {
			if( tmp_moji_type == C_COM3 ) mode--; // 戻る
		}
	}
	if( end_mark >= 4 && end_mark <= 6 ) return( 1 );	// 括弧必要
	else return( 0 );									// 括弧不要
}
// ---------------------------------------------------------------------
// return処理
// ---------------------------------------------------------------------
void return_syori( char *tok_buf, int *tok_len )
{
	int hojo_flag, back_line_type;

#ifdef _DEBUG
	if( max_line >= 9099 )
	{
		debug_n = tab_pos;
	}
#endif

	if( fdata->line_type == T_DEFINE || fdata->line_type == T_B_K_PAIR )
	{
		position_save( 4, T_RETURN );	// 戻る.
		kyotu_syori( tok_buf );			// '()[]'などの共通処理
		ope_type = 0;
		return;
	}

//	if( ope_cnt == 0 ) fdata->tab_pos = tab_pos; // zzzzzzzzzzzzzzzzzzzzzzzzzzz
	if( before_type != T_IF && before_type != T_ELSE && ope_cnt == 0 ) fdata->tab_pos = tab_pos; // 戻す2020.03.24
	switch( ope_type )
	{
	case T_RETURN1: // 初回
//		if( kakko_cnt )
//		{
//			position_save( 4, T_RETURN );	// 戻る.
//			kyotu_syori( tok_buf );			// '()[]'などの共通処理
//			return;
//		}
		if( ope_cnt ) strcat( w_buf, " " );
		strcat( w_buf, tok_buf );
		kakko_cnt = 0;
		ope_cnt++;
		finish_flag = 0;
		ope_type = T_RETURN2;
		break;

	case T_RETURN2: // 2回目
		if( cur_moji_type == C_LF && kakko_cnt == 0 && (fdata->hojo_flag & (H_MASK_MES | H_MES_E | H_YEN1 | H_YEN2)) == 0 )
		{
			back_line_type = fdata->line_type;
			while( cur_moji_type == C_LF )
			{ // ---------- 改行を無視 ------------------
				get_next_line( 1 );											// 一時読み込み
				r_pos += get_block( 0, tok_buf, &r_buf[r_pos], tok_len );	// 次を取り込み
				if( *tok_len == 0 ) break;
			}
			fdata->line_type = back_line_type;
			if( *tok_len == 0 )
			{
				err_trap_line( 0, -30, "return" );	// ""改行後の読み出しが出来ない"
				if( ope_cnt ) save_out_syori( 1 );	// 吐き出し+LF 続行
				r_pos = -1;							// 異常終了
				break;
			}
		}
		if( cur_moji_type == C_SEMIKOLON || chk_return_kakko(&r_buf[before_r_pos]) == 0 || (fdata->hojo_flag & H_MASK_MES) )
		{ //  "(～)"不要
			kyotu_syori( tok_buf );
			ope_type = T_RETURN3;
		}
		else { // '('追加
			strcat( w_buf, "(" );
			before_c_type3 = before_c_type2;			// 3つ前へｼﾌﾄ
			before_c_type2 = before_c_type1;			// 2つ前へｼﾌﾄ
			before_c_type1 = C_K_L;						// 1つ前へｼﾌﾄ
			kakko_cnt++;
			ope_cnt++;
			if( form_kakko_space ) next_space_cut = 1;	// ｽﾍﾟｰｽなし
			kyotu_syori( tok_buf );
			ope_type = T_RETURN4;						// ')'を追加へ
		}
		break;

	case T_RETURN3: // ()の追加なし
		if( cur_moji_type == C_LF )
		{
#ifdef _DEBUG
			if( max_line >= 91 )
			{
				debug_n = tab_pos;
			}
#endif

			hojo_flag = fdata->hojo_flag; // 退避
			if( ope_cnt )
			{
				save_out_syori( 1 );	// 吐き出し+LF 続行
//				kyotu_syori( tok_buf ); // 改行
				fdata->line_type = 0;
			}
			if( finish_flag || (hojo_flag & H_MASK_MES) )
			{
//				n = tab_stack_cnt;
//				if( n != tab_stack_cnt ) repeat_flag = 1;				// 一括戻りならnext
				if( position_save(4, T_RETURN) >= 0 ) repeat_flag = 1;	// 一括戻りならnext
				finish_flag = 1;
			}
			else {
				fdata->line_type = T_RETURN;
				fdata->tab_pos = tab_pos + 1;
			}
		}
//		else if( cur_moji_type == C_BIG_K_R )
//		{ // '}'
//			if( (fdata->hojo_flag & (H_MASK_MES | H_YEN1 | H_YEN2 | H_B_K_PAIR)) == 0 && ope_cnt )
//			{ // 改行 + '{'
//				save_out_syori( 1 );								// 吐き出し+LF
//				shift_r_buf( r_pos - 1 );							// r_bufのshift
//				r_pos = get_block( 0, tok_buf, r_buf, tok_len );	// 次取り込み
//			}
//			kyotu_syori( tok_buf ); // '()[]'などの共通処理
//		}
		else kyotu_syori( tok_buf );
		break;

	case T_RETURN4: // 最後の')'追加
		if( cur_moji_type == C_SEMIKOLON )
		{
			if( kakko_cnt == 1 )
			{
				if( form_kakko_space ) strcat( w_buf, ");" );
				else strcat( w_buf, " );" );
				before_c_type3 = before_c_type2;	// 3つ前へｼﾌﾄ
				before_c_type2 = before_c_type1;	// 2つ前へｼﾌﾄ
				before_c_type1 = C_SEMIKOLON;		// 1つ前へｼﾌﾄ
				kakko_cnt = 0;
			}
			else {
				err_trap_line( 0, -23, "return" ); // "';'が異常"
				strcat( w_buf, ";" );
				ope_cnt++;
				kakko_cnt = 0;
				ope_type = T_RETURN3;
			}
			finish_flag = 1;
		}
		else if( cur_moji_type == C_LF )
		{
			if( kakko_cnt == 1 )
			{
				if( form_kakko_space ) strcat( w_buf, ")" );
				else strcat( w_buf, " )" );
				ope_cnt++;
				before_c_type3 = before_c_type2;	// 3つ前へｼﾌﾄ
				before_c_type2 = before_c_type1;	// 2つ前へｼﾌﾄ
				before_c_type1 = C_K_R;				// 1つ前へｼﾌﾄ
				kakko_cnt = 0;
				if( (ope_type & T_DEFIF) == 0 &&
					(fdata->hojo_flag & (H_MASK_MES | H_YEN1 | H_YEN2)) == 0 && finish_flag == 0 )
				{
					err_trap_line( 0, -23, "return" );	// "';'が異常"
					finish_flag = 1;					// dummy
				}
			}
			if( ope_cnt )
			{
//				save_out_syori( 1 );	// 吐き出し+LF 続行
				kyotu_syori( tok_buf ); // 改行
				fdata->line_type = 0;
			}

			if( finish_flag )
			{
				if( position_save(4, T_RETURN) >= 0 ) repeat_flag = 1; // 一括戻りならnext
				finish_flag = 1;
			}
			else {
				fdata->line_type = T_RETURN;
				fdata->tab_pos = tab_pos + 1;
			}
		}
		else {
			if( cur_moji_type == C_BIG_K_R )
			{
				if( position_save(4, T_RETURN) >= 0 ) repeat_flag = 1; // 一括戻りならnext
				finish_flag = 1;
			}
			kyotu_syori( tok_buf );
		}
		break;
	}
}
// ---------------------------------------------------------------------
// 予約語の検査
// ---------------------------------------------------------------------
void chk_yoyaku( char *tok_buf )
{
	switch( cur_moji_type )
	{
	case C_TYPEDEF: // "typedef"
		if( fdata->line_type == 0 && kakko_cnt == 0 ) fdata->line_type = T_TYPEDEF;
		break;

	case C_EXTERN: // "extern"
//		if( ope_cnt == 0 ) fdata->hojo_flag |= H_EXTERN;
		break;

	case C_STRUCT: // "struct"
		position_save( -4, T_STRUCT ); // -1:登録
		ope_type = T_STRUCT1;
		finish_flag = 0;
		if( fdata->line_type == 0 && kakko_cnt == 0 ) fdata->line_type = T_STRUCT;
		break;

	case C_UNION: // "union"
		position_save( -4, T_UNION ); // -1:登録
		ope_type = T_UNION1;
		finish_flag = 0;
		if( fdata->line_type == 0 && kakko_cnt == 0 ) fdata->line_type = T_UNION;
		break;

	case C_IF:
		position_save( -4, T_IF ); // -1:登録
		ope_type = T_IF1;
		finish_flag = 0;
		if( fdata->line_type == 0 && kakko_cnt == 0 ) before_type = fdata->line_type = T_IF;
		break;

	case C_ELSE:
		position_save( -4, T_ELSE ); // -1:登録
		ope_type = T_ELSE1;
		finish_flag = 0;
		if( fdata->line_type == 0 && kakko_cnt == 0 ) before_type = fdata->line_type = T_ELSE;
		break;

	case C_SWITCH:
		position_save( -4, T_SWITCH ); // -1:登録
		ope_type = T_SWITCH1;
		finish_flag = 0;
		if( fdata->line_type == 0 && kakko_cnt == 0 ) fdata->line_type = T_SWITCH;
		break;

	case C_CASE:
		position_save( -4, T_CASE ); // -1:登録
		ope_type = T_CASE1;
		finish_flag = 0;
		if( fdata->line_type == 0 && kakko_cnt == 0 ) fdata->line_type = T_CASE;
		break;

	case C_DEFAULT:
		position_save( -4, T_CASE ); // -1:登録
		ope_type = T_DEFAULT1;
		finish_flag = 0;
		if( fdata->line_type == 0 && kakko_cnt == 0 ) fdata->line_type = T_CASE;
		break;

	case C_FOR:
		position_save( -4, T_FOR ); // -1:登録
		ope_type = T_FOR1;
		finish_flag = 0;
		if( fdata->line_type == 0 && kakko_cnt == 0 ) fdata->line_type = T_FOR;
		break;

	case C_WHILE:
		position_save( -4, T_WHILE ); // -1:登録
		ope_type = T_WHILE1;
		finish_flag = 0;
		if( fdata->line_type == 0 && kakko_cnt == 0 ) fdata->line_type = T_WHILE;
		break;

	case C_DO:
		position_save( -4, T_DO ); // -1:登録
		ope_type = T_DO1;
		finish_flag = 0;
		if( fdata->line_type == 0 && kakko_cnt == 0 ) fdata->line_type = T_DO;
		break;

	case C_TRY:
		position_save( -4, T_TRY ); // -1:登録
		ope_type = T_TRY1;
		finish_flag = 0;
		if( fdata->line_type == 0 && kakko_cnt == 0 ) fdata->line_type = T_TRY;
		break;

	case C_SHL: // temlate<...> など
		position_save( -4, T_SHL ); // -1:登録
		ope_type = T_SHL1;
		if( fdata->line_type == 0 && kakko_cnt == 0 ) fdata->line_type = T_SHL;
		break;

	case C_RETURN:
		position_save( -4, T_RETURN ); // -1:登録
		ope_type = T_RETURN1;
		finish_flag = 0;
		if( fdata->line_type == 0 && kakko_cnt == 0 ) fdata->line_type = T_RETURN;
		break;

	case C_DEFINE:
		position_save( -4, T_DEFINE ); // -1:登録
		ope_type = T_DEFINE1;
		finish_flag = 0;
		if( fdata->line_type == 0 && kakko_cnt == 0 ) fdata->line_type = T_DEFINE;
		break;

	case C_PRAGMA: // "#pragma"
		if( ope_cnt ) cur_moji_type = C_OTHER; // 一般に変更
		else {
			ope_type = T_PRAGMA1;
			if( fdata->line_type == 0 && kakko_cnt == 0 ) fdata->line_type = T_PRAGMA;
		}
		break;

	case C_DEF_OTHER:	// "#xxxx"
	case C_UNDEF:		// "#undef"
		if( ope_cnt ) cur_moji_type = C_OTHER; // 一般に変更
		else {
			ope_type = T_DEF_OTHER1;
			if( fdata->line_type == 0 && kakko_cnt == 0 ) fdata->line_type = T_DEF_OTHER; // その他
		}
		break;

	case C_INCLUDE:		// "#include"
//	case C_TEMPLATE:	// "template"
		if( ope_cnt ) cur_moji_type = C_OTHER;	// 一般に変更
		else {
			ope_type = T_INCLUDE1;				// 2013.11.18
			if( fdata->line_type == 0 && kakko_cnt == 0 ) fdata->line_type = T_INCLUDE;
		}
		break;

	case C_DEF_ANOTHER: // "#xxxx" or "# "
		if( ope_cnt ) cur_moji_type = C_OTHER;											// 一般に変更
		else {
//			if( fdata->line_type == 0 && kakko_cnt == 0 ) fdata->line_type = T_DEF_ANO; // その他
			if( fdata->line_type == 0 )
			{
				position_save( -4, T_DEF_ANO ); // -4:一括戻るを登録
				ope_type = T_DEF_ANO1;
				fdata->line_type = T_DEF_ANO;	// その他
				finish_flag = 0;
				if( form_ifdef_mode == 0 ) fdata->tab_pos = 0;
				else tab_pos++;
			}
		}
		break;

	default:
		if( cur_moji_type & C_MASK_DEFIF )
		{
			if( cur_moji_type == C_DEF_IF || cur_moji_type == C_IFDEF || cur_moji_type == C_IFNDEF )
			{ // #if, #ifdef, #ifndef
				position_save( -4, T_DEFIF ); // -4:一括戻るを登録
				fdata->line_type = T_DEFIF;
				finish_flag = 0;
				if( form_ifdef_mode == 0 ) fdata->tab_pos = 0;
				else tab_pos++;
			}
			else if( cur_moji_type == C_DEF_ELSE || cur_moji_type == C_ELIF )
			{ // #else
				position_save( 4, T_DEFIF );	// 一括戻る
				position_save( -4, T_DEFIF );	// -4:一括戻るを登録
				fdata->line_type = T_DEFIF;
				finish_flag = 0;
				if( form_ifdef_mode == 0 ) fdata->tab_pos = 0;
				else tab_pos++;
			}
			else if( cur_moji_type == C_ENDIF )
			{ // #endif
				position_save( 4, T_DEFIF ); // 一括戻る
				fdata->line_type = T_DEFIF;
				finish_flag = 0;
				if( form_ifdef_mode == 0 ) fdata->tab_pos = 0;
			}
		}
		else if( cur_moji_type & (C_MASK_TYPE1 | C_MASK_TYPE2) )
		{ // "int,short,long" etc
			if( fdata->line_type == 0 && ope_cnt == 0 ) fdata->line_type = T_TYPE;
		}
		else if( cur_moji_type == C_WMOJI || cur_moji_type == C_SMOJI )
		{
			if( fdata->line_type == 0 )
			{
				fdata->line_type = T_MOJIS; // 文字列 実際には、ｺﾒﾝﾄ内で使うので単独では存在しない
//				if( finish_flag == 0 ) fdata->tab_pos++;
			}
		}
		break;
	}
}
// ---------------------------------------------------------------------
// 行の分類と文を分離する
// ---------------------------------------------------------------------
void refresh( void )
{
	int		tok_len, n;
	char	tok_buf[CHAR_SIZE]; // 切り出しbuf

	back_line_type = 0;
	crlf_cnt = 0;		// 行のはじめ
	space_cut_flag = 0; // pointer
	kakko_cnt = 0;		// 括弧の数. '('で+1, ')'で-1
	big_kakko_cnt = 0;
	ope_cnt = 0;		// 1行の処理数.TAB space挿入のｶｳﾝﾀ
	ope_type = 0;		// 実行中の命令
	tab_pos = 0;
	tab_stack_cnt = 0;
	src_line_no = 0;
	finish_flag = 0;
	r_pos = 0;
	w_buf[0] = 0;
	for(;;)
	{
		get_next_line( 1 ); // ﾌｧｲﾙから改行文字まで取り込む(CR+LF-->LF)
		if( r_buf[0] == 0 ) break;
		// ---------------- 1行処理 -----------------------------
		while( r_pos >= 0 )
		{
			if( repeat_flag == 1 ) repeat_flag = 0;							// 同じ部分を繰り返す
			else {
				if( repeat_flag == 2 ) r_pos = before_r_pos;				// 1つ前を繰り返す
				repeat_flag = 0;

				r_pos += get_block( 0, tok_buf, &r_buf[r_pos], &tok_len );	// 次を取り込み

#ifdef _DEBUG
				if( src_line_no >= 7817 )
				{
					if( cur_moji_type == C_LF )
					{
						debug_n = fdata->line_type;
						debug_n = fdata->tab_pos;
					}
				}
#endif

				if( r_pos >= CHAR_SIZE ) err_trap_line( 2, -13, 0 );	// "TOK buffer over"
				if( tok_len == 0 ) break;								// 1行終わり
				else if( ope_cnt == 0 && tok_len == 1 && cur_moji_type == C_LF )
				{ // 連続のLFは削除
					if( ++crlf_cnt < 2 ) save_out_syori( 3 ); // LF
					break;
				}
				else crlf_cnt = 0; // 行のはじめ
			}

			if( comment_line == 4 )
			{ // "//"なしのｺﾒﾝﾄ中
				comment_syori4( tok_buf, &tok_len ); // "*/"まで
				if( r_pos < 0 ) break;
				if( repeat_flag ) continue;
			}
			else if( comment_line == 5 )
			{ // #pragma endasm待ち
				comment_syori5( tok_buf, &tok_len );
				if( r_pos < 0 ) break;
				if( repeat_flag ) continue;
			}
			else if( cur_moji_type )
			{
				if( cur_moji_type == C_COM2 )
				{ // "/*"
					comment_syori2( tok_buf, &tok_len ); // "*/"まで
					if( r_pos < 0 ) break;
					if( repeat_flag ) continue;
				}
				else if( cur_moji_type == C_COM1 )
				{ // "//"
					comment_syori1( tok_buf, &tok_len ); // CR,LFまで
					if( r_pos < 0 ) break;
					if( repeat_flag ) continue;
				}

				if( cur_moji_type == C_YEN )
				{
					if( ope_cnt ) strcat( w_buf, " " );
//					fdata->hojo_flag |= H_YEN1; // 続行指定
					strcat( w_buf, tok_buf );	// '\'
					ope_cnt++;
					continue;
				}
				else if( ope_cnt == 0 && (cur_moji_type == C_OTHER || cur_moji_type == C_INT) )
				{ // assemblerの検査
					if( chk_asm() ) fdata->hojo_flag |= H_ASM;
//					if( chk_asm() ) fdata->line_type = T_ASM;
				}
			}

			if( tok_len != 1 || cur_moji_type != C_LF )
			{
				if( comment_line == 2 && (fdata->hojo_flag & H_MASK_MES) == 0 )
				{ // ｺﾒﾝﾄからの終了で戻す
					store_comment( 0 ); // 0:pop, 2:この行はｺﾒﾝﾄ中
				}
			}

			if( (ope_type & (T_DEFINE | T_DEF_OTHER)) == 0 )
			{
				if( (fdata->line_type & T_MASK_MES) == 0 )
				{
					chk_yoyaku( tok_buf );
				}
			}

			switch( ope_type )
			{
			default:
				if( fdata->line_type == T_TYPE )
				{
					if( (tab_pos == 0 && form_global_int_tab == 0) ||
						(tab_pos != 0 && form_local_int_tab == 0) )
					{
						strcpy( w_buf, r_buf );		// 元をsave
						fdata->line_type = T_MES17; // 原文のまま
						fdata->hojo_flag |= H_MES17;
						fdata->tab_pos = 0;
						save_out_syori( 1 );		// 吐き出し+LF
						r_pos = -1;
						break;
					}
				}
				ope_type = 0; // ope_type++の時の対策
			case 0:
				kyotu_syori( tok_buf );
				if( ope_type && (cur_moji_type != C_BIG_K_L && cur_moji_type != C_BIG_K_R) ) err_trap_line( 0, -31, tok_buf ); // "For debug"
				if( repeat_flag ) err_trap_line( 0, -32, tok_buf ); // "for debug"
				break;

			case T_DEF_IF1:		// #if, #ifdef, #ifndef
			case T_DEF_IF2:		// #if, #ifdef, #ifndef
			case T_DEF_ELSE1:	// #else
			case T_DEF_ELSE2:	// #else
				defif_syori( tok_buf, &tok_len );
				break;

			case T_DEF_END1: // #endif
			case T_DEF_END2: // #endif
				endif_syori( tok_buf, &tok_len );
				break;

			case T_INCLUDE1: // "#include"
			case T_INCLUDE2:
				include_syori( tok_buf, &tok_len );
				break;

			case T_DEFINE1:
			case T_DEFINE2:
			case T_DEFINE3:
			case T_DEFINE4:
				define_syori( tok_buf, &tok_len );
				break;

			case T_PRAGMA1:
			case T_PRAGMA2:
			case T_PRAGMA3:
				pragma_syori( tok_buf, &tok_len );
				break;

			case T_DEF_OTHER1:	// #xxxxx
			case T_DEF_OTHER2:
			case T_DEF_OTHER3:
			case T_DEF_ANO1:	// # xxxxx
				define_another_syori( tok_buf, &tok_len );
				if( r_pos < 0 ) break;
				if( repeat_flag ) continue;
				break;

			case T_IF1:
			case T_IF2:
			case T_IF3:
			case T_IF4:
			case T_IF5:
			case T_IF6:
				if_syori( tok_buf, &tok_len );
				break;

			case T_ELSE1:
			case T_ELSE2:
			case T_ELSE3:
			case T_ELSE4:
			case T_ELSE5:
			case T_ELSE6:
				else_syori( tok_buf, &tok_len );
				break;

			case T_SWITCH1:
			case T_SWITCH2:
			case T_SWITCH3:
			case T_SWITCH4:
			case T_SWITCH5:
			case T_SWITCH6:
				switch_syori( tok_buf, &tok_len );
				break;

			case T_CASE1:
			case T_CASE2:
			case T_CASE3:
			case T_DEFAULT1:
			case T_DEFAULT2:
			case T_DEFAULT3:
				case_syori( tok_buf );
				break;

			case T_FOR1:
			case T_FOR2:
			case T_FOR3:
			case T_FOR4:
			case T_FOR5:
			case T_FOR6:
				for_syori( tok_buf, &tok_len );
				break;

			case T_WHILE1:
			case T_WHILE2:
			case T_WHILE3:
			case T_WHILE4:
			case T_WHILE5:
			case T_WHILE6:
				while_syori( tok_buf, &tok_len );
				break;

			case T_DO1:
			case T_DO2:
			case T_DO3:
			case T_DO4:
			case T_DO5:
			case T_DO6:
				do_syori( tok_buf, &tok_len );
				break;

			case T_TRY1:
			case T_TRY2:
			case T_TRY3:
			case T_TRY4:
			case T_TRY5:
			case T_TRY6:
				try_syori( tok_buf, &tok_len );
				break;

			case T_SHL1:
			case T_SHL2:
				shl_syori( tok_buf, &tok_len );
				break;

			case T_RETURN1:
			case T_RETURN2:
			case T_RETURN3:
			case T_RETURN4:
				return_syori( tok_buf, &tok_len );
				break;

			case T_STRUCT1:
			case T_STRUCT2:
			case T_STRUCT3:
			case T_STRUCT4:
			case T_STRUCT5:
			case T_STRUCT6:
				struct_syori( tok_buf, &tok_len );
				break;

			case T_UNION1:
			case T_UNION2:
			case T_UNION3:
			case T_UNION4:
			case T_UNION5:
			case T_UNION6:
				union_syori( tok_buf, &tok_len );
				break;

			}
		}
		if( w_buf[0] )
		{
			n = strlen( w_buf ) - 1;
			if( w_buf[n] == _LF )
			{
				save_out_syori( 1 );			// 吐き出し
				err_trap_line( 0, -34, w_buf ); // "プログラム異常" for debug
			}
		}
	}
	if( comment_line == 4 ) err_trap_line( 0, -32, 0 );			// "'*/'がない"
	else if( comment_line == 5 ) err_trap_line( 0, -35, 0 );	// "#pragram endasm がない"
	if( comment_line ) store_comment( 0 );						// 0:pop
	if( tab_pos )
	{
		sprintf( tok_buf, "tab=%d", tab_pos );
		err_trap_line( 0, -24, tok_buf ); // "ﾌｧｲﾙ最後のTAB位置が異常"
	}
	if( tab_stack_cnt )
	{
		sprintf( tok_buf, "tab=%d", tab_stack_cnt );
		err_trap_line( 0, -27, tok_buf ); // "TAB stackが異常"
	}
}
