// ---------------------------------------------------------------------
// main.cpp
// C��۸��т����₷������
// Visual-C

// 2009.04.22	V1.00	�V�K�쐬
// 2009.04.22	V1.01	paramer��debug
// 2009.04.24	V1.02	"#if"�����̕���
// 2009.04.27	V1.03	"#include"��TAB�֎~����.
// 2009.04.28	V1.04	"/*"�`"*/"--> "//"�`�̵�߼�ݎw��ǉ�
// 2009.04.28	V1.04	"renew.ini"̧�ق������쐬�ǉ�
// 2009.05.09	V1.05	���Ăł�TAB���\�ɂ���
// 2009.05.18	V1.06	���Ă�debug
// 2009.05.31	V1.07	debug
// 2009.10.26	V1.08	��۸��т�TAB��4�ȏ�ł��낦��̂��߰��ɂ���
// 2009.10.24	V1.09	�C�����̧�ق����^��+.new �Ƃ���
// 2009.10.29	V1.10	���Ă̌������B
// 2009.11.13	V1.11	'{'�`'}'�̌�����, #define�̌��TAB���w��ł���悤�ɂ���
// 2009.11.17	V1.12	else �̌�̉��s����/���Ȃ���ǉ�.case��TAB�Y�����C��
// 2009.11.19	V1.13	if(),else �̉������Ȃ�����ޒǉ�
// 2009.11.28	V1.14	TAB�̍Œ�ƍō��͈̔͂�ǉ�����
// 2009.12.01	V1.15	#ifdef �� extern "C" { �Ŵװ���������
// 2009.12.01	V1.16	'{'�`'}'�̒��Ժ��Ă����킹�Ȃ�, ���Ă̒��������P����
// 2009.12.09	V1.17	'{'�`'}'�̍ŏ���TAB��������������, #define�̍œK������ޒǉ�
// 2010.01.04	V1.18	case���Ɗ֐��̂Q�s�̏ꍇ��debug, #include���̽�߰����
// 2010.01.18	V1.19	int* abcd �Ȃǂ�type�̂������'*'��L���ɂ���
//						long_comment�� "2:��۸��т̏ꍇ�͒�������"��ǉ�,
// 2010.05.14	V1.20	ini̧�ق̏C��.����̍s�������Ȃ�����debug
// 2010.12.18	V1.21	big_kakko_in�̍폜
// 2011.01.20	V1.22	'\'�̏����ǉ�
// 2011.01.26	V1.23	#define��debug
// 2011.03.11	V1.24	#ifdef��debug, ���Ă̂ݍs�̒���,ini̧�ق̌�����
// 2011.03.15	V1.25	TAB�͈̔͐ݒ��ǉ�.cut_comment(�S�Ă̺��Ă��폜����)���폜
// 2011.03.18	V1.26	������
// 2011.03.23	V1.27	limit_line�ǉ�
// 2011.03.24	V1.28	cut_comment(�S�Ă̺��Ă��폜����)�𕜊�
// 2011.03.24	V1.29	//+��۸��т�TAB�ʒu������
// 2011.04.13	V1.30	������ύX
// 2011.04.18	V1.31	ini̧�ٌ�����
// 2011.05.12	V1.32	big_kakko_pair�̒ǉ�
// 2011.05.13	V1.33	big_kakko_pair��debug
// 2011.05.19	V1.34	return�����̌�����,�}�����̌�����
// 2011.05.26	V1.35	���̑���{}�ɉ��s���Ēǉ�
// 2011.05.31	V1.36	{}��debug
// 2011.06.04	V1.37	stack�̌�����
// 2011.06.28	V1.38	long_comment�� 2:���폜
// 2011.07.09	V1.39	��茴���ɋ߂�����
// 2011.07.20	V1.40	Visual-C++���\�ɂ���
// 2011.07.21	V1.41	Visual-C++����
// 2011.07.30	V1.42	Visual-C++����, ���ʂ̑O����߰��̗L���ɕύX
// 2011.08.29	V1.43	tmp_̧�ق̍쐬�ɕύX, ���Ĕ���̕ύX
// 2011.08.29	V1.44	#pragma asm�`endasm �ǉ�
// 2012.05.14	V1.45	���������'$'��L���Ƃ���
// 2012.05.19	V1.46	�Ō�̊J�ƺ��ނ������Ă�װ�Ƃ��Ȃ��悤�ɂ���
// 2012.05.21	V1.47	-b��߼�݂�-b=2 (old�t�@�C�������Ȃ���ǉ�����)
// 2012.05.24	V1.48	TAB�ʒu���o���邾�����Ƃ̂܂܂ɂ���̂��폜
// 2012.07.07	V1.49	'\'�̏����C���B
// 2012.08.05	V1.50	typedef�ƒǉ�
// 2012.08.16	V1.51	"//"�̌�̂����debug. CSprig�ǉ�
// 2012.08.30	V1.52	"\"�̏����ǉ�
// 2012.08.30	V1.53	all-x��ǉ�
// 2012.10.25	V1.54	�����̏ꍇ�ͽ�߰����̋�؂�܂Ŏ�荞�ނɕύX(�s�������_�΍�)
// 2013.06.26	V1.55	�����̏ꍇ�ͽ�߰����̋�؂�܂Ŏ�荞�ނɕύX(�s�������_�΍�)debug
// 2013.07.09	V1.56	Windows xp,7(32bit/64bit)�Ή�
// 2013.08.06	V1.57	�����̌��L,F,<,+,- ��debug
// 2013.08.09	V1.58	':','::' �̑O��̽�߰��̏�����I�����ɂ����B
// 2013.08.20	V1.59	renew.ini �̕ύX
// 2013.08.25	V1.60	'\'�̏����ύX
// 2013.09.10	V1.61	#if #else #ifend ��TAB stack �L�^�ǉ�
// 2013.09.26	V1.62	TAB�̌�����
// 2013.10.21	V1.63	struct, union�̌�����
// 2019.08.16	V1.70	utf8�Ή�
// 2019.09.02	V1.71	ShiftJIS/utf8��������
// 2020.03.23	V1.72	. �̌�̏������X�y�[�X�J�b�g�ɂ���
// 2020.05.04	V1.73	1�s�̍ő�\�[�X��512����1024�����Ɋg������
// --------------------------------------------------------------------------------
char environs[] = "Windows 10 �p";
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
// �y�@�\�z1byte���޲�؂�2����HEX�ɕϊ�
// �y���́z�޲���ް�,���������ޯ̧
// �y�o�́z�Ȃ�
// �y���l�z
// ====================================================================
void obj_hex2( int obj_data, char *wr_buf )
{
	obj_data &= 0xff;
	wr_buf[0] = hex_map[obj_data / 16];
	wr_buf[1] = hex_map[obj_data & 0x0f];
}
// ====================================================================
// �y�@�\�z������0����F��HEX��BIN�ɕϊ�
// �y���́z����������
// �y�o�́zHEX�ް�(�װ����0��Ԃ�)
// �y���l�z
// ====================================================================
int hex_bin( int char_data )
{
	char_data &= 0xff;
	if( (char_data >= '0') && (char_data <= '9') ) return( char_data - '0' );		// ���l HEX 0 �` 9
	else if( (char_data >= 'A') && (char_data <= 'F') ) return( char_data - 55 );	// ��̧�ޯ� A �` F
	else if( (char_data >= 'a') && (char_data <= 'f') ) return( char_data - 87 );	// ��̧�ޯ� a �` f
	else return( 0 );
}
// ====================================================================
// �y�@�\�zhex�ȊO�̕����܂�HEX�݂̂���荞��
// �y���́z�Ȃ�
// �y�o�́zint
// �y���l�z
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
// 10�i/16�i���������f����
// s_buf ������
// cnt ����
// return �Ō�ɕϊ����������̎�� 0:error, 10:10�i��, 16:16�i��
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
//		cnt = hex_binn( &s_buf[n + 2] ); // 16�i
//		ret = 16;
//	}
//	else {
//		cnt = atoi( &s_buf[n] ); // 10�i��
//		ret = 10;
//	}
//	if( type ) cnt = -cnt;
//	*kekka = cnt;
//	return( ret );
// }
// ---------------------------------------------------------------------
// ���-�, tab���߽
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
// ��s����հè�è
// �y�@�\�z̧�ق�����s�����܂Ŏ�荞��(CR+LF-->LF)
// �y���́zmax_len	1�`max_len:�ő�buf ����
// �y�o�́zreturn	1�`max_len:����, 0: end of file
// �y���l�z���ނ͍ő�max_len - 3 �����܂�
// ---------------------------------------------------------------------
int getln( FILE *fp, char *d_buf, int max_len )
{
	int		len, c;
	char	buf[200];

	len = 0;
	while( (c = getc(fp)) != EOF )
	{
		if( c == _CR ) continue; // ����

		d_buf[len++] = c;
		if( len >= (max_len - 3) )
		{ // �c��͎̂Ă�
			sprintf( buf, "%s(%d) �o��̧��[line=%d]", src_full_name, src_line_no + 1, max_line + 1 );
			err_trap( 2, -36, buf, 0 ); // "1�s����������"
		}
		if( c == _LF ) break;
	}
	d_buf[len] = 0;
	if( len ) // 2012.05.19 �폜
	{
		if( d_buf[len - 1] != _LF )
		{ // �Ō�̍s�����s���ނȂ�
//			sprintf( buf, "%s(%d) �o��̧��[line=%d]", src_full_name, src_line_no + 1, max_line + 1 ); // 2012.05.19�폜
//			err_trap( 0, -31, buf, 0 ); // "���s�R�[�h���Ȃ�"
			d_buf[len++] = _LF;
			d_buf[len] = 0;
		}
	}
	return( len );
}
// ====================================================================
// �y�@�\�z�I�����̏���
// �y�o�́z�Ȃ�
// �y���l�z
// ====================================================================

void close_all( void )
{
	if( fp_src ) fclose( fp_src );
	if( fp_err ) fclose( fp_err );
	fp_src = fp_err = NULL;
}
// -------------- �I������ -----------------------
void wait_exit( int ret_no )
{
	int moji;

	close_all();
	printf( "�I��\r\n" );
	printf( "\r\n�����̷����͂ŏI��\r\n" );
	moji = getchar();
//	printf( "moji = %xh", moji );

	exit( ret_no );
}
// ====================================================================
// �y�@�\�zerror��save
// �y���́zmes_no
// �y�o�́z�Ȃ�
// �y���l�z
// ====================================================================
void save_error_file( char *mes_err )
{
	if( total_err_cnt > 100 ) return;
	fp_err = fopen( err_name, "a+" );
	if( fp_err == NULL ) return;

//	fseek( fp_err, 0L, SEEK_END ); // �Ō�ֈړ�
	fprintf( fp_err, "%s\n", mes_err );
	fclose( fp_err );
	fp_err = NULL;
	total_err_cnt++;
}
// ---------------------------------------------------------------------
// mode 0:�L�^ & �װү���ޕ\��--> return
// mode 1:�L�^ & �װү���ޕ\��&�����͊m�F --> return
// mode 2:�L�^ & �װү���ޕ\�� --> exit
// mode 3:�L�^ & �x��ү���ޕ\��--> return
// path_name ̧�قɋL�^�̎��ǉ�
// ---------------------------------------------------------------------
void err_trap( int mode, int err_no, char *mes_buf, char *path_name )
{
	static int	err_cnt = 0;
	int			n;
	char		*mes_p, buf[500], buf2[500];

	if( err_no < 0 ) err_no = -err_no;
	if( err_no == 999 ) return;
	if( err_no == 1 ) return; // ���~

	if( mes_buf )
	{
		for( n = 0; mes_buf[n] != 0; n++ )
		{
			if( (Uchar)mes_buf[n] < ' ' ) mes_buf[n] = ' '; // space�ɕϊ�
		}
	}

	switch( err_no )
	{
	case 0:
		return;

	case 1: mes_p = "�����𒆒f���܂���"; break;
	case 2: mes_p = "��ذ���s���ŋN���ł��܂���"; break;
	case 3: mes_p = "̧�ق�������܂���"; break;
	case 4: mes_p = "�ް��������̂ɓǂݏo����"; break;
	case 5: mes_p = "̧��ذ�޵���ݎ��s"; break;
	case 6: mes_p = "̧��ײĵ���ݎ��s"; break;
	case 7: mes_p = "̧�ق��ُ�ł�"; break;
	case 8: mes_p = "�������݂��o���܂���"; break;
	case 9: mes_p = "̧�ق̒���������܂���"; break;
	case 10: mes_p = "���̑��̗\��ꔭ��"; break;
	case 11: mes_p = "buffer over"; break;
	case 12: mes_p = "TAB over"; break;
	case 13: mes_p = "TOK buffer over"; break;
	case 14: mes_p = "SUB buffer over"; break;
	case 15: mes_p = "TAB stack over"; break;
	case 16: mes_p = "TAB stack under"; break;
	case 17: mes_p = "BUG �؂�o��"; break;
	case 18: mes_p = "���̧�ٻ��ނ����"; break;
	case 19: mes_p = "malloc()���m�ۏo���Ȃ�"; break;
	case 20: mes_p = "����memory��over����(bug)"; break;
	case 21: mes_p = "TAB_stack �����"; break;
	case 22: mes_p = "'/*'��'*/'�ɒ���"; break;
	case 23: mes_p = "';'���ُ�"; break;
	case 24: mes_p = "TAB�ʒu���ُ�"; break;
	case 25: mes_p = "'}'���ُ�"; break;
	case 26: mes_p = "')'���ُ�"; break;
	case 27: mes_p = "TAB stack���ُ�"; break;
	case 28: mes_p = ".ini ̧�ق̺���ނ��ُ�"; break;
	case 29: mes_p = "';'��2����"; break;
	case 30: mes_p = "���s��̓ǂݏo�����o���Ȃ�"; break;
	case 31: mes_p = "���s�R�[�h���Ȃ�"; break;
	case 32: mes_p = "'*/'���Ȃ�"; break;
	case 33: mes_p = "'#'���ُ�"; break;
	case 34: mes_p = "�v���O�����ُ�"; break;
	case 35: mes_p = "#pragram endasm ���Ȃ�"; break;
	case 36: mes_p = "1�s����������"; break;
	case 37: mes_p = "typedef�̒�`����������"; break;
	case 38: mes_p = "typedef�̓o�^������������"; break;
	case 39: mes_p = "�����������ٺ��ݼ�+a�𒍈�"; break;

	default: mes_p = "for_debug"; break; // �ʏ�300�ԑ�ȏ�
	}
	if( mes_p )
	{
		if( mode == 3 )
		{ // �x��
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
		{ // �x��
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
		save_error_file( buf2 ); // �L�^
	}
	else save_error_file( buf );	// �L�^

	buf[79] = 0;					// ������������
	if( ++err_cnt < 50 )
	{ // ��ʕ\���𐧌�����
		printf( "\r" );
		printf( buf );
		printf( "\r\n" );
		if( mode == 1 )
		{
			printf( "�����L�[�������ĉ�����" );
			while( getchar() == -1 );
			printf( "\n\n" );
		}
	}
	if( mode == 2 )
	{
//		reform_story(); // �����ϐ��Ƹ�۰��ق̋�ʂ�����
//		if( max_line ) save_dst_file();
		printf( "\r\n�װ�Œ��~���܂���\r\n" );
		wait_exit( 2 );
	}
}
// ---------------------------------------------------
// mode 0:�L�^ & �װү���ޕ\��--> return
// mode 1:�L�^ & �װү���ޕ\��&�����͊m�F --> return
// mode 2:�L�^ & �װү���ޕ\�� --> exit
// mode 3:�L�^ & �o��̧�قɒǉ��o��
// mode 4:mode=2�Ɠ�������debug����save����
// message�̑���ɍs�ԍ���\��(�L�^)
// ---------------------------------------------------
void err_trap_line( int mode, int err_no, char *s_buf )
{
	char buf[500];

	if( s_buf == NULL ) sprintf( buf, "%s(%d) �o��̧��[line=%d]", src_full_name, src_line_no, max_line + 1 );	// editer��1�Ԃ���n�܂�␳
	else sprintf( buf, "%s(%d) ���̧�� ���e(%s)", src_full_name, src_line_no, s_buf );							// editer��1�Ԃ���n�܂�␳
	err_trap( mode, err_no, buf, 0 );
}
// ---------------------------------------------------------------------
// �g����
// ---------------------------------------------------------------------
void usage( void )
{
	printf(
		"\n"
		" ����     :   renew.exe file_name < -parameter >\n"
		" file_name: C�̃\�[�X�t�@�C��.(�ȗ��ł��Ȃ�) '*','?'���g�p�\\n"
		" parameter: �I�v�V�������p�����[�^(ini̧�ق��D�悷��)\n"
		"\n"
		);
	wait_exit( 1 );
}

// ---------------------------------------------------------------------
// debug���\��
// ---------------------------------------------------------------------
void disp_debug_para0( void )
{
	printf(
		"\n"
		"debug������Ұ� debug=n\n"
		" n = 1: tab_stack_cnt�\�� TAB�̈ʒu�L�^�ԍ�\n"
		" n = 2: big_kakko_cnt�\�� '{'�̐�\n"
		" n = 3: if_stack_top�\�� if()... , else ...��TAB�L�^�ԍ�\n"
		" n = 4: hijo_flag�\�� �⏕���̋L�^\n"
		" n = 5: tab_pos�\�� ���݂�TAB��\n"
		" n = 6: src_line_no�\�� �\�[�X�s�̔ԍ�\n"
		" n = 7: src_com_pos�ʒu�\�� �\�[�X �R�����g�ʒu\n"
		" n = 8: sub_type�\�� char, int,long ��\n"
		"\n"
		);
	wait_exit( 1 );
}

// ---------------------------------------------------------------------
// debug���\��
// ---------------------------------------------------------------------
void disp_debug_para1( void )
{
	switch( debug_mode )
	{
	case 1: fdata->debug_joho = tab_stack_cnt; break;	// debug�p tab_stack�\��
	case 2: fdata->debug_joho = big_kakko_cnt; break;	// debug�p big_kakko_cnt�\��
	case 3: fdata->debug_joho = if_stack_top; break;	// debug�p if_stack_top�\��
	case 4: break;										// debug�p line_type�\��
	case 5: break;										// debug�p tab_pos�\��
	case 6: break;										// debug�p src_line_no�\��
	case 7: break;										// debug�p src_com_pos�ʒu�\��
	case 8: break;										// debug�p sub_type�\��
	}
}
// ---------------------------------------------------------------------
// debug���\��
// ---------------------------------------------------------------------
void disp_debug_para2( char *d_buf )
{
	char buf[CHAR_SIZE2];

	switch( debug_mode )
	{
	case 1: // debug�p tab_stack_cnt�\��
		get_debug_type_map( buf, fdata->line_type );
		sprintf( &buf[10], "[STACK=%02d]%s", fdata->debug_joho, d_buf );
		strcpy( d_buf, buf );
		break;

	case 2: // debug�p big_kakko_cnt�\��
		get_debug_type_map( buf, fdata->ope_type );
		sprintf( &buf[10], "[{=%02d]%s", fdata->debug_joho, d_buf );
		strcpy( d_buf, buf );
		break;

	case 3: // debug�p if_statck_cnt�\��
		get_debug_type_map( buf, fdata->line_type );
		sprintf( &buf[10], "[IFSTK=%02d]%s", fdata->debug_joho, d_buf );
		strcpy( d_buf, buf );
		break;

	case 4: // debug�p hijo_flag�\��
		get_debug_type_map( buf, fdata->line_type );
		sprintf( &buf[10], "[%08x]%s", fdata->hojo_flag, d_buf );
		strcpy( d_buf, buf );
		break;

	case 5: // debug�p tab_pos�\��
		get_debug_type_map( buf, fdata->line_type );
		sprintf( &buf[10], "[TAB  =%02d]%s", fdata->tab_pos, d_buf );
		strcpy( d_buf, buf );
		break;

	case 6: // debug�p src_line_no�\��
		get_debug_type_map( buf, fdata->line_type );
		sprintf( &buf[10], "[%08d]%s", fdata->src_line_no, d_buf );
		strcpy( d_buf, buf );
		break;

	case 7: // debug�p src_com_pos�ʒu�\��
		get_debug_type_map( buf, fdata->line_type );
		sprintf( &buf[10], "[COM=%04d]%s", fdata->src_com_pos, d_buf );
		strcpy( d_buf, buf );
		break;

	case 8: // debug�p sub_type�\��
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
	errno = 0;			// system �p
	if( _getcwd(p_name, len - 2) != NULL ) p_name[len - 1] = 0;
	else p_name[0] = 0; // error
	if( errno )
	{
		p_name[0] = 0;									// error
		printf( "�ި���̏������ł��Ă��܂���\r\n" );	// �\��&�����͑҂�
		return( -2 );
	}
	return( 0 );
}
// ---------------------------------------------------------------------
// ������̐؂�o��(�ׂ�������)
// �e�����Ő؂���
// max ������100�����܂�
// return s_buf�̎��̈ʒu
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
		{ // ����
			d_buf[put_cnt++] = moji;
			if( put_cnt >= max_len ) break;
			if( com_flag == 0 )
			{ // �ŏ�
				if( moji == ';' ) com_flag = 1; // �Ȍ�comment or �[������
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
// renew.ini ̧�ق����
// ---------------------------------------------------------------------
void make_ini_file( void )
{
	char *ini_mes[] =
	{
		";\n",
		"; C�p�\�[�X �t�@�C�������₷��������\n",
		"; ���̃t�@�C���̍s�̍ŏ���';'������΃R�����g�Ƃ��ď�������\n",
		";\n",
		"; renew.exe  ���s�t�@�C��\n",
		"; renew.ini  �����t�@�C��(�����ꍇ��,�v���O�����N�����V�K�쐬����)\n",
		";\n",
		"; �g����\n",
		"; ���s     :  renew.exe<Enter> <--- �ŏ��Ɏ��s\n",
		"; ����     :  file_name <-parameter>\n",
		";                ��            ��parameter: �I�v�V�������p�����[�^(ini̧�ق��D�悷��,�ȗ��\)\n",
		";                ��file_name: C�̃\�[�X�t�@�C��.(�ȗ��ł��Ȃ�) '*','?'���g�p�\\n",
		";\n",
		"; �N�����ɉ��L������parameter���w�肷��Ƃ���ini̧�ق��D�悷��̂ňꎞ�I�ɕύX���������ɗL��\n",
		"; parameter�𕡐��w�肷�鎞��,��߰��ŋ�؂��Ďw�肷�鎖\n",
		"; �� renew.exe *.c\n",
		"; �� renew.exe *.h -a3\n",
		";                   �������` �w��\n",
		"; �� renew.exe *.c -m0 -u0 -t0\n",
		";                   ��  ��  ��\n",
		";                   ��  ��  parameter�𕡐��w�肷�鎞��,��߰��ŋ�؂��Ďw�肷�鎖\n",
		";                   ��  while(){} ��'{'�`'}'�̏c�̈ʒu��0:�������`�݂̂���\n",
		";                   �s�̏��� 0:�������Ȃ�\n",
		"; �� renew.exe *.h -b2 -o1\n",
		";                   ��  ��\n",
		";                   ��  #if, #else, #endif ��TAB�𒲐�����(TAB�����ꂽ���̊m�F�p) 1:TAB����\n",
		";                   �\�[�X�������l�[������+.old�Ƃ�,�\�[�X�t�@�C���𐮌`����\n",
		"; �� renew.exe *.h -m1\n",
		";                   ��\n",
		";                  �R�����g�s�̏��� 1:��۸��т̏ꍇ�͒�������+TAB�𑵂���\n",
		"; debug_mode�̎g���� �͈͂� 1�`9�Brenew_debug.txt �� renew_debug2.txt �������\n",
		"; �� renew.exe *.c -z9\n",
		";                   ��\n",
		";                  debug�ŋL�^���閾�ו\��\n",
		"; �� renew.exe *.c -z1\n",
		";                   ��\n",
		";                   tab_stack�ԍ��\��(�ǂ���TAB�����ꂽ��������)\n",
		";\n",
		";------------------ �ȉ������� ------------------------\n",
		"; ���L�̐���(z)�̒ʂ�̐�������]�ɉ����ĕύX����\n",
		"\n",
		";-- �����-------- ����(z) --; ���Ұ� ----- ���e -------------------------------------------------------\n",
		"\n",
		"all                 0       ; '-a?' ��`�A�錾�̕ϊ��̗L��(?=0�`9:6����9�͎��R�ɏ�������)\n",
		"                            ; �����ɂ悭�g���ԍ����w��B0 �͉��L�����l�ɏ]��\n",
		"                            ; ���L all-�ԍ� �����Ұ�  ?=���� : �ݒ�l, ?=�����ȊO : �S�ď����l�ǂ���ɂ���\n",
		"all-1   -b1 -c0 -d2 -e2 -f0 -g0 -h1 -i? -j0 -k0 -l0 -m0 -n? -o0 -p0 -q0 -r0 -s0 -t0 -u0 -v0 -w0 -x0 -y0 -T1 ; �ᐮ�`\n",
		"all-2   -b1 -c2 -d2 -e2 -f0 -g2 -h2 -i? -j0 -k0 -l1 -m0 -n? -o0 -p0 -q0 -r2 -s1 -t2 -u2 -v1 -w1 -x2 -y0 -T1 ; �����`\n",
		"all-3   -b1 -c2 -d2 -e2 -f0 -g2 -h2 -i? -j1 -k0 -l1 -m1 -n? -o? -p1 -q1 -r2 -s1 -t2 -u2 -v1 -w1 -x2 -y2 -T1 ; �����`\n",
		"all-4   -b2 -c2 -d2 -e2 -f0 -g2 -h2 -i? -j0 -k0 -l1 -m0 -n? -o? -p0 -q0 -r2 -s1 -t2 -u2 -v1 -w1 -x2 -y0 -T1 ; �����`+�������\n",
		"all-5   -b2 -c2 -d2 -e2 -f0 -g2 -h2 -i? -j1 -k0 -l1 -m1 -n? -o? -p1 -q1 -r2 -s1 -t2 -u2 -v1 -w1 -x2 -y2 -T1 ; �����`+�������\n",
		"all-6   -b? -c? -d? -e? -f0 -g? -h? -i? -j? -k? -l? -m? -n? -o? -p? -q? -r? -s? -t? -u? -v? -w? -x? -y? -T? ; �ذ1\n",
		"all-7   -b? -c? -d? -e? -f0 -g? -h? -i? -j? -k? -l? -m? -n? -o? -p? -q? -r? -s? -t? -u? -v? -w? -x? -y? -T? ; �ذ2\n",
		"all-8   -b? -c? -d? -e? -f0 -g? -h? -i? -j? -k? -l? -m? -n? -o? -p? -q? -r? -s? -t? -u? -v? -w? -x? -y? -T? ; �ذ3\n",
		"all-9   -b? -c? -d? -e? -f0 -g? -h? -i? -j? -k? -l? -m? -n? -o? -p? -q? -r? -s? -t? -u? -v? -w? -x? -y? -T? ; �ذ4\n",
		"\n",
		";----------------- �����l --;---------------���� ---------------------------------------------------------\n",
		"source_name         1       ; '-b?' ������̏��� 0:�����̂�, 1:������͕ς�炸,���̧�ق𐮌`�� +.new��V�K�ɍ��\n",
		"                            ;      2:���̧�ِ��`����Â��������+.old, 3:���̧�ِ��`��,old�����Ȃ�\n",
		"\n",
		"define_tab          2       ; '-c?' #define �̑�1�Ԗڒ�`�Ƒ�2�ԖڊԒ萔��TAB�ʒu(?=0�`40)\n",
		"                            ;      0:�������Ȃ�, 1:TAB�Ȃ�(��߰��̂�), 2:������TAB�쐬, 3�`:�ŏ�TAB�ʒu\n",
		"                            ;      �� -c0\n",
		"                            ;         0---1---2---3---4 TAB�ʒu   ---> 0---1---2---3---4---5---6---\n",
		"                            ;         #define   ABCD(a) if(a){    ---> #define   ABCD(a) if(a) {\n",
		"                            ;      �� -c1\n",
		"                            ;         0---1---2---3---4 TAB�ʒu   ---> 0---1---2---3---4---5---6---\n",
		"                            ;         #define   ABCD(a) if(a){    ---> #define ABCD( a ) if( a ) {\n",
		"                            ;         #define Uint unsigned int   ---> #define Uint unsignd int\n",
		"                            ;         #define ABCD    1000        ---> #define ABCD 1000\n",
		"                            ;         #define MAX_LENGTH  128     ---> #define MAXLENGTH 128\n",
		"                            ;      �� -c2\n",
		"                            ;         0---1---2---3---4 TAB�ʒu   ---> 0---1---2---3---4---5---6---\n",
		"                            ;         #define   ABCD(a) if(a){    ---> #define ABCD( a )   if( a ) {\n",
		"                            ;         #define Uint unsigned int   ---> #define Uint        unsignd int\n",
		"                            ;         #define ABCD    1000        ---> #define ABCD        1000\n",
		"                            ;         #define MAX_LENGTH  128     ---> #define MAXLENGTH   128\n",
		"                            ;      �� -c5\n",
		"                            ;         0---1---2---3---4 TAB�ʒu   ---> 0---1---2---3---4---5---6---\n",
		"                            ;         #define   ABCD(a) if(a){    ---> #define ABCD( a )   if( a ) {\n",
		"                            ;         #define Uint unsigned int   ---> #define Uint        unsignd int\n",
		"                            ;         #define ABCD    1000        ---> #define ABCD        1000\n",
		"                            ;         #define MAX_LENGTH  128     ---> #define MAXLENGTH   128\n",
		"                            ;      �� -c6\n",
		"                            ;         0---1---2---3---4 TAB�ʒu   ---> 0---1---2---3---4---5---6---\n",
		"                            ;         #define ABCD(a) if(a){      ---> #define ABCD( a )       if( a ) {\n",
		"                            ;         #define Uint unsigned int   ---> #define Uint            unsignd int\n",
		"                            ;         #define ABCD    1000        ---> #define ABCD            1000\n",
		"                            ;         #define MAX_LENGTH  128     ---> #define MAXLENGTH       128\n",
		"\n",
		"define_com_tab      2       ; '-d?' #define �̺��Ă�TAB�ʒu(?=0�`40)\n",
		"                            ;      0:�������Ȃ�, 1:TAB�Ȃ�(��߰��̂�), 2:������TAB�쐬, 3�`:�ő�TAB�ʒu\n",
		"                            ;      �� -d1\n",
		"                            ;         0---1---2---3---4 TAB�ʒu      ---> 0---1---2---3---4---5---6---7\n",
		"                            ;         #define ABC 1234    // comment ---> #define ABC 1234 // comment\n",
		"                            ;         #define ABCDEF abcd123 // test ---> #define ABCDEF abcd123 // test\n",
		"                            ;      �� -d5\n",
		"                            ;         0---1---2---3---4 TAB�ʒu      ---> 0---1---2---3---4---5---6---7\n",
		"                            ;         #define ABC 1234 // comment    ---> #define ABC 1234    // comment\n",
		"                            ;         #define ABCDEF abcd123 // test ---> #define ABCDEF abcd123 // test\n",
		"                            ;      �� -d20\n",
		"                            ;         0---1---2---3---4 TAB�ʒu      ---> 0---1---2---3---4---5---6---7\n",
		"                            ;         #define ABC 1234 // comment    ---> #define ABC 1234        // comment\n",
		"                            ;         #define ABCDEF abcd123 // test ---> #define ABCDEF abcd123  // test\n",
		"\n",
		"other_com_tab       2       ; '-e?' #defien�ȊO�̺��Ă�TAB�ʒu(?=0�`40)\n",
		"                            ;      0:�������Ȃ�, 1:TAB�Ȃ�(��߰��̂�), 2:�ő�TAB�����Ȃ�, 3�`:�ő�TAB�ʒu\n",
		"                            ;      �� -e1\n",
		"                            ;         0---1---2---3---4 TAB�ʒu   ---> 0---1---2---3---4---5---6\n",
		"                            ;         a=0;    // test1            ---> a = 0; // test1\n",
		"                            ;         abcdef1234=0;// test2       ---> abcdef1234 = 0; // test2\n",
		"                            ;      �� -e3\n",
		"                            ;         0---1---2---3---4 TAB�ʒu   ---> 0---1---2---3---4---5---6---\n",
		"                            ;         a=0;    // test1            ---> a = 0;      // test1\n",
		"                            ;         abcdef1234=0;// test2       ---> abcdef1234 = 0; // test2\n",
		"                            ;      �� -e20\n",
		"                            ;         0---1---2---3---4 TAB�ʒu   ---> 0---1---2---3---4---5---6---\n",
		"                            ;         a=0;    // test1            ---> a = 0;          // test1\n",
		"                            ;         abcdef1234=0;// test2       ---> abcdef1234 = 0; // test2\n",
		"\n",
		"shit_jis_mode       0       ; '-f?' �\�[�X�� 0:����, 1:utf8, 2:Shift JIS\n",

//		"global_int_tab      2       ; '-f?' ��۰��ٕϐ���int, char, long, unsigned�̑���`��TAB�ʒu(?=0�`40)\n",
//		"                            ;      0:�������Ȃ�, 1:TAB�Ȃ�(��߰��̂�), 2:������TAB�쐬, 3�`:�ő�TAB�ʒu\n",
//		"                            ;      �� -f1\n",
//		"                            ;         0---1---2- TAB�ʒu   ---> 0---1---2---3---4---5---6\n",
//		"                            ;         int      abcd1;      ---> int abcd1;\n",
//		"                            ;         char   abcd2;        ---> char abcd2;\n",
//		"                            ;         unsigned long abcd3; ---> unsigned long abcd3;\n",
//		"                            ;      �� -f2\n",
//		"                            ;         0---1---2- TAB�ʒu   ---> 0---1---2---3---4---5---6\n",
//		"                            ;         int abcd1;           ---> int             abcd1;\n",
//		"                            ;         char abcd2;          ---> char            abcd2;\n",
//		"                            ;         unsigned long abcd3; ---> unsigned long   abcd3;\n",
//		"                            ;      �� -f3\n",
//		"                            ;         0---1---2- TAB�ʒu   ---> 0---1---2---3---4---5---6\n",
//		"                            ;         int abcd1;           ---> int         abcd1;\n",
//		"                            ;         char abcd2;          ---> char        abcd2;\n",
//		"                            ;         unsigned long abcd3; ---> unsigned long abcd3;\n",
//		"                            ;      �� -f6\n",
//		"                            ;         0---1---2- TAB�ʒu   ---> 0---1---2---3---4---5---6\n",
//		"                            ;         int abcd1;           ---> int             abcd1;\n",
//		"                            ;         char abcd2;          ---> char            abcd2;\n",
//		"                            ;         unsigned long abcd3; ---> unsigned long   abcd3;\n",
		"\n",
		"local_int_tab       2       ; '-g?' ���[�J���ϐ���int, char, long, unsigned�̑���`��TAB�ʒu(?=0�`40)\n",
		"                            ;      0:�������Ȃ�, 1:TAB�Ȃ�(��߰��̂�), 2:������TAB�쐬, 3�`:�ő�TAB�ʒu\n",
		"                            ;      �� -g1\n",
		"                            ;         0---1---2---3- TAB�ʒu   ---> 0---1---2---3---4---5---6\n",
		"                            ;         void abcd(void)          ---> void abcd(void)\n",
		"                            ;         {                        ---> {\n",
		"                            ;             int  abcd1;          --->     int abcd1;\n",
		"                            ;             char abcd2;          --->     char abcd2;\n",
		"                            ;             unsigned long abcd3; --->     unsigned long abcd3;\n",
		"                            ;      �� -g3\n",
		"                            ;         0---1---2---3- TAB�ʒu   ---> 0---1---2---3---4---5---6\n",
		"                            ;         void abcd(void)          ---> void abcd(void)\n",
		"                            ;         {                        ---> {\n",
		"                            ;             int  abcd1;          --->     int     abcd1;\n",
		"                            ;             char abcd2;          --->     char    abcd2;\n",
		"                            ;             unsigned long abcd3; --->     unsigned long abcd3;\n",
		"                            ;      �� -g7\n",
		"                            ;         0---1---2---3- TAB�ʒu   ---> 0---1---2---3---4---5---6\n",
		"                            ;         void abcd(void)          ---> void abcd(void)\n",
		"                            ;         {                        ---> {\n",
		"                            ;             int  abcd1;          --->     int             abcd1;\n",
		"                            ;             char abcd2;          --->     char            abcd2;\n",
		"                            ;             unsigned long abcd3; --->     unsigned long   abcd3;\n",
		"\n",
		"big_kakko_pair      2       ; '-h?' '{'�`'}' �A���̈ʒu\n",
		"                            ;      0:�X�y�[�X�̂�, 1:�����ɑ�����(�ŏ�TAB=1), 2:������TAB�쐬(��߰�+TAB�ō��킹��)\n",
		"                            ;      �� -h0\n",
		"                            ;       0---1---2---3---4- TAB�ʒu ---> 0---1---2---3---4---5---6---7---8\n",
		"                            ;       abcd[] =   {123, 456, 789} ---> abcd[] = { 123, 456, 789 }\n",
		"                            ;       d[] = {1,2,3 }             ---> d[] = { 1, 2, 3 }\n",
		"                            ;       ef[] =  { 23, 45, 6789}    ---> ef[] = { 23, 45, 6789 }\n",
		"                            ;      �� -h1\n",
		"                            ;       0---1---2---3---4- TAB�ʒu ---> 0---1---2---3---4---5---6---7---8\n",
		"                            ;       abcd[] =   {123, 456, 789} ---> abcd[] =    { 123, 456, 789 }\n",
		"                            ;       d[] = {1,2,3 }             ---> d[] =       { 1, 2, 3 }\n",
		"                            ;       ef[] =  { 23, 45, 6789}    ---> ef[] =      { 23, 45, 6789 }\n",
		"                            ;      �� -h2\n",
		"                            ;       0---1---2---3---4- TAB�ʒu ---> 0---1---2---3---4---5---6---7---8\n",
		"                            ;       abcd[] =    {123, 456, 789} ---> abcd[] = { 123, 45, 789  }\n",
		"                            ;       d[] = {1,2,3 }             ---> d[] =     { 1,   2,  3    }\n",
		"                            ;       ef[] =  { 23, 45, 6789}    ---> ef[] =    { 23,  45, 6789 }\n",
		"\n",
		"limit_line        37        ; '-i?' 1�s�̍ő吔(TAB���Z)���K������B1�s�̍ő�TAB��(?=0:������, ?=20(�ŏ�)�`99\n",
		"                            ;      �������� ?��4�{\n",
		"                            ;      ���̎w�蕶�����𒴂���ꍇTAB���߰��Ƃ���\n",
		"                            ;       �� -p33\n",
		"                            ;         26--27--28--29---30-- TAB�ʒu ---> ---27---28--29--30--31--32--\n",
		"                            ;             abcd=0;//test             --->    abcd = 0;    // test\n",
		"                            ;             c(1); //commment          --->    c( 1 );      // comment\n",
		"                            ;       �� -p32\n",
		"                            ;         26--27--28--29---30-- TAB�ʒu ---> ---27---28--29--30--31--32--\n",
		"                            ;             abcd=0;//test             --->    abcd = 0;    // test\n",
		"                            ;             c(1); //commment          --->    c( 1 ); // comment\n",
		"\n",
		"kolon               1       ; '-j?' ':','::' �R�����̑O��̃X�y�[�X����\n",
		"                            ;      0:�������Ȃ�, 1:�����ŃX�y�[�X���폜/�}������\n",
		"                            ;      �� -i1\n",
		"                            ;       0---1---2---3---4- TAB�ʒu ---> 0---1---2---3---4---5---6\n",
		"                            ;           case abc :             --->     case abc:\n",
		"\n",
		"cut_comment         0       ; '-k?' ���Ă��폜����B���L�ԍ������Z�����ԍ����w��(?=0�`15)\n",
		"                            ;      0:�폜���Ȃ�\n",
		"                            ;      1:1�s�̉E�[�̺���(//�`, /*�`*/)���폜����\n",
		"                            ;      2:1�s���̕�������(/*�`*/)���폜����\n",
		"                            ;      4:���čs(//�`)���폜����\n",
		"                            ;      8:���ĕ����s(/*�`, �`*/)���폜����\n",
		"                            ;      �� -j3\n",
		"                            ;        1:1�s�̉E�[�̺���(//�`, /*�`*/)���폜����\n",
		"                            ;        2:1�s���̕�������(/*�`*/)���폜����\n",
		"                            ;      �� -j15\n",
		"                            ;        1:1�s�̉E�[�̺���(//�`, /*�`*/)���폜����\n",
		"                            ;        2:1�s���̕�������(/*�`*/)���폜����\n",
		"                            ;        4:���čs(//�`)���폜����\n",
		"                            ;        8:���ĕ����s(/*�`, �`*/)���폜����\n",
		"\n",
		"long_comment        1       ; '-l?' '/*�`*/' �s�̏���\n",
		"                            ;      0:�ϊ����Ȃ�\n",
		"                            ;      1:�s�̍Ō�� '/*�`*/' ��'//'�ɕϊ�\n",
		"                            ;      2:'/*'�Ŏn�܂镡���s�̒������͂܂ł�'//'�ɕϊ�\n",
		"                            ;     �� -k1\n",
		"                            ;         0---1---2---3----4--- TAB�ʒu ---> 0---1---2---3---4---5\n",
		"                            ;             abcde= 0;/* test0 */      --->     abcde = 0;  // test0\n",
		"                            ;             a=b;// test1              --->     a = 0;      // test1\n",
		"                            ;             //abc(1);//test2          --->     // abc(1);//test2\n",
		"                            ;      �� -k2\n",
		"                            ;         0---1---2 TAB�ʒu      ---> 0---1---2---3---4---5---6\n",
		"                            ;         /*                     ---> //\n",
		"                            ;           This is sample.      ---> // This is sample.\n",
		"                            ;           20xx�Nyy��zz��       ---> // 20xx�Nyy��zz��\n",
		"                            ;           char abcd[]={1,2,3}; ---> // char abcd[]={1,2,3};\n",
		"                            ;         */                     ---> //\n",
		"\n",
		"comment_prog         1      ; '-m?' '//' �s�̏���\n",
		"                            ;      0:�������Ȃ�, 1:��۸��т̏ꍇ�͒�������+TAB�𑵂���\n",
		"                            ;       �� -m1\n",
		"                            ;         0---1---2---3----4--- TAB�ʒu ---> 0---1---2---3---4---5\n",
		"                            ;             abcde= 0;/* test0 */      --->     abcde = 0;  // test0\n",
		"                            ;             a=b;// test1              --->     a = 0;      // test1\n",
		"                            ;        //abc(1);//test2               ---> //  abc( 1 );   //test2\n",
		"                            ;        ��'//'�ʒu���擪+��۸��тȂ̂���۸��тƂ��Ē�������\n",
		"                            ;             //abc(1);//test2          --->     // abc(1);//test2\n",
		"                            ;             ��'//'�ʒu���擪�łȂ��ꍇ�͉������Ȃ�\n",
		"                            ;             b(1); //test3             --->     b( 1 );     // test3\n",
		"                            ;               //ý�                   --->     // ý�\n",
		"                            ;               ��'//'�ʒu���O�s�Ƃ�����ĂȂ��ꍇ,TAB=0�Ƃ���\n",
		"                            ;             c(1); //test4             --->     c( 1 );     // test4\n",
		"                            ;                   //�����ͺ���        --->                 // �����ͺ���\n",
		"                            ;                   ��'//'�ʒu���O�s�Ɠ������Ĉʒu�̏ꍇ,�O�s�ɂ��낦��\n",
		"\n",
		"kakko_space         0       ; '-n?' ���ʂ̑O��̏���\n",
		"                            ;      0:�A�����銇�ʂ̍ŏ��ƍŌ�ͽ�߰�������, 1:���ʂ̓����ͽ�߰������Ȃ�\n",
		"                            ;       �� -n0\n",
		"                            ;         0---1---2---3--- TAB�ʒu   ---> 0---1---2---3---4---5---6\n",
		"                            ;         if( abc( 1 ) == 0 ) d = 0; ---> if( abc(1) == 0 ) d = 0;\n",
		"                            ;       �� -n1:\n",
		"                            ;         0---1---2---3--- TAB�ʒu   ---> 0---1---2---3---4---5---6\n",
		"                            ;         if( abc( 1 ) == 0 ) d = 0; ---> if(abc(1) == 0) d = 0;\n",
		"\n",
		"ifdef_mode          0       ; '-o?' #if, #else, #endif ��TAB�𒲐�����(TAB�����ꂽ���̊m�F�p)\n",
		"                            ;      0:�������Ȃ�, 1:TAB����\n",
		"\n",
		"yen                 1       ; '-p?' '\\'�s�̏���\n",
		"                            ;      0:�ŏ���TAB�͕ύX�Ȃ�, 1:��������\n",
		"\n",
		"struct_big_kakko    0       ; '-q?' struct{} ��'{'�`'}'�̏c�̈ʒu�����낦��\n",
		"                            ;      0:�������`�݂̂���, 1:'struct {'+���s �ɂ���, 2:���s+{��,{ }���c�ɑ�����\n",
		"\n",
		"if_big_kakko        2       ; '-r?' if(){} ��'{'�`'}'�̏c�̈ʒu�����낦��('{'�`'}'�̏ꍇ�͑����Ȃ�)\n",
		"                            ;      0:�������`�݂̂���, 1:if(...) {+���s �ɂ���, 2:���s+{��,{ }���c�ɑ�����\n",
		"\n",
		"else_big_kakko      1       ; '-s?' else{} ��'{'�`'}'�̏c�̈ʒu�����낦��('{'�`'}'�̏ꍇ�͑����Ȃ�)\n",
		"                            ;      0:�������`�݂̂���, 1:else {+���s �ɂ���, 2:���s+{��,{ }���c�ɑ�����\n",
		"\n",
		"for_big_kakko       2       ; '-t?' for(){} ��'{'�`'}'�̏c�̈ʒu�����낦��('{'�`'}'�̏ꍇ�͑����Ȃ�)\n",
		"                            ;      0:�������`�݂̂���, 1:for(...) {+���s �ɂ���, 2:���s+{��,{ }���c�ɑ�����\n",
		"\n",
		"while_big_kakko     2       ; '-u?' while(){} ��'{'�`'}'�̏c�̈ʒu�����낦��({'�`'}'�̏ꍇ�͑����Ȃ�)\n",
		"                            ;      0:�������`�݂̂���, 1:while(...) {+���s �ɂ���, 2:���s+{��,{ }���c�ɑ�����\n",
		"\n",
		"do_big_kakko        1       ; '-v?' do{} while() ��'{'�`'}'�̏c�̈ʒu�����낦��('{'�`'}'�̏ꍇ�͑����Ȃ�)\n",
		"                            ;      0:�������`�݂̂���, 1:do {+���s �ɂ���, 2:���s+{��,{ }���c�ɑ�����\n",
		"\n",
		"try_big_kakko       1       ; '-w?' try{} ��'{'�`'}'�̏c�̈ʒu�����낦��('{'�`'}'�̏ꍇ�͑����Ȃ�)\n",
		"                            ;      0:�������`�݂̂���, 1:try {+���s �ɂ���, 2:���s+{��,{ }���c�ɑ�����\n",
		"\n",
		"switch_big_kakko    2       ; '-x?' switch(){} ��'{'�`'}'�̏c�̈ʒu�����낦��('{'�`'}'�̏ꍇ�͑����Ȃ�)\n",
		"                            ;      0:�������`�݂̂���, 1:switch(...) {+���s �ɂ���, 2:���s+{��,{ }���c�ɑ�����\n",
		"\n",
		"other_big_kakko     0       ; '-y?' ���̑���'{'�`'}'�̏���('{'�`'}'�̏ꍇ�͑����Ȃ�)\n",
		"                            ;      0:�������`�݂̂���, 1,2:���s+{��,{ }���c�ɑ�����\n",				// {+���s�͕s�B�g���Ă͂����Ȃ�
		"\n",
		"debug_mode          0       ; '-z?' debug�p 0:�L�^�Ȃ�\n",
		"                            ;      1:tab_stack_cnt, 2:big_kakko_cnt, 3:if_stack_top\n",
		"                            ;      4:hojo_flag�C5:tab_pos, 6:src_line_no�C7:src_com_pos\n",
		"                            ;      8:sub_type�C9:debug���\��\n",
		"\n",

//		"typedef_mode        1       ; '-T?' typedef���}�N���Ƃ��Ēu�������� 0:��`�𖳎�����, 1:�L���Ƃ���\n", // V1.61�ō폜
//		"                            ;      ��`�͍ő�50�s��,�ő�35�����܂�\n",
//		"                            ;      �@typedef, �A�L���� char,short,int,long, long long, unsigned\n",
//		"                            ;      �B�������,�Ō�� ; �͂Ȃ��Ă��ǂ�(�r���̃X�y�[�XTAB�͕s��)\n",
//		"                            ;      �C ; �Ȍ�͖��������(�R�����g���K�v�ȏꍇ)\n",
//		";   �@           �A                �B       �C\n",
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
		printf( "�V�K�� %s ̧�ق��쐬�ł��܂���\n", ini_name );
		wait_exit( 2 );
	}

	sprintf( buf, "; ===== %s V%s %s Kenjiy ======\n;\n", exe_name, versions, environs );
	fwrite( buf, sizeof(char), strlen(buf), ini_fp );
	sprintf( buf, "; C�̃\�[�X�t�@�C���̕������`\n" );
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
// �����̐ݒ�
// ---------------------------------------------------------------------
void para_sub( char command, int para )
{
	switch( command )
	{
	case '?': // �g�p���@�\��
		usage();
		break;

	case 'a': // -cx �` -gx �̗L���w��
		form_all = para;
		break;

	case 'b': // ������̏��� 0:�����̂�, 1:������͕ς�炸+.new��V�K�ɍ��, 2:�������+.old�Ƃ���, 3:old�����Ȃ�
		form_source_name = para;
		break;

	case 'c': // #define �̏��� 0:�������Ȃ�, 1:TAB�Ȃ�(��߰��̂�), 2:������TAB�쐬, 3�`:�ŏ�TAB�ʒu
		form_define_tab = para;
		if( form_define_tab > 30 ) form_define_tab = 30;
//		else if( form_define_tab == 2 ) form_define_tab = 99;
		break;

	case 'd': // #define �̺���TAB 0:�������Ȃ�, 1:TAB�Ȃ�(��߰��̂�), 2:������TAB�쐬, 3�`:�ő�TAB�ʒu
		form_define_com_tab = para;
		if( form_define_com_tab > 40 ) form_define_com_tab = 40;
//		else if( form_define_com_tab == 2 ) form_define_com_tab = 99;
		break;

	case 'e': // �֐����̺��Ĉʒu��TAB�ʒu, 0:�������Ȃ�, 1:��߰��̂�, 2:�ő�TAB�����Ȃ�, 3�`:�ő�TAB�ʒu\n",
		form_other_com_tab = para;
		if( form_other_com_tab > 40 ) form_other_com_tab = 40;
//		else if( form_other_com_tab == 2 ) form_other_com_tab = 99;
		break;

	case 'f': // 0:����, 1:utf8, 2;Shif JIS
		form_utf8_mode = para;
		if( form_utf8_mode > 2 ) form_utf8_mode = 2;
		break;

//	case 'f': // ��۰��ٕϐ���int,char,long, unsigned��TAB�ʒu 0:�������Ȃ�, 1:��߰��̂�, 2:������TAB�쐬, 3�`:�ő�TAB�ʒu
//		form_global_int_tab = para;
//		if( form_global_int_tab > 40 ) form_global_int_tab = 40;
//		break;

	case 'g': // ۰�ٕϐ���int,char,long, unsigned��TAB�ʒuK 0:�������Ȃ�, 1:��߰��̂�, 2:������TAB�쐬, 3�`:�ő�TAB�ʒu\n",
		form_local_int_tab = para;
		if( form_local_int_tab > 40 ) form_local_int_tab = 40;
//		else if( form_local_int_tab == 2 ) form_local_int_tab = 99;
		break;

	case 'h': // '{'�`'}'�̏��� 0:��߰��̂�, 1:�����ɑ�����(�ŏ�TAB=1), 2:������TAB�쐬(��߰�+TAB�ō��킹��)
		form_big_kakko_pair = para;
		if( form_big_kakko_pair > 2 ) form_big_kakko_pair = 2;
		break;

	case 'i': // TAB�𖳌��ɂ���P�s�̍ő�TAB��
		form_limit_line = para;
		if( form_limit_line > 0 && form_limit_line <= 20 ) form_limit_line = 20; // �ŏ�=20 TAB
		break;

	case 'j': // ��݂̑O��̽�߰�
		form_kolon = para;
		break;

	case 'k': // ���Ă��폜����
		form_cut_comment = para;
		break;

	case 'l': // "/*"�Ŏn�܂钷�����͂� 0:�ϊ����Ȃ�, 1:�s�̍Ō�� '/*�`*/' ��'//'�ɕϊ�,
			  // 2:'/*'�Ŏn�܂镡���s�̒������͂܂ł�'//'�ɕϊ�
		form_long_comment = para;
		if( form_long_comment > 2 ) form_long_comment = 2;
		break;

	case 'm': // 0:�������Ȃ�, 1:��۸��т̏ꍇ�͒�������+TAB�𑵂���
		form_comment_prog = para;
		if( form_comment_prog > 1 ) form_comment_prog = 1;
		break;

	case 'n': // ���ʂ̑O��̏��� 0:�A�����銇�ʂ̍ŏ��ƍŌ�ͽ�߰�������, 1:���ʂ̓����ͽ�߰������Ȃ�\n",
		form_kakko_space = para;
		if( form_kakko_space > 1 ) form_kakko_space = 1;
		break;

	case 'o': // #if, #else, #endif �̃O���[�v�ԍ����R�����g�ɒǉ�
		form_ifdef_mode = para;
		break;

	case 'p': // 0:�ŏ���TAB�͕ύX�Ȃ�, 1:��������
		form_yen = para;
		if( form_yen > 1 ) form_yen = 1;
		break;

	case 'q': // struct ��'{'�`'}'�̏c�̈ʒu�����낦��
		form_struct_big_kakko = para;
		break;

	case 'r': // if(){} ��'{'�`'}'�̏c�̈ʒu�����낦��
		form_if_big_kakko = para;
		break;

	case 's': // else{} ��'{'�`'}'�̏c�̈ʒu�����낦��
		form_else_big_kakko = para;
		break;

	case 't': // for(){} ��'{'�`'}'�̏c�̈ʒu�����낦��
		form_for_big_kakko = para;
		break;

	case 'u': // while(){} ��'{'�`'}'�̏c�̈ʒu�����낦��
		form_while_big_kakko = para;
		break;

	case 'v': // do{}while() ��'{'�`'}'�̏c�̈ʒu�����낦��
		form_do_big_kakko = para;
		break;

	case 'w': // try{} ��'{'�`'}'�̏c�̈ʒu�����낦��
		form_try_big_kakko = para;
		break;

	case 'x': // switch(){} ��'{'�`'}'�̏c�̈ʒu�����낦��
		form_switch_big_kakko = para;
		break;

	case 'y': // ���̑� '{'�`'}'�̏c�̈ʒu�����낦��
		form_other_big_kakko = para;
		if( form_other_big_kakko ) form_other_big_kakko = 2;
		break;

	case 'z': // debug mode 0:�Ȃ�
		debug_mode = para;
		if( debug_mode == 9 ) disp_debug_para0();
		break;

	case 'T': // typedef���}�N���Ƃ��Ēu��������(��`�͍ő�20�s�܂�) 0:��������, 1:�L���Ƃ���
		form_typedef_mode = para;
		if( form_typedef_mode ) form_typedef_mode = 1;
		break;

	}
}
// ---------------------------------------------------------------------
// all-x �p�����[�^�w��
// type : all-x=0�`9
// n : �w�萔��
// ---------------------------------------------------------------------
void parameter_all( int type, char *line_buf )
{
	int		cur_pos, tok_len;
	char	tok_buf[CHAR_SIZE], command;

	cur_pos = 0;
	for(;;)
	{
		cur_pos += get_def_tok( tok_buf, &line_buf[cur_pos], &tok_len );	// get next
		if( tok_len == 0 || tok_buf[0] == ';' ) break;						// �P�s�I���
		if( tok_len < 3 ) continue;
		if( tok_buf[0] != '-' ) continue;									// '-'�ȊOpass
//		if( (tok_buf[1] < 'a' || tok_buf[1] > 'z') && tok_buf[1] != 'M' && tok_buf[1] != 'T' ) continue;
		command = tok_buf[1];
		if( _isdigit(tok_buf[2]) == 0 ) continue;
		para_sub( command, atoi(&tok_buf[2]) );
	}
}
// ---------------------------------------------------------------------
// ini̧�ق�ǂݍ���
// mode 0:հ�ް�w��̧�ٖ�
// mode 2:հ�ް�w��̧�ٖ�+form_all�͖���
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
	form_utf8_mode = 0; // ����
	ini_fp = fopen( ini_name, "rb+" );
	if( ini_fp == NULL )
	{
		if( mode == 0 )
		{
			printf( "�V�K�� %s ̧�ق��쐬���܂�\n", ini_name );
			make_ini_file(); // renew.ini ̧�ق����
		}
		ini_fp = fopen( ini_name, "rb+" );
		if( ini_fp == NULL )
		{
			printf( "�V�K�� %s ̧�ق��쐬�ł��܂���\n", ini_name );
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
				{ // �s��v
					printf( " ini�t�@�C���̃o�[�W�������Ⴂ�܂��B�V�����쐬���܂�\n" );
					fclose( ini_fp );
					make_ini_file(); // renew.ini ̧�ق����
					ini_fp = fopen( ini_name, "rb+" );
					if( ini_fp == NULL )
					{
						printf( "�V�K�� %s ̧�ق��쐬�ł��܂���\n", ini_name );
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
			printf( " %s ̧�ق����Ă܂�\n", ini_name );
			wait_exit( 2 );
		}
	}

	command_buf[0] = 0;
	while( fgets(line_buf, sizeof(line_buf) - 2, ini_fp) != NULL )
	{
		loop_mode = 0;
		cur_pos = 0;
		while( loop_mode >= 0 )
		{ // 1�s���
			cur_pos += get_def_tok( tok_buf, &line_buf[cur_pos], &tok_len );	// get next
			if( tok_len == 0 || tok_buf[0] == ';' ) break;						// �P�s�I���
			if( loop_mode && tok_len == 1 && tok_buf[0] == '=' ) continue;		// pass '='
			if( loop_mode == 0 )
			{ // �s�̎n��
				if( strcmp(tok_buf, "all") == 0 )
				{
					if( mode == 2 ) break;	// �P�s�I���
					loop_mode = 'a';		// mode = 2�͖���
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
						if( typedef_cnt >= MAX_TYPEDEF_CNT ) err_trap( 0, -38, tok_buf, 0 ); // "typedef�̓o�^������������"
					}
					break;
				}
				else {
					err_trap( 0, -28, tok_buf, 0 );
					loop_mode = -1; // �P�s�I���
				}
			}
			else para_sub( (char)loop_mode, atoi(tok_buf) );
		}
	}
	fclose( ini_fp );
	ini_fp = NULL;

	if( form_all > 0 && command_buf[0] ) parameter_all( form_all, command_buf ); // ̧�ْP�ʂȂ̂ōēx�m�F
}
// ---------------------------------------------------
// path name �� file name �ɕ���
// ---------------------------------------------------
int bunri_path( char *s_buf, char *p_name, char *f_name, char *e_name )
{
	long i, len, bunri_pos, ext_pos;
//	char buf[400];

	*p_name = *f_name = *e_name = 0;
	i = len = (long)strlen( s_buf );
	if( len == 0 ) return( 0 );
//	if( len >= (sizeof(buf) - 1) ) return( -9 ); // �����ُ�
	bunri_pos = 0;
	ext_pos = len;
	for( i = 0; i < len; i++ )
	{
		if( s_buf[i] == '\\' ) bunri_pos = i;
		if( s_buf[i] == '.' ) ext_pos = i;
	}
	if( bunri_pos > ext_pos ) return( -10 ); // file name�ُ�
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
			back_all = form_all; // �ޔ�
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
// �����ް��̉��
// ---------------------------------------------------------------------
void analize_inline( char *s_buf )
{
	int i, n;

	memset( &src_name_buf, 0, sizeof(src_name_buf) );
	i = para_cnt = 0;
	n = pass_space( s_buf ); // �߽ ��߰�,TAB
	while( s_buf[n] )
	{
		if( s_buf[n] == ' ' || s_buf[n] == _TAB )
		{
			n += pass_space( &s_buf[n] ); // �߽ ��߰�,TAB
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
// �����,���Ұ�����͂���
// ---------------------------------------------------------------------
void src_input_name( void )
{
	int		n;
	char	moji, input_buf[200];

	n = 0;
	input_buf[0] = 0;
	printf( "\r\n �\�[�X�t�@�C��������͂��ĉ����� :" );
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
// ܲ��޶��ނ�̧�ٖ���T��
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
// Shift JIS�����ׂ�
//
// &H00�`&H7F�̂����ꂩ�v��1�o�C�g��ɁA�u&H80�`&HBF�̂����ꂩ�v������ꍇ
// �@�� Shift_JIS �ł��B
// �u&HC0�`&HDF�̂����ꂩ�v��1�o�C�g��ɁA�u&H80�`&HBF�ȊO�v�̃f�[�^�������ꍇ
// �� Shift_JIS �ł��B
// �u&HC0�`&HDF�̂����ꂩ�v��2�o�C�g��ɁA�u&H80�`&HBF�̂����ꂩ�v�������ꍇ
// �� Shift_JIS �ł��B
// �u&HE0�`&HEF�̂����ꂩ�v��1�`2�o�C�g��ɁA�u&H80�`&HBF�ȊO�v�̃f�[�^�������ꍇ
// �� Shift_JIS �ł��B
// �u&HE0�`&HEF�̂����ꂩ�v��3�o�C�g��ɁA�u&H80�`&HBF�ȊO�v�̃f�[�^�������ꍇ
// �� Shift_JIS �ł��B
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
	max_fdata_line = 0;											// �m�ۂ���max memory�s��
	total_err_cnt = 0;											// �װ�s�̶��� 100�s�𒴂�����L�^���Ȃ�

	printf( " ===== V%s %s Kenjiy 2009/11-2020/03 ======\r\n\r\n", versions, environs );
	printf( "\r\n C(C++)�̃\�[�X�t�@�C���̕������`�����܂�(��:*.cpp -b3)\n" );
	// ------------ .ini ̧�ق̏����l�ݒ� --------------------
	ret = bunri_path( argv[0], path_in_name, file_in_name, ext_in_name );
	if( ret < 0 ) err_trap( 2, ret, argv[0], path_in_name );

	sprintf( exe_name, "%s.%s", file_in_name, ext_in_name );	// renew.exe
	sprintf( ini_name, "%s.ini", file_in_name );				// default ".ini" file
	sprintf( err_name, "%s_err.txt", file_in_name );			// �ύX

	fp_err = fopen( err_name, "w" );
	if( fp_err != NULL )
	{ // ���e�폜
		fclose( fp_err );
		fp_err = NULL;
		DeleteFile( err_name );
	}

	// ini̧�َ�荞�݂��܂�
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

	// ������̏��� 0:�����̂�, 1:������͕ς�炸+.new��V�K�ɍ��, 2:�������+.old�Ƃ���, 3:old�����Ȃ�
	if( debug_mode == 0 )
	{
		if( form_source_name == 0 ) printf( " �����̂�\n" );
		else if( form_source_name == 1 ) printf( " ���ʂ��\�[�X�t�@�C����+(.new) �ō��܂�\n" );
		else if( form_source_name == 2 ) printf( " �\�[�X�t�@�C������+(.old) �ō��,���ʂ��\�[�X�t�@�C�����ō��܂�\n" );
	}
	else {
		printf( " ���ʂ� renew_debug2.txt �ō��܂�\n" );
		printf( " ������ ̧�� = %s, debug_mode = %d\r\n", ini_name, debug_mode );
	}

	if( src_name[0] ) bunri_path( src_name, path_in_name, file_in_name, ext_in_name ); // ret�͖���
	if( path_in_name[0] == 0 ) strcpy( path_in_name, cur_path_name );

//	sprintf( buf, "%s\\%s", path_in_name, src_name );
	file_cnt = search_src_name( src_name );
	if( file_cnt == 0 )
	{
		printf( " %s not found file\n", src_name );
		usage(); // �g�p���@�\��
	}

	DeleteFile( debug_name2 );
	total_cnt = 0; // �ύX�����t�@�C����
	for( cnt = 0; cnt < file_cnt; cnt++ )
	{
		strcpy( src_name, src_name_buf[cnt].name );
//		ret = bunri_path( src_name, buf, file_in_name, ext_in_name ); // buf = dummy
//		printf( " ̧�� %s ��͒�\r", src_name ); 2019.09.11

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
		fseek( fp_src, 0, SEEK_END );									// �Ō�
		src_size = ftell( fp_src );										// next address
		if( src_size == 0 ) err_trap( 2, -18, src_name, path_in_name ); // "���̧�ٻ��ނ����"
		fseek( fp_src, 0, SEEK_SET );									// �߂�
		max_fdata_line = 0;
		jis_font = j = 0;
		while( (len = fread(big_buf, sizeof(char), LOADSIZE, fp_src)) != 0 )
		{
			for( n = 0; n < len; n++ )
			{
				if( j < (CHAR_SIZE2 - 3) ) buf[j++] = big_buf[n]; // ���1�s��荞��
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
		printf( " Shift JIS�R�[�h�� = %d\r\n", jis_font );
		if( form_utf8_mode == 0 )
		{
			if( jis_font >= 3 ) font_type = 2;	// Shift JIS
			else font_type = 1;					// utf8
		}
		else font_type = form_utf8_mode;				// �w��

		fseek( fp_src, 0, SEEK_SET );					// �߂�

		max_fdata_line += max_fdata_line / 2;			// ����s��5���葝��
		if( max_fdata_line < 5 ) max_fdata_line = 10;	// �K����10�s�����Ƃ���
		len = max_fdata_line * sizeof( struct FDATA );
		ope_buf = (struct FDATA *)malloc( len );		// �ر���m�ۂ���
		if( ope_buf == NULL ) err_trap( 2, -19, 0, 0 ); // malloc()���m�ۏo���Ȃ�
		memset( ope_buf, 0, len );						// clear all

		max_line = 0;
		fdata = &ope_buf[0];
		refresh();										// ���s sub1.c
		if( fp_src != NULL )
		{
			fclose( fp_src );
			fp_src = NULL;
		}

		reform_story(); // �����ϐ��Ƹ�۰��ق̋�ʂ����� sub2.c
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
				printf( " ���� ̧��   = %s\r\n", src_name );
				printf( " ���� ̧��   = %s\r\n", debug_name2 );
				printf( " �Ⴂ %d�s, �S�� %d�s �����I��\r\n", len, src_line_no );
			}
			else if( len == 0 )
			{
				printf( " ���� ̧��   = %s\r\n", src_name );
				printf( " �ύX�͂���܂���\r\n" ); // sub3.c
			}
			else { // TAB������ & �L�^
				switch( form_source_name )
				{
				case 0: // ������̏��� 0:�����̂�
					printf( " ���� ̧��   = %s\r\n", src_name );
					if( len < 0 ) printf( " �ύX ****�s, �S�� %d�s �����I��\r\n", src_line_no );
					else printf( " �Ⴂ %d�s, �S�� %d�s �����I��\r\n", len, src_line_no );
					break;

				case 1: // ������̏��� 1:������͕ς�炸+.new��V�K�ɍ��
					printf( " ���� ̧��   = %s\r\n", src_name );
					printf( " ���� ̧��   = %s\r\n", new_name );
					if( len < 0 ) printf( " �ύX ****�s, �S�� %d�s �����I��\r\n", src_line_no );
					else printf( " �ύX %d�s, �S�� %d�s �����I��\r\n", len, src_line_no );
					break;

				case 2: // ������̏��� 2:�������+.old�Ƃ���
					printf( " ���� ̧��   = %s --> %s \r\n", src_name, old_name );
					printf( " �o�� ̧��   = %s\r\n", src_name );
					if( len < 0 ) printf( " �ύX ****�s, �S�� %d�s �����I��\r\n", src_line_no );
					else printf( " �ύX %d�s, �S�� %d�s �����I��\r\n", len, src_line_no );
					break;

				case 3: // ������̏��� 3:old�����Ȃ�
					printf( " ���� ̧��   = �o�� ̧�� = %s\r\n", src_name );
					if( len < 0 ) printf( " �ύX ****�s, �S�� %d�s �����I��\r\n", src_line_no );
					else printf( " �ύX %d�s, �S�� %d�s �����I��\r\n", len, src_line_no );
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
	printf( " ========= �ύX�t�@�C���� = %d ============\r\n", total_cnt );
	wait_exit( 0 );
}
